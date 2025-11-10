#include "adx_bsc.h"
#include "adx_baif.h"
#include "adx_bau.h"
#include "adx_bsps.h"
#include "adx_bwav.h"
#include "adx_dcd.h"
#include "adx_dcd3.h"
#include "adx_xpnd.h"

#include <string.h>

ADX_BASIC adxb_obj[8] = { 0 };

// 100% matching!
void ADXB_CopyExtraBufMono(Sint16 *obuf, Sint32 obsize, Sint32 xsize, Sint32 nxsmpl)
{
    memcpy2(obuf, &obuf[obsize], nxsmpl);
}

// 100% matching!
void ADXB_CopyExtraBufSte(Sint16 *obuf, Sint32 obsize, Sint32 obdist, Sint32 nxsmpl)
{
    memcpy2(obuf, &obuf[obsize], nxsmpl);
    memcpy2(&obuf[obdist], &obuf[obdist + obsize], nxsmpl);
}

// 100% matching!
ADXB ADXB_Create(Sint32 maxnch, Sint16 *obuf, Sint32 bsize, Sint32 bdist)
{
    Sint32 no;
	ADXB adxb1;
    ADXB adxb2;

    for (no = 0; no < 8; no++)
    {
        adxb1 = &adxb_obj[no];
        
        if (adxb1->used == FALSE) 
        {  
            break;
        }
    }

    if (no == 8)
    {
        return NULL;
    }

    adxb2 = &adxb_obj[no];
    
    memset(adxb2, 0, sizeof(ADX_BASIC));
    
    adxb2->used = TRUE;
    
    adxb2->xpd = ADXPD_Create();

    if (adxb2->xpd == NULL) 
    {
        ADXB_Destroy(adxb2);
        
        return NULL;
    }

    adxb2->maxnch = maxnch;
    
    adxb2->pcmbuf = obuf;
    
    adxb2->pcmbsize = bsize;
    adxb2->pcmbdist = bdist;
    
    adxb2->getwrfunc = adxb_DefGetWr;
    adxb2->addwrfunc = adxb_DefAddWr;
    
    adxb2->getwrobj = adxb2;
    adxb2->addwrobj = adxb2;
    
    return adxb2;
}

// 100% matching!
Sint32 ADXB_DecodeHeader(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    if (BSWAP_U16_EX(*(Uint16*)ibuf) == 0x8000) 
    {
        return ADXB_DecodeHeaderAdx(adxb, ibuf, ibuflen);
    }
    else if (ADXB_CheckSpsd(ibuf) != 0) 
    {
        return ADXB_DecodeHeaderSpsd(adxb, ibuf, ibuflen);
    }
    else if (ADXB_CheckWav(ibuf) != 0) 
    {
        return ADXB_DecodeHeaderWav(adxb, ibuf, ibuflen);
    }
    else if (ADXB_CheckAiff(ibuf) != 0) 
    {
        return ADXB_DecodeHeaderAiff(adxb, ibuf, ibuflen);
    }
    else if (ADXB_CheckAu(ibuf) != 0) 
    {
        return ADXB_DecodeHeaderAu(adxb, ibuf, ibuflen);
    }
    
    return 0;
}

// 100% matching!
Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    Sint16 dlen;

    adxb->hdcdflag = 1;

    if (ADX_DecodeInfo(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen, &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl) < 0)
    {
        return 0;
    }
    
    if (ADX_DecodeInfoExADPCM2(ibuf, ibuflen, &adxb->cof) < 0) 
    {
        return 0;
    }
    
    ADXPD_SetCoef(adxb->xpd, adxb->sfreq, adxb->cof);
    
    ADX_DecodeInfoExLoop(ibuf, ibuflen, &adxb->lp_ins_nsmpl, &adxb->nloop, &adxb->lp_type, &adxb->lp_spos, &adxb->lp_sofst, &adxb->lp_epos, &adxb->lp_eofst);

    adxb->fmttype = 0;
    
    adxb->curwpos = 0;
    
    adxb->dp.nch = adxb->nch;
    
    adxb->dp.blksize = adxb->blklen;
    adxb->dp.blknsmpl = adxb->blknsmpl;
    
    adxb->dp.pcmbuf = (Sint8*)adxb->pcmbuf;
    
    adxb->dp.pcmbsize = adxb->pcmbsize;
    adxb->dp.pcmbdist = adxb->pcmbdist;
    
    adxb->unk7C = adxb->unk48; // no idea what these fields are, they aren't referenced anywhere else
    adxb->unk7E = adxb->unk4A;
 
    adxb->unk80 = (Sint32)&adxb->unk4C; 

    memset((void*)adxb->unk80, 0, sizeof(Sint32));

    return dlen;
}

