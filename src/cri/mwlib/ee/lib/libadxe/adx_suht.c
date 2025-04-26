void* D_00362960;

// 100% matching!
void adxt_err_host(Sint32 arg0, Char8* err_msg) 
{
    ADXERR_CallErrFunc1(err_msg);
}

// ADXT_LoadFpCacheHost
// ADXT_SetOpMode

// 100% matching!
void ADXT_SetupHostFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc(adxt_err_host, 0);
    
    cvFsAddDev(&D_00362960, htCiGetInterface, 0);
    
    cvFsSetDefDev(&D_00362960);
    
    if (sprm != NULL) 
    {
        htCiSetOpenMode(sprm->opmode);
        
        htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
}
