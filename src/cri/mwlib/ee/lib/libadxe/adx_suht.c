#include "adx_suht.h"
#include "adx_errs.h"
#include "cri_cvfs.h"
#include "htci.h"
#include "htci_sub.h"

// 100% matching!
void adxt_err_host(void *obj, const char *msg, void *hndl)
{
    ADXERR_CallErrFunc1((const Sint8*)msg);
}

// 100% matching!
Sint32 ADXT_LoadFpCacheHost(ADXT_SPRM *sprm)
{
    Sint32 size;

    size = 0;
    
    if (sprm != NULL) 
    {
        size = htCiLoadFpCache((Sint8*)sprm->fname, (Sint8*)sprm->fpc, sprm->size);
    }
    
    return size;
}

// 100% matching!
void ADXT_SetOpMode(ADXT_SPRM *sprm) 
{
    htCiSetOpenMode(sprm->opmode);
}

// 100% matching!
void ADXT_SetupHostFs(ADXT_SPRM *sprm)
{
    cvFsEntryErrFunc((void*)adxt_err_host, NULL);
    
    cvFsAddDev((Sint8*)"HST", (void*)htCiGetInterface, NULL);
    
    cvFsSetDefDev((Sint8*)"HST");
    
    if (sprm != NULL) 
    {
        htCiSetOpenMode(sprm->opmode);
        
        htCiLoadFpCache((Sint8*)sprm->fname, (Sint8*)sprm->fpc, sprm->size);
    }
}
