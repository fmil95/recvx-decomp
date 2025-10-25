#define BSWAP_U16_EX(_val) (Uint16)(((_val & 0xFF00) >> 8) | ((_val << 8) & 0xFF00))

static ADX_BASIC adxb_obj[8] = { 0 };

void adxb_DefAddWr(void *obj, Sint32 wlen, Sint32 wnsmpl);
void* adxb_DefGetWr(void *obj, Sint32 *wpos, Sint32 *nroom, Sint32 *lp_nsmpl);
void ADXB_Destroy(ADXB adxb);
void memcpy2(Sint16 *dst, const Sint16 *src, Sint32 nword);

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

Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_DecodeHeaderAdx - UNIMPLEMENTED!\n");
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

// ADXB_EndDecode

// 100% matching!
void ADXB_EntryAddWrFunc(ADXB adxb, void (*func)(), void *obj)
{
    adxb->addwrfunc = func;
    adxb->addwrobj = obj;
}

void ADXB_EntryData(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_EntryData - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXB_EntryGetWrFunc(ADXB adxb, void* (*func)(), void *obj)
{
    adxb->getwrfunc = func;
    adxb->getwrobj = obj;
}

// ADXB_EvokeDecode
// ADXB_EvokeExpandMono
// ADXB_EvokeExpandSte

void ADXB_ExecHndl(ADXB adxb)
{
    scePrintf("ADXB_ExecHndl - UNIMPLEMENTED!\n");
}

// ADXB_ExecOneAdx
// ADXB_ExecServer

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

Sint32 ADXB_GetOutBps(ADXB adxb)
{
    scePrintf("ADXB_GetOutBps - UNIMPLEMENTED!\n");
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

// ADXB_Reset

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