// 100% matching!
void adxb_DefAddWr(void *obj, Sint32 wlen, Sint32 wnsmpl)
{
    ADXB adxb;

    adxb = obj;
    
    adxb->curwpos += wnsmpl;
    
    adxb->total_ndecsmpl += wnsmpl;
}

// 100% matching!
void* adxb_DefGetWr(void *obj, Sint32 *wpos, Sint32 *nroom, Sint32 *lp_nsmpl)
{
    ADXB adxb;

    adxb = obj;
    
    *wpos = adxb->curwpos;
    
    *nroom = adxb->pcmbsize - adxb->curwpos;
    
    *lp_nsmpl = adxb->total_nsmpl - adxb->total_ndecsmpl;
    
    return adxb->pcmbuf;
}

// 100% matching!
void ADXB_Destroy(ADXB adxb)
{
    if (adxb != NULL) 
    {
        ADXPD_Destroy(adxb->xpd);
        
        memset(adxb, 0, sizeof(ADX_BASIC));
        
        adxb->used = FALSE;
    }
}

// 100% matching!
void ADXB_EndDecode(ADXB adxb)
{
	AdxDecPara *dp;
	Sint32 blknsmpl;
	Sint32 blksize;
	Sint32 lppos;
	Sint32 wpos;
	Sint16 *pcmbuf;
	Sint32 pcmbsize;
	Sint32 pcmbdist;
	Sint32 ndecblk;
	Sint32 ndecsmpl;
	Sint32 ndelsmpl;
    
    dp = &adxb->dp;

    blknsmpl = dp->blknsmpl;
    blksize = dp->blksize;

    lppos = dp->lp_nsmpl;

    pcmbuf = (Sint16*)dp->pcmbuf;

    pcmbsize = adxb->pcmbsize;
    pcmbdist = adxb->pcmbdist;
    
    wpos = dp->wpos;
    
    ndecsmpl = ((dp->lp_nsmpl + blknsmpl) - 1) % blknsmpl;
    ndelsmpl = (blknsmpl - 1) - ndecsmpl;
    
    lppos = ((dp->lp_nsmpl + blknsmpl) - 1) / blknsmpl;

    ndecblk = ADXPD_GetNumBlk(adxb->xpd);
    
    blknsmpl = (ndecblk * blknsmpl) / dp->nch;
    
    ndecsmpl = (ndecblk < lppos) ? blknsmpl : blknsmpl - ndelsmpl;
    
    adxb->total_decsmpl = ndecsmpl;
    adxb->total_decdtlen = ndecblk * blksize;
    
    wpos += adxb->total_decsmpl;
    
    if (wpos >= pcmbsize) 
    {
        wpos -= pcmbsize;
        
        if (dp->nch == 2) 
        {
            ADXB_CopyExtraBufSte(pcmbuf, pcmbsize, pcmbdist, wpos);
        } 
        else
        {
            ADXB_CopyExtraBufMono(pcmbuf, pcmbsize, pcmbdist, wpos);
        }
    }
}

// 100% matching!
void ADXB_EntryAddWrFunc(ADXB adxb, void (*func)(), void *obj)
{
    adxb->addwrfunc = func;
    adxb->addwrobj = obj;
}

// 100% matching!
void ADXB_EntryData(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    if (adxb->fmttype == 0) 
    {
        adxb->dp.ibuf = ibuf;
        
        adxb->dp.niblk = ibuflen / adxb->blklen;
        
        adxb->ndecsmpl = 0;

        adxb->total_decsmpl = 0;
        adxb->total_decdtlen = 0;
    } 
    else 
    {
        adxb->dp.ibuf = ibuf;
        
        adxb->dp.niblk = ibuflen / ((adxb->bps / 8) * adxb->nch);
        
        adxb->ndecsmpl = 0;
        
        adxb->total_decsmpl = 0;
        adxb->total_decdtlen = 0;
    }
}

// 100% matching!
void ADXB_EntryGetWrFunc(ADXB adxb, void* (*func)(), void *obj)
{
    adxb->getwrfunc = func;
    adxb->getwrobj = obj;
}

