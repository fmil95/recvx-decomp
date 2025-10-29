#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8))

static Uint32 adxt_svrcnt;
static Uint32 adxt_svrcnt_sjd;
static Uint32 adxt_svrcnt_rna;
static Uint32 adxt_svrcnt_hndl;
static Sint32 adxt_time_unit;
Sint32 adxt_time_mode;

void ADXT_StopWithoutLsc(ADXT adxt);

// 100% matching! 
void ADXT_ClearErrCode(ADXT adxt)
{
    adxt->ercode = ADXT_ERR_OK;
    
    adxt->edecpos = 0;
    adxt->edeccnt = 0;
    
    adxt->eshrtcnt = 0;
} 

// 100% matching! 
void ADXT_CloseAllHandles(void)
{
    ADXT_DestroyAll();
}

// 100% matching! 
ADXT ADXT_Create(Sint32 maxnch, void *work, Sint32 worksize)
{
    ADXT adxt;
	Sint32 no;
	Sint32 i;
	Sint8 *wk64;
	Sint32 wk64size;
    
    wk64 = (Sint8*)(((Uint32)work + (ADXT_MIN_BUFDATA - 1)) & ~(ADXT_MIN_BUFDATA - 1));
    
    wk64size = worksize - ((Sint32)wk64 - (Sint32)work);

    for (no = 0; no < ADXT_MAX_OBJ; no++) 
    {
        if (adxt_obj[no].used == FALSE) 
        {
            break;
        }
    }
    
    if (no == ADXT_MAX_OBJ) 
    {
        return NULL;
    }
    
    adxt = &adxt_obj[no];
    
    *adxt = (ADX_TALK){ 0 };

    adxt->maxnch = maxnch;
    
    adxt->ibuf = (Sint8*)(wk64 + ADXT_CALC_OBUFSIZE(maxnch));
    adxt->obuf = (Sint16*)wk64;
    
    adxt->ibufxlen = ADXT_IBUF_XLEN;
    
    adxt->obufsize = ADXT_OBUF_SIZE;
    adxt->obufdist = ADXT_OBUF_DIST;
   
    adxt->ibuflen = (((wk64size - ADXT_CALC_OBUFSIZE(maxnch)) - ADXT_IBUF_XLEN) / 2048) * 2048;

    adxt->sji = NULL;
    adxt->sjf = SJRBF_Create(adxt->ibuf, adxt->ibuflen, adxt->ibufxlen); 

    if (adxt->sjf == NULL)
    {
        ADXT_Destroy(adxt);
        
        return NULL;
    }

    for (i = 0; i < maxnch; i++) 
    {
        adxt->sjo[i] = SJRBF_Create((Sint8*)(adxt->obuf + (adxt->obufdist * i)), adxt->obufsize * 2, (adxt->obufdist - adxt->obufsize) * 2);

        if (adxt->sjo[i] == NULL) 
        {
            ADXT_Destroy(adxt);
            
            return NULL;
        }
    }

    adxt->sjd = ADXSJD_Create(adxt->sjf, maxnch, adxt->sjo);

    if (adxt->sjd == NULL) 
    {
        ADXT_Destroy(adxt);
        
        return NULL;
    }

    adxt->rna = ADXRNA_Create(adxt->sjo, maxnch);

    if (adxt->rna == NULL)
    {
        ADXT_Destroy(adxt);
        
        return NULL;
    }

    adxt->lsc = LSC_Create(adxt->sjf);

    if (adxt->lsc == NULL) 
    {
        ADXT_Destroy(adxt);
        
        return NULL;
    }

    adxt->maxsct = adxt->ibuflen / 2048;
    
    adxt->svrfreq = ADXT_DEF_SVRFREQ;
    
    adxt->minsct = adxt->maxsct * 1.23456789; 
    
    adxt->outvol = ADXT_DEF_OUTVOL;
    
    for (i = 0; i < maxnch; i++)
    {
        adxt->outpan[i] = ADXT_PAN_AUTO;
    }

    adxt->lpflg = 1;
    
    adxt->trp = 0;
    
    adxt->wpos = 0;
    
    adxt->mofst = 0;
    
    adxt->ercode = ADXT_ERR_OK;
    
    adxt->edecpos = 0;
    
    adxt->edeccnt = 0;
    adxt->eshrtcnt = 0;
    
    adxt->autorcvr = ADXT_RMODE_STOP;
    
    adxt->pause_flag = 0;
    
    adxt->time_ofst = 0;
    
    adxt->lnkflg = 1;
    
    adxt->used = TRUE;
    
    return adxt;
}

