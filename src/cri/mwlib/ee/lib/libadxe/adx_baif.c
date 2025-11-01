#include "adx_baif.h"

void ADXB_ExecOneAiff8(ADXB adxb);
void ADXB_ExecOneAiff16(ADXB adxb);

// ADX_DecodeInfoAiff

// 100% matching!
Sint32 ADXB_CheckAiff(Sint8 *ibuf)
{
    if ((memcmp(ibuf, "FORM", 4) == 0) && (memcmp(&ibuf[8], "AIFF", 4) == 0))
    {
        return 1;
    }
    
    return 0;
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
