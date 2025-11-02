#include "adx_baif.h"

void ADXB_ExecOneAiff8(ADXB adxb);
void ADXB_ExecOneAiff16(ADXB adxb);
static void* AIFF_GetInfo(void *hdr, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl);

// 100% matching!
Sint32 ADX_DecodeInfoAiff(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk)
{
	Sint8 *dt;
	Sint32 lsfreq;
	Sint32 lnch;
	Sint32 lbps;
	Sint32 lnsmpl;
    
    if (ibuflen < 4096) 
    {
        *dlen = 0;
        
        return -1;
    }
    
    dt = AIFF_GetInfo(ibuf, &lsfreq, &lnch, &lbps, &lnsmpl);
    
    if (dt == NULL) 
    {
        return -1;
    }

    *dlen = dt - ibuf;
    
    if ((*dlen * 1024) <= 0)
    {
        return -1;
    }
    
    *sfreq = lsfreq;
    
    *nch = lnch;
    
    *bps = lbps;
    
    *total_nsmpl = lnsmpl;
    
    *code = -1;
    
    *blksize = (*nch * *bps) / 8;
    
    *nsmpl_blk = 1;

    return 0;
}

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

static void* AIFF_GetInfo(void *hdr, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl)
{
    scePrintf("AIFF_GetInfo - UNIMPLEMENTED!\n");
}
