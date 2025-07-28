// ADXRNA_ClearBuf

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

// ADXRNA_DiscardData
// ADXRNA_ExecServer

// 100% matching!
void ADXRNA_Finish(void)
{
    PS2RNA_Finish();
}

// ADXRNA_GetBitPerSmpl
// ADXRNA_GetNumData
// ADXRNA_GetNumRoom
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

// ADXRNA_SetPcmType
// ADXRNA_SetPlaySw
// ADXRNA_SetSfreq
// ADXRNA_SetStartSmpl
// ADXRNA_SetStmHdInfo

// 100% matching!
void ADXRNA_SetTotalNumSmpl(ADXRNA adxrna, Sint32 nsmpl) 
{

}

// ADXRNA_SetTransSw
// ADXRNA_SetWavFname

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
