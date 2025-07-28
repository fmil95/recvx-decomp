

// 100% matching!
void ADXRNA_ClearBuf(void) 
{

}

// 100% matching!
ADXRNA ADXRNA_Create(SJ* sjo, Sint32 maxnch)
{
    return PS2RNA_Create(sjo, maxnch);
}

// 100% matching!
void ADXRNA_Destroy(ADXRNA adxrna)
{
    PS2RNA_SetPlaySw(adxrna, 0);
    PS2RNA_SetTransSw(adxrna, 0);
    
    PS2RNA_Destroy(adxrna);
}

// 100% matching!
Sint32 ADXRNA_DiscardData(void) 
{
    return PS2RNA_DiscardData();
}

// 100% matching!
void ADXRNA_ExecServer(void) 
{
    PS2RNA_ExecServer();
}

// 100% matching!
void ADXRNA_Finish(void)
{
    PS2RNA_Finish();
}

// 100% matching!
Sint32 ADXRNA_GetBitPerSmpl(ADXRNA adxrna) 
{
    return PS2RNA_GetBitPerSmpl(adxrna);
}

// 100% matching!
Sint32 ADXRNA_GetNumData(ADXRNA adxrna) 
{
    return PS2RNA_GetNumData(adxrna);
}

// 100% matching!
Sint32 ADXRNA_GetNumRoom(ADXRNA adxrna) 
{
    return PS2RNA_GetNumRoom(adxrna);
}

// ADXRNA_GetOutPan
// ADXRNA_GetOutVol
// ADXRNA_GetSfreq
// ADXRNA_GetStat
// ADXRNA_GetTime

// 100% matching!
void ADXRNA_Init(void)
{
    PS2RNA_Init();
}

// 100% matching!
void ADXRNA_SetBitPerSmpl(ADXRNA adxrna, Sint32 bps)
{
    PS2RNA_SetBitPerSmpl(adxrna, bps);
}

// 100% matching!
void ADXRNA_SetNumChan(ADXRNA adxrna, Sint32 nch) 
{
    PS2RNA_SetNumChan(adxrna, nch);
}

// 100% matching!
void ADXRNA_SetOutPan(ADXRNA adxrna, Sint32 ch, Sint32 pan) 
{
    PS2RNA_SetOutPan(adxrna, ch, pan);
}

// 100% matching!
void ADXRNA_SetOutVol(ADXRNA adxrna, Sint32 vol)
{
    PS2RNA_SetOutVol(adxrna, vol);
}

// 100% matching!
void ADXRNA_SetPcmType(ADXRNA adxrna, Sint32 type)
{

}

// 100% matching!
void ADXRNA_SetPlaySw(ADXRNA adxrna, Sint32 sw) 
{
    PS2RNA_SetPlaySw(adxrna, sw);
}

// 100% matching!
void ADXRNA_SetSfreq(ADXRNA adxrna, Sint32 sfreq) 
{
    PS2RNA_SetSfreq(adxrna, sfreq);
}

// 100% matching!
void ADXRNA_SetStartSmpl(ADXRNA adxrna, Sint32 smpl) 
{
    PS2RNA_SetStartSmpl(adxrna, smpl);
}

// 100% matching!
Sint32 ADXRNA_SetStmHdInfo(ADXRNA adxrna, void* hinfo) 
{
    PS2RNA_SetStmHdInfo(adxrna, hinfo);
    
    return 0;
}

// 100% matching!
void ADXRNA_SetTotalNumSmpl(ADXRNA adxrna, Sint32 nsmpl) 
{

}

// 100% matching!
void ADXRNA_SetTransSw(ADXRNA adxrna, Sint32 sw) 
{
    PS2RNA_SetTransSw(adxrna, sw);
}

// 100% matching!
void ADXRNA_SetWavFname(ADXRNA adxrna, Char8* fname)
{

}

// 100% matching!
void ADXRNA_Start(ADXRNA adxrna)
{
    PS2RNA_Start(adxrna);
}

// 100% matching!
void ADXRNA_Stop(ADXRNA adxrna) 
{
    PS2RNA_Stop(adxrna);
}
