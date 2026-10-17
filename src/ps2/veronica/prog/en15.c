#include "../../../ps2/veronica/prog/en15.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/pwksub.h"

//#include <string.h>

// ENEMY: Nosferatu 

#pragma optimization_level 4

static char dbgout_buf[256];
static char poison_attack_wait;
static char poison_eff_wait;

static WPNDG_TBL WpnDamageTbl[21] = 
{
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 2, 2 },  
    { 2, 2, 2 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 2, 1, 1 },  
    { 0, 0, 0 },  
    { 2, 1, 2 },  
    { 0, 1, 1 },  
    { 2, 0, 1 },  
    { 2, 0, 0 },  
    { 2, 0, 0 },  
    { 1, 0, 0 },  
    { 1, 0, 0 },  
    { 2, 2, 2 },  
    { 0, 0, 0 },  
    { 2, 2, 2 }  
};
static COMBWEP_WORK CombWepTbl[21] = 
{
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  40, { 10,  0,  0 }, 30, 0 },
    {  70, { 10,  8,  0 }, 60, 0 },
    {  70, { 10,  8,  0 }, 60, 0 },
    {  40, { 10,  8,  0 }, 30, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  70, { 10,  8,  0 }, 30, 0 },
    { 160, { 10,  8,  0 }, 40, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  80, { 10,  8,  0 }, 70, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  60, { 10,  8,  0 }, 60, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
	{   0, {  0,  0,  0 },  0, 0 }
};
static COMBJOINT_WORK CombJointTbl[24] = { 0 };
static COMBO_EFF Combo_Eff[21] = 
{
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } }  
};
static char SdwTab[3]= { 20, 23, -1 };
static BT_WORK prt_blood_tbl[24]= 
{
    {  0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    {  1, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  2, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  3, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  4, 0.0f, 2.0f, 1.8f, 2.0f, 3.0f, 1.0f, 3.0f },
    {  5, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  6, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  7, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    {  8, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  9, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 10, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 11, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 12, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 13, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 14, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 15, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 16, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 17, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 18, 0.0f, 0.0f, 1.8f, 2.0f, 4.0f, 1.0f, 4.0f },
    { 19, 0.0f, 2.0f, 1.0f, 1.0f, 4.0f, 1.0f, 4.0f },
    { 20, 0.0f, 2.0f, 1.0f, 1.0f, 3.0f, 1.0f, 3.0f },
    { 21, 0.0f, 0.0f, 1.8f, 2.0f, 4.0f, 1.0f, 4.0f },
    { 22, 0.0f, 2.0f, 1.0f, 1.0f, 4.0f, 1.0f, 4.0f },
    { 23, 0.0f, 2.0f, 1.0f, 1.0f, 3.0f, 1.0f, 3.0f }
};
static char rfoot_joint_tree[6] = { 0, 1, 18, 19, 20, -1 };
static char lfoot_joint_tree[6] = { 0, 1, 21, 22, 23, -1 };
static LEGLOCK_LIST lrl_walk[2] = 
{
    { 40, 74 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_a1[2] = 
{
    { 64, 93 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_a2[2] = 
{
    { 25, 47 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_fldmg[2] = 
{
    { 18, 58 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_bldmg[2] = 
{
    { 27, 92 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_crdmg[2] = 
{
    { 25, 118 },
    { -1,  -1 }
};
static LEGLOCK_LIST lrl_dummy[1] = 
{
    { -1, -1 }
};
static LEGLOCK_TAB leglock_tab[11] = 
{
    {  1,  1, lrl_walk  },
    {  2,  1, lrl_a1    },
    {  3,  0, lrl_a2    },
    {  6,  0, lrl_dummy },
    {  7,  1, lrl_dummy },
    {  8,  1, lrl_fldmg },
    {  9,  1, lrl_bldmg },
    { 10,  0, lrl_crdmg },
    { 12,  0, lrl_dummy },
    { 13,  1, lrl_dummy },
    { -1, -1, NULL      }
};
static int attack1_col_joint[5] = { 7, 8, 9, 10, -1 };
static int attack2_col_joint[4] = { 8, 9, 10, -1 };
static int attack3_col_joint[6] = { 6, 7, 8, 9, 10, -1 };
static ATTACK_COL_TBL attack_col_tab[3] =
{
    { attack1_col_joint, 31, 56, 50, 8192, 6.05f, 4.3f, 41, 52 },
    { attack2_col_joint, 29, 40, 50, 5461,  4.0f, 3.3f,  0,  0 },
    { attack3_col_joint, 24, 32, 30, 7281,  4.5f, 5.0f, 24, 30 }
};
static CPCL CapColTab[23] = 
{
    {   3,   3,   4 },
    {   0,  12,  -8 },
    {   4,   4,  12 },
    {   0,   9,  -2 },
    {   3,   3,  10 },
    {  18,  14,   6 },
    {   3,   3,  10 },
    {  18,   5,   7 },
    {   3,   3,  10 },
    {  18,  -4,   8 },
    {   3,   3,  10 },
    { -18,  14,   6 },
    {   3,   3,  10 },
    { -18,   5,   7 },
    {   3,   3,  10 },
    { -18,  -4,   8 },
    {   4,   3,  12 },
    {   3,   2,  15 },
    {  18,  19,  10 },
    {  19,  20,  10 },
    {  21,  22,  10 },
    {  22,  23,  10 },
    {   0,   0,   0 }
};
static unsigned char flip_tree[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
static void (*Mode_func[6])(BH_PWORK*) = 
{
	Init,
	Move,
	Throw,
	Damage,
	Die,
	bhEne_Event
};
static void (*Move_func[5])(BH_PWORK*) = 
{
	Stand,
	CloseTurn,
	KeepFar,
	Chase,
	Attack
};
static void (*Ply_func[8])(BH_PWORK*) = 
{
	DrivePlayer,
	SlidePlayer,
	StandupPlayer,
	FallingPlayer,
	FallDiePlayer,
	HoldPlayer,
	FlyingPlayer,
	DiePlayer
};
/* unused below */
/*static JOINT_PARE jointTree[11];
static char joint_tree_buf[12];*/

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
static int target_direction(BH_PWORK* epw)
{
    float ans;

    ans = 0.005493164f * (NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz) - epw->ay);
    if (ans > 180.0f) {
        ans = ans + -360.0f;
    }
    else if (ans <= -180.0f)
    {
        ans = ans + 360.0f;
    }
    return (182.04445f * ans);
}

// 100% matching!
static float target_distance(BH_PWORK* epw)
{
    NJS_POINT3 epos;
    O_WORK* owk;

    owk = epw->mlwP->owP;
    epos.x = owk[1].mtx[12];
    epos.y = 0;
    epos.z = owk[1].mtx[14];
    
    return njDistanceP2P((NJS_POINT3*)&plp->px, &epos);
}

// 100% matching!
static int GetLocalEneNo(BH_PWORK* epw)
{
    int i;

    for (i = 0; i < 128; i++) 
    {
        if (&ene[i] == epw) 
        {
            return i;
        }
    }
    
    sprintf(dbgout_buf, "GetLocalEneNo : Not Found Enemy Object!!\n");
    
    write(1, dbgout_buf, sizeof(dbgout_buf));
    
    return -1;
}

// 100% matching!
static void SetMtnSE(BH_PWORK* epw)
{
    static MTN_SE_TBL mtn_se_tbl[30] = 
	{
		{   1,  38,    74496 },
		{   1,  74,    74496 },
		{   2,  33,    74498 },
		{   2,  11,    74496 },
		{   2,  57,    74496 },
		{   2,  96,    74496 },
		{   3,  32,    74500 },
		{   3,  15,    74496 },
		{   3,  47,    74496 },
		{   3,  66,    74496 },
		{   4,  24,    74498 },
		{   4,  20,    74496 },
		{   4,  20,    74496 },
		{   6,   1, 16851722 },
		{   7,   1, 16851722 },
		{   8,   9, 16851723 },
		{   8,  12,    74496 },
		{   8,  47,    74496 },
		{   9,  13, 16851723 },
		{   9,  26,    74496 },
		{   9,  58,    74496 },
		{  10,  33, 16851724 },
		{  10,  26,    74496 },
		{  10,  49,    74496 },
		{  10,  92,    74496 },
		{  11,   8, 16851725 },
		{  11,  91,     8974 },
		{  11, 150,     8974 },
		{  12,  21,    74496 },
		{  -1,   0,        0 }
	};
	int i;
  
    for (i = 0; mtn_se_tbl[i].mtn_no != -1; i++)
    {
        if ((epw->mtn_no == mtn_se_tbl[i].mtn_no) && ((epw->frm_no / 65536) == mtn_se_tbl[i].frm))
        {
            RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->px, mtn_se_tbl[i].seno);
            return;        
        }
    }
}
// 100% matching!
void bhEne15(BH_PWORK* epw)
{
	O_WORK* owk;

    if (poison_attack_wait != 0)
    {
        poison_attack_wait -= 1;
    }
    
    if (poison_eff_wait != 0)
    {
        poison_eff_wait -= 1;
    }

    if (epw->mode0 == 0)
    {
        Mode_func[epw->mode0](epw);
    }
    
    bhCalcModel(epw);
    if (epw->mode0 == 5)
    {
        Mode_func[epw->mode0](epw);
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        return;
    }
    
    if (!(epw->flg & 2) && !(epw->mdflg & 1))
    {
        CheckDamage(epw);
        SetMtn(epw);
        LockLeg(epw);
        bhCheckWall(epw);
        SetMtnSE(epw);
        if (epw->mode0 != 0)
        {
            Mode_func[epw->mode0](epw);
        }
        
        owk = epw->mlwP->owP;
        epw->watr.c1 = *(NJS_POINT3*)&owk[4].mtx[12];
        epw->watr.c1.y -= 1.0f;
        
        owk = epw->mlwP->owP;
        epw->watr.c2 = *(NJS_POINT3*)&owk[20].mtx[12];
        
        njAddVector(&epw->watr.c2, (NJS_VECTOR*)&(epw->mlwP->owP[23].mtx[12]));
        epw->watr.c2.x /= 2.0f;
        epw->watr.c2.y /= 2.0f;
        epw->watr.c2.z /= 2.0f;
        epw->watr.r = 2.5f;
    }
    
    if (EXP0_S(0x5A) & 1)
    {
        plp->flg |= 0x200000;
        Ply_func[epw->mode3](epw);
    }
}

// 99.86% matching
static void Init(BH_PWORK* epw) 
{   
    int i;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhGetFreeMemory(100, 32);
        if (epw->exp0 == NULL)
        {
            sprintf(dbgout_buf, "Can't Get WorkMemory!\n");
            write(1, dbgout_buf, sizeof(dbgout_buf));
        }
    }
    
    if (epw->exp0 != NULL)
    {
        EXP0_S(0x58) = -1;
        EXP0_S(0x5C) = 0;
    }
    
    epw->flg |= 0x178;
    epw->flg &= ~6;
    epw->mdflg &= ~4;
    EXP0_S(0x5A) = 0;
    bhCrFlg(sys->ev_flg, 57);
    epw->aox = epw->aoy = epw->aoz = 0.0f;
    
    epw->ar = 3.8f;
    epw->ah = 20.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 2.5f;
    epw->cah = 20.0f;
    epw->cpcl = CapColTab;
    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }
    
    if (sys->gm_mode == 2)
    {
        epw->hp = 360;
    } 
    else
    {
        epw->hp = 600;
    }
    
    bhEne_InitDamage(epw);
    epw->ct1 = 0;
    epw->ct2 = 0;
    epw->ct0 = 0;
    epw->mlwP->objP = epw->mbp[0];
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[0];
    epw->mdflg &= ~2;
    epw->shp_ct = 0.0f;
    if (!(epw->flg & 0x800))
    {
        float sxz = 5.0f; // Not from DWARF
        bhSetShadow(SdwTab, (unsigned char*)epw, 1, 6.0f, sxz, (float)sxz);
        epw->flg |= 0x800;
    }
    
    epw->clp_jno[0] = 4;
    epw->clp_jno[1] = 20;
    epw->clp_jno[2] = 23;
    epw->clp_jno[3] = -1;
    epw->mdflg |= 0x20;
    epw->lok_jno = 4;
    epw->mtn_md = 0;
    epw->mtn_no = -1;
    epw->mtn_tp = flip_tree;
    epw->mtn_add = 65536;
    epw->ct2 = 0;
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->way = 0;
    ReqMtn(epw, 0);
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 65536;
    epw->mtn_no = EXP0_S(0x58);
    
    if (bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp) != 0)
    {
        epw->flg |= 0x2000000;
    } else {
        epw->flg &= ~0x2000000;
    }

    EXP0_S(0x58) = -1;
}

// 100% matching!
static void Move(BH_PWORK* epw)
{
    Move_func[epw->mode1](epw);

    if (epw->ct2 != 0)
    {
        epw->ct2--;
    }

    if (epw->ct0 != 0)
    {
        epw->ct0--;
    }
    
    if (epw->ct1 != 0)
    {
        epw->ct1--;
    }
}

// 100% matching!
static void Stand(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
    
    if (35.0f <  target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 3;
        epw->way = 145;
        ReqMtn(epw, 1);
        return;
    }
    
    if (25.0f < target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
        return;
    }
    
    if (target_direction(epw) >= -NJM_DEG_ANG(10.0f))
    {
        if ((target_direction(epw) < NJM_DEG_ANG(10.0f)) && (7.0f > target_distance(epw))) 
        {
            if (plp->flg & 2) 
            {
                epw->ct2 = 30;
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->way = 0;
                ReqMtn(epw, 0);
                return;
            }
            else 
            {
                epw->mode2 = 0;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->way = 1456;
                ReqMtn(epw, 5);
                return;
            }            
        }
    }

    epw->ct2 = 30;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->way = 1456;
    ReqMtn(epw, 1);
}

// 100% matching! 
static void __attack(BH_PWORK* epw)
{
    int ang; 

    if (epw->mtn_no == 1)
    {
        switch (epw->frm_no / 65536) 
        {
        case 47 ... 54:

            ang = target_direction(epw);

            if ((epw->mode0 == 1) && (epw->mode1 == 2))
            {
                if ((((ang >= -24576) && (ang < -8192)) || ((ang >= 8192) && (ang < 24576))) && ((21.0f <= target_distance(epw)) && (target_distance(epw) < 30.0f))) 
                {
                    if ((plp->flg & 0x2)) 
                    {
                        epw->ct2 = 30;
                        
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        
                        epw->way = 0;
                        
                        ReqMtn(epw, 0);
                    } 
                    else if (epw->ct0 == 0) 
                    {
                        epw->mode2 = 0;
                        epw->mode0 = 1;
                        epw->mode1 = 4;
                        
                        epw->way = 3276;
                        
                        ReqMtn(epw, 3);
                    }
                    
                    break;
                }
            }

            if ((epw->mode0 == 1) && (epw->mode1 == 2)) 
            {
                if ((((ang >= -24576) && (ang < -8192)) || ((ang >= 8192) && (ang < 24576))) && ((17.0f <= target_distance(epw)) && (target_distance(epw) < 21.0f))) 
                {
                    if ((plp->flg & 0x2))
                    {
                        epw->ct2 = 30;
                        
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        
                        epw->way = 0;
                        
                        ReqMtn(epw, 0);
                    } 
                    else if (epw->ct0 == 0) 
                    {
                        epw->mode2 = 0;
                        epw->mode0 = 1;
                        epw->mode1 = 4;
                        
                        epw->way = 3276;
                        
                        ReqMtn(epw, 2);
                    }
                    
                    break;
                }
            }

            if (((ang >= -2730) && (ang < 2730)) && ((21.0f <= target_distance(epw)) && (target_distance(epw) < 30.0f)))
            {
                if ((plp->flg & 0x2)) 
                {
                    epw->ct2 = 30;
                    
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 0);
                }
                else if (epw->ct0 == 0) 
                {
                    epw->mode2 = 0;
                    epw->mode0 = 1;
                    epw->mode1 = 4;
                    
                    epw->way = 3276;
                    
                    ReqMtn(epw, 3);
                }
                
                break;
            }

            if (((ang >= -10922) && (ang < 10922)) && ((17.0f <= target_distance(epw)) && (target_distance(epw) < 22.0f)))
            {
                if ((plp->flg & 0x2)) 
                {
                    epw->ct2 = 30;
                    
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 0);
                } 
                else if (epw->ct0 == 0)
                {
                    epw->mode2 = 0;
                    epw->mode0 = 1;
                    epw->mode1 = 4;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 2);
                }
                
                break;
            }

            if ((((ang <= -16384) && (ang >= -32768)) || ((ang <= 32768) && (ang >= 16384))) && ((0 <= target_distance(epw)) && (target_distance(epw) < 22.0f)))
            {
                if ((plp->flg & 0x2))
                {
                    epw->ct2 = 30;
                    
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 0);
                } 
                else if (epw->ct0 == 0) 
                {
                    epw->mode2 = 0;
                    epw->mode0 = 1;
                    epw->mode1 = 4;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 4);
                }
                
                break;
            }

            if (((ang >= -16384) && (ang < 16384)) && (22.0f <= target_distance(epw)))
            {
                epw->ct3 = 0;
                
                if ((plp->flg & 0x2)) 
                {
                    epw->ct2 = 30;
                    
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 0);
                } 
                else if (epw->ct0 == 0) 
                {
                    epw->mode2 = 1;
                    epw->mode0 = 1;
                    epw->mode1 = 4;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 2);
                }
                
                break;
            }

            if ((((ang <= -16384) && (ang >= -32768)) || ((ang <= 32768) && (ang >= 16384))) && (22.0f <= target_distance(epw)))
            {
                epw->ct3 = 0;
                
                if ((plp->flg & 0x2))
                {
                    epw->ct2 = 30;
                    
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 0);
                } 
                else if (epw->ct0 == 0) 
                {
                    epw->mode2 = 1;
                    epw->mode0 = 1;
                    epw->mode1 = 4;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 4);
                }
                
                break;
            }
        }
    }
}

