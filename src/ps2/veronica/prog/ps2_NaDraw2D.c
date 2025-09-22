#include "ps2_NaDraw2D.h"

float Ps2_zbuff_b;
float Ps2_zbuff_a;
float fNaViwClipFar;
float fNaViwClipNear;

/*void CalcPs2ZbuffAB();
void sceVu0ITOF12Vector(float* v0, float* v1);
void njDrawLine2D(_anon2* p, int n, float pri, unsigned int attr);
void njDrawPolygon2D(_anon2* p, int n, float pri, unsigned int attr);
void njDrawPolygon2DM(_anon2* p, int n, float pri, unsigned int attr);*/

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

/*// 
// Start address: 0x2df250
void njDrawLine2D(_anon2* p, int n, float pri, unsigned int attr)
{
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	// Line 73, Address: 0x2df250, Func Offset: 0
	// Line 78, Address: 0x2df280, Func Offset: 0x30
	// Line 80, Address: 0x2df298, Func Offset: 0x48
	// Line 79, Address: 0x2df29c, Func Offset: 0x4c
	// Line 81, Address: 0x2df2a0, Func Offset: 0x50
	// Line 83, Address: 0x2df2a8, Func Offset: 0x58
	// Line 82, Address: 0x2df2b0, Func Offset: 0x60
	// Line 83, Address: 0x2df2b4, Func Offset: 0x64
	// Line 92, Address: 0x2df2b8, Func Offset: 0x68
	// Line 94, Address: 0x2df2d8, Func Offset: 0x88
	// Line 95, Address: 0x2df2e0, Func Offset: 0x90
	// Line 97, Address: 0x2df2e4, Func Offset: 0x94
	// Line 99, Address: 0x2df2e8, Func Offset: 0x98
	// Line 95, Address: 0x2df2f0, Func Offset: 0xa0
	// Line 96, Address: 0x2df300, Func Offset: 0xb0
	// Line 97, Address: 0x2df314, Func Offset: 0xc4
	// Line 99, Address: 0x2df318, Func Offset: 0xc8
	// Line 100, Address: 0x2df320, Func Offset: 0xd0
	// Line 101, Address: 0x2df328, Func Offset: 0xd8
	// Line 102, Address: 0x2df32c, Func Offset: 0xdc
	// Line 103, Address: 0x2df330, Func Offset: 0xe0
	// Line 104, Address: 0x2df334, Func Offset: 0xe4
	// Line 112, Address: 0x2df338, Func Offset: 0xe8
	// Line 107, Address: 0x2df340, Func Offset: 0xf0
	// Line 113, Address: 0x2df344, Func Offset: 0xf4
	// Line 116, Address: 0x2df34c, Func Offset: 0xfc
	// Line 107, Address: 0x2df350, Func Offset: 0x100
	// Line 108, Address: 0x2df35c, Func Offset: 0x10c
	// Line 116, Address: 0x2df360, Func Offset: 0x110
	// Line 108, Address: 0x2df364, Func Offset: 0x114
	// Line 109, Address: 0x2df370, Func Offset: 0x120
	// Line 110, Address: 0x2df380, Func Offset: 0x130
	// Line 115, Address: 0x2df38c, Func Offset: 0x13c
	// Line 110, Address: 0x2df390, Func Offset: 0x140
	// Line 112, Address: 0x2df39c, Func Offset: 0x14c
	// Line 113, Address: 0x2df3b0, Func Offset: 0x160
	// Line 115, Address: 0x2df3bc, Func Offset: 0x16c
	// Line 113, Address: 0x2df3c0, Func Offset: 0x170
	// Line 114, Address: 0x2df3c8, Func Offset: 0x178
	// Line 115, Address: 0x2df3cc, Func Offset: 0x17c
	// Line 116, Address: 0x2df3d0, Func Offset: 0x180
	// Line 118, Address: 0x2df3d8, Func Offset: 0x188
	// Line 120, Address: 0x2df3f0, Func Offset: 0x1a0
	// Line 121, Address: 0x2df40c, Func Offset: 0x1bc
	// Line 122, Address: 0x2df41c, Func Offset: 0x1cc
	// Func End, Address: 0x2df450, Func Offset: 0x200
}*/

