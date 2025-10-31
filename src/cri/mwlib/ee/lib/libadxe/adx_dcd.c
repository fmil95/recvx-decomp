#include <cri_mw.h>

#define PI 3.14159265
#define PI_2 (PI * 2)

Sint32 ADX_DecodeFooter(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen) 
{
    scePrintf("ADX_DecodeFooter - UNIMPLEMENTED!\n");
}

Sint32 ADX_DecodeInfo(Sint8* adr, Sint32 siz, Sint16* arg2, Sint8* arg3, Sint8* arg4, Sint8* arg5, Sint8* arg6, Sint32* arg7, Sint32* arg8, Sint32* arg9)
{
    scePrintf("ADX_DecodeInfo - UNIMPLEMENTED!\n");
}

Sint32 ADX_DecodeInfoExADPCM2(Sint8 *ibuf, Sint32 ibuflen, Sint16 *cof)
{
    scePrintf("ADX_DecodeInfoExADPCM2 - UNIMPLEMENTED!\n");
}

Sint32 ADX_DecodeInfoExLoop(Sint8 *ibuf, Sint32 ibuflen, Sint32 *lp_ins_nsmpl, Sint16 *nloop, Sint16 *lp_type, Sint32 *lp_spos, Sint32 *lp_sofst, Sint32 *lp_epos, Sint32 *lp_eofst)
{
    scePrintf("ADX_DecodeInfoExLoop - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADX_GetCoefficient(Sint32 cof, Sint32 sfreq, Sint16 *k0, Sint16 *k1)
{
    double val1;
    double val2;
    double r;

    val1 = sqrtf(2) - cosf((PI_2 * cof) / sfreq);
    val2 = sqrtf(2) - 1.0;

    r = (val1 - sqrtf((val1 + val2) * (val1 - val2))) / val2;
    
    *k0 = (2 * r) * 4096; 
    *k1 = (-r * r) * 4096; 
}

Sint32 ADX_ScanInfoCode(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen) 
{
    scePrintf("ADX_ScanInfoCode - UNIMPLEMENTED!\n");
}
