#include "../../../ps2/veronica/prog/en19.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/en29.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"

#pragma optimization_level 4

// ENEMY: Tentacle 

static void (*bhEne29_Mode0[6])(BH_PWORK*) = 
{
	bhEne29_Init,
	bhEne29_Move,
	bhEne29_Damage,
	bhEne29_Die,
	NULL,
	bhEne29_Event
};
static void (*bhEne29_BrainType[4])(BH_PWORK*) = 
{
	bhEne29_Br00,
	bhEne29_Br00,
	bhEne29_Br01,
	bhEne29_Br01
};

EA_WORK En29ActTbl[40] = 
{
    {   256,  0, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {   514,  2, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {   768,  0, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  1541,  5, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  1799,  7, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  2053,  5, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  2826, 10, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  3084, 12, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  3338, 10, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  4111, 15, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  4369, 17, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  4623, 15, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  7680,  0, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7685,  5, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7690, 10, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7695, 15, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    { 65280,  0, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65281,  1, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65282,  2, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65283,  3, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65284,  4, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65285,  5, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65286,  6, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65287,  7, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65288,  8, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65289,  9, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65290, 10, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65291, 11, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65292, 12, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65293, 13, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65294, 14, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65295, 15, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65296, 16, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65297, 17, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65298, 18, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65299, 19, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65300, 20, 0, 0,  8, 1.0f,    0, (void*)bhEne29_Mv20 },
    { 65301, 21, 0, 0,  8, 1.0f,    0, (void*)bhEne29_Mv20 },
    { 65302, 22, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65303, 23, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 }
};

static COMBWEP_WORK En29CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 },   0, 0 },
    {  0, {  0,  0,  0 },   0, 0 },
    { 32, {  8,  0,  0 }, 160, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    {  0, {  0,  0,  0 },  30, 0 },
    { 32, {  4,  3,  2 },  30, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  60, 0 },
    { 32, { 16, 15, 14 },  80, 0 },
    { 32, {  4,  3,  2 },  30, 0 },
    { 32, {  9,  8,  7 },  90, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    { 24, { 11, 10,  9 },  60, 0 },
    {  1, {  1,  1,  1 },   0, 0 }
};
static COMBJOINT_WORK En29CombJointTbl[21] = { 0 };

ET_WORK TypPrm[4] = 
{
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY11, 6.5f, TC_OBJ_BODY17, 6.5f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY11, 6.0f, TC_OBJ_BODY16, 7.9f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY08, 9.0f, TC_OBJ_BODY16, 8.0f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY08, 9.0f, TC_OBJ_BODY16, 8.0f }
};
int E29EffTbl[9][4] = 
{
    { 0,      3,  0,   0 },
    { 0,      4,  0,   0 },
    { 0,      5,  0,   0 },
    { 1,      3,  0,   0 },
    { 1,      4,  0,   0 },
    { 1,      5,  0,   0 },
    { 2,      1,  2, 306 },
    { 3,      2,  5, 301 },
    { 4, 131072, 40, 298 }  
};

static const char En29FlpTbl[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
static const CPCL Ene29CapColTbl[15] = 
{
    {  1,  4, 20 },
    {  4,  6, 20 },
    {  6,  8, 18 },
    {  8, 10, 18 },
    {  9, 10, 16 },
    { 10, 11, 16 },
    { 11, 12, 14 },
    { 12, 13, 14 },
    { 13, 14, 12 },
    { 14, 15, 12 },
    { 15, 16, 10 },
    { 16, 17, 10 },
    { 17, 18,  8 },
    { 18, 19,  8 },
    {  0,  0,  0 }
};
static const ACT_TBL_WORK En29PlyActTbl[2] = 
{
    { 30, 0, 0, 8, 255, -1, 0x20, (void*)bhEne29_PlyDmg117 },
    { 31, 0, 0, 8, 255, -1, 0x20, (void*)bhEne29_PlyDmg118 }
};
static const ETTY_WORK En29DmgDat = { 0x8021, 29, 8, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } };
static const DS_WORK E29DmgSet[5] = 
{
    { TC_OBJ_BODY00, TC_OBJ_BODY03, 2.0f, 16 },
    { TC_OBJ_BODY04, TC_OBJ_BODY07, 2.0f,  0 },
    { TC_OBJ_BODY08, TC_OBJ_BODY11, 2.0f, 16 },
    { TC_OBJ_BODY12, TC_OBJ_BODY15, 2.0f, 16 },
    { TC_OBJ_BODY16, TC_OBJ_BODY18, 2.0f, 16 }
};
/* unused below */
/*OFF_TBL_WORK E29OffTbl[20];
TC_BR_MODE0 InitBrnMde[4];*/

// 100% matching!
void bhEne29(BH_PWORK* ewP)
{
    if (ewP->type != 8)
    {
        bhEne29_Mode0[ewP->mode0](ewP);

        if (ewP->mode0 != TC_PRG_INIT)
        {
            ((en29_freework*)ewP->exp0)->mode0_bak = (unsigned char)ewP->mode0;
        }
    }
}

// 100% matching!
static void bhEne29_Init(BH_PWORK* ewP)
{
    en29_freework* fwP; 
    ATR_WORK* htP;      

    fwP = (en29_freework*)ewP->exp0;
    
    if (fwP != NULL) 
    {
        npSetMemory((unsigned char*)&fwP->status, 252, 0);
    }
    else
    {
        ewP->exp0 = bhEne_CallocWork(sizeof(en29_freework), 32);
        
        htP = &sys->mwalp[sys->mwal_n++];
        
        htP->flg |= 0x81;   
        
        htP->type = 1;     
        
        htP->flr_no = 0;    
        
        htP->attr = 2;     
        
        htP->prm0 = htP->prm1 = htP->prm2 = htP->prm3 = 0;      
        
        ewP->exp1 = (unsigned char*)htP;

        fwP = (en29_freework*)ewP->exp0;
        
        SetDmgEne(ewP, fwP, E29DmgSet, 5);
    }
    
    fwP = (en29_freework*)ewP->exp0;
    
    ewP->mode0 = 1;
    ewP->mode1 = 0;
    ewP->mode2 = 0;
    ewP->mode3 = 0;
    
    ewP->ar = 3.0f;
    ewP->ah = 4.0f;
    ewP->aw = 0.0f;
    ewP->ad = 0.0f;
    
    ewP->car = 6.0f;
    ewP->cah = 4.0f;
    
    ewP->hp = 160;
    
    ewP->cpcl = Ene29CapColTbl;
    
    ewP->mtn_no = 0;
    ewP->frm_no = 0;
    
    ewP->hokan_count = 0;
    ewP->hokan_rate  = 0;
    
    ewP->mtn_add = 0;
    ewP->mtn_md  = 0;
    ewP->mtn_tp  = (unsigned char*)En29FlpTbl;
    
    ewP->flg |=  0x158;
    ewP->flg &= ~0x2;
    
    ewP->flg2 |= 0x1;
    
    ewP->clp_jno[0] =  9;
    ewP->clp_jno[1] = 15;
    ewP->clp_jno[2] = 19;
    ewP->clp_jno[3] = -1;
    
    ewP->mdflg &= ~0x20;
    
    ewP->lok_jno = 16;
    
    fwP->hit_tabP = (ATR_WORK*)ewP->exp1;

    {
    ET_WORK* etP;
    ATR_WORK* htP;  
    NJS_POINT3* szP;    
	O_WRK* oP;   
    
    etP = &TypPrm[ewP->type];
        
    fwP->bas_obj = etP->bas_obj;   
    fwP->atr_obj = etP->atr_obj;  
        
    fwP->atk_obj0 = etP->atk_obj0; 
    fwP->atk_obj1 = etP->atk_obj1; 
        
    fwP->atk_rng0 = etP->atk_rng0;            
    fwP->atk_rng1 = etP->atk_rng1;         
    
    htP = fwP->hit_tabP;
        
    htP->flg |= 0x1;      
        
    szP = &etP->atr_siz;
        
    htP->w = szP->x;
    htP->h = szP->y;
    htP->d = szP->z; 
    
    *(NJS_POINT3*)&htP->px = *(NJS_POINT3*)&ewP->px;
    
    if (!(ewP->flg & 0x800)) 
    {
        ewP->flg |= 0x800;
        
        oP = rySetShadow(ewP, 1, 3, 5, 2.0f, 2.0f);
        
        fwP->sdw_owkP = oP;
        
        oP->mdlver = 1;
        
        oP->type = 1;
        
        oP->sy = 6.0f;
    }
    }
    
    bhEne29_ActionInit(&fwP->ene_act, En29ActTbl, 40);
    bhEne29_PlyActionInit(ewP, &fwP->ply_act, En29PlyActTbl, 2);
    
    sys->rm_flg &= ~0x3;
}

// 100% matching!
static void bhEne29_Move(BH_PWORK* ewP)
{
    en29_freework* fwP;   
    
    fwP = (en29_freework*)ewP->exp0;

    fwP->hit_tabP->flg   |=  0x1;
    fwP->sdw_owkP->stflg &= ~0x1000000;

    if (!(fwP->status & 0x40)) 
    {
        fwP->status |= 0x40;
        
        fwP->br_mde0 = TC_BR0_NORMAL;
        fwP->br_mde1 = TC_BR1_FIRST;

        if ((ewP->type == 2) && (!(sys->rm_flg & 0x1))) 
        {
            fwP->br_mde0 = TC_BR0_WAIT;
        }
        
        if ((ewP->type == 3) && (!(sys->rm_flg & 0x2))) 
        {
            fwP->br_mde0 = TC_BR0_WAIT;
        }
    }

    bhEne29_DmgCheck(ewP, fwP);
    
    bhEne29_BrainType[ewP->type](ewP);

    if (!(fwP->status & 0x10)) 
    {
        bhEne29_ActionMain(ewP, &fwP->ene_act);
    }
    
    { 
    en29_freework* fwP; // no fucking clue

    fwP = (en29_freework*)ewP->exp0;

    bhEne29_CalcEnemy(ewP, fwP);
    }

    if ((fwP->status & 0x20)) 
    {
        fwP->hit_tabP->flg &= ~0x1;
    }

    bhEne29_PlyMoveMain(plp, fwP);
}

// 100% matching!
static void bhEne29_Die()
{
	
}

// 100% matching!
static void bhEne29_Damage()
{

}

// 100% matching!
static void bhEne29_Event(BH_PWORK* ewP)
{
	en29_freework* fwP;

	fwP = (en29_freework*)ewP->exp0;

	fwP->hit_tabP->flg &= ~0x1;

    fwP->sdw_owkP->stflg |= 0x1000000;

    bhEne_Event(ewP);

    bhSetMotion(ewP, (int)ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);

    bhEne29_CalcEnemy(ewP, (en29_freework*)ewP->exp0);
}

// 100% matching!
static void bhEne29_Br00(BH_PWORK* ewP)
{
    en29_freework* fwP; 
    eaw_typ* eawP;     
    int* stsP;        
    int typ;          
    int sts;           
    TC_BR_MODE0* br0P;  
    TC_BR_MODE1* br1P; 
    TC_ACT_NO act;    
    int rte;          
	int lop;          

    fwP = (en29_freework*)ewP->exp0;
    
    eawP = &fwP->ene_act;
    stsP = &fwP->status;
    
    typ = (ewP->type != 0) ? 1 : 0;

    fwP->tgt_pos = *(NJS_POINT3*)&plp->px; 

    *stsP |= 0x1;

    bhEne29_TargetAnalyze(ewP, fwP);

    sts = *stsP;
    
    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;

    rte = eawP->mtn_rte;

    act = TC_ACT_ALL;
    
    lop = 0;
    
    do
    {
        if ((fwP->dmg_lvl != 0) && (*br0P != TC_BR0_DIE))
        {
            if (*br0P != TC_BR0_DAMAGE)
            {
                if (fwP->dmg_lvl < 3) 
                {
                    *br0P = TC_BR0_DAMAGE;
                }
                else 
                {
                    *br0P = TC_BR0_DIE;
                }
                
                *br1P = TC_BR1_FIRST;
            }
            else if (fwP->dmg_lvl >= 3)
            {
                *br0P = TC_BR0_DIE;
                *br1P = TC_BR1_FIRST;
            }
        }

        switch (*br0P)
        {
        case TC_BR0_NORMAL:
            if (fwP->br_tim > 0)
            {
                fwP->br_tim--;
                
                act = TC_ACT_000;
            }
            else if (((sts & 0x200)) && (!(plp->flg & 0x4)))
            {
                *br0P = TC_BR0_ATTACK;
                *br1P = TC_BR1_FIRST;
                
                lop = 1;
            }
            else
            {
                act = TC_ACT_000;
            }

            if ((act == TC_ACT_000) && (eawP->act_now == (typ * 5)))
            {
                act = TC_ACT_ALL;
            }
            
            break;
        case TC_BR0_ATTACK:
            switch (*br1P)
            {
            case TC_BR1_FIRST:
                *br1P = TC_BR1_LOOP0;
                
                act = TC_ACT_001;
                break;
            case TC_BR1_LOOP0:
                if (!(sts & 0x200))
                {
                    act = TC_ACT_022;
                    
                    *br1P = TC_BR1_LOOP1;
                }
                
                break;
            case TC_BR1_LOOP1:
                if (rte >= eawP->chg_rte)
                {
                    *br0P = TC_BR0_NORMAL;
                    
                    fwP->br_tim  = 0;
                }
                
                break;
            }
            
            break;
        case TC_BR0_DAMAGE:
            switch (*br1P)
            {
            case TC_BR1_FIRST:
                if (fwP->br_fir > 0)
                {
                    *br1P = TC_BR1_LOOP1;
                    
                    act = TC_ACT_003;
                }
                else
                {
                    if (fwP->dmg_lvl <= 1) 
                    {
                        act = TC_ACT_002;
                    }
                    else 
                    {
                        act = TC_ACT_003;
                    }
                    
                    *br1P = TC_BR1_LOOP0;
                }
                
                break;
            case TC_BR1_LOOP0:
                if (rte >= 32768)
                {
                    *br0P = TC_BR0_NORMAL;
                }
                
                break;
            case TC_BR1_LOOP1:
                if (fwP->br_fir <= 0)
                {
                    *br0P = TC_BR0_NORMAL;
                }
                
                break;
            }
            
            break;
        case TC_BR0_DIE:
            switch (*br1P)
            {
            case TC_BR1_FIRST:
                act = TC_ACT_004;
                
                *br1P = TC_BR1_LOOP0;
                break;
            case TC_BR1_LOOP0:
                if (rte >= eawP->chg_rte)
                {
                    ewP->flg |= 0x2;
                    
                    ewP->mtn_add = 0;
                    
                    *br1P = TC_BR1_LOOP1;
                }
                
                break;
            case TC_BR1_LOOP1:
                break;
            }
            
            break;
        }
    } while (lop-- != 0);

    if (act != TC_ACT_ALL)
    {
        if (act < TC_ACT_022) 
        {
            act += typ * 5;
        }
        else 
        {
            act += typ;
        }
        
        bhEne29_ActionChange(ewP, eawP, act);
    }
}

// 99.48% matching
static void bhEne29_Br01(BH_PWORK* ewP)
{
    en29_freework* fwP; 
    eaw_typ* eawP;     
    int* stsP;         
    int typ;           
    int sts;          
    TC_BR_MODE0* br0P;  
    TC_BR_MODE1* br1P;  
    TC_ACT_NO act;      
    int rte;           
	int lop;           

    fwP = (en29_freework*)ewP->exp0;
    
    eawP = &((en29_freework*)ewP->exp0)->ene_act;
    stsP = &((en29_freework*)ewP->exp0)->status;

    typ = (ewP->type == 2) ? 0 : 1;

    fwP->tgt_pos = *(NJS_POINT3*)&plp->px;

    *stsP |= 0x1;
    
    bhEne29_TargetAnalyze(ewP, fwP);
    
    rte = eawP->mtn_rte;
    sts = *stsP;

    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;

    act = TC_ACT_ALL; 
    
    lop = 0;

    do 
    {
        if ((fwP->dmg_lvl != 0) && (*br0P != TC_BR0_DIE)) 
        {
            if (*br0P != TC_BR0_DAMAGE) 
            {
                if (fwP->dmg_lvl < 3) 
                {
                    *br0P = TC_BR0_DAMAGE;
                }
                else 
                {
                    *br0P = TC_BR0_DIE;
                }
                
                *br1P = TC_BR1_FIRST;
            }
            else if (fwP->dmg_lvl >= 3) 
            {
                *br0P = TC_BR0_DIE;
                *br1P = TC_BR1_FIRST;
            }
        }

        switch (*br0P)
        {
        case TC_BR0_NORMAL:
            if (fwP->br_tim > 0) 
            {
                fwP->br_tim--;
                
                act = TC_ACT_010;
            } 
            else if (((sts & 0x200)) && (!(plp->flg & 0x4)))
            {
                *br0P = TC_BR0_ATTACK;
                *br1P = TC_BR1_FIRST;
                
                lop = 1;
            }
            else
            {
                act = TC_ACT_010;
            }
            
            if ((act == TC_ACT_010) && (eawP->act_now == ((typ * 5) + 10))) 
            {
                act = TC_ACT_ALL;
            }
            
            break;
        case TC_BR0_ATTACK:
            switch (*br1P) 
            {
            case TC_BR1_FIRST:
                act = TC_ACT_011;
                
                *br1P = TC_BR1_LOOP0;
                break;
            case TC_BR1_LOOP0:
                if (!(sts & 0x200))
                {
                    *br1P = TC_BR1_LOOP1;
                    
                    fwP->br_tim = 48;
                }
                
                break;
            case TC_BR1_LOOP1:
                if (fwP->br_tim-- == 0) 
                {
                    *br0P = TC_BR0_NORMAL;
                    
                    fwP->br_tim = 16;
                }
                
                break;
            }
            
            break;
        case TC_BR0_DAMAGE:
            switch (*br1P)
            {
            case TC_BR1_FIRST:
                if (fwP->br_fir > 0) 
                {
                    act = TC_ACT_013;
                    
                    *br1P = TC_BR1_LOOP1;
                } 
                else
                {
                    if (fwP->dmg_lvl <= 1) 
                    {
                        act = TC_ACT_012;
                    }
                    else 
                    {
                        act = TC_ACT_013;
                    }
                    
                    *br1P = TC_BR1_LOOP0;
                }
                
                break;
            case TC_BR1_LOOP0:
                if (rte >= 32768) 
                {
                    *br0P = TC_BR0_NORMAL;
                }
                
                break;
            case TC_BR1_LOOP1:
                if (fwP->br_fir <= 0) 
                {
                    *br0P = TC_BR0_NORMAL;
                }
                
                break;
            }
            
            break;
        case TC_BR0_DIE:
            switch (*br1P) 
            {
            case TC_BR1_FIRST:
                act = TC_ACT_014;
                
                *br1P = TC_BR1_LOOP0;
                break;
            case TC_BR1_LOOP0:
                if (rte >= eawP->chg_rte) 
                {
                    ewP->flg |= 0x2;
                    
                    ewP->mtn_add = 0;
                    
                    *br1P = TC_BR1_LOOP1;
                }
                
                break;
            case TC_BR1_LOOP1:
                break;
            }
            
            break;
        case TC_BR0_WAIT:
            switch (*br1P) 
            {
            case TC_BR1_FIRST:
                act = TC_ACT_020;
                
                *br1P = TC_BR1_LOOP0;
                break;
            case TC_BR1_LOOP0:
                if (sys->rm_flg & (1 << typ)) 
                {
                    *br1P = TC_BR1_LOOP1;
                    *stsP &= ~0x10;
                } 
                else
                {
                    *stsP |= 0x10;
                }
                
                break;
            case TC_BR1_LOOP1:
                if (rte >= eawP->chg_rte) 
                {
                    *br0P = TC_BR0_NORMAL;
                }
                
                break;
            }
            
            break;
        }
    } while (lop-- != 0);

    if (act != TC_ACT_ALL) 
    {
        if (act < TC_ACT_020) 
        {
            act += typ * 5;
        }
        else 
        {
            act += typ;
        }
        
        bhEne29_ActionChange(ewP, eawP, act);
    }
}

// 100% matching!
static void bhEne29_Mv00(BH_PWORK* ewP, en29_freework* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne29_Mv01(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74498);
    }

    if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_Mv02(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }
}

