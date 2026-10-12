#include "../../../cri/mwlib/ee/lib/libadxe/adx_sudv.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_errs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/cri_cvfs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/dvci.h"
#include "../../../cri/mwlib/ee/lib/libadxe/dvci_sub.h"

// 100% byte-matching object! 

void adxt_err_dvd(void *obj, const char *msg, void *hndl)
{
    ADXERR_CallErrFunc1((const Sint8*)msg);
}

void ADXT_SetupDvdFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc((void*)adxt_err_dvd, NULL);
    
    cvFsAddDev((Sint8*)"CDV", (void*)dvCiGetInterface, NULL);
    
    cvFsSetDefDev((Sint8*)"CDV");
    
    if (sprm != NULL) 
    {
        dvCiLoadFpCache((Sint8*)sprm->fname, (Sint8*)sprm->fpc, sprm->size);
        
        dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
    }
}

Sint32 ADXT_LoadFpCacheDvd(ADXT_SPRM *sprm)
{
    Sint32 size;

    size = 0;
    
    if (sprm != NULL) 
    {
        size = dvCiLoadFpCache((Sint8*)sprm->fname, (Sint8*)sprm->fpc, sprm->size);
    }
    
    return size;
}

void ADXT_SetRdMode(ADXT_SPRM *sprm)
{
    dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
}
