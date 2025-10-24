static ADX_BASIC adxb_obj[8];

// ADXB_CopyExtraBufMono
// ADXB_CopyExtraBufSte

ADXB ADXB_Create(Sint32 maxnch, Sint16 *obuf, Sint32 bsize, Sint32 bdist)
{
    scePrintf("ADXB_Create - UNIMPLEMENTED!\n");
}

// ADXB_DecodeHeader
// ADXB_DecodeHeaderAdx
// adxb_DefAddWr
// adxb_DefGetWr

void ADXB_Destroy(ADXB adxb)
{
    scePrintf("ADXB_Destroy - UNIMPLEMENTED!\n");
}

// ADXB_EndDecode
// ADXB_EntryAddWrFunc

void ADXB_EntryData(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    scePrintf("ADXB_EntryData - UNIMPLEMENTED!\n");
}

void ADXB_EntryGetWrFunc(ADXB adxb, void* (*func)(), void *obj)
{
    scePrintf("ADXB_EntryGetWrFunc - UNIMPLEMENTED!\n");
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

// ADXB_GetDecDtLen
// ADXB_GetDecNumSmpl

Sint32 ADXB_GetFmtBps(ADXB adxb)
{
    scePrintf("ADXB_GetFmtBps - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetFormat(ADXB adxb)
{
    scePrintf("ADXB_GetFormat - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetLpEndOfst(ADXB adxb)
{
    scePrintf("ADXB_GetLpEndOfst - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetLpEndPos(ADXB adxb)
{
    scePrintf("ADXB_GetLpEndPos - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetLpInsNsmpl(ADXB adxb)
{
    scePrintf("ADXB_GetLpInsNsmpl - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetLpStartOfst(ADXB adxb)
{
    scePrintf("ADXB_GetLpStartOfst - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetLpStartPos(ADXB adxb)
{
    scePrintf("ADXB_GetLpStartPos - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetNumChan(ADXB adxb)
{
    scePrintf("ADXB_GetNumChan - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetNumLoop(ADXB adxb)
{
    scePrintf("ADXB_GetNumLoop - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetOutBps(ADXB adxb)
{
    scePrintf("ADXB_GetOutBps - UNIMPLEMENTED!\n");
}

Sint16* ADXB_GetPcmBuf(ADXB adxb)
{
    scePrintf("ADXB_GetPcmBuf - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetSfreq(ADXB adxb)
{
    scePrintf("ADXB_GetSfreq - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetStat(ADXB adxb)
{
    scePrintf("ADXB_GetStat - UNIMPLEMENTED!\n");
}

Sint32 ADXB_GetTotalNumSmpl(ADXB adxb)
{
    scePrintf("ADXB_GetTotalNumSmpl - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXB_Init(void) 
{
    ADXPD_Init();
    
    memset(adxb_obj, 0, sizeof(adxb_obj));
}

// ADXB_Reset

void ADXB_Start(ADXB adxb)
{
    scePrintf("ADXB_Start - UNIMPLEMENTED!\n");
}

void ADXB_Stop(ADXB adxb)
{
    scePrintf("ADXB_Stop - UNIMPLEMENTED!\n");
}

// memcpy2