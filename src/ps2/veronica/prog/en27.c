#include "../../../ps2/veronica/prog/en27.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef void (*bhEne27_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne27_BrainType_proc)(BH_PWORK* epw);
typedef void (*bhEne27_MoveMode2_proc)(BH_PWORK* epw);

bhEne27_Mode0_proc bhEne27_Mode0[6] = 
{
	bhEne27_Init,
	bhEne27_Move,
	bhEne27_Nage,
	bhEne27_Damage,
	bhEne27_Die,
	bhEne_Event
};     
bhEne27_BrainType_proc bhEne27_BrainType[1] = 
{
	bhEne27_BR00
}; 
bhEne27_MoveMode2_proc bhEne27_MoveMode2[3] = 
{
	bhEne27_MV00,
	bhEne27_MV01,
	bhEne27_MV02
}; 

// 100% matching!
void bhEne27(BH_PWORK* epw)
{
    bhEne27_Mode0[epw->mode0](epw);
    
    if (epw->mode2 > 1) 
    {
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        bhEne27_CallSE(epw); 
    }
}

// 99.94% matching
void bhEne27_Init(BH_PWORK* epw)
{
    ATR_WORK* fp;   
    int i;               
    int flr_n;         
    NJS_MKEY_F_MOD* mkfP; 
    
    epw->mnwP = (MN_WORK*)sys->plmthp;
    epw->mlwP = &plp->mdl[6];
    
    epw->mdl_no = 0;
    
    epw->skp[8] = plp->skp[7];
    
    epw->flg &= ~0x6;
    
    epw->mdflg |=  0x4;
    epw->mdflg &= ~0x1;
    
    if ((-rand() / -2.1474836E9f) < 0.3f) 
    {
        epw->ct2 = (unsigned int)(30.0f + (120.0f * (-rand() / -2.1474836E9f)));
    }
    else
    {
        epw->ct2 = 0;
    }
    
    epw->flg |= 0x80;
    
    epw->lkwkp = (unsigned char*)plp;
    epw->lkono = 3;
    
    if (epw->mode2 == 0) 
    {
        flr_n = rom->flr_n + sys->mflr_n;
        
        for (i = 0; i < flr_n; i++)
        {
            if (i < rom->flr_n)
            {
                fp = &rom->flrp[i];
            } 
            else
            {
                fp = &sys->mflrp[i - rom->flr_n];
            }
            
            if ((((fp->flg & 0x1)) && (fp->type == 2)) && (fp->prm0 == 27)) 
            {
                fp->prm2 = 0;
            }
        } 
    }
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->hokan_rate = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no = epw->type + 93;
    epw->mtn_md = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
    
    epw->lox = mkfP->key[0];
    epw->loy = mkfP->key[1];
    epw->loz = mkfP->key[2];
    
    epw->loz -= 0.3f;
    
    epw->ax = 5461;
    
    epw->clp_jno[0] =  0;
    epw->clp_jno[1] = -1;
    
    epw->mdflg &= ~0x20;
}

// 100% matching!
void bhEne27_Brain(BH_PWORK* epw)
{
	bhEne27_BrainType[0](epw);
}

