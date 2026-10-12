#include "../../../ps2/veronica/prog/en06.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/en06sub.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: Moth 

#pragma divbyzerocheck on

static int ENE06_HITPOINT[16] = 
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1
};

static char junction_tree[1][6] =
{
    { 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 }
};

/*
char player_junction_tree[8][8];  // unused?
*/

static char SdwTab[2] = { 0x00, 0xFF };

static ETTY_WORK ene06_child =
{
    0x8001,                                 
    0x1F,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0.0f,                                   
    0.0f,                                   
    0.0f,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    {0, 0, 0, 0}                            
};

static char BrokenParts[12] = {0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};

static ETTY_WORK ene27 =
{
    0x8001,                                 
    0x1B,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0.0f,                                   
    0.0f,                                   
    0.0f,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    {0, 0, 0, 0}                            
};


static ETTY_WORK ene06_leader =
{
    0x01008001,                             
    0x06,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    0.0f,                                   
    0.0f,                                   
    0.0f,                                   
    0,                                      
    0,                                      
    0,                                      
    0,                                      
    {0, 0, 0, 0}                            
};

static BP_WORK BloodParam =
{
    {0.0f, 0.01f, 0.0f},                    
    0,                                      
    0.0f,                                   
    0.05f,                                  
    {0.3f, 0.7f, 0.5f, 0.7f, 0.4f},         
    {0, 3, 6, 9, 12}                        
};

static CPCL CapColTab[8] =
{
    { 1,  1,  5 },                          
    { 0,  0, -6 },                          
    { 1,  2,  5 },                          
    { 2,  4,  6 },                          
    { 4,  6,  7 },                          
    { 6,  8,  7 },                          
    { 8, 10,  6 },                          
    { 0,  0,  0 }                           
};

static DMG_REACT DmgReact[21] =
{
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          
    { {  2,  1,  0 }, {  1,  0,  0 }, 0 },          
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          
    { {  2,  1,  0 }, {  1,  1,  1 }, 1 },          
    { { -1, -1, -1 }, {  0,  0,  0 }, 2 },          
    { { -1, -1, -1 }, {  0,  0,  0 }, 1 },          
    { { -1, -1, -1 }, {  0,  0,  0 }, 0 },          
    { {  2,  2,  2 }, {  1,  1,  1 }, 5 },          
    { {  2,  2,  2 }, {  0,  0,  0 }, 1 },          
    { {  2,  2,  2 }, {  1,  1,  1 }, 5 }           
};

static BLOOD_TBL BloodTbl[23] =
{
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },    
    { 0, {  2.0f,  0.0f, -1.0f },  1.0f,  0.0f,  1.0f },    
    { 0, { -2.0f,  0.0f, -1.0f },  1.0f,  0.0f,  1.0f },    
    { 0, {  1.0f,  0.0f,  1.0f },  1.0f,  0.0f,  1.0f },    
    { 0, { -1.0f,  0.0f,  1.0f },  1.0f,  0.0f,  1.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },    
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f }     
};

typedef void (*bhEne06_Mode0_proc)(BH_PWORK*);
typedef void (*bhEne06_BrainType_proc)(BH_PWORK*);
typedef void (*bhEne06_MoveMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_NageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DamageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DeadMode2_proc)(BH_PWORK*);

bhEne06_Mode0_proc bhEne06_Mode0[6] =
{
    bhEne06_Init,                           
    bhEne06_Move,                           
    bhEne06_Nage,                           
    bhEne06_Damage,                         
    bhEne06_Die,                            
    bhEne_Event                             
};

bhEne06_BrainType_proc bhEne06_BrainType[1] =
{
    bhEne06_BR00
};

bhEne06_MoveMode2_proc bhEne06_MoveMode2[11] =
{
    bhEne06_MV00,                           
    bhEne06_MV01,                           
    bhEne06_MV02,                           
    bhEne06_MV03,                           
    bhEne06_MV04,
    bhEne06_MV05,
    bhEne06_MV06,
    bhEne06_MV07,
    bhEne06_MV08,
    bhEne06_MV09,
    bhEne06_MV10 
};

bhEne06_NageMode2_proc bhEne06_NageMode2[1] =
{
    bhEne06_NG00
};

bhEne06_DamageMode2_proc bhEne06_DamageMode2[2] =
{
    bhEne06_DG00,
    bhEne06_DG01
};

bhEne06_DeadMode2_proc bhEne06_DeadMode2[5] =
{
    bhEne06_DD00,
    bhEne06_DD01, 
    bhEne06_DD02,
    bhEne06_DD03,
    bhEne06_DD04
};

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne06(BH_PWORK* epw)
{
    if ((epw->flg & 0x1000000))
    {
        if ((*(int*)epw->exp1 & 1) != 0)
        {
            if(plp->mode0 == 4)
            {
                bhEne06_PlayerControl(epw);
            }
        }
    } 
    else 
    {
        bhEne06_Mode0[epw->mode0](epw);
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->car += ((EXP0_F(0x70) - epw->car) / 8.0f);
        
        bhCheckPlayer(epw);
        
        if (epw->flg & 8)
        {
            bhEne_CheckEnemiesBall(epw);
        }
        
        bhEne06_FloorCollision(epw);
        
        if (epw->flg & 0x10)
        {
            bhEne06_CollisionWalls(epw);
        }
        
        bhCalcModel(epw);
        
        bhEne_SetWeponAtr(epw, 10, 1, 2.0f);
        
        return;
    }
}

