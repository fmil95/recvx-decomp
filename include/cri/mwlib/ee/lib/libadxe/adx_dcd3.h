#ifndef _ADX_DCD3_H_
#define _ADX_DCD3_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include "macros.h"

Sint32 ADX_DecodeMonoFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 k0, Sint16 k1);
Sint32 ADX_DecodeSteFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1);
Sint32 ADX_DecodeSteFloatAsMono(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1);
Sint32 ADX_DecodeSteFloatAsSte(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1);
void ADX_SetDecodeSteAsMonoSw(Sint32 flag);

#endif
