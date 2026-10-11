#include "../../../ps2/veronica/prog/en26.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/en01b.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/Motion.h"

#pragma optimization_level 4
#pragma divbyzerocheck on

// ENEMY: Anatomist Zombie 

int En26_PlyMtn_OffsetTbl[4] =
{
    100, 100, 100, 100
};

const char en26_flipTree[21] =
{
    0, 1, 6, 7, 8, 9, 2, 3, 4, 5,
    10, 11, 12, 13, 17, 18, 19, 14, 15, 16,
    255
};

EN26_MTN_WORK en26_mtn_tbl[16] =
{
    {
        25,
        {
            { 8, 0, 10 },
            { 7, 11, 43 },
            { 8, 44, 59 }
        }
    },
    {
        16,
        {
            { 8, 0, 12 },
            { 7, 13, 28 },
            { 8, 29, 35 }
        }
    },
    {
        17,
        {
            { 0, 0, 15 },
            { 8, 16, 26 },
            { 0, 27, 60 }
        }
    },
    {
        0,
        {
            { 1, 0, 69 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        15,
        {
            { 1, 0, 69 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        3,
        {
            { 7, 0, 14 },
            { 7, 15, 33 },
            { -1, 0, 0 }
        }
    },
    {
        4,
        {
            { 1, 0, 16 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        5,
        {
            { 0, 0, 7 },
            { 8, 8, 18 },
            { 0, 19, 40 }
        }
    },
    {
        27,
        {
            { 0, 0, 7 },
            { 8, 8, 18 },
            { 0, 19, 40 }
        }
    },
    {
        6,
        {
            { 1, 0, 11 },
            { 0, 12, 17 },
            { 1, 18, 39 }
        }
    },
    {
        28,
        {
            { 1, 0, 11 },
            { 0, 12, 17 },
            { 1, 18, 39 }
        }
    },
    {
        7,
        {
            { 1, 0, 26 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        8,
        {
            { 1, 0, 37 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        1,
        {
            { 0, 0, 17 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    },
    {
        26,
        {
            { 0, 0, 6 },
            { 1, 7, 15 },
            { 0, 16, 40 }
        }
    },
    {
        -1,
        {
            { -1, 0, 0 },
            { -1, 0, 0 },
            { -1, 0, 0 }
        }
    }
};

EN26_MTN2_WORK en26_mtn_tbl2[18] =
{
    {
        15,
        {
            { 0, 16847639 },
            { -1, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        25,
        {
            { 10, 70414 },
            { 12, 70415 },
            { 43, 70414 },
            { 45, 70415 }
        }
    },
    {
        16,
        {
            { 12, 70414 },
            { 14, 70415 },
            { 28, 70414 },
            { 30, 70415 }
        }
    },
    {
        3,
        {
            { 16, 8963 },
            { 35, 8963 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        4,
        {
            { 17, 8963 },
            { 26, 8963 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        5,
        {
            { 9, 70414 },
            { 11, 70415 },
            { 16, 70414 },
            { 18, 70415 }
        }
    },
    {
        27,
        {
            { 9, 70414 },
            { 11, 70415 },
            { 16, 70414 },
            { 18, 70415 }
        }
    },
    {
        6,
        {
            { 12, 70414 },
            { 14, 70415 },
            { 20, 70414 },
            { 22, 70415 }
        }
    },
    {
        28,
        {
            { 12, 70414 },
            { 14, 70415 },
            { 20, 70414 },
            { 22, 70415 }
        }
    },
    {
        13,
        {
            { 5, 70414 },
            { 16, 70414 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        17,
        {
            { 9, 70414 },
            { 11, 70415 },
            { 40, 70415 },
            { -1, 0 }
        }
    },
    {
        2,
        {
            { 2, 16782102 },
            { 24, 8960 },
            { 38, 8960 },
            { 60, 8960 }
        }
    },
    {
        12,
        {
            { 24, 8960 },
            { 38, 8960 },
            { 60, 8960 },
            { -1, 0 }
        }
    },
    {
        1,
        {
            { 17, 16786196 },
            { -1, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        26,
        {
            { 5, 70414 },
            { 15, 70414 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        9,
        {
            { 25, 8960 },
            { 47, 8960 },
            { 66, 8960 },
            { -1, 0 }
        }
    },
    {
        14,
        {
            { 8, 8960 },
            { 30, 8960 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        -1,
        {
            { -1, 0 },
            { -1, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    }
};

EN26_MTN2_WORK en26_mtn_tbl3[6] =
{
    {
        2,
        {
            { 8, 0 },
            { 24, 0 },
            { 60, 0 },
            { -1, 0 }
        }
    },
    {
        12,
        {
            { 7, 0 },
            { 24, 0 },
            { 60, 0 },
            { -1, 0 }
        }
    },
    {
        1,
        {
            { 13, 1 },
            { -1, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        9,
        {
            { 25, 0 },
            { 47, 0 },
            { 66, 0 },
            { -1, 0 }
        }
    },
    {
        14,
        {
            { 7, 0 },
            { 30, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    },
    {
        -1,
        {
            { -1, 0 },
            { -1, 0 },
            { -1, 0 },
            { -1, 0 }
        }
    }
};

const char en26_tree[8][8] =
{
    { 0, 1, 6, 7, 8, 255, 0, 0 }, 
    { 0, 1, 2, 3, 4, 255, 0, 0 }, 
    { 0, 1, 10, 11, 17, 18, 19, 255 }, 
    { 0, 1, 10, 11, 14, 15, 16, 255 }, 
    { 10, 11, 17, 18, 19, 255, 0, 0 },
    { 10, 11, 14, 15, 16, 255, 0, 0 },
    { 0, 1, 6, 7, 255, 0, 0, 0 },
    { 0, 1, 10, 11, 12, 255, 0, 0 }
};

EN26_WPNDAMAGE_WORK En26_WpnDamageTbl[22] =
{
    {0x0000, 0, 0, 0, 0, 0, 0},
    {0x0000, 0, 0, 0, 0, 0, 0},
    {0x0C02, 0, 3, 2, 3, 5, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0112, 2, 7, 2, 3, 3, 3},
    {0x0112, 0, 1, 2, 3, 3, 3},
    {0x0EC2, 0, 7, 2, 3, 5, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 4, 7, 2, 3, 3, 3},
    {0x0039, 2, 9, 2, 9, 3, 9},
    {0x0EC2, 0, 7, 2, 3, 5, 3},
    {0x011D, 2, 3, 2, 3, 3, 3},
    {0x111C, 2, 1, 2, 3, 3, 3}, 
    {0xC100, 0, 1, 2, 3, 3, 3},
    {0x511C, 0, 1, 2, 3, 3, 3},
    {0x4000, 0, 1, 2, 3, 3, 3},
    {0x6000, 2, 1, 2, 3, 3, 3},
    {0x111C, 2, 1, 2, 3, 3, 3},
    {0x6000, 2, 1, 2, 3, 3, 3},
    {0x0FC2, 0, 1, 2, 3, 3, 3}
};

static COMBWEP_WORK CombWepTbl[21] =
{
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 90, { 10, 0, 0 }, 90, 5 },
    { 25, { 9, 5, 4 }, 60, 0 },
    { 25, { 9, 5, 4 }, 60, 0 },
    { 25, { 9, 5, 4 }, 60, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 25, { 9, 5, 4 }, 60, 0 },
    { 180, { 0, 0, 0 }, 0, 0 },
    { 25, { 9, 5, 4 }, 0, 0 },
    { 40, { 8, 5, 4 }, 40, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 100, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 },
    { 0, { 0, 0, 0 }, 0, 0 }
};

static COMBJOINT_WORK CombJointTbl[20] =
{
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 }
};


// int en26_hp_tbl[16][2]; // unused


EN26_FIRE_WORK en26_fire_tbl[14] =
{
    { 11, 2.5f, 1.0f, {  0.5f,  3.0f, -1.0f } },
    { 11, 1.5f, 1.0f, { -0.5f,  1.0f, -1.0f } },
    { 11, 4.0f, 1.0f, {  0.5f,  2.5f,  1.0f } },
    { 11, 2.0f, 1.0f, { -0.5f,  1.0f,  1.0f } },
    { 14, 2.5f, 1.0f, {  0.0f,  0.0f,  0.0f } },
    { 15, 2.0f, 1.0f, {  0.0f,  0.0f,  0.0f } },
    { 17, 2.0f, 1.0f, {  0.5f, -0.5f,  0.0f } },
    { 17, 2.5f, 1.0f, { -1.0f,  0.0f,  0.0f } },
    {  2, 1.5f, 2.0f, {  0.0f, -0.5f,  0.0f } },
    {  3, 2.5f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    {  4, 2.0f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    {  6, 3.0f, 1.0f, {  0.0f, -3.0f, -1.0f } },
    {  8, 2.5f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    {  9, 3.0f, 1.0f, {  0.0f, -2.0f,  0.5f } },
};

CPCL Ene26CapColTab[17] =
{
    {  1, 11, 16 },
    { 11, 11, 18 }, 
    {  0, 16,  0 }, 
    { 11, 11, 18 }, 
    {  0, 30,  0 }, 
    { 12, 13,  6 }, 
    { 13, 13, 11 },
    {  0,  9, -2 },
    { 14, 15,  6 }, 
    { 15, 16,  5 }, 
    { 17, 18,  6 },
    { 18, 19,  5 },
    {  2,  3,  9 },
    {  3,  4,  8 },
    {  6,  7,  9 },
    {  7,  8,  8 },
    {  0,  0,  0 }
};

char En26SdwTab[5] =
{
    0, 3, 4, 12, 255
};
BT_WORK en26prt_blood_tbl[20] =
{
    {      0,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f }, 
    {     11,   0.0f,   2.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, 
    {      2,   0.0f,   0.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, 
    {      3,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      4,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      3,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      6,   0.0f,   0.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, 
    {      7,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      8,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      7,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, 
    {      0,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f }, 
    {     11,   0.0f,   3.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, 
    {     11,   0.0f,   3.5f,   1.8f,   2.0f,   1.0f,   5.0f,   1.5f }, 
    {     11,   0.0f,   3.5f,   1.8f,   2.0f,   1.0f,   5.0f,   1.5f }, 
    {     14,   0.0f,   0.0f,   0.5f,   0.2f,   0.5f,   5.0f,   1.5f }, 
    {     15,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, 
    {     16,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, 
    {     17,   0.0f,   0.0f,   0.5f,   0.2f,   0.5f,   5.0f,   1.5f }, 
    {     18,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, 
    {     19,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }  
};

EN26_KAMI_WORK en26_keff_tbl[5] =
{
    {  2, { 28, 38, 62, -1 } },
    { 12, { 24, 38, 60, -1 } },
    {  9, { 25, 47, 66, -1 } },
    { 14, {  9, 32, -1, -1 } },
    { -1, { -1, -1, -1, -1 } }
};

void (*bhEne26_Mode0[6])(BH_PWORK *) =
{
    bhEne26_Init,
    bhEne26_Move,
    bhEne26_Nage,
    bhEne26_Damage,
    bhEne26_Die,
    bhEne_Event
};

void(*bhEne26_MoveMode2[17])(BH_PWORK*) =
{
    bhEne26_MV00,
    bhEne26_MV01,
    bhEne26_MV02,
    bhEne26_MV03,   
    NULL,
    bhEne26_MV05,     
    bhEne26_MV06,
    bhEne26_MV07,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,    
    bhEne26_MV16 
};

void(*bhEne26_NageMode2[1])(BH_PWORK*) =
{
    bhEne26_NG00
};

void (*bhEne26_DamageMode2[16])(BH_PWORK*) =
{
    bhEne26_DG00, 
    bhEne26_DG01, 
    bhEne26_DG02, 
    bhEne26_DG03, 
    bhEne26_DG04, 
    NULL,         
    NULL, 
    NULL,
    NULL, 
    NULL,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    bhEne26_DG15
};

void(*bhEne26_DieMode2[1])(BH_PWORK*) =
{
    bhEne26_DD00
};

void(*bhEne26_PlyDmgMode[1])(BH_PWORK*, BH_PWORK*) =
{
    bhEne26_PlyDG00
};

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne26(BH_PWORK* epw)
{
    bhEne26_DmgCheck(epw);
    bhEne26_MainLoop(epw, plp);

    if (epw->flg & 4)
    {
        epw->flg = epw->flg & ~4;
    }

    if (EXP0_UC(0x2F) > 0)
    {
        EXP0_UC(0x2F)--;
    }

    if (EXP0_I(0x30) > 0)
    {
        EXP0_I(0x30)--;
    }

    if (EXP0_I(0x34) > 0)
    {
        EXP0_I(0x34)--;
    }
    bhEne26_CollCheck(epw);
    
    if (EXP0_I(0x40) & 0x80000)
    {
        bhEne26_PlayerLink(epw, plp);
    }
    
    bhEne26_CalcEnemy(epw);
}

// 100% matching!
void bhEne26_DmgCheck(BH_PWORK* epw)
{
    int ang;
    
    if ((epw->flg & 0x4) && !(epw->flg & 0x2))        
    {    
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if (epw->total_dam != 0)
        {
            if ((EXP0_I(0x44) & 0x40) &&
                (epw->flr_no <= plp->flr_no) &&
                !(WpnTab[epw->wpnr_no].flg & 0x20) &&
                !(WpnTab[epw->wpnr_no].flg & 0x20000000) &&
                (plp->at_flg & 0x2))
            {
                return;
            }
    
            bhEne26_DamageAdd(epw, En26_WpnDamageTbl);
        
            if ((epw->mode0 >= 3) ||
                (EXP0_I(0x40) & 0x80) ||
                (EXP0_I(0x40) & 0x40000) && (epw->mode0 == 1) && (epw->mode3 == 0))
            {
                return;
            }
       
            EXP0_I(0x40) |= 0x200400;
            EXP0_I(0x48) = 0;
        
            if (epw->comb_flg & 4)
            {
                EXP0_I(0x40) |= 0x2000;
            } 
            else
            {
                EXP0_I(0x40) &= ~0x2000;
            }
        
            ang = njArcTan2(epw->dvx, epw->dvz);
        
            if ((unsigned short)(ang - epw->ay) <= NJM_DEG_ANG(180.0f))
            {
                EXP0_I(0x44) |= 0x20;
            } 
            else
            {
                EXP0_I(0x44) &= ~0x20;
            }
        
            bhEne26_DmgCheckType00(epw, En26_WpnDamageTbl);
            
            if (EXP0_I(0x78) != -1)
            {
                if (epw->hp < 0)
                {
                    bhEne26_SePlay(epw, 16786197);
                } 
                else
                {
                    bhEne26_SePlay(epw, 16786196);
                }
            }
            bhEne26_SetBlood(epw, En26_WpnDamageTbl);
        }
    } 
}
// 100% matching!
void bhEne26_DamageAdd(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
	int* d;
	int low_flg;    
	int i;
 
    low_flg = 0;
    if (epw->hp >= 0)
    {
        epw->hp -= epw->total_dam;
    }

    wp_tbl += epw->comb_wep;

    for (d = &epw->dam[1], i = 1; i < (int)epw->mlwP->obj_num; i++, d++)
    {
        if (*d > 0)
        {
            if (epw->djnt_no == 3 || epw->djnt_no == 4 ||
                epw->djnt_no == 7 || epw->djnt_no == 8)
            {
                low_flg = 1;
            }
            if (epw->djnt_no == 13)
            {
                EXP0_I(0x78) += *d;
            }
        }
    }
    
    if ((wp_tbl->flg & 0x8000) && (EXP0_I(0x34) <= 0))
    {
        bhEne_SetSanEffect(epw, epw->djnt_no, en26prt_blood_tbl);
        EXP0_I(0x34) = 10;
    }

    if (wp_tbl->flg & 0x1000)
    {
        if (low_flg == 0)
        {
            bhEne26_LinkFireEffect(epw, (rand() % 4) + 4);
        }
        else
        {         
            bhEne26_LinkFireEffect(epw, (rand() % 4) + 8);
        }
        EXP0_I(0x40) |= 0x10000;
    }
    else if (wp_tbl->flg & 0x2000)
    {
        bhEne26_LinkFireEffect(epw, (rand() % 4) + 4);
        EXP0_I(0x40) |= 0x10000;
        EXP0_I(0x3C) = 0xFF000000U;
        epw->mdflg |= 0x400;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, EXP0_I(0x3C));
    }
}

// 100% matching!
void bhEne26_LinkFireEffect(BH_PWORK* epw, int type)
{
    EN26_FIRE_WORK* eff_p;
    char* ftbl_p;
    int eno;
    int i;   
    int time;
    int flg;  

    char fire_tbl[12][8] =
    {
        {  0,  1,  2,  3,  4,  6,  8, 255 }, 
        {  0,  1,  2,  3,  5,  6,  9, 255 },
        {  0,  1,  2,  3,  4,  7, 11, 255 }, 
        {  0,  1,  2,  3,  5,  7, 12, 255 }, 
        {  0,  1,  2,  3,  4,  6, 255, 255 }, 
        {  0,  1,  2,  3,  5,  6, 255, 255 }, 
        {  0,  1,  2,  3,  4,  7, 255, 255 }, 
        {  0,  1,  2,  3,  5,  7, 255, 255 },
        { 11, 10, 13, 255, 255, 255, 255, 255 }, 
        {  8, 10, 13, 255, 255, 255, 255, 255 },
        {  9, 10, 13, 255, 255, 255, 255, 255 },
        { 10, 12, 13, 255, 255, 255, 255, 255 }
    };

    sys->ef.id = 352;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.sz = 0.0f;
    sys->ef.px = 0.0f;
    sys->ef.py = 0.0f;
    sys->ef.pz = 0.0f;
    sys->ef.ay = 0;
    
    for (i = 0, ftbl_p = fire_tbl[type]; i < 8; i++, ftbl_p++)
    {
        eff_p = &en26_fire_tbl[*ftbl_p];
        if (*ftbl_p != -1)
        {
            flg = 1 << *ftbl_p;
            if (!(EXP0_I(0x38) & flg))
            {
                EXP0_I(0x38) |= flg;
                time = rand() % 5;
                sys->ef.sy = sys->ef.sx = eff_p->size;
                sys->ef.type = 0;
                eno = bhSetEffectTb(&sys->ef, &eff_p->ofs, (unsigned char*)epw, eff_p->obj);
                if (eno != -1)
                {
                    eff[eno].zn = eff_p->len;
                    eff[eno].ct3 = time;
                }
                sys->ef.type = 1;
                eno = bhSetEffectTb(&sys->ef, &eff_p->ofs, (unsigned char*)epw, eff_p->obj);
                if (eno != -1)
                {
                    eff[eno].zn = eff_p->len;
                    eff[eno].ct3 = time;
                }
            }
        }
    } 
}

// 100% matching!
void bhEne26_DmgCheckType00(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
    int act;

    // not present in DWARF
    EN26_WPNDAMAGE_WORK* wp;
    
    wp = &wp_tbl[epw->wpnr_no];
    act = wp->nm_act;
    if ((wp->flg & 0x10) && !(EXP0_I(0x40) & 0x440000) && (bhEne26_CheckExpHead(epw) != 0))
    {
        epw->hp = -1;
        bhEne26_ExpHeadEffect(epw, 0);
        bhEne26_NeckBloodEffect(epw, 0);
        EXP0_I(0x78) = -1;
        bhEne26_SePlay(epw, 4869);
    }
    
    if (epw->hp < 0)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        act = wp->dw_act;
    } 
    else if (epw->comb_flg & 1)
    {
        epw->comb_pnt = 0;
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        act = wp->cb_act;
    }
    
    if (act == 0)
    {
        if (!(EXP0_I(0x40) & 0x8000000))
        {
            EXP0_I(0x40) |= 0x8000000;
            EXP0_UC(0x2C) = 0;
        }
    }
    else if (act == 1)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 1;
        epw->mode3 = 0;
    }
    else if (act == 2)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
    else if (act == 5)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 3;
        epw->mode3 = 0;
    }
    else if (act == 3)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;

        if ((wp->flg & 0x100) && (epw->hp > 0))
        {
            if (rand() % 10 >= 3)
            {
                epw->mode2 = 2;
                return;
            }
        }

        if (epw->comb_flg & 4)
        {
            if (wp->flg & 0x200)
            {
                epw->mode2 = (rand() % 3 == 0) ? 3 : 4;
            } 
            else
            {
                epw->mode2 = 4;
            }
        } 
        else
        {
            epw->mode2 = 3;
        }

    }
}

// 100% matching!
int bhEne26_CheckExpHead(BH_PWORK* epw)
{
    if (EXP0_I(0x78) > 0)
    {
        return 1;
    }

    switch (epw->wpnr_no)
    {
    case 11:
    case 14:
        if ((epw->flr_no == plp->flr_no) && (EXP0_F(0x54) < 10.0f) && (plp->at_flg & 4))
        {
            return 1;
        }
        break;
        
    case 6:
        if (((epw->flr_no == plp->flr_no) &&
             (epw->comb_flg & 0x10)) &&
             (plp->at_flg & 6) &&
             (epw->djnt_no == 1 || ((epw->djnt_no == 10) || epw->djnt_no == 11 || epw->djnt_no == 12 || epw->djnt_no == 13)))
        {
          return 1;
        }
        break;
        
    case 19:
        if (((epw->djnt_no >= 10) && (19 >= epw->djnt_no)) || (epw->djnt_no == 1))
        {
          return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne26_SetBlood(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
	O_WORK* owk;
	NJS_POINT3 ofp;    
	int obj_no;

    // not from DWARF
    EN26_WPNDAMAGE_WORK* wp;
    
    wp = &wp_tbl[epw->wpnr_no];
    if (!(wp->flg & 0x4000))
    {
        if ((epw->djnt_no == 11) || (epw->djnt_no == 1) || (epw->djnt_no == 10))
        {
            ofp.x = -epw->dvx;
            ofp.y = -epw->dvy;
            ofp.z = -epw->dvz;
            bhLinkBlood(epw, epw->djnt_no, &ofp, 0.5f);
        }
        
        if ((epw->comb_flg & 1) || (epw->hp < 0))
        {
            if ((EXP0_I(0x30) <= 0) && (EXP0_I(0x78) != -1))
            {
                EXP0_I(0x30) = 20;

                if ((1 < epw->djnt_no) && (epw->djnt_no < 10))
                {
                    ofp.x = ofp.z = 0.0f;
                    ofp.y = -2.0f;
                    obj_no = 1;
                } 
                else
                {
                    ofp.x = ofp.z = 0.0f;;
                    ofp.y = 2.5f;
                    obj_no = 11;
                }

                if (wp->cb_blood == 9)
                {
                    if (epw->comb_flg & 0x40)
                    {
                        bhEne_SetBlood4(epw, obj_no, &ofp, 8, 3);
                    } 
                    else
                    {
                        bhEne_SetBlood4(epw, obj_no, &ofp, 8, 1);
                    }
                    
                    ofp.x = ofp.z = 0.0f;
                    ofp.y = 2.5f;
                    bhEne_SetBlood2(epw, 9, &ofp, plp->way);
                } 
                else
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 0);
                }
            }
        }
        else
        {
            if (wp->nm_blood == 9)
            {
                bhEne_SetBlood2(epw, 9, &ofp, plp->way);

                if ((1 < epw->djnt_no) && (epw->djnt_no < 10))
                {
                    ofp.x = ofp.z = 0.0f;
                    ofp.y = -2.0f;
                    obj_no = 1;
                } 
                else
                {
                    ofp.x = ofp.z = 0.0f;
                    ofp.y = 2.5f;
                    obj_no = 11;
                }
                
                if (epw->comb_flg & 0x40)
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 3);
                } 
                else
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 0);
                }
            } 
            else
            {
                bhEne_SetBlood(epw, wp->nm_blood, en26prt_blood_tbl);
            }
        }
    }
    if ((wp->flg & 1) && !(epw->comb_flg & 0x40) && (EXP0_I(0x78) != -1) && (epw->hp < 0))
    {
        owk = &epw->mlwP->owP[epw->djnt_no];
        ofp.x = owk->mtx[12];
        ofp.y = owk->mtx[13];
        ofp.z = owk->mtx[14];
        bhEne_SetNikuhenEffect2(epw, 0, &ofp, 4, 7);
    }
}

// 100% matching!
void bhEne26_MainLoop(BH_PWORK* epw, BH_PWORK* pl)
{
    if (epw->mode0 != 6)
    {
        bhEne26_Mode0[epw->mode0](epw);
    }
    bhEne26_PlayerControl(epw, pl);
    bhEne26_SetMtn(epw);
    bhEne26_SearchNeck(epw, pl);
}

// 100 matching!
void bhEne26_PlayerControl(BH_PWORK* epw, BH_PWORK* pl)
{
    if ((EXP0_I(0x40) & 0x20000) && (pl->mode0 == 4 || pl->mode0 == 6))
    {
        bhEne26_PlyDmgMode[pl->mode2](pl, epw);
    }
}

// 100% matching!
int bhEne26_SetMtn(BH_PWORK* epw)
{
    static int rot_tbl[4][8] =
    {
        { 0x800, 0xA00, 0x1000, 0xE00, 0xC00, 0x800, 0x400, 0x200 },
        { -0x800, -0xA00, -0x1000, -0xE00, -0xC00, -0x800, -0x400, -0x200 },
        { 0x800, 0xA00, 0x1000, 0xE00, 0xC00, 0x800, 0x400, 0x200 },
        { -0x800, -0xA00, -0x1000, -0xE00, -0xC00, -0x800, -0x400, -0x200 }
    };
    NJS_CNK_OBJECT* obj;
    int ret;
    int frm;
    int h_count;   
    int frm_no;
   
    if (EXP0_I(0x40) & 0x10)
    {
        return 0;
    }
    
    frm = epw->frm_no / 65536;
    if (EXP0_I(0x40) & 0x8000000)
    {
        obj = &epw->mlwP->objP[10];
        if (EXP0_I(0x40) & 0x2000)
        {
            obj->ang[0] = rot_tbl[0][EXP0_UC(0x2C)];
            if (EXP0_I(0x44) & 0x20)
            {
                obj->ang[1] = rot_tbl[2][EXP0_UC(0x2C)];
            } 
            else
            {
                obj->ang[1] = rot_tbl[3][EXP0_UC(0x2C)];
            }
        } 
        else
        {
            obj->ang[0] = rot_tbl[1][EXP0_UC(0x2C)];
            if (EXP0_I(0x44) & 0x20)
            {
                obj->ang[1] = rot_tbl[3][EXP0_UC(0x2C)];
            } 
            else 
            {
                obj->ang[1] = rot_tbl[2][EXP0_UC(0x2C)];
            }
        }

        EXP0_UC(0x2C)++;
        if (EXP0_UC(0x2C) >= 8)
        {
            EXP0_I(0x40) &= ~0x8000000;
            EXP0_UC(0x2C) = 0;
        }
    }
    
    ret = bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if ((EXP0_I(0x44) & 0x80) && (epw->mtn_no == 25))
    {
        h_count = epw->hokan_count;
        frm_no = epw->frm_no;
        epw->mlwP->objP += 10;
        epw->mlwP->owP += 10;
        epw->mlwP->obj_num -= 10;
        epw->mtn_no = 23;
        epw->frm_no = EXP0_I(0x80);
        ret = bhSetMotion(epw, 65536, epw->mtn_md, epw->mtn_tp);
        EXP0_I(0x80) = epw->frm_no;
        epw->mtn_no = 25;
        epw->mlwP->obj_num += 10;
        epw->mlwP->owP -= 10;
        epw->mlwP->objP -= 10;
        epw->hokan_count = h_count;
        epw->frm_no = frm_no;
    }

    if (EXP0_I(0x40) & 0x1000000)
    {
        obj = epw->mlwP->objP;
        obj->pos[0] = obj->pos[2] = 0.0f;
        bhEne_GetTranslateMtn(epw, frm, 0);
    } 
    else if (EXP0_I(0x40) & 0x2000000)
    {
        obj = epw->mlwP->objP;
        obj->pos[0] = obj->pos[2] = 0.0f;
        bhEne_GetTranslateMtn2(epw, frm, 0);
        bhAddSpeed(epw, 0);
    }
    
    if (ret != 0)
    {
        epw->flg |= 0x2000000;
    } 
    else
    {
        epw->flg &= ~0x2000000;
    }

    if (epw->mode0 < 5)
    {
        bhEne26_KamiEffect(epw, frm);
    }
    
    if (EXP0_I(0x40) & 0x10000000)
    {

        if (epw->mtn_no == 2) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_kamikami[frm];
        } 
        else if (epw->mtn_no == 12) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_kamikami2[frm];
        } 
        else if (epw->mtn_no == 25 || epw->mtn_no == 16) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_mogmog[frm % 40];
        } 
        else 
        {
            epw->mdflg &= ~2;
            epw->shp_ct = 0.0f;
        }
    }
    bhEne26_CheckMtnTbl(epw, frm);
    return ret;
}

// 100% matching!
void bhEne26_CheckMtnTbl(BH_PWORK* epw, int frm)
{
	EN26_MTN_WORK* mtbl;
	EN26_MTN2_WORK* mtbl2;
	EN26_MTN2_WORK* mtbl3;
    int i;   
  
    mtbl = en26_mtn_tbl;
    mtbl2 = en26_mtn_tbl2;
    mtbl3 = en26_mtn_tbl3;
 
    {
        NJS_VECTOR vec = {0.0f, 0.0f, 0.0f};
	    NJS_VECTOR vec1 = {0.0f, 0.0f, 0.0f};
	    NJS_VECTOR vec2 = {0.0f, -1.0f, -1.9f};  

        if (sys->rmthp != epw->mnwP)
        {
            if (epw->flg & 0x40000)
            {
                while (mtbl->no != -1)
                {                    
                    if (epw->mtn_no == 0)
                    {
                        if (epw->flg & 0x40000)
                        {
                            if (epw->flg & 0x80000) 
                            {
                                bhCalcFixOffset(epw, en26_tree[0], &vec1, &vec);
                                epw->px -= vec.x;
                                epw->pz -= vec.z;
                                break;
                            } 
                            else
                            {
                                bhCalcFixOffset(epw, en26_tree[1], &vec1, &vec);
                                epw->px -= vec.x;
                                epw->pz -= vec.z;
                                break;
                            }
                            
                        } else break;
                    } 
                    else
                    {
                        if (mtbl->no == epw->mtn_no)
                        {
                            for (i = 0; i < 3; i++)
                            {
                                if ((mtbl->fmtn[i].type != -1) &&
                                    (frm >= mtbl->fmtn[i].s_frm) &&
                                    (frm <= mtbl->fmtn[i].e_frm))
                                {
                                    switch (mtbl->fmtn[i].type)
                                    {
                                    case 0:
                                        if (epw->mtn_md & 2)
                                        {
                                            bhCalcFixOffset(epw, en26_tree[1], &vec1, &vec);
                                        }
                                        else
                                        {
                                            bhCalcFixOffset(epw, en26_tree[0], &vec1, &vec);
                                        }
                                        break;
                    
                                    case 1:
                                        if (epw->mtn_md & 2)
                                        {
                                            bhCalcFixOffset(epw, en26_tree[0], &vec1, &vec);
                                        }
                                        else
                                        {
                                            bhCalcFixOffset(epw, en26_tree[1], &vec1, &vec);
                                        }
                                        break;
                    
                                    case 7:
                                        if (epw->mtn_md & 2)
                                        {
                                            bhCalcFixOffset(epw, en26_tree[1], &vec2, &vec);
                                        }
                                        else
                                        {
                                            bhCalcFixOffset(epw, en26_tree[0], &vec2, &vec);
                                        }
                                        break;
                    
                                    case 8:
                                        if (epw->mtn_md & 2)
                                        {
                                            bhCalcFixOffset(epw, en26_tree[0], &vec2, &vec);
                                        }
                                        else
                                        {
                                            bhCalcFixOffset(epw, en26_tree[1], &vec2, &vec);
                                        }
                                        break;
                                    }                    
                                    if (epw->mtn_no == 16)
                                    {
                                        vec.x *= 1.2f;
                                        vec.z *= 1.2f;
                                    }
                    
                                    epw->px -= vec.x;
                                    epw->pz -= vec.z;
                    
                                    break;
                                }
                            }
                        }                    
                        mtbl++;                    
                    }
                }
            }
            while (mtbl2->no != -1) 
            {
                if (mtbl2->no == epw->mtn_no)
                {
                    for (i = 0; i < 4; i++)
                    {
                        if (mtbl2->atb[i].frm != -1) 
                        {
                            if (mtbl2->atb[i].frm == frm) 
                            {
                                bhEne26_SePlay(epw, mtbl2->atb[i].act);
                            }
                        }
                        else break;
                    }
                }                
                mtbl2++;
            }
            
            if (epw->mode0 < 5)
            {
                while (mtbl3->no != -1)
                {                    
                    if (mtbl3->no == epw->mtn_no) 
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (mtbl3->atb[i].frm != -1)
                            {
                                if (mtbl3->atb[i].frm == frm) 
                                {
                                    bhEne_SetVibration(mtbl3->atb[i].act);
                                }
                            }
                            else break;
                        }
                    }
                    mtbl3++;                              
                }   
            }
        }
    }
}

// 100% matching!
void bhEne26_SearchNeck(BH_PWORK* epw, BH_PWORK* pl)
{
    NJS_CNK_OBJECT* obj;

    if (epw->mode0 < 5)
    {
        if (EXP0_I(0x40) & 0x1000)
        {
            obj = &epw->mlwP->objP[10];
            obj->ang[1] = epw->wax;
            obj = &epw->mlwP->objP[13];
            obj->ang[1] = EXP0_I(0x50);            
        } 
        else
        {
            if ((EXP0_I(0x40) & 0x800) && (EXP0_UC(0x28) & 0x40) && (EXP0_F(0x54) < 35.0f)) 
            {
                obj = &epw->mlwP->objP[13];
                obj->ang[1] = EXP0_I(0x50);
                bhEne01_RotNeck(epw, 13, pl, 5);
                EXP0_I(0x50) = obj->ang[1];
            }
            else
            {
                obj = &epw->mlwP->objP[13];
                if (EXP0_I(0x50) != 0)
                {
                    if (EXP0_I(0x50) < 32768)
                    {
                        EXP0_I(0x50) -= 910;
                        if (EXP0_I(0x50) < 0)
                        {
                            EXP0_I(0x50) = 0;
                        }
                    } 
                    else
                    {
                        EXP0_I(0x50) += 910;
                        if (EXP0_I(0x50) >= 65536)
                        {
                            EXP0_I(0x50) = 0;
                        }
                    }
                }
                obj->ang[1] = EXP0_I(0x50);  
            }
        }    
    }
}

// 100% matching!
void bhEne26_CollCheck(BH_PWORK* epw)
{
	O_WORK* owk;
	ATR_WORK* hp;

    if (!(epw->flg & 2))
    {
        if (epw->flg & 8)
        {
            if (EXP0_I(0x40) & 0x100)
            {
                bhEne01_CollCheckPush(epw, ene);
            } 
            else
            {
                if (epw->flg & 0x80)
                {
                    owk = epw->mlwP->owP;
                    epw->aox = owk->mtx[12] - epw->px;
                    epw->aoz = owk->mtx[14] - epw->pz;
                    epw->aoy = 0.0f;
                } 
                else
                {
                    epw->aox = 0.0f;
                    epw->aoy = 0.0f;
                    epw->aoz = 0.0f;
                }
                if (!(EXP0_I(0x40) & 0x40))
                {
                    bhCheckPlayer(epw);
                    bhCheckEnemies(epw);
                }
            }
        }
        bhEne26_CollCheckWall(epw);
    }
    
    if (sys->st_flg & 0x100)
    {
        epw->mdflg &= ~0x40;
        hp = bhCheckFloorEffect(epw->flr_no, epw->px, epw->pz);
        if ((hp != NULL) && (hp->prm0 == 2))
        {
            epw->mdflg |= 0x40;
        }
    }
}

// 99.92% matching
void bhEne26_CollCheckWall(BH_PWORK* epw)
{
    NJS_POINT3 ps; 
    NJS_POINT3 ops;  
    NJS_POINT3 pd;
    NJS_POINT3 ps2;
    NJS_POINT3 ops2;    
    NJS_POINT3 pd2;   
    O_WORK* owk;

    // not present in DWARF
    int t;

    ps.x = plp->px;
    ps.y = plp->py;
    ps.z = plp->pz;
    
    *(ATR_WORK **)(epw->exp0 + 0x70) = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &ps);

    t = EXP0_I(0x40) & 0xF;
    
    if (t == 1 && epw->flg & 0x10)
    {
        ps.x = epw->px + epw->aox;
        ps.y = epw->py + epw->aoy;
        ps.z = epw->pz + epw->aoz;
        
        ops.x = epw->pxb + epw->aox;
        ops.y = epw->pyb + epw->aoy;
        ops.z = epw->pzb + epw->aoz;
        
        bhCheckDansa(epw);
        bhCheckWallEx(epw, &ps, &ops, epw->ar, epw->ah);
        
        epw->px += (ps.x - (epw->px + epw->aox));
        epw->py += (ps.y - (epw->py + epw->aoy));
        epw->pz += (ps.z - (epw->pz + epw->aoz));
        if (!(EXP0_I(0x40) & 0x8000000))
        {
            owk = epw->mlwP->owP;
            ops.x = owk[12].mtx[12];
            ops.z = owk[12].mtx[14];
            ops.y = epw->pyb;
            
            bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 5, 1);
            
            ps.y = epw->py;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 2.0f, 2.0f);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }        
    }        
    else if (t == 2)
    {
        ps.x = epw->px + epw->aox;
        ps.y = epw->py + epw->aoy;
        ps.z = epw->pz + epw->aoz;
       
        ops.x = epw->pxb + epw->aox;
        ops.y = epw->pyb + epw->aoy;
        ops.z = epw->pzb + epw->aoz;
        bhCheckDansa(epw);
        bhCheckWallEx(epw, &ps, &ops, epw->ar, epw->ah);
        
        epw->px += (ps.x - (epw->px + epw->aox));
        epw->py += (ps.y - (epw->py + epw->aoy));
        epw->pz += (ps.z - (epw->pz + epw->aoz));
        
        owk = epw->mlwP->owP;
        ops.x = owk[16].mtx[12];
        ops.z = owk[16].mtx[14];
        
        owk = epw->mlwP->owP;
        ops.x = (ops.x + owk[19].mtx[12]) / 2.0f;
        ops.z = (ops.z + owk[19].mtx[14]) / 2.0f;
        ops.y = epw->pyb;        
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[2], 7, 1);
        bhEne_CalcPartsPos(epw, lcmat, &pd, en26_tree[3], 7, 1);
        
        ps.x = (ps.x + pd.x) / 2.0f;
        ps.z = (ps.z + pd.z) / 2.0f;
        ps.y = epw->py;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 3.0f, 2.0f);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }       
    else if (t == 3)
    {
        owk = epw->mlwP->owP;
        ops.x = owk[1].mtx[12];
        ops.z = owk[1].mtx[14];
        ops.y = epw->pyb;
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 2, 1);
        
        ps.y = epw->py;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 1.5f, 2.0f);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }
        
    else if (t == 5)
    {
        owk = epw->mlwP->owP;
        ops.x = owk[0].mtx[12];
        ops.z = owk[0].mtx[14];
        ops.y = epw->pyb;
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 1, 1);
        
        ps.y = epw->py;        
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }
        
    else if (t == 6)        
    {
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 2, 1);
        owk =&epw->mlwP->owP[1];
        pd.x = 0.0f;
        pd.y = -5.0f;                
        pd.z = 0.0f;
        njCalcPoint(lcmat, &pd, &ps);
        njCalcPoint(&owk->mtx, &pd, &ops);
        
        pd2.x = 0.0f;
        pd2.y = 3.5f;
        pd2.z = 0.0f;
        njCalcPoint(lcmat, &pd2, &ps2);
        njCalcPoint(&owk->mtx, &pd2, &ops2);
        
        ps.y = ps2.y = epw->py;
        ops.y = ops2.y = epw->pyb;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
        
        bhEne_CollisionCheckWall2(epw, &ps2, &ops2, &pd, epw->ar, epw->ah);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }    
}

// 100% matching!
void bhEne26_PlayerLink(BH_PWORK* epw, BH_PWORK* pl)
{	   
	NJS_POINT2_XZ* ply_pos_p;
	NJS_POINT3 pos;
	NJS_POINT3 ps;
	NJS_POINT3 pd;   
    int mtn_no;
          
    NJS_POINT2_XZ* ply_pos[16] =
    {
        cl_mtn01_xz,
        cl_mtn02_xz,
        cl_mtn04_xz,
        cl_mtn05_xz,
        ch_mtn01_xz,
        ch_mtn02_xz,
        ch_mtn04_xz,
        ch_mtn05_xz,
        st_mtn01_xz,
        st_mtn02_xz,
        st_mtn04_xz,
        st_mtn05_xz,
        ch_mtn01_xz,
        ch_mtn02_xz,
        ch_mtn04_xz,
        ch_mtn05_xz
    };
    
    njUnitMatrix(NULL);
    njTranslate(NULL, epw->px, epw->py, epw->pz);
    njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
    njCalcPoint(NULL, (NJS_POINT3*)(epw->exp0 + 0x64), &pd);
    pl->px = pd.x;
    pl->pz = pd.z;
    pl->ay = (unsigned short)(epw->ay + epw->waxp);
    if (pl->flg & 0x1000)
    {
		if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 1)) 
        {
            mtn_no = 0;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 2))
        {
            mtn_no = 1;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 4))
        {
            mtn_no = 2;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 5))
        {
            mtn_no = 3;
        }
			
        ply_pos_p = ply_pos[(sys->ply_id * 4 + mtn_no)];
        ply_pos_p += pl->frm_no / 65536;
        
        ps.x = ply_pos_p->x;
        ps.y = 0.0f;
        ps.z = ply_pos_p->z;
        njUnitMatrix(NULL);
        njTranslate(NULL, pl->px, pl->py, pl->pz);
        njRotateXYZ(NULL, pl->ax, pl->ay, pl->az);
        njCalcPoint(NULL, &ps, &pos);
        njUnitMatrix(pl->mtx);
        njTranslate(pl->mtx, pos.x, pos.y, pos.z);
        njRotateXYZ(pl->mtx, pl->ax, pl->ayp, pl->az);
    }
}

// 100% matching!
void bhEne26_CalcEnemy(BH_PWORK* epw)
{
    O_WORK* owk;
    
    bhCalcModel(epw);
    owk = &epw->mlwP->owP[12];
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13];
    epw->watr.c1.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[4];
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[8];
    epw->watr.c2.x = (epw->watr.c2.x + owk->mtx[12]) / 2.0f;
    epw->watr.c2.y = (epw->watr.c2.y + owk->mtx[13]) / 2.0f;
    epw->watr.c2.z = (epw->watr.c2.z + owk->mtx[14]) / 2.0f;
    
    epw->watr.r = 2.0f;    
    epw->cah = epw->ah = epw->mlwP->owP[12].mtx[13] - epw->py;
}

// 100% matching!
void bhEne26_Init(BH_PWORK* epw)
{
	int i;
	unsigned char* addr;
	int size;

    plp->flg &= ~4;
    epw->ar = 3.8f;
    epw->ah = 18.2f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 2.5f;
    epw->cah = 18.2f;
    epw->hp = 200;
    epw->stflg = 0;
    
	for (i = 0; i < 64; i++)
    {
    	epw->dam[i] = 0;
	}
    
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 65536;
    epw->mtn_no = 0;
    epw->mtn_tp = (unsigned char *)en26_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(160, 8);
        epw->exp1 = 0;
    } 
    else
    {
        addr = epw->exp0;
        size = 160;        
        while (size-- != 0)
        {
            *addr++ = 0;
        }
    }

    EXP0_I(0x40) |= 1;
    epw->flg |= 0x178;
    epw->flg &= ~2;
    epw->cpcl = Ene26CapColTab;
    epw->mlwP->objP = epw->mbp[0];
    epw->mdflg = 0;
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];

    EXP0_I(0x40) |= 0x10000000;
    
    if (!(epw->flg & 0x800))
    {
        bhSetShadow(En26SdwTab,(unsigned char *)epw, 1.0f, 6.0f, 5.0f, 5.0f);
        epw->flg |= 0x800;
    }
    
    if ((EXP0_I(0x3C) & 0xFFFFFF) == 0)
    {
        epw->mdflg &= ~0x400;
        EXP0_I(0x3C) = 0xFFB2B2B2U;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, (int)EXP0_I(0x3C));
    }
    
    epw->clp_jno[0] = 13;
    epw->clp_jno[1] = 16;
    epw->clp_jno[2] = 19;
    epw->clp_jno[3] = 4;
    epw->clp_jno[4] = 8;
    epw->clp_jno[5] = -1;
    epw->mdflg |= 0x20;
    epw->lok_jno = 12;
    epw->comb_flg |= 2;
    bhClrUseKaidanFlag(epw);
    bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    bhEne26_CalcEnemy(epw);
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->mlwP->owP[10].flg |= 2;
}

// 100% matching!
void bhEne26_Move(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	O_WORK* owk;

    EXP0_I(0x40) &= ~0x800;
    
    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = plp->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x54) = njDistanceP2P(&pos,  (NJS_POINT3*)&epw->px);
    if (epw->mode2 != 9)
    {
        EXP0_I(0x40) |= 0x800;
    }
    
    bhEne26_MVType(epw);
}

// 100% matching!
void bhEne26_MVType(BH_PWORK* epw)
{
    if (bhEne_EnemyAtariCheck((NJS_POINT3*) &plp->px, plp->flr_no, epw->id, 0))
    {
        EXP0_I(0x40) |= 0x20000000;
    } 
    else
    {
        EXP0_I(0x40) &= ~0x20000000;
    }

    if (epw->mode1 == 1) 
    {
        bhEne26_Brain00(epw);
    }
    
    if (EXP0_I(0x70) == 0)
    {
        bhEne26_ActionModeCheck(epw);
    }
    
    if (epw->mode0 == 1)
    {
        bhEne26_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne26_EneSearch(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* neck_obj;
    O_WORK* neck_owk;
    NJS_POINT3 pos;

    neck_owk = &epw->mlwP->owP[13];
    neck_obj = &epw->mlwP->objP[13];

    pos.x = neck_owk->mtx[12];
    pos.y = 0.0f;
    pos.z = neck_owk->mtx[14];

    if ((EXP0_UC(0x28) & 0x1F) < 31)
    {
        if (bhSearchPlayer2(epw, &pos, epw->ay + neck_obj->ang[1], 14563) != -1)
        {
            EXP0_UC(0x28) |= 0x20;
        }
        
        if (EXP0_UC(0x28) & 0x20)
        {
            EXP0_UC(0x28) |= 0x40;
            EXP0_UC(0x28) &= ~0x20;
        } 
        else if ((EXP0_UC(0x28) & 0x1F) == 30)
        {
            EXP0_UC(0x28) &= ~0x40;
        }
    }
    
    EXP0_UC(0x28)++;
    if ((EXP0_UC(0x28) & 0x1F) >= 31)
    {
        EXP0_UC(0x28) &= ~0x1F;
    }

    if (EXP0_UC(0x28) & 0x40)
    {
        EXP0_I(0x40) |= 0x400;
        EXP0_UC(0x29) = 15;
    }
    else if (EXP0_I(0x40) & 0x400)
    {
        if (--EXP0_UC(0x29) < 0)
        {
            EXP0_I(0x40) &= ~0x400;
        }
    }
}

// 100% matching!
void bhEne26_Brain00(BH_PWORK* epw)
{
    unsigned char rid;
	NJS_POINT3 pos;

    bhEne26_EneSearch(epw);
    if (EXP0_I(0x40) & 0x400)
    {
        if ((EXP0_F(0x54) < 50.0f) && (EXP0_I(0x70) == 0) && (epw->flr_no == plp->flr_no))
        {
            EXP0_F(0x58) = plp->px;
            EXP0_F(0x60) = plp->pz;
            EXP0_UC(0x2A) = bhCheckRouteID((NJS_POINT3*) &epw->px);
            EXP0_UC(0x2B) = 0;
            return;            
        }
        
        rid = (unsigned char) bhCheckRouteID((NJS_POINT3*) &epw->px);
        EXP0_UC(0x2B)++;
        if ((EXP0_UC(0x2A) == rid) || (EXP0_UC(0x2B) >= 255))
        {
            rid = bhCheckRoute((NJS_POINT3*) &epw->px, (NJS_POINT3*) &plp->px, &pos);
            EXP0_F(0x58) = pos.x;
            EXP0_F(0x60) = pos.z;
            EXP0_UC(0x2A) = rid;
            EXP0_UC(0x2B) = 0;
        }
    }
}

// 100% matching!
int bhEne26_ActionModeCheck(BH_PWORK* epw)
{
    O_WORK* owk;
    
    if (((epw->mode2 == 0) || (epw->mode2 == 1 || epw->mode2 == 2)) &&
        (ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 4096) == 0) &&
        (EXP0_F(0x54) < 10.0f) && (plp->mode0 == 6) && (plp->hp < 0))
    {
        epw->mode1 = 0;
        epw->mode2 = 16;
        epw->mode3 = 0;
        return 1;
    }

    if ((plp->flg & 4) || (plp->flg & 2) || (plp->stflg & 0x80000000))
    {
        if (bhSearchPlayer2(epw, (NJS_POINT3*)&epw->px, epw->ay, 5461) != -1)
        {
            if ((EXP0_F(0x54) < 7.0f) &&
                (plp->flr_no == epw->flr_no) &&
                (((epw->mode2 == 0)) || (epw->mode2 == 1 || epw->mode2 == 2)))
            {
                epw->mode1 = 0;
                epw->mode2 = 6;
                epw->mode3 = 0;
                return 1;
            }             
        } 
        return 0;
    } 
    else
    {
        if ((epw->mode2 == 0) || (epw->mode2 == 1 || epw->mode2 == 2))
        {
            owk = plp->mlwP->owP;
            if (bhEne26_EatCheck(epw, 8192, 5.5f, 0) && (EXP0_UC(0x2F) == 0) && (epw->mtn_no == 16))
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                epw->flg &= ~0x20;
                plp->flg |= 0x10000;
                plp->flg |= 4;
                return 1;
            }
            
            if ((bhCdirCheck(epw->ay, plp->ay) == 0) &&
                (plp->mode2 == 6) &&
                ((rand() % 2) == 0) &&
                (bhEne26_EatCheck(epw, 5461, 11.0f, 0)))
            {
                epw->mode1 = 0;
                epw->mode2 = 5;
                epw->mode3 = 0;
                return 1;
            }
            
            if ((EXP0_F(0x54) < 11.0f) &&
                (epw->flr_no == plp->flr_no) &&
                (plp->hp >= 0) &&
                (ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 16384)) &&
                !(EXP0_I(0x40) & 0x20000000))
            {
                epw->mode1 = 0;
                epw->mode2 = 3;
                epw->mode3 = 0;
                return 1;
            }
            
            if ((epw->flg & 4) &&
                (epw->flr_no == plp->flr_no) &&
                !(EXP0_F(0x54) <= 15.0f) &&
                (ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 24576)))
            {
                epw->mode1 = 0;
                epw->mode2 = 7;
                epw->mode3 = 0;
                return 1;
            }
        }
    }
}

// 100% matching!
void bhEne26_MV00(BH_PWORK* epw)
{
    int frm_no;

    switch (epw->mode3)
    {
    case 0:
        frm_no = (rand() % epw->mnwP[epw->mtn_no].frm_num) * 65536;
        bhEne_ChgMtn(epw, 0, 0, 15);
        EXP0_I(0x40) &= ~0x3000000;
        epw->frm_no = frm_no;
        epw->flg |= 0x40000;
        epw->ct0 = ((rand() % 10) * 20) + 15;
        EXP0_I(0x40) &= ~0x400;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 1;
        epw->mode1 = 1;
        epw->mode3++;
        bhEne26_SePlay(epw, 16847639);

    case 1:
        epw->ct0 -= 1;
        if ((epw->ct0 <= 0) || (EXP0_I(0x40) & 0x400))
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        } 
        break;
    }
}

// 100% matching!
void bhEne26_MV01(BH_PWORK* epw)
{
    int hit;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 25, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->way = 512;
        epw->flg |= 0x40000;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        epw->ct0 = (rand() % 128) + 200;
        epw->ct1 = 19;
        epw->ct3 = rand() % 120;
        epw->mode3 = 1;

    case 1:
        if (EXP0_F(0x54) < 30.0f || (EXP0_I(0x40) & 0x400))
        { 
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                bhEne26_SePlay(epw, 16847639);
                EXP0_I(0x40) |= 0x400;
        }
        else
        {
            if (bhEne_CheckDirWall(epw, 0, 8.0f))
            {
                hit = bhEne_CheckSideWall(epw, 8.0f, 0);  
                
                if (hit == 0)
                {
                    epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
                    epw->ayp = (unsigned short)(epw->ayp - epw->ay);
                    if (epw->ayp < 32769)
                    {
                        epw->way = 256;
                    } 
                    else 
                    {
                        epw->way = -256;
                    } 
                } 
                else
                {
                    epw->way = hit * 256;
                }
                epw->mode3 = 2;
            }
        }            
        break;
        
    case 2:
        if (bhEne_CheckDirWall(epw, 0, 8.0f) == NULL) 
        {
            epw->mode3 = 1;
        } 
        else
        {
            epw->ay += epw->way;
        }
        break;
    }

    if (--epw->ct3 < 0)
    {
        bhEne26_SePlay(epw, 16847639);
        epw->ct3 = (rand() % 120) + 180;
    }
}

// 100% matching!
void bhEne26_MV02(BH_PWORK* epw)
{
    int frm;
    
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 25, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->way = 0x100;
        epw->flg |= 0x40000;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = (rand() % 120) + 120;
        EXP0_I(0x84) = 0;
        EXP0_I(0x88) = 0;
        epw->ct3 = rand() % 120;
        EXP0_I(0x44) &= ~0x80;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        epw->mode3 = 2;
        break;
    case 1:
        bhEne_ChgMtn(epw, 16, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->way = 0x200;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = (rand() % 120) + 120;
        EXP0_I(0x84) = 0;
        EXP0_I(0x88) = 0;
        epw->ct3 = rand() % 120;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        EXP0_I(0x40) |= 0x400;
        epw->mode3 = 2;
        break;
    case 2:
        if (epw->mtn_no == 25)
        {
            if (!(EXP0_I(0x44) & 0x80))
            {
                EXP0_I(0x7C) = 10;
                EXP0_I(0x80) = 0;
                if (epw->hokan_count < 10)
                {
                    epw->hokan_count = 10;
                }
                epw->ct1 = 19;
                EXP0_I(0x44) |= 0x80;
            } 
            else
            {
                if (--epw->ct1 < 0)
                {
                    frm = bhGetFrameNum(epw->mnwP[epw->mtn_no].frm_num, epw->mnwP[16].frm_num, epw->frm_no);
                    bhEne_ChgMtn(epw, 16, frm, 10);
                    EXP0_I(0x40) &= ~0x3000000;
                    epw->flg |= 0x40000;
                    epw->way = 0x200;
                }
            }
        }
        ikou(epw, (NJS_POINT3*)(epw->exp0 + 0x58), epw->way);
        break;
    case 3:
        if (bhEne_CheckDirWall(epw, 0, 8.0f) == NULL)
        {
            epw->mode3 = 2;
        } 
        else
        {
            epw->ay += epw->way;
        }
        break;
    }
    
    if (--epw->ct3 < 0)
    {
        bhEne26_SePlay(epw, 16847639);
        epw->ct3 = (rand() % 120) + 180;
    }
}

// 100% matching!
void bhEne26_MV03(BH_PWORK* epw)
{
	O_WORK* owk;
	int rot;
    
    switch (epw->mode3)
    { 
    case 0:
        bhEne_ChgMtn(epw, 13, 0, 8);
        EXP0_I(0x40) &= ~0x3000000;
        epw->mtn_add = 0;
        epw->ct0 = 6;
        epw->mode3++;

    case 1:
        owk = plp->mlwP->owP;
        rot = ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 4096);
        epw->ct0--;
        if ((epw->ct0 <= 0) || (rot == 0))
        {
            if (!ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 4096) && (EXP0_F(0x54) < 10.0f) && (plp->mode0 == 6) && (plp->hp < 0))
            {                               
                epw->mode1 = 0;
                epw->mode2 = 16; 
                epw->mode3 = 0;
            } 
            else
            {
                epw->mode1 = 0;
                epw->mode2 = 5;
                epw->mode3 = 0;
            }            
        }
        epw->ay += rot;
        break;
    }
}

// 100% matching!
void bhEne26_MV05(BH_PWORK* epw)
{
	BH_PWORK* pl;
	float hit;
	int frm;

    pl = plp;
    switch (epw->mode3)
    {
    case 0:
        if (sys->ply_id == 1)
        {
            bhEne_ChgMtn(epw, 13, 0, 8);
            EXP0_I(0x40) &= ~0x2000000;
            EXP0_I(0x40) |= 0x1000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 13, 0, 8);
            EXP0_I(0x40) &= ~0x2000000;
            EXP0_I(0x40) |= 0x1000000;
        }
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        EXP0_F(0x68) = 0.0f;
        EXP0_F(0x64) = epw->px;
        EXP0_F(0x6C) = epw->pz;
        bhEne26_SePlay(epw, 16782102);
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;

        if (frm < 13)
        {
            epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 1536);
        }
        
        hit = 0.0f;
        if (frm >= 8)
        {
            if ((frm < 0xD) && !(plp->flg & 4) && (bhEne26_EatCheck(epw, 3640, 5.5f, 0) != 0))
            {
                plp->flg |= 4;
                plp->flg |= 0x10000;
                epw->flg &= ~0x20;
                epw->flg &= ~0x40;
                
                *(int*)&pl->mode0 = 4;
                pl->mode3 = 4;
                
                EXP0_I(0x40) |= 0x20000;
                if (bhCdirCheck(plp->ay, epw->ay) == 0)
                {
                    EXP0_I(0x40) |= 0x4000;
                } 
                else
                {
                    EXP0_I(0x40) &= ~0x4000;
                }
                
                if (sys->ply_id == 1)
                {
                    bhEne_ChgMtn(epw, 12, 0, 5);
                    EXP0_I(0x40) &= ~0x3000000;
                } 
                else
                {
                    bhEne_ChgMtn(epw, 12, 0, 5);
                    EXP0_I(0x40) &= ~0x3000000;
                }
                
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 5;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 2;
                epw->ct0 = 75;
                hit = 1.0f;
            }
        }
        if ((frm == 12) && (hit == 0.0f))
        {
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne26_MV06(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 15, 2949120, 15);
        EXP0_I(0x40) &= ~0x3000000;       
        epw->flg |= 0x40000;
        epw->ct0 = (rand() % 15) + 15;
        epw->mode1 = 1;
        epw->mode3++;

    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->px, 910);
        if (!(plp->flg & 4))
        {
            if (bhEne26_EatCheck(epw, 4551, 5.5f, 0))
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                plp->flg |= 4;
                plp->flg |= 0x10000;
                epw->flg &= ~0x20;
                break;
            } 
            
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        } 
    }
}

