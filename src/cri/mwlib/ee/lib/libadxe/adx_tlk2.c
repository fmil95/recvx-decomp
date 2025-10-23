#define BSWAP_S32(_val) (Sint32)(((Uint32)_val >> 24) | (_val << 24) | (((_val << 8) & 0xFF0000) | ((_val >> 8) & 0xFF00)))

void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_StartFname(ADXT adxt, Char8 *fname);
void ADXT_StartMem(ADXT adxt, void *adxdat);
void ADXT_StartMem2(ADXT adxt, void *adxdat, Sint32 datlen);
void ADXT_StartMemIdx(ADXT adxt, void *acx, Sint32 no);

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
        adxt->stm = ADXSTM_OpenFileRangeExRt((Sint8*)&fname, dir, ofst, fnsct, adxt->sjf);
        
        if (adxt->stm == NULL) 
        {
            ADXCRS_Unlock();
            
            ADXERR_ItoA2(patid, fid, (Sint8*)error, 16);
            ADXERR_CallErrFunc2("E8101202 ADXT_StartAfs: can't open ", (Sint8*)error);
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
    
    adxt->stm = ADXSTM_OpenFname((Sint8*)fname, adxt->sjf);
    
    if (adxt->stm == NULL) 
    {
        ADXCRS_Unlock();
        
        ADXERR_CallErrFunc2("E8101205 ADXT_StartFname: can't open ", (Sint8*)fname);
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

// 100% matching!
void ADXT_StartMemIdx(ADXT adxt, void *acx, Sint32 no)
{
    SJ sj;

    ADXT_Stop(adxt);
    
    if ((no < BSWAP_S32(((Sint32*)acx)[1])) && (no >= 0))
    {
        ADXCRS_Lock();
        
        sj = SJMEM_Create((Sint8*)acx + BSWAP_S32(((Sint32*)acx + (no * 2))[2]), ADXT_MAX_DATASIZE);
        
        if (sj == NULL) 
        {
            ADXCRS_Unlock();
            
            ADXERR_CallErrFunc1("E8101207: can't create sj (ADXT_StartMemIdx)");
        }
        else 
        {
            adxt_start_sj(adxt, sj);
            
            adxt->lnkflg = 0;
            
            adxt->pmode = ADXT_PMODE_MEM;
        }
        
        ADXCRS_Unlock();
    }
}
