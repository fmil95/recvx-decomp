#ifndef _ADX_STMC_H_
#define _ADX_STMC_H_

#include <cri_xpt.h>
#include <sj.h>
#include "override_adxf.h"
#include <cri_adxf.h>
#include "cri_cvfs.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b)) // TODO: move this macro somewhere else

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
} ADXSTM_FILE;
typedef ADXSTM_FILE *ADXSTMF;

void ADXSTM_Close(ADXSTM stm);
void ADXSTM_EntryEosFunc(ADXSTM stm, void (*fn)(), void *obj);
void ADXSTM_EntryErrFunc(void (*errfn)(), void *obj);
void ADXSTM_ExecServer(void);
void ADXSTM_Finish(void);
Sint32 ADXSTM_GetBufSize(ADXSTM stm, Sint32 *min, Sint32 *max);
Sint32 ADXSTM_GetCurOfst(ADXSTM stm, Sint32 *ofst);
void ADXSTM_GetCvdfsStat(ADXSTM stm, Sint32 *cvfsst);
Sint32 ADXSTM_GetFad(const Sint8 *fname, Sint32 *fad);
Sint32 ADXSTM_GetFileLen(ADXSTM stm);
Sint32 ADXSTM_GetFsizeByte(const Sint8 *fname, Sint32 *fsize);
Sint32 ADXSTM_GetFsizeSct(const Sint8 *fname, Sint32 *fnsct);
SJ ADXSTM_GetSj(ADXSTM stm);
Sint32 ADXSTM_GetStat(ADXSTM stm);
Sint32 ADXSTM_Init(void);
ADXSTM ADXSTM_OpenFileRange(const Sint8 *fname, Sint32 ofst, Sint32 nsct, SJ sj);
ADXSTM ADXSTM_OpenFileRangeEx(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj);
ADXSTM ADXSTM_OpenFileRangeExRt(const Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct, SJ sj);
ADXSTM ADXSTM_OpenFname(const Sint8 *fname, SJ sj);
ADXSTM ADXSTM_OpenFnameEx(const Sint8 *fname, void *dir, SJ sj);
void ADXSTM_Reset(void);
Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 ofst);
Sint32 ADXSTM_SetBufSize(ADXSTM stm, Sint32 min, Sint32 max);
void ADXSTM_SetEos(ADXSTM stm, Sint32 esct);
void ADXSTM_SetOfst(ADXSTM stm, Sint32 ofst);
void ADXSTM_SetRdSct(ADXSTM stm, Sint32 nsct);
Sint32 ADXSTM_SetReqRdSize(ADXSTM stm, Sint32 sct);
void ADXSTM_SetSj(ADXSTM stm, SJ sj);
void adxstm_sj_internal_error(void);
Sint32 ADXSTM_Start(ADXSTM stm);
void ADXSTM_Stop(ADXSTM stm);
Sint32 ADXSTM_Tell(ADXSTM stm);
ADXSTMF ADXSTMF_CreateCvfs(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj);
ADXSTMF ADXSTMF_CreateCvfsRt(CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj);
void ADXSTMF_Destroy(ADXSTMF stmf);
void ADXSTMF_ExecHndl(ADXSTMF stmf);
void ADXSTMF_SetupHandleMember(ADXSTMF stmf, CVFS fp, Sint32 fofst, Sint32 fsize, SJ sj);
void adxstmf_stat_exec(ADXSTMF stmf);
void ADXT_SetNumRetry(Sint32 num);
void ADXT_SetupNrmlNumStm(Sint32 num);
void ADXT_SetupRtimeNumStm(Sint32 num);

#endif
