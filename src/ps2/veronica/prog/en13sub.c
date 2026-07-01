#include "../../../ps2/veronica/prog/en13sub.h"
#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

/* exp0: 0x4 ATR_WORK* atr[32], 0x84 NJS_POINT3 prev_pos[32], 0x204 int atr_ct */
#define EXP0_ATR(n) (*(ATR_WORK**)(epw->exp0 + (n) * 4 + 0x4))
#define EXP0_P3(n) ((NJS_POINT3*)(epw->exp0 + (n) * 12 + 0x84))

Mode0_proc bhEne13B_Mode0[6] =
{
    bhEne13B_Init,
    bhEne13B_Move,
    bhEne13B_Nage,
    bhEne13B_Damage,
    bhEne13B_Die,
    bhEne_Event
};

MoveMode2_proc bhEne13B_MoveMode2[2] =
{
    bhEne13B_MV00,
    bhEne13B_MV01
};

void bhEne13B(BH_PWORK* epw)
{
    int i;
    O_WORK* owk;

    bhEne13B_Mode0[epw->mode0](epw);

    if (((BH_PWORK*)epw->lkwkp)->stflg & 0x1000000)
    {
        int i;

        epw->stflg |= 0x1000000;

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }
    }

    for (i = 0, owk = epw->mlwP->owP; i < epw->mlwP->obj_num; i++, owk++)
    {
        *EXP0_P3(i) = *(NJS_POINT3*)&owk->mtx[12];
    }

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    bhEne13B_SetHittab(epw);
}

void bhEne13B_Init(BH_PWORK* epw)
{
    int i;

    epw->flg |= 0x8018;
    epw->flg &= ~6;

    epw->flg2 |= 0x1;
    epw->flg2 |= 0x10;

    epw->mdflg |= 0x20;

    epw->ar = 5.0f;
    epw->ah = 1.0f;
    epw->car = 3.0f;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate = 0x10000;
    epw->hokan_count = 0;

    epw->mtn_no = 4;
    epw->mtn_md = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0x208, 8);

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i) = &sys->mwalp[sys->mwal_n];
            sys->mwal_n++;

            EXP0_ATR(i)->flg = 0;
            EXP0_ATR(i)->type = 3;
            EXP0_ATR(i)->w = 2.0f;
            EXP0_ATR(i)->h = 1.0f;
            EXP0_ATR(i)->d = 0;
            EXP0_ATR(i)->attr = 0;

            EXP0_ATR(i)->px = epw->mlwP->owP->mtx[12];
            EXP0_ATR(i)->py = epw->mlwP->owP->mtx[13];
            EXP0_ATR(i)->pz = epw->mlwP->owP->mtx[14];
        }
    }
}

void bhEne13B_Move(BH_PWORK* epw)
{
    bhEne13B_MoveMode2[epw->mode2](epw);
}

void bhEne13B_MV00()
{

}

