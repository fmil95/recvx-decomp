#ifndef _ADX_RNAP_H_
#define _ADX_RNAP_H_

void ADXRNA_ClearBuf(ADXRNA rna);
ADXRNA ADXRNA_Create(SJ *sj, Sint32 maxnch);
void ADXRNA_Destroy(ADXRNA rna);
Sint32 ADXRNA_DiscardData(ADXRNA rna, Sint32 nsmpl);
void ADXRNA_ExecServer(void);
void ADXRNA_Finish(void);
Sint32 ADXRNA_GetBitPerSmpl(ADXRNA rna);
Sint32 ADXRNA_GetNumData(ADXRNA rna);
Sint32 ADXRNA_GetNumRoom(ADXRNA rna);
Sint32 ADXRNA_GetOutPan(ADXRNA rna, Sint32 chno);
Sint32 ADXRNA_GetOutVol(ADXRNA rna);
Sint32 ADXRNA_GetSfreq(ADXRNA rna);
Sint32 ADXRNA_GetStat(ADXRNA rna);
void ADXRNA_GetTime(ADXRNA rna, Sint32 *ncount, Sint32 *tscale);
void ADXRNA_Init(void);
void ADXRNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps);
void ADXRNA_SetNumChan(ADXRNA rna, Sint32 nch);
void ADXRNA_SetOutPan(ADXRNA rna, Sint32 chno, Sint32 pan);
void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol);
void ADXRNA_SetPcmType(ADXRNA rna, Sint32 type);
void ADXRNA_SetPlaySw(ADXRNA rna, Sint32 sw);
void ADXRNA_SetSfreq(ADXRNA rna, Sint32 sfreq);
void ADXRNA_SetStartSmpl(ADXRNA rna, Sint32 nsmpl);
Sint32 ADXRNA_SetStmHdInfo(ADXRNA rna, void *snddat);
void ADXRNA_SetTotalNumSmpl(ADXRNA rna, Sint32 nsmpl);
void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw);
void ADXRNA_SetWavFname(ADXRNA rna, const Sint8 *fname);
void ADXRNA_Start(ADXRNA rna);
void ADXRNA_Stop(ADXRNA rna);

#endif
