#include "../../../cri/mwlib/ee/lib/libadxe/adx_suht.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_errs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/cri_cvfs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/htci.h"
#include "../../../cri/mwlib/ee/lib/libadxe/htci_sub.h"

// 100% byte-matching object! 

void adxt_err_host(void *obj, const char *msg, void *hndl)
{
    ADXERR_CallErrFunc1((const Sint8*)msg);
}

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

void ADXT_SetOpMode(ADXT_SPRM *sprm) 
{
    htCiSetOpenMode(sprm->opmode);
}
