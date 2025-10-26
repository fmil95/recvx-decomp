static Sint32 adxt_dbg_rna_ndata;
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

// 100% matching!
void adxt_nlp_trap_entry(void *obj)
{
    ADXT adxt;
	ADXSJD sjd;
	SJ sji;
	SJCK ck;
	SJCK ck2;
	SJCK ck3;
	SJCK ck4;
	Sint32 ret;
	Sint32 ret2;
	Sint32 pos;
	Sint16 dlen;
	Sint16 dlen2;
    short temp, temp2;

    adxt = obj;
    
    sjd = adxt->sjd;
    sji = adxt->sji;

    if (adxt->lnkflg != 0)
    {
        temp2 = temp = 0;
        
        SJ_GetChunk(sji, 1, SJCK_LEN_MAX, &ck);
        SJ_GetChunk(sji, 1, SJCK_LEN_MAX, &ck3);
        
        if (ADX_DecodeFooter(ck.data + temp2, ck.len - temp2, &dlen) != 0)
        {
            adxt->lnkflg = 0;
            
            SJ_UngetChunk(sji, 1, &ck3);
            SJ_UngetChunk(sji, 1, &ck);
            return;
        }
    
        temp += dlen;
        
        ret = ADX_ScanInfoCode(ck.data + temp, ck.len - temp, &dlen);
        
        if (ret == 0) 
        {
            ret2 = -1;
        } 
        else 
        {
            ret2 = ADX_ScanInfoCode(ck3.data, ck3.len, &dlen2);
        }
    
        temp += dlen;
        
        temp2 = dlen2;
        
        if ((ret != 0) && (ret2 != 0)) 
        {
            SJ_UngetChunk(sji, 1, &ck3);
            SJ_UngetChunk(sji, 1, &ck);
            
            adxt->lnkflg = 0;
            return;
        }
        else if (ret == 0) 
        {
            SJ_UngetChunk(sji, 1, &ck3);
            
            SJ_SplitChunk(&ck, temp, &ck, &ck2);
            
            SJ_PutChunk(sji, 0, &ck);
            
            SJ_UngetChunk(sji, 1, &ck2);
        }
        else 
        {
            SJ_PutChunk(sji, 0, &ck);
            
            SJ_SplitChunk(&ck3, temp2, &ck3, &ck4);
            
            SJ_PutChunk(sji, 0, &ck3);
            
            SJ_UngetChunk(sji, 1, &ck4);
        }
        
        ADXSJD_Stop(sjd);
        
        ADXSJD_Start(sjd);
        
        ADXSJD_ExecHndl(sjd);
        
        if (ADXSJD_GetStat(sjd) != 2) 
        {
           adxt->lnkflg = 0;
        } 
        else 
        {
            ADXSJD_SetMaxDecSmpl(sjd, adxt->maxdecsmpl);
            ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
            ADXSJD_SetTrapDtLen(sjd, 0);
            ADXSJD_SetTrapCnt(sjd, 0);
        }
    }
}

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
        if (adxt->outpan[0] == ADXT_PAN_AUTO)
        {
            ADXRNA_SetOutPan(adxt->rna, 0, ADXT_PAN_CENTER);
            return;
        }
        
        ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
        return;
    }
    
    if (adxt->outpan[0] == ADXT_PAN_AUTO)
    {
        ADXRNA_SetOutPan(adxt->rna, 0, ADXT_PAN_LEFT);
    } 
    else 
    {
        ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
    }
    
    if (adxt->outpan[1] == ADXT_PAN_AUTO) 
    {
        ADXRNA_SetOutPan(adxt->rna, 1, ADXT_PAN_RIGHT);
        return;
    }
    
    ADXRNA_SetOutPan(adxt->rna, 1, adxt->outpan[1]);
}

// 100% matching!
void adxt_stat_decend(ADXT adxt)
{
    adxt_dbg_rna_ndata = ADXRNA_GetNumData(adxt->rna);
    
    if (ADXRNA_GetNumData(adxt->rna) <= 0) 
    {
        ADXRNA_SetPlaySw(adxt->rna, 0);
        
        adxt->stat = ADXT_STAT_PLAYEND;
    }
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

// 100% matching!
void adxt_stat_prep(ADXT adxt) 
{
    ADXRNA rna;
	Sint32 npoolsmpl;
	Sint32 nroomsmpl;
	ADXSJD sjd;
	Sint32 nch;
	Sint32 i;
	Sint32 nbyte;
	SJ sj;
	SJCK ck;
    
    rna = adxt->rna;
    sjd = adxt->sjd;

    npoolsmpl = ADXRNA_GetNumData(rna);
    nroomsmpl = ADXRNA_GetNumRoom(rna);

    if ((npoolsmpl >= (adxt->maxdecsmpl * 2)) || (ADXSJD_GetBlkSmpl(sjd) >= nroomsmpl) || (ADXSJD_GetStat(adxt->sjd) == 3))
    {
        if (adxt->pstwait_flag == 0)
        {
            if (adxt->pause_flag == 0) 
            {
                ADXRNA_SetPlaySw(rna, 1);
                
                adxt->tvofst = 0;
                
                adxt->svcnt = adxt_vsync_cnt;
            }

            adxt->stat = ADXF_STAT_READEND;
        }

        adxt->pstready_flag = 1;
    }

    if (ADXSJD_GetStat(adxt->sjd) == 3) 
    {
        nch = ADXT_GetNumChan(adxt);
        
        nbyte = (adxt->maxdecsmpl * nch) * 2;
    
        for (i = 0; i < nch; i++) 
        {
            sj = adxt->sjo[i];
            
            SJ_GetChunk(sj, 0, nbyte, &ck);
            
            memset(ck.data, 0, ck.len);
            
            SJ_PutChunk(sj, 1, &ck);
        }
    }
}

// 100% matching!
void adxt_trap_entry(void *obj)
{
    ADXT adxt;
	ADXSJD sjd;
	SJ sji;
	Sint32 lspos;
	Sint32 lsofst;
	Sint32 lepos;
	SJCK ck;
    
    adxt = obj;

    sjd = adxt->sjd;
    sji = adxt->sji;
    
    lspos = ADXSJD_GetLpStartPos(sjd);
    lsofst = ADXSJD_GetLpStartOfst(sjd);
    lepos = ADXSJD_GetLpEndPos(sjd);
    
    if ((adxt->stm == NULL) && (adxt->lpflg == 0)) 
    {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
    }
    else
    {
        SJ_GetChunk(sji, 1, adxt->lp_skiplen, &ck);
        
        if (ck.len < adxt->lp_skiplen)
        {
            ADXERR_CallErrFunc1((const Sint8*)"E8101201 adxt_trap_entry: not enough data");
        }
        
        SJ_PutChunk(sji, 0, &ck);
        
        ADXSJD_SetTrapCnt(sjd, 0);
        
        adxt->trpnsmpl = lepos - lspos;
        
        ADXSJD_SetTrapNumSmpl(sjd, adxt->trpnsmpl);
        ADXSJD_SetTrapDtLen(sjd, lsofst);
        ADXSJD_SetDecPos(sjd, lspos);
        
        if (adxt->pmode == ADXT_PMODE_MEM) 
        {
            SJ_Reset(sji);
            
            SJ_GetChunk(sji, 1, lsofst, &ck);
            
            SJ_PutChunk(sji, 0, &ck);
        }
        
        adxt->lpcnt++;
    }
}
