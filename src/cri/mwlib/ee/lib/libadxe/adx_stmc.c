
typedef void *ADXSTM;

typedef struct _adxstm_file 
{ 
	Sint8 used;
	Sint8 stat;
	Sint8 rdflg;
	Sint8 errcnt;
	SJ sj;
	CVFS fp;
	Sint32 stpos;
	Sint32 fofst;
	Sint32 fsize;
	Sint32 maxsize;
	Sint32 minsize;
	Sint32 reqsct;
	SJCK reqck;
	Sint32 rdsct;
	Sint32 esct;
	Sint32 tbyte;
	void (*eosfunc)();
	void *eosobj;
	Sint32 bsize;
	Sint8 pauseflg;
	Sint8 rsv;
	Sint16 rsv2;
} ADXSTM_FILE;
typedef ADXSTM_FILE *ADXSTMF;

Sint32 adxstmf_num_rtry;

void ADXSTMF_Destroy(ADXSTMF stmf);                      
void ADXSTM_Stop(ADXSTM stm);  

// 100% matching!
void ADXSTM_Close(ADXSTM stm) 
{
    ADXSTMF stmf;

    if (stm != NULL) 
    {
        ADXSTM_Stop(stm);
        
        stmf = stm;
        
        if (stmf->fp != NULL) 
        {
            cvFsClose(stmf->fp);
        }
        
        ADXSTMF_Destroy(stmf);
    }
}

// ADXSTM_EntryEosFunc

// 100% matching!
void ADXSTM_EntryErrFunc(void (*errfn)(), void *obj)
{

}

void ADXSTM_ExecServer(void)
{
    scePrintf("ADXSTM_ExecServer - UNIMPLEMENTED!\n");
}

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

Sint32 ADXSTM_GetFileLen(ADXSTM stm)
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

void ADXSTM_Init(void)
{
    scePrintf("ADXSTM_Init - UNIMPLEMENTED!\n");
}

// ADXSTM_OpenFileRange

ADXSTM ADXSTM_OpenFileRangeEx(Char8* fname, Sint32* dir, Sint32 ofst, Sint32 fnsct, Sint32 arg4)
{
    scePrintf("ADXSTM_OpenFileRangeEx - UNIMPLEMENTED!\n");
}

ADXSTM ADXSTM_OpenFileRangeExRt(Char8* fname, void** dir, Sint32 ofst, Sint32 fnsct, SJ sjf)
{
    scePrintf("ADXSTM_OpenFileRangeExRt - UNIMPLEMENTED!\n");
}

ADXSTM ADXSTM_OpenFname(Sint8 *fname, SJ sj)
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

void ADXSTM_Stop(ADXSTM stm)
{
    scePrintf("ADXSTM_Stop - UNIMPLEMENTED!\n");
}

// ADXSTM_Tell
// ADXSTMF_CreateCvfs
// ADXSTMF_CreateCvfsRt

void ADXSTMF_Destroy(ADXSTMF stmf)
{
    scePrintf("ADXSTMF_Destroy - UNIMPLEMENTED!\n");
}

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
