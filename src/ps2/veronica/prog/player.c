#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/cut.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/objitm.h"
#include "../../../ps2/veronica/prog/playpch.h"
#include "../../../ps2/veronica/prog/pl_evt.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/room.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/weapon.h"

ETTY_WORK lkmtab[2] = 
{
    { 129, 1211, 0, 0, 4, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } },
    { 129, 1212, 0, 0, 4, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } }
};
CPCL PlyCapColTab[18] = 
{
    {  1,  2, 10 },  
    {  2,  3,  9 },  
    {  3,  3, 12 },  
    {  0, 15,  0 },  
    {  4,  5,  4 },  
    {  5,  5,  9 },  
    {  0,  9,  0 },  
    {  7,  8,  4 },  
    {  8,  9,  3 },  
    { 11, 12,  4 },  
    { 12, 13,  3 },  
    { 14, 15,  8 },  
    { 15, 16,  6 },  
    { 16, 17,  4 },  
    { 18, 19,  8 },  
    { 19, 20,  6 },  
    { 20, 21,  4 },  
    {  0,  0,  0 } 
};
EF_WORK WpnEffTab[23][4]; // DATA
char PlyTrsZ[6][3] = 
{
    { 0,   1, 2  },
    { 6,   7, 8  },
    { 10, 10, 10 },
    { 3,   4, 5  },
    { 9,   9, 9  },
    { 0,   0, 0  }
};
void (*bhCtrPly_mode0[9])() = 
{
    bhSetPlayer,
    bhCPM0_action,
    bhCPM0_damage,
    bhCPM0_die,
    bhCPM0_nage,
    bhCPM0_enedam,
    bhCPM0_enedie,
    bhCPM0_event,
    bhCPM0_nothing
}; 

const float PlyInfo[4][2] = 
{
    { 3.5f, 16.5f },
    { 3.5f, 17.5f },
    { 3.5f, 17.5f },
    { 3.5f, 17.5f }
};
const char PlyEyeTab[8] = 
{
    0, 0, 1, 1, 2, 2, 1, 0
};
const int KnfAtrTab[4] = 
{
    6, 4, 4, 4
}; 
const char PlyLegRoute[2][7] = 
{
    { 0, 1, 14, 15, 16, 17, -1 },
    { 0, 1, 18, 19, 20, 21, -1 }
};
const char PlyFlip[23] = 
{
    0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 6, 7, 8, 9, 18, 19, 20, 21, 14, 15, 16, 17, -1
};
const unsigned short PlMtnAct[2][3][7] = 
{
    {
        { 42, 39, 0, 4, 16, 52, 9 },  
        { 43, 40, 2, 7, 18, 52, 9 },  
        { 44, 41, 3, 8, 19, 52, 9 }  
    },
    {
        { 42, 39, 1, 6, 17, 54, 9 },  
        { 43, 40, 2, 7, 18, 54, 9 },  
        { 44, 41, 3, 8, 19, 54, 9 }  
    }
};
const unsigned short PlMtnWpn[5] = 
{
    100,
    104,
    109,
    114,
    101
}; 
const char PlFootSnd[4][2][7] = 
{
    {
        { 10,  8, 10, 10,  0, 21, 20 }, 
        { 28, 18, 28, 30, 16,  8,  8 }
    },
    {
        { 10,  8, 10, 10,  0, 21, 20 }, 
        { 28, 18, 28, 30, 16,  8,  8 }
    },
    {
        { 10,  8, 10, 10,  0, 21, 20 }, 
        { 28, 18, 28, 30, 16,  8,  8 }
    },
    {
        { 10,  8, 10, 10,  0, 21, 20 }, 
        { 28, 18, 28, 30, 16,  8,  8 }
    }
};
const char PlKDU[3][2][4] =
{
    { 
        { 19,  6, 15, 19 }, 
        {  6, 15, 21, 10 } 
    },
    {
        { 15, 24, 18, 15 }, 
        { 21, 10, 15, 21 }
    },
    {
        { 14, 15, 21, 10 }, 
        { 15, 24, 18, 15 }
    }
};
const WPN_TAB WpnTab[23] = 
{
    { 
        0, 1, 1, 0,
        1, 0, 0, 0,
        0.0f, 0.0f, 0.0f, 0.0f,
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 0.0f,
        -1, 0,
        0, 0,
        0, 0,
        0, 0 
    },
    { 
        0, 1, 1, 0,
        1, 0, 0, 0,
        0.0f, 0.0f, 0.0f, 0.0f,
        { 1.01f, 0.0f, -0.67f },
        {  0.0f, 0.0f, 0.0f   },
        {  0.0f, 0.0f, 0.0f   },
        100, 128, 128, 128,
        5, 20,
        0.6f, 0.0f,
        19, 0,
        0, 0,
        0, 0,
        0, 0 
    },
    { 
        1140850944, 1, 1, 4,
        13, 0, 0, 0,
        1.0f, 0.0f, 0.0f, 0.0f,
        { 2.7f, 0.0f, -1.8f },
        { 0.0f, 0.0f, 0.0f  },
        { 0.0f, 0.0f, 0.0f  },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.0f,
        12, 4,
        0, 0,
        -1, 0,
        0, 0 
    },
    { 
        268451974, 1, 1, 2,
        1, 4, 15, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 2.45f, 0.0f, -0.65f },
        { 2.45f, 0.0f, -0.65f },
        {  0.7f, 0.0f, -1.0f  },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.0f,
        0, 4,
        261, 0,
        0, 0,
        0, 0 
    },
    { 
        268451974, 1, 1, 2,
        1, 4, 15, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 2.95f, 0.0f, -0.81f },
        { 2.95f, 0.0f, -0.81f },
        { 1.29f, 0.0f, -0.81f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.25f,
        1, 4,
        261, 0,
        0, 0,
        0, 0 
    },
    { 
        268452550, 1, 2, 2,
        1, 4, 15, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 3.17f, 0.0f, -0.81f },
        { 3.17f, 0.0f, -0.81f },
        { 1.29f, 0.0f, -0.81f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.25f,
        3, 4,
        261, 0,
        0, 1,
        0, 0 
    },
    { 
        2415935508, 1, 1, 2,
        1, 5, 24, 34,
        2.0f, 200.0f, 0.2f, 1.0f,
        { 3.02f,  0.0f, -0.86f },
        { 3.02f,  0.0f, -0.86f },
        {  1.0f, -0.2f, -0.5f  },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.5f,
        4, 6,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        268453892, 1, 1, 2,
        1, 4, 15, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 2.67f, 0.0f, -0.64f },
        { 2.67f, 0.0f, -0.64f },
        { 1.42f, 0.0f, -0.72f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.0f,
        2, 4,
        261, 0,
        0, 0,
        0, 0 
    },
    { 
        268453956, 1, 2, 1,
        1, 0, 0, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 2.69f,  0.0f, -0.84f },
        {  3.5f,  0.0f, -0.84f },
        { 1.13f, 0.14f, -0.95f },
        100, 128, 128, 128,
        5, 20,
        0.75f, 1.5f,
        16, 5,
        261, 0,
        1, 3,
        0, 0 
    },
    { 
        268453892, 1, 1, 2,
        1, 4, 15, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 3.01f,  0.0f, -0.65f },
        { 3.01f,  0.0f, -0.65f },
        { 1.18f, 0.12f, -0.65f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.0f,
        0, 4,
        261, 0,
        0, 0,
        0, 0 
    },
    { 
        536879368, 1, 1, 1,
        1, 4, 0, 0,
        0.1f, 6.0f, 0.0f, 0.0f,
        { 1.0f, 0.0f, -1.0f },
        { 0.0f, 0.0f,  0.0f },
        { 0.0f, 0.0f,  0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.0f,
        11, 0,
        271, 0,
        0, 0,
        0, 0 
    },
    { 
        2608861188, 1, 1, 2,
        21, 20, 13, 0,
        2.0f, 200.0f, 0.3f, 40.0f,
        { 6.9f,   0.0f, -0.88f },
        { 6.85f,  0.0f, -0.88f },
        { 2.45f, 0.08f, -1.0f  },
        100, 160, 160, 128,
        5, 30,
        0.6f, 0.0f,
        6, 0,
        261, 265,
        2, 0,
        0, 0 
    },
    { 
        268435652, 1, 3, 1,
        1, 6, 29, 0,
        2.0f, 200.0f, 0.4f, 4.0f,
        { 6.49f, 0.0f,  -0.88f },
        { 7.38f, 0.0f,  -0.88f },
        { 2.67f, 0.12f, -1.04f },
        100, 128, 128, 128,
        5, 20,
        0.75f, 1.5f,
        7, 5,
        261, 0,
        1, 2,
        0, 0 
    },
    { 
        268435628, 1, 1, 1,
        1, 0, 4, 0,
        0.1f, 1000.0f, 0.0f, 0.0f,
        { 6.15f, 0.0f, -6.16f },
        { 6.15f, 0.0f, -6.16f },
        { 1.76f, 0.0f, -1.77f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.8f,
        13, 5,
        261, 0,
        1, 0,
        0, 0 
    },
    { 
        536871940, 1, 1, 1,
        1, 6, 31, 0,
        2.0f, 1.0f, 0.0f, 0.0f,
        { 3.53f, 0.0f, -3.69f },
        {  4.0f, 0.0f,  -4.1f },
        {  0.0f, 0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        8, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        536871940, 1, 1, 1,
        1, 6, 31, 0,
        2.0f, 1.0f, 0.0f, 0.0f,
        { 3.53f, 0.0f, -3.69f },
        { 4.0f,  0.0f,  -4.1f },
        { 0.0f,  0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        10, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        536871940, 1, 1, 1,
        1, 6, 31, 0,
        2.0f, 1.0f, 0.0f, 0.0f,
        { 3.53f, 0.0f, -3.69f },
        { 4.0f,  0.0f,  -4.1f },
        { 0.0f,  0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        9, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        536871940, 1, 1, 1,
        1, 6, 31, 0,
        2.0f, 1.0f, 0.0f, 0.0f,
        { 3.53f, 0.0f, -3.69f },
        { 4.0f,  0.0f,  -4.1f },
        { 0.0f,  0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        18, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        536870948, 1, 1, 1,
        1, 0, 0, 0,
        4.0f, 1.0f, 0.0f, 0.0f,
        { 4.26f, 0.0f, -1.21f },
        { 4.26f, 0.0f, -1.21f },
        { 0.0f,  0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        15, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        536879368, 1, 1, 1,
        1, 4, 0, 0,
        0.1f, 6.0f, 0.0f, 0.0f,
        { 1.0f, 0.0f, -1.0f },
        { 0.0f, 0.0f,  0.0f },
        { 0.0f, 0.0f,  0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 3.0f,
        17, 0,
        271, 0,
        0, 0,
        0, 0 
    },
    { 
        595591173, 1, 1, 1,
        1, 0, 0, 0,
        4.0f, 1.0f, 0.0f, 0.0f,
        { 4.9f,  0.0f, -1.06f },
        { -4.0f, 0.0f,  -1.3f },
        { 0.0f,  0.0f,   0.0f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 4.0f,
        14, 0,
        261, 0,
        2, 0,
        0, 0 
    },
    { 
        268435520, 1, 3, 1,
        1, 6, 29, 0,
        3.0f, 200.0f, 0.5f, 5.0f,
        { 0.0f, 2.2f, -11.0f },
        { 0.0f, 2.2f, -13.0f },
        { 1.0f, 1.5f,   1.0f },
        100, 128, 128, 128,
        5, 20,
        0.75f, 1.5f,
        7, 5,
        0, 0,
        -1, 0,
        0, 0 
    },
    { 
        268435460, 1, 1, 1,
        1, 0, 0, 0,
        0.1f, 1000.0f, 0.0f, 0.0f,
        { 8.28f, 1.62f, -2.58f },
        { 8.28f, 1.62f, -2.58f },
        { 2.28f, 0.51f, -1.26f },
        100, 128, 128, 128,
        5, 20,
        0.6f, 1.8f,
        13, 5,
        261, 0,
        -1, 0,
        0, 0 
    }
};
/* unused below */
/*char PlyClipTab[5];
char PlySdwTab[8];*/

// 100% matching! 
void bhInitPlayer()
{
    npSetMemory((unsigned char*)plp, sizeof(BH_PWORK), 0);
    
    sys->plmdlp = bhGetFreeMemory(131072, 32);
    sys->lmmdlp = bhGetFreeMemory(32768, 32);
    sys->wrmdlp = bhGetFreeMemory(32768, 32);
    sys->wlmdlp = bhGetFreeMemory(32768, 32);
    
    sys->plmthp = bhGetFreeMemory(12288, 32);
    
    sys->plbmtp = bhGetFreeMemory(393216, 32);
    sys->plwmtp = bhGetFreeMemory(65536, 32);
    sys->plzmtp = bhGetFreeMemory(8192, 32);
    
    sys->plexwp = bhGetFreeMemory(124, 32);
    sys->plhdwp = bhGetFreeMemory(124, 32);
    
    sys->pletcp = bhGetFreeMemory(32768, 32);
    
    plp->exp0 = sys->plexwp;
    plp->exp1 = sys->plhdwp;
    plp->exp3 = sys->pletcp;
    
    sys->mempb = sys->memp;
    
    if ((sys->ss_flg & 0x200)) 
    {
        plp->stflg = sys->ply_stflg[sys->ply_id] | 0x40000000;
        
        plp->hp = sys->ply_hp[sys->ply_id];
        
        plp->wpnr_no =  sys->ply_wno[sys->ply_id];
        
        sys->cb_flg |= 0x800000;
    }
    else
    {
        plp->stflg = 0x40000000;
        
        if (sys->gm_mode == 2) 
        {
            plp->hp = 320;
        } 
        else 
        {
            plp->hp = 160;
        }
        
        plp->wpnl_no = plp->wpnr_no = 0;
    }
}

// 99.96% matching
void bhSetPlayer()
{
    plp->flg = 0x119;
    
    if (plp->wpnr_no > 1) 
    {
        plp->flg |= 0x20000;
    }
    
    plp->mdflg = 0x20;
    
    plp->id = 0;
    plp->type = 0;
     
    plp->param = 0;
    
    plp->ar = PlyInfo[sys->ply_id][0];
    plp->ah = PlyInfo[sys->ply_id][1];
    
    plp->car = PlyInfo[sys->ply_id][0] - 1.0f;
    plp->cah = PlyInfo[sys->ply_id][1] - 1.0f;
    
    plp->ofx = plp->ofy = plp->ofz = 0;
    plp->lox = plp->loy = plp->loz = 0;
    plp->aox = plp->aoy = plp->aoz = 0;
    
    *(int*)&plp->mode0 = 1;
    
    plp->ct0 = plp->ct1 = plp->ct2 = plp->ct3 = 0;
    
    plp->lkwkp = NULL;
    
    plp->exp0 = sys->plexwp;
    plp->exp1 = sys->plhdwp;
    plp->exp3 = sys->pletcp;
    
    plp->mtx = (float(*)[16])plp->mtxbuf;
    
    plp->frm_no = 0;
    plp->mtn_no = 0;
    plp->mdl_no = 0;
    
    plp->at_flg = 0;
    
    plp->sx = plp->sxb = 1.0f;
    plp->sy = plp->syb = 1.0f;
    plp->sz = plp->szb = 1.0f;
    
    plp->kdnp = NULL;
    
    if (plp->wpnr_no < 10) 
    {
        ((EXP_WORK*)plp->exp0)->wpntp = 0;
    }
    else 
    {
        ((EXP_WORK*)plp->exp0)->wpntp = 1;
    }
    
    plp->clp_jno[0] = 0;
    plp->clp_jno[1] = 5;
    plp->clp_jno[2] = 9;
    plp->clp_jno[3] = 13;
    plp->clp_jno[4] = -1;
    
    plp->cpcl = PlyCapColTab;
    
    switch (sys->ply_id)
    {
    case 0:
        bhSetObject(lkmtab, 2, (unsigned char*)plp);
        
        sys->obwp[2].lkono = 5;
        
        sys->obwp[2].lox   = 0;
        sys->obwp[2].loy   = 1.5869f;
        sys->obwp[2].loz   = 0.7747f;
        
        sys->obwp[2].skp[0] = plp->skp[sys->obwp[2].mdlver];
        sys->obwp[2].mdl[0] = plp->mdl[sys->obwp[2].mdlver];
        
        sys->obwp[2].mlwP = &sys->obwp[2].mdl[0];
        break;
    case 3:
        bhSetObject(&lkmtab[1], 2, (unsigned char*)plp);
        
        sys->obwp[2].lkono = 5;
        
        sys->obwp[2].lox   = 0;
        sys->obwp[2].loy   = 0.85f;
        sys->obwp[2].loz   = -1.03f;
        
        sys->obwp[2].mdl[0] = plp->mdl[sys->obwp[2].mdlver];
        
        sys->obwp[2].mlwP = &sys->obwp[2].mdl[0];
        break;
    }

    ((int*)plp->exp1)[0] = 1;
    
    ((short*)plp->exp1)[34] = -1;
    
    bhSetShadow(NULL, (unsigned char*)plp, 1, 4.5f, 4.0f, 3.5f);
    
    plp->flg |= 0x800;
    
    bhSetFloorNum(plp);
    
    plp->py = rom->grand[plp->flr_no + 2];
    
    if (plp->hp >= 120)
    {
        if ((plp->stflg & 0x280000)) 
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
        else if (((EXP_WORK*)plp->exp0)->dmlvl != 0)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 0;
        }
    }
    else if (plp->hp >= 30) 
    {
        if (((EXP_WORK*)plp->exp0)->dmlvl != 1)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
    }
    else 
    {
        if (((EXP_WORK*)plp->exp0)->dmlvl != 2)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 2;
        }
    }
    
    plp->hokan_count = 0;
    plp->hokan_rate = 0;
    
    plp->frm_mode = 0;
    
    plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
    plp->mtn_add = 65536;
    plp->mtn_md = 0;
    plp->mtn_tp = (unsigned char*)PlyFlip;
    
    (void*)plp->mtn_tp; // FAKE
    bhSetMotion(plp, (int)plp->mtn_add, plp->mtn_md, plp->mtn_tp);
    
    plp->kdnp = NULL;
    
    bhCalcModel(plp);
    
    bhCheckCut(1);
    bhCheckMothEgg();
    bhCheckSubPack();
    
    PlyPchInit(plp);
    
    bhPushGameData();
    
    plp->mlwP->owP[7].flg  |= 0x8;
    plp->mlwP->owP[11].flg |= 0x8;
}

// 100% matching!
void bhInitRoomChangePlayer()
{
    plp = &ply;
    
    plp->flg &= 0x20119;
    plp->flg |= 0x118;
    
    plp->stflg &= 0x78280000;
    
    plp->mdflg = 0x20;
    plp->at_flg = 0;
    
    plp->ar = PlyInfo[sys->ply_id][0];
    plp->ah = PlyInfo[sys->ply_id][1];
    
    plp->car = PlyInfo[sys->ply_id][0] - 1.0f;
    plp->cah = PlyInfo[sys->ply_id][1] - 1.0f;
    
    *(int*)&plp->mode0 = 1;

    ((int*)plp->exp1)[0] = 1;
    ((int*)plp->exp1)[0] &= ~0x2;
    
    ((int*)plp->exp1)[15] = 0;
    ((int*)plp->exp1)[16] = 0;
    
    ((short*)plp->exp1)[34] = -1;
    
    ((int*)plp->exp1)[1] = 0;
    ((int*)plp->exp1)[2] = 0;
    
    ((short*)plp->exp1)[24] = 0;
    ((short*)plp->exp1)[25] = 0;
    ((short*)plp->exp1)[27] = 0;
    ((short*)plp->exp1)[28] = 0;
    
    ((char*)plp->exp1)[120] = 0;
    
    ((int*)plp->exp1)[29] = 0;
    ((int*)plp->exp1)[28] = 0;
    ((int*)plp->exp1)[27] = 0;
    ((int*)plp->exp1)[26] = 0;
    ((int*)plp->exp1)[25] = 0;
    ((int*)plp->exp1)[24] = 0;
    ((int*)plp->exp1)[23] = 0;
    ((int*)plp->exp1)[22] = 0;
    ((int*)plp->exp1)[21] = 0;
    
    plp->mlwP->texP = plp->txp[0];
    
    bhSetShadow(NULL, (unsigned char*)plp, 1, 4.5f, 4.0f, 3.5f);
    
    plp->flg |= 0x800;

    bhCheckFloorP(plp);
    
    ((EXP_WORK*)plp->exp0)->bpx = plp->px;
    ((EXP_WORK*)plp->exp0)->bpy = 12.5f + plp->py;
    ((EXP_WORK*)plp->exp0)->bpz = plp->pz;
    
    plp->hokan_count = 0;
    plp->hokan_rate = 0;
    
    plp->frm_mode = 0;
    plp->frm_no = 0;
    
    plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
    
    plp->mtn_add = 65536;
    plp->mtn_md = 0;
    plp->mtn_tp = (unsigned char*)PlyFlip;
    
    (void*)plp->mtn_tp; // FAKE
    bhSetMotion(plp, (int)plp->mtn_add, plp->mtn_md, plp->mtn_tp); 
    
    plp->kdnp = NULL;
    
    bhCalcModel(plp);
    
    bhCheckMothEgg();
    bhCheckSubPack();
    
    if (sys->ply_id == 0) 
    {
        sys->obwp[2].lkwkp = (unsigned char*)plp;
    }
    
    PlyPchInit(plp);
    
    plp->mlwP->owP[7].flg  |= 0x8;
    plp->mlwP->owP[11].flg |= 0x8;
}

// 100% matching!
void bhResetPlayer()
{
    BH_PWORK* epp;
	int i;

    plp->ar = PlyInfo[sys->ply_id][0]; 
    plp->ah = PlyInfo[sys->ply_id][1];
    
    plp->car = PlyInfo[sys->ply_id][0] - 1.0f;
    plp->cah = PlyInfo[sys->ply_id][1] - 1.0f;
    
    plp->mlwP = plp->mdl;
    
    switch (sys->ply_id)
    {
    case 0:
        bhSetObject(lkmtab, 2, (unsigned char*)plp);
        
        sys->obwp[2].lkono = 5;
        
        sys->obwp[2].lox   = 0;
        sys->obwp[2].loy   = 1.5869f;
        sys->obwp[2].loz   = 0.7747f;
        
        sys->obwp[2].skp[0] = plp->skp[sys->obwp[2].mdlver];
        sys->obwp[2].mdl[0] = plp->mdl[sys->obwp[2].mdlver];
        
        sys->obwp[2].mlwP = &sys->obwp[2].mdl[0];
        break;
    case 3:
        bhSetObject(&lkmtab[1], 2, (unsigned char*)plp);
    
        sys->obwp[2].lkono = 5;
        
        sys->obwp[2].lox   = 0;
        sys->obwp[2].loy   = 0.85f;
        sys->obwp[2].loz   = -1.03f;
        
        sys->obwp[2].mdl[0] = plp->mdl[sys->obwp[2].mdlver];
        
        sys->obwp[2].mlwP = &sys->obwp[2].mdl[0];
        break;
    }
    
    plp->stflg = sys->ply_stflg[sys->ply_id];
    plp->stflg |= 0x40000000;
    
    plp->hp = sys->ply_hp[sys->ply_id];
    
    if (plp->hp >= 120) 
    {
        if ((plp->stflg & 0x280000)) 
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
        else if (((EXP_WORK*)plp->exp0)->dmlvl != 0)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 0;
        } 
    }
    else if (plp->hp >= 30) 
    {
        if (((EXP_WORK*)plp->exp0)->dmlvl != 1)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
    }
    else 
    {
        if (((EXP_WORK*)plp->exp0)->dmlvl != 2)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 2;
        }
    }
    
    epp = ene;
    
    for (i = 0; i < 128; i++, epp++)
    {
        if (((epp->flg & 0x1)) && (epp->id == 27)) 
        {
            epp->flg = 0;
        }
    }
    
    bhCheckMothEgg();
    bhCheckSubPack();
    
    plp->mlwP->owP[7].flg  |= 0x8;
    plp->mlwP->owP[11].flg |= 0x8;
}

// 100% matching! 
void bhCheckMothEgg()
{
    EGG_WORK egg = { 0 };

    if ((plp->stflg & 0x8000000)) 
    {
        egg.type = 0;
        
        bhSetEnemy(&egg, 0);
    }
    
    if ((plp->stflg & 0x10000000)) 
    {
        egg.type = 1;
        
        bhSetEnemy(&egg, 0);
    }
    
    if ((plp->stflg & 0x20000000)) 
    {
        egg.type = 2;
        
        bhSetEnemy(&egg, 0);
    }
}

// 100% matching!
void bhCheckSubPack()
{
    int ply_id;
    
    ply_id = sys->ply_id;
    switch (ply_id) 
    {                         
    case 0:
        if (bhCkFlg(sys->ev_flg, 6) != 0) 
        {
            sys->gm_flg |= 0x8000000;
        } 
        else 
        {
            sys->gm_flg &= ~0x8000000;
        }
        break;
    case 1:
        if (bhCkFlg(sys->ev_flg, 7) != 0) 
        {
            sys->gm_flg |= 0x8000000;
        } 
        else 
        {
            sys->gm_flg &= ~0x8000000;
        }
        break;
    case 2:
        if (bhCkFlg(sys->ev_flg, 8) != 0) 
        {
            sys->gm_flg |= 0x8000000;
        } 
        else 
        {
            sys->gm_flg &= ~0x8000000;
        }
        break;
    }
}

// TODO: find the struct that plp->exp0 gets parsed to 
// 100% matching!
void bhStandPlayerMotion()
{
    if (plp->hp >= 120)
    {
        if ((plp->stflg & 0x280000)) 
        {
            ((int*)plp->exp0)[5] = 1; 
        } 
        else if (((int*)plp->exp0)[5] != 0) 
        {
            ((int*)plp->exp0)[5] = 0; 
        }
    }
    else if (plp->hp >= 30)
    {
        if (((int*)plp->exp0)[5] != 1) 
        {
            ((int*)plp->exp0)[5] = 1; 
        }
    } 
    else if (((int*)plp->exp0)[5] != 2) 
    {
        ((int*)plp->exp0)[5] = 2;
    }
    
    plp->flg &= 0xC96EFFFB;
    
    plp->flg |= 0x8;
    
    plp->stflg &= ~0x18000;
    
    *(int*)&plp->mode0 = 1;
    
    *(float*)&plp->exp0[72] = plp->px;
    *(float*)&plp->exp0[80] = plp->pz;
    
    plp->mtn_no = PlMtnAct[((int*)plp->exp0)[0]][((int*)plp->exp0)[5]][0];
    
    plp->hokan_rate = 0; 
    plp->hokan_count = 0;
    
    plp->frm_no = 0;
    
    plp->mnwP = plp->mnwPb;
    
    bhSetMotion(plp, 0, 0, NULL);
    
    bhCalcModel(plp);
}

// 100% matching!
void bhKaidanPlayerMotion(int flg, int idx)
{
	ATR_WORK* exp;

    exp = &rom->etcp[idx];
    
    bhSetUseKaidanFlag(plp, exp, idx);
    
    plp->stflg |= 0x80010010;
    
    plp->flg |= 0x10400;
    plp->flg &= ~0x110;
    
    plp->flg2 |= 0x1;
    
    sys->pl_htp = exp;
    
    if (flg == 0) 
    {
        plp->mode0 = 1;
        plp->mode1 = 0;
        
        if ((exp->attr & 0x1))
        {
            plp->mode2 = 20;
        }
        else 
        {
            plp->mode2 = 14;
        }
        
        plp->mode3 = 0;
        return;
    }
    
    plp->mode0 = 1;
    plp->mode1 = 0;
    
    if ((exp->attr & 0x1))
    {
        plp->mode2 = 21;
    }
    else 
    {
        plp->mode2 = 15;
    }
    
    plp->mode3 = 0;
    
    plp->flr_no = bhCheckFloorNum(plp->py - (2.0f * exp->prm2));
}

// 
// 100% matching!
void bhFixPositionXYZ(BH_PWORK* ewP, char* datP)
{
    NJS_POINT3 pos;
    bhCalcFixOffset(ewP, datP, NULL, &pos);
    ewP->px -= pos.x;
    ewP->py -= pos.y;
    ewP->pz -= pos.z;
}

// 100% matching!
int bhCheckPlayerKegaMotion(int wpntp, int dmlvl, int num)
{
    if (plp->hp >= 120) 
    {
        if ((plp->stflg & 0x280000)) 
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
        else if (((EXP_WORK*)plp->exp0)->dmlvl != 0) 
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 0;
        }
    }
    else if (plp->hp >= 30) 
    {
        if (((EXP_WORK*)plp->exp0)->dmlvl != 1)
        {
            ((EXP_WORK*)plp->exp0)->dmlvl = 1;
        }
    } 
    else if (((EXP_WORK*)plp->exp0)->dmlvl != 2)
    {
        ((EXP_WORK*)plp->exp0)->dmlvl = 2;
    }
    
    if (((EXP_WORK*)plp->exp0)->dmlvl != dmlvl)
    {
        plp->mtn_no = PlMtnAct[wpntp][((EXP_WORK*)plp->exp0)->dmlvl][num];
        plp->frm_no = bhGetFrameNum(plp->mnwP[PlMtnAct[wpntp][dmlvl][num]].frm_num, plp->mnwP[PlMtnAct[wpntp][((EXP_WORK*)plp->exp0)->dmlvl][num]].frm_num, plp->frm_no);
        
        plp->hokan_count = 3;

        return 1;
    }
    
    return 0;
}

// 100% matching!
void bhCheckEvtTimer()
{
    POINT pnt; 

    if ((sys->evt_tim == 0) && (((sys->sp_flg & 0x200)) && ((sys->gm_flg & 0x20000000)) && (!(sys->ts_flg & 0x80)) && ((sys->ts_flg & 0x4000)) && ((sys->ts_flg & 0x1000)) && ((sys->ts_flg & 0x200)) && ((sys->ts_flg & 0x400)) && ((sys->ts_flg & 0x800)) && ((sys->ts_flg & 0x10000)) && (!(sys->cb_flg & 0x1))))
    {
        if (bhCkFlg(sys->ev_flg, 69) != 0) 
        {
            if ((sys->st_flg & 0x200)) 
            {
                sys->st_flg |= 0x400000;
                
                sys->cb_flg |= 0x2000;
                sys->cb_flg &= ~0x1000;
            }
            
            bhSetEffect(26, &pnt, NULL, 0);
            
            plp->hp = -1;
            
            bhCrFlg(sys->ev_flg, 69);
        }
        
        if (bhCkFlg(sys->ev_flg, 67) != 0) 
        {
            sys->sp_flg = 0;
            sys->sp_flg |= 0x20;
            
            sys->st_flg &= ~0x200;
            
            sys->gm_flg |= 0x400;
            
            sys->ts_flg &= ~0x4000;
            sys->ts_flg |= 0x100;
            
            plp->flg |= 0x10002;
            
            *(int*)&sys->gov_md0 = 0;
            
            bhCrFlg(sys->ev_flg, 67);
        }
        
        if (bhCkFlg(sys->ev_flg, 70) != 0) 
        {
            CallSystemVoice(11);
            
            sys->sp_flg = 0;
            sys->sp_flg |= 0x20;
            
            sys->st_flg &= ~0x200;
            
            sys->gm_flg |= 0x400;
            
            sys->ts_flg &= ~0x4000;
            sys->ts_flg |= 0x100;
            
            plp->flg |= 0x10002;
            
            *(int*)&sys->gov_md0 = 0;
            
            bhCrFlg(sys->ev_flg, 70);
        }
    }
}

#pragma divbyzerocheck on 

// 100% matching!
void bhControlPlayer()
{
    unsigned int stf_bk;
	MN_WORK* mnwP;
    EXP_WORK* expw;
    float px, py, pz;
    int bhit;
    int fsnd;
    O_WORK* owP;
    NJS_POINT3 eff0, eff1;   
    NJS_POINT3 bps; 
    ATR_WORK* hp;
    GA_WORK gap;   

    expw = (EXP_WORK*)plp->exp0;
        
    if (((sys->sp_flg & 0x1)) && (!(plp->stflg & 0x1000000))) 
    {
        plp->pxb = plp->px;
        plp->pyb = plp->py;
        plp->pzb = plp->pz;
        
        expw->bpxb = expw->bpx;
        expw->bpyb = expw->bpy;
        expw->bpzb = expw->bpz;
        
        plp->axb = plp->ax;
        plp->ayb = plp->ay;
        plp->azb = plp->az;
        
        px = plp->mlwP->owP->mtx[12] - ((EXP_WORK*)plp->exp0)->nlxb;
        py = plp->py - ((EXP_WORK*)plp->exp0)->nlyb;
        pz = plp->mlwP->owP->mtx[14] - ((EXP_WORK*)plp->exp0)->nlzb;
        
        if (njSqrt((px * px) + (py * py) + (pz * pz)) > 0.3f) 
        {
            ((EXP_WORK*)plp->exp0)->nlxb = plp->mlwP->owP->mtx[12];
            ((EXP_WORK*)plp->exp0)->nlyb = plp->py;
            ((EXP_WORK*)plp->exp0)->nlzb = plp->mlwP->owP->mtx[14];
        }
        
        plp->stflg &= ~0x300;
        
        if (((plp->stflg & 0x281000)) && (!(plp->stflg & 0x40000))) 
        {
            ((EXP_WORK*)plp->exp0)->dm_ct++;
            
            if (((EXP_WORK*)plp->exp0)->dm_ct > 30) 
            {
                ((EXP_WORK*)plp->exp0)->dm_ct = 0;
                
                if (plp->hp > 0) 
                {
                    plp->hp--;
                }
            }
        }
        
        if (plp->hp < 0) 
        {
            if ((plp->mode0 != 3) && (!(plp->stflg & 0x40000))) 
            {
                *(int*)&plp->mode0 = 3;
                
                plp->mnwP = plp->mnwPb;
            }
        }
        
        bhCtrPly_mode0[plp->mode0]();
        
        if ((plp->flg & 0x100000)) 
        {
            plp->ay += (short)(plp->ayp - plp->ay) / ((EXP_WORK*)plp->exp0)->yrct;
            
            ((EXP_WORK*)plp->exp0)->yrct--;
            
            if (((EXP_WORK*)plp->exp0)->yrct <= 0)
            {
                plp->ay = plp->ayp;
                
                if ((plp->flg & 0x4000000)) 
                {
                    owP = plp->mlwP->owP;
                    
                    CallPlayerFootStepSe(bhCheckFloorSound(plp, plp->flr_no, owP[17].mtx[12], owP[17].mtx[14]), 1, 1);
                    
                    plp->stflg |= 0x200;
                    
                    if ((plp->stflg & 0x100000)) 
                    {
                        bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                        bhSetWaterSplash(plp, 19, 1, 1.6f, 1.6f, 1.6f);
                    }
                    
                    if ((plp->flg2 & 0x8)) 
                    {
                        px = py = pz = 0.8f;
                        
                        bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[21].mtx[12], plp->ay, plp->footeff, px, py, pz);
                    }
                }
                
                plp->flg &= ~0x4100000;
                plp->stflg &= ~0x800;
                
                ((EXP_WORK*)plp->exp0)->spx = plp->px;
                ((EXP_WORK*)plp->exp0)->spz = plp->pz;
            }
        }
        
        if (plp->wpnr_no == 1) 
        {
            if (!(plp->flg & 0x1000000)) 
            {
                plp->flg |= 0x1000000;
                
                bhSetEffectTb(WpnEffTab[plp->wpnr_no], (NJS_POINT3*)&WpnTab[plp->wpnr_no].wp_fps1, (unsigned char*)plp, 9);
                
                lgttab->ct2 = 1;
                lgttab->ct3 = 0;
                
                lgttab->wpx = 1.3e-44f;
                
                bhSetLightTab((LGT_WORK*)&lgttab->mode, 1); // the first parameter is probably a dev mistake
                
                rom->lgtp[1].flg |= 0x2;
            }
            else if (!(rom->lgtp[1].flg & 0x2))
            {
                rom->lgtp[1].flg |= 0x2;
                
                rom->lgtp[1].lkflg = 1;
                
                rom->lgtp[1].lkno = 0;
                rom->lgtp[1].lkono = 9;
            }
            
            plp->mlwP->owP[7].flg |= 0x2;
            plp->mlwP->owP[8].flg |= 0x2;
            plp->mlwP->owP[9].flg |= 0x2;        
        }
        else if ((plp->flg & 0x1000000))
        {
            plp->flg &= ~0x1000000;
            
            rom->lgtp[1].flg &= ~0x2;
        }
        
        PlyPchMain(plp);
        
        mnwP = plp->mnwP;

        (void*)plp->mtn_tp; // FAKE
        bhSetMotion(plp, (int)plp->mtn_add, plp->mtn_md, plp->mtn_tp);
        
        if ((plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            plp->flg |= 0x400000;
        }
        else 
        {
            plp->flg &= ~0x400000;
        }
        
        plp->mnwP = mnwP;
        
        if (plp->wpnr_no == 1) 
        {
            owP = plp->mlwP->owP;
                
            if (sys->ply_id == 0) 
            {
                eff1.x = 1.8f;
                eff1.z = -3.0f;
            }
            else 
            {
                eff1.x = 2.4f;
                eff1.z = -3.5f;
            }
            
            eff1.y = -3.0f;
            
            njCalcPoint(&owP[4].mtx, &eff1, &eff0);
            
            bhArmIkMdk(plp, 6, &eff0, 35498);
            
            plp->mlwP->objP[9].ang[1] = -910;
        }
        
        if ((plp->flg & 0x40000)) 
        {
            if (!(plp->flg & 0x8000000)) 
            {
                if ((plp->flg & 0x80000)) 
                {
                    bhFixPosition(plp, PlyLegRoute[1]);
                }
                else 
                {
                    bhFixPosition(plp, *PlyLegRoute);
                }
            } 
            else if ((plp->flg & 0x80000)) 
            {
                bhFixPositionXYZ(plp, PlyLegRoute[1]);
            }
            else 
            {
                bhFixPositionXYZ(plp, *PlyLegRoute);
            }
        }
        
        if (((plp->flg & 0x20000000)) && (plp->spd > 0)) 
        {
            plp->flg |= 0x200000;
            
            bhAddSpeed(plp, 32768);
            
            plp->spd *= 0.5f;
            
            if (plp->spd < 0.1f) 
            {
                plp->flg &= ~0x20000000;
                
                plp->spd = 0;
            }
        }
        
        if (expw->arn != expw->arp)
        {
            expw->arn += 0.5f * (expw->arp - expw->arn);
        }
        
        njSinCos(plp->ay, &expw->fpx, &expw->fpz);
        
        expw->fpx = plp->px - (expw->fpx * expw->arn);
        expw->fpy = plp->py;
        expw->fpz = plp->pz - (expw->fpz * expw->arn);
        
        expw->bpx = expw->fpx;
        expw->bpy = 12.5f + plp->py;
        expw->bpz = expw->fpz;
        
        if ((plp->flg & 0x8)) 
        {
            bhCheckEnemies(plp);
        }
        
        fsnd = plp->flg;
        
        if ((plp->flg & 0x10))
        {
            stf_bk = plp->stflg;
            
            plp->flg &= ~0x100;
            
            plp->stflg &= ~0x20000;
            plp->stflg &= ~0x1;
            
            bps.x = expw->bpx;
            
            if (plp->mode0 == 3) 
            {
                bps.y = plp->py;
            }
            else 
            {
                bps.y = expw->bpy;
            }
            
            bps.z = expw->bpz;
            
            if (bhCheckWallEx(plp, &bps, (NJS_POINT3*)&expw->bpxb, plp->ar, 1.0f) != 0)
            {
                bhit = 1;
                
                ((EXP_WORK*)plp->exp0)->spx = bps.x;
                ((EXP_WORK*)plp->exp0)->spy = plp->py;
                ((EXP_WORK*)plp->exp0)->spz = bps.z;
            }
            else
            {
                bhit = 0;
            }
            
            plp->px += bps.x - expw->bpx;
            plp->pz += bps.z - expw->bpz;
            
            expw->bpx = bps.x;
            expw->bpy = bps.y;
            expw->bpz = bps.z;
            
            plp->flg = fsnd;
            
            plp->stflg = stf_bk;
            plp->stflg &= ~0x1;
            
            bhCheckWallEx(plp, (NJS_POINT3*)&plp->px, (NJS_POINT3*)&plp->pxb, plp->ar, plp->ah);
            
            if (bhit == 0)
            {
                ((EXP_WORK*)plp->exp0)->spx = expw->bpx;
                ((EXP_WORK*)plp->exp0)->spy = plp->py;
                ((EXP_WORK*)plp->exp0)->spz = expw->bpz;
            }
        }
        
        if ((plp->flg & 0x200000)) 
        {
            expw->plx = expw->spx;
            expw->ply = expw->spy;
            expw->plz = expw->spz;
        }
        
        bhCheckFloorP(plp);
        
        if ((sys->st_flg & 0x100)) 
        {
            plp->mdflg &= ~0x40;
            
            hp = bhCheckFloorEffect(plp->flr_no, plp->gpx, plp->gpz);
            
            if ((hp != NULL) && (hp->prm0 == 2)) 
            {
                plp->mdflg |= 0x40;
            }
        }
        
        if ((plp->mode0 == 1) && (!(plp->stflg & 0x10080)) && (!(plp->flg & 0x4000004)) && (!(sys->cb_flg & 0x4017)) && ((sys->pad_ps & 0x200))) 
        {
            bhCheckExmAtari(plp);
        }
        
        if (plp->exp1 != NULL)
        {
            bhControlPlayerHead();
        }
        
        bhCalcModel(plp);
        
        if (((plp->mode0 == 1) && (plp->mode1 == 1) && (plp->mode2 == 0x45) && (plp->mode3 == 1)) && ((WpnTab[plp->wpnr_no].flg & 0x40000000))) 
        {
            if (((plp->frm_no / 65536) > KnfAtrTab[sys->ply_id]) && ((plp->frm_no / 65536) < WpnTab[plp->wpnr_no].ef_yct)) 
            {
                gap.at_flg = plp->at_flg;
                
                gap.wpn_no = plp->wpnr_no;
                
                gap.r = WpnTab[plp->wpnr_no].r;
                gap.l = 0;
                
                gap.rn = 0;
                gap.rmax = 0;
                
                gap.ax = plp->wax;
                gap.ay = plp->ay;
                
                plp->way = plp->ay;
                plp->waz = 0;
                
                njSetMatrix(NULL, &plp->mlwP->owP[9].mtx);
                njCalcPoint(NULL, (NJS_POINT3*)&WpnTab[plp->wpnr_no].wp_fps1, (NJS_POINT3*)&gap.px);
                
                gap.gx = plp->mlwP->owP[8].mtx[12];
                gap.gy = plp->mlwP->owP[8].mtx[13];
                gap.gz = plp->mlwP->owP[8].mtx[14];
                
                gap.vx = gap.px - gap.gx;
                gap.vy = gap.py - gap.gy;
                gap.vz = gap.pz - gap.gz;
                
                bhCheckKnifeAtari(&gap);
                
                if ((plp->frm_no / 65536) == (KnfAtrTab[sys->ply_id] + 1)) 
                {
                    CallPlayerWeaponSeEx((NJS_POINT3*)&gap.px, 276, 0);
                }
            }
        }
        
        if ((plp->flg & 0x4)) 
        {
            sys->st_flg |= 0x4;
        }
        
        plp->flg2 &= ~0x200;
        
        if ((!(plp->stflg & 0x10)) && (plp->kdnp != NULL)) 
        {
            bhClrUseKaidanFlag(plp);
            
            plp->kdnp = NULL;
        }
        
        if (((plp->stflg & 0x30)) || (plp->mode0 == 7)) 
        {
            plp->gpx = plp->mlwP->owP->mtx[12];
            plp->gpz = plp->mlwP->owP->mtx[14];
        }
        else 
        {
            plp->gpx = plp->px;
            plp->gpz = plp->pz;
        }
        
        plp->gpy = plp->mlwP->owP[1].mtx[13];
        plp->gpy = bhGetGroundPosition((NJS_VECTOR*)&plp->gpx);
        
        plp->watr.c1.x = plp->mlwP->owP[4].mtx[12];
        plp->watr.c1.y = plp->mlwP->owP[4].mtx[13];
        plp->watr.c1.z = plp->mlwP->owP[4].mtx[14];
        
        plp->watr.c2.x = plp->mlwP->owP->mtx[12];
        plp->watr.c2.y = plp->mlwP->owP->mtx[13];
        plp->watr.c2.z = plp->mlwP->owP->mtx[14];
        
        plp->watr.r = 2.5f;
    }
    else if ((((plp->stflg & 0x1000000)) && (plp->wpnr_no == 1)) && (!(sys->st_flg & 0x20000000)))
    {
        rom->lgtp[1].flg &= ~0x2;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhCPM0_action()
{
    plp->mtn_md = 0;
    
    if (((sys->gm_flg & 0x1000000)) && (!(sys->gm_flg & 0x40)))
    {
        cam.pe_ax = 0;
        cam.pe_pers = 11832;
        
        sys->gm_flg |= 0x2000;
    }
    
    if (((sys->pad_on & 0x10)) && (((plp->flg & 0x20000)) && (!(plp->flg & 0x4000000))) && (((!(plp->stflg & 0x400)) && (!(plp->stflg & 0x10000))))) 
    {
        plp->flg |= 0x10000;
        plp->stflg |= 0x400;
        
        plp->at_flg = 1;
        
        plp->mode1 = 1;
        plp->mode2 = 0x40;
        plp->mode3 = 0;
        
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
    }
    
    if (!(plp->flg & 0x10000)) 
    {
        bhControlPlayerPad();
    }
    
    if (plp->mode1 == 0) 
    {
        bhCPM1_act_bas();
    }
    else 
    {
        bhCPM1_act_atk();
    }
}

// 100% matching!
void bhControlPlayerPad()
{
    if ((!(sys->pad_on & 0x1)) && ((plp->stflg & 0x80))) 
    {
        plp->flg |= 0x200000;
        
        if (plp->mode3 == 5) 
        {
            plp->mode3 = 6;
        }
    } 
    else 
    {
        plp->mode1 = 0;
        
        plp->flg &= ~0x200000;
        
        plp->stflg &= ~0x400;
        sys->st_flg &= ~0x4;
        
        switch (sys->pad_on & 0xF) 
        {
        case 8:
            if (plp->mode2 != 1) 
            {
                plp->mode3 = 0;
            }
            
            plp->mode2 = 1;
            break;
        case 4:
            if (plp->mode2 != 2) 
            {
                plp->mode3 = 0;
            }
            
            plp->mode2 = 2;
            break;
        case 1:
            plp->flg |= 0x200000;
            
            if (!(plp->stflg & 0x80)) 
            {
                plp->mode2 = 3;
                
                if (!(sys->pad_old & 0x1)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            return;
        case 9:
            plp->flg |= 0x200000;
            
            if (!(plp->stflg & 0x80)) 
            {
                plp->mode2 = 4;
                
                if (!(sys->pad_old & 0x1)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            break;
        case 5:
            plp->flg |= 0x200000;
            
            if (!(plp->stflg & 0x80))
            {
                plp->mode2 = 5;
                
                if (!(sys->pad_old & 0x1)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            break;
        case 2:
            plp->flg |= 0x200000;
            
            if (plp->mode2 != 12) 
            {
                plp->mode2 = 9;
                
                if (!(sys->pad_old & 0x2)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            break;
        case 10:
            plp->flg |= 0x200000;
            
            if (plp->mode2 != 12) 
            {
                plp->mode2 = 10;
                
                if (!(sys->pad_old & 0x2)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            break;
        case 6:
            plp->flg |= 0x200000;
            
            if (plp->mode2 != 12) 
            {
                plp->mode2 = 11;
                
                if (!(sys->pad_old & 0x2)) 
                {
                    plp->mode3 = 0;
                }
            }
            
            break;
        default:
            plp->flg |= 0x10;
            
            if (plp->mode2 != 0) 
            {
                plp->mode3 = 0;
            }
            
            plp->mode2 = 0;
            break;
        }
    }
}

// 100% matching!
void bhCPM1_act_bas()
{
    BH_PWORK* p; // not from DWARF
    
    if ((!(sys->gm_flg & 0x40)) || ((plp->stflg & 0x30))) 
    {
        switch (((EXP_WORK*)plp->exp0)->dmlvl)
        {
        case 1:
            ((EXP_WORK*)plp->exp0)->rtspd = 1.0f;
            break;
        case 2:
            ((EXP_WORK*)plp->exp0)->rtspd = 0.8f;
            break;
        default:
            ((EXP_WORK*)plp->exp0)->rtspd = 1.0f;
            break;
        }
    }
    else 
    {
        if ((sys->pad_on & 0xC))
        {
            ((EXP_WORK*)plp->exp0)->rtspd = 0.0078125f * fabsf(sys->pad_dx);
        }
        else 
        {
            ((EXP_WORK*)plp->exp0)->rtspd = 0.0078125f * fabsf(sys->pad_ax);
        }
        
        if (((EXP_WORK*)plp->exp0)->dmlvl == 2)
        {
            ((EXP_WORK*)plp->exp0)->rtspd *= 0.8f;
        }
    }
    
    p = plp;
    
    switch (plp->mode2) 
    {
    case 0:           
        bhCPM2_act_std();
        break;
    case 1:           
        p->ay -= (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
            
        plp->mtn_add = -65536;
        
        bhCPM2_act_srt();
        break;
    case 2:           
        p->ay += (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        plp->mtn_add = 65536;
        
        bhCPM2_act_srt();
        break;
    case 3:           
        bhCPM2_act_wlk();
        break;
    case 4:           
        p->ay -= (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        bhCPM2_act_wlk();
        break;
    case 5:           
        p->ay += (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        bhCPM2_act_wlk();
        break;
    case 6:           
        bhCPM2_act_run();
        break;
    case 9:           
        bhCPM2_act_bak();
        break;
    case 10:          
        p->ay -= (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        bhCPM2_act_bak();
        break;
    case 11:          
        p->ay += (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        bhCPM2_act_bak();
        break;
    case 12:          
        bhCPM2_act_bk2();
        break;
    case 13:          
        bhCPM2_act_sta();
        break;
    case 14:          
        bhCPM2_act_kdu();
        break;
    case 15:          
        bhCPM2_act_kdd();
        break;
    case 16:          
        bhCPM2_act_dnu();
        break;
    case 17:          
        bhCPM2_act_dnd();
        break;
    case 18:          
        bhCPM2_act_psh();
        break;
    case 19:          
        bhCPM2_act_cro();
        break;
    case 20:          
        bhCPM2_act_hsu();
        break;
    case 21:          
        bhCPM2_act_hsd();
        break;
    case 22:          
        bhCPM2_act_rpsh();
        break;
    }
    
    if (plp->mode2 != 3) 
    {
        plp->psh_ct = 0;
    }
}

// 100% matching!
void bhCPM2_act_std() 
{
    int dmlvl;

    if ((sys->gm_flg & 0x1000000)) 
    {
        dmlvl = 0;
    }
    else 
    {
        dmlvl = ((EXP_WORK*)plp->exp0)->dmlvl;
    }
    
    switch (plp->mode3)
    {
    case 0:
        if ((plp->stflg & 0x8000))
        {
            plp->flg &= ~0x2801000;
        }
        else 
        {
            plp->flg &= ~0x2811000;
        }
        
        plp->flg2 &= ~0x1;
        
        EXP1_I(0) |= 0x4;
            
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][0];
        
        plp->hokan_rate = 42598;
        plp->hokan_count = 5;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        plp->ct3 = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        ((EXP_WORK*)plp->exp0)->spxn = 0.3f * (((EXP_WORK*)plp->exp0)->spx - plp->px);
        ((EXP_WORK*)plp->exp0)->spzn = 0.3f * (((EXP_WORK*)plp->exp0)->spz - plp->pz);
        
        plp->mode3++;
    case 1:
        if (plp->hokan_count == 0) 
        {
            plp->flg &= ~0xC0000;
        }
        else if (plp->hokan_count > 2) 
        {
            plp->px += ((EXP_WORK*)plp->exp0)->spxn;
            plp->pz += ((EXP_WORK*)plp->exp0)->spzn;
        }
        
        plp->ct3++;
        
        if ((plp->ct3 > 300) && (((EXP_WORK*)plp->exp0)->dmlvl == 0) && ((sys->ply_id != 1) || (plp->wpnr_no != 1))) 
        {
            plp->flg |= 0x10000;
            
            plp->mode2 = 0xD;
            plp->mode3 = 0;
        }
    }
    
    bhCheckPlayerKegaMotion(((EXP_WORK*)plp->exp0)->wpntp, ((EXP_WORK*)plp->exp0)->dmlvl, 0);
}

// 99.91% matching
void bhCPM2_act_srt()
{
    int dmlvl;

    if ((sys->gm_flg & 0x1000000))
    {
        dmlvl = 0;
    }
    else 
    {
        dmlvl = ((EXP_WORK*)plp->exp0)->dmlvl;
    }
    
    switch (plp->mode3)
    {
    case 0:
        plp->flg  &= ~0x28C0000;
        plp->flg2 &= ~0x1;
        
        EXP1_I(0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][1];
        
        plp->hokan_rate = 42598;
        plp->hokan_count = 8;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->mode3++;
    case 1:
        if ((((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][4]) || (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][4])) 
        {
            plp->flr_snd = bhCheckFloorSound(plp, (int)plp->flr_no, plp->gpx, plp->gpz);
            
            CallPlayerFootStepSe(plp->flr_snd, 0, 1);
            
            plp->stflg |= 0x200;

            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);

                if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][4]) 
                {
                    bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
                }
                else 
                {
                    bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
                }
            }
            
            if ((plp->flg2 & 0x8)) 
            {
                if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][4]) 
                {
                    bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[17].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
                } 
                else 
                {
                    bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[21].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
                }
            }
        }
    }
    
    bhCheckPlayerKegaMotion(((EXP_WORK*)plp->exp0)->wpntp, ((EXP_WORK*)plp->exp0)->dmlvl, 1);
}

// 100% matching!
void bhCPM2_act_sta()
{
    switch (plp->mode3)
    {
    case 0:
        plp->flg  |= 0xD0000;
        plp->flg2 &= ~0x1;
        
        EXP1_I(0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6];
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;

        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->mode3++;
    case 1:
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1)) 
        {
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6] + 1;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    }
    
    if (((sys->pad_on & 0x1F)) || (bhCheckPlayerKegaMotion(((EXP_WORK*)plp->exp0)->wpntp, ((EXP_WORK*)plp->exp0)->dmlvl, 6) != 0))
    {
        plp->flg &= ~0x10000;
        
        sys->pad_on &= ~0xF;
    }
}

// 100% matching!
void bhCPM2_act_wlk()
{
	float* trsz;
    int fsnd;
    int dmlvl;

    if ((sys->gm_flg & 0x1000000)) 
    {
        dmlvl = 0;
    }
    else 
    {
        dmlvl = ((EXP_WORK*)plp->exp0)->dmlvl;
    }
    
    switch (plp->mode3) 
    {
    case 0:
        plp->flg &= ~0xC0000;
        plp->flg2 &= ~0x1;
        
        if (!(plp->flg & 0x800000))
        {
            plp->frm_no = 327680;
        }
        else 
        {
            plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][2]].frm_num, plp->frm_no);
        }
        
        plp->flg &= ~0x800000;
        
        EXP1_I(0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][2];
        
        plp->hokan_rate = 42598;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        if ((plp->stflg & 0x100000)) 
        {
            bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
        }
        
        plp->mode3++;
    case 1:
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][2];
        
        plp->flg |= 0x2000000;
        
        trsz = bhGetTransZ(PlyTrsZ[0][dmlvl]);
        
        plp->spd = trsz[(plp->frm_no / 65536) + 1];
        
        if ((plp->stflg & 0x100000)) 
        {
            plp->spd *= 0.8f;
        }
        
        if ((sys->gm_flg & 0x1000000)) 
        {
            switch (((EXP_WORK*)plp->exp0)->dmlvl) 
            {
            case 1:
                plp->spd *= 0.8f;
                break;
            case 2:
                plp->spd *= 0.6f;
            }
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][0])
        {
            CallPlayerFootStepSe(bhCheckFloorSound(plp, (int)plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]), 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
            }
            
            if ((plp->flg2 & 0x8)) 
            {
                bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[17].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
            }
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][0])
        {
            CallPlayerFootStepSe(bhCheckFloorSound(plp, (int)plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]), 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
            }
            
            if ((plp->flg2 & 0x8)) 
            {
                bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[21].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
            }
        }
    }
    
    bhAddSpeed(plp, 0);
    
    if ((sys->pad_on & 0x400)) 
    {
        plp->flg |= 0x10000;
        
        plp->mode2 = 6;
        plp->mode3 = 0;
        return;
    }
    
    if ((plp->psh_ct > 5) && (!(plp->stflg & 0x80))) 
    {
        sys->st_flg |= 0x4;
        plp->stflg |= 0x10080;
        
        plp->mode2 = 18;
        plp->mode3 = 0;
    }
    
    bhCheckPlayerKegaMotion(((EXP_WORK*)plp->exp0)->wpntp, ((EXP_WORK*)plp->exp0)->dmlvl, 2);
}

// 100% matching!
void bhCPM2_act_run()
{
	float* trsz;
    int fsnd;
    int dmlvl;
    float fSin, fCos;    

    if ((sys->gm_flg & 0x1000000)) 
    {
        dmlvl = 0;
    }
    else 
    {
        dmlvl = ((EXP_WORK*)plp->exp0)->dmlvl;
    }
    
    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0xC0000;
        plp->flg2 &= ~0x1;
        
        EXP1_I(0) |= 0x4;
        
        plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][3]].frm_num, plp->frm_no);
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][dmlvl][3];
        
        plp->hokan_rate = 42598;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 3.0f;
        
        plp->mode3++;
    case 1:
        plp->flg |= 0x2000000;
        
        if (!(plp->flg & 0x4000000)) 
        {
            trsz = bhGetTransZ(PlyTrsZ[3][dmlvl]);
            
            plp->spd = trsz[(plp->frm_no / 65536) + 1];
            
            if ((plp->stflg & 0x100000)) 
            {
                plp->spd *= 0.8f;
            }
            
            if ((sys->gm_flg & 0x1000000)) 
            {
                switch (((EXP_WORK*)plp->exp0)->dmlvl)
                {
                case 1:
                    plp->spd *= 0.8f;
                    break;
                case 2:
                    plp->spd *= 0.6f;
                    break; 
                }
            }
            
            if (!(sys->pad_on & 0x1)) 
            {
                plp->flg &= ~0x10000;
                
                plp->mode2 = 0;
                plp->mode3 = 0;
                return;
            }
        
            if (!(sys->pad_on & 0x400)) 
            {
                plp->flg &= ~0x10000;
                plp->flg |= 0x800000;
                
                plp->mode2 = 3;
                plp->mode3 = 0;
                return;
            }
            
            if ((sys->pad_on & 0x8)) 
            {
                plp->ay -= (int)(182.04445f * (4.5f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            if ((sys->pad_on & 0x4)) 
            {
                plp->ay += (int)(182.04445f * (4.5f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            bhAddSpeed(plp, 0);
        }
        else
        {
            plp->spd = 0;
            
            njSinCos(plp->ayp + 16384, &fSin, &fCos);
            
            plp->px -= 0.2f * fSin;
            plp->pz -= 0.2f * fCos;
            
            ((EXP_WORK*)plp->exp0)->spx = plp->px;
            ((EXP_WORK*)plp->exp0)->spz = plp->pz;
        }

        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][1]) 
        {
            CallPlayerFootStepSe(bhCheckFloorSound(plp, (int)plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]), 1, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                bhSetWaterSplash(plp, 15, 1, 1.6f, 1.6f, 1.6f);
            }
            
            if ((plp->flg2 & 0x8)) 
            {
                bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[17].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
            }
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][1]) 
        {
            CallPlayerFootStepSe(bhCheckFloorSound(plp, (int)plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]), 1, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                bhSetWaterSplash(plp, 19, 1, 1.6f, 1.6f, 1.6f);
            }
            
            if ((plp->flg2 & 0x8)) 
            {
                bhSetWaterSplash3((NJS_POINT3*)&plp->mlwP->owP[21].mtx[12], plp->ay, plp->footeff, 0.8f, 0.8f, 0.8f);
            }
        }
    default:
        bhCheckPlayerKegaMotion(((EXP_WORK*)plp->exp0)->wpntp, ((EXP_WORK*)plp->exp0)->dmlvl, 3);
        break;
    }
}

