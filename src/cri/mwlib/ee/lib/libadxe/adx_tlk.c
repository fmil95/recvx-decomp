#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8))

Sint32 adxt_time_unit;
Sint32 adxt_time_mode;
Sint32 adxt_vsync_cnt;

void ADXT_StopWithoutLsc(ADXT adxt);

// 100% matching! 
void ADXT_ClearErrCode(ADXT adxt)
{
    adxt->ercode = 0;
    
    adxt->edecpos = 0;
    adxt->edeccnt = 0;
    
    adxt->eshrtcnt = 0;
}

// 100% matching! 
void ADXT_CloseAllHandles(void)
{
    ADXT_DestroyAll();
}

ADXT ADXT_Create(Sint32 maxnch, void *work, Sint32 worksize)
{
    scePrintf("ADXT_Create - UNIMPLEMENTED!\n");
}

void ADXT_Destroy(ADXT adxt)
{
    scePrintf("ADXT_Destroy - UNIMPLEMENTED!\n");
}

void ADXT_DestroyAll(void)
{
    scePrintf("ADXT_DestroyAll - UNIMPLEMENTED!\n");
}

// ADXT_DiscardSmpl
// adxt_disp_rna_stat
// ADXT_EntryErrFunc
// ADXT_EntryFltFunc
// ADXT_ExecServer

// 100% matching! 
Sint32 ADXT_GetDecNumSmpl(ADXT adxt)
{
    return ADXSJD_GetDecNumSmpl(adxt->sjd);
}

// 100% matching! 
Sint32 ADXT_GetErrCode(ADXT adxt)
{
    return adxt->ercode;
}

// 100% matching! 
Sint32 ADXT_GetFmtBps(ADXT adxt)
{
    if (adxt->stat >= ADXT_STAT_PREP) 
    {
        return ADXSJD_GetFmtBps(adxt->sjd);
    }
    
    return 0;
}

// 100% matching! 
Sint32 ADXT_GetHdrLen(ADXT adxt)
{
    if (adxt->stat >= ADXT_STAT_PREP)
    {
        return ADXSJD_GetHdrLen(adxt->sjd);
    }
    
    return 0;
}

// ADXT_GetIbufRemainTime

// 100% matching! 
SJ ADXT_GetInputSj(ADXT adxt)
{
    return adxt->sji;
}

// 100% matching! 
Sint32 ADXT_GetLnkSw(ADXT adxt)
{
    return adxt->lnkflg;
}

// 100% matching! 
Sint32 ADXT_GetLpCnt(ADXT adxt)
{
    return adxt->lpcnt;
}

// ADXT_GetNumChan
// ADXT_GetNumSctIbuf
// ADXT_GetNumSmpl
// ADXT_GetNumSmplObuf
// ADXT_GetOutPan
// ADXT_GetOutVol
// ADXT_GetSfreq

// 100% matching!
Sint32 ADXT_GetStat(ADXT adxt)
{
    return adxt->stat;
}

void ADXT_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale)
{
    scePrintf("ADXT_GetTime - UNIMPLEMENTED!\n");
}

// ADXT_GetTimeReal
// ADXT_GetTimeSfreq
// ADXT_GetTimeSfreq2
// ADXT_InsertSilence

// 100% matching! 
Sint32 ADXT_IsCompleted(ADXT adxt)
{
    return adxt->stat == ADXT_STAT_PLAYEND;
}

// 100% matching! 
Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz)
{
    if (siz <= 1) 
    {
        return 0;
    }

    if (BSWAP_U16(adr) != 0x8001) 
    {
        return 0;
    }

    *endsiz = siz;

    return 1;
}

// 100% matching! 
Sint32 ADXT_IsHeader(Sint8 *adr, Sint32 siz, Sint32 *hdrsiz)
{
    Sint16 unk0;
    Sint8 unk1;
    Sint8 unk2;
    Sint8 unk3;
    Sint8 unk4;
    Sint32 unk5;
    Sint32 unk6;    
    Sint32 unk7;

    if (siz < 2) 
    {
        return 0;
    }
    
    if (BSWAP_U16(adr) != 0x8000) 
    {
        return 0;
    }
    
    if (ADX_DecodeInfo(adr, siz, &unk0, &unk1, &unk2, &unk3, &unk4, &unk5, &unk6, &unk7) < 0) 
    {  
        return 0;
    }
   
    *hdrsiz = unk0;
    
    return 1;
}

// 100% matching! 
Sint32 ADXT_IsIbufSafety(ADXT adxt)
{
    if (adxt->sji != NULL) 
    {
        return adxt->sji->vtbl->GetNumData(adxt->sji, 1) >= (adxt->minsct * ADXF_DEF_SCT_SIZE);
    }
    
    return FALSE;
}

// 100% matching! 
Sint32 ADXT_IsReadyPlayStart(ADXT adxt)
{
    return adxt->pstready_flag;
}

// 100% matching!
void ADXT_SetAutoRcvr(ADXT adxt, Sint32 rmode)
{
    adxt->autorcvr = rmode;
}

