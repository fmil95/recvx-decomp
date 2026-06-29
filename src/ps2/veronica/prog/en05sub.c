#include "../../../ps2/veronica/prog/en05sub.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchkl.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne05s_Mode0[2] =
{
    bhEne05s_Init,
    bhEne05s_Move,
};

MoveMode2_proc bhEne05s_MoveMode2[3] =
{
    bhEne05s_MV00,
    bhEne05s_MV01,
    bhEne05s_MV02
};

// 100% matching!
void bhEne05s(BH_PWORK* epw) 
{
    NJS_POINT3 v;

    bhEne05s_Mode0[epw->mode0](epw);
    bhEne05s_FloorCollision(epw);
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    njCalcVector(epw->mtx, &v, &v);
    epw->px += v.x;
    epw->py += v.y;
    epw->pz += v.z;
    bhEne03_Collision(epw);
    epw->px -= v.x;
    epw->py -= v.y;
    epw->pz -= v.z;
}

// 100% matching!
void bhEne05s_Init(BH_PWORK* epw) 
{
    epw->ar = 1.0f;
    epw->ah = 1.0f;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x60, 8);
    }
}


// 100% matching!
void bhEne05s_Move(BH_PWORK* epw)
{
    bhEne05s_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne05s_MV00()
{

}

// 99.95% matching!
void bhEne05s_MV01(BH_PWORK* epw) 
{
	int ang;
    BH_PWORK* ep;
    NJS_VECTOR vec;

    switch (epw->mode3)
    {
        case 0:
            epw->px = epw->pxb = epw->mtx[0][0xC];
            epw->py = epw->pyb = epw->mtx[0][0xD];
            epw->pz = epw->pzb = epw->mtx[0][0xE];
            
            ep = (BH_PWORK*)epw->lkwkp;
            ang = (int)((ep->ay + (3640.0f * (-rand() / -2.1474836e9f))) - 1820.0f);

            EXP0_F(0x44) = -1.2f * njSin(ang);
            EXP0_F(0x4C) = -1.2f * njCos(ang);
            EXP0_F(0x48) = 1.0f;
            EXP0_US(0x40) |= 1;
            
            epw->ct0 = 3;
            epw->ct1 = 0;
            epw->mode3 += 1;
        
            /* fallthrough */
        case 1:
            if (EXP0_US(0x40) & 1)
            {
                EXP0_F(0x48) -= 0.3f;
                
                epw->px += EXP0_F(0x44);
                epw->py += EXP0_F(0x48);
                epw->pz += EXP0_F(0x4C);
                
                njRotateY(epw->mtx, 0x4FA);
                njRotateZ(epw->mtx, 0xC16);
            }
            else if (epw->ct0 != 0) 
            {
                epw->px += EXP0_F(0x44);
                epw->py += EXP0_F(0x48);
                epw->pz += EXP0_F(0x4C);
                
                EXP0_US(0x40) |= 1;
                
                epw->ct0 -= 1;
            }
            else 
            {
                epw->mode3 += 1;
            }
            
            epw->mtx[0][0xC] = epw->px;
            epw->mtx[0][0xD] = epw->py;
            epw->mtx[0][0xE] = epw->pz;
        
            /* fallthrough */
        case 2:
            if (epw->ct1-- == 0)
            {
                if (epw->ct0 != 0)
                {
                    epw->ct1 = (int)(2.0f * (-rand() / -2.1474836e9f));
                }
                else 
                {
                    epw->ct1 = (int)(5.0f * (-rand() / -2.1474836e9f));
                }
                
                vec.x = -epw->mtx[0][4];
                vec.y = -epw->mtx[0][5];
                vec.z = -epw->mtx[0][6];
                
                bhEne_SetBloodEffect4((NJS_VECTOR* ) &epw->px, (NJS_VECTOR* ) &vec, 0, 9, 2);
            }
    }
}

// 100% matching!
void bhEne05s_MV02(BH_PWORK* epw)
{
	O_WORK* owk;
    NJS_VECTOR pos;
    NJS_VECTOR vec;

    owk = &((BH_PWORK*)epw->lkwkp)->mlwP->owP[epw->ct3];
    
    switch (epw->mode3)
    {
        case 0:
            njUnitMatrix((NJS_MATRIX *) epw->exp0);
            njRotateX((NJS_MATRIX *) epw->exp0, -0x4000);
            epw->ct0 = (int)(25.0f * (-rand() / -2.1474836e9f)) + 0x19;
            epw->ct1 = (int)(15.0f * (-rand() / -2.1474836e9f)) + 5;
            epw->mode3 += 1;
        
            /* fallthrough */
        case 1:
            njSetMatrix(NULL, &owk->mtx);
            njMultiMatrix(NULL, (NJS_MATRIX *) epw->exp0);
            njGetMatrix(epw->mtx);
            
            pos.x = 2.0f;
            pos.y = -1.0f;
            pos.z = 1.0f;
            
            njCalcPoint(&owk->mtx, (NJS_VECTOR* ) &pos, (NJS_VECTOR* ) &pos);
            
            epw->mtx[0][0xC] = pos.x;
            epw->mtx[0][0xD] = pos.y;
            epw->mtx[0][0xE] = pos.z;
            
            if (epw->ct1-- == 0) 
            {
                epw->ct1 = (int)(15.0f * (-rand() / -2.1474836e9f)) + 5;
                
                vec.x = -owk->mtx[4];
                vec.y = -owk->mtx[5];
                vec.z = -owk->mtx[6];
                
                bhEne_SetBloodEffect4((NJS_VECTOR* ) &pos, (NJS_VECTOR* ) &vec, 0, 0, 2);
            }
            
            return;
    }
}

// 100% matching!
void bhEne05s_FloorCollision(BH_PWORK* epw)
{
    ATR_WORK *hp;

    if ((EXP0_US(0x40) & 1) && (bhCollisionCheckLine((NJS_VECTOR* ) &epw->pxb, (NJS_VECTOR* ) &epw->px) != NULL)) 
    {
        bhGetHitCollisionNormal((NJS_VECTOR* ) (epw->exp0 + 0x50));
        njUnitVector((NJS_VECTOR* ) (epw->exp0 + 0x50));
        
        if (!(EXP0_F(0x54) <= 0.9f))
        {
            EXP0_US(0x40) &= 0xFFFE;
            
            if (!(EXP0_F(0x54) <= 0.9f)) 
            {
                EXP0_F(0x48) *= -0.5f;
            }
        }
        
        if (EXP0_F(0x54) < 0.9f) 
        {
            EXP0_F(0x48) = 0.0f;
        }
            
        if (fabsf(EXP0_F(0x54)) <= 0.5f) 
        {
            if (!(fabsf(EXP0_F(0x50)) <= 0.5f)) 
            {
                EXP0_F(0x44) *= -0.3f;
            }
            
            if (!(fabsf(EXP0_F(0x58)) <= 0.5f)) 
            {
                EXP0_F(0x4C) *= -0.3f;
            }
        }
    }
}

