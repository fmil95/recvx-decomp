#include "../../../ps2/veronica/prog/en14.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"

// ENEMY: Third Form Alexia 

#pragma divbyzerocheck on

static unsigned char flip_tree[22] = { 0, 1, 2, 3, 4, 5, 6, 9, 10, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };
static char SdwTab[5] = { 1, 6, 11, 12, -1 };
static DMG_REACT DmgReact[21] =
{
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },   
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },   
    { {  2,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  2,  1,  0 }, {  1,  1,  1 }, 1 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 2 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 1 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 0 },
    { {  2,  2,  2 }, {  1,  1,  1 }, 0 },
    { {  2,  2,  2 }, {  1,  0,  0 }, 1 },
    { {  2,  2,  2 }, {  1,  1,  1 }, 0 }
};
static COMBWEP_WORK CombWepTbl[21] =
{
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  4, { 1, 0, 0 }, 120, 800 },
    { 20, { 6, 4, 2 },  60,   0 },
    { 20, { 6, 4, 2 },  60,   0 },
    { 20, { 6, 4, 2 },  60,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    { 25, { 5, 3, 1 },  30,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  1, { 1, 1, 1 },  60,   0 },
    { 25, { 5, 4, 2 },  30,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 }
};
static COMBJOINT_WORK CombJointTbl[22] = { 0 };
static BLOOD_TBL BloodTbl[22] =
{
    { 1, {  0.0f,  0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 0, {  0.0f,  2.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 0, {  0.0f,  2.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 0, {  0.0f,  1.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 2.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f }
};
static CPCL CapColTab[25] = 
{
    {   1,   2,  18 },
    {   2,   3,  18 },
    {   3,   3,  30 },
    {   0,  25,   0 },
    {   3,   3,  20 },
    {  15,  40,   0 },
    {   3,   3,  20 },
    { -15,  40,   0 },
    {   7,   7,  12 },
    {   0,   0,   0 },
    {   8,   8,  12 },
    {   0,   0,   0 },
    {   9,   9,  12 },
    {   0,   0,   0 },
    {  10,  10,  12 },
    {   0,   0,   0 },
    {   3,   4,  12 },
    {   4,   5,   8 },
    {   5,   6,   6 },
    {   6,   6,  15 },
    {   0,  15,   0 },
    {   1,  11,  20 },
    {   1,   1,  30 },
    {   0, -20,   0 },
    {   0,   0,   0 }
};
static P_WORK ShapeTbl_Acid_F[5] = 
{
    {   0,    0.0f },
    {   5, 1000.0f },
    {  12, 1000.0f },
    {  20,    0.0f },
    { 999,    0.0f }
};
static P_WORK ShapeTbl_Acid_S[6] = 
{
    {   0,    0.0f },
    {   6, 1000.0f },
    {  10,  300.0f },
    {  16, 1000.0f },
    {  25,    0.0f },
    { 999,    0.0f }
};
/* unused below */
/*static char joint_tree[1][6];
static P_WORK ShapeTbl_Acid_A[5];*/

void (*bhEne14_Mode0[6])(BH_PWORK*) = 
{
	bhEne14_Init,
	bhEne14_Move,
	bhEne14_Nage,
	bhEne14_Damage,
	bhEne14_Die,
	bhEne_Event
};
void (*bhEne14_BrainType[2])(BH_PWORK*) = 
{
	bhEne14_BR00,
	bhEne14_BR01
};
void (*bhEne14_MoveMode2[12])(BH_PWORK*) = 
{
	bhEne14_MV00,
	bhEne14_MV01,
	bhEne14_MV02,
	bhEne14_MV03,
	bhEne14_MV04,
	bhEne14_MV05,
	bhEne14_MV06,
	bhEne14_MV07,
	bhEne14_MV08,
	bhEne14_MV09,
	bhEne14_MV10,
	bhEne14_MV11
};
void (*bhEne14_NageMode2[1])(BH_PWORK*) = { bhEne14_NG00 };
void (*bhEne14_DamageMode2[2])(BH_PWORK*) = 
{
	bhEne14_DG00,
	bhEne14_DG01
};

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne14(BH_PWORK* epw)
{
	int i;
	O_WRK* op;

    bhEne14_Mode0[epw->mode0](epw);
    bhEne14_CallSE(epw);
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (epw->flg & 0x20000)
    {
        bhEne14_TailSwing(epw);
    }
    
    if (epw->flg & 0x10)
    {
        bhEne14_CheckWall(epw);
    }
    
    if (epw->type == 1)
    {
        bhEne14_SetMotion(epw);
    }
    
    bhCalcModel(epw);
    bhEne14_LookPlayaer(epw);
    bhEne_SetWeponAtr(epw, 6, 1, 5.0f);
    
    if (epw->type == 1)
    {
        bhEne14_PlayerControl(epw);
    }
    
    *(O_WRK **)(epw->exp0 + 0x244) = NULL;
    for (i = 0, op = eff; i < 512; i++, op++)
    {
        if ((op->flg & 1) && !(op->stflg & 0x1000000) && (op->id == 130) && (op->type == 4))
        {
            *(O_WRK **)(epw->exp0 + 0x244) = op;
            break;
        }
    }
}

// 100% matching!
void bhEne14_Init(BH_PWORK* epw)
{
	BH_PWORK* ep;
	int i;

    epw->flg |= 0x78;
    epw->flg &= ~6;
    epw->flg2 |= 1;
    epw->ar = 8.0f;
    epw->ah = 25.0f;
    epw->car = 4.0f;
    epw->car = 25.0f;
    epw->hp = 400;
    
    if (epw->type == 0)
    {
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
        epw->mtn_no = 0;
        epw->mtn_md = 0;
        epw->hokan_rate = 65536;
        epw->hokan_count = 0;
        epw->mtn_add = 65536;
        epw->mtn_tp = flip_tree;
        epw->frm_no = 0;
    } 
    else
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 4;
        epw->mode3 = 0;
        epw->mtn_no = 5;
        epw->mtn_md = 0;
        epw->hokan_rate = 65536;
        epw->hokan_count = 0;
        epw->mtn_add = 65536;
        epw->mtn_tp = flip_tree;
        epw->frm_no = 0;
    }
    
    epw->clp_jno[0] = 6;
    epw->clp_jno[1] = 1;
    epw->clp_jno[2] = 7;
    epw->clp_jno[3] = 9;
    epw->clp_jno[4] = 11;
    epw->clp_jno[5] = 15;
    epw->clp_jno[6] = 18;
    epw->clp_jno[7] = 21;
    epw->mdflg &= ~0x20;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(584, 8);
    }
    
    epw->flg &= ~0x80;
    
    if (epw->type == 0)
    {
        for (i = 0, ep = ene; i <= sys->enow; i++, ep++)
        {
            if ((ep->flg & 1) && (ep->id == 13)) 
            {
                epw->lkwkp = (unsigned char*)ep;
                epw->lkono = 0;
                epw->px = ep->px;
                epw->py = ep->py;
                epw->pz = ep->pz;
                epw->ay = ep->ay;
                epw->flg &= ~0x10;
                break;
            }
        }
    }
    
    if (epw->type == 1)
    {
        if (!(epw->flg & 0x800))
        {
            bhSetShadow(SdwTab, (unsigned char*) epw, 2, 6.0f, 6.0f, 4.0f);
            epw->flg |= 0x800;
        }
        epw->stflg &= ~8;
    } 
    else
    {
        epw->stflg |= 8;
    }

    epw->cpcl = CapColTab;
    bhEne14_TailInit(epw);
}


// 100% matching!
void bhEne14_Brain(BH_PWORK* epw)
{
	bhEne14_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne14_BR00()
{
	
}

// 100% matching!
void bhEne14_BR01()
{

}

// 100% matching!
void bhEne14_Move(BH_PWORK* epw) 
{
    bhEne14_MoveMode2[epw->mode2](epw);
    if (epw->mode1 == 1)
    {
        bhEne14_Brain(epw);
    }
    
    if (epw->type == 1)
    {
        if (epw->flg & 4)
        {
            epw->flg &= ~4;
            bhEne14_InitDamage(epw);
        }
    }
}

// 100% matching!
void bhEne14_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_md &= ~2;
        epw->flg |= 0x100000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 18;
        epw->hokan_rate = 45875;
        epw->mode3++;
        break;
    }

}

// 100% matching!
void bhEne14_MV01(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 16;
        epw->mtn_no = 1;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->frm_no == 2949120)
        {
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 16;
        }
        break;

    }
}

