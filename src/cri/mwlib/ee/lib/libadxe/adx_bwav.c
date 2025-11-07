#include "adx_bwav.h"

void ADXB_ExecOneWav4(ADXB adxb);
void ADXB_ExecOneWav8(ADXB adxb);
void ADXB_ExecOneWav16(ADXB adxb);

// ADX_DecodeInfoWav

Sint32 ADXB_CheckWav(Sint8 *ibuf)
{
    scePrintf("ADXB_CheckWav - UNIMPLEMENTED!\n");
}

Sint32 ADXB_DecodeHeaderWav(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_DecodeHeaderWav - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXB_ExecOneWav(ADXB adxb)
{
    if (adxb->cdctype == 2) 
    {                    
        ADXB_ExecOneWav4(adxb);
    }
    else if (adxb->cdctype == 1) 
    {
        ADXB_ExecOneWav8(adxb);
    }
    else if (adxb->cdctype == 0)
    { 
        ADXB_ExecOneWav16(adxb);
    }
}

void ADXB_ExecOneWav4(ADXB adxb)
{
    scePrintf("ADXB_ExecOneWav4 - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneWav8(ADXB adxb)
{
    scePrintf("ADXB_ExecOneWav8 - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneWav16(ADXB adxb)
{
    scePrintf("ADXB_ExecOneWav16 - UNIMPLEMENTED!\n");
}
