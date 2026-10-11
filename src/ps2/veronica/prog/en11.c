#include "../../../ps2/veronica/prog/en11.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"

// ENEMY: Spotter 

#pragma divbyzerocheck on

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*BrainType_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne11_Mode0[6] =
{
    bhEne11_Init,
    bhEne11_Move,
    bhEne11_Nage,
    bhEne11_Damage,
    bhEne11_Die,
    bhEne_Event
};

BrainType_proc bhEne11_BrainType[1] =
{
    bhEne11_BR00
};

MoveMode2_proc bhEne11_MoveMode2[10] =
{
    bhEne11_MV00,
    bhEne11_MV01,
    bhEne11_MV02,
    bhEne11_MV03,
    bhEne11_MV04,
    bhEne11_MV05,
    bhEne11_MV06,
    bhEne11_MV07,
    bhEne11_MV08,
    bhEne11_MV09,
};

// 100% matching!
void bhEne11(BH_PWORK* epw)
{
    unsigned int flg;
    NJS_VECTOR v;
    int ang;

    bhEne11_Mode0[epw->mode0](epw);
    
    if (epw->mnwP != epw->mnwPb)
    {
        epw->az = 0;
        epw->ay = 0;
        epw->ax = 0;
        
        flg = epw->flg;
        epw->flg &= ~0x1000;
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        bhCalcModel(epw);
        
        epw->flg = flg;
        epw->flg |= 0x80000;
        return;
    }
    
    if (epw->flg & 0x80000) 
    {
        epw->mtn_no = 0;
        epw->mtn_add = 0;
        epw->frm_no = 0;
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->flg &= ~0x80000;
        
        switch (epw->type)
        {
            case 0:
                ang = bhArcTan2(-EXP0_F(0x28), -EXP0_F(0x20));
                
                v.x = 8.0f * njCos(ang);
                v.z = 8.0f * njSin(ang);
                v.y = -fabsf(plp->py - epw->py);
                break;
            
            case 1:
                v.x = 0.0f;
                v.z = 16.0f;
                v.y = -fabsf(plp->py - epw->py);
                break;
            
            case 3:
                v.x = 0.0f;
                v.z = -16.0f;
                v.y = -fabsf(plp->py - epw->py);
                break;
            
            case 2:
                v.x = 16.0f;
                v.z = 0.0f;
                v.y = -fabsf(plp->py - epw->py);
                break;
            
            case 4:
                v.x = -16.0f;
                v.z = 0.0f;
                v.y = -fabsf(plp->py - epw->py);
                break;
        }
        
        bhEne11_CameraSet(epw, &v, 0);
    }
    
    bhEne11_CollisionWalls(epw);
    njUnitMatrix(epw->mtx);
    njTranslate(epw->mtx, epw->px, epw->py, epw->pz);
    njMultiMatrix(epw->mtx, (NJS_MATRIX *)&EXP0_F(0x0));
    bhCalcModel(epw);
}

// 100% matching!
void bhEne11_Init(BH_PWORK* epw)
{
    int eff_id;

    sys->rm_flg &= ~1;
    epw->flg |= 0x1848;
    epw->flg &= ~6;
    epw->ar = 3.5f;
    epw->ah = 1.5f;
    epw->car = 1.0f;
    epw->cah = 1.0f;
    epw->spd = 0.2f;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x70, 8);
    }
    
    njUnitMatrix((NJS_MATRIX *)&EXP0_F(0x0));
    
    if (epw->type == 0)
    {
        njRotateY((NJS_MATRIX *)&EXP0_F(0x0), epw->ay);
        njRotateZ((NJS_MATRIX *)&EXP0_F(0x0), 0x8000);
    }
    else 
    {
        njRotateY((NJS_MATRIX *)&EXP0_F(0x0), (epw->type - 1) << 0xE);
        njRotateX((NJS_MATRIX *)&EXP0_F(0x0), 0x4000);
        njRotateY((NJS_MATRIX *)&EXP0_F(0x0), epw->ay);
    }
    
    EXP0_UC(0x56) = 0;
    
    if (*(O_WRK **)(epw->exp0 + 0x60) == NULL)
    {
        sys->ef.id = 0x105;
        sys->ef.flg = 1;
        sys->ef.type = 0;
        sys->ef.mdlver = 0;
        sys->ef.px = 0.0f;
        sys->ef.py = 0.0f;
        sys->ef.pz = 0.0f;
        sys->ef.sx = 0.0f;
        sys->ef.sy = 0.0f;
        sys->ef.sz = 0.0f;
        sys->ef.ay = 0;
        
        eff_id = bhSetEffectTb(&sys->ef, NULL, (unsigned char *)epw, 0);
        
        if (eff_id >= 0)
        {
            *(O_WRK **)(epw->exp0 + 0x60) = &eff[eff_id];
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 0;
            
        }
    }
    else 
    {
        (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 0;
        (*(O_WRK **)(epw->exp0 + 0x60))->ct2 = 0;
    }
    
    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 4;
    epw->clp_jno[2] = -1;
    
    bhEne11_MoveNearWall(epw);
    
    epw->flg |= 0x80000;
}