// 100% matching!
static void bhEne29_Mv03(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }

    if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_Mv04(BH_PWORK* ewP, en29_freework* fwP, int count) // third parameter not present on DWARF
{
	if ((fwP->ene_act.mtn_rte < 65536) && (ChechPlayEnemySe(sys->enow, 74499) == 0))
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }
}

// 100% matching!
static void bhEne29_Mv20(BH_PWORK* ewP, en29_freework* fwP, int count) // third parameter not present on DWARF
{
	if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_ActionInit(eaw_typ* eawP, EA_WORK* act_tblP, int tbl_num)
{
	eawP->act_tblP = act_tblP;

	eawP->tbl_num = tbl_num;

	eawP->act_now = 30;
}

// 100% matching!
static EA_WORK* bhEne29_ActionSearch(eaw_typ* eawP, int act_nw, int act_no)
{
    EA_WORK* eaP; 
    int key;     
    int high, low, middle;    
	int val;      
    
    eaP = eawP->act_tblP;
    
    key = ((unsigned char)act_nw << 8) | ((unsigned char)act_no << 0);
    
    high = eawP->tbl_num;
    low  = 0;

    while (low <= high) 
    {
        middle = (low + high) / 2;
         
        val = eaP[middle].label;

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
            return &eaP[middle];
        }
    }
    
    return NULL;
}

