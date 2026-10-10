#include "../../../ps2/veronica/prog/en07.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "ninjaapi.h"
#include "ninjastr.h"

// ENEMY: Bat 

static int ENE07_HITPOINT[16] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};

static char junction_tree[1][6] = {
    {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00},
};

static char SdwTab[3] = {0x01, 0x03, 0xFF};

static char AtkPos[5] = {0x0D, 0x07, 0x0B, 0x08, 0x05};

static NJS_POINT3 AtkOffset[5] = {
    {-0.5f, 0.5f,  0.0f},
    { 1.0f, 0.5f, -0.5f},
    {-1.0f, 0.5f, -0.5f},
    { 0.5f, 0.5f,  0.0f},
    { 0.0f, 3.0f,  0.0f}
};

static int AtkAngle[5] = {
    NJM_DEG_ANG(180),
    NJM_DEG_ANG(20),
    NJM_DEG_ANG(-20),
    NJM_DEG_ANG(90),
    NJM_DEG_ANG(0)
};

static BP_WORK BloodParam = {
    {0.0f, 0.1f, 0.0f},
    0,
    0.0f,
    0.03f,
    {0.5f, 0.3f, 0.3f, 0.8f, 0.5f},
    {0, 3, 6, 9, 12}
};

static CPCL CapColTab[5] = {
    {1,  2, 5},
    {1,  1, 4},
    {0, -5, 0},
    {2,  3, 5},
    {0,  0, 0}
};

void (*bhEne07_Mode0[6])(BH_PWORK*) =
{
    bhEne07_Init,
    bhEne07_Move,
    bhEne07_Nage,
    bhEne07_Damage,
    bhEne07_Die,
    bhEne_Event
};

void (*bhEne07_BrainType[2])(BH_PWORK*) = {
    bhEne07_BR00,
    bhEne07_BR01
};

void (*bhEne07_MoveMode2[9])(BH_PWORK*) = {
    bhEne07_MV00,
    bhEne07_MV01,
    bhEne07_MV02,
    bhEne07_MV03,
    bhEne07_MV04,
    bhEne07_MV05,
    bhEne07_MV06,
    bhEne07_MV07,
    bhEne07_MV08
};

void (*bhEne07_NageMode2[2])(BH_PWORK*) = {
    bhEne07_NG00,
    bhEne07_NG01
};

void (*bhEne07_DeadMode2[7])(BH_PWORK*) = {
    bhEne07_DD00,
    bhEne07_DD01,
    bhEne07_DD02,
    bhEne07_DD03,
    bhEne07_DD04,
    bhEne07_DD05,
    bhEne07_DD06
};

// 100% matching!
void bhEne07(BH_PWORK* epw)
{
    bhEne07_Mode0[epw->mode0](epw);

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    epw->ar += (EXP0_F(0x3C) - epw->ar) / 8.0f;
    epw->car += (EXP0_F(0x40) - epw->car) / 8.0f;

    bhCheckPlayer(epw);
    bhCheckEnemies(epw);
    bhEne07_FloorCollision(epw);
    bhEne07_CollisionWalls(epw);
    bhEne07_FloorCollision(epw);
    bhCalcModel(epw);
    bhEne_SetWeponAtr(epw, 6, 11, 2.0f);

    if (epw->exp1[6] == sys->enow)
    {
        if (plp->mode0 == 4)
        {
            bhEne07_PlayerControl(epw);
        }

        if (epw->exp1[7] != 0)
        {
            epw->exp1[7]--;
        }
    }
}

// 100% matching!
void bhEne07_Init(BH_PWORK* epw)
{
    int i;
    int sdw;
    BH_PWORK* ep;

    epw->flg |= 0x68;
    epw->flg &= ~0x9006;
    epw->flg2 |= 0x40;
    epw->mlwP->objP[1].evalflags &= ~0x8;
    epw->ar = 1.5f;
    epw->ah = 1.5f;
    epw->hp = ENE07_HITPOINT[(int)(16.0f * njRandom())];
    epw->car = 3.0f;
    epw->cah = 2.0f;

    if (epw->type == 2)
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 4;
        epw->mode3 = 0;
        epw->hokan_rate = 0x10000;
        epw->hokan_count = 0;
        epw->mtn_no = 0;
        epw->mtn_md = 0;
        epw->mtn_add = 0x10000;
        epw->frm_no = 0;
    }
    else
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 0;
        epw->mode3 = 0;
        epw->hokan_rate = 0x10000;
        epw->hokan_count = 0;
        epw->mtn_no = 3;
        epw->mtn_md = 0;
        epw->mtn_add = 0x10000;
        epw->frm_no = 0;
    }

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0x44, 0x8);

        for (i = 0, ep = ene; i < sys->ewk_n; i++, ep++)
        {
            if ((ep->flg & 1) && (ep->id == 7))
            {
                if (ep->exp1 != NULL)
                {
                    epw->exp1 = ep->exp1;
                }
                else
                {
                    epw->exp1 = bhEne_CallocWork(0x8, 0x8);
                }
                break;
            }
        }
    }

    epw->exp1[0] = 0;
    epw->exp1[5] = 0;
    epw->exp1[7] = 0;
    for (i = 0; i < 4; i++)
    {
        *((char*)epw->exp1 + (i + 1)) = 0;
    }

    if ((epw->flg & 0x800) == 0)
    {
        sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 1, 5.0f, 2.0f, 4.0f);
        eff[sdw].mdlver = 1;
        epw->flg |= 0x800;
    }

    epw->stflg &= ~0x8;
    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 2;
    epw->clp_jno[2] = 3;
    epw->clp_jno[3] = 8;
    epw->clp_jno[4] = 13;
    epw->clp_jno[5] = -1;

    if (epw->type == 2)
    {
        epw->ar = 3.5f;
        epw->type = 0;
        EXP0_I(0x38) = 300 + (int)(300.0f * njRandom());
        epw->flg &= ~0x400000;
    }
    else if (epw->type == 3)
    {
        epw->type = 0;
        epw->flg |= 0x500000;
    }
    else if (epw->type == 4)
    {
        epw->type = 1;
        epw->flg |= 0x500000;
    }
    else
    {
        NJS_POINT3 p;

        p.x = epw->px;
        p.y = epw->py + 999.0f;
        p.z = epw->pz;

        if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &p))
        {
            epw->py = p.y;
            epw->pxb = epw->px;
            epw->pyb = epw->py;
            epw->pzb = epw->pz;
        }

        epw->flg |= 0x500000;
    }

    if (epw->type > 1)
    {
        epw->type = 0;
    }

    epw->cpcl = CapColTab;
    EXP0_F(0x3C) = epw->ar;
    EXP0_F(0x40) = epw->car;
}

