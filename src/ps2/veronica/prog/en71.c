#include "../../../ps2/veronica/prog/en71.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/subpl.h"

#pragma optimization_level 4

typedef void (*bhEne71_Mode0_proc)(BH_PWORK* epw);
bhEne71_Mode0_proc bhEne71_Mode0[6] = 
{
	bhEne71_Init,
	bhEne71_Move,
	bhEne71_Nage,
	bhEne71_Damage,
	bhEne71_Die,
	bhEne_Event
};

// 100% matching!
void bhEne71(BH_PWORK* epw) 
{
    bhEne71_Mode0[epw->mode0](epw);
    
    epw->mode2++;
    
    if (epw->mode2 > 2) 
    {
        epw->mode2 = 0;
        
        epw->mode3++;
        
        if (epw->mode3 > 3) 
        {
            epw->mode3 = 0;
        }
    }
    
    epw->mlwP = &epw->mdl[epw->mode3];
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    bhCalcModel(epw);
}

// 100% matching!
void bhEne71_Init(BH_PWORK* epw)
{
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(4, 8);
    }
    
    epw->flg |= 0x18;
    epw->flg &= ~0x6;
    
    epw->mtn_no = 0;
    
    if ((epw->type == 1) || (epw->type == 3) || (epw->type == 5)) 
    {
        epw->mtn_no = 1;
    } 
    
    epw->frm_no = 0;
    
    epw->hokan_count = 0;
    epw->hokan_rate = 65536;
    
    epw->mtn_add = 65536;
    epw->mtn_md = 0;
    
    if ((epw->type == 2) || (epw->type == 3)) 
    {
        epw->ax = 16384;  
    } 
    else if ((epw->type == 4) || (epw->type == 5))
    {
        epw->ax = 8192; 
    }

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->clp_jno[0] = 0;
    epw->clp_jno[1] = -1;
    
    epw->mdflg &= ~0x20;
}

// 100% matching!
void bhEne71_Move()
{

}

// 100% matching!
void bhEne71_Nage()
{

}

// 100% matching!
void bhEne71_Damage()
{

}

// 100% matching!
void bhEne71_Die()
{

}
