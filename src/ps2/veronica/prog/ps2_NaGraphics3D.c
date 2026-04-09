#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
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

// 
// Start address: 0x2dfcf0
float Head_or_Tail(PS2_PLANE* plane, float* v) // first parameter is not present on DWARF
{
	float tmp[4];
	//_anon1 p;
	// Line 141, Address: 0x2dfcf0, Func Offset: 0
	// Line 144, Address: 0x2dfd04, Func Offset: 0x14
	// Line 141, Address: 0x2dfd08, Func Offset: 0x18
	// Line 144, Address: 0x2dfd0c, Func Offset: 0x1c
	// Line 145, Address: 0x2dfd18, Func Offset: 0x28
	// Line 146, Address: 0x2dfd24, Func Offset: 0x34
	// Func End, Address: 0x2dfd30, Func Offset: 0x40
	scePrintf("Head_or_Tail - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x2e0770
void njDrawPolygon3D(_anon2* p, int n, unsigned int attr)
{
	tagVU1_STRIP_BUF* vp;
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	tagVU1_STRIP_BUF vb[256];
	// Line 496, Address: 0x2e0770, Func Offset: 0
	// Line 507, Address: 0x2e079c, Func Offset: 0x2c
	// Line 496, Address: 0x2e07a0, Func Offset: 0x30
	// Line 507, Address: 0x2e07ac, Func Offset: 0x3c
	// Line 508, Address: 0x2e07b4, Func Offset: 0x44
	// Line 509, Address: 0x2e07c0, Func Offset: 0x50
	// Line 519, Address: 0x2e07c8, Func Offset: 0x58
	// Line 520, Address: 0x2e07d4, Func Offset: 0x64
	// Line 521, Address: 0x2e07dc, Func Offset: 0x6c
	// Line 528, Address: 0x2e0800, Func Offset: 0x90
	// Line 529, Address: 0x2e0850, Func Offset: 0xe0
	// Line 530, Address: 0x2e08a0, Func Offset: 0x130
	// Line 532, Address: 0x2e08f0, Func Offset: 0x180
	// Line 535, Address: 0x2e0934, Func Offset: 0x1c4
	// Line 532, Address: 0x2e0938, Func Offset: 0x1c8
	// Line 535, Address: 0x2e093c, Func Offset: 0x1cc
	// Line 532, Address: 0x2e0940, Func Offset: 0x1d0
	// Line 535, Address: 0x2e0944, Func Offset: 0x1d4
	// Line 549, Address: 0x2e0950, Func Offset: 0x1e0
	// Line 550, Address: 0x2e0958, Func Offset: 0x1e8
	// Line 551, Address: 0x2e0980, Func Offset: 0x210
	// Line 553, Address: 0x2e09a0, Func Offset: 0x230
	// Line 551, Address: 0x2e09a4, Func Offset: 0x234
	// Line 553, Address: 0x2e09ac, Func Offset: 0x23c
	// Line 554, Address: 0x2e09b8, Func Offset: 0x248
	// Line 555, Address: 0x2e09d0, Func Offset: 0x260
	// Line 557, Address: 0x2e09ec, Func Offset: 0x27c
	// Line 558, Address: 0x2e0a04, Func Offset: 0x294
	// Line 559, Address: 0x2e0a0c, Func Offset: 0x29c
	// Line 560, Address: 0x2e0a14, Func Offset: 0x2a4
	// Line 559, Address: 0x2e0a1c, Func Offset: 0x2ac
	// Line 560, Address: 0x2e0a20, Func Offset: 0x2b0
	// Line 562, Address: 0x2e0a38, Func Offset: 0x2c8
	// Line 567, Address: 0x2e0a3c, Func Offset: 0x2cc
	// Line 562, Address: 0x2e0a40, Func Offset: 0x2d0
	// Line 563, Address: 0x2e0a4c, Func Offset: 0x2dc
	// Line 564, Address: 0x2e0a5c, Func Offset: 0x2ec
	// Line 565, Address: 0x2e0a6c, Func Offset: 0x2fc
	// Line 567, Address: 0x2e0a7c, Func Offset: 0x30c
	// Line 568, Address: 0x2e0a88, Func Offset: 0x318
	// Line 569, Address: 0x2e0a90, Func Offset: 0x320
	// Line 570, Address: 0x2e0a98, Func Offset: 0x328
	// Line 571, Address: 0x2e0aa0, Func Offset: 0x330
	// Line 574, Address: 0x2e0aa8, Func Offset: 0x338
	// Line 575, Address: 0x2e0ab0, Func Offset: 0x340
	// Line 579, Address: 0x2e0ab4, Func Offset: 0x344
	// Line 575, Address: 0x2e0abc, Func Offset: 0x34c
	// Line 576, Address: 0x2e0acc, Func Offset: 0x35c
	// Line 577, Address: 0x2e0ae0, Func Offset: 0x370
	// Line 579, Address: 0x2e0ae4, Func Offset: 0x374
	// Line 580, Address: 0x2e0aec, Func Offset: 0x37c
	// Line 581, Address: 0x2e0af8, Func Offset: 0x388
	// Line 583, Address: 0x2e0b04, Func Offset: 0x394
	// Line 584, Address: 0x2e0b0c, Func Offset: 0x39c
	// Line 585, Address: 0x2e0b10, Func Offset: 0x3a0
	// Line 586, Address: 0x2e0b14, Func Offset: 0x3a4
	// Line 587, Address: 0x2e0b18, Func Offset: 0x3a8
	// Line 588, Address: 0x2e0b1c, Func Offset: 0x3ac
	// Line 589, Address: 0x2e0b20, Func Offset: 0x3b0
	// Line 587, Address: 0x2e0b24, Func Offset: 0x3b4
	// Line 589, Address: 0x2e0b2c, Func Offset: 0x3bc
	// Line 590, Address: 0x2e0b38, Func Offset: 0x3c8
	// Line 591, Address: 0x2e0b50, Func Offset: 0x3e0
	// Line 592, Address: 0x2e0b6c, Func Offset: 0x3fc
	// Line 594, Address: 0x2e0b7c, Func Offset: 0x40c
	// Func End, Address: 0x2e0bb0, Func Offset: 0x440
}*/
