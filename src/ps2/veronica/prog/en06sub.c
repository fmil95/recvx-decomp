#include "../../../ps2/veronica/prog/en06sub.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

#pragma divbyzerocheck on

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne06s_Mode0[3] =
{
    bhEne06s_Init,
    bhEne06s_Move,
    bhEne06s_Dummy
};
MoveMode2_proc bhEne06s_MoveMode2[2] =
{
    bhEne06s_MV00,
    bhEne06s_MV01
};

static NJS_POINT3 CollisionOffset[4][3] =
{
    { { 0.0f, 0.0f, 0.0f }, {  5.0f, -0.5f, -2.5f }, {  3.5f, -0.5f, 1.5f } },
    { { 0.0f, 0.0f, 0.0f }, { -5.0f, -0.5f, -2.5f }, { -3.5f, -0.5f, 1.5f } },
    { { 0.0f, 0.0f, 0.0f }, {  3.0f, -0.5f,  2.0f }, {  0.5f, -0.3f, 5.0f } },
    { { 0.0f, 0.0f, 0.0f }, { -3.0f, -0.5f,  2.0f }, { -0.5f, -0.3f, 5.0f } }
};

// 100% matching!
void bhEne06s(BH_PWORK* epw)
{
    bhEne06s_Mode0[epw->mode0](epw);

    if ((epw->flg & 0x10))
    {
        if (epw->lkono < 4)
        {
            bhEne06s_WallCheck(epw);
        }
        else
        {
            bhEne06s_FloorCollision(epw);
            bhEne03_Collision(epw);
        }
    }
}

// 100% matching!
void bhEne06s_Init(BH_PWORK* epw)
{
    epw->flg &= ~0x10;

    epw->ar = 0.5f;
    epw->ah = 0.3f;

    epw->car = 0.5f;
    epw->cah = 0.3f;

    epw->mode0 = 2;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(68, 8);
    }
}

