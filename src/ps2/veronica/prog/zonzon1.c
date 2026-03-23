#include "zonzon1.h"
#include "effect.h"
#include "effsub3.h"
#include "ps2_NaMath.h"
#include "main.h"

static BT_WK BloodType[31] = 
{
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 1, 0, 5 }, 
    { 1, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 1 }, 
    { 1, 1, 0 }, 
    { 0, 0, 1 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 3, 2, 1 }, 
    { 2, 3, 0 }, 
    { 3, 0, 1 }, 
    { 3, 0, 8 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 2, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 1, 6 }, 
    { 0, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 2, 0, 2 } 
};
unsigned int BloodCol[4][2] = 
{
    { 0xFF5F0000, 0xFF4F0000 },
    { 0xFF4F3520, 0xFF20102F },
    { 0xFF3F3F16, 0xFF102F18 },
    { 0xFF3F0000, 0xFF2F0000 }
};

/*// 
// Start address: 0x218d10
void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num)
{
	float size;
	int dam_ang;
	int i;
	int eno;
	// Line 105, Address: 0x218d10, Func Offset: 0
	// Line 110, Address: 0x218d28, Func Offset: 0x18
	// Line 111, Address: 0x218d38, Func Offset: 0x28
	// Line 110, Address: 0x218d3c, Func Offset: 0x2c
	// Line 111, Address: 0x218d48, Func Offset: 0x38
	// Line 112, Address: 0x218d60, Func Offset: 0x50
	// Line 113, Address: 0x218d74, Func Offset: 0x64
	// Line 114, Address: 0x218d8c, Func Offset: 0x7c
	// Line 115, Address: 0x218da4, Func Offset: 0x94
	// Line 116, Address: 0x218db8, Func Offset: 0xa8
	// Line 117, Address: 0x218dd8, Func Offset: 0xc8
	// Line 116, Address: 0x218de0, Func Offset: 0xd0
	// Line 120, Address: 0x218df0, Func Offset: 0xe0
	// Line 117, Address: 0x218df4, Func Offset: 0xe4
	// Line 116, Address: 0x218dfc, Func Offset: 0xec
	// Line 120, Address: 0x218e08, Func Offset: 0xf8
	// Line 116, Address: 0x218e0c, Func Offset: 0xfc
	// Line 117, Address: 0x218e18, Func Offset: 0x108
	// Line 118, Address: 0x218e1c, Func Offset: 0x10c
	// Line 119, Address: 0x218e30, Func Offset: 0x120
	// Line 120, Address: 0x218e44, Func Offset: 0x134
	// Line 122, Address: 0x218e6c, Func Offset: 0x15c
	// Line 123, Address: 0x218e90, Func Offset: 0x180
	// Line 122, Address: 0x218e94, Func Offset: 0x184
	// Line 123, Address: 0x218e98, Func Offset: 0x188
	// Line 126, Address: 0x218ea0, Func Offset: 0x190
	// Line 131, Address: 0x218ef4, Func Offset: 0x1e4
	// Line 126, Address: 0x218f00, Func Offset: 0x1f0
	// Line 131, Address: 0x218f0c, Func Offset: 0x1fc
	// Line 132, Address: 0x218f24, Func Offset: 0x214
	// Line 133, Address: 0x218f30, Func Offset: 0x220
	// Line 134, Address: 0x218f54, Func Offset: 0x244
	// Line 135, Address: 0x218f5c, Func Offset: 0x24c
	// Line 133, Address: 0x218f64, Func Offset: 0x254
	// Line 134, Address: 0x218f6c, Func Offset: 0x25c
	// Line 135, Address: 0x218f98, Func Offset: 0x288
	// Line 137, Address: 0x218fb0, Func Offset: 0x2a0
	// Line 138, Address: 0x218fc0, Func Offset: 0x2b0
	// Func End, Address: 0x218fdc, Func Offset: 0x2cc
}

// 
// Start address: 0x218fe0
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num)
{
	int dam_ang;
	int i;
	int eno;
	// Line 151, Address: 0x218fe0, Func Offset: 0
	// Line 155, Address: 0x218ff8, Func Offset: 0x18
	// Line 164, Address: 0x219000, Func Offset: 0x20
	// Line 155, Address: 0x219008, Func Offset: 0x28
	// Line 164, Address: 0x21900c, Func Offset: 0x2c
	// Line 155, Address: 0x219010, Func Offset: 0x30
	// Line 156, Address: 0x21901c, Func Offset: 0x3c
	// Line 157, Address: 0x219038, Func Offset: 0x58
	// Line 158, Address: 0x21904c, Func Offset: 0x6c
	// Line 159, Address: 0x219064, Func Offset: 0x84
	// Line 160, Address: 0x21907c, Func Offset: 0x9c
	// Line 161, Address: 0x219094, Func Offset: 0xb4
	// Line 162, Address: 0x2190a8, Func Offset: 0xc8
	// Line 163, Address: 0x2190bc, Func Offset: 0xdc
	// Line 164, Address: 0x2190d0, Func Offset: 0xf0
	// Line 166, Address: 0x2190f8, Func Offset: 0x118
	// Line 167, Address: 0x21911c, Func Offset: 0x13c
	// Line 166, Address: 0x219120, Func Offset: 0x140
	// Line 167, Address: 0x219124, Func Offset: 0x144
	// Line 170, Address: 0x21912c, Func Offset: 0x14c
	// Line 175, Address: 0x219180, Func Offset: 0x1a0
	// Line 170, Address: 0x21918c, Func Offset: 0x1ac
	// Line 175, Address: 0x219198, Func Offset: 0x1b8
	// Line 176, Address: 0x2191b0, Func Offset: 0x1d0
	// Line 177, Address: 0x2191bc, Func Offset: 0x1dc
	// Line 178, Address: 0x2191e0, Func Offset: 0x200
	// Line 179, Address: 0x2191e8, Func Offset: 0x208
	// Line 177, Address: 0x2191f0, Func Offset: 0x210
	// Line 178, Address: 0x2191f8, Func Offset: 0x218
	// Line 179, Address: 0x219224, Func Offset: 0x244
	// Line 180, Address: 0x21923c, Func Offset: 0x25c
	// Line 181, Address: 0x219240, Func Offset: 0x260
	// Line 182, Address: 0x219250, Func Offset: 0x270
	// Func End, Address: 0x21926c, Func Offset: 0x28c
}*/

