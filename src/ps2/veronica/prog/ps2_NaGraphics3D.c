#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_Vu1Strip.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"

PS2_PLANE sc_plane = { { 0, 0, 1.0f, 1.0f }, { 0, 0, 2.0f, 1.0f } };
PS2_PLANE c_plane[5] = { { { 0, 0, 1.0f, 1.0f }, { 0, 0, 2.0f, 1.0f } }, 
						 { { 0, 0, 0,    1.0f }, { 0, 0, 0,    1.0f } },  
						 { { 0, 0, 0,    1.0f }, { 0, 0, 0,    1.0f } },
						 { { 0, 0, 0,    1.0f }, { 0, 0, 0,    1.0f } }, 
						 { { 0, 0, 0,    1.0f }, { 0, 0, 0,    1.0f } } };

// 100% matching! 
void Ps2SetPlane(PS2_PLANE* p, sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
	sceVu0FVECTOR tmp0;
    sceVu0FVECTOR tmp1;

    sceVu0SubVector(tmp0, v1, v0);
    sceVu0SubVector(tmp1, v2, v0);
     
    sceVu0OuterProduct(tmp0, tmp0, tmp1);
    
    sceVu0Normalize(p->norm, tmp0);

    *(long128*)p->pos = *(long128*)&v0;
}

// 98.22% matching
void Ps2CalcScreenCone()
{
    sceVu0FVECTOR cp = { 0, 0, 0, 1.0f };
	static const sceVu0FMATRIX pos = { { -320.0f, -240.0f, 0, 1.0f }, { 320.0f, -240.0f, 0, 1.0f }, { 320.0f, 240.0f, 0, 1.0f }, { -320.0f, 240.0f, 0, 1.0f } };

    cp[2] = -_nj_screen_.dist;

    Ps2SetPlane(&c_plane[1], cp, pos[1], pos[0]);
    Ps2SetPlane(&c_plane[2], cp, pos[2], pos[1]);
    Ps2SetPlane(&c_plane[3], cp, pos[3], pos[2]);
    Ps2SetPlane(&c_plane[4], cp, pos[0], pos[3]);
}

// 100% matching! 
float Calc_Intersection2(sceVu0FVECTOR v0, sceVu0FVECTOR v1, PS2_PLANE* plane)
{
    sceVu0FVECTOR tmp0;
    sceVu0FVECTOR tmp1;
    float tmpf;

    sceVu0SubVector(tmp0, v0, plane->pos);
    sceVu0SubVector(tmp1, v1, v0);
    
    tmpf = sceVu0InnerProduct(plane->norm, tmp1);
    
    if (tmpf == 0)
    {
        return 10000000.0f;
    }
    
    return -sceVu0InnerProduct(plane->norm, tmp0) / tmpf;
}

// 100% matching! 
int CalcIntersectionCone(float* ans, float* v0, float* v1) 
{
    int i;         
    float tmp1[4]; 
    float tmpf;    
    float f;       
    
    tmpf = 1.0E7f;
    
    sceVu0SubVector(tmp1, v1, v0);
    
    for (i = 0; i < 5; i++) 
    {
        f = Calc_Intersection2(v0, v1, &c_plane[i]);
        
        if ((f >= 0) && (f < tmpf)) 
        {
            tmpf = f; 
        }
    } 
    
    sceVu0ScaleVector(ans, tmp1, tmpf);
    sceVu0AddVector(ans, ans, v0);
}

// 100% matching!
float Head_or_Tail(PS2_PLANE* plane, float* v) // first parameter is not present on DWARF
{
    PS2_PLANE p;       
    sceVu0FVECTOR tmp; 

    p = *plane;

    sceVu0SubVector(tmp, v, p.pos);
    
    return sceVu0InnerProduct(tmp, p.norm);
}

// 100% matching!
float Across_Plane(PS2_PLANE* plane, float* v0, float* v1) // first parameter is not present on DWARF
{
    PS2_PLANE p;
    sceVu0FVECTOR tmp0; 
    sceVu0FVECTOR tmp1; 
    
    p = *plane;
    
    sceVu0SubVector(tmp0, v0, p.pos);
    sceVu0SubVector(tmp1, v1, p.pos);
    
    return sceVu0InnerProduct(tmp0, p.norm) * sceVu0InnerProduct(tmp1, p.norm);
}

