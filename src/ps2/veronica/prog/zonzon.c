#include "zonzon.h"
#include "hitchk.h"
#include "ps2_NinjaCnk.h"
#include "main.h"

// 100% matching! 
void ikou(BH_PWORK* epw, NJS_POINT3* pos, int add_dir)
{
	int ang;
	int rot;

    if ((epw->flg & 0x80) != 0)
    {
        return;
    }
    
    ang = NitenDir_ck(epw->px, epw->pz, pos->x, pos->z);
    if ((add_dir & 0x80000000) != 0) 
    {
        add_dir = -add_dir;
        ang = ang + 0x8000 & 0xffff;
    }

    rot = add_dir + (ang - epw->ay) & 0xffff;

    if (rot < (add_dir + add_dir))
    {
        epw->ay = ang;
    }
    else 
    {
        epw->ay -= add_dir;
        
        if (rot <= 0x8000)
        {
            epw->ay += (add_dir + add_dir);
        }
    }
}

// 100% matching!
int ikou3(BH_PWORK* epw, NJS_POINT3* pos, int add_dir)
{
    int rot;

    if((epw->flg & 0x80) != 0) 
    {
        return 0;
    }

    rot = NitenDir_ck(epw->px, epw->pz, pos->x, pos->z);
    rot = add_dir + (rot - epw->ay) & 0xffff;
    if ((int)rot < add_dir + add_dir) 
    {
        return 0;
    }
    
    if (rot < 0x8001) 
    {
        return add_dir;
    }
    
    return -add_dir;
}

// 100% matching!
int NitenDir_ck(float hontai_x, float hontai_z, float target_x, float target_z) 
{
    int uVar1;
    float fVar2;

    fVar2 = atan2f(hontai_x - target_x, hontai_z - target_z);
    uVar1 = (int)(fVar2 * 10430.381f);
    return uVar1;
}

// 100% matching!
int bhCdirCheck(int my_ang, int trg_ang) 
{    
   return (((my_ang - trg_ang) + 0x4000) & 0xffff) < 0x8000 ? 1 : 0;
}

// 100% matching!
int bhEne_LeverCheck() 
{
    int dec_cnt;
    
    dec_cnt = 0;

    if ((sys->pad_ps & 0xf) != 0)
    {
        dec_cnt = 4;
    }
    
    if ((sys->pad_ps & 0x2d00) != 0) 
    {
        dec_cnt += 3;
    }
    return dec_cnt;
}

// 100% matching!
int bhDGCdirCheck(NJS_VECTOR* dv, int rot) 
{
    NJS_VECTOR v1;
    NJS_VECTOR v0;
    
    v1.x = -njSin(rot);
    v1.z = -njCos(rot);
    v1.y = 0;

    v0.x = dv->x;
    v0.y = dv->y;
    v0.z = dv->z;
    
    njUnitVector(&v0);

    if (njInnerProduct(&v1, &v0) < 0.0f) 
    {
        return 0;
    }

    return 1;
}

// 100% matching!
int bhDGCdirCheck2(NJS_VECTOR* dv, O_WORK* owk)
{
    NJS_VECTOR v0;
    NJS_VECTOR v1;

    v1.x = 0;
    v1.y = 0;
    v1.z = -1.0f;

    njCalcVector((NJS_MATRIX*)owk->mtx, &v1, &v0);
    
    v1.x = dv->x;
    v1.y = dv->y;
    v1.z = dv->z;
    
    njUnitVector(&v1);
    
    if (njInnerProduct(&v0, &v1) < 0.0f) 
    {
        return 0;
    }
    return 1;
}

// 100% matching!
int bhDGCdirCheck3(NJS_VECTOR* dv, int rot) 
{
    int ang; // r2

    ang = ((int) (atan2f(dv->x, dv->z) * 10430.381f) - rot) & 0xffff;

    if ((ang < 0x2000) || (ang >= 0xE000))
    {
        return 0;
    }
    
    if ((ang >= 0x2000) && (ang < 0x6000))
    {
        return 1;
    }

    if (((ang >= 0x6000)) && (ang < 0xa000))
    {
        return 2;
    }
    
    if ((ang >= 0xA000) && (ang < 0xE000))
    {
        return 3;
    }

    return 3;
}

// 100% matching!
int bhEne_AngleCheck(NJS_VECTOR* vec, int rot, int chk_ang) {
    float n2;
    float n1; // Unused
    NJS_VECTOR v3;
    NJS_VECTOR v2;
    NJS_VECTOR v1;

    v3.x = 0;
    v3.y = 0;
    v3.z = -1.0f;
    
    njUnitMatrix(0);
    njRotateY(0, chk_ang);
    njCalcVector(0, &v3, &v2);
    njUnitMatrix(0);
    njRotateY(0, rot + 0x7FFF + 1);
    njCalcVector(0, &v3, &v1);
    njUnitVector(vec);
    n2 = njInnerProduct(&v3, &v2);

    if (njInnerProduct(vec, &v1) > n2) 
    {
        return 1;
    }
    
    return 0;
}/*

// 
// Start address: 0x216420
void bhEne_GetTranslateMtn(BH_PWORK* epw, int frm, int mode)
{
	_anon4 key;
	_anon14* mkfP;
	// Line 483, Address: 0x216420, Func Offset: 0
	// Line 486, Address: 0x21642c, Func Offset: 0xc
	// Line 490, Address: 0x216434, Func Offset: 0x14
	// Line 486, Address: 0x21643c, Func Offset: 0x1c
	// Line 490, Address: 0x216460, Func Offset: 0x40
	// Line 492, Address: 0x216478, Func Offset: 0x58
	// Line 494, Address: 0x216480, Func Offset: 0x60
	// Line 495, Address: 0x216488, Func Offset: 0x68
	// Line 496, Address: 0x216490, Func Offset: 0x70
	// Line 497, Address: 0x216494, Func Offset: 0x74
	// Line 500, Address: 0x21649c, Func Offset: 0x7c
	// Line 501, Address: 0x2164ac, Func Offset: 0x8c
	// Line 502, Address: 0x2164bc, Func Offset: 0x9c
	// Line 504, Address: 0x2164cc, Func Offset: 0xac
	// Line 506, Address: 0x2164d8, Func Offset: 0xb8
	// Line 507, Address: 0x2164e4, Func Offset: 0xc4
	// Line 508, Address: 0x2164f8, Func Offset: 0xd8
	// Line 509, Address: 0x21650c, Func Offset: 0xec
	// Line 512, Address: 0x21651c, Func Offset: 0xfc
	// Line 514, Address: 0x21655c, Func Offset: 0x13c
	// Func End, Address: 0x21656c, Func Offset: 0x14c
}

// 
// Start address: 0x216570
void bhEne_GetTranslateMtn2(BH_PWORK* epw, int frm, int mode)
{
	_anon4 key;
	_anon14* mkfP;
	// Line 533, Address: 0x216570, Func Offset: 0
	// Line 536, Address: 0x21657c, Func Offset: 0xc
	// Line 540, Address: 0x216584, Func Offset: 0x14
	// Line 536, Address: 0x21658c, Func Offset: 0x1c
	// Line 540, Address: 0x2165b0, Func Offset: 0x40
	// Line 545, Address: 0x2165c8, Func Offset: 0x58
	// Line 547, Address: 0x2165d0, Func Offset: 0x60
	// Line 548, Address: 0x2165d8, Func Offset: 0x68
	// Line 549, Address: 0x2165e0, Func Offset: 0x70
	// Line 550, Address: 0x2165e4, Func Offset: 0x74
	// Line 553, Address: 0x2165ec, Func Offset: 0x7c
	// Line 554, Address: 0x2165fc, Func Offset: 0x8c
	// Line 555, Address: 0x21660c, Func Offset: 0x9c
	// Line 557, Address: 0x21661c, Func Offset: 0xac
	// Line 558, Address: 0x216628, Func Offset: 0xb8
	// Line 559, Address: 0x216638, Func Offset: 0xc8
	// Func End, Address: 0x216648, Func Offset: 0xd8
}*/