// 99.69% matching
void bhEne06_Init(BH_PWORK* epw)
{
	int sdw;
	int i;
	BH_PWORK* ep_leader;
	BH_PWORK* ep;
	BH_PWORK** epw2;
	O_WORK* owk;
    
    // not present in DWARF
	int ene_n;

	epw->flg |= 0x78;
	epw->flg &= ~0x9006;
	epw->flg &= ~0x800000;

	epw->ar = 5.0f;
	epw->ah = 1.0f;
	epw->car = 3.0f;
	epw->cah = 3.0f;

	epw->hp = ENE06_HITPOINT[(int)(16.0f * njRandom())];

	epw->hokan_rate = 65536;
	epw->hokan_count = 0;
	epw->mtn_no = 4;
	epw->mtn_md = 0;
	epw->mtn_add = 65536;
	epw->frm_no = 0;

	epw->mode0 = 1;
	epw->mode1 = 0;
	epw->mode2 = 0;
	epw->mode3 = 0;

	owk = epw->mlwP->owP;
	for (i = 0; i < epw->mnwP->obj_num; i++, owk++)
    {
		owk->flg &= ~3;
	}

	if (epw->exp0 == NULL)
    {
		epw->exp0 = (unsigned char*)bhEne_CallocWork(176, 8);
		ep = (BH_PWORK*)ene;
		for (i = 0; i < sys->ewk_n; i++, ep++)
        {
			if ((ep->flg & 1) && ep->id == 6)
            {
				if (ep->exp1 != NULL)
                {
					epw->exp1 = ep->exp1;
				} 
                else
                {
					epw->exp1 = (unsigned char*)bhEne_CallocWork(12, 8);
				}

				if (ep->exp2 != NULL)
                {
					epw->exp2 = ep->exp2;
				} 
                else
                {
					ene_n = rom->ene_n;
					ep_leader = bhSetEnemy((EGG_WORK*)&ene06_leader, ene_n);
					epw->exp2 = (unsigned char*)ep_leader;
					ep_leader->mdflg |= 0x21;
					ep_leader->exp1 = epw->exp1;
					ep_leader->mnwP = epw->mnwP;
				}
				break;
			}
		}

		epw2 = (BH_PWORK**)(epw->exp0 + 0x34);
		for (i = 0; i < 14; i++, epw2++)
        {
			ene_n = rom->ene_n;
			*epw2 = bhSetEnemy((EGG_WORK*)&ene06_child, ene_n);
			(*epw2)->lkwkp = (unsigned char*)epw;
			(*epw2)->lkono = i;
			(*epw2)->lox = 0.0f;
			(*epw2)->loy = 0.0f;
			(*epw2)->loz = 0.0f;
			(*epw2)->mdflg |= 1;
			(*epw2)->mtx = &epw->mlwP->owP[BrokenParts[i]].mtx;
        }
		bhEne_SetCallFunc((void (*)(BH_PWORK*))&bhEne06s, 31);
	}

	EXP0_F(0x6c) = epw->ar;
	EXP0_F(0x70) = epw->car;
	EXP0_I(0x74) = (int)(30.0f * njRandom()) + 20;

	if (!(epw->flg & 0x800))
    {
		sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 5.0f, 4.0f, 4.0f);
		eff[sdw].mdlver = 1;
		epw->flg |= 0x800;
		*(O_WRK **)((epw->exp0 + 0x84)) = &eff[sdw];
	}

	epw->stflg &= ~8;
	epw->clp_jno[0] = 11;
	epw->clp_jno[1] = 12;
	epw->clp_jno[2] = 13;
	epw->clp_jno[3] = 14;
	epw->clp_jno[4] = 1;
	epw->clp_jno[5] = 2;
	epw->clp_jno[6] = -1;

	epw->cpcl = CapColTab;
	epw->flg |= 0x100000;

	epw->mlwP->objP[1].evalflags &= ~8;
	epw->mlwP->objP[2].evalflags &= ~8;
}

// 100% matching!
void bhEne06_Brain(BH_PWORK* epw)
{ 
    bhEne06_BrainType[epw->type](epw); 
}

// 100% matching!
void bhEne06_BR00(BH_PWORK* epw)
{
    bhEne06_SearchPlayer(epw);
    if (epw->flg & 0x400000)
    {
        if ((EXP0_F(0) < 20.0f) && (epw->mode2 != 3))
        {
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }

        if (!(!(plp->flg & 4) && !(plp->stflg & 0x80000000)))
        {
            return;
        }

        if ((!(plp->stflg & 0x8000000) || !(plp->stflg & 0x10000000) || !(plp->stflg & 0x20000000))
            && (EXP0_F(0) < 15.0f)
            && (fabsf((epw->py - plp->py) - 15.0f) < 8.0f)
            && (abs((short)(epw->ay - plp->ay)) < NJM_DEG_ANG(90))
            && (abs(bhEne_DirTarget(epw, plp->px, plp->pz, NJM_DEG_ANG(90))) < NJM_DEG_ANG(90)))
        {
            epw->mode0 = 2;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            plp->flg |= 0x10004;
            plp->stflg |= 0x10000;
            return;
        }
    }

}

