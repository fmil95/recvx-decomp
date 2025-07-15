

// 100% matching! 
void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid)
{
    static Char8 fname;
    Char8 error[16];
    void* dir;
    Sint32 ofst;
    Sint32 fnsct;

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    if (ADXF_GetFnameRangeEx(patid, fid, &fname, &dir, &ofst, &fnsct) == 0) 
    {
        adxt->stm = ADXSTM_OpenFileRangeExRt(&fname, dir, ofst, fnsct, adxt->sjf);
        
        if (adxt->stm == NULL) 
        {
            ADXCRS_Unlock();
            
            ADXERR_ItoA2(patid, fid, error, 16);
            ADXERR_CallErrFunc2("E8101202 ADXT_StartAfs: can't open ", error);
        } 
        else 
        {
            adxt_start_stm(adxt);
            
            adxt->lnkflg = 0;
        }
    }
    
    ADXCRS_Unlock();
}

// 100% matching!
void ADXT_StartFname(ADXT adxt, Char8 *fname)
{
    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    adxt->stm = ADXSTM_OpenFname(fname, adxt->sjf);
    
    if (adxt->stm == NULL) 
    {
        ADXCRS_Unlock();
        
        ADXERR_CallErrFunc2("E8101205 ADXT_StartFname: can't open ", fname);
    } 
    else 
    {
        adxt_start_stm(adxt);
        
        adxt->lnkflg = 0;
    }
    
    ADXCRS_Unlock();
}

// 100% matching!
void ADXT_StartMem(ADXT adxt, void *adxdat)
{
    ADXT_StartMem2(adxt, adxdat, ADXT_MAX_DATASIZE);
}

// 100% matching!
void ADXT_StartMem2(ADXT adxt, void *adxdat, Sint32 datlen)
{
    SJ sj;

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();
    
    sj = SJMEM_Create(adxdat, datlen);
    
    if (sj == NULL) 
    {
        ADXCRS_Unlock();
        
        ADXERR_CallErrFunc1("E8101207: can't create sj (ADXT_StartMem)\n");
    } 
    else 
    {
        adxt_start_sj(adxt, sj);
        
        adxt->lnkflg = 0;
        
        adxt->pmode = ADXT_PMODE_MEM;
    }
    
    ADXCRS_Unlock();
}

// ADXT_StartMemIdx
