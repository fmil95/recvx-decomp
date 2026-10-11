#include "../../../ps2/veronica/prog/en04.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"

// ENEMY: Cerberus 

#pragma divbyzerocheck on 

int En04_PlyMtn_OffsetTbl[4] =
{
    0x64,
    0x69,
    0x64,
    0x69
};

EN04_MTBL en04_mtn_tbl[30] =
{
    { 0x00, {
        { 0x12, 0x00012300 },
        { 0x30, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x01, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x02, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x03, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x22, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x28, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x29, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x04, {
        { 0x04, 0x00012300 },
        { 0x0A, 0x01011304 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x06, {
        { 0x0C, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x07, {
        { 0x09, 0x01012302 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x08, {
        { 0x0C, 0x01011306 },
        { 0x16, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x09, {
        { 0x08, 0x01011306 },
        { 0x1D, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x0E, {
        { 0x00, 0x00011308 },
        { 0x10, 0x00011308 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x10, {
        { 0x12, 0x00012301 },
        { 0x1F, 0x01011304 },
        { 0x37, 0x01011306 },
        { 0x5A, 0x01012303 }
    }},
    { 0x14, {
        { 0x0A, 0x00012301 },
        { 0x12, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x15, {
        { 0x00, 0x00011308 },
        { 0x0C, 0x01002309 },
        { 0x40, 0x00011308 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x19, {
        { 0x00, 0x0101230E },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x2B, {
        { 0x00, 0x0101230E },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x21, {
        { 0x15, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x22, {
        { 0x00, 0x00012300 },
        { 0x02, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x23, {
        { 0x09, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x24, {
        { 0x00, 0x01011304 },
        { 0x09, 0x01011306 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x25, {
        { 0x18, 0x00012301 },
        { 0x25, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x26, {
        { 0x18, 0x00012301 },
        { 0x29, 0x00012301 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x11, {
        { 0x07, 0x01011304 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x12, {
        { 0x0C, 0x0101130D },
        { 0x1A, 0x0101130D },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x13, {
        { 0x0F, 0x0101130D },
        { 0x21, 0x01011307 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x2E, {
        { 0x1B, 0x00012300 },
        { 0x2A, 0x00012300 },
        { 0x36, 0x00012300 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x30, {
        { 0x14, 0x00012300 },
        { 0x1D, 0x00012300 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0xFFFFFFFF, {
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }}
};

EN04_MTBL en04_mtn_tbl2[6] =
{
    { 0x11, {
        { 0x0C, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x12, {
        { 0x0B, 0x00 },
        { 0x19, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x13, {
        { 0x0A, 0x00 },
        { 0x24, 0x01 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x10, {
        { 0x00, 0x01 },
        { 0x46, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0x19, {
        { 0x04, 0x00 },
        { 0x16, 0x00 },
        { 0x21, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }},
    { 0xFFFFFFFF, {
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 },
        { 0xFFFFFFFF, 0x00 }
    }}
};

const char en04_tree[1][8] =
{
    {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0xFF, 0x00}
};

char En04SdwTab[6] =
{
    0x05, 0x0F, 0x12, 0x08, 0x0B, 0xFF
};

WPNDAMAGE_WORK En04_WpnDamageTbl[22] =
{
    { 0x00, 0, 0, 0, 0 },  
    { 0x00, 0, 0, 0, 0 },  
    { 0x00, 0, 3, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 5, 3, 5 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x01, 0, 5, 3, 5 },  
    { 0x00, 0, 7, 3, 3 },  
    { 0x00, 0, 3, 3, 3 },  
    { 0x02, 0, 5, 3, 5 },  
    { 0x18, 0, 1, 3, 3 },  
    { 0x0A, 0, 1, 3, 3 },  
    { 0x00, 0, 1, 3, 3 },  
    { 0x0C, 0, 5, 3, 5 },  
    { 0x02, 0, 5, 3, 5 },  
    { 0x0C, 0, 5, 3, 5 },  
    { 0x00, 0, 1, 3, 3 },  
};

static COMBWEP_WORK CombWepTbl[21] =
{
    {0, {0, 0, 0}, 0, 0}, 
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0}
};

static COMBJOINT_WORK CombJointTbl[19] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};

CPCL Ene04CapColTab[17] =
{
    { 1,  2,  13 }, 
    { 2,  3,  13 }, 
    { 4,  4,  14 }, 
    { 0,  4,  -6 }, 
    { 5,  5,  12 }, 
    { 0,  2,  -8 }, 
    { 12, 12, 15 }, 
    { 0,  0,  10 }, 
    { 6,  7,   8 }, 
    { 7,  8,   4 },
    { 9,  10,  8 },
    { 10, 11,  4 },
    { 13, 14,  8 },
    { 14, 15,  4 },
    { 16, 17,  8 },
    { 17, 18,  4 },
    { 0,  0,   0 } 
};

BP_WORK en04_BldTbl =
{
    {0.0f, 0.1f, 0.0f},                     
    0,                                      
    0.0f,                                   
    0.08f,                                  
    {0.8f, 0.6f, 0.0f, 0.8f, 0.9f},         
    {0, 4, 8, 12, 14}                       
};

BT_WORK en04prt_blood_tbl[19] =
 {
    {      0,    0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f }, 
    {      1,    0.0f,   0.0f,   0.0f,   1.0f,   1.0f,   3.0f,   1.0f }, 
    {      2,    0.0f,   0.0f,   0.0f,   1.0f,   1.0f,   4.0f,   1.0f }, 
    {      3,    0.0f,   0.0f,   0.0f,   0.5f,   0.5f,   3.0f,   1.0f }, 
    {      4,    0.0f,   0.0f,   0.0f,   0.5f,   0.5f,   2.0f,   1.0f }, 
    {      5,    0.0f,   0.0f,   0.0f,   0.5f,   0.5f,   3.0f,   1.0f }, 
    {      6,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   4.0f,   1.0f }, 
    {      7,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   2.0f,   1.0f }, 
    {      8,    0.0f,   0.0f,   0.0f,   0.2f,   0.2f,   3.0f,   1.0f }, 
    {      9,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   4.0f,   1.0f }, 
    {     10,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   2.0f,   1.0f },  
    {     11,    0.0f,   0.0f,   0.0f,   0.2f,   0.2f,   3.0f,   1.0f },  
    {     12,    0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   2.0f,   1.0f },  
    {     13,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   4.0f,   1.0f }, 
    {     14,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   2.0f,   1.0f }, 
    {     15,    0.0f,   0.0f,   0.0f,   0.2f,   0.2f,   3.0f,   1.0f }, 
    {     16,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   4.0f,   1.0f }, 
    {     17,    0.0f,   0.0f,   0.0f,   0.2f,   0.5f,   2.0f,   1.0f }, 
    {     18,    0.0f,   0.0f,   0.0f,   0.2f,   0.2f,   3.0f,   1.0f }  
};

const int en04_hp_tbl[2][16] =
{
    { 60, 60, 60, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 120, 120, 120 },
    { 30, 30, 30, 45, 45, 45, 45, 45, 60, 60, 60, 60, 60,  75,  75,  75 } 
};

const char en04_flipTree[20] =
{
    0x00, 0x01, 0x02, 0x03, 0x04,
    0x05, 0x09, 0x0A, 0x0B, 0x06,
    0x07, 0x08, 0x0C, 0x10, 0x11,
    0x12, 0x0D, 0x0E, 0x0F, 0xFF
};

static int en04_contact_flg;
static int en04_atari_flg;

void (*bhEne04_Mode0[6])(BH_PWORK*) =
{
    bhEne04_Init,
    bhEne04_Move,
    bhEne04_Nage,
    bhEne04_Damage,
    bhEne04_Die,
    bhEne_Event
};

void (*bhEne04_MoveType[3])(BH_PWORK*) =
{
    bhEne04_MVType00,
    bhEne04_MVType01,
    bhEne04_MVType02
};

void (*bhEne04_NageType[3])(BH_PWORK*) =
{
    bhEne04_NGType00,
    bhEne04_NGType00,
    bhEne04_NGType00
};

void (*bhEne04_DamageType[3])(BH_PWORK*) =
{
    bhEne04_DGType00, 
    bhEne04_DGType00, 
    bhEne04_DGType00  
};

void (*bhEne04_DieType[3])(BH_PWORK*) = 
{
    bhEne04_DDType00,
    bhEne04_DDType00,
    bhEne04_DDType00
};

void (*bhEne04_BrainMode2[12])(BH_PWORK*) =
{
    bhEne04_Brain00,
    bhEne04_Brain01,
    bhEne04_Brain02,
    bhEne04_DmmyBrain,
    bhEne04_Brain04,
    bhEne04_DmmyBrain,
    bhEne04_Brain06,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain
};

void (*bhEne04_MoveMode2[13])(BH_PWORK*) =
{
    bhEne04_MV00,  
    bhEne04_MV01,
    bhEne04_MV02,
    bhEne04_MV03, 
    bhEne04_MV04,
    bhEne04_MV05,
    bhEne04_MV06,
    bhEne04_MV07,
    bhEne04_MV08,
    bhEne04_MV09,
    bhEne04_MV10,
    bhEne04_MV11,
    bhEne04_MV12
};

void (*bhEne04_NageMode2[2])(BH_PWORK*) =
{
    bhEne04_NG00,
    bhEne04_NG01
};

void (*bhEne04_DamageMode2[3])(BH_PWORK*) =
{
    bhEne04_DG00, 
    bhEne04_DG01,
    bhEne04_DG00
};

void (*bhEne04_DieMode2[1])(BH_PWORK*) = 
{
    bhEne04_DD00
};

void (*bhEne04_PlyDmgMode[2])(BH_PWORK*, BH_PWORK*) = 
{
    bhEne04_PlyDG00, 
    bhEne04_PlyDG01  
};

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne04_DmmyBrain(void)
{

}

// 100% matching!
void bhEne04(BH_PWORK* epw) {
    int i;
    O_WRK* op;

    bhEne04_DmgChk(epw);
    bhEne04_MainLoop(epw);
    
    if (epw->flg & 0x4)
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        
        epw->flg &= ~0x4;
    }
    
    bhEne04_CollisionCheck(epw);
    bhEne04_PlayerLink(plp, epw);
    bhCalcModel(epw);
    bhEne04_SetCollision(epw);
    
    for (i = 4, op = &sys->obwp[i]; i < (rom->obj_n - 1); i++, op++)
    {
        if ((op->flg & 0x1) && (op->id == 52) && (op->flg2 & 0x1))
        {
            bhEne04_ShakeWire(op);
        }
    }

    if (EXP0_I(0x14) > 0)
    {
        EXP0_I(0x14)--;
    }

    if (EXP0_I(0x18) > 0)
    {
        EXP0_I(0x18)--;
    }
}

// 100% matching!
void bhEne04_MainLoop(BH_PWORK* epw)
{
    bhEne04_Mode0[epw->mode0](epw); 
    
    bhEne04_PlayerControl(plp, epw);
    
    if (!(EXP0_I(0x10) & 0x40))
    {
        bhEne04_SetMtn(epw);
    }   
    if (epw->mode0 != 5)
    {        
        if (EXP0_I(0x10) & 0x80)
        {
            bhEne04_SearchNeck(epw);           
            return;
        }
        if (EXP0_I(0x1C) != 0)
        {
            if ((EXP0_I(0x1C) & 0xFFFF) < 32768)
            {
                EXP0_I(0x1C) -= 256;                
                if (EXP0_I(0x1C) < 0)
                {
                    EXP0_I(0x1C) = 0;
                }
            } 
            else
            {
                EXP0_I(0x1C) += 256;
                
                if (EXP0_I(0x1C) >= 0)
                {
                  EXP0_I(0x1C) = 0;  
                }
            }
            bhEne04_RotNeck(epw, 0, EXP0_I(0x1C), 0); // signature differs from DWARF
        }
    }
}

// 100% matching!
void bhEne04_SetCollision(BH_PWORK* epw)
{
	NJS_POINT3 pd;
	NJS_POINT3 ps;

    njGetTranslation(&epw->mlwP->owP[1].mtx, &epw->watr.c1);
    njGetTranslation(&epw->mlwP->owP[4].mtx, &epw->watr.c2);
    
    epw->watr.r = 2.0f;
    
    njUnitMatrix(NULL);
    
    njTranslate(NULL, epw->px, epw->py, epw->pz);
    njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
    
    pd.x = 0.0f;
    pd.y = 0.0f;
    pd.z = -3.0f;
    
    njCalcPoint(NULL, &pd, &ps);
    
    epw->aox = ps.x - epw->px;
    epw->aoz = ps.z - epw->pz;
}

// 100% matching!
void bhEne04_DmgChk(BH_PWORK* epw)
{
    if ((epw->flg & 4) && !(epw->flg & 2) && (bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl), (epw->total_dam != 0)))
{        
        if (!(EXP0_I(0x10) & 0x2000000) || 
            (epw->flr_no > plp->flr_no) || 
            ((WpnTab[epw->wpnr_no].flg & 0x20) != 0) || 
            (WpnTab[epw->wpnr_no].flg & 0x20000000) || 
            !(plp->at_flg & 2))
        {            
            bhEne04_DamageAdd(epw);
            if (epw->type != 0)
            {
                epw->type = 0;
            }
            if (epw->mode0 < 3)
            {
                epw->flg |= 0x40;
                if (epw->comb_flg & 4)
                {
                    EXP0_I(0x10) |= 0x100;
                }
                else
                {
                    EXP0_I(0x10) &= ~0x100;
                }
                bhEne04_ChgDmgMode(epw);
                if (EXP0_I(0x10) & 0x4000000)
                {
                    EXP0_I(0x10) &= ~0x40C0000;
                    *(unsigned int*)plp->exp1 |= 4;
                    sys->pad_on &= ~0xF;
                    plp->flg &= ~0x10000;
                    plp->flg |= 8;
                    plp->stflg &= ~0x50000;
                    plp->at_flg = 0;
                    plp->mnwP = plp->mnwPb;
                    if (plp->flg2 & 0x200)
                    {
                        plp->mode0 = 2;
                        plp->mode2 = 1;
                        plp->mode3 = 0;
                        if (bhDGCdirCheck((NJS_VECTOR*)&plp->dvx, plp->ay) == 0)
                        {
                            plp->mode1 = 0;
                        }
                        else
                        {
                            plp->mode1 = 1;
                        }
                        plp->flg |= 4;
                        return;
                    }
                    *(int*)&plp->mode0 = 1;
                    plp->flg &= ~4;
                }
            }
        }
    }
}

// 100% matching!
void bhEne04_ChgDmgMode(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl;
    int act;

    wp_tbl = En04_WpnDamageTbl;
    wp_tbl += epw->wpnr_no;
    act = wp_tbl->nm_act;
    if ((EXP0_I(0x10) & 0x100000) || epw->hp < 0)
    {
        epw->comb_flg |= 1;
        epw->comb_timeout = 0;
        epw->comb_pnt = 0;
    }

    if (epw->comb_flg & 1)
    {
        if (EXP0_I(0x10) & 0x100000)
        {
            EXP0_UC(0x3) = 0;
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 2;
            bhEne04_ChgMtn(epw, 14, 0, 10);
            EXP0_I(0x10) &= ~0x100000;
            return;
        }
        act = wp_tbl->cb_act;
    }

    if ((unsigned int)act < 4)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
        if (EXP0_I(0x10) & 0x20000)
        {
            epw->mode2 = 1;
        }
    }
}

// 100% matching!
void bhEne04_DamageAdd(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl = En04_WpnDamageTbl;
    NJS_POINT3 ofp = { 0.0f, 0.0f, 0.0f }; // @136
    int* d;
    int i;
    O_WORK* owk;

    if (epw->hp >= 0)
    {
        epw->hp -= epw->total_dam;
        wp_tbl += epw->comb_wep
            ;
        if (epw->hp < 0)
        {
            bhEne04_SePlay(epw, 16786185);
        } 
        else
        {
            bhEne04_SePlay(epw, 16847623);
        }
        
        for (d = &epw->dam[1], i = 1; i < (int)epw->mlwP->obj_num; i++, d++)
        {
            if (*d > 0)
            {
                epw->djnt_no = i;
                if (!(wp_tbl->flg & 8))
                {
                    if ((epw->comb_flg & 1) || (epw->hp < 0))
                    {
                        bhEne_SetBlood(epw, wp_tbl->cb_blood, en04prt_blood_tbl);
                    } 
                    else
                    {
                        bhEne_SetBlood(epw, wp_tbl->nm_blood, en04prt_blood_tbl);
                    }
                }
            }
        }
        
        if ((wp_tbl->flg & 1) && (epw->comb_flg & 0x10) && (epw->hp < 0))
        {
            owk = &epw->mlwP->owP[epw->djnt_no];
            ofp.x = owk->mtx[12];
            ofp.y = owk->mtx[13];
            ofp.z = owk->mtx[14];
            bhEne_SetNikuhenEffect2(epw, 2, &ofp, 4, 4);
        }
    }

    if ((wp_tbl->flg & 2) || (wp_tbl->flg & 4))
    {
        if (EXP0_I(0x18) <= 0)
        {
            EXP0_I(0x18) = 10;
            if (wp_tbl->flg & 4)
            {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en04prt_blood_tbl, 2);
                if (epw->hp < 0)
                {
                    epw->mdflg |= 0x400;
                    npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF000000);
                }
            } 
            else
            {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en04prt_blood_tbl, 1);
            }
        }
    }
    
    if (wp_tbl->flg & 0x10)
    {
        if (EXP0_I(0x18) <= 0)
        {
            EXP0_I(0x18) = 10;
            bhEne_SetSanEffect(epw, epw->djnt_no, en04prt_blood_tbl);
        }
    }
}

// 100% matching!
void bhEne04_PlayerControl(BH_PWORK* pl, BH_PWORK* epw)
{
    if ((EXP0_I(0x10) & 0x40000) && (pl->mode0 == 4 || pl->mode0 == 6))
    {
        bhEne04_PlyDmgMode[pl->mode1](pl, epw);
    }
}

// 100% matching!
void bhEne04_PlayerLink(BH_PWORK* pl, BH_PWORK* epw)
{
    NJS_POINT3 pd;

    if (EXP0_I(0x10) & 0x80000)
    {
        njUnitMatrix(NULL);
        njTranslate(NULL, epw->px, epw->py, epw->pz);
        njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
        njCalcPoint(NULL, (NJS_POINT3*) &EXP0_UC(0x30), &pd);
        pl->px = pd.x;
        pl->pz = pd.z;
        pl->ay = (epw->ay + epw->waxp) & 0xFFFF;
    }
}

// 100% matching!
void bhEne04_CollisionCheck(BH_PWORK* epw) {
    if (!(epw->flg & 2))
    {
        if ((EXP0_I(0x10) & 0x20) && (plp->hp >= 0))
        {
            bhCheckPlayer(epw);
        }
        bhCheckEnemies(epw);
    }
    bhEne04_CollCheckWall(epw);
}

// 100% matching!
void bhEne04_CollCheckWall(BH_PWORK* epw)
{
	ATR_WORK* hp;
	NJS_POINT3 ps;
	NJS_POINT3 ops;
	NJS_POINT3 pd;
	O_WORK* owk;
    O_WORK* owk2; // not from DWARF
	//char ply_tree[7];

	if (!(EXP0_I(0x10) & 0x10) && (epw->flg & 0x10))
	{
        
    	epw->stflg &= ~1;
    
    	ps.x = plp->px;
    	ps.y = plp->py;
    	ps.z = plp->pz;
    	EXP0_I(0x44) = (int)bhCollisionCheckLine((NJS_POINT3*)&epw->px, &ps);
    
    	EXP0_US(0x6) = (EXP0_US(0x6) << 1) & 0xE;
    
    	hp = bhCheckWallType((NJS_POINT3*)&epw->px, epw->flg, epw->ar, epw->ah);
    	EXP0_I(0x3C) = (int)hp;
    	if (hp != 0)
    	{
    		EXP0_US(0x6) |= 1;
    	}
    
    	if ((EXP0_I(0x10) & 0xF) == 1)
    	{
    		bhCheckWallEx(epw, (NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->pxb, epw->ar, epw->ah);
    		bhEne_CalcPartsPos(epw, lcmat, &ps, en04_tree[0], 6, 1);
    
    		ps.y = epw->py;
    		owk = epw->mlwP->owP;
    		ops.x = owk[5].mtx[12];
    		ops.z = owk[5].mtx[14];
    		ops.y = epw->pyb;
    
    		hp = bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 2.5f, epw->ah);
    		if (hp != 0)
    		{
    			EXP0_I(0x3C) = (int)hp;
    		}
    
    		epw->px += pd.x;
    		epw->py += pd.y;
    		epw->pz += pd.z;
        }
        else if ((EXP0_I(0x10) & 0xF) == 2)
        {
    		char ply_tree[7] = { 0, 1, 2, 3, 4, 5, 0xFF };
    		owk = plp->mlwP->owP;
    		ops.x = owk->mtx[12];
    		ops.z = owk->mtx[14];
            ops.y = plp->pyb;
    		
    		bhEne_CalcPartsPos(plp, lcmat, &ps, ply_tree, 1, 1);
    
    		ps.y = plp->py;
    		bhEne_CollisionCheckWall2(plp, &ps, &ops, &pd, plp->ar, plp->ah);
    
    		epw->px += pd.x;
    		epw->pz += pd.z;
    
    		owk2 = plp->mlwP->owP;
            
    		ops.x = owk2[5].mtx[12];
    		ops.z = owk2[5].mtx[14];
            ops.y = plp->pyb;
    		
    		bhEne_CalcPartsPos(plp, lcmat, &ps, ply_tree, 6, 1);
    
    		ps.y = plp->py;
    		bhEne_CollisionCheckWall2(plp, &ps, &ops, &pd, plp->ar, plp->ah);
    
    		epw->px += pd.x;
    		epw->pz += pd.z;
        }
    }
}

// 99.90% matching
void bhEne04_Init(BH_PWORK* epw)
{
    int i;
    u_char* addr;
    int size;

    en04_contact_flg = 0;
    en04_atari_flg = 0;
    epw->ar = 3.0f;
    epw->ah = 4.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 3.5f;
    epw->cah = 4.0f;
    epw->stflg = 0;
    if (sys->gm_mode != 2)
    {
        epw->hp = en04_hp_tbl[0][rand() % 16];
    }
    else
    {
        epw->hp = en04_hp_tbl[1][rand() % 16];
    }

    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }
    
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = (unsigned char*) en04_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(88, 8);
    }
    else
    {
        size = 88;
        addr = epw->exp0;
        while (size--)
        {
            *addr++ = 0;
        }
    }

    EXP0_I(0x10) |= 0x21;
    epw->flg |= 0x178;
    epw->flg &= ~2;
    epw->cpcl = Ene04CapColTab;
    if (!(epw->flg & 0x800))
    {
        bhSetShadow(En04SdwTab, (unsigned char*)epw, 1, 3.0f, 3.0f, 6.0f);
        epw->flg |= 0x800;
    }
    epw->mdflg &= ~0x400;

    npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFFB2B2B2);
    
    epw->clp_jno[0] = 4;
    epw->clp_jno[1] = 5;
    epw->clp_jno[2] = 6;
    epw->clp_jno[3] = 9;
    epw->clp_jno[4] = 15;
    epw->clp_jno[5] = 15;
    epw->clp_jno[6] = -1;
    epw->clp_jno[7] = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->lok_jno = 4;
}
// 100% matching!
void bhEne04_Move(BH_PWORK* epw) 
{
    EXP0_I(0x10) &= ~0x80;    
    bhEne04_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne04_Nage(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_NageType[epw->type](epw);
}

// 100% matching!
void bhEne04_Damage(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne04_Die(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_DieType[epw->type](epw);
}

// 100% matching!
void bhEne04_MVType00(BH_PWORK* epw)
{
    int ang_tbl[4] =
    {
        0,          // 0°
        49152,      // 270°
        32768,      // 180°
        16384       // 90°
    };

	O_WORK* owk;
	NJS_POINT3 pos;    
	ATR_WORK* hp;

    owk = plp->mlwP->owP;
    pos.x = owk[1].mtx[12];
    pos.y = epw->py;
    pos.z = owk[1].mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    if (bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 0) != NULL)
    {
        EXP0_I(0x10) |= 0x200000;
    }
    else
    {
        EXP0_I(0x10) &= ~0x200000;
    }
    
    if (epw->mode1 == 1)
    {
        bhEne04_Brain(epw);
    }
    
    if (epw->mode0 == 1)
    {
        pos.x = epw->px - (6.0f * njSin(epw->ay));
        pos.z = epw->pz - (6.0f * njCos(epw->ay));
        pos.y = 0.0f;
        if (bhEne_EnemyAtariCheck(&pos, epw->flr_no, epw->id, 5) != NULL)
        {
            EXP0_I(0x10) |= 0x8000;
        } 
        else
        {
            EXP0_I(0x10) &= ~0x8000;
        }

        if ((epw->mode2 == 2) || (epw->mode2 == 3))
        {
            hp = bhEne_EnemyAtariCheck(&pos, epw->flr_no, epw->id, 4);
            if ((hp != NULL) && (hp->prm1 == 4))
            {
                if (sys->obwp[hp->prm2].mode1 == 0)
                {
                    sys->obwp[hp->prm2].ayp = ang_tbl[hp->prm3];
                    sys->obwp[hp->prm2].mode3 = 0;
                    sys->obwp[hp->prm2].flg2 |= 1;

                    bhEne04_SePlay(epw, 70415);
                }
            }
        }
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne04_MVType01(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos;
    ATR_WORK* hp;
	unsigned char no;
    
    owk = &plp->mlwP->owP[1];   
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    hp = bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 1);    
    if (hp != NULL)
    {
        no = hp->prm3;
        hp = bhEne_EnemyAtariCheck((NJS_POINT3*) &epw->px, epw->flr_no, epw->id, 2);
        if ((hp != NULL) && (hp->prm3 == no))
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->type = 0;
        }
    }
    
    if (epw->mode0 == 1)
    {
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne04_MVType02(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos;

    owk = &plp->mlwP->owP[1];   
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    if (en04_contact_flg & 1)
    {
        bhEne04_AtariCheck2(epw);
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->type = 0;
    }
    else if (bhEne04_AtariCheck(epw) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->type = 0;
    }
    
    if (epw->mode0 == 1)
    {
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
int bhEne04_AtariCheck(BH_PWORK* epw)
{
    ATR_WORK* hp; 
    ATR_WORK* hp2;   
    ATR_WORK* fp;
    int flr_n;
    int atr_num;
    int i;
   
    hp = bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 6);
    if (hp == NULL)
    {
        return 0;
    }

    if (32 < hp->prm3)
    {
        return 0;
    }

    if (en04_atari_flg & (1 << hp->prm3))
    {
        return 0;
    }
    
    en04_atari_flg |= (1 << hp->prm3);

    atr_num = 0;
    flr_n = rom->flr_n + sys->mflr_n;

    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n)
        {
            fp = &rom->flrp[i];
        } 
        else
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 1) && 
            fp->type == 2 && 
            fp != hp && 
            fp->flr_no == epw->flr_no && 
            fp->prm0 == epw->id && 
            fp->prm1 == 6 && 
            !(en04_atari_flg & (1 << fp->prm3))) 
        { 
            atr_num++; 
        }
    }
    
    if ((atr_num == 0) || ((rand() % 2) == 0))
    {
        hp2 = bhEne04_EnemyAtariCheck2(epw, 7, hp->prm3);
        if (hp2 != NULL)
        {
            epw->px = hp2->px + (hp2->w / 2.0f);
            epw->pz = hp2->pz + (hp2->d / 2.0f);
            
            epw->ay = kaidan_ang[hp2->prm2];
            
            sys->rm_flg |= 1 << (hp2->prm3 + 16);
            
            en04_contact_flg |= 1;
            
            return 1;
        }
    }
    return 0;
}

// 100% matching!
int bhEne04_AtariCheck2(BH_PWORK* epw) {
	ATR_WORK* hp;
	ATR_WORK* hp2;
    ATR_WORK* fp;
    ATR_WORK* work[32];
    int flr_n;
    int atr_num;
	int i;

    hp = bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 6);
    
    if (hp == NULL)
    {
        return 0;
    }
    
    if (32 < hp->prm3)
    {
        return 0;
    }
    
    atr_num = 0;
    flr_n = rom->flr_n + sys->mflr_n;
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n)
        {
            fp = &rom->flrp[i];
        } 
        else
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
    
        if ((fp->flg & 1) && 
            (fp->type == 2) && 
            (fp != hp) && 
            (fp->flr_no == epw->flr_no) && 
            (fp->prm0 == epw->id) && 
            (fp->prm1 == 6)) 
        {
            work[atr_num++] = fp;
        }
    }
    
    if (atr_num > 0)
    {
        if (atr_num == 1)
        {
            fp = work[0];
        }
        else
        {
            fp = work[rand() % atr_num];
        }
        
        hp2 = bhEne04_EnemyAtariCheck2(epw, 7, fp->prm3);
        if (hp2 != NULL)
        {
            epw->px = hp2->px + (hp2->w / 2.0f);
            epw->pz = hp2->pz + (hp2->d / 2.0f);
            
            epw->ay = kaidan_ang[hp2->prm2];
            if ((rand() % 3) == 0)
            {
                sys->rm_flg |= 1 << (hp2->prm3 + 16);
            }
            return 1;
        }

    }
    return 0;
}

// 100% matching! 
ATR_WORK* bhEne04_EnemyAtariCheck2(BH_PWORK* epw, unsigned char type, unsigned char ip)
{
    ATR_WORK* fp;
    int i;
    int flr_n;

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n)
        {
            fp = &rom->flrp[i];
        }
        else
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 1) && 
            (fp->type == 2) && 
            (fp->flr_no == epw->flr_no) && 
            (fp->prm0 == epw->id) && 
            (fp->prm1 == type) && 
            (fp->prm3 == ip))
        {            
            return fp;
        }
    }

    return NULL;
}

// 100% matching! 
void bhEne04_EneSearch(BH_PWORK* epw)
{
    EXP0_UC(0) |= 0x80;

    if ((EXP0_UC(0) & 0x1F) < 4)
    {
        if (bhSearchPlayer(epw, 18204) != -1)
        {
            if ((unsigned char*)EXP0_I(0x44) == NULL)
            {
                EXP0_UC(0) |= 0x20;
            }
            else
            {
                if (*(unsigned char*)(EXP0_I(0x44) + 1) == 1 || 
                    *(unsigned char*)(EXP0_I(0x44) + 1) == 3 || 
                    *(unsigned char*)(EXP0_I(0x44) + 1) == 5) 
                {
                    EXP0_UC(0) |= 0x20;
                }
            }
        }

        if ((EXP0_UC(0) & 0x1F) == 3)
        {
            if (EXP0_UC(0) & 0x20)
            {
                EXP0_UC(0) |= 0x40;
            }
            else
            {
                EXP0_UC(0) &= ~0x40;
            }
            EXP0_UC(0) &= 0x5F;
        }
    }

    EXP0_UC(0)++;

    if (15 < (EXP0_UC(0) & 0x1F))
    {
        EXP0_UC(0) &= 0xE0;
    }
}

// 100% matching!
void bhEne04_Brain(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    bhEne04_EneSearch(epw);

    if (!(EXP0_UC(0) & 0x80))
    {
        if (EXP0_UC(0) & 0x40)
        {
            if ((EXP0_F(0x20) < 50.0f) && (EXP0_I(0x44) == 0) && (epw->flr_no == plp->flr_no))
            {
                EXP0_F(0x24) = plp->px;
                EXP0_F(0x2C) = plp->pz;
            }
            else
            {
                bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos);
                EXP0_F(0x24) = pos.x;
                EXP0_F(0x2C) = pos.z;
            }
        }
        else
        {
            bhCheckRoute((NJS_POINT3*)&epw->px,(NJS_POINT3*) &plp->px, &pos);
            EXP0_F(0x24) = pos.x;
            EXP0_F(0x2C) = pos.z;
        }
    }
    bhEne04_BrainMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_Brain00(BH_PWORK* epw)
{
    if (((ikou3(epw, (NJS_POINT3*)&plp->px, 12288) == 0) && (EXP0_F(0x20) < 35.0f)) ||
        ((plp->mode1 == 1) && (plp->mode2 == 69)) ||
        ((plp->mode2 == 6) && (EXP0_F(0x20) < 40.0f)))
    {
        EXP0_I(0x10) |= 0x400000;
    }
}

// 100% matching!
void bhEne04_Brain01(BH_PWORK* epw)
{
    if (((ikou3(epw, (NJS_POINT3*)&plp->px, 8192) == 0) && (EXP0_F(0x20) < 20.0f)) ||
        ((plp->mode1 == 1) && (plp->mode2 == 69)) ||
        ((plp->mode2 == 6) && (EXP0_F(0x20) < 40.0f)) ||
        (EXP0_I(0x10) & 0x8000)) 
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne04_Brain02(BH_PWORK* epw) {
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    int back_flg;

    if (EXP0_F(0x20) < 20.0f && !(EXP0_I(0x10) & 0x8000) && !(plp->flg & 0x4) && (epw->flr_no == plp->flr_no))
    {        
        if (EXP0_F(0x20) > 11.0f)
        {            
            if (!ikou3(epw, (NJS_POINT3*)&plp->px, 1024))
            {
                back_flg = bhCdirCheck(epw->ay, plp->ay);
                
                if (back_flg == 0 || (back_flg == 1 && plp->mode2 != 6))
                { 
                    pos.x = epw->px;
                    pos.y = epw->py;
                    pos.z = epw->pz;
                    pos2.x = plp->px;
                    pos2.y = plp->py;
                    pos2.z = plp->pz;
                    
                    if (!bhCollisionCheckLine(&pos, &pos2))
                    {
                        epw->mode1 = 0;
                        epw->mode2 = 7;
                        epw->mode3 = 0;
                    }
                }
            }
        } 
        else
        {
            if (!ikou3(epw, (NJS_POINT3*)&plp->px, 2048))
            {
                back_flg = bhCdirCheck(epw->ay, plp->ay);
                
                if (!(EXP0_I(0x10) & 0x200000) && !(plp->flg & 0x6) && !(plp->stflg & 0x80000000) && back_flg == 0)
                {
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    plp->flg |= 0x4;
                    plp->flg |= 0x10000;
                    EXP0_I(0x10) |= 0x4000000; 
                    return;
                }
                
                epw->mode1 = 0;
                epw->mode2 = 9;
                epw->mode3 = 0;
            }
        }

        if (!ikou3(epw, (NJS_POINT3*)&plp->px, 16384))
        {
            EXP0_I(0x10) |= 0x2000;
        }
        else
        {
            if (EXP0_I(0x10) & 0x2000)
            {
                if (56 < (rand() % 64))
                {
                    EXP0_I(0x10) &= ~0x2000; 
                    EXP0_I(0x10) |= 0x1800;
                }
            }
        }
    }

    if (EXP0_F(0x20) >= 8.0f && EXP0_F(0x20) <= 15.0f && (plp->flg & 0x4))
    {
        if (!ikou3(epw, (NJS_POINT3*)&plp->px, 4096))
        {
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
    }

    if (bhEne04_KaidanCheck(epw))
    {
        EXP0_I(0x10) |= 0x20000;
        epw->mode1 = 0;
        epw->mode2 = 11;
        epw->mode3 = 0;
        EXP0_F(0x30) = epw->px;
        EXP0_F(0x34) = epw->py;
        EXP0_F(0x38) = epw->pz;
    }
}

// 100% matching!
void bhEne04_Brain04(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_POINT3 pos2;

    if (plp->hp < 0)
    {
        epw->mode1 = 0;
        epw->mode2 = 12;
        epw->mode3 = 0;
        EXP0_I(0x10) &= ~0x2000000;
        return;
    }
    
    if ((EXP0_F(0x20) < 20.0f) && !(EXP0_I(0x10) & 0x8000) && !(plp->flg & 4) && (epw->flr_no == plp->flr_no))
    {
        if (!(EXP0_F(0x20) <= 11.0f))
        {
            if (ikou3(epw, (NJS_POINT3*)&plp->px, 1024) == 0)
            {
                pos.x = epw->px;
                pos.y = epw->py;
                pos.z = epw->pz;
                
                pos2.x = plp->px;
                pos2.y = plp->py;
                pos2.z = plp->pz;
                
                if (bhCollisionCheckLine(&pos, &pos2) == NULL)
                {
                    epw->mode1 = 0;
                    epw->mode2 = 7;
                    epw->mode3 = 0;
                    EXP0_I(0x10) &= ~0x2000000;
                }
            }
        }
        else if (ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            EXP0_I(0x10) &= ~0x2000000;
        }
    }
}

// 100% matching!
void bhEne04_Brain06(BH_PWORK* epw)
{
    if (EXP0_F(0x20) < 11.0f)
    {
        epw->ct1++;
        if ((plp->spd >= 0.9f))
        {
            epw->ct1 += 20;
        }
        if ((ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0) && !(plp->flg & 4) && (epw->flr_no == plp->flr_no) && !(EXP0_F(0x20) <= 8.0f))
        {
            epw->mode1 = 0;
            epw->mode2 = 7;
            epw->mode3 = 0;
            en04_contact_flg |= 2;
        }
    }
    else
    {
        epw->ct1 -= epw->ct2 > 0;
        if ((ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0) && (plp->spd >= 0.9f))
        {
            epw->ct1 += 6;
        }
    }
    
    if ((epw->ct1 >= 65) || ((plp->mode1 == 1) && (plp->mode2 == 69)) || (en04_contact_flg & 2) || (EXP0_I(0x10) & 0x8000))
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne04_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->type == 0)
        {
            bhEne04_ChgMtn(epw, 47, 0, 7);
        }
        else
        {
            bhEne04_ChgMtn(epw, 49, 0, 7);
        }
        epw->ct0 = (rand() % 128) + 100;
        epw->mode1 = 1;
        epw->mode3++;

    case 1:
        EXP0_I(0x10) |= 0x80;
        EXP0_I(0x1C) = 4096;
        epw->ct0--;
        if (((epw->ct0 <= 0) || (EXP0_I(0x10) & 0x400000)) && (epw->type == 0))
        {
            bhEne04_ChgMtn(epw, 48, 0, 10);
            if (!(EXP0_I(0x10) & 0x400000))
            {
                EXP0_I(0x10) &= ~0x80;
                EXP0_I(0x1C) = 0;
            }
            epw->mode3++;
        }
        break;
        
    case 2:
        if (EXP0_I(0x10) & 0x400000)
        {
            EXP0_I(0x10) |= 0x80;
        }
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            if (EXP0_I(0x10) & 0x400000)
            {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
            }
            else 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne04_MV01(BH_PWORK* epw)
{
    int hit;

    if ((EXP0_UC(0x0) & 0x40) && (EXP0_F(0x20) < 35.0f))
    {
        EXP0_I(0x10) |= 0x80;
    }
    
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        
        epw->way = 256;
        epw->ct0 = (rand() % 32) + 75;
        epw->ct2 = 0;

        EXP0_F(0x24) = plp->px; 
        EXP0_F(0x2C) = plp->pz; 

        epw->mode3++; 

    case 1:
        epw->spd = 0.15f;

        if ((EXP0_UC(0x0) & 0x40) && (EXP0_F(0x20) < 35.0f))
        {
            ikou(epw, (NJS_POINT3*)&EXP0_UC(0x24), epw->way);
        }

        bhAddSpeed(epw, 0);

        if (EXP0_I(0x3C) != 0 || epw->ct0 == 0)
        {
            hit = bhEne_CheckSideWall(epw, 10.0f, 0);
            
            if (hit == 0)
            {
                epw->way = ((rand() % 2) != 0) ? 256 : -256;
            } 
            else
            {
                epw->way = hit * 256;
            }

            epw->ct0 = 16384;
            epw->ct1 = 256;
            epw->mode3++;
        } 
        else
        {
            epw->ct0--;
        }
        break;

    case 2:
        epw->spd = 0.08f;
        bhAddSpeed(epw, 16);

        epw->ay += epw->way;
        epw->ct0 -= 256;

        if (epw->ct0 < 0)
        {
            epw->mode3 = 1;
            epw->ct0 = (rand() % 32) + 75;
        }
    }

    epw->ct2++;
    
    if ((epw->ct2 % 90) == 0)
    {
        bhEne04_SePlay(epw, 16851714);
    }
}

// 99.85% matching
void bhEne04_MV02(BH_PWORK* epw)
{
	int rot;
	int ang;

    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no == 6)
        {
            bhEne04_ChgMtn(epw, 1, 327680, 0);
        } else {
            bhEne04_ChgMtn(epw, 1, 0, 7);
        }
        epw->way = 1152;
        epw->wax = 0;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        epw->ct3 = 0;
        if (EXP0_I(0x10) & 0x800)
        {
            epw->ct1 = (rand() % 15) + 20;
        }
        EXP0_I(0x10) &= ~0x3000;
        EXP0_I(0x10) &= ~0x4000;
        epw->spd = 0.08f;
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
        epw->mode3++;

    case 1:
        if (EXP0_I(0x10) & 0x1000) {
            epw->mode3 = 2;
        } else {
            bhEne04_SpeedUp(&epw->spd, 0.1f, 1.2f);
            if ((epw->spd >= 1.2f) && (epw->ct1 < 10) && (epw->ct3 == 0))
            {
                rot = NitenDir_ck(epw->px, epw->pz, EXP0_F(0x24), EXP0_F(0x2C));
                epw->azp = (rot - epw->ay) & 0xFFFF;
                rot = ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), epw->way);
                ikou(epw, (NJS_POINT3*)&EXP0_UC(0x24), epw->way);
                epw->wax = rot;
            } 
            else
            {

                if (EXP0_I(0x3C))
                {
                    epw->wax = (!(EXP0_I(0x10) & 0x800) ? 64 : 0) + ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), epw->way);
                    EXP0_I(0x10) &= ~0x800;
                }
                rot = epw->wax;
                epw->ay += rot;
                if (--epw->ct1 < 11)
                {
                    epw->ct1 = 5;
                    EXP0_I(0x10) &= ~0x800;
                }
            }            
            if (!(EXP0_UC(0) & 0x80))
            {
                if (!(EXP0_UC(0) & 0x40))
                {
                    if (++epw->ct2 >= 6)
                    {
                        epw->mode2 = 6;
                        epw->mode3 = 0;
                        break;
                    } 
                } 
                else
                {
                    epw->ct2 = 0;
                    
                }
            } 
                        
            ang = ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), 8192);
            if (((ang != 0) && !(EXP0_F(0x20) < 20.0f) && (EXP0_I(0x3C) != 0)) || ((EXP0_I(0x44) != 0) && (EXP0_I(0x3C) != 0)))
            {
                epw->ct0 += 2;
                if (20 < epw->ct0)
                {
                    epw->mode1 = 0;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                }
            } 
            else
            {
                epw->ct0 = epw->ct0 - (0 < epw->ct0);
            }
                bhAddSpeed(epw,0);

        }
        break;
    case 2:
        epw->wax = 0;
        epw->ct0 = 0;
        epw->mode3++;

    case 3:
        rot = ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), 1280);
        bhAddSpeed(epw, -rot);
        
        if (epw->ct0 == 0)
        {
            bhEne04_SpeedDown(&epw->spd, 0.07f, 0.05f);
            if (epw->spd <= 0.05f)
            {
                epw->ct0 += 1;
            }
        } 
        else
        {
            bhEne04_SpeedUp(&epw->spd, 0.07f, 1.2f);
        
        }
        epw->ay += rot;
        epw->wax += 1280;
        
        if (((unsigned short) epw->wax >= 32768) || (rot == 0))
        {
            EXP0_I(0x10) &= ~0x1000;
            epw->ct0 = 0;
            epw->wax = 0;
            epw->mode3 = 1;
        }
        break;
    case 4:
        bhEne04_SpeedUp(&epw->spd, 0.1f, 1.2f);
        bhAddSpeed(epw, 0);
        rot = bhEne04_Escape(epw, 90, 1152);
        
        if (EXP0_I(0x10) & 0x4000)
        {
            epw->ct3 = ((rand() % 3) * 2) + 8;
            epw->mode3 = 0;
        }
        break;
    case 5:
        rot = 1280;
        bhAddSpeed(epw, -1280);
        if (epw->ct0 == 0)
        {
            bhEne04_SpeedDown(&epw->spd, 0.07f, 0.05f);
            if (epw->spd <= 0.05f)
            {
                epw->ct0++;
            }
        } 
        else
        {
            bhEne04_SpeedUp(&epw->spd, 0.07f, 1.2f);
        }
        
        epw->ay += 1280;
        epw->wax += 1280;
        if ((unsigned short) epw->wax >= 32768)
        {
            EXP0_UC(0) = 132;
            epw->ct1 = (rand() % 15) + 20;
            epw->ct0 = 0;
            epw->wax = 0;
            epw->mode3 = 0;
        }
        break;
    }

    if (((((NitenDir_ck(epw->px, epw->pz, EXP0_F(0x24), EXP0_F(0x2C)) - epw->ay) + 9102) & 0xFFFF) < 18204) || (EXP0_F(0x20) < 15.0f))
    {
        rot = 0;
    }
    bhEne04_RunMotion(epw, rot);
}

// 100% matching!
void bhEne04_MV03(BH_PWORK* epw)
{
    int hit;
    int rot; 
    
    switch (epw->mode3)
    { 
    case 0:
        hit = bhEne_CheckSideWall(epw, 10.0f, 0);
        
        if (hit == 0)
        {
            rot = ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), 1536);
            rot = (rot == 0) ? ((rand() % 2) ? 1536 : -1536) : rot;
        } 
        else
        {
            rot = hit * 1536;
        }
        
        epw->way = rot;
        
        epw->ct0 = 8;
        epw->ct1 = 0;
        epw->mode3++;
        
    case 1:
        epw->ay += epw->way;
        bhAddSpeed(epw, 0);
        
        if (epw->ct0 > 0)
        {
            epw->ct0--;
        }
        else if (EXP0_I(0x3C) == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;

            epw->way = 1152;
        }
        break;
        
    case 2:
        epw->ay += epw->way;
        bhAddSpeed(epw, 0);
        
        if (EXP0_I(0x3C) == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->way = 1152;
            break;
        }

        if (epw->ct0++ >= 8)
        {
            epw->ct0 = 19;
            epw->spd = 0.3f;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne04_SpeedDown(&epw->spd, 0.1f, 0.08f);
        ikou(epw, (NJS_POINT3*)&EXP0_UC(0x24), 256);

        if (epw->ct0-- <= 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->way = 1152;
            break;
        }
        break;
    }
    
    bhEne04_RunMotion(epw, epw->way);
}

// 100% matching!
void bhEne04_MV04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 7, 0, 7);
        EXP0_I(0x10) |= 0x40000000;
        epw->mode1 = 0;
        epw->mode3++;
    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 512);
        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 49, 0, 0);
            EXP0_I(0x10) &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode3++;
        }
        break;
    case 2:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 512);
        if (!(plp->flg & 4))
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            EXP0_I(0x10) &= ~0x2000000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no == 45)
        {
            epw->ay += 32768;
        }
        if (EXP0_I(0x10) & 0x8000)
        {
            bhEne04_ChgMtn(epw, 46, 0, 0);
            EXP0_I(0x10) &= ~0x40000000;
        }
        else
        {
            bhEne04_ChgMtn(epw, 15, 0, 0);
        }
        EXP0_I(0x10) |= 0x100000;
        epw->flg2 |= 1;
        epw->mode3++;
    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->px, 512);
        if ((epw->frm_no / 65536) >= 30)
        {
            EXP0_I(0x10) &= ~0x100000;
        }
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            if (EXP0_I(0x10) & 0x8000)
            {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                EXP0_I(0x10) &= ~0x2000000;
            }
            else
            {
                epw->mode1 = 0;
                epw->mode2 = 4;
                epw->mode3 = 0;
            }
            epw->flg2 &= ~1;
        }
        break;
    }
}

void bhEne04_MV06(BH_PWORK* epw)
{
	int rot;
    
    EXP0_I(0x10) |= 0x80;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        
        epw->way = 256 - ((int)(rand() % 7) * 16);       
        epw->ct0 = (rand() % 32) + 45;        
        epw->ct1 = 0;
        
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
        EXP0_I(0x10) &= ~0x4000;
        
        epw->mode3++;

    case 1:
        epw->spd = 0.15f;
        bhAddSpeed(epw, 0);

        epw->ay += epw->way;
        
        if (--epw->ct0 == 0)
        {
            epw->ct0 = (rand() % 32) + 15;
            epw->mode3++;
        }
        break;
    case 2:
        bhAddSpeed(epw, 0);
        if ((--epw->ct0 == 0) || (EXP0_I(0x3C) != 0))
        {
            epw->way = ikou3(epw, (NJS_POINT3*)&plp->px, 256 - ((rand() % 7) * 16));
            epw->ct0 = 2;
            epw->mode3 = 1;
            epw->ct0 = (rand() % 32) + 45;
        }
        break;
    case 3:
        bhAddSpeed(epw, 0);
        bhEne04_Escape(epw, 600, 256);
        if (EXP0_I(0x10) & 0x4000)
        {
            epw->mode3 = 0;
        }
        break;
    }
    
    if (epw->mode3 != 3)
    {
        rot = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        if (bhEne_CheckDirWall(epw, rot, 8.0f) != NULL)
        {
            EXP0_I(0x50) = 0;
            EXP0_I(0x4C)= 0;
            EXP0_I(0x48) = 0;
            epw->mode3 = 3;
        }
    }
}

// 100% matching!
void bhEne04_MV07(BH_PWORK* epw)
{
    ATR_WORK* hp;
    O_WORK* owk;
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    NJS_POINT3 pos3;
	int ret;

    switch (epw->mode3)
    {
    case 0:  
        bhEne04_ChgMtn(epw, 4, 0, 7);
        epw->spd = 0.4f;
        epw->ct0 = 11;
        epw->mode3++;

    case 1: 
        bhAddSpeed(epw, 0);
        epw->ct0--;
        if (epw->ct0 <= 0) {
            epw->ct0 = 0;
            EXP0_F(0x48) = 2.2f;
            EXP0_I(0x10) |= 0x400;
            epw->spd = 1.9f;
            epw->mode3++;            
        }
        break;

    case 2:
        bhAddSpeed(epw, 0);
        epw->py += EXP0_F(0x48) - (0.28f * epw->ct0);
        epw->ct0++;
        if (((epw->frm_no / 65536) >= 13) || (epw->flg & 0x2000000))
        {
            ret = bhEne04_PlyDamageCheck(epw, 1);
            if (ret == 2)
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
                EXP0_I(0x10) &= ~0x400;
                EXP0_I(0x10) |= 0x4000000;
                plp->flg |= 4;
                plp->flg |= 0x10000;
                break;
            }
            else if (ret == 1)
            {
                bhEne04_ChgMtn(epw, 9, 0, 0);
                epw->mode1 = 0;
                epw->mode2 = 8;
                epw->mode3 = 0;
                plp->hp -= 12;
                break;
            }            
        }
        else
        {
            if (bhEne04_PlyDamageCheck(epw, 0) != 0)
            {
                bhEne04_ChgMtn(epw, 8, 0, 5);
                epw->mode1 = 0;
                epw->mode2 = 8;
                epw->mode3 = 2;
                plp->hp -= 6;
                break;
            }
        }
        
        if ((epw->frm_no / 65536) == 17)
        {
            bhEne04_ChgMtn(epw, 5, 0, 0);
            epw->mode3++;
        }
        break;

    case 3:
        bhAddSpeed(epw, 0);
        epw->py += EXP0_F(0x48) - (0.28f * epw->ct0);
        epw->ct0++;
        owk = epw->mlwP->owP;
        pos.x = owk[5].mtx[12];
        pos.y = owk[5].mtx[13];
        pos.z = owk[5].mtx[14];
        pos2.x = pos.x - (6.0f * njSin(epw->ay));
        pos2.z = pos.z - (6.0f * njCos(epw->ay));
        pos2.y = pos.y;
        ret = bhEne04_PlyDamageCheck(epw, 1);
        if (ret != 0)
        {
            if (ret == 2)
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
                EXP0_I(0x10) &= ~0x400;
                EXP0_I(0x10) |= 0x4000000;
                plp->flg |= 4;
                plp->flg |= 0x10000;
                break;
            } 
            else if (ret == 1)
            {
                bhEne04_ChgMtn(epw, 9, 0, 0);
                epw->mode1 = 0;
                epw->mode2 = 8;
                epw->mode3 = 0;
                plp->hp -= 12;
                break;
            }             
        }
      
        hp = bhCollisionCheckLine(&pos, &pos2);
        if ((hp != NULL) && !(hp->attr & 8))
        {
            bhGetHitCollisionNormal(&pos3);
            if (bhEne_AngleCheck(&pos3, epw->ay, 8192) != 0)
            {
                epw->ayp = (10430.381f * atan2f(pos3.x, pos3.z));
                epw->ayp = (epw->ayp - epw->ay) & 0xFFFF;
                if (32768 < epw->ayp)
                {
                    epw->ayp = (epw->ayp - 32768) - 32768;
                }
                bhEne04_ChgMtn(epw, 20, 0, 0);
                epw->mode3 = 6;
                epw->ct0 = 0;
                break;
            }
        }  
        if (7 < epw->ct0)
        {
            bhEne04_ChgMtn(epw, 6, 0, 0);
            epw->mode3++;
        }
        break;

    case 4:
        bhAddSpeed(epw, 0);
        epw->py += EXP0_F(0x48) - (0.28f * epw->ct0);
        if (epw->py <= rom->grand[epw->flr_no + 2])
        {
            epw->flg |= 0x100;
            epw->py = rom->grand[epw->flr_no + 2];
        }
        epw->ct0++;
        if ((epw->frm_no / 65536) == 9)
        {
            epw->mode3++;
            EXP0_I(0x10) &= ~0x400;
        }
        break;

    case 5:
        bhAddSpeed(epw, 0);
        bhEne04_SpeedDown(&epw->spd, 0.2f, 1.2f);
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;

    case 6:  
        if ((epw->frm_no / 65536) < 8)
        {
            epw->ay += epw->ayp / 8;
        }
        epw->spd = (2.0 - epw->ct0 * 0.1f);
        bhAddSpeed(epw, 0);        
        epw->ct0++;
        if ((epw->frm_no / 65536) == 11)
        {
            epw->ct0 = 10;
            epw->spd = 1.9f;
            epw->mode3++;
        }
        break;
        
    case 7:     
        bhAddSpeed(epw, 32768);
        bhEne04_SpeedDown(&epw->spd, 0.2f, 1.2f);
        epw->py += EXP0_F(0x48) - (0.28f * epw->ct0);
        
        if (epw->py <= rom->grand[epw->flr_no + 2])
        {
            EXP0_I(0x10) &= ~0x400;
            epw->flg |= 0x100;
            epw->py = rom->grand[epw->flr_no + 2];
        }
        epw->ct0++;
        
        if ((epw->frm_no / 65536) == 20)
        {
            epw->mlwP->objP->ang[1] = 0;
            bhEne04_ChgMtn(epw, 1, 0, 5);
            epw->ay = epw->ay + 32768;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 99.84% matching
void bhEne04_MV08(BH_PWORK* epw)
{
	NJS_POINT3 pos;
    int frm;
	float jump;

    switch (epw->mode3)
    {
    case 0:
        EXP0_I(0x10) |= 0x800;
        epw->ct0 = 8;
        epw->ct1 = 5;
        EXP0_F(0x48) = 2.2f;
        epw->way = 0;
        epw->spd = 0.8f;
        epw->car = 1.5f;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if (frm < 10)
        {
            epw->spd = (1.2000000476837158f - epw->ct0 * 0.05);
            bhAddSpeed(epw, 0);
            epw->ct0 ++;
        }
        if (frm >= 14 && frm < 26)
        {
            epw->car = 3.5f;
            epw->py += EXP0_F(0x48) - (0.28f * epw->ct1);
            if (epw->py <= rom->grand[epw->flr_no + 2])
            {
                EXP0_I(0x10) &= ~0x400;
                epw->flg |= 0x100;
                epw->py = rom->grand[epw->flr_no + 2];
            } 
            else 
            {
                epw->spd = 0.8f;
                bhAddSpeed(epw, 32768);
            }
            epw->ct1++;
        }
        if ((epw->frm_no / 65536) == 26)
        {
            epw->mlwP->objP->ang[1] = 0;
            bhEne04_ChgMtn(epw, 1, 0, 5);
            epw->ay += 32768;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    case 2:
        EXP0_I(0x10) |= 0x800;
        epw->ct0 = 0;
        epw->ct1 = 10;
        EXP0_F(0x48) = 2.5f;
        epw->way = 0;
        epw->spd = 0.8f;
        
        pos.x = epw->px;
        pos.y = epw->py;
        pos.z = epw->pz;
        
        epw->px = plp->px;
        epw->py = plp->py;
        epw->pz = plp->pz;
        
        epw->spd = 1.0f;
        
        epw->way = bhEne_CheckSideWall(epw, 5.0f, 3);
        
        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;
        
        EXP0_F(0x24) = epw->px - (40.0f * njSin(epw->ay));
        EXP0_F(0x2C) = epw->pz - (40.0f * njCos(epw->ay));
        EXP0_F(0x28) = rom->grand[epw->flr_no + 2];

        if (epw->way == 3)
        {
            epw->way = 0;
        } 
        else
        {
            if (epw->way == 0)
            {
                epw->way = 1;
            }
            pos.x = EXP0_F(0x24);
            pos.y = EXP0_F(0x28);
            pos.z = EXP0_F(0x2C);
            if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos))
            {
                epw->way = 0;
            }
            if (epw->way > 0)
            {
                epw->mtn_md |= 2;
            }
            epw->way *= 546;
        }
        epw->mode3++;
    case 3:
        frm = epw->frm_no / 65536;
        if (frm >= 4 && frm < 14)
        { 
            epw->ay += epw->way;            
        }
        if (frm < 13)
        {
            jump = 0.3 - (float)epw->ct0 * 0.02f;
            epw->ct0++;
        } else
        {
            jump = EXP0_F(0x48) - 0.28f * epw->ct1;
            epw->ct1++;
        }
        epw->py += jump;
        if (epw->py <= rom->grand[epw->flr_no + 2])
        {
            EXP0_I(0x10) &= ~0x400;
            epw->flg |= 0x100;
            epw->py = rom->grand[epw->flr_no + 2];
        }
        if (frm == 26)
        {            
            if (epw->way == 0)
            {
                epw->mode3 = 5;
            } 
            else
            {
                epw->mode3 = 4;
            }
            bhEne04_ChgMtn(epw, 1, 0, 5);
            epw->way = 1152;
            epw->spd = 0.08f;
            epw->ct0 = 12;
        }
        break;
    case 4:

        if (--epw->ct0 < 0)
        {
            EXP0_UC(0) = 132;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 1;
        }
        bhEne04_SpeedUp(&epw->spd, 0.1f, 1.2f);
        bhAddSpeed(epw, 0);
        bhEne04_RunMotion(epw, 0);
        break;
    case 5:
        bhAddSpeed(epw, -1280);
        if (epw->ct0 == 0)
        {
            bhEne04_SpeedDown(&epw->spd, 0.07f, 0.05f);
            if (epw->spd <= 0.05f)
            {
                epw->ct0++;
            }
        } 
        else
        {
            bhEne04_SpeedUp(&epw->spd, 0.07f, 1.2f);
        }
        
        epw->ay += 1280;
        epw->wax += 1280;
        
        if ((unsigned short)epw->wax >= 32768)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        bhEne04_RunMotion(epw, 1280);
        break;
    }
}


// 100% matching!
void bhEne04_MV09(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 36, 0, 5);
        epw->spd = 0.0f;
        epw->way = -546;
        EXP0_I(0x10) |= 0x40000000;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 4) && (frm < 14))
        {
            epw->ay += epw->way;
            
            if (bhEne04_PlyDamageCheck(epw, 0) != 0)
            {
                plp->hp -= 6;
            }
        }
        
        if (epw->flg & 0x2000000)
        {
            EXP0_I(0x10) &= ~0x40000000;
            
            bhEne04_ChgMtn(epw, 1, 0, 0);
            
            epw->wax = 0;
            
            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct2 = 0;
            
            if (EXP0_I(0x10) & 0x800)
            {
                epw->ct1 = (rand() % 15) + 20;
            }
            
            EXP0_I(0x10) &= ~0x3000;
            EXP0_I(0x10) &= ~0x4000;
            
            epw->spd = 0.6f;
            
            EXP0_F(0x24) = plp->px;
            EXP0_F(0x2C) = plp->pz;
            
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 1;
        }
        break;
    }
}

// 99.64% matching
void bhEne04_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 33, 0, 5);
      
    case 1:
        if ((epw->frm_no / 65536) < 8)
        {
            epw->ay += epw->ayp / 8;
        }

        bhEne04_SpeedUp(&epw->spd, 0.1f, 1.2f); // float memes? :(
        bhAddSpeed(epw, 0);

        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 1, 0, 0);

            epw->wax = 0;

            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct2 = 0;

            if (EXP0_I(0x10) & 0x800)
            {
                epw->ct1 = (rand() % 15) + 20;
            }

            EXP0_I(0x10) &= ~0x3000;
            EXP0_I(0x10) &= ~0x4000;

            epw->spd = 0.6f;

            EXP0_F(0x24) = plp->px;
            EXP0_F(0x2C) = plp->pz;

            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 1;
        }
    }
}

// 100% matching!
void bhEne04_MV11(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (*(unsigned char*)((char*)EXP0_I(0x40) + 0x20) == 0)
        {
            EXP0_UC(0x5) = 0;
            epw->yn = epw->py + (*(unsigned char*)((char*)EXP0_I(0x40) + 0x22) * 2);
            EXP0_I(0x10) |= 0x10000;
        } 
        else
        {
            EXP0_C(0x5) = *(unsigned char*)((char*)EXP0_I(0x40) + 0x22);
            epw->yn = epw->py - (*(unsigned char*)((char*)EXP0_I(0x40) + 0x22) * 2);
            EXP0_I(0x10) &= ~0x10000;
        }
        
        EXP0_C(0x4) = epw->flr_no;
        EXP0_I(0x10) |= 0x10;
        
        epw->axp = kaidan_ang[*(unsigned char*)((char*)EXP0_I(0x40) + 0x21)];
        epw->ayp = (epw->axp - epw->ay) & 0xFFFF;
        if (epw->ayp > 32768)
        {
            epw->ayp -= 65536;
        }
        epw->ayp /= 10;
        epw->ct0 = 10;
        epw->mode3++;
    case 1:
        epw->ay += epw->ayp;
        if (--epw->ct0 < 0)
        {
            bhEne04_ChgMtn(epw, (EXP0_I(0x10) & 0x10000) ? 37 : 38, 0, 5);
            
            EXP0_I(0x10) |= 0x40000000;
            EXP0_I(0x10) |= 0x20000;
            EXP0_I(0x10) &= ~0x20;
            
            epw->flg2 |= 1;
            
            EXP0_F(0x30) = epw->px;
            EXP0_F(0x34) = epw->py;
            EXP0_F(0x38) = epw->pz;
            
            epw->ay = epw->axp;
            epw->mode3++;
        }
        break;
    case 2:
        if (EXP0_I(0x10) & 0x10000)
        {
            epw->cah = epw->mlwP->owP[5].mtx[13] - epw->py;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flr_no = bhCheckFloorNum(epw->yn);            
            epw->py = rom->grand[2 + epw->flr_no];            
            epw->flg2 &= ~1;            
            bhEne04_ChgMtn(epw, 1, 0, 10);           
            epw->mtn_md |= 0x100;            
            bhClrUseKaidanFlag(epw);
            epw->cah = 4.0f;
            
            EXP0_I(0x10) &= ~0x10;
            EXP0_I(0x10) &= ~0x40000000;
            EXP0_I(0x10) &= ~0x20000;
            EXP0_I(0x10) |= 0x20;
            
            epw->mode1 = 1;            
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne04_MV12(BH_PWORK* epw)
{
    O_WORK* owk;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        epw->mode3++;

    case 1:
        owk = &plp->mlwP->owP[1];
        epw->spd = 0.15f;
        bhAddSpeed(epw, 0);
        epw->ay += ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 256);
        if (EXP0_F(0x20) <= 9.0f)
        {
            bhEne04_ChgMtn(epw, 42, 0, 7);
            EXP0_I(0x10) |= 0x40000000;
            epw->mode3++;
        }
        break;
        
    case 2:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP[1].mtx[12], 256);
        if (epw->flg & 0x2000000)
        {
            EXP0_I(0x10) &= ~0x40000000;
            bhEne04_ChgMtn(epw, 43, 0, 7);
            epw->mode3++;
        } 
        
    case 3:
        break;    
    }
}