// 100% matching!
void ADXT_Destroy(ADXT adxt)
{
    Sint32 i;

    if (adxt != NULL)
    {
        if (adxt->used == TRUE) 
        {
            ADXT_Stop(adxt);
        }
    
        if (adxt->rna != NULL) 
        {
            ADXRNA_Destroy(adxt->rna);
        }
    
        if (adxt->sjd != NULL) 
        {
            ADXSJD_Destroy(adxt->sjd);
        }
    
        if (adxt->stm != NULL) 
        {
            ADXSTM_Close(adxt->stm);
        }
    
        ADXCRS_Lock();
    
        if (adxt->lsc != NULL)
        {
            LSC_Destroy(adxt->lsc);
        }
    
        if (adxt->sjf != NULL) 
        {
            adxt->sjf->vtbl->Destroy(adxt->sjf);
        }
    
        for (i = 0; i < adxt->maxnch; i++) 
        {
            if (adxt->sjo[i] != NULL) 
            {
                adxt->sjo[i]->vtbl->Destroy(adxt->sjo[i]);
            }
    
            if (adxt->ampsji[i] != NULL) 
            {
                adxt->ampsji[i]->vtbl->Destroy(adxt->ampsji[i]);
            }
    
            if (adxt->ampsjo[i] != NULL) 
            {
                adxt->ampsjo[i]->vtbl->Destroy(adxt->ampsjo[i]);
            }
        }
        
        if (adxt->amp != NULL) 
        {
            ADXAMP_Destroy(adxt->amp);
        }
    
        *adxt = (ADX_TALK){ 0 };
        
        adxt->used = FALSE;
    
        ADXCRS_Unlock();
    }
}

// 100% matching! 
void ADXT_DestroyAll(void)
{
    ADXT adxt;
    Sint32 i;

    for (i = 0; i < ADXT_MAX_OBJ; i++)
    {
        adxt = &adxt_obj[i];
        
        if (adxt->used == TRUE) 
        {
            ADXT_Destroy(adxt);
        }
    }
}

// 100% matching! 
Sint32 ADXT_DiscardSmpl(ADXT adxt, Sint32 nsmpl)
{
    Sint32 nd;
	Sint32 ncount;
	Sint32 tscale;

    if (adxt->pause_flag == 0)
    {
        return 0;
    }
    
    nd = ADXRNA_DiscardData(adxt->rna, nsmpl);
    
    ADXT_ExecServer();
    
    ADXRNA_GetTime(adxt->rna, &ncount, &tscale);
    
    adxt->svcnt = adxt_vsync_cnt;
    
    adxt->tvofst = (Sint32)(((float)ncount / tscale) * adxt_time_unit);
    
    return nd;
}

