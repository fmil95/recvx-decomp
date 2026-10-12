#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/en13sub.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Second Form Alexia 

#pragma divbyzerocheck on

static ETTY_WORK ene18 = 
{
    0x8081, 18, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};
static ETTY_WORK ene13B = 
{
    0x8081, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};
void (*bhEne13_Mode0[6])(BH_PWORK*) = 
{
	bhEne13_Init,
	bhEne13_Move,
	bhEne13_Nage,
	bhEne13_Damage,
	bhEne13_Die,
	bhEne_Event
};       
void (*bhEne13_BrainType[2])(BH_PWORK*) = 
{
	bhEne13_BR00,
	bhEne13_BR01
};   
void (*bhEne13_MoveMode2[4])(BH_PWORK*) = 
{
	bhEne13_MV00,
	bhEne13_MV01,
	bhEne13_MV02,
	bhEne13_MV03
};   
void (*bhEne13_DamageMode2[1])(BH_PWORK*) = 
{
	bhEne13_DG00
}; 

// 100% matching!
void bhEne13(BH_PWORK* epw) 
{
    bhEne13_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    bhCalcModel(epw);
    
    bhEne13_CameraControl(epw);
    bhEne13_PlayerControl(epw);
}

// 100% matching!
void bhEne13_Init(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int i;

    epw->flg   |=  0x8018;
    epw->flg   &= ~0x6;
    
    epw->flg2  |=  0x1;
    
    epw->mdflg |=  0x20;
    
    epw->ar = 5.0f;
    epw->ah = 1.0f;
    
    epw->car = 3.0f;
    
    epw->hp = (sys->gm_mode != 2) ? 700 : 400;
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(992, 8);

        *(BH_PWORK**)&epw->exp0[8] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[8])->type = 1;
        
        (*(BH_PWORK**)&epw->exp0[8])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[8])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[8])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[8])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[8])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[8])->mlwP = &epw->mdl[1];

        *(BH_PWORK**)&epw->exp0[12] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[12])->type = 2;
        
        (*(BH_PWORK**)&epw->exp0[12])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[12])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[12])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[12])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[12])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[12])->mlwP = &epw->mdl[4];

        *(BH_PWORK**)&epw->exp0[16] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[16])->type = 3;
        
        (*(BH_PWORK**)&epw->exp0[16])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[16])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[16])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[16])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[16])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[16])->mlwP = &epw->mdl[7];

        *(BH_PWORK**)&epw->exp0[4] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[4])->type = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[4])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[4])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[4])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->mlwP = &epw->mdl[10];

        *(NJS_CNK_OBJECT**)&epw->exp0[92]  = (*(BH_PWORK**)&epw->exp0[4])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[96]  = (*(BH_PWORK**)&epw->exp0[8])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[100] = (*(BH_PWORK**)&epw->exp0[12])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[104] = (*(BH_PWORK**)&epw->exp0[16])->mlwP->objP;

        for (i = 0; i < 6; i++)
        {
            ((BH_PWORK**)epw->exp0)[i + 5] = bhSetEnemy(&ene18, rom->ene_n);
            
            ((BH_PWORK**)epw->exp0)[i + 5]->type = i + 4;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->lkwkp = (unsigned char*)epw;
            ((BH_PWORK**)epw->exp0)[i + 5]->lkono = 0;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->lox = 0;
            ((BH_PWORK**)epw->exp0)[i + 5]->loy = 0;
            ((BH_PWORK**)epw->exp0)[i + 5]->loz = 0;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->mlwP = &epw->mdl[10];
        }

        *(BH_PWORK**)&epw->exp0[976] = bhSetEnemy(&ene13B, rom->ene_n);

        (*(BH_PWORK**)&epw->exp0[976])->type = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[976])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[976])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[976])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->mlwP = &epw->mdl[13];
        
        (*(BH_PWORK**)&epw->exp0[976])->skp[0] = epw->skp[13];
        
        (*(BH_PWORK**)&epw->exp0[976])->mdl_no = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->mnwP  = epw->mnwP;
        (*(BH_PWORK**)&epw->exp0[976])->mnwPb = epw->mnwPb;
        
        bhEne_SetCallFunc(bhEne13B, 31);
        
        EXP0_I(932) = 0;
        EXP0_I(936) = bhEne13_StoreObject(                        epw, (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(932));
        EXP0_I(940) = bhEne13_StoreObject( *(BH_PWORK**)&epw->exp0[4], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(936));
        EXP0_I(944) = bhEne13_StoreObject( *(BH_PWORK**)&epw->exp0[8], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(940));
        EXP0_I(948) = bhEne13_StoreObject(*(BH_PWORK**)&epw->exp0[12], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(944));
        
        bhEne13_StoreObject(*(BH_PWORK**)&epw->exp0[16], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(948));
    }

    (*(BH_PWORK**)&epw->exp0[4])->mlwP->objP  = *(NJS_CNK_OBJECT**)&epw->exp0[92];
    (*(BH_PWORK**)&epw->exp0[8])->mlwP->objP  = *(NJS_CNK_OBJECT**)&epw->exp0[96];
    (*(BH_PWORK**)&epw->exp0[12])->mlwP->objP = *(NJS_CNK_OBJECT**)&epw->exp0[100];
    (*(BH_PWORK**)&epw->exp0[16])->mlwP->objP = *(NJS_CNK_OBJECT**)&epw->exp0[104];

    bhEne13_RestoreObject(                        epw, (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(932));
    bhEne13_RestoreObject( *(BH_PWORK**)&epw->exp0[4], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(936));
    bhEne13_RestoreObject( *(BH_PWORK**)&epw->exp0[8], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(940));
    bhEne13_RestoreObject(*(BH_PWORK**)&epw->exp0[12], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(944));
    bhEne13_RestoreObject(*(BH_PWORK**)&epw->exp0[16], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(948));
    
    EXP0_I(108) = 0;

    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 30))
        {
            *((BH_PWORK**)epw->exp0 + (EXP0_I(108) + 11)) = ep;
            
            EXP0_I(108)++;
            
            ep->lkwkp = (unsigned char*)epw;
        }
        
        if (((ep->flg & 0x1)) && (ep->id == 14)) 
        {
            *(BH_PWORK**)&epw->exp0[112] = ep;
            
            ep->lkwkp = (unsigned char*)epw;
        }
    }
    
    EXP0_I(964) = 15;
    EXP0_I(968) = 30;
    EXP0_I(972) = 45;
    
    EXP0_I(116) = EXP0_I(120) = EXP0_I(124) = 100;
}

