#include "sjx.h"

static Char8* volatile sjx_build = "\nSJX Ver 1.00 Build:Jan 26 2001 09:59:55\n";
static SJX_OBJ sjx_obj[16] = { 0 };
static Sint32 sjx_init_cnt;
static Sint32 sjx_wklen;
static void* sjx_eewk;
static Sint32 sjx_ee_work[564] = { 0 };
static void* sjx_iopwk;
static DTX sjx_dtx;

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
        
        sjx_eewk = (void*)(((Uint32)sjx_ee_work + 64) & ~0x3F); // simplify this line

        if (sjx_iopwk == NULL) 
        {
            sjx_iopwk = sceSifAllocIopHeap(2256);

            if (sjx_iopwk == NULL) 
            {
                printf("E0100301: SJX_Init can't allocate IOP Heap\n");
                
                while (TRUE);
            }
        }

        sjx_iopwk = (void*)(((Uint32)sjx_iopwk + 64) & ~0x3F); // same as above
        
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
    SJX_WORK sjxwk;
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
        sjxwk = &buf->wk[i];

        if ((sjxwk->unk0 == 0) && (sjxwk->unk2 == sjxwk->sjx->unk2))
        {
            SJ_PutChunk(sjxwk->sjx->sj, sjxwk->id, &sjxwk->ck);
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
void sjx_sndcbf(SJX sjx, SJX_SNDCBF buf, Sint32 bfsize) // it is likely that the first parameter is of a different type here
{
    SJX _sjx;
    SJX_WORK sjxwk;
    SJCK ck;
    Sint32 i;
    Sint32 j;
    
    sjxwk = buf->wk;
    
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
                    goto label;
                }
    
                SJ_GetChunk(_sjx->sj, _sjx->wksize, SJCK_LEN_MAX, &ck);
    
                if (ck.len == 0)
                {
                    break;
                }
    
                sjxwk[j].unk0 = 0;
                
                sjxwk[j].sjx = (SJX)_sjx->urpc;
                
                sjxwk[j].id = _sjx->wksize;   
                
                sjxwk[j].ck = ck;
                
                sjxwk[j].unk2 = _sjx->unk2; 
            }
        }
    }

label:
    SJCRS_Unlock();  
    
    buf->size = j;
}