// 100% matching!
void bhEne07_Brain(BH_PWORK* epw)
{
    bhEne07_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne07_BR00(BH_PWORK* epw)
{
    bhEne07_SearchPlayer(epw);

    if ((EXP0_F(0) < 15.0f) && (plp->wpnr_no == 1))
    {
        if (epw->flg & 0x400000)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
            return;
        }

        if (EXP0_I(0x38) < 300)
        {
            EXP0_I(0x38) += (int)(100.0f * njRandom());
        }
    }

    if (plp->stflg & 0x200)
    {
        switch (plp->mode2)
        {
        case 6:
        case 7:
        case 8:
            if (EXP0_F(0) >= 40.0f)
            {
                break;
            }

            if (epw->flg & 0x400000)
            {
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
                return;
            }

            if (EXP0_I(0x38) < 300)
            {
                EXP0_I(0x38) += (int)(100.0f * njRandom());
            }
        }
    }

    if (plp->stflg & 0x100)
    {
        if (epw->flg & 0x400000)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
            return;
        }

        EXP0_I(0x38) = 300 + (int)(300.0f * njRandom());
    }

    if ((plp->wpnr_no == 1) || (plp->stflg & 0x80000000) || (EXP0_UC(0x34) == 0) || (epw->exp1[7] > 0))
    {
        return;
    }

    if (!(sys->cb_flg & 0x4) && (EXP0_F(0) < 10.0f) && (epw->py < plp->py + 23.0f) && (epw->py > plp->py + 10.0f))
    {
        if (abs(bhEne_DirTarget(epw, plp->px, plp->pz, NJM_DEG_ANG(20))) < NJM_DEG_ANG(20))
        {
            if ((abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(160)) && (epw->exp1[0] == 0) && (njRandom() < 0.5f))
            {
                epw->exp1[6] = sys->enow;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
                epw->exp1[0] = 0x63;
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
            }
            else
            {
                if (epw->exp1[0] < 4)
                {
                    if (epw->exp1[0] == 0)
                    {
                        epw->exp1[6] = sys->enow;
                        plp->flg |= 0x10004;
                        plp->stflg |= 0x10000;
                    }

                    EXP0_UC(0x35) = epw->exp1[0];
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    epw->exp1[0]++;
                }
                else
                {
                    epw->mode1 = 0;
                    epw->mode2 = 4;
                    epw->mode3 = 0;
                }
            }
        }
    }
}

// 100% matching!
void bhEne07_BR01(BH_PWORK* epw)
{
    if (plp->stflg & 0x100)
    {
        if (epw->flg & 0x400000)
        {
            epw->type = 0;
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
            sys->rm_flg |= 0x1;
            return;
        }

        EXP0_I(0x38) = 300 + (int)(300.0f * njRandom());
    }
}

// 100% matching!
void bhEne07_Move(BH_PWORK* epw)
{
    bhEne07_MoveMode2[epw->mode2](epw);

    if ((epw->flg & 0x4) && !(epw->flg & 0x2)) {
        epw->flg &= ~0x4;
        bhEne07_Damage(epw);
        return;
    }

    if (epw->mode1 == 1) {
        bhEne07_Brain(epw);
    }
}

// 100% matching!
void bhEne07_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0x8000 * njRandom() * epw->mnwP[epw->mtn_no].frm_num;
        epw->hokan_count = 0;
        epw->flg |= 0x500000;
        epw->ct0 = 20 + (int)(63.0f * njRandom());
        epw->mode3++;
    case 1:
        if (epw->ct0--) break;

        if ((int)(8.0f * njRandom()) == 0)
        {
            epw->mtn_no = 25;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 0x8000;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            epw->mode3++;
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12304);
        }
        else
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2303);
        }
        break;

    case 2:
        if (epw->ct0--) break;

        epw->mode3 = 0;
    }
}

// 100% matching;
void bhEne07_MV01(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 20.0f * njRandom();
        epw->mode3++;
    case 1:
        if (epw->ct0--) break;

        epw->mtn_no = 1;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x100000;
        epw->flg &= ~0x400000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        break;

    case 2:
        if (epw->ct0--) break;

        bhEne_GetPartsPos(epw, junction_tree[0], &pos);
        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;
        EXP0_F(0x3C) = 3.5f;
        EXP0_F(0x40) = 3.5f;
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->flg &= ~0x100000;
        EXP0_I(0x38) = 300 + (int)(300.0f * njRandom());
    }
}

// 100% matching!
void bhEne07_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 0x8000;
        }
        epw->flg |= 0x100000;
        epw->spd = 0.7f;
        if (plp->wpnr_no != 1)
        {
            epw->ct0 = 40 + (int)(63.0f * njRandom());
        }
        else
        {
            epw->ct0 = 20;
        }
        epw->ct1 = (njRandom() > 0.5) ? 1 : -1;
        epw->ct2 = 30 + (int)(20.0f * njRandom());
        epw->ct3 = 0;
        epw->yn = plp->py + 10.0f + (10.0f * njRandom());
        epw->mode3++;
    case 1:
        if (fabsf(epw->yn - epw->py) > 0.3)
        {
            epw->py += (epw->yn - epw->py > 0.0f) ? 0.3f : -0.3f;
        }
        else
        {
            epw->py += 0.3f * (epw->yn - epw->py);
        }

        bhAddSpeed(epw, 0);

        if (bhEne07_AvoidWall(epw, epw->ct1))
        {
            if (epw->ct3 == 0)
            {
                epw->ct3 = 10;
            }
        }
        else
        {
            if (epw->ct3 > 0)
            {
                epw->ct3--;
            }
            else
            {
                epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, NJM_DEG_ANG(5));
            }
        }

        if ((epw->ct0-- == 0) || ((epw->exp1[7] > 0) && (EXP0_F(0) < 10.0f)))
        {
            epw->mode1 = 1;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }

        if (EXP0_UC(0x34) && (EXP0_F(0) < 20.0f))
        {
            epw->yn = 15.0f + plp->py;
        }

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x13301);
            epw->ct2 = 60 + (int)(30.0f * njRandom());
        }
    }
}