// 100% matching!
void bhEne13_Brain(BH_PWORK* epw)
{
    bhEne13_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne13_BR00(BH_PWORK* epw) 
{
    BH_PWORK* ep; 
    int i, j;        
    float dist;   
    
    if (epw->hp < 0)
    {
        return;
    }

    dist = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    if (EXP0_I(964) != 0)
    {
        EXP0_I(964)--;
    }

    if (EXP0_I(968) != 0)
    {
        EXP0_I(968)--;
    }

    if (EXP0_I(972) != 0)
    {
        EXP0_I(972)--;
    }

    if ((EXP0_I(972) == 0) && (dist > 40.0f))
    {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;

        if (dist > 60.0f)
        {
            EXP0_I(972) = 10;
        }
        else
        {
            EXP0_I(972) = 45;
        }
        
        return;
    }

    if ((dist < 60.0f) && (EXP0_I(968) == 0) && ((((*(BH_PWORK**)&epw->exp0[8])->mode2  != 4) && ((*(BH_PWORK**)&epw->exp0[8])->mode2 != 5)) && (((*(BH_PWORK**)&epw->exp0[12])->mode2 != 4) && ((*(BH_PWORK**)&epw->exp0[12])->mode2 != 5)) && (((*(BH_PWORK**)&epw->exp0[16])->mode2 != 4) && ((*(BH_PWORK**)&epw->exp0[16])->mode2 != 5))))
    {
        j = bhEne13_SelectTentacle(epw);

        if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0)
        {
            EXP0_I(128) = j;

            if (njRandom() < 0.4f)
            {
                EXP0_I(984) = EXP0_I(128);
            }
            else
            {
                EXP0_I(984) = EXP0_I(128) + 3;
            }

            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;

            EXP0_I(968) = 30;

            if (EXP0_I(964) != 0)
            {
                EXP0_I(964)--;
            }
            else
            {
                epw->type = 0;
            }
            
            return;
        }
    }

    if (EXP0_I(964) == 0)
    {
        j = 3.0f * njRandom();

        EXP0_I(128) = -1;

        for (i = 0; i < 3; i++)
        {
            if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0)
            {
                EXP0_I(128) = j;
                break;
            }

            if (++j > 2)
            {
                j = 0;
            }
        }

        if (EXP0_I(128) != -1)
        {
            for (i = 0; i < EXP0_I(108); i++)
            {
                ep = *(BH_PWORK**)(&epw->exp0[44] + (4 * i));

                if ((ep->mode0 == 1) && (ep->mode2 == 0))
                {
                    epw->mode1 = 0;
                    epw->mode2 = 1;
                    epw->mode3 = 0;

                    EXP0_I(964) = 15;
                    break;
                }
            }
        }
    }
}

