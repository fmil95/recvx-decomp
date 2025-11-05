#include "adx_stmc.h"
#include "adx_crs.h"
#include "adx_errs.h"

#include <string.h>

static ADXSTM_FILE adxstmf_obj[40] = { 0 };
static Sint32 adxstm_sj_internal_error_cnt;
static Sint32 adxstmf_nrml_num;
static Sint32 adxstmf_nrml_ofst;
static Sint32 adxstmf_num_rtry;

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
        ADXERR_CallErrFunc2((const Sint8*)"E0041206 ADXSTM_OpenFnameRang: can't open ", fname);
        
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
        ADXERR_CallErrFunc2((const Sint8*)"E00041205 ADXSTM_OpenFnameRangeExRt: can't open ", fname);
        
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
        ADXERR_CallErrFunc2((const Sint8*)"E00041205 ADXSTM_OpenFnameEx: can't open ", fname);
        
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
        ADXERR_CallErrFunc1((const Sint8*)"E0062201 ADXSTM_OpenFname: can't specify dir");
        
        return NULL;
    }

    fsize = cvFsGetFileSize(fname);

    fp = cvFsOpen(fname, NULL, CVE_FS_OP_READ);
    
    if (fp == NULL) 
    {
        ADXERR_CallErrFunc2((const Sint8*)"E00041205 ADXSTM_OpenFnameEx: can't open ", fname);
        
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

// 100% matching!
Sint32 ADXSTM_Start(ADXSTM stm) 
{
    ADXSTMF stmf;

    stmf = stm;
    
    if (stmf->fsize == 0) 
    {
        stmf->stat = 3;
        
        stmf->stpos = 0;
        
        stmf->tbyte = 0;
    } 
    else
    {
        stmf->tbyte = 0;
        
        stmf->stat = 2;
        
        stmf->stpos = ADXSTM_Tell(stm);
        
        stmf->errcnt = 0;
    }
    
    return 1;
}

// 100% matching!
void ADXSTM_Stop(ADXSTM stm) 
{
    ADXSTMF stmf;

    stmf = stm;

    ADXCRS_Lock();
    
    if ((stmf->rdflg == 1) && (stmf->fp != NULL)) 
    {
        cvFsStopTr(stmf->fp);
        
        stmf->rdflg = 0;
    }
    
    ADXCRS_Unlock();
    
    stmf->stat = 1;
}

// 100% matching!
Sint32 ADXSTM_Tell(ADXSTM stm)
{
    ADXSTMF stmf;

    stmf = stm;

    if (stmf->fp != NULL) 
    {
        return cvFsTell(stmf->fp) - stmf->fofst;
    }
    
    return 0;
}

// 100% matching!
ADXSTMF ADXSTMF_CreateCvfs(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj)
{
    ADXSTMF stmf;
	Sint32 no;

    stmf = NULL;

    for (no = 0; no < adxstmf_nrml_num; no++) 
    {
        stmf = &adxstmf_obj[adxstmf_nrml_ofst + no];

        if (stmf->used == FALSE) 
        {
            break;
        }
    }

    if (no == adxstmf_nrml_num) 
    {
        return NULL;
    }

    ADXSTMF_SetupHandleMember(stmf, fp, fofst, fsize, sj);
    
    return stmf;
}

// 100% matching!
ADXSTMF ADXSTMF_CreateCvfsRt(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj)
{
    ADXSTMF stmf;
	Sint32 no;

    stmf = NULL;

    for (no = 0; no < adxstmf_nrml_num; no++) 
    {
        stmf = &adxstmf_obj[adxstmf_nrml_ofst + no];

        if (stmf->used == FALSE) 
        {
            break;
        }
    }

    if (no == adxstmf_nrml_num) 
    {
        return NULL;
    }

    ADXSTMF_SetupHandleMember(stmf, fp, fofst, fsize, sj);
    
    return stmf;
}

// 100% matching!
void ADXSTMF_Destroy(ADXSTMF stmf)
{
    memset(stmf, 0, sizeof(ADXSTM_FILE));
}

// 100% matching!
void ADXSTMF_ExecHndl(ADXSTMF stmf)
{
    if (stmf->stat == 2) 
    {
        adxstmf_stat_exec(stmf);
    }
}

// 100% matching!
void ADXSTMF_SetupHandleMember(ADXSTMF stmf, CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj)
{
    stmf->stat = 1;
    
    stmf->sj = sj;
    
    stmf->fp = fp;
    
    stmf->rdflg = 0;
    
    stmf->stpos = 0;
    
    stmf->fofst = fofst;
    
    stmf->fsize = fsize;
    
    stmf->rdsct = 512;
    
    stmf->esct = (stmf->fsize + 2047) / 2048;
    
    stmf->used = TRUE;
}

// 100% matching!
void adxstmf_stat_exec(ADXSTMF stmf) 
{
    SJ sj;
	Sint32 ndata;
	Sint32 nsct;
	Sint32 rbyte;
	Sint32 stat;
	Sint32 fsize; /* unused */
	Sint32 fnsct;
	Sint32 esct; /* unused */
	SJCK ck;
	SJCK ck2;
    
    sj = stmf->sj;

    if (stmf->rdflg == 1)
    {
        stat = cvFsGetStat(stmf->fp);
        
        if (stat == CVE_FS_ST_COMPLETE) 
        {
            rbyte = stmf->reqsct * 2048;
            
            SJ_SplitChunk(&stmf->reqck, rbyte, &ck, &ck2);
            
            SJ_PutChunk(sj, 1, &ck);
            
            SJ_UngetChunk(sj, 0, &ck2);
            
            if ((ADXSTM_Tell(stmf) == stmf->esct) && (stmf->eosfunc != NULL)) 
            {
                stmf->eosfunc(stmf->eosobj);
            } 
            
            stmf->rdflg = 0;

            stmf->tbyte += rbyte;

            if (ADXSTM_Tell(stmf) >= ((stmf->fsize + 2047) / 2048)) 
            {
                stmf->stat = 3;
            }
            
            stmf->errcnt = 0;
        } 
        else if (stat == CVE_FS_ST_ERR) 
        {
            SJ_UngetChunk(sj, 0, &stmf->reqck);
            
            if (adxstmf_num_rtry >= 0) 
            {
                if (stmf->errcnt >= adxstmf_num_rtry) 
                {
                    stmf->stat = 4;
                } 
                else
                {
                    stmf->errcnt++;
                }
            }

            stmf->rdflg = 0;
        } 
    } 
    
    if (stmf->rdflg != 0) 
    {
        return;
    }
    
    if ((sj == NULL) || (sj->vtbl == NULL)) 
    { 
        adxstm_sj_internal_error();
        return;
    }

    ndata = SJ_GetNumData(sj, 1);

    if (ndata < stmf->minsize) 
    {
        SJ_GetChunk(sj, 0, stmf->maxsize, &stmf->reqck);
        
        nsct = stmf->reqck.len / 2048;
        
        fnsct = stmf->esct;
        
        fnsct -= ADXSTM_Tell(stmf);
        
        nsct = MIN(nsct, fnsct);
        nsct = MIN(nsct, stmf->rdsct);
    
        if (nsct == 0) 
        {
            SJ_UngetChunk(sj, 0, &stmf->reqck);
        }
        else 
        {
            stmf->reqsct = cvFsReqRd(stmf->fp, nsct, stmf->reqck.data);
            
            if (stmf->reqsct <= 0)
            {
                SJ_UngetChunk(sj, 0, &stmf->reqck);
            
                if ((cvFsGetStat(stmf->fp) == CVE_FS_ST_ERR) && (adxstmf_num_rtry >= 0)) 
                {
                    if (stmf->errcnt >= adxstmf_num_rtry)
                    {
                        stmf->stat = 4;
                    } 
                    else
                    {
                        stmf->errcnt++;
                    }
                }
        
            }
            else 
            {
                stmf->rdflg = 1;
            }
        }
    }
}

// 100% matching!
void ADXT_SetNumRetry(Sint32 num) 
{
    adxstmf_num_rtry = num;
}

// 100% matching!
void ADXT_SetupNrmlNumStm(Sint32 num)
{
    adxstmf_nrml_num = num;
    adxstmf_nrml_ofst = 40 - num;
}

// 100% matching!
void ADXT_SetupRtimeNumStm(Sint32 num)
{
    adxstmf_nrml_num = num;
}
