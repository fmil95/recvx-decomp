#include "adx_bau.h"
#include "adx_xpnd.h"

#include <string.h>

static Sint16 ulaw_exp_table[256] = { 0x8284, 0x8684, 0x8A84, 0x8E84, 0x9284, 0x9684, 0x9A84, 0x9E84, 0xA284, 0xA684, 0xAA84, 0xAE84, 0xB284, 0xB684, 0xBA84, 0xBE84, 0xC184, 0xC384, 0xC584, 0xC784, 0xC984, 0xCB84, 0xCD84, 0xCF84, 0xD184, 0xD384, 0xD584, 0xD784, 0xD984, 0xDB84, 0xDD84, 0xDF84, 0xE104, 0xE204, 0xE304, 0xE404, 0xE504, 0xE604, 0xE704, 0xE804, 0xE904, 0xEA04, 0xEB04, 0xEC04, 0xED04, 0xEE04, 0xEF04, 0xF004, 0xF0C4, 0xF144, 0xF1C4, 0xF244, 0xF2C4, 0xF344, 0xF3C4, 0xF444, 0xF4C4, 0xF544, 0xF5C4, 0xF644, 0xF6C4, 0xF744, 0xF7C4, 0xF844, 0xF8A4, 0xF8E4, 0xF924, 0xF964, 0xF9A4, 0xF9E4, 0xFA24, 0xFA64, 0xFAA4, 0xFAE4, 0xFB24, 0xFB64, 0xFBA4, 0xFBE4, 0xFC24, 0xFC64, 0xFC94, 0xFCB4, 0xFCD4, 0xFCF4, 0xFD14, 0xFD34, 0xFD54, 0xFD74, 0xFD94, 0xFDB4, 0xFDD4, 0xFDF4, 0xFE14, 0xFE34, 0xFE54, 0xFE74, 0xFE8C, 0xFE9C, 0xFEAC, 0xFEBC, 0xFECC, 0xFEDC, 0xFEEC, 0xFEFC, 0xFF0C, 0xFF1C, 0xFF2C, 0xFF3C, 0xFF4C, 0xFF5C, 0xFF6C, 0xFF7C, 0xFF88, 0xFF90, 0xFF98, 0xFFA0, 0xFFA8, 0xFFB0, 0xFFB8, 0xFFC0, 0xFFC8, 0xFFD0, 0xFFD8, 0xFFE0, 0xFFE8, 0xFFF0, 0xFFF8, 0x0000, 0x7D7C, 0x797C, 0x757C, 0x717C, 0x6D7C, 0x697C, 0x657C, 0x617C, 0x5D7C, 0x597C, 0x557C, 0x517C, 0x4D7C, 0x497C, 0x457C, 0x417C, 0x3E7C, 0x3C7C, 0x3A7C, 0x387C, 0x367C, 0x347C, 0x327C, 0x307C, 0x2E7C, 0x2C7C, 0x2A7C, 0x287C, 0x267C, 0x247C, 0x227C, 0x207C, 0x1EFC, 0x1DFC, 0x1CFC, 0x1BFC, 0x1AFC, 0x19FC, 0x18FC, 0x17FC, 0x16FC, 0x15FC, 0x14FC, 0x13FC, 0x12FC, 0x11FC, 0x10FC, 0x0FFC, 0x0F3C, 0x0EBC, 0x0E3C, 0x0DBC, 0x0D3C, 0x0CBC, 0x0C3C, 0x0BBC, 0x0B3C, 0x0ABC, 0x0A3C, 0x09BC, 0x093C, 0x08BC, 0x083C, 0x07BC, 0x075C, 0x071C, 0x06DC, 0x069C, 0x065C, 0x061C, 0x05DC, 0x059C, 0x055C, 0x051C, 0x04DC, 0x049C, 0x045C, 0x041C, 0x03DC, 0x039C, 0x036C, 0x034C, 0x032C, 0x030C, 0x02EC, 0x02CC, 0x02AC, 0x028C, 0x026C, 0x024C, 0x022C, 0x020C, 0x01EC, 0x01CC, 0x01AC, 0x018C, 0x0174, 0x0164, 0x0154, 0x0144, 0x0134, 0x0124, 0x0114, 0x0104, 0x00F4, 0x00E4, 0x00D4, 0x00C4, 0x00B4, 0x00A4, 0x0094, 0x0084, 0x0078, 0x0070, 0x0068, 0x0060, 0x0058, 0x0050, 0x0048, 0x0040, 0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0010, 0x0008, 0x0000 };

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
