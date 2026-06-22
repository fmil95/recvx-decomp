#include "../../../ps2/veronica/prog/en08.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne08_Mode0[6] =
{
    bhEne08_Init,
    bhEne08_Move,
    bhEne08_Nage,
    bhEne08_Damage,
    bhEne08_Die,
    bhEne_Event 
};

MoveMode2_proc bhEne08_MoveMode2[3] =
{ 
    bhEne08_MV00,
    bhEne08_MV01,
    bhEne08_MV02
};

// 100% matching! 
void bhEne08(BH_PWORK* epw)
{
    bhEne08_Mode0[epw->mode0](epw);
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    epw->ar = 5.0f;
    bhEne03_Collision(epw);
    bhEne_CheckEnemiesBall(epw);
    bhCalcModel(epw);
}

// 100% matching! 
void bhEne08_Init(BH_PWORK* epw)
{
    epw->flg |= 0x8018;
    epw->flg &= ~6;

    epw->ar = 5.0f;
    epw->ah = 1.0f;
    epw->car = 3.0f;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate = 65536;
    epw->hokan_count = 0;

    epw->mtn_no = 0;
    epw->mtn_md = 0;
    epw->mtn_add = 65536;

    epw->frm_no = 0;

    epw->clp_jno[0] = 0;
    epw->clp_jno[1] = -1;

    epw->mdflg &= ~0x20;

    epw->ct1 = ((-rand()) / -2.1474836e9f > 0.5f) ? 1 : -1;
}

// 100% matching! 
void bhEne08_Move(BH_PWORK* epw) 
{ 
    bhEne08_MoveMode2[epw->mode2](epw); 
}

// 99.96% matching
void bhEne08_MV00(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	float dy;  
    ATR_WORK* hp;
	NJS_VECTOR vec;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;

        epw->ct0 = (int)(njRandom() * 180.0f) + 120;
        epw->ct1 = (njRandom() > 0.5f) ? 1 : -1;
        epw->spd = 0.01f;
        epw->ayp = epw->ay + bhRandomAngle(3);
        epw->yn  = njRandom() * 2.0f + epw->py - 1.0f;
        epw->mode3++;
            
    case 1:
        bhAddSpeed(epw, 0);
        
        if (epw->ct0-- == 0)
        {
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

    }

    epw->ay += (short)(epw->ayp - epw->ay) / 8;

    epw->py += (epw->yn - epw->py) / 100.0f;
    dy = (epw->yn - epw->py) / 100.0f; 
    epw->py += dy;
    
    epw->axp = njArcTan2(dy, 0.1f);

    epw->ax += (short)(epw->axp - epw->ax) / 16;

    pos.x = epw->px - njSin(epw->ayp) * 20.0f;
    pos.y = epw->py;
    pos.z = epw->pz - njCos(epw->ayp) * 20.0f;

    if (bhCheckWallType(&pos, 0, 5.0f, 1.0f))
    {
        epw->ayp += epw->ct1 * 91;
    }

    pos.x = epw->px - njSin(epw->ayp) * 7.0f;
    pos.y = epw->py;
    pos.z = epw->pz - njCos(epw->ayp) * 7.0f;

    hp = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos);
    if (hp != NULL)
    {
        bhGetHitCollisionNormal(&vec);
        njUnitVector(&vec);
    
        njUnitMatrix(NULL);
        njRotateY(NULL, -epw->ay);
        njCalcVector(NULL, &vec, &vec);

        if (vec.x < 0.0f)
        {
            epw->ct1 = 1;
        }
        else
        {
            epw->ct1 = -1;
        }

        epw->ayp = njArcSin(vec.z);
        
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 99.96% matching
void bhEne08_MV01(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	float dy;  
    ATR_WORK* hp;
	NJS_VECTOR vec;
    
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 1;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;

        epw->ct0 = (int)(60.0f * njRandom()) + 90;
        epw->spd = 0.2f + 0.2f * njRandom();
        epw->ayp = epw->ay + bhRandomAngle(10);
        epw->yn  = epw->py + 6.0f * njRandom() - 3.0f;

        epw->mode3++;
        break;

    case 1:
        if (epw->frm_no == 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 8;
            epw->hokan_rate = 45875;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
    }
    bhAddSpeed(epw, 0);

    epw->spd *= 0.96f;
    if (epw->spd < 0.01f)
    {
        epw->spd = 0.01f;
    }

    epw->ay += (short)(epw->ayp - epw->ay) / 8;

    dy = (epw->yn - epw->py) / 100.0f; 
    epw->py += dy;
    
    epw->axp = njArcTan2(dy, 0.1f);

    epw->ax += (short)(epw->axp - epw->ax) / 16;

    pos.x = epw->px - njSin(epw->ayp) * 20.0f;
    pos.y = epw->py;
    pos.z = epw->pz - njCos(epw->ayp) * 20.0f;

    hp = bhCheckWallType(&pos, 0, 5.0f, 1.0f);
    if (hp != NULL)
    {
        epw->ayp += epw->ct1 * 91;
    }

    pos.x = epw->px - njSin(epw->ayp) * 7.0f;
    pos.y = epw->py;
    pos.z = epw->pz - njCos(epw->ayp) * 7.0f;

    if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos) != NULL)
    {
        bhGetHitCollisionNormal(&vec);
        njUnitVector(&vec);
    
        njUnitMatrix(NULL);
        njRotateY(NULL, -epw->ay);
        njCalcVector(NULL, &vec, &vec);

        if (vec.x < 0.0f)
        {
            epw->ct1 = 1;
        }
        else 
        {
            epw->ct1 = -1;
        }

        epw->ayp = njArcSin(vec.z);
        
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching! 
void bhEne08_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ayp = epw->ay + (epw->ct1 * (epw->ayp + (3640.0f * (-rand() / -2.1474836e9f))));
        if (epw->ct1 > 0)
        {
          epw->mtn_no = 3;
        }
        else
        {
          epw->mtn_no = 2;
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        
        epw->ct0 = 30;
        epw->spd = 0.1f;
        
        epw->mode3++;

    case 1:
        bhAddSpeed(epw, 0);
        epw->spd *= 0.96f;
        
        if (epw->spd < 0.01f)
        {
            epw->spd = 0.01f;
        }
        
        if (epw->ct0-- == 0)
        {
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        break;
    }
    
    epw->ax -= (short) epw->ax / 8;    
    epw->ay += (short)(epw->ayp - epw->ay) / 12;
}

// 100% matching! 
void bhEne08_Nage(void)
{

}

// 100% matching! 
void bhEne08_Damage(void)
{

}

// 100% matching! 
void bhEne08_Die(void)
{

}