// 100% matching!
void bhEne13_BR01(BH_PWORK* epw) 
{
    int j;
    float dist;

    if (epw->hp < 0) 
    {
        return;
    }

    dist = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    if (EXP0_I(968) != 0)
    {
        EXP0_I(968)--;
    }
    
    if (EXP0_I(972) != 0)
    {
        EXP0_I(972)--;
    }
    
    if ((EXP0_I(972) == 0) && (dist > 60.0f))
    {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        
        EXP0_I(972) = 45;
        return;
    }
    
    if ((EXP0_I(968) == 0) && (((*(BH_PWORK**)(&epw->exp0[8]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[8]))->mode2 != 5) && ((*(BH_PWORK**)(&epw->exp0[12]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[12]))->mode2 != 5) && ((*(BH_PWORK**)(&epw->exp0[16]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[16]))->mode2 != 5)))
    {
        j = bhEne13_SelectTentacle(epw);
        
        if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0) 
        {
            EXP0_I(128) = j;

            if (njRandom() > 0.7f)
            {
                EXP0_I(984) = EXP0_I(128);
            }
            else 
            {
                EXP0_I(984) = EXP0_I(128) + 3;
            }
            
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
    
            EXP0_I(968) = 30;
            
            if (EXP0_I(964) != 0)
            {
                EXP0_I(964)--;
            }
            else
            {
                epw->type = 0;
                return;
            }
        }
    }
}

// 100% matching!
void bhEne13_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1) 
    {
        bhEne13_Brain(epw);
    }
    
    bhEne13_MoveMode2[epw->mode2](epw);
    
    if (((((*(BH_PWORK**)&epw->exp0[20])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[24])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[28])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[32])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[36])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[40])->flg & 0x4))) || ((*(BH_PWORK**)&epw->exp0[112] != NULL) && ((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))) 
    {
        bhEne13_InitDamage(epw);
    }
}

// 100% matching!
void bhEne13_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        epw->mode3++;
        break;
    }
}