// 100% matching!
void bhEne11_Brain(BH_PWORK* epw)
{
    bhEne11_BrainType[0](epw);
}

// 100% matching!
void bhEne11_BR00(BH_PWORK* epw)
{
    if ((*(O_WRK **)(epw->exp0 + 0x60))->ct2 != 0)
    {
        EXP0_UC(0x56) = 1;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        if (!(sys->st_flg & 0x2000))
        {
            sys->rm_flg |= 1;
        }
    } 
    else if ((sys->rm_flg & 1) && ((*(O_WRK **)(epw->exp0 + 0x60))->mode0 == 2)) 
    {
        EXP0_UC(0x56) = 1;
        (*(O_WRK **)(epw->exp0 + 0x60))->ct2 = 1;
    }
}

// 100% matching!
void bhEne11_Move(BH_PWORK* epw) 
{
    if (epw->mode1 == 1) 
    {
        bhEne11_Brain(epw);
    }
    
    bhEne11_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne11_MV00(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x1E;
            epw->mode3++;
        case 1:
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                }
                else
                {
                    epw->mode2 = 6;
                }
            }
            break;
    }
}

// 100% matching!
void bhEne11_MV01(BH_PWORK* epw)
{
    NJS_VECTOR v;
    int ang;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = 0;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            
            epw->ay = bhArcTan2(-EXP0_F(0x28), -EXP0_F(0x20));
            
            epw->mode3++;
        case 1:
            ang = epw->ay + (epw->ct2 * 0x28F);
            
            v.x = 8.0f * njCos(ang);
            v.z = 8.0f * njSin(ang);
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                }
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            break;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->mode3 += 1;
            epw->spd = 0.2f;
        case 1:
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                }
                else 
                {
                    epw->mode2 = 6;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else
            {
                bhEne_SetSEPan(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            break;
    }
}

// 100% matching!
void bhEne11_MV03(BH_PWORK* epw) 
{
    NJS_VECTOR v;

    switch (epw->mode3)
    {
        case 0:
            switch (EXP0_I(0x5C))
            {
                case 0:
                    epw->way = 0;
                    epw->ct0 = 0;
                    break;
                
                case 1:
                    epw->way = -0x222;
                    epw->ct0 = 0x1D;
                    bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x12301);
                    break;
                
                case 2:
                    epw->way = 0x38E;
                    epw->ct0 = 0x23;
                    bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x12301);
                    break;
                
                case 3:
                    epw->way = 0x222;
                    epw->ct0 = 0x1D;
                    bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x12301);
                    break;
            }
            
            epw->ct1 = 0x10;
            epw->mode3++;
        case 1:
            njRotateY((NJS_MATRIX *)&EXP0_F(0x0), epw->way);
            
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                }
                else 
                {
                    epw->mode2 = 6;
                }
            }
            
            if (epw->type != 0)
            {
                switch ((unsigned short)epw->type)
                {
                    case 1:
                        v.x = 0;
                        v.z = 16.0f;
                        break;
                    
                    case 3:
                        v.x = 0;
                        v.z = -16.0f;
                        break;
                    
                    case 2:
                        v.x = 16.0f;
                        v.z = 0;
                        break;
                    
                    case 4:
                        v.x = -16.0f;
                        v.z = 0;
                }
                
                v.y = -fabsf(plp->py - epw->py);
                
                bhEne11_CameraSet(epw, &v, epw->ct1);
                
                if (epw->ct1 != 0)
                {
                    epw->ct1--;
                }
            }
            break;
    }
}