// 100% matching!
void bhEne26_MV07(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 17, 0, 8);
        EXP0_I(0x40) &= ~0x3000000;
        epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        epw->ayp = (unsigned short)(epw->ayp - epw->ay);
        
        if (epw->ayp < 32769)
        {
            epw->ayp /= 22;
        } 
        else
        {
            epw->ayp = (-(65536 - epw->ayp) / 22);
            epw->mtn_md |= 2;
        }
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 17) && (frm < 40))
        {
            epw->ay += epw->ayp;
        }

        if ((epw->frm_no / 65536) == 40)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_MV16(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 910);
        bhEne_ChgMtn(epw, 18, 0, 5);
        EXP0_I(0x40) &= ~0x2000000;
        EXP0_I(0x40) |= 0x1000000;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 14, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            epw->mode3++;
        }

    case 2:
        break;
    }
}

// 100% matching!
void bhEne26_Nage(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    bhEne26_NGType(epw);
}

// 100% matching!
void bhEne26_NGType(BH_PWORK* epw)
{
    if (epw->mode3 == 0)
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0)
        {
            EXP0_I(0x40) |= 0x4000;
        } 
        else
        {
            EXP0_I(0x40) &= ~0x4000;
        }
    }
    bhEne26_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne26_NG00(BH_PWORK* epw)
{
    BH_PWORK* pl;
    O_WORK* owk;
    NJS_POINT3 ps;
    int ang;    
    int frm;

    pl = plp;

    switch (epw->mode3)
    {
    case 0:
        if (sys->ply_id == 1)
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        }

        epw->ay = NitenDir_ck(epw->px, epw->pz, pl->px, pl->pz);
        epw->flg &= ~0x40;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 5;
        EXP0_I(0x40) &= ~0x4000000;
        pl->mode0 = 4;
        pl->mode1 = 0;
        pl->mode2 = 0;
        pl->mode3 = 0;
        epw->flg2 |= 1;
        ps.x = 0.0f;
        ps.y = 0.0f;
        
        if (EXP0_I(0x40) & 0x4000)
        {
            ps.z = -6.442887f;
            ang = (unsigned short)(epw->ay + NJM_DEG_ANG(180.0f));
        } 
        else
        {
            ps.z = 6.290813f;
            ang = epw->ay;
        }
        
        njUnitMatrix(NULL);
        njTranslate(NULL, pl->px, pl->py, pl->pz);
        njRotateY(NULL, ang);
        njCalcPoint(NULL, &ps, (NJS_POINT3*)&epw->px);
        EXP0_I(0x40) |= 0x20000;
        epw->mode3++;
        
    case 1:
        if ((epw->frm_no / 65536) == 20)
        {
            epw->ct0 = 60;
            epw->mode3++;            
        }
        break;
        
    case 2:
        frm = epw->frm_no / 65536;
        if ((frm == 25) || (frm == 60))
        {
            pl->hp -= 30;
            if (pl->hp < 0)
            {
                pl->stflg |= 0x40000;
            }
        }
        epw->ct0 -= bhEne_LeverCheck() + 1;
        if ((epw->ct0 <= 0) || (epw->flg & 0x2000000))
        {
            if (pl->hp < 0)
            {
                bhEne_ChgMtn(epw, 9, 0, 0);
                EXP0_I(0x40) &= ~0x3000000;
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 5;
                epw->mode3 = 5;
                pl->mode0 = 6;
                pl->mode3 = 6;
            } 
            else
            {
                bhEne_ChgMtn(epw, 1, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
                epw->flg |= 0x40000;
                epw->mode3++;
                pl->mode3 = 2;
                pl->ct1 = 0;
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 6;
                epw->ct0 = 0;
                epw->flg2 &= ~1;
            }
            epw->flg |= 0x20;
        }
        break;
        
    case 3:
        frm = epw->frm_no / 65536;
        if (17 < frm && frm < 31)
        {
            epw->spd = (1.5f - epw->ct0 * 0.14);
            if (epw->spd < 0.0f)
            {
                epw->spd = 0.05f;
            }
            bhAddSpeed(epw, 32768);
            epw->ct0++;            
        }
        
        if (frm == 20)
        {
            EXP0_I(0x40) |= 0x100;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 26, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            epw->flg |= 0x40000;
            EXP0_I(0x40) &= ~0x80;
            epw->flg |= 0x40;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mode3++;
        }
        break;
        
    case 4:
        frm = epw->frm_no / 65536;
        if (frm == 10)
        {
            EXP0_I(0x40) &= ~0x100;
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg2 &= ~1;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 1;
            epw->mtn_add = 0;
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
        
    case 5:
        if (epw->flg & 0x2000000)
        {
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            EXP0_I(0x40) &= ~0x80000;
            bhEne_ChgMtn(epw, 14, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            EXP0_I(0x40) &= ~0xF;
            epw->mode3++;
        }
        break;
        
    case 6:
        break;
        
    }
}

// 100% matching!
void bhEne26_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
    static NJS_POINT3 ply_ofs_pos[8] =
    {
        {0.0f, 0.0f, -6.326351f},
        {0.0f, 0.0f, -6.326351f},
        {0.0f, 0.0f, -5.0f},
        {0.0f, 0.0f, -6.019392f},
        {0.167357f, 0.0f, -5.7556629f},
        {0.0f, 0.0f, -5.9214029f},
        {0.0f, 0.0f, -5.0f},
        {0.0f, 0.0f, -6.019392f}
    };
    
    static NJS_POINT3 ply_ofs_pos2[8] =
    {
        {0.469302f, 0.0f, -5.826981f},
        {0.469231f, 0.0f, -5.499186f},
        {0.2f, 0.0f, -4.5f},
        {0.4f, 0.0f, -5.1999998f},
        {0.469302f, 0.0f, -5.0f},
        {0.469231f, 0.0f, -4.9f},
        {0.2f, 0.0f, -4.5f},
        {0.4f, 0.0f, -5.1999998f}
    };
    
    unsigned int frm;

    switch (pl->mode3)
    {
    case 0:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg &= ~8;
        EXP1_I(0) |= 0x1E0;
        EXP1_I(0) &= ~4;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->ayp = (unsigned short)((epw->ay + 32768) - pl->ay);
            epw->waxp = -32768;
        } 
        else 
        {
            pl->ayp = (unsigned short)(epw->ay - pl->ay);
            epw->waxp = 0;
        }
        
        if (32768 < pl->ayp)
        {
            pl->ayp = (pl->ayp - 32768) - 32768;
        }
        epw->waxp -= pl->ayp;
        pl->ayp /= 5;
        pl->ct0 = 0;
        pl->mode3++;

    case 1:
        if (pl->ct0 < 5)
        {
            epw->waxp += pl->ayp;
        } 
        else if (pl->ct0 == 5)
        {
            if (EXP0_I(0x40) & 0x4000)
            {
                epw->waxp = -32768;
            } 
            else
            {
                epw->waxp = 0;
            }
        }
        
        pl->ct0++;
        frm = epw->frm_no / 65536;
        if (frm == 1)
        {            
            pl->mnwP = epw->mnwP;
            pl->frm_no = 0;
            pl->hokan_count = 5;
            pl->hokan_rate = 42598;
            pl->mtn_add = 65536;
            pl->mtn_md = 0;
            EXP0_I(0x40) |= 0x80;
            if (EXP0_I(0x40) & 0x4000)
            {
                pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 6;
                EXP0_F(0x64) = ply_ofs_pos[sys->ply_id * 2].x;
                EXP0_F(0x68) = ply_ofs_pos[sys->ply_id * 2].y;
                EXP0_F(0x6C) = ply_ofs_pos[sys->ply_id * 2].z;
                epw->waxp = -32768;
                EXP0_I(0x40) |= 0x80000;
                break;
            } 
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 7;
            EXP0_F(0x64) = ply_ofs_pos[sys->ply_id * 2 + 1].x;
            EXP0_F(0x68) = ply_ofs_pos[sys->ply_id * 2 + 1].y;
            EXP0_F(0x6C) = ply_ofs_pos[sys->ply_id * 2 + 1].z;
            epw->waxp = 0;
            EXP0_I(0x40) |= 0x80000;            
        } 
        else if (frm == 12)
        {
            bhEne_PlayerSePlay(epw, 1026);
        }
        break;
        
    case 2:
        EXP1_I(0) |= 4;
        pl->frm_no = 0;
        pl->hokan_count = 0;
        pl->hokan_rate = 32768;
        pl->mtn_add = 65536;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 10;
        } 
        else
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 11;
        }

        EXP0_I(0x40) &= ~0x80000;
        pl->mode3++;

    case 3:
        frm = pl->frm_no / 65536;
        if (frm == 14)
        {
            bhEne01_EnemyPushChk(epw, 1);
        } 
        else if (frm == 17)
        {
            bhEne01_EnemyPushChk(epw, 0);
        }
        
        if ((pl->frm_no / 65536) >= (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->flg |= 8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->mnwP = pl->mnwPb;
            *(int*)&pl->mode0 = 1;
            plp->flg &= ~4;
            EXP0_I(0x40) &= ~0x4000;
            EXP0_I(0x40) &= ~0x20000;
        }
        break;
        
    case 4:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg &= ~8;
        EXP1_I(0) |= 0x1E0;
        EXP1_I(0) &= ~4;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 8;
            EXP0_F(0x64) = ply_ofs_pos2[sys->ply_id * 2].x;
            EXP0_F(0x68) = ply_ofs_pos2[sys->ply_id * 2].y;
            EXP0_F(0x6C) = ply_ofs_pos2[sys->ply_id * 2].z;
            EXP0_I(0x40) |= 0x80000;
            pl->ayp = (unsigned short)((epw->ay + 32768) - pl->ay);
            epw->waxp = -32768;
        } 
        else
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 9;
            EXP0_F(0x64) = ply_ofs_pos2[sys->ply_id * 2 + 1].x;
            EXP0_F(0x68) = ply_ofs_pos2[sys->ply_id * 2 + 1].y;
            EXP0_F(0x6C) = ply_ofs_pos2[sys->ply_id * 2 + 1].z;
            epw->waxp = 0;
            EXP0_I(0x40) |= 0x80000;
            pl->ayp = (unsigned short)(epw->ay - pl->ay);
            epw->waxp = 0;
        }
        
        pl->mnwP = epw->mnwP;
        pl->frm_no = 0;
        pl->hokan_count = 5;
        pl->hokan_rate = 42598;
        pl->mtn_add = 65536;
        pl->mtn_md = 0;
        EXP0_I(0x40) |= 0x80;
        bhEne_PlayerSePlay(epw, 1026);

        if (32768 < pl->ayp)
        {
            pl->ayp = (pl->ayp - 32768) - 32768;
        }
        epw->waxp -= pl->ayp;
        pl->ayp /= 5;
        pl->ct0 = 0;
        pl->mode3++;

    case 5:
        if (pl->ct0 < 5)
        {
            epw->waxp += pl->ayp;
        } 
        else if (pl->ct0 == 5)
        {
            if (EXP0_I(0x40) & 0x4000)
            {
                epw->waxp = -32768;
            } 
            else
            {
                epw->waxp = 0;
            }
        }
        pl->ct0++;
        break;
        
    case 6:
        pl->frm_no = 0;
        pl->hokan_count = 0;
        pl->hokan_rate = 32768;
        pl->mtn_add = 65536;
        pl->flg &= ~0x10;
        if (EXP0_I(0x40) & 0x4000)
        {
             pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 12;
        } 
        else
        {
             pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 13;
        }
        bhEne_PlayerSePlay(epw, 1025);
        pl->mode3++;

    case 7:
        frm = pl->frm_no / 65536;
        
        if (EXP0_I(0x40) & 0x4000)
        {
            if (frm == 22 || frm == 30)
            {
                bhEne26_SePlay(epw, 8963);
            }
        }
        else
        {
            if (frm == 16 || frm == 22)
            {
                bhEne26_SePlay(epw, 8963);
            }
        }
        
        if (frm >= (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            plp->mtn_add = 0;
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->flg |= 2;
            EXP0_I(0x40) &= ~0x4000;
            EXP0_I(0x40) &= ~0x20000;
            EXP0_I(0x40) &= ~0x80000;
            plp->flg &= ~4;
        }
        break;
    }
}

