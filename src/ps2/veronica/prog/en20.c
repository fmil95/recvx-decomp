#include "../../../ps2/veronica/prog/en20.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/subpl.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne20_Mode0[6] =
{
    bhEne20_Init,
    bhEne20_Move,
    bhEne20_Nage,
    bhEne20_Damage,
    bhEne20_Die,
    bhEne_Event
};

MoveMode2_proc bhEne20_MoveMode2[8] =
{
    bhEne20_MV00,
    bhEne20_MV01,
    bhEne20_MV02,
    bhEne20_MV03,
    bhEne20_MV04,
    bhEne20_MV05,
    bhEne20_MV06,
    bhEne20_MV07
};

// 100% matching!
void bhEne20(BH_PWORK* epw) 
{
    bhEne20_Mode0[epw->mode0](epw);
    bhSetMotion(epw, epw->mtn_add, (int) epw->mtn_md, epw->mtn_tp);
    bhCalcModel(epw);
}

// 100% matching!
void bhEne20_Init(BH_PWORK* epw) 
{
	float dx, dz;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x30, 8);
    }
    
    epw->flg |= 1;
    epw->flg |= 0x8000;
    epw->flg &= ~6;
    epw->ar = 0.0f;
    epw->ah = 0.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->hp = 0x64;
    
    if (epw->type == 0) 
    {
        dx = epw->px - 70.0f;
        dz = epw->pz - 70.0f;

        epw->ax = 0x4000;
        
        epw->ay = (int)(10430.381f * atan2f(dx, dz));
    }
    
    epw->mtn_no = 0;
    epw->frm_no = 0;
    epw->hokan_count = 0;
    epw->hokan_rate = 0x10000;
    epw->mtn_add = 0x10000;
    epw->mtn_md = 0;
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->clp_jno[0] = 0;
    epw->clp_jno[1] = -1;
    epw->mdflg &= ~0x20;
}

// 100% matching!
void bhEne20_Move(BH_PWORK* epw) 
{
    if (epw->mode0 == 1) 
    {
        bhEne20_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne20_MV00(BH_PWORK* epw) 
{
    unsigned int rnd;

    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 0) 
            {
                epw->mtn_no = 0;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = (rand() % 10) + 10;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->ct0-- == 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                
                rnd = rand() % 6;
                
                if (rnd == 0) 
                {
                    epw->mode2 = 6;
                }
                else if (rnd == 1) 
                {
                    epw->mode2 = 7;
                } 
                else 
                {
                    epw->mode2 = 0;
                }
                
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV01(BH_PWORK* epw) 
{
    unsigned int rnd;

    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 7) 
            {
                epw->mtn_no = 7;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = (rand() % 10) + 10;
            epw->spd = 0.0f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            bhAddSpeed(epw, 0);
            
            if (epw->ct0-- == 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                
                rnd = rand() % 10;
                
                if (rnd < 2) 
                {
                    epw->mode2 = 0;
                }
                else 
                {
                    if (rnd == 2)
                    {
                        epw->mode2 = 3;
                    }
                    else if (rnd == 3)
                    {
                        epw->mode2 = 2;
                    }
                    else 
                    {
                        epw->mode2 = 1;
                    }
                }
                
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 7) 
            {
                epw->mtn_no = 7;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = (rand() % 10) + 0xA;
            epw->spd = 0.0f;
            epw->mode3++;
            
            /* fallthrough */
        case 1:
            bhAddSpeed(epw, 0);
            
            if (epw->ct0-- == 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV03(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 7)
            {
                epw->mtn_no = 7;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = (rand() % 10) + 0xA;
            epw->spd = 0.0f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            bhAddSpeed(epw, 0);
            
            if (epw->ct0-- == 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV04(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 5) 
            {
                epw->mtn_no = 5;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
            epw->spd = 0.0f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            bhAddSpeed(epw, 0);
            
            if (epw->ct0-- == 0)
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV05(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no != 6) 
            {
                epw->mtn_no = 6;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
            epw->spd = 0.0f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            bhAddSpeed(epw, 0);
            
            if (epw->ct0-- == 0)
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV06(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
        case 0:
            if (epw->mtn_no != 3) 
            {
                epw->mtn_no = 3;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;    
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->ct0-- == 0)
            {
                epw->mtn_no = 4;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num * 2;
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if (epw->ct0-- == 0)
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_MV07(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {
        case 0:
            if (epw->mtn_no != 2) 
            {
                epw->mtn_no = 2;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
            }
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->ct0-- == 0)
            {
                epw->mtn_no = 1;
                epw->frm_no = 0;
                epw->hokan_count = 3;
                epw->hokan_rate = 0x8000;
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if (epw->ct0-- == 0)
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne20_Nage(void) 
{

}

// 100% matching!
void bhEne20_Damage(void) 
{

}

// 100% matching!
void bhEne20_Die(void) 
{

}