// 100% matching!
void bhEne14_MV02(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int ang; 
    int fno;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        ep = (BH_PWORK*) epw->lkwkp;
        ang = (short)(bhArcTan2(ep->px - plp->px, ep->pz - plp->pz) - ep->ay);
        
        if (ang < -NJM_DEG_ANG(30.0f))
        {
            epw->ct1 = 1;
        } 
        else if (ang > NJM_DEG_ANG(30.0f))
        {
            epw->ct1 = 2;
        }
        else
        {
            epw->ct1 = 0;
        }

        switch (epw->ct1)
        {
        case 0: 
            epw->mtn_no = 2;
            break;
        case 1: 
            epw->mtn_no = 3;
            break;
        case 2:
            epw->mtn_no = 3;
            epw->mtn_md |= 2;
            break;
        }
        
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 0.0f;
        epw->mode3++;

    case 1:
        fno = epw->frm_no / 65536;
        switch (epw->ct1) 
        {
            case 0:
                epw->shp_ct = bhEne_GetShapeCnt(ShapeTbl_Acid_F, fno);
                break;
            default:
                epw->shp_ct = bhEne_GetShapeCnt(ShapeTbl_Acid_S, fno);
                break;
        }
        
        if (fno >= 7 && fno < 13)
        {
            bhEne14_Acid(epw, 1);            
        }
        
        if (fno == 15)
        {
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 4;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->mdflg &= ~2;
        }

    }
}

