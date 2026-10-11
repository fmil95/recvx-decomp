#include "../../../ps2/veronica/prog/en19.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

// ENEMY: Tyrant T-078 

#pragma divbyzerocheck on

static void (*bhEne19_Mode0[6])(BH_PWORK*) = 
{ 
	bhEne19_Init,
	bhEne19_Move,
	bhEne19_Damage,
	bhEne19_Die,
	NULL,
	bhEne19_Event
};
static void (*bhEne19_BrainType[3])(BH_PWORK*) = 
{ 
	bhEne19_Br00,
	bhEne19_Br01,
	bhEne19_Br02
};
static TY_DMG_MODE(*bhEne19_CheckDmgLvl[3])(BH_PWORK*, FW_WORK*) = 
{ 
	bhEne19_CheckDmgLvl0,
	bhEne19_CheckDmgLvl1,
	bhEne19_CheckDmgLvl2
};

EA_WORK En19ActTbl[50] =
{
    {  1033,  8,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv08  },
    {  1034,  9,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv09  },
    {  2056,  7,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv07  },
    {  2308,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2309,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2310,  5, 56, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2564,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2565,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2566,  5, 22, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2816,  0,  0, 0, 32,  1.0f, 0x00080020, bhEne19_Mv00  },
    {  2827, 10,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv10  },
    {  2832, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    {  3589,  4, 40, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3599, 14,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv14  },
    {  3845,  4,  4, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3854, 13,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv13  },
    {  4100,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4101,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4102,  5, 26, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  4356,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4357,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4358,  5, 58, 0, 10,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  5124,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  5125,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65024,  0,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv00  },
    { 65028,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04a },
    { 65029,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65030,  5,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65280,  0,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv00  },
    { 65281,  1,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv01  },
    { 65282,  2,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv02  },
    { 65283,  3,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv03  },
    { 65284,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    { 65285,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65286,  5,  0, 0, 12,  1.0f, 0x00080020, bhEne19_Mv05  },
    { 65287,  6,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv06  },
    { 65288,  7,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv07  },
    { 65289,  8,  0, 0,  8, 0.95f, 0x00080020, bhEne19_Mv08  },
    { 65290,  9,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv09  },
    { 65291, 10,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv10  },
    { 65292, 11,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv11  },
    { 65293, 12,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv12  },
    { 65294, 13,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv13  },
    { 65295, 14,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv14  },
    { 65296, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    { 65297, 16,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv16  },
    { 65298, 17,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv17  },
    { 65299, 18,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv18  },
    { 65300, 19,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv19  },
    { 65301, 20,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv20  }
};
COMBWEP_WORK En19CombWepTbl[21] =
{
    {   0, {  0,  0,  0 },   0,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  90, { 10,  0,  0 }, 999, 100 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 190, {  8,  6,  4 }, 300,   0 },
    { 500, { 10, 10, 10 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 300, {  8,  6,  2 }, 400, 200 },
    {  56, { 10,  8,  4 },  80,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    {  10, { 10, 10, 10 },  60,   0 },
    {  60, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  40, { 10, 10, 10 },  60,   0 },
    {   0, {  0,  0,  0 },   0,   0 }
};

static const char FlpTbl[26] =
{
    0, 1, 2, 3, 4, 5, 14, 15, 16, 17, 10, 11, 12, 13, 6, 7, 8, 9, 22, 23, 24, 25, 18, 19, 20, 21
};
static const CPCL Ene19CapColTbl[28] =
{
    {   1,  1, 20 },
    {   0, -8,  0 },
    {   1,  2, 10 },
    {   2,  3, 16 },
    {   3,  3, 12 },
    {   0, 15,  0 },
    {  14, 14, 20 },
    {  -6, 18,  8 },
    {   6,  6, 20 },
    {   6, 18,  8 },
    {   4,  5,  9 },
    {   5,  5, 12 },
    {   0,  9,  0 },
    {   7,  8,  9 },
    {   8,  9,  9 },
    {   9,  9, 15 },
    {  14,  0,  0 },
    {  15, 16,  9 },
    {  16, 17,  9 },
    {  17, 17, 15 },
    { -14,  0,  0 },
    {  18, 19, 10 },
    {  19, 20,  8 },
    {  20, 21,  8 },
    {  22, 23, 10 },
    {  23, 24,  8 },
    {  24, 25,  8 },
    {   0,  0,  0 }
};
static const ACT_TBL_WORK En19PlyActTbl[17] = 
{
    { 35, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 30, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg042     },
    { 31, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg043     },
    { 32, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg044     },
    { 33, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg045     },
    { 34, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 35, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 36, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 37, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 38, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 39, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 40, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 41, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 42, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 43, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 44, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 45, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     }
};
static const float En19OvlTbl[3] = 
{
    2.5f, 1.5f, 1.5f    
};
static const int En19HpTbl[4][3] = 
{
    { 500, 700, 900 },
    { 500, 700, 900 },
    { 300, 420, 540 },
    { 900, 900, 900 }
};
static const float En19AtkRng[3][4] = 
{
    { 13.0f, 11.0f, 15.0f, 13.0f },  
    { 11.0f, 15.0f, 13.0f, 17.0f },  
    { 12.0f, 13.0f, 14.0f, 15.0f }   
};
static const PMA_WORK Eff30aPrm1[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 728, 2.0f, 0.98f, 1456, 4.0f, 0.99f       
    },
    {
        2, 0, 1456, 4.0f, 0.99f, 728, 2.0f, 0.98f      
    }
};
static const PMA_WORK Eff30aPrm2[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 8192, 1.0f, 0.9f, 8192, 2.0f, 0.94f      
    },
    {
        2, 0, 8192, 2.0f, 0.94f, 8192, 1.0f, 0.9f      
    }
};

static COMBJOINT_WORK En19CombJointTbl[26] = { 0 };
static PMA_WORK* Eff30aTbl[3] = 
{ 
	Eff30aPrm2,
	Eff30aPrm1,
	Eff30aPrm2
};

// 100% matching!
void bhEne19(BH_PWORK* ewP)
{
    FW_WORK* fwP;   
    int sts;        
    R49_WORK* r49P; 
    EB_WORK* ebP;   
    ML_WORK* mlwP;  

    if (ewP->mode0 != 0)
    {
        fwP = (FW_WORK*)ewP->exp0;
        
        sts = fwP->status;

        if ((ewP->exp2 == NULL) && (!(sys->gm_flg & 0x1)))
        {
            ewP->exp2 = (unsigned char*)-1;

            if ((sts & 0x20000000))
            {
                fwP->cam_clrP = (R0A_WORK*)bhSetRapEff(310, fwP->e0aP, 8)->free4;
            }

            if ((sts & 0x10000000))
            {
                r49P = (R49_WORK*)bhSetRapEff(349, NULL, 0)->free4;
                
                r49P->fnc_prcP = (void*)bhEne19_TyBloodSet;
                
                ebP = (EB_WORK*)r49P->free;
                
                ebP->ewP = ewP;
                ebP->fwP = fwP;
                
                ebP->time = 0;
            }

            if ((sts & 0x80000000))
            {
                mlwP = ewP->mlwP;
                
                fwP->clw0P = bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW0);
                
                bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW1);
                
                fwP->clw2P = bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW2);
            }
        }
    }

    bhEne19_Mode0[ewP->mode0](ewP);

    if (ewP->mode0)
    {
        ((FW_WORK*)ewP->exp0)->mode0_bak = ewP->mode0;
    }
}

// 100% matching!
static void bhEne19_Init(BH_PWORK* ewP)
{
    FW_WORK* fwP;           
    float* rngP;            
    NJS_CNK_OBJECT* objP;  
    NJS_POINT3* posP;      

    if (ewP->exp0 == NULL) 
    {
        ewP->exp0 = bhEne_CallocWork(sizeof(FW_WORK), 32);
    } 
    else
    {
        npSetMemory(ewP->exp0, sizeof(FW_WORK), 0);
    }
    
    fwP = (FW_WORK*)ewP->exp0;

    ewP->mode0 = 1;
    ewP->mode1 = 0;
    ewP->mode2 = 0;
    ewP->mode3 = 0;
    
    ewP->exp2 = NULL;

    ewP->ar = 5.0f;
    ewP->ah = 4.0f;
    ewP->aw = 0;
    ewP->ad = 0;
    
    ewP->car = 6.5f;
    ewP->cah = 4.0f;

    ewP->hp = fwP->hp_bak = En19HpTbl[sys->gm_mode][ewP->type];

    ewP->cpcl = Ene19CapColTbl;

    fwP->ovl_rte = En19OvlTbl[ewP->type];

    ewP->mtn_no = 0;
    ewP->frm_no = 0;
    
    ewP->hokan_count = 0;
    ewP->hokan_rate  = 0;
    
    ewP->mtn_add = 0;
    ewP->mtn_md  = 0;
    ewP->mtn_tp  = (unsigned char*)FlpTbl;

    ewP->flg  |=  0x178;
    ewP->flg  &= ~0x2;
    
    ewP->flg2 |= 0x1;
    
    ewP->stflg |= 0x4000;

    ewP->clp_jno[0] = 5;
    ewP->clp_jno[1] = 17;
    ewP->clp_jno[2] = 9;
    ewP->clp_jno[3] = 1;
    ewP->clp_jno[4] = 25;
    ewP->clp_jno[5] = 21;
    ewP->clp_jno[6] = -1;

    ewP->mdflg &= ~0x20;
    
    ewP->lok_jno = 4;

    fwP->ewP = ewP;
    
    fwP->watr_top = 4;
    fwP->watr_rad = 3.0f;
    
    fwP->ct_pinch = 3600;
    
    fwP->e0aP = Eff30aTbl[ewP->type];

    rngP = En19AtkRng[ewP->type];
    
    fwP->atk_rng_a_near = *rngP++;
    fwP->atk_rng_b_near = *rngP++;
	
    fwP->atk_rng_a_far  = *rngP++;
    fwP->atk_rng_b_far  = *rngP++;

    if (!(ewP->flg & 0x800)) 
    {
        ewP->flg |= 0x800;
        
        rySetShadow(ewP, 24, 20, 2, 2.0f, 3.0f);
    }

    posP = fwP->ClwPos;
    objP = &ewP->mlwP->objP[10];
    
	*posP++ = *(NJS_POINT3*)&(  objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;

    if (ewP->type == 0) 
    {
        NJS_CNK_OBJECT* objP; 
        O_WORK* owP;         
        
        owP  = ewP->mlwP->owP;
        objP = ewP->mlwP->objP;

        objP[10].pos[0] = -1.0f; 
        objP[10].pos[1] = objP[10].pos[2] = 0;
        
        objP[11].pos[0] = -1.0f; 
        objP[11].pos[1] = objP[11].pos[2] = 0;
        
        objP[12].pos[0] = -1.0f; 
        objP[12].pos[1] = objP[12].pos[2] = 0;
        
        objP[13].pos[0] = 3.0f; 
        objP[13].pos[1] = objP[13].pos[2] = 0;

        owP[10].flg |= 0x2;
        owP[11].flg |= 0x2;
        owP[12].flg |= 0x2;
        owP[13].flg |= 0x2;

        ewP->ay &= ~0xFF;
    }

    sys->rm_flg &= ~0x1F;

    bhEne19_ActionChange(ewP, fwP, 0);
    
    bhEne_PlyActionInit(ewP, &fwP->ply_act, En19PlyActTbl, 17);

    if (ewP->type == 1) 
    {
        fwP->status |= 0x70000000;
    } 
    else if (ewP->type == 2) 
    {
        fwP->status |= 0xE0000000;
    }
}

// 100% matching!
static void bhEne19_Move(BH_PWORK* ewP) 
{
    FW_WORK* fwP;        
    int* stsP;           
    NJS_CNK_OBJECT* objP; 
    NJS_POINT3 pos;       
    NJS_MATRIX* mtxP;   
    float ah_bak, ar_bak;         

    fwP = (FW_WORK*)ewP->exp0;

    stsP = &fwP->status;

    bhEne19_DmgCheck(ewP, fwP);

    bhEne19_BrainType[ewP->type](ewP);

    bhEne19_ActionMain(ewP, fwP);

    if ((*stsP & 0x20))
    {
        objP = ewP->mlwP->objP;
        
        objP->ang[0] = objP->ang[1] = objP->ang[2] = 0;
        
        objP->pos[0] *= 0.25f;
        objP->pos[2] *= 0.25f;
        
        *stsP &= ~0x20;
    }

    if ((*stsP & 0x8000))
    {
        bhEne19_PositonFix(ewP, fwP);
    }

    bhEne19_SoundSet(ewP, fwP);

    bhEne19_HeadTurn(ewP, fwP, *stsP & 0x4);

    if (ewP->type != 0)
    {
        bhCheckPlayer(ewP);
    }

    bhCheckEnemies(ewP);

    if ((ewP->flg & 0x10))
    {
        bhCheckWall(ewP);
    }

    if ((ewP->flg & 0x40))
    {
        mtxP = &ewP->mlwP->owP->mtx;
        
        pos = *(NJS_POINT3*)&plp->px;

        if (bhEne19_CollisionCircle2Oval(mtxP, ewP->car * fwP->ovl_rte, ewP->car, &pos, plp->car) != 0)
        {
            plp->px = pos.x;
            plp->pz = pos.z;

            ah_bak = plp->ah;
            ar_bak = plp->ar;

            plp->ah = 1.0f;
            
            bhCheckWall(plp);
            
            plp->ah = ah_bak;
            plp->ar = ar_bak;

            PEXP0_F(72) = plp->px;
            PEXP0_F(80) = plp->pz;
        }
    }

    bhEne19_CalcEnemy(ewP, fwP);
    
    bhEne19_PlyMoveMain(plp, fwP);
}

// 100% matching!
static void bhEne19_Damage()
{

}

// 100% matching!
static void bhEne19_Die(BH_PWORK* ewP) 
{
    ewP->flg |= 0x2; 

    ewP->mtn_add = 0; 
}

// 100% matching!
static void bhEne19_Event(BH_PWORK* ewP)
{
    ((FW_WORK*)ewP->exp0)->status &= ~0x4;

    ewP->mlwP->owP[4].flg &= ~0x2;
    ewP->mlwP->owP[5].flg &= ~0x2;

    bhEne_Event(ewP);

    bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);

    bhEne19_CalcEnemy(ewP, (FW_WORK*)ewP->exp0);
}

