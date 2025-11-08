#include "adx_dcd.h"

#include <mathf.h>

// 100% matching!
Sint32 ADX_DecodeFooter(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen) 
{
    if (ibuflen < 16) 
    {
        return -1;
    }
    
    if (BSWAP_U16_EX(((Uint16*)ibuf)[0]) != 0x8001) 
    {
        return -2;
    }

    *dlen = BSWAP_U16_EX(((Uint16*)ibuf)[1]) + 4;
    
    return 0;
}

Sint32 ADX_DecodeInfo(Sint8* adr, Sint32 siz, Sint16* arg2, Sint8* arg3, Sint8* arg4, Sint8* arg5, Sint8* arg6, Sint32* arg7, Sint32* arg8, Sint32* arg9)
{
    scePrintf("ADX_DecodeInfo - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADX_DecodeInfoExADPCM2(Sint8 *ibuf, Sint32 ibuflen, Sint16 *cof) 
{
	Sint32 dlen; 

    if (ibuflen < 18) 
    {
        return -1;
    }
    
    if (BSWAP_U16_EX(((Uint16*)ibuf)[0]) != 0x8000) 
    {
        return -2;
    }
    
    if ((Sint16)BSWAP_S16(((Uint16*)ibuf)[1]) < 14) 
    {
        return -1;
    }

    *cof = BSWAP_U16_EX(((Uint16*)ibuf)[8]);
    
    return 0;
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

// 100% matching!
Sint32 ADX_ScanInfoCode(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen)
{
	Sint16 code;
	Sint32 ptr;
	Sint32 minptr;

    minptr = 0x7FFFFFFF;
    
    code = 0x80;
    
    for (ptr = 0; ptr < (ibuflen - 1); ptr += 2) 
    {
        if (*(Sint16*)&ibuf[ptr] == code) 
        {
            minptr = (ptr < minptr) ? ptr : minptr;
            break;
        }
    }
    
    if (minptr != 0x7FFFFFFF) 
    {
        *dlen = minptr;
        
        return 0;
    } 
    else 
    {
        *dlen = 0;
        
        return -1;
    }
}