// 100% matching!
int bhEne04_Escape(BH_PWORK* epw, int res, int r) {
    ATR_WORK* hp;
    int d_tmp;
    int rot;
    // not present in DWARF
    short temp_v0;
    int var_v0;

    switch (EXP0_I(0x48))
    {                              
    case 0:
        temp_v0 = ikou3(epw,(NJS_POINT3*)&plp->px, r);
        epw->wax = temp_v0;
        if (temp_v0  == 0)
        {
            epw->wax = r;
        }
        EXP0_I(0x10) &= ~0x4000;
        EXP0_I(0x4C) = 0;
        EXP0_I(0x48)++;

    case 1:
        if (EXP0_I(0x3C) != 0)
        {
            EXP0_I(0x48)++;
            d_tmp = epw->wax;
        }
        
        if (8 < EXP0_I(0x4C))
        {
            EXP0_I(0x4C) = 8;
        }
        break;
    case 2:
        if (!((unsigned short)EXP0_S(0x6) & 0xF))
        {
            EXP0_I(0x48)++;
            EXP0_I(0x50) = 0;
            temp_v0 = bhEne_CheckSideWall(epw, 3.0f, 1);
            epw->waz = temp_v0;
            if (temp_v0 == 0)
            {
                epw->waz = -1;
            }
            epw->waz = -epw->waz;
        }
        epw->ay += epw->wax;
        d_tmp = epw->wax;
        if (EXP0_I(0x4C) > 8)
        {
            EXP0_I(0x4C) = 8;
        }
        break;
    case 3:
        if (((bhEne_CheckDirWall(epw, epw->waz * 16384, 3.0f) == NULL) && (EXP0_I(0x50) == 0)) || (((unsigned short)EXP0_S(0x6) & 1) != 0))
        {
            d_tmp = 0;
            EXP0_I(0x48) = 4;
            epw->wax = epw->waz;
            EXP0_I(0x50) = 0x4000;
        } 
        else
        {
            d_tmp = 0;
            EXP0_I(0x50) -= ((EXP0_I(0x50) > 0));
        }
        break;
    case 4:
        epw->ay += epw->wax * r;
        EXP0_I(0x50) = EXP0_I(0x50) - r;
        if (EXP0_I(0x50) <= 0)
        {
            EXP0_I(0x48) = 3;
            EXP0_I(0x50) = 4;
        }
        d_tmp = epw->wax;
        break;    
    }
    
    rot = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
    if ((bhEne_CheckDirWall(epw, rot, 4.0f) == NULL) && (12 < EXP0_I(0x4C)))
    {
        epw->waz = 0;
        EXP0_I(0x10) |= 0x4000;
    }
    
    if (res < ++EXP0_I(0x4C))
    {
        EXP0_I(0x48) = 0;
    }
    
    
    return ((d_tmp != 0) ? ((d_tmp > 0) ? 1 : -1) : 0) + 1;
}

