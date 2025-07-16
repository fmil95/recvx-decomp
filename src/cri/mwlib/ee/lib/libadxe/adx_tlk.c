Sint32 adxt_time_unit;
Sint32 adxt_time_mode;

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
// ADXT_GetDecNumSmpl
// ADXT_GetErrCode
// ADXT_GetFmtBps
// ADXT_GetHdrLen
// ADXT_GetIbufRemainTime
// ADXT_GetInputSj
// ADXT_GetLnkSw
// ADXT_GetLpCnt
// ADXT_GetNumChan
// ADXT_GetNumSctIbuf
// ADXT_GetNumSmpl
// ADXT_GetNumSmplObuf
// ADXT_GetOutPan
// ADXT_GetOutVol
// ADXT_GetSfreq

Sint32 ADXT_GetStat(ADXT adxt)
{
    scePrintf("ADXT_GetStat - UNIMPLEMENTED!\n");
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

// ADXT_IsEndcode
// ADXT_IsHeader
// ADXT_IsIbufSafety
// ADXT_IsReadyPlayStart

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

void adxt_start_sj(ADXT adxt, SJ sj)
{
    scePrintf("adxt_start_sj - UNIMPLEMENTED!\n");
}

void adxt_start_stm(ADXT adxt)
{
    scePrintf("adxt_start_stm - UNIMPLEMENTED!\n");
}

// ADXT_StartSj

void ADXT_Stop(ADXT adxt)
{
    scePrintf("ADXT_Stop - UNIMPLEMENTED!\n");
}

// ADXT_StopWithoutLsc