// 100% matching! 
void adxt_disp_rna_stat(ADXT adxt)
{
    PS2RNA rna;
	SJ sjiop;
	SJ sjtmp;
	Sint32 ntmp0;
	Sint32 ntmp2;
	Sint32 niop0;
	Sint32 niop2;
    Sint32 sum;
    Sint32 ttl;
    
    rna = adxt->rna;
    
    sjiop = PS2RNA_GetSjiop(rna, 0);
    sjtmp = PS2RNA_GetSjtmp(rna, 0);
    
    ntmp0 = SJ_GetNumData(sjtmp, 1);
    ntmp2 = SJ_GetNumData(sjtmp, 0);
    
    niop0 = SJRMT_GetNumData(sjiop, 1);
    niop2 = SJRMT_GetNumData(sjiop, 0);
    
    sum = ntmp0 + ntmp2;
    
    printf("ntmp0=%4d, ntmp2=%4d, sum=%4d\n", ntmp0, ntmp2, sum);
    
    sum = niop0 + niop2;
    
    printf("niop0=%4d, niop2=%4d, sum=%4d\n", niop0, niop2, sum);
    
    sum = ntmp0 + niop2;
    
    ttl = niop0 + ntmp2;
    
    printf("stat=%4d, ttl=%4d\n", adxt->stat, sum + ttl);
}

// 100% matching! 
void ADXT_EntryErrFunc(void (*func)(), void *obj)
{
    ADXERR_EntryErrFunc(func, obj);
}

// 100% matching! 
void ADXT_EntryFltFunc(ADXT adxt, void (*f)(), void *obj)
{
    ADXSJD_EntryFltFunc(adxt->sjd, f, obj);
}

// 100% matching!
void ADXT_ExecServer(void) 
{
    ADXT adxt;
    Sint32 no;

    ADXSJD_ExecServer();
    
    adxt_svrcnt_sjd = 0;
    
    ADXRNA_ExecServer();
    
    adxt_svrcnt_rna = 0;
    
    for (no = 0; no < ADXT_MAX_OBJ; no++)
    {
        adxt = &adxt_obj[no];
        
        if (adxt->used == TRUE) 
        {
            ADXT_ExecHndl(adxt);
        }
    }
    
    LSC_ExecServer();
    
    adxt_svrcnt_hndl = 0;
    
    adxt_svrcnt = 0;
}

// 100% matching! 
Sint32 ADXT_GetDecNumSmpl(ADXT adxt)
{
    return ADXSJD_GetDecNumSmpl(adxt->sjd);
}

// 100% matching! 
Sint32 ADXT_GetErrCode(ADXT adxt)
{
    return adxt->ercode;
}

// 100% matching! 
Sint32 ADXT_GetFmtBps(ADXT adxt)
{
    if (adxt->stat >= ADXT_STAT_PREP) 
    {
        return ADXSJD_GetFmtBps(adxt->sjd);
    }
    
    return 0;
}

// 100% matching! 
Sint32 ADXT_GetHdrLen(ADXT adxt)
{
    if (adxt->stat >= ADXT_STAT_PREP)
    {
        return ADXSJD_GetHdrLen(adxt->sjd);
    }
    
    return 0;
}

// 100% matching! 
float ADXT_GetIbufRemainTime(ADXT adxt) 
{
    Sint32 nbyte;
	Sint32 nch;
	float sfreq;
	float time;
    
    time = 0;
    
    if ((ADXT_GetStat(adxt) >= ADXT_STAT_PREP) && (adxt->sji != NULL))
    {
        nbyte = SJ_GetNumData(adxt->sji, 1);
        
        nch = ADXT_GetNumChan(adxt);
        
        sfreq = ADXT_GetSfreq(adxt);
        
        time = ((nbyte / (18 * nch)) * 32) / sfreq;
    }
    
    return time;
}

// 100% matching! 
SJ ADXT_GetInputSj(ADXT adxt)
{
    return adxt->sji;
}

// 100% matching! 
Sint32 ADXT_GetLnkSw(ADXT adxt)
{
    return adxt->lnkflg;
}

// 100% matching! 
Sint32 ADXT_GetLpCnt(ADXT adxt)
{
    return adxt->lpcnt;
}

// 100% matching! 
Sint32 ADXT_GetNumChan(ADXT adxt)
{
    if (adxt->stat >= ADXT_STAT_PREP) 
    {
        return ADXSJD_GetNumChan(adxt->sjd);
    }
    
    return 0;
}