// 100% matching!
void bhEne13_MV01(BH_PWORK* epw)
{
    BH_PWORK* ep;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        {
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
        }
        
        epw->ct0 = 10;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->ct0-- == 0)
        {
            ep = *(BH_PWORK**)&epw->exp0[8] + EXP0_I(128);
            
            ep->mode2 = 2;
            ep->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 2;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        { 
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 2;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0; 
        }
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_MV03(BH_PWORK* epw) 
{
    BH_PWORK* ep;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        {
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
        }
        
        epw->ct0 = 10;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->ct0-- == 0)
        {
            ep = *(BH_PWORK**)&epw->exp0[8] + EXP0_I(128);
            
            ep->mode3 = 0;
            
            if (EXP0_I(984) >= 3)
            {
                ep->mode2 = 4;
            }
            else
            {
                ep->mode2 = 5;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_Nage()
{

}

// 100% matching!
void bhEne13_Damage(BH_PWORK* epw)
{
    int dam;    
    int i;      
    int max_dam; 
    
    if ((((*(BH_PWORK**)&epw->exp0[20])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[24])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[28])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[32])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[36])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[40])->flg & 0x4)) || ((*(BH_PWORK**)&epw->exp0[112] != NULL) && ((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4))))
    {
        max_dam = 0;

        for (i = 0; i < 6; i++)
        {
            if (((*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg & 0x4))
            {
                (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg &= ~0x4;

                dam = bhEne18_HitMark(*(BH_PWORK**)(&epw->exp0[20] + (4 * i)));

                if (max_dam < dam)
                {
                    max_dam = dam;
                }
            }
        }

        if (((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))
        {
            (*(BH_PWORK**)&epw->exp0[112])->flg &= ~0x4;

            dam = bhEne14_HitMark(*(BH_PWORK**)&epw->exp0[112]);

            if (max_dam < dam)
            {
                max_dam = dam;
            }
        }

        epw->hp -= max_dam;
    }

    bhEne13_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne13_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        if ((epw->frm_no == 3932160) && (epw->hp < 0))
        {
            epw->flg |= 0x2;
        }
    }
}

// 100% matching!
void bhEne13_Die(BH_PWORK* epw)
{
    int i;

    switch (epw->mode3) 
    {
    case 0:
        (*(unsigned char**)&epw->exp0[976])[12] = 4;
        (*(unsigned char**)&epw->exp0[976])[13] = 0;
        (*(unsigned char**)&epw->exp0[976])[14] = 0;
        (*(unsigned char**)&epw->exp0[976])[15] = 0;

        for (i = 0; i < 4; i++)
        {
            ((unsigned char**)epw->exp0)[1 + i][12] = 4;
            ((unsigned char**)epw->exp0)[1 + i][13] = 0;
            ((unsigned char**)epw->exp0)[1 + i][14] = 0;
            ((unsigned char**)epw->exp0)[1 + i][15] = 0;
        }

        for (i = 0; i < 6; i++) 
        {
            ((unsigned char**)epw->exp0)[5 + i][12] = 4;
            ((unsigned char**)epw->exp0)[5 + i][13] = 0;
            ((unsigned char**)epw->exp0)[5 + i][14] = 0;
            ((unsigned char**)epw->exp0)[5 + i][15] = 0;
        }

        epw->mode3++;
        break;
    case 1:
        epw->spd = 0.97f + (epw->mode2 / 50.0f);
        
        bhEne13_Finish(epw);
        break;
    }
}

// 100% matching!
void bhEne13_InitDamage(BH_PWORK* epw) 
{
    int dam, dam0, dam1, dam2, max_dam;    
    int i;      
    int wep_no;  
    int dflg, flg;   
    
    dam0 = dam1 = dam2 = max_dam = 0;

    for (i = 0; i < 6; i++)
    {
        if (((*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg & 0x4))
        {
            (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg &= ~0x4;

            dam = bhEne18_HitMark(*(BH_PWORK**)(&epw->exp0[20] + (4 * i)));

            if (max_dam < dam)
            {
                max_dam = dam;

                wep_no = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->wpnr_no;
                
                dflg = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg2 & 0x4;
            }
        }
    }

    if (((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))
    {
        (*(BH_PWORK**)&epw->exp0[112])->flg &= ~0x4;

        dam = bhEne14_HitMark(*(BH_PWORK**)&epw->exp0[112]);

        if (max_dam < dam)
        {
            max_dam = dam;

            wep_no = (*(BH_PWORK**)&epw->exp0[112])->wpnr_no;
            
            dflg = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg2 & 0x4;
        }
    }

    if ((max_dam != 0) || (dam0 != 0) || (dam1 != 0) || (dam2 != 0))
    {
        flg = 0;

        switch (wep_no) 
        {
        case 15:
        case 16:
        case 17:
            if (dflg == 0) 
            {
                break;
            }
        default:
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8961);
            break;
        }
        
        if (epw->hp > 600)
        {
            epw->hp -= max_dam;

            if (epw->hp < 600)
            {
                flg = 1;
            }
        }
        else if (epw->hp > 400)
        {
            epw->hp -= max_dam;

            if (epw->hp < 400)
            {
                flg = 1;
            }
        }
        else if (epw->hp > 200)
        {
            epw->hp -= max_dam;

            if (epw->hp < 200)
            {
                flg = 1;
            }
        }
        else
        {
            epw->hp -= max_dam;

            if (epw->hp < 0)
            {
                flg = 1;
            }
        }

        if (flg != 0)
        {
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;

            if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
            {
                if (epw->hp < 0)
                {
                    (*(BH_PWORK**)&epw->exp0[112])->mode0 = 3;
                    (*(BH_PWORK**)&epw->exp0[112])->mode1 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
                    (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
                }
                else
                {
                    (*(BH_PWORK**)&epw->exp0[112])->mode0 = 3;
                    (*(BH_PWORK**)&epw->exp0[112])->mode1 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode2 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
                }
            }
        }
    }
}

// 100% matching!
void bhEne13_Finish(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* pObj; 
    int ono, obj_n;             
    int i;               

    for (i = 0; i < 4; i++)
    {
        pObj  = (*(BH_PWORK**)(&epw->exp0[4] + (4 * i)))->mlwP->objP;
        obj_n = (*(BH_PWORK**)(&epw->exp0[4] + (4 * i)))->mlwP->obj_num;

        for (ono = 0; ono < obj_n; ono++, pObj++)
        {
            pObj->pos[1] *= epw->spd;

            bhEne13_ScaleModel(pObj, 1.0f, epw->spd, 1.0f);
        }
    }

    pObj  = epw->mlwP->objP;
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++)
    {
        if ((ono == 1) || (ono == 4) || (ono == 7) || (ono == 11) || (ono == 15) || (ono == 19))
        {
            pObj->pos[1] *= epw->spd;
        }
        else
        {
            pObj->pos[0] *= epw->spd;
            pObj->pos[1] *= epw->spd;
            pObj->pos[2] *= epw->spd;
        }

        bhEne13_ScaleModel(pObj, epw->spd, epw->spd, epw->spd);
    }
}

// 100% matching!
void bhEne13_ScaleModel(NJS_CNK_OBJECT* pObj, float sx, float sy, float sz)
{
	int nVtx;
	int i; 
 	NJS_POINT4* p; 
	HDR_PS* pHdr; 
   
    if (pObj->model != NULL)
    {
        pHdr = (HDR_PS*)pObj->model->vlist;
        
        nVtx = pHdr->usIndexMax;
        
        p = (NJS_POINT4*)&pHdr[1];
    
        for (i = 0; i < nVtx; i++)
        {
            p[0].x *= sx;
            p[0].y *= sy;
            p[0].z *= sz;
            
            p[1].x *= sx;
            p[1].y *= sy;
            p[1].z *= sz;
            
            p += 2;
        }
    }
}

// 100% matching!
int bhEne13_StoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	NJS_CNK_OBJECT* pObj;
	int ono, obj_n; 
	int i; 
	NJS_CNK_MODEL* pModel;
 	int nVtx;
	NJS_POINT4* ps, *pd; 
	HDR_PS* pHdr; 

    pObj = epw->mlwP->objP;
    
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++, no++)
    {
        pos[no].x = pObj->pos[0];
        pos[no].y = pObj->pos[1];
        pos[no].z = pObj->pos[2];

        pModel = pObj->model;
        
        if (pModel != NULL)
        {
            pHdr = (HDR_PS*)pModel->vlist;
            
            nVtx = pHdr->usIndexMax;
            
            v[no] = bhEne_CallocWork(nVtx * 32, 64);
            
            pd = (NJS_POINT4*)v[no];
            ps = (NJS_POINT4*)&pHdr[1];

            for (i = 0; i < nVtx; i++)
            {
                pd[0].x = ps[0].x;
                pd[0].y = ps[0].y;
                pd[0].z = ps[0].z;
                
                pd[1].x = ps[1].x;
                pd[1].y = ps[1].y;
                pd[1].z = ps[1].z;
                
                ps += 2;
                pd += 2;
            }
        }
    }
    
    return no;
}

// 100% matching!
int bhEne13_RestoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	NJS_CNK_OBJECT* pObj; 
	int ono, obj_n;
	int i; 
	NJS_CNK_MODEL* pModel;
	int nVtx; 
	NJS_POINT4* ps, *pd;
	HDR_PS* pHdr;

    pObj = epw->mlwP->objP;
    
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++, no++)
    {
        pObj->pos[0] = pos[no].x;
        pObj->pos[1] = pos[no].y;
        pObj->pos[2] = pos[no].z;

        pModel = pObj->model;
        
        if (pModel != NULL)
        {
            pHdr = (HDR_PS*)pModel->vlist;
            
            ps = (NJS_POINT4*)v[no];
            
            nVtx = pHdr->usIndexMax;
            
            pd = (NJS_POINT4*)&pHdr[1];

            for (i = 0; i < nVtx; i++)
            {
                pd[0].x = ps[0].x;
                pd[0].y = ps[0].y;
                pd[0].z = ps[0].z;
                
                pd[1].x = ps[1].x;
                pd[1].y = ps[1].y;
                pd[1].z = ps[1].z;
                
                ps += 2;
                pd += 2;
            }
        }
    }
    
    return no;
}