// 
// Start address: 0x13d970
void bhCPM2_act_bak()
{
	int fsnd;
	float* trsz;
	// Line 1662, Address: 0x13d970, Func Offset: 0
	// Line 1665, Address: 0x13d978, Func Offset: 0x8
	// Line 1667, Address: 0x13d9a0, Func Offset: 0x30
	// Line 1668, Address: 0x13d9ac, Func Offset: 0x3c
	// Line 1667, Address: 0x13d9b4, Func Offset: 0x44
	// Line 1668, Address: 0x13d9bc, Func Offset: 0x4c
	// Line 1670, Address: 0x13d9c0, Func Offset: 0x50
	// Line 1668, Address: 0x13d9c4, Func Offset: 0x54
	// Line 1669, Address: 0x13d9c8, Func Offset: 0x58
	// Line 1668, Address: 0x13d9cc, Func Offset: 0x5c
	// Line 1669, Address: 0x13d9d4, Func Offset: 0x64
	// Line 1670, Address: 0x13d9dc, Func Offset: 0x6c
	// Line 1669, Address: 0x13d9e0, Func Offset: 0x70
	// Line 1670, Address: 0x13d9ec, Func Offset: 0x7c
	// Line 1671, Address: 0x13da00, Func Offset: 0x90
	// Line 1674, Address: 0x13da84, Func Offset: 0x114
	// Line 1675, Address: 0x13da8c, Func Offset: 0x11c
	// Line 1677, Address: 0x13da90, Func Offset: 0x120
	// Line 1678, Address: 0x13daa0, Func Offset: 0x130
	// Line 1677, Address: 0x13daa8, Func Offset: 0x138
	// Line 1678, Address: 0x13daac, Func Offset: 0x13c
	// Line 1679, Address: 0x13dab0, Func Offset: 0x140
	// Line 1680, Address: 0x13dab4, Func Offset: 0x144
	// Line 1681, Address: 0x13dab8, Func Offset: 0x148
	// Line 1677, Address: 0x13dabc, Func Offset: 0x14c
	// Line 1678, Address: 0x13dac4, Func Offset: 0x154
	// Line 1683, Address: 0x13dac8, Func Offset: 0x158
	// Line 1684, Address: 0x13dacc, Func Offset: 0x15c
	// Line 1678, Address: 0x13dad0, Func Offset: 0x160
	// Line 1679, Address: 0x13dad4, Func Offset: 0x164
	// Line 1678, Address: 0x13dad8, Func Offset: 0x168
	// Line 1679, Address: 0x13db10, Func Offset: 0x1a0
	// Line 1680, Address: 0x13db18, Func Offset: 0x1a8
	// Line 1681, Address: 0x13db24, Func Offset: 0x1b4
	// Line 1682, Address: 0x13db30, Func Offset: 0x1c0
	// Line 1683, Address: 0x13db3c, Func Offset: 0x1cc
	// Line 1684, Address: 0x13db48, Func Offset: 0x1d8
	// Line 1683, Address: 0x13db4c, Func Offset: 0x1dc
	// Line 1684, Address: 0x13db50, Func Offset: 0x1e0
	// Line 1685, Address: 0x13db64, Func Offset: 0x1f4
	// Line 1686, Address: 0x13db78, Func Offset: 0x208
	// Line 1688, Address: 0x13db8c, Func Offset: 0x21c
	// Line 1689, Address: 0x13dba0, Func Offset: 0x230
	// Line 1688, Address: 0x13dba4, Func Offset: 0x234
	// Line 1689, Address: 0x13dbdc, Func Offset: 0x26c
	// Line 1691, Address: 0x13dbf8, Func Offset: 0x288
	// Line 1696, Address: 0x13dc00, Func Offset: 0x290
	// Line 1691, Address: 0x13dc08, Func Offset: 0x298
	// Line 1693, Address: 0x13dc0c, Func Offset: 0x29c
	// Line 1691, Address: 0x13dc10, Func Offset: 0x2a0
	// Line 1692, Address: 0x13dc14, Func Offset: 0x2a4
	// Line 1694, Address: 0x13dc18, Func Offset: 0x2a8
	// Line 1691, Address: 0x13dc1c, Func Offset: 0x2ac
	// Line 1692, Address: 0x13dc24, Func Offset: 0x2b4
	// Line 1693, Address: 0x13dc2c, Func Offset: 0x2bc
	// Line 1692, Address: 0x13dc30, Func Offset: 0x2c0
	// Line 1693, Address: 0x13dc3c, Func Offset: 0x2cc
	// Line 1694, Address: 0x13dc44, Func Offset: 0x2d4
	// Line 1695, Address: 0x13dc50, Func Offset: 0x2e0
	// Line 1696, Address: 0x13dc5c, Func Offset: 0x2ec
	// Line 1695, Address: 0x13dc60, Func Offset: 0x2f0
	// Line 1696, Address: 0x13dc6c, Func Offset: 0x2fc
	// Line 1699, Address: 0x13dcec, Func Offset: 0x37c
	// Line 1700, Address: 0x13dcf4, Func Offset: 0x384
	// Line 1701, Address: 0x13dcf8, Func Offset: 0x388
	// Line 1696, Address: 0x13dcfc, Func Offset: 0x38c
	// Line 1699, Address: 0x13dd00, Func Offset: 0x390
	// Line 1702, Address: 0x13dd08, Func Offset: 0x398
	// Line 1703, Address: 0x13dd0c, Func Offset: 0x39c
	// Line 1704, Address: 0x13dd10, Func Offset: 0x3a0
	// Line 1699, Address: 0x13dd14, Func Offset: 0x3a4
	// Line 1700, Address: 0x13dd18, Func Offset: 0x3a8
	// Line 1699, Address: 0x13dd1c, Func Offset: 0x3ac
	// Line 1700, Address: 0x13dd54, Func Offset: 0x3e4
	// Line 1701, Address: 0x13dd5c, Func Offset: 0x3ec
	// Line 1702, Address: 0x13dd68, Func Offset: 0x3f8
	// Line 1703, Address: 0x13dd74, Func Offset: 0x404
	// Line 1704, Address: 0x13dd80, Func Offset: 0x410
	// Line 1703, Address: 0x13dd84, Func Offset: 0x414
	// Line 1704, Address: 0x13dd88, Func Offset: 0x418
	// Line 1706, Address: 0x13dd90, Func Offset: 0x420
	// Line 1704, Address: 0x13dd94, Func Offset: 0x424
	// Line 1706, Address: 0x13dd98, Func Offset: 0x428
	// Line 1709, Address: 0x13ddb4, Func Offset: 0x444
	// Line 1710, Address: 0x13ddc4, Func Offset: 0x454
	// Line 1711, Address: 0x13ddcc, Func Offset: 0x45c
	// Line 1710, Address: 0x13ddd0, Func Offset: 0x460
	// Line 1711, Address: 0x13ddd4, Func Offset: 0x464
	// Line 1710, Address: 0x13ddd8, Func Offset: 0x468
	// Line 1711, Address: 0x13dde0, Func Offset: 0x470
	// Line 1712, Address: 0x13ddf4, Func Offset: 0x484
	// Line 1713, Address: 0x13de08, Func Offset: 0x498
	// Line 1716, Address: 0x13de30, Func Offset: 0x4c0
	// Line 1717, Address: 0x13de48, Func Offset: 0x4d8
	// Line 1721, Address: 0x13de74, Func Offset: 0x504
	// Line 1723, Address: 0x13de7c, Func Offset: 0x50c
	// Line 1725, Address: 0x13de90, Func Offset: 0x520
	// Line 1729, Address: 0x13deb4, Func Offset: 0x544
	// Line 1730, Address: 0x13dec4, Func Offset: 0x554
	// Line 1731, Address: 0x13decc, Func Offset: 0x55c
	// Line 1735, Address: 0x13ded4, Func Offset: 0x564
	// Line 1736, Address: 0x13def8, Func Offset: 0x588
	// Line 1737, Address: 0x13df00, Func Offset: 0x590
	// Line 1736, Address: 0x13df04, Func Offset: 0x594
	// Line 1737, Address: 0x13df08, Func Offset: 0x598
	// Line 1736, Address: 0x13df0c, Func Offset: 0x59c
	// Line 1737, Address: 0x13df24, Func Offset: 0x5b4
	// Line 1739, Address: 0x13df54, Func Offset: 0x5e4
	// Line 1740, Address: 0x13df94, Func Offset: 0x624
	// Line 1743, Address: 0x13dfac, Func Offset: 0x63c
	// Line 1744, Address: 0x13dfbc, Func Offset: 0x64c
	// Line 1745, Address: 0x13dfc4, Func Offset: 0x654
	// Line 1744, Address: 0x13dfc8, Func Offset: 0x658
	// Line 1745, Address: 0x13dfcc, Func Offset: 0x65c
	// Line 1744, Address: 0x13dfd0, Func Offset: 0x660
	// Line 1745, Address: 0x13dfd8, Func Offset: 0x668
	// Line 1746, Address: 0x13dfec, Func Offset: 0x67c
	// Line 1747, Address: 0x13e000, Func Offset: 0x690
	// Line 1750, Address: 0x13e028, Func Offset: 0x6b8
	// Line 1751, Address: 0x13e040, Func Offset: 0x6d0
	// Line 1757, Address: 0x13e06c, Func Offset: 0x6fc
	// Line 1758, Address: 0x13e0ac, Func Offset: 0x73c
	// Line 1761, Address: 0x13e0c4, Func Offset: 0x754
	// Line 1762, Address: 0x13e0d4, Func Offset: 0x764
	// Line 1763, Address: 0x13e0dc, Func Offset: 0x76c
	// Line 1762, Address: 0x13e0e0, Func Offset: 0x770
	// Line 1763, Address: 0x13e0e4, Func Offset: 0x774
	// Line 1762, Address: 0x13e0e8, Func Offset: 0x778
	// Line 1763, Address: 0x13e0f0, Func Offset: 0x780
	// Line 1764, Address: 0x13e104, Func Offset: 0x794
	// Line 1765, Address: 0x13e118, Func Offset: 0x7a8
	// Line 1768, Address: 0x13e140, Func Offset: 0x7d0
	// Line 1769, Address: 0x13e158, Func Offset: 0x7e8
	// Line 1776, Address: 0x13e184, Func Offset: 0x814
	// Line 1777, Address: 0x13e194, Func Offset: 0x824
	// Line 1778, Address: 0x13e1b0, Func Offset: 0x840
	// Func End, Address: 0x13e1bc, Func Offset: 0x84c
    scePrintf("bhCPM2_act_bak - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x13e1c0
void bhCPM2_act_bk2()
{
	int fsnd;
	float* trsz;
	// Line 1784, Address: 0x13e1c0, Func Offset: 0
	// Line 1787, Address: 0x13e1cc, Func Offset: 0xc
	// Line 1789, Address: 0x13e1f4, Func Offset: 0x34
	// Line 1790, Address: 0x13e200, Func Offset: 0x40
	// Line 1792, Address: 0x13e204, Func Offset: 0x44
	// Line 1790, Address: 0x13e208, Func Offset: 0x48
	// Line 1789, Address: 0x13e20c, Func Offset: 0x4c
	// Line 1790, Address: 0x13e214, Func Offset: 0x54
	// Line 1792, Address: 0x13e218, Func Offset: 0x58
	// Line 1790, Address: 0x13e21c, Func Offset: 0x5c
	// Line 1791, Address: 0x13e220, Func Offset: 0x60
	// Line 1790, Address: 0x13e224, Func Offset: 0x64
	// Line 1791, Address: 0x13e22c, Func Offset: 0x6c
	// Line 1792, Address: 0x13e234, Func Offset: 0x74
	// Line 1791, Address: 0x13e238, Func Offset: 0x78
	// Line 1792, Address: 0x13e244, Func Offset: 0x84
	// Line 1795, Address: 0x13e2c4, Func Offset: 0x104
	// Line 1796, Address: 0x13e2cc, Func Offset: 0x10c
	// Line 1797, Address: 0x13e2d0, Func Offset: 0x110
	// Line 1792, Address: 0x13e2d4, Func Offset: 0x114
	// Line 1795, Address: 0x13e2d8, Func Offset: 0x118
	// Line 1798, Address: 0x13e2e0, Func Offset: 0x120
	// Line 1800, Address: 0x13e2e4, Func Offset: 0x124
	// Line 1795, Address: 0x13e2e8, Func Offset: 0x128
	// Line 1796, Address: 0x13e2ec, Func Offset: 0x12c
	// Line 1795, Address: 0x13e2f0, Func Offset: 0x130
	// Line 1796, Address: 0x13e328, Func Offset: 0x168
	// Line 1797, Address: 0x13e330, Func Offset: 0x170
	// Line 1798, Address: 0x13e33c, Func Offset: 0x17c
	// Line 1799, Address: 0x13e348, Func Offset: 0x188
	// Line 1800, Address: 0x13e354, Func Offset: 0x194
	// Line 1801, Address: 0x13e360, Func Offset: 0x1a0
	// Line 1800, Address: 0x13e364, Func Offset: 0x1a4
	// Line 1801, Address: 0x13e368, Func Offset: 0x1a8
	// Line 1803, Address: 0x13e378, Func Offset: 0x1b8
	// Line 1805, Address: 0x13e398, Func Offset: 0x1d8
	// Line 1810, Address: 0x13e3a0, Func Offset: 0x1e0
	// Line 1805, Address: 0x13e3a8, Func Offset: 0x1e8
	// Line 1807, Address: 0x13e3ac, Func Offset: 0x1ec
	// Line 1805, Address: 0x13e3b0, Func Offset: 0x1f0
	// Line 1806, Address: 0x13e3b4, Func Offset: 0x1f4
	// Line 1808, Address: 0x13e3b8, Func Offset: 0x1f8
	// Line 1805, Address: 0x13e3bc, Func Offset: 0x1fc
	// Line 1806, Address: 0x13e3c4, Func Offset: 0x204
	// Line 1807, Address: 0x13e3cc, Func Offset: 0x20c
	// Line 1806, Address: 0x13e3d0, Func Offset: 0x210
	// Line 1807, Address: 0x13e3dc, Func Offset: 0x21c
	// Line 1808, Address: 0x13e3e4, Func Offset: 0x224
	// Line 1809, Address: 0x13e3f0, Func Offset: 0x230
	// Line 1810, Address: 0x13e3fc, Func Offset: 0x23c
	// Line 1809, Address: 0x13e400, Func Offset: 0x240
	// Line 1810, Address: 0x13e40c, Func Offset: 0x24c
	// Line 1813, Address: 0x13e48c, Func Offset: 0x2cc
	// Line 1814, Address: 0x13e494, Func Offset: 0x2d4
	// Line 1815, Address: 0x13e498, Func Offset: 0x2d8
	// Line 1810, Address: 0x13e49c, Func Offset: 0x2dc
	// Line 1813, Address: 0x13e4a0, Func Offset: 0x2e0
	// Line 1816, Address: 0x13e4a8, Func Offset: 0x2e8
	// Line 1817, Address: 0x13e4ac, Func Offset: 0x2ec
	// Line 1818, Address: 0x13e4b0, Func Offset: 0x2f0
	// Line 1813, Address: 0x13e4b4, Func Offset: 0x2f4
	// Line 1814, Address: 0x13e4b8, Func Offset: 0x2f8
	// Line 1813, Address: 0x13e4bc, Func Offset: 0x2fc
	// Line 1814, Address: 0x13e4f4, Func Offset: 0x334
	// Line 1815, Address: 0x13e4fc, Func Offset: 0x33c
	// Line 1816, Address: 0x13e508, Func Offset: 0x348
	// Line 1817, Address: 0x13e514, Func Offset: 0x354
	// Line 1818, Address: 0x13e520, Func Offset: 0x360
	// Line 1817, Address: 0x13e524, Func Offset: 0x364
	// Line 1818, Address: 0x13e528, Func Offset: 0x368
	// Line 1820, Address: 0x13e530, Func Offset: 0x370
	// Line 1818, Address: 0x13e534, Func Offset: 0x374
	// Line 1820, Address: 0x13e538, Func Offset: 0x378
	// Line 1823, Address: 0x13e554, Func Offset: 0x394
	// Line 1824, Address: 0x13e564, Func Offset: 0x3a4
	// Line 1825, Address: 0x13e56c, Func Offset: 0x3ac
	// Line 1824, Address: 0x13e570, Func Offset: 0x3b0
	// Line 1825, Address: 0x13e574, Func Offset: 0x3b4
	// Line 1824, Address: 0x13e578, Func Offset: 0x3b8
	// Line 1825, Address: 0x13e580, Func Offset: 0x3c0
	// Line 1826, Address: 0x13e594, Func Offset: 0x3d4
	// Line 1827, Address: 0x13e5a8, Func Offset: 0x3e8
	// Line 1830, Address: 0x13e5d0, Func Offset: 0x410
	// Line 1831, Address: 0x13e5e8, Func Offset: 0x428
	// Line 1835, Address: 0x13e614, Func Offset: 0x454
	// Line 1838, Address: 0x13e61c, Func Offset: 0x45c
	// Line 1839, Address: 0x13e630, Func Offset: 0x470
	// Line 1840, Address: 0x13e63c, Func Offset: 0x47c
	// Line 1841, Address: 0x13e644, Func Offset: 0x484
	// Line 1844, Address: 0x13e64c, Func Offset: 0x48c
	// Line 1848, Address: 0x13e674, Func Offset: 0x4b4
	// Line 1849, Address: 0x13e680, Func Offset: 0x4c0
	// Line 1848, Address: 0x13e684, Func Offset: 0x4c4
	// Line 1849, Address: 0x13e688, Func Offset: 0x4c8
	// Line 1848, Address: 0x13e68c, Func Offset: 0x4cc
	// Line 1849, Address: 0x13e694, Func Offset: 0x4d4
	// Line 1850, Address: 0x13e69c, Func Offset: 0x4dc
	// Line 1851, Address: 0x13e6a4, Func Offset: 0x4e4
	// Line 1854, Address: 0x13e6ac, Func Offset: 0x4ec
	// Line 1855, Address: 0x13e6cc, Func Offset: 0x50c
	// Line 1856, Address: 0x13e6d4, Func Offset: 0x514
	// Line 1855, Address: 0x13e6d8, Func Offset: 0x518
	// Line 1856, Address: 0x13e6dc, Func Offset: 0x51c
	// Line 1855, Address: 0x13e6e0, Func Offset: 0x520
	// Line 1856, Address: 0x13e6f8, Func Offset: 0x538
	// Line 1858, Address: 0x13e728, Func Offset: 0x568
	// Line 1859, Address: 0x13e748, Func Offset: 0x588
	// Line 1861, Address: 0x13e784, Func Offset: 0x5c4
	// Line 1862, Address: 0x13e7a4, Func Offset: 0x5e4
	// Line 1865, Address: 0x13e7e0, Func Offset: 0x620
	// Line 1866, Address: 0x13e820, Func Offset: 0x660
	// Line 1869, Address: 0x13e838, Func Offset: 0x678
	// Line 1870, Address: 0x13e848, Func Offset: 0x688
	// Line 1871, Address: 0x13e850, Func Offset: 0x690
	// Line 1870, Address: 0x13e854, Func Offset: 0x694
	// Line 1871, Address: 0x13e858, Func Offset: 0x698
	// Line 1870, Address: 0x13e85c, Func Offset: 0x69c
	// Line 1871, Address: 0x13e864, Func Offset: 0x6a4
	// Line 1872, Address: 0x13e878, Func Offset: 0x6b8
	// Line 1873, Address: 0x13e88c, Func Offset: 0x6cc
	// Line 1876, Address: 0x13e8b4, Func Offset: 0x6f4
	// Line 1877, Address: 0x13e8cc, Func Offset: 0x70c
	// Line 1883, Address: 0x13e8f8, Func Offset: 0x738
	// Line 1884, Address: 0x13e938, Func Offset: 0x778
	// Line 1887, Address: 0x13e950, Func Offset: 0x790
	// Line 1888, Address: 0x13e960, Func Offset: 0x7a0
	// Line 1889, Address: 0x13e968, Func Offset: 0x7a8
	// Line 1888, Address: 0x13e96c, Func Offset: 0x7ac
	// Line 1889, Address: 0x13e970, Func Offset: 0x7b0
	// Line 1888, Address: 0x13e974, Func Offset: 0x7b4
	// Line 1889, Address: 0x13e97c, Func Offset: 0x7bc
	// Line 1890, Address: 0x13e990, Func Offset: 0x7d0
	// Line 1891, Address: 0x13e9a4, Func Offset: 0x7e4
	// Line 1894, Address: 0x13e9cc, Func Offset: 0x80c
	// Line 1895, Address: 0x13e9e4, Func Offset: 0x824
	// Line 1902, Address: 0x13ea10, Func Offset: 0x850
	// Line 1903, Address: 0x13ea20, Func Offset: 0x860
	// Line 1904, Address: 0x13ea3c, Func Offset: 0x87c
	// Func End, Address: 0x13ea4c, Func Offset: 0x88c
    scePrintf("bhCPM2_act_bk2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x13ea50
void bhCPM2_act_kdu()
{
	short ayn;
	int dlvl;
	int fsnd;
	int flr_no;
	int ang[3];
	//_anon35 pos2;
	//_anon35 pos;
	//_anon22* htp;
	// Line 1910, Address: 0x13ea50, Func Offset: 0
	// Line 1911, Address: 0x13ea5c, Func Offset: 0xc
	// Line 1917, Address: 0x13ea6c, Func Offset: 0x1c
	// Line 1911, Address: 0x13ea70, Func Offset: 0x20
	// Line 1917, Address: 0x13ea74, Func Offset: 0x24
	// Line 1918, Address: 0x13ea7c, Func Offset: 0x2c
	// Line 1920, Address: 0x13eab0, Func Offset: 0x60
	// Line 1927, Address: 0x13eabc, Func Offset: 0x6c
	// Line 1920, Address: 0x13eac4, Func Offset: 0x74
	// Line 1921, Address: 0x13eacc, Func Offset: 0x7c
	// Line 1933, Address: 0x13ead4, Func Offset: 0x84
	// Line 1921, Address: 0x13eae0, Func Offset: 0x90
	// Line 1922, Address: 0x13eae8, Func Offset: 0x98
	// Line 1928, Address: 0x13eaec, Func Offset: 0x9c
	// Line 1929, Address: 0x13eaf0, Func Offset: 0xa0
	// Line 1930, Address: 0x13eaf4, Func Offset: 0xa4
	// Line 1921, Address: 0x13eaf8, Func Offset: 0xa8
	// Line 1922, Address: 0x13eb04, Func Offset: 0xb4
	// Line 1926, Address: 0x13eb0c, Func Offset: 0xbc
	// Line 1922, Address: 0x13eb10, Func Offset: 0xc0
	// Line 1926, Address: 0x13eb1c, Func Offset: 0xcc
	// Line 1927, Address: 0x13eb24, Func Offset: 0xd4
	// Line 1926, Address: 0x13eb28, Func Offset: 0xd8
	// Line 1927, Address: 0x13eb30, Func Offset: 0xe0
	// Line 1928, Address: 0x13eb38, Func Offset: 0xe8
	// Line 1927, Address: 0x13eb3c, Func Offset: 0xec
	// Line 1928, Address: 0x13eb74, Func Offset: 0x124
	// Line 1929, Address: 0x13eb7c, Func Offset: 0x12c
	// Line 1930, Address: 0x13eb88, Func Offset: 0x138
	// Line 1931, Address: 0x13eb94, Func Offset: 0x144
	// Line 1932, Address: 0x13eba0, Func Offset: 0x150
	// Line 1931, Address: 0x13eba4, Func Offset: 0x154
	// Line 1932, Address: 0x13eba8, Func Offset: 0x158
	// Line 1933, Address: 0x13ebb0, Func Offset: 0x160
	// Line 1934, Address: 0x13ebf0, Func Offset: 0x1a0
	// Line 1936, Address: 0x13ebfc, Func Offset: 0x1ac
	// Line 1937, Address: 0x13ec0c, Func Offset: 0x1bc
	// Line 1938, Address: 0x13ec20, Func Offset: 0x1d0
	// Line 1939, Address: 0x13ec24, Func Offset: 0x1d4
	// Line 1941, Address: 0x13ec2c, Func Offset: 0x1dc
	// Line 1943, Address: 0x13ec30, Func Offset: 0x1e0
	// Line 1944, Address: 0x13ec50, Func Offset: 0x200
	// Line 1945, Address: 0x13ec54, Func Offset: 0x204
	// Line 1947, Address: 0x13ec5c, Func Offset: 0x20c
	// Line 1948, Address: 0x13ec90, Func Offset: 0x240
	// Line 1947, Address: 0x13ec98, Func Offset: 0x248
	// Line 1948, Address: 0x13eca0, Func Offset: 0x250
	// Line 1949, Address: 0x13eca4, Func Offset: 0x254
	// Line 1951, Address: 0x13ecac, Func Offset: 0x25c
	// Line 1953, Address: 0x13ecb0, Func Offset: 0x260
	// Line 1954, Address: 0x13ecd0, Func Offset: 0x280
	// Line 1955, Address: 0x13ecd4, Func Offset: 0x284
	// Line 1957, Address: 0x13ecdc, Func Offset: 0x28c
	// Line 1958, Address: 0x13ed10, Func Offset: 0x2c0
	// Line 1957, Address: 0x13ed18, Func Offset: 0x2c8
	// Line 1958, Address: 0x13ed20, Func Offset: 0x2d0
	// Line 1959, Address: 0x13ed24, Func Offset: 0x2d4
	// Line 1961, Address: 0x13ed2c, Func Offset: 0x2dc
	// Line 1962, Address: 0x13ed40, Func Offset: 0x2f0
	// Line 1963, Address: 0x13ed60, Func Offset: 0x310
	// Line 1965, Address: 0x13ed74, Func Offset: 0x324
	// Line 1966, Address: 0x13ed84, Func Offset: 0x334
	// Line 1967, Address: 0x13edac, Func Offset: 0x35c
	// Line 1968, Address: 0x13edb8, Func Offset: 0x368
	// Line 1967, Address: 0x13edbc, Func Offset: 0x36c
	// Line 1968, Address: 0x13edc0, Func Offset: 0x370
	// Line 1969, Address: 0x13edd0, Func Offset: 0x380
	// Line 1970, Address: 0x13ee24, Func Offset: 0x3d4
	// Line 1971, Address: 0x13ee2c, Func Offset: 0x3dc
	// Line 1972, Address: 0x13ee30, Func Offset: 0x3e0
	// Line 1973, Address: 0x13ee34, Func Offset: 0x3e4
	// Line 1974, Address: 0x13ee38, Func Offset: 0x3e8
	// Line 1970, Address: 0x13ee3c, Func Offset: 0x3ec
	// Line 1971, Address: 0x13ee40, Func Offset: 0x3f0
	// Line 1976, Address: 0x13ee44, Func Offset: 0x3f4
	// Line 1970, Address: 0x13ee50, Func Offset: 0x400
	// Line 1971, Address: 0x13ee54, Func Offset: 0x404
	// Line 1972, Address: 0x13ee68, Func Offset: 0x418
	// Line 1971, Address: 0x13ee6c, Func Offset: 0x41c
	// Line 1972, Address: 0x13ee70, Func Offset: 0x420
	// Line 1973, Address: 0x13ee78, Func Offset: 0x428
	// Line 1974, Address: 0x13ee84, Func Offset: 0x434
	// Line 1975, Address: 0x13ee90, Func Offset: 0x440
	// Line 1976, Address: 0x13ee9c, Func Offset: 0x44c
	// Line 1978, Address: 0x13eed8, Func Offset: 0x488
	// Line 1976, Address: 0x13eedc, Func Offset: 0x48c
	// Line 1978, Address: 0x13eee0, Func Offset: 0x490
	// Line 1979, Address: 0x13eeec, Func Offset: 0x49c
	// Line 1980, Address: 0x13eefc, Func Offset: 0x4ac
	// Line 1981, Address: 0x13ef14, Func Offset: 0x4c4
	// Line 1982, Address: 0x13ef20, Func Offset: 0x4d0
	// Line 1981, Address: 0x13ef24, Func Offset: 0x4d4
	// Line 1982, Address: 0x13ef28, Func Offset: 0x4d8
	// Line 1981, Address: 0x13ef2c, Func Offset: 0x4dc
	// Line 1982, Address: 0x13ef30, Func Offset: 0x4e0
	// Line 1984, Address: 0x13ef38, Func Offset: 0x4e8
	// Line 1986, Address: 0x13ef48, Func Offset: 0x4f8
	// Line 1987, Address: 0x13ef60, Func Offset: 0x510
	// Line 1988, Address: 0x13ef6c, Func Offset: 0x51c
	// Line 1987, Address: 0x13ef70, Func Offset: 0x520
	// Line 1988, Address: 0x13ef74, Func Offset: 0x524
	// Line 1987, Address: 0x13ef78, Func Offset: 0x528
	// Line 1988, Address: 0x13ef80, Func Offset: 0x530
	// Line 1989, Address: 0x13ef94, Func Offset: 0x544
	// Line 1990, Address: 0x13efac, Func Offset: 0x55c
	// Line 1991, Address: 0x13efb4, Func Offset: 0x564
	// Line 1992, Address: 0x13efc8, Func Offset: 0x578
	// Line 1993, Address: 0x13efd8, Func Offset: 0x588
	// Line 1994, Address: 0x13efe8, Func Offset: 0x598
	// Line 1993, Address: 0x13efec, Func Offset: 0x59c
	// Line 1994, Address: 0x13eff4, Func Offset: 0x5a4
	// Line 1995, Address: 0x13f004, Func Offset: 0x5b4
	// Line 1994, Address: 0x13f008, Func Offset: 0x5b8
	// Line 1995, Address: 0x13f018, Func Offset: 0x5c8
	// Line 1996, Address: 0x13f024, Func Offset: 0x5d4
	// Line 1995, Address: 0x13f028, Func Offset: 0x5d8
	// Line 1996, Address: 0x13f030, Func Offset: 0x5e0
	// Line 1999, Address: 0x13f038, Func Offset: 0x5e8
	// Line 2000, Address: 0x13f060, Func Offset: 0x610
	// Line 2003, Address: 0x13f134, Func Offset: 0x6e4
	// Line 2004, Address: 0x13f138, Func Offset: 0x6e8
	// Line 2005, Address: 0x13f140, Func Offset: 0x6f0
	// Line 2003, Address: 0x13f148, Func Offset: 0x6f8
	// Line 2004, Address: 0x13f154, Func Offset: 0x704
	// Line 2010, Address: 0x13f15c, Func Offset: 0x70c
	// Line 2004, Address: 0x13f16c, Func Offset: 0x71c
	// Line 2005, Address: 0x13f170, Func Offset: 0x720
	// Line 2006, Address: 0x13f174, Func Offset: 0x724
	// Line 2007, Address: 0x13f178, Func Offset: 0x728
	// Line 2008, Address: 0x13f17c, Func Offset: 0x72c
	// Line 2004, Address: 0x13f180, Func Offset: 0x730
	// Line 2005, Address: 0x13f188, Func Offset: 0x738
	// Line 2006, Address: 0x13f190, Func Offset: 0x740
	// Line 2005, Address: 0x13f194, Func Offset: 0x744
	// Line 2006, Address: 0x13f1cc, Func Offset: 0x77c
	// Line 2007, Address: 0x13f1d4, Func Offset: 0x784
	// Line 2008, Address: 0x13f1e0, Func Offset: 0x790
	// Line 2009, Address: 0x13f1ec, Func Offset: 0x79c
	// Line 2010, Address: 0x13f1f8, Func Offset: 0x7a8
	// Line 2009, Address: 0x13f1fc, Func Offset: 0x7ac
	// Line 2010, Address: 0x13f204, Func Offset: 0x7b4
	// Line 2011, Address: 0x13f22c, Func Offset: 0x7dc
	// Line 2010, Address: 0x13f230, Func Offset: 0x7e0
	// Line 2011, Address: 0x13f238, Func Offset: 0x7e8
	// Line 2012, Address: 0x13f25c, Func Offset: 0x80c
	// Line 2013, Address: 0x13f260, Func Offset: 0x810
	// Line 2014, Address: 0x13f270, Func Offset: 0x820
	// Line 2013, Address: 0x13f274, Func Offset: 0x824
	// Line 2014, Address: 0x13f27c, Func Offset: 0x82c
	// Line 2017, Address: 0x13f29c, Func Offset: 0x84c
	// Line 2018, Address: 0x13f2ac, Func Offset: 0x85c
	// Line 2019, Address: 0x13f2b4, Func Offset: 0x864
	// Line 2018, Address: 0x13f2b8, Func Offset: 0x868
	// Line 2019, Address: 0x13f2bc, Func Offset: 0x86c
	// Line 2018, Address: 0x13f2c0, Func Offset: 0x870
	// Line 2019, Address: 0x13f2c8, Func Offset: 0x878
	// Line 2020, Address: 0x13f2cc, Func Offset: 0x87c
	// Line 2023, Address: 0x13f2d4, Func Offset: 0x884
	// Line 2024, Address: 0x13f30c, Func Offset: 0x8bc
	// Line 2025, Address: 0x13f31c, Func Offset: 0x8cc
	// Line 2028, Address: 0x13f33c, Func Offset: 0x8ec
	// Line 2029, Address: 0x13f34c, Func Offset: 0x8fc
	// Line 2032, Address: 0x13f360, Func Offset: 0x910
	// Line 2033, Address: 0x13f3a0, Func Offset: 0x950
	// Line 2034, Address: 0x13f3b0, Func Offset: 0x960
	// Line 2037, Address: 0x13f3d0, Func Offset: 0x980
	// Line 2038, Address: 0x13f3e0, Func Offset: 0x990
	// Line 2040, Address: 0x13f3f0, Func Offset: 0x9a0
	// Line 2042, Address: 0x13f3f8, Func Offset: 0x9a8
	// Line 2043, Address: 0x13f3fc, Func Offset: 0x9ac
	// Line 2042, Address: 0x13f400, Func Offset: 0x9b0
	// Line 2043, Address: 0x13f408, Func Offset: 0x9b8
	// Line 2044, Address: 0x13f418, Func Offset: 0x9c8
	// Line 2045, Address: 0x13f420, Func Offset: 0x9d0
	// Line 2049, Address: 0x13f428, Func Offset: 0x9d8
	// Line 2054, Address: 0x13f430, Func Offset: 0x9e0
	// Line 2045, Address: 0x13f438, Func Offset: 0x9e8
	// Line 2055, Address: 0x13f43c, Func Offset: 0x9ec
	// Line 2045, Address: 0x13f440, Func Offset: 0x9f0
	// Line 2055, Address: 0x13f444, Func Offset: 0x9f4
	// Line 2045, Address: 0x13f448, Func Offset: 0x9f8
	// Line 2046, Address: 0x13f460, Func Offset: 0xa10
	// Line 2047, Address: 0x13f46c, Func Offset: 0xa1c
	// Line 2046, Address: 0x13f470, Func Offset: 0xa20
	// Line 2047, Address: 0x13f474, Func Offset: 0xa24
	// Line 2048, Address: 0x13f498, Func Offset: 0xa48
	// Line 2049, Address: 0x13f4b8, Func Offset: 0xa68
	// Line 2048, Address: 0x13f4bc, Func Offset: 0xa6c
	// Line 2049, Address: 0x13f4c0, Func Offset: 0xa70
	// Line 2050, Address: 0x13f4e0, Func Offset: 0xa90
	// Line 2049, Address: 0x13f4e4, Func Offset: 0xa94
	// Line 2050, Address: 0x13f4e8, Func Offset: 0xa98
	// Line 2051, Address: 0x13f504, Func Offset: 0xab4
	// Line 2050, Address: 0x13f508, Func Offset: 0xab8
	// Line 2051, Address: 0x13f50c, Func Offset: 0xabc
	// Line 2052, Address: 0x13f514, Func Offset: 0xac4
	// Line 2051, Address: 0x13f518, Func Offset: 0xac8
	// Line 2052, Address: 0x13f51c, Func Offset: 0xacc
	// Line 2053, Address: 0x13f524, Func Offset: 0xad4
	// Line 2052, Address: 0x13f528, Func Offset: 0xad8
	// Line 2053, Address: 0x13f52c, Func Offset: 0xadc
	// Line 2054, Address: 0x13f534, Func Offset: 0xae4
	// Line 2053, Address: 0x13f538, Func Offset: 0xae8
	// Line 2054, Address: 0x13f53c, Func Offset: 0xaec
	// Line 2055, Address: 0x13f544, Func Offset: 0xaf4
	// Line 2054, Address: 0x13f548, Func Offset: 0xaf8
	// Line 2055, Address: 0x13f550, Func Offset: 0xb00
	// Line 2060, Address: 0x13f558, Func Offset: 0xb08
	// Line 2055, Address: 0x13f55c, Func Offset: 0xb0c
	// Line 2060, Address: 0x13f564, Func Offset: 0xb14
	// Line 2061, Address: 0x13f56c, Func Offset: 0xb1c
	// Line 2060, Address: 0x13f570, Func Offset: 0xb20
	// Line 2061, Address: 0x13f578, Func Offset: 0xb28
	// Line 2062, Address: 0x13f580, Func Offset: 0xb30
	// Line 2064, Address: 0x13f588, Func Offset: 0xb38
	// Line 2063, Address: 0x13f58c, Func Offset: 0xb3c
	// Line 2064, Address: 0x13f590, Func Offset: 0xb40
	// Line 2062, Address: 0x13f594, Func Offset: 0xb44
	// Line 2065, Address: 0x13f5a0, Func Offset: 0xb50
	// Line 2066, Address: 0x13f5a4, Func Offset: 0xb54
	// Line 2067, Address: 0x13f5a8, Func Offset: 0xb58
	// Line 2062, Address: 0x13f5ac, Func Offset: 0xb5c
	// Line 2063, Address: 0x13f5b8, Func Offset: 0xb68
	// Line 2062, Address: 0x13f5bc, Func Offset: 0xb6c
	// Line 2063, Address: 0x13f5c0, Func Offset: 0xb70
	// Line 2064, Address: 0x13f5c8, Func Offset: 0xb78
	// Line 2065, Address: 0x13f5d4, Func Offset: 0xb84
	// Line 2064, Address: 0x13f5d8, Func Offset: 0xb88
	// Line 2065, Address: 0x13f610, Func Offset: 0xbc0
	// Line 2066, Address: 0x13f618, Func Offset: 0xbc8
	// Line 2067, Address: 0x13f624, Func Offset: 0xbd4
	// Line 2068, Address: 0x13f630, Func Offset: 0xbe0
	// Line 2069, Address: 0x13f63c, Func Offset: 0xbec
	// Line 2073, Address: 0x13f650, Func Offset: 0xc00
	// Func End, Address: 0x13f660, Func Offset: 0xc10
    scePrintf("bhCPM2_act_kdu - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x13f660
void bhCPM2_act_kdd()
{
	short ayn;
	int fsnd;
	int flr_no;
	float py;
	int ang[3];
	//_anon35 pos2;
	//_anon35 pos;
	//_anon22* htp;
	// Line 2079, Address: 0x13f660, Func Offset: 0
	// Line 2080, Address: 0x13f670, Func Offset: 0x10
	// Line 2086, Address: 0x13f680, Func Offset: 0x20
	// Line 2080, Address: 0x13f684, Func Offset: 0x24
	// Line 2086, Address: 0x13f688, Func Offset: 0x28
	// Line 2087, Address: 0x13f690, Func Offset: 0x30
	// Line 2089, Address: 0x13f6c4, Func Offset: 0x64
	// Line 2096, Address: 0x13f6d0, Func Offset: 0x70
	// Line 2089, Address: 0x13f6d8, Func Offset: 0x78
	// Line 2090, Address: 0x13f6e0, Func Offset: 0x80
	// Line 2102, Address: 0x13f6e8, Func Offset: 0x88
	// Line 2090, Address: 0x13f6f4, Func Offset: 0x94
	// Line 2091, Address: 0x13f6fc, Func Offset: 0x9c
	// Line 2097, Address: 0x13f700, Func Offset: 0xa0
	// Line 2098, Address: 0x13f704, Func Offset: 0xa4
	// Line 2099, Address: 0x13f708, Func Offset: 0xa8
	// Line 2090, Address: 0x13f70c, Func Offset: 0xac
	// Line 2091, Address: 0x13f718, Func Offset: 0xb8
	// Line 2095, Address: 0x13f720, Func Offset: 0xc0
	// Line 2091, Address: 0x13f724, Func Offset: 0xc4
	// Line 2095, Address: 0x13f730, Func Offset: 0xd0
	// Line 2096, Address: 0x13f738, Func Offset: 0xd8
	// Line 2095, Address: 0x13f73c, Func Offset: 0xdc
	// Line 2096, Address: 0x13f744, Func Offset: 0xe4
	// Line 2097, Address: 0x13f74c, Func Offset: 0xec
	// Line 2096, Address: 0x13f750, Func Offset: 0xf0
	// Line 2097, Address: 0x13f788, Func Offset: 0x128
	// Line 2098, Address: 0x13f790, Func Offset: 0x130
	// Line 2099, Address: 0x13f79c, Func Offset: 0x13c
	// Line 2100, Address: 0x13f7a8, Func Offset: 0x148
	// Line 2101, Address: 0x13f7b4, Func Offset: 0x154
	// Line 2100, Address: 0x13f7b8, Func Offset: 0x158
	// Line 2101, Address: 0x13f7bc, Func Offset: 0x15c
	// Line 2102, Address: 0x13f7c4, Func Offset: 0x164
	// Line 2103, Address: 0x13f804, Func Offset: 0x1a4
	// Line 2105, Address: 0x13f810, Func Offset: 0x1b0
	// Line 2106, Address: 0x13f820, Func Offset: 0x1c0
	// Line 2107, Address: 0x13f834, Func Offset: 0x1d4
	// Line 2108, Address: 0x13f838, Func Offset: 0x1d8
	// Line 2110, Address: 0x13f840, Func Offset: 0x1e0
	// Line 2112, Address: 0x13f844, Func Offset: 0x1e4
	// Line 2113, Address: 0x13f864, Func Offset: 0x204
	// Line 2114, Address: 0x13f868, Func Offset: 0x208
	// Line 2116, Address: 0x13f870, Func Offset: 0x210
	// Line 2117, Address: 0x13f8a4, Func Offset: 0x244
	// Line 2116, Address: 0x13f8ac, Func Offset: 0x24c
	// Line 2117, Address: 0x13f8b4, Func Offset: 0x254
	// Line 2118, Address: 0x13f8b8, Func Offset: 0x258
	// Line 2120, Address: 0x13f8c0, Func Offset: 0x260
	// Line 2122, Address: 0x13f8c4, Func Offset: 0x264
	// Line 2123, Address: 0x13f8e4, Func Offset: 0x284
	// Line 2124, Address: 0x13f8e8, Func Offset: 0x288
	// Line 2126, Address: 0x13f8f0, Func Offset: 0x290
	// Line 2127, Address: 0x13f924, Func Offset: 0x2c4
	// Line 2126, Address: 0x13f92c, Func Offset: 0x2cc
	// Line 2127, Address: 0x13f934, Func Offset: 0x2d4
	// Line 2128, Address: 0x13f938, Func Offset: 0x2d8
	// Line 2130, Address: 0x13f940, Func Offset: 0x2e0
	// Line 2131, Address: 0x13f954, Func Offset: 0x2f4
	// Line 2132, Address: 0x13f974, Func Offset: 0x314
	// Line 2134, Address: 0x13f988, Func Offset: 0x328
	// Line 2135, Address: 0x13f998, Func Offset: 0x338
	// Line 2136, Address: 0x13f9c0, Func Offset: 0x360
	// Line 2140, Address: 0x13f9c8, Func Offset: 0x368
	// Line 2136, Address: 0x13f9d0, Func Offset: 0x370
	// Line 2140, Address: 0x13f9d4, Func Offset: 0x374
	// Line 2137, Address: 0x13f9d8, Func Offset: 0x378
	// Line 2136, Address: 0x13f9dc, Func Offset: 0x37c
	// Line 2137, Address: 0x13f9e0, Func Offset: 0x380
	// Line 2138, Address: 0x13f9e8, Func Offset: 0x388
	// Line 2137, Address: 0x13f9ec, Func Offset: 0x38c
	// Line 2138, Address: 0x13f9f0, Func Offset: 0x390
	// Line 2139, Address: 0x13f9fc, Func Offset: 0x39c
	// Line 2140, Address: 0x13fa08, Func Offset: 0x3a8
	// Line 2141, Address: 0x13fa44, Func Offset: 0x3e4
	// Line 2140, Address: 0x13fa48, Func Offset: 0x3e8
	// Line 2141, Address: 0x13fa4c, Func Offset: 0x3ec
	// Line 2142, Address: 0x13fa58, Func Offset: 0x3f8
	// Line 2143, Address: 0x13fa68, Func Offset: 0x408
	// Line 2144, Address: 0x13fa80, Func Offset: 0x420
	// Line 2145, Address: 0x13fa8c, Func Offset: 0x42c
	// Line 2144, Address: 0x13fa90, Func Offset: 0x430
	// Line 2145, Address: 0x13fa94, Func Offset: 0x434
	// Line 2144, Address: 0x13fa98, Func Offset: 0x438
	// Line 2145, Address: 0x13fa9c, Func Offset: 0x43c
	// Line 2147, Address: 0x13faa4, Func Offset: 0x444
	// Line 2149, Address: 0x13faf8, Func Offset: 0x498
	// Line 2147, Address: 0x13fafc, Func Offset: 0x49c
	// Line 2149, Address: 0x13fb00, Func Offset: 0x4a0
	// Line 2151, Address: 0x13fb0c, Func Offset: 0x4ac
	// Line 2152, Address: 0x13fb24, Func Offset: 0x4c4
	// Line 2153, Address: 0x13fb30, Func Offset: 0x4d0
	// Line 2154, Address: 0x13fb34, Func Offset: 0x4d4
	// Line 2153, Address: 0x13fb38, Func Offset: 0x4d8
	// Line 2152, Address: 0x13fb3c, Func Offset: 0x4dc
	// Line 2154, Address: 0x13fb40, Func Offset: 0x4e0
	// Line 2153, Address: 0x13fb44, Func Offset: 0x4e4
	// Line 2154, Address: 0x13fb4c, Func Offset: 0x4ec
	// Line 2155, Address: 0x13fb60, Func Offset: 0x500
	// Line 2156, Address: 0x13fb68, Func Offset: 0x508
	// Line 2157, Address: 0x13fb7c, Func Offset: 0x51c
	// Line 2158, Address: 0x13fb8c, Func Offset: 0x52c
	// Line 2159, Address: 0x13fb9c, Func Offset: 0x53c
	// Line 2158, Address: 0x13fba0, Func Offset: 0x540
	// Line 2159, Address: 0x13fba8, Func Offset: 0x548
	// Line 2160, Address: 0x13fbb8, Func Offset: 0x558
	// Line 2159, Address: 0x13fbbc, Func Offset: 0x55c
	// Line 2160, Address: 0x13fbcc, Func Offset: 0x56c
	// Line 2161, Address: 0x13fbd8, Func Offset: 0x578
	// Line 2160, Address: 0x13fbdc, Func Offset: 0x57c
	// Line 2161, Address: 0x13fbe4, Func Offset: 0x584
	// Line 2164, Address: 0x13fbec, Func Offset: 0x58c
	// Line 2165, Address: 0x13fc44, Func Offset: 0x5e4
	// Line 2167, Address: 0x13fc58, Func Offset: 0x5f8
	// Line 2165, Address: 0x13fc5c, Func Offset: 0x5fc
	// Line 2167, Address: 0x13fc64, Func Offset: 0x604
	// Line 2168, Address: 0x13fc68, Func Offset: 0x608
	// Line 2171, Address: 0x13fc80, Func Offset: 0x620
	// Line 2172, Address: 0x13fc90, Func Offset: 0x630
	// Line 2173, Address: 0x13fc9c, Func Offset: 0x63c
	// Line 2172, Address: 0x13fca0, Func Offset: 0x640
	// Line 2173, Address: 0x13fca8, Func Offset: 0x648
	// Line 2174, Address: 0x13fcb0, Func Offset: 0x650
	// Line 2175, Address: 0x13fcd8, Func Offset: 0x678
	// Line 2176, Address: 0x13fd24, Func Offset: 0x6c4
	// Line 2175, Address: 0x13fd28, Func Offset: 0x6c8
	// Line 2176, Address: 0x13fd2c, Func Offset: 0x6cc
	// Line 2177, Address: 0x13fd50, Func Offset: 0x6f0
	// Line 2178, Address: 0x13fd5c, Func Offset: 0x6fc
	// Line 2179, Address: 0x13fd6c, Func Offset: 0x70c
	// Line 2180, Address: 0x13fd74, Func Offset: 0x714
	// Line 2185, Address: 0x13fd7c, Func Offset: 0x71c
	// Line 2179, Address: 0x13fd84, Func Offset: 0x724
	// Line 2180, Address: 0x13fd9c, Func Offset: 0x73c
	// Line 2179, Address: 0x13fda0, Func Offset: 0x740
	// Line 2180, Address: 0x13fda4, Func Offset: 0x744
	// Line 2181, Address: 0x13fdc4, Func Offset: 0x764
	// Line 2180, Address: 0x13fdc8, Func Offset: 0x768
	// Line 2181, Address: 0x13fdcc, Func Offset: 0x76c
	// Line 2182, Address: 0x13fde8, Func Offset: 0x788
	// Line 2181, Address: 0x13fdec, Func Offset: 0x78c
	// Line 2182, Address: 0x13fdf0, Func Offset: 0x790
	// Line 2183, Address: 0x13fdf8, Func Offset: 0x798
	// Line 2182, Address: 0x13fdfc, Func Offset: 0x79c
	// Line 2183, Address: 0x13fe00, Func Offset: 0x7a0
	// Line 2184, Address: 0x13fe08, Func Offset: 0x7a8
	// Line 2183, Address: 0x13fe0c, Func Offset: 0x7ac
	// Line 2184, Address: 0x13fe10, Func Offset: 0x7b0
	// Line 2185, Address: 0x13fe18, Func Offset: 0x7b8
	// Line 2184, Address: 0x13fe1c, Func Offset: 0x7bc
	// Line 2185, Address: 0x13fe20, Func Offset: 0x7c0
	// Line 2186, Address: 0x13fe28, Func Offset: 0x7c8
	// Line 2185, Address: 0x13fe2c, Func Offset: 0x7cc
	// Line 2186, Address: 0x13fe34, Func Offset: 0x7d4
	// Line 2187, Address: 0x13fe3c, Func Offset: 0x7dc
	// Line 2186, Address: 0x13fe40, Func Offset: 0x7e0
	// Line 2187, Address: 0x13fe48, Func Offset: 0x7e8
	// Line 2188, Address: 0x13fe50, Func Offset: 0x7f0
	// Line 2190, Address: 0x13fe58, Func Offset: 0x7f8
	// Line 2189, Address: 0x13fe5c, Func Offset: 0x7fc
	// Line 2190, Address: 0x13fe60, Func Offset: 0x800
	// Line 2188, Address: 0x13fe64, Func Offset: 0x804
	// Line 2191, Address: 0x13fe70, Func Offset: 0x810
	// Line 2192, Address: 0x13fe74, Func Offset: 0x814
	// Line 2193, Address: 0x13fe78, Func Offset: 0x818
	// Line 2188, Address: 0x13fe7c, Func Offset: 0x81c
	// Line 2189, Address: 0x13fe88, Func Offset: 0x828
	// Line 2188, Address: 0x13fe8c, Func Offset: 0x82c
	// Line 2189, Address: 0x13fe90, Func Offset: 0x830
	// Line 2190, Address: 0x13fe98, Func Offset: 0x838
	// Line 2191, Address: 0x13fea4, Func Offset: 0x844
	// Line 2190, Address: 0x13fea8, Func Offset: 0x848
	// Line 2191, Address: 0x13fee0, Func Offset: 0x880
	// Line 2192, Address: 0x13fee8, Func Offset: 0x888
	// Line 2193, Address: 0x13fef4, Func Offset: 0x894
	// Line 2194, Address: 0x13ff00, Func Offset: 0x8a0
	// Line 2195, Address: 0x13ff0c, Func Offset: 0x8ac
	// Line 2196, Address: 0x13ff1c, Func Offset: 0x8bc
	// Line 2199, Address: 0x13ff24, Func Offset: 0x8c4
	// Line 2200, Address: 0x13ff64, Func Offset: 0x904
	// Line 2201, Address: 0x13ff74, Func Offset: 0x914
	// Line 2204, Address: 0x13ff94, Func Offset: 0x934
	// Line 2205, Address: 0x13ffa4, Func Offset: 0x944
	// Line 2208, Address: 0x13ffb8, Func Offset: 0x958
	// Line 2209, Address: 0x13fff8, Func Offset: 0x998
	// Line 2210, Address: 0x140008, Func Offset: 0x9a8
	// Line 2213, Address: 0x140028, Func Offset: 0x9c8
	// Line 2214, Address: 0x140038, Func Offset: 0x9d8
	// Line 2218, Address: 0x14004c, Func Offset: 0x9ec
	// Func End, Address: 0x140060, Func Offset: 0xa00
    scePrintf("bhCPM2_act_kdd - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x140060
void bhCPM2_act_dnu()
{
	short ayn;
	// Line 2224, Address: 0x140060, Func Offset: 0
	// Line 2227, Address: 0x14006c, Func Offset: 0xc
	// Line 2228, Address: 0x140078, Func Offset: 0x18
	// Line 2227, Address: 0x14007c, Func Offset: 0x1c
	// Line 2228, Address: 0x140084, Func Offset: 0x24
	// Line 2230, Address: 0x1400b4, Func Offset: 0x54
	// Line 2237, Address: 0x1400c0, Func Offset: 0x60
	// Line 2231, Address: 0x1400c4, Func Offset: 0x64
	// Line 2230, Address: 0x1400cc, Func Offset: 0x6c
	// Line 2231, Address: 0x1400d4, Func Offset: 0x74
	// Line 2237, Address: 0x1400d8, Func Offset: 0x78
	// Line 2238, Address: 0x1400dc, Func Offset: 0x7c
	// Line 2239, Address: 0x1400e0, Func Offset: 0x80
	// Line 2231, Address: 0x1400e4, Func Offset: 0x84
	// Line 2232, Address: 0x1400e8, Func Offset: 0x88
	// Line 2240, Address: 0x1400ec, Func Offset: 0x8c
	// Line 2243, Address: 0x1400f0, Func Offset: 0x90
	// Line 2231, Address: 0x1400f4, Func Offset: 0x94
	// Line 2232, Address: 0x140100, Func Offset: 0xa0
	// Line 2236, Address: 0x140108, Func Offset: 0xa8
	// Line 2232, Address: 0x14010c, Func Offset: 0xac
	// Line 2236, Address: 0x140118, Func Offset: 0xb8
	// Line 2237, Address: 0x140120, Func Offset: 0xc0
	// Line 2236, Address: 0x140124, Func Offset: 0xc4
	// Line 2237, Address: 0x14012c, Func Offset: 0xcc
	// Line 2238, Address: 0x140134, Func Offset: 0xd4
	// Line 2237, Address: 0x140138, Func Offset: 0xd8
	// Line 2238, Address: 0x140170, Func Offset: 0x110
	// Line 2239, Address: 0x140178, Func Offset: 0x118
	// Line 2240, Address: 0x140184, Func Offset: 0x124
	// Line 2241, Address: 0x140190, Func Offset: 0x130
	// Line 2242, Address: 0x14019c, Func Offset: 0x13c
	// Line 2241, Address: 0x1401a0, Func Offset: 0x140
	// Line 2242, Address: 0x1401a4, Func Offset: 0x144
	// Line 2243, Address: 0x1401ac, Func Offset: 0x14c
	// Line 2244, Address: 0x1401b8, Func Offset: 0x158
	// Line 2243, Address: 0x1401bc, Func Offset: 0x15c
	// Line 2244, Address: 0x1401c8, Func Offset: 0x168
	// Line 2246, Address: 0x1401d0, Func Offset: 0x170
	// Line 2247, Address: 0x1401e0, Func Offset: 0x180
	// Line 2249, Address: 0x1401f4, Func Offset: 0x194
	// Line 2251, Address: 0x1401fc, Func Offset: 0x19c
	// Line 2253, Address: 0x140200, Func Offset: 0x1a0
	// Line 2254, Address: 0x140220, Func Offset: 0x1c0
	// Line 2255, Address: 0x140224, Func Offset: 0x1c4
	// Line 2257, Address: 0x14022c, Func Offset: 0x1cc
	// Line 2258, Address: 0x140260, Func Offset: 0x200
	// Line 2257, Address: 0x140268, Func Offset: 0x208
	// Line 2258, Address: 0x140270, Func Offset: 0x210
	// Line 2259, Address: 0x140274, Func Offset: 0x214
	// Line 2261, Address: 0x14027c, Func Offset: 0x21c
	// Line 2263, Address: 0x140280, Func Offset: 0x220
	// Line 2264, Address: 0x1402a0, Func Offset: 0x240
	// Line 2265, Address: 0x1402a4, Func Offset: 0x244
	// Line 2267, Address: 0x1402ac, Func Offset: 0x24c
	// Line 2268, Address: 0x1402e0, Func Offset: 0x280
	// Line 2267, Address: 0x1402e8, Func Offset: 0x288
	// Line 2268, Address: 0x1402f0, Func Offset: 0x290
	// Line 2269, Address: 0x1402f4, Func Offset: 0x294
	// Line 2271, Address: 0x1402fc, Func Offset: 0x29c
	// Line 2272, Address: 0x140308, Func Offset: 0x2a8
	// Line 2271, Address: 0x140310, Func Offset: 0x2b0
	// Line 2272, Address: 0x140318, Func Offset: 0x2b8
	// Line 2273, Address: 0x14031c, Func Offset: 0x2bc
	// Line 2274, Address: 0x140320, Func Offset: 0x2c0
	// Line 2275, Address: 0x140324, Func Offset: 0x2c4
	// Line 2277, Address: 0x140328, Func Offset: 0x2c8
	// Line 2272, Address: 0x14032c, Func Offset: 0x2cc
	// Line 2273, Address: 0x140330, Func Offset: 0x2d0
	// Line 2278, Address: 0x140338, Func Offset: 0x2d8
	// Line 2279, Address: 0x14033c, Func Offset: 0x2dc
	// Line 2273, Address: 0x140340, Func Offset: 0x2e0
	// Line 2274, Address: 0x140344, Func Offset: 0x2e4
	// Line 2275, Address: 0x140350, Func Offset: 0x2f0
	// Line 2276, Address: 0x14035c, Func Offset: 0x2fc
	// Line 2277, Address: 0x140368, Func Offset: 0x308
	// Line 2278, Address: 0x140374, Func Offset: 0x314
	// Line 2277, Address: 0x140378, Func Offset: 0x318
	// Line 2278, Address: 0x140384, Func Offset: 0x324
	// Line 2279, Address: 0x14038c, Func Offset: 0x32c
	// Line 2280, Address: 0x1403a4, Func Offset: 0x344
	// Line 2281, Address: 0x1403b8, Func Offset: 0x358
	// Line 2282, Address: 0x1403c0, Func Offset: 0x360
	// Line 2281, Address: 0x1403c4, Func Offset: 0x364
	// Line 2282, Address: 0x1403c8, Func Offset: 0x368
	// Line 2283, Address: 0x1403d0, Func Offset: 0x370
	// Line 2285, Address: 0x1403d8, Func Offset: 0x378
	// Line 2286, Address: 0x1403f4, Func Offset: 0x394
	// Line 2285, Address: 0x1403f8, Func Offset: 0x398
	// Line 2286, Address: 0x1403fc, Func Offset: 0x39c
	// Line 2288, Address: 0x140408, Func Offset: 0x3a8
	// Line 2289, Address: 0x140448, Func Offset: 0x3e8
	// Line 2290, Address: 0x14044c, Func Offset: 0x3ec
	// Line 2289, Address: 0x140454, Func Offset: 0x3f4
	// Line 2290, Address: 0x140458, Func Offset: 0x3f8
	// Line 2293, Address: 0x140460, Func Offset: 0x400
	// Line 2295, Address: 0x140484, Func Offset: 0x424
	// Line 2298, Address: 0x14049c, Func Offset: 0x43c
	// Line 2295, Address: 0x1404a0, Func Offset: 0x440
	// Line 2298, Address: 0x1404a4, Func Offset: 0x444
	// Line 2299, Address: 0x1404b8, Func Offset: 0x458
	// Line 2301, Address: 0x1404cc, Func Offset: 0x46c
	// Line 2302, Address: 0x1404d8, Func Offset: 0x478
	// Line 2301, Address: 0x1404dc, Func Offset: 0x47c
	// Line 2302, Address: 0x1404e0, Func Offset: 0x480
	// Line 2301, Address: 0x1404e4, Func Offset: 0x484
	// Line 2302, Address: 0x1404ec, Func Offset: 0x48c
	// Line 2303, Address: 0x140500, Func Offset: 0x4a0
	// Line 2304, Address: 0x140504, Func Offset: 0x4a4
	// Line 2307, Address: 0x140510, Func Offset: 0x4b0
	// Line 2303, Address: 0x140518, Func Offset: 0x4b8
	// Line 2312, Address: 0x14051c, Func Offset: 0x4bc
	// Line 2303, Address: 0x140520, Func Offset: 0x4c0
	// Line 2312, Address: 0x140524, Func Offset: 0x4c4
	// Line 2313, Address: 0x140528, Func Offset: 0x4c8
	// Line 2303, Address: 0x140530, Func Offset: 0x4d0
	// Line 2304, Address: 0x140534, Func Offset: 0x4d4
	// Line 2305, Address: 0x14053c, Func Offset: 0x4dc
	// Line 2304, Address: 0x140540, Func Offset: 0x4e0
	// Line 2305, Address: 0x140548, Func Offset: 0x4e8
	// Line 2306, Address: 0x140550, Func Offset: 0x4f0
	// Line 2305, Address: 0x140554, Func Offset: 0x4f4
	// Line 2306, Address: 0x140560, Func Offset: 0x500
	// Line 2307, Address: 0x14057c, Func Offset: 0x51c
	// Line 2306, Address: 0x140580, Func Offset: 0x520
	// Line 2307, Address: 0x140584, Func Offset: 0x524
	// Line 2308, Address: 0x1405a4, Func Offset: 0x544
	// Line 2307, Address: 0x1405a8, Func Offset: 0x548
	// Line 2308, Address: 0x1405ac, Func Offset: 0x54c
	// Line 2309, Address: 0x1405c8, Func Offset: 0x568
	// Line 2308, Address: 0x1405cc, Func Offset: 0x56c
	// Line 2309, Address: 0x1405d0, Func Offset: 0x570
	// Line 2310, Address: 0x1405d8, Func Offset: 0x578
	// Line 2309, Address: 0x1405dc, Func Offset: 0x57c
	// Line 2310, Address: 0x1405e0, Func Offset: 0x580
	// Line 2311, Address: 0x1405e8, Func Offset: 0x588
	// Line 2310, Address: 0x1405ec, Func Offset: 0x58c
	// Line 2311, Address: 0x1405f0, Func Offset: 0x590
	// Line 2312, Address: 0x1405f8, Func Offset: 0x598
	// Line 2311, Address: 0x1405fc, Func Offset: 0x59c
	// Line 2312, Address: 0x140600, Func Offset: 0x5a0
	// Line 2313, Address: 0x140608, Func Offset: 0x5a8
	// Line 2312, Address: 0x14060c, Func Offset: 0x5ac
	// Line 2313, Address: 0x140614, Func Offset: 0x5b4
	// Line 2314, Address: 0x14061c, Func Offset: 0x5bc
	// Line 2313, Address: 0x140620, Func Offset: 0x5c0
	// Line 2314, Address: 0x140628, Func Offset: 0x5c8
	// Line 2315, Address: 0x140630, Func Offset: 0x5d0
	// Line 2314, Address: 0x140634, Func Offset: 0x5d4
	// Line 2315, Address: 0x14063c, Func Offset: 0x5dc
	// Line 2316, Address: 0x140644, Func Offset: 0x5e4
	// Line 2318, Address: 0x14064c, Func Offset: 0x5ec
	// Line 2317, Address: 0x140650, Func Offset: 0x5f0
	// Line 2318, Address: 0x140654, Func Offset: 0x5f4
	// Line 2316, Address: 0x140658, Func Offset: 0x5f8
	// Line 2319, Address: 0x140664, Func Offset: 0x604
	// Line 2320, Address: 0x140668, Func Offset: 0x608
	// Line 2321, Address: 0x14066c, Func Offset: 0x60c
	// Line 2316, Address: 0x140670, Func Offset: 0x610
	// Line 2317, Address: 0x14067c, Func Offset: 0x61c
	// Line 2316, Address: 0x140680, Func Offset: 0x620
	// Line 2317, Address: 0x140684, Func Offset: 0x624
	// Line 2318, Address: 0x14068c, Func Offset: 0x62c
	// Line 2319, Address: 0x140698, Func Offset: 0x638
	// Line 2318, Address: 0x14069c, Func Offset: 0x63c
	// Line 2319, Address: 0x1406d4, Func Offset: 0x674
	// Line 2320, Address: 0x1406dc, Func Offset: 0x67c
	// Line 2321, Address: 0x1406e8, Func Offset: 0x688
	// Line 2322, Address: 0x1406f4, Func Offset: 0x694
	// Line 2323, Address: 0x140700, Func Offset: 0x6a0
	// Line 2336, Address: 0x140714, Func Offset: 0x6b4
	// Func End, Address: 0x140724, Func Offset: 0x6c4
    scePrintf("bhCPM2_act_dnu - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x140730
void bhCPM2_act_dnd()
{
	int ay;
	float py;
	short ayn;
	//_anon22* hp;
	// Line 2342, Address: 0x140730, Func Offset: 0
	// Line 2346, Address: 0x140744, Func Offset: 0x14
	// Line 2347, Address: 0x140750, Func Offset: 0x20
	// Line 2346, Address: 0x140754, Func Offset: 0x24
	// Line 2347, Address: 0x14075c, Func Offset: 0x2c
	// Line 2349, Address: 0x14078c, Func Offset: 0x5c
	// Line 2356, Address: 0x140798, Func Offset: 0x68
	// Line 2350, Address: 0x14079c, Func Offset: 0x6c
	// Line 2349, Address: 0x1407a4, Func Offset: 0x74
	// Line 2350, Address: 0x1407ac, Func Offset: 0x7c
	// Line 2356, Address: 0x1407b0, Func Offset: 0x80
	// Line 2357, Address: 0x1407b4, Func Offset: 0x84
	// Line 2358, Address: 0x1407b8, Func Offset: 0x88
	// Line 2350, Address: 0x1407bc, Func Offset: 0x8c
	// Line 2351, Address: 0x1407c0, Func Offset: 0x90
	// Line 2359, Address: 0x1407c4, Func Offset: 0x94
	// Line 2362, Address: 0x1407c8, Func Offset: 0x98
	// Line 2350, Address: 0x1407cc, Func Offset: 0x9c
	// Line 2351, Address: 0x1407d8, Func Offset: 0xa8
	// Line 2355, Address: 0x1407e0, Func Offset: 0xb0
	// Line 2351, Address: 0x1407e4, Func Offset: 0xb4
	// Line 2355, Address: 0x1407f0, Func Offset: 0xc0
	// Line 2356, Address: 0x1407f8, Func Offset: 0xc8
	// Line 2355, Address: 0x1407fc, Func Offset: 0xcc
	// Line 2356, Address: 0x140804, Func Offset: 0xd4
	// Line 2357, Address: 0x14080c, Func Offset: 0xdc
	// Line 2356, Address: 0x140810, Func Offset: 0xe0
	// Line 2357, Address: 0x140848, Func Offset: 0x118
	// Line 2358, Address: 0x140850, Func Offset: 0x120
	// Line 2359, Address: 0x14085c, Func Offset: 0x12c
	// Line 2360, Address: 0x140868, Func Offset: 0x138
	// Line 2361, Address: 0x140874, Func Offset: 0x144
	// Line 2360, Address: 0x140878, Func Offset: 0x148
	// Line 2361, Address: 0x14087c, Func Offset: 0x14c
	// Line 2362, Address: 0x140884, Func Offset: 0x154
	// Line 2363, Address: 0x140890, Func Offset: 0x160
	// Line 2362, Address: 0x140894, Func Offset: 0x164
	// Line 2363, Address: 0x1408a0, Func Offset: 0x170
	// Line 2365, Address: 0x1408a8, Func Offset: 0x178
	// Line 2366, Address: 0x1408b8, Func Offset: 0x188
	// Line 2368, Address: 0x1408cc, Func Offset: 0x19c
	// Line 2370, Address: 0x1408d4, Func Offset: 0x1a4
	// Line 2372, Address: 0x1408d8, Func Offset: 0x1a8
	// Line 2373, Address: 0x1408f8, Func Offset: 0x1c8
	// Line 2374, Address: 0x1408fc, Func Offset: 0x1cc
	// Line 2376, Address: 0x140904, Func Offset: 0x1d4
	// Line 2377, Address: 0x140938, Func Offset: 0x208
	// Line 2376, Address: 0x140940, Func Offset: 0x210
	// Line 2377, Address: 0x140948, Func Offset: 0x218
	// Line 2378, Address: 0x14094c, Func Offset: 0x21c
	// Line 2380, Address: 0x140954, Func Offset: 0x224
	// Line 2382, Address: 0x140958, Func Offset: 0x228
	// Line 2383, Address: 0x140978, Func Offset: 0x248
	// Line 2384, Address: 0x14097c, Func Offset: 0x24c
	// Line 2386, Address: 0x140984, Func Offset: 0x254
	// Line 2387, Address: 0x1409b8, Func Offset: 0x288
	// Line 2386, Address: 0x1409c0, Func Offset: 0x290
	// Line 2387, Address: 0x1409c8, Func Offset: 0x298
	// Line 2388, Address: 0x1409cc, Func Offset: 0x29c
	// Line 2390, Address: 0x1409d4, Func Offset: 0x2a4
	// Line 2391, Address: 0x1409e0, Func Offset: 0x2b0
	// Line 2390, Address: 0x1409e8, Func Offset: 0x2b8
	// Line 2391, Address: 0x1409f0, Func Offset: 0x2c0
	// Line 2392, Address: 0x1409f4, Func Offset: 0x2c4
	// Line 2393, Address: 0x1409f8, Func Offset: 0x2c8
	// Line 2394, Address: 0x1409fc, Func Offset: 0x2cc
	// Line 2396, Address: 0x140a00, Func Offset: 0x2d0
	// Line 2391, Address: 0x140a04, Func Offset: 0x2d4
	// Line 2392, Address: 0x140a08, Func Offset: 0x2d8
	// Line 2393, Address: 0x140a14, Func Offset: 0x2e4
	// Line 2394, Address: 0x140a20, Func Offset: 0x2f0
	// Line 2395, Address: 0x140a2c, Func Offset: 0x2fc
	// Line 2396, Address: 0x140a38, Func Offset: 0x308
	// Line 2397, Address: 0x140a44, Func Offset: 0x314
	// Line 2396, Address: 0x140a48, Func Offset: 0x318
	// Line 2397, Address: 0x140a54, Func Offset: 0x324
	// Line 2398, Address: 0x140a5c, Func Offset: 0x32c
	// Line 2399, Address: 0x140a64, Func Offset: 0x334
	// Line 2401, Address: 0x140a6c, Func Offset: 0x33c
	// Line 2402, Address: 0x140a88, Func Offset: 0x358
	// Line 2403, Address: 0x140a8c, Func Offset: 0x35c
	// Line 2401, Address: 0x140a94, Func Offset: 0x364
	// Line 2402, Address: 0x140a98, Func Offset: 0x368
	// Line 2403, Address: 0x140aa0, Func Offset: 0x370
	// Line 2405, Address: 0x140aa8, Func Offset: 0x378
	// Line 2408, Address: 0x140ad4, Func Offset: 0x3a4
	// Line 2411, Address: 0x140b0c, Func Offset: 0x3dc
	// Line 2414, Address: 0x140b30, Func Offset: 0x400
	// Line 2419, Address: 0x140b38, Func Offset: 0x408
	// Line 2420, Address: 0x140b3c, Func Offset: 0x40c
	// Line 2424, Address: 0x140b40, Func Offset: 0x410
	// Line 2415, Address: 0x140b44, Func Offset: 0x414
	// Line 2414, Address: 0x140b48, Func Offset: 0x418
	// Line 2419, Address: 0x140b4c, Func Offset: 0x41c
	// Line 2431, Address: 0x140b50, Func Offset: 0x420
	// Line 2417, Address: 0x140b5c, Func Offset: 0x42c
	// Line 2419, Address: 0x140b64, Func Offset: 0x434
	// Line 2420, Address: 0x140b74, Func Offset: 0x444
	// Line 2421, Address: 0x140b88, Func Offset: 0x458
	// Line 2422, Address: 0x140b9c, Func Offset: 0x46c
	// Line 2423, Address: 0x140bb0, Func Offset: 0x480
	// Line 2424, Address: 0x140bc4, Func Offset: 0x494
	// Line 2425, Address: 0x140bd8, Func Offset: 0x4a8
	// Line 2426, Address: 0x140bec, Func Offset: 0x4bc
	// Line 2427, Address: 0x140c00, Func Offset: 0x4d0
	// Line 2428, Address: 0x140c28, Func Offset: 0x4f8
	// Line 2429, Address: 0x140c48, Func Offset: 0x518
	// Line 2430, Address: 0x140c70, Func Offset: 0x540
	// Line 2431, Address: 0x140c94, Func Offset: 0x564
	// Line 2432, Address: 0x140cac, Func Offset: 0x57c
	// Line 2433, Address: 0x140cb4, Func Offset: 0x584
	// Line 2432, Address: 0x140cc0, Func Offset: 0x590
	// Line 2433, Address: 0x140cdc, Func Offset: 0x5ac
	// Line 2434, Address: 0x140cf4, Func Offset: 0x5c4
	// Line 2435, Address: 0x140cfc, Func Offset: 0x5cc
	// Line 2434, Address: 0x140d08, Func Offset: 0x5d8
	// Line 2435, Address: 0x140d28, Func Offset: 0x5f8
	// Line 2437, Address: 0x140d40, Func Offset: 0x610
	// Line 2442, Address: 0x140d48, Func Offset: 0x618
	// Line 2437, Address: 0x140d54, Func Offset: 0x624
	// Line 2438, Address: 0x140d58, Func Offset: 0x628
	// Line 2437, Address: 0x140d5c, Func Offset: 0x62c
	// Line 2438, Address: 0x140d64, Func Offset: 0x634
	// Line 2439, Address: 0x140d88, Func Offset: 0x658
	// Line 2440, Address: 0x140da8, Func Offset: 0x678
	// Line 2441, Address: 0x140dd0, Func Offset: 0x6a0
	// Line 2442, Address: 0x140df4, Func Offset: 0x6c4
	// Line 2443, Address: 0x140e0c, Func Offset: 0x6dc
	// Line 2444, Address: 0x140e14, Func Offset: 0x6e4
	// Line 2443, Address: 0x140e20, Func Offset: 0x6f0
	// Line 2444, Address: 0x140e3c, Func Offset: 0x70c
	// Line 2445, Address: 0x140e54, Func Offset: 0x724
	// Line 2446, Address: 0x140e5c, Func Offset: 0x72c
	// Line 2445, Address: 0x140e68, Func Offset: 0x738
	// Line 2446, Address: 0x140e88, Func Offset: 0x758
	// Line 2456, Address: 0x140ea0, Func Offset: 0x770
	// Line 2457, Address: 0x140eac, Func Offset: 0x77c
	// Line 2458, Address: 0x140eb8, Func Offset: 0x788
	// Line 2459, Address: 0x140ec4, Func Offset: 0x794
	// Line 2463, Address: 0x140ed8, Func Offset: 0x7a8
	// Line 2465, Address: 0x140efc, Func Offset: 0x7cc
	// Line 2468, Address: 0x140f14, Func Offset: 0x7e4
	// Line 2465, Address: 0x140f18, Func Offset: 0x7e8
	// Line 2468, Address: 0x140f1c, Func Offset: 0x7ec
	// Line 2469, Address: 0x140f30, Func Offset: 0x800
	// Line 2471, Address: 0x140f44, Func Offset: 0x814
	// Line 2472, Address: 0x140f50, Func Offset: 0x820
	// Line 2471, Address: 0x140f54, Func Offset: 0x824
	// Line 2472, Address: 0x140f58, Func Offset: 0x828
	// Line 2471, Address: 0x140f5c, Func Offset: 0x82c
	// Line 2472, Address: 0x140f64, Func Offset: 0x834
	// Line 2473, Address: 0x140f78, Func Offset: 0x848
	// Line 2474, Address: 0x140f7c, Func Offset: 0x84c
	// Line 2477, Address: 0x140f88, Func Offset: 0x858
	// Line 2473, Address: 0x140f90, Func Offset: 0x860
	// Line 2483, Address: 0x140f94, Func Offset: 0x864
	// Line 2482, Address: 0x140f98, Func Offset: 0x868
	// Line 2473, Address: 0x140f9c, Func Offset: 0x86c
	// Line 2483, Address: 0x140fa0, Func Offset: 0x870
	// Line 2484, Address: 0x140fa4, Func Offset: 0x874
	// Line 2473, Address: 0x140fac, Func Offset: 0x87c
	// Line 2474, Address: 0x140fb0, Func Offset: 0x880
	// Line 2475, Address: 0x140fb8, Func Offset: 0x888
	// Line 2474, Address: 0x140fbc, Func Offset: 0x88c
	// Line 2475, Address: 0x140fc4, Func Offset: 0x894
	// Line 2476, Address: 0x140fcc, Func Offset: 0x89c
	// Line 2475, Address: 0x140fd0, Func Offset: 0x8a0
	// Line 2476, Address: 0x140fdc, Func Offset: 0x8ac
	// Line 2477, Address: 0x140ff8, Func Offset: 0x8c8
	// Line 2476, Address: 0x140ffc, Func Offset: 0x8cc
	// Line 2477, Address: 0x141000, Func Offset: 0x8d0
	// Line 2478, Address: 0x141020, Func Offset: 0x8f0
	// Line 2477, Address: 0x141024, Func Offset: 0x8f4
	// Line 2478, Address: 0x141028, Func Offset: 0x8f8
	// Line 2479, Address: 0x141044, Func Offset: 0x914
	// Line 2478, Address: 0x141048, Func Offset: 0x918
	// Line 2479, Address: 0x14104c, Func Offset: 0x91c
	// Line 2480, Address: 0x141054, Func Offset: 0x924
	// Line 2479, Address: 0x141058, Func Offset: 0x928
	// Line 2480, Address: 0x14105c, Func Offset: 0x92c
	// Line 2481, Address: 0x141064, Func Offset: 0x934
	// Line 2480, Address: 0x141068, Func Offset: 0x938
	// Line 2481, Address: 0x14106c, Func Offset: 0x93c
	// Line 2482, Address: 0x141074, Func Offset: 0x944
	// Line 2481, Address: 0x141078, Func Offset: 0x948
	// Line 2482, Address: 0x14107c, Func Offset: 0x94c
	// Line 2483, Address: 0x141084, Func Offset: 0x954
	// Line 2484, Address: 0x141090, Func Offset: 0x960
	// Line 2483, Address: 0x141094, Func Offset: 0x964
	// Line 2484, Address: 0x14109c, Func Offset: 0x96c
	// Line 2485, Address: 0x1410a4, Func Offset: 0x974
	// Line 2484, Address: 0x1410a8, Func Offset: 0x978
	// Line 2485, Address: 0x1410b0, Func Offset: 0x980
	// Line 2486, Address: 0x1410b8, Func Offset: 0x988
	// Line 2485, Address: 0x1410bc, Func Offset: 0x98c
	// Line 2486, Address: 0x1410c4, Func Offset: 0x994
	// Line 2487, Address: 0x1410cc, Func Offset: 0x99c
	// Line 2489, Address: 0x1410d4, Func Offset: 0x9a4
	// Line 2488, Address: 0x1410d8, Func Offset: 0x9a8
	// Line 2489, Address: 0x1410dc, Func Offset: 0x9ac
	// Line 2487, Address: 0x1410e0, Func Offset: 0x9b0
	// Line 2490, Address: 0x1410ec, Func Offset: 0x9bc
	// Line 2491, Address: 0x1410f0, Func Offset: 0x9c0
	// Line 2492, Address: 0x1410f4, Func Offset: 0x9c4
	// Line 2487, Address: 0x1410f8, Func Offset: 0x9c8
	// Line 2488, Address: 0x141104, Func Offset: 0x9d4
	// Line 2487, Address: 0x141108, Func Offset: 0x9d8
	// Line 2488, Address: 0x14110c, Func Offset: 0x9dc
	// Line 2489, Address: 0x141114, Func Offset: 0x9e4
	// Line 2490, Address: 0x141120, Func Offset: 0x9f0
	// Line 2489, Address: 0x141124, Func Offset: 0x9f4
	// Line 2490, Address: 0x14115c, Func Offset: 0xa2c
	// Line 2491, Address: 0x141164, Func Offset: 0xa34
	// Line 2492, Address: 0x141170, Func Offset: 0xa40
	// Line 2493, Address: 0x14117c, Func Offset: 0xa4c
	// Line 2494, Address: 0x141188, Func Offset: 0xa58
	// Line 2502, Address: 0x14119c, Func Offset: 0xa6c
	// Func End, Address: 0x1411b4, Func Offset: 0xa84
    scePrintf("bhCPM2_act_dnd - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1411c0
void bhCPM2_act_psh()
{
	short ayn;
	float* trsz;
	// Line 2508, Address: 0x1411c0, Func Offset: 0
	// Line 2512, Address: 0x1411cc, Func Offset: 0xc
	// Line 2513, Address: 0x1411d8, Func Offset: 0x18
	// Line 2512, Address: 0x1411dc, Func Offset: 0x1c
	// Line 2513, Address: 0x1411e4, Func Offset: 0x24
	// Line 2515, Address: 0x141214, Func Offset: 0x54
	// Line 2516, Address: 0x14121c, Func Offset: 0x5c
	// Line 2515, Address: 0x141220, Func Offset: 0x60
	// Line 2516, Address: 0x141224, Func Offset: 0x64
	// Line 2515, Address: 0x14122c, Func Offset: 0x6c
	// Line 2516, Address: 0x141234, Func Offset: 0x74
	// Line 2523, Address: 0x141238, Func Offset: 0x78
	// Line 2517, Address: 0x141240, Func Offset: 0x80
	// Line 2516, Address: 0x141244, Func Offset: 0x84
	// Line 2517, Address: 0x141248, Func Offset: 0x88
	// Line 2524, Address: 0x14124c, Func Offset: 0x8c
	// Line 2525, Address: 0x141250, Func Offset: 0x90
	// Line 2529, Address: 0x141254, Func Offset: 0x94
	// Line 2516, Address: 0x141258, Func Offset: 0x98
	// Line 2517, Address: 0x141260, Func Offset: 0xa0
	// Line 2518, Address: 0x141268, Func Offset: 0xa8
	// Line 2517, Address: 0x14126c, Func Offset: 0xac
	// Line 2518, Address: 0x141278, Func Offset: 0xb8
	// Line 2522, Address: 0x141280, Func Offset: 0xc0
	// Line 2518, Address: 0x141284, Func Offset: 0xc4
	// Line 2522, Address: 0x141290, Func Offset: 0xd0
	// Line 2523, Address: 0x141298, Func Offset: 0xd8
	// Line 2522, Address: 0x14129c, Func Offset: 0xdc
	// Line 2523, Address: 0x1412a4, Func Offset: 0xe4
	// Line 2524, Address: 0x1412ac, Func Offset: 0xec
	// Line 2523, Address: 0x1412b0, Func Offset: 0xf0
	// Line 2524, Address: 0x1412e8, Func Offset: 0x128
	// Line 2525, Address: 0x1412f0, Func Offset: 0x130
	// Line 2526, Address: 0x1412fc, Func Offset: 0x13c
	// Line 2527, Address: 0x141308, Func Offset: 0x148
	// Line 2528, Address: 0x141314, Func Offset: 0x154
	// Line 2527, Address: 0x141318, Func Offset: 0x158
	// Line 2528, Address: 0x14131c, Func Offset: 0x15c
	// Line 2529, Address: 0x141324, Func Offset: 0x164
	// Line 2530, Address: 0x141330, Func Offset: 0x170
	// Line 2529, Address: 0x141334, Func Offset: 0x174
	// Line 2530, Address: 0x141340, Func Offset: 0x180
	// Line 2532, Address: 0x141348, Func Offset: 0x188
	// Line 2533, Address: 0x141358, Func Offset: 0x198
	// Line 2535, Address: 0x14136c, Func Offset: 0x1ac
	// Line 2537, Address: 0x141374, Func Offset: 0x1b4
	// Line 2539, Address: 0x141378, Func Offset: 0x1b8
	// Line 2541, Address: 0x141398, Func Offset: 0x1d8
	// Line 2543, Address: 0x1413a0, Func Offset: 0x1e0
	// Line 2544, Address: 0x1413d4, Func Offset: 0x214
	// Line 2543, Address: 0x1413dc, Func Offset: 0x21c
	// Line 2544, Address: 0x1413e4, Func Offset: 0x224
	// Line 2545, Address: 0x1413e8, Func Offset: 0x228
	// Line 2547, Address: 0x1413f0, Func Offset: 0x230
	// Line 2549, Address: 0x1413f4, Func Offset: 0x234
	// Line 2551, Address: 0x141414, Func Offset: 0x254
	// Line 2553, Address: 0x14141c, Func Offset: 0x25c
	// Line 2554, Address: 0x141450, Func Offset: 0x290
	// Line 2553, Address: 0x141458, Func Offset: 0x298
	// Line 2554, Address: 0x141460, Func Offset: 0x2a0
	// Line 2555, Address: 0x141464, Func Offset: 0x2a4
	// Line 2557, Address: 0x14146c, Func Offset: 0x2ac
	// Line 2558, Address: 0x141474, Func Offset: 0x2b4
	// Line 2559, Address: 0x141480, Func Offset: 0x2c0
	// Line 2560, Address: 0x141484, Func Offset: 0x2c4
	// Line 2562, Address: 0x141488, Func Offset: 0x2c8
	// Line 2558, Address: 0x14148c, Func Offset: 0x2cc
	// Line 2559, Address: 0x141490, Func Offset: 0x2d0
	// Line 2560, Address: 0x14149c, Func Offset: 0x2dc
	// Line 2561, Address: 0x1414a8, Func Offset: 0x2e8
	// Line 2562, Address: 0x1414b4, Func Offset: 0x2f4
	// Line 2563, Address: 0x1414c0, Func Offset: 0x300
	// Line 2562, Address: 0x1414c4, Func Offset: 0x304
	// Line 2563, Address: 0x1414d0, Func Offset: 0x310
	// Line 2564, Address: 0x1414d4, Func Offset: 0x314
	// Line 2566, Address: 0x1414dc, Func Offset: 0x31c
	// Line 2567, Address: 0x1414e4, Func Offset: 0x324
	// Line 2566, Address: 0x1414ec, Func Offset: 0x32c
	// Line 2567, Address: 0x1414f4, Func Offset: 0x334
	// Line 2568, Address: 0x141508, Func Offset: 0x348
	// Line 2569, Address: 0x141510, Func Offset: 0x350
	// Line 2570, Address: 0x14151c, Func Offset: 0x35c
	// Line 2571, Address: 0x141520, Func Offset: 0x360
	// Line 2573, Address: 0x141524, Func Offset: 0x364
	// Line 2569, Address: 0x141528, Func Offset: 0x368
	// Line 2570, Address: 0x14152c, Func Offset: 0x36c
	// Line 2571, Address: 0x141538, Func Offset: 0x378
	// Line 2572, Address: 0x141544, Func Offset: 0x384
	// Line 2573, Address: 0x141550, Func Offset: 0x390
	// Line 2574, Address: 0x14155c, Func Offset: 0x39c
	// Line 2575, Address: 0x141578, Func Offset: 0x3b8
	// Line 2577, Address: 0x141584, Func Offset: 0x3c4
	// Line 2579, Address: 0x14158c, Func Offset: 0x3cc
	// Line 2580, Address: 0x141594, Func Offset: 0x3d4
	// Line 2579, Address: 0x14159c, Func Offset: 0x3dc
	// Line 2580, Address: 0x1415a4, Func Offset: 0x3e4
	// Line 2581, Address: 0x1415b8, Func Offset: 0x3f8
	// Line 2582, Address: 0x1415d4, Func Offset: 0x414
	// Line 2584, Address: 0x1415e0, Func Offset: 0x420
	// Line 2585, Address: 0x141604, Func Offset: 0x444
	// Line 2586, Address: 0x141610, Func Offset: 0x450
	// Line 2585, Address: 0x141614, Func Offset: 0x454
	// Line 2586, Address: 0x141628, Func Offset: 0x468
	// Line 2587, Address: 0x141634, Func Offset: 0x474
	// Line 2589, Address: 0x14163c, Func Offset: 0x47c
	// Line 2590, Address: 0x141648, Func Offset: 0x488
	// Line 2589, Address: 0x141650, Func Offset: 0x490
	// Line 2590, Address: 0x141658, Func Offset: 0x498
	// Line 2591, Address: 0x14165c, Func Offset: 0x49c
	// Line 2592, Address: 0x141660, Func Offset: 0x4a0
	// Line 2593, Address: 0x141664, Func Offset: 0x4a4
	// Line 2590, Address: 0x141668, Func Offset: 0x4a8
	// Line 2591, Address: 0x14166c, Func Offset: 0x4ac
	// Line 2594, Address: 0x141674, Func Offset: 0x4b4
	// Line 2596, Address: 0x141678, Func Offset: 0x4b8
	// Line 2591, Address: 0x14167c, Func Offset: 0x4bc
	// Line 2592, Address: 0x141680, Func Offset: 0x4c0
	// Line 2593, Address: 0x14168c, Func Offset: 0x4cc
	// Line 2594, Address: 0x141698, Func Offset: 0x4d8
	// Line 2595, Address: 0x1416a4, Func Offset: 0x4e4
	// Line 2596, Address: 0x1416b4, Func Offset: 0x4f4
	// Line 2595, Address: 0x1416b8, Func Offset: 0x4f8
	// Line 2596, Address: 0x1416d8, Func Offset: 0x518
	// Line 2597, Address: 0x1416dc, Func Offset: 0x51c
	// Line 2599, Address: 0x1416e4, Func Offset: 0x524
	// Line 2600, Address: 0x1416ec, Func Offset: 0x52c
	// Line 2601, Address: 0x141704, Func Offset: 0x544
	// Line 2602, Address: 0x141708, Func Offset: 0x548
	// Line 2603, Address: 0x141710, Func Offset: 0x550
	// Line 2604, Address: 0x141718, Func Offset: 0x558
	// Line 2602, Address: 0x141720, Func Offset: 0x560
	// Line 2603, Address: 0x141724, Func Offset: 0x564
	// Line 2604, Address: 0x141730, Func Offset: 0x570
	// Line 2603, Address: 0x141734, Func Offset: 0x574
	// Line 2604, Address: 0x14173c, Func Offset: 0x57c
	// Line 2609, Address: 0x14175c, Func Offset: 0x59c
	// Func End, Address: 0x14176c, Func Offset: 0x5ac
    scePrintf("bhCPM2_act_psh - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCPM2_act_cro()
{
    sys->st_flg |= 0x4;
    
    switch (plp->mode3)
    {
    case 0:
        plp->flg   |= 0x10000;
        plp->stflg |= 0x10000;
        
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
        
        plp->flg2 |= 0x1;
        
        plp->mtn_no = 45;
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->mode3++;
    case 1:
        if (((int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 6)) 
        {
            plp->flg &= ~0x8;
        }
         
        if ((plp->flg & 0x400000))
        {
            plp->flg   &= ~0x10000;
            plp->stflg &= ~0x10000;
            
            plp->mtn_add = 0;
            
            sys->st_flg &= ~0x4;
            sys->cb_flg |= 0x10;
        }
    }
}

// 100% matching!
void bhCPM2_act_hsu()
{
	ATR_WORK* htp;
    short ayn;

    htp = sys->pl_htp;
    
    sys->st_flg |= 0x4;
    
    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0x28C0008;
        
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
        
        plp->flg2 |= 0x1;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][1];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->frm_no = 0;
        
        plp->ayp = -((int)(182.04445f * (htp->prm1 * 90)) & 0xFFFF);
        
        ayn = plp->ay;
        
        if ((short)((short)plp->ayp - ayn) >= 0) 
        {
            plp->mode3 = 2;
        }
        else
        {
            plp->mode3 = 1;
        }
        
        break;
    case 1:      
        ayn = plp->ay;
        
        if (ABS(((short)plp->ayp - ayn)) < 1310)
        {
            plp->mode3 = 3;
        }
        else
        {
            plp->ay -= (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
            plp->mtn_add = -65536;
        }
        
        break;
    case 2:         
        ayn = plp->ay;
        
        if (ABS(((short)plp->ayp - ayn)) < 1310)
        {
            plp->mode3 = 3;
        }
        else
        {
            plp->ay += (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
            plp->mtn_add = 65536;
        }
        
        break;
    case 3:
        plp->flg &= ~0x4C0000;
        
        plp->mtn_no = 62;
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        plp->ay = -((int)(182.04445f * (htp->prm1 * 90)) & 0xFFFF);
        
        plp->ct0 = (htp->prm2 / 2) - 2;
        
        plp->mode3 = 4;
        
        plp->px = htp->px + (0.5f * htp->w);
        plp->pz = htp->pz + (0.5f * htp->d);
        
        switch (htp->prm1)
        {  
        case 0:
            plp->pz += 5.0f;
            break;
        case 1:
            plp->px -= 5.0f;
            break;
        case 2:
            plp->pz -= 5.0f;
            break;
        case 3:
            plp->px += 5.0f; 
            break;
        }
        
        break;
    case 4:
        if ((plp->frm_no / 65536) == 0)
        {
            plp->px = plp->mlwP->owP->mtx[12];
            plp->pz = plp->mlwP->owP->mtx[14];
            plp->py = plp->mlwP->owP->mtx[13];
            
            plp->mode3 = 5;
            
            plp->mtn_no = 63;
            plp->frm_no = 0;
        }
        
        break;
    case 5:
        plp->flg |= 0x200000;
        
        if ((plp->flg & 0x400000)) 
        {
            plp->py = plp->mlwP->owP->mtx[13];
            
            plp->frm_no = 0;
            
            plp->ct0--;
            
            if (plp->ct0 <= 0) 
            {
                plp->px = plp->mlwP->owP->mtx[12];
                plp->pz = plp->mlwP->owP->mtx[14];
                
                plp->mode3 = 6;
                
                plp->mtn_no = 64;
                plp->frm_no = 0;
            }
        }
        
        break;
    case 6:
        if ((plp->frm_no / 65536) == 0) 
        {
            bhClrUseKaidanFlag(plp);
            
            plp->px = plp->mlwP->owP->mtx[12];
            plp->py = htp->py + (4.0f * htp->prm2);
            plp->pz = plp->mlwP->owP->mtx[14];
            
            ((EXP_WORK*)plp->exp0)->bpx = ((EXP_WORK*)plp->exp0)->bpxb = plp->px;
            ((EXP_WORK*)plp->exp0)->bpy = ((EXP_WORK*)plp->exp0)->bpyb = 12.5f + plp->py;
            ((EXP_WORK*)plp->exp0)->bpz = ((EXP_WORK*)plp->exp0)->bpzb = plp->pz;
            
            plp->pxb = plp->px;
            plp->pyb = plp->py;
            plp->pzb = plp->pz;
            
            plp->stflg &= ~0x80010010;
            plp->flg   &= ~0xD0400;
            
            plp->flg |= 0x118;
            
            bhSetFloorNum(plp);
            
            plp->py = rom->grand[plp->flr_no + 2];
            
            *(int*)&plp->mode0 = 1;
            
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
            
            plp->hokan_rate  = 49152;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mtn_md |= 0x100;
        }

        break;
    }
}

// 100% matching!
void bhCPM1_act_atk()
{
    sys->st_flg |= 0x4;
    plp->stflg |= 0x10000;
    
    if ((plp->flg2 & 0x400)) 
    {
        plp->flg &= ~0x2800000;
        plp->flg2 &= ~0x400;
    }
    else 
    {
        plp->flg &= ~0x2A00000;
    }
    
    plp->flg2 &= ~0x1;
    
    if (!(sys->gm_flg & 0x40)) 
    {
        ((EXP_WORK*)plp->exp0)->rtspd = 1.0f;
    }
    else 
    {
        if ((sys->pad_on & 0xC)) 
        {
            ((EXP_WORK*)plp->exp0)->rtspd = 0.0078125f * fabsf(sys->pad_dx);
        }
        else 
        {
            ((EXP_WORK*)plp->exp0)->rtspd = 0.0078125f * fabsf(sys->pad_ax);
        }
    }
    
    if ((WpnTab[plp->wpnr_no].flg & 0x800)) 
    {
        if (plp->mode2 == 64) 
        {
            plp->mode2 = 164;
        }
        
        if (plp->mode2 == 69) 
        {
            plp->mode2 = 169;
        }
    }
    
    switch (plp->mode2)
    {
    case 64:
        bhCPM2_act_suw();
        break;
    case 65:
        bhCPM2_act_wpn();
        break;
    case 66:
        bhCPM2_act_wpn();
        break;
    case 67:
        bhCPM2_act_wpn();
        break;
    case 68:
        bhCPM2_act_wre();
        break;
    case 69:
        bhCPM2_act_atk();
        break;
    case 70:
        bhCPM2_act_rld();
        break;
    case 71:
        bhCPM2_act_scp();
        break;
    case 72:
        bhCPM2_act_knf();
        break;
    case 164:
        bhCPM2_act_suw_pch();
        break;
    case 169:
        bhCPM2_act_atk_pch();
        break;
    case 197:
        bhCPM2_act_wsc_pch();
        break;
    }
}

// 100% matching!
void bhCPM2_act_hsd()
{
	ATR_WORK* htp;
    short ayn;

    htp = sys->pl_htp;
    
    sys->st_flg |= 0x4;
    
    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0x28C0008;
        
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
        
        plp->flg2 |= 0x1;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][1];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->frm_no = 0;
        
        plp->ayp = 32768 - ((int)(182.04445f * (htp->prm1 * 90)) & 0xFFFF);
        
        ayn = plp->ay;
        
        if ((short)((short)plp->ayp - ayn) >= 0) 
        {
            plp->mode3 = 2;
        }
        else
        {
            plp->mode3 = 1;
        }
        
        break;
    case 1:      
        ayn = plp->ay;
        
        if (ABS(((short)plp->ayp - ayn)) < 1310)
        {
            plp->mode3 = 3;
        }
        else
        {
            plp->ay -= (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
            plp->mtn_add = -65536;
        }
        
        break;
    case 2:         
        ayn = plp->ay;
        
        if (ABS(((short)plp->ayp - ayn)) < 1310)
        {
            plp->mode3 = 3;
        }
        else
        {
            plp->ay += (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
            plp->mtn_add = 65536;
        }
        
        break;
    case 3:
        plp->flg &= ~0x4C0000;
        
        plp->mtn_no = 65;
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        plp->ay = 32768 - ((int)(182.04445f * (htp->prm1 * 90)) & 0xFFFF);
        
        plp->ct0 = (htp->prm2 / 2) - 2;
        
        plp->mode3 = 4;
        
        plp->px = htp->px + (0.5f * htp->w);
        plp->pz = htp->pz + (0.5f * htp->d);
        
        switch (htp->prm1)
        {  
        case 0:
            plp->pz += 0.5f;
            break;
        case 1:
            plp->px -= 0.5f;
            break;
        case 2:
            plp->pz -= 0.5f;
            break;
        case 3:
            plp->px += 0.5f;
            break;
        }
        
        break;
    case 4:
        if ((plp->frm_no / 65536) == 0)
        {
            plp->px = plp->mlwP->owP->mtx[12];
            plp->pz = plp->mlwP->owP->mtx[14];
            plp->py = plp->mlwP->owP->mtx[13];
            
            plp->mode3 = 5;
            
            plp->mtn_no = 66;
            plp->frm_no = 0;
        }
        
        break;
    case 5:
        plp->flg |= 0x200000;
        
        if ((plp->frm_no / 65536) == 0) 
        {
            plp->py = plp->mlwP->owP->mtx[13];
            
            plp->frm_no = 65536;
            
            plp->ct0--;
            
            if (plp->ct0 <= 0) 
            {
                plp->px = plp->mlwP->owP->mtx[12];
                plp->pz = plp->mlwP->owP->mtx[14];
                
                plp->mode3 = 6;
                
                plp->mtn_no = 67;
                plp->frm_no = 0;
            }
        }
        
        break;
    case 6:
        if ((plp->frm_no / 65536) == 0) 
        {
            bhClrUseKaidanFlag(plp);
            
            plp->px = plp->mlwP->owP->mtx[12];
            plp->py = htp->py - (4.0f * htp->prm2);
            plp->pz = plp->mlwP->owP->mtx[14];
            
            ((EXP_WORK*)plp->exp0)->bpx = ((EXP_WORK*)plp->exp0)->bpxb = plp->px;
            ((EXP_WORK*)plp->exp0)->bpy = ((EXP_WORK*)plp->exp0)->bpyb = 12.5f + plp->py;
            ((EXP_WORK*)plp->exp0)->bpz = ((EXP_WORK*)plp->exp0)->bpzb = plp->pz;
            
            plp->pxb = plp->px;
            plp->pyb = plp->py;
            plp->pzb = plp->pz;
            
            plp->stflg &= ~0x80010010;
            plp->flg   &= ~0xD0400;
            
            plp->flg |= 0x118;
            
            bhSetFloorNum(plp);
            
            plp->py = rom->grand[plp->flr_no + 2];
            
            *(int*)&plp->mode0 = 1;
            
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
            
            plp->hokan_rate  = 49152;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mtn_md |= 0x100;
        }

        break;
    }
}

// 
// Start address: 0x142a20
void bhCPM2_act_rpsh()
{
	short ayn;
	// Line 2964, Address: 0x142a20, Func Offset: 0
	// Line 2966, Address: 0x142a2c, Func Offset: 0xc
	// Line 2967, Address: 0x142a38, Func Offset: 0x18
	// Line 2966, Address: 0x142a3c, Func Offset: 0x1c
	// Line 2967, Address: 0x142a44, Func Offset: 0x24
	// Line 2969, Address: 0x142a74, Func Offset: 0x54
	// Line 2970, Address: 0x142a7c, Func Offset: 0x5c
	// Line 2969, Address: 0x142a80, Func Offset: 0x60
	// Line 2970, Address: 0x142a84, Func Offset: 0x64
	// Line 2969, Address: 0x142a8c, Func Offset: 0x6c
	// Line 2970, Address: 0x142a94, Func Offset: 0x74
	// Line 2977, Address: 0x142a98, Func Offset: 0x78
	// Line 2971, Address: 0x142a9c, Func Offset: 0x7c
	// Line 2977, Address: 0x142aa0, Func Offset: 0x80
	// Line 2970, Address: 0x142aa4, Func Offset: 0x84
	// Line 2971, Address: 0x142aa8, Func Offset: 0x88
	// Line 2978, Address: 0x142aac, Func Offset: 0x8c
	// Line 2979, Address: 0x142ab0, Func Offset: 0x90
	// Line 2970, Address: 0x142ab4, Func Offset: 0x94
	// Line 2971, Address: 0x142abc, Func Offset: 0x9c
	// Line 2972, Address: 0x142ac4, Func Offset: 0xa4
	// Line 2971, Address: 0x142ac8, Func Offset: 0xa8
	// Line 2972, Address: 0x142ad4, Func Offset: 0xb4
	// Line 2976, Address: 0x142adc, Func Offset: 0xbc
	// Line 2972, Address: 0x142ae0, Func Offset: 0xc0
	// Line 2976, Address: 0x142aec, Func Offset: 0xcc
	// Line 2977, Address: 0x142af4, Func Offset: 0xd4
	// Line 2976, Address: 0x142af8, Func Offset: 0xd8
	// Line 2977, Address: 0x142b00, Func Offset: 0xe0
	// Line 2978, Address: 0x142b08, Func Offset: 0xe8
	// Line 2977, Address: 0x142b0c, Func Offset: 0xec
	// Line 2978, Address: 0x142b44, Func Offset: 0x124
	// Line 2979, Address: 0x142b4c, Func Offset: 0x12c
	// Line 2980, Address: 0x142b58, Func Offset: 0x138
	// Line 2981, Address: 0x142b64, Func Offset: 0x144
	// Line 2982, Address: 0x142b70, Func Offset: 0x150
	// Line 2981, Address: 0x142b74, Func Offset: 0x154
	// Line 2982, Address: 0x142b78, Func Offset: 0x158
	// Line 2983, Address: 0x142b80, Func Offset: 0x160
	// Line 2984, Address: 0x142b8c, Func Offset: 0x16c
	// Line 2983, Address: 0x142b90, Func Offset: 0x170
	// Line 2984, Address: 0x142b94, Func Offset: 0x174
	// Line 2986, Address: 0x142b9c, Func Offset: 0x17c
	// Line 2987, Address: 0x142bac, Func Offset: 0x18c
	// Line 2989, Address: 0x142bc0, Func Offset: 0x1a0
	// Line 2991, Address: 0x142bc8, Func Offset: 0x1a8
	// Line 2993, Address: 0x142bcc, Func Offset: 0x1ac
	// Line 2995, Address: 0x142bec, Func Offset: 0x1cc
	// Line 2997, Address: 0x142bf4, Func Offset: 0x1d4
	// Line 2998, Address: 0x142c28, Func Offset: 0x208
	// Line 2997, Address: 0x142c30, Func Offset: 0x210
	// Line 2998, Address: 0x142c38, Func Offset: 0x218
	// Line 2999, Address: 0x142c3c, Func Offset: 0x21c
	// Line 3001, Address: 0x142c44, Func Offset: 0x224
	// Line 3003, Address: 0x142c48, Func Offset: 0x228
	// Line 3005, Address: 0x142c68, Func Offset: 0x248
	// Line 3007, Address: 0x142c70, Func Offset: 0x250
	// Line 3008, Address: 0x142ca4, Func Offset: 0x284
	// Line 3007, Address: 0x142cac, Func Offset: 0x28c
	// Line 3008, Address: 0x142cb4, Func Offset: 0x294
	// Line 3009, Address: 0x142cb8, Func Offset: 0x298
	// Line 3011, Address: 0x142cc0, Func Offset: 0x2a0
	// Line 3013, Address: 0x142cc8, Func Offset: 0x2a8
	// Line 3014, Address: 0x142ccc, Func Offset: 0x2ac
	// Line 3015, Address: 0x142cd0, Func Offset: 0x2b0
	// Line 3011, Address: 0x142cd4, Func Offset: 0x2b4
	// Line 3012, Address: 0x142ce4, Func Offset: 0x2c4
	// Line 3013, Address: 0x142cf0, Func Offset: 0x2d0
	// Line 3014, Address: 0x142cfc, Func Offset: 0x2dc
	// Line 3015, Address: 0x142d08, Func Offset: 0x2e8
	// Line 3016, Address: 0x142d14, Func Offset: 0x2f4
	// Line 3017, Address: 0x142d20, Func Offset: 0x300
	// Line 3018, Address: 0x142d2c, Func Offset: 0x30c
	// Line 3017, Address: 0x142d30, Func Offset: 0x310
	// Line 3018, Address: 0x142d34, Func Offset: 0x314
	// Line 3019, Address: 0x142d38, Func Offset: 0x318
	// Line 3021, Address: 0x142d40, Func Offset: 0x320
	// Line 3022, Address: 0x142d48, Func Offset: 0x328
	// Line 3021, Address: 0x142d50, Func Offset: 0x330
	// Line 3022, Address: 0x142d58, Func Offset: 0x338
	// Line 3023, Address: 0x142d6c, Func Offset: 0x34c
	// Line 3024, Address: 0x142d70, Func Offset: 0x350
	// Line 3025, Address: 0x142d7c, Func Offset: 0x35c
	// Line 3026, Address: 0x142d80, Func Offset: 0x360
	// Line 3028, Address: 0x142d84, Func Offset: 0x364
	// Line 3024, Address: 0x142d88, Func Offset: 0x368
	// Line 3025, Address: 0x142d8c, Func Offset: 0x36c
	// Line 3029, Address: 0x142d94, Func Offset: 0x374
	// Line 3025, Address: 0x142d98, Func Offset: 0x378
	// Line 3026, Address: 0x142d9c, Func Offset: 0x37c
	// Line 3027, Address: 0x142da8, Func Offset: 0x388
	// Line 3028, Address: 0x142db4, Func Offset: 0x394
	// Line 3029, Address: 0x142dbc, Func Offset: 0x39c
	// Line 3030, Address: 0x142dc4, Func Offset: 0x3a4
	// Line 3032, Address: 0x142dd0, Func Offset: 0x3b0
	// Line 3034, Address: 0x142dd8, Func Offset: 0x3b8
	// Line 3035, Address: 0x142de0, Func Offset: 0x3c0
	// Line 3034, Address: 0x142de8, Func Offset: 0x3c8
	// Line 3035, Address: 0x142df0, Func Offset: 0x3d0
	// Line 3036, Address: 0x142e04, Func Offset: 0x3e4
	// Line 3037, Address: 0x142e10, Func Offset: 0x3f0
	// Line 3039, Address: 0x142e1c, Func Offset: 0x3fc
	// Line 3040, Address: 0x142e3c, Func Offset: 0x41c
	// Line 3042, Address: 0x142e44, Func Offset: 0x424
	// Line 3044, Address: 0x142e4c, Func Offset: 0x42c
	// Line 3045, Address: 0x142e58, Func Offset: 0x438
	// Line 3046, Address: 0x142e5c, Func Offset: 0x43c
	// Line 3047, Address: 0x142e60, Func Offset: 0x440
	// Line 3044, Address: 0x142e64, Func Offset: 0x444
	// Line 3045, Address: 0x142e6c, Func Offset: 0x44c
	// Line 3048, Address: 0x142e70, Func Offset: 0x450
	// Line 3050, Address: 0x142e74, Func Offset: 0x454
	// Line 3045, Address: 0x142e78, Func Offset: 0x458
	// Line 3046, Address: 0x142e7c, Func Offset: 0x45c
	// Line 3047, Address: 0x142e88, Func Offset: 0x468
	// Line 3048, Address: 0x142e94, Func Offset: 0x474
	// Line 3049, Address: 0x142ea0, Func Offset: 0x480
	// Line 3050, Address: 0x142eb0, Func Offset: 0x490
	// Line 3049, Address: 0x142eb4, Func Offset: 0x494
	// Line 3050, Address: 0x142ed4, Func Offset: 0x4b4
	// Line 3051, Address: 0x142ed8, Func Offset: 0x4b8
	// Line 3053, Address: 0x142ee0, Func Offset: 0x4c0
	// Line 3054, Address: 0x142ef0, Func Offset: 0x4d0
	// Line 3055, Address: 0x142ef4, Func Offset: 0x4d4
	// Line 3057, Address: 0x142efc, Func Offset: 0x4dc
	// Line 3055, Address: 0x142f04, Func Offset: 0x4e4
	// Line 3056, Address: 0x142f08, Func Offset: 0x4e8
	// Line 3055, Address: 0x142f0c, Func Offset: 0x4ec
	// Line 3056, Address: 0x142f10, Func Offset: 0x4f0
	// Line 3057, Address: 0x142f18, Func Offset: 0x4f8
	// Line 3062, Address: 0x142f2c, Func Offset: 0x50c
	// Func End, Address: 0x142f3c, Func Offset: 0x51c
    scePrintf("bhCPM2_act_rpsh - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x142f40
void bhCPM1_act_atk()
{
	// Line 3068, Address: 0x142f40, Func Offset: 0
	// Line 3069, Address: 0x142f48, Func Offset: 0x8
	// Line 3070, Address: 0x142f50, Func Offset: 0x10
	// Line 3069, Address: 0x142f54, Func Offset: 0x14
	// Line 3070, Address: 0x142f58, Func Offset: 0x18
	// Line 3069, Address: 0x142f5c, Func Offset: 0x1c
	// Line 3070, Address: 0x142f64, Func Offset: 0x24
	// Line 3071, Address: 0x142f6c, Func Offset: 0x2c
	// Line 3070, Address: 0x142f70, Func Offset: 0x30
	// Line 3071, Address: 0x142f78, Func Offset: 0x38
	// Line 3072, Address: 0x142f8c, Func Offset: 0x4c
	// Line 3073, Address: 0x142f98, Func Offset: 0x58
	// Line 3072, Address: 0x142fa0, Func Offset: 0x60
	// Line 3073, Address: 0x142fa8, Func Offset: 0x68
	// Line 3074, Address: 0x142fb4, Func Offset: 0x74
	// Line 3075, Address: 0x142fbc, Func Offset: 0x7c
	// Line 3077, Address: 0x142fd0, Func Offset: 0x90
	// Line 3079, Address: 0x142fe0, Func Offset: 0xa0
	// Line 3077, Address: 0x142fe4, Func Offset: 0xa4
	// Line 3079, Address: 0x142fec, Func Offset: 0xac
	// Line 3081, Address: 0x143000, Func Offset: 0xc0
	// Line 3082, Address: 0x143010, Func Offset: 0xd0
	// Line 3085, Address: 0x143018, Func Offset: 0xd8
	// Line 3087, Address: 0x143030, Func Offset: 0xf0
	// Line 3088, Address: 0x143060, Func Offset: 0x120
	// Line 3090, Address: 0x143068, Func Offset: 0x128
	// Line 3103, Address: 0x14309c, Func Offset: 0x15c
	// Line 3104, Address: 0x1430d8, Func Offset: 0x198
	// Line 3105, Address: 0x1430f0, Func Offset: 0x1b0
	// Line 3108, Address: 0x143114, Func Offset: 0x1d4
	// Line 3110, Address: 0x1431b8, Func Offset: 0x278
	// Line 3111, Address: 0x1431c0, Func Offset: 0x280
	// Line 3113, Address: 0x1431c8, Func Offset: 0x288
	// Line 3114, Address: 0x1431d0, Func Offset: 0x290
	// Line 3116, Address: 0x1431d8, Func Offset: 0x298
	// Line 3117, Address: 0x1431e0, Func Offset: 0x2a0
	// Line 3119, Address: 0x1431e8, Func Offset: 0x2a8
	// Line 3120, Address: 0x1431f0, Func Offset: 0x2b0
	// Line 3122, Address: 0x1431f8, Func Offset: 0x2b8
	// Line 3123, Address: 0x143200, Func Offset: 0x2c0
	// Line 3125, Address: 0x143208, Func Offset: 0x2c8
	// Line 3126, Address: 0x143210, Func Offset: 0x2d0
	// Line 3128, Address: 0x143218, Func Offset: 0x2d8
	// Line 3129, Address: 0x143220, Func Offset: 0x2e0
	// Line 3131, Address: 0x143228, Func Offset: 0x2e8
	// Line 3132, Address: 0x143230, Func Offset: 0x2f0
	// Line 3134, Address: 0x143238, Func Offset: 0x2f8
	// Line 3135, Address: 0x143240, Func Offset: 0x300
	// Line 3137, Address: 0x143248, Func Offset: 0x308
	// Line 3138, Address: 0x143250, Func Offset: 0x310
	// Line 3140, Address: 0x143258, Func Offset: 0x318
	// Line 3141, Address: 0x143260, Func Offset: 0x320
	// Line 3143, Address: 0x143268, Func Offset: 0x328
	// Line 3146, Address: 0x143270, Func Offset: 0x330
	// Func End, Address: 0x14327c, Func Offset: 0x33c
}*/

// 100% matching!
void bhCPM2_act_suw()
{
	float ln;   
    BH_PWORK* epp;
    int i;

    switch (plp->mode3)
    {
    case 0:
        ln = plp->mlwP->owP[5].mtx[13] - plp->py;
        
        plp->ayp = 0;
        
        epp = ene;
        
        for (i = 0; i < sys->ewk_n; i++, epp++)
        {
            epp->stflg &= ~0x800;
        }
        
        plp->flg &= ~0xC0000;
        
        plp->wax = 0;
        
        plp->at_flg &= ~0x10;
        
        plp->mtn_no = PlMtnWpn[0];
        
        plp->hokan_rate = 42598;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        plp->frm_no = 0;
        
        if (bhSearchNearEnemy(plp, &plp->ayp, &ln, &plp->src_no) != 0) 
        {
            if ((WpnTab[plp->wpnr_no].flg & 0x4000000)) 
            {
                plp->flg &= ~0x80000;
            }
            else 
            {
                plp->flg |= 0x80000;
            }
            
            plp->ayp = bhCalcLockEneYR(plp, plp->src_no);
            
            plp->flg   |= 0x100000;
            plp->stflg |= 0x800;
            
            ((EXP_WORK*)plp->exp0)->yrct = 8;
        }
        
        if ((plp->stflg & 0x100000)) 
        {
            bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
            bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
            bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
        }
        
        if (!bhCheckBullet()) 
        {
            sys->gm_flg |= 0x40000;
        }
        
        plp->mode3++;
    case 1:
        if (plp->hokan_count == 0) 
        {
            plp->flg |= 0x40000;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x4000000)) 
            {
                plp->flg &= ~0x80000;
            }
            else 
            {
                plp->flg |= 0x80000;
            }
        }
        else 
        {
            plp->flg |= 0x200000;
        }
        
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 4)) 
        {
            plp->at_flg &= ~0x1;
        }
        
        if ((WpnTab[plp->wpnr_no].flg & 0x20))
        {
            if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= (plp->frm_no / 65536))
            {
                plp->at_flg &= ~0x1;
                
                if ((sys->pad_on & 0x10)) 
                {
                    plp->mtn_add = 0;
                    
                    plp->mode2 = 71;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 2;
                    
                    plp->hokan_count = 0;
                    
                    plp->wax = 0;
                    plp->waxp = 0;
                    
                    cam.pe_ax = 0;
                    cam.pe_pers = 11832;
                    
                    sys->gm_flg |= 0x2000;
                }
                else 
                {
                    plp->mode2 = 68;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 0;
                }
                
                return;
            }
        } 
        else 
        {
            if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
            {
                plp->mtn_add = 0;
                
                plp->mode2 = 65;
                plp->mode3 = 0;
                
                plp->at_flg = 2;
                
                plp->hokan_count = 1;
                
                plp->wax = 0;
                plp->waxp = 0;
                return;
            }
            
            if (!(WpnTab[plp->wpnr_no].flg & 0x1)) 
            {
                if ((sys->pad_on & 0x20)) 
                {
                    if (!(plp->at_flg & 0x1)) 
                    {
                        plp->mode2 = 66;
                        plp->mode3 = 0;
                        
                        plp->at_flg = 4;
                        
                        plp->hokan_count = 8;
                        
                        plp->wax = 0;
                        plp->waxp = 8192;
                        break;
                    }
                }
                
                if (((sys->pad_on & 0x40)) && (!(plp->at_flg & 0x1))) 
                {
                    plp->mode2 = 67;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 8;
                    
                    plp->hokan_count = 8;
                    
                    plp->wax = 0;
                    plp->waxp = -8192;
                    break;
                }
            }
        // nested case
        default:
            if ((sys->pad_on & 0x8))
            {
                plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            if ((sys->pad_on & 0x4)) 
            {
                plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            return;
        }
    }
}

// 
// Start address: 0x1439f0
void bhCPM2_act_wpn()
{
	//_anon35 fpsb;
	//_anon35 fps;
	//_anon40* eft;
	//_anon35 pos;
	short bn;
	int wno;
	// Line 3282, Address: 0x1439f0, Func Offset: 0
	// Line 3286, Address: 0x143a00, Func Offset: 0x10
	// Line 3288, Address: 0x143a28, Func Offset: 0x38
	// Line 3289, Address: 0x143a30, Func Offset: 0x40
	// Line 3288, Address: 0x143a3c, Func Offset: 0x4c
	// Line 3289, Address: 0x143a44, Func Offset: 0x54
	// Line 3290, Address: 0x143a8c, Func Offset: 0x9c
	// Line 3292, Address: 0x143ac8, Func Offset: 0xd8
	// Line 3293, Address: 0x143ad4, Func Offset: 0xe4
	// Line 3294, Address: 0x143adc, Func Offset: 0xec
	// Line 3296, Address: 0x143ae4, Func Offset: 0xf4
	// Line 3297, Address: 0x143aec, Func Offset: 0xfc
	// Line 3296, Address: 0x143af0, Func Offset: 0x100
	// Line 3297, Address: 0x143af4, Func Offset: 0x104
	// Line 3298, Address: 0x143afc, Func Offset: 0x10c
	// Line 3300, Address: 0x143b04, Func Offset: 0x114
	// Line 3301, Address: 0x143b0c, Func Offset: 0x11c
	// Line 3300, Address: 0x143b10, Func Offset: 0x120
	// Line 3301, Address: 0x143b14, Func Offset: 0x124
	// Line 3305, Address: 0x143b20, Func Offset: 0x130
	// Line 3307, Address: 0x143b2c, Func Offset: 0x13c
	// Line 3308, Address: 0x143b30, Func Offset: 0x140
	// Line 3314, Address: 0x143b34, Func Offset: 0x144
	// Line 3305, Address: 0x143b38, Func Offset: 0x148
	// Line 3306, Address: 0x143b3c, Func Offset: 0x14c
	// Line 3307, Address: 0x143b48, Func Offset: 0x158
	// Line 3306, Address: 0x143b4c, Func Offset: 0x15c
	// Line 3307, Address: 0x143b50, Func Offset: 0x160
	// Line 3308, Address: 0x143b58, Func Offset: 0x168
	// Line 3309, Address: 0x143b64, Func Offset: 0x174
	// Line 3308, Address: 0x143b68, Func Offset: 0x178
	// Line 3309, Address: 0x143b6c, Func Offset: 0x17c
	// Line 3310, Address: 0x143b74, Func Offset: 0x184
	// Line 3314, Address: 0x143b80, Func Offset: 0x190
	// Line 3310, Address: 0x143b84, Func Offset: 0x194
	// Line 3314, Address: 0x143b8c, Func Offset: 0x19c
	// Line 3315, Address: 0x143b9c, Func Offset: 0x1ac
	// Line 3316, Address: 0x143bc4, Func Offset: 0x1d4
	// Line 3317, Address: 0x143bcc, Func Offset: 0x1dc
	// Line 3327, Address: 0x143be4, Func Offset: 0x1f4
	// Line 3328, Address: 0x143c04, Func Offset: 0x214
	// Line 3330, Address: 0x143c1c, Func Offset: 0x22c
	// Line 3332, Address: 0x143c40, Func Offset: 0x250
	// Line 3334, Address: 0x143c50, Func Offset: 0x260
	// Line 3336, Address: 0x143c60, Func Offset: 0x270
	// Line 3334, Address: 0x143c64, Func Offset: 0x274
	// Line 3336, Address: 0x143c7c, Func Offset: 0x28c
	// Line 3338, Address: 0x143c98, Func Offset: 0x2a8
	// Line 3339, Address: 0x143ca8, Func Offset: 0x2b8
	// Line 3340, Address: 0x143cb4, Func Offset: 0x2c4
	// Line 3341, Address: 0x143cbc, Func Offset: 0x2cc
	// Line 3344, Address: 0x143cc4, Func Offset: 0x2d4
	// Line 3351, Address: 0x143ccc, Func Offset: 0x2dc
	// Line 3344, Address: 0x143cd4, Func Offset: 0x2e4
	// Line 3351, Address: 0x143cd8, Func Offset: 0x2e8
	// Line 3344, Address: 0x143cdc, Func Offset: 0x2ec
	// Line 3351, Address: 0x143ce4, Func Offset: 0x2f4
	// Line 3353, Address: 0x143d74, Func Offset: 0x384
	// Line 3354, Address: 0x143d84, Func Offset: 0x394
	// Line 3355, Address: 0x143d88, Func Offset: 0x398
	// Line 3356, Address: 0x143d90, Func Offset: 0x3a0
	// Line 3355, Address: 0x143d94, Func Offset: 0x3a4
	// Line 3356, Address: 0x143d98, Func Offset: 0x3a8
	// Line 3355, Address: 0x143d9c, Func Offset: 0x3ac
	// Line 3356, Address: 0x143da4, Func Offset: 0x3b4
	// Line 3358, Address: 0x143dac, Func Offset: 0x3bc
	// Line 3359, Address: 0x143db8, Func Offset: 0x3c8
	// Line 3358, Address: 0x143dbc, Func Offset: 0x3cc
	// Line 3359, Address: 0x143dc0, Func Offset: 0x3d0
	// Line 3360, Address: 0x143dcc, Func Offset: 0x3dc
	// Line 3359, Address: 0x143dd0, Func Offset: 0x3e0
	// Line 3360, Address: 0x143dd8, Func Offset: 0x3e8
	// Line 3361, Address: 0x143de0, Func Offset: 0x3f0
	// Line 3360, Address: 0x143de4, Func Offset: 0x3f4
	// Line 3361, Address: 0x143dec, Func Offset: 0x3fc
	// Line 3362, Address: 0x143df4, Func Offset: 0x404
	// Line 3361, Address: 0x143df8, Func Offset: 0x408
	// Line 3362, Address: 0x143dfc, Func Offset: 0x40c
	// Line 3363, Address: 0x143e00, Func Offset: 0x410
	// Line 3365, Address: 0x143e08, Func Offset: 0x418
	// Line 3366, Address: 0x143e18, Func Offset: 0x428
	// Line 3367, Address: 0x143e1c, Func Offset: 0x42c
	// Line 3368, Address: 0x143e24, Func Offset: 0x434
	// Line 3367, Address: 0x143e28, Func Offset: 0x438
	// Line 3368, Address: 0x143e2c, Func Offset: 0x43c
	// Line 3367, Address: 0x143e30, Func Offset: 0x440
	// Line 3368, Address: 0x143e38, Func Offset: 0x448
	// Line 3370, Address: 0x143e40, Func Offset: 0x450
	// Line 3371, Address: 0x143e4c, Func Offset: 0x45c
	// Line 3374, Address: 0x143e50, Func Offset: 0x460
	// Line 3370, Address: 0x143e54, Func Offset: 0x464
	// Line 3371, Address: 0x143e58, Func Offset: 0x468
	// Line 3372, Address: 0x143e64, Func Offset: 0x474
	// Line 3371, Address: 0x143e68, Func Offset: 0x478
	// Line 3372, Address: 0x143e70, Func Offset: 0x480
	// Line 3373, Address: 0x143e78, Func Offset: 0x488
	// Line 3372, Address: 0x143e7c, Func Offset: 0x48c
	// Line 3373, Address: 0x143e84, Func Offset: 0x494
	// Line 3374, Address: 0x143e8c, Func Offset: 0x49c
	// Line 3373, Address: 0x143e90, Func Offset: 0x4a0
	// Line 3374, Address: 0x143e94, Func Offset: 0x4a4
	// Line 3375, Address: 0x143e98, Func Offset: 0x4a8
	// Line 3377, Address: 0x143ea0, Func Offset: 0x4b0
	// Line 3378, Address: 0x143eb0, Func Offset: 0x4c0
	// Line 3379, Address: 0x143eb4, Func Offset: 0x4c4
	// Line 3380, Address: 0x143ebc, Func Offset: 0x4cc
	// Line 3379, Address: 0x143ec0, Func Offset: 0x4d0
	// Line 3380, Address: 0x143ec4, Func Offset: 0x4d4
	// Line 3379, Address: 0x143ec8, Func Offset: 0x4d8
	// Line 3380, Address: 0x143ed0, Func Offset: 0x4e0
	// Line 3382, Address: 0x143ed8, Func Offset: 0x4e8
	// Line 3383, Address: 0x143ee4, Func Offset: 0x4f4
	// Line 3386, Address: 0x143ee8, Func Offset: 0x4f8
	// Line 3382, Address: 0x143eec, Func Offset: 0x4fc
	// Line 3383, Address: 0x143ef0, Func Offset: 0x500
	// Line 3384, Address: 0x143efc, Func Offset: 0x50c
	// Line 3383, Address: 0x143f00, Func Offset: 0x510
	// Line 3384, Address: 0x143f08, Func Offset: 0x518
	// Line 3385, Address: 0x143f10, Func Offset: 0x520
	// Line 3384, Address: 0x143f14, Func Offset: 0x524
	// Line 3385, Address: 0x143f1c, Func Offset: 0x52c
	// Line 3386, Address: 0x143f24, Func Offset: 0x534
	// Line 3385, Address: 0x143f28, Func Offset: 0x538
	// Line 3386, Address: 0x143f2c, Func Offset: 0x53c
	// Line 3392, Address: 0x143f34, Func Offset: 0x544
	// Line 3394, Address: 0x143f64, Func Offset: 0x574
	// Line 3395, Address: 0x143fac, Func Offset: 0x5bc
	// Line 3394, Address: 0x143fb4, Func Offset: 0x5c4
	// Line 3395, Address: 0x143fb8, Func Offset: 0x5c8
	// Line 3404, Address: 0x144058, Func Offset: 0x668
	// Line 3407, Address: 0x144060, Func Offset: 0x670
	// Line 3408, Address: 0x144090, Func Offset: 0x6a0
	// Line 3409, Address: 0x14409c, Func Offset: 0x6ac
	// Line 3408, Address: 0x1440a4, Func Offset: 0x6b4
	// Line 3409, Address: 0x1440ac, Func Offset: 0x6bc
	// Line 3410, Address: 0x1440b4, Func Offset: 0x6c4
	// Line 3411, Address: 0x1440bc, Func Offset: 0x6cc
	// Line 3414, Address: 0x1440c4, Func Offset: 0x6d4
	// Line 3417, Address: 0x144108, Func Offset: 0x718
	// Line 3418, Address: 0x144118, Func Offset: 0x728
	// Line 3420, Address: 0x144120, Func Offset: 0x730
	// Line 3423, Address: 0x14412c, Func Offset: 0x73c
	// Line 3420, Address: 0x144134, Func Offset: 0x744
	// Line 3423, Address: 0x14413c, Func Offset: 0x74c
	// Line 3425, Address: 0x144140, Func Offset: 0x750
	// Line 3428, Address: 0x144144, Func Offset: 0x754
	// Line 3423, Address: 0x144148, Func Offset: 0x758
	// Line 3424, Address: 0x14414c, Func Offset: 0x75c
	// Line 3425, Address: 0x144158, Func Offset: 0x768
	// Line 3426, Address: 0x144164, Func Offset: 0x774
	// Line 3425, Address: 0x144168, Func Offset: 0x778
	// Line 3426, Address: 0x144170, Func Offset: 0x780
	// Line 3428, Address: 0x144178, Func Offset: 0x788
	// Line 3430, Address: 0x14419c, Func Offset: 0x7ac
	// Line 3435, Address: 0x1441e4, Func Offset: 0x7f4
	// Line 3434, Address: 0x1441ec, Func Offset: 0x7fc
	// Line 3435, Address: 0x1441f0, Func Offset: 0x800
	// Line 3436, Address: 0x1441f8, Func Offset: 0x808
	// Line 3437, Address: 0x144200, Func Offset: 0x810
	// Line 3440, Address: 0x144218, Func Offset: 0x828
	// Line 3444, Address: 0x14427c, Func Offset: 0x88c
	// Line 3446, Address: 0x144284, Func Offset: 0x894
	// Line 3444, Address: 0x14428c, Func Offset: 0x89c
	// Line 3446, Address: 0x144290, Func Offset: 0x8a0
	// Line 3444, Address: 0x144294, Func Offset: 0x8a4
	// Line 3446, Address: 0x14429c, Func Offset: 0x8ac
	// Line 3447, Address: 0x1442ac, Func Offset: 0x8bc
	// Line 3448, Address: 0x1442d8, Func Offset: 0x8e8
	// Line 3451, Address: 0x1442f8, Func Offset: 0x908
	// Line 3452, Address: 0x144314, Func Offset: 0x924
	// Line 3456, Address: 0x144328, Func Offset: 0x938
	// Line 3460, Address: 0x14438c, Func Offset: 0x99c
	// Line 3462, Address: 0x144390, Func Offset: 0x9a0
	// Line 3461, Address: 0x144398, Func Offset: 0x9a8
	// Line 3463, Address: 0x14439c, Func Offset: 0x9ac
	// Line 3460, Address: 0x1443a0, Func Offset: 0x9b0
	// Line 3461, Address: 0x1443a4, Func Offset: 0x9b4
	// Line 3462, Address: 0x1443ac, Func Offset: 0x9bc
	// Line 3463, Address: 0x1443b8, Func Offset: 0x9c8
	// Line 3462, Address: 0x1443bc, Func Offset: 0x9cc
	// Line 3463, Address: 0x1443cc, Func Offset: 0x9dc
	// Line 3462, Address: 0x1443d0, Func Offset: 0x9e0
	// Line 3463, Address: 0x1443d4, Func Offset: 0x9e4
	// Line 3464, Address: 0x1443dc, Func Offset: 0x9ec
	// Line 3467, Address: 0x144418, Func Offset: 0xa28
	// Line 3468, Address: 0x144420, Func Offset: 0xa30
	// Line 3469, Address: 0x14443c, Func Offset: 0xa4c
	// Line 3472, Address: 0x144474, Func Offset: 0xa84
	// Line 3473, Address: 0x14447c, Func Offset: 0xa8c
	// Line 3474, Address: 0x144484, Func Offset: 0xa94
	// Line 3475, Address: 0x144488, Func Offset: 0xa98
	// Line 3476, Address: 0x14448c, Func Offset: 0xa9c
	// Line 3474, Address: 0x144494, Func Offset: 0xaa4
	// Line 3475, Address: 0x144498, Func Offset: 0xaa8
	// Line 3476, Address: 0x14449c, Func Offset: 0xaac
	// Line 3475, Address: 0x1444a0, Func Offset: 0xab0
	// Line 3476, Address: 0x1444a4, Func Offset: 0xab4
	// Line 3477, Address: 0x1444ac, Func Offset: 0xabc
	// Line 3478, Address: 0x1444c0, Func Offset: 0xad0
	// Line 3480, Address: 0x1444c8, Func Offset: 0xad8
	// Line 3481, Address: 0x1444d4, Func Offset: 0xae4
	// Line 3483, Address: 0x1444e4, Func Offset: 0xaf4
	// Line 3484, Address: 0x1444e8, Func Offset: 0xaf8
	// Line 3483, Address: 0x1444ec, Func Offset: 0xafc
	// Line 3484, Address: 0x1444f0, Func Offset: 0xb00
	// Line 3485, Address: 0x1444f8, Func Offset: 0xb08
	// Line 3487, Address: 0x144500, Func Offset: 0xb10
	// Line 3485, Address: 0x14450c, Func Offset: 0xb1c
	// Line 3486, Address: 0x144510, Func Offset: 0xb20
	// Line 3485, Address: 0x144514, Func Offset: 0xb24
	// Line 3486, Address: 0x144518, Func Offset: 0xb28
	// Line 3487, Address: 0x144520, Func Offset: 0xb30
	// Line 3488, Address: 0x144528, Func Offset: 0xb38
	// Line 3489, Address: 0x14453c, Func Offset: 0xb4c
	// Line 3490, Address: 0x144548, Func Offset: 0xb58
	// Line 3491, Address: 0x144550, Func Offset: 0xb60
	// Line 3492, Address: 0x14455c, Func Offset: 0xb6c
	// Line 3493, Address: 0x144564, Func Offset: 0xb74
	// Line 3492, Address: 0x14456c, Func Offset: 0xb7c
	// Line 3493, Address: 0x144570, Func Offset: 0xb80
	// Line 3494, Address: 0x144578, Func Offset: 0xb88
	// Line 3495, Address: 0x14458c, Func Offset: 0xb9c
	// Line 3496, Address: 0x144594, Func Offset: 0xba4
	// Line 3497, Address: 0x1445a0, Func Offset: 0xbb0
	// Line 3498, Address: 0x1445a8, Func Offset: 0xbb8
	// Line 3499, Address: 0x1445b4, Func Offset: 0xbc4
	// Line 3500, Address: 0x1445bc, Func Offset: 0xbcc
	// Line 3499, Address: 0x1445c4, Func Offset: 0xbd4
	// Line 3500, Address: 0x1445c8, Func Offset: 0xbd8
	// Line 3501, Address: 0x1445d0, Func Offset: 0xbe0
	// Line 3502, Address: 0x1445e4, Func Offset: 0xbf4
	// Line 3503, Address: 0x1445ec, Func Offset: 0xbfc
	// Line 3504, Address: 0x1445f8, Func Offset: 0xc08
	// Line 3505, Address: 0x144600, Func Offset: 0xc10
	// Line 3506, Address: 0x14460c, Func Offset: 0xc1c
	// Line 3507, Address: 0x144614, Func Offset: 0xc24
	// Line 3506, Address: 0x14461c, Func Offset: 0xc2c
	// Line 3507, Address: 0x144620, Func Offset: 0xc30
	// Line 3508, Address: 0x144628, Func Offset: 0xc38
	// Line 3509, Address: 0x14463c, Func Offset: 0xc4c
	// Line 3510, Address: 0x144644, Func Offset: 0xc54
	// Line 3511, Address: 0x144650, Func Offset: 0xc60
	// Line 3512, Address: 0x144658, Func Offset: 0xc68
	// Line 3513, Address: 0x144664, Func Offset: 0xc74
	// Line 3514, Address: 0x14466c, Func Offset: 0xc7c
	// Line 3513, Address: 0x144674, Func Offset: 0xc84
	// Line 3514, Address: 0x144678, Func Offset: 0xc88
	// Line 3515, Address: 0x144680, Func Offset: 0xc90
	// Line 3516, Address: 0x144694, Func Offset: 0xca4
	// Line 3517, Address: 0x14469c, Func Offset: 0xcac
	// Line 3521, Address: 0x1446a4, Func Offset: 0xcb4
	// Line 3522, Address: 0x1446ac, Func Offset: 0xcbc
	// Line 3523, Address: 0x1446b4, Func Offset: 0xcc4
	// Line 3524, Address: 0x1446b8, Func Offset: 0xcc8
	// Line 3525, Address: 0x1446bc, Func Offset: 0xccc
	// Line 3523, Address: 0x1446c4, Func Offset: 0xcd4
	// Line 3524, Address: 0x1446c8, Func Offset: 0xcd8
	// Line 3525, Address: 0x1446cc, Func Offset: 0xcdc
	// Line 3524, Address: 0x1446d0, Func Offset: 0xce0
	// Line 3525, Address: 0x1446d4, Func Offset: 0xce4
	// Line 3526, Address: 0x1446dc, Func Offset: 0xcec
	// Line 3527, Address: 0x1446f0, Func Offset: 0xd00
	// Line 3529, Address: 0x1446f8, Func Offset: 0xd08
	// Line 3530, Address: 0x144700, Func Offset: 0xd10
	// Line 3531, Address: 0x144708, Func Offset: 0xd18
	// Line 3532, Address: 0x14470c, Func Offset: 0xd1c
	// Line 3533, Address: 0x144710, Func Offset: 0xd20
	// Line 3531, Address: 0x144718, Func Offset: 0xd28
	// Line 3532, Address: 0x14471c, Func Offset: 0xd2c
	// Line 3533, Address: 0x144720, Func Offset: 0xd30
	// Line 3532, Address: 0x144724, Func Offset: 0xd34
	// Line 3533, Address: 0x144728, Func Offset: 0xd38
	// Line 3534, Address: 0x144730, Func Offset: 0xd40
	// Line 3535, Address: 0x144744, Func Offset: 0xd54
	// Line 3536, Address: 0x14475c, Func Offset: 0xd6c
	// Line 3537, Address: 0x144768, Func Offset: 0xd78
	// Line 3539, Address: 0x144770, Func Offset: 0xd80
	// Line 3540, Address: 0x144778, Func Offset: 0xd88
	// Line 3541, Address: 0x144780, Func Offset: 0xd90
	// Line 3542, Address: 0x144784, Func Offset: 0xd94
	// Line 3543, Address: 0x144788, Func Offset: 0xd98
	// Line 3541, Address: 0x144790, Func Offset: 0xda0
	// Line 3542, Address: 0x144794, Func Offset: 0xda4
	// Line 3543, Address: 0x144798, Func Offset: 0xda8
	// Line 3542, Address: 0x14479c, Func Offset: 0xdac
	// Line 3543, Address: 0x1447a0, Func Offset: 0xdb0
	// Line 3544, Address: 0x1447a8, Func Offset: 0xdb8
	// Line 3545, Address: 0x1447bc, Func Offset: 0xdcc
	// Line 3548, Address: 0x1447d0, Func Offset: 0xde0
	// Line 3553, Address: 0x1447d8, Func Offset: 0xde8
	// Line 3554, Address: 0x1447f8, Func Offset: 0xe08
	// Line 3556, Address: 0x144830, Func Offset: 0xe40
	// Line 3554, Address: 0x144838, Func Offset: 0xe48
	// Line 3556, Address: 0x144840, Func Offset: 0xe50
	// Line 3557, Address: 0x144874, Func Offset: 0xe84
	// Line 3558, Address: 0x144888, Func Offset: 0xe98
	// Line 3559, Address: 0x1448a8, Func Offset: 0xeb8
	// Line 3561, Address: 0x1448d8, Func Offset: 0xee8
	// Line 3564, Address: 0x144900, Func Offset: 0xf10
	// Line 3565, Address: 0x144920, Func Offset: 0xf30
	// Line 3567, Address: 0x144958, Func Offset: 0xf68
	// Line 3565, Address: 0x144960, Func Offset: 0xf70
	// Line 3567, Address: 0x144968, Func Offset: 0xf78
	// Line 3568, Address: 0x14499c, Func Offset: 0xfac
	// Line 3569, Address: 0x1449b0, Func Offset: 0xfc0
	// Line 3570, Address: 0x1449d0, Func Offset: 0xfe0
	// Line 3572, Address: 0x144a00, Func Offset: 0x1010
	// Line 3577, Address: 0x144a28, Func Offset: 0x1038
	// Line 3578, Address: 0x144a48, Func Offset: 0x1058
	// Line 3583, Address: 0x144a84, Func Offset: 0x1094
	// Line 3585, Address: 0x144a8c, Func Offset: 0x109c
	// Line 3587, Address: 0x144a94, Func Offset: 0x10a4
	// Line 3589, Address: 0x144ab8, Func Offset: 0x10c8
	// Line 3587, Address: 0x144abc, Func Offset: 0x10cc
	// Line 3589, Address: 0x144ac0, Func Offset: 0x10d0
	// Line 3590, Address: 0x144ad4, Func Offset: 0x10e4
	// Line 3591, Address: 0x144ae4, Func Offset: 0x10f4
	// Line 3593, Address: 0x144ae8, Func Offset: 0x10f8
	// Line 3590, Address: 0x144aec, Func Offset: 0x10fc
	// Line 3591, Address: 0x144af0, Func Offset: 0x1100
	// Line 3592, Address: 0x144afc, Func Offset: 0x110c
	// Line 3591, Address: 0x144b00, Func Offset: 0x1110
	// Line 3592, Address: 0x144b08, Func Offset: 0x1118
	// Line 3593, Address: 0x144b10, Func Offset: 0x1120
	// Line 3592, Address: 0x144b14, Func Offset: 0x1124
	// Line 3593, Address: 0x144b1c, Func Offset: 0x112c
	// Line 3621, Address: 0x144b28, Func Offset: 0x1138
	// Func End, Address: 0x144b3c, Func Offset: 0x114c
    scePrintf("bhCPM2_act_wpn - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCPM2_act_wre()
{
    switch (plp->mode3)
    { 
    case 0:
        if ((WpnTab[plp->wpnr_no].flg & 0x20)) 
        {
            sys->pt_flg |= 0x1;
        }
        
        plp->flg |= 0xC0000;
        
        if ((WpnTab[plp->wpnr_no].flg & 0x4000000))
        {
            plp->flg &= ~0x80000;
        }
        
        plp->mtn_no = PlMtnWpn[0];
        
        plp->hokan_rate = 45875;
        plp->hokan_count = 12;
        
        plp->mtn_add = -131072;
        
        plp->frm_no = (plp->mnwP[plp->mtn_no].frm_num - 1) * 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->wax = 0;
        
        if ((plp->stflg & 0x100000)) 
        {
            bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
            bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
            bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
        }
        
        plp->mode3++;
    case 1:
        if (((int)plp->frm_no / 65536) < 2) 
        {
            plp->stflg &= ~0x10400;
            
            plp->mtn_add = 0;
            
            plp->flg &= ~0x10000;
            
            sys->pad_on &= ~0xF;
            break;
        }
    default:
        if ((sys->pad_on & 0x8)) 
        {
            plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
        
        if ((sys->pad_on & 0x4)) 
        {
            plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
    }
}

// 100% matching!
void bhCPM2_act_atk()
{
	NJS_POINT3 ps;  
    GA_WORK gap;    
    int frm_no;
    short* act_ct;

    if ((!(WpnTab[plp->wpnr_no].flg & 0x40)) || (((WpnTab[plp->wpnr_no].flg & 0x200)) && (bhCkFlg(sys->ev_flg, 74) != 0))) 
    {
        switch (plp->mode3)
        {
        case 0:
            plp->flg |= 0xC0000;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x8000000)) 
            {
                plp->flg &= ~0x80000;
            }
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no =  PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = (int)(65536.0f * WpnTab[plp->wpnr_no].hrate);
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3++;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x2000000)) 
            {
                plp->flg |= 0x20000000;
                
                switch (plp->wpnr_no)
                {
                case 20:
                    if (sys->ply_id == 0) 
                    {
                        plp->spd = 0.8f;
                    }
                    else 
                    {
                        plp->spd = 0.4f;
                    }
                    
                    break;
                default:
                    if (sys->ply_id == 0) 
                    {
                        plp->spd = 0.5f;
                    }
                    else 
                    {
                        plp->spd = 0.1f;
                    }

                    break;
                }
            }
            
            if ((WpnTab[plp->wpnr_no].flg & 0x2))
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }
            
            if ((WpnTab[plp->wpnr_no].flg & 0x10000000))
            {
                gap.at_flg = plp->at_flg;
                
                gap.wpn_no = plp->wpnr_no;
                
                gap.r = WpnTab[plp->wpnr_no].r;
                gap.l = WpnTab[plp->wpnr_no].l;
                
                gap.rn   = WpnTab[plp->wpnr_no].rn;
                gap.rmax = WpnTab[plp->wpnr_no].rmax;
                
                gap.ax = plp->wax;
                gap.ay = plp->ay;
                
                plp->way = plp->ay;
                plp->waz = 0;
                
                njSetMatrix(NULL, &plp->mlwP->owP[9].mtx);
                
                ps.x = ps.y = 0;
                ps.z = WpnTab[plp->wpnr_no].wp_fps1.z;

                (void*)&gap.gx; // FAKE
                njCalcPoint(NULL, (NJS_POINT3*)&ps, (NJS_POINT3*)&gap.gx);
                
                njSinCos(plp->ay, &gap.px, &gap.pz);
                
                gap.px = plp->px - (gap.px * (3.0f + gap.r));
                gap.py = 11.0f + plp->py;
                gap.pz = plp->pz - (gap.pz * (3.0f + gap.r));
                
                njUnitRotPortion(NULL);
                
                njPushMatrix(NULL);
                
                njRotateXYZ(NULL, plp->wax, plp->way, plp->waz);
                
                ps.x = 0;
                ps.y = 0;
                ps.z = -gap.l;
                
                (void*)&gap.vx; // FAKE
                njCalcVector(NULL, (NJS_VECTOR*)&ps, (NJS_VECTOR*)&gap.vx);
                
                bhCheckGunAtari(&gap);
                
                bhCountBullet();
                
                njPopMatrix(1);
            }
            
            if (((plp->stflg & 0x100000)) && ((WpnTab[plp->wpnr_no].flg & 0x800000)))
            {
                if ((WpnTab[plp->wpnr_no].flg & 0x1000000)) 
                {
                    bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                    bhSetWaterSplash(plp, 15, 1, 1.6f, 1.6f, 1.6f);
                    bhSetWaterSplash(plp, 19, 1, 1.6f, 1.6f, 1.6f);
                }
                else 
                {
                    bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                    bhSetWaterSplash(plp, 15, 1, 0.8f, 0.8f, 0.8f);
                    bhSetWaterSplash(plp, 19, 1, 0.8f, 0.8f, 0.8f);
                }
            }
        case 1:
            frm_no = plp->frm_no / 65536;
            
            if ((frm_no == WpnTab[plp->wpnr_no].ef_yct) && (WpnEffTab[plp->wpnr_no][3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, plp->ay);
            }

            act_ct = (short*)&WpnTab[plp->wpnr_no].act_ct0;
            act_ct += sys->ply_id;
            
            if ((frm_no == *act_ct) && ((WpnTab[plp->wpnr_no].flg & 0x1000)))
            {
                sys->obwp->flg |= 0x400000;
                
                sys->obwp->mode0 = 0;
            }
            
            if ((frm_no == (*act_ct + 4)) && (plp->wpnr_no == 11))
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], WpnTab[plp->wpnr_no].seno1, 0);
            }
            
            if ((frm_no == 12) && (((WpnTab[plp->wpnr_no].flg & 0x400)) && (bhCheckBullet() != 0))) 
            {
                sys->obwp->flg |= 0x800000;
                
                sys->obwp->mode0 = 0;
                
                CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], 263, 0);
            }
            
            if ((frm_no == 35) && (((WpnTab[plp->wpnr_no].flg & 0x400)) && (bhCheckBullet() != 0))) 
            {
                sys->obwp->mode0 = 1;
                
                CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], 264, 0);
            }
            
            if (((((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10)))) || (frm_no >= (plp->mnwP[plp->mtn_no].frm_num - 1)) || ((frm_no == 10) && ((WpnTab[plp->wpnr_no].flg & 0x400)) && (!bhCheckBullet())))
            {
                if ((((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10))) && ((!bhCheckBullet()) && (bhSearchBullet() != 0)))
                {
                    sys->gm_flg &= ~0x40000;
                    
                    plp->mode2 = 70;
                    plp->mode3 = 0;
                    return;
                }
                
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    break;
                case 4:
                    plp->mode2 = 66;
                    break;
                case 8:
                    plp->mode2 = 67;
                    break;
                }
                
                plp->hokan_count = 1;
                
                switch (((WpnTab[plp->wpnr_no].flg & 0x1)) ? sys->pad_on & 0x10 : sys->pad_on & 0x70)
                {
                case 0x10:
                    if (!(plp->at_flg & 0x2)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x30:
                    if (!(plp->at_flg & 0x4)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x50:
                    if (!(plp->at_flg & 0x8)) 
                    {
                        plp->hokan_count = 12;
                    }

                    break;
                }
                
                if (((WpnTab[plp->wpnr_no].flg & 0x400)) && (!bhCheckBullet())) 
                {
                    plp->hokan_count = 5;
                }
                
                plp->mode3 = 0;
                break;
            }
            
            if (frm_no >= (plp->mnwP[plp->mtn_no].frm_num - WpnTab[plp->wpnr_no].at_cct)) 
            {
                plp->at_flg |= 0x10;
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
        default:
            plp->wax += (plp->waxp - plp->wax) / 4;
            
            if ((sys->pad_on & 0x8)) 
            {
                plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
                
                if (((plp->stflg & 0x100000)) && (!(sys->eor_ct & 0xF))) 
                {
                    bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                    
                    if ((sys->eor_ct & 0x10)) 
                    {
                        bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f); 
                    }
                    else 
                    {
                        bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
                    }
                }
            }
            
            if ((sys->pad_on & 0x4)) 
            {
                plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
                
                if (((plp->stflg & 0x100000)) && (!(sys->eor_ct & 0xF)))
                {
                    bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                    
                    if ((sys->eor_ct & 0x10)) 
                    {
                        bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
                    }
                    else
                    {
                        bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
                    }
                }
            }
            
            break;
        }
    } 
    else 
    {
        if ((plp->ct0 >= WpnTab[plp->wpnr_no].fend_ct) && (plp->mode3 == 2)) 
        {
            plp->mode3 = 1;
            
            plp->ct0 = 0;
            plp->ct1++;
        } 
        else 
        {
            plp->ct0++;
        }
        
        switch (plp->mode3) 
        {
        case 0:
            plp->flg |= 0xC0000;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x8000000))
            {
                plp->flg &= ~0x80000;
            }
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no = PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = 65536.0f * WpnTab[plp->wpnr_no].hrate;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->ct1 = 0;
            plp->ct0 = 0;
            
            plp->mode3 = 1;
        case 1:
            bhSetGunFire(plp, plp->wpnr_no, 9, 0, plp->ay);
            
            if ((WpnTab[plp->wpnr_no].flg & 0x2)) 
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }
            
            if (((WpnTab[plp->wpnr_no].flg & 0x10000000)) && (
            gap.at_flg = plp->at_flg,
            
            gap.wpn_no = plp->wpnr_no,
            
            gap.r = WpnTab[plp->wpnr_no].r,
            gap.l = WpnTab[plp->wpnr_no].l,
            
            gap.rn   = WpnTab[plp->wpnr_no].rn,
            gap.rmax = WpnTab[plp->wpnr_no].rmax,
            
            gap.ax = plp->wax,
            gap.ay = plp->ay,
    
            plp->way = plp->ay,
            plp->waz = 0,
    
            njSetMatrix(NULL, &plp->mlwP->owP[9].mtx),
    
            ps.x = ps.y = 0,
            ps.z = WpnTab[plp->wpnr_no].wp_fps1.z,
    
            njCalcPoint(NULL, &ps, (NJS_POINT3*)&gap.gx),
            
            njSinCos(plp->ay, &gap.px, &gap.pz),
    
            gap.px = plp->px - (gap.px * (3.0f + gap.r)),
            gap.py = 11.0f + plp->py,
            gap.pz = plp->pz - (gap.pz * (3.0f + gap.r)),
    
            njUnitRotPortion(NULL),
            njRotateXYZ(NULL, plp->wax, plp->way, plp->waz),
    
            ps.x = 0,
            ps.y = 0,
            ps.z = -gap.l,
    
            njCalcVector(NULL, &ps, (NJS_POINT3 *)&gap.vx),
            
            bhCheckGunAtari(&gap),
            
            (bhCountBullet() == 0)))
            {
                sys->gm_flg |= 0x40000;
                
                plp->mode3 = 3;
                
                if (!(WpnTab[plp->wpnr_no].flg & 0x200)) 
                {
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
            } 
            else 
            {
                if (WpnTab[plp->wpnr_no].seno0 != 0)
                {
                    CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], (unsigned short)WpnTab[plp->wpnr_no].seno0, 0);
                    
                    if (!(WpnTab[plp->wpnr_no].flg & 0x100)) 
                    {
                        plp->stflg |= 0x100;
                    }
                }
                
                plp->mode3 = 2;
        // nested case
        case 2:
            if ((plp->ct0 == WpnTab[plp->wpnr_no].ef_yct) && (WpnEffTab[plp->wpnr_no][3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, plp->ay);
            }
            
            if (((!(sys->pad_on & 0x100)) || (!(sys->pad_on & 0x10))) || (((WpnTab[plp->wpnr_no].flg & 0x200)) && (plp->ct1 > 1))) 
            {
                plp->mode3 = 3;
                
                plp->ct1 = 0;
                
                if ((WpnTab[plp->wpnr_no].flg & 0x200)) 
                {
                    plp->at_flg |= 0x40;
                }
                else 
                {
                    plp->at_flg &= ~0x40;
                    
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
            }
        }

        break;
        case 3:
            if ((plp->ct0 == WpnTab[plp->wpnr_no].ef_yct) && (WpnEffTab[plp->wpnr_no][3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, plp->ay);
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
            
            plp->at_flg |= 0x10;
            
            if ((plp->flg & 0x400000)) 
            {
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    
                    plp->mtn_no = PlMtnWpn[1];
                    
                    plp->waxp = 0;
                    break;
                case 4:
                    plp->mode2 = 66;
                    
                    plp->mtn_no = PlMtnWpn[2];
                    
                    plp->waxp = 8192;
                    break;
                case 8:
                    plp->mode2 = 67;
                    
                    plp->mtn_no = PlMtnWpn[3];
                    
                    plp->waxp = -8192;
                    break;
                }
                
                plp->mode3 = 0;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 0;
                return;
            }
            
            break;
        case 4:
            plp->hokan_count = 12;
            plp->hokan_rate = 45875;
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mode2 = 65;

                plp->mtn_no = PlMtnWpn[1];
                
                plp->waxp = 0;
                break;
            case 4:
                plp->mode2 = 66;
                
                plp->mtn_no = PlMtnWpn[2];
                
                plp->waxp = 8192;
                break;
            case 8:
                plp->mode2 = 67;
                
                plp->mtn_no = PlMtnWpn[3];
                
                plp->waxp = -8192;
                break;
            }
            
            plp->mode3 = 0;
            return;
        }

        if ((plp->mode3 >= 3) && (!(sys->gm_flg & 0x40000)) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10))) && (((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))))
        {
            plp->mode3 = 0;
            
            plp->hokan_count = 0;
        }
        
        plp->wax += (plp->waxp - plp->wax) / 4;
        
        switch (sys->pad_on & 0x70)
        {
        case 0x10:
            if (!(plp->at_flg & 0x2)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x2;
                
                plp->mtn_no = PlMtnWpn[4];

                plp->hokan_rate = 65536.0f * WpnTab[plp->wpnr_no].hrate;
                
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 0;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x30:
            if (!(plp->at_flg & 0x4)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x4;
                
                plp->mtn_no = PlMtnWpn[4] + 5;
                
                plp->hokan_rate = 65536.0f * WpnTab[plp->wpnr_no].hrate;
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x50:
            if (!(plp->at_flg & 0x8)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x8;
                
                plp->mtn_no = PlMtnWpn[4] + 10;
                
                plp->hokan_rate = 65536.0f * WpnTab[plp->wpnr_no].hrate;
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = -8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
        }
        
        if ((sys->pad_on & 0x8)) 
        {
            plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            
            if (((plp->stflg & 0x100000)) && (!(sys->eor_ct & 0xF))) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                
                if ((sys->eor_ct & 0x10)) 
                {
                    bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
                }
                else 
                {
                    bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
                }
            }
        }
        
        if ((sys->pad_on & 0x4))
        {
            plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            
            if (((plp->stflg & 0x100000)) && (!(sys->eor_ct & 0xF))) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                
                if ((sys->eor_ct & 0x10)) 
                {
                    bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
                }
                else 
                {
                    bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
                }
            }
        }
        
        if ((sys->pad_ps & 0x80)) 
        {
            plp->ayp = bhSearchNextEnemy(plp, 15473, plp->mlwP->owP[5].mtx[13] - plp->py);
            
            if (plp->ayp != -1) 
            {
                plp->ayp = bhCalcLockEneYR(plp, plp->src_no);
                
                plp->flg   |= 0x100000;
                plp->stflg |= 0x800;
                
                ((EXP_WORK*)plp->exp0)->yrct = 4;
            }
        }
    }
}

// 
// Start address: 0x1470c0
void bhCPM2_act_rld()
{
	int frm_no;
	int j;
	int i;
	// Line 4216, Address: 0x1470c0, Func Offset: 0
	// Line 4219, Address: 0x1470d0, Func Offset: 0x10
	// Line 4220, Address: 0x1470fc, Func Offset: 0x3c
	// Line 4221, Address: 0x147104, Func Offset: 0x44
	// Line 4220, Address: 0x14710c, Func Offset: 0x4c
	// Line 4221, Address: 0x147114, Func Offset: 0x54
	// Line 4222, Address: 0x14713c, Func Offset: 0x7c
	// Line 4223, Address: 0x147140, Func Offset: 0x80
	// Line 4222, Address: 0x147144, Func Offset: 0x84
	// Line 4223, Address: 0x147148, Func Offset: 0x88
	// Line 4222, Address: 0x14714c, Func Offset: 0x8c
	// Line 4223, Address: 0x147154, Func Offset: 0x94
	// Line 4224, Address: 0x14716c, Func Offset: 0xac
	// Line 4225, Address: 0x147178, Func Offset: 0xb8
	// Line 4224, Address: 0x147184, Func Offset: 0xc4
	// Line 4225, Address: 0x14718c, Func Offset: 0xcc
	// Line 4226, Address: 0x147194, Func Offset: 0xd4
	// Line 4225, Address: 0x147198, Func Offset: 0xd8
	// Line 4226, Address: 0x1471a0, Func Offset: 0xe0
	// Line 4229, Address: 0x1471b0, Func Offset: 0xf0
	// Line 4231, Address: 0x1471d8, Func Offset: 0x118
	// Line 4232, Address: 0x1471e0, Func Offset: 0x120
	// Line 4233, Address: 0x1471e8, Func Offset: 0x128
	// Line 4231, Address: 0x1471ec, Func Offset: 0x12c
	// Line 4232, Address: 0x1471f4, Func Offset: 0x134
	// Line 4238, Address: 0x1471f8, Func Offset: 0x138
	// Line 4234, Address: 0x1471fc, Func Offset: 0x13c
	// Line 4235, Address: 0x147200, Func Offset: 0x140
	// Line 4237, Address: 0x147204, Func Offset: 0x144
	// Line 4232, Address: 0x147208, Func Offset: 0x148
	// Line 4233, Address: 0x14720c, Func Offset: 0x14c
	// Line 4238, Address: 0x147214, Func Offset: 0x154
	// Line 4233, Address: 0x147218, Func Offset: 0x158
	// Line 4234, Address: 0x14721c, Func Offset: 0x15c
	// Line 4235, Address: 0x147228, Func Offset: 0x168
	// Line 4236, Address: 0x147234, Func Offset: 0x174
	// Line 4237, Address: 0x147240, Func Offset: 0x180
	// Line 4238, Address: 0x14724c, Func Offset: 0x18c
	// Line 4237, Address: 0x147250, Func Offset: 0x190
	// Line 4238, Address: 0x147254, Func Offset: 0x194
	// Line 4239, Address: 0x147284, Func Offset: 0x1c4
	// Line 4241, Address: 0x147290, Func Offset: 0x1d0
	// Line 4239, Address: 0x147298, Func Offset: 0x1d8
	// Line 4240, Address: 0x1472a8, Func Offset: 0x1e8
	// Line 4239, Address: 0x1472ac, Func Offset: 0x1ec
	// Line 4240, Address: 0x1472b4, Func Offset: 0x1f4
	// Line 4241, Address: 0x1472c8, Func Offset: 0x208
	// Line 4243, Address: 0x1472e0, Func Offset: 0x220
	// Line 4245, Address: 0x1472f4, Func Offset: 0x234
	// Line 4247, Address: 0x1472fc, Func Offset: 0x23c
	// Line 4245, Address: 0x147304, Func Offset: 0x244
	// Line 4247, Address: 0x147308, Func Offset: 0x248
	// Line 4245, Address: 0x14730c, Func Offset: 0x24c
	// Line 4247, Address: 0x147310, Func Offset: 0x250
	// Line 4248, Address: 0x147338, Func Offset: 0x278
	// Line 4249, Address: 0x147350, Func Offset: 0x290
	// Line 4250, Address: 0x14735c, Func Offset: 0x29c
	// Line 4251, Address: 0x147360, Func Offset: 0x2a0
	// Line 4249, Address: 0x147364, Func Offset: 0x2a4
	// Line 4251, Address: 0x147370, Func Offset: 0x2b0
	// Line 4249, Address: 0x147374, Func Offset: 0x2b4
	// Line 4250, Address: 0x147378, Func Offset: 0x2b8
	// Line 4249, Address: 0x14737c, Func Offset: 0x2bc
	// Line 4250, Address: 0x147384, Func Offset: 0x2c4
	// Line 4251, Address: 0x147398, Func Offset: 0x2d8
	// Line 4255, Address: 0x1473b0, Func Offset: 0x2f0
	// Line 4257, Address: 0x147404, Func Offset: 0x344
	// Line 4259, Address: 0x147410, Func Offset: 0x350
	// Line 4260, Address: 0x147420, Func Offset: 0x360
	// Line 4261, Address: 0x147440, Func Offset: 0x380
	// Line 4263, Address: 0x147448, Func Offset: 0x388
	// Line 4267, Address: 0x14744c, Func Offset: 0x38c
	// Line 4264, Address: 0x147450, Func Offset: 0x390
	// Line 4266, Address: 0x147454, Func Offset: 0x394
	// Line 4263, Address: 0x147458, Func Offset: 0x398
	// Line 4267, Address: 0x147464, Func Offset: 0x3a4
	// Line 4264, Address: 0x147468, Func Offset: 0x3a8
	// Line 4275, Address: 0x147470, Func Offset: 0x3b0
	// Line 4264, Address: 0x147474, Func Offset: 0x3b4
	// Line 4265, Address: 0x147480, Func Offset: 0x3c0
	// Line 4266, Address: 0x147494, Func Offset: 0x3d4
	// Line 4267, Address: 0x1474a8, Func Offset: 0x3e8
	// Line 4268, Address: 0x1474bc, Func Offset: 0x3fc
	// Line 4269, Address: 0x1474d0, Func Offset: 0x410
	// Line 4270, Address: 0x1474e4, Func Offset: 0x424
	// Line 4271, Address: 0x147504, Func Offset: 0x444
	// Line 4272, Address: 0x147524, Func Offset: 0x464
	// Line 4273, Address: 0x147544, Func Offset: 0x484
	// Line 4274, Address: 0x147558, Func Offset: 0x498
	// Line 4276, Address: 0x14756c, Func Offset: 0x4ac
	// Line 4280, Address: 0x147574, Func Offset: 0x4b4
	// Line 4276, Address: 0x147580, Func Offset: 0x4c0
	// Line 4280, Address: 0x147598, Func Offset: 0x4d8
	// Line 4282, Address: 0x1475e0, Func Offset: 0x520
	// Line 4283, Address: 0x1475f0, Func Offset: 0x530
	// Line 4282, Address: 0x1475f4, Func Offset: 0x534
	// Line 4283, Address: 0x147604, Func Offset: 0x544
	// Line 4282, Address: 0x147608, Func Offset: 0x548
	// Line 4283, Address: 0x147614, Func Offset: 0x554
	// Line 4284, Address: 0x147620, Func Offset: 0x560
	// Line 4287, Address: 0x147650, Func Offset: 0x590
	// Line 4288, Address: 0x147658, Func Offset: 0x598
	// Line 4290, Address: 0x147668, Func Offset: 0x5a8
	// Line 4291, Address: 0x147678, Func Offset: 0x5b8
	// Line 4295, Address: 0x147698, Func Offset: 0x5d8
	// Line 4297, Address: 0x1476ec, Func Offset: 0x62c
	// Line 4298, Address: 0x147704, Func Offset: 0x644
	// Line 4299, Address: 0x14771c, Func Offset: 0x65c
	// Line 4302, Address: 0x147748, Func Offset: 0x688
	// Line 4303, Address: 0x147784, Func Offset: 0x6c4
	// Line 4304, Address: 0x147798, Func Offset: 0x6d8
	// Line 4305, Address: 0x1477ac, Func Offset: 0x6ec
	// Line 4307, Address: 0x1477c4, Func Offset: 0x704
	// Line 4308, Address: 0x1477cc, Func Offset: 0x70c
	// Line 4309, Address: 0x1477d4, Func Offset: 0x714
	// Line 4314, Address: 0x1477ec, Func Offset: 0x72c
	// Line 4315, Address: 0x147828, Func Offset: 0x768
	// Line 4317, Address: 0x147854, Func Offset: 0x794
	// Line 4321, Address: 0x14786c, Func Offset: 0x7ac
	// Line 4323, Address: 0x1478c0, Func Offset: 0x800
	// Line 4325, Address: 0x1478d8, Func Offset: 0x818
	// Line 4326, Address: 0x14790c, Func Offset: 0x84c
	// Line 4328, Address: 0x147940, Func Offset: 0x880
	// Line 4329, Address: 0x147944, Func Offset: 0x884
	// Line 4331, Address: 0x147950, Func Offset: 0x890
	// Line 4336, Address: 0x147954, Func Offset: 0x894
	// Line 4329, Address: 0x147958, Func Offset: 0x898
	// Line 4330, Address: 0x14795c, Func Offset: 0x89c
	// Line 4331, Address: 0x147968, Func Offset: 0x8a8
	// Line 4332, Address: 0x147974, Func Offset: 0x8b4
	// Line 4333, Address: 0x147980, Func Offset: 0x8c0
	// Line 4334, Address: 0x14798c, Func Offset: 0x8cc
	// Line 4335, Address: 0x147998, Func Offset: 0x8d8
	// Line 4336, Address: 0x1479a0, Func Offset: 0x8e0
	// Line 4337, Address: 0x1479a8, Func Offset: 0x8e8
	// Line 4338, Address: 0x1479b8, Func Offset: 0x8f8
	// Line 4340, Address: 0x1479c0, Func Offset: 0x900
	// Line 4342, Address: 0x1479f4, Func Offset: 0x934
	// Line 4343, Address: 0x1479f8, Func Offset: 0x938
	// Line 4344, Address: 0x147a04, Func Offset: 0x944
	// Line 4346, Address: 0x147a0c, Func Offset: 0x94c
	// Line 4347, Address: 0x147a10, Func Offset: 0x950
	// Line 4348, Address: 0x147a1c, Func Offset: 0x95c
	// Line 4350, Address: 0x147a24, Func Offset: 0x964
	// Line 4351, Address: 0x147a28, Func Offset: 0x968
	// Line 4354, Address: 0x147a38, Func Offset: 0x978
	// Line 4359, Address: 0x147a44, Func Offset: 0x984
	// Func End, Address: 0x147a58, Func Offset: 0x998
    scePrintf("bhCPM2_act_rld - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCPM2_act_knf()
{
    switch (plp->mode3) 
    {
    case 0:
        plp->flg |= 0xC0000;
        
        switch (plp->at_flg & 0xE)
        {
        case 2:
            plp->mtn_no = 103;
            break;
        case 4:
            plp->mtn_no = 108;
            break;
        case 8:
            plp->mtn_no = 113;
            break;
        }
        
        plp->hokan_rate = 45875;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        plp->mode3++;
    case 1:
        if ((plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->hokan_count = 1;
                
                plp->mode2 = 65;
                break;
            case 4:
                plp->hokan_count = 1;
                
                plp->mode2 = 66;
                break;
            case 8:
                plp->hokan_count = 1;
                
                plp->mode2 = 67;
                break;
            }
            
            plp->mode3 = 0;
        }
        
        return;
    }
}

// 100% matching!
void bhCPM0_damage()
{
	float* trsz;

    sys->st_flg |= 0x4;
    
    plp->flg |= 0x200000;
    
    switch (plp->mode1)
    { 
    case 0:
        switch (plp->mode3)
        {
        case 0: 
            plp->flg |= 0x10000;
            plp->flg &= ~0x36940000;
            
            plp->stflg &= ~0x80;
            plp->stflg |= 0x10000;
            
            EXP1_I(0) &= ~0x4;
            EXP1_I(0) |= 0x1E0;
            
            plp->mtn_no = (plp->mode2 * 2) + 71;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 1;
            
            ((EXP_WORK*)plp->exp0)->arp = -(1.0f + plp->mode2);
            
            if (plp->mode2 < 2) 
            {
                CallPlayerVoice(1026);
            }
            else 
            {
                CallPlayerVoice(1027);
            }
        
            break;
        case 1:    
            if ((plp->flg & 0x400000))
            {
                plp->flg   &= ~0x10004;
                plp->stflg &= ~0x10000;
                
                *(int*)&plp->mode0 = 1;
                return;
            }
            
            trsz = bhGetTransZ((plp->mode2 * 2) + 11);
            
            plp->spd = trsz[plp->frm_no / 65536];
                
            bhAddSpeed(plp, 0);
        }
        
        break;
    case 1:  
        switch (plp->mode3)
        {
        case 0:
            plp->flg |= 0x10000;
            plp->flg &= ~0x36940000;
            
            plp->stflg &= ~0x80;
            plp->stflg |= 0x10000;
            
            EXP1_I(0) &= ~0x4;
            EXP1_I(0) |= 0x1E0;
            
            plp->mtn_no = (plp->mode2 * 2) + 72;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 1;
            
            ((EXP_WORK*)plp->exp0)->arp = 1.0f + plp->mode2;
            
            CallPlayerVoice(1024);
            break;
        case 1:
            if ((plp->flg & 0x400000)) 
            {
                plp->flg   &= ~0x10004;
                plp->stflg &= ~0x10000;
                
                *(int*)&plp->mode0 = 1;
                return;
            }
            
            trsz = bhGetTransZ((plp->mode2 * 2) + 12);
            
            plp->spd = trsz[plp->frm_no / 65536];
            
            bhAddSpeed(plp, 0);
        }
    }

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
            
            sys->pt_flg |= 0x1;
        }
    }
}

// 100% matching!
void bhCPM0_die()
{
    NJS_POINT3 pos; 
    float gy;
    float* trsz;

    sys->st_flg |= 0x4;
    
    plp->flg2 |= 0x1;
    
    switch (plp->mode1)
    {   
    case 0:
        switch (plp->mode3)
        { 
        case 0:
            sys->fade_an = 0;
            sys->fade_rn = 0;
            sys->fade_gn = 0;
            sys->fade_bn = 0;
            
            plp->flg |=  0x10002;
            plp->flg &= ~0x36940000;
            
            plp->stflg |= 0x10000;
            plp->flg   |= 0x10;
            
            EXP1_I(0) &= ~0x4;
            EXP1_I(0) |= 0x1E0;
            
            plp->mtn_no = 25;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 1;
            
            ((EXP_WORK*)plp->exp0)->arp = 3.0f;
            
            plp->yn = 0;
            
            CallPlayerVoice(1025);
            break;
        case 1:      
            pos.x = plp->mlwP->owP[2].mtx[12];
            pos.y = 1.0f + plp->mlwP->owP[2].mtx[13];
            pos.z = plp->mlwP->owP[2].mtx[14];
            
            gy = bhGetGroundPosition(&pos);
            
            if (rom->grand[plp->flr_no + 2] < gy)
            {
                gy = rom->grand[plp->flr_no + 2];
            }
            
            if (gy < plp->py)
            {
                plp->py += plp->yn;
                
                if (plp->yn > -2.0f) 
                {
                    plp->yn -= 0.2f;
                }
            }
            
            if (gy >= plp->py) 
            {
                plp->py = gy;
            }
            
            if ((plp->frm_no / 65536) == 0)
            {
                if ((sys->ts_flg & 0x4000))
                {
                    sys->ts_flg &= ~0x4000;
                    
                    *(unsigned int*)&sys->gov_md0 = 0;
                }
                
                plp->mtn_no = 26;
                
                plp->mode3 = 2;
                
                plp->hokan_rate = 49152;
                plp->hokan_count = 4;
            }
            else 
            {
                trsz = bhGetTransZ(17);
                
                plp->spd = trsz[plp->frm_no / 65536];
                
                bhAddSpeed(plp, 0);
            }
            
            break;
        case 2:  
            pos.x = plp->mlwP->owP[2].mtx[12];
            pos.y = 1.0f + plp->mlwP->owP[2].mtx[13];
            pos.z = plp->mlwP->owP[2].mtx[14];
            
            gy = bhGetGroundPosition(&pos);
            
            if (rom->grand[plp->flr_no + 2] < gy)
            {
                gy = rom->grand[plp->flr_no + 2];
            }
            
            if (gy >= plp->py) 
            {
                plp->py = gy;
            }
        }
        
        break;
    case 1:        
        switch (plp->mode3)
        {         
        case 0:       
            sys->fade_an = 0;
            sys->fade_rn = 0;
            sys->fade_gn = 0;
            sys->fade_bn = 0;
            
            plp->flg |=  0x10002;
            plp->flg &= ~0x36940000;
            
            plp->stflg |= 0x10000;
            plp->flg   |= 0x10;
            
            EXP1_I(0) &= ~0x4;
            EXP1_I(0) |= 0x1E0;
            
            plp->mtn_no = 27;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 1;

            ((EXP_WORK*)plp->exp0)->arp = -3.0f;
            
            plp->yn = 0;
            
            CallPlayerVoice(1025);
            break;
        case 1:          
            pos.x = plp->mlwP->owP[2].mtx[12];
            pos.y = 1.0f + plp->mlwP->owP[2].mtx[13];
            pos.z = plp->mlwP->owP[2].mtx[14];
            
            gy = bhGetGroundPosition(&pos);
            
            if (rom->grand[plp->flr_no + 2] < gy)
            {
                gy = rom->grand[plp->flr_no + 2];
            }
            
            if (gy < plp->py)
            {
                plp->py += plp->yn;
                
                if (plp->yn > -2.0f) 
                {
                    plp->yn -= 0.2f;
                }
            }
            
            if (gy >= plp->py) 
            {
                plp->py = gy;
            }
            
            if ((plp->frm_no / 65536) == 0)
            {
                if ((sys->ts_flg & 0x4000)) 
                {
                    sys->ts_flg &= ~0x4000;
                    
                    *(unsigned int*)&sys->gov_md0 = 0;
                }
                
                plp->mtn_no = 28;
                
                plp->mode3 = 2;
                
                plp->hokan_rate = 49152;
                plp->hokan_count = 4;
            } 
            else 
            {
                trsz = bhGetTransZ(18);
                
                plp->spd = trsz[plp->frm_no / 65536];
                
                bhAddSpeed(plp, 0);
            }
            
            break;
        case 2:              
            pos.x = plp->mlwP->owP[2].mtx[12];
            pos.y = 1.0f + plp->mlwP->owP[2].mtx[13];
            pos.z = plp->mlwP->owP[2].mtx[14];
            
            gy = bhGetGroundPosition(&pos);
            
            if (rom->grand[plp->flr_no + 2] < gy)
            {
                gy = rom->grand[plp->flr_no + 2];
            }
            
            if (gy >= plp->py) 
            {
                plp->py = gy;
            }
            
            break;
        }
    }
    
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
            
            sys->pt_flg |= 0x1;
        }
    }
}

// 100% matching!
void bhCPM0_nage() 
{
    if ((EXP1_I(0) & 0x4))
    {
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
    }
    
    sys->st_flg |= 0x4;
    
    ((EXP_WORK*)plp->exp0)->spx = plp->px;
    ((EXP_WORK*)plp->exp0)->spz = plp->pz;
    
    ((EXP_WORK*)plp->exp0)->arp = 0;
    
    plp->flg &= ~0x36900000;
    
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
            
            sys->pt_flg |= 0x1;
        }
    }
}