// 100% matching!
static void CloseTurn(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px,  epw->way);
    
    if (16.0f < target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
        return;
    }
    
    if (target_direction(epw) >= -NJM_DEG_ANG(10.0f))
    {
        if ((target_direction(epw) < NJM_DEG_ANG(10.0f)) && (7.0f > target_distance(epw)))
        {
            if (plp->flg & 2)
            {
                epw->ct2 = 30;
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->way = 0;
                ReqMtn(epw, 0);
            } 
            else
            {
                epw->mode2 = 0;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->way = 1456;
                ReqMtn(epw, 5);
            }
            return;
        }
    }

    if (9.0f < target_distance(epw))
    {
        __attack(epw);
    }
}

// 100% matching!
static void Chase(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
    
    if (25.0f > target_distance(epw)) 
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
    }
    else
    {
        __attack(epw);       
    }
}

// 100% matching!
static void __goalAng(BH_PWORK* epw, NJS_VECTOR* vec, NJS_VECTOR* ans)
{
    NJS_VECTOR v = { 0.0f, 1.0f, 0.0f };

    *vec = *(NJS_POINT3*)&plp->px;

    njSubVector(vec, (NJS_VECTOR*)&epw->px);
    njOuterProduct(vec, &v, ans);
}

// 100% matching!
static int _goalAng(BH_PWORK* epw)
{
    NJS_POINT3 vec;
    NJS_POINT3 ans;

    __goalAng(epw, &vec, &ans);   
    return njArcTan2(ans.x, ans.z);
}

// 100% matching!
static int _goalAng2(BH_PWORK* epw)
{
    NJS_POINT3 vec;
    NJS_POINT3 ans;

    __goalAng(epw, &vec, &ans);   
    njAddVector(&ans, &vec);
    return njArcTan2(ans.x, ans.z);
}

// 100% matching!
static void KeepFar(BH_PWORK* epw)
{
    if (9.0f > target_distance(epw)) 
    {
        epw->ct2 = 30;
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->way = 1456;
        ReqMtn(epw, 1);
    } 
    else
    {
        if (16.0f > target_distance(epw))
        {
            bhEne15_RotChar(epw, _goalAng2(epw), epw->way);
        } 
        else
        {
            bhEne15_RotChar(epw, _goalAng(epw), epw->way);
        }
        
        if (35.0f < target_distance(epw))
        {
            epw->mode0 = 1;
            epw->mode1 = 3;
            epw->way = 145;
            ReqMtn(epw, 1);
        }
        else
        {
            __attack(epw);
        }        
    }    
}