// 100% matching!
static void bhEne19_Br00(BH_PWORK* ewP)
{
    FW_WORK* fwP;     
    int* stsP, *pstP;         
    int sts;           
    TY_BR_MODE0* br0P; 
    TY_BR_MODE1* br1P; 
    TY_BR_MODE2* br2P; 
    int* wt1P;         
    int rte;           
    int act;          
    int lop;          

    pdGetPeripheral(0);
    
    stsP = &((FW_WORK*)ewP->exp0)->status;
    pstP = &((FW_WORK*)ewP->exp0)->ply_act.p_status;

    fwP = (FW_WORK*)ewP->exp0;

    if (!(*stsP & 0x400)) 
    {
        fwP->tgt_pos = *(NJS_POINT3*)&plp->px;
        
        *stsP |= 0x1;
    }

    bhEne19_TargetAnalyze(ewP, fwP);

    if ((fwP->dmg_dly >= 3) && (fwP->br_mde1 != TY_BR1_DAMAGE)) 
    {
        fwP->dmg_lvl = fwP->dmg_dly;
        fwP->dmg_dly = 0;
        
        fwP->br_mde1 = TY_BR1_DAMAGE;
        fwP->br_mde2 = TY_BR2_FIRST;
    }

    sts = *stsP;
    
    rte = fwP->mtn_rte;

    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;
    br2P = &fwP->br_mde2;
    
    wt1P = &fwP->br_wait1;

    act = -1;
    
    lop = 0;

    do 
    {
        switch (*br0P) 
        {
        case TY_BR0_NORMAL:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0)
                {
                    (*wt1P)--;
                    
                    act = 0;
                } 
                else if (!(sts & 0x2000000))
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        lop = 1;
                        
                        *br1P = lop;
                        *br2P = TY_BR2_FIRST;
                    }
                } 
                else 
                {
                    *br1P = TY_BR1_ROTATE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        } 
                        else 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        }
                    } 
                    else
                    {
                        act = 0;
                    }
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    { 
                        *br1P = TY_BR1_NORMAL; 
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 4;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((((sts & 0x1000000)) || ((sts & 0x1000))) && (((sts & 0x2000000)) || ((sts & 0x1000))))
                    {
                        lop = 1;
                        
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= 65536) || (fwP->tgt_ang < 1820))
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl < 3) 
                    {
                        if (fwP->dmg_lvl < 2) 
                        { 
                            act = 16; 
                        }
                        else 
                        { 
                            act = 17; 
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                        
                        fwP->dmg_lvl = 0;
                    }
                    else 
                    {
                        act = 18;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte)
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->dmg_lvl != 0)
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if (fwP->dmg_lvl >= 5)
                    {
                        if (rte > 39321)
                        {
                            *br0P = TY_BR0_DOWN;
                            *br1P = TY_BR1_DAMAGE;
                            *br2P = TY_BR2_FIRST;
                        }
                    }
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_DOWN;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                        
                        *wt1P = 120;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DOWN:
            ewP->comb_timeout = 0;
            
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0) 
                {
                    (*wt1P)--;
                    
                    if ((!(sts & 0x2000000)) && ((sts & 0x1000)))
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        act = 1;
                    }
                } 
                else 
                {
                    *br1P = TY_BR1_CHANGE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (((sts & 0x1)) && (!(*pstP & 0x1)))
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 12; 
                            } 
                            else 
                            { 
                                act = 13; 
                            }
                        } 
                        else 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 13; 
                            } 
                            else 
                            { 
                                act = 12; 
                            }
                        }
                    } 
                    else 
                    {
                        act = 1;
                    }
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    { 
                        *br1P = TY_BR1_NORMAL; 
                    }
                    
                    break;
                }
                            
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl >= 5) 
                    {
                        act = 19;
                        
                        *br2P = TY_BR2_LOOP0;
                    } 
                    else
                    {
                        *br1P = TY_BR1_NORMAL;
                        
                        lop = 1;
                    }
                    
                    fwP->dmg_lvl = 0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_LAY;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_CHANGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 20;
                    
                    *br2P = TY_BR2_LOOP0;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_NORMAL;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_LAY:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                *br0P = TY_BR0_DIE;
                *br1P = TY_BR1_NORMAL;
                
                act = 2;
                
                *br2P = TY_BR2_FIRST;
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DIE:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    ewP->mtn_add = 0;
                    
                    act = 2;
                    
                    ewP->flg |= 0x2;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        }
    } while (lop-- != 0);

    if (act != -1) 
    {
        bhEne19_ActionChange(ewP, fwP, act);
    }
}

// 100% matching!
static void bhEne19_Br01(BH_PWORK* ewP)
{
    FW_WORK* fwP;      
    int* stsP, *pstP;        
    int sts;         
    TY_BR_MODE0* br0P; 
    TY_BR_MODE1* br1P; 
    TY_BR_MODE2* br2P; 
    int* wt1P;         
    int rte;          
    int act;          
    int lop;           
    ATR_WORK* htP;    
    BH_PWORK* ewP2; // not from DWARF

    stsP = &((FW_WORK*)ewP->exp0)->status;
    pstP = &((FW_WORK*)ewP->exp0)->ply_act.p_status; 

    fwP = (FW_WORK*)ewP->exp0;

    if (!(*stsP & 0x400)) 
    {
        fwP->tgt_pos = *(NJS_POINT3*)&plp->px;
        
        *stsP |= 0x1;
    }

    bhEne19_TargetAnalyze(ewP, fwP);

    sts = *stsP;
    
    rte = fwP->mtn_rte;
    
    br0P = &fwP->br_mde0;
    br2P = &fwP->br_mde2;
    br1P = &fwP->br_mde1;
    
    wt1P = &fwP->br_wait1;
    
    act = -1;
    
    lop = 0;

    if (fwP->ct_pinch > 0) 
    {
        fwP->ct_pinch--;
    }

    if ((fwP->mode0_bak == 5) || ((sys->rm_flg & 0x8))) 
    {
        sys->rm_flg &= ~0x8;
        
        if (fwP->ct_pinch <= 0) 
        {
            fwP->act_now = -2;
            
            *br0P = TY_BR0_PINCH;
            *br1P = TY_BR1_NORMAL;
            *br2P = TY_BR2_FIRST;
        } 
        else
        {
            fwP->act_now = -2;
            
            *br0P = TY_BR0_NORMAL;
            *br1P = TY_BR1_NORMAL;
            *br2P = TY_BR2_FIRST;
        }
    }

    htP = bhCheckFloorEnemy(ewP->flr_no, (ewP2 = ewP)->px, ewP->pz); // the second parameter is a bit devious and I sure hope that it's not the actual solution
    
    sys->rm_flg &= ~0x7;
    
    if ((htP != NULL) && (htP->prm0 == 19)) 
    {
        if (htP->prm1 == 4) 
        {
            sys->rm_flg |= 0x1;
        } 
        else if (htP->prm1 == 5) 
        {
            sys->rm_flg |= 0x2;
        }
    }

    if ((*br0P == TY_BR0_PINCH) || (ewP->hp < 0)) 
    {
        sys->rm_flg |= 0x4;
    }

    if ((sys->rm_flg & 0x10)) 
    {
        sys->rm_flg &= ~0x10;
        
        bhEne19_ClawReset(ewP, fwP);
    }

    do 
    {
        switch (*br0P) 
        {
        case TY_BR0_NORMAL:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0)
                {
                    act = 0;
                    
                    (*wt1P)--;
                } 
                else if (!(sts & 0x1000000)) 
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else if ((((sts & 0x200000)) && (!(sts & 0x400000)) && ((sts & 0x1))) && (!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        *br1P = TY_BR1_DASH_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                } 
                else if (!(sts & 0x2000000)) 
                {
                    if ((sts & 0x1000)) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                        break;
                    }
                    
                    *br1P = TY_BR1_WALK;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                } 
                else 
                {
                    *br1P = TY_BR1_ROTATE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        }
                        else
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                    } 
                    else 
                    {
                        act = 11;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if ((rte <= 32768) && (((sts & 0x2000000)) || (!(sts & 0x1000)))) 
                    {
                        *wt1P = 20;
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_DASH_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (!(sts & 0x8)) 
                    {
                        if ((sts & 0x2000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    } 
                    else 
                    {
                        if ((sts & 0x4000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    }
                    
                    fwP->ct_dash = 1;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= 45875) && (!(*pstP & 0x1)) && ((!(sts & 0x1000000)) && (!(sts & 0x400000))) && (fwP->ct_dash < 3)) 
                    {
                        if (ewP->hp >= 0) 
                        {
                            fwP->ct_dash++;
                            
                            if (fwP->act_now == 15) 
                            {
                                act = 14;
                            }
                            else 
                            { 
                                act = 15;
                            }
                        }
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 5;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((!(sts & 0x1000000)) && (!(sts & 0x1000))) 
                    {
                        if (((!(sts & 0x200000)) || ((sts & 0x400000))) || ((*pstP & 0x1)))
                        {
                            break;
                        }
                    } 
                    else if ((!(sts & 0x2000000)) && (!(sts & 0x1000))) 
                    {
                        break;
                    }
                    
                    *br1P = TY_BR1_NORMAL;
                    
                    lop = 1;
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->tgt_ang < 1820)
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if ((fwP->ct_pinch == 0) || (fwP->dmg_lvl >= 5)) 
                    {
                        act = 17;
                        
                        *br2P = TY_BR2_LOOP1;
                        break;
                    } 
                    else if (fwP->dmg_lvl >= 3) 
                    {
                        fwP->ct_pinch = (fwP->ct_pinch * 50) / 100;
                    }
                    
                    fwP->dmg_lvl = 0;
                    
                    act = 16;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if ((rte >= 32768) && (fwP->dmg_lvl != 0)) 
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_PINCH;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_PINCH:
            switch (*br1P)
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0) 
                {
                    act = 0;
                    
                    (*wt1P)--;
                } 
                else if (!(sts & 0x2000000))
                {
                    if ((sts & 0x1000))
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                    else  
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                } 
                else 
                {
                    *br1P = TY_BR1_ROTATE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        } 
                        else 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        }

                        *br2P = TY_BR2_LOOP0;
                    }
                    else 
                    {
                        act = 11;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if ((rte <= 32768) && (((sts & 0x2000000)) || (!(sts & 0x1000)))) 
                    {
                        *wt1P = 32;
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (rte >= fwP->chg_rte)
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 6;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (((sts & 0x2000000)) || ((sts & 0x1000))) 
                    {
                        *br1P = TY_BR1_NORMAL;
                        
                        lop = 1;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= fwP->chg_rte) || (fwP->tgt_ang < 1820))  
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl >= 4) 
                    {
                        act = 17;
                    }
                    else 
                    {
                        act = 16;
                    }
                    
                    fwP->dmg_lvl = 0;
                    
                    *br2P = TY_BR2_LOOP0;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte)
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if ((rte >= 32768) && (fwP->dmg_lvl != 0)) 
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        }
    } while (lop--);

    if (act != -1) 
    {
        bhEne19_ActionChange(ewP, fwP, act);
    }
}

