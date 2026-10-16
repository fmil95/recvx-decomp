#include "../../../cri/mwlib/ee/lib/libadxe/adx_rnap.h"
#include "../../../cri/mwlib/ee/lib/libadxe/ps2_rna.h"

#include <stdio.h>

// 100% byte-matching object! 

/* There's little of interest here, most of these functions are thunks for the console-specific audio renderer code in ps2_rna. */

void ADXRNA_Init(void)
{
    PS2RNA_Init();
}

void ADXRNA_Finish(void)
{
    PS2RNA_Finish();
}

ADXRNA ADXRNA_Create(SJ *sj, Sint32 maxnch)
{
    return PS2RNA_Create(sj, maxnch);
}

void ADXRNA_Destroy(ADXRNA rna)
{
    PS2RNA_SetPlaySw(rna, 0);
    PS2RNA_SetTransSw(rna, 0);
    
    PS2RNA_Destroy(rna);
}

void ADXRNA_Start(ADXRNA rna)
{
    PS2RNA_Start(rna);
}

void ADXRNA_Stop(ADXRNA rna)
{
    PS2RNA_Stop(rna);
}

void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw)
{
    PS2RNA_SetTransSw(rna, sw);
}

void ADXRNA_SetPlaySw(ADXRNA rna, Sint32 sw)
{
    PS2RNA_SetPlaySw(rna, sw);
}

void ADXRNA_GetTime(ADXRNA rna, Sint32 *ncount, Sint32 *tscale)
{
    PS2RNA_GetTime(rna, ncount, tscale);
}

Sint32 ADXRNA_GetNumData(ADXRNA rna)
{
    return PS2RNA_GetNumData(rna);
}

Sint32 ADXRNA_GetNumRoom(ADXRNA rna) 
{
    return PS2RNA_GetNumRoom(rna);
}

Sint32 ADXRNA_GetStat(ADXRNA rna)
{
    printf("ADXRNA_GetStat: not implemented\n");
    
    while (TRUE);
}

void ADXRNA_ExecServer(void) 
{
    PS2RNA_ExecServer();
}

void ADXRNA_SetStartSmpl(ADXRNA rna, Sint32 nsmpl) 
{
    PS2RNA_SetStartSmpl(rna, nsmpl);
}

void ADXRNA_SetNumChan(ADXRNA rna, Sint32 nch) 
{
    PS2RNA_SetNumChan(rna, nch);
}

void ADXRNA_SetSfreq(ADXRNA rna, Sint32 sfreq)
{
    PS2RNA_SetSfreq(rna, sfreq);
}

void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol)
{
    PS2RNA_SetOutVol(rna, vol);
}

void ADXRNA_SetOutPan(ADXRNA rna, Sint32 chno, Sint32 pan)
{
    PS2RNA_SetOutPan(rna, chno, pan);
}

void ADXRNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps)
{
    PS2RNA_SetBitPerSmpl(rna, bps);
}

Sint32 ADXRNA_GetSfreq(ADXRNA rna)
{
    return PS2RNA_GetSfreq(rna);
}

Sint32 ADXRNA_GetOutVol(ADXRNA rna)
{
    return PS2RNA_GetOutVol(rna);
}

Sint32 ADXRNA_GetOutPan(ADXRNA rna, Sint32 chno)
{
    return PS2RNA_GetOutPan(rna, chno);
}

Sint32 ADXRNA_GetBitPerSmpl(ADXRNA rna) 
{
    return PS2RNA_GetBitPerSmpl(rna);
}

Sint32 ADXRNA_DiscardData(ADXRNA rna, Sint32 nsmpl)
{
    return PS2RNA_DiscardData(rna, nsmpl);
}

void ADXRNA_ClearBuf(ADXRNA rna)
{

}

void ADXRNA_SetPcmType(ADXRNA rna, Sint32 type)
{

}

void ADXRNA_SetTotalNumSmpl(ADXRNA rna, Sint32 nsmpl)
{

}

void ADXRNA_SetWavFname(ADXRNA rna, const Sint8 *fname)
{

}

Sint32 ADXRNA_SetStmHdInfo(ADXRNA rna, void *snddat)
{
    PS2RNA_SetStmHdInfo(rna, snddat);
    
    return 0;
}