// 100% matching!
void bhEne26_Damage(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    bhEne26_DGType(epw);
}

// 100% matching!
void bhEne26_DGType(BH_PWORK* epw)
{
    bhEne26_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne26_DG00(void)
{

}

// 100% matching!
void bhEne26_DG01(void)
{

}

// 100% matching!
void bhEne26_DG02(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        if (EXP0_I(0x40) & 0x2000)
        {
            if (epw->mtn_no == 0x10)
            {                
                bhEne_ChgMtn(epw, 27, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            } 
            else
            {
                bhEne_ChgMtn(epw, 5, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            }
        }
        else
        {
            if (epw->mtn_no == 16)
            {
                bhEne_ChgMtn(epw, 28, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;  
            }
  
        }
        
        epw->flg |= 0x40000;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 0x1;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;

        if ((frm == 28 && epw->mtn_no == 5)  ||
            (frm == 28 && epw->mtn_no == 27) ||
            (frm == 30 && epw->mtn_no == 6)  ||
            (frm == 30 && epw->mtn_no == 28))
        {
            if ((epw->flr_no == plp->flr_no &&
                EXP0_F(0x54) > 15.0f &&
                ikou3(epw, (NJS_POINT3*)&plp->px, 24576)))
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 7;
                epw->mode3 = 0;
            }
            else
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }

            EXP0_I(0x40) &= ~0x200;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 0x1;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {        
    case 0:
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 6;
        epw->spd = 0.0f;
        bhEne_ChgMtn(epw, 3, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) {
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mtn_add = 0;
            EXP0_I(0x40) &= ~0x8000;
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG04(BH_PWORK* epw)
{
	int frm;
	int ang;

    switch (epw->mode3)
    {
    case 0:
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 6;
        bhEne_ChgMtn(epw, 4, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        if (!(EXP0_I(0x40) & 0x200))
        {
            epw->ayp = (10430.381f * atan2f(epw->dvx, epw->dvz));
        }
        epw->mode3++;

    case 1:
        
        frm = epw->frm_no / 65536;        
        if (!(EXP0_I(0x40) & 0x200))
        {
            if (frm < 10)
            {
                ang = (unsigned short)(epw->ayp - epw->ay);
                if (ang > NJM_DEG_ANG(180.0f))
                {
                    ang -= NJM_DEG_ANG(360.0f); 
                }
                epw->ay += (ang / 2);
            }
        }

        if (frm == 10)
        {
            EXP0_I(0x40) &= ~0x100;
        }
        
        if ((16 <= frm) && (frm < 21))
        {
            epw->spd = 0.49733332f;
            bhAddSpeed(epw, 32768);
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mtn_add = 0;
            EXP0_I(0x40) |= 0x8000;
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG15(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 16, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_Die(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    if (EXP0_I(0x38) != 0) {
        if ((EXP0_I(0x3C) & 0x00FFFFFF) > 0)
        {
            EXP0_I(0x3C) += 0xFFFEFEFF;
        }
        epw->mdflg |= 0x400;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, EXP0_I(0x3C));
    }
    bhEne26_DDType(epw);
}

// 100% matching!
void bhEne26_DDType(BH_PWORK* epw)
{
  bhEne26_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne26_DD00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (!(EXP0_I(0x40) & 0x8000))
        {
            bhEne_ChgMtn(epw, 10, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 11, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        }
        
        epw->mtn_add = 0;
        epw->flg |= 2;
        epw->flg &= ~0x128;
        epw->ct0 = 0;
        epw->ct1 = (rand() % 5) + 10;
        bhSetBloodPoolLnk(epw, (NJS_POINT3*)&epw->px, epw->ay, &en01_BldTbl, 0);
        epw->mode3++;

    case 1:
        if (--epw->ct0 < 0)
        {
            epw->mtn_add = 65536;
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            if (epw->ct1-- > 0)
            {
                epw->ct0 = (rand() % 50) + 10;
                epw->mode3 = 1;
            } 
            else
            {
                epw->mode3++;  
            }          
        }
    case 3:
        break;
    }
}

// 100% matching!
int bhEne26_EatCheck(BH_PWORK* epw, int rng, float dist, int mode)
{
    NJS_SPHERE at;
    O_WORK* owk;
    NJS_POINT3 ps;
    NJS_POINT3 eps;
    float ds;

    if (EXP0_I(0x40) & 0x20000000 || plp->flg & 2 || plp->stflg & 0x80000000)
    {
        return 0;
    }
    
    owk = &plp->mlwP->owP[3];
    ps.x = owk->mtx[12];
    ps.y = plp->py;
    ps.z = owk->mtx[14];
    owk = &epw->mlwP->owP[12];
    eps.x = owk->mtx[12];
    eps.y = plp->py;
    eps.z = owk->mtx[14];

    ds = njDistanceP2P(&ps, &eps);

    switch (mode)
    {
    case 0:
        if ((bhSearchPlayer2(epw,(NJS_POINT3*) &epw->px, epw->ay, rng) == -1) ||
            (ds >= dist) ||
            (plp->py != epw->py) ||
            (plp->hp < 0))
        {
            break;
        }
            
        return 1;

    case 1:
        if ((plp->py != epw->py) || (plp->hp < 0))
        {
            break;
        }
        
        return 1;

    case 2:
        owk = &epw->mlwP->owP[12];
        ps.x = 0.0f;
        ps.y = 0.0f;
        ps.z = -4.0f;
        njCalcPoint((NJS_MATRIX*)owk->mtx, &ps, &at.c);
        at.r = 1.0f;

        if (!npCollisionCheckSC(&at, &plp->watr) ||
           (plp->py != epw->py) ||
           (plp->flg & 2) ||
           (plp->stflg & 0x80000000) ||
           (plp->hp < 0))
        {
            break;            
        }
        return 1;
       
    }
    return 0;
}

// 100% matching!
void bhEne26_ExpHeadEffect(BH_PWORK* epw, int unused)
{
	NJS_VECTOR v;
	NJS_POINT3 ps;
	NJS_POINT3 pd;
	O_WORK* owk;
	int ang1;   
	int i;

	owk = &epw->mlwP->owP[12];
	ps.x = 0.0f;
	ps.y = 0.5f;
	ps.z = -1.0f;
	njCalcPoint(&owk->mtx, &ps, &pd);

	for (i = 0; i < 4; i++)
    {
		ang1 = (NJM_DEG_ANG(45.0f) + epw->py + (i * NJM_DEG_ANG(90.0f)));
		v.x = -njSin(ang1) * njCos(NJM_DEG_ANG(22.5f));
		v.y = njSin(NJM_DEG_ANG(22.5f));
		v.z = -njCos(ang1) * njCos(NJM_DEG_ANG(22.5f));
		bhEne_SetNikuhenEffect(epw, 0, &pd, &v, 7);
	}
}

// 100% matching!
void bhEne26_NeckBloodEffect(BH_PWORK* epw, int type)
{
    NJS_POINT3 ofs = { 0.0f, 1.0f, 0.0f };
    NJS_VECTOR v;
    int i;
    // not present in DWARF
    int ang;
      
    for (i = 0, ang = NJM_DEG_ANG(45.0f); i < 4; ang += NJM_DEG_ANG(90.0f), i++)
    {
        ofs.y = -1.0f;
        if (type == 0)
        {
            ofs.y = 0.0f;
            
            v.x = -(njSin(ang) * njCos(NJM_DEG_ANG(56.25f)));
            v.y = njSin(NJM_DEG_ANG(56.25f));
            v.z = -(njCos(ang) * njCos(NJM_DEG_ANG(56.25f)));
            bhEne_SetBlood3(epw, 12, &ofs, &v, 6, 8, 1, i);
            
            v.x = -(njSin(ang) * njCos(NJM_DEG_ANG(22.5f)));
            v.y = njSin(NJM_DEG_ANG(22.5f));
            v.z = -(njCos(ang) * njCos(NJM_DEG_ANG(22.5f)));
            bhEne_SetBlood3(epw, 12, &ofs, &v, 3, 8, 3, i);
        }
    }     
}

// 100% matching!
void bhEne26_KamiEffect(BH_PWORK* epw, int frm)
{
	EN26_KAMI_WORK* keff;
	NJS_POINT3 pd;
	int i;
	int j;

	i = 0;
	keff = en26_keff_tbl;
    
	for (i = 0; TRUE; i++, keff++) 
	{
		if (keff->mtn_no == -1)
        {
            return;
        }
			
		if (epw->mtn_no == keff->mtn_no)
		{
            for (j = 0; j < 4; j++)
            {
                if (frm == keff->frm[j])
                {
                	pd.x = 0.0f;
                	pd.y = 0.0f;
                	pd.z = -1.8f;
                
                	epw->djnt_no = 13;
                	bhEne_SetBlood2(epw, 1, &pd, 0);
                
                	if (j == 0)
                	{
                		epw->djnt_no = 13;
                		bhEne_SetBlood2(epw, 4, &pd, epw->ay);
                	}
                
                	return;
                }
            }
		}
	}
}

// 100% matching!
void bhEne26_SePlay(BH_PWORK* epw, int no)
{    
    if (epw->flg & 0x10000)
    {
        return;
    }

    if (((unsigned char)no >= 20) && (((unsigned char)no == 20 || (unsigned char)no == 21)))
    {
        if ((ChechPlayEnemySe(sys->enow, no)) || (!(rand() % 2)))
        {
            return;
        }
    }

    RequestEnemySe(sys->enow, (NJS_POINT3*)&epw->px, no);
}