// 100% matching!
void bhEne07_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 4)
        {
            epw->mtn_no = 4;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 0x8000;
        }
        epw->flg |= 0x100000;
        epw->ct0 = 40 + (int)(63.0f * njRandom());
        epw->mode3++;
    case 1:
        epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, NJM_DEG_ANG(10));

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne07_MV04(BH_PWORK* epw)
{
    int dir;

    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 0x8000;
        }

        epw->flg |= 0x100000;
        epw->spd = 0.7f;
        epw->ct0 = 60 + (int)(60.0f * njRandom());
        epw->ct2 = 10 + (int)(40.0f * njRandom());
        epw->ct3 = 0;

        dir = epw->ay - (bhArcTan2(plp->px - epw->px, plp->pz - epw->pz) + NJM_DEG_ANG(90));
        if (abs((short)dir) < NJM_DEG_ANG(90))
        {
            epw->ct1 = 1;
        }
        else
        {
            epw->ct1 = -1;
        }

        epw->yn = 10.0f + bhGetGroundPosition((NJS_POINT3*)&epw->px) + (10.0f * njRandom());
        epw->mode3++;
    case 1:
        if (fabsf(epw->yn - epw->py) > 0.3)
        {
            epw->py += (epw->yn - epw->py > 0.0f) ? 0.3f : -0.3f;
        }
        else
        {
            epw->py += 0.3f * (epw->yn - epw->py);
        }

        bhAddSpeed(epw, 0);

        if ((EXP0_F(0) < 30.0f) && (EXP0_UC(0x34)))
        {
            epw->yn = plp->py + 20.0f + (5.0f * njRandom());
        }

        epw->ayp = NJM_DEG_ANG(90) * epw->ct1 + bhArcTan2(plp->px - epw->px, plp->pz - epw->pz);

        if (bhEne07_AvoidWall(epw, epw->ct1))
        {
            if (epw->ct3 == 0)
            {
                epw->ct3 = 10;
            }
        }
        else
        {
            if (epw->ct3 > 0)
            {
                epw->ct3--;
            }
            else
            {
                epw->ay += (short)(epw->ayp - epw->ay) / 8;
            }
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x13301);
            epw->ct2 = 60 + (int)(30.0f * njRandom());
        }

        if (EXP0_I(0x38) > 0)
        {
            EXP0_I(0x38)--;
        }
        else if (bhEne07_CheckHangingWall(epw))
        {
            epw->mode1 = 0;
            epw->mode2 = 8;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne07_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 0x8000;
        epw->mode3++;
        epw->ct0 = 14 + (int)(8.0f * njRandom());
        epw->yn = 15.0f + bhGetGroundPosition((NJS_POINT3*)&epw->px) + (10.0f * njRandom());
        epw->ayp = epw->ay + NJM_DEG_ANG(40) - (NJM_DEG_ANG(20) * njRandom());
        EXP0_F(0x28) = 0.9f * njSin(epw->ayp);
        EXP0_F(0x30) = 0.9f * njCos(epw->ayp);
    case 1:
        epw->ax -= (short)epw->ax / 16;
        epw->ay += (short)(epw->ayp - epw->ay) / 16;
        epw->px += EXP0_F(0x28);
        epw->pz += EXP0_F(0x30);
        EXP0_F(0x28) -= 0.1f * njSin(epw->ayp);
        EXP0_F(0x30) -= 0.1f * njCos(epw->ayp);

        if (fabsf(epw->yn - epw->py) > 0.3)
        {
            epw->py += ((epw->yn - epw->py) > 0.0f) ? 0.3f : -0.3f;
        }
        else
        {
            epw->py += 0.3f * (epw->yn - epw->py);
        }

        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x40;
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne07_MV06(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne07_MV07(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne07_MV08(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x500000;
        EXP0_F(0x3C) = 1.5f;
        epw->ar = 1.5f;
        EXP0_F(0x40) = 1.5f;
        epw->car = 1.5f;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, junction_tree[0], &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->mtn_no = 3;
            epw->frm_no = 0;
            epw->flg |= 0x100000;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        else
        {
            epw->px += (EXP0_F(0x14) - epw->px) / 8.0f;
            epw->py += (EXP0_F(0x18) - epw->py) / 8.0f;
            epw->pz += (EXP0_F(0x1C) - epw->pz) / 8.0f;
            epw->ay += (epw->ayp - epw->ay) / 8;
        }
    }
}

// 100% matching!
void bhEne07_Nage(BH_PWORK* epw)
{
    bhEne07_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne07_NG00(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x20;
        epw->flg |= 0x100000;
        EXP0_F(0x40) = 0.1f;
        epw->car = 0.1f;

        if (epw->exp1[6] == sys->enow)
        {
            plp->mode0 = 4;
            plp->mode2 = 1;
            plp->mode3 = 0;
            epw->exp1[5] = 1;

            bhEne_CallPlayerVoice(2);
        }

        epw->mtn_no = 5;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 0x8000;
        epw->ct0 = 3 * epw->mnwP[epw->mtn_no].frm_num;
        epw->ct2 = 0;
        epw->mode3++;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2302);
    case 1:
        epw->ay += (short)(plp->ay + AtkAngle[EXP0_UC(0x35)] - epw->ay) / 8;
        njCalcPoint((NJS_MATRIX*)plp->mlwP->owP[AtkPos[EXP0_UC(0x35)]].mtx, &AtkOffset[EXP0_UC(0x35)], &pos);

        {
            NJS_VECTOR v = {0.0f, -1.0f, 2.0f};
            pos.x += v.z * njSin(epw->ay);
            pos.y += v.y;
            pos.z += v.z * njCos(epw->ay);
        }

        epw->px += (pos.x - epw->px) / 8.0f;
        epw->py += (pos.y - epw->py) / 8.0f;
        epw->pz += (pos.z - epw->pz) / 8.0f;
        epw->ct2 += bhEne_LeverCheck();

        if ((epw->ct0-- == 0) || (epw->exp1[0x5] == 0) || ((epw->ct0 == 24) && (epw->ct2 > 30)))
        {
            if (epw->exp1[0x6] == sys->enow)
            {
                epw->exp1[0x5] = 0;
                epw->exp1[0x0] = 0;
                epw->exp1[0x7] = 60;

                plp->mode0 = 4;
                plp->mode2 = 2;
                plp->mode3 = 0;
            }

            epw->flg |= 0x60;
            epw->flg &= ~0x1000;
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            EXP0_F(0x40) = 3.5f;
        }

        if ((epw->frm_no >> 0x10) == 9)
        {
            bhEne07_PlayerBloodEffect(epw, 1);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1002305);
            StartVibrationEx(1, 9);

            plp->hp -= 2;
            if (plp->hp <= 0)
            {
                plp->hp = 1;
            }
        }
    }
}