// 100% matching!
void bhEne_SetBloodEffect(BH_PWORK* epw, int type)
{
    bhEne_SetBloodEffect5(epw, 0, type);
}

// 100% matching!
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp)
{
    NJS_POINT3 org = { 0 }; 
    NJS_POINT3 vec; 
    
    if (ofp == NULL) 
    {
        ofp = &org;
    }
    
    vec.x = -epw->dvx;
    vec.y = -epw->dvy;
    vec.z = -epw->dvz;
    
    bhSetEffParticleMk2(epw, jno, ofp, &vec, BloodCol[BloodType[epw->id].color][0], BloodCol[BloodType[epw->id].color][1], type >> 16);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = (char)(type & 0xFF);
    
    sys->ef.px = sys->ef.py = sys->ef.pz = 0;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, jno);
}

// 100% matching!
void bhEne_SetBloodEffect4(NJS_POINT3* pos, NJS_POINT3* vec, int col, int type1, int type2)
{
    bhSetEffParticleMk2(NULL, 0, pos, vec, BloodCol[col][0], BloodCol[col][1], type1);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type2 & 0xFF;
    
    sys->ef.mdlver = col;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 100% matching!
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2)
{
    NJS_POINT3 ofp; 
    NJS_POINT3 vec; 

    ofp.x = epw->dpx - epw->mlwP->owP[epw->djnt_no].mtx[12];
    ofp.y = epw->dpy - epw->mlwP->owP[epw->djnt_no].mtx[13];
    ofp.z = epw->dpz - epw->mlwP->owP[epw->djnt_no].mtx[14];
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[epw->djnt_no].mtx);
    njInvertMatrix(NULL);
    
    njCalcVector(NULL, &ofp, &ofp);
    
    vec.x = -epw->dvx;
    vec.y = -epw->dvy;
    vec.z = -epw->dvz;
    
    bhSetEffParticleMk2(epw, epw->djnt_no, &ofp, &vec, BloodCol[BloodType[epw->id].color][0], BloodCol[BloodType[epw->id].color][1], type1);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type2;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, epw->djnt_no);
}

