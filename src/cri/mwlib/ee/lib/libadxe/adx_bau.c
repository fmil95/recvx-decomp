#include "adx_bau.h"

void ADXB_ExecOneAu16(ADXB adxb);                          
void ADXB_ExecOneAu8(ADXB adxb);                            
void ADXB_ExecOneAuUlaw(ADXB adxb); 

Sint32 ADX_DecodeInfoAu(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint32 *cdc) 
{
    scePrintf("ADX_DecodeInfoAu - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXB_CheckAu(Sint8 *ibuf)
{
    if ((memcmp(ibuf, ".snd", 4) == 0) || (memcmp(ibuf, ".sd", 4) == 0)) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
Sint32 ADXB_DecodeHeaderAu(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen) 
{
	Sint16 dlen;
	Sint32 cdc;
    Sint32 temp;

    adxb->hdcdflag = 1;

    if (ADX_DecodeInfoAu(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen, &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl, &cdc) < 0) 
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
    
    adxb->fmttype = 4;
    adxb->cdctype = cdc;

    memset((void*)temp, 0, sizeof(Sint32));
    
    return dlen;
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