// 100% matching!
void bhEne07_NG01(BH_PWORK* epw)
{
    O_WORK* owk;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x20;
        epw->flg |= 0x100000;
        EXP0_F(0x40) = 0.1f;
        epw->car = 0.1f;
        EXP0_UC(0x35) = 4;

        plp->mode0 = 4;
        plp->mode2 = 0;
        plp->mode3 = 0;

        epw->mtn_no = 6;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 0x8000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 8;
        epw->ct2 = 0;
        epw->mode3++;

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2302);
        bhEne_CallPlayerVoice(2);
        StartVibrationEx(1, 9);
    case 1:
        {
            NJS_POINT3 pos;
            NJS_POINT3 offset = {0.0f, 0.3f, -5.2f};
            NJS_VECTOR v = {0.0f, 0.0f, 1.0f};

            owk = &plp->mlwP->owP[5];
            njCalcPoint((NJS_MATRIX*)owk->mtx, &offset, &pos);

            if (epw->ct1 > 0)
            {
                epw->px += (pos.x - epw->px) / epw->ct1;
                epw->py += (pos.y - epw->py) / epw->ct1;
                epw->pz += (pos.z - epw->pz) / epw->ct1;

                njSetMatrix((NJS_MATRIX*)epw->mtx, (NJS_MATRIX*)owk->mtx);
                njRotateY((NJS_MATRIX*)epw->mtx, NJM_DEG_ANG(180));
                njCalcVector((NJS_MATRIX*)owk->mtx, &v, &v);

                epw->ayp = bhArcTan2(-v.x, -v.z);
                epw->axp = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));
                epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
                epw->ax += (short)(epw->axp - epw->ax) / epw->ct1;
                epw->ct1--;
            }
            else
            {
                epw->px = pos.x;
                epw->py = pos.y;
                epw->pz = pos.z;
                epw->flg |= 0x1000;

                njSetMatrix((NJS_MATRIX*)epw->mtx, (NJS_MATRIX*)owk->mtx);
                njRotateY((NJS_MATRIX*)epw->mtx, NJM_DEG_ANG(180));

                (*epw->mtx)[12] = epw->px;
                (*epw->mtx)[13] = epw->py;
                (*epw->mtx)[14] = epw->pz;

                njCalcVector((NJS_MATRIX*)owk->mtx, &v, &v);

                epw->ay = bhArcTan2(-v.x, -v.z);
                epw->ax = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));
            }

            epw->ct2 += bhEne_LeverCheck();
        }

        if ((epw->ct0-- == 0) || ((epw->ct2 > 30) && ((epw->frm_no >> 0x10) > 20)))
        {
            epw->flg |= 0x60;
            epw->flg &= ~0x1000;
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            epw->exp1[0] = 0;
            epw->exp1[7] = 60;
            EXP0_F(0x40) = 3.5f;
        }

        if (((epw->frm_no >> 0x10) == 10) || ((epw->frm_no >> 0x10) == 20))
        {
            bhEne07_PlayerBloodEffect(epw, 1);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1002305);

            plp->hp -= 10;
            if (plp->hp <= 0)
            {
                plp->hp = 1;
            }
        }
    }
}

// 100% matching!
void bhEne07_Damage(BH_PWORK* epw)
{
    int i;
    int dam;

    for (i = 0, dam = 0; i < epw->mnwP->obj_num; i++) {
        if (epw->dam[i]) {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }
    epw->hp -= dam;

    if (epw->hp >= 0)
    {
        return;
    }

    if (dam > 50)
    {
        epw->mode2 = 6;

        epw->dpx = epw->px;
        epw->dpy = epw->py;
        epw->dpz = epw->pz;

        bhEne_SetMinceEffect(epw, 2, 3);
        bhEne_SetMinceEffect(epw, 0x103, 2);
        bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->dvx, 0, 9, 2);
    }
    else
    {
        if (bhEne_DGDirCheck(epw))
        {
            if (epw->flg & 0x400000)
            {
                epw->mode2 = 0;
            }
            else
            {
                if (bhEne07_CheckLeaningWall(epw, 0))
                {
                    epw->mode2 = 4;
                }
                else
                {
                    epw->mode2 = 2;
                }
            }
        }
        else if (epw->flg & 0x400000)
        {
            epw->mode2 = 1;
        }
        else if (bhEne07_CheckLeaningWall(epw, 1))
        {
            epw->mode2 = 5;
        }
        else
        {
            epw->mode2 = 3;
        }

        bhEne_SetBloodEffectBurst(epw, 1, 2, NULL, 0);

        if ((epw->wpnr_no == 0x10) || (epw->wpnr_no - 0x13 <= 1U))
        {
            NJS_POINT3 ofp;
            float size;  // Not in DWARF

            ofp.x = njRandom() - 0.5f;
            ofp.y = njRandom();
            ofp.z = 0.0f;
            size = 1.2f;
            bhEne_SetFireEffect(epw, 2, &ofp, size, 60 + (int)(10.0f * njRandom()));

            ofp.x = njRandom() - 0.5f;
            ofp.y = njRandom();
            ofp.z = 0.0f;
            size = 1.0f;
            bhEne_SetFireEffect(epw, 2, &ofp, size, 30 + (int)(10.0f * njRandom()));

            ofp.x = njRandom() - 0.5f;
            ofp.y = njRandom();
            ofp.z = 0.0f;
            size = 0.7f;
            bhEne_SetFireEffect(epw, 2, &ofp, size, 30 + (int)(10.0f * njRandom()));
        }

        if (epw->wpnr_no == 0xF)
        {
            NJS_POINT3 ofp;

            ofp.x = njRandom() - 0.5f;
            ofp.y = njRandom();
            ofp.z = 0.0f;

            bhEne_SetAcidEffect(epw, 2, &ofp, 2.0f);
        }
    }

    epw->flg |= 0x2;
    epw->flg &= ~0x68;

    EXP0_F(0x3C) = 2.5f;
    EXP0_F(0x40) = 2.5f;

    epw->mode0 = 4;
    epw->mode1 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne07_Die(BH_PWORK* epw)
{
    bhEne07_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne07_DD00(BH_PWORK* epw)
{
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 16;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = epw->dvx;
        EXP0_F(0x2C) = epw->dvy;
        EXP0_F(0x30) = epw->dvz;
        njUnitVector((NJS_VECTOR*)&EXP0_F(0x28));
        EXP0_F(0x28) *= 2.0f;
        EXP0_F(0x30) *= 2.0f;
        EXP0_I(0x20) = 0;
        EXP0_I(0x24) = 0;
        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        mkfP += (epw->frm_no >> 0x10);
        trans.x = mkfP->key[0];
        trans.y = mkfP->key[1];
        trans.z = mkfP->key[2];
        njUnitMatrix(NULL);
        njRotateY(NULL, epw->ay);
        njCalcVector(NULL, &trans, &trans);
        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->ct1 = 2;
        epw->mode3++;
    case 1:
        if (epw->flg & 0x200000) break;

        epw->mtn_no = ((int)(128.0f * njRandom()) & 1) ? 17 : 18;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->hokan_count = 0;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);
        epw->flg |= 0x200000;
        EXP0_F(0x2C) = 0.4f;
        EXP0_F(0x28) *= 0.5f;
        EXP0_F(0x30) *= 0.5f;
        break;

    case 2:
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x2C) = 0.0f;

            if ((epw->ct1) && (EXP0_I(0x24) != EXP0_I(0x20)) && bhEne07_ObjEdge(epw))
            {
                EXP0_I(0x24) = EXP0_I(0x20);
                epw->flg |= 0x200000;
                epw->ct1--;
            }
            else
            {
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
        }

        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (epw->ct0 == 0)
            {
                epw->mtn_add = 0;
            }
        }
        break;

    case 3:
        if (epw->ct0--) break;

        epw->mtn_no = (epw->mtn_no == 17) ? 28 : 29;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }

    if (epw->flg & 0x200000)
    {
        epw->px += EXP0_F(0x28);
        epw->py += EXP0_F(0x2C);
        epw->pz += EXP0_F(0x30);
        EXP0_F(0x2C) -= 0.2f;
    }
}

