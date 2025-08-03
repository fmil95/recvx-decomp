static Sint32 sjx_init_cnt;
static Sint32 sjx_wklen;
static void* sjx_eewk;
static Sint32 sjx_ee_work[564];
static void* sjx_iopwk;
static DTX sjx_dtx;

void sjx_rcvcbf(void* sjx, void* buf, Sint32 bfsize);
void sjx_sndcbf(void* sjx, void* buf, Sint32 bfsize);

void* SJX_Create(SJ sj, Sint8 *work, Sint32 wksize)
{
    scePrintf("SJX_Create - UNIMPLEMENTED!\n");
}

void SJX_Destroy(void* sjx)
{
    scePrintf("SJX_Destroy - UNIMPLEMENTED!\n");
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

void sjx_rcvcbf(void* sjx, void* buf, Sint32 bfsize)
{
    scePrintf("sjx_rcvcbf - UNIMPLEMENTED!\n");
}

// SJX_Reset

void sjx_sndcbf(void* sjx, void* buf, Sint32 bfsize)
{
    scePrintf("sjx_sndcbf - UNIMPLEMENTED!\n");
}