// 100% matching!
void bhEne04_NGType00(BH_PWORK* epw)
{
    if (epw->mode3 == 0)
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0)
        {
            EXP0_I(0x10) |= 0x200;
        } 
        else
        {
            EXP0_I(0x10) &= ~0x200;
        }
    }
    bhEne04_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_NG00(BH_PWORK* epw)
{
    O_WORK* owk;
	NJS_POINT3 pos;

    switch (epw->mode3)
    {        
    case 0:
        bhEne04_ChgMtn(epw, 17, 0, 5);
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        epw->flg &= ~0x40;
        
        EXP0_I(0x10) |= 0x40000;
        EXP0_I(0x10) |= 0x80000;
        
        plp->mode0 = 4;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        
        epw->ct0 = 60;
        
        epw->mode3++;
        
    case 1:
        if ((epw->frm_no / 65536) == 12)
        {
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = -1.0f;
            njCalcPoint(&epw->mlwP->owP[5].mtx, &pos, (NJS_POINT3*)&plp->dpx);
            
            plp->djnt_no = 12;
            
            bhEne_SetBlood(plp, 1, NULL);
            
            bhEne04_SePlay(epw, 16847622);
        }
        
        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 18, 0, 0);
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == 1)
        {
            plp->hp -= 8;
            if (plp->hp < 0)
            {
                plp->hp = 0;
            }
        }
        
        epw->ct0 -= bhEne_LeverCheck() + 1;
        
        if ((epw->ct0 < 0) && (epw->flg & 0x2000000))
        {
            bhEne04_ChgMtn(epw, 19, 0, 0);
            
            epw->mode3++;
            plp->mode3++;
            
            epw->flg |= 0x20;
            
        }
        break;
    case 3:
        if (epw->flg & 0x2000000)
        {
            njUnitMatrix(NULL);
            njTranslate(NULL, epw->px, epw->py, epw->pz);
            njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
            
            pos.x = 1.633476f;
            pos.z = -1.806519f;
            pos.y = 0.0f;
            njCalcPoint(NULL, &pos, (NJS_POINT3*)&epw->px);
            
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            
            EXP0_I(0x10) &= ~0x80000;
            
            bhEne04_ChgMtn(epw, 14, 0, 0);
            
            epw->mode3++;
            
        }
        break;
    case 4:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg |= 0x40;
            
            epw->mtn_add = 0;
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_NG01(BH_PWORK* epw)
{
    O_WORK* owk;

    switch (epw->mode3)
    {
    case 0:
        epw->py = rom->grand[epw->flr_no + 2];
        
        bhEne04_ChgMtn(epw, 16, 0, 5);
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        epw->flg &= ~0x40;
        
        EXP0_I(0x10) |= 0x40000;
        EXP0_I(0x10) |= 0x80000;
        EXP0_I(0x10) &= ~0xF;
        EXP0_I(0x10) |= 2;

        plp->mode0 = 6;
        plp->mode1 = 1;
        plp->mode2 = 0;
        plp->mode3 = 0;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x02000000)
        {
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            
            bhEne04_ChgMtn(epw, 25, 0, 0);
            
            EXP0_I(0x10) &= ~0x40C0000;
            
            epw->flg |= 0x20;
            
            epw->mode3++;
        }

    case 2:
        break;
    }
}