// 100% matching!
void    njDrawLine3D(NJS_POINT3COL *p, Int n, Uint32 attr)
{
    float invz;      
    float buff[32][4]; 
    float (*bp)[4];    
    unsigned int i;    
    unsigned long prim; 
    NJS_SCRVECTOR scr; 
    
    if ((attr & 0x2)) 
    {
        n++;
        
        prim = 0x15000000000000;

        bp = buff;
    
        for (i = 0; i < n; i++, bp += 3) 
        {
            *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2];
            *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1];
            *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0];
            *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3];
            
            njRotTransPers(&p->p[i], &scr);
            
            bp[2][0] = scr.x;
            bp[2][1] = scr.y;
            bp[2][2] = scr.z;
            bp[2][3] = scr.fog;
            
            invz = scr.iz; 
            
            if ((attr & 0x80000000)) 
            {
                *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
                *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
                *(unsigned int*)&bp[0][2] = 0;
                *(unsigned int*)&bp[0][3] = 0;
                
                sceVu0ITOF12Vector(bp[0], (int*)bp);
                
                bp[0][0] *= invz;
                bp[0][1] *= invz;
                
                bp[0][2] = invz;
            } 
            else 
            {
                bp[0][0] = 0;
                bp[0][1] = 0;
                bp[0][2] = invz;
                bp[0][3] = 0;
            }
        }
    }
    else  
    {
        n *= 2;
        
        prim = 0x14800000000000;

        bp = buff;
    
        for (i = 0; i < n; i++, bp += 3) 
        {
            *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2];
            *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1];
            *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0];
            *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3];
            
            njRotTransPers(&p->p[i], &scr);
            
            bp[2][0] = scr.x;
            bp[2][1] = scr.y;
            bp[2][2] = scr.z;
            bp[2][3] = scr.fog;
            
            invz = scr.iz; 
            
            if ((attr & 0x80000000)) 
            {
                *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
                *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
                *(unsigned int*)&bp[0][2] = 0;
                *(unsigned int*)&bp[0][3] = 0;
                
                sceVu0ITOF12Vector(bp[0], (int*)bp);
                
                bp[0][0] *= invz;
                bp[0][1] *= invz;
                
                bp[0][2] = invz;
            } 
            else 
            {
                bp[0][0] = 0;
                bp[0][1] = 0;
                bp[0][2] = invz;
                bp[0][3] = 0;
            }
        } 
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim3D(prim, buff, n);
}

// 100% matching!
void njDrawLine3DEx(NJS_POINT3COL* p, int n, unsigned int attr)
{
    float invz;         
    float buff[32][4];  
    float (*bp)[4];    
    float pos[2][4];   
    float ans[4];       
    unsigned int i;     
    unsigned long prim; 
    NJS_SCRVECTOR scr;  
    
    if ((attr & 0x2)) 
    {
        n++;
        
        prim = 0x15000000000000;

        bp = buff;
    
        for (i = 0; i < n; i++, bp += 3) 
        {
            *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2];
            *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1];
            *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0];
            *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3];
            
            njRotTransPers(&p->p[i], &scr);
            
            bp[2][0] = scr.x;
            bp[2][1] = scr.y;
            bp[2][2] = scr.z;
            bp[2][3] = scr.fog;
            
            invz = scr.iz; 
            
            if ((attr & 0x80000000)) 
            {
                *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
                *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
                *(unsigned int*)&bp[0][2] = 0;
                *(unsigned int*)&bp[0][3] = 0;
                
                sceVu0ITOF12Vector(bp[0], (int*)bp);
                
                bp[0][0] *= invz;
                bp[0][1] *= invz;
                
                bp[0][2] = invz;
            } 
            else 
            {
                bp[0][0] = 0;
                bp[0][1] = 0;
                bp[0][2] = invz;
                bp[0][3] = 0;
            }
        }
    }
    else  
    {
        n *= 2;
        
        prim = 0x14800000000000;

        bp = buff;
    
        for (i = 0; i < n; i++, bp += 3) 
        {
            if (!(i & 0x1)) 
            {
                njRotTrans(&p->p[i],     (NJS_POINT3*)&pos); 
                njRotTrans(&p->p[i] + 1, (NJS_POINT3*)&pos[1]); 
             }
            
            *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2];
            *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1];
            *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0];
            *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3];
            
            if (Across_Plane(&sc_plane, pos[0], pos[1]) < 0)
            {
                if ((i & 0x1)) 
                {
                    if (Head_or_Tail(&sc_plane, pos[1]) < 0) 
                    {
                        CalcIntersectionCone(ans, pos[0], pos[1]);
                        
                        scr.x = ans[0];
                        scr.y = ans[1];
                        scr.z = ans[2];
                        
                        njPers(&scr);
                    }
                    else 
                    {
                        goto label;
                    }
                } 
                else if (Head_or_Tail(&sc_plane, pos[0]) < 0) 
                {
                    CalcIntersectionCone(ans, pos[1], pos[0]);
                    
                    scr.x = ans[0];
                    scr.y = ans[1];
                    scr.z = ans[2];
                    
                    njPers(&scr);
                } 
                else 
                {
                    goto label;
                }
            } 
            else 
            {
label:
                njRotTransPers(&p->p[i], &scr); 
            }
            
            bp[2][0] = scr.x;
            bp[2][1] = scr.y;
            bp[2][2] = scr.z;
            bp[2][3] = scr.fog;
            
            invz = scr.iz; 
            
            if ((attr & 0x80000000)) 
            {
                *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
                *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
                *(unsigned int*)&bp[0][2] = 0;
                *(unsigned int*)&bp[0][3] = 0;
                
                sceVu0ITOF12Vector(bp[0], (int*)bp);
                
                bp[0][0] *= invz;
                bp[0][1] *= invz;
                
                bp[0][2] = invz;
            } 
            else 
            {
                bp[0][0] = 0;
                bp[0][1] = 0;
                bp[0][2] = invz;
                bp[0][3] = 0;
            }
        } 
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim3D(prim, buff, n);
}

