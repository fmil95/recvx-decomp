
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
	/* these fields are likely not present in this version
    Sint32 bsize;
	Sint8 pauseflg;
	Sint8 rsv;
	Sint16 rsv2; */
} ADXSTM_FILE;
typedef ADXSTM_FILE *ADXSTMF;

static ADXSTM_FILE adxstmf_obj[40] = { 0 };
static Sint32 adxstm_sj_internal_error_cnt;
Sint32 adxstmf_num_rtry;

void ADXSTMF_Destroy(ADXSTMF stmf);                      
void ADXSTM_Stop(ADXSTM stm);  
ADXSTM ADXSTM_OpenFileRangeEx(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj);
ADXSTM ADXSTM_OpenFileRangeExRt(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj);
ADXSTMF ADXSTMF_CreateCvfs(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj);
ADXSTMF ADXSTMF_CreateCvfsRt(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj);
void ADXSTMF_ExecHndl(ADXSTMF stmf);

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

// 100% matching!
void ADXSTM_EntryEosFunc(ADXSTM stm, void (*fn)(), void *obj)
{
    ADXSTMF stmf;

    stmf = stm;

    stmf->eosfunc = fn;
    stmf->eosobj = obj;
}

// 100% matching!
void ADXSTM_EntryErrFunc(void (*errfn)(), void *obj)
{

}

// 100% matching!
void ADXSTM_ExecServer(void)
{
    ADXSTMF stmf;
    Sint32 no;

    for (no = 0; no < 40; no++)
    {
        stmf = &adxstmf_obj[no];
        
        if (stmf->used == TRUE) 
        {
            ADXSTMF_ExecHndl(stmf);
        }
    }
}

// 100% matching!
void ADXSTM_Finish(void)
{
    cvFsFinish();
}

// 100% matching!
Sint32 ADXSTM_GetBufSize(ADXSTM stm, Sint32 *min, Sint32 *max) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    *min = stmf->minsize;
    *max = stmf->maxsize;
    
    return 1;
}

// 100% matching!
Sint32 ADXSTM_GetCurOfst(ADXSTM stm, Sint32 *ofst)
{
    ADXSTMF stmf;

    stmf = stm;
    
    *ofst = ADXSTM_Tell(stm) - stmf->stpos;
    
    return 1;
}

// 100% matching!
void ADXSTM_GetCvdfsStat(ADXSTM stm, Sint32 *cvfsst) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    *cvfsst = cvFsGetStat(stmf->fp);
}

// 100% matching!
Sint32 ADXSTM_GetFad(const Sint8 *fname, Sint32 *fad)
{
    *fad = 0;
    
    return 1;
}

// 100% matching!
Sint32 ADXSTM_GetFileLen(ADXSTM stm)
{
    ADXSTMF stmf;

    stmf = stm;
    
    return stmf->fsize;
}

// 100% matching!
Sint32 ADXSTM_GetFsizeByte(const Sint8 *fname, Sint32 *fsize) 
{
    *fsize = cvFsGetFileSize(fname);
    
    return 1;
}

// 100% matching!
Sint32 ADXSTM_GetFsizeSct(const Sint8 *fname, Sint32 *fnsct) 
{
    Sint32 fsize;

    fsize = cvFsGetFileSize(fname);
    
    *fnsct = (fsize + 2047) / 2048;
    
    return 1;
}

// 100% matching!
SJ ADXSTM_GetSj(ADXSTM stm) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    return stmf->sj;
}

// 100% matching!
Sint32 ADXSTM_GetStat(ADXSTM stm) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    return stmf->stat;
}

// 100% matching!
Sint32 ADXSTM_Init(void)
{
    memset(adxstmf_obj, 0, sizeof(adxstmf_obj));
    
    return 1;
}

// 100% matching!
ADXSTM ADXSTM_OpenFileRange(const Sint8 *fname, Sint32 ofst, Sint32 nsct, SJ sj)
{
    return ADXSTM_OpenFileRangeExRt(fname, NULL, ofst, nsct, sj);
}

// 100% matching!
ADXSTM ADXSTM_OpenFileRangeEx(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj)
{
    ADXSTMF stmf;
	CVFS fp;

    fp = cvFsOpen(fname, dir, CVE_FS_OP_READ);
    
    if (fp == NULL) 
    {
        ADXERR_CallErrFunc2("E0041206 ADXSTM_OpenFnameRang: can't open ", fname);
        
        return NULL;
    }
    
    stmf = ADXSTMF_CreateCvfs(fp, ofst, nsct * 2048, sj);
    
    if (stmf != NULL)
    {
        ADXSTM_Seek(stmf, 0);
    }
    
    return stmf;
}

// 100% matching!
ADXSTM ADXSTM_OpenFileRangeExRt(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj)
{
    ADXSTMF stmf;
	CVFS fp;

    fp = cvFsOpen(fname, dir, CVE_FS_OP_READ);
    
    if (fp == NULL) 
    {
        ADXERR_CallErrFunc2("E00041205 ADXSTM_OpenFnameRangeExRt: can't open ", fname);
        
        return NULL;
    }
    
    stmf = ADXSTMF_CreateCvfsRt(fp, ofst, nsct * 2048, sj);
    
    if (stmf != NULL)
    {
        ADXSTM_Seek(stmf, 0);
    }
    
    return stmf;
}