// 100% matching!
void bhCPM0_enedam() 
{
    if ((EXP1_I(0) & 0x4))
    {
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
    }
    
    sys->st_flg |= 0x4;
    
    ((EXP_WORK*)plp->exp0)->spx = plp->px;
    ((EXP_WORK*)plp->exp0)->spz = plp->pz;
    
    ((EXP_WORK*)plp->exp0)->arp = 0;
    
    plp->flg &= ~0x36900000;
    
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
            
            sys->pt_flg |= 0x1;
        }
    }
}

// 100% matching!
void bhCPM0_enedie() 
{
    if ((EXP1_I(0) & 0x4))
    {
        EXP1_I(0) &= ~0x4;
        EXP1_I(0) |= 0x1E0;
    }
    
    sys->st_flg |= 0x4;
    
    ((EXP_WORK*)plp->exp0)->spx = plp->px;
    ((EXP_WORK*)plp->exp0)->spz = plp->pz;
    
    ((EXP_WORK*)plp->exp0)->arp = 0;
    
    plp->flg &= ~0x36900000;
    
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
            
            sys->pt_flg |= 0x1;
        }
    }
    
    if (((plp->flg & 0x2)) && ((sys->ts_flg & 0x4000))) 
    {
        sys->ts_flg &= ~0x4000;
        
        *(int*)&sys->gov_md0 = 0;
    }
}