// 100% matching!
void bhEne14_MV03()
{

}

// 100% matching!
void bhEne14_MV04(BH_PWORK* epw)
{
	float dist;
	ATR_WORK* hp;
	int ang;  
	NJS_VECTOR vec;
	NJS_VECTOR v;
	float spd;
	NJS_POINT3 cp;
	NJS_LINE ln;
	//float dist; // from DWARF but couldnt find a use

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x100000;
        epw->mtn_md &= ~2;
        EXP0_I(0x240) = 8;
        epw->flg &= ~0x20000;
        bhEne14_TailInit(epw);
        epw->mtn_no = 6;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->flg &= ~0x80000;
        epw->ct0 = 4;
        epw->ct2 = 1;
        epw->mode3++;

    case 1:
        hp = bhCheckFloorEnemy(plp->flr_no, plp->px, plp->pz);
        if ((hp != NULL) && (hp->prm0 == 14))
        {
            vec.x = (hp->px + (hp->w / 2.0f)) - plp->px;
            vec.z = (hp->pz + (hp->d / 2.0f)) - plp->pz;
            vec.y = 0;
            njUnitMatrix(NULL);
            njRotateY(NULL, -epw->ay);
            njCalcVector(NULL, &vec, &vec);
            if (njRandom() > 0.5f)
            {
                ang = bhArcTan2(epw->pz - plp->pz, epw->px - plp->px);
                if (vec.x < 0.0f)
                {
                    ang = (ang + (5461.0f + (3640.0f * njRandom())));
                    epw->mtn_no = 13;
                    epw->frm_no = 0;
                    epw->hokan_count = 8;
                    epw->hokan_rate = 45875;
                    epw->mtn_md &= ~2;
                } 
                else
                {
                    ang = (ang - (5461.0f + (3640.0f * njRandom())));
                    epw->mtn_no = 13;
                    epw->frm_no = 0;
                    epw->hokan_count = 8;
                    epw->hokan_rate = 45875;
                    epw->mtn_md |= 2;
                }

                dist = 40.0f + (20.0f * njRandom());
                epw->xn = plp->px + (dist * njCos(ang));
                epw->zn = plp->pz + (dist * njSin(ang));
                epw->yn = 25.0f + plp->py + (30.0f * njRandom());
            } 
            else
            {
                ang = bhArcTan2(epw->pz - plp->pz, epw->px - plp->px);
                if (epw->py > (55.0f + plp->py))
                {
                    ang = (ang + (3640.0f * njRandom()));
                    epw->mtn_no = 15;
                    epw->frm_no = 0;
                    epw->hokan_count = 8;
                    epw->hokan_rate = 45875;
                    epw->mtn_md &= ~2;
                    dist = 50.0f + (10.0f * njRandom());
                    epw->xn = plp->px + (dist * njCos(ang));
                    epw->zn = plp->pz + (dist * njSin(ang));
                    epw->yn = 25.0f + plp->py + (20.0f * njRandom());
                } 
                else
                {
                    ang = (ang - (3640.0f * njRandom()));
                    epw->mtn_no = 12;
                    epw->frm_no = 0;
                    epw->hokan_count = 8;
                    epw->hokan_rate = 45875;
                    dist = 40.0f + (20.0f * njRandom());
                    epw->xn = plp->px + (dist * njCos(ang));
                    epw->zn = plp->pz + (dist * njSin(ang));
                    epw->yn = (95.0f + plp->py) - (20.0f * njRandom());
                }
            }
        }

        if (epw->hp > 300)
        {
            epw->ct1 = 35;
        }            
        else if (epw->hp > 150)
        {
            epw->ct1 = 45;
        }            
        else
        {
            epw->ct1 = 50;
        }
            
        epw->mode3++;
        break;
        
    case 2:
        v.x = (epw->xn - epw->px) / 16.0f;
        v.z = (epw->zn - epw->pz) / 16.0f;
        v.y = (epw->yn - epw->py) / 16.0f;
        
        spd = njScalor(&v);
        if (spd > 2.5f)
        {
            v.x = (2.5f * v.x) / spd;
            v.y = (2.5f * v.y) / spd;
            v.z = (2.5f * v.z) / spd;
        }
        
        njAddVector((NJS_VECTOR*)&epw->px, &v);
        epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 546);
        
        if (epw->frm_no == 0)
        {
            epw->mtn_no = 6;
            epw->frm_no = 0;
            epw->hokan_count = 8;
            epw->hokan_rate = 45875;
        }

        if (epw->ct1-- == 0)
        {
            epw->ct0 -= 1;
            if (epw->ct0 <= 0 && !(plp->flg & 4))
            {
                epw->mode2 = 11;
                epw->mode3 = 0;
            }
            else
            {
                epw->mode3 = 1;
            }
        }
        
        if ((epw->ct2 != 0) && (epw->hp > 300))
        {
            if (*(int *)(epw->exp0 + 0x244) != 0)
            {
                ln.px = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x10);
                ln.py = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x14);
                ln.pz = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x18);
                ln.vx = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x64);
                ln.vy = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x68);
                ln.vz = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x6C);
                
                if (njDistanceP2L((NJS_POINT3*)&epw->xn, &ln, &cp) < 20.0f)
                {
                    epw->mode3 = 1;
                    epw->ct2--;
                }
                else if (njDistanceP2L((NJS_POINT3*)&epw->px, &ln, &cp) < 20.0f)
                {
                    epw->mode3 = 1;
                    epw->ct2--;
                }
            }
        }
        return;
    }
}