// 100% matching!
static void Attack(BH_PWORK* epw) 
{    
    int i;                                                 
    NJS_VECTOR attack_v;                                
    ATTACK_COL col;                                        

    if (epw->ct3 != 0) 
    {
        epw->ct3--;
    }

    if ((epw->mtn_no >= 2) && (epw->mtn_no < 5)) 
    {
        ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
        
        if ((epw->frm_no / 65536) == 20) 
        {
            epw->way = 0;
        }
        
        if (((attack_col_tab[MTN_NO_CHECK(epw)].start_frm <= (epw->frm_no / 65536)) && ((epw->frm_no / 65536) < attack_col_tab[MTN_NO_CHECK(epw)].end_frm)) && (!(EXP0_S(90) & 0x1)))
        {
            for (i = 0; attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] != -1; i++) 
            {
                if (MTN_NO_CHECK(epw) == 1)
                {
                    NJS_POINT3 _p; 
                    
                    col.cap.r = attack_col_tab[MTN_NO_CHECK(epw)].volume;
                    
                    _p.x = 0;
                    _p.y = 0;
                    _p.z = 0;
                    
                    njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, &col.cap.c1);
                    
                    if (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] != -1) 
                    {
                        NJS_POINT3 _p; 

                        _p.x = 0;
                        _p.y = 0;
                        _p.z = 0;
                        
                        njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1]].mtx, &_p, &col.cap.c2);
                    } 
                    else 
                    {
                        NJS_POINT3 _p = { 0, 8.0f, 0 }; 
                        
                        njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &col.cap.c2);
                    }
                } 
                else
                {
					static char left_idx[4] = { 0, 4, 5, 1 }, right_idx[4] = { 3, 7, 6, 2 }; 
                    float vane_width; 
                    char* f_idx, *b_idx;      

                    vane_width = 2.0f;
                    
                    if (MTN_NO_CHECK(epw) == 0)
                    {
                        b_idx = left_idx;
                        f_idx = right_idx;
                    } 
                    else
                    {
                        vane_width *= -1.0f;
                        
                        b_idx = right_idx;
                        f_idx = left_idx;
                    }

                    col.box.v[b_idx[0]] = col.box.v[b_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 5));
                    
                    col.box.v[b_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    col.box.v[b_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    
                    {
                        NJS_POINT3 _p; 
                        
                        _p.x = vane_width;
                        _p.y = 0;
                        _p.z = 0;
                        
                        njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, &col.box.v[b_idx[3]]);
                    }
                    
                    col.box.v[b_idx[2]] = col.box.v[b_idx[3]];
                    
                    col.box.v[b_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    col.box.v[b_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                    if (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] != -1)
                    {
                        col.box.v[f_idx[0]] = col.box.v[f_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] - 5));
                        
                        col.box.v[f_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                        {
                            NJS_POINT3 _p; 
                            
                            _p.x = vane_width;
                            _p.y = 0;
                            _p.z = 0;
                            
                            njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1]].mtx, &_p, &col.box.v[f_idx[3]]);
                        }

                        col.box.v[f_idx[2]] = col.box.v[f_idx[3]];
                        
                        col.box.v[f_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    } 
                    else 
                    {
                        
                        col.box.v[f_idx[0]] = col.box.v[f_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 4));

                        col.box.v[f_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                        {
                            NJS_POINT3 _p = { 0, 9.8f, 0 }; 
                            
                            _p.x = vane_width;
                            
                            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &col.box.v[f_idx[3]]);
                        }

                        col.box.v[f_idx[2]] = col.box.v[f_idx[3]];
                        
                        col.box.v[f_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    }
                }

                if (MTN_NO_CHECK(epw) == 1) 
                {
                    NJS_MATRIX mat;                   
                    NJS_VECTOR vec = { 0, 0, -1.0f }; 
                    
                    njUnitMatrix(&mat);
                    
                    njRotateY(&mat, epw->ay);
                    njCalcVector(&mat, &vec, &attack_v);
                } 
                else
                {
                    NJS_VECTOR vec0, vec1; 

                    vec0 = col.box.v[1];
                    vec1 = col.box.v[2];
                    
                    njSubVector(&vec1, &vec0);
                    
                    vec0.x = 0;
                    vec0.y = 1.0f;
                    vec0.z = 0;
                    
                    njOuterProduct(&vec0, &vec1, &attack_v);
                }
                    
                njUnitVector(&attack_v);
                
                attack_v.x *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                attack_v.y *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                attack_v.z *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                
                {
                    NJS_MATRIX mat;                 
                    NJS_VECTOR vec = { 0, 1.0f, 0 };
                    NJS_POINT3 axis;                 

                    njOuterProduct(&attack_v, &vec, &axis);
                    
                    njUnitVector(&axis);
                    
                    vec = attack_v; 
                    
                    njUnitMatrix(&mat);
                    
                    njRotate(&mat, &axis, attack_col_tab[MTN_NO_CHECK(epw)].impact_ang);
                    njCalcVector(&mat, &vec, &attack_v);
                }
                
                if (((MTN_NO_CHECK(epw) == 1) ? bhEne15_AttackPlayerCC(&col.cap, &attack_v, attack_col_tab[MTN_NO_CHECK(epw)].damage) : bhEne15_AttackPlayerBC(&col.box, &attack_v, attack_col_tab[MTN_NO_CHECK(epw)].damage)) != 0)
                {
                    bhEne_SetBloodEffect(plp, 1, -1);  
                    
                    RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->dpx, (MTN_NO_CHECK(epw) == 1) ? 0x12305 : 0x12303);
                    
                    StartVibrationEx(1, 11);
                    
                    plp->flg &= ~0x110;
                    
                    if (bhDGCdirCheck((NJS_VECTOR*)&plp->dvx, plp->ay) != 0) 
                    {
                        plp->day += 32768;
                        
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 0;
                        
                        plp->spd = 0;
                        
                        SetPlyMtn(14);
                        
                        plp->mode0 = 5;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    } 
                    else
                    {
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 0;
                        
                        plp->spd = 0;
                        
                        SetPlyMtn(15);
                        
                        plp->mode0 = 5;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    }
                    
                    break;
                }
            }
        }

        if (((attack_col_tab[MTN_NO_CHECK(epw)].sp_start_frm <= (epw->frm_no / 65536)) && ((epw->frm_no / 65536) < attack_col_tab[MTN_NO_CHECK(epw)].sp_end_frm)) && (epw->mode2 == 1))
        {
            NJS_VECTOR splash_v;            
            NJS_POINT3 _p = { 0, 9.8f, 0 }; 
            
            _p.x = 0; 
            
            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &splash_v);
            njSubVector(&splash_v, (NJS_VECTOR*)epw->exp0 + 6);
            
            SpecialAttack(epw, &splash_v);
        }

        if (MTN_NO_CHECK(epw) != 1) 
        {
            NJS_POINT3 _p; 
            
            for (i = 0; attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] != -1; i++) 
            {
                _p.x = 0;
                _p.y = 0;
                _p.z = 0;
                
                njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, (NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 5));
            }
            
            {
                NJS_POINT3 _p = { 0, 9.8f, 0 };
                
                _p.x = 0; 
                
                njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, (NJS_POINT3*)epw->exp0 + 6);
            }
        }

        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            epw->ct0 = (rand() % 150) + 30;
            
            epw->mode0 = 1;
            epw->mode1 = 3;
            
            epw->way = 145;
            
            ReqMtn(epw, 1);
        }
    }
}

// 100% matching! 
static void Throw(BH_PWORK* epw)
{
    if ((epw->mode2 == 0) && ((epw->frm_no / 65536) < 22))
    {
        ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
    }
    
    if (epw->mtn_no == 5)
    {
        if (epw->mode2 != 0)
        {
            if ((epw->frm_no / 65536) == 0)
            {
                epw->mode0 = 1;
                epw->mode1 = 3;
                
                epw->way = 145;
                
                ReqMtn(epw, 1);
            }
        } 
        else
        {
            if ((epw->frm_no / 65536) == 0)
            {
                if ((((plp->mode0 == 3) || (plp->mode0 == 6)) || (plp->hp < 0)) || (((target_direction(epw) < -2730) || (target_direction(epw) >= 2730)) || (9.0f < target_distance(epw))))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 3;
                    
                    epw->way = 145;
                    
                    ReqMtn(epw, 1);
                    return;
                }
            }

            if ((epw->frm_no / 65536) == 22) 
            {
                if ((((plp->mode0 != 3) && (plp->mode0 != 6)) && (plp->hp >= 0)) && (((target_direction(epw) >= -2730) && (target_direction(epw) < 2730)) && (9.0f >= target_distance(epw))))
                {
                    if (bhCdirCheck(plp->ay, epw->ay) != 0)
                    {
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 5;
                        
                        plp->spd = 1.0f;
                        
                        SetPlyMtn(21);
                        
                        plp->mode0 = 4;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    } 
                    else
                    {
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 5;
                        
                        plp->spd = 1.0f;
                        
                        SetPlyMtn(19);
                        
                        plp->mode0 = 4;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    }
                    
                    RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->px, 74502);
                    
                    StartVibrationEx(1, 9);
                    
                    epw->flg &= ~0x40;
                }
                else
                {
                    epw->mode2 = 1;
                    
                    epw->mtn_add = -65536;
                    return;
                }
            }

            if ((epw->frm_no / 65536) == 55)
            {
	            NJS_POINT3 pos, _p  = { 0.0f, 8.0f, 0.0f }; 

                njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &pos);
                
                if (bhEne_AttackHitCheck(plp, &pos, 3.0f))
                {
                    bhEne_SetBloodEffect(plp, 1, -1);
                }
                
                RequestEnemySe(GetLocalEneNo(epw), &pos, 74503);
                
                plp->flg &= ~0x118;
                
                EXP0_S(90) |= 0x1;
                
                epw->mode3 = 6;
                
                plp->spd = 0;
            }
            
            if ((epw->frm_no / 65536) == 78)
            {
            	NJS_MATRIX mat;
            	NJS_VECTOR attack_v, vec = { 0.0f, 0.0f, -1.0f }; 

                njUnitMatrix(&mat);
                
                njRotateY(&mat, epw->ay + 32768);
                njCalcVector(&mat, &vec, &attack_v);
                
                njUnitVector(&attack_v);
                
                attack_v.x *= 3.0f;
                attack_v.y *= 3.0f;
                attack_v.z *= 3.0f;
                
                plp->dax = njArcTan2(attack_v.y, attack_v.z);
                plp->day = njArcTan2(attack_v.x, attack_v.z);
                
                *(NJS_VECTOR*)&plp->dvx = attack_v;
                
                RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&plp->px, 74504);
                
                plp->flg &= ~0x100;
                
                if (bhDGCdirCheck((NJS_VECTOR*)&plp->dvx, plp->ay) != 0) 
                {
                    EXP0_S(90) |= 0x1;
                    
                    epw->mode3 = 0;
                    
                    plp->spd = 0;
                } 
                else
                {
                    EXP0_S(90) |= 0x1;
                    
                    epw->mode3 = 0;
                    
                    plp->spd = 0;
                }             
                
                epw->flg |= 0x40;
            }
            
            if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
            {
                epw->ct2 = ((rand() % 10) * 20) + 15;
                
                epw->mode0 = 1;
                epw->mode1 = 0;
                
                epw->way = 0;
                
                ReqMtn(epw, 0);
                return;
            }
        }
    }
}

// 100% matching!
static void Damage(BH_PWORK* epw)
{
    if ((epw->mtn_no >= 6) && (epw->mtn_no < 11))
    {
        if ((epw->mtn_no == 10) && ((epw->frm_no / 65536) == 1))
        {
            EXP0_I(0x54) = (epw->ay + NJM_DEG_ANG(90.0f));
        }

        if (epw->mtn_no == 10)
        {
            if (((epw->frm_no / 65536) >= 29) && ((epw->frm_no / 65536) < epw->mnwP[epw->mtn_no].frm_num))
            {
                bhEne15_RotChar(epw, EXP0_I(0x54), 910);
            }
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode0 = 1;
            epw->mode1 = 3;
            epw->way = 145;
            ReqMtn(epw, 1);
            epw->ct1 = 60;
        }
    }
}

// 100% matching!
static void Die(BH_PWORK* epw)
{
    NJS_VECTOR vec;

    if (epw->mtn_no == 11)
    {
        vec = *(NJS_VECTOR*)&epw->px;
        njSubVector(&vec, (NJS_VECTOR*)&epw->mlwP->owP[4].mtx[12]);
        vec.y = 0.0f;
        if (njScalor(&vec) > 3.8f)
        {
            epw->ar = njScalor(&vec);
        } 
        else 
        {
            epw->ar = 3.8f;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg &= ~0x40;
            epw->flg |= 2;
            epw->mtn_add = 0;
            if ((epw->mode1 == 0) && (sys->gm_flg & 0x40))
            {
                sys->gm_flg &= ~0x40;
                if (!(sys->gm_flg & 0x1000000))
                {
                    sys->gm_flg &= ~0x80;
                }
                
                sys->gm_flg |= 0x800;
                
                if (sys->st_flg & 0x800000) 
                {
                    sys->st_flg &= ~0x800000;
                    sys->gm_flg &= ~0x80000;
                    sys->pt_flg |= 1;
                }
            }
        }
    }
}

