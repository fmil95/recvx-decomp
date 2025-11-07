#include "adx_bwav.h"

#include <string.h>

void ADXB_ExecOneWav4(ADXB adxb);
void ADXB_ExecOneWav8(ADXB adxb);
void ADXB_ExecOneWav16(ADXB adxb);

Sint32 ADX_DecodeInfoWav(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc)
{
    scePrintf("ADX_DecodeInfoWav - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXB_CheckWav(Sint8 *ibuf)
{
    if ((memcmp(ibuf, "RIFF", 4) == 0) && (memcmp(&ibuf[8], "WAVE", 4) == 0)) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
Sint32 ADXB_DecodeHeaderWav(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
	Sint16 dlen;
    Sint32 temp;

    adxb->hdcdflag = 1;

    if (ADX_DecodeInfoWav(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen, &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl, &adxb->cdctype) < 0) 
    {
        return 0;
    }

    temp = (Sint32)&adxb->unk4C;
    
    adxb->cof = 0;
    
    adxb->unk4A = 0;
    adxb->unk48 = 0;
    
    adxb->nloop = adxb->lp_type = 0;
    
    adxb->lp_ins_nsmpl = adxb->lp_spos = adxb->lp_sofst = adxb->lp_epos = adxb->lp_eofst = 0; 
    
    adxb->dp.nch = adxb->nch;
    
    adxb->dp.blksize = adxb->blklen;
    adxb->dp.blknsmpl = adxb->blknsmpl;
    
    adxb->dp.pcmbuf = (Sint8*)adxb->pcmbuf;
    adxb->dp.pcmbsize = adxb->pcmbsize;
    adxb->dp.pcmbdist = adxb->pcmbdist;
    
    adxb->unk7C = 0;
    adxb->unk7E = 0;
    
    adxb->unk80 = temp; 
    
    adxb->curwpos = 0;
    
    adxb->total_ndecsmpl = 0;
    
    adxb->fmttype = 1;

    memset((void*)temp, 0, sizeof(Sint32));
    
    return dlen;
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