// 100% matching!
static int bhEne29_ActionChange(BH_PWORK* ewP, eaw_typ* eawP, int act_dst)
{
	EA_WORK* eaP;
    
    if (((eaP = bhEne29_ActionSearch(eawP, eawP->act_now, act_dst)) == NULL) && (eawP->act_now != act_dst)) 
    {
        eaP = bhEne29_ActionSearch(eawP, -1, act_dst);
    }
    
    if (eaP != NULL) 
    {
        njMemCopy4(&eawP->b_act_flg, &eawP->act_flg, 7);
        
        eawP->b_mtn_md = ewP->mtn_md;
        
        eawP->act_flg = 0;
        
        eawP->prgP = eaP->prgP;
        
        eawP->act_cnt = 0;
        eawP->act_frm = eaP->frm_no;
        
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
        
        eawP->chg_rte = eaP->chg_rte * 65536.0f;
        
        eawP->act_now = act_dst;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static int bhEne29_ActionMain(BH_PWORK* ewP, eaw_typ* eawP)
{
	short* s16P;
    
    if (eawP->prgP != NULL) 
    {
        eawP->prgP(ewP, ewP->exp0, eawP->act_cnt++);
    }
    
    s16P = (short*)&eawP->act_frm;
    
    s16P[1] += bhSetMotion(ewP, (int)ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);
    s16P[0] =  ewP->frm_no / 65536;
    
    eawP->mtn_rte = ewP->frm_no / (ewP->mnwP[ewP->mtn_no].frm_num - 1);
    
    return 0;
}

// 100% matching!
static void bhEne29_TargetAnalyze(BH_PWORK* ewP, en29_freework* fwP)
{
    int* stsP;       
    NJS_POINT3* vP;  
    
    stsP = &fwP->status;

    if (((*stsP & 0x1)) && ((plp->hp < 0) || ((plp->flg & 0x2)))) 
    {
        *stsP |= 0x20;
    }

    vP = (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[8];
    
    fwP->bas_ax = 10430.381f * asinf(vP->y);
    fwP->bas_ay = 10430.381f * atan2f(vP->x, vP->z);

    {
    NJS_POINT3 dlt; 
    int ad;          
    
    dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12];
        
    njSubVector(&dlt, &fwP->tgt_pos);

    ad = (int)(10430.381f * atan2f(dlt.x, dlt.z)) - fwP->bas_ay;
        
    *stsP &= ~0xC00;
        
    if ((short)ad < 0) 
    {
        *stsP |= 0x800;
    } 
    else
    {
        *stsP |= 0x400;
    }
    }

    {
    int dlt;   
        
    dlt = (unsigned short)(plp->ay - fwP->bas_ay);
        
    if ((dlt & 0x8000)) 
    {
        dlt = (65536 - dlt) | 0x80000000;
    }
        
    fwP->dir_dlt = dlt;
    }

    *stsP &= ~0x200;

    {
    NJS_POINT3 dlt;
    float dst;      
    
    dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->atk_obj0].mtx[12];
        
    njSubVector(&dlt, &fwP->tgt_pos);

    vP = (NJS_POINT3*)&dlt.z;
        
    dst = (dlt.x * dlt.x) + (vP->x * vP->x);

    if (dst <= (fwP->atk_rng0 * fwP->atk_rng0)) 
    {
        *stsP |= 0x200;
    } 
    else 
    {
        dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->atk_obj1].mtx[12];
        
        njSubVector(&dlt, &fwP->tgt_pos);
        
        dst = (dlt.x * dlt.x) + (vP->x * vP->x);
        
        if (dst <= (fwP->atk_rng1 * fwP->atk_rng1))
        {
            *stsP |= 0x200;
        }
    }
    }
}