// 100% matching!
void bhEne14_MV05()
{

}

// 100% matching!
void bhEne14_MV06()
{

}

// 100% matching!
void bhEne14_MV07()
{

}

// 100% matching!
void bhEne14_MV08()
{

}

// 100% matching!
void bhEne14_MV09()
{

}

// 100% matching!
void bhEne14_MV10()
{

}

// 100% matching!
void bhEne14_MV11(BH_PWORK* epw)
{
	float dist;
	ATR_WORK* hp; 
	int ang;
	NJS_VECTOR vec; 
	NJS_VECTOR v;   
	float spd; 
	NJS_POINT3 cp;
	NJS_LINE ln; 
	//float dist; // from DWARF but couldnt find a use

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x100000;
        epw->mtn_md &= ~2;
        EXP0_I(0x240) = 8;
        epw->flg &= ~0x20000;
        bhEne14_TailInit(epw);
        epw->mtn_no = 19;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->flg &= ~0x80000;

        if (epw->hp > 0)
        {
            epw->ct0 = 1;
        }            
        else
        {
            epw->ct0 = 3;
        }
            
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
        epw->ct2 = 1;
        epw->mode3++;

    case 1:
        hp = bhCheckFloorEnemy(plp->flr_no, plp->px, plp->pz);
        if (hp != NULL) 
        {
            if (hp->prm0 == 14)
            {
                vec.x = (hp->px + (hp->w / 2.0f)) - plp->px;
                vec.z = (hp->pz + (hp->d / 2.0f)) - plp->pz;
                vec.y = 0.0f;

                njUnitMatrix(NULL);
                njRotateY(NULL, -epw->ay);
                njCalcVector(NULL, &vec, &vec);

                ang = bhArcTan2(epw->pz - plp->pz, epw->px - plp->px);
                if (vec.x < 0.0f)
                {
                    ang = (ang + (7281.0f + (1820.0f * njRandom())));
                }
                    
                else
                {
                    ang = (ang - (7281.0f + (1820.0f * njRandom())));
                }
                    
                dist = 40.0f + (20.0f * njRandom());
                epw->xn = plp->px + (dist * njCos(ang));
                epw->zn = plp->pz + (dist * njSin(ang));
                epw->yn = 25.0f + plp->py + (30.0f * njRandom());
            }
        }
        epw->ct1 = 30;
        epw->mode3++;
        break;

    case 2:
        v.x = (epw->xn - epw->px) / 16.0f;
        v.z = (epw->zn - epw->pz) / 16.0f;
        v.y = (epw->yn - epw->py) / 16.0f;

        spd = njScalor(&v);
        if (spd > 2.5f)
        {
            v.x = (2.5f * v.x) / spd;
            v.y = (2.5f * v.y) / spd;
            v.z = (2.5f * v.z) / spd;
        }
        
        njAddVector((NJS_VECTOR*)&epw->px, &v);
        epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 546);

        if (epw->frm_no == 327680)
        {
            bhEne14_Acid(epw, 0);
        }
        
        if ((epw->frm_no >= 393216) && (epw->frm_no < 720897))
        {
            bhEne14_Acid(epw, 1);
        }
        
        if (epw->ct1-- == 0)
        {
            if ((epw->ct0-- == 0) || (plp->flg & 4))
            {
                epw->mode2 = 4;
                epw->mode3 = 0;
            } 
            else 
            {
                epw->mode3 = 1;
            }
        }

        if (*(int *)(epw->exp0 + 0x244) != 0)
        {
            ln.px = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x10);
            ln.py = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x14);
            ln.pz = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x18);
            ln.vx = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x64);
            ln.vy = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x68);
            ln.vz = *(float *)(*(int *)(epw->exp0 + 0x244) + 0x6C);

            if (njDistanceP2L((NJS_POINT3*)&epw->xn, &ln, &cp) < 20.0f)
                epw->mode3 = 1;

            if ((epw->ct2 != 0) && (njDistanceP2L((NJS_POINT3*)&epw->px, &ln, &cp) < 20.0f))
            {
                epw->mode3 = 1;
                epw->ct2--;
            }
        }
        return;
    }
}

