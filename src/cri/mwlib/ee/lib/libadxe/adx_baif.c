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

// 100% matching!
Sint32 ADXB_DecodeHeaderAiff(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
	Sint16 dlen;
    Sint32 temp;

    adxb->hdcdflag = 1;

    if (ADX_DecodeInfoAiff(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen, &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl) < 0) 
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
    
    adxb->fmttype = 3;
    
    if (adxb->bps == 8) 
    {
        adxb->cdctype = 1;
    }
    else 
    {
        adxb->cdctype = 0;
    }

    memset((void*)temp, 0, sizeof(Sint32));
    
    return dlen;
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

// 100% matching!
void ADXB_ExecOneAiff8(ADXB adxb) 
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
                pcmbuf_l[i] = ibuf[(i * 2) + 0] * 256;
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

void ADXB_ExecOneAiff16(ADXB adxb)
{
    scePrintf("ADXB_ExecOneAiff16 - UNIMPLEMENTED!\n");
}

static void* AIFF_GetInfo(void *hdr, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl)
{
    scePrintf("AIFF_GetInfo - UNIMPLEMENTED!\n");
}