// 100% matching!
static int NearestCapsule(BH_PWORK* epw, NJS_VECTOR* pos, NJS_CAPSULE* dest, short* jnt)
{
	NJS_CAPSULE top;
	short topjnt;
	float topdis;
	int notop;
	CPCL* ctab;
	NJS_CAPSULE cap;
	float dis;  
	short _jnt;
	NJS_POINT3 p;
   
    ctab = epw->cpcl;
    notop = 1;

    while ((ctab->jnt_a != 0) && (ctab->jnt_b != 0) && (ctab->cap_r != 0))
    {
        if (ctab->jnt_a != ctab->jnt_b)
        {
            _jnt = ctab->jnt_a;
            cap.c1 = *(NJS_POINT3*)&epw->mlwP->owP[ctab->jnt_a].mtx[12];
            cap.c2 = *(NJS_POINT3*)&epw->mlwP->owP[ctab->jnt_b].mtx[12];
            cap.r = 0.1f * ctab->cap_r;
        } 
        else
        {
            _jnt = ctab->jnt_a;
            cap.c1 = *(NJS_POINT3*)&epw->mlwP->owP[ctab->jnt_a].mtx[12];
            cap.r = 0.1f * ctab->cap_r;
            ctab++;
            cap.c2.x = 0.1f * ctab->jnt_a;
            cap.c2.y = 0.1f * ctab->jnt_b;
            cap.c2.z = 0.1f * ctab->cap_r;
            njAddVector((NJS_VECTOR*)&cap.c1, (NJS_VECTOR*)&cap.c2);
            cap.c2 = cap.c1;
        }

        p.x = (cap.c1.x + cap.c2.x) / 2.0f;
        p.y = (cap.c1.y + cap.c2.y) / 2.0f;
        p.z = (cap.c1.z + cap.c2.z) / 2.0f;
        dis = njDistanceP2P(pos, &p);

        if (notop != 0)
        {
            topdis = dis;
            top = cap;
            topjnt = _jnt;
            notop = 0;
        } 
        else if (dis < topdis) 
        {
            topdis = dis;
            top = cap;
            topjnt = _jnt;
        }
        ctab++;
    }

    *dest = top;
    *jnt = topjnt;
    
    return !notop;
}

// 100% matching! 
static void CheckDamage(BH_PWORK* epw)
{
    int is_core_damage; 
    NJS_POINT3 ofs, pos;    
    NJS_POINT3 ofp;   
    NJS_CAPSULE cap;   
    short jnt;         
    
    if (!(epw->flg & 0x4))
    {
        return;
    }

    is_core_damage = FALSE;
    
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);

    if ((!(epw->comb_flg & 0x8)) && (epw->wpnr_no == 2)) 
    {
        ofs.x = 0.1f * CapColTab[1].jnt_a;
        ofs.y = 0.1f * CapColTab[1].jnt_b;
        ofs.z = 0.1f * CapColTab[1].cap_r;
        
        njCalcPoint(&epw->mlwP->owP[3].mtx, &ofs, &pos);
        njSubVector(&pos, (NJS_VECTOR*)&epw->dpx);
        
        if (njScalor(&pos) < (3.0f + (0.1f * CapColTab[0].cap_r))) 
        {
            is_core_damage = 1;
            
            epw->total_dam *= 20;
        }
    }

    if ((!(epw->comb_flg & 0x8)) && ((epw->wpnr_no == 13) && (epw->cpcl_no == 0))) 
    {
        is_core_damage = TRUE;
        
        epw->total_dam *= 5;
    }

    epw->hp -= epw->total_dam;

    if (is_core_damage != FALSE)
    {
        if (epw->hp >= 0) 
        {
            bhEne_SetBloodEffect5(epw, 0, 1);
        }
    }
    else 
    {
        if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4))) 
        {
            if (((epw->comb_flg & 0x1)) && (Combo_Eff[epw->wpnr_no].blood_type[((epw->comb_flg & 0x10)) ? 0 : ((epw->comb_flg & 0x20)) ? 1 : 2] != -1)) 
            {
                bhEne_SetBloodEffect5(epw, 0, Combo_Eff[epw->wpnr_no].blood_type[((epw->comb_flg & 0x10)) ? 0 : ((epw->comb_flg & 0x20)) ? 1 : 2]);
            } 
            else if (WpnDamageTbl[epw->wpnr_no].blood_type != -1) 
            {
                bhEne_SetBloodEffect5(epw, 0, WpnDamageTbl[epw->wpnr_no].blood_type);
            }
        }

        if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4))) 
        {
            bhEne_SetPoison(epw, prt_blood_tbl);
        }
    }

    if ((epw->wpnr_no == 18) || ((epw->wpnr_no == 16) && ((epw->flg2 & 0x4))) || ((epw->wpnr_no == 16) && ((-rand() / -2147483648.0f) < 0.3))) 
    {
        NearestCapsule(epw, (NJS_POINT3*)&epw->dpx, &cap, &jnt);
        
        npDistanceP2C((NJS_POINT3*)&epw->dpx, &cap, &ofp);
        
        njSubVector(&ofp, (NJS_VECTOR*)&epw->mlwP->owP[jnt].mtx[12]);
         
        bhEne_SetFireEffect(epw, jnt, &ofp, 2.0f, 90);
    }

    if (epw->hp >= 0) 
    {
        if (is_core_damage != FALSE) 
        {
            epw->mode0 = 3;
            epw->mode1 = 4;
            
            epw->way = 0;
            
            ReqMtn(epw, 10);
        } 
        else if ((epw->comb_flg & 0x1))
        {
            switch (Combo_Eff[epw->wpnr_no].dmg_type[((epw->comb_flg & 0x10)) ? 0 : ((epw->comb_flg & 0x20)) ? 1 : 2]) 
            {
            case 1:
                if ((epw->comb_flg & 0x8)) 
                {
                    epw->mode0 = 3;
                    epw->mode1 = 1;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 7);
                } 
                else 
                {
                    epw->mode0 = 3;
                    epw->mode1 = 0;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 6);
                }
                
                break;
            case 2:
                if ((epw->comb_flg & 0x8)) 
                {
                    epw->mode0 = 3;
                    epw->mode1 = 3;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 9);
                } 
                else 
                {
                    epw->mode0 = 3;
                    epw->mode1 = 2;
                    
                    epw->way = 0;
                    
                    ReqMtn(epw, 8);
                }
                
                break;
            }
        } 
        else if ((epw->mode0 != 2) && (epw->mode0 != 3) && ((epw->mode0 != 1) || (epw->mode1 != 4)))  
        {
            if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4))) 
            {
                switch (WpnDamageTbl[epw->wpnr_no].dmg_type) 
                {
                case 1:
                    if ((epw->comb_flg & 0x8))
                    {
                        if (((epw->ct1 == 0) && (epw->mtn_no == 1)) && (((epw->frm_no / 65536) >= 21) && ((epw->frm_no / 65536) < 29)))
                        {
                            epw->mode0 = 3;
                            epw->mode1 = 1;
                            
                            epw->way = 0;
                            
                            ReqMtn(epw, 7);
                        }
                    } 
                    else 
                    {
                        if (((epw->ct1 == 0) && (epw->mtn_no == 1)) && (((epw->frm_no / 65536) >= 47) && ((epw->frm_no / 65536) < 55)))
                        {
                            epw->mode0 = 3;
                            epw->mode1 = 0;
                            
                            epw->way = 0;
                            
                            ReqMtn(epw, 6);
                        }
                    }
                    
                    break;
                case 2:
                    if ((epw->comb_flg & 0x8)) 
                    {
                        if (((epw->ct1 == 0) && (epw->mtn_no == 1)) && (((epw->frm_no / 65536) >= 62) && ((epw->frm_no / 65536) < 74)))
                        {
                            epw->mode0 = 3;
                            epw->mode1 = 3;
                            
                            epw->way = 0;
                            
                            ReqMtn(epw, 9);
                        }
                    } 
                    else 
                    {
                        if (((epw->ct1 == 0) && (epw->mtn_no == 1)) && (((epw->frm_no / 65536) >= 13) && ((epw->frm_no / 65536) < 25)))
                        {
                            epw->mode0 = 3;
                            epw->mode1 = 2;
                            
                            epw->way = 0;
                            
                            ReqMtn(epw, 8);
                        }
                    }
                    
                    break;
                }
            }
        }
    } 
    else if (epw->mode0 != 4)
    {
        if (sys->gm_mode != 3) 
        {
            if (is_core_damage != FALSE) 
            {
                epw->flg |= 0x2;
                
                bhStFlg(sys->ev_flg, 57);
                
                if ((sys->gm_flg & 0x40))
                {
                    sys->gm_flg &= ~0x40;
                    
                    if (!(sys->gm_flg & 0x1000000))
                    {
                        sys->gm_flg &= ~0x80;
                    }
                    
                    sys->gm_flg |= 0x800;
                    
                    if ((sys->st_flg & 0x800000)) 
                    {
                        sys->st_flg &= ~0x800000;
                        sys->gm_flg &= ~0x80000;
                        
                        sys->pt_flg |=  0x1;
                    }
                }
            } 
            else 
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                
                epw->way = 0;
                
                ReqMtn(epw, 11);
            }
        } 
        else 
        {
            epw->mode0 = 4;
            epw->mode1 = 1;
            
            epw->way = 0;
            
            ReqMtn(epw, 11);
        }
    }

    epw->flg &= ~0x4;
    
    bhEne_InitDamage(epw);
}

static MTN_RELAY mtn_relay[21] = 
{
    {  1,  2, 55,  0 },
    {  1,  3, 55,  0 },
    {  1,  4, 55,  0 },
    {  2,  1, -1,  0 },
    {  3,  1, -1,  0 },
    {  4,  1, -1, 23 },
    {  1,  5, 55,  0 },
    {  1,  6, 55,  0 },
    {  1,  7, 29,  0 },
    {  6,  1, -1, 31 },
    {  7,  1, -1, 38 },
    {  8,  1, -1, 23 },
    {  9,  1, -1,  0 },
    { 10,  1, -1, 64 },
    {  1, 12, 55,  0 },
    { 12,  0, -1,  0 },
    {  0, 13,  1,  0 },
    { 13,  1, -1, 23 },
    {  5,  0, -1,  0 },
    {  5,  1,  0, 56 },
    { -1,  0,  0,  0 }
};
static MTN_RELAY_RELAY mtn_relay_relay[4] = 
{
    {  1,  0, &mtn_relay[14] },
    {  0,  1, &mtn_relay[16] },
    {  5,  1, &mtn_relay[18] },
    { -1,  0, NULL           }
};

// 100% matching!
static int GetRelay(BH_PWORK* epw, MTN_RELAY** ret)
{
    int i;    
	int found; 

    *ret = NULL;
    
    found = FALSE;
    
    for (i = 0; mtn_relay[i].old_mtn_no != -1; i++)
    {
        if ((epw->mtn_no == mtn_relay[i].old_mtn_no) && (EXP0_S(88) == mtn_relay[i].next_mtn_no))
        { 
            if (((epw->frm_no / 65536) == mtn_relay[i].from) || ((mtn_relay[i].from == -1) && ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))))
            {
                *ret = &mtn_relay[i];
                
                return 1;
            }

            found = TRUE;
        }
    }

    for (i = 0; mtn_relay_relay[i].old_mtn_no != -1; i++)
    {
        if ((epw->mtn_no == mtn_relay_relay[i].old_mtn_no) && (EXP0_S(88) == mtn_relay_relay[i].next_mtn_no))
        {
            if (((epw->frm_no / 65536) == mtn_relay_relay[i].relay->from) || ((mtn_relay_relay[i].relay->from == -1) && ((epw->frm_no / 65536) >= (epw->mnwP[epw->mtn_no].frm_num - 1))))
            {
                *ret = mtn_relay_relay[i].relay;
                
                return 1;
            }

            found = TRUE;
        }
    }

    return found;
}