// 100% matching!
void bhEne11_MV04(BH_PWORK* epw) 
{
    NJS_VECTOR v;
    float f;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = EXP0_I(0x5C) * 0x19;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
        case 1:
            f = 16.0f + (16.0f * njSin(epw->ct2 * 0x28F));
            
            v.x = -EXP0_F(0x20) * f;
            v.z = -EXP0_F(0x28) * f;
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                }
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            break;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV05(BH_PWORK* epw) 
{
    NJS_VECTOR v;
    float f;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 0x19;
            epw->ct2 = 0;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
        case 1:
            f = 16.0f + (16.0f * njSin(epw->ct2 * 0x28F));
            
            v.x = EXP0_F(0x10) * f;
            v.z = EXP0_F(0x18) * f;
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            break;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV06(BH_PWORK* epw) 
{
	NJS_VECTOR v;
    int ang;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = 0x19;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
        case 1:
            ang = (int)(16384.0f + (16384.0f * njCos(epw->ct2 * 0x28F)));
            
            switch (epw->type)
            {
                case 1:
                    v.x = 16.0f * njCos(ang);
                    v.z = 16.0f * njSin(ang);
                    break;
                
                case 3:
                    v.x = 16.0f * njCos(ang);
                    v.z = -16.0f * njSin(ang);
                    break;
                
                case 2:
                    v.x = 16.0f * njSin(ang);
                    v.z = 16.0f * njCos(ang);
                    break;
                
                case 4:
                    v.x = -16.0f * njSin(ang);
                    v.z = 16.0f * njCos(ang);
                    break;
            }
            
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            break;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV07(BH_PWORK* epw)
{
    switch(epw->mode3)
    {
        case 0:
            bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x2302);
            epw->mode3++;
            break;
    }
}

// 100% matching!
void bhEne11_MV08(BH_PWORK* epw) 
{
    switch(epw->mode3)
    {
        case 0:
            epw->mode1 = 0;
            bhEne11_LightControl(epw, 1);
            epw->mode3++;
            break;
    }
}

// 100% matching!
void bhEne11_MV09(BH_PWORK* epw)
{
    O_WORK* owk;

    owk = &epw->mlwP->owP[1];
    njSetMatrix((NJS_MATRIX *)&EXP0_F(0x0), (NJS_MATRIX *)owk->mtx);
    
    EXP0_I(0x30) = 0;
    EXP0_I(0x34) = 0;
    EXP0_I(0x38) = 0;
    
    owk = epw->mlwP->owP;
    
    epw->px = owk->mtx[0xC] + (3.0f * EXP0_F(0x10));
    epw->py = owk->mtx[0xD] + (3.0f * EXP0_F(0x14));
    epw->pz = owk->mtx[0xE] + (3.0f * EXP0_F(0x18));
    
    owk = &epw->mlwP->owP[2];
    owk->flg |= 2;
    
    owk = &epw->mlwP->owP[3];
    owk->flg |= 2;
    
    epw->mnwP = epw->mnwPb;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    owk = &epw->mlwP->owP[2];
    owk->flg &= ~2;
    
    owk = &epw->mlwP->owP[3];
    owk->flg &= ~2;
    
    bhEne11_MoveNearWall(epw);
    
    if (epw->type == 0) 
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 4;
        epw->mode3 = 1;
        epw->ct0 = 0x96;
        epw->ct1 = 0x20;
        epw->ct2 = 0;
    } 
    else 
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 6;
        epw->mode3 = 1;
        epw->ct0 = 0x96;
        epw->ct1 = 0x20;
        epw->ct2 = 0;
    }
    
    epw->flg &= ~0x80000;
    epw->spd = 0.2f;
    
    bhEne11_GoFoward(epw);
}

// 100% matching!
void bhEne11_Nage() 
{

}

