
typedef struct 
{ 
	Sint8 used;
	Sint8 stat;
	Sint8 maxnch;
	Sint8 rsrv;
	SJ sji[2];
	SJ sjo[2];
	Sint32 total_exsmpl[2];
	Sint32 nch;
	Sint32 sfreq;
	Float32 frm_len;
	Float32 frm_prd;
	Sint32 frm_no;
} ADX_AMP;

typedef ADX_AMP *ADXAMP;

// ADXAMP_Create

void ADXAMP_Destroy(void* adxamp)
{
    scePrintf("ADXAMP_Destroy - UNIMPLEMENTED!\n");
}

// ADXAMP_ExecHndl
// ADXAMP_ExecServer
// adxamp_extract
// ADXAMP_Finish

// 100% matching! 
Sint32 ADXAMP_GetExtractNumSmpl(ADXAMP amp) 
{
    return amp->total_exsmpl[0];
}

// ADXAMP_GetFrmLen
// ADXAMP_GetFrmPrd
// ADXAMP_GetSfreq
// ADXAMP_GetStat
// ADXAMP_Init
// ADXAMP_SetFrmLen
// ADXAMP_SetFrmPrd
// ADXAMP_SetSfreq
// ADXAMP_Start
// ADXAMP_Stop
