static ADX_SJDEC adxsjd_obj[8];

void adxsjd_clear(ADXSJD sjd)
{
    scePrintf("adxsjd_clear - UNIMPLEMENTED!\n");
}

ADXSJD ADXSJD_Create(SJ sjf, Sint32 maxnch, SJ* sjo)
{
    scePrintf("ADXSJD_Create - UNIMPLEMENTED!\n");
}

// adxsjd_decexec_end
// adxsjd_decexec_start
// adxsjd_decode_exec
// adxsjd_decode_prep

void ADXSJD_Destroy(ADXSJD adxsjd)
{
    scePrintf("ADXSJD_Destroy - UNIMPLEMENTED!\n");
}

// ADXSJD_EntryFltFunc
// ADXSJD_EntryTrapFunc
// ADXSJD_ExecHndl
// ADXSJD_ExecServer

void ADXSJD_Finish(void)
{
    scePrintf("ADXSJD_Finish - UNIMPLEMENTED!\n");
}

// adxsjd_get_wr

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

// ADXSJD_GetCof
// ADXSJD_GetDecDtLen

Sint32 ADXSJD_GetDecNumSmpl(ADXSJD adxsjd)
{
    scePrintf("ADXSJD_GetDecNumSmpl - UNIMPLEMENTED!\n");
}

// ADXSJD_GetDecPos

Sint32 ADXSJD_GetFmtBps(ADXSJD adxsjd)
{
    scePrintf("ADXSJD_GetFmtBps - UNIMPLEMENTED!\n");
}

// ADXSJD_GetFormat

Sint32 ADXSJD_GetHdrLen(ADXSJD adxsjd)
{
    scePrintf("ADXSJD_GetHdrLen - UNIMPLEMENTED!\n");
}

// ADXSJD_GetLpEndOfst
// ADXSJD_GetLpEndPos
// ADXSJD_GetLpInsNsmpl
// ADXSJD_GetLpStartOfst
// ADXSJD_GetLpStartPos
// ADXSJD_GetNumChan
// ADXSJD_GetNumLoop
// ADXSJD_GetOutBps
// ADXSJD_GetSfreq
// ADXSJD_GetSpsdInfo
// ADXSJD_GetStat
// ADXSJD_GetTotalNumSmpl
// ADXSJD_GetTrapCnt
// ADXSJD_GetTrapDtLen
// ADXSJD_GetTrapNumSmpl

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
