
/* There's little here of interest, most of these functions are thunks for the console-specific audio renderer code in ps2_rna. */

void ADXRNA_ClearBuf(ADXRNA adxrna);
ADXRNA ADXRNA_Create(SJ* sjo, Sint32 maxnch);
void ADXRNA_Destroy(ADXRNA adxrna);
Sint32 ADXRNA_DiscardData(ADXRNA rna, Sint32 nsmpl);
void ADXRNA_ExecServer(void);
void ADXRNA_Finish(void);
Sint32 ADXRNA_GetBitPerSmpl(ADXRNA adxrna);
Sint32 ADXRNA_GetNumData(ADXRNA adxrna);
Sint32 ADXRNA_GetNumRoom(ADXRNA adxrna);
Sint32 ADXRNA_GetOutPan(ADXRNA adxrna, Sint32 ch);
Sint32 ADXRNA_GetOutVol(ADXRNA adxrna);
Sint32 ADXRNA_GetSfreq(ADXRNA adxrna);
Sint32 ADXRNA_GetStat(ADXRNA adxrna);
void ADXRNA_GetTime(ADXRNA adxrna, Sint32 *ncount, Sint32 *tscale);
void ADXRNA_Init(void);
void ADXRNA_SetBitPerSmpl(ADXRNA adxrna, Sint32 bps);
void ADXRNA_SetNumChan(ADXRNA adxrna, Sint32 nch);
void ADXRNA_SetOutPan(ADXRNA adxrna, Sint32 ch, Sint32 pan);
void ADXRNA_SetOutVol(ADXRNA adxrna, Sint32 vol);
void ADXRNA_SetPcmType(ADXRNA adxrna, Sint32 type);
void ADXRNA_SetPlaySw(ADXRNA adxrna, Sint32 sw);
void ADXRNA_SetSfreq(ADXRNA adxrna, Sint32 sfreq);
void ADXRNA_SetStartSmpl(ADXRNA adxrna, Sint32 smpl);
Sint32 ADXRNA_SetStmHdInfo(ADXRNA adxrna, void* hinfo);
void ADXRNA_SetTotalNumSmpl(ADXRNA adxrna, Sint32 nsmpl);
void ADXRNA_SetTransSw(ADXRNA adxrna, Sint32 sw);
void ADXRNA_SetWavFname(ADXRNA adxrna, Char8* fname);
void ADXRNA_Start(ADXRNA adxrna);
void ADXRNA_Stop(ADXRNA adxrna);

// 100% matching!
void ADXRNA_ClearBuf(ADXRNA rna)
{

}

// 100% matching!
ADXRNA ADXRNA_Create(SJ *sj, Sint32 maxnch)
{
    return PS2RNA_Create(sj, maxnch);
}

// 100% matching!
void ADXRNA_Destroy(ADXRNA rna)
{
    PS2RNA_SetPlaySw(rna, 0);
    PS2RNA_SetTransSw(rna, 0);
    
    PS2RNA_Destroy(rna);
}

// 100% matching!
Sint32 ADXRNA_DiscardData(ADXRNA rna, Sint32 nsmpl)
{
    return PS2RNA_DiscardData(rna, nsmpl);
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
Sint32 ADXRNA_GetBitPerSmpl(ADXRNA rna) 
{
    return PS2RNA_GetBitPerSmpl(rna);
}

// 100% matching!
Sint32 ADXRNA_GetNumData(ADXRNA rna)
{
    return PS2RNA_GetNumData(rna);
}

// 100% matching!
Sint32 ADXRNA_GetNumRoom(ADXRNA rna) 
{
    return PS2RNA_GetNumRoom(rna);
}

// 100% matching!
Sint32 ADXRNA_GetOutPan(ADXRNA rna, Sint32 chno)
{
    return PS2RNA_GetOutPan(rna, chno);
}

// 100% matching!
Sint32 ADXRNA_GetOutVol(ADXRNA rna)
{
    return PS2RNA_GetOutVol(rna);
}

// 100% matching!
Sint32 ADXRNA_GetSfreq(ADXRNA rna)
{
    return PS2RNA_GetSfreq(rna);
}

// 100% matching!
Sint32 ADXRNA_GetStat(ADXRNA rna)
{
    printf("ADXRNA_GetStat: not implemented\n");
    
    while (TRUE);
}

// 100% matching!
void ADXRNA_GetTime(ADXRNA rna, Sint32 *ncount, Sint32 *tscale)
{
    PS2RNA_GetTime(rna, ncount, tscale);
}

// 100% matching!
void ADXRNA_Init(void)
{
    PS2RNA_Init();
}

// 100% matching!
void ADXRNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps)
{
    PS2RNA_SetBitPerSmpl(rna, bps);
}

// 100% matching!
void ADXRNA_SetNumChan(ADXRNA rna, Sint32 nch) 
{
    PS2RNA_SetNumChan(rna, nch);
}

// 100% matching!
void ADXRNA_SetOutPan(ADXRNA rna, Sint32 chno, Sint32 pan)
{
    PS2RNA_SetOutPan(rna, chno, pan);
}

// 100% matching!
void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol)
{
    PS2RNA_SetOutVol(rna, vol);
}

// 100% matching!
void ADXRNA_SetPcmType(ADXRNA rna, Sint32 type)
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