// 100% matching!
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, NJS_POINT3* pos, int flg)
{   
    int eno;
    O_WRK* op; 
    NJS_POINT3 ofp; 

    if (pos == NULL) 
    {
        ofp.z = 0;
        ofp.y = 0;
        ofp.x = 0;
    }
    else 
    {
        ofp = *pos; 
    }
    
    if (flg != 0) 
    {   
        njSubVector(&ofp, (NJS_VECTOR*)&epw->mlwP->owP[jno].mtx[12]);
        
        njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[jno].mtx);
        njInvertMatrix(NULL);
        
        njCalcVector(NULL, &ofp, &ofp);
    }
    
    sys->ef.id = 297;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    eno = bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, jno);
    
    if (eno != -1) 
    {
        op = &eff[eno];
        
        op->xn = -epw->dvx;
        op->yn = -epw->dvy;
        op->zn = -epw->dvz;
    }
}

// 100% matching!
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp)
{
    NJS_POINT3 pos; 
    float d; 

    if (jno < 0)
    {
        if (ofp != NULL) 
        {
            pos = *ofp;
        } 
        else 
        {
            *(NJS_POINT3*)&pos = *(NJS_POINT3*)&epw->px;
        }
    }
    else if (ofp != NULL)
    {
        njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[jno].mtx);

        njCalcPoint(NULL, ofp, &pos);
    } 
    else 
    {
        *(NJS_POINT3*)&pos = *(NJS_POINT3*)&epw->mlwP->owP[jno].mtx[12];
    }
    
    sys->ef.id = 301;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.px = pos.x;
    sys->ef.py = pos.y;
    sys->ef.pz = pos.z;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    sys->ef.ax = bhArcTan2(epw->dvy, njSqrt((epw->dvx * epw->dvx) + (epw->dvz * epw->dvz)));
    sys->ef.ay = bhArcTan2(-epw->dvx, -epw->dvz);
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 100% matching!
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, NJS_POINT3* ofp, float size, int len)
{
    NJS_POINT3 org = { 0 }; 
    int eno; 
    
    if (ofp == NULL) 
    {
        ofp = &org;
    }
    
    sys->ef.id = 252;
    
    sys->ef.flg = 1;
    
    sys->ef.type = 0;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = 0;
    
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, jno);
    
    if (eno != -1) 
    {
        eff[eno].ct0 = len;
    }
}

