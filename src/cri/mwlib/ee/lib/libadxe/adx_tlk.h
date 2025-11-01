#ifndef _ADX_TLK_H_
#define _ADX_TLK_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8)) // TODO: move this macro somewhere else

void ADXT_ClearErrCode(ADXT adxt);
void ADXT_CloseAllHandles(void);
ADXT ADXT_Create(Sint32 maxnch, void *work, Sint32 worksize);
void ADXT_Destroy(ADXT adxt);
void ADXT_DestroyAll(void);
Sint32 ADXT_DiscardSmpl(ADXT adxt, Sint32 nsmpl);
void adxt_disp_rna_stat(ADXT adxt);
void ADXT_EntryErrFunc(void (*func)(), void *obj);
void ADXT_EntryFltFunc(ADXT adxt, void (*f)(), void *obj);
void ADXT_ExecServer(void);
Sint32 ADXT_GetDecNumSmpl(ADXT adxt);
Sint32 ADXT_GetErrCode(ADXT adxt);
Sint32 ADXT_GetFmtBps(ADXT adxt);
Sint32 ADXT_GetHdrLen(ADXT adxt);
float ADXT_GetIbufRemainTime(ADXT adxt);
SJ ADXT_GetInputSj(ADXT adxt);
Sint32 ADXT_GetLnkSw(ADXT adxt);
Sint32 ADXT_GetLpCnt(ADXT adxt);
Sint32 ADXT_GetNumChan(ADXT adxt);
Sint32 ADXT_GetNumSctIbuf(ADXT adxt);
Sint32 ADXT_GetNumSmpl(ADXT adxt);
Sint32 ADXT_GetNumSmplObuf(ADXT adxt, Sint32 chno);
Sint32 ADXT_GetOutPan(ADXT adxt, Sint32 ch);
Sint32 ADXT_GetOutVol(ADXT adxt);
Sint32 ADXT_GetSfreq(ADXT adxt);
Sint32 ADXT_GetStat(ADXT adxt);
void ADXT_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale);
Sint32 ADXT_GetTimeReal(ADXT adxt);
void ADXT_GetTimeSfreq(ADXT adxt, Sint32 *ncount, Sint32 *tscale);
void ADXT_GetTimeSfreq2(ADXT adxt, Sint32 *ncount, Sint32 *tscale);
Sint32 ADXT_InsertSilence(ADXT adxt, Sint32 nch, Sint32 nsmpl);
Sint32 ADXT_IsCompleted(ADXT adxt);
Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz);
Sint32 ADXT_IsHeader(Sint8 *adr, Sint32 siz, Sint32 *hdrsiz);
Sint32 ADXT_IsIbufSafety(ADXT adxt);
Sint32 ADXT_IsReadyPlayStart(ADXT adxt);
void ADXT_SetAutoRcvr(ADXT adxt, Sint32 rmode);
void ADXT_SetLnkSw(ADXT adxt, Sint32 sw);
void ADXT_SetLpFlg(ADXT adxt, Sint32 flg);
void ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan);
void ADXT_SetOutputMono(Sint32 flag);
void ADXT_SetOutVol(ADXT adxt, Sint32 vol);
Sint32 ADXT_SetPauseBuf(void);
void ADXT_SetReloadSct(ADXT adxt, Sint32 minsct);
void ADXT_SetReloadTime(ADXT adxt, float time, Sint32 nch, Sint32 sfreq);
void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq);
void ADXT_SetTimeMode(Sint32 mode);
void ADXT_SetTimeOfst(ADXT adxt, Sint32 ofst);
void ADXT_SetWaitPlayStart(ADXT adxt, Sint32 flg);
void adxt_start_sj(ADXT adxt, SJ sj);
void adxt_start_stm(ADXT adxt);
void ADXT_StartSj(ADXT adxt, SJ sj);
void ADXT_Stop(ADXT adxt);
void ADXT_StopWithoutLsc(ADXT adxt);

#endif
