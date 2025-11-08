#include "adx_dcd3.h"

Sint32 adx_decode_output_mono_flag;

Sint32 ADX_DecodeMonoFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 k0, Sint16 k1)
{
    scePrintf("ADX_DecodeMonoFloat - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADX_DecodeSteFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1)
{
    if (adx_decode_output_mono_flag == 0)
    {
        return ADX_DecodeSteFloatAsSte(ibuf, nblk, obuf_l, dly_l, obuf_r, dly_r, k0, k1);
    }
    
    return ADX_DecodeSteFloatAsMono(ibuf, nblk, obuf_l, dly_l, obuf_r, dly_r, k0, k1);
}

Sint32 ADX_DecodeSteFloatAsMono(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1) 
{
    scePrintf("ADX_DecodeSteFloatAsMono - UNIMPLEMENTED!\n");
}

Sint32 ADX_DecodeSteFloatAsSte(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1) 
{
    scePrintf("ADX_DecodeSteFloatAsSte - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADX_SetDecodeSteAsMonoSw(Sint32 flag)
{
    adx_decode_output_mono_flag = flag;
}
