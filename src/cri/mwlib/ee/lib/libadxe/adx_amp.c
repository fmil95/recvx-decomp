
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

void adxamp_extract(ADXAMP amp);

static Sint32 adxsmp_init_cnt;
static ADX_AMP adxamp_obj[8];

// ADXAMP_Create

// 100% matching!
void ADXAMP_Destroy(ADXAMP amp) 
{
    if (amp != NULL)
    {
        ADXCRS_Lock();
        
        memset(amp, 0, sizeof(ADX_AMP));
        
        ADXCRS_Unlock();
    }
}

// 100% matching!
void ADXAMP_ExecHndl(ADXAMP amp) 
{
    if (amp->stat == 2)
    {
        adxamp_extract(amp);
    }
}

// 100% matching!
void ADXAMP_ExecServer(void)
{
    ADXAMP amp;
    Sint32 no;

    for (no = 0; no < 8; no++) 
    {
        amp = &adxamp_obj[no];
        
        if (amp->used == TRUE)
        {
            ADXAMP_ExecHndl(amp);
        }
    } 
}

void adxamp_extract(ADXAMP amp) 
{
	scePrintf("adxamp_extract - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXAMP_Finish(void) 
{
    if (--adxsmp_init_cnt == 0) 
    {
        memset(adxamp_obj, 0, sizeof(adxamp_obj));
    }
}

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

// 100% matching!
void ADXAMP_SetSfreq(ADXAMP amp, Sint32 sfreq) 
{
    amp->sfreq = sfreq;
}

// 100% matching!
void ADXAMP_Start(ADXAMP amp) 
{
    Sint32 chno;

    for (chno = 0; chno < amp->maxnch; chno++)
    {
        amp->total_exsmpl[chno] = 0;
    }
    
    amp->frm_no = 0;
    
    amp->stat = 2;
}

// 100% matching!
void ADXAMP_Stop(ADXAMP amp)
{
    amp->stat = 0;
}
