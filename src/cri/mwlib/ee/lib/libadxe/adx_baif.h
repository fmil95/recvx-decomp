#ifndef _ADX_BAIF_H_
#define _ADX_BAIF_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include "macros.h"

Sint32 ADX_DecodeInfoAiff(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk);
Sint32 ADXB_CheckAiff(Sint8 *ibuf);
Sint32 ADXB_DecodeHeaderAiff(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_ExecOneAiff(ADXB adxb);
void ADXB_ExecOneAiff8(ADXB adxb);
void ADXB_ExecOneAiff16(ADXB adxb);
static void* AIFF_GetInfo(void *hdr, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl);

#endif
