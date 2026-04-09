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

/*// 
// Start address: 0x2dfcf0
float Head_or_Tail(float* v)
{
	float tmp[4];
	_anon1 p;
	// Line 141, Address: 0x2dfcf0, Func Offset: 0
	// Line 144, Address: 0x2dfd04, Func Offset: 0x14
	// Line 141, Address: 0x2dfd08, Func Offset: 0x18
	// Line 144, Address: 0x2dfd0c, Func Offset: 0x1c
	// Line 145, Address: 0x2dfd18, Func Offset: 0x28
	// Line 146, Address: 0x2dfd24, Func Offset: 0x34
	// Func End, Address: 0x2dfd30, Func Offset: 0x40
}

// 
// Start address: 0x2dfd30
float Across_Plane(float* v0, float* v1)
{
	float tmp1[4];
	float tmp0[4];
	_anon1 p;
	// Line 150, Address: 0x2dfd30, Func Offset: 0
	// Line 153, Address: 0x2dfd50, Func Offset: 0x20
	// Line 150, Address: 0x2dfd58, Func Offset: 0x28
	// Line 153, Address: 0x2dfd5c, Func Offset: 0x2c
	// Line 154, Address: 0x2dfd6c, Func Offset: 0x3c
	// Line 155, Address: 0x2dfd7c, Func Offset: 0x4c
	// Line 156, Address: 0x2dfd9c, Func Offset: 0x6c
	// Func End, Address: 0x2dfdb4, Func Offset: 0x84
}*/

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