// 100% matching!
void ADXB_EvokeDecode(ADXB adxb)
{
	AdxDecPara *dp;
	Sint32 pcmbsize;
	Sint32 lppos;
	Sint32 ndelsmpl;
	Sint32 nroom;
	Sint32 nendblk;
	Sint32 nendsmpl;
	Sint32 wpos;
	Sint32 niblk;
	Sint32 blknsmpl;
    Sint32 temp;

    dp = &adxb->dp;

    niblk = dp->niblk / dp->nch;
    
    pcmbsize = dp->pcmbsize;
    
    wpos = dp->wpos;
    
    nroom = dp->nroom;
    
    blknsmpl = dp->blknsmpl;
    
    lppos = dp->lp_nsmpl;
    
    ndelsmpl = ((lppos + blknsmpl) - 1) / blknsmpl;
    
    nendsmpl = ((lppos + blknsmpl) - 1) % blknsmpl;
    nendsmpl = (blknsmpl - 1) - nendsmpl;
    
    nendblk = (((pcmbsize - wpos) + blknsmpl) - 1) / blknsmpl;
    
    temp = nendblk * blknsmpl;
    
    if ((ndelsmpl < nendblk) && (((wpos + temp) - nendsmpl) < pcmbsize)) 
    {
        nendblk++;
    }

    if (lppos < nroom) 
    { 
        nroom += nendsmpl;
    }

    niblk = MIN(nroom / blknsmpl, niblk);
    niblk = MIN(ndelsmpl, niblk);
    niblk = MIN(nendblk, niblk);
    
    if (dp->nch == 2) 
    {
        ADXB_EvokeExpandSte(adxb, niblk);
    } 
    else 
    {
        ADXB_EvokeExpandMono(adxb, niblk);
    }
}

// 100% matching!
void ADXB_EvokeExpandMono(ADXB adxb, Sint32 nblk) 
{
	AdxDecPara *dp;
	ADXPD xpd;
	Sint16 *obuf_l;

    dp = &adxb->dp;

    xpd = adxb->xpd;

    obuf_l = (Sint16*)dp->pcmbuf;
    
    obuf_l += dp->wpos;
    
    ADXPD_EntryMono(xpd, dp->ibuf, nblk, obuf_l);
    
    ADXPD_Start(xpd);
}

// 100% matching!
void ADXB_EvokeExpandSte(ADXB adxb, Sint32 nblk)
{
	AdxDecPara *dp;
	ADXPD xpd;
	Sint16 *obuf_l;

    dp = &adxb->dp;

    xpd = adxb->xpd;
    
    obuf_l = (Sint16*)dp->pcmbuf;
    
    obuf_l += dp->wpos;
    
    ADXPD_EntrySte(xpd, dp->ibuf, nblk * 2, obuf_l, obuf_l + dp->pcmbdist);
    
    ADXPD_Start(xpd);
}

// 100% matching!
void ADXB_ExecHndl(ADXB adxb) 
{
    if (adxb->fmttype == 0) 
    {
        ADXB_ExecOneAdx(adxb);
    } 
    else if (adxb->fmttype == 2) 
    {
        ADXB_ExecOneSpsd(adxb);
    } 
    else if (adxb->fmttype == 3)
    {
        ADXB_ExecOneAiff(adxb);
    } 
    else if (adxb->fmttype == 4) 
    {
        ADXB_ExecOneAu(adxb);
    } 
    else if (adxb->fmttype == 1) 
    {
        ADXB_ExecOneWav(adxb);
    }
}

// 100% matching!
void ADXB_ExecOneAdx(ADXB adxb) 
{
    if (adxb->stat == 1)
    {
        if (ADXPD_GetStat(adxb->xpd) == 0) 
        {
            adxb->getwrfunc(adxb->getwrobj, &adxb->dp.wpos, &adxb->dp.nroom, &adxb->dp.lp_nsmpl);
            
            ADXB_EvokeDecode(adxb);
            
            adxb->stat = 2;
        }
    }
    
    if (adxb->stat == 2) 
    {
        ADXPD_ExecHndl(adxb->xpd);
        
        if (ADXPD_GetStat(adxb->xpd) == 3) 
        {
            ADXB_EndDecode(adxb);
            
            ADXPD_Reset(adxb->xpd);
            
            adxb->addwrfunc(adxb->addwrobj, adxb->total_decdtlen, adxb->total_decsmpl);
            
            adxb->stat = 3;
        }
    }
}

