#include "zonzon.h"
#include "effect.h"
#include "effsub3.h"
#include "hitchk.h"
#include "ps2_NaMath.h"
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

// 100% matching!
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, NJS_POINT3* ofp, short ry)
{
    unsigned int bl_color;
    O_WRK* op; 
    
    sys->ef.flg = 1;
    
    sys->ef.px = 0;
    sys->ef.py = 0;
    sys->ef.pz = 0;
    
    sys->ef.sx = 1.5f;
    sys->ef.sy = 1.5f;
    sys->ef.sz = 0;
    
    sys->ef.ay = 0;
    
    if (epw->id == 17)
    {
        bl_color = 0xFFFFFFFFFF400000;
        
        sys->ef.mdlver = 3;
    }
    else 
    {
        bl_color = 0xFFFFFFFFFF5F0000;
        
        sys->ef.mdlver = 0;
    }
    
    switch (type)
    {
    case 0:
    case 1:
    case 2:
        sys->ef.id = 5;
        
        sys->ef.type = type;
        
        if (type == 2) 
        {
            sys->ef.sx = 3.0f;
            sys->ef.sy = 3.0f;
            sys->ef.sz = 0;
        }
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        break;
    case 3: 
    {
        NJS_POINT3 ps;
        
        sys->ef.id = 5;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 0);
        break;
    }
    case 4:
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, bl_color, 1);
        break;
    case 5:
        sys->ef.id = 5;
        
        sys->ef.type = 2;
        
        sys->ef.sx = 3.0f;
        sys->ef.sy = 3.0f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        break;
    case 6:
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        sys->ef.id = 5;
        
        sys->ef.type = 1;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, bl_color, 3);
        break;
    case 7: 
    {
        NJS_POINT3 ps;
        
        sys->ef.id = 5;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
            
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 8);
        break;
    }
    case 8: 
    {
        NJS_POINT3 ps;
        
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 13);
        break;
    }
    case 10:
        ofp->z = 0;
        
        bhEne_SetBlood4(epw, epw->djnt_no, ofp, 0, 2);
        break;
    case 11:
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        ofp->z = 0;
        
        op = bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, 0xFFFFFFFFFF9F0000, 18);
        
        op->mode1 = 1;
        break;
    }
}

// 100% matching!
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, NJS_POINT3* dv, int n, int tex_id, int type, int wcnt) 
{   
    int eno;

    sys->ef.id = 370;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.sx = 3.5f;
    sys->ef.sy = 3.5f;
    sys->ef.sz = 0;
    
    if (lnk_obj != -1) 
    {
        sys->ef.px = 0;
        sys->ef.py = 0;
        sys->ef.pz = 0;
        
        eno = bhSetEffectTb(&sys->ef, ofs, (unsigned char*)epw, lnk_obj);
    } 
    else 
    {
        sys->ef.px = ofs->x;
        sys->ef.py = ofs->y;
        sys->ef.pz = ofs->z;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    if (eno != -1) 
    {
        eff[eno].stflg |= 0x20;
        
        eff[eno].txp[0] = epw->mlwP->texP;
        
        eff[eno].tex_id = tex_id;
        
        eff[eno].xn = dv->x;
        eff[eno].yn = dv->y;
        eff[eno].zn = dv->z;
        
        eff[eno].ct0 = wcnt;
        eff[eno].ct1 = n;
    }
}

// 100% matching!
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int tex_id, int type)
{
    BT_WRK* tbl; 
    NJS_POINT3 ps; 
    NJS_POINT3 v; 
    int ang; // DWARF has this variable placed below angY 
    int angY;  
    int i; 
    static BT_WRK bld_tbl[20] = // TODO: match this to 100%, the signed zeroes are causing trouble
    {
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00002000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0xFFFFE000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000004, 0, 0 },
        { { -0.0f,  0.0f, 0.0f }, 0xFFFFF000, 4         , 0, 0 },
        { {  0.2f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 4, 3 },
        { {  0.0f, -0.2f, 0.0f }, 0x00000000, 4         , 3, 0 },
        { {  0.2f,  0.0f, 0.0f }, 0x00002000, 0x00009000, 4, 6 },
        { {  0.0f, -0.2f, 0.0f }, 0xFFFFF000, 0x00008000, 4, 7 },
        { {  0.0f,  0.2f, 0.0f }, 0x00002000, 0x00007000, 4, 8 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000800, 8, 1 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0xFFFFF800, 8, 1 },
        { {  0.0f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 8, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000800, 4, 1 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0xFFFFF800, 4, 1 },
        { {  0.0f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 4, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00009000, 4, 2 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0x00007000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 }
    };
    static int blood_n[4] = { 5, 10, 2, 3 };

    tbl = bld_tbl;
    
    angY = 0;
    
    if (type == 2)
    {
        if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, &epw->mlwP->owP[lnk_obj]) != 0)
        {
            angY = 32768;
        }
        
        ps.z = 0;
        ps.y = 0;
        ps.x = 0;
        
        tbl = &tbl[10];
        
        v.x = -epw->dvx;
        v.y = -epw->dvy;
        v.z = -epw->dvz;
        
        njUnitVector(&v);
        
        bhEne_SetBlood3(epw, lnk_obj, &ps, &v, 1, 0, 9, 3);
    } 
    else if (type == 3)
    {
        tbl = &tbl[14];
    }

    for (i = 0; i < 10; i++, tbl++)
    {
        if (tbl->type == -1)
        {
            break;
        }

        ang = (tbl->angY + angY) & 0xFFFF;
        
        v.x = -(njSin(ang) * njCos(tbl->angX));
        v.y = njSin(tbl->angX);
        v.z = -(njCos(ang) * njCos(tbl->angX));
        
        ps.x = ofs->x + tbl->ofs.x;
        ps.y = ofs->y + tbl->ofs.y;
        ps.z = ofs->z + tbl->ofs.z;
        
        bhEne_SetBlood3(epw, lnk_obj, &ps, &v, blood_n[type], tex_id, tbl->type, tbl->wcnt);
    }
}

/*// 
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