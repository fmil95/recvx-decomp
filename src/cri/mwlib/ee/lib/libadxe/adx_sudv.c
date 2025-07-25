void* D_00362958;

// 100% matching!
void adxt_err_dvd(Sint32 arg0, Char8* err_msg)
{
    ADXERR_CallErrFunc1(err_msg);
}

// ADXT_LoadFpCacheDvd

// 100% matching!
void ADXT_SetRdMode(ADXT_SPRM* sprm)
{
    dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
}

// 100% matching!
void ADXT_SetupDvdFs(ADXT_SPRM *sprm) 
{
    cvFsEntryErrFunc(adxt_err_dvd, 0);
    
    cvFsAddDev(&D_00362958, dvCiGetInterface, 0);
    
    cvFsSetDefDev(&D_00362958);
    
    if (sprm != NULL) 
    {
        dvCiLoadFpCache(sprm->fname, sprm->fpc, sprm->size);
        
        dvCiSetRdMode(sprm->nrtry, sprm->speed, sprm->dtype);
    }
}
