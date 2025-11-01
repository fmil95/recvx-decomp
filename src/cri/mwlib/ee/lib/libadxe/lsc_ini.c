#include "lsc_ini.h"

static Char8* lsc_obj_mark = "MARK:lsc_obj"; /* unused */
LSC_OBJ lsc_obj[LSC_OBJ_MAX] = { 0 };
static Sint32 lsc_init_cnt;

// 100% matching!
void lsc_DeleteSvrInt(void) 
{

}

// 100% matching!
void lsc_EntrySvrInt(void)
{

}

// 100% matching!
void LSC_Finish(void)
{
    LSC lsc;
    LSC_CRS crs;
    Sint32 i;
    
    LSC_LockCrs(&crs);
    
    if (--lsc_init_cnt == 0) 
    {
        for (i = 0; i < LSC_OBJ_MAX; i++) 
        {
            lsc = &lsc_obj[i];
            
            if (lsc->used == TRUE) 
            {
                LSC_Destroy(lsc);
            }
        }

        memset(lsc_obj, 0, sizeof(lsc_obj));
        
        lsc_DeleteSvrInt();
        LSC_EntryErrFunc(NULL, NULL);
    }
    
    LSC_UnlockCrs(&crs);
}

// 100% matching!
void LSC_Init(void)
{
    LSC_CRS crs;
    
    LSC_LockCrs(&crs);
    
    if (lsc_init_cnt == 0) 
    {
        memset(lsc_obj, 0, sizeof(lsc_obj));
        
        lsc_EntrySvrInt();
        LSC_EntryErrFunc(NULL, NULL);
    }
    
    lsc_init_cnt++;
    
    LSC_UnlockCrs(&crs);
}