// 100% matching!
void ADXT_SetLnkSw(ADXT adxt, Sint32 sw)
{
    adxt->lnkflg = sw;
}

// 100% matching!
void ADXT_SetLpFlg(ADXT adxt, Sint32 flg)
{
    adxt->lpflg = flg;
}

// 100% matching!
void ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan)
{
    adxt->outpan[ch] = pan;
    
    if (ch < adxt->maxnch) 
    {
        ADXRNA_SetOutPan(adxt->rna, ch, pan);
    }
    else 
    {
        ADXERR_CallErrFunc1("E8101208 ADXT_SetOutPan: parameter error");
    }
}

// 100% matching!
void ADXT_SetOutputMono(Sint32 flag)
{
    ADX_SetDecodeSteAsMonoSw(flag);
}

// 100% matching!
void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
    adxt->outvol = vol; 
    
    ADXRNA_SetOutVol(adxt->rna, vol);
}

// 100% matching!
Uint32 ADXT_SetPauseBuf(void) 
{
    return 16384;
}

// 100% matching! 
void ADXT_SetReloadSct(ADXT adxt, Sint32 minsct)
{
    adxt->minsct = minsct;
}

// 100% matching! 
void ADXT_SetReloadTime(ADXT adxt, float time, Sint32 nch, Sint32 sfreq)
{
    Sint32 ch;
    Sint32 sec;

    ch = nch * 18;
    
    sec = (((Sint32)(time * sfreq) / 32) * ch) / ADXF_DEF_SCT_SIZE;
    
    adxt->minsct = (sec < adxt->maxsct) ? sec : adxt->maxsct;
}

// 100% matching! 
void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq)
{
    adxt->svrfreq = freq;
}

// 100% matching! 
void ADXT_SetTimeMode(Sint32 mode)
{
    if (mode == 1) 
    {
        adxt_time_unit = 5994;
    }
    else if (mode == 2) 
    {
        adxt_time_unit = 5000;
    }
    
    adxt_time_mode = mode;
}

// 100% matching! 
void ADXT_SetTimeOfst(ADXT adxt, Sint32 ofst)
{
    adxt->time_ofst = ofst;
}

// 100% matching! 
void ADXT_SetWaitPlayStart(ADXT adxt, Sint32 flg)
{
    adxt->pstwait_flag = flg;
}

// 100% matching! 
void adxt_start_sj(ADXT adxt, SJ sj)
{
    Sint32 ch;

    for (ch = 0; ch < adxt->maxnch; ch++) 
    {
        adxt->sjo[ch]->vtbl->Reset(adxt->sjo[ch]);
    }

    ADXSJD_SetInSj(adxt->sjd, sj);
    
    adxt->sji = sj;
    
    ADXSJD_Start(adxt->sjd);
    
    adxt->stat = ADXF_STAT_STOP;
    
    adxt->lesct = 0x7FFFFFFF;
    
    adxt->trpnsmpl = -1;
    
    adxt->lpcnt = 0;
    
    adxt->pstready_flag = 0;
    
    adxt->tvofst = 0;
    
    adxt->svcnt = adxt_vsync_cnt;
}

// 100% matching! 
void adxt_start_stm(ADXT adxt) 
{
    ADXSTM_SetBufSize(adxt->stm, adxt->minsct * ADXF_DEF_SCT_SIZE, adxt->maxsct * ADXF_DEF_SCT_SIZE);
    ADXSTM_SetEos(adxt->stm, ADXT_PREP_RDSCT);
    
    ADXSTM_Start(adxt->stm);
    
    adxt_start_sj(adxt, adxt->sjf);
    
    adxt->pmode = ADXT_PMODE_FNAME;
}

// 100% matching! 
void ADXT_StartSj(ADXT adxt, SJ sj)
{
    Sint32 ch;

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();

    for (ch = 0; ch < adxt->maxnch; ch++) 
    {
        adxt->sjo[ch]->vtbl->Reset(adxt->sjo[ch]);
    }

    ADXSJD_SetInSj(adxt->sjd, sj);
    
    adxt->sji = sj;
    
    ADXSJD_Start(adxt->sjd);
    
    adxt->pmode = ADXT_PMODE_SJ;
    
    adxt->lpcnt = 0;
    
    adxt->tvofst = 0;
    
    adxt->stat = ADXT_STAT_DECINFO;
    
    adxt->lnkflg = 1;
    
    adxt->svcnt = adxt_vsync_cnt;
    
    ADXCRS_Unlock();
}

// 100% matching! 
void ADXT_Stop(ADXT adxt)
{
    if (adxt->pmode == ADXT_PMODE_SLFILE) 
    {
        LSC_Stop(adxt->lsc);
        
        if (adxt->sji != NULL) 
        {
            adxt->sji->vtbl->Reset(adxt->sji);
        }
    }
    
    ADXT_StopWithoutLsc(adxt);
}

void ADXT_StopWithoutLsc(ADXT adxt)
{
    scePrintf("ADXT_StopWithoutLsc - UNIMPLEMENTED!\n");
}