// 100% matching!
void bhEne07_DD01(BH_PWORK* epw)
{
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 16;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = epw->dvx;
        EXP0_F(0x2C) = epw->dvy;
        EXP0_F(0x30) = epw->dvz;
        njUnitVector((NJS_VECTOR*)&EXP0_F(0x28));
        EXP0_F(0x28) *= 2.0f;
        EXP0_F(0x30) *= 2.0f;
        EXP0_I(0x20) = 0;
        EXP0_I(0x24) = 0;
        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        mkfP += (epw->frm_no >> 0x10);
        trans.x = mkfP->key[0];
        trans.y = mkfP->key[1];
        trans.z = mkfP->key[2];
        njUnitMatrix(NULL);
        njRotateY(NULL, epw->ay);
        njCalcVector(NULL, &trans, &trans);
        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->ct1 = 2;
        epw->mode3++;
    case 1:
        if (epw->flg & 0x200000) break;

        epw->mtn_no = ((int)(128.0f * njRandom()) & 1) ? 17 : 18;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->hokan_count = 0;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);
        epw->flg |= 0x200000;
        EXP0_F(0x2C) = 0.4f;
        EXP0_F(0x28) *= 0.5f;
        EXP0_F(0x30) *= 0.5f;
        break;

    case 2:
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x2C) = 0.0f;

            if ((epw->ct1) && (EXP0_I(0x24) != EXP0_I(0x20)) && bhEne07_ObjEdge(epw))
            {
                EXP0_I(0x24) = EXP0_I(0x20);
                epw->flg |= 0x200000;
                epw->ct1--;
            }
            else
            {
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
        }

        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (epw->ct0 == 0)
            {
                epw->mtn_add = 0;
            }
        }
        break;

    case 3:
        if (epw->ct0--) break;

        epw->mtn_no = (epw->mtn_no == 17) ? 28 : 29;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }

    if (epw->flg & 0x200000)
    {
        epw->px += EXP0_F(0x28);
        epw->py += EXP0_F(0x2C);
        epw->pz += EXP0_F(0x30);
        EXP0_F(0x2C) -= 0.2f;
    }
}

// 100% matching!
void bhEne07_DD02(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;
    NJS_MKEY_A_MOD* mkaP;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 15;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = epw->dvx;
        EXP0_F(0x2C) = epw->dvy;
        EXP0_F(0x30) = epw->dvz;
        njUnitVector((NJS_POINT3*)&EXP0_F(0x28));
        EXP0_F(0x28) *= 2.0f;
        EXP0_F(0x30) *= 2.0f;
        EXP0_I(0x20) = 0;
        EXP0_I(0x24) = 0;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->ct1 = 2;
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, junction_tree[0], &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->mtn_no = 16;
            epw->frm_no = 0;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += (epw->frm_no >> 0x10);
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
        if (epw->flg & 0x200000) break;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += (epw->frm_no >> 0x10);
        epw->ay += mkaP->key[1];

        if (epw->mtn_no == 15)
        {
            epw->mtn_no = 18;
            epw->frm_no = 0x10000 * (float)(epw->mnwP[epw->mtn_no].frm_num - 1);
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 0x8000;
        }
        else
        {
            epw->mtn_no = ((int)(128.0f * njRandom()) & 1) ? 17 : 18;
            epw->frm_no = 0;
            epw->hokan_count = 0;
        }

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3 = 3;
        epw->flg |= 0x200000;
        EXP0_F(0x2C) = 0.4f;
        EXP0_F(0x28) *= 0.5f;
        EXP0_F(0x30) *= 0.5f;
        break;

    case 3:
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x2C) = 0.0f;

            if ((epw->ct1) && (EXP0_I(0x24) != EXP0_I(0x20)) && bhEne07_ObjEdge(epw))
            {
                EXP0_I(0x24) = EXP0_I(0x20);
                epw->flg |= 0x200000;
                epw->ct1--;
            }
            else
            {
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
        }

        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (epw->ct0 == 0)
            {
                epw->mtn_add = 0;
            }
        }
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_no = (epw->mtn_no == 17) ? 28 : 29;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 5:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }

    if (epw->flg & 0x200000)
    {
        epw->px += EXP0_F(0x28);
        epw->py += EXP0_F(0x2C);
        epw->pz += EXP0_F(0x30);
        EXP0_F(0x2C) -= 0.2f;
    }
}