// 100% matching!
static void bhEne29_CalcEnemy(BH_PWORK* ewP, en29_freework* fwP)
{
	ATR_WORK* htP;

    bhCalcModel(ewP);

    CalcDmgEne(ewP, fwP);

    htP = fwP->hit_tabP;

    htP->px = ewP->mlwP->owP[fwP->atr_obj].mtx[12];
    htP->pz = ewP->mlwP->owP[fwP->atr_obj].mtx[14];
}

// 100% matching!
static void bhEne29_DmgCheck(BH_PWORK* ewP, en29_freework* fwP)
{
    static const DD_WRK DmgDat[21] = 
	{
		{ 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 3, 1, 4 }, { 0, 3, 1, 4 },
		{ 0, 3, 1, 4 }, { 0, 3, 1, 4 }, { 1, 4, 2, 5 }, { 0, 3, 1, 4 },
		{ 0, 3, 0, 4 }, { 0, 3, 1, 4 }, { 0, 3, 1, 4 }, { 1, 4, 2, 5 },
		{ 0, 3, 1, 4 }, { 2, 4, 2, 5 }, { 2, 4, 2, 5 }, { 0, 8, 1, 8 },
		{ 0, 6, 1, 6 }, { 2, 4, 2, 5 }, { 2, 5, 2, 5 }, { 1, 3, 2, 4 },
		{ 2, 5, 2, 5 }
	};
    int dmg_obj;
	DD_WRK* ddP; 

    CheckDmgEne(ewP, fwP);
    
    if ((ewP->flg & 0x4)) 
    {
        ewP->flg &= ~0x4;
        
        bhEne_CalcDamage(ewP, En29CombWepTbl, En29CombJointTbl);
        
        dmg_obj = ewP->djnt_no;
        
        ewP->hp -= ewP->total_dam;
        
        fwP->dmg_obj = dmg_obj;
        
        if (fwP->eff_wit == 0) 
        {
            ddP = (DD_WRK*)&DmgDat[ewP->comb_wep];
            
            if ((ewP->comb_flg & 0x1)) 
            {
                bhEne29_SetDmgEffect(ewP, ddP->eff_cmb_p);
                bhEne29_SetDmgEffect(ewP, ddP->eff_cmb_s);
                bhEne29_SetDmgEffect(ewP, 7);
            } 
            else 
            {
                if ((ewP->type == 2) || (ewP->type == 3)) 
                {
                    bhEne29_SetDmgEffect(ewP, ddP->eff_nml_p);
                }
                
                bhEne29_SetDmgEffect(ewP, ddP->eff_nml_s);
            }
        }
        
        if (ewP->comb_wep == 16) 
        {
            fwP->br_fir = 128;
            
            fwP->eff_wit = 24;
        }
        else if (ewP->comb_wep == 15) 
        {
            fwP->br_fir = 64;
            
            fwP->eff_wit = 24;
        }
        
        if ((ewP->comb_flg & 0x1)) 
        {
            fwP->dmg_lvl = 2;
        } 
        else 
        {
            fwP->dmg_lvl = 1;
        }
    } 
    else 
    {
        fwP->dmg_lvl = 0;
    }
    
    if (fwP->br_fir > 0) 
    {
        fwP->br_fir--;
        
        if (!(fwP->br_fir & 0x3))
        {
            ewP->hp--;
        }
    }
    
    if (fwP->eff_wit != 0) 
    {
        fwP->eff_wit--;
    }
    
    if (ewP->hp < 0) 
    {
        fwP->dmg_lvl = 3;
    }
}

