#include "../../../ps2/veronica/prog/en10.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/subpl.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne10_Mode0[6] =
{
    bhEne10_Init,
    bhEne10_Move,
    bhEne10_Nage,
    bhEne10_Damage,
    bhEne10_Die,
    bhEne_Event
};

MoveMode2_proc bhEne10_MoveMode2[3] =
{
    bhEne10_MV00,
    bhEne10_MV01,
    bhEne10_MV02
};

// 100% matching!
void bhEne10(BH_PWORK* epw) 
{
	O_WORK *owk;
    int i;

    bhEne10_Mode0[epw->mode0](epw);
    
    EXP0_UC(0x0)++;
    
    if (EXP0_UC(0x0) > 2)
    {
        EXP0_UC(0x0) = 0;
        
        EXP0_UC(0x1) += 1;
        
        if (EXP0_UC(0x1) > 3)
        {
            EXP0_UC(0x1) = 0;
        }
    }
    
    epw->mlwP = &epw->mdl[EXP0_UC(0x1)];
    
    if (epw->flg & 4) 
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        
        epw->flg &= ~4;
    }
    
    if (epw->flg & 8) 
    {
        bhCheckWall(epw);
        bhCheckPlayer(epw);
    }
    
    bhCalcModel(epw);
    
    owk = &epw->mlwP->owP[1];
    
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13] + 0.2;
    epw->watr.c1.z = owk->mtx[14];

    owk = &epw->mlwP->owP[1];
    
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    epw->watr.r = 0.8f;
    
    if (EXP0_UC(0x20) != 0)
    {
        EXP0_UC(0x20)--;
    }
    
    bhEne10_CheckPos(epw);
}

// 100% matching!
void bhEne10_Init(BH_PWORK* epw) 
{
    int ang;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0x24, 8);
    }
    
    epw->flg |= 0x138;
    epw->flg2 &= ~1;
    epw->flg &= 0xFFFF7FF9;
    epw->mdflg &= ~1;
    epw->ar = 1.0f;
    epw->ah = 1.0f;
    epw->car = 1.0f;
    epw->cah = 1.0f;
    epw->hp = 1;
    
    EXP0_F(0x8) = epw->px;
    EXP0_F(0xC) = epw->py;
    EXP0_F(0x10) = epw->pz;
    
    epw->spd = 0.14f;
    
    EXP0_F(0x18) = 999.0f;
    EXP0_F(0x1C) = 0;
    EXP0_C(0x20) = 0;
    EXP0_C(0x21) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;
    epw->mode3 = 0;
    
    ang = rand() % 5 * 1.5 * 182.04444885253906;

    ang = ((rand() % 2) != 0) ? ang : -ang;
    
    EXP0_I(0x4) = ang;
    
    epw->clp_jno[0] = 0;
    epw->clp_jno[1] = -1;
    epw->mdflg &= ~0x20;
}

// 100% matching!
void bhEne10_CheckPos(BH_PWORK* epw)
{
	float dx, dz;
    int ang;

    dx = epw->px - EXP0_F(0x8);
    dz = epw->pz - EXP0_F(0x10);
    
    EXP0_F(0x14) = njSqrt(dx * dx + dz * dz);
    
    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    
    EXP0_F(0x18) = njSqrt(dx * dx + dz * dz);
    EXP0_I(0x1C) = (short)(njArcTan2(dx, dz) - epw->ay);
}

// 100% matching!
void bhEne10_Brain(BH_PWORK* epw) 
{
    if (!(plp->stflg & 0x80000000)) 
    {
        if (!(plp->flg & 4) && !(plp->flg & 2) && !(epw->flg & 4)) 
        {
            if ((EXP0_UC(0x20) == 0) && (EXP0_F(0x18) < 3.0f) && (abs(EXP0_I(0x1C)) < 0xE38)) 
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                bhEne10_Nage(epw);
                return;
            }
        }
    }
    
    if (!(EXP0_F(0x14) <= 10.0f) && (epw->mode2 != 2)) 
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->spd = 0.042000003f;
    }
}