// 100% matching!
void bhEne07_DD03(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;
    NJS_MKEY_A_MOD* mkaP;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 14;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = epw->dvx;
        EXP0_F(0x2C) = epw->dvy;
        EXP0_F(0x30) = epw->dvz;
        njUnitVector((NJS_POINT3*)&EXP0_F(0x28));
        EXP0_F(0x28) *= 2.0f;
        EXP0_F(0x30) *= 2.0f;
        EXP0_I(0x20) = 0;
        EXP0_I(0x24) = 0;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->ct1 = 2;
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, junction_tree[0], &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->mtn_no = 16;
            epw->frm_no = 0;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += (epw->frm_no >> 0x10);
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
        if (epw->flg & 0x200000) break;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += (epw->frm_no >> 0x10);
        epw->ay += mkaP->key[1];

        if (epw->mtn_no == 14)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0x10000 * (float)(epw->mnwP[epw->mtn_no].frm_num - 1);
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 0x8000;
        }
        else
        {
            epw->mtn_no = ((int)(128.0f * njRandom()) & 1) ? 17 : 18;
            epw->frm_no = 0;
            epw->hokan_count = 0;
        }

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3 = 3;
        epw->flg |= 0x200000;
        EXP0_F(0x2C) = 0.4f;
        EXP0_F(0x28) *= 0.5f;
        EXP0_F(0x30) *= 0.5f;
        break;

    case 3:
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x2C) = 0.0f;

            if ((epw->ct1) && (EXP0_I(0x24) != EXP0_I(0x20)) && bhEne07_ObjEdge(epw))
            {
                EXP0_I(0x24) = EXP0_I(0x20);
                epw->flg |= 0x200000;
                epw->ct1--;
            }
            else
            {
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
        }

        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (epw->ct0 == 0)
            {
                epw->mtn_add = 0;
            }
        }
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_no = (epw->mtn_no == 17) ? 28 : 29;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 5:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }

    if (epw->flg & 0x200000)
    {
        epw->px += EXP0_F(0x28);
        epw->py += EXP0_F(0x2C);
        epw->pz += EXP0_F(0x30);
        EXP0_F(0x2C) -= 0.2f;
    }
}

// 100% matching!
void bhEne07_DD04(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 27;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = 0.0f;
        EXP0_F(0x2C) = 0.0f;
        EXP0_F(0x30) = 0.0f;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->mode3++;
    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        epw->px += (EXP0_F(0x14) - epw->px) / 8;
        epw->pz += (EXP0_F(0x1C) - epw->pz) / 8;

        if (epw->ct0--) break;

        bhEne_GetPartsPos(epw, junction_tree[0], &pos);

        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;
        epw->mtn_no = 16;
        epw->frm_no = 0;

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        mkfP += epw->frm_no >> 16;
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
        break;

    case 2:
        if ((epw->flg & 0x200000) == 0)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);
            break;
        }

        epw->py += EXP0_F(0x2C);
        EXP0_F(0x2C) -= 0.2f;
        break;

    case 3:
        if (epw->ct0--) break;

        epw->mtn_no = 28;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }
}

// 100% matching!
void bhEne07_DD05(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_MKEY_F_MOD* mkfP;
    NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 26;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        epw->flg |= 0x200000;
        epw->flg &= ~0x100000;
        EXP0_F(0x28) = 0.0f;
        EXP0_F(0x2C) = 0.0f;
        EXP0_F(0x30) = 0.0f;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2307);
        epw->mode3++;
    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        epw->px += (EXP0_F(0x14) - epw->px) / 8;
        epw->pz += (EXP0_F(0x1C) - epw->pz) / 8;

        if (epw->ct0--) break;

        bhEne_GetPartsPos(epw, junction_tree[0], &pos);

        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;
        epw->mtn_no = 16;
        epw->frm_no = 0;

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        mkfP += epw->frm_no >> 16;
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
        break;

    case 2:
        if ((epw->flg & 0x200000) == 0)
        {
            epw->mtn_no = 18;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12308);
            break;
        }

        epw->py += EXP0_F(0x2C);
        EXP0_F(0x2C) -= 0.2f;
        break;

    case 3:
        if (epw->ct0--) break;

        epw->mtn_no = 29;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;

    case 4:
        if (epw->ct0--) break;

        epw->mtn_add = 0;
        epw->mode3++;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
    }
}

// 100% matching!
void bhEne07_DD06(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mlwP->objP[1].evalflags |= 0x8;
        epw->flg |= 0x8000;

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2306);

        epw->stflg |= 0x8;
        epw->mtn_add = 0;
        epw->mode3++;
    }
}

// 100% matching!
void bhEne07_SearchPlayer(BH_PWORK* epw)
{
    float dx;
    float dz;
    NJS_POINT3 pos;

    EXP0_UC(0x34) = 1;

    pos.x = plp->px;
    pos.y = plp->py;
    pos.z = plp->pz;

    if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos)) {
        EXP0_UC(0x34) = 0;
    }

    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0) = njSqrt((dx * dx) + (dz * dz));
}

// 100% matching!
void bhEne07_CollisionWalls(BH_PWORK* epw)
{
    NJS_POINT3 ofp;

    bhEne07_CalcAtariOffset(epw, &ofp);

    epw->px += ofp.x;
    epw->py += ofp.y;
    epw->pz += ofp.z;

    bhEne03_Collision(epw);

    epw->px -= ofp.x;
    epw->py -= ofp.y;
    epw->pz -= ofp.z;
}

