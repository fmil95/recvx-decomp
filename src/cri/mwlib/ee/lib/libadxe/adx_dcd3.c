#include <cri_mw.h>

Sint32 adx_decode_output_mono_flag;

Sint32 ADX_DecodeMonoFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 k0, Sint16 k1)
{
    scePrintf("ADX_DecodeMonoFloat - UNIMPLEMENTED!\n");
}

Sint32 ADX_DecodeSteFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1)
{
    scePrintf("ADX_DecodeSteFloat - UNIMPLEMENTED!\n");
}

// ADX_DecodeSteFloatAsMono
// ADX_DecodeSteFloatAsSte

// 100% matching!
void ADX_SetDecodeSteAsMonoSw(Sint32 flag)
{
    adx_decode_output_mono_flag = flag;
}