// 100% matching! 
Sint32 ADXT_GetNumSctIbuf(ADXT adxt)
{
    if (adxt->sji != NULL) 
    {
        return SJ_GetNumData(adxt->sji, 1) / 2048;
    }
    
    return 0;
}

// ADXT_GetNumSmpl
// ADXT_GetNumSmplObuf
// ADXT_GetOutPan
// ADXT_GetOutVol
// ADXT_GetSfreq

// 100% matching!
Sint32 ADXT_GetStat(ADXT adxt)
{
    return adxt->stat;
}

void ADXT_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale)
{
    scePrintf("ADXT_GetTime - UNIMPLEMENTED!\n");
}

// ADXT_GetTimeReal
// ADXT_GetTimeSfreq
// ADXT_GetTimeSfreq2
// ADXT_InsertSilence

// 100% matching! 
Sint32 ADXT_IsCompleted(ADXT adxt)
{
    return adxt->stat == ADXT_STAT_PLAYEND;
}

// 100% matching! 
Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz)
{
    if (siz <= 1) 
    {
        return 0;
    }

    if (BSWAP_U16(adr) != 0x8001) 
    {
        return 0;
    }

    *endsiz = siz;

    return 1;
}

// 100% matching! 
Sint32 ADXT_IsHeader(Sint8 *adr, Sint32 siz, Sint32 *hdrsiz)
{
    Sint16 unk0;
    Sint8 unk1;
    Sint8 unk2;
    Sint8 unk3;
    Sint8 unk4;
    Sint32 unk5;
    Sint32 unk6;    
    Sint32 unk7;

    if (siz < 2) 
    {
        return 0;
    }
    
    if (BSWAP_U16(adr) != 0x8000) 
    {
        return 0;
    }
    
    if (ADX_DecodeInfo(adr, siz, &unk0, &unk1, &unk2, &unk3, &unk4, &unk5, &unk6, &unk7) < 0) 
    {  
        return 0;
    }
   
    *hdrsiz = unk0;
    
    return 1;
}

// 100% matching! 
Sint32 ADXT_IsIbufSafety(ADXT adxt)
{
    if (adxt->sji != NULL) 
    {
        return adxt->sji->vtbl->GetNumData(adxt->sji, 1) >= (adxt->minsct * ADXF_DEF_SCT_SIZE);
    }
    
    return FALSE;
}

// 100% matching! 
Sint32 ADXT_IsReadyPlayStart(ADXT adxt)
{
    return adxt->pstready_flag;
}

// 100% matching!
void ADXT_SetAutoRcvr(ADXT adxt, Sint32 rmode)
{
    adxt->autorcvr = rmode;
}

// 100% matching!
void ADXT_SetLnkSw(ADXT adxt, Sint32 sw)
{
    adxt->lnkflg = sw;
}

// 100% matching!
void ADXT_SetLpFlg(ADXT adxt, Sint32 flg)
{
    adxt->lpflg = flg;
}

// 100% matching!
void ADXT_SetOutPan(ADXT adxt, Sint32 ch, Sint32 pan)
{
    adxt->outpan[ch] = pan;
    
    if (ch < adxt->maxnch) 
    {
        ADXRNA_SetOutPan(adxt->rna, ch, pan);
    }
    else 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E8101208 ADXT_SetOutPan: parameter error");
    }
}

// 100% matching!
void ADXT_SetOutputMono(Sint32 flag)
{
    ADX_SetDecodeSteAsMonoSw(flag);
}

// 100% matching!
void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
    adxt->outvol = vol; 
    
    ADXRNA_SetOutVol(adxt->rna, vol);
}

// 100% matching!
Uint32 ADXT_SetPauseBuf(void) 
{
    return 16384;
}

// 100% matching! 
void ADXT_SetReloadSct(ADXT adxt, Sint32 minsct)
{
    adxt->minsct = minsct;
}

