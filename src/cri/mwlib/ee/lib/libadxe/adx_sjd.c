#include "adx_sjd.h"
#include "adx_bsc.h"
#include "sj_rbf.h"

static ADX_SJDEC adxsjd_obj[8] = { 0 };

// 100% matching!
void adxsjd_clear(ADXSJD sjd)
{
    sjd->dtrpsmpl = -1;
    
    sjd->maxdecsmpl = 0x7FFFFFFF;
    
    sjd->hdrlen = 0;
    
    sjd->total_decsmpl = 0;
    
    sjd->total_decdtlen = 0;
    
    sjd->decpos = 0;
    
    sjd->dtrpcnt = 0;
    
    sjd->dtrpdtlen = 0;
    
    sjd->empty_end = 0;
}

// 100% matching!
ADXSJD ADXSJD_Create(SJ sji, Sint32 maxnch, SJ *sjo)
{
    ADXSJD sjd;
	Sint32 no;
	Sint32 i;
	Sint16 *obuf;
	Sint32 bsize;
	SJRBF sjrbf;

    sjrbf = (SJRBF)sjo[0];

    for (i = 0; i < 8; i++) 
    {
        if (adxsjd_obj[i].used == FALSE) 
        {
            break;
        }
    }
    
    if (i == 8)
    { 
        return NULL;
    }

    sjd = &adxsjd_obj[i];
    
    obuf = (Sint16*)SJRBF_GetBufPtr(sjrbf);
    
    bsize = (Uint32)SJRBF_GetBufSize(sjrbf) / 2;
    
    sjd->adxb = ADXB_Create(maxnch, obuf, bsize, bsize + (Uint32)SJRBF_GetXtrSize(sjrbf) / 2);

    ADXB_EntryGetWrFunc(sjd->adxb, adxsjd_get_wr, sjd);
    
    if (sjd->adxb == NULL) 
    {
        return NULL;
    }
    
    sjd->sji = sji;
    
    sjd->maxnch = maxnch;

    for (no = 0; no < maxnch; no++) 
    {
        sjd->sjo[no] = sjo[no];
    }

    sjd->stat = 0;
    
    adxsjd_clear(sjd);
    
    sjd->dtrpfunc = NULL;
    sjd->dtrpobj = NULL;
    
    sjd->dfltfunc = NULL;
    sjd->dfltobj = NULL;
    
    sjd->used = TRUE;
    
    return sjd;
}

// 100% matching!
void adxsjd_decexec_end(ADXSJD sjd) 
{
    ADXB adxb;
	SJCK ck;
	SJCK ck2;
	Sint32 dlen;
	Sint32 i;
	Sint32 ndecsmpl;
	Sint32 total_nsmpl;
	SJ sji;
    
    adxb = sjd->adxb;

    sji = sjd->sji;

    total_nsmpl = ADXB_GetTotalNumSmpl(adxb);

    dlen = ADXB_GetDecDtLen(adxb);

    ndecsmpl = ADXB_GetDecNumSmpl(adxb);
    
    total_nsmpl -= sjd->decpos;

    ndecsmpl = (ndecsmpl < total_nsmpl) ? ndecsmpl : total_nsmpl;
    
    SJ_SplitChunk(&sjd->cki, dlen, &ck, &ck2);
    
    SJ_PutChunk(sji, 0, &ck);
    
    SJ_UngetChunk(sji, 1, &ck2);

    for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) 
    {
        SJ_SplitChunk(&sjd->cko[i], ndecsmpl * 2, &ck, &ck2);

        if (sjd->dfltfunc != NULL) 
        {
            sjd->dfltfunc(sjd->dfltobj, i, ck.data, ck.len);
        }

        SJ_PutChunk(sjd->sjo[i], 1, &ck);
        
        SJ_UngetChunk(sjd->sjo[i], 0, &ck2);
    }

    sjd->total_decsmpl += ndecsmpl;
    sjd->total_decdtlen += dlen;
    
    sjd->decpos += ndecsmpl;
    
    sjd->dtrpcnt += ndecsmpl;
    sjd->dtrpdtlen += dlen;

    if (((sjd->dtrpsmpl >= 0) && (sjd->dtrpcnt >= sjd->dtrpsmpl)) && (sjd->dtrpfunc != NULL)) 
    {
        sjd->dtrpfunc(sjd->dtrpobj);
    }
    
    ADXB_Reset(adxb);
}