// 100% matching!
void    njDrawTriangle3D(NJS_POINT3COL *p, Int n, Uint32 attr)
{
    float invz;      
    float buff[96][4]; 
    float (*bp)[4];    
    unsigned int i;    
    unsigned long prim; 
    NJS_SCRVECTOR scr;  
    
    if ((attr & 0x2)) 
    {
        n++;
        
        prim = 0x16000000000000;
    }
    else  
    {
        n *= 3;
        
        prim = 0x15800000000000;
    }
    
    bp = buff;
    
    for (i = 0; i < n; i++, bp += 3) 
    {
        *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2] >> 1;
        *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1] >> 1;
        *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0] >> 1;
        *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3] >> 1;
        
        njRotTransPers(&p->p[i], &scr);
        
        bp[2][0] = scr.x;
        bp[2][1] = scr.y;
        bp[2][2] = scr.z;
        bp[2][3] = scr.fog;
        
        invz = scr.iz; 
        
        if ((attr & 0x80000000)) 
        {
            *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
            *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
            *(unsigned int*)&bp[0][2] = 0;
            *(unsigned int*)&bp[0][3] = 0;
            
            sceVu0ITOF12Vector(bp[0], (int*)bp);
            
            bp[0][0] *= invz;
            bp[0][1] *= invz;
            
            bp[0][2] = invz;
        } 
        else 
        {
            bp[0][0] = 0;
            bp[0][1] = 0;
            bp[0][2] = invz;
            bp[0][3] = 0;
        }
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim3D(prim, buff, n);
}

// 100% matching!
void    njDrawPolygon3D(NJS_POINT3COL *p, Int n, Uint32 attr)
{
    float invz;                  
    float buff[64][4];            
    float (*bp)[4];              
    unsigned int i;              
    unsigned long prim;          
    NJS_SCRVECTOR scr;           
    VU1_STRIP_BUF* vp;            
    static VU1_STRIP_BUF vb[256]; 

    if (!(attr & 0x20)) 
    {
        printf("NOT SUPPORT! njDrawPolygon3D\n");
        
        exit(0);
    }
    
    if (n == 3) 
    {
        prim = 0x16000000000000;
        
        vp = vb;
        
        for (i = 0; i < n; i++, vp++) 
        {
            vp->fIr = ((unsigned char*)&p->col[i])[2] / 256.0f;
            vp->fIg = ((unsigned char*)&p->col[i])[1] / 256.0f;
            vp->fIb = ((unsigned char*)&p->col[i])[0] / 256.0f;
            vp->fA =  ((unsigned char*)&p->col[i])[3] / 256.0f;
            
            vu1RotTransStripBuf(NULL, &p->p[i], vp);
            
            if ((attr & 0x80000000)) 
            {
                vp->fU = p->tex[i].tex.u / 256.0f;
                vp->fV = p->tex[i].tex.v / 256.0f;
            }
        } 
        
        if ((attr & 0x40)) 
        {
            prim |= 0x20000000000000;
        }
        
        if ((attr & 0x80000000)) 
        {
            prim |= 0x8000000000000; 
        }
        
        vu1DrawTriangleStripTransDouble(prim, vb, n, 0);
    }
    else 
    {
        prim = 0x16800000000000;
    
        bp = buff;
    
        for (i = 0; i < n; i++, bp += 3) 
        {
            *(unsigned int*)&bp[1][0] = ((unsigned char*)&p->col[i])[2];
            *(unsigned int*)&bp[1][1] = ((unsigned char*)&p->col[i])[1];
            *(unsigned int*)&bp[1][2] = ((unsigned char*)&p->col[i])[0];
            *(unsigned int*)&bp[1][3] = ((unsigned char*)&p->col[i])[3];
            
            njRotTransPers(&p->p[i], &scr);
            
            bp[2][0] = scr.x;
            bp[2][1] = scr.y;
            bp[2][2] = scr.z;
            bp[2][3] = scr.fog;
            
            invz = scr.iz; 
            
            if ((attr & 0x80000000)) 
            {
                *(unsigned int*)&bp[0][0] = p->tex[i].tex.u << 4;
                *(unsigned int*)&bp[0][1] = p->tex[i].tex.v << 4;
                *(unsigned int*)&bp[0][2] = 0;
                *(unsigned int*)&bp[0][3] = 0;
                
                sceVu0ITOF12Vector(bp[0], (int*)bp);
                
                bp[0][0] *= invz;
                bp[0][1] *= invz;
                
                bp[0][2] = invz;
            } 
            else 
            {
                bp[0][0] = 0;
                bp[0][1] = 0;
                bp[0][2] = invz;
                bp[0][3] = 0;
            }
        } 
        
        if ((attr & 0x40)) 
        {
            prim |= 0x20000000000000;
        }
        
        if ((attr & 0x80000000)) 
        {
            prim |= 0x8000000000000; 
        }
        
        Ps2AddPrim3D(prim, buff, n);
    }
}
