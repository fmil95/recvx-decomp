#ifndef _ADX_BSPS_H_
#define _ADX_BSPS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

Sint32 ADX_DecodeInfoSpsd(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc);
Sint32 ADXB_CheckSpsd(Sint8 *ibuf);
Sint32 ADXB_DecodeHeaderSpsd(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_ExecOneSpsd(ADXB adxb);

#endif
