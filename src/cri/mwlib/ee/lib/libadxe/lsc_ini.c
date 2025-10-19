#include "cri_lsc.h"

static Char8* lsc_obj_mark = "MARK:lsc_obj"; /* unused */
static LSC_OBJ lsc_obj[LSC_OBJ_MAX] = { 0 };
static Sint32 lsc_init_cnt;

// 100% matching!
void lsc_DeleteSvrInt(void) 
{

}

// 100% matching!
void lsc_EntrySvrInt(void)
{

}

void LSC_Finish(void)
{
    scePrintf("LSC_Finish - UNIMPLEMENTED!\n");
}

// 100% matching!
void LSC_Init(void)
{
    Sint32 unused; 
    
    LSC_LockCrs(&unused);
    
    if (lsc_init_cnt == 0) 
    {
        memset(lsc_obj, 0, sizeof(lsc_obj));
        
        lsc_EntrySvrInt();
        LSC_EntryErrFunc(NULL, NULL);
    }
    
    lsc_init_cnt++;
    
    LSC_UnlockCrs(&unused);
}
