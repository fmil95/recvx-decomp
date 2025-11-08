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

// 100% matching!
Sint32 ADX_DecodeInfo(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk) 
{
    Sint32 temp;
    
    if (ibuflen < 16) 
    {
        return -1;
    }
    
    temp = (Uint8)ibuf[1] | ((Uint8)ibuf[0] << 8);
    
    if (temp != 0x8000) 
    {
        return -2;
    }
    
    *dlen = ((Uint8)ibuf[3] | ((Uint8)ibuf[2] << 8)) + 4;
    
    *code = ibuf[4];
    
    *blksize = ibuf[5];
    
    *bps = ibuf[6];
    
    *nch = ibuf[7];
    
    *sfreq = ((Uint8)ibuf[8] << 24) | ((Uint8)ibuf[9] << 16) | ((Uint8)ibuf[10] << 8) | (Uint8)ibuf[11];
    
    *total_nsmpl = ((Uint8)ibuf[12] << 24) | ((Uint8)ibuf[13] << 16) | ((Uint8)ibuf[14] << 8) | (Uint8)ibuf[15];

    *nsmpl_blk = ((*blksize - 2) * 8) / *bps;

    return 0;
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

// 100% matching!
Sint32 ADX_DecodeInfoExLoop(Sint8 *ibuf, Sint32 ibuflen, Sint32 *lp_ins_nsmpl, Sint16 *nloop, Sint16 *lp_type, Sint32 *lp_spos, Sint32 *lp_sofst, Sint32 *lp_epos, Sint32 *lp_eofst)
{
	Sint32 dlen;
	Sint32 lp_inf_len;
	Sint32 ptr;
	Uint8 ver;
	Uint8 rev;

    *nloop = 0;
    
    lp_inf_len = 48;

    if (ibuflen < lp_inf_len) 
    {
        return -1;
    }
    
    if (BSWAP_U16_EX(((Uint16*)ibuf)[0]) != 0x8000) 
    {
        return -2;
    }
    
    if ((Sint16)BSWAP_U16_EX(((Uint16*)ibuf)[1]) < (lp_inf_len - 4)) 
    {
        return -1; 
    }
    
    ptr = 20;
  
    *lp_ins_nsmpl = (Sint16)BSWAP_S16(*(Uint16*)&ibuf[ptr]);
    
    ptr += 2; 
    
    *nloop = BSWAP_S16(*(Uint16*)&ibuf[ptr]);
    
    ptr += 2;
    
    if (*nloop != 1) 
    {
        return -2;
    }
    
    ptr += 2;

    *lp_type = BSWAP_S16(*(Uint16*)&ibuf[ptr]);
    
    ptr += 2;

    *lp_spos = BSWAP_S32(*(Sint32*)&ibuf[ptr]);
    
    ptr += 4;

    *lp_sofst = BSWAP_S32(*(Sint32*)&ibuf[ptr]);
    
    ptr += 4;

    *lp_epos = BSWAP_S32(*(Sint32*)&ibuf[ptr]);
    
    ptr += 4;

    *lp_eofst = BSWAP_S32(*(Sint32*)&ibuf[ptr]);

    return 0;
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
