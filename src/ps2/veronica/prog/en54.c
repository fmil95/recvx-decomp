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

// 100% matching!
void bhEne54_MV00(BH_PWORK* epw)
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
void bhEne54_DGType00(BH_PWORK* epw)
{
	bhEne54_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne54_DG00(BH_PWORK* epw)
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
