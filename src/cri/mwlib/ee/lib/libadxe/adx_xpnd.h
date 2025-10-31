#ifndef _ADX_XPND_H_
#define _ADX_XPND_H_

#include <cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <cri_adxt.h>

/* structs are located in the override_adxt header */

ADXPD ADXPD_Create(void);
void ADXPD_Destroy(ADXPD xpd);
Sint32 ADXPD_EntryMono(ADXPD xpd, Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l);
Sint32 ADXPD_EntrySte(ADXPD xpd, Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *obuf_r);
void adxpd_error(void);
void ADXPD_ExecHndl(ADXPD xpd);
void ADXPD_ExecServer(void);
Sint32 ADXPD_GetNumBlk(ADXPD xpd);
Sint32 ADXPD_GetStat(ADXPD xpd);
void ADXPD_Init(void);
void ADXPD_Reset(ADXPD xpd);
void ADXPD_SetCoef(ADXPD xpd, Sint32 sfreq, Sint32 cof);
void ADXPD_SetMode(ADXPD xpd, Sint32 mode);
void ADXPD_Start(ADXPD xpd);
void ADXPD_Stop(ADXPD xpd);

#endif