// 100% matching!
void ADXB_ExecServer(void) 
{
    ADXB adxb;
	Sint32 no;
    
    for (no = 0; no < 8; no++) 
    {
        adxb = &adxb_obj[no];
        
        if (adxb->used == TRUE)
        {
            ADXB_ExecHndl(adxb);
        }
    }
}

// 100% matching!
ADXPD ADXB_GetAdxpd(ADXB adxb) 
{
    return adxb->xpd;
}

// 100% matching!
Sint32 ADXB_GetBlkLen(ADXB adxb)
{
    return adxb->blklen;
}

// 100% matching!
Sint32 ADXB_GetBlkSmpl(ADXB adxb)
{
    return adxb->blknsmpl;
}

// 100% matching!
Sint32 ADXB_GetCof(ADXB adxb)
{
    return adxb->cof;
}

// 100% matching!
Sint32 ADXB_GetDecDtLen(ADXB adxb) 
{
    return adxb->total_decdtlen;
}

// 100% matching!
Sint32 ADXB_GetDecNumSmpl(ADXB adxb)
{
    return adxb->total_decsmpl;
}

// 100% matching!
Sint32 ADXB_GetFmtBps(ADXB adxb)
{
    return adxb->bps;
}

// 100% matching!
Sint32 ADXB_GetFormat(ADXB adxb)
{
    return adxb->fmttype;
}

// 100% matching!
Sint32 ADXB_GetLpEndOfst(ADXB adxb)
{
    return adxb->lp_eofst;
}

// 100% matching!
Sint32 ADXB_GetLpEndPos(ADXB adxb)
{
    return adxb->lp_epos;
}

// 100% matching!
Sint32 ADXB_GetLpInsNsmpl(ADXB adxb)
{
    return adxb->lp_ins_nsmpl;
}

// 100% matching!
Sint32 ADXB_GetLpStartOfst(ADXB adxb)
{
    return adxb->lp_sofst;
}

// 100% matching!
Sint32 ADXB_GetLpStartPos(ADXB adxb) 
{
    return adxb->lp_spos;
}

// 100% matching!
Sint32 ADXB_GetNumChan(ADXB adxb)
{
    return adxb->nch;
}

// 100% matching!
Sint32 ADXB_GetNumLoop(ADXB adxb)
{
    return adxb->nloop;
}

// 100% matching!
Sint32 ADXB_GetOutBps(ADXB adxb)
{
    if (adxb->fmttype == 0) 
    {
        return 16;
    }

    if (adxb->fmttype == 2)
    {
        if (adxb->cdctype == 2)
        {
            return 4;
        } 
        else if (adxb->cdctype == 1) 
        {
            return 8;
        }
        
        return 16;
    }
    else if (adxb->fmttype == 1) 
    {
        return (adxb->cdctype != 2) ? 16 : 4;
    }
    
    return 16;
}

// 100% matching!
Sint16* ADXB_GetPcmBuf(ADXB adxb)
{
    return adxb->pcmbuf;
}

// 100% matching!
Sint32 ADXB_GetSfreq(ADXB adxb)
{
    return adxb->sfreq;
}

// 100% matching!
Sint32 ADXB_GetStat(ADXB adxb)
{
    return adxb->stat;
}

// 100% matching!
Sint32 ADXB_GetTotalNumSmpl(ADXB adxb)
{
    return adxb->total_nsmpl;
}

// 100% matching!
void ADXB_Init(void) 
{
    ADXPD_Init();
    
    memset(adxb_obj, 0, sizeof(adxb_obj));
}

// 100% matching!
void ADXB_Reset(ADXB adxb)
{
    if (adxb->stat == 3) 
    {
        ADXPD_Reset(adxb->xpd);
        
        adxb->curwpos = 0;
        
        adxb->stat = 0;
    }
}

// 100% matching!
void ADXB_Start(ADXB adxb)
{
    if (adxb->stat == 0) 
    {
        adxb->stat = 1;
    }
}

// 100% matching!
void ADXB_Stop(ADXB adxb)
{
    ADXPD_Stop(adxb->xpd);
    
    adxb->stat = 0;
}

// 100% matching!
void memcpy2(Sint16 *dst, const Sint16 *src, Sint32 nword)
{
    for ( ; nword > 0; nword--) 
    {
        *dst++ = *src++;
    }
}
