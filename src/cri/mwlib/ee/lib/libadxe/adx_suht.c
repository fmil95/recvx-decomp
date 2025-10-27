

// 100% matching!
void adxt_err_host(Sint32 arg0, Char8* err_msg) 
{
    ADXERR_CallErrFunc1((const Sint8*)err_msg);
}

// 100% matching!
Sint32 ADXT_LoadFpCacheHost(ADXT_SPRM* sprm)
{
    Sint32 ret;

    ret = 0;
    
    if (sprm != NULL) 
    {
        ret = htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
    
    return ret;
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
    
    cvFsAddDev("HST", (void*)htCiGetInterface, NULL);
    
    cvFsSetDefDev("HST");
    
    if (sprm != NULL) 
    {
        htCiSetOpenMode(sprm->opmode);
        
        htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
}
