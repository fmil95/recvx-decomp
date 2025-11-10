#include "adx_tlk2.h"
#include "adx_crs.h"
#include "adx_errs.h"
#include "adx_fs.h"
#include "adx_stmc.h"
#include "adx_tlk.h"
#include "lsc.h"

Char8* volatile adxt_build = "\nADXT Ver.6.24 Build:Mar 14 2001 14:23:32\n";

// 100% matching! 
void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid)
{
    Sint32 ofst;
	Sint32 nsct;
	static Sint8 fname[256];
	void *dir;
	Sint8 msg[16];

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    if (ADXF_GetFnameRangeEx(patid, fid, (Char8*)fname, &dir, &ofst, &nsct) == 0) 
    {
        adxt->stm = ADXSTM_OpenFileRangeExRt(fname, dir, ofst, nsct, adxt->sjf);
        
        if (adxt->stm == NULL) 
        {
            ADXCRS_Unlock();
            
            ADXERR_ItoA2(patid, fid, msg, sizeof(msg));
            ADXERR_CallErrFunc2((const Sint8*)"E8101202 ADXT_StartAfs: can't open ", msg);
        } 
        else 
        {
            adxt_start_stm(adxt);
            
            adxt->lnkflg = 0;
        }
    }
    
    ADXCRS_Unlock();
}

// 100% matching!
void ADXT_StartFname(ADXT adxt, Char8 *fname)
{
    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    adxt->stm = ADXSTM_OpenFname((Sint8*)fname, adxt->sjf);
    
    if (adxt->stm == NULL) 
    {
        ADXCRS_Unlock();
        
        ADXERR_CallErrFunc2((const Sint8*)"E8101205 ADXT_StartFname: can't open ", (Sint8*)fname);
    } 
    else 
    {
        adxt_start_stm(adxt);
        
        adxt->lnkflg = 0;
    }
    
    ADXCRS_Unlock();
}

// 100% matching!
void ADXT_StartMem(ADXT adxt, void *adxdat)
{
    ADXT_StartMem2(adxt, adxdat, ADXT_MAX_DATASIZE);
}

// 100% matching!
void ADXT_StartMem2(ADXT adxt, void *adxdat, Sint32 datlen)
{
    SJ sj;

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    sj = SJMEM_Create(adxdat, datlen);
    
    if (sj == NULL) 
    {
        ADXCRS_Unlock();
        
        ADXERR_CallErrFunc1((const Sint8*)"E8101207: can't create sj (ADXT_StartMem)\n");
    } 
    else 
    {
        adxt_start_sj(adxt, sj);
        
        adxt->lnkflg = 0;
        
        adxt->pmode = ADXT_PMODE_MEM;
    }
    
    ADXCRS_Unlock();
}

// 100% matching!
void ADXT_StartMemIdx(ADXT adxt, void *acx, Sint32 no)
{
    SJ sj;

    ADXT_Stop(adxt);
    
    if ((no < BSWAP_S32(((Sint32*)acx)[1])) && (no >= 0)) // TODO: simplify this line when GCC is added
    {
        ADXCRS_Lock();
        
        sj = SJMEM_Create((Sint8*)acx + BSWAP_S32(((Sint32*)acx + (no * 2))[2]), ADXT_MAX_DATASIZE); // this one too
        
        if (sj == NULL) 
        {
            ADXCRS_Unlock();
            
            ADXERR_CallErrFunc1((const Sint8*)"E8101207: can't create sj (ADXT_StartMemIdx)");
        }
        else 
        {
            adxt_start_sj(adxt, sj);
            
            adxt->lnkflg = 0;
            
            adxt->pmode = ADXT_PMODE_MEM;
        }
        
        ADXCRS_Unlock();
    }
}