// 100% matching!
void bhEne07_FloorCollision(BH_PWORK* epw)
{
    NJS_VECTOR n;
    ATR_WORK* hp;

    hp = bhCollisionCheckLine2((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px, 0x4000, -1);

    if (hp == NULL) return;

    bhGetHitCollisionNormal(&n);

    if (n.y > 0.9f) {
        epw->flg &= ~0x200000;
        EXP0_ATR(7) = hp;
    }

    if (n.y < 0.9f) {
        EXP0_F(0x2C) = 0.0f;
    }

    if (n.y == 0.0f) {
        EXP0_F(0x28) = 0.0f;
        EXP0_F(0x2C) = 0.0f;
        EXP0_F(0x30) = 0.0f;
    }
}

// 100% matching!
int bhEne07_CheckLeaningWall(BH_PWORK* epw, int flg)
{
    return 0;
}

// 100% matching!
int bhEne07_CheckHangingWall(BH_PWORK* epw)
{
    NJS_VECTOR vec;
    NJS_VECTOR n;
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    ATR_WORK* hp;
    NJS_MKEY_F_MOD* mkfP;
    BH_PWORK* ep;
    float dist;
    int i;

    vec.x = 0.0f;
    vec.y = 10.0f;
    vec.z = -10.0f;

    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &vec, &vec);

    pos.x = epw->px + vec.x;
    pos.y = epw->py + vec.y;
    pos.z = epw->pz + vec.z;

    for (i = 0, ep = ene; i < sys->ewk_n; i++, ep++) {
        if ((ep->flg & 0x1) && (ep->id == 7) && (ep != epw)) {
            dist = njDistanceP2P((NJS_POINT3*)&ep->px, &pos);

            if (dist < 3.0f) {
                return 0;
            }
        }
    }

    hp = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos);

    if ((hp != NULL) && (hp->type == 7) && !(hp->attr & 0x8)) {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);

        if (n.y < -0.9f) {
            float tmp = 5.0f;  // Not in DWARF

            pos2.x = pos.x;
            pos2.y = pos.y - 5.1f;
            pos2.z = pos.z;

            if (bhCheckWallType(&pos2, 0, tmp, tmp) == NULL) {
                mkfP = epw->mnwP[2].md2P->p[0];
                mkfP += epw->mnwP[2].frm_num - 1;
                vec.x = mkfP->key[0];
                vec.y = mkfP->key[1];
                vec.z = mkfP->key[2];

                njUnitMatrix(NULL);
                njRotateY(NULL, epw->ay);
                njCalcVector(NULL, &vec, &vec);

                EXP0_F(0x14) = pos.x - vec.x;
                EXP0_F(0x18) = pos.y - vec.y;
                EXP0_F(0x1C) = pos.z - vec.z;
                EXP0_ATR(7) = hp;
                epw->ayp = epw->ay;

                return 1;
            }
        }
    }

    return 0;
}

// 100% matching!
int bhEne07_AvoidWall(BH_PWORK* epw, int dir)
{
    NJS_POINT3 pos1;
    NJS_POINT3 pos2;
    ATR_WORK* hp1;
    ATR_WORK* hp2;
    NJS_POINT3 body;
    NJS_POINT3 vdB;
    NJS_POINT3 trans;
    int i;
    BH_PWORK* ep;
    BH_PWORK* ep2;
    float dist;
    float wdist;
    float dx;
    float dz;
    NJS_MKEY_A_MOD* mkaP;
    NJS_CNK_OBJECT* objP;

    ep = ene;
    ep2 = NULL;
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if ((ep != epw) && (ep->flg & 0x1) && (ep->id == 7) && !(ep->flg & 0x2))
        {
            dist = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&ep->px);
            if ((ep2 == NULL) || (dist < wdist))
            {
                wdist = dist;
                ep2 = ep;
            }
        }
    }

    if ((ep2 != NULL) && (wdist < 20.0f) && (fabsf(epw->py - ep2->py) < 10.0f))
    {
        if (ep2->yn < epw->py)
        {
            epw->yn += 3.5f;
        }
        else
        {
            epw->yn -= 3.5f;
        }
    }

    if ((epw->mode2 == 4) && (epw->py > plp->py) && (epw->py < plp->py + 20.0f))
    {
        dx = epw->px - 10.0f * njSin(epw->ay) - plp->px;
        dz = epw->pz - 10.0f * njCos(epw->ay) - plp->pz;
        if (njSqrt(dx * dx + dz * dz) < 10.0f)
        {
            epw->ay += NJM_DEG_ANG(10) * dir;
        }
    }

    body.x = body.z = 0.0f;
    body.y = (epw->flg & 0x400000) ? 1.5f : 3.5f;

    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);

    if (epw->flg & 0x100000)
    {
        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += (epw->frm_no >> 0x10);
        njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
    }

    njCalcVector(NULL, &body, &vdB);

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

    pos1.x = epw->px + trans.x + vdB.x;
    pos1.y = epw->py + trans.y + vdB.y;
    pos1.z = epw->pz + trans.z + vdB.z;

    pos2.x = pos1.x;
    pos2.y = pos1.y - 4.5f;
    pos2.z = pos1.z;

    hp1 = bhCollisionCheckLine(&pos1, &pos2);
    if (hp1 == NULL)
    {
        pos1.x = epw->px + trans.x + vdB.x;
        pos1.y = epw->py + trans.y + vdB.y - 4.5f;
        pos1.z = epw->pz + trans.z + vdB.z;

        pos2.x = pos1.x - 10.0f * njSin(epw->ay);
        pos2.y = epw->py + trans.y + vdB.y;
        pos2.z = pos1.z - 10.0f * njCos(epw->ay);

        hp1 = bhCollisionCheckLine(&pos1, &pos2);
    }

    {
        float tmp = 4.5f;  // Not in DWARF

        pos1.x = epw->px + trans.x + vdB.x;
        pos1.y = epw->py + trans.y + vdB.y;
        pos1.z = epw->pz + trans.z + vdB.z;

        pos2.x = pos1.x;
        pos2.y = pos1.y + tmp;
        pos2.z = pos1.z;
    }

    hp2 = bhCollisionCheckLine(&pos1, &pos2);
    if (hp2 == NULL)
    {
        pos1.x = epw->px + trans.x + vdB.x;
        pos1.y = epw->py + trans.y + vdB.y + 4.5f;
        pos1.z = epw->pz + trans.z + vdB.z;

        pos2.x = pos1.x - 10.0f * njSin(epw->ay);
        pos2.y = epw->py + trans.y + vdB.y;
        pos2.z = pos1.z - 10.0f * njCos(epw->ay);

        hp2 = bhCollisionCheckLine(&pos1, &pos2);
    }

    if ((hp1 != NULL) && (hp2 != NULL))
    {
        epw->ay += NJM_DEG_ANG(10) * dir;
        return 1;
    }

    if ((hp1 != NULL) && (hp2 == NULL))
    {
        if (hp1->type == 7)
        {
            float tmp = 4.5f;  // Not in DWARF
            epw->yn = hp1->py + tmp;
        }
        else
        {
            epw->yn = hp1->py + hp1->h + 4.5f;
        }
        epw->yn -= trans.y + vdB.y;
    }

    if ((hp1 == NULL) && (hp2 != NULL))
    {
        if (hp2->type == 7)
        {
            epw->yn = hp2->py + hp2->h - 4.5f;
        }
        else
        {
            epw->yn = hp2->py - 4.5f;
        }
        epw->yn -= trans.y + vdB.y;
    }

    pos2.x = pos1.x - 2.0f * njSin(epw->ay);
    pos2.y = epw->py + trans.y + vdB.y;
    pos2.z = pos1.z - 2.0f * njCos(epw->ay);

    if (bhCheckWallType(&pos2, 0, 2.0f, 1.0f) != NULL)
    {
        epw->ay += NJM_DEG_ANG(10) * dir;
        return 1;
    }

    return 0;
}