// 100% matching!
static void SetMtn(BH_PWORK* epw)
{
    MTN_RELAY* relay;

    if (EXP0_S(88) != -1)
    {
        if (GetRelay(epw, &relay) != 0)
        {
            if (relay != NULL)
            {
                epw->hokan_rate  = 19660;
                epw->hokan_count = 30;
                
                epw->frm_no = 65536.0f * relay->to;
                
                epw->mtn_add = 65536;
                epw->mtn_no  = relay->next_mtn_no;

                if (bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp) != 0)
                {
                    epw->flg |=  0x2000000;
                }
                else
                {
                    epw->flg &= ~0x2000000;
                }

                if (EXP0_S(88) == epw->mtn_no)
                {
                    EXP0_S(88) = -1;
                }

                return;
            }
        }
        else if (epw->mtn_no != EXP0_S(88))
        {
            epw->hokan_rate  = 6553;
            epw->hokan_count = 0;
            
            epw->frm_no = 0;
            
            epw->mtn_add = 65536;
            epw->mtn_no  = EXP0_S(88);

            if (bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp) != 0)
            {
                epw->flg |=  0x2000000;
            }
            else
            {
                epw->flg &= ~0x2000000;
            }

            EXP0_S(88) = -1;
            return;
        }
    }

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
}

// 100% matching!
static void ReqMtn(BH_PWORK* epw, unsigned int mtn_no)
{
    EXP0_S(0x58) = mtn_no;
}

// 100% matching!
static void SetPlyMtn(unsigned int mtn_no)
{
    plp->hokan_rate = 13107;
    plp->hokan_count = 10;
    plp->frm_no = 0;
    plp->mtn_add = 65536;
    plp->mtn_no = mtn_no;
    
    if (bhSetMotion(plp, 0, plp->mtn_md, plp->mtn_tp) != 0)
    {
        plp->flg |= 0x2000000;
    } 
    else
    {
        plp->flg &= ~0x2000000;
    }

    if (plp->mtn_no == 26)
    {
        plp->py -= 10.6722f;
    }
    
    if (plp->mtn_no == 25)
    {
        plp->py -= 10.7582f;
    }
}

// 100% matching!
static int VacumeToPoint(BH_PWORK* pw, NJS_VECTOR* pos)
{
    NJS_VECTOR v;
    
    v = *pos;
    
    njSubVector(&v, (NJS_VECTOR*)&pw->px);
    if (njScalor(&v) > pw->spd)
    {
        njUnitVector(&v);
        v.x *= pw->spd;
        v.y *= pw->spd;
        v.z *= pw->spd;
        njAddVector((NJS_VECTOR*)&pw->px, &v);
        return 0;
    }
    
    *(NJS_POINT3*)&pw->px = *pos;

    return 1;
}

// 100% matching! 
static void LockLeg(BH_PWORK* epw)
{
    int i, j;        
	char lock_leg;
    int ii, jj; // not from DWARF
 
    for (i = 0; ii = 0, ((leglock_tab[i].mtn_no == leglock_tab[i].default_lr) ? ((leglock_tab[i].mtn_no == -1) ? (ii = 1) : 0) : 0, ((ii != 0) ? 1 : 0)) == 0; i++) // convoluted isn't the word
    {
        if (epw->mtn_no == leglock_tab[i].mtn_no)
        {
            lock_leg = leglock_tab[i].default_lr;
 
            for (j = 0; jj = 0, ((leglock_tab[i].list[j].start == leglock_tab[i].list[j].end) ? ((leglock_tab[i].list[j].start == -1) ? (jj = 1) : 0) : 0, ((jj != 0) ? 1 : 0)) == 0; j++)
            {
                if ((leglock_tab[i].list[j].start <= (epw->frm_no / 65536)) && (leglock_tab[i].list[j].end > (epw->frm_no / 65536)))
                {
                    if (lock_leg == 0)
                    {
                        lock_leg = 1;
                    }
                    else
                    {
                        lock_leg = 0;
                    }
                }
            }
 
            if (lock_leg == 0)
            {
                bhFixPosition(epw, rfoot_joint_tree);
            }
            else
            {
                bhFixPosition(epw, lfoot_joint_tree);
            }
            
            return;
        }
    }
} 

// 100% matching! 
int bhEne15_AttackPlayerCC(NJS_CAPSULE* cap, NJS_VECTOR* attack_v, int damage)
{
    int j;
    int kno;
    float latest;
    NJS_POINT3 hit_p;
    float distance;
    NJS_POINT3 tar_p;

    if (njCollisionCheckCC(cap, &plp->watr) != 0)
    {
        hit_p.x = (cap->c1.x + cap->c2.x) / 2.0f;
        hit_p.y = (cap->c1.y + cap->c2.y) / 2.0f;
        hit_p.z = (cap->c1.z + cap->c2.z) / 2.0f;

        for (j = 0; j < plp->mlwP->obj_num; j++)
        {
            tar_p.x = plp->mlwP->owP[j].mtx[12];
            tar_p.y = plp->mlwP->owP[j].mtx[13];
            tar_p.z = plp->mlwP->owP[j].mtx[14];
            if (j == 0) 
            {
                latest = njDistanceP2P(&hit_p, &tar_p);
                kno = 0;
            } 
            else
            {
                distance = njDistanceP2P(&hit_p, &tar_p);
                if (latest > distance) 
                {
                    latest = distance;
                    kno = j;
                }
            }
        }

        plp->dax = njArcTan2(attack_v->y, attack_v->z);
        plp->day = njArcTan2(attack_v->x, attack_v->z);
        plp->dvx = attack_v->x;
        plp->dvy = attack_v->y;
        plp->dvz = attack_v->z;
        plp->djnt_no = kno;
        plp->dpx = hit_p.x;
        plp->dpy = hit_p.y;
        plp->dpz = hit_p.z;
        plp->dam[kno] = damage;
        plp->hp -= damage;
        plp->flg |= 4;
        return 1;
    }
    
    return 0;
}

// 100% matching!
int bhEne15_AttackPlayerBC(NJS_BOX* box, NJS_VECTOR* attack_v, int damage)
{
	int j;
	int kno;
	float latest;
	NJS_POINT3 hit_p;
	float distance;
	NJS_POINT3 tar_p;

    if (njCollisionCheckBC2(box, &plp->watr) != 0)
    {
        hit_p.x = (box->v[6].x + (box->v[5].x + (box->v[1].x + box->v[2].x))) / 4.0f;
        hit_p.y = (box->v[6].y + (box->v[5].y + (box->v[1].y + box->v[2].y))) / 4.0f;
        hit_p.z = (box->v[6].z + (box->v[5].z + (box->v[1].z + box->v[2].z))) / 4.0f;

        for (j = 0; j < plp->mlwP->obj_num; j++)
        {
            tar_p.x = plp->mlwP->owP[j].mtx[12];
            tar_p.y = plp->mlwP->owP[j].mtx[13];
            tar_p.z = plp->mlwP->owP[j].mtx[14];
            if (j == 0) 
            {
                latest = njDistanceP2P(&hit_p, &tar_p);
                kno = 0;
            } 
            else
            {
                distance = njDistanceP2P(&hit_p, &tar_p);
                if (latest > distance) 
                {
                    latest = distance;
                    kno = j;
                }
            }
        }

        plp->dax = njArcTan2(attack_v->y, attack_v->z);
        plp->day = njArcTan2(attack_v->x, attack_v->z);
        plp->dvx = attack_v->x;
        plp->dvy = attack_v->y;
        plp->dvz = attack_v->z;
        plp->djnt_no = kno;
        plp->dpx = hit_p.x;
        plp->dpy = hit_p.y;
        plp->dpz = hit_p.z;
        plp->dam[kno] = damage;
        plp->hp -= damage;
        plp->flg |= 4;
        return 1;
    }
    
    return 0;
}

// 100% matching!
int bhEne15_AttackPlayerSS(NJS_SPHERE* spr, NJS_VECTOR* attack_v, int damage)
{
    NJS_SPHERE plcol;
    
    plcol.c.x = plp->mlwP->owP[5].mtx[12];
    plcol.c.y = plp->mlwP->owP[5].mtx[13];
    plcol.c.z = plp->mlwP->owP[5].mtx[14];
    plcol.r = 2.0f;

    if (njCollisionCheckSS(&plcol, spr) != 0)
    {
        plp->dax = NJM_RAD_ANG(atan2f(attack_v->y, attack_v->z));
        plp->day = NJM_RAD_ANG(atan2f(attack_v->x, attack_v->z));
        *(NJS_POINT3*)&plp->dvx = *attack_v;
        plp->djnt_no = 5;
        *(NJS_POINT3*)&plp->dpx = spr->c;
        
        plp->dam[5] = damage;
        plp->hp -= damage;
        plp->flg |= 4;
        return 1;
    }
    
    return 0;
}