/*// 
// Start address: 0x2e00e0
void njDrawLine3DEx(_anon2* p, int n, unsigned int attr)
{
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float ans[4];
	float pos[4][2];
	float bp[4];
	float buff[4][32];
	float invz;
	// Line 280, Address: 0x2e00e0, Func Offset: 0
	// Line 287, Address: 0x2e010c, Func Offset: 0x2c
	// Line 280, Address: 0x2e0110, Func Offset: 0x30
	// Line 287, Address: 0x2e011c, Func Offset: 0x3c
	// Line 288, Address: 0x2e0124, Func Offset: 0x44
	// Line 289, Address: 0x2e0128, Func Offset: 0x48
	// Line 296, Address: 0x2e0130, Func Offset: 0x50
	// Line 289, Address: 0x2e0138, Func Offset: 0x58
	// Line 296, Address: 0x2e013c, Func Offset: 0x5c
	// Line 298, Address: 0x2e0158, Func Offset: 0x78
	// Line 303, Address: 0x2e015c, Func Offset: 0x7c
	// Line 298, Address: 0x2e0160, Func Offset: 0x80
	// Line 299, Address: 0x2e016c, Func Offset: 0x8c
	// Line 300, Address: 0x2e017c, Func Offset: 0x9c
	// Line 301, Address: 0x2e018c, Func Offset: 0xac
	// Line 303, Address: 0x2e019c, Func Offset: 0xbc
	// Line 304, Address: 0x2e01a8, Func Offset: 0xc8
	// Line 305, Address: 0x2e01b0, Func Offset: 0xd0
	// Line 306, Address: 0x2e01b8, Func Offset: 0xd8
	// Line 307, Address: 0x2e01c0, Func Offset: 0xe0
	// Line 310, Address: 0x2e01c8, Func Offset: 0xe8
	// Line 311, Address: 0x2e01d0, Func Offset: 0xf0
	// Line 315, Address: 0x2e01d4, Func Offset: 0xf4
	// Line 311, Address: 0x2e01dc, Func Offset: 0xfc
	// Line 312, Address: 0x2e01ec, Func Offset: 0x10c
	// Line 313, Address: 0x2e0200, Func Offset: 0x120
	// Line 315, Address: 0x2e0204, Func Offset: 0x124
	// Line 316, Address: 0x2e020c, Func Offset: 0x12c
	// Line 317, Address: 0x2e0218, Func Offset: 0x138
	// Line 319, Address: 0x2e0224, Func Offset: 0x144
	// Line 320, Address: 0x2e022c, Func Offset: 0x14c
	// Line 321, Address: 0x2e0230, Func Offset: 0x150
	// Line 322, Address: 0x2e0234, Func Offset: 0x154
	// Line 323, Address: 0x2e0238, Func Offset: 0x158
	// Line 324, Address: 0x2e023c, Func Offset: 0x15c
	// Line 325, Address: 0x2e0240, Func Offset: 0x160
	// Line 323, Address: 0x2e0244, Func Offset: 0x164
	// Line 325, Address: 0x2e024c, Func Offset: 0x16c
	// Line 326, Address: 0x2e0258, Func Offset: 0x178
	// Line 328, Address: 0x2e0260, Func Offset: 0x180
	// Line 327, Address: 0x2e0264, Func Offset: 0x184
	// Line 328, Address: 0x2e0268, Func Offset: 0x188
	// Line 335, Address: 0x2e0270, Func Offset: 0x190
	// Line 328, Address: 0x2e0278, Func Offset: 0x198
	// Line 335, Address: 0x2e027c, Func Offset: 0x19c
	// Line 336, Address: 0x2e029c, Func Offset: 0x1bc
	// Line 337, Address: 0x2e02a8, Func Offset: 0x1c8
	// Line 338, Address: 0x2e02b8, Func Offset: 0x1d8
	// Line 339, Address: 0x2e02cc, Func Offset: 0x1ec
	// Line 341, Address: 0x2e02d0, Func Offset: 0x1f0
	// Line 347, Address: 0x2e02d4, Func Offset: 0x1f4
	// Line 341, Address: 0x2e02e0, Func Offset: 0x200
	// Line 347, Address: 0x2e02e8, Func Offset: 0x208
	// Line 341, Address: 0x2e02ec, Func Offset: 0x20c
	// Line 342, Address: 0x2e02f0, Func Offset: 0x210
	// Line 343, Address: 0x2e0300, Func Offset: 0x220
	// Line 344, Address: 0x2e0310, Func Offset: 0x230
	// Line 347, Address: 0x2e031c, Func Offset: 0x23c
	// Line 348, Address: 0x2e033c, Func Offset: 0x25c
	// Line 349, Address: 0x2e0344, Func Offset: 0x264
	// Line 351, Address: 0x2e036c, Func Offset: 0x28c
	// Line 352, Address: 0x2e037c, Func Offset: 0x29c
	// Line 353, Address: 0x2e0380, Func Offset: 0x2a0
	// Line 354, Address: 0x2e0384, Func Offset: 0x2a4
	// Line 355, Address: 0x2e0388, Func Offset: 0x2a8
	// Line 352, Address: 0x2e038c, Func Offset: 0x2ac
	// Line 353, Address: 0x2e0390, Func Offset: 0x2b0
	// Line 355, Address: 0x2e0394, Func Offset: 0x2b4
	// Line 356, Address: 0x2e039c, Func Offset: 0x2bc
	// Line 358, Address: 0x2e03a4, Func Offset: 0x2c4
	// Line 360, Address: 0x2e03cc, Func Offset: 0x2ec
	// Line 361, Address: 0x2e03dc, Func Offset: 0x2fc
	// Line 362, Address: 0x2e03e0, Func Offset: 0x300
	// Line 363, Address: 0x2e03e4, Func Offset: 0x304
	// Line 364, Address: 0x2e03e8, Func Offset: 0x308
	// Line 361, Address: 0x2e03ec, Func Offset: 0x30c
	// Line 362, Address: 0x2e03f0, Func Offset: 0x310
	// Line 364, Address: 0x2e03f4, Func Offset: 0x314
	// Line 365, Address: 0x2e03fc, Func Offset: 0x31c
	// Line 369, Address: 0x2e0404, Func Offset: 0x324
	// Line 370, Address: 0x2e0414, Func Offset: 0x334
	// Line 374, Address: 0x2e0418, Func Offset: 0x338
	// Line 375, Address: 0x2e0420, Func Offset: 0x340
	// Line 376, Address: 0x2e0428, Func Offset: 0x348
	// Line 377, Address: 0x2e0430, Func Offset: 0x350
	// Line 380, Address: 0x2e0438, Func Offset: 0x358
	// Line 381, Address: 0x2e0440, Func Offset: 0x360
	// Line 385, Address: 0x2e0444, Func Offset: 0x364
	// Line 381, Address: 0x2e044c, Func Offset: 0x36c
	// Line 382, Address: 0x2e045c, Func Offset: 0x37c
	// Line 383, Address: 0x2e0470, Func Offset: 0x390
	// Line 385, Address: 0x2e0474, Func Offset: 0x394
	// Line 386, Address: 0x2e047c, Func Offset: 0x39c
	// Line 387, Address: 0x2e0488, Func Offset: 0x3a8
	// Line 389, Address: 0x2e0494, Func Offset: 0x3b4
	// Line 390, Address: 0x2e049c, Func Offset: 0x3bc
	// Line 391, Address: 0x2e04a0, Func Offset: 0x3c0
	// Line 392, Address: 0x2e04a4, Func Offset: 0x3c4
	// Line 393, Address: 0x2e04a8, Func Offset: 0x3c8
	// Line 394, Address: 0x2e04ac, Func Offset: 0x3cc
	// Line 395, Address: 0x2e04b0, Func Offset: 0x3d0
	// Line 393, Address: 0x2e04b4, Func Offset: 0x3d4
	// Line 395, Address: 0x2e04bc, Func Offset: 0x3dc
	// Line 397, Address: 0x2e04c8, Func Offset: 0x3e8
	// Line 398, Address: 0x2e04ec, Func Offset: 0x40c
	// Line 400, Address: 0x2e0514, Func Offset: 0x434
	// Line 401, Address: 0x2e0524, Func Offset: 0x444
	// Func End, Address: 0x2e0558, Func Offset: 0x478
}*/

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
