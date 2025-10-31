#ifndef _ADX_AMP_H_
#define _ADX_AMP_H_

#include <cri_mw.h>

typedef struct 
{ 
	Sint32 val;
	Sint32 time;
	Sint32 tunit;
	Sint32 frmlen;
} ADXAMP_VAL;

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

ADXAMP ADXAMP_Create(Sint32 maxnch, SJ *sji, SJ *sjo);
void ADXAMP_Destroy(ADXAMP amp);
void ADXAMP_ExecHndl(ADXAMP amp);
void ADXAMP_ExecServer(void);
void adxamp_extract(ADXAMP amp);
void ADXAMP_Finish(void);
Sint32 ADXAMP_GetExtractNumSmpl(ADXAMP amp);
Float32 ADXAMP_GetFrmLen(ADXAMP amp);
Float32 ADXAMP_GetFrmPrd(ADXAMP amp);
Sint32 ADXAMP_GetSfreq(ADXAMP amp);
Sint32 ADXAMP_GetStat(ADXAMP amp);
void ADXAMP_Init(void);
void ADXAMP_SetFrmLen(ADXAMP amp, Float32 len_sec);
void ADXAMP_SetFrmPrd(ADXAMP amp, Float32 prd_sec);
void ADXAMP_SetSfreq(ADXAMP amp, Sint32 sfreq);
void ADXAMP_Start(ADXAMP amp);
void ADXAMP_Stop(ADXAMP amp);

#endif
