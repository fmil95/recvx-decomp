#include "adx_suht.h"

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
        size = htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
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
    cvFsEntryErrFunc(adxt_err_host, NULL);
    
    cvFsAddDev("HST", (void*)htCiGetInterface, NULL);
    
    cvFsSetDefDev("HST");
    
    if (sprm != NULL) 
    {
        htCiSetOpenMode(sprm->opmode);
        
        htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
}