// 100% matching!
void bhEne06_Move(BH_PWORK* epw)
{
    bhEne06_MoveMode2[epw->mode2](epw);
    if ((epw->flg & 4) && !(epw->flg & 2))
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;      
        epw->flg &= ~4;        
        bhEne06_Damage(epw);
        return;
    }
    if (epw->mode1 == 1)
    {
        bhEne06_Brain(epw);
    }
}

// 100% matching!
void bhEne06_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->mtn_no = 4;
        epw->frm_no = epw->mnwP[epw->mtn_no].frm_num * (32768.0f * njRandom());
        epw->hokan_count = 0;
        
        epw->flg |= 0x180000;
        epw->flg &= ~0x400000;
        
        if (njRandom() < 0.8f)
        {
            epw->ct0 = (int)(30.0f * njRandom()) + 30;
        } 
        else
        {
            epw->ct0 = (int)(90.0f * njRandom()) + 120;
        }
        epw->mode3++;

    case 1:
        epw->ax += (short)-epw->ax / 8;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

    }
}

// 100% matching!
void bhEne06_MV01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ct1 = (njRandom() > 0.5f);
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x580000;
        epw->ar = 0.1f;
        EXP0_F(0x6C) = 5.0f;
        epw->spd = 1.0f;
        
        if (epw->ct1 != 0)
        {
          epw->ayp = epw->ay + 16384;
        }
        else
        {
          epw->ayp = epw->ay - 16384;
        }
        
        epw->ct0 = 14;
        epw->ct2 = 8;
        epw->mode3++;
        break;
        
    case 1:
        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ct0--;
        } 
        else
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;                        
        } 
        else
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;
    
                }
            }
        }

        if (epw->ct2 != 0)
        {
            ((BH_PWORK*)EXP0_I(0x84))->sy += (4.0f - ((BH_PWORK*)EXP0_I(0x84))->sy) / (float)epw->ct2;
            epw->ct2--;
        }
    }
}

// 100% matching!
void bhEne06_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        epw->flg |= 0x580000;
        epw->flg &= ~0x2180000;
        epw->spd = 1.0f;
        epw->ct0 = (int)(128.0f * njRandom()) + 90;
        epw->ct1 = (njRandom() > 0.5f) ? 1 : -1; 
        epw->ct2 = 20;
        epw->ct3 = (int)(20.0f * njRandom()) + 10;
        epw->yn = 10.0f + plp->py + (20.0f * njRandom());
        epw->ayp = (int)(epw->ay + ((7281.0f * njRandom()) - 3640.0f));
        EXP0_F(0x20) = 0.0f;
        epw->mode3++;

    case 1:
        EXP0_F(0x20) += 0.1f * (epw->yn - epw->py);

        if (EXP0_F(0x20) > 0.4f)
        {
            EXP0_F(0x20) = 0.4f;
        }
        
        if (EXP0_F(0x20) < -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-3640 - epw->ax) / 16;
        } 
        else
        {
            epw->ax += (short)(-10922 - epw->ax) / 16;
        }
        
        bhAddSpeed(epw, 0);
        epw->ct0 = epw->ct0;
        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
            {
                epw->flg |= 0x2000000;
            } 
            else if (!(epw->flg & 0x2000000))
            {
                epw->ay += (short)(epw->ayp - epw->ay) / 16;
            }
        } 
        else if (bhEne06_CheckLeaningWall(epw) != 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 8;
            epw->mode3 = 0;
        } 
        else if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
        {
            epw->flg |= 0x2000000;
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->ay += (short)(epw->ayp - epw->ay) / 16;
        }

        if (epw->ct3-- == 0)
        {
            epw->yn = 15.0f + plp->py + (10.0f * njRandom());
            epw->ayp = (int)(epw->ay + ((7281.0f * njRandom()) - 3640.0f));
            epw->ct3 = (int)(10.0f * njRandom()) + 20;
            epw->flg &= ~0x2000000;
        }
        
        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74497);
            epw->ct2 = (int)(5.0f * njRandom()) + 20;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;
        } 
        else 
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;    
                }
            } 
        }
    }
}

