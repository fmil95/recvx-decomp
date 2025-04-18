Sint32 D_00362960;
Sint32 adxt_err_host;

// adxt_err_host
// ADXT_LoadFpCacheHost
// ADXT_SetOpMode

// 100% matching!
void ADXT_SetupHostFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc(&adxt_err_host, 0);
    
    cvFsAddDev(&D_00362960, htCiGetInterface, 0);
    
    cvFsSetDefDev(&D_00362960);
    
    if (sprm != NULL) 
    {
        htCiSetOpenMode(sprm->opmode);
        
        htCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
}