// 100% matching!
void bhEne_CalcPartsPos(BH_PWORK* epw, NJS_MATRIX* mtx, NJS_POINT3* pos, char* tree, int parts_num, int clr_flg)
{   
    NJS_CNK_OBJECT* obj;
    int i; 
        
    if (clr_flg != 0)
    {
        njUnitMatrix(mtx);
        
        njTranslate(mtx, epw->px, epw->py, epw->pz);
        njRotateXYZ(mtx, epw->ax, epw->ay, epw->az);
    }

    for (i = 0; i < parts_num; i++, tree++) 
    {
        obj = &epw->mlwP->objP[*tree];
        
        njTranslate(mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
        njRotateXYZ(mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
    }

    njGetTranslation(mtx, pos);
}

/*// 
// Start address: 0x216760
_anon23* bhKaidanAtrCheck(BH_PWORK* epw, float len, int* idx)
{
	int etc_n;
	int i;
	float pz2;
	float pz;
	float px2;
	float px;
	_anon23* exp;
	// Line 623, Address: 0x216760, Func Offset: 0
	// Line 628, Address: 0x21677c, Func Offset: 0x1c
	// Line 629, Address: 0x216790, Func Offset: 0x30
	// Line 628, Address: 0x216794, Func Offset: 0x34
	// Line 629, Address: 0x216798, Func Offset: 0x38
	// Line 642, Address: 0x2167a0, Func Offset: 0x40
	// Line 629, Address: 0x2167a8, Func Offset: 0x48
	// Line 643, Address: 0x2167b0, Func Offset: 0x50
	// Line 642, Address: 0x2167b4, Func Offset: 0x54
	// Line 643, Address: 0x2167d0, Func Offset: 0x70
	// Line 660, Address: 0x2167e0, Func Offset: 0x80
	// Line 664, Address: 0x2167e4, Func Offset: 0x84
	// Line 660, Address: 0x2167e8, Func Offset: 0x88
	// Line 650, Address: 0x2167ec, Func Offset: 0x8c
	// Line 653, Address: 0x2167f0, Func Offset: 0x90
	// Line 646, Address: 0x2167f4, Func Offset: 0x94
	// Line 648, Address: 0x216830, Func Offset: 0xd0
	// Line 650, Address: 0x216840, Func Offset: 0xe0
	// Line 653, Address: 0x216854, Func Offset: 0xf4
	// Line 660, Address: 0x2168cc, Func Offset: 0x16c
	// Line 664, Address: 0x2168d0, Func Offset: 0x170
	// Line 661, Address: 0x2168d4, Func Offset: 0x174
	// Line 662, Address: 0x2168d8, Func Offset: 0x178
	// Line 664, Address: 0x2168dc, Func Offset: 0x17c
	// Line 666, Address: 0x2168f0, Func Offset: 0x190
	// Line 669, Address: 0x216914, Func Offset: 0x1b4
	// Line 674, Address: 0x21691c, Func Offset: 0x1bc
	// Line 677, Address: 0x21693c, Func Offset: 0x1dc
	// Line 684, Address: 0x216944, Func Offset: 0x1e4
	// Line 685, Address: 0x216958, Func Offset: 0x1f8
	// Line 686, Address: 0x21695c, Func Offset: 0x1fc
	// Func End, Address: 0x216978, Func Offset: 0x218
}*/

// 100% matching!
ATR_WORK* bhEne_EnemyAtariCheck(NJS_POINT3* pos, int flr_no, unsigned char id, unsigned char type) 
{
    ATR_WORK* fp;
    int i; 
    int flr_n; 

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (rom->flr_n > i)
        {
            fp = rom->flrp + i;
        }
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if (((fp->flg & 0x1)) && (fp->type == 2) && (bhEne_PosCheck(pos->x, pos->z, fp->px, fp->pz, fp->w, fp->d) != 0) && (fp->flr_no == flr_no) && ((fp->prm0 == id) && (fp->prm1 == type))) 
        {
            return fp;
        }
    }

    return NULL;
}

// 100% matching!
int bhEne_PosCheck(float px, float pz, float x, float z, float w, float h)
{
    if (x <= px) 
	{
        if (!((x + w) < px) && (z <= pz) && !((z + h) < pz)) 
		{
            return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne_SetBlood(BH_PWORK* epw, unsigned char type, BT_WORK* bt)
{
    O_WORK* owk; 
    NJS_POINT3 ofp; 
    NJS_POINT3 ps; 
    int fhit;
    BT_WORK* btp; // not from DWARF

    fhit = 0;
    
    owk = &epw->mlwP->owP[epw->djnt_no];
    
    if ((bt == NULL) || ((epw->wpnr_no == 13) || (epw->wpnr_no == 10)))
    {
        ps.x = epw->dpx - owk->mtx[12];
        ps.y = epw->dpy - owk->mtx[13];
        ps.z = epw->dpz - owk->mtx[14];
        
        njSetMatrix(NULL, &owk->mtx);
        njInvertMatrix(NULL);
        
        njCalcVector(NULL, &ps, &ofp);
    } 
    else 
    {
        if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, owk) == 0)
        {
            fhit = 1;
        }
        
        btp = &bt[epw->djnt_no];
        
        ofp.x = btp->x + (btp->xlen - ((2.0f * btp->xlen) * (-rand() / -2.1474836E9f)));
        ofp.y = btp->y + (btp->ylen - ((2.0f * btp->ylen) * (-rand() / -2.1474836E9f)));
        
        if (fhit != 0) 
        {
            ofp.z = -btp->z;
        }
        else 
        {
            ofp.z = btp->z;
        }
        
        epw->djnt_no = btp->lnk_obj;
    }
    
    bhEne_SetBlood2(epw, type, &ofp, plp->way);
}

/*// 
// Start address: 0x216d20
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, _anon4* ofp, short ry)
{
	_anon4 ps;
	_anon4 ps;
	_anon4 ps;
	_anon0* op;
	unsigned int bl_color;
	// Line 848, Address: 0x216d20, Func Offset: 0
	// Line 853, Address: 0x216d3c, Func Offset: 0x1c
	// Line 857, Address: 0x216d4c, Func Offset: 0x2c
	// Line 853, Address: 0x216d54, Func Offset: 0x34
	// Line 854, Address: 0x216d60, Func Offset: 0x40
	// Line 863, Address: 0x216d68, Func Offset: 0x48
	// Line 854, Address: 0x216d6c, Func Offset: 0x4c
	// Line 855, Address: 0x216d78, Func Offset: 0x58
	// Line 856, Address: 0x216d8c, Func Offset: 0x6c
	// Line 857, Address: 0x216da0, Func Offset: 0x80
	// Line 858, Address: 0x216db4, Func Offset: 0x94
	// Line 859, Address: 0x216dc8, Func Offset: 0xa8
	// Line 860, Address: 0x216ddc, Func Offset: 0xbc
	// Line 863, Address: 0x216df0, Func Offset: 0xd0
	// Line 865, Address: 0x216dfc, Func Offset: 0xdc
	// Line 866, Address: 0x216e08, Func Offset: 0xe8
	// Line 865, Address: 0x216e0c, Func Offset: 0xec
	// Line 867, Address: 0x216e14, Func Offset: 0xf4
	// Line 870, Address: 0x216e1c, Func Offset: 0xfc
	// Line 871, Address: 0x216e24, Func Offset: 0x104
	// Line 870, Address: 0x216e28, Func Offset: 0x108
	// Line 874, Address: 0x216e34, Func Offset: 0x114
	// Line 882, Address: 0x216e60, Func Offset: 0x140
	// Line 883, Address: 0x216e68, Func Offset: 0x148
	// Line 882, Address: 0x216e6c, Func Offset: 0x14c
	// Line 885, Address: 0x216e70, Func Offset: 0x150
	// Line 882, Address: 0x216e74, Func Offset: 0x154
	// Line 883, Address: 0x216e80, Func Offset: 0x160
	// Line 885, Address: 0x216e90, Func Offset: 0x170
	// Line 887, Address: 0x216e98, Func Offset: 0x178
	// Line 888, Address: 0x216eb0, Func Offset: 0x190
	// Line 889, Address: 0x216ec4, Func Offset: 0x1a4
	// Line 893, Address: 0x216ed8, Func Offset: 0x1b8
	// Line 897, Address: 0x216efc, Func Offset: 0x1dc
	// Line 903, Address: 0x216f04, Func Offset: 0x1e4
	// Line 904, Address: 0x216f10, Func Offset: 0x1f0
	// Line 906, Address: 0x216f14, Func Offset: 0x1f4
	// Line 903, Address: 0x216f18, Func Offset: 0x1f8
	// Line 904, Address: 0x216f24, Func Offset: 0x204
	// Line 911, Address: 0x216f2c, Func Offset: 0x20c
	// Line 904, Address: 0x216f34, Func Offset: 0x214
	// Line 905, Address: 0x216f40, Func Offset: 0x220
	// Line 906, Address: 0x216f54, Func Offset: 0x234
	// Line 907, Address: 0x216f68, Func Offset: 0x248
	// Line 908, Address: 0x216f7c, Func Offset: 0x25c
	// Line 911, Address: 0x216f90, Func Offset: 0x270
	// Line 913, Address: 0x216fac, Func Offset: 0x28c
	// Line 917, Address: 0x216fb0, Func Offset: 0x290
	// Line 913, Address: 0x216fc0, Func Offset: 0x2a0
	// Line 914, Address: 0x216fc8, Func Offset: 0x2a8
	// Line 915, Address: 0x216fd4, Func Offset: 0x2b4
	// Line 916, Address: 0x216fe0, Func Offset: 0x2c0
	// Line 917, Address: 0x216fe4, Func Offset: 0x2c4
	// Line 919, Address: 0x216ff0, Func Offset: 0x2d0
	// Line 922, Address: 0x216ff8, Func Offset: 0x2d8
	// Line 923, Address: 0x21700c, Func Offset: 0x2ec
	// Line 924, Address: 0x21701c, Func Offset: 0x2fc
	// Line 925, Address: 0x21702c, Func Offset: 0x30c
	// Line 926, Address: 0x217048, Func Offset: 0x328
	// Line 929, Address: 0x217050, Func Offset: 0x330
	// Line 930, Address: 0x21705c, Func Offset: 0x33c
	// Line 931, Address: 0x217060, Func Offset: 0x340
	// Line 929, Address: 0x217064, Func Offset: 0x344
	// Line 930, Address: 0x217070, Func Offset: 0x350
	// Line 936, Address: 0x217078, Func Offset: 0x358
	// Line 930, Address: 0x217080, Func Offset: 0x360
	// Line 931, Address: 0x21708c, Func Offset: 0x36c
	// Line 932, Address: 0x2170a0, Func Offset: 0x380
	// Line 933, Address: 0x2170b4, Func Offset: 0x394
	// Line 936, Address: 0x2170c8, Func Offset: 0x3a8
	// Line 959, Address: 0x2170e4, Func Offset: 0x3c4
	// Line 962, Address: 0x2170ec, Func Offset: 0x3cc
	// Line 965, Address: 0x2170f8, Func Offset: 0x3d8
	// Line 966, Address: 0x2170fc, Func Offset: 0x3dc
	// Line 962, Address: 0x217100, Func Offset: 0x3e0
	// Line 963, Address: 0x21710c, Func Offset: 0x3ec
	// Line 968, Address: 0x217114, Func Offset: 0x3f4
	// Line 963, Address: 0x21711c, Func Offset: 0x3fc
	// Line 964, Address: 0x217128, Func Offset: 0x408
	// Line 965, Address: 0x21713c, Func Offset: 0x41c
	// Line 966, Address: 0x217150, Func Offset: 0x430
	// Line 968, Address: 0x217164, Func Offset: 0x444
	// Line 973, Address: 0x217180, Func Offset: 0x460
	// Line 974, Address: 0x217194, Func Offset: 0x474
	// Line 975, Address: 0x2171a4, Func Offset: 0x484
	// Line 976, Address: 0x2171b4, Func Offset: 0x494
	// Line 977, Address: 0x2171b8, Func Offset: 0x498
	// Line 978, Address: 0x2171d4, Func Offset: 0x4b4
	// Line 982, Address: 0x2171dc, Func Offset: 0x4bc
	// Line 983, Address: 0x2171e8, Func Offset: 0x4c8
	// Line 985, Address: 0x2171ec, Func Offset: 0x4cc
	// Line 982, Address: 0x2171f0, Func Offset: 0x4d0
	// Line 983, Address: 0x2171fc, Func Offset: 0x4dc
	// Line 988, Address: 0x217204, Func Offset: 0x4e4
	// Line 983, Address: 0x21720c, Func Offset: 0x4ec
	// Line 984, Address: 0x217218, Func Offset: 0x4f8
	// Line 985, Address: 0x21722c, Func Offset: 0x50c
	// Line 986, Address: 0x217240, Func Offset: 0x520
	// Line 987, Address: 0x217254, Func Offset: 0x534
	// Line 988, Address: 0x217268, Func Offset: 0x548
	// Line 991, Address: 0x217284, Func Offset: 0x564
	// Line 995, Address: 0x217288, Func Offset: 0x568
	// Line 991, Address: 0x217294, Func Offset: 0x574
	// Line 992, Address: 0x21729c, Func Offset: 0x57c
	// Line 995, Address: 0x2172a0, Func Offset: 0x580
	// Line 992, Address: 0x2172a4, Func Offset: 0x584
	// Line 993, Address: 0x2172ac, Func Offset: 0x58c
	// Line 994, Address: 0x2172b8, Func Offset: 0x598
	// Line 995, Address: 0x2172bc, Func Offset: 0x59c
	// Line 997, Address: 0x2172c8, Func Offset: 0x5a8
	// Line 1002, Address: 0x2172d0, Func Offset: 0x5b0
	// Line 1006, Address: 0x2172d4, Func Offset: 0x5b4
	// Line 1002, Address: 0x2172e0, Func Offset: 0x5c0
	// Line 1003, Address: 0x2172e8, Func Offset: 0x5c8
	// Line 1006, Address: 0x2172ec, Func Offset: 0x5cc
	// Line 1003, Address: 0x2172f0, Func Offset: 0x5d0
	// Line 1004, Address: 0x2172f8, Func Offset: 0x5d8
	// Line 1005, Address: 0x217304, Func Offset: 0x5e4
	// Line 1006, Address: 0x217308, Func Offset: 0x5e8
	// Line 1008, Address: 0x217314, Func Offset: 0x5f4
	// Line 1027, Address: 0x21731c, Func Offset: 0x5fc
	// Line 1028, Address: 0x217320, Func Offset: 0x600
	// Line 1029, Address: 0x217338, Func Offset: 0x618
	// Line 1044, Address: 0x217340, Func Offset: 0x620
	// Line 1046, Address: 0x217354, Func Offset: 0x634
	// Line 1050, Address: 0x217364, Func Offset: 0x644
	// Line 1051, Address: 0x217374, Func Offset: 0x654
	// Line 1053, Address: 0x217378, Func Offset: 0x658
	// Line 1055, Address: 0x217394, Func Offset: 0x674
	// Line 1058, Address: 0x21739c, Func Offset: 0x67c
	// Func End, Address: 0x2173b8, Func Offset: 0x698
}

// 
// Start address: 0x2173c0
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, _anon4* ofs, _anon4* dv, int n, int tex_id, int type, int wcnt)
{
	int eno;
	// Line 1086, Address: 0x2173c0, Func Offset: 0
	// Line 1089, Address: 0x2173dc, Func Offset: 0x1c
	// Line 1090, Address: 0x217400, Func Offset: 0x40
	// Line 1092, Address: 0x21740c, Func Offset: 0x4c
	// Line 1096, Address: 0x217410, Func Offset: 0x50
	// Line 1090, Address: 0x217414, Func Offset: 0x54
	// Line 1091, Address: 0x217420, Func Offset: 0x60
	// Line 1092, Address: 0x21743c, Func Offset: 0x7c
	// Line 1093, Address: 0x217450, Func Offset: 0x90
	// Line 1094, Address: 0x217464, Func Offset: 0xa4
	// Line 1096, Address: 0x217474, Func Offset: 0xb4
	// Line 1098, Address: 0x21747c, Func Offset: 0xbc
	// Line 1101, Address: 0x217484, Func Offset: 0xc4
	// Line 1098, Address: 0x217490, Func Offset: 0xd0
	// Line 1099, Address: 0x21749c, Func Offset: 0xdc
	// Line 1100, Address: 0x2174b0, Func Offset: 0xf0
	// Line 1101, Address: 0x2174c4, Func Offset: 0x104
	// Line 1102, Address: 0x2174dc, Func Offset: 0x11c
	// Line 1105, Address: 0x2174e4, Func Offset: 0x124
	// Line 1108, Address: 0x2174f0, Func Offset: 0x130
	// Line 1105, Address: 0x2174f8, Func Offset: 0x138
	// Line 1106, Address: 0x217504, Func Offset: 0x144
	// Line 1107, Address: 0x21751c, Func Offset: 0x15c
	// Line 1108, Address: 0x217534, Func Offset: 0x174
	// Line 1111, Address: 0x217550, Func Offset: 0x190
	// Line 1113, Address: 0x21755c, Func Offset: 0x19c
	// Line 1114, Address: 0x21757c, Func Offset: 0x1bc
	// Line 1113, Address: 0x217584, Func Offset: 0x1c4
	// Line 1114, Address: 0x217588, Func Offset: 0x1c8
	// Line 1113, Address: 0x21758c, Func Offset: 0x1cc
	// Line 1114, Address: 0x217594, Func Offset: 0x1d4
	// Line 1115, Address: 0x217598, Func Offset: 0x1d8
	// Line 1114, Address: 0x2175a4, Func Offset: 0x1e4
	// Line 1116, Address: 0x2175a8, Func Offset: 0x1e8
	// Line 1114, Address: 0x2175b0, Func Offset: 0x1f0
	// Line 1115, Address: 0x2175b4, Func Offset: 0x1f4
	// Line 1116, Address: 0x2175b8, Func Offset: 0x1f8
	// Line 1117, Address: 0x2175c0, Func Offset: 0x200
	// Line 1116, Address: 0x2175cc, Func Offset: 0x20c
	// Line 1117, Address: 0x2175d0, Func Offset: 0x210
	// Line 1118, Address: 0x2175d4, Func Offset: 0x214
	// Line 1117, Address: 0x2175e0, Func Offset: 0x220
	// Line 1118, Address: 0x2175e4, Func Offset: 0x224
	// Line 1119, Address: 0x2175e8, Func Offset: 0x228
	// Line 1118, Address: 0x2175f4, Func Offset: 0x234
	// Line 1119, Address: 0x2175f8, Func Offset: 0x238
	// Line 1120, Address: 0x2175fc, Func Offset: 0x23c
	// Line 1122, Address: 0x21760c, Func Offset: 0x24c
	// Func End, Address: 0x21762c, Func Offset: 0x26c
}

// 
// Start address: 0x217630
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, _anon4* ofs, int tex_id, int type)
{
	int i;
	int ang;
	int angY;
	_anon4 v;
	_anon4 ps;
	_anon6* tbl;
	int blood_n[4];
	_anon6 bld_tbl[20];
	// Line 1146, Address: 0x217630, Func Offset: 0
	// Line 1186, Address: 0x21765c, Func Offset: 0x2c
	// Line 1187, Address: 0x217664, Func Offset: 0x34
	// Line 1146, Address: 0x21766c, Func Offset: 0x3c
	// Line 1187, Address: 0x217680, Func Offset: 0x50
	// Line 1192, Address: 0x217688, Func Offset: 0x58
	// Line 1194, Address: 0x2176b0, Func Offset: 0x80
	// Line 1198, Address: 0x2176b4, Func Offset: 0x84
	// Line 1199, Address: 0x2176c0, Func Offset: 0x90
	// Line 1202, Address: 0x2176c4, Func Offset: 0x94
	// Line 1196, Address: 0x2176c8, Func Offset: 0x98
	// Line 1199, Address: 0x2176cc, Func Offset: 0x9c
	// Line 1200, Address: 0x2176d4, Func Offset: 0xa4
	// Line 1201, Address: 0x2176e0, Func Offset: 0xb0
	// Line 1202, Address: 0x2176e8, Func Offset: 0xb8
	// Line 1203, Address: 0x2176f0, Func Offset: 0xc0
	// Line 1204, Address: 0x217714, Func Offset: 0xe4
	// Line 1205, Address: 0x21771c, Func Offset: 0xec
	// Line 1207, Address: 0x217728, Func Offset: 0xf8
	// Line 1210, Address: 0x217738, Func Offset: 0x108
	// Line 1212, Address: 0x217740, Func Offset: 0x110
	// Line 1214, Address: 0x217750, Func Offset: 0x120
	// Line 1216, Address: 0x217754, Func Offset: 0x124
	// Line 1214, Address: 0x217758, Func Offset: 0x128
	// Line 1216, Address: 0x21775c, Func Offset: 0x12c
	// Line 1217, Address: 0x21777c, Func Offset: 0x14c
	// Line 1218, Address: 0x217788, Func Offset: 0x158
	// Line 1223, Address: 0x2177a0, Func Offset: 0x170
	// Line 1218, Address: 0x2177a8, Func Offset: 0x178
	// Line 1220, Address: 0x2177b0, Func Offset: 0x180
	// Line 1223, Address: 0x2177b8, Func Offset: 0x188
	// Line 1220, Address: 0x2177c0, Func Offset: 0x190
	// Line 1221, Address: 0x2177c8, Func Offset: 0x198
	// Line 1222, Address: 0x2177d8, Func Offset: 0x1a8
	// Line 1223, Address: 0x2177e8, Func Offset: 0x1b8
	// Line 1225, Address: 0x2177fc, Func Offset: 0x1cc
	// Line 1226, Address: 0x217810, Func Offset: 0x1e0
	// Func End, Address: 0x217844, Func Offset: 0x214
}

// 
// Start address: 0x217850
void bhEne_SetNikuhenEffect(BH_PWORK* epw, int type, _anon4* pos, _anon4* v, int tex_id)
{
	int eno;
	// Line 1311, Address: 0x217850, Func Offset: 0
	// Line 1314, Address: 0x217864, Func Offset: 0x14
	// Line 1315, Address: 0x217874, Func Offset: 0x24
	// Line 1314, Address: 0x217878, Func Offset: 0x28
	// Line 1315, Address: 0x217884, Func Offset: 0x34
	// Line 1316, Address: 0x2178a0, Func Offset: 0x50
	// Line 1317, Address: 0x2178b4, Func Offset: 0x64
	// Line 1318, Address: 0x2178cc, Func Offset: 0x7c
	// Line 1319, Address: 0x2178e4, Func Offset: 0x94
	// Line 1320, Address: 0x2178f8, Func Offset: 0xa8
	// Line 1323, Address: 0x21791c, Func Offset: 0xcc
	// Line 1320, Address: 0x217924, Func Offset: 0xd4
	// Line 1323, Address: 0x21793c, Func Offset: 0xec
	// Line 1320, Address: 0x217940, Func Offset: 0xf0
	// Line 1321, Address: 0x217948, Func Offset: 0xf8
	// Line 1322, Address: 0x217968, Func Offset: 0x118
	// Line 1323, Address: 0x21797c, Func Offset: 0x12c
	// Line 1324, Address: 0x217994, Func Offset: 0x144
	// Line 1326, Address: 0x2179a0, Func Offset: 0x150
	// Line 1327, Address: 0x2179c4, Func Offset: 0x174
	// Line 1326, Address: 0x2179d0, Func Offset: 0x180
	// Line 1327, Address: 0x2179d8, Func Offset: 0x188
	// Line 1328, Address: 0x2179dc, Func Offset: 0x18c
	// Line 1327, Address: 0x2179e8, Func Offset: 0x198
	// Line 1329, Address: 0x2179ec, Func Offset: 0x19c
	// Line 1327, Address: 0x2179f4, Func Offset: 0x1a4
	// Line 1328, Address: 0x2179f8, Func Offset: 0x1a8
	// Line 1329, Address: 0x2179fc, Func Offset: 0x1ac
	// Line 1330, Address: 0x217a04, Func Offset: 0x1b4
	// Line 1329, Address: 0x217a0c, Func Offset: 0x1bc
	// Line 1330, Address: 0x217a10, Func Offset: 0x1c0
	// Line 1331, Address: 0x217a18, Func Offset: 0x1c8
	// Line 1330, Address: 0x217a20, Func Offset: 0x1d0
	// Line 1331, Address: 0x217a24, Func Offset: 0x1d4
	// Line 1333, Address: 0x217a30, Func Offset: 0x1e0
	// Func End, Address: 0x217a48, Func Offset: 0x1f8
}

// 
// Start address: 0x217a50
void bhEne_SetNikuhenEffect2(BH_PWORK* epw, int type, _anon4* pos, int n, int tex_id)
{
	int i;
	int angZ;
	int angY;
	_anon4 v2;
	_anon4 v;
	// Line 1358, Address: 0x217a50, Func Offset: 0
	// Line 1363, Address: 0x217a78, Func Offset: 0x28
	// Line 1365, Address: 0x217a94, Func Offset: 0x44
	// Line 1367, Address: 0x217a9c, Func Offset: 0x4c
	// Line 1368, Address: 0x217ab8, Func Offset: 0x68
	// Line 1374, Address: 0x217ac8, Func Offset: 0x78
	// Line 1368, Address: 0x217ad4, Func Offset: 0x84
	// Line 1374, Address: 0x217ad8, Func Offset: 0x88
	// Line 1375, Address: 0x217ae0, Func Offset: 0x90
	// Line 1378, Address: 0x217ae4, Func Offset: 0x94
	// Line 1375, Address: 0x217ae8, Func Offset: 0x98
	// Line 1376, Address: 0x217af0, Func Offset: 0xa0
	// Line 1377, Address: 0x217afc, Func Offset: 0xac
	// Line 1378, Address: 0x217b04, Func Offset: 0xb4
	// Line 1379, Address: 0x217b0c, Func Offset: 0xbc
	// Line 1380, Address: 0x217b1c, Func Offset: 0xcc
	// Line 1381, Address: 0x217b34, Func Offset: 0xe4
	// Line 1382, Address: 0x217b48, Func Offset: 0xf8
	// Func End, Address: 0x217b70, Func Offset: 0x120
}

// 
// Start address: 0x217b70
int bhEne_SetDFireEffect(BH_PWORK* epw, int no, _anon10* ltbl, int type)
{
	int i;
	int fmax;
	int obj_num;
	_anon4 pos;
	_anon4 vec;
	_anon20* owk;
	_anon1* wp;
	_anon1 work[42];
	// Line 1404, Address: 0x217b70, Func Offset: 0
	// Line 1412, Address: 0x217b98, Func Offset: 0x28
	// Line 1413, Address: 0x217bac, Func Offset: 0x3c
	// Line 1416, Address: 0x217bc0, Func Offset: 0x50
	// Line 1417, Address: 0x217bc4, Func Offset: 0x54
	// Line 1422, Address: 0x217bc8, Func Offset: 0x58
	// Line 1419, Address: 0x217bcc, Func Offset: 0x5c
	// Line 1420, Address: 0x217bd0, Func Offset: 0x60
	// Line 1422, Address: 0x217bd4, Func Offset: 0x64
	// Line 1421, Address: 0x217bd8, Func Offset: 0x68
	// Line 1422, Address: 0x217bdc, Func Offset: 0x6c
	// Line 1425, Address: 0x217be4, Func Offset: 0x74
	// Line 1427, Address: 0x217c08, Func Offset: 0x98
	// Line 1428, Address: 0x217c0c, Func Offset: 0x9c
	// Line 1429, Address: 0x217c10, Func Offset: 0xa0
	// Line 1427, Address: 0x217c14, Func Offset: 0xa4
	// Line 1429, Address: 0x217c18, Func Offset: 0xa8
	// Line 1432, Address: 0x217c20, Func Offset: 0xb0
	// Line 1434, Address: 0x217c30, Func Offset: 0xc0
	// Line 1435, Address: 0x217c38, Func Offset: 0xc8
	// Line 1436, Address: 0x217c3c, Func Offset: 0xcc
	// Line 1437, Address: 0x217c40, Func Offset: 0xd0
	// Line 1434, Address: 0x217c44, Func Offset: 0xd4
	// Line 1435, Address: 0x217c4c, Func Offset: 0xdc
	// Line 1436, Address: 0x217c58, Func Offset: 0xe8
	// Line 1437, Address: 0x217c60, Func Offset: 0xf0
	// Line 1438, Address: 0x217c68, Func Offset: 0xf8
	// Line 1441, Address: 0x217c70, Func Offset: 0x100
	// Line 1442, Address: 0x217c7c, Func Offset: 0x10c
	// Line 1445, Address: 0x217c80, Func Offset: 0x110
	// Line 1443, Address: 0x217c84, Func Offset: 0x114
	// Line 1445, Address: 0x217c88, Func Offset: 0x118
	// Line 1448, Address: 0x217c98, Func Offset: 0x128
	// Line 1450, Address: 0x217ca8, Func Offset: 0x138
	// Line 1452, Address: 0x217cb4, Func Offset: 0x144
	// Line 1453, Address: 0x217cb8, Func Offset: 0x148
	// Line 1461, Address: 0x217cbc, Func Offset: 0x14c
	// Line 1464, Address: 0x217cd0, Func Offset: 0x160
	// Line 1466, Address: 0x217ce0, Func Offset: 0x170
	// Line 1467, Address: 0x217cf4, Func Offset: 0x184
	// Line 1469, Address: 0x217d08, Func Offset: 0x198
	// Line 1470, Address: 0x217d0c, Func Offset: 0x19c
	// Func End, Address: 0x217d38, Func Offset: 0x1c8
}

// 
// Start address: 0x217d40
void bhEne_SetDFireEffect2(BH_PWORK* epw, int no, _anon10* ltbl, int type)
{
	_anon41 line;
	int time;
	int eno;
	_anon4 gpos;
	_anon4 ofp;
	// Line 1491, Address: 0x217d40, Func Offset: 0
	// Line 1499, Address: 0x217d5c, Func Offset: 0x1c
	// Line 1503, Address: 0x217d7c, Func Offset: 0x3c
	// Line 1508, Address: 0x217d80, Func Offset: 0x40
	// Line 1517, Address: 0x217d84, Func Offset: 0x44
	// Line 1503, Address: 0x217d8c, Func Offset: 0x4c
	// Line 1504, Address: 0x217d90, Func Offset: 0x50
	// Line 1505, Address: 0x217d98, Func Offset: 0x58
	// Line 1507, Address: 0x217da0, Func Offset: 0x60
	// Line 1508, Address: 0x217da4, Func Offset: 0x64
	// Line 1517, Address: 0x217da8, Func Offset: 0x68
	// Line 1518, Address: 0x217db0, Func Offset: 0x70
	// Line 1519, Address: 0x217dbc, Func Offset: 0x7c
	// Line 1522, Address: 0x217dc4, Func Offset: 0x84
	// Line 1540, Address: 0x217dcc, Func Offset: 0x8c
	// Line 1526, Address: 0x217dd4, Func Offset: 0x94
	// Line 1528, Address: 0x217de0, Func Offset: 0xa0
	// Line 1526, Address: 0x217de4, Func Offset: 0xa4
	// Line 1527, Address: 0x217df0, Func Offset: 0xb0
	// Line 1528, Address: 0x217e04, Func Offset: 0xc4
	// Line 1530, Address: 0x217e18, Func Offset: 0xd8
	// Line 1531, Address: 0x217e2c, Func Offset: 0xec
	// Line 1532, Address: 0x217e40, Func Offset: 0x100
	// Line 1538, Address: 0x217e54, Func Offset: 0x114
	// Line 1542, Address: 0x217e64, Func Offset: 0x124
	// Line 1543, Address: 0x217e80, Func Offset: 0x140
	// Line 1544, Address: 0x217edc, Func Offset: 0x19c
	// Line 1547, Address: 0x217ef0, Func Offset: 0x1b0
	// Line 1548, Address: 0x217f30, Func Offset: 0x1f0
	// Line 1554, Address: 0x217f4c, Func Offset: 0x20c
	// Line 1548, Address: 0x217f50, Func Offset: 0x210
	// Line 1554, Address: 0x217f74, Func Offset: 0x234
	// Line 1556, Address: 0x217f9c, Func Offset: 0x25c
	// Line 1557, Address: 0x217fa4, Func Offset: 0x264
	// Line 1560, Address: 0x217fac, Func Offset: 0x26c
	// Line 1564, Address: 0x217fb4, Func Offset: 0x274
	// Line 1565, Address: 0x217fc0, Func Offset: 0x280
	// Line 1564, Address: 0x217fc4, Func Offset: 0x284
	// Line 1565, Address: 0x217fc8, Func Offset: 0x288
	// Line 1564, Address: 0x217fcc, Func Offset: 0x28c
	// Line 1565, Address: 0x217fd8, Func Offset: 0x298
	// Line 1566, Address: 0x217ff4, Func Offset: 0x2b4
	// Line 1568, Address: 0x218000, Func Offset: 0x2c0
	// Line 1569, Address: 0x218028, Func Offset: 0x2e8
	// Line 1570, Address: 0x218038, Func Offset: 0x2f8
	// Line 1573, Address: 0x21804c, Func Offset: 0x30c
	// Line 1574, Address: 0x218058, Func Offset: 0x318
	// Line 1573, Address: 0x218060, Func Offset: 0x320
	// Line 1574, Address: 0x21806c, Func Offset: 0x32c
	// Line 1575, Address: 0x218088, Func Offset: 0x348
	// Line 1577, Address: 0x218094, Func Offset: 0x354
	// Line 1578, Address: 0x2180bc, Func Offset: 0x37c
	// Line 1579, Address: 0x2180cc, Func Offset: 0x38c
	// Line 1581, Address: 0x2180e0, Func Offset: 0x3a0
	// Func End, Address: 0x218100, Func Offset: 0x3c0
}

// 
// Start address: 0x218100
int bhEne_SetSanEffect(BH_PWORK* epw, int no, _anon10* ltbl)
{
	int i;
	int obj_num;
	_anon4 pos;
	_anon4 vec;
	_anon20* owk;
	_anon1* wp;
	_anon1 work[42];
	// Line 1601, Address: 0x218100, Func Offset: 0
	// Line 1610, Address: 0x218124, Func Offset: 0x24
	// Line 1611, Address: 0x218134, Func Offset: 0x34
	// Line 1614, Address: 0x218148, Func Offset: 0x48
	// Line 1615, Address: 0x21814c, Func Offset: 0x4c
	// Line 1620, Address: 0x218150, Func Offset: 0x50
	// Line 1617, Address: 0x218154, Func Offset: 0x54
	// Line 1618, Address: 0x218158, Func Offset: 0x58
	// Line 1620, Address: 0x21815c, Func Offset: 0x5c
	// Line 1619, Address: 0x218160, Func Offset: 0x60
	// Line 1620, Address: 0x218164, Func Offset: 0x64
	// Line 1623, Address: 0x21816c, Func Offset: 0x6c
	// Line 1625, Address: 0x218190, Func Offset: 0x90
	// Line 1626, Address: 0x218194, Func Offset: 0x94
	// Line 1627, Address: 0x218198, Func Offset: 0x98
	// Line 1625, Address: 0x21819c, Func Offset: 0x9c
	// Line 1627, Address: 0x2181a0, Func Offset: 0xa0
	// Line 1630, Address: 0x2181a8, Func Offset: 0xa8
	// Line 1632, Address: 0x2181b8, Func Offset: 0xb8
	// Line 1633, Address: 0x2181c0, Func Offset: 0xc0
	// Line 1634, Address: 0x2181c4, Func Offset: 0xc4
	// Line 1635, Address: 0x2181c8, Func Offset: 0xc8
	// Line 1632, Address: 0x2181cc, Func Offset: 0xcc
	// Line 1633, Address: 0x2181d4, Func Offset: 0xd4
	// Line 1634, Address: 0x2181e0, Func Offset: 0xe0
	// Line 1635, Address: 0x2181e8, Func Offset: 0xe8
	// Line 1636, Address: 0x2181f0, Func Offset: 0xf0
	// Line 1639, Address: 0x2181f8, Func Offset: 0xf8
	// Line 1640, Address: 0x218204, Func Offset: 0x104
	// Line 1643, Address: 0x218208, Func Offset: 0x108
	// Line 1641, Address: 0x21820c, Func Offset: 0x10c
	// Line 1643, Address: 0x218210, Func Offset: 0x110
	// Line 1646, Address: 0x218220, Func Offset: 0x120
	// Line 1649, Address: 0x218230, Func Offset: 0x130
	// Line 1652, Address: 0x218240, Func Offset: 0x140
	// Line 1654, Address: 0x218248, Func Offset: 0x148
	// Line 1655, Address: 0x218258, Func Offset: 0x158
	// Line 1657, Address: 0x218268, Func Offset: 0x168
	// Line 1658, Address: 0x21826c, Func Offset: 0x16c
	// Func End, Address: 0x218294, Func Offset: 0x194
}

// 
// Start address: 0x2182a0
int bhEne_SetSanEffect2(BH_PWORK* epw, int no, _anon10* ltbl)
{
	_anon4 ofp;
	_anon20* owk;
	// Line 1677, Address: 0x2182a0, Func Offset: 0
	// Line 1683, Address: 0x2182b8, Func Offset: 0x18
	// Line 1684, Address: 0x2182c8, Func Offset: 0x28
	// Line 1683, Address: 0x2182cc, Func Offset: 0x2c
	// Line 1684, Address: 0x2182d8, Func Offset: 0x38
	// Line 1686, Address: 0x2182f4, Func Offset: 0x54
	// Line 1687, Address: 0x218308, Func Offset: 0x68
	// Line 1688, Address: 0x21831c, Func Offset: 0x7c
	// Line 1694, Address: 0x218330, Func Offset: 0x90
	// Line 1695, Address: 0x218340, Func Offset: 0xa0
	// Line 1697, Address: 0x21836c, Func Offset: 0xcc
	// Line 1695, Address: 0x218378, Func Offset: 0xd8
	// Line 1698, Address: 0x21837c, Func Offset: 0xdc
	// Line 1695, Address: 0x218380, Func Offset: 0xe0
	// Line 1698, Address: 0x218384, Func Offset: 0xe4
	// Line 1695, Address: 0x218388, Func Offset: 0xe8
	// Line 1697, Address: 0x21838c, Func Offset: 0xec
	// Line 1700, Address: 0x218394, Func Offset: 0xf4
	// Line 1701, Address: 0x2183f0, Func Offset: 0x150
	// Line 1704, Address: 0x218404, Func Offset: 0x164
	// Line 1705, Address: 0x218444, Func Offset: 0x1a4
	// Line 1711, Address: 0x218460, Func Offset: 0x1c0
	// Line 1710, Address: 0x218464, Func Offset: 0x1c4
	// Line 1711, Address: 0x218468, Func Offset: 0x1c8
	// Line 1705, Address: 0x21846c, Func Offset: 0x1cc
	// Line 1711, Address: 0x218490, Func Offset: 0x1f0
	// Line 1713, Address: 0x2184a0, Func Offset: 0x200
	// Line 1714, Address: 0x2184a8, Func Offset: 0x208
	// Line 1717, Address: 0x2184b0, Func Offset: 0x210
	// Line 1719, Address: 0x2184b8, Func Offset: 0x218
	// Line 1720, Address: 0x2184dc, Func Offset: 0x23c
	// Func End, Address: 0x2184f8, Func Offset: 0x258
}

// 
// Start address: 0x218500
void bhEne_QuickSort(_anon1* a, int first, int last)
{
	float t;
	float x;
	int indx;
	int j;
	int i;
	// Line 1739, Address: 0x218500, Func Offset: 0
	// Line 1744, Address: 0x218518, Func Offset: 0x18
	// Line 1746, Address: 0x218524, Func Offset: 0x24
	// Line 1747, Address: 0x218538, Func Offset: 0x38
	// Line 1748, Address: 0x21853c, Func Offset: 0x3c
	// Line 1752, Address: 0x218544, Func Offset: 0x44
	// Line 1753, Address: 0x218570, Func Offset: 0x70
	// Line 1754, Address: 0x218594, Func Offset: 0x94
	// Line 1755, Address: 0x2185a0, Func Offset: 0xa0
	// Line 1758, Address: 0x2185a8, Func Offset: 0xa8
	// Line 1755, Address: 0x2185b0, Func Offset: 0xb0
	// Line 1756, Address: 0x2185b4, Func Offset: 0xb4
	// Line 1758, Address: 0x2185b8, Func Offset: 0xb8
	// Line 1763, Address: 0x2185bc, Func Offset: 0xbc
	// Line 1764, Address: 0x2185c0, Func Offset: 0xc0
	// Line 1758, Address: 0x2185c4, Func Offset: 0xc4
	// Line 1759, Address: 0x2185c8, Func Offset: 0xc8
	// Line 1761, Address: 0x2185d0, Func Offset: 0xd0
	// Line 1765, Address: 0x2185d4, Func Offset: 0xd4
	// Line 1767, Address: 0x2185dc, Func Offset: 0xdc
	// Line 1768, Address: 0x2185f4, Func Offset: 0xf4
	// Line 1769, Address: 0x218610, Func Offset: 0x110
	// Func End, Address: 0x218628, Func Offset: 0x128
}
*/

// 100% matching!
int bhEne_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate) 
{
    epw->mtn_add = 0x10000;
    if (epw->mtn_no != no) 
    {
        epw->mtn_no = no;
        epw->frm_no = frm;
        epw->hokan_count = rate;
        epw->hokan_rate = 0;
        epw->mtn_md = 0x20;
        epw->flg = (int) (epw->flg & ~0x40000);
        epw->flg = (int) (epw->flg & ~0x2000000);
        return 0;
    }
    
    return -1;
}

/*
// 
// Start address: 0x2186a0
int bhEne_CollisionCheckWall(BH_PWORK* pw, _anon4* ps, _anon4* pd, float ar, float ah)
{
	unsigned int flg;
	float h;
	float r;
	float z;
	float y;
	float x;
	// Line 1835, Address: 0x2186a0, Func Offset: 0
	// Line 1844, Address: 0x2186cc, Func Offset: 0x2c
	// Line 1845, Address: 0x2186d0, Func Offset: 0x30
	// Line 1846, Address: 0x2186d4, Func Offset: 0x34
	// Line 1847, Address: 0x2186d8, Func Offset: 0x38
	// Line 1848, Address: 0x2186dc, Func Offset: 0x3c
	// Line 1850, Address: 0x2186e0, Func Offset: 0x40
	// Line 1857, Address: 0x2186e4, Func Offset: 0x44
	// Line 1850, Address: 0x2186f4, Func Offset: 0x54
	// Line 1851, Address: 0x2186f8, Func Offset: 0x58
	// Line 1852, Address: 0x218700, Func Offset: 0x60
	// Line 1853, Address: 0x218708, Func Offset: 0x68
	// Line 1854, Address: 0x21870c, Func Offset: 0x6c
	// Line 1856, Address: 0x218710, Func Offset: 0x70
	// Line 1857, Address: 0x218714, Func Offset: 0x74
	// Line 1858, Address: 0x218718, Func Offset: 0x78
	// Line 1859, Address: 0x218720, Func Offset: 0x80
	// Line 1860, Address: 0x218728, Func Offset: 0x88
	// Line 1862, Address: 0x21872c, Func Offset: 0x8c
	// Line 1873, Address: 0x218734, Func Offset: 0x94
	// Line 1862, Address: 0x21873c, Func Offset: 0x9c
	// Line 1863, Address: 0x218744, Func Offset: 0xa4
	// Line 1864, Address: 0x218754, Func Offset: 0xb4
	// Line 1866, Address: 0x218764, Func Offset: 0xc4
	// Line 1867, Address: 0x218768, Func Offset: 0xc8
	// Line 1868, Address: 0x21876c, Func Offset: 0xcc
	// Line 1869, Address: 0x218770, Func Offset: 0xd0
	// Line 1870, Address: 0x218774, Func Offset: 0xd4
	// Line 1873, Address: 0x218778, Func Offset: 0xd8
	// Line 1874, Address: 0x2187a0, Func Offset: 0x100
	// Line 1880, Address: 0x2187ac, Func Offset: 0x10c
	// Line 1881, Address: 0x2187b0, Func Offset: 0x110
	// Func End, Address: 0x2187e0, Func Offset: 0x140
}

// 
// Start address: 0x2187e0
_anon23* bhEne_CollisionCheckWall2(BH_PWORK* pw, _anon4* ps, _anon4* ops, _anon4* pd, float ar, float ah)
{
	unsigned int flg;
	_anon4 pos;
	_anon23* hp;
	// Line 1904, Address: 0x2187e0, Func Offset: 0
	// Line 1915, Address: 0x218810, Func Offset: 0x30
	// Line 1916, Address: 0x218814, Func Offset: 0x34
	// Line 1917, Address: 0x21881c, Func Offset: 0x3c
	// Line 1920, Address: 0x218824, Func Offset: 0x44
	// Line 1915, Address: 0x218828, Func Offset: 0x48
	// Line 1916, Address: 0x21882c, Func Offset: 0x4c
	// Line 1905, Address: 0x218840, Func Offset: 0x60
	// Line 1916, Address: 0x218844, Func Offset: 0x64
	// Line 1917, Address: 0x218848, Func Offset: 0x68
	// Line 1919, Address: 0x218850, Func Offset: 0x70
	// Line 1920, Address: 0x218854, Func Offset: 0x74
	// Line 1923, Address: 0x218858, Func Offset: 0x78
	// Line 1924, Address: 0x218860, Func Offset: 0x80
	// Line 1926, Address: 0x218880, Func Offset: 0xa0
	// Line 1928, Address: 0x218898, Func Offset: 0xb8
	// Line 1930, Address: 0x21889c, Func Offset: 0xbc
	// Line 1934, Address: 0x2188a4, Func Offset: 0xc4
	// Line 1930, Address: 0x2188a8, Func Offset: 0xc8
	// Line 1931, Address: 0x2188b0, Func Offset: 0xd0
	// Line 1932, Address: 0x2188c0, Func Offset: 0xe0
	// Line 1935, Address: 0x2188d0, Func Offset: 0xf0
	// Func End, Address: 0x218904, Func Offset: 0x124
}
*/

// 100% matching!
ATR_WORK* bhEne_CheckDirWall(BH_PWORK* epw, int ang, float step) 
{
    NJS_POINT3* pos = (NJS_POINT3*)((char*)epw + 0x10);
    ATR_WORK* hp;

    hp = bhEne_CheckDirWall3(epw, pos, ang, step);
    return hp;
}

// 100% matching!
ATR_WORK* bhEne_CheckDirWall2(BH_PWORK* epw, int ang, float step)
{
    ATR_WORK* hp;
    NJS_POINT3 pos;

    pos.x = epw->px + epw->aox;
    pos.z = epw->pz + epw->aoz;
    pos.y = epw->py;
  
    hp = bhEne_CheckDirWall3(epw, &pos, ang, step);
    return hp;
}

// 100% matching!
ATR_WORK* bhEne_CheckDirWall3(BH_PWORK* epw, NJS_POINT3* pos, int ang, float step)
{
    int angle; // not from debugging symbols
    float float_angle; // not from debugging symbols

    ATR_WORK* hp;
	NJS_POINT3 ps;
    
    angle = (epw->ay + ang) & 0xffff;

    float_angle = step * njSin(angle);
    ps.x = pos->x - float_angle;
    
    float_angle = step * njCos(angle);
    ps.z = pos->z - float_angle;
    
    ps.y = pos->y;
    
    hp = bhCheckWallType(&ps, epw->flg, epw->ar, epw->ah);
    return hp;
}

// 100% matching!
int bhEne_CheckSideWall(BH_PWORK* epw, float step, int both) {  

    NJS_POINT3 *pos = (NJS_POINT3*)&epw->px;
    return bhEne_CheckSideWall3(epw, pos, step, both);
}

// 100% matching!
int bhEne_CheckSideWall2(BH_PWORK* epw, float step, int both)
{
    NJS_POINT3 pos;

    pos.x = epw->px + epw->aox;
    pos.z = epw->pz + epw->aoz;
    pos.y = epw->py;
    
    return bhEne_CheckSideWall3(epw, &pos, step, both);
}

// 100% matching!
int bhEne_CheckSideWall3(BH_PWORK* epw, NJS_POINT3* pos, float step, int both)
{
    int left_hit;
    int right_hit;

    right_hit = 0;
    left_hit = 0;
    
    if (bhEne_CheckDirWall3(epw, pos, -0x4000, step) != 0) 
    {
        left_hit = 1;
    }
    if (bhEne_CheckDirWall3(epw, pos, 0x4000, step) != 0) 
    {
        right_hit = -1;
    }

    if (left_hit != 0) 
    {
        if (right_hit != 0) 
        {
            return both;
        }
    }

    return left_hit + right_hit;
}

// 100% matching!
void bhEne_SetVibration(int no)
{
    switch (no) 
	{                               
        case 0:
            StartVibrationEx(1, 9);
            break;
        case 1:
            StartVibrationEx(1, 0xA);
            break;
        case 2:
            StartVibrationEx(1, 0xB);
            break;
    }
}

// 100% matching!
void bhEne_PlayerSePlay(BH_PWORK* epw, int no)
{
    if (!(epw->flg & 0x10000)) 
	{
        CallPlayerVoice(no);
    }
}

// 100% matching!
void bhEne_HitCheckParts(BH_PWORK* pp, NJS_POINT3* pos) {
    O_WORK* owk;
    NJS_VECTOR vec;
    float len;
    float slen;
    int i;

    owk = (O_WORK*)pp->mlwP->owP+1;
    len = -1.0f;
    
    for (i = 1; i < (int)(pp->mlwP->obj_num - 1); i++)
    {        
        vec.x = pos->x - owk->mtx[12];
        vec.y = pos->y - owk->mtx[13];
        vec.z = pos->z - owk->mtx[14];
        slen = njScalor2(&vec);

        if (len > slen || len == -1.0f)
        {
            len = slen;
            pp->djnt_no = i;
            pp->dvx = -vec.x;
            pp->dvy = -vec.y;
            pp->dvz = -vec.z;
        }
        
         owk++;
    }
    
    pp->dpx = pos->x;
    pp->dpy = pos->y;
    pp->dpz = pos->z;
}