// 100% matching!
void bhEne06_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg |= 0x580000;
        epw->flg &= ~0x2180000;
        epw->spd = 1.0f;
        
        epw->ct0 = (int) (63.0f * njRandom()) + 20;
        epw->ct1 = (njRandom() > 0.5f) ? 1 : -1;       
        epw->ct2 = 20;
        epw->ct3 = (int)(20.0f * njRandom()) + 10;
        
        epw->yn = 15.0f + plp->py + (10.0f * njRandom());
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        EXP0_F(0x20) = 0.0f;
        epw->mode3++;

    case 1:
        EXP0_F(0x20) += (0.1f * (epw->yn - epw->py));

        if (EXP0_F(0x20) > 0.4f)
        {
             EXP0_F(0x20) = 0.4f;
        }

        if (EXP0_F(0x20)< -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-epw->ax) / 8;
        } 
        else
        {
            epw->ax += (short)(-3640 - epw->ax) / 8;
        }
        
        bhAddSpeed(epw, 0);
        if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
        {
            epw->flg |= 0x2000000;
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->ay += (short)(epw->ayp - epw->ay) / 16;
        }

        if (epw->ct3-- == 0)
        {
            epw->yn = 10.0f + plp->py + (10.0f * njRandom());
            epw->ayp = (int)(bhArcTan2(epw->px - plp->px, epw->pz - plp->pz) + ((7281.0f * njRandom()) - 3640.0f));
            epw->ct3 = (int)(10.0f * njRandom()) + 20;
        }

        if (epw->ct2-- == 0) {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74497);
            epw->ct2 = 20;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;
        } 
        else
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;
                }
            }
        }
    }
}

// 100% matching!
void bhEne06_MV04(void)
{

}

// 100% matching!
void bhEne06_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mode3++;
        
        epw->ct0 = (int)(8.0f * njRandom()) + 14;
        epw->ayp = epw->ay + 32768;
        epw->spd = 1.0f;
        epw->flg |= 0x50;
        epw->car = 0.1f;
        
        EXP0_F(0x70) = 3.0f;
        epw->ar = 0.1f;
        EXP0_F(0x6C) = 5.0f;
        epw->yn = 15.0f + plp->py + (20.0f * njRandom());
        EXP0_F(0x20) = 0.0f;
        
    case 1:
        EXP0_F(0x20) += (0.1f * (epw->yn - epw->py));

        if (EXP0_F(0x20) > 0.4f)
        {
            EXP0_F(0x20) = 0.4f;
        }

        if (EXP0_F(0x20) < -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-epw->ax) / 8;
        } 
        else
        {
            epw->ax += (short)(-3640 - epw->ax) / 8;
        }

        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ct0--;
            break;
        }
        
        epw->car = 3.0f;
        
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        
        epw->ax = 0;

    }
}

// 100% matching!
void bhEne06_MV06(void)
{

}

// 100% matching!
void bhEne06_MV07(void)
{

}

// 100% matching!
void bhEne06_MV08(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        
        epw->flg |= 0x580000;
        epw->flg &= ~0x400000;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 8;
        epw->mode3++;
        
    case 1:
        if (epw->ct1 != 0)
        {
            epw->ax += (short)-epw->ax / epw->ct1;
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
            
            epw->px = epw->px + ((EXP0_F(0x28)- epw->px) / epw->ct1);   
            epw->pz = epw->pz + ((EXP0_F(0x30) - epw->pz) / epw->ct1);
            
            ((BH_PWORK*)EXP0_I(0x84))->sy += (2.0f - ((BH_PWORK*)EXP0_I(0x84))->sy) / (float)epw->ct1;
            
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->ay = epw->ayp;
            
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->mtn_no = 4;
            epw->frm_no = 0;
        }
    }
}

// 100% matching!
void bhEne06_MV09(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 15)
        {
            epw->mtn_no = 15;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 100% matching!
void bhEne06_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 16)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 100% matching!
void bhEne06_Nage(BH_PWORK* epw)
{
    bhEne06_NageMode2[epw->mode2](epw);
}

// 99.76% matching!
void bhEne06_NG00(BH_PWORK* epw)
{
    NJS_POINT3 pos; 
    O_WORK* owk; 
    BH_PWORK* epw2; 
    int i;  
    int type; 

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 6;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        *(int*)epw->exp1 |= 1;
        *(int*)&plp->mode0 = 4;
        plp->flg |= 0x10004;
        plp->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        epw->flg &= ~0x70;
        epw->flg |= 0x580000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;
        epw->ct2 = 0;
        epw->ct3 = 12;

    case 1:
        epw->ct2 += bhEne_LeverCheck();
        if (epw->frm_no == 655360)
        {
            StartVibrationEx(1, 11);
        }
        if (epw->mtn_no == 6)
        {
            {
                NJS_VECTOR offset = { 0.0f, 1.0f, 2.5f };
                NJS_VECTOR v = { 0.0f, 0.0f, -1.0f }; 
                    
                owk = &plp->mlwP->owP[3];
                njCalcPoint((NJS_MATRIX*) &owk->mtx, &offset, &pos);
                if (epw->ct3 > 0)
                {
                    epw->px = epw->px + ((pos.x - epw->px) / epw->ct3);
                    epw->py = epw->py + ((pos.y - epw->py) / epw->ct3);
                    epw->pz = epw->pz + ((pos.z - epw->pz) / epw->ct3);
                    
                    njCalcVector((NJS_MATRIX*) &owk->mtx, &v, &v);
                    epw->ayp = bhArcTan2(-v.x, -v.z);
                    epw->axp = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));

                    epw->ax += (short)(epw->axp - epw->ax) / epw->ct3;
                    epw->ay += (short)(epw->ayp - epw->ay) / epw->ct3;
                    epw->ct3--;
                } 
                else
                {
                    epw->px = pos.x;
                    epw->py = pos.y;
                    epw->pz = pos.z;
                    epw->flg |= 0x1000;
                    
                    njSetMatrix(epw->mtx, (NJS_MATRIX*) &owk->mtx);
                    epw->mtx[0][12] = epw->px;
                    epw->mtx[0][13] = epw->py;
                    epw->mtx[0][14] = epw->pz;
                    
                    njCalcVector((NJS_MATRIX*) &owk->mtx, &v, &v);
                    epw->ay = bhArcTan2(-v.x, -v.z);
                    epw->ax = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));
                }
            }
        }
        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x20;
            epw->flg &= ~0x1000;
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }
        
        if (((epw->frm_no / 65536) == 29) && (epw->ct2 < 30))
        {
            {
            unsigned int flg[3] = { 0x8000000, 0x10000000, 0x20000000 };  

            bhEne_CallSE(epw, (NJS_VECTOR*) &epw->px, 0x12303);
            type = (int)(3.0f * njRandom());
            for (i = 0; i < 3; i++)
            {
                if (!(plp->stflg & flg[type]))
                {
                    plp->stflg |= flg[type];
                    break;
                }
    
                type++;
                if (2 < type)
                {
                    type = 0;
                }
            }
                epw2 = bhSetEnemy(&ene27, rom->ene_n); 
                epw2->type = (unsigned short)type;
                epw2->mode2 = 1;
            }
        }
        break;
    }
}

