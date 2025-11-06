#include "adx_bsps.h"

#include <string.h>

Sint32 ADX_DecodeInfoSpsd(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc)
{
    scePrintf("ADX_DecodeInfoSpsd - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXB_CheckSpsd(Sint8 *ibuf)
{
    return memcmp(ibuf, "SPSD", 4) == 0;
}

// 100% matching!
Sint32 ADXB_DecodeHeaderSpsd(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
	Sint16 dlen;
    Sint32 temp;

    adxb->hdcdflag = 1;

    if (ADX_DecodeInfoSpsd(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen, &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl, &adxb->cdctype) < 0) 
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
    
    adxb->fmttype = 2;

    memset((void*)temp, 0, sizeof(Sint32));
    
    return dlen;
}

void ADXB_ExecOneSpsd(ADXB adxb)
{
    scePrintf("ADXB_ExecOneSpsd - UNIMPLEMENTED!\n");
}
