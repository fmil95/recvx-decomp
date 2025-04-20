Sint32 adxstmf_num_rtry;

// ADXSTM_Close
// ADXSTM_EntryEosFunc
// ADXSTM_EntryErrFunc
// ADXSTM_ExecServer
// ADXSTM_Finish
// ADXSTM_GetBufSize

Sint32 ADXSTM_GetCurOfst(ADXSTM adxstm, Sint32* arg1)
{
    scePrintf("ADXSTM_GetCurOfst - UNIMPLEMENTED!\n");
}

// ADXSTM_GetCvdfsStat
// ADXSTM_GetFad
// ADXSTM_GetFileLen
// ADXSTM_GetFsizeByte
// ADXSTM_GetFsizeSct
// ADXSTM_GetSj
// ADXSTM_GetStat
// ADXSTM_Init
// ADXSTM_OpenFileRange
// ADXSTM_OpenFileRangeEx
// ADXSTM_OpenFileRangeExRt
// ADXSTM_OpenFname
// ADXSTM_OpenFnameEx
// ADXSTM_Reset
// ADXSTM_Seek
// ADXSTM_SetBufSize
// ADXSTM_SetEos
// ADXSTM_SetOfst
// ADXSTM_SetRdSct
// ADXSTM_SetReqRdSize
// ADXSTM_SetSj
// adxstm_sj_internal_error
// ADXSTM_Start

void ADXSTM_Stop(ADXSTM adxstm)
{
    scePrintf("ADXSTM_Stop - UNIMPLEMENTED!\n");
}

// ADXSTM_Tell
// ADXSTMF_CreateCvfs
// ADXSTMF_CreateCvfsRt
// ADXSTMF_Destroy
// ADXSTMF_ExecHndl
// ADXSTMF_SetupHandleMember
// adxstmf_stat_exec

// 100% matching!
void ADXT_SetNumRetry(Sint32 num) 
{
    adxstmf_num_rtry = num;
}

// ADXT_SetupNrmlNumStm
// ADXT_SetupRtimeNumStm