// 100% matching!
static int bhEne29_AttackHitCheck(BH_PWORK* ewP, en29_freework* fwP)
{
    static const CLL_WORK E29Cll[6] = { { 18, 3.0f }, { 17, 3.0f }, { 15, 3.5f }, { 13, 4.0f }, { 11, 4.5f }, {  9, 4.5f } };
	static NJS_SPHERE spr;
    int i;   
    int ang; 
    float px, py, pz; // not from DWARF
    
    for (i = 0; (unsigned int)i < 6; i++) 
    {
        spr.c = *(NJS_POINT3*)&ewP->mlwP->owP[E29Cll[i].obj_no].mtx[12];
        spr.r = E29Cll[i].chk_siz;
        
        if ((!(plp->flg & 0x4)) && (njCollisionCheckSC(&spr, &plp->watr) != 0)) 
        {
            ang = fwP->bas_ay;
            
            if ((fwP->status & 0x400))
            {
                ang += 16384;
            } 
            else 
            {
                ang -= 16384;
            }

            px = 1.0f;
            fwP->ply_dmg.x = px * -njSin(ang);
            
            py = 0;
            fwP->ply_dmg.y = py;
            
            pz = 1.0f;
            fwP->ply_dmg.z = pz * -njCos(ang);
            
            fwP->dmg_dir = ang;
            
            return i;
        }
    }
    
    return -1;
}

