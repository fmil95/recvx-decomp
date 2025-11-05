#include "adx_inis.h"
#include "adx_crs.h"
#include "adx_errs.h"
#include "adx_rnap.h"
#include "adx_sjd.h"
#include "adx_stmc.h"
#include "lsc_ini.h"

#include <string.h>

static Sint32 adxt_vsync_svr_flag;
Sint32 adxt_init_cnt;
ADX_TALK adxt_obj[ADXT_MAX_OBJ] = { 0 };
Uint32 adxt_vsync_cnt;
static Sint8 adxt_obj_mark[16] = "MARK:adxt_obj"; /* unused */

// 100% matching!
void adxini_rnaerr_cbfn(void *obj, const Char8 *msg)
{
    ADXERR_CallErrFunc1((const Sint8*)msg);
}

// 100% matching!
void ADXT_ConfigVsyncSvr(Sint32 vsync_svr_flag)
{
    adxt_vsync_svr_flag = vsync_svr_flag;
}

// 100% matching! 
void ADXT_Finish(void) 
{
    adxt_init_cnt--;
    
    if (adxt_init_cnt == 0) 
    {
        ADXCRS_Lock();
        
        LSC_Finish();
        
        ADXCRS_Unlock();
        
        ADXRNA_Finish();
        
        ADXCRS_Lock();
        
        ADXF_Finish();
        ADXSJD_Finish();
        ADXSTM_Finish();
        ADXERR_Finish();
        SJMEM_Finish();
        SJRBF_Finish();
        SJUNI_Finish();
        
        ADXCRS_Unlock();
    }
}

// 100% matching! 
void ADXT_Init(void) 
{
    if (adxt_init_cnt == 0) 
    {
        ADXCRS_Init();
        
        ADXCRS_Lock();
        
        SJUNI_Init();
        SJRBF_Init();
        SJMEM_Init();
        ADXERR_Init();
        ADXSTM_Init();
        ADXSJD_Init();
        ADXF_Init();
        ADXRNA_Init();
        
        memset(adxt_obj, 0, sizeof(adxt_obj));
        
        LSC_Init();
        
        adxt_vsync_cnt = 0;
        
        ADXCRS_Unlock();
    }
    
    adxt_init_cnt++;
}

// 100% matching!
void ADXT_ResetLibrary(void)
{
    adxt_init_cnt = 0;
    
    ADXT_Init();
}

// 100% matching!
void ADXT_VsyncProc(void) 
{
    adxt_vsync_cnt++; 
    
    ADXT_ExecServer();
}