// 
// Start address: 0x2df450
void	njDrawPolygon2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr)
{
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	// Line 141, Address: 0x2df450, Func Offset: 0
	// Line 153, Address: 0x2df478, Func Offset: 0x28
	// Line 141, Address: 0x2df47c, Func Offset: 0x2c
	// Line 153, Address: 0x2df480, Func Offset: 0x30
	// Line 154, Address: 0x2df49c, Func Offset: 0x4c
	// Line 156, Address: 0x2df4a0, Func Offset: 0x50
	// Line 158, Address: 0x2df4c0, Func Offset: 0x70
	// Line 161, Address: 0x2df4c8, Func Offset: 0x78
	// Line 164, Address: 0x2df4cc, Func Offset: 0x7c
	// Line 166, Address: 0x2df4d0, Func Offset: 0x80
	// Line 161, Address: 0x2df4d8, Func Offset: 0x88
	// Line 162, Address: 0x2df4ec, Func Offset: 0x9c
	// Line 164, Address: 0x2df504, Func Offset: 0xb4
	// Line 166, Address: 0x2df508, Func Offset: 0xb8
	// Line 167, Address: 0x2df510, Func Offset: 0xc0
	// Line 168, Address: 0x2df518, Func Offset: 0xc8
	// Line 169, Address: 0x2df51c, Func Offset: 0xcc
	// Line 170, Address: 0x2df520, Func Offset: 0xd0
	// Line 171, Address: 0x2df524, Func Offset: 0xd4
	// Line 174, Address: 0x2df528, Func Offset: 0xd8
	// Line 175, Address: 0x2df530, Func Offset: 0xe0
	// Line 176, Address: 0x2df544, Func Offset: 0xf4
	// Line 177, Address: 0x2df558, Func Offset: 0x108
	// Line 178, Address: 0x2df56c, Func Offset: 0x11c
	// Line 179, Address: 0x2df580, Func Offset: 0x130
	// Line 180, Address: 0x2df588, Func Offset: 0x138
	// Line 181, Address: 0x2df598, Func Offset: 0x148
	// Line 182, Address: 0x2df5a8, Func Offset: 0x158
	// Line 183, Address: 0x2df5b8, Func Offset: 0x168
	// Line 186, Address: 0x2df5d0, Func Offset: 0x180
	// Line 187, Address: 0x2df5dc, Func Offset: 0x18c
	// Line 190, Address: 0x2df5e4, Func Offset: 0x194
	// Line 189, Address: 0x2df5e8, Func Offset: 0x198
	// Line 186, Address: 0x2df5ec, Func Offset: 0x19c
	// Line 190, Address: 0x2df5f8, Func Offset: 0x1a8
	// Line 186, Address: 0x2df5fc, Func Offset: 0x1ac
	// Line 187, Address: 0x2df600, Func Offset: 0x1b0
	// Line 189, Address: 0x2df60c, Func Offset: 0x1bc
	// Line 187, Address: 0x2df610, Func Offset: 0x1c0
	// Line 188, Address: 0x2df618, Func Offset: 0x1c8
	// Line 189, Address: 0x2df61c, Func Offset: 0x1cc
	// Line 190, Address: 0x2df620, Func Offset: 0x1d0
	// Line 191, Address: 0x2df628, Func Offset: 0x1d8
	// Line 192, Address: 0x2df634, Func Offset: 0x1e4
	// Line 193, Address: 0x2df640, Func Offset: 0x1f0
	// Line 197, Address: 0x2df648, Func Offset: 0x1f8
	// Line 199, Address: 0x2df660, Func Offset: 0x210
	// Line 200, Address: 0x2df67c, Func Offset: 0x22c
	// Line 201, Address: 0x2df688, Func Offset: 0x238
	// Func End, Address: 0x2df6b8, Func Offset: 0x268
	scePrintf("njDrawPolygon2D - UNIMPLEMENTED!\n");
}

void Ps2AddPrim2D(unsigned long prim, void* dp, unsigned int num);
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