// 100% matching! 
void ADXT_SetReloadTime(ADXT adxt, float time, Sint32 nch, Sint32 sfreq)
{
    Sint32 ch;
    Sint32 sec;

    ch = nch * 18;
    
    sec = (((Sint32)(time * sfreq) / 32) * ch) / ADXF_DEF_SCT_SIZE;
    
    adxt->minsct = (sec < adxt->maxsct) ? sec : adxt->maxsct;
}

// 100% matching! 
void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq)
{
    adxt->svrfreq = freq;
}

// 100% matching! 
void ADXT_SetTimeMode(Sint32 mode)
{
    if (mode == 1) 
    {
        adxt_time_unit = 5994;
    }
    else if (mode == 2) 
    {
        adxt_time_unit = 5000;
    }
    
    adxt_time_mode = mode;
}

// 100% matching! 
void ADXT_SetTimeOfst(ADXT adxt, Sint32 ofst)
{
    adxt->time_ofst = ofst;
}

// 100% matching! 
void ADXT_SetWaitPlayStart(ADXT adxt, Sint32 flg)
{
    adxt->pstwait_flag = flg;
}

// 100% matching! 
void adxt_start_sj(ADXT adxt, SJ sj)
{
    Sint32 ch;

    for (ch = 0; ch < adxt->maxnch; ch++) 
    {
        adxt->sjo[ch]->vtbl->Reset(adxt->sjo[ch]);
    }

    ADXSJD_SetInSj(adxt->sjd, sj);
    
    adxt->sji = sj;
    
    ADXSJD_Start(adxt->sjd);
    
    adxt->stat = ADXF_STAT_STOP;
    
    adxt->lesct = 0x7FFFFFFF;
    
    adxt->trpnsmpl = -1;
    
    adxt->lpcnt = 0;
    
    adxt->pstready_flag = 0;
    
    adxt->tvofst = 0;
    
    adxt->svcnt = adxt_vsync_cnt;
}

// 100% matching! 
void adxt_start_stm(ADXT adxt) 
{
    ADXSTM_SetBufSize(adxt->stm, adxt->minsct * ADXF_DEF_SCT_SIZE, adxt->maxsct * ADXF_DEF_SCT_SIZE);
    ADXSTM_SetEos(adxt->stm, ADXT_PREP_RDSCT);
    
    ADXSTM_Start(adxt->stm);
    
    adxt_start_sj(adxt, adxt->sjf);
    
    adxt->pmode = ADXT_PMODE_FNAME;
}

// 100% matching! 
void ADXT_StartSj(ADXT adxt, SJ sj)
{
    Sint32 ch;

    ADXT_Stop(adxt);
    
    ADXCRS_Lock();

    for (ch = 0; ch < adxt->maxnch; ch++) 
    {
        adxt->sjo[ch]->vtbl->Reset(adxt->sjo[ch]);
    }

    ADXSJD_SetInSj(adxt->sjd, sj);
    
    adxt->sji = sj;
    
    ADXSJD_Start(adxt->sjd);
    
    adxt->pmode = ADXT_PMODE_SJ;
    
    adxt->lpcnt = 0;
    
    adxt->tvofst = 0;
    
    adxt->stat = ADXT_STAT_DECINFO;
    
    adxt->lnkflg = 1;
    
    adxt->svcnt = adxt_vsync_cnt;
    
    ADXCRS_Unlock();
}

// 100% matching! 
void ADXT_Stop(ADXT adxt)
{
    if (adxt->pmode == ADXT_PMODE_SLFILE) 
    {
        LSC_Stop(adxt->lsc);
        
        if (adxt->sji != NULL) 
        {
            adxt->sji->vtbl->Reset(adxt->sji);
        }
    }
    
    ADXT_StopWithoutLsc(adxt);
}

void ADXT_StopWithoutLsc(ADXT adxt)
{
    scePrintf("ADXT_StopWithoutLsc - UNIMPLEMENTED!\n");
}