// 100% matching!
void bhEne13_PutAttacker(BH_PWORK* epw, int no)
{
    BH_PWORK* ep;       
	int i;           
	NJS_POINT3 wp;     
	NJS_POINT3 pos[3] =
	{
		{   0.0f,   0.0f, -25.0f },
		{ -20.0f,   0.0f, -13.0f },
		{  20.0f,   0.0f, -13.0f }
	};
	int ang[3] = { 0, 8192, 0xFFFFE000 }; 
    
    for (i = 0; i < EXP0_I(108); i++)
    {
        ep = *(BH_PWORK**)(&epw->exp0[44] + (4 * i));

        if ((ep->mode0 == 1) && (ep->mode2 == 0))
        {
            ep->mode1 = 0;
            ep->mode2 = 6;
            ep->mode3 = 0;

            njUnitMatrix(NULL);
            
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &pos[no], &wp);

            ep->px = ep->pxb = epw->px + wp.x;
            ep->py = ep->pyb = epw->py + wp.y;
            ep->pz = ep->pzb = epw->pz + wp.z;

            ep->ay = epw->ay + ang[no];

            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74507);
            break;
        }
    }
}

// 100% matching!
void bhEne13_Tentacle(BH_PWORK* epw, int no)
{
    (*(unsigned char**)&epw->exp0[976])[12] = 1;
    (*(unsigned char**)&epw->exp0[976])[13] = 0;
    (*(unsigned char**)&epw->exp0[976])[14] = 1;
    (*(unsigned char**)&epw->exp0[976])[15] = 0;
    
    (*(unsigned short**)&epw->exp0[976])[3] = no;
}