// 100% matching!
static void bhEne19_Br02(BH_PWORK* ewP)
{
    FW_WORK* fwP;      
    int* stsP, *pstP;         
    unsigned char rut; 
    NJS_POINT3 pos;   
    int sts;         
    TY_BR_MODE0* br0P; 
    TY_BR_MODE1* br1P;
    TY_BR_MODE2* br2P; 
    int* wt1P;         
    int rte;           
    int act;           
    int lop;           

    fwP = (FW_WORK*)ewP->exp0;
    
    stsP = &fwP->status;
    pstP = (int*)&fwP->ply_act;

    if (!(fwP->status & 0x400))
    {
        pos = *(NJS_POINT3*)&ewP->mlwP->owP[1].mtx[12];
        
        pos.y = ewP->py;
        
        njSubVector(&pos, (NJS_VECTOR*)&ewP->mlwP->owP->mtx[8]);

        rut = bhCheckRoute(&pos, (NJS_POINT3*)&plp->px, &((FW_WORK*)ewP->exp0)->tgt_pos);
        
        if (rut == 0xFF) 
        {
            ((FW_WORK*)ewP->exp0)->tgt_pos = *(NJS_POINT3*)&plp->px;
            
            *stsP |= 0x1;
        }
        else if (rut == bhCheckRouteID((NJS_POINT3*)&plp->px)) 
        {
            ((FW_WORK*)ewP->exp0)->tgt_pos = *(NJS_POINT3*)&plp->px;
            
            *stsP |=  0x1;
        } 
        else 
        {
            *stsP &= ~0x1;
        }
    }

    bhEne19_TargetAnalyze(ewP, fwP);

    sts = *stsP;
    
    rte = fwP->mtn_rte;
    
    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;
    br2P = &fwP->br_mde2;
    
    wt1P = &fwP->br_wait1;
    
    act = -1;
    
    lop = 0;

    do 
    {
        switch (*br0P) 
        {
        case TY_BR0_NORMAL:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0) 
                {
                    act = 0;
                    
                    (*wt1P)--;
                } 
                else if (!(sts & 0x1000000)) 
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else
                    {
                        if ((((sts & 0x200000)) && (!(sts & 0x400000)) && ((sts & 0x1))) && (!(*pstP & 0x1)) && (!(sts & 0x800))) 
                        {
                            *br1P = TY_BR1_DASH_ATTACK;
                            *br2P = TY_BR2_FIRST;
                            
                            lop = 1;
                        } 
                        else 
                        {
                            *br1P = TY_BR1_WALK;
                            *br2P = TY_BR2_FIRST;
                            
                            lop = 1;
                        }
                    }
                } 
                else if (!(sts & 0x2000000)) 
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                    else 
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                } 
                else 
                {
                    if ((sts & 0x1))
                    {
                        *br1P = TY_BR1_ROTATE;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        } 
                        else
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                    } 
                    else 
                    {
                        act = 11;
                        
                        *br2P = TY_BR2_LOOP1;
                    } 
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if ((rte <= 32768) && (((sts & 0x1000000)) || (!(sts & 0x1000)))) 
                    {
                        *wt1P = 20;
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_DASH_ATTACK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    if (!(sts & 0x8)) 
                    {
                        if ((sts & 0x2000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    }
                    else 
                    {
                        if ((sts & 0x4000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    }
                    
                    fwP->ct_dash = 1;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= 45875) && (!(*pstP & 0x1)) && ((!(sts & 0x1000000)) && (!(sts & 0x400000))) && (fwP->ct_dash < 3) && ((sts & 0x1)) && (ewP->hp >= 0)) 
                    {
                        fwP->ct_dash++;
                        
                        if (fwP->act_now == 15) 
                        {
                            act = 14;
                        }
                        else
                        {
                            act = 15;
                        }
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    act = 5;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((!(sts & 0x1000000)) && (!(sts & 0x1000))) 
                    {
                        if (((!(sts & 0x200000)) || ((sts & 0x400000))) || ((*pstP & 0x1)))
                        {
                            break;
                        }
                    } 
                    else if ((!(sts & 0x2000000)) && (!(sts & 0x1000))) 
                    {
                        break;
                    }
                    
                    *br1P = TY_BR1_NORMAL;
                    
                    lop = 1;
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->tgt_ang < 1820) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl < 3) 
                    {
                        if (fwP->dmg_lvl <= 1) 
                        {
                            act = 16;
                        }
                        else
                        {
                            act = 17;
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                        
                        fwP->dmg_lvl = 0;
                    }
                    else
                    {
                        ewP->flg &= ~0x60;
                        
                        act = 18;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->dmg_lvl != 0) 
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if (rte > 39321) 
                    {
                        *br0P = TY_BR0_DOWN;
                        *br1P = TY_BR1_DAMAGE;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DOWN:
            switch (*br1P) 
            {
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 19;
                    
                    *br2P = TY_BR2_LOOP0;
                    
                    fwP->dmg_lvl = 0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_DIE;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DIE:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 2;
                    
                    ewP->flg |= 0x2;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    ewP->mtn_add = 0;
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        }
    } while (lop--);

    if (act != -1) 
    {
        bhEne19_ActionChange(ewP, fwP, act);
    }
}

// 100% matching!
static void bhEne19_Mv00(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv01(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv02(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x4;
    }
}

// 100% matching!
static void bhEne19_Mv03(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv04a(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP |= 0x4;
    }
}

// 100% matching!
static void bhEne19_Mv04b(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv05(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv06(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv07(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP;    
    float pos[3]; 
    int ang[3];   

    stsP = &fwP->status;

    *stsP |= 0x20;  
    
    if (count == 0) 
    {
        *stsP &= ~0x4;
        
        if ((*stsP & 0x2000)) 
        {
            *stsP |= 0x8;
        }
        else if ((*stsP & 0x4000))
        {
            *stsP &= ~0x8;
        }
        
        fwP->pos_tmp[0] = ewP->px;
        fwP->pos_tmp[1] = ewP->py;
        fwP->pos_tmp[2] = ewP->pz;
        
        fwP->ang_tmp[0] = ewP->ax;
        fwP->ang_tmp[1] = ewP->ay;
        fwP->ang_tmp[2] = ewP->az;
        
        njSetMatrix(&fwP->mtx_bak, ewP->mtx);
    }
    
    if ((*stsP & 0x8)) 
    {
        ewP->mtn_md |= 0x2;
    } 
    else 
    {
        ewP->mtn_md &= ~0x2;
    }
    
    bhGetObjMotion(ewP, 0, pos, ang);
    
    ewP->ax = ang[0];
    ewP->ay = fwP->ang_tmp[1] + ang[1];
    ewP->az = ang[2];
    
    njCalcPoint(&fwP->mtx_bak, (NJS_POINT3*)pos, (NJS_POINT3*)pos);
    
    ewP->px += 0.1f * (pos[0] - ewP->px);
    ewP->pz += 0.1f * (pos[2] - ewP->pz);
    
    if (fwP->mtn_rte >= 52428) 
    {
        *stsP |= 0x4;
    }
}

// 100% matching!
static void bhEne19_Mv08(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    int* stsP;       
    NJS_POINT3 dir;   
    NJS_POINT3 pos;  
    NJS_MATRIX* mtxP; 

    stsP = &fwP->status;

    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(*stsP & 0x8)) ? TY_ARM_RIGHT : TY_ARM_LEFT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        fwP->trw_spd = 2.0f;

        if (((!(*stsP & 0x8)) && ((*stsP & 0x40000000))) || (((*stsP & 0x8)) && ((*stsP & 0x80000000)))) 
        {
            mtxP = &plp->mlwP->owP[2].mtx;
            
            pos = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[12];
            
            njAddVector(&pos, (NJS_VECTOR*)&plp->mlwP->owP[2].mtx[12]);
            
            pos.x *= 0.5f;
            pos.y *= 0.5f;
            pos.z *= 0.5f;
            
            dir = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[4];
            
            dir.x *= -1.0f;
            dir.y *= -1.0f;
            dir.z *= -1.0f;
            
            rySetEffBlood(mtxP, &pos, &dir, 0);
            
            fwP->snd_no = 11;
        } 
        else 
        {
            fwP->snd_no = 9;
        }
    }
}

// 100% matching!
static void bhEne19_Mv09(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    int* stsP;       
    NJS_POINT3 dir;   
    NJS_POINT3 pos;  
    NJS_MATRIX* mtxP; 

    stsP = &fwP->status;

    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(*stsP & 0x8)) ? TY_ARM_LEFT : TY_ARM_RIGHT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        fwP->trw_spd = 2.0f;

        if ((((*stsP & 0x8)) && ((*stsP & 0x40000000))) || ((!(*stsP & 0x8)) && ((*stsP & 0x80000000)))) 
        {
            mtxP = &plp->mlwP->owP[2].mtx;
            
            pos = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[12];
            
            njAddVector(&pos, (NJS_VECTOR*)&plp->mlwP->owP[2].mtx[12]);
            
            pos.x *= 0.5f;
            pos.y *= 0.5f;
            pos.z *= 0.5f;
            
            dir = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[4];
            
            dir.x *= -1.0f;
            dir.y *= -1.0f;
            dir.z *= -1.0f;
            
            rySetEffBlood(mtxP, &pos, &dir, 0);
            
            fwP->snd_no = 11;
        } 
        else 
        {
            fwP->snd_no = 9;
        }
    }
}

// 100% matching!
static void bhEne19_Mv10(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* flgP, *stsP;        
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;    
    NJS_POINT3 dir;   
	static NJS_POINT3 off = {  2.5f,    0,    0 };
	static NJS_VECTOR vct = { -1.0f,    0,    0 };

    flgP = &fwP->act_flg;
    stsP = &fwP->status;
    
    if (count == 0) 
    {
        *stsP &= ~0x8;
        *flgP |=  0x8;
        
        fwP->trn_spd = 182;
    }
    
    mtx0P = &ewP->mlwP->owP[10].mtx;
    mtx2P = &ewP->mlwP->owP[12].mtx;
    
    if (fwP->act_frm == 50) 
    {
        bhEne19_SetClawPlane(ewP, mtx0P, -0x0F7F7F80, 11, -2.0f, 3.0f);
        bhEne19_SetClawPlane(ewP, mtx2P,          -1, 11, -2.0f, 3.0f);
    }
    
    if (fwP->act_frm == 60)
    {
        njCalcVector(mtx0P, &vct, &dir);
        njCalcPoint(mtx0P,  &off, &pos);
        
        bhSetEffSpark(&pos, &dir, -1, 0x40F08000, 0);
        bhSetEffSpark(&pos, &dir, -1, 0x40F08000, 1);
        bhSetEffSpark(&pos, &dir, -1, 0x40F04000, 0);
        bhSetEffSpark(&pos, &dir, -1, 0x40F04000, 1);
        
        bhSetRapEff(310, &fwP->e0aP[1], 8);
        
        fwP->snd_no = 19;
    }
    
    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, TY_ARM_RIGHT, 5.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        NJS_POINT3 dir;
        NJS_MATRIX* mtxP; 
        
        fwP->trw_spd = 0.5f;
        
        fwP->snd_no = 15;
        
        mtxP = &plp->mlwP->owP[2].mtx;
        
        dir = *(NJS_POINT3*)&(*mtxP)[4];
        
        njSubVector(&dir, (NJS_POINT3*)&(*mtxP)[8]);
        
        rySetEffBlood(mtxP, (NJS_POINT3*)&(*mtxP)[12], &dir, 2);
    }
}

// 100% matching!
static void bhEne19_Mv11(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, ((fwP->status & 0x8)) ? TY_ARM_LEFT : TY_ARM_RIGHT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 100% matching!
static void bhEne19_Mv12(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, ((fwP->status & 0x8)) ? TY_ARM_RIGHT : TY_ARM_LEFT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 100% matching!
static void bhEne19_Mv13(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP, *flgP;          
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;     
    NJS_POINT3 dir;     
    TY_OBJ_MODE obj_no;
    TY_ARM_NO arm_no;   
    ATR_WORK* htP;      
	static NJS_POINT3 off = {  3.0f,     0,     0 };
	static NJS_VECTOR vct = { -1.0f, -1.0f, -1.0f };
    
    stsP = &fwP->status;
    flgP = &fwP->act_flg;

    if (count == 0) 
    {
        *flgP |= 0x8;
        
        fwP->trn_spd = 546;
    }

    if ((!(*stsP & 0x8)) || ((*stsP & 0x80000000))) 
    {
        if (!(*stsP & 0x8)) 
        {
            mtx0P = &ewP->mlwP->owP[10].mtx;
            mtx2P = &ewP->mlwP->owP[12].mtx;
        } 
        else 
        {
            mtx0P = fwP->clw0P->mtxP;
            mtx2P = fwP->clw2P->mtxP;
        }

        if (fwP->act_frm == 8)
        {
            bhEne19_SetClawPlane(ewP, mtx0P, -0xF7F7F80, 16, -2.0f, 3.0f);
            bhEne19_SetClawPlane(ewP, mtx2P, -1,         16, -2.0f, 3.0f);
        }

        if ((fwP->act_frm >= 18) && (fwP->act_frm < 19)) 
        {
            njCalcVector(mtx0P, &vct, &dir);
            njCalcPoint(mtx0P,  &off, &pos);
            
            bhSetEffSpark(&pos, &dir, -1, 0x80F02000, 0);
            bhSetEffSpark(&pos, &dir, -1, 0x80F04000, 0);
            bhSetEffSpark(&pos, &dir, -1, 0x80F05000, 0);
        }
    }

    if ((*stsP & 0x40)) 
    {
        if ((*stsP & 0x8)) 
        {
            arm_no = TY_ARM_LEFT;
            obj_no = TY_OBJ_ARM_L2;
        } 
        else 
        {
            arm_no = TY_ARM_RIGHT;
            obj_no = TY_OBJ_ARM_R2;
        }

        if (bhEne19_AttackHitCheck(ewP, arm_no, 3.5f, &fwP->trw_dir) != 0) 
        {
            NJS_POINT3 dir; 
            int dmg;       
            float spd;     
            int ang;       
            
            ang = fwP->trw_dir;

            dir.x = plp->px - (25.0f * njSin(ang));
            dir.y = plp->py;
            dir.z = plp->pz - (25.0f * njCos(ang));

            if ((bhCollisionCheckLine2((NJS_POINT3*)&plp->px, &dir, 0x4000, plp->flr_no) != NULL) && (njDistanceP2P((NJS_POINT3*)&plp->px, &dir) > 10.0f)) 
            {
                dmg = 3;
                
                spd = 2.5f;
            } 
            else 
            {
                dmg = 1;
                
                spd = 2.0f;
            }

            if (bhEne19_PlySetDamage(plp, fwP, dmg) != 0) 
            {
                if ((!(*stsP & 0x8)) || ((*stsP & 0x80000000))) 
                {
                    NJS_POINT3 dir;  
                    NJS_MATRIX* mtxP;
                    NJS_POINT3* posP; 

                    mtxP = &plp->mlwP->owP[2].mtx;
                    posP = (NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[12];

                    dir = *(NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[4];
                    
                    dir.x *= -1.0f; 
                    dir.y *= -1.0f;
                    dir.z *= -1.0f;
                    
                    rySetEffBlood(mtxP, posP, &dir, 1);
                    
                    fwP->snd_no = 11;
                } 
                else 
                {
                    fwP->snd_no = 9;
                }
                
                fwP->trw_spd = spd;
            }
        }
    }
}

// 99.85% matching
static void bhEne19_Mv14(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP, *flgP;          
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;     
    NJS_POINT3 dir;     
    TY_OBJ_MODE obj_no;
    TY_ARM_NO arm_no;   
    ATR_WORK* htP;      
	static NJS_POINT3 off = {  3.0f,     0,     0 };
	static NJS_VECTOR vct = {  1.0f, -1.0f,  1.0f };
    
    stsP = &fwP->status;
    flgP = &fwP->act_flg;

    if (count == 0) 
    {
        *flgP |= 0x8;
        
        fwP->trn_spd = 546;
    }

    if (((*stsP & 0x8)) || ((*stsP & 0x80000000))) 
    {
        if ((*stsP & 0x8)) 
        {
            mtx0P = &ewP->mlwP->owP[10].mtx;
            mtx2P = &ewP->mlwP->owP[12].mtx;
        } 
        else 
        {
            mtx0P = fwP->clw0P->mtxP;
            mtx2P = fwP->clw2P->mtxP;
        }

        if (fwP->act_frm == 8)
        {
            bhEne19_SetClawPlane(ewP, mtx0P, -0xF7F7F80, 16, -2.0f, 3.0f);
            bhEne19_SetClawPlane(ewP, mtx2P, -1,         16, -2.0f, 3.0f);
        }

        if ((fwP->act_frm >= 16) && (fwP->act_frm < 23)) 
        {
            njCalcVector(mtx0P, &vct, &dir);
            njCalcPoint(mtx0P,  &off, &pos);
            
            if (bhCheckWallType(&pos, 0, 0.1f, 0.1f) != NULL) 
            {
                bhSetEffSpark(&pos, &dir, -1, 0x80F06000, 0);
                bhSetEffSpark(&pos, &dir, -1, 0x80F04000, 0);
                bhSetEffSpark(&pos, &dir, -1, 0x80F02000, 0);
            }
        }
    }

    if ((*stsP & 0x40)) 
    {
        if ((*stsP & 0x8)) 
        {
            arm_no = TY_ARM_RIGHT;
            obj_no = TY_OBJ_ARM_R2;
        } 
        else 
        {
            arm_no = TY_ARM_LEFT;
            obj_no = TY_OBJ_ARM_L2;
        }

        if (bhEne19_AttackHitCheck(ewP, arm_no, 3.5f, &fwP->trw_dir) != 0) 
        {
            NJS_POINT3 dir; 
            int dmg;       
            float spd;     
            int ang;       
            
            ang = fwP->trw_dir;

            dir.x = plp->px - (25.0f * njSin(ang));
            dir.y = plp->py;
            dir.z = plp->pz - (25.0f * njCos(ang));

            if ((bhCollisionCheckLine2((NJS_POINT3*)&plp->px, &dir, 0x4000, plp->flr_no) != NULL) && (njDistanceP2P((NJS_POINT3*)&plp->px, &dir) > 10.0f)) 
            {
                dmg = 3;
                
                spd = 2.5f;
            } 
            else 
            {
                dmg = 1;
                
                spd = 2.0f;
            }

            if (bhEne19_PlySetDamage(plp, fwP, dmg) != 0) 
            {
                if (((*stsP & 0x8)) || ((*stsP & 0x80000000))) 
                {
                    NJS_POINT3 dir;  
                    NJS_MATRIX* mtxP;
                    NJS_POINT3* posP; 

                    mtxP = &plp->mlwP->owP[2].mtx;
                    posP = (NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[12];

                    dir = *(NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[4];
                    
                    dir.x *= -1.0f; 
                    dir.y *= -1.0f;
                    dir.z *= -1.0f;
                    
                    rySetEffBlood(mtxP, posP, &dir, 1);
                    
                    fwP->snd_no = 11;
                } 
                else 
                {
                    fwP->snd_no = 9;
                }
                
                fwP->trw_spd = spd;
            }
        }
    }
}

// 100% matching!
static void bhEne19_Mv15(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv16(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv17(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        *stsP |= 0x100;

        if ((*bstP & 0x40000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv18(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg &= ~0x60;

        fwP->status &= ~0x100;
        fwP->status |=  0x200;
    }
}

// 100% matching!
static void bhEne19_Mv19(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x100;
    }
}

// 100% matching!
static void bhEne19_Mv20(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg |= 0x60;
    }

    if (fwP->mtn_rte >= 65536)
    {
        fwP->status &= ~0x200;
        fwP->status |=  0x100;
    }
}

// 100% matching!
static EA_WORK* bhEne19_ActionSearch(int act_nw, int act_no)
{
	int key;  
	int high, low;  
	int val;   
	int middle; 

    key = ((unsigned char)act_nw << 8) | ((unsigned char)act_no << 0);

    high = 50;
    low  = 0;

    while (low <= high)
    {
        middle = (low + high) / 2;
        
        val = En19ActTbl[middle].label;

        if (key != val)
        {
            if (key < val)
            {
                high = middle - 1;
            }
            else if (key > val)
            {
                low  = middle + 1;
            }
        }
        else 
        {
            return &En19ActTbl[middle];
        }
    }

    return NULL;
}

// 100% matching!
static int bhEne19_ActionChange(BH_PWORK* ewP, FW_WORK* fwP, int act_dst)
{
    EA_WORK* eaP;
    
    if (((eaP = bhEne19_ActionSearch(fwP->act_now, act_dst)) == NULL) && (fwP->act_now != act_dst)) 
    {
        eaP = bhEne19_ActionSearch(-1, act_dst);
    }
    
    if (eaP != NULL) 
    {
        njMemCopy4(&fwP->b_status, &fwP->status, 8);
        
        fwP->b_mtn_md = ewP->mtn_md;
        
        fwP->act_flg = 0;
        
        fwP->prgP = eaP->prgP;
        
        fwP->act_cnt = 0;
        fwP->act_frm = eaP->frm_no;
        
        ewP->mtn_no = eaP->mtn_no;
        ewP->frm_no = eaP->frm_no * 65536;
        
        ewP->hokan_rate  = eaP->hkn_lvl * (65536.0 / 255.0);
        ewP->hokan_count = eaP->hkn_cnt;

        if ((eaP->flag & 0x20000)) 
        {
            ewP->mtn_add = 0;
        } 
        else if ((eaP->flag & 0x40000)) 
        {
            ewP->mtn_add = -65536;
        } 
        else 
        {
            ewP->mtn_add =  65536;
        }

        ewP->mtn_md = (unsigned short)eaP->flag;
        
        fwP->chg_rte = eaP->chg_rte * 65536.0f;
        
        fwP->status &= ~0x38000;

        if ((eaP->flag & 0x80000)) 
        {
            fwP->status |= 0x8000;
        }

        fwP->act_now = act_dst;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static int bhEne19_ActionMain(BH_PWORK* ewP, FW_WORK* fwP)
{
    short* s16P; 
    int ang;    
    int mat;     
    int* stsP;  

    stsP = &fwP->status;
    
    mat = bhEne19_MtnAttrbuteGet(ewP);
    
    *stsP &= ~0x30000;
    
    if ((mat & 0x2)) 
    {
        *stsP |= 0x10000;
    }
    else if ((mat & 0x1)) 
    {
        *stsP |= 0x20000;
    }
    
    *stsP &= ~0xC0000;
    
    if ((mat & 0x8)) 
    {
        *stsP |= 0x40000;
    }
    else if ((mat & 0x4)) 
    {
        *stsP |= 0x80000;
    }
    
    fwP->snd_no = (unsigned char)(mat / 256);
    
    if ((mat & 0x10))
    {
        *stsP |=  0x40;
    }
    else 
    {
        *stsP &= ~0x40;
    }
    
    if ((mat & 0x20)) 
    {
        *stsP |=  0x10;
    }
    else
    {
        *stsP &= ~0x10;
    }
    
    if (fwP->prgP != NULL) 
    {
        fwP->prgP(ewP, (en19_freework*)fwP, fwP->act_cnt++);
    }
    
    if ((fwP->act_flg & 0x8)) 
    {
        ang = (fwP->tgt_ang > fwP->trn_spd) ? fwP->trn_spd : fwP->tgt_ang;
        
        if ((fwP->status & 0x2000))
        {
            ewP->ay += ang;
        }
        
        if ((fwP->status & 0x4000)) 
        {
            ewP->ay -= ang;
        }
    }
    
    if ((fwP->status & 0x8)) 
    {
        ewP->mtn_md |=  0x2;
    } 
    else 
    {
        ewP->mtn_md &= ~0x2;
    } 
    
    s16P = (short*)&fwP->act_frm;
    
    s16P[1] += bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);
    s16P[0] =  ewP->frm_no / 65536;
    
    fwP->mtn_rte = ewP->frm_no / (ewP->mnwP[ewP->mtn_no].frm_num - 1);
    
    return 0;
}

// 100% matching!
static void bhEne19_TargetAnalyze(BH_PWORK* ewP, FW_WORK* fwP)
{    
    int* stsP;        
    float dst;        
    int dlt;          
    int ang;        

    stsP = &fwP->status;

    if (((*stsP & 0x1)) && ((plp->hp < 0) || ((plp->flg & 0x2)))) 
    {
        *stsP |= 0x800;
    }

    dst = njDistanceP2P((NJS_POINT3*)&ewP->px, &fwP->tgt_pos);
    
    fwP->tgt_dst = dst;

    *stsP &= ~0xF00000;

    if (dst >= 10.0f) 
    {
        *stsP |= 0x100000;
    }
    
    if (dst >= 20.0f) 
    {
        *stsP |= 0x200000;
    }
    
    if (dst >= 25.0f) 
    {
        *stsP |= 0x400000;
    }
    
    if (dst >= 17.0f) 
    {
        *stsP |= 0x800000;
    }

    fwP->ply_dst = njDistanceP2P((NJS_POINT3*)&ewP->px, (NJS_POINT3*)&plp->px);

    dlt = plp->ay - ewP->ay;
    
    if ((dlt & 0x8000)) 
    {
        dlt = (65536 - dlt) | 0x80000000;
    }
    
    fwP->dir_dlt = dlt;

    {
    int dlt;         
    NJS_POINT3 pos;   
    NJS_MATRIX* mtxP; 
        
    dlt = (short)((int)(10430.381f * atan2f(ewP->px - fwP->tgt_pos.x, ewP->pz - fwP->tgt_pos.z)) - ewP->ay);
        
    fwP->tgt_ang = ang = abs(dlt);

    *stsP &= ~0xF006000;
        
    if (dlt < 0) 
    {
        fwP->status |= 0x4000;
    } 
    else 
    {
        fwP->status |= 0x2000;
    }

    if (ang >= 5461) 
    {
        *stsP |= 0x1000000;
    }
        
    if (ang >= 16384) 
    {
        *stsP |= 0x2000000;
    }
        
    if (ang >= 21845) 
    {
        *stsP |= 0x4000000;
    }
        
    if (ang >= 27306) 
    {
        *stsP |= 0x8000000;
    }

    mtxP = &ewP->mlwP->owP->mtx;

    pos = fwP->tgt_pos;

    *stsP &= ~0x1000;

    if ((*stsP & 0x2)) 
    {
        if (bhEne19_CollisionCircle2Oval(mtxP, fwP->atk_rng_a_far, fwP->atk_rng_b_far, &pos, 0) != 0) 
        {
            *stsP |=  0x1000;
        } 
        else 
        {
            *stsP &= ~0x2;
        }
    } 
    else 
    {
        if (bhEne19_CollisionCircle2Oval(mtxP, fwP->atk_rng_a_near, fwP->atk_rng_b_near, &pos, 0) != 0) 
        {
            *stsP |= 0x1002;
        }
    }
    }
}

// 100% matching!
static void bhEne19_PositonFix(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_POINT3* vaP; 
    int sts;         
    char** tblP;     
    NJS_VECTOR vct; 
    NJS_POINT3* vzP; 
	static const char FixDatLL[7] = { 0, 1, 22, 23, 24, 25, -1 };
	static const char FixDatLR[7] = { 0, 1, 18, 19, 20, 21, -1 };
	static const char FixDatAL[9] = { 0, 1,  2,  3, 14, 15, 16, 17, -1 };
	static const char FixDatAR[9] = { 0, 1,  2,  3,  6,  7,  8,  9, -1 };
	static char* FixDatTbl[2][4] = 
	{
		{ (char*)FixDatLL, (char*)FixDatLR, (char*)FixDatAL, (char*)FixDatAR },
		{ (char*)FixDatLR, (char*)FixDatLL, (char*)FixDatAR, (char*)FixDatAL } 
	};

    sts = fwP->status;
    
    vaP = &fwP->fix_adj;
    
    if ((sts & 0x30000)) 
    {
        if ((sts & 0x8)) 
        {
            tblP = FixDatTbl[1];
        } 
        else
        {
            tblP = FixDatTbl[0];
        }
        
        if ((!(sts & 0x10000)) && ((sts & 0x20000))) 
        {
            tblP++;
        }
        
        bhCalcFixOffset(ewP, *tblP, NULL, vaP);
    } 
    else 
    {
        if (njScalor2(vaP) > 0.25f) 
        {
            njUnitVector(vaP);
            
            vaP->x *= 0.25f;
            vaP->y *= 0.25f;
            vaP->z *= 0.25f;
        }
        else
        {
            vaP->x *= 0.96f;
            vaP->y *= 0.96f;
            vaP->z *= 0.96f;
        }
    }
    
    vzP = (NJS_POINT3*)&lcmat[0][8];
    
    njUnitRotPortion(lcmat);
    
    njRotateY(lcmat, -ewP->ay);
    
    njCalcVector(lcmat, vaP, &vct);
    
    njTransposeMatrix(lcmat);
    
    njScaleV(lcmat, &vct);
    
    njSubVector((NJS_VECTOR*)&ewP->px, vzP);
    
    vaP = (NJS_POINT3*)&lcmat;
    
    fwP->adj_vx = *vaP;
    fwP->adj_vz = *vzP;
}

// 99.55% matching
static void bhEne19_HeadTurn(BH_PWORK* ewP, FW_WORK* fwP, int mode)
{
    O_WORK* owP;        
    NJS_CNK_OBJECT* objP; 
    NJS_POINT3* posP; // needs use    
    int dlt;              
    int ang;              
    
    owP = ewP->mlwP->owP;    

    if (mode != 0)
    {
        objP = &ewP->mlwP->objP[5];       
        
        ang = objP->ang[1]; 
        
        dlt = (short)(((int)(10430.381f * atan2f(owP[5].mtx[12] - fwP->tgt_pos.x, owP[5].mtx[14] - fwP->tgt_pos.z)) - ewP->ay) - ang);
        
        ang += dlt / 8;

        if ((short)ang < -7281) 
        {
            ang = -7281;
        }
        else if ((short)ang > 7281) 
        {
            ang = 7281;
        }

        objP[0].ang[1] = ang;
        objP[1].ang[1] = 0;         

        owP[4].flg |= 0x2;
        owP[5].flg |= 0x2;
    }
    else
    {
        owP[4].flg &= ~0x2;
        owP[5].flg &= ~0x2;
    }
}

// 100% matching!
static int bhEne19_AttackHitCheck(BH_PWORK* ewP, TY_ARM_NO arm_no, float ar, int* angP) 
{
    int hit;        
    NJS_SPHERE spr; 
    FW_WORK* fwP;   
    int dir;       
	static const TY_OBJ_MODE AtkObj[2][2] =
	{
		{ TY_OBJ_ARM_L1, TY_OBJ_ARM_L2 }, 
    	{ TY_OBJ_ARM_R1, TY_OBJ_ARM_R2 }  
	};
	static const NJS_POINT3 AtkOff[2] = 
	{
		{  1.0f, -1.0f,  1.0f },
   	    {  1.0f,  1.0f,  1.0f }
	};
    
    fwP = (FW_WORK*)ewP->exp0;
    
    arm_no &= 0x1;
    
    spr.r = ar;
    
    hit = 0;

    njCalcPoint(&ewP->mlwP->owP[AtkObj[arm_no][0]].mtx, (NJS_POINT3*)&AtkOff[arm_no], &spr.c);

    if (njCollisionCheckSC(&spr, &plp->watr) != 0) 
    {
        hit = 1;
    } 
    else 
    {
        njCalcPoint(&ewP->mlwP->owP[AtkObj[arm_no][1]].mtx, (NJS_POINT3*)&AtkOff[arm_no], &spr.c);
        
        if (njCollisionCheckSC(&spr, &plp->watr) != 0) 
        {
            hit = 1;
        }
        else
        {
            hit = 0;
        }
    }

    if (hit != 0) 
    {
        dir = (fwP->tgt_ang - 16384) / 4;
        
        if (arm_no == 1) 
        {
            dir = ewP->ay - dir;
        }
        else 
        {
            dir = ewP->ay + dir;
        }
        
        *angP = dir;
        
        hit = 1;
    }
    else 
    {
        hit = 0;
    }

    return hit;
}

// 100% matching!
static void bhEne19_CalcEnemy(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_POINT3* srcP, *dstP;
    O_WORK* owP;
    
    bhCalcModel(ewP);
    
    owP = &ewP->mlwP->owP[fwP->watr_top];
    
    srcP = &ewP->watr.c1;
    dstP = (NJS_POINT3*)&owP->mtx[12];
    
    *srcP = *dstP;
    
    owP = &owP[19 - fwP->watr_top];
    
    srcP = &ewP->watr.c2;
    dstP = (NJS_POINT3*)&owP->mtx[12];
    
    *srcP = *dstP;
    
    ewP->watr.c2.x = (ewP->watr.c2.x + owP[4].mtx[12]) / 2.0f;
    ewP->watr.c2.y = (ewP->watr.c2.y + owP[4].mtx[13]) / 2.0f;
    ewP->watr.c2.z = (ewP->watr.c2.z + owP[4].mtx[14]) / 2.0f;
    
    ewP->watr.r = fwP->watr_rad;
}

// 100% matching!
static void bhEne19_DmgCheck(BH_PWORK* ewP, FW_WORK* fwP)
{
    int* stsP;      
    DD_WORK* ddP;   
    int eff_typ;   
    int flg;     
    int dst;        
    NJS_POINT3 dir; 
	static const DD_WORK DmgDat[21] =
	{
		{ { -1, -1, -1 }, { -1, -1, -1 },  0 },
		{ { -1, -1, -1 }, { -1, -1, -1 },  0 },
		{ {  0, -1, -1 }, { 10, -1, -1 }, 14 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  2,  2,  1 }, { -1, -1, -1 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  6,  6,  6 }, { 11, 10,  9 }, 14 },
		{ {  1,  0,  0 }, { -1, -1, -1 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  8,  8,  8 }, { -1, -1, -1 }, 14 },
		{ {  1,  1, -1 }, { -1, -1, -1 }, 14 },
		{ {  5,  5,  5 }, { -1, -1, -1 }, 14 },
		{ {  3,  3,  3 }, { -1, -1, -1 }, 14 },
		{ {  1,  1, -1 }, { -1, -1, -1 }, 14 },
		{ { 11, 11, 11 }, { -1, -1, -1 }, 14 },
		{ {  7,  7,  1 }, { -1, -1, -1 }, 14 },
		{ { 11, 11, 11 }, { -1, -1, -1 }, 14 }
	};
    
    stsP = &fwP->status;
    
    if (((fwP->dmg_flg & 0x80)) && (!(fwP->status & 0x10))) 
    {
        fwP->dmg_flg &= ~0xA0;
        
        if (ewP->hp < 0) 
        {
            ewP->flg |= 0x4;
            
            ewP->comb_flg = fwP->comb_flg;
        }
    }

    if ((ewP->flg & 0x4))
    {
        ewP->flg &= ~0x4;
        
        bhEne_CalcDamage(ewP, En19CombWepTbl, En19CombJointTbl);
        
        ddP = (DD_WORK*)&DmgDat[ewP->comb_wep];
        
        if (((!(*stsP & 0x100)) || ((plp->at_flg & ddP->dmg_cdn))) && ((ewP->comb_wep != 16) || ((ewP->flg2 & 0x4)))) 
        {
            if (ewP->hp >= 0) 
            {
                ewP->hp -= ewP->total_dam;
            }
    
            fwP->dmg_obj = ewP->djnt_no;
            fwP->dmg_lvl = bhEne19_CheckDmgLvl[ewP->type](ewP, fwP);
    
            if (fwP->dmg_dly > fwP->dmg_lvl) 
            {
                fwP->dmg_lvl = fwP->dmg_dly;
                fwP->dmg_dly = TY_DMG_NON;
            }
    
            flg = ewP->comb_flg;
            
            if ((flg & 0x10)) 
            {
                dst = 0;
            } 
            else if ((flg & 0x20))
            {
                dst = 1;
            } 
            else if ((flg & 0x40)) 
            {
                dst = 2;
            }
    
            if ((ewP->comb_wep == 17) && (!(ewP->flg2 & 0x4))) 
            {
                eff_typ = -1;
            }
            else
            {
                eff_typ = ddP->eff_nml[dst];
            }
    
            if ((fwP->eff_tim == 0) && (eff_typ != -1)) 
            {
                dir.x = -ewP->dvx;
                dir.y = -ewP->dvy;
                dir.z = -ewP->dvz;
                
                bhEne19_SetDmgEffect(ewP, ewP->djnt_no, eff_typ, &dir);
                
                if (((flg & 0x1)) && (ddP->eff_nml[dst + 3] != -1))
                {
                    bhEne19_SetDmgEffect(ewP, ewP->djnt_no, ddP->eff_nml[dst + 3], &dir);
                }
                
                if (ewP->comb_wep == 16)
                {
                    fwP->eff_tim = 32;
                }
            }
    
            if (!(fwP->status & 0x10)) 
            {
                if ((fwP->dmg_lvl > 0) && (fwP->br_mde1 != TY_BR1_DAMAGE))
                {
                    fwP->br_mde1 = TY_BR1_DAMAGE;
                    fwP->br_mde2 = TY_BR2_FIRST;
                }
            } 
            else if (fwP->dmg_lvl >= 3) 
            {
                fwP->dmg_flg |= 0x80;
                
                fwP->comb_flg = ewP->comb_flg;
                
                if (fwP->dmg_dly < fwP->dmg_lvl) 
                {
                    fwP->dmg_dly = fwP->dmg_lvl;
                }
            }
        }
    }

    if (fwP->eff_tim != 0) 
    {
        fwP->eff_tim--;
    }
}

// 100% matching!
static void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, NJS_POINT3* dirP)
{
    int* effP;  
    float off_z; 
	static const EO_WORK OffTbl[26] =
	{
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  1.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  6.0f,  3.0f },
		{  0.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f,  0.0f,  4.0f,  4.0f },
		{  1.5f,  0.0f,  3.0f,  3.0f },
		{  1.5f,  0.0f,  3.0f,  3.0f },
		{  1.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  4.0f,  4.0f },
		{ -1.5f,  0.0f,  3.0f,  3.0f },
		{ -1.5f,  0.0f,  3.0f,  3.0f },
		{ -1.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f }
	};
	static const int EffTbl[12][4] = 
	{
		{ 0, 0xFF800000,    4198400,  14 },
		{ 0, 0xFF800000,    4198400,  15 },
		{ 0, 0xFF800000,    4198400,  16 },
		{ 1,          1,          5, 306 },
		{ 1,          0,          1, 305 },
		{ 2,     131072,         32, 298 },
		{ 3,          1,          0,   0 },
		{ 3,          1,          1,   0 },
		{ 3,          1,          2,   0 },
		{ 4,          1, 0x80000000,   0 },
		{ 4,          1, 0x80000001,   0 },
		{ 4,          1, 0x80000002,   0 }
	};
    
    effP = (int*)EffTbl[eff_typ];
    
    if (njInnerProduct((NJS_VECTOR*)&ewP->mlwP->owP->mtx[8], dirP) > 0)
    {
        off_z =  0.8f;
    } 
    else 
    {
        off_z = -0.8f;
    }
    
    switch (effP[0]) 
    {
    case 0:
    {
        NJS_POINT3 off; 
        EO_WORK* eoP;   
        
        eoP = (EO_WORK*)&OffTbl[set_obj];
        
        off.x = eoP->off_x + (eoP->rnd_x * ((-rand() / -2.1474836E9f) - 0.5f));
        off.y = eoP->off_y + (eoP->rnd_y * ((-rand() / -2.1474836E9f) - 0.5f));
        off.z = off_z;
        
        bhSetEffParticleMk2(ewP, set_obj, &off, dirP, effP[1], effP[2], effP[3]);
        break;
    }
    case 1:
    {
        NJS_POINT3 vct; 
        int i;          
        EO_WORK* eoP;  
        NJS_POINT3 off; 
        
        vct = *dirP;
        
        njUnitVector(&vct);
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = 10430.381f * asinf(vct.y);
        sys->ef.ay = 10430.381f * atan2f(vct.x, vct.z);
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = effP[1];
        
        sys->ef.type = 0;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[set_obj].mtx[12];
        
        eoP = (EO_WORK*)&OffTbl[set_obj];
        
        for (i = effP[2]; i > 0; i--) 
        {
            off.x = eoP->off_x + (eoP->rnd_x * ((-rand() / -2.1474836E9f) - 0.5f));
            off.y = eoP->off_y + (eoP->rnd_y * ((-rand() / -2.1474836E9f) - 0.5f));
            off.z = off_z;
            
            bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, set_obj);
        } 
        
        break;
    }
    case 2:
    {
        NJS_POINT3 off; 
        int djnt_no;    
        float scl;     
        
        djnt_no = ewP->djnt_no;
        
        scl = 0.000015258789f * effP[1];
        
        njSetMatrix(lcmat, &ewP->mlwP->owP[djnt_no].mtx);
        
        njInvertMatrix(lcmat);
        
        njCalcPoint(lcmat, (NJS_POINT3*)&ewP->dpx, &off);
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = sys->ef.ay = 0;
        
        sys->ef.mdlver = 0;
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = scl;
        
        sys->ef.type = effP[2];
        
        sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
        
        bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
        break;
    }
    case 3:
    {
        NJS_POINT3 dir;   
        NJS_POINT3* posP; 
        NJS_MATRIX* mtxP; 
        int i;            
        
        dir.x = -ewP->dvx;
        
        posP = (NJS_POINT3*)&ewP->dpx;
        
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        mtxP = &ewP->mlwP->owP[ewP->djnt_no].mtx;
        
        for (i = effP[1]; i > 0; i--)
        {
            rySetEffBlood2(mtxP, posP, &dir, effP[2]);
        }
        
        break;
    }
    case 4:
    {
        NJS_MATRIX* mtxP; 
        EO_WORK* eoP;     
        int i; // moved position from DWARF
        NJS_POINT3 off;   
        
        eoP  = (EO_WORK*)&OffTbl[set_obj];
        mtxP = &ewP->mlwP->owP[ewP->djnt_no].mtx;
        
        for (i = effP[1]; i > 0; i--) 
        {
            off.x = eoP->off_x + (eoP->rnd_x * ((-rand() / -2.1474836E9f) - 0.5f));
            off.y = eoP->off_y + (eoP->rnd_y * ((-rand() / -2.1474836E9f) - 0.5f));
            off.z = off_z;
            
            rySetEffBlood(mtxP, &off, dirP, effP[2]);
        } 
        
        break;
    }
    }
}

// 100% matching!
static int bhEne19_CollisionCircle2Oval(NJS_MATRIX* basP, float ra, float rb, NJS_POINT3* posP, float rc)
{
    float dst;      
    NJS_VECTOR vct; 
    NJS_POINT3 dlt;
    float dr;       
	static const NJS_MATRIX UniMtx = 
	{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

    if (basP == NULL) 
    {
        basP = (NJS_MATRIX*)&UniMtx;
    }
    
    vct.x = posP->x - basP[0][12];
    vct.y = 0;
    vct.z = posP->z - basP[0][14];
    
    dst = njScalor2(&vct);
    
    njSetMatrix(lcmat, basP);
    
    njInvertMatrix(lcmat);
    
    njCalcPoint(lcmat, posP, &dlt);
    
    dlt.x /= ra;
    dlt.y  = 0;
    dlt.z /= rb;
    
    njUnitVector(&dlt);
    
    dlt.x *= ra;
    dlt.z *= rb;
    
    dr = (rc * rc) + njScalor2(&dlt);
    
    if (dr > dst) 
    {
        njUnitVector(&dlt);
        
        dr = njSqrt(dr);
        
        posP->x = dlt.x * dr;
        posP->y = dlt.y * dr;
        posP->z = dlt.z * dr; 
        
        njCalcPoint(basP, posP, posP);
        
        return 1;
    }
    
    *posP = dlt;
    
    njCalcPoint(basP, posP, posP);
    
    return 0;
}

// 100% matching!
static void bhEne19_TyBloodSet(EB_WORK* ebP)
{
    BH_PWORK* ewP;
    FW_WORK* fwP; 
    int rnd;      
    float* prmP;  
	static const float SetPrm[2][3] = 
	{
		{ 18.0f,  0.5f,  1.0f },
		{  4.0f,  1.0f,  2.0f }
	};

    ewP = ebP->ewP;
    fwP = ebP->fwP;
    
    if ((ewP->mode0 != 5) && (ewP->mode0 != 3))
    {
        if (ebP->time == 0)
        {
            rnd = (int)(16.0f * (-rand() / -2.1474836E9f)) & 0xF;
            
            if (fwP->br_mde0 != TY_BR0_PINCH) 
            {
                prmP = (float*)&SetPrm[0];
            } 
            else
            {
                prmP = (float*)&SetPrm[1];
            }
            
            ebP->time = *prmP++ + rnd;
            
            sys->ef.flg = 1;
            
            sys->ef.id = 303;
            
            sys->ef.ax = 0;
            sys->ef.ay = ewP->ay + (rnd * 1024);
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = (rnd & 0x3) + 4;
            
            *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[18].mtx[12];
            
            sys->ef.py = bhGetGroundPosition((NJS_POINT3*)&sys->ef.px);
            
            sys->ef.px += *prmP   * ((-rand() / -2.1474836E9f) - 0.5f);
            sys->ef.pz += *prmP++ * ((-rand() / -2.1474836E9f) - 0.5f);
            
            sys->ef.sx = sys->ef.sx = sys->ef.sz = 0.5f + (*prmP * (-rand() / -2.1474836E9f)); // maybe they meant to assign to sy as well?
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        else
        {
            ebP->time--;
        }
    }
}

// 100% matching!
static void bhEne19_ClawReset(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_CNK_OBJECT* objP;
    NJS_POINT3* posP;

    objP = ewP->mlwP->objP;
    posP = fwP->ClwPos;

    *(NJS_POINT3*)objP[10].pos = *posP++;
    *(NJS_POINT3*)objP[11].pos = *posP++;
    *(NJS_POINT3*)objP[12].pos = *posP++;
    *(NJS_POINT3*)objP[13].pos = *posP++;
}

// 100% matching!
static void bhEne19_SoundSet(BH_PWORK* ewP, FW_WORK* fwP)
{
    int SndTbl[20] =  
	{
		    0, 74496,  8961, 16786178, 16851715, 16851716, 74501, 74502, 74503, 74504, 
		74505, 74506, 74507,    74508,    74509,    74510, 74511, 74512, 74513, 74514
	};
    int snd_no;      
    int obj;        
    int sts;         
    int i;          
    int obj_a, obj_b;    
	static const NJS_POINT3 WlkOff = {  0.0f, -1.5f,  0.0f };
	static const int EffTbl[15] = {  4, 17, 16, 15, 14, 23, 24,  1, 19, 20,  6,  7,  8,  9,  2 };

    snd_no = fwP->snd_no;
    
    if (snd_no != 0) 
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->px, SndTbl[snd_no]);
        
        fwP->snd_no = 0;
    }

    switch (SndTbl[snd_no]) 
    {
    case 74496:
        sts = fwP->status;
        
        if ((sts & 0x8)) 
        {
            sts ^= 0x30000;
        }
        
        if ((sts & 0x10000)) 
        {
            sts = 0x18;
        } 
        else if ((sts & 0x20000)) 
        {
            sts = 0x14;
        } 
        else 
        {
            sts = 0;
        }

        if (sts != 0) 
        {
            njCalcPoint(&ewP->mlwP->owP[sts].mtx, &WlkOff, (NJS_POINT3*)&sys->ef.px);
            
            sys->ef.flg = 1;
            
            sys->ef.id = 305;
            
            sys->ef.ay = ewP->ay + 10922;
            sys->ef.ax = 16384;
            
            sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
            
            sys->ef.mdlver = 0;
            
            sys->ef.flr_no = 0;
            
            sys->ef.type = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    case 74501:
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
    
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
    
        for (i = 0; i < 15; i++)
        {
            sys->ef.ax = 0;
            sys->ef.ay = ewP->ay + (i * 4369);
            
            sys->ef.type = i & 0x3;
        
            *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[EffTbl[i]].mtx[12];
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    case 74502:
    {
        int sts; 

        sts = fwP->status;
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
        
        sys->ef.flr_no = 0;

        if ((sts & 0x8)) 
        {
            obj_a = 19;
            obj_b = 9;
        } 
        else 
        {
            obj_a = 23;
            obj_b = 17;
        }
        
        sys->ef.type = 2;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[obj_a].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);

        sys->ef.type = 1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[obj_b].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        break;
    }
    }
}

// 100% matching!
static int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP)
{
	unsigned short* atrP;

    atrP = ewP->mnwP[ewP->mtn_no].atrP;
  
    return (atrP != NULL) ? atrP[ewP->frm_no / 65536] : 0;
}

// 100% matching!
static int bhEne19_PlySetDamage(BH_PWORK* plP, FW_WORK* fwP, int dmg_mod)
{
    static const int PlyDmgTbl[4] = { 30, 40, 40, 50 };

    if ((!(fwP->ply_act.p_status & 0x1)) && (!(fwP->status & 0x800)))
    {
        plP->flg |=  0x10004;
        plP->flg &= ~0x40000;
        
        plP->mode0 = 5;
        plP->mode1 = 0;
        plP->mode2 = 0;
        plP->mode3 = 0;
        
        plP->hp -= PlyDmgTbl[dmg_mod];
        
        if ((plP->hp < 0) && (dmg_mod == 0)) 
        {
            dmg_mod = 1;
        }
        
        plP->stflg |= 0x40000;
        plP->stflg |= 0x4000;
        
        fwP->ply_act.p_act_flg =  0;
        fwP->ply_act.p_status  =  1;
        fwP->ply_act.p_act_now = -1;
        
        fwP->ply_mde        = 0;
        fwP->ply_act.p_mode = dmg_mod;
        
        if (((fwP->dir_dlt / 16384) & 0x1)) 
        {
            fwP->ply_act.p_status |= 0x2;
        }
        
        StartVibrationEx(1, 11);
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static void bhEne19_PlyMoveMain(BH_PWORK* plP, FW_WORK* fwP)
{
    int* stsP;     
    int act;       
    ATR_WORK* htP; 

    stsP = &fwP->ply_act.p_status;
    
    act = -1;
    
    htP = bhCheckFloorEnemy(plP->flr_no, plP->px, plP->pz);
    
    *stsP &= ~0x38;
    
    if ((htP != NULL) && (htP->prm0 == 19)) 
    {
        if (htP->prm1 == 0) 
        {
            *stsP |= 0x8;
        } 
        else if (htP->prm1 == 1) 
        {
            *stsP |= 0x10;
        } 
        else if (htP->prm1 == 6) 
        {
            *stsP |= 0x20;
        }
    }
    
    if ((*stsP & 0x1))
    {
        switch (fwP->ply_act.p_mode) 
        {
        case 0:
            if ((*stsP & 0x2))
            {
                act = 13;
            }
            else
            { 
                act = 14;
            }
            
            fwP->ply_act.p_mode = 8;
            break;
        case 1:
        case 2:
            if ((*stsP & 0x2)) 
            {
                act = 2;
            }
            else 
            { 
                act = 1;
            }
            
            fwP->ply_act.p_mode = 4;
            break;
        case 3:
            if ((*stsP & 0x2)) 
            {
                act = 11;
            }
            else 
            { 
                act = 12; 
            }
            
            fwP->ply_act.p_mode = 5;
            break;
        case 4:
            if (fwP->trw_spd > 0.8f) 
            {
                plP->flg |=  0x4000;
            } 
            else 
            {
                plP->flg &= ~0x4000;
            }
            
            if ((*stsP & 0x20)) 
            {
                fwP->ply_act.p_act_flg &= ~0x7;
                
                if (!(*stsP & 0x2)) 
                {
                    act = 15;
                }
                else 
                { 
                    act = 16;
                }
                
                fwP->ply_act.p_mode = 8;
            } 
            else if ((*stsP & 0x10))
            {
                if ((*stsP & 0x2)) 
                {
                    act = 6;
                }
                else 
                {
                    act = 5;
                }
            }
            else if (plp->hp >= 0) 
            {
                if ((*stsP & 0x2))
                {
                    act = 4;
                }
                else 
                { 
                    act = 3;
                }
            } 
            else
            {
                if ((*stsP & 0x2)) 
                {
                    act = 10;
                }
                else 
                { 
                    act = 9;
                }
            }
            
            break;
        case 5:
            if ((*stsP & 0x20)) 
            {
                fwP->ply_act.p_act_flg &= ~0x7;
                
                if (!(*stsP & 0x2)) 
                {
                    act = 15;
                }
                else 
                { 
                    act = 16;
                }
                
                fwP->ply_act.p_mode = 8;
            } 
            else if ((*stsP & 0x10)) 
            {
                if (!(*stsP & 0x2)) 
                {
                    act = 6;
                }
                else 
                { 
                    act = 5;
                }
            } 
            else if (plp->hp >= 0) 
            {
                if (!(*stsP & 0x2)) 
                {
                    act = 4;
                }
                else 
                { 
                    act = 3;
                }
            } 
            else 
            {
                if (!(*stsP & 0x2)) 
                {
                    act = 10;
                }
                else 
                { 
                    act = 9;
                }
            }
            
            break;
        case 6:
        case 7:
        case 8:
            break;
        }
    }
    
    if ((*stsP & 0x11)) 
    {
        if (act != -1) 
        {
            bhEne_PlyActionChange(plP, &fwP->ply_act, act);
        }
        
        bhEne_PlyActionMain(plP, &fwP->ply_act);
    }
}

// 100% matching!
static void bhEne19_PlyDmg042(BH_PWORK* plP, FW_WORK* fwP)
{    
    int dir;   
    float spd; 
    int dlt;  
    int obj;  
	static const int EffTbl[4] = { 20,  9, 16, 13 };

    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0) 
    {
        CallPlayerVoice(1026);
    }
    
    spd = fwP->trw_spd; 
    dir = fwP->trw_dir;
    
    if (spd > 0)
    {
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.075f;
    }
    
    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0)
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 16;
    }
    
    if (fwP->ply_act.p_mtn_rte > 26214) 
    {
        obj = EffTbl[fwP->ply_act.p_act_frm & 0x3];
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[obj].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
}

// 100% matching!
static void bhEne19_PlyDmg043(BH_PWORK* plP, FW_WORK* fwP)
{
    bhEne19_PlyDmg042(plP, fwP);
    
    if ((fwP->ply_act.p_mtn_rte > 26214) && ((fwP->ply_act.p_act_frm & 0x1))) 
    {
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[1].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
}

// 100% matching!
static void bhEne19_PlyDmg044(BH_PWORK* plP, FW_WORK* fwP)
{
    if (fwP->ply_act.p_act_frm < 18)
    {
        plP->flg |=  0xC0000;
    }
    else if (fwP->ply_act.p_act_frm <= 40)
    {
        plP->flg &= ~0x80000;
    }
    else
    {
        plP->flg |=  0xC0000;
    }
	
    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg045(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_act_frm >= 11)
    {
        plP->flg |=  0x40000;
        plP->flg &= ~0x80000;
    }

    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg046_047(BH_PWORK* plP, FW_WORK* fwP)
{
	bhEne19_PlyDmgDie(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg050_051(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1025);
    }

    bhEne19_PlyDmgDie(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg052_053(BH_PWORK* plP, FW_WORK* fwP)
{
    int dir;      
    float spd;    
    ATR_WORK* htP; 
    int i;        
    int dlt;      
    
    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1026);
        
        fwP->bnd_tim = 0;
    }

    dir = fwP->trw_dir;
    
    if (fwP->trw_spd > 0) 
    {
        spd = fwP->trw_spd;
        
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.07f;
    }
    
    if (fwP->bnd_tim == 0) 
    {
        htP = bhCheckWallRefAngle((NJS_POINT3*)&plP->px, 0, plP->ar, plP->ah, &fwP->trw_dir);
        
        if (htP != NULL) 
        {
            static const int EffTbl[4] = {  2,  1, 18, 14 };
            
            fwP->bnd_tim = 1;
                
            fwP->trw_spd *= 0.25f;
                
            sys->ef.flg = 1;
                
            sys->ef.id = 305;
                
            sys->ef.ay = fwP->ewP->ay + 10922;
            sys->ef.ax = 0;
                
            sys->ef.sx = sys->ef.sy = 1.0f;
                
            sys->ef.mdlver = 0;
                
            sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
            
            for (i = 0; (unsigned int)i < 4; i++) 
            {
                *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[EffTbl[i]].mtx[12];
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            if (fwP->ewP->type == 1)
            {
                bhSetRapEff(310, &fwP->e0aP[2], 8);
            }
                
            fwP->snd_no = 9;
        }
    }
    
    if (fwP->ply_act.p_mtn_rte <= 58982) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0) 
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 8;
    }
    
    if (fwP->ply_act.p_act_frm == 18) 
    {
        static const int EffTbl[4] = { 20,  9, 16, 13 };
        int i; 
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        for (i = 0; (unsigned int)i < 4; i++) 
        {
            *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[EffTbl[i]].mtx[12];
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
    }
}

// 100% matching!
static void bhEne19_PlyDmg117_118(BH_PWORK* plP, FW_WORK* fwP)
{
    int dir;   
    float spd; 
    int dlt;   
    int obj;  
	static const int EffTbl[2] = { 20, 16 };

    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1026);
    }
    
    spd = fwP->trw_spd;
    dir = fwP->trw_dir;
    
    if (spd > 0) 
    {
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.1f;
    }
    
    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0) 
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 32;
    }
    
    if ((fwP->ply_act.p_mtn_rte < 32768) && ((fwP->ply_act.p_act_frm & 0x1)))
    {
        obj = EffTbl[(fwP->ply_act.p_act_frm & 0x2) / 2];
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[obj].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmgDie(BH_PWORK* plP, FW_WORK* fwP)
{
	PAW_WORK* pawP;

	pawP = &fwP->ply_act;

	if (pawP->p_mtn_rte > 32768)
    {
        if (!(plP->flg & 0x2))
        {
            plP->flg |= 0x2;

            plP->flg   &= ~0x10004;
            plP->stflg &= ~0x10000;

            plP->mode0 = 6;
            plP->mode1 = 0;
            plP->mode2 = 0;
            plP->mode3 = 0;
        }
    }

    if (pawP->p_mtn_rte >= 65536)
    {
        fwP->ply_act.p_status &= ~0x1;

        plP->mtn_add = 0;
    }
}

// 100% matching!
static void bhEne19_PlyDmgRtn(BH_PWORK* plP, FW_WORK* fwP)
{
    if (fwP->ply_act.p_mtn_rte >= 65536)
    {
        plP->mnwP = plP->mnwPb;
        
        plP->flg &= ~0x10004;
        
        plP->stflg &= ~0x10000; 
        plP->stflg &= ~0x4000;
            
        plP->flg &= ~0x4000;
        
        plP->stflg &= ~0x40000;
        
        plP->mode0 = 1;
        plP->mode1 = 0;
        plP->mode2 = 0;
        plP->mode3 = 0;
        
        fwP->ply_act.p_status &= ~0x1;
    }
}

// 100% matching!
static void bhEne19_PlyDmgFal(BH_PWORK* plP, FW_WORK* fwP)
{
    PAW_WORK* pawP; 
    PF_WORK* pfP;  
    int dlt;        
    int dir;       
	float spd;     
	static const PF_WORK PlyFal[3] = 
	{
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.0f, -0.065333336f, 0.0f }, 0.98f, 50.0f, 0                               
		},
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.3f,  0.065333337f, 0.0f }, 0.75f, 50.0f, 1                               
		},
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.0f, -0.065333336f, 0.0f }, 0.98f, 25.0f, 0                               
		}
	};
    
    pfP  = &PlyFal[fwP->ewP->type];
    pawP = &fwP->ply_act;

    switch (fwP->ply_mde) 
    {          
    case 0:
        plP->flg |=  0x2;
        plP->flg &= ~0x118;
        
        plP->stflg |= 0x8;
        
        fwP->wnd_spd = pfP->vct_spd;
        
        fwP->ply_mde++;
    case 1:
        if (fwP->tgt_dst > 32.0f)
        {
            plP->flg   &= ~0x10004;
            plP->stflg &= ~0x10000;
            
            plP->mode0 = 6;
            plP->mode1 = 0;
            plP->mode2 = 0;
            plP->mode3 = 0;
            
            fwP->ply_mde++;
        }
    case 2:
        if (pawP->p_mtn_rte <= 49152) 
        {
            dlt = fwP->trw_dir - plP->ay;
            
            if (njCos(dlt) < 0) 
            {
                dlt += 32768;
            }
            
            plP->ay += (short)dlt / 16;
        }
        
        if (pfP->mode != 0) 
        {
            if ((pawP->p_status & 0x2)) 
            {
                plP->ax += 1820;
            } 
            else 
            {
                plP->ax -= 910;
            }
        }
        
        if (fwP->tgt_dst < 500.0f) 
        {
            spd = fwP->trw_spd;
            dir = fwP->trw_dir;
            
            plP->px += spd * -njSin(dir);
            plp->pz += spd * -njCos(dir); 
            
            njAddVector((NJS_VECTOR*)&plP->px, &fwP->wnd_spd);
            
            fwP->trw_spd = spd * pfP->acl_rte;
            
            njAddVector(&fwP->wnd_spd, &pfP->vct_acl);
        } 
        else 
        {
            pawP->p_status &= ~0x1;
            
            plP->ax = 0;
        }
        
        break;
    }
    
    if (pawP->p_mtn_rte >= 65536)
    {
        plP->mtn_add = 0;
    }
}