// 100% matching!
void bhEne11_Damage()
{

}

// 100% matching!
void bhEne11_Die() 
{

}

// 100% matching!
void bhEne11_GoFoward(BH_PWORK* epw) 
{
    epw->px -= EXP0_F(0x20) * epw->spd;
    epw->py -= EXP0_F(0x24) * epw->spd;
    epw->pz -= EXP0_F(0x28) * epw->spd;
}

// 100% matching!
void bhEne11_CollisionWalls(BH_PWORK* epw) 
{
	NJS_VECTOR body = { 0.0f, 3.5f, 0.0f };
    NJS_VECTOR vd;

    njCalcVector((NJS_MATRIX *)&EXP0_F(0x0), &body, &vd);
    
    epw->px += vd.x;
    epw->py += vd.y;
    epw->pz += vd.z;
    
    bhEne03_Collision(epw);
    
    if (EXP0_I(0x58) != 0) 
    {
        bhEne11_CollisionBoxEdge2(epw);
    }
    
    epw->px -= vd.x;
    epw->py -= vd.y;
    epw->pz -= vd.z;
}

// 100% matching!
void bhEne11_CollisionBoxEdge2(BH_PWORK* epw)
{
	NJS_POINT3 v;
    NJS_POINT3 p[4];
    NJS_POINT3 p2[4];
    float ar;
    int i;

    ar = 1.0f + epw->ar;
        
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    
    njCalcVector((NJS_MATRIX *)&EXP0_F(0x0), &v, &v);
    
    switch (bhEne03_GetWallDir(&v)) 
    {
        case 0:
            p[0].x = epw->px - ar;
            p[0].z = epw->pz - ar;
            
            p[1].x = epw->px - ar;
            p[1].z = epw->pz + ar;
            
            p[2].x = epw->px + ar;
            p[2].z = epw->pz - ar;
            
            p[3].x = epw->px + ar;
            p[3].z = epw->pz + ar;
            
            p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
            
            v.x = 0.0f;
            v.y = -ar;
            v.z = 0.0f;
            break;
        
        case 1:
            p[0].x = epw->px - ar;
            p[0].z = epw->pz - ar;
        
            p[1].x = epw->px - ar;
            p[1].z = epw->pz + ar;
        
            p[2].x = epw->px + ar;
            p[2].z = epw->pz - ar;
        
            p[3].x = epw->px + ar;
            p[3].z = epw->pz + ar;
        
            p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
        
            v.x = 0.0f;
            v.y = ar;
            v.z = 0.0f;
            break;
            
        case 4:
            p[0].y = epw->py - ar;
            p[0].z = epw->pz - ar;
        
            p[1].y = epw->py - ar;
            p[1].z = epw->pz + ar;
        
            p[2].y = epw->py + ar;
            p[2].z = epw->pz - ar;
        
            p[3].y = epw->py + ar;
            p[3].z = epw->pz + ar;
        
            p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
        
            v.x = ar;
            v.y = 0.0f;
            v.z = 0.0f;
            break;
        
        case 2:
            p[0].y = epw->py - ar;
            p[0].z = epw->pz - ar;
        
            p[1].y = epw->py - ar;
            p[1].z = epw->pz + ar;
        
            p[2].y = epw->py + ar;
            p[2].z = epw->pz - ar;
        
            p[3].y = epw->py + ar;
            p[3].z = epw->pz + ar;
        
            p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
        
            v.x = -ar;
            v.y = 0.0f;
            v.z = 0.0f;
            break;
            
        case 3:
            p[0].x = epw->px - ar;
            p[0].y = epw->py - ar;
        
            p[1].x = epw->px - ar;
            p[1].y = epw->py + ar;
        
            p[2].x = epw->px + ar;
            p[2].y = epw->py - ar;
        
            p[3].x = epw->px + ar;
            p[3].y = epw->py + ar;
        
            p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
        
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = ar;
            break;
            
        case 5:
            p[0].x = epw->px - ar;
            p[0].y = epw->py - ar;
        
            p[1].x = epw->px - ar;
            p[1].y = epw->py + ar;
        
            p[2].x = epw->px + ar;
            p[2].y = epw->py - ar;
        
            p[3].x = epw->px + ar;
            p[3].y = epw->py + ar;
        
            p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
        
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = -ar;
            break;
            
    }

    for (i = 0; i < 4; i++)
    {
        p2[i].x = v.x + p[i].x;
        p2[i].y = v.y + p[i].y;
        p2[i].z = v.z + p[i].z;

        if (bhCollisionCheckLine(&p[i], &p2[i]) == NULL)
        {
            *(ATR_WORK **)(epw->exp0 + 0x58) = bhEne03_GetWall(epw);

            if (*(ATR_WORK **)(epw->exp0 + 0x58) != NULL)
            {
                bhEne03_CollisionBoxEdge(*(ATR_WORK **)(epw->exp0 + 0x58), (NJS_VECTOR *)&epw->px, epw->ar);
                break;
            }
        }
    }
}