// 100% matching!
void bhCPM0_nothing()
{
    switch (plp->mode3)
    {
    case 0:
        plp->mtn_no = 218;
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        plp->mode3++;
    case 1:
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1)) 
        {
            plp->frm_no = (plp->mnwP[plp->mtn_no].frm_num - 1) * 65536;
            
            plp->mtn_add = 0;
        }
    }
}

// 
// Start address: 0x1490b0
void bhControlPlayerHead()
{
	short pay;
	short pax;
	short lay;
	short lax;
	short az;
	short ay;
	short ax;
	// Line 4894, Address: 0x1490b0, Func Offset: 0
	// Line 4899, Address: 0x1490c4, Func Offset: 0x14
	// Line 4900, Address: 0x1490d0, Func Offset: 0x20
	// Line 4899, Address: 0x1490d4, Func Offset: 0x24
	// Line 4900, Address: 0x1490dc, Func Offset: 0x2c
	// Line 4901, Address: 0x1490e4, Func Offset: 0x34
	// Line 4900, Address: 0x1490e8, Func Offset: 0x38
	// Line 4901, Address: 0x1490f0, Func Offset: 0x40
	// Line 4903, Address: 0x1490f8, Func Offset: 0x48
	// Line 4901, Address: 0x1490fc, Func Offset: 0x4c
	// Line 4903, Address: 0x149104, Func Offset: 0x54
	// Line 4904, Address: 0x14910c, Func Offset: 0x5c
	// Line 4903, Address: 0x149110, Func Offset: 0x60
	// Line 4904, Address: 0x149118, Func Offset: 0x68
	// Line 4905, Address: 0x149120, Func Offset: 0x70
	// Line 4904, Address: 0x149124, Func Offset: 0x74
	// Line 4905, Address: 0x14912c, Func Offset: 0x7c
	// Line 4907, Address: 0x149134, Func Offset: 0x84
	// Line 4905, Address: 0x149138, Func Offset: 0x88
	// Line 4907, Address: 0x149140, Func Offset: 0x90
	// Line 4910, Address: 0x149144, Func Offset: 0x94
	// Line 4907, Address: 0x149148, Func Offset: 0x98
	// Line 4909, Address: 0x14914c, Func Offset: 0x9c
	// Line 4908, Address: 0x149150, Func Offset: 0xa0
	// Line 4910, Address: 0x149154, Func Offset: 0xa4
	// Line 4924, Address: 0x149158, Func Offset: 0xa8
	// Line 4910, Address: 0x14915c, Func Offset: 0xac
	// Line 4912, Address: 0x149160, Func Offset: 0xb0
	// Line 4911, Address: 0x149164, Func Offset: 0xb4
	// Line 4913, Address: 0x149168, Func Offset: 0xb8
	// Line 4914, Address: 0x14916c, Func Offset: 0xbc
	// Line 4915, Address: 0x149170, Func Offset: 0xc0
	// Line 4910, Address: 0x149174, Func Offset: 0xc4
	// Line 4924, Address: 0x149178, Func Offset: 0xc8
	// Line 4912, Address: 0x14917c, Func Offset: 0xcc
	// Line 4916, Address: 0x149180, Func Offset: 0xd0
	// Line 4911, Address: 0x149184, Func Offset: 0xd4
	// Line 4918, Address: 0x149188, Func Offset: 0xd8
	// Line 4910, Address: 0x14918c, Func Offset: 0xdc
	// Line 4912, Address: 0x149190, Func Offset: 0xe0
	// Line 4910, Address: 0x149194, Func Offset: 0xe4
	// Line 4913, Address: 0x149198, Func Offset: 0xe8
	// Line 4917, Address: 0x14919c, Func Offset: 0xec
	// Line 4911, Address: 0x1491a0, Func Offset: 0xf0
	// Line 4913, Address: 0x1491a4, Func Offset: 0xf4
	// Line 4911, Address: 0x1491a8, Func Offset: 0xf8
	// Line 4914, Address: 0x1491ac, Func Offset: 0xfc
	// Line 4919, Address: 0x1491b0, Func Offset: 0x100
	// Line 4914, Address: 0x1491b4, Func Offset: 0x104
	// Line 4912, Address: 0x1491b8, Func Offset: 0x108
	// Line 4915, Address: 0x1491bc, Func Offset: 0x10c
	// Line 4920, Address: 0x1491c0, Func Offset: 0x110
	// Line 4915, Address: 0x1491c4, Func Offset: 0x114
	// Line 4913, Address: 0x1491cc, Func Offset: 0x11c
	// Line 4914, Address: 0x1491d0, Func Offset: 0x120
	// Line 4918, Address: 0x1491d4, Func Offset: 0x124
	// Line 4921, Address: 0x1491d8, Func Offset: 0x128
	// Line 4916, Address: 0x1491dc, Func Offset: 0x12c
	// Line 4917, Address: 0x1491e0, Func Offset: 0x130
	// Line 4918, Address: 0x1491e4, Func Offset: 0x134
	// Line 4916, Address: 0x1491e8, Func Offset: 0x138
	// Line 4917, Address: 0x1491ec, Func Offset: 0x13c
	// Line 4918, Address: 0x1491f0, Func Offset: 0x140
	// Line 4916, Address: 0x1491f4, Func Offset: 0x144
	// Line 4917, Address: 0x1491f8, Func Offset: 0x148
	// Line 4921, Address: 0x1491fc, Func Offset: 0x14c
	// Line 4919, Address: 0x149204, Func Offset: 0x154
	// Line 4920, Address: 0x149208, Func Offset: 0x158
	// Line 4919, Address: 0x14920c, Func Offset: 0x15c
	// Line 4920, Address: 0x149210, Func Offset: 0x160
	// Line 4924, Address: 0x149214, Func Offset: 0x164
	// Line 4919, Address: 0x149218, Func Offset: 0x168
	// Line 4920, Address: 0x14921c, Func Offset: 0x16c
	// Line 4924, Address: 0x149220, Func Offset: 0x170
	// Line 4927, Address: 0x149228, Func Offset: 0x178
	// Line 4928, Address: 0x149234, Func Offset: 0x184
	// Line 4929, Address: 0x14923c, Func Offset: 0x18c
	// Line 4928, Address: 0x149240, Func Offset: 0x190
	// Line 4929, Address: 0x149248, Func Offset: 0x198
	// Line 4930, Address: 0x14926c, Func Offset: 0x1bc
	// Line 4931, Address: 0x149274, Func Offset: 0x1c4
	// Line 4932, Address: 0x14927c, Func Offset: 0x1cc
	// Line 4931, Address: 0x149280, Func Offset: 0x1d0
	// Line 4932, Address: 0x149288, Func Offset: 0x1d8
	// Line 4934, Address: 0x1492b0, Func Offset: 0x200
	// Line 4936, Address: 0x1492bc, Func Offset: 0x20c
	// Line 4934, Address: 0x1492c0, Func Offset: 0x210
	// Line 4936, Address: 0x1492d0, Func Offset: 0x220
	// Line 4937, Address: 0x1492e8, Func Offset: 0x238
	// Line 4938, Address: 0x1492f0, Func Offset: 0x240
	// Line 4937, Address: 0x1492f4, Func Offset: 0x244
	// Line 4938, Address: 0x1492fc, Func Offset: 0x24c
	// Line 4939, Address: 0x149320, Func Offset: 0x270
	// Line 4940, Address: 0x149328, Func Offset: 0x278
	// Line 4941, Address: 0x149330, Func Offset: 0x280
	// Line 4940, Address: 0x149334, Func Offset: 0x284
	// Line 4941, Address: 0x14933c, Func Offset: 0x28c
	// Line 4943, Address: 0x149364, Func Offset: 0x2b4
	// Line 4945, Address: 0x14937c, Func Offset: 0x2cc
	// Line 4947, Address: 0x149384, Func Offset: 0x2d4
	// Line 4948, Address: 0x149394, Func Offset: 0x2e4
	// Line 4952, Address: 0x1493a8, Func Offset: 0x2f8
	// Line 4955, Address: 0x1493e4, Func Offset: 0x334
	// Line 4956, Address: 0x1493f0, Func Offset: 0x340
	// Line 4957, Address: 0x149400, Func Offset: 0x350
	// Line 4958, Address: 0x14941c, Func Offset: 0x36c
	// Line 4959, Address: 0x14942c, Func Offset: 0x37c
	// Line 4960, Address: 0x149448, Func Offset: 0x398
	// Line 4961, Address: 0x149458, Func Offset: 0x3a8
	// Line 4962, Address: 0x149474, Func Offset: 0x3c4
	// Line 4964, Address: 0x149480, Func Offset: 0x3d0
	// Line 4965, Address: 0x149488, Func Offset: 0x3d8
	// Line 4966, Address: 0x149494, Func Offset: 0x3e4
	// Line 4967, Address: 0x14949c, Func Offset: 0x3ec
	// Line 4968, Address: 0x1494b8, Func Offset: 0x408
	// Line 4969, Address: 0x1494c8, Func Offset: 0x418
	// Line 4970, Address: 0x1494e4, Func Offset: 0x434
	// Line 4971, Address: 0x1494f4, Func Offset: 0x444
	// Line 4972, Address: 0x149510, Func Offset: 0x460
	// Line 4975, Address: 0x149520, Func Offset: 0x470
	// Line 4976, Address: 0x14953c, Func Offset: 0x48c
	// Line 4977, Address: 0x149540, Func Offset: 0x490
	// Line 4976, Address: 0x149544, Func Offset: 0x494
	// Line 4978, Address: 0x14954c, Func Offset: 0x49c
	// Line 4979, Address: 0x149568, Func Offset: 0x4b8
	// Line 4980, Address: 0x149590, Func Offset: 0x4e0
	// Line 4981, Address: 0x149594, Func Offset: 0x4e4
	// Line 4979, Address: 0x14959c, Func Offset: 0x4ec
	// Line 4981, Address: 0x1495a0, Func Offset: 0x4f0
	// Line 4982, Address: 0x1495a8, Func Offset: 0x4f8
	// Line 4983, Address: 0x1495b0, Func Offset: 0x500
	// Line 4987, Address: 0x1495c0, Func Offset: 0x510
	// Line 4988, Address: 0x1495dc, Func Offset: 0x52c
	// Line 4989, Address: 0x1495e0, Func Offset: 0x530
	// Line 4988, Address: 0x1495e4, Func Offset: 0x534
	// Line 4990, Address: 0x1495ec, Func Offset: 0x53c
	// Line 4991, Address: 0x149608, Func Offset: 0x558
	// Line 4992, Address: 0x149630, Func Offset: 0x580
	// Line 4993, Address: 0x149634, Func Offset: 0x584
	// Line 4991, Address: 0x14963c, Func Offset: 0x58c
	// Line 4993, Address: 0x149640, Func Offset: 0x590
	// Line 4994, Address: 0x149648, Func Offset: 0x598
	// Line 4995, Address: 0x149650, Func Offset: 0x5a0
	// Line 5000, Address: 0x149660, Func Offset: 0x5b0
	// Line 5005, Address: 0x14966c, Func Offset: 0x5bc
	// Line 5000, Address: 0x149670, Func Offset: 0x5c0
	// Line 5001, Address: 0x149678, Func Offset: 0x5c8
	// Line 5002, Address: 0x14967c, Func Offset: 0x5cc
	// Line 5005, Address: 0x149680, Func Offset: 0x5d0
	// Line 5000, Address: 0x149684, Func Offset: 0x5d4
	// Line 5001, Address: 0x149688, Func Offset: 0x5d8
	// Line 5002, Address: 0x14968c, Func Offset: 0x5dc
	// Line 5000, Address: 0x149690, Func Offset: 0x5e0
	// Line 5001, Address: 0x149694, Func Offset: 0x5e4
	// Line 5002, Address: 0x149698, Func Offset: 0x5e8
	// Line 5005, Address: 0x14969c, Func Offset: 0x5ec
	// Line 5000, Address: 0x1496a0, Func Offset: 0x5f0
	// Line 5001, Address: 0x1496a4, Func Offset: 0x5f4
	// Line 5005, Address: 0x1496a8, Func Offset: 0x5f8
	// Line 5007, Address: 0x1496b0, Func Offset: 0x600
	// Line 5008, Address: 0x1496b4, Func Offset: 0x604
	// Line 5007, Address: 0x1496b8, Func Offset: 0x608
	// Line 5008, Address: 0x1496bc, Func Offset: 0x60c
	// Line 5009, Address: 0x1496d0, Func Offset: 0x620
	// Line 5012, Address: 0x1496d8, Func Offset: 0x628
	// Line 5013, Address: 0x1496e8, Func Offset: 0x638
	// Line 5014, Address: 0x1496ec, Func Offset: 0x63c
	// Line 5015, Address: 0x1496f0, Func Offset: 0x640
	// Line 5016, Address: 0x14970c, Func Offset: 0x65c
	// Line 5017, Address: 0x149734, Func Offset: 0x684
	// Line 5018, Address: 0x149738, Func Offset: 0x688
	// Line 5016, Address: 0x149740, Func Offset: 0x690
	// Line 5018, Address: 0x149744, Func Offset: 0x694
	// Line 5019, Address: 0x14974c, Func Offset: 0x69c
	// Line 5020, Address: 0x149754, Func Offset: 0x6a4
	// Line 5024, Address: 0x149764, Func Offset: 0x6b4
	// Line 5025, Address: 0x149780, Func Offset: 0x6d0
	// Line 5026, Address: 0x149784, Func Offset: 0x6d4
	// Line 5025, Address: 0x149788, Func Offset: 0x6d8
	// Line 5027, Address: 0x149790, Func Offset: 0x6e0
	// Line 5028, Address: 0x1497ac, Func Offset: 0x6fc
	// Line 5029, Address: 0x1497d4, Func Offset: 0x724
	// Line 5030, Address: 0x1497d8, Func Offset: 0x728
	// Line 5028, Address: 0x1497e0, Func Offset: 0x730
	// Line 5030, Address: 0x1497e4, Func Offset: 0x734
	// Line 5031, Address: 0x1497ec, Func Offset: 0x73c
	// Line 5032, Address: 0x1497f4, Func Offset: 0x744
	// Line 5038, Address: 0x149804, Func Offset: 0x754
	// Line 5049, Address: 0x14980c, Func Offset: 0x75c
	// Line 5038, Address: 0x149810, Func Offset: 0x760
	// Line 5043, Address: 0x149814, Func Offset: 0x764
	// Line 5038, Address: 0x149818, Func Offset: 0x768
	// Line 5042, Address: 0x14981c, Func Offset: 0x76c
	// Line 5038, Address: 0x149820, Func Offset: 0x770
	// Line 5039, Address: 0x149824, Func Offset: 0x774
	// Line 5038, Address: 0x149828, Func Offset: 0x778
	// Line 5040, Address: 0x14982c, Func Offset: 0x77c
	// Line 5039, Address: 0x149830, Func Offset: 0x780
	// Line 5042, Address: 0x149834, Func Offset: 0x784
	// Line 5043, Address: 0x149838, Func Offset: 0x788
	// Line 5040, Address: 0x14983c, Func Offset: 0x78c
	// Line 5043, Address: 0x149840, Func Offset: 0x790
	// Line 5044, Address: 0x149844, Func Offset: 0x794
	// Line 5043, Address: 0x149848, Func Offset: 0x798
	// Line 5044, Address: 0x14984c, Func Offset: 0x79c
	// Line 5045, Address: 0x149854, Func Offset: 0x7a4
	// Line 5044, Address: 0x149858, Func Offset: 0x7a8
	// Line 5045, Address: 0x14985c, Func Offset: 0x7ac
	// Line 5046, Address: 0x149864, Func Offset: 0x7b4
	// Line 5045, Address: 0x149868, Func Offset: 0x7b8
	// Line 5046, Address: 0x149878, Func Offset: 0x7c8
	// Line 5047, Address: 0x149880, Func Offset: 0x7d0
	// Line 5046, Address: 0x149884, Func Offset: 0x7d4
	// Line 5047, Address: 0x149894, Func Offset: 0x7e4
	// Line 5049, Address: 0x14989c, Func Offset: 0x7ec
	// Line 5047, Address: 0x1498a0, Func Offset: 0x7f0
	// Line 5049, Address: 0x1498b0, Func Offset: 0x800
	// Line 5050, Address: 0x1498c0, Func Offset: 0x810
	// Line 5051, Address: 0x149934, Func Offset: 0x884
	// Line 5052, Address: 0x149938, Func Offset: 0x888
	// Line 5051, Address: 0x14993c, Func Offset: 0x88c
	// Line 5052, Address: 0x149944, Func Offset: 0x894
	// Line 5053, Address: 0x14994c, Func Offset: 0x89c
	// Line 5052, Address: 0x149950, Func Offset: 0x8a0
	// Line 5053, Address: 0x149954, Func Offset: 0x8a4
	// Line 5054, Address: 0x14995c, Func Offset: 0x8ac
	// Line 5055, Address: 0x149964, Func Offset: 0x8b4
	// Line 5061, Address: 0x149990, Func Offset: 0x8e0
	// Line 5062, Address: 0x1499ac, Func Offset: 0x8fc
	// Line 5063, Address: 0x1499b4, Func Offset: 0x904
	// Line 5062, Address: 0x1499b8, Func Offset: 0x908
	// Line 5063, Address: 0x1499d8, Func Offset: 0x928
	// Line 5064, Address: 0x1499f0, Func Offset: 0x940
	// Line 5065, Address: 0x1499f4, Func Offset: 0x944
	// Line 5064, Address: 0x1499f8, Func Offset: 0x948
	// Line 5065, Address: 0x149a00, Func Offset: 0x950
	// Line 5066, Address: 0x149a18, Func Offset: 0x968
	// Line 5067, Address: 0x149a20, Func Offset: 0x970
	// Line 5066, Address: 0x149a24, Func Offset: 0x974
	// Line 5067, Address: 0x149a2c, Func Offset: 0x97c
	// Line 5068, Address: 0x149a34, Func Offset: 0x984
	// Line 5067, Address: 0x149a38, Func Offset: 0x988
	// Line 5068, Address: 0x149a3c, Func Offset: 0x98c
	// Line 5069, Address: 0x149a44, Func Offset: 0x994
	// Line 5068, Address: 0x149a48, Func Offset: 0x998
	// Line 5069, Address: 0x149a4c, Func Offset: 0x99c
	// Line 5073, Address: 0x149a5c, Func Offset: 0x9ac
	// Func End, Address: 0x149a74, Func Offset: 0x9c4
	scePrintf("bhControlPlayerHead - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhLookNearEnemy()
{    
    float h; 
    int ay; 
    int id; 

    ay = 23665;
    
    h = EXP1_F(16) - plp->py;
    
    if (bhSearchNearEnemy2(plp, &ay, &h, &id) != 0)
    {
        if (EXP1_I(60) > 30)
        {
            if (EXP1_S(68) != id)
            {
                EXP1_I(60) = 0;
            }
            
            EXP1_I(0) |= 0x10;
            
            EXP1_I(64) = 2;
            EXP1_S(68) = id;
            
            EXP1_S(70) = ene[id].lok_jno;
        }
    } 
    else if ((EXP1_I(0) & 0x10))
    {
        EXP1_I(0) |= 0x1E0;
        
        EXP1_I(0) &= ~0x10;
        
        EXP1_S(68) = -1;
        EXP1_I(60) = 0;
    }
    
    if (EXP1_I(60) < 1024)
    {
        EXP1_I(60)++;
    }
}

// 
// Start address: 0x149c10
void bhSetHeadRotation(short ax, short ay)
{
	short pay;
	short pax;
	short lay;
	short lax;
	int ono;
	float lpz;
	float lpy;
	float lpx;
	float pz;
	float py;
	float px;
	//_anon4* psp;
	BH_PWORK* pwp;
	// Line 5111, Address: 0x149c10, Func Offset: 0
	// Line 5119, Address: 0x149c2c, Func Offset: 0x1c
	// Line 5120, Address: 0x149c40, Func Offset: 0x30
	// Line 5119, Address: 0x149c44, Func Offset: 0x34
	// Line 5120, Address: 0x149c48, Func Offset: 0x38
	// Line 5122, Address: 0x149c70, Func Offset: 0x60
	// Line 5123, Address: 0x149c74, Func Offset: 0x64
	// Line 5124, Address: 0x149c80, Func Offset: 0x70
	// Line 5125, Address: 0x149c84, Func Offset: 0x74
	// Line 5126, Address: 0x149c88, Func Offset: 0x78
	// Line 5128, Address: 0x149c90, Func Offset: 0x80
	// Line 5129, Address: 0x149cb8, Func Offset: 0xa8
	// Line 5130, Address: 0x149ce4, Func Offset: 0xd4
	// Line 5132, Address: 0x149cec, Func Offset: 0xdc
	// Line 5133, Address: 0x149d0c, Func Offset: 0xfc
	// Line 5134, Address: 0x149d44, Func Offset: 0x134
	// Line 5136, Address: 0x149d4c, Func Offset: 0x13c
	// Line 5137, Address: 0x149d6c, Func Offset: 0x15c
	// Line 5138, Address: 0x149da4, Func Offset: 0x194
	// Line 5140, Address: 0x149dac, Func Offset: 0x19c
	// Line 5141, Address: 0x149dcc, Func Offset: 0x1bc
	// Line 5142, Address: 0x149e14, Func Offset: 0x204
	// Line 5144, Address: 0x149e1c, Func Offset: 0x20c
	// Line 5145, Address: 0x149e20, Func Offset: 0x210
	// Line 5146, Address: 0x149e50, Func Offset: 0x240
	// Line 5147, Address: 0x149e74, Func Offset: 0x264
	// Line 5148, Address: 0x149e78, Func Offset: 0x268
	// Line 5149, Address: 0x149e7c, Func Offset: 0x26c
	// Line 5152, Address: 0x149e84, Func Offset: 0x274
	// Line 5153, Address: 0x149eac, Func Offset: 0x29c
	// Line 5155, Address: 0x149eb4, Func Offset: 0x2a4
	// Line 5156, Address: 0x149eb8, Func Offset: 0x2a8
	// Line 5157, Address: 0x149ebc, Func Offset: 0x2ac
	// Line 5158, Address: 0x149ec4, Func Offset: 0x2b4
	// Line 5159, Address: 0x149ee0, Func Offset: 0x2d0
	// Line 5160, Address: 0x149ee4, Func Offset: 0x2d4
	// Line 5164, Address: 0x149eec, Func Offset: 0x2dc
	// Line 5165, Address: 0x149ef0, Func Offset: 0x2e0
	// Line 5166, Address: 0x149ef4, Func Offset: 0x2e4
	// Line 5164, Address: 0x149ef8, Func Offset: 0x2e8
	// Line 5165, Address: 0x149efc, Func Offset: 0x2ec
	// Line 5167, Address: 0x149f00, Func Offset: 0x2f0
	// Line 5166, Address: 0x149f0c, Func Offset: 0x2fc
	// Line 5167, Address: 0x149f10, Func Offset: 0x300
	// Line 5169, Address: 0x149f54, Func Offset: 0x344
	// Line 5170, Address: 0x149f58, Func Offset: 0x348
	// Line 5171, Address: 0x149f64, Func Offset: 0x354
	// Line 5170, Address: 0x149f68, Func Offset: 0x358
	// Line 5171, Address: 0x149f6c, Func Offset: 0x35c
	// Line 5172, Address: 0x149f74, Func Offset: 0x364
	// Line 5173, Address: 0x149f7c, Func Offset: 0x36c
	// Line 5174, Address: 0x149f8c, Func Offset: 0x37c
	// Line 5175, Address: 0x149f90, Func Offset: 0x380
	// Line 5178, Address: 0x149f98, Func Offset: 0x388
	// Line 5179, Address: 0x149fa4, Func Offset: 0x394
	// Line 5178, Address: 0x149fa8, Func Offset: 0x398
	// Line 5179, Address: 0x149fac, Func Offset: 0x39c
	// Line 5180, Address: 0x149fb0, Func Offset: 0x3a0
	// Line 5182, Address: 0x149fbc, Func Offset: 0x3ac
	// Line 5183, Address: 0x149ff8, Func Offset: 0x3e8
	// Line 5184, Address: 0x14a008, Func Offset: 0x3f8
	// Line 5185, Address: 0x14a020, Func Offset: 0x410
	// Line 5187, Address: 0x14a040, Func Offset: 0x430
	// Line 5189, Address: 0x14a04c, Func Offset: 0x43c
	// Line 5187, Address: 0x14a050, Func Offset: 0x440
	// Line 5189, Address: 0x14a054, Func Offset: 0x444
	// Line 5190, Address: 0x14a084, Func Offset: 0x474
	// Line 5191, Address: 0x14a094, Func Offset: 0x484
	// Line 5192, Address: 0x14a0ac, Func Offset: 0x49c
	// Line 5198, Address: 0x14a0cc, Func Offset: 0x4bc
	// Line 5199, Address: 0x14a0dc, Func Offset: 0x4cc
	// Line 5200, Address: 0x14a0ec, Func Offset: 0x4dc
	// Line 5198, Address: 0x14a0f4, Func Offset: 0x4e4
	// Line 5199, Address: 0x14a0f8, Func Offset: 0x4e8
	// Line 5200, Address: 0x14a0fc, Func Offset: 0x4ec
	// Line 5205, Address: 0x14a100, Func Offset: 0x4f0
	// Line 5200, Address: 0x14a104, Func Offset: 0x4f4
	// Line 5201, Address: 0x14a108, Func Offset: 0x4f8
	// Line 5202, Address: 0x14a10c, Func Offset: 0x4fc
	// Line 5203, Address: 0x14a128, Func Offset: 0x518
	// Line 5204, Address: 0x14a144, Func Offset: 0x534
	// Line 5205, Address: 0x14a148, Func Offset: 0x538
	// Line 5206, Address: 0x14a150, Func Offset: 0x540
	// Line 5205, Address: 0x14a154, Func Offset: 0x544
	// Line 5206, Address: 0x14a158, Func Offset: 0x548
	// Line 5207, Address: 0x14a160, Func Offset: 0x550
	// Line 5206, Address: 0x14a164, Func Offset: 0x554
	// Line 5207, Address: 0x14a168, Func Offset: 0x558
	// Line 5208, Address: 0x14a170, Func Offset: 0x560
	// Line 5207, Address: 0x14a174, Func Offset: 0x564
	// Line 5208, Address: 0x14a178, Func Offset: 0x568
	// Line 5209, Address: 0x14a180, Func Offset: 0x570
	// Line 5208, Address: 0x14a184, Func Offset: 0x574
	// Line 5209, Address: 0x14a194, Func Offset: 0x584
	// Line 5210, Address: 0x14a19c, Func Offset: 0x58c
	// Line 5209, Address: 0x14a1a0, Func Offset: 0x590
	// Line 5210, Address: 0x14a1b0, Func Offset: 0x5a0
	// Line 5211, Address: 0x14a1b8, Func Offset: 0x5a8
	// Line 5210, Address: 0x14a1bc, Func Offset: 0x5ac
	// Line 5211, Address: 0x14a1cc, Func Offset: 0x5bc
	// Line 5212, Address: 0x14a1e4, Func Offset: 0x5d4
	// Func End, Address: 0x14a204, Func Offset: 0x5f4
    scePrintf("bhSetHeadRotation - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x14a210
void bhCalcHair(O_WRK* op, BH_PWORK* pp)
{
	short az;
	short ay;
	short ax;
	//_anon35 ps;
	//_anon34* hair;
	// Line 5218, Address: 0x14a210, Func Offset: 0
	// Line 5222, Address: 0x14a228, Func Offset: 0x18
	// Line 5224, Address: 0x14a22c, Func Offset: 0x1c
	// Line 5225, Address: 0x14a234, Func Offset: 0x24
	// Line 5226, Address: 0x14a23c, Func Offset: 0x2c
	// Line 5231, Address: 0x14a244, Func Offset: 0x34
	// Line 5228, Address: 0x14a248, Func Offset: 0x38
	// Line 5229, Address: 0x14a24c, Func Offset: 0x3c
	// Line 5230, Address: 0x14a250, Func Offset: 0x40
	// Line 5231, Address: 0x14a254, Func Offset: 0x44
	// Line 5233, Address: 0x14a25c, Func Offset: 0x4c
	// Line 5232, Address: 0x14a260, Func Offset: 0x50
	// Line 5234, Address: 0x14a264, Func Offset: 0x54
	// Line 5235, Address: 0x14a268, Func Offset: 0x58
	// Line 5236, Address: 0x14a26c, Func Offset: 0x5c
	// Line 5231, Address: 0x14a270, Func Offset: 0x60
	// Line 5233, Address: 0x14a274, Func Offset: 0x64
	// Line 5237, Address: 0x14a278, Func Offset: 0x68
	// Line 5232, Address: 0x14a27c, Func Offset: 0x6c
	// Line 5239, Address: 0x14a280, Func Offset: 0x70
	// Line 5231, Address: 0x14a284, Func Offset: 0x74
	// Line 5233, Address: 0x14a288, Func Offset: 0x78
	// Line 5231, Address: 0x14a28c, Func Offset: 0x7c
	// Line 5234, Address: 0x14a290, Func Offset: 0x80
	// Line 5238, Address: 0x14a294, Func Offset: 0x84
	// Line 5232, Address: 0x14a298, Func Offset: 0x88
	// Line 5234, Address: 0x14a29c, Func Offset: 0x8c
	// Line 5232, Address: 0x14a2a0, Func Offset: 0x90
	// Line 5235, Address: 0x14a2a4, Func Offset: 0x94
	// Line 5240, Address: 0x14a2a8, Func Offset: 0x98
	// Line 5235, Address: 0x14a2ac, Func Offset: 0x9c
	// Line 5233, Address: 0x14a2b0, Func Offset: 0xa0
	// Line 5236, Address: 0x14a2b4, Func Offset: 0xa4
	// Line 5241, Address: 0x14a2b8, Func Offset: 0xa8
	// Line 5236, Address: 0x14a2bc, Func Offset: 0xac
	// Line 5234, Address: 0x14a2c0, Func Offset: 0xb0
	// Line 5237, Address: 0x14a2c4, Func Offset: 0xb4
	// Line 5242, Address: 0x14a2c8, Func Offset: 0xb8
	// Line 5237, Address: 0x14a2cc, Func Offset: 0xbc
	// Line 5235, Address: 0x14a2d0, Func Offset: 0xc0
	// Line 5238, Address: 0x14a2d4, Func Offset: 0xc4
	// Line 5243, Address: 0x14a2d8, Func Offset: 0xc8
	// Line 5238, Address: 0x14a2dc, Func Offset: 0xcc
	// Line 5236, Address: 0x14a2e0, Func Offset: 0xd0
	// Line 5239, Address: 0x14a2e4, Func Offset: 0xd4
	// Line 5244, Address: 0x14a2e8, Func Offset: 0xd8
	// Line 5239, Address: 0x14a2ec, Func Offset: 0xdc
	// Line 5237, Address: 0x14a2f0, Func Offset: 0xe0
	// Line 5240, Address: 0x14a2f4, Func Offset: 0xe4
	// Line 5245, Address: 0x14a2f8, Func Offset: 0xe8
	// Line 5240, Address: 0x14a2fc, Func Offset: 0xec
	// Line 5238, Address: 0x14a300, Func Offset: 0xf0
	// Line 5241, Address: 0x14a304, Func Offset: 0xf4
	// Line 5246, Address: 0x14a308, Func Offset: 0xf8
	// Line 5247, Address: 0x14a30c, Func Offset: 0xfc
	// Line 5239, Address: 0x14a310, Func Offset: 0x100
	// Line 5242, Address: 0x14a314, Func Offset: 0x104
	// Line 5240, Address: 0x14a318, Func Offset: 0x108
	// Line 5241, Address: 0x14a31c, Func Offset: 0x10c
	// Line 5242, Address: 0x14a324, Func Offset: 0x114
	// Line 5243, Address: 0x14a328, Func Offset: 0x118
	// Line 5248, Address: 0x14a32c, Func Offset: 0x11c
	// Line 5242, Address: 0x14a330, Func Offset: 0x120
	// Line 5244, Address: 0x14a334, Func Offset: 0x124
	// Line 5243, Address: 0x14a338, Func Offset: 0x128
	// Line 5245, Address: 0x14a33c, Func Offset: 0x12c
	// Line 5243, Address: 0x14a340, Func Offset: 0x130
	// Line 5246, Address: 0x14a344, Func Offset: 0x134
	// Line 5244, Address: 0x14a348, Func Offset: 0x138
	// Line 5245, Address: 0x14a350, Func Offset: 0x140
	// Line 5247, Address: 0x14a358, Func Offset: 0x148
	// Line 5248, Address: 0x14a35c, Func Offset: 0x14c
	// Line 5249, Address: 0x14a360, Func Offset: 0x150
	// Line 5250, Address: 0x14a364, Func Offset: 0x154
	// Line 5251, Address: 0x14a368, Func Offset: 0x158
	// Line 5253, Address: 0x14a36c, Func Offset: 0x15c
	// Line 5248, Address: 0x14a370, Func Offset: 0x160
	// Line 5246, Address: 0x14a374, Func Offset: 0x164
	// Line 5247, Address: 0x14a378, Func Offset: 0x168
	// Line 5246, Address: 0x14a37c, Func Offset: 0x16c
	// Line 5247, Address: 0x14a380, Func Offset: 0x170
	// Line 5253, Address: 0x14a384, Func Offset: 0x174
	// Line 5254, Address: 0x14a388, Func Offset: 0x178
	// Line 5248, Address: 0x14a38c, Func Offset: 0x17c
	// Line 5254, Address: 0x14a390, Func Offset: 0x180
	// Line 5255, Address: 0x14a394, Func Offset: 0x184
	// Line 5257, Address: 0x14a39c, Func Offset: 0x18c
	// Line 5258, Address: 0x14a3ac, Func Offset: 0x19c
	// Line 5259, Address: 0x14a3bc, Func Offset: 0x1ac
	// Line 5271, Address: 0x14a3c4, Func Offset: 0x1b4
	// Line 5259, Address: 0x14a3c8, Func Offset: 0x1b8
	// Line 5268, Address: 0x14a3d0, Func Offset: 0x1c0
	// Line 5269, Address: 0x14a3e0, Func Offset: 0x1d0
	// Line 5270, Address: 0x14a3e4, Func Offset: 0x1d4
	// Line 5271, Address: 0x14a3f0, Func Offset: 0x1e0
	// Line 5272, Address: 0x14a3f8, Func Offset: 0x1e8
	// Line 5273, Address: 0x14a40c, Func Offset: 0x1fc
	// Line 5274, Address: 0x14a420, Func Offset: 0x210
	// Line 5275, Address: 0x14a434, Func Offset: 0x224
	// Line 5276, Address: 0x14a444, Func Offset: 0x234
	// Line 5277, Address: 0x14a44c, Func Offset: 0x23c
	// Line 5276, Address: 0x14a458, Func Offset: 0x248
	// Line 5277, Address: 0x14a460, Func Offset: 0x250
	// Line 5278, Address: 0x14a478, Func Offset: 0x268
	// Line 5279, Address: 0x14a49c, Func Offset: 0x28c
	// Line 5280, Address: 0x14a4c0, Func Offset: 0x2b0
	// Line 5281, Address: 0x14a4e4, Func Offset: 0x2d4
	// Line 5282, Address: 0x14a508, Func Offset: 0x2f8
	// Line 5283, Address: 0x14a52c, Func Offset: 0x31c
	// Func End, Address: 0x14a548, Func Offset: 0x338
    scePrintf("bhCalcHair - UNIMPLEMENTED!\n");
}

// 100% matching!
void* bhGetTransZ(int mtn_no)
{
	unsigned char* datp, *retp; 
    unsigned int sz;     
    int i;               

    i = mtn_no + 1;

    datp = sys->plzmtp;
    
    while (i-- != 0) 
    {
        sz = *(unsigned int*)datp;
        
        if (sz == -1) 
        {
            retp = NULL;
            break;
        }

        datp += 4;

        retp = datp;

        datp = &datp[sz];
    }

    return retp;
}
