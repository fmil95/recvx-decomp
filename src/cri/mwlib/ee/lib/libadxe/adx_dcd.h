#ifndef _ADX_DCD_H_
#define _ADX_DCD_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include "macros.h"

#define PI 3.14159265
#define PI_2 (PI * 2)

Sint32 ADX_DecodeFooter(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen);
Sint32 ADX_DecodeInfo(Sint8* adr, Sint32 siz, Sint16* arg2, Sint8* arg3, Sint8* arg4, Sint8* arg5, Sint8* arg6, Sint32* arg7, Sint32* arg8, Sint32* arg9);
Sint32 ADX_DecodeInfoExADPCM2(Sint8 *ibuf, Sint32 ibuflen, Sint16 *cof);
Sint32 ADX_DecodeInfoExLoop(Sint8 *ibuf, Sint32 ibuflen, Sint32 *lp_ins_nsmpl, Sint16 *nloop, Sint16 *lp_type, Sint32 *lp_spos, Sint32 *lp_sofst, Sint32 *lp_epos, Sint32 *lp_eofst);
void ADX_GetCoefficient(Sint32 cof, Sint32 sfreq, Sint16 *k0, Sint16 *k1);
Sint32 ADX_ScanInfoCode(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen);

#endif