// 100% matching!
static void SetSmoke(NJS_POINT3* pos, float arg1) // second arg not present in DWARF
{
    sys->ef.id = 257;
    sys->ef.flg = 1;
    sys->ef.type = 0;
    
    *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&pos->x;
    
    sys->ef.sz = 0.5f;
    sys->ef.sy = 0.5f;
    sys->ef.sx = 0.5f;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

static UVINFO uvinfo1_1[5] = 
{
    {  0,  0, 24, 24,  3, 20 },
    {  0, 24, 24, 24,  2, 20 },
    {  0, 48, 24, 24,  5, 20 },
    {  0, 24, 24, 24,  3, 20 },
    { -1,  0,  0,  0,  0,  0 }
};
static UVINFO uvinfo1_2[16] = 
{
    {  24,   0,  16,  16,   1,  10 },
    {  40,   0,  24,  24,   2,  10 },
    {  64,   0,  32,  32,   2,  10 },
    {  96,   0,  40,  40,   2,  10 },
    { 136,   0,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 120,  48,  56,  56,   3,  10 },
    { 176,  48,  56,  56,   4,  10 },
    {   0,  88,  56,  56,   5,  10 },
    {  56,  88,  56,  56,   5,  10 },
    { 112, 104,  56,  56,   5,  10 },
    { 168, 104,  56,  56,   5,  10 },
    { 168, 160,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo1_3[23] = 
{
    {  24,   0,  16,  16,   1,  10 },
    {  40,   0,  24,  24,   2,  10 },
    {  64,   0,  32,  32,   2,  10 },
    {  96,   0,  40,  40,   2,  10 },
    { 136,   0,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    {  24,  40,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 120,  48,  56,  56,   3,  10 },
    { 176,  48,  56,  56,   4,  10 },
    {   0,  88,  56,  56,   5,  10 },
    {  56,  88,  56,  56,   5,  10 },
    { 112, 104,  56,  56,   5,  10 },
    { 168, 104,  56,  56,   5,  10 },
    { 168, 160,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo2_1[30] = 
{
    {   0,   0,  16,  16,   1,  10 },
    {  16,   0,  16,  16,   1,  11 },
    {  32,   0,  24,  24,   1,  12 },
    {  56,   0,  24,  24,   1,  13 },
    {  80,   0,  24,  24,   1,  14 },
    {   0,  16,  32,  32,   1,  15 },
    {  80,   0,  24,  24,   1,  16 },
    {  56,   0,  24,  24,   1,  17 },
    {  32,   0,  24,  24,   1,  18 },
    {  56,   0,  24,  24,   1,  19 },
    {  80,   0,  24,  24,   1,  20 },
    {   0,  16,  32,  32,   1,  21 },
    {  80,   0,  24,  24,   1,  22 },
    {  56,   0,  24,  24,   1,  23 },
    {  32,   0,  24,  24,   1,  24 },
    {  56,   0,  24,  24,   1,  25 },
    {  80,   0,  24,  24,   1,  26 },
    {   0,  16,  32,  32,   1,  27 },
    {   0,  48,  32,  32,   1,  28 },
    {   0,  80,  32,  32,   1,  29 },
    {   0, 112,  32,  32,   1,  30 },
    {   0, 144,  32,  32,   1,  31 },
    {  32,  24,  40,  40,   1,  32 },
    {  72,  24,  40,  40,   1,  33 },
    {  32,  64,  40,  40,   1,  34 },
    {  72,  64,  40,  40,   1,  35 },
    {  32, 104,  40,  40,   1,  36 },
    {  72, 104,  40,  40,   1,  37 },
    {  32, 144,  40,  40,   1,  38 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo2_2[16] = 
{
    { 104,   0,  16,  16,   1,  10 },
    { 112,  16,  24,  24,   2,  10 },
    { 136,   0,  32,  32,   2,  10 },
    { 168,   0,  40,  40,   2,  10 },
    { 208,   0,  48,  48,   2,  10 },
    { 112,  40,  48,  48,   2,  10 },
    { 160,  40,  48,  48,   2,  10 },
    { 208,  48,  48,  48,   3,  10 },
    { 112,  88,  56,  56,   3,  10 },
    {  72, 144,  56,  56,   4,  10 },
    { 128, 144,  56,  56,   5,  10 },
    { 184, 144,  56,  56,   5,  10 },
    {   0, 200,  56,  56,   5,  10 },
    {  56, 200,  56,  56,   5,  10 },
    { 112, 200,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static EFF_INFO eff_info[5] = 
{
    { 7, uvinfo2_2 },
    { 6, uvinfo1_2 },
    { 6, uvinfo1_3 },
    { 7, uvinfo2_1 },
    { 6, uvinfo1_1 }
};

// 100% matching!
static void SpecialAttack(BH_PWORK* epw, NJS_VECTOR* splash_v)
{
	int eno;

    if (epw->ct3 == 0)
    {
        sys->ef.flg = 1;
        {
            NJS_POINT3 _p = { 0.0f, 8.0f, 0.0f };
            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, (NJS_POINT3*)&sys->ef.px);
        }

        sys->ef.ay = 0;
        sys->ef.mdlver = 0;
        sys->ef.id = 397;
        sys->ef.type = 4;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            eff[eno].txp[0] = epw->mlwP->texP;
            eff[eno].tex_id = eff_info[sys->ef.type].texid;
            eff[eno].mode3 = 0;
            eff[eno].exp0 = (unsigned char*)epw;            
            *(NJS_POINT3*)&eff[eno].xn = *splash_v;        
        }
    }
}

// 100% matching!
static void _bhEne_SetPoison(BH_PWORK* epw, NJS_VECTOR* ofp, short ry)
{
    int eno;

    sys->ef.id = 397;
    sys->ef.type = 1;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry;
    sys->ef.ax = 0;
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].xn = eff[eno].yn = eff[eno].zn = 0.0f;
    }

    sys->ef.id = 397;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry - NJM_DEG_ANG(90.0f);
    sys->ef.ax = 0;
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].mode3 = 0;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].tv[0].x = 2.0f;
        eff[eno].tv[0].y = -1.0f;
        eff[eno].tv[1].x = 0.0f;
        eff[eno].tv[1].y = -1.0f;
        eff[eno].tv[2].x = 2.0f;
        eff[eno].tv[2].y = 1.0f;
        eff[eno].tv[3].x = 0.0f;
        eff[eno].tv[3].y = 1.0f;
    }

    sys->ef.id = 397;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry - NJM_DEG_ANG(90.0f);
    sys->ef.ax = NJM_DEG_ANG(90.0f);
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].tv[0].x = 2.0f;
        eff[eno].tv[0].y = -1.0f;
        eff[eno].tv[1].x = 0.0f;
        eff[eno].tv[1].y = -1.0f;
        eff[eno].tv[2].x = 2.0f;
        eff[eno].tv[2].y = 1.0f;
        eff[eno].tv[3].x = 0.0f;
        eff[eno].tv[3].y = 1.0f;
    }
}

// 100% matching!
static void _bhEne_SetPoison2(O_WRK* op, int type, NJS_VECTOR* ofp, int param) // fourth parameter not present on DWARF
{
	int eno;

    sys->ef.id = 397;
    sys->ef.type = type;
    sys->ef.flg = 1;

    *(NJS_VECTOR*)&sys->ef.px = *(NJS_VECTOR*)&op->px;

    njAddVector((NJS_VECTOR*)&sys->ef.px, ofp);
       
    sys->ef.sx = sys->ef.sy = 2.0f;
    
    sys->ef.sz = 0.0f;

    if (type == 2)
    {
        sys->ef.ax = NJM_DEG_ANG(90.0f);
        sys->ef.ay = 0;
    }
    else
    {
        sys->ef.ay = 0;
        sys->ef.ax = 0;
    }

    sys->ef.mdlver = 0;

    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = op->txp[0];
        eff[eno].tex_id = eff_info[type].texid;
        eff[eno].exp0 = op->exp0;
        *(NJS_VECTOR*)&eff[eno].xn = *(NJS_VECTOR*)&op->xn;
    }
}

// 100% matching!
void bhEne_SetPoison(BH_PWORK* epw, BT_WORK* bt) 
{
	O_WORK* owk; 
	NJS_POINT3 ofp; 
	NJS_POINT3 ps;
	int fhit;

    // not present in DWARF
    BT_WORK* btp;
    
    fhit = 0;
    if (poison_eff_wait == 0)
    {
        poison_eff_wait = 15;
        owk = &epw->mlwP->owP[epw->djnt_no];
        if ((bt == NULL) || (epw->wpnr_no == 13) || (epw->wpnr_no == 10))
        {
            ps.x = epw->dpx - owk->mtx[12];
            ps.y = epw->dpy - owk->mtx[13];
            ps.z = epw->dpz - owk->mtx[14];
            njSetMatrix(lcmat, &owk->mtx);
            njInvertMatrix(lcmat);
            njCalcVector(lcmat, &ps, &ofp);
        } 
        else 
        {
            if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, owk) == 0)
            {
                fhit = 1;
            }
            
            btp = &bt[epw->djnt_no];

            ofp.x = btp->x + (btp->xlen - (2.0f * btp->xlen * njRandom()));
            ofp.y = btp->y + (btp->ylen - (2.0f * btp->ylen * njRandom()));
            
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
        _bhEne_SetPoison(epw, (NJS_VECTOR*)&ofp, plp->way);
    }
}

// 100% matching!
static void PoisonAttack(O_WRK* op)
{
    NJS_SPHERE col;
    NJS_VECTOR attack_v;

    if (poison_attack_wait != 0)
    {
        return;
    }
        
    if ((op->type == 1) || (op->type == 2))
    {
        return;
    }
        
    col.c = *(NJS_POINT3*)&op->px; 
    col.r = 3.0f;

    attack_v = *(NJS_POINT3*)&plp->px; 

    njSubVector(&attack_v, &col.c);

    if (*(short*)(*(unsigned char**)(op->exp0 + 0x2F0) + 0x5A) & 1)
    {
        return;
    }

    if (bhEne15_AttackPlayerSS(&col, &attack_v, 3) == 0)
    {
        return;
    }
        
    if ((plp->mode0 != 1) && (plp->mode0 != 0))
    {
        plp->hp += 3;
    } 
    else
    {
        if (*(short *)(*(int *)(op->exp0 + 0x2F0) + 0x5C) > 5)
        {
            if (njRandom() < 0.6)
            {
                plp->stflg |= 0x200000;
            }  
        }
        else
        {
            (*(short *)(*(int *)(op->exp0 + 0x2F0) + 0x5C))++;
        }

        plp->flg |= 4;

        if (plp->hp < 0)
        {
            plp->hp = 0;
        }
            
        plp->mode0 = 2;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
    }

    poison_attack_wait = 20;
}

// 100% matching!
static void AddWindForce(O_WRK* op, float reg)
{
    NJS_VECTOR vec1;
	NJS_VECTOR vec2;

    vec1.x = reg * sys->winds * -njSin(sys->windr);
    vec1.y = 0.0f;
    vec1.z = reg * sys->winds * -njCos(sys->windr);
    
    vec2.x = reg * sys->windsb * -njSin(sys->windrb);
    vec2.y = 0.0f;
    vec2.z = reg * sys->windsb * -njCos(sys->windrb);
    
    njSubVector(&vec1, &vec2);
    njAddVector((NJS_VECTOR*)&op->xn, &vec1);
    njAddVector((NJS_VECTOR*)&op->px, (NJS_VECTOR*)&op->xn);
}

