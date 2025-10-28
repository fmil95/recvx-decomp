#include "adx_sudv.h"

// 100% matching!
void adxt_err_dvd(void *obj, const char *msg, void *hndl)
{
    ADXERR_CallErrFunc1((const Sint8*)msg);
}

// 100% matching!
Sint32 ADXT_LoadFpCacheDvd(ADXT_SPRM *sprm)
{
    Sint32 size;

    size = 0;
    
    if (sprm != NULL) 
    {
        size = dvCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
    
    return size;
}

// 100% matching!
void ADXT_SetRdMode(ADXT_SPRM *sprm)
{
    dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
}

// 100% matching!
void ADXT_SetupDvdFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc(adxt_err_dvd, NULL);
    
    cvFsAddDev("CDV", (void*)dvCiGetInterface, NULL);
    
    cvFsSetDefDev("CDV");
    
    if (sprm != NULL) 
    {
        dvCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
        
        dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
    }
}