/*// 
// Start address: 0x219f90
void bhEne_BloodPool(BH_PWORK* epw, _anon6* pos, int ang, _anon39* param)
{
	// Line 515, Address: 0x219f90, Func Offset: 0
	// Func End, Address: 0x219fb0, Func Offset: 0x20
}

// 
// Start address: 0x219fb0
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size)
{
	_anon6 org;
	// Line 529, Address: 0x219fb0, Func Offset: 0
	// Line 530, Address: 0x219fb8, Func Offset: 0x8
	// Line 529, Address: 0x219fc0, Func Offset: 0x10
	// Line 530, Address: 0x219fc4, Func Offset: 0x14
	// Line 533, Address: 0x219fd4, Func Offset: 0x24
	// Line 536, Address: 0x219fe0, Func Offset: 0x30
	// Line 537, Address: 0x219ff4, Func Offset: 0x44
	// Line 539, Address: 0x219ffc, Func Offset: 0x4c
	// Line 540, Address: 0x21a010, Func Offset: 0x60
	// Line 542, Address: 0x21a018, Func Offset: 0x68
	// Line 544, Address: 0x21a030, Func Offset: 0x80
	// Line 559, Address: 0x21a038, Func Offset: 0x88
	// Line 544, Address: 0x21a03c, Func Offset: 0x8c
	// Line 559, Address: 0x21a040, Func Offset: 0x90
	// Line 544, Address: 0x21a044, Func Offset: 0x94
	// Line 546, Address: 0x21a050, Func Offset: 0xa0
	// Line 554, Address: 0x21a08c, Func Offset: 0xdc
	// Line 555, Address: 0x21a0a0, Func Offset: 0xf0
	// Line 556, Address: 0x21a0b4, Func Offset: 0x104
	// Line 557, Address: 0x21a0c8, Func Offset: 0x118
	// Line 559, Address: 0x21a0dc, Func Offset: 0x12c
	// Line 563, Address: 0x21a0f4, Func Offset: 0x144
	// Func End, Address: 0x21a100, Func Offset: 0x150
}

// 
// Start address: 0x21a100
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 576, Address: 0x21a100, Func Offset: 0
	// Line 582, Address: 0x21a110, Func Offset: 0x10
	// Line 583, Address: 0x21a12c, Func Offset: 0x2c
	// Line 585, Address: 0x21a13c, Func Offset: 0x3c
	// Line 586, Address: 0x21a150, Func Offset: 0x50
	// Line 589, Address: 0x21a168, Func Offset: 0x68
	// Line 590, Address: 0x21a16c, Func Offset: 0x6c
	// Func End, Address: 0x21a180, Func Offset: 0x80
}

// 
// Start address: 0x21a180
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 603, Address: 0x21a180, Func Offset: 0
	// Line 609, Address: 0x21a190, Func Offset: 0x10
	// Line 610, Address: 0x21a1bc, Func Offset: 0x3c
	// Line 611, Address: 0x21a1e4, Func Offset: 0x64
	// Line 612, Address: 0x21a1e8, Func Offset: 0x68
	// Func End, Address: 0x21a1fc, Func Offset: 0x7c
}

// 
// Start address: 0x21a200
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, _anon6* p)
{
	npobj* objP;
	_anon12* mlwP;
	// Line 624, Address: 0x21a200, Func Offset: 0
	// Line 625, Address: 0x21a218, Func Offset: 0x18
	// Line 627, Address: 0x21a224, Func Offset: 0x24
	// Line 629, Address: 0x21a22c, Func Offset: 0x2c
	// Line 630, Address: 0x21a234, Func Offset: 0x34
	// Line 631, Address: 0x21a23c, Func Offset: 0x3c
	// Line 633, Address: 0x21a248, Func Offset: 0x48
	// Line 634, Address: 0x21a250, Func Offset: 0x50
	// Line 636, Address: 0x21a270, Func Offset: 0x70
	// Line 637, Address: 0x21a278, Func Offset: 0x78
	// Line 638, Address: 0x21a284, Func Offset: 0x84
	// Line 639, Address: 0x21a298, Func Offset: 0x98
	// Line 641, Address: 0x21a2a4, Func Offset: 0xa4
	// Line 642, Address: 0x21a2ac, Func Offset: 0xac
	// Func End, Address: 0x21a2c8, Func Offset: 0xc8
}

// 
// Start address: 0x21a2d0
int bhEne_DirCheck(int ay, _anon6* vec)
{
	_anon6 v;
	// Line 653, Address: 0x21a2d0, Func Offset: 0
	// Line 656, Address: 0x21a2e8, Func Offset: 0x18
	// Line 657, Address: 0x21a2f0, Func Offset: 0x20
	// Line 658, Address: 0x21a2fc, Func Offset: 0x2c
	// Line 661, Address: 0x21a30c, Func Offset: 0x3c
	// Line 665, Address: 0x21a32c, Func Offset: 0x5c
	// Func End, Address: 0x21a340, Func Offset: 0x70
}

// 
// Start address: 0x21a340
int bhEne_DGDirCheck(BH_PWORK* epw)
{
	// Line 676, Address: 0x21a340, Func Offset: 0
	// Func End, Address: 0x21a34c, Func Offset: 0xc
}

// 
// Start address: 0x21a350
void bhEne_CallPlayerVoice(int no)
{
	// Line 688, Address: 0x21a350, Func Offset: 0
	// Func End, Address: 0x21a358, Func Offset: 0x8
}

// 
// Start address: 0x21a360
void bhEne_CheckEnemiesBall(BH_PWORK* epw)
{
	int i;
	float r;
	float ez1;
	float ey1;
	float ex1;
	float ez0;
	float ey0;
	float ex0;
	float ln;
	float pz;
	float py;
	float px;
	BH_PWORK* epp;
	// Line 699, Address: 0x21a360, Func Offset: 0
	// Line 704, Address: 0x21a38c, Func Offset: 0x2c
	// Line 706, Address: 0x21a39c, Func Offset: 0x3c
	// Line 707, Address: 0x21a3a4, Func Offset: 0x44
	// Line 708, Address: 0x21a3ac, Func Offset: 0x4c
	// Line 710, Address: 0x21a3b4, Func Offset: 0x54
	// Line 706, Address: 0x21a3b8, Func Offset: 0x58
	// Line 710, Address: 0x21a3bc, Func Offset: 0x5c
	// Line 711, Address: 0x21a3c0, Func Offset: 0x60
	// Line 707, Address: 0x21a3c4, Func Offset: 0x64
	// Line 711, Address: 0x21a3c8, Func Offset: 0x68
	// Line 712, Address: 0x21a3d0, Func Offset: 0x70
	// Line 713, Address: 0x21a3f4, Func Offset: 0x94
	// Line 714, Address: 0x21a410, Func Offset: 0xb0
	// Line 716, Address: 0x21a418, Func Offset: 0xb8
	// Line 715, Address: 0x21a420, Func Offset: 0xc0
	// Line 714, Address: 0x21a428, Func Offset: 0xc8
	// Line 716, Address: 0x21a42c, Func Offset: 0xcc
	// Line 717, Address: 0x21a430, Func Offset: 0xd0
	// Line 720, Address: 0x21a434, Func Offset: 0xd4
	// Line 715, Address: 0x21a438, Func Offset: 0xd8
	// Line 718, Address: 0x21a43c, Func Offset: 0xdc
	// Line 720, Address: 0x21a440, Func Offset: 0xe0
	// Line 719, Address: 0x21a448, Func Offset: 0xe8
	// Line 720, Address: 0x21a44c, Func Offset: 0xec
	// Line 721, Address: 0x21a454, Func Offset: 0xf4
	// Line 726, Address: 0x21a470, Func Offset: 0x110
	// Line 727, Address: 0x21a478, Func Offset: 0x118
	// Line 736, Address: 0x21a480, Func Offset: 0x120
	// Line 726, Address: 0x21a484, Func Offset: 0x124
	// Line 727, Address: 0x21a48c, Func Offset: 0x12c
	// Line 728, Address: 0x21a498, Func Offset: 0x138
	// Line 727, Address: 0x21a49c, Func Offset: 0x13c
	// Line 728, Address: 0x21a4a0, Func Offset: 0x140
	// Line 729, Address: 0x21a4b0, Func Offset: 0x150
	// Line 728, Address: 0x21a4b4, Func Offset: 0x154
	// Line 729, Address: 0x21a4b8, Func Offset: 0x158
	// Line 736, Address: 0x21a4cc, Func Offset: 0x16c
	// Line 737, Address: 0x21a4d8, Func Offset: 0x178
	// Line 738, Address: 0x21a4e0, Func Offset: 0x180
	// Line 739, Address: 0x21a4e8, Func Offset: 0x188
	// Line 743, Address: 0x21a4f4, Func Offset: 0x194
	// Line 744, Address: 0x21a520, Func Offset: 0x1c0
	// Func End, Address: 0x21a550, Func Offset: 0x1f0
}

// 
// Start address: 0x21a550
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r)
{
	_anon31* owk;
	// Line 760, Address: 0x21a550, Func Offset: 0
	// Line 765, Address: 0x21a554, Func Offset: 0x4
	// Line 760, Address: 0x21a558, Func Offset: 0x8
	// Line 765, Address: 0x21a568, Func Offset: 0x18
	// Line 760, Address: 0x21a56c, Func Offset: 0x1c
	// Line 765, Address: 0x21a574, Func Offset: 0x24
	// Line 760, Address: 0x21a580, Func Offset: 0x30
	// Line 761, Address: 0x21a584, Func Offset: 0x34
	// Line 762, Address: 0x21a58c, Func Offset: 0x3c
	// Line 763, Address: 0x21a594, Func Offset: 0x44
	// Line 765, Address: 0x21a59c, Func Offset: 0x4c
	// Line 766, Address: 0x21a5a8, Func Offset: 0x58
	// Line 767, Address: 0x21a5b0, Func Offset: 0x60
	// Line 768, Address: 0x21a5b8, Func Offset: 0x68
	// Line 771, Address: 0x21a5c0, Func Offset: 0x70
	// Func End, Address: 0x21a5c8, Func Offset: 0x78
}

// 
// Start address: 0x21a5d0
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, _anon6* pos, float ar)
{
	_anon45 sphere;
	int kno;
	int i;
	float knr;
	float ll;
	_anon6 vec;
	// Line 783, Address: 0x21a5d0, Func Offset: 0
	// Line 789, Address: 0x21a5f8, Func Offset: 0x28
	// Line 795, Address: 0x21a604, Func Offset: 0x34
	// Line 794, Address: 0x21a60c, Func Offset: 0x3c
	// Line 789, Address: 0x21a610, Func Offset: 0x40
	// Line 790, Address: 0x21a614, Func Offset: 0x44
	// Line 791, Address: 0x21a61c, Func Offset: 0x4c
	// Line 795, Address: 0x21a624, Func Offset: 0x54
	// Line 796, Address: 0x21a638, Func Offset: 0x68
	// Line 797, Address: 0x21a63c, Func Offset: 0x6c
	// Line 798, Address: 0x21a648, Func Offset: 0x78
	// Line 799, Address: 0x21a650, Func Offset: 0x80
	// Line 800, Address: 0x21a654, Func Offset: 0x84
	// Line 798, Address: 0x21a658, Func Offset: 0x88
	// Line 801, Address: 0x21a660, Func Offset: 0x90
	// Line 798, Address: 0x21a664, Func Offset: 0x94
	// Line 799, Address: 0x21a66c, Func Offset: 0x9c
	// Line 800, Address: 0x21a688, Func Offset: 0xb8
	// Line 801, Address: 0x21a6a0, Func Offset: 0xd0
	// Line 802, Address: 0x21a6a8, Func Offset: 0xd8
	// Line 804, Address: 0x21a6b8, Func Offset: 0xe8
	// Line 805, Address: 0x21a6bc, Func Offset: 0xec
	// Line 803, Address: 0x21a6c0, Func Offset: 0xf0
	// Line 805, Address: 0x21a6c4, Func Offset: 0xf4
	// Line 806, Address: 0x21a6cc, Func Offset: 0xfc
	// Line 807, Address: 0x21a6d8, Func Offset: 0x108
	// Line 808, Address: 0x21a6e4, Func Offset: 0x114
	// Line 807, Address: 0x21a6e8, Func Offset: 0x118
	// Line 809, Address: 0x21a6ec, Func Offset: 0x11c
	// Line 810, Address: 0x21a704, Func Offset: 0x134
	// Line 812, Address: 0x21a708, Func Offset: 0x138
	// Line 813, Address: 0x21a710, Func Offset: 0x140
	// Line 814, Address: 0x21a714, Func Offset: 0x144
	// Line 818, Address: 0x21a718, Func Offset: 0x148
	// Line 814, Address: 0x21a71c, Func Offset: 0x14c
	// Line 815, Address: 0x21a720, Func Offset: 0x150
	// Line 816, Address: 0x21a728, Func Offset: 0x158
	// Line 818, Address: 0x21a72c, Func Offset: 0x15c
	// Line 821, Address: 0x21a734, Func Offset: 0x164
	// Line 822, Address: 0x21a738, Func Offset: 0x168
	// Func End, Address: 0x21a764, Func Offset: 0x194
}

// 
// Start address: 0x21a770
void bhEne_AddNullTrans(BH_PWORK* epw, _anon6* mtn)
{
	_anon6 v;
	// Line 833, Address: 0x21a770, Func Offset: 0
	// Line 836, Address: 0x21a788, Func Offset: 0x18
	// Line 837, Address: 0x21a790, Func Offset: 0x20
	// Line 838, Address: 0x21a79c, Func Offset: 0x2c
	// Line 840, Address: 0x21a7c0, Func Offset: 0x50
	// Line 841, Address: 0x21a7d0, Func Offset: 0x60
	// Line 842, Address: 0x21a7e0, Func Offset: 0x70
	// Func End, Address: 0x21a7f4, Func Offset: 0x84
}

// 
// Start address: 0x21a800
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, _anon6* mtn)
{
	_anon6 v;
	// Line 853, Address: 0x21a800, Func Offset: 0
	// Line 856, Address: 0x21a820, Func Offset: 0x20
	// Line 857, Address: 0x21a828, Func Offset: 0x28
	// Line 858, Address: 0x21a834, Func Offset: 0x34
	// Line 860, Address: 0x21a858, Func Offset: 0x58
	// Line 861, Address: 0x21a868, Func Offset: 0x68
	// Line 862, Address: 0x21a878, Func Offset: 0x78
	// Func End, Address: 0x21a890, Func Offset: 0x90
}

// 
// Start address: 0x21a890
float bhEne_GetShapeCnt(_anon40* p, int key)
{
	_anon40* pp;
	// Line 878, Address: 0x21a890, Func Offset: 0
	// Line 880, Address: 0x21a8a0, Func Offset: 0x10
	// Line 882, Address: 0x21a8a8, Func Offset: 0x18
	// Line 885, Address: 0x21a8b8, Func Offset: 0x28
	// Line 886, Address: 0x21a8f4, Func Offset: 0x64
	// Func End, Address: 0x21a8fc, Func Offset: 0x6c
}

// 
// Start address: 0x21a900
void bhEne_CalcDamage(BH_PWORK* epw, _anon18* CombWepTbl, _anon20* CombJointTbl)
{
	_anon18* cwp;
	_anon20* cjp;
	unsigned int i;
	int dam;
	// Line 898, Address: 0x21a900, Func Offset: 0
	// Line 902, Address: 0x21a90c, Func Offset: 0xc
	// Line 905, Address: 0x21a910, Func Offset: 0x10
	// Line 908, Address: 0x21a91c, Func Offset: 0x1c
	// Line 902, Address: 0x21a920, Func Offset: 0x20
	// Line 905, Address: 0x21a924, Func Offset: 0x24
	// Line 902, Address: 0x21a92c, Func Offset: 0x2c
	// Line 908, Address: 0x21a930, Func Offset: 0x30
	// Line 902, Address: 0x21a934, Func Offset: 0x34
	// Line 908, Address: 0x21a938, Func Offset: 0x38
	// Line 902, Address: 0x21a93c, Func Offset: 0x3c
	// Line 908, Address: 0x21a944, Func Offset: 0x44
	// Line 910, Address: 0x21a94c, Func Offset: 0x4c
	// Line 912, Address: 0x21a954, Func Offset: 0x54
	// Line 914, Address: 0x21a960, Func Offset: 0x60
	// Line 915, Address: 0x21a970, Func Offset: 0x70
	// Line 916, Address: 0x21a98c, Func Offset: 0x8c
	// Line 917, Address: 0x21a990, Func Offset: 0x90
	// Line 919, Address: 0x21a998, Func Offset: 0x98
	// Line 920, Address: 0x21a9a0, Func Offset: 0xa0
	// Line 921, Address: 0x21a9a4, Func Offset: 0xa4
	// Line 922, Address: 0x21a9ac, Func Offset: 0xac
	// Line 924, Address: 0x21a9b0, Func Offset: 0xb0
	// Line 925, Address: 0x21a9d0, Func Offset: 0xd0
	// Line 926, Address: 0x21a9f0, Func Offset: 0xf0
	// Line 930, Address: 0x21aa10, Func Offset: 0x110
	// Line 931, Address: 0x21aa2c, Func Offset: 0x12c
	// Line 932, Address: 0x21aa38, Func Offset: 0x138
	// Line 933, Address: 0x21aa48, Func Offset: 0x148
	// Line 934, Address: 0x21aa4c, Func Offset: 0x14c
	// Line 936, Address: 0x21aa50, Func Offset: 0x150
	// Line 937, Address: 0x21aa7c, Func Offset: 0x17c
	// Line 939, Address: 0x21aa84, Func Offset: 0x184
	// Line 940, Address: 0x21aaac, Func Offset: 0x1ac
	// Line 943, Address: 0x21aab0, Func Offset: 0x1b0
	// Line 957, Address: 0x21aabc, Func Offset: 0x1bc
	// Line 943, Address: 0x21aac0, Func Offset: 0x1c0
	// Line 957, Address: 0x21aac4, Func Offset: 0x1c4
	// Line 960, Address: 0x21aae4, Func Offset: 0x1e4
	// Line 961, Address: 0x21aaf4, Func Offset: 0x1f4
	// Line 962, Address: 0x21aafc, Func Offset: 0x1fc
	// Line 963, Address: 0x21ab04, Func Offset: 0x204
	// Line 965, Address: 0x21ab10, Func Offset: 0x210
	// Func End, Address: 0x21ab20, Func Offset: 0x220
}*/