// 100% matching!
void bhEff_E15_Poison(O_WRK* op) 
{
    UVINFO* uvp;     
    NJS_POINT3 pos;   

    switch (op->mode0) 
    {
    case 0:
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 3;

        if ((op->type == 1) || (op->type == 0) || (op->type == 2)) 
        {
            op->flg |= 0x80000;
        }
        else
        {
            op->flg |= 0x180000;
        }
        
        op->stflg |= 0x20;

        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct0 = op->ct1 = op->ct2 = 0;

        if (op->type == 4) 
        {
            op->ct3 = 99;
        } 
        else 
        {
            op->ct3 = 0;
        }

        if ((op->type == 1) || (op->type == 2))
        {
            RequestEnemySe(GetLocalEneNo((BH_PWORK*)op->exp0), (NJS_POINT3*)&op->px, 74505);
        }

        op->mode0++;
        
        op->mtn_attr = 0;
    case 1:
        uvp = eff_info[op->type].uvtbl;
        
        PoisonAttack(op);

        switch (op->type) 
        {
        case 4:
            op->yn -= 1.3f;
            
            op->xn *= 0.9f;
            op->yn *= 0.9f;
            op->zn *= 0.9f;
        case 3:
            if (op->type == 3) 
            {
                op->yn -= 0.044f;
            }
            
            op->xn += ((-rand() / -2147483648.0f) - 0.5) / 20.0;
            op->yn += ((-rand() / -2147483648.0f) - 0.5) / 20.0;
            op->zn += ((-rand() / -2147483648.0f) - 0.5) / 20.0;
            
            AddWindForce(op, 0.03f);

            if (op->py < -90.0f) 
            {
                op->flg = 0;
                return;
            }
            
            break;
        }

        switch (op->type) 
        {
        case 1:
            if ((op->mtn_attr != 0) ? ((-rand() / -2147483648.0f) < 0.6) : ((-rand() / -2147483648.0f) < 0.1)) 
            {
                pos.x = 2.0f * (-rand() / -2147483648.0f);
                pos.y = 2.0f * (-rand() / -2147483648.0f);
                pos.z = 2.0f * (-rand() / -2147483648.0f);
                
                op->xn = (0.03f * sys->winds) * -njSin(sys->windr);
                op->yn = 0;
                op->zn = (0.03f * sys->winds) * -njCos(sys->windr);
                
                _bhEne_SetPoison2(op, 3, &pos, 0);
                
                op->mtn_attr++;
                
                if (op->mtn_attr > 10) 
                {
                    op->mtn_attr = 0;
                }
            }
            
            break;
        case 2:
            if ((op->mtn_attr != 0) ? ((-rand() / -2147483648.0f) < 0.6) : ((-rand() / -2147483648.0f) < 0.1)) 
            {
                NJS_POINT3 pos; 
                
                pos.x = 2.0f * (-rand() / -2147483648.0f);
                pos.y = 2.0f * (-rand() / -2147483648.0f);
                pos.z = 2.0f * (-rand() / -2147483648.0f);
                
                op->xn = (0.03f * sys->winds) * -njSin(sys->windr);
                op->yn = 1.2f;
                op->zn = (0.03f * sys->winds) * -njCos(sys->windr);
                
                _bhEne_SetPoison2(op, 3, &pos, 0);
                
                op->mtn_attr++;
                
                if (op->mtn_attr > 10)
                {
                    op->mtn_attr = 0;
                }
            }
            
            break;
        case 4:
            if (bhCollisionCheckLine2((NJS_POINT3*)&op->pxb, (NJS_POINT3*)&op->px, 0x4400, -1) != NULL) 
            {
                NJS_POINT3 pos; 
                
                op->py = 0;
                
                pos.x = pos.z = 0;
                pos.y = 0.01f;
                
                _bhEne_SetPoison2(op, 2, &pos, 0);
                
                op->flg = 0;
                return;
            }
            
            break;
        }

        op->tv[0].u = uvp[op->ct0].u / 256.0f;
        op->tv[0].v = uvp[op->ct0].v / 256.0f;
        
        op->tv[1].u = ((uvp[op->ct0].u + uvp[op->ct0].sx) - 1) / 256.0f;
        op->tv[1].v = op->tv[0].v;
        
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = ((uvp[op->ct0].v + uvp[op->ct0].sy) - 1) / 256.0f;
        
        op->tv[3].u = op->tv[1].u;
        op->tv[3].v = op->tv[2].v;

        op->sx = op->sy = op->sz = uvp[op->ct0].scale / 10.0f;

        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            sys->ef_trsn++;
        }

        op->ct2++;

        if (op->ct1 < uvp[op->ct0].frm) 
        {
            op->ct1++;
        }
        else
        {
            op->ct0++;
            
            op->ct1 = 0;
        }

        if (uvp[op->ct0].u == -1)
        {
            if (op->ct3 != 0) 
            {
                op->ct0 = op->ct1 = 0;
                
                op->ct3--;
                break;
            }
            
            op->ct0   = 0;
            op->mode0 = 2;
        }
        
        return;
    case 2:
        if (op->ct0 < 15) 
        {
            op->ct0++;
        } 
        else 
        {
            op->flg = 0;
            break;
        }

        op->tv[0].col = ((0xFF - (op->ct0 * 17)) << 24) | 0xFFFFFF;
        op->tv[1].col = ((0xFF - (op->ct0 * 17)) << 24) | 0xFFFFFF;
        op->tv[2].col = ((0xFF - (op->ct0 * 17)) << 24) | 0xFFFFFF;
        op->tv[3].col = ((0xFF - (op->ct0 * 17)) << 24) | 0xFFFFFF;
        break;
    case 4:
        break;
    }
}

// 99.06% matching
void bhEne15_RotChar(BH_PWORK* pw, int goal, int add_ang)
{
    int rot;

    if (!(pw->flg & 0x80))
    {
        if (add_ang & 0x80000000)
        {
            add_ang = -add_ang;
            goal = (unsigned short)(goal + NJM_DEG_ANG(180.0f));
        }
        
        rot = (unsigned short)(add_ang + (goal - pw->ay));
        
        if (rot < (add_ang + add_ang)) 
        {
            pw->ay = goal;
            return;
        }
        
        pw->ay = pw->ay - add_ang;
        if (rot <= NJM_DEG_ANG(180.0f))
        {
            pw->ay += (add_ang + add_ang);
        }
    }
}

// 100% matching!
static int AbleToFall(BH_PWORK* pp)
{
    O_WORK* owk;

    owk = &pp->mlwP->owP[1];

    if (((owk->mtx[12] <= rom->posp[1].px) || (owk->mtx[12] >= rom->posp[4].px))
      || (owk->mtx[14] <= rom->posp[2].pz) || (owk->mtx[14] >= rom->posp[3].pz))
        return 1;

    return 0;
}

// 100% matching! 
static int _DrivePlayer(BH_PWORK* epw) // signature different from DWARF
{
    int ans;
    float ofs;
    float FP0;
    float FP1;
    float FP;

    ans = 0;

    ofs = plp->mlwP->owP[1].mtx[13] - plp->py;
    njAddVector((NJS_VECTOR*)&plp->px, (NJS_VECTOR*)&plp->dvx);

    if (plp->py + ofs < 0.0f)
    {
        ans = 3;
        if (AbleToFall(plp) != 0)
        {
            ans = 2;
        } 
        else 
        {
            FP0 = njSqrt(powf(plp->pxb, 2.0f) + powf(plp->pzb, 2.0f));
            FP1 = njSqrt(powf(plp->px, 2.0f) + powf(plp->pz, 2.0f));
            FP = FP0 + FP1;

            plp->py = -1.0f * (plp->py + ofs) - ofs;
            plp->dvy -= 1.3f * (FP0 / FP);
            plp->dvy *= -0.15f;
            plp->dvy -= 1.3f * (FP1 / FP);
        }

        if (fabsf(plp->dvy) < 0.3f)
        {
            plp->py = 0.0f;
            plp->dvy = 0.0f;
            plp->spd = njScalor((NJS_VECTOR*)&plp->dvx);
            if ((plp->mtn_no == 15) || (plp->mtn_no == 19) || (plp->mtn_no == 20) || (plp->mtn_no == 21) || (plp->mtn_no == 22))
            {
                plp->spd *= -1.0f;
            }
            ans = 1;
        }
    } 
    else
    {
        plp->dvy -= 1.3f;
    }

    plp->dvx *= 0.9f;
    plp->dvy *= 0.9f;
    plp->dvz *= 0.9f;
    
    return ans;
}

// 100% matching!
static void DrivePlayer(BH_PWORK* epw)
{
    int _mtnno;

    bhEne15_RotChar(plp, plp->day, NJM_DEG_ANG(90.0f));

    switch (_DrivePlayer(epw))
    {
    case 2:
        if ((plp->mtn_no == 19) || (plp->mtn_no == 21))
        {
            EXP0_S(0x5A) |= 1;
            epw->mode3 = 3;
            plp->spd = 0.0f;
            break;
        }
        
        switch (plp->mtn_no)
        {
        case 15:
            _mtnno = 26;
            break;
        case 14:
            _mtnno = 25;
            break;
        case 22:
            _mtnno = 26;
            break;
        case 20:
            _mtnno = 25;
            break;
        }
        
        plp->mnwP = epw->mnwP;
        EXP0_S(0x5A) |= 1;
        epw->mode3 = 3;
        plp->spd = plp->spd;
        SetPlyMtn(_mtnno);
        plp->mode0 = 5;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        plp->flg |= 0x10004;
        plp->flg &= ~0x40000;
        plp->stflg |= 0x50000;
        break;
        
    case 3:
        if ((plp->mtn_no == 19) || (plp->mtn_no == 21))
        {
            SetPlyMtn(plp->mtn_no == 19 ? 22 : 20);
        }
        
        SetSmoke((NJS_VECTOR*)&plp->px, 2.0f);
        
        if (plp->mode3 == 0)
        {
            CallPlayerVoice(519);
            StartVibrationEx(1, 11);
            plp->mode3++;
        }
        break;
        
    case 1:
        if ((plp->mtn_no == 19) || (plp->mtn_no == 21))
        {
            SetPlyMtn(plp->mtn_no == 19 ? 22 : 20);
            plp->hp -= 80;
        }
        
        if (plp->mode3 == 0)
        {
            CallPlayerVoice(519);
            StartVibrationEx(1, 11);
            plp->mode3++;
        }
        
        EXP0_S(0x5A) |= 1;
        epw->mode3 = 1;
        plp->spd = plp->spd;
        break;
    }

    if ((plp->frm_no / 65536) == plp->mnwP[plp->mtn_no].frm_num - 1) 
    {
        plp->mtn_add = 0;
    }
}

// 100% matching!
static void FallingPlayer(BH_PWORK* epw)
{
    bhEne15_RotChar(plp, plp->day, NJM_DEG_ANG(90.0f));
    njAddVector((NJS_VECTOR*)&plp->px, (NJS_VECTOR*)&plp->dvx);
    plp->dvy -= 1.3f;
    plp->dvx *= 0.9f;
    plp->dvy *= 0.9f;
    plp->dvz *= 0.9f;
    
    if (plp->py < -90.0f)
    {
        plp->hp = -1;
        plp->mnwP = epw->mnwP;
        EXP0_S(0x5A) |= 1;
        epw->mode3 = 4;
        plp->spd = plp->spd;
        SetPlyMtn(plp->mtn_no);
        plp->mode0 = 6;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        plp->flg |= 0x10004;
        plp->flg &= ~0x40000;
        plp->stflg |= 0x50000;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        plp->mtn_add = 0;
    }
}

// 98.28% matching
static void SlidePlayer(BH_PWORK* epw)
{
    int _mtnno;
    NJS_POINT3 delta;

    if (AbleToFall(plp) != 0)
    {
        switch (plp->mtn_no)
        {
        case 15:
            _mtnno = 26;
            break;
        case 14:
            _mtnno = 25;
            break;
        case 22:
            _mtnno = 26;
            break;
        case 20:
            _mtnno = 25;
            break;
        }
        
        plp->mnwP = epw->mnwP;
        
        EXP0_S(90) |= 0x1;
        
        epw->mode3 = 3;
        
        plp->spd = plp->spd;
        
        SetPlyMtn(_mtnno);
        
        plp->mode0 = 5;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        
        plp->flg |=  0x10004;
        plp->flg &= ~0x40000;
        
        plp->stflg |= 0x50000;
        return;
    }

    bhEne15_RotChar(plp, plp->day, NJM_DEG_ANG(90.0f));
    
    bhAddSpeed(plp, 0);

    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        plp->mtn_add = 0;
    }

    if ((plp->spd < 0.8f) && (njRandom() < 0.6)) 
    {
        SetSmoke((NJS_POINT3*)&plp->px, 2.0f);
    }

    plp->spd *= 0.94f;
    
    delta = *(NJS_POINT3*)&plp->px;
    
    njSubVector(&delta, (NJS_VECTOR*)&plp->pxb);

    if (njScalor(&delta) < 0.33f)
    {
        int _mtnno;
        
        plp->spd = 0;
        
        plp->flg |= 0x100;

        if (plp->hp < 0)
        {
            switch (plp->mtn_no)
            {
            case 15:
            case 22:
                _mtnno = 27;
                break;
            case 14:
            case 20:
                _mtnno = 28;
                break;
            }
            
            plp->mnwP = epw->mnwP;
            
            EXP0_S(90) |= 0x1;
            
            epw->mode3 = 7;
            
            plp->spd = 0;
            
            SetPlyMtn(_mtnno);
            
            plp->mode0 = 6;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            
            plp->flg |=  0x10004;
            plp->flg &= ~0x40000;
            
            plp->stflg |= 0x50000;
        } 
        else 
        {
            switch (plp->mtn_no)
            {
            case 15:
                _mtnno = 17;
                break;
            case 14:
                _mtnno = 16;
                break;
            case 22:
                _mtnno = 23;
                break;
            case 20:
                _mtnno = 24;
                break;
            }
            
            EXP0_S(90) |= 0x1;
            
            epw->mode3 = 2;
            
            plp->spd = 0;
            
            SetPlyMtn(_mtnno);
        }
    }

    if (njScalor(&delta) < 0.8f)
    {
        plp->flg |= 0x10;
    }
}