// 100% matching!
void adxsjd_decexec_start(ADXSJD sjd) 
{
    ADXB adxb;
	SJ sji;
	Sint32 blksmpl;
	Sint32 nroom;
    
    adxb = sjd->adxb;

    sji = sjd->sji;
    
    if ((sjd->empty_end == 1) && (SJ_GetNumData(sji, 1) == 0)) 
    {
        sjd->stat = 3;
        return;
    }

    SJ_GetChunk(sji, 1, SJCK_LEN_MAX, &sjd->cki);

    if ((ADXB_GetFormat(adxb) == 0) && ((sjd->cki.len >= 2) && (BSWAP_U16_EX(*(Uint16*)sjd->cki.data) == 0x8001))) 
    {
        sjd->stat = 3;
        
        SJ_UngetChunk(sji, 1, &sjd->cki);
        return;
    }

    if (sjd->decpos >= ADXSJD_GetTotalNumSmpl(sjd)) 
    {
        sjd->stat = 3;
        
        SJ_UngetChunk(sji, 1, &sjd->cki);
        return;
    }

    blksmpl = ADXSJD_GetBlkSmpl(sjd);
    
    nroom = (Uint32)SJ_GetNumData(sjd->sjo[0], 0) / 2;

    if (nroom < blksmpl) 
    {
        SJ_UngetChunk(sji, 1, &sjd->cki);
        return;   
    }
    
    ADXB_EntryData(adxb, sjd->cki.data, sjd->cki.len);
    
    ADXB_Start(adxb);
}

// 100% matching!
void adxsjd_decode_exec(ADXSJD sjd)
{
    ADXB adxb;

    adxb = sjd->adxb;
    
    if (ADXB_GetStat(adxb) == 0) 
    {
        adxsjd_decexec_start(sjd);
    }
    
    ADXB_ExecHndl(adxb);
    
    if (ADXB_GetStat(adxb) == 3) 
    {
        adxsjd_decexec_end(sjd);
    }
}

// 100% matching!
void adxsjd_decode_prep(ADXSJD sjd)
{
    ADXB adxb;
	SJ sji;
	SJCK ck;
	SJCK ck2;
	Sint32 len;
	Sint32 fmt;
    
    sji = sjd->sji;
    
    adxb = sjd->adxb;

    SJ_GetChunk(sji, 1, 4096, &ck);

    if (ck.len < 16)
    {
        SJ_UngetChunk(sji, 1, &ck);
        return;
    }

    len = ADXB_DecodeHeader(adxb, ck.data, ck.len);

    if ((len == 0) || (ck.len < len)) 
    {
        SJ_UngetChunk(sji, 1, &ck);
        return;
    }

    sjd->hdrlen = len;

    fmt = ADXB_GetFormat(adxb);

    if (fmt == 4)
    {
        sjd->empty_end = 1;
    }

    fmt = ADXB_GetFormat(adxb);

    if (fmt == 2)
    {
        memcpy(sjd->spsdinfo, ck.data, (ck.len > (Sint32)sizeof(sjd->spsdinfo)) ? (Sint32)sizeof(sjd->spsdinfo) : ck.len);
    }

    SJ_SplitChunk(&ck, len, &ck, &ck2);

    SJ_PutChunk(sji, 0, &ck);
    
    SJ_UngetChunk(sji, 1, &ck2);

    sjd->stat = 2;
}

// 100% matching!
void ADXSJD_Destroy(ADXSJD sjd) 
{
    ADXB adxb;

    if (sjd != NULL) 
    {
        adxb = sjd->adxb;

        if (adxb != NULL) 
        {
            ADXB_Destroy(adxb);
        }
    
        ADXCRS_Lock();
        
        memset(sjd, 0, sizeof(ADX_SJDEC));
        
        ADXCRS_Unlock();
    }
}

// 100% matching!
void ADXSJD_EntryFltFunc(ADXSJD sjd, void (*f)(), void *obj)
{
    sjd->dfltfunc = f;
    sjd->dfltobj = obj;
}

// 100% matching!
void ADXSJD_EntryTrapFunc(ADXSJD sjd, void (*f)(), void *obj)
{
    sjd->dtrpfunc = f;
    sjd->dtrpobj = obj;
}

// 100% matching!
void ADXSJD_ExecHndl(ADXSJD sjd)
{
    if (sjd->stat == 2)
    {
        adxsjd_decode_exec(sjd);
    } 
    else if (sjd->stat == 1)
    {
        adxsjd_decode_prep(sjd);
    }
}

// 100% matching!
void ADXSJD_ExecServer(void) 
{
    ADXSJD sjd;
    Sint32 no;

    for (no = 0; no < 8; no++) 
    {
        sjd = &adxsjd_obj[no];
        
        if (sjd->used == TRUE) 
        {
            ADXSJD_ExecHndl(sjd);
        }
    }
}