// 100% matching!
void bhEne_InitDamage(BH_PWORK* epw)
{
    int i;

    if (epw->mlwP != NULL) 
    {
        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            epw->dam[i] = 0;
        }
    }
    
    if (epw->comb_timeout != 0)
    {
        epw->comb_timeout--;
    }
    
    epw->comb_flg &= ~0x70;
    epw->flg2 &= ~0x4;
}

/*// 
// Start address: 0x21aba0
void bhEne_CallSE(BH_PWORK* epw, _anon6* pos, int se)
{
	// Line 1005, Address: 0x21aba0, Func Offset: 0
	// Line 1006, Address: 0x21aba8, Func Offset: 0x8
	// Line 1007, Address: 0x21abbc, Func Offset: 0x1c
	// Line 1009, Address: 0x21abd4, Func Offset: 0x34
	// Func End, Address: 0x21abe0, Func Offset: 0x40
}

// 
// Start address: 0x21abe0
void bhEne_CallSE_EX(BH_PWORK* epw, _anon6* pos, int se, int fade)
{
	// Line 1021, Address: 0x21abe0, Func Offset: 0
	// Line 1022, Address: 0x21abe8, Func Offset: 0x8
	// Line 1023, Address: 0x21abfc, Func Offset: 0x1c
	// Line 1025, Address: 0x21ac14, Func Offset: 0x34
	// Func End, Address: 0x21ac20, Func Offset: 0x40
}

// 
// Start address: 0x21ac20
void bhEne_CallEffectSE(_anon6* pos, int se)
{
	// Line 1037, Address: 0x21ac24, Func Offset: 0x4
	// Func End, Address: 0x21ac30, Func Offset: 0x10
}

// 
// Start address: 0x21ac30
void bhEne_SetSEPan(_anon6* pos, int se)
{
	// Line 1051, Address: 0x21ac30, Func Offset: 0
	// Func End, Address: 0x21ac50, Func Offset: 0x20
}

// 
// Start address: 0x21ac50
int bhEne_CheckPlayEffectSE(int se)
{
	// Line 1063, Address: 0x21ac54, Func Offset: 0x4
	// Func End, Address: 0x21ac5c, Func Offset: 0xc
}*/

