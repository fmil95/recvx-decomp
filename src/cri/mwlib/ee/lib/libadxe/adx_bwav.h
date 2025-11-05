#ifndef _ADX_BWAV_H_
#define _ADX_BWAV_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

Sint32 ADXB_CheckWav(Sint8 *ibuf);
Sint32 ADXB_DecodeHeaderWav(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_ExecOneWav(ADXB adxb);

#endif