// 100% matching!
void bhEne14_Nage(BH_PWORK* epw)
{
	bhEne14_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne14_NG00()
{

}

// 100% matching!
void bhEne14_Damage(BH_PWORK* epw)
{
	bhEne14_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne14_DG00(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mtn_md &= ~2;
        epw->mode3++;
        
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 8;
        }
        break;

    }
}

// 100% matching!
void bhEne14_DG01(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        epw->mtn_no = 22;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mtn_md &= ~2;
        epw->mode3++;
        
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 8;
        }
        break;

    }
}

// 100% matching!
void bhEne14_Die()
{

}

// 100% matching!
void bhEne14_InitDamage(BH_PWORK* epw)
{
	bhEne14_HitMark(epw);
}

// 100% matching!
void bhEne14_LookPlayaer(BH_PWORK* epw)
{
    float* mat;
    float* mat2; 
    int rx;
    int ry;
    int rz;
    int rz1;
    int rz2;
	NJS_POINT3 view; 
	NJS_VECTOR vec;
 	NJS_VECTOR ov;
	float out;
	int ang; 
	NJS_MKEY_A_MOD* mkaP; 
	NJS_CNK_OBJECT* objP;

    mat = (float*)&lcmat;
    mat2 = (float*)&lcmat[1];
    
    if (epw->mnwP != epw->mnwPb) 
    {
        epw->flg &= ~0x100000;
        epw->mlwP->owP[6].flg &= ~0x2;
        return;
    }
    
    epw->mlwP->owP[6].flg |= 0x2;

    
    if (!(epw->flg & 0x100000))
    {
        
        mkaP = epw->mnwP[epw->mtn_no].md2P[6].p[1];
        mkaP += (epw->frm_no / 65536);
        if (epw->mtn_md & 2)
        {
            njUnitMatrix(lcmat);
            njRotateXYZ(lcmat, mkaP->key[0], -mkaP->key[1], -mkaP->key[2]);
        } 
        else
        {
            njUnitMatrix(lcmat);
            njRotateXYZ(lcmat, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
        }
        
    } 
    else
    {
        view.x = plp->mlwP->owP[5].mtx[12] - epw->mlwP->owP[6].mtx[12];
        view.y = plp->mlwP->owP[5].mtx[13] - epw->mlwP->owP[6].mtx[13];
        view.z = plp->mlwP->owP[5].mtx[14] - epw->mlwP->owP[6].mtx[14];
        njUnitVector(&view);
        njSetMatrix(NULL, &epw->mlwP->owP[5].mtx);
        njInvertMatrix(NULL);
        njCalcVector(NULL, &view, &view);
        
        rx = (int)(10430.381f * asinf(view.y));
        ry = bhArcTan2(-view.x, -view.z);
        if (ry > NJM_DEG_ANG(60.0f))
        {
            ry = NJM_DEG_ANG(60.0f);
        } 
        
        if (ry < NJM_DEG_ANG(-60.0f)) 
        {
            ry = NJM_DEG_ANG(-60.0f);
        }

        if (rx > NJM_DEG_ANG(60.0f))
        {
            rx = NJM_DEG_ANG(60.0f);
        } 
        
        if (rx < NJM_DEG_ANG(-30.0f)) 
        {
            rx = NJM_DEG_ANG(-30.0f);
        }
        
        view.x = 0.0f;
        view.y = 0.0f;
        view.z = -1.0f;
        njUnitMatrix(NULL);
        njRotateXYZ(NULL, rx, ry, 0);
        njCalcVector(NULL, &view, &view);
        vec.x = 0.0f;
        vec.y = 0.0f;
        vec.z = -1.0f;
        {
            float inner = njOuterProduct(&vec, &view, &ov);
            njUnitVector(&ov);
            ang = (int)(10430.381f * asinf(inner));
            njUnitMatrix(lcmat);
            njRotate(lcmat, &ov, ang);
        }
        njRotateZ(lcmat, -(int)(10430.381f * asinf(mat[1])));
    }
    
    if (EXP0_I(0x240) != 0)
    {
        njSetMatrix(&(lcmat[1]), &epw->mlwP->owP[6].mtx);
        njSetMatrix(NULL, &epw->mlwP->owP[5].mtx);
        njInvertMatrix(NULL);
        njMultiMatrix(NULL, (NJS_MATRIX*)&(lcmat[1]));
        njGetMatrix((NJS_MATRIX*)&(lcmat[1]));
        rz2 = (int)(10430.381f * asinf(mat[1]));
        rz1 = (int)(10430.381f * asinf(mat2[1]));
        out = njOuterProduct((NJS_VECTOR*) &mat2[8], (NJS_VECTOR*) &mat[8], &ov);
        njUnitVector(&ov);
        ang = (int)(10430.381f * asinf(out)) / EXP0_I(0x240);
        njUnitMatrix(NULL);
        njRotate(NULL, &ov, ang);
        njMultiMatrix(NULL, (NJS_MATRIX*)&(lcmat[1]));
        njGetMatrix(lcmat);

        njRotateZ(lcmat, ((short)(rz2 - rz1)) / EXP0_I(0x240));
        EXP0_I(0x240)--;
    }

    rx = bhArcTan2(mat[6], mat[5]);
    ry = bhArcTan2(-mat[2], mat[0]);
    rz = (int)(10430.381f * asinf(mat[1]));
    objP = &epw->mlwP->objP[6];
    objP->ang[0] = rx;
    objP->ang[1] = ry;
    objP->ang[2] = rz;
    njSetMatrix(NULL, &epw->mlwP->owP[5].mtx);
    njRotateXYZ(NULL, rx, ry, rz);
    njGetMatrix(&epw->mlwP->owP[6].mtx);
}

// 100% matching!
void bhEne14_TailInit(BH_PWORK* epw)
{
    int i;
    O_WORK* p;

    p = &epw->mlwP->owP[11];

    for (i = 0; i < 11; i++, p++) 
    {
        *(float *)(epw->exp0 + 0x138 + i * 0xC) = p->mtx[12];
        *(float *)(epw->exp0 + 0x13C + i * 0xC) = p->mtx[13];
        *(float *)(epw->exp0 + 0x140 + i * 0xC) = p->mtx[14];
        *(int *)(epw->exp0 + 0x30 + i * 0xC) = 0;
        *(int *)(epw->exp0 + 0x34 + i * 0xC) = 0;
        *(int *)(epw->exp0 + 0x38 + i * 0xC) = 0;
        *(float *)(epw->exp0 + 4 + i * 4) = 2.5f;
    }
}

// 99.92% matching
void bhEne14_TailSwing(BH_PWORK* epw)
{
    static float g[11] = { 0.5f, 0.5f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
    static float n[11] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };   
    NJS_VECTOR v;
    int i;
    O_WORK* owp;
	NJS_CNK_OBJECT* objp;

    bhCalcModel(epw);

    for (i = 0; i < 11; i++)
    {
        *(float *)(epw->exp0 + 0x1BC + i * 0xC) = *(float *)(epw->exp0 + 0x138 + i * 0xC);
        *(float *)(epw->exp0 + 0x1C0 + i * 0xC) = *(float *)(epw->exp0 + 0x13C + i * 0xC);
        *(float *)(epw->exp0 + 0x1C4 + i * 0xC) = *(float *)(epw->exp0 + 0x140 + i * 0xC);
    }

    owp = &epw->mlwP->owP[11];
    for (i = 0; i < 11; i++, owp++)
    {
        *(float *)(epw->exp0 + 0x138 + i * 0xC) += *(float *)(epw->exp0 + 0x30 + i * 0xC) * n[i];
        *(float *)(epw->exp0 + 0x13C + i * 0xC) += *(float *)(epw->exp0 + 0x34 + i * 0xC) * n[i];
        *(float *)(epw->exp0 + 0x140 + i * 0xC) += *(float *)(epw->exp0 + 0x38 + i * 0xC) * n[i];

        *(float *)(epw->exp0 + 0x138 + i * 0xC) += (owp->mtx[12] - *(float *)(epw->exp0 + 0x138 + i * 0xC)) * g[i];
        *(float *)(epw->exp0 + 0x13C + i * 0xC) += (owp->mtx[13] - *(float *)(epw->exp0 + 0x13C + i * 0xC)) * g[i];
        *(float *)(epw->exp0 + 0x140 + i * 0xC) += (owp->mtx[14] - *(float *)(epw->exp0 + 0x140 + i * 0xC)) * g[i];
    }

    EXP0_F(0x138) = epw->mlwP->owP[11].mtx[12];
    EXP0_F(0x13C) = epw->mlwP->owP[11].mtx[13];
    EXP0_F(0x140) = epw->mlwP->owP[11].mtx[14];

    for (i = 0; i < 10; i++)
    {
        v.x = *(float *)(epw->exp0 + 0x144 + i * 0xC) - *(float *)(epw->exp0 + 0x138 + i * 0xC);
        v.y = *(float *)(epw->exp0 + 0x148 + i * 0xC) - *(float *)(epw->exp0 + 0x13C + i * 0xC);
        v.z = *(float *)(epw->exp0 + 0x14C + i * 0xC) - *(float *)(epw->exp0 + 0x140 + i * 0xC);
        njUnitVector(&v);

        *(float *)(epw->exp0 + 0x144 + i * 0xC) = *(float *)(epw->exp0 + 0x138 + i * 0xC) + 2.5f * v.x;
        *(float *)(epw->exp0 + 0x148 + i * 0xC) = *(float *)(epw->exp0 + 0x13C + i * 0xC) + 2.5f * v.y;
        *(float *)(epw->exp0 + 0x14C + i * 0xC) = *(float *)(epw->exp0 + 0x140 + i * 0xC) + 2.5f * v.z;
    }

    for (i = 0; i < 11; i++)
    {
        *(float *)(epw->exp0 + 0x30 + i * 0xC) = *(float *)(epw->exp0 + 0x138 + i * 0xC) - *(float *)(epw->exp0 + 0x1BC + i * 0xC);
        *(float *)(epw->exp0 + 0x34 + i * 0xC) = *(float *)(epw->exp0 + 0x13C + i * 0xC) - *(float *)(epw->exp0 + 0x1C0 + i * 0xC);
        *(float *)(epw->exp0 + 0x38 + i * 0xC) = *(float *)(epw->exp0 + 0x140 + i * 0xC) - *(float *)(epw->exp0 + 0x1C4 + i * 0xC);
    }

    owp = &epw->mlwP->owP[1];
    objp = &epw->mlwP->objP[11];
    njSetMatrix(NULL, &owp->mtx);
    
    for (i = 0; i < 10; i++, objp++) 
    {
        njPushMatrix(NULL);
        njInvertMatrix(NULL);

        njCalcPoint(NULL, (NJS_POINT3 *)((char*)epw->exp0 + 0x138 + (i + 1) * 0xC), &v);
        njPopMatrix(1);

        objp->ang[0] = bhArcTan2(-v.z, -v.y);
        objp->ang[1] = 0;
        objp->ang[2] = bhArcTan2(v.x, fabsf(v.y));

        if (objp->ang[0] > NJM_DEG_ANG(30.0f)) 
        {
            objp->ang[0] = NJM_DEG_ANG(30.0f);
        }
        if (objp->ang[0] < NJM_DEG_ANG(-10.0f)) 
        {
            objp->ang[0] = NJM_DEG_ANG(-10.0f);
        }
        if (objp->ang[2] > NJM_DEG_ANG(10.0f)) 
        {
            objp->ang[2] = NJM_DEG_ANG(10.0f);
        }
        if (objp->ang[2] < NJM_DEG_ANG(-10.0f)) 
        {
            objp->ang[2] = NJM_DEG_ANG(-10.0f);
        }

        njTranslateEx((NJS_POINT3 *)objp->pos);
        njRotateEx(objp->ang, 0);
    }
}

// 100% matching!
int bhEne14_HitMark(BH_PWORK* epw)
{
	int range;
	int i;
	NJS_POINT3 ofp;
	BLOOD_TBL* blp;

    range = 0;
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
    blp = &BloodTbl[epw->djnt_no];
    
    if ((epw->comb_flg & 0x10))
    {
        range = 0;
    }
    
    if ((epw->comb_flg & 0x20))
    {
        range = 1;
    }
    
    if ((epw->comb_flg & 0x40))
    {
        range = 2;
    }
    
    if (DmgReact[epw->wpnr_no].type[range] >= 0)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = (epw->comb_flg & 4) ? blp->ofp.z : -blp->ofp.z;


        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        

        switch (epw->wpnr_no)
        {
        case 10:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, (NJS_POINT3*)&epw->dpx, 1);
            break;
        default:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
            break;
        }
    }
   
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0))
    {
        for (i = 0; i < 4; i++)        
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;

            ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, (0.5f + (0.5f * njRandom())), (int)(40.0f * njRandom()) + 20);
        }         
    }
    
    if (DmgReact[epw->wpnr_no].exef & 2)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;

        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if (epw->type == 1)
    {
        epw->hp -= epw->total_dam;
    }
    
    if (sys->gm_mode != 3) 
    {
        if (epw->hp < 0)
        {
            epw->hp = 0;
        }
        
        if (epw->wpnr_no == 18)
        {
            epw->flg |= 2;
            plp->mnwP = plp->mnwPb;
        }
    } 
    else if (epw->hp < 0)
    {
        epw->flg |= 2;
    }
    
    return epw->total_dam;
}

