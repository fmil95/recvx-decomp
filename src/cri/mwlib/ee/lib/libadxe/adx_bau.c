#include "adx_bau.h"

void ADXB_ExecOneAu8(ADXB adxb);             
void ADXB_ExecOneAu16(ADXB adxb);                   
void ADXB_ExecOneAuUlaw(ADXB adxb); 
static void* AU_GetInfo(void *hdr, Sint32 hdrlen, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *cdc);

// 100% matching!
Sint32 ADX_DecodeInfoAu(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint32 *cdc)
{
	Sint8 *dt;
	Sint32 lsfreq;
	Sint32 lnch;
	Sint32 lbps;
	Sint32 lnsmpl;
    
    if (ibuflen < 8) 
    {
        *dlen = 0;
        
        return -1;
    }
    
    dt = AU_GetInfo(ibuf, ibuflen, &lsfreq, &lnch, &lbps, &lnsmpl, cdc);
    
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

// 100% matching!
void ADXB_ExecOneAu8(ADXB adxb) 
{
	AdxDecPara *dp;
	Uint16 *pcmbuf;
	Uint16 *pcmbuf_l;
	Uint16 *pcmbuf_r;
	Uint8 *ibuf;
	Sint32 i;
	Sint32 ndata;

    dp = &adxb->dp;

    ibuf = (Uint8*)dp->ibuf;
    
    if ((adxb->stat == 1) && (ADXPD_GetStat(adxb->xpd) == 0)) 
    {
        adxb->getwrfunc(adxb->getwrobj, &adxb->dp.wpos, &adxb->dp.nroom, &adxb->dp.lp_nsmpl);

        ndata = dp->pcmbsize - dp->wpos;
        
        ndata = (dp->nroom < ndata) ? dp->nroom : ndata;
        ndata = (dp->niblk < ndata) ? dp->niblk : ndata;

        pcmbuf = (Uint16*)dp->pcmbuf;
        
        pcmbuf_l = pcmbuf + dp->wpos;
        
        if (adxb->nch == 2) 
        {
            pcmbuf_r = pcmbuf + (dp->pcmbdist + dp->wpos);
            
            for (i = 0; i < ndata; i++) 
            {
                pcmbuf_l[i] = ibuf[i * 2] * 256;
                pcmbuf_r[i] = ibuf[(i * 2) + 1] * 256;
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                pcmbuf_l[i] = ibuf[i] * 256;
            }
        }
        
        adxb->total_decsmpl = ndata;
        adxb->total_decdtlen = ndata * adxb->nch;
        
        adxb->stat = 2;
    }
    
    if (adxb->stat == 2)
    {
        adxb->addwrfunc(adxb->addwrobj, adxb->total_decdtlen, adxb->total_decsmpl);
        
        adxb->stat = 3;
    }
}

// 100% matching!
void ADXB_ExecOneAu16(ADXB adxb)
{
	AdxDecPara *dp;
	Uint16 *pcmbuf;
	Uint16 *pcmbuf_l;
	Uint16 *pcmbuf_r;
    Uint16 tmp;
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
        
        pcmbuf_l = pcmbuf + dp->wpos;
        
        if (adxb->nch == 2) 
        {
            pcmbuf_r = pcmbuf + (dp->pcmbdist + dp->wpos);
            
            for (i = 0; i < ndata; i++) 
            {
                tmp = ibuf[i * 2];
                
                pcmbuf_l[i] = (tmp / 256) | (tmp * 256);
                
                tmp = ibuf[(i * 2) + 1];
                
                pcmbuf_r[i] = (tmp / 256) | (tmp * 256);
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                tmp = ibuf[i];
                
                pcmbuf_l[i] = (tmp / 256) | (tmp * 256);
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

void ADXB_ExecOneAuUlaw(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAuUlaw - UNIMPLEMENTED!\n");
}

static void* AU_GetInfo(void *hdr, Sint32 hdrlen, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *cdc) 
{
    scePrintf("AU_GetInfo - UNIMPLEMENTED!\n");
}
