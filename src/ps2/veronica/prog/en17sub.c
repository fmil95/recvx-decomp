#include "../../../ps2/veronica/prog/en17sub.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

typedef void (*Mode0_proc)(BH_PWORK*);

Mode0_proc bhEne17LArm_Mode0[4] =
{
    bhEne17LArm_Init,
    bhEne17LArm_Move,
    NULL,
    NULL
};

Mode0_proc bhEne17RArm_Mode0[4] =
{
    bhEne17RArm_Init,
    bhEne17RArm_Move,
    NULL,
    NULL
};

void bhEne17LArm(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* obj;
    BH_PWORK* epp;

    epp = (BH_PWORK*)epw->lkwkp;

    bhEne17LArm_Mode0[epw->mode0](epw);

    bhCalcModel(epw);

    if (epp->flg & 0x80000000)
    {
        if (epp->flg & 0x40000000) bhEne17_AxsCheck(epw);
    }
    else
    {
        bhEne17_AxsCheck(epw);
    }

    obj = &epw->mlwP->objP[1];

    if (epp->type == 1)
    {
        obj->evalflags |= 0x8;
    }
    else
    {
        obj->evalflags &= ~0x8;
    }
}

void bhEne17LArm_Init(BH_PWORK* epw)
{
    BH_PWORK* epp;
    float* ax_p1;
    float* ax_p2;
    int i;

    epp = (BH_PWORK*)epw->lkwkp;

    epw->stflg = 0;

    epw->flg |= 0x8000;
    epw->mdflg |= 0x20;

    ax_p1 = (float*)epp->exp1;
    ax_p2 = (float*)(epp->exp1 + 0x138);

    for (i = 0; i < 15; i++)
    {
        *ax_p1++ = 0.0f;
        *ax_p2++ = 0.0f;
    }

    ax_p1 = (float*)(epp->exp1 + 0x48);
    ax_p2 = (float*)(epp->exp1 + 0x180);

    for (i = 0; i < 60; i++)
    {
        *ax_p1++ = 0.0f;
        *ax_p2++ = 0.0f;
    }

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

void bhEne17LArm_Move()
{

}

void bhEne17RArm(BH_PWORK* epw)
{
    bhEne17RArm_Mode0[epw->mode0](epw);

    bhCalcModel(epw);
}

void bhEne17RArm_Init(BH_PWORK* epw)
{
    epw->stflg = 0;

    epw->flg |= 0x8000;
    epw->mdflg |= 0x20;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

void bhEne17RArm_Move()
{

}

void bhEne17_AxsCheck(BH_PWORK* epw)
{
    BH_PWORK* epp;
    O_WORK* owk;
    NJS_POINT3 ps;
    NJS_POINT3 pd;
    int i;
    float idata[6][3];
    NJS_SPLINE attr;
    int iparam;
    float fparam;

    epp = (BH_PWORK*)epw->lkwkp;

    owk = &epw->mlwP->owP[1];

    ps.x = 0.0f;
    ps.y = 0.0f;

    ps.z = -19.5f;
    njCalcPoint(&owk->mtx, &ps, &pd);

    for (i = 5; i > 0; i--)
    {
        ((NJS_POINT3*)epp->exp1)[i].x = ((NJS_POINT3*)epp->exp1)[i - 1].x;
        ((NJS_POINT3*)epp->exp1)[i].y = ((NJS_POINT3*)epp->exp1)[i - 1].y;
        ((NJS_POINT3*)epp->exp1)[i].z = ((NJS_POINT3*)epp->exp1)[i - 1].z;

        ((NJS_POINT3*)epp->exp1)[i + 26].x = ((NJS_POINT3*)epp->exp1)[i + 25].x;
        ((NJS_POINT3*)epp->exp1)[i + 26].y = ((NJS_POINT3*)epp->exp1)[i + 25].y;
        ((NJS_POINT3*)epp->exp1)[i + 26].z = ((NJS_POINT3*)epp->exp1)[i + 25].z;
    }

    ((NJS_POINT3*)epp->exp1)[i].x = pd.x;
    ((NJS_POINT3*)epp->exp1)[i].y = pd.y;
    ((NJS_POINT3*)epp->exp1)[i].z = pd.z;

    ((NJS_POINT3*)epp->exp1)[i + 26].x = owk->mtx[12];
    ((NJS_POINT3*)epp->exp1)[i + 26].y = owk->mtx[13];
    ((NJS_POINT3*)epp->exp1)[i + 26].z = owk->mtx[14];

    attr.keys = 0;
    attr.iparam = &iparam;
    attr.fparam = &fparam;
    *attr.iparam = 6;

    for (i = 0; i < 6; i++)
    {
        idata[i][0] = ((NJS_POINT3*)epp->exp1)[i].x;
        idata[i][1] = ((NJS_POINT3*)epp->exp1)[i].y;
        idata[i][2] = ((NJS_POINT3*)epp->exp1)[i].z;
    }

    ((NJS_POINT3*)epp->exp1)[6].x = ((NJS_POINT3*)epp->exp1)[0].x;
    ((NJS_POINT3*)epp->exp1)[6].y = ((NJS_POINT3*)epp->exp1)[0].y;
    ((NJS_POINT3*)epp->exp1)[6].z = ((NJS_POINT3*)epp->exp1)[0].z;

    for (i = 1; i < 20; i++)
    {
        njBezierSpline((float*)idata, (float*)(epp->exp1 + (i * 12) + 0x48), &attr, 0.05f * i);
    }

    for (i = 0; i < 6; i++)
    {
        idata[i][0] = ((NJS_POINT3*)epp->exp1)[i + 26].x;
        idata[i][1] = ((NJS_POINT3*)epp->exp1)[i + 26].y;
        idata[i][2] = ((NJS_POINT3*)epp->exp1)[i + 26].z;
    }

    ((NJS_POINT3*)epp->exp1)[32].x = ((NJS_POINT3*)epp->exp1)[26].x;
    ((NJS_POINT3*)epp->exp1)[32].y = ((NJS_POINT3*)epp->exp1)[26].y;
    ((NJS_POINT3*)epp->exp1)[32].z = ((NJS_POINT3*)epp->exp1)[26].z;

    for (i = 1; i < 20; i++)
    {
        njBezierSpline((float*)idata, (float*)(epp->exp1 + (i * 12) + 0x180), &attr, 0.05f * i);
    }
}