// 100% matching!
void bhEne07_PlayerBloodEffect(BH_PWORK* epw, unsigned char size)
{
    NJS_POINT3 pos;
    NJS_VECTOR v;

    njCalcPoint(&plp->mlwP->owP[AtkPos[EXP0_UC(0x35)]].mtx, &AtkOffset[EXP0_UC(0x35)], &pos);

    v.x = pos.x - epw->px;
    v.y = pos.x - epw->py;
    v.z = pos.x - epw->pz;

    bhEne_SetBloodEffect4(&pos, &v, 0, 10, size);
}

// 100% matching!
void bhEne07_PlayerControl(BH_PWORK* epw)
{
    unsigned int ply_motion[3][3] = {
        {0x1E, 0x1F, 0x20},
        {0x21, 0x22, 0x23},
        {0x24, 0x25, 0x26}
    };

    switch (plp->mode2)
    {
    case 0:
        switch (plp->mode3)
        {
        case 0:
            plp->flg |= 0x40000;
            plp->flg |= 0x80000;
            plp->flg |= 0x10004;
            plp->stflg |= 0x10000;
            plp->mnwP = epw->mnwP;
            plp->mtn_no = ply_motion[sys->ply_id][1];
            plp->frm_no = 0;
            plp->hokan_count = 5;
            plp->hokan_rate = 0xCCCC;
            plp->mtn_add = 0x10000;
            EXP1_I(0) |= 0x1E0;
            EXP1_I(0) &= ~0x4;
            plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
            plp->mode3++;
        case 1:
            if (plp->ct0-- == 0) {
                plp->mnwP = plp->mnwPb;
                plp->flg &= ~0x10004;
                plp->flg |= 0x8;
                plp->at_flg = 0x0;
                plp->stflg &= ~0x10000;
                *((int*)&plp->mode0) = 1;
                EXP1_I(0) |= 0x4;
            }
        }
        break;

    case 1:
        if (plp->mode3 != 0) break;

        plp->flg |= 0x40000;
        plp->flg &= ~0x80000;
        plp->flg |= 0x10004;
        plp->stflg |= 0x10000;
        plp->mnwP = epw->mnwP;
        plp->mtn_no = ply_motion[sys->ply_id][2];
        plp->frm_no = 0;
        plp->hokan_count = 5;
        plp->hokan_rate = 0xCCCC;
        plp->mtn_add = 0x10000;
        EXP1_I(0) |= 0x1E0;
        EXP1_I(0) &= ~0x4;
        plp->mode3++;
        break;

    case 2:
        switch (plp->mode3)
        {
        case 0:
            plp->mnwP = epw->mnwP;
            plp->mtn_no = ply_motion[sys->ply_id][0];
            plp->frm_no = 0;
            plp->mtn_add = 0x10000;
            plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
            plp->mode3++;
        case 1:
            if (plp->ct0-- == 0) {
                plp->mnwP = plp->mnwPb;
                plp->flg &= ~0x10004;
                plp->flg |= 0x8;
                plp->at_flg = 0x0;
                plp->stflg &= ~0x10000;
                *((int*)&plp->mode0) = 1;
                EXP1_I(0) |= 0x4;
            }
        }
    }
}

// 100% matching!
int bhEne07_ObjEdge(BH_PWORK* epw)
{
    int ret;
    ATR_WORK* hp;
    NJS_POINT3 p1;
    NJS_POINT3 p2;

    ret = 0;
    hp = EXP0_ATR(7);

    switch (hp->type)
    {
    case 0:
    case 1:
    case 7:
        if ((epw->px >= hp->px) && (epw->px <= hp->px + 1.0f) && (epw->px <= hp->px + (hp->w / 2.0f)))
        {
            ret = 1;
            epw->px = hp->px - 0.1f;
            EXP0_F(0x28) = -0.2f;
        }
        else if ((epw->px <= hp->px + hp->w) && (epw->px >= hp->px + hp->w - 1.0f) && (epw->px >= hp->px + (hp->w / 2.0f)))
        {
            ret = 1;
            epw->px = hp->px + hp->w + 0.1f;
            EXP0_F(0x28) = 0.2f;
        }

        if ((epw->pz >= hp->pz) && (epw->pz <= hp->pz + 1.0f) && (epw->pz <= hp->pz + (hp->d / 2.0f)))
        {
            ret = 1;
            epw->pz = hp->pz - 0.1f;
            EXP0_F(0x30) = -0.2f;
        }
        else if ((epw->pz <= hp->pz + hp->d) && (epw->pz >= hp->pz + hp->d - 1.0f) && (epw->pz >= hp->pz + (hp->d / 2.0f)))
        {
            ret = 1;
            epw->pz = hp->pz + hp->d + 0.1f;
            EXP0_F(0x30) = 0.2f;
        }
    }

    if (ret != 0) {
        p1.x = epw->px;
        p1.y = epw->py + 0.1f;
        p1.z = epw->pz;

        p2.x = epw->px;
        p2.y = epw->py - 0.1f;
        p2.z = epw->pz;

        if (bhCollisionCheckLine2(&p1, &p2, 0x4000, -1) && (epw->py == p2.y)) {
            return 0;
        }
    }

    return ret;
}

// 100% matching!
void bhEne07_CalcAtariOffset(BH_PWORK* epw, NJS_POINT3* ofp)
{
    NJS_POINT3 body;
    NJS_POINT3 trans;
    NJS_MKEY_A_MOD* mkaP;
    NJS_CNK_OBJECT* objP;

    body.x = body.z = 0;
    body.y = epw->ar;

    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);

    if (epw->flg & 0x100000) {
        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no >> 0x10;
        njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
    }

    njCalcVector(NULL, &body, ofp);

    objP = epw->mlwP->objP;
    trans.x = objP->pos[0];
    trans.y = objP->pos[1];
    trans.z = objP->pos[2];
    if (!(epw->flg & 0x80000)) {
        trans.y = 0.0f;
    }

    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &trans, &trans);
    njAddVector(ofp, &trans);
}