// 100% matching!
void bhEne06_Damage(BH_PWORK* epw)
{
    int i;
    int dir;
    int dam;

    for (i = 0, dam = 0; i < epw->mnwP->obj_num; i++)
    {
        if (epw->dam[i])
        {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }
    
    epw->hp -= dam;

    if (epw->mode3 == 0)
    {
        bhEne06_HitMark(epw);
        bhEne06_SetRinpunEffect(epw, 8, 1);
        dir = bhEne_DGDirCheck(epw);

        if ((dam < 31) && (epw->flg & 0x400000) && (njRandom() < 0.4f))
        {
            epw->mode2 = (dir != 0) ? 0 : 1;
        } 
        else
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            if (epw->flg & 0x800000)
            {
                epw->mode2 = 4;
            } 
            else if (30 < dam)
            {
                epw->mode2 = 3;
                epw->dpx = epw->px;
                epw->dpy = epw->py;
                epw->dpz = epw->pz;
                bhEne_SetMinceEffect2(epw, 2, 0.3f, 6);
                bhEne_SetMinceEffect2(epw, 259, 0.3f, 8);
            } 
            else if (epw->flg & 0x400000)
            {
                epw->mode2 = (dir != 0) ? 1 : 2;
            } 
            else
            {
                epw->mode2 = 0;
            }
            
            epw->flg |= 2;
            epw->flg &= ~0x28;
            bhEne06_Die(epw);
            return;
        }        
    }
    bhEne06_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne06_DG00(BH_PWORK* epw) {
	NJS_POINT3 pos;
	int pno;
	O_WORK* owk;
	char parts[4] = { 0xB, 0xC, 0xD, 0xE }; 
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 10;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));
        EXP0_F(0x20) *= 0.5f;
        
        owk = epw->mlwP->owP;
        pno = (int)(4.0f * njRandom());
        owk[parts[pno]].flg |= 3;
        
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[12] = 1;
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[14] = 1;
        
        EXP0_F(0x70) = 1.0f;
        
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8964);
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0) {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 12;
            epw->frm_no = 0;
            
            epw->flg &= ~0x80000;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 14;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        }
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 10;
            epw->mode3 = 0;
            epw->flg &= ~0x40;
        }
    }
    epw->ax += (short)(-epw->ax) / 8;
}

// 99.87% matching
void bhEne06_DG01(BH_PWORK* epw)
{
	NJS_POINT3 pos; 
	int pno;
	O_WORK* owk;
	char parts[4] = { 0xB, 0xC, 0xD, 0xE };   
	NJS_MKEY* mkfP;
	NJS_VECTOR trans; 

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));
        EXP0_F(0x20) *= 0.5f;
        EXP0_F(0x70) = 1.0f;
        
        owk = epw->mlwP->owP;
        pno = (int)(4.0f * njRandom());
        owk[parts[pno]].flg |= 3;
        
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[12] = 1;
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[14] = 1;
        
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8964);
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0) {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 13;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        }
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 9;
            epw->mode3 = 0;
            epw->mtn_no = 15;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ay += 32768;
            epw->flg &= ~0x40;
        }
    }
    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_Die(BH_PWORK* epw)
{
    bhEne06_DeadMode2[epw->mode2](epw); 
}

