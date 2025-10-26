static Sint32 adxt_dbg_nch;
static Sint32 adxt_dbg_ndt;

void adxt_RcvrReplay(ADXT adxt);
void adxt_stat_decend(ADXT adxt);                      
void adxt_stat_decinfo(ADXT adxt);                  
void adxt_stat_playend(ADXT adxt);               
void adxt_stat_playing(ADXT adxt);             
void adxt_stat_prep(ADXT adxt);  

// 100% matching!
void adxt_eos_entry(void *obj)
{
    ADXT adxt;
    ADXSTM stm;
	Sint32 lsofst;

    adxt = obj;
    
    stm = adxt->stm;

    lsofst = ADXSJD_GetLpStartOfst(adxt->sjd);
    
    if (adxt->lpflg == 0) 
    {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
        
        ADXSTM_SetEos(adxt->stm, 0x7FFFFFFF);
    } 
    else
    {
        ADXSTM_Seek(stm, lsofst / 2048);
    }
}

// 100% matching!
void ADXT_ExecErrChk(ADXT adxt)
{
    Sint32 stat;
	Sint32 pos;
	Sint32 ndata;
    
    stat = adxt->stat;
    
    if ((stat == ADXF_STAT_READEND) && (adxt->pause_flag == 0) && (ADXSJD_GetStat(adxt->sjd) != 3))
    {
        pos = ADXSJD_GetDecNumSmpl(adxt->sjd);
        
        if (adxt->edecpos == pos) 
        {
            if (++adxt->edeccnt > (adxt->svrfreq * 5)) 
            {
                adxt->ercode = ADXF_ERR_INTERNAL;
            }
        }
        else 
        {
            adxt->edeccnt = 0;
        }
        
        adxt->edecpos = pos;
        
        if (adxt->ercode != ADXF_ERR_OK) 
        {
            if ((adxt->autorcvr == ADXT_RMODE_STOP) || (adxt->autorcvr == ADXT_RMODE_REPLAY)) 
            {
                ADXT_Stop(adxt);
            }
            
            if (adxt->autorcvr != ADXT_RMODE_NOACT)
            {
                adxt->ercode = ADXF_ERR_OK;
                
                adxt->edeccnt = 0;
            }
        }
    }
    else
    {
        adxt->edeccnt = 0;
    }
    
    if (((stat == ADXF_STAT_STOP) || (stat == ADXF_STAT_READING) || (stat == ADXF_STAT_READEND)) && (adxt->pause_flag == 0) && (ADXSJD_GetStat(adxt->sjd) != 3))
    {
        ndata = (adxt->sji == NULL) ? 0 : SJ_GetNumData(adxt->sji, 1);
        
        if (ndata < 64) 
        {
            adxt->eshrtcnt++;
            
            if (stat == ADXF_STAT_READEND)
            {
                if (adxt->eshrtcnt > (adxt->svrfreq * 5)) 
                {
                    adxt->ercode = ADXF_ERR_FATAL;
                }
            } 
            else if (adxt->eshrtcnt > (adxt->svrfreq * 20)) 
            {
                adxt->ercode = ADXF_ERR_FATAL;
            }
            
            if (adxt->ercode != ADXF_ERR_OK) 
            {
                if (adxt->autorcvr == ADXT_RMODE_STOP) 
                {
                    ADXT_Stop(adxt);
                } 
                else if (adxt->autorcvr == ADXT_RMODE_REPLAY) 
                {
                    adxt_RcvrReplay(adxt);
                }
                
                if (adxt->autorcvr != ADXT_RMODE_NOACT)
                {
                    adxt->ercode = ADXF_ERR_OK;
                    
                    adxt->eshrtcnt = 0;
                }
            }
        } 
        else 
        {
            adxt->eshrtcnt = 0;
        }
    } 
    else 
    {
        adxt->eshrtcnt = 0;
    }
    
    if ((adxt->stm != NULL) && (ADXSTM_GetStat(adxt->stm) == 4)) 
    {
        if (adxt->autorcvr == ADXT_RMODE_STOP) 
        {
            ADXT_Stop(adxt);
        } 
        else if (adxt->autorcvr == ADXT_RMODE_REPLAY) 
        {
            adxt_RcvrReplay(adxt);
        }
        
        if (adxt->autorcvr != ADXT_RMODE_NOACT) 
        {
            adxt->ercode = ADXF_ERR_OK;
            
            adxt->eshrtcnt = 0;
        }
    }
}