// 100% matching!
void bhEne14_Acid(BH_PWORK* epw, int se)
{
	int eno; 
    int i; 
    int rapid;
	O_WORK* owk;
	float dt; // needs use
    float t;
    float spd;       // not from DWARF
    float size;      // not from DWARF
    NJS_POINT3 p, v; // not from DWARF

    owk = epw->mlwP->owP;
    
    p.x = owk[6].mtx[12];
    p.y = owk[6].mtx[13];
    p.z = owk[6].mtx[14];

    v.y = njSqrt(0);
    
    t = (v.y + njSqrt((v.y *  v.y) - (0.6f * (plp->py - p.y)))) / 0.3f;
    t = floorf(t);
    
    if (t < 1.0f) 
    {
        t = 1.0f;
    }
        
    v.x = (plp->px - p.x) / t;
    v.z = (plp->pz - p.z) / t;

    sys->ef.id = 256;
    
    sys->ef.flg = 1;
    
    sys->ef.px = p.x;
    sys->ef.py = p.y;
    sys->ef.pz = p.z;
  
    if (epw->type == 0) 
    {
        rapid = 4;
        
        sys->ef.type = 4;
    } 
    else 
    {
        rapid = 1;
        
        sys->ef.type = 6;
    }
    
    for (i = 0; i < rapid; i++) 
    {
        size = 1.0f + (0.5f * njRandom());
        
        sys->ef.sx = size;
        sys->ef.sy = size;
        sys->ef.sz = size;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {
            eff[eno].stflg |= 0x20;
            
            eff[eno].txp[0] = epw->mdl[2].texP;
            eff[eno].tex_id = 0;
            
            eff[eno].xn = v.x;
            eff[eno].yn = v.y;
            eff[eno].zn = v.z;

            njUnitMatrix(NULL);
            
            njRotateY(NULL, (1092.0f * njRandom()) - 546.0f);
            njRotateX(NULL, 910.0f * njRandom());
            
            njCalcVector(NULL, (NJS_VECTOR*)&eff[eno].xn, (NJS_VECTOR*)&eff[eno].xn);

            spd = njRandom();
            
            eff[eno].px += spd * eff[eno].xn;
            eff[eno].py += spd * eff[eno].yn;
            eff[eno].pz += spd * eff[eno].zn;
            
            eff[eno].mdlver = se;
        }
    }
}