// 100% matching!
void bhEne11_CameraSet(BH_PWORK* epw, NJS_VECTOR* vec, int hcnt)
{
	NJS_CNK_OBJECT *objP;
    NJS_VECTOR v;
    NJS_VECTOR vb;
    NJS_VECTOR ov;
    float out;
    int ang;
    int ax;
    int ay;

    njSetMatrix(NULL, (NJS_MATRIX *)&EXP0_F(0x0));
    njInvertMatrix(NULL);
    
    njCalcVector(NULL, vec, &v);
    
    njUnitVector(&v);
    
    if (hcnt != 0) 
    {
        objP = &epw->mlwP->objP[2];
        
        vb.x = 0;
        vb.y = 0;
        vb.z = -1.0f;
        
        njUnitMatrix(NULL);
        
        njRotateEx(objP[0].ang, 0);
        njRotateEx(objP[1].ang, 0);
        
        njCalcVector(NULL, &vb, &vb);
        
        out = njOuterProduct(&vb, &v, &ov);
        
        njUnitVector(&ov);
        
        ang = (int)(10430.381f * asinf(out)) / hcnt;
        
        njUnitMatrix(NULL);
        njRotate(NULL, &ov, ang);
        njCalcVector(NULL, &vb, &v);
    }
    
    ax = bhArcTan2(-v.x, -v.z);
    ay = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));
    
    if (ay < 0) 
    {
        ay = 0;
    }
    
    objP = epw->mlwP->objP;
    objP[2].ang[1] = ax;
    objP[3].ang[0] = ay;
}

// 100% matching!
void bhEne11_MoveNearWall(BH_PWORK* epw) 
{
	NJS_VECTOR vec;
    NJS_VECTOR vd;
    NJS_VECTOR pt;

    vec.x = 0;
    vec.y = -999.0f;
    vec.z = 0;
    
    njSetMatrix(NULL, (NJS_MATRIX *)&EXP0_F(0x0));
    njCalcVector(NULL, &vec, &vd);
    
    pt.x = epw->px + vd.x;
    pt.y = epw->py + vd.y;
    pt.z = epw->pz + vd.z;
    
    *(ATR_WORK **)(epw->exp0 + 0x58) = bhCollisionCheckLine((NJS_VECTOR *)&epw->px, &pt);
    
    if (*(ATR_WORK **)(epw->exp0 + 0x58) != NULL)
    {
        epw->px = epw->pxb = pt.x;
        epw->py = epw->pyb = pt.y;
        epw->pz = epw->pzb = pt.z;
    }
}

// 100% matching!
void bhEne11_LightControl(BH_PWORK* epw, int flg)
{
    switch (flg) 
    {                          
        case 0:
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 1;
            (*(O_WRK **)(epw->exp0 + 0x60))->axp = 0x38E;
            break;
            
        case 1:
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 3;
            break;
            
        case 2:
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 0;
            break;
            
        case 3:
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 2;
            (*(O_WRK **)(epw->exp0 + 0x60))->ax = 0x38E;
            (*(O_WRK **)(epw->exp0 + 0x60))->axp = 0x38E;
            break;
    }
}

