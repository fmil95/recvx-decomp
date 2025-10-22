
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

void adxamp_extract(ADXAMP amp);

static Sint32 adxsmp_init_cnt;
static ADX_AMP adxamp_obj[8] = { 0 };

// 100% matching!
ADXAMP ADXAMP_Create(Sint32 maxnch, SJ *sji, SJ *sjo) 
{
    ADXAMP amp;
	Sint32 no;
	Sint32 i;

    for (no = 0; no < 8; no++) 
    {
        if (adxamp_obj[no].used == FALSE)
        {
            break;
        }
    } 

    if (no != 8) 
    {
        ADXCRS_Lock();
        
        amp = &adxamp_obj[no];
        
        amp->maxnch = maxnch;
        
        for (i = 0; i < maxnch; i++) 
        {
            amp->sji[i] = sji[i];
            amp->sjo[i] = sjo[i]; 
            
            amp->total_exsmpl[i] = 0;
        } 
        
        amp->nch = maxnch;
        
        amp->sfreq = 44100;
        
        amp->stat = 0;
        
        amp->frm_no = 0; 
        
        amp->frm_len = 0.1f;
        amp->frm_prd = 0.1f;
        
        amp->used = TRUE;
        
        ADXCRS_Unlock(); 

        return amp;
    }
    
    return NULL;
}

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

// 100% matching!
void adxamp_extract(ADXAMP amp) 
{
    Sint32 insmpl;
	Sint32 nsmpl;
	Sint32 max;
	Sint32 nfrm;
	Sint32 frmlen;
	Sint32 i;
	Sint32 j;
	Sint32 k;
	Sint32 n;
	Sint32 tmp;
	SJCK ck;
	SJCK ck2;
	Sint16 *pcm;
	ADXAMP_VAL *aval;

    frmlen = amp->sfreq * amp->frm_len;
    
    for (i = 0; i < amp->nch; i++) 
    {
        insmpl = (unsigned int)SJ_GetNumData(amp->sji[i], 1) / 2; 
        
        insmpl /= frmlen;
        
        nfrm = (unsigned int)SJ_GetNumData(amp->sjo[i], 0) / 16;
        
        nfrm = (insmpl < nfrm) ? insmpl : nfrm;
        
        for (n = 0; n < nfrm; n++) 
        {
            max = 0;
            
            for (j = 0; j < frmlen; j += nsmpl) 
            {
                SJ_GetChunk(amp->sji[i], 1, (frmlen - j) * 2, &ck);
                
                nsmpl = (unsigned int)ck.len / 2;
                
                pcm = (Sint16*)ck.data;
                
                for (k = 0; k < nsmpl; k++, pcm++) 
                {
                    tmp = *pcm;
                    
                    if (tmp < 0) 
                    { 
                        tmp = -*pcm;
                    }
                    
                    if (tmp > max) 
                    {
                        max = tmp;
                    }
                }
                
                SJ_PutChunk(amp->sji[i], 0, &ck);
            }
            
            SJ_GetChunk(amp->sjo[i], 0, 16, &ck2);
            
            if (ck2.len == 0) 
            {
                while (TRUE);
            }
            
            aval = (ADXAMP_VAL*)ck2.data;
            
            aval->val = max;
            
            aval->time = amp->total_exsmpl[i];
            
            aval->tunit = amp->sfreq;
            
            aval->frmlen = frmlen;
            
            SJ_PutChunk(amp->sjo[i], 1, &ck2);
            
            amp->total_exsmpl[i] += frmlen;
            
            amp->frm_no++;
        }
    }
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