// 100% matching!
void bhEne06s_Move(BH_PWORK* epw)
{
    bhEne06s_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne06s_MV00(BH_PWORK* epw)
{
    NJS_POINT3 v, vd, ov;
	float out;
	int ang;

    switch (epw->mode3)
    {
	case 0:
		epw->px = epw->pxb = epw->mtx[0][12];
		epw->py = epw->pyb = epw->mtx[0][13];
		epw->pz = epw->pzb = epw->mtx[0][14];

		EXP0_F(4)  = (-rand() / -2.1474836E9f) - 0.5f;
		EXP0_F(8)  = (-rand() / -2.1474836E9f) - 0.2f;
		EXP0_F(12) = (-rand() / -2.1474836E9f) - 0.5f;

		EXP0_US(0) |= 0x1;

		epw->flg |= 0x10;

		epw->ct3 = 8;

		epw->mode3++;
	case 1:
		if ((EXP0_US(0) & 0x1))
		{
			EXP0_F(8) -= 0.1f;

			epw->px += EXP0_F(4);
			epw->py += EXP0_F(8);
			epw->pz += EXP0_F(12);
		}
		else
		{
			epw->mode3++;
		}

		epw->mtx[0][12] = epw->px;
		epw->mtx[0][13] = epw->py;
		epw->mtx[0][14] = epw->pz;
		break;
	case 2:
		if (epw->ct3 != 0)
		{
			v.x = EXP0_F(16);
			v.y = EXP0_F(20);
			v.z = EXP0_F(24);

			njCalcVector(epw->mtx, &v, &vd);

			if (vd.y < 0)
			{
				vd.x *= -1.0f;
				vd.y *= -1.0f;
				vd.z *= -1.0f;
			}

			out = njOuterProduct(&vd, &v, &ov);

			njUnitVector(&ov);
			njUnitMatrix(NULL);

			ang = njArcSin(out);

			njRotate(NULL, &ov, ang / epw->ct3);
			njMultiMatrix(NULL, epw->mtx);

			njGetMatrix(epw->mtx);

			if (ang < 18)
			{
				epw->flg &= ~0x10;

				epw->mode0 = 2;
			}

			epw->ct3--;
		}

		epw->mtx[0][12] = epw->px;
		epw->mtx[0][13] = epw->py;
		epw->mtx[0][14] = epw->pz;
		break;
    }
}

// 100% matching!
void bhEne06s_MV01(BH_PWORK* epw)
{
    NJS_POINT3 avec, vd, ov;
	float out;
	int ang;

    switch (epw->mode3)
    {
	case 0:
		epw->px = epw->pxb = epw->mtx[0][12];
		epw->py = epw->pyb = epw->mtx[0][13];
		epw->pz = epw->pzb = epw->mtx[0][14];

		EXP0_F(4)  = (-rand() / -2.1474836E9f) - 0.5f;
		EXP0_F(8)  = (-rand() / -2.1474836E9f) - 0.2f;
		EXP0_F(12) = (-rand() / -2.1474836E9f) - 0.5f;

		EXP0_US(0) |= 0x1;

		epw->flg |= 0x10;

		njCalcPoints(epw->mtx, CollisionOffset[epw->lkono], (NJS_POINT3*)&epw->exp0[28], 3);

		epw->mode3++;
	case 1:
		if ((EXP0_US(0) & 0x1))
		{
			avec.x = 0;
			avec.y = 0;
			avec.z = -0.1f;

			njCalcVector(epw->mtx, &avec, &avec);

			if (avec.y > 0)
			{
				avec.y *= -1.0f;
			}

			njRotateX(epw->mtx, 910);
			njRotateZ(epw->mtx, 364);
			njRotateY(epw->mtx, 546);

			EXP0_F(8) += avec.y - 0.01f;

			epw->px += EXP0_F(4);
			epw->py += EXP0_F(8);
			epw->pz += EXP0_F(12);
		}
		else
		{
			epw->mode3++;

			epw->ct3 = 10;
		}

		epw->mtx[0][12] = epw->px;
		epw->mtx[0][13] = epw->py;
		epw->mtx[0][14] = epw->pz;
		break;
	case 2:
		if (epw->ct3 > 0)
		{
			njGetPlaneNormal(CollisionOffset[epw->lkono], &vd);

			njCalcVector(epw->mtx, &vd, &vd);

			if (vd.y < 0)
			{
				vd.x *= -1.0f;
				vd.y *= -1.0f;
				vd.z *= -1.0f;
			}

			njUnitVector(&vd);

			out = njOuterProduct(&vd, (NJS_VECTOR*)&epw->exp0[16], &ov);

			njUnitVector(&ov);

			njSubVector((NJS_VECTOR*)&epw->mtx[0][12], (NJS_VECTOR*)(&epw->exp0[EXP0_I(64) * 12] + 28));

			ang = njArcSin(out);

			njUnitMatrix(NULL);

			njRotate(NULL, &ov, ang / epw->ct3);
			njMultiMatrix(NULL, epw->mtx);

			njGetMatrix(epw->mtx);

			njAddVector((NJS_VECTOR*)&epw->mtx[0][12], (NJS_VECTOR*)(&epw->exp0[EXP0_I(64) * 12] + 28));

			epw->px = epw->mtx[0][12];
			epw->py = epw->mtx[0][13];
			epw->pz = epw->mtx[0][14];

			epw->ct3--;
		}
		else
		{
			epw->mode0 = 2;

			epw->flg &= ~0x10;
		}

		epw->mtx[0][12] = epw->px;
		epw->mtx[0][13] = epw->py;
		epw->mtx[0][14] = epw->pz;
		break;
    }
}

// 100% matching!
void bhEne06s_Dummy()
{

}

// 100% matching!
void bhEne06s_FloorCollision(BH_PWORK* epw)
{
    ATR_WORK* hp;

    if ((EXP0_US(0) & 0x1))
    {
        hp = bhCollisionCheckLine((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px);

        if (hp != NULL)
        {
            bhGetHitCollisionNormal((NJS_POINT3*)&epw->exp0[16]);
            
			njUnitVector((NJS_VECTOR*)&epw->exp0[16]);

            if (EXP0_F(20) > 0)
            {
                EXP0_US(0) &= ~0x1;
            }

            if (EXP0_F(20) < 0)
            {
                EXP0_F(8) = 0;
            }

            if (EXP0_F(20) == 0)
            {
                EXP0_F(4)  = 0;
                EXP0_F(12) = 0;
            }
        }

        epw->mtx[0][12] = epw->px;
        epw->mtx[0][13] = epw->py;
        epw->mtx[0][14] = epw->pz;
    }
}

// 100% matching!
void bhEne06s_WallCheck(BH_PWORK* epw)
{
	NJS_POINT3 vec;
	int i;
    ATR_WORK* hp;
    
    if ((EXP0_US(0) & 0x1))
    {
        for (i = 0; i < 3; i++)
        {
            njCalcVector(epw->mtx, &CollisionOffset[epw->lkono][i], &vec);
            njAddVector((NJS_VECTOR*)&epw->px, &vec);

            hp = bhCollisionCheckLine((NJS_POINT3*)(&epw->exp0[(i * 12)] + 28), (NJS_POINT3*)&epw->px);

            if (hp != NULL)
            {
                bhGetHitCollisionNormal((NJS_POINT3*)&epw->exp0[16]);

                njUnitVector((NJS_VECTOR*)&epw->exp0[16]);

                if (EXP0_F(20) > 0)
                {
                    EXP0_US(0) &= ~0x1;

                    EXP0_I(64) = i;
                }

                if (EXP0_F(20) < 0)
                {
                    EXP0_F(8) = 0;
                }

                if (EXP0_F(20) == 0)
                {
                    EXP0_F(4)  = 0;
                    EXP0_F(12) = 0;
                }
            }

            bhEne03_Collision(epw);

            njSubVector((NJS_VECTOR*)&epw->px, &vec);
        }

        epw->mtx[0][12] = epw->px;
        epw->mtx[0][13] = epw->py;
        epw->mtx[0][14] = epw->pz;

        njCalcPoints(epw->mtx, CollisionOffset[epw->lkono], (NJS_POINT3*)&epw->exp0[28], 3);
    }
}
