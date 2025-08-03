
typedef struct _sjx 
{
    Sint8   used;
    Sint8   unk1;
    Sint8   unk2;
    Sint8   unk3;
    SJ      sj;
    void*   work;
    Sint32  wksize;
    Sint32  urpc;
} SJX_OBJ;

typedef SJX_OBJ    *SJX;

static SJX_OBJ sjx_obj[16];
static Sint32 sjx_init_cnt;
static Sint32 sjx_wklen;
static void* sjx_eewk;
static Sint32 sjx_ee_work[564];
static void* sjx_iopwk;
static DTX sjx_dtx;

void sjx_rcvcbf(SJX sjx, void* buf, Sint32 bfsize);
void sjx_sndcbf(SJX sjx, void* buf, Sint32 bfsize);

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

void sjx_rcvcbf(SJX sjx, void* buf, Sint32 bfsize)
{
    scePrintf("sjx_rcvcbf - UNIMPLEMENTED!\n");
}

// SJX_Reset

void sjx_sndcbf(SJX sjx, void* buf, Sint32 bfsize)
{
    scePrintf("sjx_sndcbf - UNIMPLEMENTED!\n");
}