// 100% matching!
void bhEne06_DD00(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 8;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x180000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        
        epw->ar = 0.0f;
        EXP0_F(0x6C) = 5.0f;
        
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;            
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 13;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD01(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 10;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;        
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));        
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;        
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 12;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;  
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 14;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD02(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));        
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 13;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD03(BH_PWORK* epw)
{
    O_WORK* owk;
	int i;
	
    switch (epw->mode3)
    {
    case 0:
        owk = epw->mlwP->owP;
        for (i = 0; i < 12U; i++)
        {
            owk[BrokenParts[i]].flg |= 3;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xC) = 1;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xE) = (i < 4);
        }
        
        epw->mlwP->objP[1].evalflags |= 8;
        epw->mlwP->objP[2].evalflags |= 8;
        
        epw->stflg |= 8;
        epw->flg &= ~0x78;
        epw->flg |= 0x8000;
        
        epw->mtn_add = 0;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8960);
        epw->mode3++;        
    } 
}

// 100% matching!
void bhEne06_DD04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->frm_no = 0;
        epw->mtn_add = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->flg |= 2;
        epw->flg &= ~0x28;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;
    }
}

// 100% matching!
void bhEne06_SearchPlayer(BH_PWORK* epw)
{
    float dx;
    float dz;
    
    EXP0_C(0x16) = 0;
    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0) = njSqrt(dx * dx + dz * dz);
    EXP0_C(0x16) = 1;
}

// 100% matching!
void bhEne06_CollisionWalls(BH_PWORK* epw)
{
    NJS_VECTOR ofp;
    NJS_VECTOR trans;
    NJS_MKEY_A_MOD* mkaP;
	NJS_CNK_OBJECT* objP;
	
    epw->ar += (EXP0_F(0x6C) - epw->ar) / 8.0f;
    if (epw->flg & 0x400000)
    {
        ofp.z = 0.0f;
        ofp.y = 0.0f;
        ofp.x = 0.0f;
    } 
    else
    {
        ofp.z = 0.0f;
        ofp.x = 0.0f;
        ofp.y = epw->ar;
        if (epw->flg & 0x100000)
        {
            mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            mkaP += (epw->frm_no / 65536); 
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
            njCalcVector(NULL, &ofp, &ofp);
        }
    }
    objP = epw->mlwP->objP;
    trans.x = objP->pos[0];
    trans.y = objP->pos[1];
    trans.z = objP->pos[2];
    
    if (!(epw->flg & 0x80000))
    {
        trans.y = 0.0f;
    }
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &trans, &trans);
    
    epw->px += trans.x;
    epw->py += trans.y;
    epw->pz += trans.z;
    
    epw->px += ofp.x;
    epw->py += ofp.y;
    epw->pz += ofp.z;
    
    *(ATR_WORK**)((char *)epw->exp0 + 0x18) = bhEne03_Collision(epw);
    
    epw->px -= ofp.x;
    epw->py -= ofp.y;
    epw->pz -= ofp.z;
    
    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;
}

// 100% matching!
void bhEne06_FloorCollision(BH_PWORK* epw)
{
    ATR_WORK* hp;

    hp = (ATR_WORK*)bhCollisionCheckLine((NJS_VECTOR*)&epw->pxb, (NJS_VECTOR*)&epw->px);
    
    if (hp != NULL)
    {
        bhGetHitCollisionNormal((NJS_VECTOR*)((char *)epw->exp0 + 0x78));
        njUnitVector((NJS_VECTOR*)((char *)epw->exp0 + 0x78));
        *(ATR_WORK**)((char *)epw->exp0 + 0x18) = hp;
        
        if (EXP0_F(0x7C) > 0.9f)
        {
            epw->flg &= ~0x200000; 
            
            if (hp->type == 7)
            {
                if (hp->py > epw->py)
                {
                    epw->py = hp->py;
                }
            } 
            else
            {
                float tmp = hp->py + ((hp->h) ? hp->h : rom->h);
                if (tmp > epw->py)
                {
                    epw->py = tmp;
                }
            }
        }
        
        if (EXP0_F(0x7C) < -0.9f)
        {
            EXP0_I(0x20) = 0;
        }
        
        if (fabsf(EXP0_F(0x7C)) < 0.3f)
        {
            EXP0_I(0x1C) = 0;
            EXP0_I(0x24) = 0;
        }
    }
}

// 100% matching!
int bhEne06_CheckLeaningWall(BH_PWORK* epw)
{
	NJS_VECTOR vec;
	NJS_POINT3 pos;
	ATR_WORK* hp;
	NJS_VECTOR n; 
	BH_PWORK* ep;
	float dist;    
	int i;

    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = -10.0f;
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &vec, &vec);
    ep = ene;
    i = 0;
    pos.x = epw->px + vec.x;
    pos.y = epw->py;
    pos.z = epw->pz + vec.z;

    while (i < sys->ewk_n)
    {
        if ((ep->flg & 1) && (ep->id == 6) && (ep != epw))
        {
            dist = njDistanceP2P((NJS_POINT3*)&ep->px, &pos);
            if (dist < 10.0f)
            {
                return 0;
            }
        }
        
        i++;
        ep++;
    }

    hp = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &pos);
    if ((hp != NULL) && !(hp->attr & 8))
    {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        epw->ayp = bhArcTan2(n.x, n.z);
        EXP0_F(0x28) = pos.x + n.x;
        EXP0_F(0x2C) = pos.y + n.y;
        EXP0_F(0x30) = pos.z + n.z;
        return 1;
    }

    return 0;
}