// 100% matching!
static int bhEne29_PlySetDamage(BH_PWORK* plP, en29_freework* fwP, int dmg_mde)
{
	static const int PlyDmgTbl[4] = { 5, 5, 5, 5 };
    int dir_mde;

    if (dmg_mde > 3) 
    {
        dmg_mde = 3;
    }
    
    if (!(plP->flg & 0x4)) 
    {
        plP->hp -= PlyDmgTbl[dmg_mde];
        
        if ((fwP->dir_dlt & 0x80000000))
        {
            dir_mde = ((fwP->status & 0x400)) ? 0 : (unsigned int)1;
        } 
        else
        {
            dir_mde = ((fwP->status & 0x400)) ? (unsigned int)1 : 0;
        }
        
        if (plP->hp > 0) 
        {
            if (dmg_mde < 3) 
            {
                plP->flg |=  0x210004;
                plP->flg &= ~0x40000;
                
                plP->mode0 = 2;
                plP->mode1 = dir_mde;
                plP->mode2 = dmg_mde;
                plP->mode3 = 0;
                
                fwP->p_status = 1;
                
                fwP->p_br_mde0 = 2;
                fwP->p_br_mde1 = 0;
            }
            else
            {
                CallPlayerVoice(1027);
                
                plP->flg |=  0x210004;
                plP->flg &= ~0x40000;
                
                plP->mode0 = 5;
                plP->mode1 = 0;
                plP->mode2 = 0;
                plP->mode3 = 0;
                
                fwP->ply_act.p_act_flg = 0;
                
                fwP->p_status = 1;
                
                fwP->p_br_mde0 = dir_mde;
                fwP->p_br_mde1 = 0;
                
                return 1;
            }
        }
    }
    
    return 0;
}