// 100% matching!
static void bhEne_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num)
{
    pawP->act_tblP = act_tblP;
    
    pawP->tbl_num = tbl_num;
    
    pawP->p_act_now = -1;
    
    pawP->ene_mnwP = ewP->mnwP;
    pawP->p_paramP = ewP->exp0;
}

// 100% matching!
static void bhEne_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP)
{
    if ((pawP->p_act_flg & 0x7) == 2)
    {
        pawP->p_act_flg &= ~0x2;
        
        bhEne_PlyActionChange(plP, pawP, pawP->p_act_jmp);
    }
    
    pawP->p_mtn_rte = plP->frm_no / (pawP->p_frm_num - 1);
    
    if (pawP->p_prgP != NULL) 
    {
        pawP->p_prgP(plP, pawP->p_paramP);
    }
    
    pawP->p_act_frm = plP->frm_no / 65536;
    
    if (pawP->p_act_frm == pawP->p_chg_frm) 
    {
        pawP->p_act_flg &= ~0x1;
    }
}

// 100% matching!
static int bhEne_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no)
{
    ACT_TBL_WORK* paP;
    
    paP = &pawP->act_tblP[act_no];
    
    if ((!(pawP->p_act_flg & 0x7)) && (pawP->p_act_now != act_no))
    {
        pawP->p_prgP = paP->prgP;
        
        pawP->p_act_now = act_no;
        pawP->p_act_flg = 1;
        
        if (paP->mtn_no != -1)
        {
            plP->mnwP = pawP->ene_mnwP;
            
            plP->mtn_no = paP->mtn_no;
            plP->frm_no = paP->frm_no * 65536;
            
            plP->hokan_count = paP->hkn_cnt;
            plP->hokan_rate  = paP->hkn_lvl * (65536.0 / 255.0);
            
            plP->mtn_add = 65536;
            plP->mtn_md  = (unsigned short)paP->flag;
                
            pawP->p_frm_num = plP->mnwP[paP->mtn_no].frm_num;
            
            pawP->p_act_frm = paP->frm_no;
            pawP->p_act_jmp = paP->act_jmp;
            
            if (pawP->p_act_jmp != -1)
            {
                pawP->p_act_flg |= 0x2;
            }
            
            if (paP->chg_frm != 0xFF) 
            {
                pawP->p_chg_frm = paP->chg_frm;
            } 
            else 
            {
                pawP->p_chg_frm = pawP->p_frm_num - 1;
            }
        }
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static int bhEne_CalcCombRate(BH_PWORK* ewP, COMBWEP_WORK* cwP)
{
	int cmb_lvl;

    cmb_lvl = 0;
    
    cwP += ewP->wpnr_no;

    if (cwP->crit != 0)
    {
        cmb_lvl = (ewP->comb_pnt * 16) / cwP->crit;
    }
    else
    {
        cmb_lvl = 0;
    }

    if ((cmb_lvl & ~0xF))
    {
        cmb_lvl = 15;
    }

    return cmb_lvl;
}

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl0(BH_PWORK* ewP, FW_WORK* fwP)
{
	TY_DMG_MODE dmg_lvl; 
    int cmb_lvl;         
    int* flgP;          

	flgP = &fwP->dmg_flg;

    cmb_lvl = bhEne_CalcCombRate(ewP, En19CombWepTbl);
    
    if (ewP->comb_pnt == 0) 
    {
        *flgP &= ~0x6;
    }

    if (ewP->hp < 0)
    {
        dmg_lvl = TY_DMG_LVL4;
    }
    else if ((ewP->comb_flg & 0x1)) 
    {
        dmg_lvl = TY_DMG_LVL2;
    }
    else if ((cmb_lvl >= 12) && (!(*flgP & 0x4)))
    {
		fwP->dmg_flg |= 0x4;

		dmg_lvl = TY_DMG_LVL1;
    }
    else if ((cmb_lvl >= 8) && (!(*flgP & 0x2))) 
    {
		fwP->dmg_flg |= 0x2;

		dmg_lvl = TY_DMG_LVL0;
    }
	else 
	{
		dmg_lvl = TY_DMG_NON;
	}

    return dmg_lvl;
}

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl1(BH_PWORK* ewP, FW_WORK* fwP)
{
	TY_DMG_MODE dmg_lvl;

    bhEne_CalcCombRate(ewP, En19CombWepTbl);

    if ((ewP->hp < 0) && (!(fwP->dmg_flg & 0x20))) 
	{
        fwP->dmg_flg |= 0x20;

        dmg_lvl = TY_DMG_LVL4;
    } 
	else if ((ewP->hp < ((fwP->hp_bak * 50) / 100)) && (!(fwP->dmg_flg & 0x8))) 
	{
        fwP->dmg_flg |= 0x8;

        dmg_lvl = TY_DMG_LVL2;
    } 
	else if ((ewP->comb_flg & 0x1)) 
	{
        dmg_lvl = TY_DMG_LVL0;
    } 
	else 
	{
        dmg_lvl = TY_DMG_NON;
    }

    if ((fwP->ct_pinch == 0) && (!(fwP->dmg_flg & 0x40)))
	{
        fwP->dmg_flg |= 0x40;

        dmg_lvl = TY_DMG_SPECIAL;
    }

    return dmg_lvl;
}

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl2(BH_PWORK* ewP, FW_WORK* fwP)
{
    TY_DMG_MODE dmg_lvl; 
    int cmb_lvl;         
    int* flgP;          

    flgP = &fwP->dmg_flg;
    
	cmb_lvl = bhEne_CalcCombRate(ewP, En19CombWepTbl);
    
	if (ewP->comb_pnt == 0) 
	{
        *flgP &= ~0x2;
    }

    if (ewP->hp < 0)
	{
        dmg_lvl = TY_DMG_LVL4;
    }
    else if ((ewP->comb_flg & 0x1)) 
	{
        dmg_lvl = TY_DMG_LVL1;
    }
    else if ((cmb_lvl >= 10) && (!(*flgP & 0x2))) 
	{
        fwP->dmg_flg |= 0x2;

        dmg_lvl = TY_DMG_LVL0;
    }
    else 
	{
        dmg_lvl = TY_DMG_NON;
    }

    return dmg_lvl;
}

// 100% matching!
static R0_WK* bhEne19_SetLeftClaw(ML_WORK* mlwP, TY_OBJ_MODE tgt_bas, TY_OBJ_MODE tgt_obj)
{
	PRM_WRK prm;
	NJS_CNK_OBJECT* objP;

    objP = &mlwP->objP[tgt_obj];

    prm.mtxP = &mlwP->owP[tgt_bas].mtx;
    prm.texP = mlwP->texP;
    prm.mdlP = (NJS_MODEL*)objP->model;

    prm.pos[0] = -objP->pos[0];
    prm.pos[1] =  objP->pos[1];
    prm.pos[2] =  objP->pos[2];

    prm.ang[0] = objP->ang[0];
    prm.ang[1] = 32768 - objP->ang[1];
    prm.ang[2] = -objP->ang[2];

    return (R0_WK*)((bhSetRapEff(312, &prm, 9))->free4);
}

// 100% matching!
static void bhEne19_SetClawPlane(BH_PWORK* ewP, NJS_MATRIX* mtxP, int col, int tim, float src_x, float dst_x)
{
	EFFPRM_WORK Dat307;

	Dat307.src.x = src_x;
    Dat307.src.y = Dat307.src.z = 0;

    Dat307.dst.x = dst_x;
    Dat307.dst.y = Dat307.dst.z = 0;

    Dat307.frm_inc = 0.125f;

    Dat307.tim = tim;

    Dat307.texP = ewP->mlwP->texP;

    Dat307.tex_id = 4;

    Dat307.col = col;

    Dat307.mtxP = mtxP;
	
    bhSetRapEff(307, &Dat307, 12);
}
