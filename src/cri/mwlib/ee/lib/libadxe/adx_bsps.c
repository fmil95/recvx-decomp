#include "adx_bsps.h"
#include "adx_xpnd.h"

#include <string.h>

// 100% matching!
Sint32 ADX_DecodeInfoSpsd(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc)
{
	Uint8 bitsize; 
    Sint32 temp, temp2;

    *dlen = (Uint8)ibuf[7] * 16;    
    
    *nch = (ibuf[9] & 0x3) + 1;
    
    *sfreq = *(Uint16*)&ibuf[42];
    
    bitsize = ibuf[8];
    
    switch (bitsize) 
    {
    case 0:
        *bps = 16;
        
        *blksize = *nch * 2;
        
        *nsmpl_blk = 1;
        
        *total_nsmpl = *(Sint32*)&ibuf[12] / 2;
        
        *cdc = 0;
        break;
    case 1:
        *bps = 8;
        
        *blksize = temp = (Uint8)*nch;
        
        *nsmpl_blk = 1;
        
        *total_nsmpl = *(Sint32*)&ibuf[12];
        
        *cdc = 1;
        break;
    case 2:
    case 3:
        *bps = 4;
        
        *blksize = temp2 = (Uint8)*nch;
        
        *nsmpl_blk = 2;
        
        *total_nsmpl = *(Sint32*)&ibuf[12] * 2;
 
        *cdc = 2;
        break;
    }
    
    *blksize = 2;
    
    *nsmpl_blk = 1;
    
    *total_nsmpl = *(Sint32*)&ibuf[12] / 2;
    
    *bps = 16;
    
    *code = -1;
    
    return 0;
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

// 100% matching!
void ADXB_ExecOneSpsd(ADXB adxb) 
{
	AdxDecPara *dp;
	Uint16 *pcmbuf;
	Uint16 *pcmbuf_l;
	Uint16 *pcmbuf_r;
	Uint16 *ibuf;
	Sint32 i;
	Sint32 ndata;

    dp = &adxb->dp;

    ibuf = (Uint16*)dp->ibuf;
    
    if ((adxb->stat == 1) && (ADXPD_GetStat(adxb->xpd) == 0)) 
    {
        adxb->getwrfunc(adxb->getwrobj, &adxb->dp.wpos, &adxb->dp.nroom, &adxb->dp.lp_nsmpl);

        ndata = dp->pcmbsize - dp->wpos;
        
        ndata = (dp->nroom < ndata) ? dp->nroom : ndata;
        ndata = (dp->niblk < ndata) ? dp->niblk : ndata;

        pcmbuf = (Uint16*)dp->pcmbuf;
        
        pcmbuf_l = &pcmbuf[dp->wpos];
        
        if (adxb->nch == 2) 
        {
            pcmbuf_r = &pcmbuf[dp->pcmbdist + dp->wpos];
            
            for (i = 0; i < ndata; i++) 
            {
                pcmbuf_l[i] = ibuf[i * 2];
                pcmbuf_r[i] = ibuf[(i * 2) + 1];
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                pcmbuf_l[i] = ibuf[i];
            }
        }
        
        adxb->total_decsmpl = ndata;
        adxb->total_decdtlen = ndata * (adxb->nch << 1);
        
        adxb->stat = 2;
    }
    
    if (adxb->stat == 2)
    {
        adxb->addwrfunc(adxb->addwrobj, adxb->total_decdtlen, adxb->total_decsmpl);
        
        adxb->stat = 3;
    }
}
