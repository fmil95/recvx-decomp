#include "../../../ps2/veronica/prog/en55.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
//#include "../../../ps2/veronica/prog/Motion.h" /* they might have forgotten to include this in the original codebase */
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"

typedef void (*bhEne55_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne55_MoveType_proc)(BH_PWORK* epw);
typedef void (*bhEne55_MoveMode2_proc)(BH_PWORK* epw);
typedef void (*bhEne55_DamageType_proc)(BH_PWORK* epw);
typedef void (*bhEne55_DamageMode2_proc)(BH_PWORK* epw);

bhEne55_Mode0_proc bhEne55_Mode0[6] = 
{
	bhEne55_Init,
	bhEne55_Move,
	NULL,
	bhEne55_Damage,
	NULL,
	bhEne_Event
};
bhEne55_MoveType_proc bhEne55_MoveType[1] = 
{
	bhEne55_MVType00
};
bhEne55_MoveMode2_proc bhEne55_MoveMode2[1] = 
{
	bhEne55_MV00
};
bhEne55_DamageType_proc bhEne55_DamageType[1] = 
{
	bhEne55_DGType00
};
bhEne55_DamageMode2_proc bhEne55_DamageMode2[1] = 
{
	bhEne55_DG00
};

// 100% matching!
void bhEne55(BH_PWORK* epw)
{
	int i;
	
	bhEne55_MainLoop(epw);

    if ((epw->flg & 0x4))
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }

        epw->flg &= ~0x4;
    }

    bhEne55_CalcEnemy(epw);

    bhEne55_CollCheck(epw);
}

// 100% matching!
void bhEne55_MainLoop(BH_PWORK* epw)
{
	bhEne55_Mode0[epw->mode0](epw);

	bhEne55_SetMtn(epw);
}

// 100% matching!
int bhEne55_SetMtn(BH_PWORK* epw)
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

// 
// Start address: 0x21b540
void bhEne55_CollCheck(BH_PWORK* epw)
{
	int i;
	//_anon20 ps;
	//_anon31 at;
	//_anon4* owk;
	BH_PWORK* epp;
	// Line 260, Address: 0x21b540, Func Offset: 0
	// Line 267, Address: 0x21b550, Func Offset: 0x10
	// Line 270, Address: 0x21b580, Func Offset: 0x40
	// Line 273, Address: 0x21b598, Func Offset: 0x58
	// Line 276, Address: 0x21b59c, Func Offset: 0x5c
	// Line 277, Address: 0x21b5a0, Func Offset: 0x60
	// Line 273, Address: 0x21b5a8, Func Offset: 0x68
	// Line 274, Address: 0x21b5b4, Func Offset: 0x74
	// Line 275, Address: 0x21b5b8, Func Offset: 0x78
	// Line 277, Address: 0x21b5bc, Func Offset: 0x7c
	// Line 278, Address: 0x21b5c8, Func Offset: 0x88
	// Line 279, Address: 0x21b5cc, Func Offset: 0x8c
	// Line 281, Address: 0x21b5e4, Func Offset: 0xa4
	// Line 282, Address: 0x21b5ec, Func Offset: 0xac
	// Line 281, Address: 0x21b5f0, Func Offset: 0xb0
	// Line 282, Address: 0x21b5fc, Func Offset: 0xbc
	// Line 283, Address: 0x21b600, Func Offset: 0xc0
	// Line 284, Address: 0x21b604, Func Offset: 0xc4
	// Line 287, Address: 0x21b608, Func Offset: 0xc8
	// Line 289, Address: 0x21b610, Func Offset: 0xd0
	// Line 290, Address: 0x21b628, Func Offset: 0xe8
	// Func End, Address: 0x21b63c, Func Offset: 0xfc
}

// 100% matching!
void bhEne55_CalcEnemy(BH_PWORK* epw)
{
	O_WORK* owk;

    bhCalcModel(epw);

	owk = &epw->mlwP->owP[12];

    epw->cah = epw->ah = owk->mtx[13] - epw->py;

    owk = &epw->mlwP->owP[12];

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
void bhEne55_Init(BH_PWORK* epw)
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
void bhEne55_Move(BH_PWORK* epw)
{
	bhEne55_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne55_Damage(BH_PWORK* epw)
{
	bhEne55_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne55_MVType00(BH_PWORK* epw)
{
	bhEne55_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne55_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)                               
    {
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 0);

        epw->mtn_add = 0;

        epw->mode3++;
    case 1:
        break;
    }
}

// 100% matching!
void bhEne55_DGType00(BH_PWORK* epw)
{
	bhEne55_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne55_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)                        
    {
    case 0:
        if (epw->pz < 20.0f)
        {
            bhEne_ChgMtn(epw, 1, 0, 0);
        }
        else
        {
            bhEne_ChgMtn(epw, 0, 0, 0);
        }

        epw->mode3++;
    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;

            epw->mode3++;
        }
    case 2:
        break;
    }
}