// 99.81% matching
int bhEne06_AvoidWall(BH_PWORK* epw, int dir)
{
    NJS_POINT3 pos1; 
    NJS_POINT3 pos2; 
    ATR_WORK* hp1; 
    ATR_WORK* hp2; 
    NJS_VECTOR ofp; 
    NJS_VECTOR trans; 
    int ret; 
    NJS_MKEY_A_MOD* mkaP; 
    int i; 
    BH_PWORK* ep; 
    BH_PWORK* ep2;   
    float dist; 
    float wdist; 
    NJS_CNK_OBJECT* objP; 

    ep = ene;
    ret = 0;
    ep2 = NULL;
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if ((ep->flg & 1) && (ep->id == 6) && (ep != epw) && !(ep->flg & 0x1000000) && !(ep->flg & 2) && ((dist = njSqrt((epw->px - ep->px) * (epw->px - ep->px) + (epw->pz - ep->pz) * (epw->pz - ep->pz)), (ep2 == NULL)) || (dist < wdist))) {
            wdist = dist;
            ep2 = ep;
        }
    }
    
    if ((ep2 != NULL) && (fabsf(epw->py - ep2->py) < 8.0f))
    {
        if (ep2->yn < epw->py)
        {
            epw->yn += 3.0f;
        } 
        else
        {
            epw->yn -= 3.0f;
        }
    }
    
    if (epw->flg & 0x400000)
    {
        ofp.z = 0.0f;
        ofp.y = 0.0f;
        ofp.x = 0.0f;
    } 
    else
    {
        ofp.z = 0.0f;
        ofp.x = 0.0f;
        ofp.y = epw->ar;
        if (epw->flg & 0x100000)
        {
            mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            mkaP += (epw->frm_no / 65536); 
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
            njCalcVector(NULL, &ofp, &ofp);
        }
    }
    
    objP  = epw->mlwP->objP;
    trans.x = objP ->pos[0];
    trans.y = objP ->pos[1];
    trans.z = objP ->pos[2];
    if (!(epw->flg & 0x80000))
    {
        trans.y = 0.0f;
    }
    
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &trans, &trans);
    pos1.x = ofp.x + (epw->px + trans.x);
    pos1.y = ofp.y + (epw->py + trans.y);
    pos1.z = ofp.z + (epw->pz + trans.z);
    pos2.x = pos1.x;
    pos2.y = pos1.y - 6.0f;
    pos2.z = pos1.z;
    
    hp1 = (ATR_WORK*) bhCollisionCheckLine(&pos1, &pos2);
    if (hp1 == NULL)
    {
        pos1.x = ofp.x + (epw->px + trans.x);
        pos1.y = (ofp.y + (epw->py + trans.y)) - 6.0f;
        pos1.z = ofp.z + (epw->pz + trans.z);
        pos2.x = pos1.x - (10.0f * njSin(epw->ay));
        pos2.y = ofp.y + (epw->py + trans.y);
        pos2.z = pos1.z - (10.0f * njCos(epw->ay));
        hp1 = bhCollisionCheckLine(&pos1, &pos2);
    }
    
    pos1.x = ofp.x + (epw->px + trans.x);
    pos1.y = ofp.y + (epw->py + trans.y);
    pos1.z = ofp.z + (epw->pz + trans.z);
    pos2.x = pos1.x;
    pos2.y = pos1.y + 6.0f;
    pos2.z = pos1.z;
    
    hp2 = bhCollisionCheckLine(&pos1, &pos2);
    if (hp2 == NULL)
    {
        pos1.x = ofp.x + (epw->px + trans.x);
        pos1.y = 6.0f + (ofp.y + (epw->py + trans.y));
        pos1.z = ofp.z + (epw->pz + trans.z);
        pos2.x = pos1.x - (10.0f * njSin(epw->ay));
        pos2.y = ofp.y + (epw->py + trans.y);
        pos2.z = pos1.z - (10.0f * njCos(epw->ay));
        hp2 = bhCollisionCheckLine(&pos1, &pos2);
    }
    
    if ((hp1 != NULL) && (hp2 != NULL))
    {
        epw->ay += dir * 1820;
        return 1;
    }
    
    if ((hp1 != NULL) && (hp2 == NULL))
    {
        if (hp1->type == 7)
        {
            epw->yn = 6.0f + hp1->py;
        } 
        else
        {
            epw->yn = 6.0f + (hp1->py + hp1->h);
        }
        ret = 1;
        epw->yn -= trans.y + ofp.y;
    }
    
    if ((hp1 == NULL) && (hp2 != NULL))
    {
        if (hp2->type == 7)
        {
            epw->yn = (hp2->py + hp2->h) - 6.0f;
        } 
        else
        {
            epw->yn = hp2->py - 6.0f;
        }
        ret = 1;
        epw->yn -= trans.y + ofp.y;
    }
    
    pos2.x = pos1.x - (3.0f * njSin(epw->ay));
    pos2.y = (ofp.y + (epw->py + trans.y)) - 5.0f;
    pos2.z = pos1.z - (3.0f * njCos(epw->ay));

    if (bhCheckWallType(&pos2, 0, 2.0f, 10.0f) != NULL)
    {
        epw->ay += dir * 1820;
        ret = 1;
    }
    return ret;
}