// 100% matching!
void bhEne04_DGType00(BH_PWORK* epw)
{
    bhEne04_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_DG00(BH_PWORK* epw) {
    int h_cnt;
	int mtn_no;

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 0;
        bhClrUseKaidanFlag(epw);

        if (EXP0_I(0x10) & 0x400)
        {
            epw->flg &= ~0x100;
            EXP0_I(0x10) &= ~0x8400;
            epw->py += 3.8f;
            EXP0_F(0x48) = 1.0f;
            bhEne04_ChgMtn(epw, 12, 0, 5);
        }
        else if (EXP0_I(0x10) & 0x8000)
        {
            if (EXP0_I(0x10) & 0x100)
            {
                epw->spd = 0.0f;
                epw->way = -28672;
                mtn_no = 45;                
            }
            else
            {
                epw->spd = 0.0f;
                epw->way = 4096;                
                mtn_no = 44;
            }
            
            epw->mode3 = 2;

            bhEne04_ChgMtn(epw, mtn_no, 0, 5);
            EXP0_I(0x10) |= 0x40000000;
            return;
        }
        else
        {
            if (EXP0_I(0x10) & 0x100)
            {
                epw->spd = 0.0f;
                epw->way = -28672;
                mtn_no = 10;
            }
            else
            {
                epw->spd = 0.0f;
                epw->way = 4096;
                mtn_no = 11;
            }

            bhEne04_ChgMtn(epw, mtn_no, 0, 5);
            EXP0_I(0x10) &= ~0x40000000;

        }
        epw->mode3++;

    case 1:        
        if (epw->mtn_no == 12)
        {
            epw->py += (fabsf(EXP0_F(0x48)) * njSin(8192)) - 0.2f * epw->ct0;
            
            if (rom->grand[epw->flr_no + 2] > epw->py)
            {
                epw->py = rom->grand[epw->flr_no + 2];
            } 
            else
            {
                float tmp = njCos(8192); // cant find a way to match it without a variable
                epw->spd = EXP0_F(0x48) * tmp;
                bhAddSpeed(epw, 32768);
            }
            
            epw->ct0++;
        } 
        else
        {
            if (3 < (epw->frm_no / 65536))
            {
                epw->spd += (0.25f - (0.05f * epw->ct0));
                
                if (epw->spd < 0.0f)
                {
                    epw->spd = 0.0f;
                }
                
                bhAddSpeed(epw, epw->way);
                epw->ct0++;
            }
        }

        if ((epw->flg & 0x2000000) != 0)
        {
            epw->flg |= 0x100;
            h_cnt = 0;
            
            if (epw->mtn_no == 11)
            {
                epw->ay += 32768;
            } 
            else if(epw->mtn_no == 12)
            {
                h_cnt = 5; 
            }
            
            bhEne04_ChgMtn(epw, 14, 0, h_cnt);
            epw->py = rom->grand[epw->flr_no + 2];
            epw->mode3++;
        }
        break;

    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {            
            epw->mtn_add = 0;
            
            if (epw->hp < 0)
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                break;
            }
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_DG01(BH_PWORK* epw)
{
	NJS_POINT3 p1;
	NJS_POINT3 p2;   
    float dist;
    float px;
	float pz;

    switch (epw->mode3)
    {
    case 0:
        bhClrUseKaidanFlag(epw);
        
        EXP0_I(0x10) &= ~0x40000000;
        EXP0_I(0x10) &= ~0x20000;
        EXP0_I(0x10) &= ~0x20;
        
        epw->flg2 |= 1;
        epw->ay = kaidan_ang[*(unsigned char*)((char*)EXP0_I(0x40) + 0x21)];
        epw->py = 3.8f + epw->mlwP->owP->mtx[13];
        
        if (EXP0_I(0x10) & 0x10000)
        {
            bhEne04_ChgMtn(epw, 12, 0, 5);
            px = epw->px - EXP0_F(0x30);
            pz = epw->pz - EXP0_F(0x38);
        } 
        else
        {
            epw->flr_no = bhCheckFloorNum(epw->yn);
            bhEne04_ChgMtn(epw, 39, 0, 5);
            
            njUnitMatrix(NULL);
            njTranslate(NULL, EXP0_F(0x30), EXP0_F(0x34), EXP0_F(0x38));
            njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
            
            p1.x = 0.0f;
            p1.y = -8.027999f;
            p1.z = -22.000042f;
            njCalcPoint(NULL, &p1, &p2);
            
            px = p2.x - epw->px;
            pz = p2.z - epw->pz;
        }
        
        dist = njSqrt((px * px) + (pz * pz));
        EXP0_F(0x48) = dist * 0.033333335f + 1.0f;
        
        epw->flg &= ~0x100;
        epw->ct0 = 0;
        epw->mode3++;

    case 1:
        epw->py += (fabsf(EXP0_F(0x48)) * njSin(8192)) - 0.2f * epw->ct0;
        if (rom->grand[epw->flr_no + 2] > epw->py)
        {
            epw->py = rom->grand[epw->flr_no + 2];
        } 
        else
        {
            dist = njCos(8192);
            epw->spd = EXP0_F(0x48) * dist;
            if (EXP0_I(0x10) & 0x10000)
            {
                bhAddSpeed(epw, 32768);
            } 
            else
            {
                bhAddSpeed(epw, 0);
            }
        }
        
        epw->ct0++;
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
        }
        
        if ((epw->mtn_add == 0) && (epw->py == 0.0f))
        {
            epw->flg |= 0x100;
            if (!(EXP0_I(0x10) & 0x10000))
            {
                epw->ay += 32768;
            }
            bhEne04_ChgMtn(epw, 14, 0, 0);
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            epw->flg2 &= ~1;
            EXP0_I(0x10) &= ~0x30;
            
            if (epw->hp < 0)
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                break;
            }
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_DDType00(BH_PWORK* epw)
{
    bhEne04_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_DD00(BH_PWORK* epw)
 {
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 2;
        
        epw->flg &= ~0x28;
        
        bhSetBloodPoolLnk(epw, (NJS_POINT3*)&epw->px, epw->ay, &en04_BldTbl, 0);
        
        epw->mode3++;
        
    case 1:
        break;
    }
}

// 100% matching!
void bhEne04_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{

    static NJS_POINT3 ply_ofs_pos[4] =
    {
        { -0.937615f,  0.0f,  -9.776372f }, 
        { -0.112207f,  0.0f, -10.525611f }, 
        { -0.937615f,  0.0f,  -9.776372f }, 
        { -0.112207f,  0.0f, -10.525611f }
    }; // @ 0x0030F990

    NJS_CNK_OBJECT* obj;
	O_WORK* owk;

    switch (pl->mode3)
    {
    case 0:
        pl->mnwP = epw->mnwP;
        pl->frm_no = 0;
        pl->hokan_count = 5;
        pl->mtn_add = 65536;
        pl->mtn_md = 0;
        pl->flg &= ~0x40000;
        
        pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id];
        EXP0_F(0x30) = ply_ofs_pos[sys->ply_id].x;
        EXP0_F(0x34) = ply_ofs_pos[sys->ply_id].y;
        EXP0_F(0x38) = ply_ofs_pos[sys->ply_id].z;
        
        epw->waxp = -32768;
        pl->mode3++;
        break;
    case 1:
        if ((pl->frm_no / 65536) == 12)
        {
            bhEne_PlayerSePlay(epw, 1026);
        }
        if ((pl->frm_no / 65536) == 0)
        {
            pl->frm_no = 0;
            pl->hokan_count = 0;
            pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 1;
            pl->mode3++;            
        }

    case 2:
        break;
    case 3:
        pl->frm_no = 0;
        pl->hokan_count = 0;
        pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 2;
        pl->mode3++;
        break;
    case 4:
        if ((pl->frm_no / 65536) == 0)
        {
            owk = pl->mlwP->owP;
            pl->px = owk->mtx[12];
            pl->pz = owk->mtx[14];
            PEXP0_F(0x48) = pl->px;
            PEXP0_F(0x50) = pl->pz;
            obj = pl->mlwP->objP;
            obj->pos[2] = 0.0f;
            obj->pos[0] = 0.0f;
            pl->mnwP = pl->mnwPb;
            pl->frm_no = 0;
            pl->mtn_no = 42;
            pl->hokan_rate = 58982;
            pl->hokan_count = 1;
            pl->mtn_add = 0;
            pl->mode3++;
        }
        break;
    case 5:
        if (plp->hokan_count == 0)
        {
            sys->pad_on &= ~0xF;
            
            pl->flg &= ~0x10000;
            pl->stflg &= ~0x10000;
            
            pl->at_flg = 0;
            *(int*)&pl->mode0 = 1;
            
            pl->flg &= ~4;
            EXP0_I(0x10) &= ~0x4040000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
	int frm;

    switch (pl->mode3)
    {
    case 0:
        if (EXP0_I(0x10) & 0x200)
        {
            pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 3;
            
            EXP0_F(0x30) = 0.000104f;
            EXP0_F(0x34) = 0.0f;
            EXP0_F(0x38) = -5.032532f;
            
            epw->waxp = -32768;
        }
        else
        {
            pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 4;
            
            EXP0_F(0x30) = -0.785082;
            EXP0_F(0x34) = 0;
            EXP0_F(0x38) = -4.901211;
            
            epw->waxp = 0;
        }
        EXP1_I(0) |= 0x1E0;      
        EXP1_I(0) &= ~4;
        
        pl->stflg |= 0x40000;
        pl->hp = -1;
        
        pl->flg &= ~0x40000;
        
        pl->mnwP = epw->mnwP;
        
        pl->frm_no = 0;
        
        pl->hokan_count = 5;
        
        pl->mtn_add = 0x10000;
        pl->mtn_md = 0;
        
        pl->mode3++;
        
        break;
        
    case 1:
        frm = pl->frm_no / 65536;
        if (frm == 3)
        {
            bhEne_PlayerSePlay(epw, 1025);
        }
        
        if ((EXP0_I(0x10) & 0x200))
        {
            if ((frm == 20) || (frm == 29))
            {
                bhEne04_SePlay(epw, 70408);
            }
        } 
        else if ((frm == 9) || (frm == 15) || (frm == 22))
        {
            bhEne04_SePlay(epw, 70408);
        }
        
        if ((pl->frm_no / 65536) == (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            pl->mtn_add = 0;
            
            pl->flg &= ~8;
            pl->flg |= 2;
        }
        
    case 2:
        break;
    }
}

// 100% matching!
int bhEne04_PlyDamageCheck(BH_PWORK* epw, int type)
{
	int rot;
	int hit;
	NJS_SPHERE at;
    
    hit = 0;
    
    if ((plp->flg & 4) || (plp->flg & 2) || (plp->stflg & 0x80000000))
    {
        return 0;
    }
    
    bhEne_CalcPartsPos(epw, lcmat, &at.c, en04_tree[0], 6, 1);
    
    at.r = 1.2f;
    
    if (npCollisionCheckSC(&at, &plp->watr) == 0)
    {
        return 0;
    }
    
    if (bhCdirCheck(plp->ay, epw->ay) == 0)
    {
        hit = 1;
    }
    
    if ((type == 1) && (plp->hp < 12))
    {
        return 2;
    }
    {
    NJS_POINT3 pos = {0.0f, 0.0f, 0.0f};

    bhEne_HitCheckParts(plp, &at.c);
    
    if (hit == 1)
    {
        rot = plp->ay;
        pos.z = -1.5f;
    } 
    else
    {
        rot = plp->ay + 32768;
        pos.z = 1.5f;
    }
    
    bhEne_SetBlood2(plp, 6, &pos, rot);
    }
    bhEne_SetVibration(1);
    plp->flg |= 4;
    
    plp->mode0 = 2;
    plp->mode2 = 1;
    plp->mode3 = 0;
    
    if (hit != 0)
    {
        plp->mode1 = 0;
    } 
    else
    {
        plp->mode1 = 1;
    }
    
    return 1;
}

// 100% matching!
void bhEne04_SpeedUp(float* spd, float g, float limit)
{
    if (*spd < limit)
    {
        *spd += g;       
        if (*spd > limit)
        {
            *spd = limit;
        }
    }
}

// 100% matching!
void bhEne04_SpeedDown(float* spd, float g, float limit)
{
    if (*spd > limit)
    {
        *spd -= g;       
        if (*spd < limit)
        {
            *spd = limit;
        }
    }
}

// 100% matching!
void bhEne04_RunMotion(BH_PWORK* epw, int rot)
{    
    int mtn_tbl[3] = { 3, 1, 2 };     
    int mtn_tbl2[3] = { 41, 34, 40 }; 
	int no;                          
    int idx;                          // not from DWARF

    if (EXP0_I(0x10) & 0x8000)
    {        
        if (rot != 0)
        {
            idx = (rot > 0) ? 0 : 2;
        }
        else
        {
            idx = 1;
        }
        no = mtn_tbl2[idx];
    }
    else
    {
        if (rot != 0) 
        {
            idx = (rot > 0) ? 0 : 2;
        }
        else
        {
            idx = 1;
        }
        no = mtn_tbl[idx];
    }

    if (epw->mtn_no != no)
    {
        epw->mtn_no = no;

        if (epw->hokan_count < 8)
        {
            epw->hokan_count = 7;
            epw->hokan_rate = 0;
            epw->mtn_md = 32;
        }
    }
}

// 100% matching!
int bhEne04_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate)
{
    epw->mtn_add = 65536; 
    if (epw->mtn_no != no)
    {
        epw->mtn_no = no;
        epw->frm_no = frm;            
        epw->hokan_count = rate;
        epw->hokan_rate = 32768;            
        epw->mtn_md = 0;    
        epw->flg &= ~0x40000;
        epw->flg &= ~0x2000000;         
        return 0;
    }

    return -1;
}

// 99.96% matching!
int bhEne04_SetMtn(BH_PWORK* epw)
{
	NJS_CNK_OBJECT* obj;
	int ret;
    int frm;
	NJS_POINT3 pos;
    
    frm = epw->frm_no / 65536;
    ret = bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    if (EXP0_I(0x10) & 0x40000000)
    {
        obj = epw->mlwP->objP;
        
        obj->pos[0] = obj->pos[2] = 0.0f;
        bhEne_GetTranslateMtn(epw, frm, 0);
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
        if (((epw->mtn_no == 16) && (frm == 5 || frm == 70)) ||
            ((epw->mtn_no == 25) && (frm == 4 || frm == 22 || frm == 33)) ||
            ((epw->mtn_no == 43) && (frm == 4 || frm == 26 || frm == 37)))
        {
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = -1.0f;
            
            epw->djnt_no = 5;
        
            bhEne_SetBlood2(epw, 1, &pos, 0);
            bhEne_SetBlood2(epw, 4, &pos, epw->ay + 32768);
        }

        if (epw->mtn_no == 4)
        {
    
            if (frm >= 11) {
                epw->mlwP->objP->pos[1] = 0.0f;
                epw->flg &= ~0x100;
            }
    
        } 
        else if (epw->mtn_no == 5)
        {    
            epw->mlwP->objP->pos[1] = 0.0f;    
        } 
        else if (epw->mtn_no == 6)
        {
            if (frm < 10)
            {
                epw->mlwP->objP->pos[1] = 0.0f;
                epw->flg &= ~0x100;
            } 
            else 
            {
                epw->flg |= 0x100;
            }    
        }
        else if (epw->mtn_no == 8)
        {
            obj = epw->mlwP->objP;
            obj->pos[0] = obj->pos[2] = 0.0f;
    
            if (frm < 18)
            {
                obj->pos[1] = 0.0f;
                epw->flg &= ~0x100;
            } 
            else
            {
                epw->flg |= 0x100;
            }
    
        } 
        else if (epw->mtn_no == 9)
        {
            obj = epw->mlwP->objP;
            obj->pos[0] = obj->pos[2] = 0.0f;
    
            if (frm < 25)
            {
                obj->pos[1] = 0.0f;
                epw->flg &= ~0x100;
            } 
            else
            {
                epw->flg |= 0x100;
            }
    
        } 
        else if ((epw->mtn_no - 10) < 2)
        {
            obj = epw->mlwP->objP;
            obj->pos[0] = obj->pos[2] = 0.0f;
    
        } 
        else if (epw->mtn_no == 20)
        {
            obj = epw->mlwP->objP;
            obj->pos[0] = obj->pos[2] = 0.0f;
    
            if (frm < 17)
            {
                obj->pos[1] = 0.0f;
                epw->flg &= ~0x100;
            }
            else
            {
                epw->flg |= 0x100;
            }
    
        } 
        else if (epw->mtn_no == 12)
        {
    
            epw->mlwP->objP->pos[1] = -3.880015f;
    
        } 
        else if (epw->mtn_no == 39)
        {
            obj = epw->mlwP->objP;
            obj->pos[0] = obj->pos[1] = obj->pos[2] = 0.0f;
            obj->pos[1] = -3.782267f;
        }
    }
    bhEne04_CheckMtnTbl(epw, frm);
    return ret;
}

// 100% matching!
void bhEne04_CheckMtnTbl(BH_PWORK* epw, int frm)
{
    int i;
    EN04_MTBL* mtbl = en04_mtn_tbl;
    EN04_MTBL* mtbl2 = en04_mtn_tbl2;


    if (sys->rmthp == epw->mnwP) {
        return;
    }

    for (; mtbl->no != -1; mtbl++) {
        if (mtbl->no == epw->mtn_no) {
            for (i = 0; i < 4; i++) {
                if (mtbl->atb[i].frm == -1) {
                    break;
                }
                if (mtbl->atb[i].frm == frm) {
                    bhEne04_SePlay(epw, mtbl->atb[i].act);
                }
            }
        }
    }

    if (epw->mode0 < 5) {
        for (; mtbl2->no != -1; mtbl2++) {
            if (mtbl2->no == epw->mtn_no) {
                for (i = 0; i < 4; i++) {
                    if (mtbl2->atb[i].frm == -1) {
                        break;
                    }
                    if (mtbl2->atb[i].frm == frm) {
                        bhEne_SetVibration(mtbl2->atb[i].act);
                    }
                }
            }
        }
    }
}

// 100% matching!
int bhEne04_KaidanCheck(BH_PWORK* epw)
{
    ATR_WORK* hp;
    BH_PWORK* ep;
    int i;
	int idx;
    
    ep = ene;
    if (plp->stflg & 0x80000000)
    {
        return 0;
    }
   
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (ep->id == 4 &&
            (ep->flg & 1) &&
            !(ep->flg & 2) &&
            ep->exp0 != NULL &&
            ep != epw &&
            (EP_EXP0_I(0x10) & 0x20000))
        {
            return 0;
        }
    }

    hp = bhKaidanAtrCheck(epw, 7.0f, &idx);

    if (hp != NULL) 
    {
        if (hp->prm2 != 4)
        {
            return 0;
        }
        if (hp->prm0 == 0)
        {
            if (plp->flr_no > epw->flr_no)
            {
                EXP0_I(0x40) = (int)hp;
                bhSetUseKaidanFlag(epw, hp, idx);
                return 1;
            }
        } 
        else if (plp->flr_no < epw->flr_no)
        {
            EXP0_I(0x40) = (int)hp;
            bhSetUseKaidanFlag(epw, hp, idx);
            return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne04_ShakeWire(O_WRK* obwp)
{
    NJS_POINT3 pos[10] =
    {
        { 0.0f,   0.1f,   0.05f },
        { 0.0f,  -0.1f,   0.1f  },
        { 0.0f,   0.1f,   0.35f },
        { 0.0f,  -0.1f,   0.0f  },
        { 0.0f,   0.1f,   0.0f  },   
        { 0.0f,  -0.1f,  -0.2f  },   
        { 0.0f,   0.1f,  -0.15f }, 
        { 0.0f,  -0.1f,  -0.1f  },
        { 0.0f,   0.1f,  -0.05f },
        { 0.0f,  -0.1f,   0.0f  }
    };
    
    switch (obwp->mode3)
    {
    case 0:
        obwp->ct0 = 0;
        obwp->mode1 = 1;
        obwp->mode3++;
    case 1:
        obwp->py += pos[obwp->ct0].y;
        
        obwp->px -= pos[obwp->ct0].z * njSin(obwp->ay + obwp->ayp);
        obwp->pz -= pos[obwp->ct0].z * njCos(obwp->ay + obwp->ayp);

        obwp->ct0++;

        if (obwp->ct0 >= 10) {
            obwp->mode3++;
            obwp->flg2 &= ~1;
        }
        break;

    case 2:
        obwp->mode1 = 0;
    }
}

// 100% matching!
void bhEne04_RotNeck(BH_PWORK* epw, int rx, int ry, int rz) // signature differs from DWARF
{ 
    NJS_CNK_OBJECT* obj;

    obj = epw->mlwP->objP;
    obj[2].ang[1] = ry;
    obj[3].ang[1] = (ry + (ry / 4));
    obj[4].ang[1] = (ry + (ry / 2));
}

// 100% matching!
int bhEne04_SearchNeck(BH_PWORK* epw)
{
    int rot;
    int rot2;
    int d_tmp;
    int lim;
   
    lim = 0;
    bhEne04_RotNeck(epw, 0, EXP0_I(0x1C), 0); // signature differs from DWARF
    rot = epw->ay + EXP0_I(0x1C);
    d_tmp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
    rot2 = ((d_tmp - rot) + 512) & 0xFFFF;
    
    if (1024 < rot2)
    {
        if (32768 >= rot2)
        {
            EXP0_I(0x1C) += 256;
        }
        else
        {
            EXP0_I(0x1C) -= 256;
        }
    }

    if (EXP0_I(0x1C) < -4096)
    {
        lim = 1;
        EXP0_I(0x1C) = -4096;
    }

    if (4096 < EXP0_I(0x1C))
    {
        EXP0_I(0x1C) = 4096;
        lim = 1;
    }
    return lim;
}

// 100% matching!
void bhEne04_SePlay(BH_PWORK* epw, int no)
{
    if (!(epw->flg & 0x10000))
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&epw->px, no);
    }
}