// 100% matching!
void bhEne10_Move(BH_PWORK* epw) 
{
    NJS_POINT3 pos;

    if (epw->mode1 == 1) 
    {
        bhEne10_Brain(epw);
    }
    
    if ((plp->mode0 == 1) && (njDistanceP2P((NJS_VECTOR* ) &epw->px, (NJS_VECTOR* ) &plp->px) < 1.5f)) 
    {
        switch (plp->mode2)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
                epw->flg |= 2;
                break;
        }
    }
    
    if (epw->flg & 4)
    {
        epw->flg |= 2;
    }
    
    if (epw->flg & 2)
    {
        bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x2303);
        
        pos.x = epw->px;
        pos.y = epw->py;
        pos.z = epw->pz;
        
        epw->dvx = 0.0f;
        epw->dvy = 1.0f;
        epw->dvz = 0.0f;
        
        bhEne_SetBloodEffect4((NJS_VECTOR* ) &pos, (NJS_VECTOR* ) &epw->dvx, 1, 1, 0);
        
        epw->mdflg |= 1;
        epw->mode0 = 4;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
        epw->hp = -1;
        
        return;
    }
    
    if (epw->mode0 == 1) 
    {
        bhEne10_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne10_MV00() 
{

}

// 100% matching!
void bhEne10_MV01(BH_PWORK* epw)
{
    int ang;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = (rand() % 10) + 0xA;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            epw->ay += EXP0_I(0x4);
            
            bhAddSpeed(epw, 0);
            
            if (epw->ct0 == 0x13) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12300);
            }
            
            if (epw->ct0-- == 0) 
            {
                ang = rand() % 5 * 1.5 * 182.04444885253906;

                ang = (rand() % 2) ? ang : -ang;
                
                EXP0_I(0x4) = ang;
                
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne10_MV02(BH_PWORK* epw) 
{
    int ay;

    switch (epw->mode3)
    {
        case 0:
            ay = bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), 0x5B0);
            epw->ay += ay;
                
            bhAddSpeed(epw, 0);
            
            if (abs((int)(0.005493164f * ay)) < 1.0f)
            {
                epw->mode3++;
                epw->spd = 0.14f;
            }
            
            break;
        
        case 1:
            
            epw->ay += bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), 0x38E);
            
            bhAddSpeed(epw, 0);
            
            if (epw->ct0 == 0x12) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12300);
            }

            
            if ((abs((int)(epw->px - EXP0_F(0x8))) < 1.0f) && (abs((int)(epw->pz - EXP0_F(0x10))) < 1.0f)) 
            {
                epw->mode3 += 1;
                
            }
            
            break;
        
        case 2:
            ay = (rand() % 5) * 182.04444885253906;
            
            ay = (rand() % 2) ? ay : -ay;
            
            EXP0_I(0x4) = ay;
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            epw->spd = 0.14f;
    }
}

// 100% matching!
void bhEne10_Nage(BH_PWORK* epw)
{
    int ay;

    switch (epw->mode3)
    {
        case 0:
            plp->flg |= 4;
            plp->hp--;
            
            if (plp->hp < 0) 
            {
                plp->hp = 0;
            }
            
            plp->mode0 = 2;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            epw->ct0 = 0xA;
            
            bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12302);
            StartVibrationEx(1, 0xA);
            
            sys->ef.id = 5;
            sys->ef.flg = 1;
            sys->ef.type = 0;
            sys->ef.mdlver = 0;
            sys->ef.px = epw->px - 0.5f;
            sys->ef.py = 0.3f + epw->py;
            sys->ef.pz = epw->pz - 0.5f;
            sys->ef.sx = 2.0f;
            sys->ef.sy = 2.0f;
            sys->ef.sz = 2.0f;
            sys->ef.ay = epw->ay;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->ct0-- == 0)
            {
                epw->ay = epw->ay + 0x7FFF + 1;
                
                EXP0_C(0x20) = 0x1E;
                
                ay = (rand() % 5) * 182.04445f;

                ay = (rand() % 2) ? ay : -ay;
            
                EXP0_I(0x4) = ay;
                
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
                epw->spd = 0.14f;
            }
    }
}

// 100% matching!
void bhEne10_Damage(void) 
{

}

// 100% matching!
void bhEne10_Die(void)
{

}
