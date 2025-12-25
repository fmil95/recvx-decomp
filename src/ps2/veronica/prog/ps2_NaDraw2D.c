#include "ps2_NaDraw2D.h"
#include "ps2_dummy.h"
#include "main.h"

float Ps2_zbuff_a;
float Ps2_zbuff_b;

// 100% matching!
void CalcPs2ZbuffAB()
{ 
    Ps2_zbuff_a = (-65536.0f * fNaViwClipNear) / (fNaViwClipFar - fNaViwClipNear); 
    Ps2_zbuff_b = (65536.0f * fNaViwClipNear * fNaViwClipFar) / (fNaViwClipFar - fNaViwClipNear); 
}

// 100% matching! 
void sceVu0ITOF12Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1)
{
	asm __volatile__("
	lqc2    vf4,0x0(%1)
	vitof12.xyzw vf5,vf4
	sqc2    vf5,0x0(%0)
	": : "r" (v0) , "r" (v1));
}

// 100% matching! 
void	njDrawLine2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr)
{
    float buff[32][4];  
    float (* bp)[4];  
    unsigned int i;    
    unsigned long prim; 

    if ((attr & 0x2)) 
    {
        n++;
        
        prim = 0x5000000000000;
    }
    else 
    {
        n *= 2;
        
        prim = 0x4800000000000;
    }
    
    bp = buff;
    
    for (i = 0; i < n; i++, bp += 3) 
    {
        if ((attr & 0x80000000)) 
        {
            *(int*)&bp[0][0] = p->tex[i].tex.u * 16;
            *(int*)&bp[0][1] = p->tex[i].tex.v * 16;
            *(int*)&bp[0][2] = 4096;
            *(int*)&bp[0][3] = 0;
            
            sceVu0ITOF12Vector((float*)bp, (int*)bp);
        } 
        else 
        {
            bp[0][0] = 0;
            bp[0][1] = 0;
            bp[0][2] = 0;
            bp[0][3] = 0;
        }
        
        *(int*)&bp[1][0] = p->col[i].argb.r;
        *(int*)&bp[1][1] = p->col[i].argb.g;
        *(int*)&bp[1][2] = p->col[i].argb.b;
        *(int*)&bp[1][3] = (p->col[i].argb.a + 1) >> 1;
        
        bp[2][0] = 1728.0f + p->p[i].x;
        bp[2][1] = 1808.0f + p->p[i].y;
        bp[2][2] = pri;
        bp[2][3] = 0;
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim2D(prim, buff, n + 1);
}

// 100% matching! 
void	njDrawPolygon2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr)
{
    float buff[32][4];  
    float (* bp)[4];  
    unsigned int i;    
    unsigned long prim; 

    if (pri > -1.0f) 
    {
        pri = -1.0f;
    }
    
    bp = buff;
    
    for (i = 0; i < n; i++, bp += 3) 
    {
        if ((attr & 0x80000000)) 
        {
            *(int*)&bp[0][0] = (p->tex[i].tex.u * 16) + 8;
            *(int*)&bp[0][1] = (p->tex[i].tex.v * 16) + 8;
            *(int*)&bp[0][2] = 4096;
            *(int*)&bp[0][3] = 0;
            
            sceVu0ITOF12Vector((float*)bp, (int*)bp);
        } 
        else 
        {
            bp[0][0] = 0;
            bp[0][1] = 0;
            bp[0][2] = 0;
            bp[0][3] = 0;
        }
        
        if ((attr & 0x80000000)) 
        {
            *(int*)&bp[1][0] = p->col[i].argb.r >> 1;
            *(int*)&bp[1][1] = p->col[i].argb.g >> 1;
            *(int*)&bp[1][2] = p->col[i].argb.b >> 1;
            *(int*)&bp[1][3] = (p->col[i].argb.a + 1) >> 1;
        } 
        else 
        {
            *(int*)&bp[1][0] = p->col[i].argb.r;
            *(int*)&bp[1][1] = p->col[i].argb.g;
            *(int*)&bp[1][2] = p->col[i].argb.b;
            *(int*)&bp[1][3] = (p->col[i].argb.a + 1) >> 1;
        }
        
        bp[2][0] = 1728.0f + p->p[i].x;
        bp[2][1] = 1808.0f + p->p[i].y;
        bp[2][2] = pri;
        bp[2][3] = 0;
    }
    
    prim = 0x6800000000000;
    
    if (!(attr & 0x20)) 
    {
        prim = 0x5000000000000;
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim2D(prim, buff, n);
}

// 100% matching! 
void njDrawPolygon2DM(NJS_POINT2COL* p, int n, float pri, unsigned int attr)
{
    float buff[32][4];  
    float (* bp)[4];  
    unsigned int i;    
    unsigned long prim; 

    if (pri > -1.0f) 
    {
        pri = -1.0f;
    }
    
    bp = buff;
    
    for (i = 0; i < n; i++, bp += 3) 
    {
        if ((attr & 0x80000000)) 
        {
            switch (i) 
            {                 
            case 0:
                *(int*)&bp[0][0] = (p->tex[i].tex.u * 16) + 8;
                *(int*)&bp[0][1] = (p->tex[i].tex.v * 16) + 8;
                break;
            case 1:
                *(int*)&bp[0][0] = (p->tex[i].tex.u * 16) + 4;
                *(int*)&bp[0][1] = (p->tex[i].tex.v * 16) + 8;
                break;
            case 2:
                *(int*)&bp[0][0] = (p->tex[i].tex.u * 16) + 4;
                *(int*)&bp[0][1] = (p->tex[i].tex.v * 16) + 4;
                break;
            case 3:
                *(int*)&bp[0][0] = (p->tex[i].tex.u * 16) + 8;
                *(int*)&bp[0][1] = (p->tex[i].tex.v * 16) + 4;
                break;
            }
            
            *(int*)&bp[0][2] = 4096;
            *(int*)&bp[0][3] = 0;
            
            sceVu0ITOF12Vector((float*)bp, (int*)bp);
        } 
        else 
        {
            bp[0][0] = 0;
            bp[0][1] = 0;
            bp[0][2] = 0;
            bp[0][3] = 0;
        }
        
        if ((attr & 0x80000000)) 
        {
            *(int*)&bp[1][0] = p->col[i].argb.r >> 1;
            *(int*)&bp[1][1] = p->col[i].argb.g >> 1;
            *(int*)&bp[1][2] = p->col[i].argb.b >> 1;
            *(int*)&bp[1][3] = (p->col[i].argb.a + 1) >> 1;
        } 
        else 
        {
            *(int*)&bp[1][0] = p->col[i].argb.r;
            *(int*)&bp[1][1] = p->col[i].argb.g;
            *(int*)&bp[1][2] = p->col[i].argb.b;
            *(int*)&bp[1][3] = (p->col[i].argb.a + 1) >> 1;
        }
        
        bp[2][0] = 1728.0f + p->p[i].x;
        bp[2][1] = 1808.0f + p->p[i].y;
        bp[2][2] = pri;
        bp[2][3] = 0;
    }
    
    prim = 0x6800000000000;
    
    if (!(attr & 0x20)) 
    {
        prim = 0x5000000000000;
    }
    
    if ((attr & 0x40)) 
    {
        prim |= 0x20000000000000;
    }
    
    if ((attr & 0x80000000)) 
    {
        prim |= 0x8000000000000; 
    }
    
    Ps2AddPrim2D(prim, buff, n);
}
