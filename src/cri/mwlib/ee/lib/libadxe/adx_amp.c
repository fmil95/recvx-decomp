
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

static Sint32 adxsmp_init_cnt;
static ADX_AMP adxamp_obj[8];

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

// 100% matching! 
Float32 ADXAMP_GetFrmLen(ADXAMP amp)
{
    return amp->frm_len;
}

// 100% matching! 
Float32 ADXAMP_GetFrmPrd(ADXAMP amp) 
{
    return amp->frm_prd;
}

// 100% matching! 
Sint32 ADXAMP_GetSfreq(ADXAMP amp)
{
    return amp->sfreq;
}

// 100% matching! 
Sint32 ADXAMP_GetStat(ADXAMP amp)
{
    return amp->stat;
}

// 100% matching! 
void ADXAMP_Init(void) 
{
    if (adxsmp_init_cnt == 0) 
    {
        memset(adxamp_obj, 0, sizeof(adxamp_obj));
    }
    
    adxsmp_init_cnt++;
}

// 100% matching!
void ADXAMP_SetFrmLen(ADXAMP amp, Float32 len_sec) 
{
    amp->frm_len = len_sec;
}

// 100% matching!
void ADXAMP_SetFrmPrd(ADXAMP amp, Float32 prd_sec) 
{
    amp->frm_prd = prd_sec;
}

// ADXAMP_SetSfreq
// ADXAMP_Start
// ADXAMP_Stop