// 99.35% matching (matches on NGC)
static void bhEne29_PlyMoveMain(BH_PWORK* plP, en29_freework* fwP)
{
    int* stsP;
    int* br0P, *br1P;
    int act;  
    int lop;   

    stsP = &fwP->p_status;
    
    if ((*stsP & 0x1))
    {
        br0P = &fwP->p_br_mde0;
        br1P = &fwP->p_br_mde1;
        
        act = TC_ACT_ALL;
        
        lop = 0;
        
        do 
        {
            switch (*br0P) 
            {                     
            case TC_BR0_NORMAL:
                act = (*br1P != TC_BR1_FIRST) ? act : TC_ACT_000;
                break;
            case TC_BR0_ATTACK:
                act = (*br1P != TC_BR1_FIRST) ? act : TC_ACT_001;
                break;
            case TC_BR0_DAMAGE:
                plP->px += fwP->ply_dmg.x;
                plP->pz += fwP->ply_dmg.z;
                
                fwP->ply_dmg.x *= 0.8f;
                fwP->ply_dmg.z *= 0.8f;
                
                if (fabsf(fwP->ply_dmg.x + fwP->ply_dmg.z) < 0.01f)
                {
                    *stsP &= ~0x1;
                }
                
                break;
            }
        } while (lop-- != 0);
        
        if (act != TC_ACT_ALL) 
        {
            bhEne29_PlyActionChange(plP, &fwP->ply_act, act);
        }
        
        bhEne29_PlyActionMain(plP, &fwP->ply_act);
    }
}

// 100% matching!
static void bhEne29_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num)
{
	pawP->act_tblP = act_tblP;
    
    pawP->tbl_num = tbl_num;
    
    pawP->p_act_now = -1;
    
    pawP->ene_mnwP = ewP->mnwP;
    pawP->p_paramP = ewP->exp0;
}

// 100% matching!
static void bhEne29_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP)
{
	if ((pawP->p_act_flg & 0x7) == 2)
    {
        pawP->p_act_flg &= ~0x2;
        
        bhEne29_PlyActionChange(plP, pawP, pawP->p_act_jmp);
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
static int bhEne29_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no)
{
	ACT_TBL_WORK* paP;
    
    paP = &pawP->act_tblP[act_no];
    
    if ((!(pawP->p_act_flg & 0x7)) && (pawP->p_act_now != act_no))
    {
        pawP->p_prgP = paP->prgP;
        
        pawP->p_act_now = act_no;
        pawP->p_act_flg = 1;
        
        if (act_no >= 0)
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
static void bhEne29_PlyDmg117(BH_PWORK* plP, en29_freework* fwP)
{
	int dlt;
	
    plP->px += fwP->ply_dmg.x;
    plP->pz += fwP->ply_dmg.z;

    fwP->ply_dmg.x *= 0.9f;
    fwP->ply_dmg.z *= 0.9f;

    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
		dlt = fwP->dmg_dir - plP->ay;

        if (njCos(dlt) < 0)
        {
            dlt += 32768;
        }

        plP->ay += (short)dlt / 32;
    }

    if (fwP->ply_act.p_mtn_rte >= 65536)
    {
        bhEne29_PlyDmgRtn(plP, fwP);
    }
}

// 100% matching!
static void bhEne29_PlyDmg118(BH_PWORK* plP, en29_freework* fwP)
{
	bhEne29_PlyDmg117(plP, fwP);
}

// 100% matching!
static void bhEne29_PlyDmgRtn(BH_PWORK* plP, en29_freework* fwP)
{
	plP->mnwP = plP->mnwPb;
	
	plP->flg   &= ~0x10004;
	plP->stflg &= ~0x10000; 
	
	plP->mode0 = 1;
	plP->mode1 = 0;
	plP->mode2 = 0;
	plP->mode3 = 0;
	
	fwP->p_status &= ~0x1;
}

// 99.98% matching
static void bhEne29_SetDmgEffect(BH_PWORK* ewP, int eff_typ)
{
    int* effP;       
    float px, py, pz; // not from DWARF

    effP = E29EffTbl[eff_typ];
    
    switch (effP[0]) 
    {                            
    case 0:
    {
        NJS_POINT3 dir;  
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        rySetEffBlood2(&ewP->mlwP->owP[ewP->djnt_no].mtx, (NJS_POINT3*)&ewP->dpx, &dir, effP[1]);
        break;
    }
    case 1:
    {
        NJS_POINT3 dir; 
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        rySetEffBlood(&ewP->mlwP->owP[ewP->djnt_no].mtx, (NJS_POINT3*)&ewP->dpx, &dir, effP[1]);
        break;
    }
    case 2:
    {
        NJS_VECTOR vct;   
        int i;          
        NJS_POINT3 dir;
        int djnt_no;    
        NJS_POINT3 off;

        vct = *(NJS_POINT3*)&ewP->dvx;
        
        njUnitVector(&vct);
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = 10430.381f * asinf(vct.y);
        sys->ef.ay = 10430.381f * atan2f(-vct.x, -vct.z);
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
        
        sys->ef.mdlver = effP[1];
        
        sys->ef.type = 0;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[ewP->djnt_no].mtx[12];
        
        djnt_no = ewP->djnt_no;
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        njUnitVector(&dir);
        
        for (i = effP[2]; i > 0; i--) 
        {
            if (djnt_no != 1) 
            {
                off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.z = 3.0f *  (-rand() / -2.1474836E9f);
                
                bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no - 1);
            }
            
            off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
            off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
            off.z = 2.0f *  (-rand() / -2.1474836E9f);
            
            bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
            
            off.x = 3.0f *        ((-rand() / -2.1474836E9f) - 0.5f);
            off.y = 3.0f *        ((-rand() / -2.1474836E9f) - 0.5f);
            off.z = 1.0f + (2.0f * (-rand() / -2.1474836E9f));
            
            bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
            
            if (djnt_no != 19)
            {
                off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.z = 3.0f *  (-rand() / -2.1474836E9f);
                
                bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no + 1);
            }
        }  
        
        break;
    }
    case 3:
    {  
        NJS_MATRIX* mtxP; 
        int i;      
    
        mtxP = (NJS_MATRIX*)&ewP->mlwP->owP[ewP->djnt_no].mtx[8];
        
        px = -(*mtxP)[0];
        py = -(*mtxP)[1];      
        pz = -(*mtxP)[2]; 
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = 10430.381f * asinf(py);
        sys->ef.ay = 10430.381f * atan2f(-px, -pz);
        
        sys->ef.mdlver = effP[1];
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
        
        sys->ef.type = 6;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->dpx;
        
        for (i = effP[2]; i > 0; i--)
        {
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        } 
        
        break;
    }
    case 4:
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
        
        sys->ef.px = sys->ef.py = sys->ef.pz = 0;
        
        bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
        break;
    }
    }
}