// 100% matching!
void bhEne14_SetMotion(BH_PWORK* epw)
{
	NJS_MKEY_A_MOD* mkaP; 
	NJS_CNK_OBJECT* objP;
	int i;
	int obj_list[4]   = {  7,  8,  9, 10 }; 
	int obj_list_f[4] = {  9, 10,  7,  8 }; 

    if (epw->mtn_md & 2)
    {
        for (i = 0; i < 4; i++)
        {
            objP = &epw->mlwP->objP[obj_list[i]];
            mkaP = (NJS_MKEY_A_MOD*)epw->mnwP[epw->mtn_no].md2P[obj_list_f[i]].p[1] + (epw->frm_no / 65536);

            objP->ang[0] =  mkaP->key[0];
            objP->ang[1] = -mkaP->key[1];
            objP->ang[2] = -mkaP->key[2];
        }
    } 
    else
    {
        for (i = 0; i < 4; i++)
        {
            objP = epw->mlwP->objP;
            objP += obj_list[i];
            mkaP = (NJS_MKEY_A_MOD*)epw->mnwP[epw->mtn_no].md2P[obj_list[i]].p[1] + (epw->frm_no / 65536);

            objP->ang[0] = mkaP->key[0];
            objP->ang[1] = mkaP->key[1];
            objP->ang[2] = mkaP->key[2];
        }
    }
}