void bhEne13B_MV01(BH_PWORK* epw)
{
    int mtn_no[6] = { 6, 4, 8, 7, 5, 9 };
    O_WORK* owk;
    int i;
    int j;
    int num;
    BH_PWORK** ep;
    NJS_POINT3 p1;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn_no[epw->type];
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->hokan_count = 0;

        epw->ct0 = 1;

        epw->flg &= ~0x80000;

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230B);

        epw->mode3++;
        break;

    case 1:
        if (((epw->mtn_no == 5) && (epw->frm_no == 0x320000))
            || ((epw->mtn_no == 7) && (epw->frm_no == 0x3A0000))
            || ((epw->mtn_no == 9) && (epw->frm_no == 0x320000)))
        {
            bhEne13_SetCamera((BH_PWORK*)epw->lkwkp, 3.2f);

            bhEne_CallSE(epw, (NJS_POINT3*)&epw->mlwP->owP[18].mtx[12], 0x12310);
        }

        if (((epw->mtn_no == 4) && (epw->frm_no == 0x170000))
            || ((epw->mtn_no == 6) && (epw->frm_no == 0x170000))
            || ((epw->mtn_no == 8) && (epw->frm_no == 0x170000)))
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->mlwP->owP[18].mtx[12], 0x1230F);
        }

        switch (epw->mtn_no)
        {
        case 4:
            if (epw->frm_no >= 0x360000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;

        case 6:
            if (epw->frm_no >= 0x2C0000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;

        case 8:
            if (epw->frm_no >= 0x360000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;

        case 5:
            if (epw->frm_no == 0xD0000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            if (epw->frm_no == 0x2F0000)
            {
                epw->flg &= ~0x80000;
                epw->ct0 = 2;
            }

            if (epw->frm_no == 0x350000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;

        case 7:
            if (epw->frm_no == 0x130000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            if (epw->frm_no == 0x370000)
            {
                epw->flg &= ~0x80000;
                epw->ct0 = 2;
            }

            if (epw->frm_no == 0x3C0000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;

        case 9:
            if (epw->frm_no == 0xD0000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            if (epw->frm_no == 0x2F0000)
            {
                epw->flg &= ~0x80000;
                epw->ct0 = 2;
            }

            if (epw->frm_no == 0x350000)
            {
                epw->flg |= 0x80000;
                epw->ct0 = 0;
            }

            break;
        }

        if (epw->ct0 != 0)
        {
            for (i = epw->mlwP->obj_num - 1, owk = &epw->mlwP->owP[epw->mlwP->obj_num] - 1; i > 0; i--, owk--)
            {
                if ((epw->ct0 != 0)
                    && (plp->mode0 != 3)
                    && (plp->mode0 != 4)
                    && (plp->mode0 != 6)
                    && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&owk->mtx[12], 4.0f)))
                {
                    p1.x = epw->mlwP->owP->mtx[12];
                    p1.y = epw->mlwP->owP->mtx[13];
                    p1.z = epw->mlwP->owP->mtx[14];

                    {
                        float dx, dy, dz;

                        dx = epw->mlwP->owP[i].mtx[12];
                        dy = epw->mlwP->owP[i].mtx[13];
                        dz = epw->mlwP->owP[i].mtx[14];

                        plp->dvx = EXP0_P3(i)->x - dx;
                        plp->dvy = EXP0_P3(i)->y - dy;
                        plp->dvz = EXP0_P3(i)->z - dz;
                    }

                    if ((njDistanceP2P(&p1, (NJS_POINT3*)&plp->px) < 15.0f)
                        || (njScalor((NJS_VECTOR*)&plp->dvx) < 5.0f))
                    {
                        plp->dvx = p1.x - plp->px;
                        plp->dvy = p1.y - plp->py;
                        plp->dvz = p1.z - plp->pz;
                    }

                    if (epw->ct0 == 1)
                    {
                        plp->hp -= 25;
                    }
                    else
                    {
                        plp->hp -= 60;
                    }

                    if (plp->hp < 0)
                    {
                        plp->flg |= 0x10004;
                        plp->stflg |= 0x50000;

                        plp->mode0 = 6;
                        plp->mode1 = 0;

                        if (bhEne_DGDirCheck(plp))
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);
                            plp->mode2 = 1;
                        }
                        else
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);
                            plp->mode2 = 0;
                        }

                        plp->mode3 = 0;
                    }
                    else
                    {
                        plp->flg |= 0x10004;
                        plp->stflg |= 0x10000;

                        plp->mode0 = 4;
                        plp->mode1 = 0;

                        if (bhEne_DGDirCheck(plp))
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);
                            plp->mode2 = 1;
                        }
                        else
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);
                            plp->mode2 = 0;
                        }

                        plp->mode3 = 0;
                    }

                    bhEne13_PlayerControl((BH_PWORK*)epw->lkwkp);

                    epw->ct0 = 0;
                }

                ep = bhEne13_GetChild((BH_PWORK*)epw->lkwkp, &num);

                for (j = 0; j < num; j++, ep++)
                {
                    if ((*ep)->flg & 0x20)
                    {
                        if (bhEne_AttackHitCheck(*ep, (NJS_POINT3*)&owk->mtx[12], 4.0f))
                        {
                            (*ep)->flg |= 0x4;
                            (*ep)->dam[0] = 100;
                        }
                    }
                }
            }
        }

        if (epw->frm_no == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mtn_add = 0;
            epw->mode3 = 0;
        }

        break;
    }
}

void bhEne13B_Nage()
{

}

void bhEne13B_Damage()
{

}

void bhEne13B_Die(BH_PWORK* epw)
{
    int i;

    epw->stflg |= 0x1000000;

    epw->flg |= 0x2;

    for (i = 0; i < epw->mlwP->obj_num; i++)
    {
        EXP0_ATR(i)->flg = 0;
    }

    epw->flg &= ~0x80000;
}

void bhEne13B_SetHittab(BH_PWORK* epw)
{
    int i;
    O_WORK* owk;

    if (epw->flg & 0x80000)
    {
        EXP0_I(0x204)++;

        if (EXP0_I(0x204) > 15)
        {
            EXP0_I(0x204) = 15;
        }

        owk = epw->mlwP->owP;

        for (i = 0; i < EXP0_I(0x204); i++, owk++)
        {
            EXP0_ATR(i)->flg = 1;

            EXP0_ATR(i)->px = owk->mtx[12];
            EXP0_ATR(i)->py = owk->mtx[13];
            EXP0_ATR(i)->pz = owk->mtx[14];
        }
    }
    else
    {
        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }

        EXP0_I(0x204) = 0;
    }
}