// 
// Start address: 0x21ac60
int bhArcTan2(float y, float x)
{
	int ang;
	float len;
	// Line 1075, Address: 0x21ac60, Func Offset: 0
	// Line 1079, Address: 0x21ac74, Func Offset: 0x14
	// Line 1080, Address: 0x21ac84, Func Offset: 0x24
	// Line 1082, Address: 0x21aca4, Func Offset: 0x44
	// Line 1084, Address: 0x21acd4, Func Offset: 0x74
	// Line 1085, Address: 0x21acec, Func Offset: 0x8c
	// Line 1094, Address: 0x21acfc, Func Offset: 0x9c
	// Func End, Address: 0x21ad10, Func Offset: 0xb0
	scePrintf("bhArcTan2 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x21ad10
_anon21* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max)
{
	int flr_n;
	int i;
	_anon21* fp;
	// Line 1113, Address: 0x21ad10, Func Offset: 0
	// Line 1114, Address: 0x21ad34, Func Offset: 0x24
	// Line 1117, Address: 0x21ad44, Func Offset: 0x34
	// Line 1116, Address: 0x21ad48, Func Offset: 0x38
	// Line 1117, Address: 0x21ad84, Func Offset: 0x74
	// Line 1122, Address: 0x21adc8, Func Offset: 0xb8
	// Line 1125, Address: 0x21ae2c, Func Offset: 0x11c
	// Line 1128, Address: 0x21ae34, Func Offset: 0x124
	// Line 1129, Address: 0x21ae48, Func Offset: 0x138
	// Line 1130, Address: 0x21ae4c, Func Offset: 0x13c
	// Func End, Address: 0x21ae54, Func Offset: 0x144
}

// 
// Start address: 0x21ae60
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no)
{
	_anon0* op;
	int i;
	// Line 1145, Address: 0x21ae60, Func Offset: 0
	// Line 1146, Address: 0x21ae68, Func Offset: 0x8
	// Line 1148, Address: 0x21ae6c, Func Offset: 0xc
	// Line 1147, Address: 0x21ae70, Func Offset: 0x10
	// Line 1148, Address: 0x21ae8c, Func Offset: 0x2c
	// Line 1151, Address: 0x21aeb0, Func Offset: 0x50
	// Line 1153, Address: 0x21aeb4, Func Offset: 0x54
	// Line 1154, Address: 0x21aeb8, Func Offset: 0x58
	// Line 1155, Address: 0x21aec8, Func Offset: 0x68
	// Func End, Address: 0x21aed0, Func Offset: 0x70
}*/