// 100% matching!
void bhEne27_BR00(BH_PWORK* epw)
{
    ATR_WORK* hp;
    
    if ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x30))) 
    {
        hp = bhCheckFloorEnemy(plp->flr_no, plp->px, plp->pz);
        
        if ((hp != NULL) && ((hp->prm0 == 27) && (hp->prm2 == 0))) 
        {
            if ((hp->prm1 == 0) || (hp->prm1 == (epw->type + 1))) 
            {
                epw->mode2 = 1;
                epw->mode3 = 0;
                
                hp->prm2 = 1;
                return;
            }
        } 
        
        if (epw->ct2 > 0)
        {
            epw->ct2--;
            
            if (epw->ct2 == 0) 
            {
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne27_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1) 
    {
        bhEne27_Brain(epw);
    }
    
    bhEne27_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne27_MV00()
{

}

// 100% matching!
void bhEne27_MV01(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mlwP = &plp->mdl[7];
            
        epw->mdl_no = 8;
            
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
            
        bhEne27_IncubateEffect(epw);
            
        epw->lox = 0;
        epw->loy = 0;
        epw->loz = 0;
            
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
            
        plp->flg  |= 0x10004;
        plp->flg2 |= 0x1;
            
        plp->stflg |= 0x10000;
            
        plp->mode0 = 4;
        plp->mode2 = 0;
        plp->mode3 = 0;
            
        plp->mtn_no = 90;
        plp->frm_no = 0;
            
        plp->mtn_add = 0;
            
        plp->hokan_count = 10;
        plp->hokan_rate  = 45875;
        break;
    }
}

// 100% matching!
void bhEne27_MV02(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg |= 0x80000;
        
        epw->mtn_no = epw->type + 93;
        epw->frm_no = 0;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 0;
        
        epw->mode3++;
    case 1:
        epw->ct1 += bhEne_LeverCheck();
        
        if (epw->ct0-- == 0)
        {
            if (epw->ct1 > 30) 
            {
                epw->mtn_no = 96;
                epw->frm_no = 0;
                
                epw->mtn_add = 0;
                
                epw->ct1 = 0;
                
                plp->mtn_no = 92;
                plp->frm_no = 0;
                
                plp->mtn_add = 65536;
                
                plp->hokan_count = 10;
                plp->hokan_rate  = 45875;
                
                epw->mode3 = 3;
            } 
            else
            {
                epw->mtn_no = 96;
                epw->frm_no = 0;
                
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                
                epw->mode3 = 2;
                
                plp->mtn_no = 91;
                plp->frm_no = 0;
                
                plp->mtn_add = 65536;
                
                plp->hokan_count = 10;
                plp->hokan_rate  = 45875;
            }
        }
        
        if ((epw->frm_no / 65536) == 2) 
        {
            plp->mtn_no = 90;
            plp->frm_no = 0;
            
            plp->mtn_add = 65536;
            
            plp->hokan_count = 10;
            plp->hokan_rate  = 45875;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            plp->stflg |= 0x80000;
            
            plp->hp -= 5;
            
            if (plp->hp < 0) 
            {
                plp->hp = 0;
            }
            
            epw->mtn_add = 0;
            
            epw->ct1 = 0;
            
            plp->mtn_no = 92;
            plp->frm_no = 0;
            
            plp->mtn_add = 65536;
            
            plp->hokan_count = 10;
            plp->hokan_rate  = 45875;
            
            epw->mode3++;
            break;
        }
        
        if (((unsigned int)(epw->frm_no / 65536) % 10) == 9) 
        {
            plp->dvx = njSin(plp->ay);
            plp->dvy = -1.0f;
            plp->dvz = njCos(plp->ay);
            
            bhEne_SetBloodEffectBurst(plp, 6, 4, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        break;
    case 3:
        if (((epw->flg & 0x80000)) && (plp->frm_no == 0)) 
        {
            epw->flg &= ~0x80000;
            
            plp->flg &=  ~0x10004;
            plp->flg2 &= ~0x1;
            
            plp->flg |= 0x8;
            
            plp->at_flg = 0;
            
            plp->stflg &= ~0x10000;
            
            *(int*)&plp->mode0 = 1;
            
            if (epw->type == 0) 
            {
                plp->stflg &= ~0x8000000;
            }
            
            if (epw->type == 1) 
            {
                plp->stflg &= ~0x10000000;
            }
            
            if (epw->type == 2) 
            {
                plp->stflg &= ~0x20000000;
            }
            
            if ((epw->flg & 0x2)) 
            {
                epw->flg = 0;
                break; 
            }
        }
        
        if (!(epw->flg & 0x2)) 
        {
            epw->ct1++;
            
            if (epw->ct1 == 10) 
            {
                epw->flg &= ~0x80;
                
                epw->ay = plp->ay;
                
                epw->px = plp->px;
                epw->py = plp->py;
                epw->pz = plp->pz;
                
                epw->mtn_no = 97;
                epw->frm_no = 0;
                
                epw->mtn_add = 65536;
            }
            
            if (epw->ct1 == 24) 
            {
                NJS_VECTOR vec = { 0.4f, -1.7f, -0.2f }; 
                
                njUnitMatrix(NULL);
                
                njRotateY(NULL, epw->ay);
                njCalcVector(NULL, &vec, (NJS_VECTOR*)&epw->xn);
                
                epw->mtn_add = 0;
            }
            
            if (epw->ct1 > 24) 
            {
                NJS_POINT3 p1;  
                NJS_POINT3 p2; 
                O_WORK* owk;  
                
                owk = epw->mlwP->owP;
                
                p1.x = owk->mtx[12];
                p1.y = owk->mtx[13];
                p1.z = owk->mtx[14];
                
                p2.x = p1.x + epw->xn;
                p2.y = p1.y + epw->yn;
                p2.z = p1.z + epw->zn;
                
                if (bhCollisionCheckLine2(&p1, &p2, 0x4400, -1) != 0) 
                {
                    NJS_VECTOR vec;
                    
                    bhGetHitCollisionNormal(&vec);
                    
                    njUnitVector(&vec);
                    
                    p2.y += 1.0f;
                    
                    bhEne_SetBloodEffect4(&p2, &vec, 1, 0, 1);
                    
                    epw->mdflg |= 0x1;
                    epw->flg   |= 0x2;
                    
                    bhEne_CallSE(epw, &p2, 9031);
                    
                    if (!(epw->flg & 0x80000))
                    {
                        epw->flg = 0;
                    }
                }
                else 
                {
                    epw->px += epw->xn;
                    epw->py += epw->yn;
                    epw->pz += epw->zn;
                }
            }
            
            if (epw->ct1 > 60) 
            {
                epw->flg = 0;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne27_Nage()
{
	
}

// 100% matching!
void bhEne27_Damage()
{

}

// 100% matching!
void bhEne27_Die()
{

}

// 100% matching!
void bhEne27_IncubateEffect(BH_PWORK* epw)
{
    sys->ef.id = 5;
    
    sys->ef.flg  = 1;
    sys->ef.type = 0;
    
    sys->ef.mdlver = 0;
    
    sys->ef.px = 0.0f;
    sys->ef.py = 0.0f;
    sys->ef.pz = 0.0f;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, (NJS_POINT3*)&epw->lox, epw->lkwkp, epw->lkono); 
}

// 100% matching!
void bhEne27_CallSE(BH_PWORK* epw)
{
    char NullTree[2] = { 0, 0xFF };  
    int fno;                    
    NJS_POINT3 pos;        
    
    bhEne_GetPartsPos(epw, NullTree, &pos);
    
    fno = epw->frm_no / 65536;
    
    switch (epw->mtn_no) 
    {                        
    case 93:
    case 94:
    case 95:
        if (fno == 0) 
        {
            bhEne_CallSE(epw, &pos, 74564);
        }
        
        if ((fno % 12) == 11) 
        {
            bhEne_CallSE(epw, &pos, 74565);
        }
        
        break;
    case 96:
        if ((fno % 10) == 9) 
        {
            bhEne_CallSE(epw, &pos, 74566);
        }
        
        break;
    }
}
