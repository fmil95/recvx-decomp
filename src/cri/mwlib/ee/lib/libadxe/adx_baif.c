#include "adx_baif.h"

void ADXB_ExecOneAiff8(ADXB adxb);
void ADXB_ExecOneAiff16(ADXB adxb);

// ADX_DecodeInfoAiff

Sint32 ADXB_CheckAiff(Sint8 *ibuf)
{
    scePrintf("ADXB_CheckAiff - UNIMPLEMENTED!\n");
}

Sint32 ADXB_DecodeHeaderAiff(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_DecodeHeaderAiff - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXB_ExecOneAiff(ADXB adxb)
{
    if (adxb->cdctype == 1)
    {
        ADXB_ExecOneAiff8(adxb);
    }
    else 
    {
        ADXB_ExecOneAiff16(adxb);
    }
}

void ADXB_ExecOneAiff8(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAiff8 - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneAiff16(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAiff16 - UNIMPLEMENTED!\n");
}

// AIFF_GetInfo
