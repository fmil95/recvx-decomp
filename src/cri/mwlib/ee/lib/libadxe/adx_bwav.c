#include "adx_bwav.h"
#include "adx_xpnd.h"

#include <string.h>

// 100% matching!
Sint32 ADX_DecodeInfoWav(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc)
{
	WAVEFORMATEX *wfex;
	static Sint8 *fmt_id = (Sint8*)"fmt ";
	static Sint8 *data_id = (Sint8*)"data";
	Sint32 i;
	Sint32 wavsize;
    Uint8 *temp;

    for (i = 0; i < ibuflen; i++)
    {
        if (memcmp(&ibuf[i], fmt_id, 4) == 0) 
        {
            break;
        }
    }
    
    if (i == ibuflen)
    {
        return -1;
    }

    if ((i & 0x3))
    {
        return -1;
    }

    wfex = (WAVEFORMATEX*)&ibuf[i + 8];

    if (wfex->wFormatTag >= 2) 
    {
        return -1;
    }

    for (i = 0; i < ibuflen; i++)
    {
        if (memcmp(&ibuf[i], data_id, 4) == 0) 
        {
            break;
        }
    }

    if (i == ibuflen)
    {
        return -1;
    }

    temp = (Uint8*)&ibuf[i + 4];
    
    wavsize = temp[0] | (temp[1] << 8) | (temp[2] << 16) | (temp[3] << 24);

    *dlen = i + 8;
    
    *code = -1;

    temp = (Uint8*)&wfex->nSamplesPerSec;
    
    *sfreq = temp[0] | (temp[1] << 8) | (temp[2] << 16) | (temp[3] << 24);

    *nch = wfex->nChannels;
    
    *bps = wfex->wBitsPerSample;
    
    *blksize = wfex->nBlockAlign;
    
    *total_nsmpl = wavsize / *blksize;
    
    *nsmpl_blk = 1;

    if (*bps == 16)
    {
        *cdc = 0;
    }
    else if (*bps == 8)
    {
        *cdc = 1;
    }
    else if (*bps == 4) 
    {
        *blksize = *nch * 2;
        
        *nsmpl_blk = 4;
        
        *total_nsmpl = ((unsigned int)wavsize >> 1) / *nch;
        
        *bps = 16;
        
        *cdc = 2;
    }

    if (*bps == 0) 
    {
        return -1;
    }

    if (*blksize == 0) 
    {
        return -1;
    }

    if ((*nch != 1) && (*nch != 2)) 
    {
        return -1;
    }

    if (*sfreq == 0) 
    {
        return -1;
    }

    return 0;
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

// 100% matching!
void ADXB_ExecOneWav4(ADXB adxb) 
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
        
        pcmbuf_l = &pcmbuf[dp->wpos];
        
        if (adxb->nch == 2) 
        {
            pcmbuf_r = &pcmbuf[dp->pcmbdist + dp->wpos];
            
            for (i = 0; i < ndata; i++) 
            {
                pcmbuf_l[i] = ibuf[i * 4] | (ibuf[(i * 4) + 2] * 256);
                pcmbuf_r[i] = ibuf[(i * 4) + 1] | (ibuf[(i * 4) + 3] * 256);
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                pcmbuf_l[i] = ibuf[i * 2] | (ibuf[(i * 2) + 1] * 256);
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
void ADXB_ExecOneWav8(ADXB adxb)
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
        
        pcmbuf_l = &pcmbuf[dp->wpos];
        
        if (adxb->nch == 2) 
        {
            pcmbuf_r = &pcmbuf[dp->pcmbdist + dp->wpos];
            
            for (i = 0; i < ndata; i++) 
            {
                pcmbuf_l[i] = (ibuf[i * 2] - 128) * 256;
                pcmbuf_r[i] = (ibuf[(i * 2) + 1] - 128) * 256;
            }
        } 
        else 
        {
            for (i = 0; i < ndata; i++)
            {
                pcmbuf_l[i] = (ibuf[i] - 128) * 256;
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
void ADXB_ExecOneWav16(ADXB adxb)
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