// 100% matching!
static void StandupPlayer(BH_PWORK* epw)
{
    if ((plp->mtn_no == 17) || (plp->mtn_no == 16))
    {
        plp->flg |= 0xC0000;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        if (plp->mtn_no == 22)
        {
            SetPlyMtn(23);
        }
        else if (plp->mtn_no == 20)
        {
            SetPlyMtn(24);
        } 
        else
        {
            plp->mnwP = plp->mnwPb;
            plp->mode0 = 1;
            plp->mode3 = 0;
            plp->mode2 = 0;
            plp->mode1 = 0;
            plp->flg &= ~0x310004;
            plp->flg |= 0x118;
            plp->stflg &= ~0x50480;
            plp->spd = 0.0f;
            EXP0_S(0x5A) &= ~1;
        }
    }
}

// 100% matching!
static void HoldPlayer(BH_PWORK* epw)
{	
    NJS_VECTOR _v;

    if (plp->mtn_no == 19)
    {
        ikou(plp, (NJS_POINT3*)&epw->px, 8192);
    } 
    else
    {        
        _v = *(NJS_VECTOR*)&plp->px;

        njSubVector(&_v, (NJS_VECTOR*)&epw->px);
        njAddVector(&_v, (NJS_VECTOR*)&plp->px);
        
        ikou(plp, &_v, 8192);
    }
    
    {
        NJS_VECTOR _v;
        NJS_POINT3 pos; 
	    O_WORK* owk;
        
        _v.x = -njSin(epw->ay);
        _v.y = 0;
        _v.z = -njCos(epw->ay);
        
        njUnitVector(&_v);
        
        _v.x *= 2.0f;
        _v.z *= 2.0f;
        
        owk = epw->mlwP->owP;
        pos.x = owk[1].mtx[12];
        pos.y = 0.0f;
        pos.z = owk[1].mtx[14];
        
        njAddVector(&_v, &pos);
        VacumeToPoint(plp, &_v);
    }
}

// 100% matching!
static void FlyingPlayer(BH_PWORK* epw)
{
	NJS_POINT3 pos1;
    NJS_POINT3 pos2;
	NJS_POINT3 pos3;    	    
	O_WORK* owk;
    NJS_POINT3 _p = { 0.0f, 8.0f, 0.0f };

    njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &pos1);
    
    owk = plp->mlwP->owP;
    pos2.x = owk[1].mtx[12];
    pos2.y = owk[1].mtx[13];
    pos2.z = owk[1].mtx[14];
    
    pos3 = *(NJS_POINT3*)&plp->px;
    
    njSubVector(&pos3, &pos2);
    njAddVector(&pos1, &pos3);
    
    *(NJS_POINT3*)&plp->px = pos1;
}

// 100% matching!
static void FallDiePlayer(BH_PWORK* epw)
{
    switch (plp->mode1)
    {
    case 0:
        plp->mnwP = plp->mnwPb;
        plp->flg &= ~0x310004;
        plp->flg &= ~0x118;
        plp->stflg &= ~0x10480;
        plp->stflg |= 8;
        plp->spd = 0.0f;
        plp->mode1++;
        break;
        
    case 1:
        CallPlayerVoice(1025);
        StartVibrationEx(1, 11);
        plp->mode1++;
        break;
        
    case 2:
        EXP0_S(0x5A) &= ~1;
        plp->flg |= 2;
        sys->ts_flg |= 0x4000;
        break;
        
    }
}

// 100% matching!
static void DiePlayer(BH_PWORK* epw)
{
    if (plp->mode1 == 0)
    {
        CallPlayerVoice(1025);
        plp->mode1++;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        EXP0_S(0x5A) &= ~1;
        plp->flg |= 2;
        plp->mtn_add = 0;
        sys->ts_flg |= 0x4000;
    }
}

// 100% matching!
static void ChangeAmbient(short* plist, unsigned char add)
{
    while (*plist != 0xFF)
    {
        switch (*(unsigned char *)plist)
        {
        case 18:
            *((unsigned char *)plist + 5) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 19:
            *((unsigned char *)plist + 9) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 22:
            *((unsigned char *)plist + 5) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 23:
            *((unsigned char *)plist + 9) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:            
        case 5:
            plist++;
            break;
            
        case 8:
        case 9:
            plist += 2;
            break;
            
        default:
            plist++;
            plist += *plist;
            plist++;
            break;
            
        }
    }
}

// 99.93% matching
static void SetMince(BH_PWORK* epw, int type, int num)
{
    int i;
	int eno;

    sys->ef.id = 250;
    sys->ef.flg = 1;
    sys->ef.type = type;
    
    *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&epw->dpx;
    
    sys->ef.sx = sys->ef.sy = 0.1f + (0.3f * njRandom());
    sys->ef.sz = 0.0f;
    sys->ef.mdlver = 0;
    
    for (i = 0; i < num; i++)
    {
        sys->ef.ay = ((bhArcTan2(epw->dvx, epw->dvz) + (21845.0f * njRandom())) - 10922.0f);
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            eff[eno].txp[0] = epw->txp[0];
            eff[eno].tex_id = 1;
            *(NJS_POINT3*)&eff[eno].xn = *(NJS_POINT3*)&epw->dvx;
        }
    }
}

// 100% matching!
static void CoreInit(BH_PWORK* epw) 
{
    epw->flg &= ~0x178;
    epw->flg &= ~6;
    epw->mdflg |= 4;
    epw->aoz = 0.0f;
    epw->aoy = 0.0f;
    epw->aox = 0.0f;
    epw->loz = 0.0f;
    epw->loy = 0.0f;
    epw->lox = 0.0f;
    epw->mdflg |= 2;
    epw->shp_ct = 0.0f;
    epw->mtn_md = 0;
    epw->mtn_no = 0;
    epw->mtn_tp = NULL;
    epw->mtn_add = 0;
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 0;
    ChangeAmbient(epw->mbp[0]->child->model->plist, 178);
    ChangeAmbient(epw->mbp[1]->child->model->plist, 178);
    ChangeAmbient(epw->mbp[2]->child->model->plist, 178);
    epw->mlwP->objP = epw->mbp[0];
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];
    epw->shp_ct = 0.0f;
    epw->mode0++;
    epw->mode1 = 0;
}

// 100% matching!
static void CoreMove(BH_PWORK* epw)
{
    if (!(epw->mdflg & 1) && (epw->mdflg & 2))
    {
        switch (epw->mode1)
        {
        case 0:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 1;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[2];
                epw->ct0 = 0;
                break;
            }
            epw->shp_ct += 400.0f;
            break;
            
        case 1:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 2;
                epw->ct0 = 0;
                break;
            }
            epw->shp_ct += 166.67f;
            break;
            
        case 2:
            if (epw->ct0++ == 3) {
                epw->mode1 = 3;
                epw->obj_a = epw->mbp[2];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                break;
            }
            break;
            
        case 3:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 4;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[0];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += 166.67f;
            break;
            
        case 4:
            if (1000.0f < epw->shp_ct) 
            {
                epw->mode1 = 0;
                epw->obj_a = epw->mbp[0];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += 150.0f;
            break;
            
        }
    }
}

// 100% matching!
static void CoreDie(BH_PWORK* epw)
{
    int i;

    switch (epw->mode2)
    {
    case 1:
        if (epw->mode3 == 0) 
        {
            epw->ct1 = 0;
            epw->mode3++;
        }

        switch (epw->mode1)
        { 
        case 0:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 1;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[2];
                break;
            }
            epw->shp_ct += (400.0f / (epw->ct1 + 2));
            break;
            
        case 1:
            if (1000.0f < epw->shp_ct)
            {
                epw->ct0 = 0;
                epw->ct1++;

                if (epw->ct1 < 5)
                {
                    epw->mode1 = 2;
                    break;
                }
                
                epw->mode1 = 5;

                break;
            }
            epw->shp_ct += (166.67f / (epw->ct1 + 2));
            break;
            
        case 2:
            if (epw->ct0++ == 3)
            {
                epw->mode1 = 3;
                epw->obj_a = epw->mbp[2];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
            }
            break;
            
        case 3:
            if (1000.f < epw->shp_ct)
            {
                epw->mode1 = 4;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[0];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += (166.67f / (epw->ct1 + 2));
            break;
            
        case 4:
            if (1000.f < epw->shp_ct)
            {
                epw->obj_a = epw->mbp[0];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                epw->mode1 = 0;
                break;
            }
            epw->shp_ct += (150.0f / (epw->ct1 + 2));
            break;
        }
        break;
    case 2:
        if (!(epw->mdflg & 1))
        {
            if (epw->mode3 == 0)
            {
                epw->ct2 = 178;
                if (epw->mode1 < 5)
                {
                    epw->mode1 = 0;
                }
                epw->mode3++;
            }
            ChangeAmbient(epw->obj_a->child->model->plist, epw->ct2);
            ChangeAmbient(epw->obj_b->child->model->plist, epw->ct2);

            if (0 < epw->ct2 - 4)
            {
                epw->ct2 -= 4;
            }
            else
            {
                epw->ct2 = 0;
            }

            switch (epw->mode1)
            {
            case 0:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 1;
                    epw->obj_a = epw->mbp[1];
                    epw->obj_b = epw->mbp[2];
                    epw->ct0 = 0;
                    break;
                }
                epw->shp_ct += 400.0f;
                break;
                
            case 1:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 2;
                    epw->ct0 = 0;
                    break;
                }
                epw->shp_ct += 166.67f;
                break;
                
            case 2:
                if (epw->ct2 == 0)
                {
                    epw->mode1 = 5;
                }
                break;
                
            case 3:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 4;
                    epw->obj_a = epw->mbp[1];
                    epw->obj_b = epw->mbp[0];
                    epw->shp_ct = 0.0f;
                    break;
                }
                epw->shp_ct += 166.67f;
                break;
                
            case 4:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 0;
                    epw->obj_a = epw->mbp[0];
                    epw->obj_b = epw->mbp[1];
                    epw->shp_ct = 0.0f;
                    break;
                }
                epw->shp_ct += 150.0f;
                break;
                
            case 5:
                epw->mdflg |= 1;
                epw->id = 15;
                epw->djnt_no = 1;
                *(NJS_POINT3*)&epw->dpx = *(NJS_POINT3*)&epw->mlwP->owP[epw->djnt_no].mtx[12];
                epw->dvx = 2.0f * njSin(epw->ay);
                epw->dvz = 2.0f * njCos(epw->ay);
                epw->dvy = 0.0f;
                SetMince(epw, 2, 32);
                bhEne_SetBloodEffect5(epw, 2, 2);
                for (i = 0; i < 5; i++)
                {
                    epw->dpx += (njRandom() - 0.5) * 5.0f;
                    epw->dpy += (njRandom() - 0.5) * 5.0f;
                    epw->dpz += (njRandom() - 0.5) * 5.0f;
                    bhEne_SetBloodEffect5(epw, 0, 2);
                }
                epw->id = 53;
                RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->px, 2147484170);
                epw->mode1 = 6;
                break;
            }
        }
        break;
    }
}

// 100% matching!
void bhEne53(BH_PWORK* epw)
{
    switch (epw->mode0)
    {
    case 0:
        CoreInit(epw);

    case 1:
        CoreMove(epw);
        break;
		
    case 3:
        CoreDie(epw);
        break;

    case 5:
        bhEne_Event(epw);
        break;
    }
}
