#include "adx_bau.h"
#include "adx_xpnd.h"

#include <string.h>

static Sint16 ulaw_exp_table[256];

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

// 100% matching!
void ADXB_ExecOneAuUlaw(ADXB adxb)
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
                pcmbuf_l[i] = ulaw_exp_table[ibuf[i * 2]];
                pcmbuf_r[i] = ulaw_exp_table[ibuf[(i * 2) + 1]];
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                pcmbuf_l[i] = ulaw_exp_table[ibuf[i]];
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
static void* AU_GetInfo(void *hdr, Sint32 hdrlen, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl, Sint32 *cdc)
{
	Uint32 magic;
	Uint32 hdr_size;
	Uint32 data_size;
	Uint32 encoding;
	Uint8 *pdw;
    Sint32 temp, temp2;

    pdw = (Uint8*)hdr;

    magic = READ_INT32(pdw);
    
    pdw += 4;
    
    if ((magic != SD_IMAGIC) && (magic != SND_IMAGIC)) 
    {
        return NULL;
    }
    
    hdr_size = READ_INT32(pdw);
    hdr_size = BSWAP_U32(hdr_size);
    
    pdw += 4;
    
    if (hdrlen < (Sint32)hdr_size) 
    {
        return NULL;
    }
    
    data_size = READ_INT32(pdw);
    data_size = BSWAP_U32(data_size);
    
    pdw += 4;

    encoding = READ_INT32(pdw);
    encoding = BSWAP_U32(encoding);
    
    pdw += 4;
    
    switch (encoding) 
    {
    case 1:
        *cdc = 2;
        
        *bps = 8;
        break;
    case 2:
        *cdc = 1;
        
        *bps = 8;
        break;
    case 3:
        *cdc = 0;
        
        *bps = 16;
        break;
    default:
        return NULL;
    }
   
    temp = READ_INT32(pdw);
    
    *sfreq = BSWAP_S32(temp);
    
    pdw += 4;

    temp2 = READ_INT32(pdw);
    
    *nch = BSWAP_S32(temp2);
    
    pdw += 4;
    
    if (*cdc == 2) 
    {
        *nsmpl = data_size / *nch;
    }
    else if (*cdc == 1) 
    { 
        *nsmpl = data_size / *nch;
    }
    else if (*cdc == 0) 
    {
        *nsmpl = (data_size / 2) / *nch;
    }
    else
    { 
        *nsmpl = 0x7FFF0000;
    }
    
    return (void*)((Sint32)hdr + hdr_size); // TODO: simplify this line when adding GCC
}