// 100% matching!
void ADXT_ExecErrChkPS2(ADXT adxt)  
{
    if ((adxt->stm != NULL) && (ADXSTM_GetStat(adxt->stm) == 4)) 
    {
        adxt->ercode = ADXF_ERR_FATAL;
    }
}

// 100% matching!
void ADXT_ExecHndl(ADXT adxt)
{
    if (adxt->stat == ADXT_STAT_PLAYING) 
    {
        adxt_stat_playing(adxt);
    }
    else if (adxt->stat == ADXT_STAT_DECINFO) 
    {
        adxt_stat_decinfo(adxt);
    }
    else if (adxt->stat == ADXT_STAT_PREP) 
    {
        adxt_stat_prep(adxt);
    } 
    else if (adxt->stat == ADXT_STAT_DECEND) 
    {
        adxt_stat_decend(adxt);
    } 
    else if (adxt->stat == ADXT_STAT_PLAYEND)
    {
        adxt_stat_playend(adxt);
    }
    
    ADXT_ExecErrChkPS2(adxt);
}

// adxt_nlp_trap_entry

// 100% matching!
void adxt_RcvrReplay(ADXT adxt) 
{
    Sint32 i;

    ADXCRS_Lock();
    
    ADXRNA_SetTransSw(adxt->rna, 0);
    ADXRNA_SetPlaySw(adxt->rna, 0);
    
    ADXSJD_Stop(adxt->sjd);
    
    if (adxt->stm != NULL) 
    {
        ADXSTM_Stop(adxt->stm);
        
        SJ_Reset(adxt->sji);
    }

    for (i = 0; i < adxt->maxnch; i++)
    {
        SJ_Reset(adxt->sjo[i]);
    }
    
    if (adxt->stm != NULL) 
    {
        ADXSTM_Seek(adxt->stm, 0);
        
        ADXSTM_Start(adxt->stm);
    }
    
    adxt_start_sj(adxt, adxt->sji);
    
    ADXCRS_Unlock();
}

// 100% matching!
void adxt_set_outpan(ADXT adxt) 
{
    if (ADXSJD_GetNumChan(adxt->sjd) == 1) 
    {
        if (adxt->outpan[0] == -128)
        {
            ADXRNA_SetOutPan(adxt->rna, 0, 0);
            return;
        }
        
        ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
        return;
    }
    
    if (adxt->outpan[0] == -128)
    {
        ADXRNA_SetOutPan(adxt->rna, 0, -15);
    } 
    else 
    {
        ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
    }
    
    if (adxt->outpan[1] == -128) 
    {
        ADXRNA_SetOutPan(adxt->rna, 1, 15);
        return;
    }
    
    ADXRNA_SetOutPan(adxt->rna, 1, adxt->outpan[1]);
}

void adxt_stat_decend(ADXT adxt) 
{
    scePrintf("adxt_stat_decend - UNIMPLEMENTED!\n");
}

void adxt_stat_decinfo(ADXT adxt) 
{
    scePrintf("adxt_stat_decinfo - UNIMPLEMENTED!\n");
}

// 100% matching!
void adxt_stat_playend(ADXT adxt) 
{

}

// 100% matching!
void adxt_stat_playing(ADXT adxt) 
{
    Sint32 i;
    Sint32 nch;

    if (ADXSJD_GetStat(adxt->sjd) == 3) 
    {
        adxt_dbg_nch = nch = ADXSJD_GetNumChan(adxt->sjd);
    
        for (i = 0; i < nch; i++) 
        {
            adxt_dbg_ndt = SJ_GetNumData(adxt->sjo[i], 1);
    
            if ((adxt_dbg_ndt >= 64) && (ADXRNA_GetNumData(adxt->rna) <= 0)) 
            {
                break;
            }
        }
    
        if (i == nch) 
        {
            ADXRNA_SetTransSw(adxt->rna, 0);
            
            adxt->stat = ADXT_STAT_DECEND;
        }
    }
}

void adxt_stat_prep(ADXT adxt) 
{
    scePrintf("adxt_stat_prep - UNIMPLEMENTED!\n");
}

// adxt_trap_entry