// 100% matching!
void ADXSJD_Finish(void)
{
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

// 100% matching!
void* adxsjd_get_wr(void *obj, Sint32 *wpos, Sint32 *nroom, Sint32 *lp_nsmpl) 
{
    ADXSJD sjd;
    SJRBF sjrbf;
	Sint32 i;
	Sint32 tmp;
    Sint32 tmp2; 

    sjd = obj;

    sjrbf = (SJRBF)sjd->sjo[0];

    for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) 
    {
        SJ_GetChunk(sjd->sjo[i], 0, 16384, &sjd->cko[i]);
    }
    
    *wpos = (Uint32)(sjd->cko[0].data - SJRBF_GetBufPtr(sjrbf)) / 2;
    
    tmp = (Uint32)sjd->cko[0].len / 2;
    
    tmp2 = sjd->maxdecsmpl;

    if (tmp < tmp2)
    {
        tmp2 = tmp;
    }
    
    *nroom = tmp2;

    if (sjd->dtrpsmpl >= 0) 
    {
        *lp_nsmpl = sjd->dtrpsmpl - sjd->dtrpcnt;
    } 
    else 
    {
        *lp_nsmpl = 0x1FFFFFFF;
    }
    
    return ADXB_GetPcmBuf(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetBlkLen(ADXSJD sjd)
{
    return ADXB_GetBlkLen(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetBlkSmpl(ADXSJD sjd)
{
    return ADXB_GetBlkSmpl(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetCof(ADXSJD sjd)
{
    return ADXB_GetCof(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetDecDtLen(ADXSJD sjd) 
{
    return sjd->total_decdtlen;
}

// 100% matching!
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD sjd) 
{
    return sjd->total_decsmpl;
}

// 100% matching!
Sint32 ADXSJD_GetDecPos(ADXSJD sjd) 
{
    return sjd->decpos;
}

// 100% matching!
Sint32 ADXSJD_GetFmtBps(ADXSJD sjd)
{
    return ADXB_GetFmtBps(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetFormat(ADXSJD sjd)
{
    return ADXB_GetFormat(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetHdrLen(ADXSJD sjd)
{
    return sjd->hdrlen;
}

// 100% matching!
Sint32 ADXSJD_GetLpEndOfst(ADXSJD sjd)
{
    return ADXB_GetLpEndOfst(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetLpEndPos(ADXSJD sjd)
{
    return ADXB_GetLpEndPos(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetLpInsNsmpl(ADXSJD sjd)
{
    return ADXB_GetLpInsNsmpl(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetLpStartOfst(ADXSJD sjd)
{
    return ADXB_GetLpStartOfst(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetLpStartPos(ADXSJD sjd)
{
    return ADXB_GetLpStartPos(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetNumChan(ADXSJD sjd)
{
    return ADXB_GetNumChan(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetNumLoop(ADXSJD sjd)
{
    return ADXB_GetNumLoop(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetOutBps(ADXSJD sjd)
{
    return ADXB_GetOutBps(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetSfreq(ADXSJD sjd)
{
    return ADXB_GetSfreq(sjd->adxb);
}

// 100% matching!
void* ADXSJD_GetSpsdInfo(ADXSJD sjd)
{
    return sjd->spsdinfo;
}

// 100% matching!
Sint32 ADXSJD_GetStat(ADXSJD sjd)
{
    return sjd->stat;
}

// 100% matching!
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd)
{
    return ADXB_GetTotalNumSmpl(sjd->adxb);
}

// 100% matching!
Sint32 ADXSJD_GetTrapCnt(ADXSJD sjd)
{
    return sjd->dtrpcnt;
}

// 100% matching!
Sint32 ADXSJD_GetTrapDtLen(ADXSJD sjd)
{
    return sjd->dtrpdtlen;
}

// 100% matching!
Sint32 ADXSJD_GetTrapNumSmpl(ADXSJD sjd)
{
    return sjd->dtrpsmpl;
}

// 100% matching!
void ADXSJD_Init(void) 
{
    ADXB_Init();
    
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

// 100% matching!
void ADXSJD_SetDecPos(ADXSJD sjd, Sint32 decpos) 
{
    sjd->decpos = decpos;
}

// 100% matching!
void ADXSJD_SetInSj(ADXSJD sjd, SJ sj)
{
    sjd->sji = sj;
}

// 100% matching!
void ADXSJD_SetMaxDecSmpl(ADXSJD sjd, Sint32 nsmpl)
{
    sjd->maxdecsmpl = nsmpl;
}

// 100% matching!
void ADXSJD_SetOutSj(ADXSJD sjd, Sint32 chno, SJ sj)
{
    sjd->sjo[chno] = sj;
}

// 100% matching!
void ADXSJD_SetTrapCnt(ADXSJD sjd, Sint32 nsmpl)
{
    sjd->dtrpcnt = nsmpl;
}

// 100% matching!
void ADXSJD_SetTrapDtLen(ADXSJD sjd, Sint32 nbyte)
{
    sjd->dtrpdtlen = nbyte;
}

// 100% matching!
void ADXSJD_SetTrapNumSmpl(ADXSJD sjd, Sint32 nsmpl)
{
    sjd->dtrpsmpl = nsmpl;
}

// 100% matching!
void ADXSJD_Start(ADXSJD sjd)
{
    adxsjd_clear(sjd);
    
    sjd->stat = 1;
}

// 100% matching!
void ADXSJD_Stop(ADXSJD sjd) 
{
    ADXB_Stop(sjd->adxb);
    
    sjd->stat = 0;
}
