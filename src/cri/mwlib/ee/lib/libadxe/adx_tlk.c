Sint32 adxt_time_unit;
Sint32 adxt_time_mode;

// ADXT_ClearErrCode
// ADXT_CloseAllHandles

ADXT ADXT_Create(Sint32 maxnch, void *work, Sint32 worksize)
{
    scePrintf("ADXT_Create - UNIMPLEMENTED!\n");
}

void ADXT_Destroy(ADXT adxt)
{
    scePrintf("ADXT_Destroy - UNIMPLEMENTED!\n");
}

// ADXT_DestroyAll
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
// ADXT_IsCompleted
// ADXT_IsEndcode
// ADXT_IsHeader
// ADXT_IsIbufSafety
// ADXT_IsReadyPlayStart

void ADXT_SetAutoRcvr(ADXT adxt, Sint32 rmode)
{
    scePrintf("ADXT_SetAutoRcvr - UNIMPLEMENTED!\n");
}

// ADXT_SetLnkSw
// ADXT_SetLpFlg
// ADXT_SetOutPan

// 100% matching!
void ADXT_SetOutputMono(Sint32 flag)
{
    ADX_SetDecodeSteAsMonoSw(flag);
}

void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
    scePrintf("ADXT_SetOutVol - UNIMPLEMENTED!\n");
}

// ADXT_SetPauseBuf

void ADXT_SetReloadSct(ADXT adxt, Sint32 minsct)
{
    scePrintf("ADXT_SetReloadSct - UNIMPLEMENTED!\n");
}

// ADXT_SetReloadTime

void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq)
{
    scePrintf("ADXT_SetSvrFreq - UNIMPLEMENTED!\n");
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

// ADXT_SetTimeOfst
// ADXT_SetWaitPlayStart

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
