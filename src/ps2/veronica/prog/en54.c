#include "../../../ps2/veronica/prog/en54.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
//#include "../../../ps2/veronica/prog/Motion.h" /* they might have forgotten to include this in the original codebase */
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"

typedef void (*bhEne54_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne54_MoveType_proc)(BH_PWORK* epw);
typedef void (*bhEne54_MoveMode2_proc)(BH_PWORK* epw);
typedef void (*bhEne54_DamageType_proc)(BH_PWORK* epw);
typedef void (*bhEne54_DamageMode2_proc)(BH_PWORK* epw);

bhEne54_Mode0_proc bhEne54_Mode0[6] = 
{
	bhEne54_Init,
	bhEne54_Move,
	NULL,
	bhEne54_Damage,
	NULL,
	bhEne_Event
};
bhEne54_MoveType_proc bhEne54_MoveType[1] = 
{
	bhEne54_MVType00
};
bhEne54_MoveMode2_proc bhEne54_MoveMode2[1] = 
{
	bhEne54_MV00
};
bhEne54_DamageType_proc bhEne54_DamageType[1] = 
{
	bhEne54_DGType00
};
bhEne54_DamageMode2_proc bhEne54_DamageMode2[1] = 
{
	bhEne54_DG00
};

// 100% matching!
void bhEne54(BH_PWORK* epw)
{
	int i;

	bhEne54_MainLoop(epw);

    if ((epw->flg & 0x4))
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }

        epw->flg &= ~0x4;
    }

    bhEne54_CalcEnemy(epw);

    bhEne54_CollCheck(epw);
}

// 100% matching!
void bhEne54_MainLoop(BH_PWORK* epw)
{
	bhEne54_Mode0[epw->mode0](epw);

	bhEne54_SetMtn(epw);
}

// 100% matching!
int bhEne54_SetMtn(BH_PWORK* epw)
{
	int ret;

	ret = bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    if (ret != 0)
    {
        epw->flg |= 0x2000000;
    }
    else
    {
        epw->flg &= ~0x2000000;
    }

    return ret;
}

// 100% matching!
void bhEne54_CollCheck(BH_PWORK* epw)
{
	BH_PWORK* epp; 
	O_WORK* owk;   
	NJS_SPHERE at; 
	NJS_POINT3 ps; 
	int i;         
	
    epp = ene;

    for (i = 0; i < sys->ewk_n; i++, epp++)
    {
        if ((epp->id == 17) && (epw->mode0 == 1))
        {
			owk = &((O_WRK*)epp->exp2)->mlwP->owP[1];

            ps.x = 0;
            ps.y = 0;
            ps.z = -17.5f;

            njCalcPoint(&owk->mtx, &ps, &at.c);

            at.r = 4.0f;

            if (npCollisionCheckSC(&at, &epw->watr) != 0)
            {
                ((unsigned int*)epp->exp0)[2] |= 0x20000000;

                epw->mode0 = 3;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
            }

            break;
        }
    }
}

// 100% matching!
void bhEne54_CalcEnemy(BH_PWORK* epw)
{
	O_WORK* owk;

    bhCalcModel(epw);

	owk = &epw->mlwP->owP[5];

    epw->cah = epw->ah = owk->mtx[13] - epw->py;

    owk = &epw->mlwP->owP[5];

    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13];
    epw->watr.c1.z = owk->mtx[14];

	owk = epw->mlwP->owP;

    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];

    epw->watr.r = 3.0f;
}

// 100% matching!
void bhEne54_Init(BH_PWORK* epw)
{
	int i;

    epw->ar = 6.0f;

    epw->ah = 20.0f;
    epw->aw = 0;

    epw->ad = 0;

    epw->car = 6.0f;
    epw->cah = 20.0f;

    epw->hp = 250;

    epw->stflg = 0;

    for (i = 0; i < 64; i++)
	{
		epw->dam[i] = 0;
	}

    epw->hokan_rate = 0;
    epw->hokan_count = 0;

    epw->mtn_no = 0;
    epw->mtn_add = 0;

    epw->frm_no = 0;

    epw->mtn_tp = NULL;
    epw->mtn_md = 0;

    epw->flg |= 0x8000;
    epw->flg &= ~0x2;

    epw->clp_jno[0] = -1;

    epw->mdflg |= 0x20;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne54_Move(BH_PWORK* epw)
{
	bhEne54_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne54_Damage(BH_PWORK* epw)
{
	bhEne54_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne54_MVType00(BH_PWORK* epw)
{
	bhEne54_MoveMode2[epw->mode2](epw);
}

// 
// Start address: 0x21b2b0
void bhEne54_MV00(BH_PWORK* epw)
{
	// Line 459, Address: 0x21b2b0, Func Offset: 0
	// Line 460, Address: 0x21b2bc, Func Offset: 0xc
	// Line 463, Address: 0x21b2dc, Func Offset: 0x2c
	// Line 464, Address: 0x21b2ec, Func Offset: 0x3c
	// Line 465, Address: 0x21b2f0, Func Offset: 0x40
	// Line 470, Address: 0x21b2fc, Func Offset: 0x4c
	// Func End, Address: 0x21b30c, Func Offset: 0x5c
}

// 
// Start address: 0x21b310
void bhEne54_DGType00(BH_PWORK* epw)
{
	// Line 489, Address: 0x21b310, Func Offset: 0
	// Func End, Address: 0x21b330, Func Offset: 0x20
}

// 
// Start address: 0x21b330
void bhEne54_DG00(BH_PWORK* epw)
{
	// Line 510, Address: 0x21b330, Func Offset: 0
	// Line 511, Address: 0x21b33c, Func Offset: 0xc
	// Line 514, Address: 0x21b368, Func Offset: 0x38
	// Line 516, Address: 0x21b388, Func Offset: 0x58
	// Line 517, Address: 0x21b394, Func Offset: 0x64
	// Line 520, Address: 0x21b39c, Func Offset: 0x6c
	// Line 522, Address: 0x21b3ac, Func Offset: 0x7c
	// Line 525, Address: 0x21b3b8, Func Offset: 0x88
	// Line 527, Address: 0x21b3e8, Func Offset: 0xb8
	// Line 528, Address: 0x21b3ec, Func Offset: 0xbc
	// Line 535, Address: 0x21b3f8, Func Offset: 0xc8
	// Func End, Address: 0x21b408, Func Offset: 0xd8
}
