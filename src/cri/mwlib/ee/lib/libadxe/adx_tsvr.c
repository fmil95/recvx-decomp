static Sint32 adxt_dbg_nch;
static Sint32 adxt_dbg_ndt;

void adxt_stat_decend(ADXT adxt);                      
void adxt_stat_decinfo(ADXT adxt);                  
void adxt_stat_playend(ADXT adxt);               
void adxt_stat_playing(ADXT adxt);             
void adxt_stat_prep(ADXT adxt);  

// adxt_eos_entry
// ADXT_ExecErrChk

void ADXT_ExecErrChkPS2(ADXT adxt) 
{
    scePrintf("ADXT_ExecErrChkPS2 - UNIMPLEMENTED!\n");
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
// adxt_RcvrReplay
// adxt_set_outpan

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
