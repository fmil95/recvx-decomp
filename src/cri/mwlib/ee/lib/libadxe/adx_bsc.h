#ifndef _ADX_BSC_H_
#define _ADX_BSC_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include "macros.h"

/* structs are located in the override_adxt header */

void ADXB_CopyExtraBufMono(Sint16 *obuf, Sint32 obsize, Sint32 xsize, Sint32 nxsmpl);
void ADXB_CopyExtraBufSte(Sint16 *obuf, Sint32 obsize, Sint32 obdist, Sint32 nxsmpl);
ADXB ADXB_Create(Sint32 maxnch, Sint16 *obuf, Sint32 bsize, Sint32 bdist);
Sint32 ADXB_DecodeHeader(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void adxb_DefAddWr(void *obj, Sint32 wlen, Sint32 wnsmpl);
void* adxb_DefGetWr(void *obj, Sint32 *wpos, Sint32 *nroom, Sint32 *lp_nsmpl);
void ADXB_Destroy(ADXB adxb);
void ADXB_EndDecode(ADXB adxb);
void ADXB_EntryAddWrFunc(ADXB adxb, void (*func)(), void *obj);
void ADXB_EntryData(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_EntryGetWrFunc(ADXB adxb, void* (*func)(), void *obj);
void ADXB_EvokeDecode(ADXB adxb);
void ADXB_EvokeExpandMono(ADXB adxb, Sint32 nblk);
void ADXB_EvokeExpandSte(ADXB adxb, Sint32 nblk);
void ADXB_ExecHndl(ADXB adxb);
void ADXB_ExecOneAdx(ADXB adxb);
void ADXB_ExecServer(void);
ADXPD ADXB_GetAdxpd(ADXB adxb);
Sint32 ADXB_GetBlkLen(ADXB adxb);
Sint32 ADXB_GetBlkSmpl(ADXB adxb);
Sint32 ADXB_GetCof(ADXB adxb);
Sint32 ADXB_GetDecDtLen(ADXB adxb);
Sint32 ADXB_GetDecNumSmpl(ADXB adxb);
Sint32 ADXB_GetFmtBps(ADXB adxb);
Sint32 ADXB_GetFormat(ADXB adxb);
Sint32 ADXB_GetLpEndOfst(ADXB adxb);
Sint32 ADXB_GetLpEndPos(ADXB adxb);
Sint32 ADXB_GetLpInsNsmpl(ADXB adxb);
Sint32 ADXB_GetLpStartOfst(ADXB adxb);
Sint32 ADXB_GetLpStartPos(ADXB adxb);
Sint32 ADXB_GetNumChan(ADXB adxb);
Sint32 ADXB_GetNumLoop(ADXB adxb);
Sint32 ADXB_GetOutBps(ADXB adxb);
Sint16* ADXB_GetPcmBuf(ADXB adxb);
Sint32 ADXB_GetSfreq(ADXB adxb);
Sint32 ADXB_GetStat(ADXB adxb);
Sint32 ADXB_GetTotalNumSmpl(ADXB adxb);
void ADXB_Init(void);
void ADXB_Reset(ADXB adxb);
void ADXB_Start(ADXB adxb);
void ADXB_Stop(ADXB adxb);
void memcpy2(Sint16 *dst, const Sint16 *src, Sint32 nword);

#endif
