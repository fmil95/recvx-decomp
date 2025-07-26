// ADXRNA_ClearBuf

ADXRNA ADXRNA_Create(SJ* sjo, Sint32 maxnch)
{
    scePrintf("ADXRNA_Create - UNIMPLEMENTED!\n");
}

void ADXRNA_Destroy(ADXRNA adxrna)
{
    scePrintf("ADXRNA_Destroy - UNIMPLEMENTED!\n");
}

// ADXRNA_DiscardData
// ADXRNA_ExecServer

void ADXRNA_Finish(void)
{
    scePrintf("ADXRNA_Finish - UNIMPLEMENTED!\n");
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

// ADXRNA_SetBitPerSmpl
// ADXRNA_SetNumChan

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
// ADXRNA_SetTotalNumSmpl
// ADXRNA_SetTransSw
// ADXRNA_SetWavFname
// ADXRNA_Start
// ADXRNA_Stop