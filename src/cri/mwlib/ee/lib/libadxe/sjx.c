
typedef struct _sjx 
{
    Sint8   used;
    Sint8   unk1;
    Sint16  unk2;
    SJ      sj;
    void*   work;
    Sint32  wksize;
    Sint32  urpc;
} SJX_OBJ;

typedef SJX_OBJ       *SJX;

typedef struct _sjx_work
{
    Sint8   unk0;
    Sint8   id;
    Sint16  unk2;
    SJX     sjx;
    SJCK    ck;
} SJX_WORK_OBJ; 

typedef SJX_WORK_OBJ   *SJX_WORK;

typedef struct _sjx_buf
{
    Sint32        size;
    Sint32        unk4;
    Sint32        unk8;
    Sint32        unkC;
    SJX_WORK_OBJ  wk[0];
} SJX_BUF_OBJ;

typedef SJX_BUF_OBJ   *SJX_RCVCBF;
typedef SJX_BUF_OBJ   *SJX_SNDCBF;

static SJX_OBJ sjx_obj[16] = { 0 };
static Sint32 sjx_init_cnt;
static Sint32 sjx_wklen;
static void* sjx_eewk;
static Sint32 sjx_ee_work[564] = { 0 };
static void* sjx_iopwk;
static DTX sjx_dtx;

void sjx_rcvcbf(SJX sjx, SJX_RCVCBF buf, Sint32 bfsize);
void sjx_sndcbf(SJX sjx, SJX_SNDCBF buf, Sint32 bfsize);

// 100% matching!
SJX SJX_Create(SJ sj, Sint8 *work, Sint32 wksize) 
{
    SJX sjx;
    Sint32 i;
    Sint32 sbuf[4];

    for (i = 0; i < 16; i++) 
    {
        sjx = &sjx_obj[i];

        if (sjx->used == FALSE) 
        {
            break;
        }
    }
    
    if (i == 16) 
    {
        return NULL;
    }

    memset(sjx, 0, sizeof(SJX_OBJ));
    
    sjx->wksize = wksize;
    
    sjx->sj = sj;
    
    sjx->work = work;
    
    sbuf[0] = (Sint32)sj;
    sbuf[1] = (Sint32)work;
    sbuf[2] = wksize;
    sbuf[3] = (Sint32)sjx;
    
    sjx->urpc = DTX_CallUrpc(0, sbuf, 4, sbuf, 1);
    
    if (sjx->urpc == 0) 
    {
        printf("E0100401: can't create SJX of IOP\n");
        
        return NULL;
    }

    sjx->used = TRUE;
    
    return sjx;
}

// 100% matching!
void SJX_Destroy(SJX sjx)
{
    Sint32 sbuf[1];

    sbuf[0] = sjx->urpc;
    
    DTX_CallUrpc(1, sbuf, 1, NULL, 0);
    
    sjx->used = FALSE;
}

// 100% matching!
void SJX_ExecServer(void) 
{
    DTX_ExecServer();
}

// 100% matching!
void SJX_Finish(void) 
{
    sjx_init_cnt--;
}

// 100% matching!
void SJX_Init(void)
{
    if (sjx_init_cnt == 0)
    {
        DTX_Init();
        
        sjx_wklen = 2176;
        
        sjx_eewk = (void*)(((Uint32)sjx_ee_work + 64) & ~0x3F);

        if (sjx_iopwk == NULL) 
        {
            sjx_iopwk = sceSifAllocIopHeap(2256);

            if (sjx_iopwk == NULL) 
            {
                printf("E0100301: SJX_Init can't allocate IOP Heap\n");
                
                while (TRUE);
            }
        }

        sjx_iopwk = (void*)(((Uint32)sjx_iopwk + 64) & ~0x3F);
        
        sjx_dtx = DTX_Create(0, sjx_eewk, sjx_iopwk, sjx_wklen);

        if (sjx_dtx == NULL) 
        {
            printf("E0100302: SJX_Init can't create DTX\n");
            
            while (TRUE);
        }

        DTX_SetRcvCbf(sjx_dtx, sjx_rcvcbf, 0);
        DTX_SetSndCbf(sjx_dtx, sjx_sndcbf, 0);
    }

    sjx_init_cnt++;
}

// 100% matching!
void sjx_rcvcbf(SJX sjx, SJX_RCVCBF buf, Sint32 bfsize) 
{
    SJX_WORK cur;
    Sint32 size;
    Sint32 i;

    if (buf == NULL) 
    {
        while (TRUE);
    }

    size = buf->size;
    
    SJCRS_Lock();

    for (i = 0; i < size; i++) 
    {
        cur = &buf->wk[i];

        if ((cur->unk0 == 0) && (cur->unk2 == cur->sjx->unk2))
        {
            SJ_PutChunk(cur->sjx->sj, cur->id, &cur->ck);
        }
    }

    SJCRS_Unlock();
}

// 100% matching!
void SJX_Reset(SJX sjx)
{
    Sint32 sbuf[2];

    sbuf[0] = sjx->urpc;
    sbuf[1] = (Sint16)++sjx->unk2;
    
    DTX_CallUrpc(2, sbuf, 2, NULL, 0);
}

// 100% matching!
void sjx_sndcbf(SJX sjx, SJX_SNDCBF buf, Sint32 bfsize) 
{
    SJX _sjx;
    SJX_WORK cur;
    SJCK ck;
    Sint32 i;
    Sint32 j;
    
    cur = buf->wk;
    
    j = 0;

    SJCRS_Lock();

    for (i = 0; i < 16; i++)
    {
        _sjx = &sjx_obj[i];
        
        if (_sjx->used == TRUE) 
        {
            for ( ; ; j++) 
            {
                if (j == 128) 
                {
                    goto end;
                }
    
                SJ_GetChunk(_sjx->sj, _sjx->wksize, SJCK_LEN_MAX, &ck);
    
                if (ck.len == 0)
                {
                    break;
                }
    
                cur[j].unk0 = 0;
                
                cur[j].sjx = (SJX)_sjx->urpc;
                
                cur[j].id = _sjx->wksize;
                
                cur[j].ck = ck;
                
                cur[j].unk2 = _sjx->unk2; 
            }
        }
    }

end:
    SJCRS_Unlock();  
    
    buf->size = j;
}