// 100% matching!
int bhEne11_SelectDir(BH_PWORK* epw) 
{
	NJS_POINT3 p1;
    NJS_POINT3 p2;
    NJS_POINT3 p3;
    int i;
    int dir;
    int flg[4];
    float h;
    NJS_POINT3 pos;
    unsigned char ang;

    flg[3] = 0;
    flg[2] = 0;
    flg[1] = 0;
    flg[0] = 0;
    
    p1.x = epw->px + EXP0_F(0x10);
    p1.y = epw->py + EXP0_F(0x14);
    p1.z = epw->pz + EXP0_F(0x18);
    
    p2.x = p1.x - (20.0f * EXP0_F(0x20));
    p2.y = p1.y - (20.0f * EXP0_F(0x24));
    p2.z = p1.z - (20.0f * EXP0_F(0x28));
    
    if (bhCollisionCheckLine(&p1, &p2) == NULL)
    {
        p3.x = p2.x - (2.0f * EXP0_F(0x10));
        p3.y = p2.y - (2.0f * EXP0_F(0x14));
        p3.z = p2.z - (2.0f * EXP0_F(0x18));
        
        if ((bhCollisionCheckLine(&p2, &p3) != NULL) && ((p2.y - bhGetGroundPosition(&p2)) > 10.0f)) 
        {
            flg[0] = 1;
        }
    }
    
    p2.x = p1.x + (20.0f * EXP0_F(0x0));
    p2.y = p1.y + (20.0f * EXP0_F(0x4));
    p2.z = p1.z + (20.0f * EXP0_F(0x8));
    
    if (bhCollisionCheckLine(&p1, &p2) == NULL) 
    {
        p3.x = p2.x - (2.0f * EXP0_F(0x10));
        p3.y = p2.y - (2.0f * EXP0_F(0x14));
        p3.z = p2.z - (2.0f * EXP0_F(0x18));
        
        if ((bhCollisionCheckLine(&p2, &p3) != NULL) && ((p2.y - bhGetGroundPosition(&p2)) > 10.0f))
        {
            flg[1] = 1;
        }
    }
    
    p2.x = p1.x + (20.0f * EXP0_F(0x20));
    p2.y = p1.y + (20.0f * EXP0_F(0x24));
    p2.z = p1.z + (20.0f * EXP0_F(0x28));
    
    if (bhCollisionCheckLine(&p1, &p2) == NULL) 
    {
        p3.x = p2.x - (2.0f * EXP0_F(0x10));
        p3.y = p2.y - (2.0f * EXP0_F(0x14));
        p3.z = p2.z - (2.0f * EXP0_F(0x18));
        
        if ((bhCollisionCheckLine(&p2, &p3) != NULL) && ((p2.y - bhGetGroundPosition(&p2)) > 10.0f)) 
        {
            flg[2] = 1;
        }
    }
    
    p2.x = p1.x - (20.0f * EXP0_F(0x0));
    p2.y = p1.y - (20.0f * EXP0_F(0x4));
    p2.z = p1.z - (20.0f * EXP0_F(0x8));
    
    if (bhCollisionCheckLine(&p1, &p2) == NULL)
    {
        p3.x = p2.x - (2.0f * EXP0_F(0x10));
        p3.y = p2.y - (2.0f * EXP0_F(0x14));
        p3.z = p2.z - (2.0f * EXP0_F(0x18));
        
        if ((bhCollisionCheckLine(&p2, &p3) != NULL) && ((p2.y - bhGetGroundPosition(&p2)) > 10.0f)) 
        {
            flg[3] = 1;
        }
    }
    
    if ((epw->type == 0) && (njRandom() > 0.5)) 
    {
        njSetMatrix(NULL, (NJS_MATRIX *)&EXP0_F(0x0));
        njInvertMatrix(NULL);
        njCalcPoint(NULL, (NJS_VECTOR *)&plp->px, &pos);
        
        dir = dir = (int)((bhArcTan2(-pos.x, -pos.z) & 0xFF) + 0x2000) / 0x4000;
    }
    else 
    {
        dir = (int)(4.0f * njRandom());
    }
    
    for (i = 0; i < 4; i++)
    {
        if (flg[dir] != 0)
        {
            break;
        }
        dir = (dir + 1) & 3;
    }
    
    return dir;
}