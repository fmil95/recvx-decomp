#ifndef _ADX_BAU_H_
#define _ADX_BAU_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include "macros.h"

Sint32 ADX_DecodeInfoAu(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint32 *cdc);
Sint32 ADXB_CheckAu(Sint8 *ibuf);
Sint32 ADXB_DecodeHeaderAu(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_ExecOneAu(ADXB adxb);
void ADXB_ExecOneAu8(ADXB adxb);             
void ADXB_ExecOneAu16(ADXB adxb);                   
void ADXB_ExecOneAuUlaw(ADXB adxb); 
static void* AU_GetInfo(void *hdr, Sint32 hdrlen, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *cdc);

#endif