// 100% matching!
static void SetDmgEne(BH_PWORK* ewP, en29_freework* fwP, DS_WORK* dsP, int set_num) // first parameter not present on DWARF
{
    e19_dmg_typ* hedP, *edP; 

    edP = fwP->DmgWrk;
    
    fwP->dmg_eneP = edP;
    
    hedP = edP++;
    
    fwP->DmgWrk->nextP = fwP->DmgWrk;   
    
    for (; set_num > 0; set_num--, dsP++, edP++)
    {
        BH_PWORK* ewP;

        ewP = bhSetEnemy(&En29DmgDat, 0);
        
        ewP->flg2 |= dsP->or_flg2;
        
        edP->atr_top = dsP->atr_top;
        edP->atr_end = dsP->atr_end;
        edP->atr_rad = dsP->atr_rad;
        
        edP->ewP = ewP;
        
        edP->nextP  = hedP->nextP;
        hedP->nextP = edP;
    }
}

// 100% matching!
static void CalcDmgEne(BH_PWORK* ewP, en29_freework* fwP)
{
	O_WORK* owP;      
	e19_dmg_typ* hedP, *edP; 
	BH_PWORK* enP;    
	
    hedP = fwP->dmg_eneP;

    owP = ewP->mlwP->owP;

	for (edP = hedP->nextP; edP != hedP; edP = edP->nextP)
	{
		enP = edP->ewP;

		enP->watr.r = edP->atr_rad;

		enP->watr.c1 = *(NJS_POINT3*)&owP[edP->atr_top].mtx[12];
		enP->watr.c2 = *(NJS_POINT3*)&owP[edP->atr_end].mtx[12];

		enP->cpcl = ewP->cpcl;
		
		enP->mlwP = ewP->mlwP;
	} 
}

// 100% matching!
static void CheckDmgEne(BH_PWORK* ewP, en29_freework* fwP)
{
    BH_PWORK* dmgP;    
    e19_dmg_typ* hedP, *edP; 
    BH_PWORK* enP;    
    float d;          
    int* srcP, *dstP;        
    int num;          

    hedP = fwP->dmg_eneP;
    dmgP = NULL;
    
    for (edP = hedP->nextP; edP != hedP; edP = edP->nextP) 
    {
        enP = edP->ewP;
        
        if ((enP->flg & 0x4)) 
        {
            enP->flg &= ~0x4;
            
            d = 10000.0f;
            
            if (d > njDistanceP2P((NJS_POINT3*)&plp->px, (NJS_POINT3*)&enP->dpx)) 
            {
                dmgP = enP;
            }
        }
    }
    
    if (dmgP != NULL) 
    {
        if (!(ewP->flg & 0x4)) 
        {
            ewP->flg |= 0x4;
            
            num = 64;
            
            srcP = dmgP->dam;
            dstP = ewP->dam;
            
            ewP->djnt_no = dmgP->djnt_no;
            
            for (; num > 0; num--) 
            {
                *dstP++ = *srcP++;
            } 
            
            ewP->dpx = dmgP->dpx;
            ewP->dpy = dmgP->dpy;
            ewP->dpz = dmgP->dpz;
            
            ewP->dvx = dmgP->dvx;
            ewP->dvy = dmgP->dvy;
            ewP->dvz = dmgP->dvz;
            
            ewP->dax = dmgP->dax;
            ewP->day = dmgP->day;
            
            ewP->wpnr_no = dmgP->wpnr_no;
            
            ewP->comb_flg |= dmgP->comb_flg & 0x70;
        }
    }
}