// 100% matching!
int bhEne13_GetHatchNo(BH_PWORK* epw)
{
    return EXP0_I(128);
}

// 100% matching!
int bhEne13_GetTentaNo(BH_PWORK* epw)
{
    return EXP0_I(984);
}

// 100% matching!
BH_PWORK** bhEne13_GetChild(BH_PWORK* epw, int* num)
{
    *num = EXP0_I(108);
    
    return (BH_PWORK**)&epw->exp0[44];
}

// 100% matching!
void bhEne13_CameraControl(BH_PWORK* epw)
{
    if (epw->mode0 != 5)
    {
        if ((epw->flg & 0x80000))
        {
            cam.ofx = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofy = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofz = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
        }
        else if (EXP0_F(980) > 0.01f)
        {
            cam.ofx = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofy = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofz = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            
            EXP0_F(980) *= 0.9f;
        }
        else
        {
            cam.ofx = cam.ofy = cam.ofz = 0;
        }
    }
}

// 100% matching!
void bhEne13_SetCamera(BH_PWORK* epw, float f)
{
    EXP0_F(980) = f;
}

// 100% matching!
int bhEne13_SelectTentacle(BH_PWORK* epw)
{
    int ang;

    ang = (short)(bhArcTan2(epw->px - plp->px, epw->pz - plp->pz) - epw->ay);
	
    if (njRandom() < 0.9f)
    {
        if (ang > NJM_DEG_ANG(30.0f))
        {
            return 1;
        }
        else if (ang < -NJM_DEG_ANG(30.0f))
        {
            return 2;
        }
    }

    return 0;
}

