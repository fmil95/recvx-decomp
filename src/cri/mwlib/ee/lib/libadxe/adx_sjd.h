#ifndef _ADX_SJD_H_
#define _ADX_SJD_H_

void adxsjd_clear(ADXSJD sjd);
ADXSJD ADXSJD_Create(SJ sji, Sint32 maxnch, SJ *sjo);
void adxsjd_decexec_end(ADXSJD sjd);
void adxsjd_decexec_start(ADXSJD sjd);
void adxsjd_decode_exec(ADXSJD sjd);
void adxsjd_decode_prep(ADXSJD sjd);
void ADXSJD_Destroy(ADXSJD sjd);
void ADXSJD_EntryFltFunc(ADXSJD sjd, void (*f)(), void *obj);
void ADXSJD_EntryTrapFunc(ADXSJD sjd, void (*f)(), void *obj);
void ADXSJD_ExecHndl(ADXSJD sjd);
void ADXSJD_ExecServer(void);
void ADXSJD_Finish(void);
void* adxsjd_get_wr(void *obj, Sint32 *wpos, Sint32 *nroom, Sint32 *lp_nsmpl);
Sint32 ADXSJD_GetBlkLen(ADXSJD sjd);
Sint32 ADXSJD_GetBlkSmpl(ADXSJD sjd);
Sint32 ADXSJD_GetCof(ADXSJD sjd);
Sint32 ADXSJD_GetDecDtLen(ADXSJD sjd);
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD sjd);
Sint32 ADXSJD_GetDecPos(ADXSJD sjd);
Sint32 ADXSJD_GetFmtBps(ADXSJD sjd);
Sint32 ADXSJD_GetFormat(ADXSJD sjd);
Sint32 ADXSJD_GetHdrLen(ADXSJD sjd);
Sint32 ADXSJD_GetLpEndOfst(ADXSJD sjd);
Sint32 ADXSJD_GetLpEndPos(ADXSJD sjd);
Sint32 ADXSJD_GetLpInsNsmpl(ADXSJD sjd);
Sint32 ADXSJD_GetLpStartOfst(ADXSJD sjd);
Sint32 ADXSJD_GetLpStartPos(ADXSJD sjd);
Sint32 ADXSJD_GetNumChan(ADXSJD sjd);
Sint32 ADXSJD_GetNumLoop(ADXSJD sjd);
Sint32 ADXSJD_GetOutBps(ADXSJD sjd);
Sint32 ADXSJD_GetSfreq(ADXSJD sjd);
void* ADXSJD_GetSpsdInfo(ADXSJD sjd);
Sint32 ADXSJD_GetStat(ADXSJD sjd);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd);
Sint32 ADXSJD_GetTrapCnt(ADXSJD sjd);
Sint32 ADXSJD_GetTrapDtLen(ADXSJD sjd);
Sint32 ADXSJD_GetTrapNumSmpl(ADXSJD sjd);
void ADXSJD_Init(void);
void ADXSJD_SetDecPos(ADXSJD sjd, Sint32 decpos);
void ADXSJD_SetInSj(ADXSJD sjd, SJ sj);
void ADXSJD_SetMaxDecSmpl(ADXSJD sjd, Sint32 nsmpl);
void ADXSJD_SetOutSj(ADXSJD sjd, Sint32 chno, SJ sj);
void ADXSJD_SetTrapCnt(ADXSJD sjd, Sint32 nsmpl);
void ADXSJD_SetTrapDtLen(ADXSJD sjd, Sint32 nbyte);
void ADXSJD_SetTrapNumSmpl(ADXSJD sjd, Sint32 nsmpl);
void ADXSJD_Start(ADXSJD sjd);
void ADXSJD_Stop(ADXSJD sjd);

#endif
