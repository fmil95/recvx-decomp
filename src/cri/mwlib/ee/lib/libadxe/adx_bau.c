#include "adx_bau.h"

void ADXB_ExecOneAu16(ADXB adxb);                          
void ADXB_ExecOneAu8(ADXB adxb);                            
void ADXB_ExecOneAuUlaw(ADXB adxb); 

// ADX_DecodeInfoAu

Sint32 ADXB_CheckAu(Sint8 *ibuf)
{
    scePrintf("ADXB_CheckAu - UNIMPLEMENTED!\n");
}

Sint32 ADXB_DecodeHeaderAu(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_DecodeHeaderAu - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXB_ExecOneAu(ADXB adxb)
{
    if (adxb->cdctype == 2) 
    {
        ADXB_ExecOneAuUlaw(adxb);
    } 
    else if (adxb->cdctype == 1)
    {
        ADXB_ExecOneAu8(adxb);
    } 
    else
    {
        ADXB_ExecOneAu16(adxb);
    }
}

void ADXB_ExecOneAu8(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAu8 - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneAu16(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAu16 - UNIMPLEMENTED!\n");
}

void ADXB_ExecOneAuUlaw(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAuUlaw - UNIMPLEMENTED!\n");
}

// AU_GetInfo