// 100% matching!
ADXSTM ADXSTM_OpenFname(const Sint8 *fname, SJ sj)
{
    Sint32 fsize;
    ADXSTMF stmf;
	CVFS fp;

    fsize = cvFsGetFileSize(fname);

    fp = cvFsOpen(fname, NULL, CVE_FS_OP_READ);
    
    if (fp == NULL) 
    {
        ADXERR_CallErrFunc2("E00041205 ADXSTM_OpenFnameEx: can't open ", fname);
        
        return NULL;
    }
    
    stmf = ADXSTMF_CreateCvfsRt(fp, 0, fsize, sj);
    
    if (stmf != NULL)
    {
        ADXSTM_Seek(stmf, 0);
    }
    
    return stmf;
}

// 100% matching!
ADXSTM ADXSTM_OpenFnameEx(const Sint8 *fname, void *dir, SJ sj)
{
    Sint32 fsize;
    ADXSTMF stmf;
	CVFS fp;

    if (dir != NULL) 
    {
        ADXERR_CallErrFunc1("E0062201 ADXSTM_OpenFname: can't specify dir");
        
        return NULL;
    }

    fsize = cvFsGetFileSize(fname);

    fp = cvFsOpen(fname, NULL, CVE_FS_OP_READ);
    
    if (fp == NULL) 
    {
        ADXERR_CallErrFunc2("E00041205 ADXSTM_OpenFnameEx: can't open ", fname);
        
        return NULL;
    }
    
    stmf = ADXSTMF_CreateCvfs(fp, 0, fsize, sj);
    
    if (stmf != NULL)
    {
        ADXSTM_Seek(stmf, 0);
    }
    
    return stmf;
}

// 100% matching!
void ADXSTM_Reset(void) 
{

}

// 100% matching!
Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 ofst) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    cvFsSeek(stmf->fp, stmf->fofst + ofst, CVE_FS_SK_SET);
    
    return cvFsTell(stmf->fp) - stmf->fofst;
}

// 100% matching!
Sint32 ADXSTM_SetBufSize(ADXSTM stm, Sint32 min, Sint32 max)
{
    ADXSTMF stmf;

    stmf = stm;
    
    stmf->minsize = min;
    stmf->maxsize = max;
    
    return 1;
}

// 100% matching!
void ADXSTM_SetEos(ADXSTM stm, Sint32 esct)
{
    ADXSTMF stmf;

    stmf = stm;

    if (esct >= 0)
    {
        stmf->esct = esct;
    }
    else 
    {
        stmf->esct = (stmf->fsize + 2047) / 2048;
    }
}

// 100% matching!
void ADXSTM_SetOfst(ADXSTM stm, Sint32 ofst) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    stmf->fofst = ofst;
    
    ADXSTM_Seek(stm, 0);
}

// 100% matching!
void ADXSTM_SetRdSct(ADXSTM stm, Sint32 nsct) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    stmf->fsize = nsct * 2048;
}

// 100% matching!
Sint32 ADXSTM_SetReqRdSize(ADXSTM stm, Sint32 sct) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    stmf->rdsct = sct;
    
    return 1;
}

// 100% matching!
void ADXSTM_SetSj(ADXSTM stm, SJ sj)
{
    ADXSTMF stmf;

    stmf = stm;
    
    stmf->sj = sj;
    
    stmf->minsize = stmf->maxsize = SJ_GetNumData(sj, 0);
}

// 100% matching!
void adxstm_sj_internal_error(void) 
{
    adxstm_sj_internal_error_cnt++;
}

void ADXSTM_Start(ADXSTM adxstm)
{
    scePrintf("ADXSTM_Start - UNIMPLEMENTED!\n");
}

void ADXSTM_Stop(ADXSTM stm)
{
    scePrintf("ADXSTM_Stop - UNIMPLEMENTED!\n");
}

Sint32 ADXSTM_Tell(ADXSTM stm)
{
    scePrintf("ADXSTM_Tell - UNIMPLEMENTED!\n");
}

ADXSTMF ADXSTMF_CreateCvfs(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj)
{
    scePrintf("ADXSTMF_CreateCvfs - UNIMPLEMENTED!\n");
}

ADXSTMF ADXSTMF_CreateCvfsRt(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj)
{
    scePrintf("ADXSTMF_CreateCvfsRt - UNIMPLEMENTED!\n");
}

void ADXSTMF_Destroy(ADXSTMF stmf)
{
    scePrintf("ADXSTMF_Destroy - UNIMPLEMENTED!\n");
}

void ADXSTMF_ExecHndl(ADXSTMF stmf)
{
    scePrintf("ADXSTMF_ExecHndl - UNIMPLEMENTED!\n");
}

// ADXSTMF_SetupHandleMember
// adxstmf_stat_exec

// 100% matching!
void ADXT_SetNumRetry(Sint32 num) 
{
    adxstmf_num_rtry = num;
}

// ADXT_SetupNrmlNumStm
// ADXT_SetupRtimeNumStm
