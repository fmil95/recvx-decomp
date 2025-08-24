void* D_00362958;

// 100% matching!
void adxt_err_dvd(Sint32 arg0, Char8* err_msg)
{
    ADXERR_CallErrFunc1(err_msg);
}

// 100% matching!
Sint32 ADXT_LoadFpCacheDvd(ADXT_SPRM* sprm)
{
    Sint32 ret;

    ret = 0;
    
    if (sprm != NULL) 
    {
        ret = dvCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
    }
    
    return ret;
}

// 100% matching!
void ADXT_SetRdMode(ADXT_SPRM* sprm)
{
    dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
}

// 100% matching!
void ADXT_SetupDvdFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc((void*)adxt_err_dvd, NULL);
    
    cvFsAddDev(&D_00362958, dvCiGetInterface, 0);
    
    cvFsSetDefDev(&D_00362958);
    
    if (sprm != NULL) 
    {
        dvCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
        
        dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
    }
}
