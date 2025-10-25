#define PI 3.14159265
#define PI_2 (PI * 2)

// ADX_DecodeFooter

Sint32 ADX_DecodeInfo(Sint8* adr, Sint32 siz, Sint16* arg2, Sint8* arg3, Sint8* arg4, Sint8* arg5, Sint8* arg6, Sint32* arg7, Sint32* arg8, Sint32* arg9)
{
    scePrintf("ADX_DecodeInfo - UNIMPLEMENTED!\n");
}

// ADX_DecodeInfoExADPCM2
// ADX_DecodeInfoExLoop

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

// ADX_ScanInfoCode