// 100% matching!
void bhEne14_CheckWall(BH_PWORK* epw)
{
    bhEne03_Collision(epw);
    epw->py -= 8.0f;
    bhEne03_Collision(epw);
    epw->py += 8.0f;
    epw->py += 8.0f;
    bhEne03_Collision(epw);
    epw->py -= 8.0f;
}

// 100% matching!
void bhEne14_PlayerControl(BH_PWORK* epw)
{
    if ((plp->mode0 == 4) && !(epw->flg & 2))
    {
        switch (plp->mode2) 
        {
        case 0:
		case 1:
            switch (plp->mode3)
            {
            case 0:
                plp->flg &= ~0x40000;
                plp->flg |= 0x10000;
                plp->flg2 |= 1;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = 71;
                } 
                else
                {
                    plp->mtn_no = 72;
                }
    
                plp->frm_no = 0;
                plp->hokan_count = 3;
                plp->hokan_rate = 32768;
                plp->mtn_add = 65536;
                plp->mode3++;
                bhEne_CallPlayerVoice(2);
                StartVibrationEx(1, 9);
                break;
                
            case 1:
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = epw->mnwP;
                    
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = 31;
                    } 
                    else
                    {
                        plp->mtn_no = 32;
                    }
                    plp->frm_no = 0;
                    plp->hokan_count = 3;
                    plp->hokan_rate = 32768;
                    plp->mtn_add = 65536;
                    plp->mode3++;
                }
                break;
                
            case 2:
                if (plp->frm_no == 0)
                {
                    plp->mnwP = plp->mnwPb;
                    plp->flg &= ~0x10004;
                    plp->flg2 &= ~1;
                    plp->flg |= 8;
                    plp->at_flg = 0;
                    plp->stflg &= ~0x10000;
                    *(int*)&plp->mode0 = 1;    
                } 
                break;

            }
        } 
    } 
}

// 100% matching!
void bhEne14_CallSE(BH_PWORK* epw) 
{
    if (epw->mnwP == epw->mnwPb)
    {
        switch (epw->mtn_no)
        {
        case 1:
            if (epw->frm_no == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16851712);
            }
            break;
            
        case 2:
        case 3:
            if (epw->frm_no == 458752)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            break;
            
        case 4:
            if (epw->frm_no == 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8962);
            }
            break;
            
        case 22:
            if (epw->frm_no == 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16786193);
            }
            break;
        }
    }
}