// 100% matching!
void bhEne13_PlayerControl(BH_PWORK* epw) 
{
	int mtn[3][8] =         
	{
		{ 10, 11, 12, 13, 15, 14,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 } 
	};
	NJS_POINT3* trans[3][3] = 
	{
		{ cler_042, cler_043, cler_045 },
		{ cher_060, cher_061, cher_063 },
		{ cher_060, cher_061, cher_063 }
	};
    
    if (plp->mode0 == 4)
    {
        switch (plp->mode2)
        {
        case 0:
        case 1:
            switch (plp->mode3)
            {
            case 0:
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;

                plp->mnwP = epw->mnwP;

                if (plp->mode2 == 0)
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                }
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }

                plp->frm_no = 0;

                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;

                plp->mtn_add = 65536;

                plp->mode3++;

                plp->ct0 = 8;

                bhEne_CallPlayerVoice(2);
                
                StartVibrationEx(1, 11);
                break;
            case 1:
                if (plp->mode2 == 0)
                {
                    bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][1]);
                }

                if (plp->ct0 != 0)
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;

                    plp->ct0--;
                }

                if (plp->frm_no == 0)
                {
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = mtn[sys->ply_id][2];

                        plp->flg |= 0xC0000;
                    }
                    else
                    {
                        plp->mtn_no = mtn[sys->ply_id][3];
                    }

                    plp->mode3++;
                }
                
                break;
            case 2:
                if (plp->mode2 == 0)
                {
                    if ((plp->frm_no / 65536) == 19)
                    {
                        plp->flg &= ~0x80000;
                    }

                    if ((sys->ply_id == 0) && ((plp->frm_no / 65536) == 41))
                    {
                        plp->flg |= 0x80000;
                    }
                }
                else
                {
                    if (plp->mtn_no == mtn[sys->ply_id][3])
                    {
                        bhEne_AddNullTrans(plp, trans[sys->ply_id][2]);
                    }
                }

                if (plp->frm_no == 0)
                {
                    plp->mnwP = plp->mnwPb;

                    plp->flg  &= ~0x10004;
                    plp->flg2 &= ~0x1;
                    plp->flg  |=  0x8;

                    plp->at_flg = 0;

                    plp->stflg &= ~0x10000;

                    *(int*)&plp->mode0 = 1;
                }
                
                break;
            }
        }

        plp->flg |= 0x200000;
    }
    else if (plp->mode0 == 6)
    {
        switch (plp->mode2)
        {
        case 0:
        case 1:
            switch (plp->mode3)
            {
            case 0:
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;

                plp->mnwP = epw->mnwP;

                if (plp->mode2 == 2)
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                }
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }

                plp->frm_no = 0;

                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;

                plp->mtn_add = 65536;

                plp->mode3++;

                plp->ct0 = 8;

                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                break;
            case 1:
                if (plp->mode2 == 2)
                {
                    bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][1]);
                }

                if (plp->ct0 != 0)
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;

                    plp->ct0--;
                }

                if (plp->frm_no == 0)
                {
                    if (plp->mode2 == 2)
                    {
                        plp->mtn_no = mtn[sys->ply_id][4];
                    }
                    else
                    {
                        plp->mtn_no = mtn[sys->ply_id][5];
                    }

                    plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 2;

                    plp->mode3++;
                }
                
                break;
            case 2:
                if (plp->ct0-- == 0)
                {
                    plp->mtn_add = 0;

                    plp->ct0 = 45;

                    plp->mode3++;
                }
                
                break;
            case 3:
                if (plp->ct0-- == 0)
                {
                    plp->flg |= 0x2;
                }
                
                break;
            }
                
            break;
        }

        plp->flg |= 0x200000;
    }
}
