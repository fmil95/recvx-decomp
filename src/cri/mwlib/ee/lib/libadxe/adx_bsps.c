#include "adx_bsps.h"

#include <string.h>

// ADX_DecodeInfoSpsd

// 100% matching!
Sint32 ADXB_CheckSpsd(Sint8 *ibuf)
{
    return memcmp(ibuf, "SPSD", 4) == 0;
}

Sint32 ADXB_DecodeHeaderSpsd(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_DecodeHeaderSpsd - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneSpsd(ADXB adxb)
{
    scePrintf("ADXB_ExecOneSpsd - UNIMPLEMENTED!\n");
}