// 100% matching!
void bhEne06_PlayerControl(BH_PWORK* epw)
{
    // Not present in DWARF
    float dx, dz;

    switch (plp->mode2)
    {
    case 0:
        break;
    default:
        return;
    }

    switch (plp->mode3)
    {        
    case 0:
        plp->flg &= ~0x40000;
        plp->flg |= 0x10004;
        plp->mnwP = epw->mnwP;
        plp->mtn_no = 20;
        plp->frm_no = 0;
        plp->hokan_count = 5;
        plp->hokan_rate = 52428;
        plp->mtn_add = 65536;
        plp->ct1 = 8;
        plp->mode3++;
        break;
        
    case 1:

        if (plp->ct1 > 0)
        {
            plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
            plp->ct1--;
        }
        if (plp->frm_no == 0)
        {
            plp->mnwP = plp->mnwPb;
            
            plp->flg &= ~0x10004;
            plp->flg |= 8;
            plp->at_flg = 0;
            plp->stflg &= ~0x10000;
            
            *(int*)&plp->mode0 = 1;
            *(int*)epw->exp1 &= ~1;
        }
        
        dx = plp->mlwP->owP[5].mtx[12] - plp->px;
        dz = plp->mlwP->owP[5].mtx[14] - plp->pz;
        
        plp->px += dx;
        plp->pz += dz;
        
        bhCheckWall(plp);
        
        plp->px -= dx;
        plp->pz -= dz;
    }
}

// 100% matching!
void bhEne06_SetRinpunEffect(BH_PWORK* epw, int num, int flg)
{
    int eno;
	float size;
	
    while (0 < num)
    {
        sys->ef.id = 260;
        sys->ef.flg = 1;
        sys->ef.type = flg;
        size = 0.6f + (0.4f * njRandom());
        sys->ef.sy = sys->ef.sx = size;
        sys->ef.sz = 1.0f;
        sys->ef.ay = (int)((epw->ay + 18204) + (29127.0f * njRandom()));
        size = 8.0f * njRandom();
        sys->ef.px = epw->px - (size * njSin(sys->ef.ay));
        sys->ef.pz = epw->pz - (size * njCos(sys->ef.ay));
        sys->ef.py = (epw->py + (8.0f * njRandom())) - 4.0f;
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {            
            eff[eno].stflg |= 0x20;            
            eff[eno].txp[0] = epw->mdl[1].texP;
            eff[eno].tex_id = 1;            
        }
        break;
    }     
}

// 100% matching!
void bhEne06_HitMark(BH_PWORK* epw)
{
	int i;
	int range;
	BLOOD_TBL* blp;    
	NJS_POINT3 ofp;

    blp = &BloodTbl[epw->djnt_no];   
	i = 0;
	if (epw->comb_flg & 0x10) i = 0;
	if (epw->comb_flg & 0x20) i = 1;
	if (epw->comb_flg & 0x40) i = 2;
    
    if (DmgReact[epw->wpnr_no].type[i] >= 0)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[i], epw->djnt_no, &ofp, 0);
        if (DmgReact[epw->wpnr_no].bloodstain[i] != 0)
        {
            bhEne_SetBloodstain(epw, 0, epw->djnt_no, &ofp);
        }
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0))
    {
        range = 0;
        do
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;
            ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
            ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * njRandom()), (int)(40.0f * njRandom()) + 20);
            range++;
        } while (range < 4);
    }
    
    if (DmgReact[epw->wpnr_no].exef & 2)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if (DmgReact[epw->wpnr_no].exef & 4)
    {
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF201010U);
        epw->mdflg |= 0x400;
    }
}

// 100% matching!
int bhEne06_DeadCheck(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_VECTOR vec;
    int ang;
    int w;
    float mov;
    O_WORK* owk;
    int i;     
    int joint[2] = { 17, 21 };

    for (i = 0; i < 2; i++)
    {
        owk = &plp->mlwP->owP[joint[i]];
        pos.x = owk->mtx[12];
        pos.y = owk->mtx[13];
        pos.z = owk->mtx[14];
        
        vec.x = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x88)) - pos.x;
        vec.y = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x8C)) - pos.y;
        vec.z = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x90)) - pos.z;
        
        mov = njScalor(&vec);

        w = bhArcTan2(owk->mtx[8], owk->mtx[10]);

        ang = (short)(w - *(int *)((char *)epw->exp0 + ((i) * 4) + 0xA0));
        if (ang < 0)
        {
            ang = -ang;
        }

        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x88) = pos.x;
        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x8C) = pos.y;
        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x90) = pos.z;
       
        *(int *)((char *)epw->exp0 + ((i) * 4) + 0xA0) = w;
    
        if ((mov > 0.1f || 182 < ang) && (njDistanceP2P((NJS_POINT3*)&epw->px, &pos) < 2.0f))
        {
            return 1;            
        }
    }
    return 0;
}
