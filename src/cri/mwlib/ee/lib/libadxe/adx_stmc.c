Sint32 adxstmf_num_rtry;

void ADXSTM_Close(ADXSTM adxstm)
{
    scePrintf("ADXSTM_Close - UNIMPLEMENTED!\n");
}

// ADXSTM_EntryEosFunc
// ADXSTM_EntryErrFunc
// ADXSTM_ExecServer

void ADXSTM_Finish(void)
{
    scePrintf("ADXSTM_Finish - UNIMPLEMENTED!\n");
}

// ADXSTM_GetBufSize

Sint32 ADXSTM_GetCurOfst(ADXSTM adxstm, Sint32* nsct)
{
    scePrintf("ADXSTM_GetCurOfst - UNIMPLEMENTED!\n");
}

// ADXSTM_GetCvdfsStat
// ADXSTM_GetFad

Sint32 ADXSTM_GetFileLen(Sint32 fid)
{
    scePrintf("ADXSTM_GetFileLen - UNIMPLEMENTED!\n");
}

// ADXSTM_GetFsizeByte
// ADXSTM_GetFsizeSct
// ADXSTM_GetSj

Sint8 ADXSTM_GetStat(ADXSTM adxstm)
{
    scePrintf("ADXSTM_GetStat - UNIMPLEMENTED!\n");
}

// ADXSTM_Init
// ADXSTM_OpenFileRange

ADXSTM ADXSTM_OpenFileRangeEx(Char8* fname, Sint32* dir, Sint32 ofst, Sint32 fnsct, Sint32 arg4)
{
    scePrintf("ADXSTM_OpenFileRangeEx - UNIMPLEMENTED!\n");
}

ADXSTM ADXSTM_OpenFileRangeExRt(Char8* fname, void** dir, Sint32 ofst, Sint32 fnsct, SJ sjf)
{
    scePrintf("ADXSTM_OpenFileRangeExRt - UNIMPLEMENTED!\n");
}

ADXSTM ADXSTM_OpenFname(Char8* fname, SJ sjf)
{
    scePrintf("ADXSTM_OpenFname - UNIMPLEMENTED!\n");
}

Sint32 ADXSTM_OpenFnameEx(Char8* fname, void* atr, Sint32 arg2)
{
    scePrintf("ADXSTM_OpenFnameEx - UNIMPLEMENTED!\n");
}

// ADXSTM_Reset
// ADXSTM_Seek

void ADXSTM_SetBufSize(ADXSTM adxstm, Sint32 minsct, Sint32 maxsct)
{
    scePrintf("ADXSTM_SetBufSize - UNIMPLEMENTED!\n");
}

void ADXSTM_SetEos(ADXSTM adxstm, Sint32 nsct)
{
    scePrintf("ADXSTM_SetEos - UNIMPLEMENTED!\n");
}

void ADXSTM_SetOfst(ADXSTM adxstm, Sint32 ofst)
{
    scePrintf("ADXSTM_SetOfst - UNIMPLEMENTED!\n");
}

void ADXSTM_SetRdSct(ADXSTM adxstm, Sint32 rqsct)
{
    scePrintf("ADXSTM_SetRdSct - UNIMPLEMENTED!\n");
}

void ADXSTM_SetReqRdSize(ADXSTM adxstm, Sint32 rqrdsct)
{
    scePrintf("ADXSTM_SetReqRdSize - UNIMPLEMENTED!\n");
}

void ADXSTM_SetSj(ADXSTM adxstm, SJ sj)
{
    scePrintf("ADXSTM_SetSj - UNIMPLEMENTED!\n");
}

// adxstm_sj_internal_error

void ADXSTM_Start(ADXSTM adxstm)
{
    scePrintf("ADXSTM_Start - UNIMPLEMENTED!\n");
}

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
