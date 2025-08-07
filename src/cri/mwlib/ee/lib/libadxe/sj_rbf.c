
typedef void (*SJRBF_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjrbf 
{
    SJ           sj;
    Sint32       used;
    UUID*        uuid;
    Sint32       datano;
    Sint32       unk10;
    Sint32       unk14;
    Sint32       unk18;
    void*        buf;
    Sint32       bfsize;
    Sint32       xtrsize;
    SJRBF_ERRFN  err_func;
    void*        err_obj;
} SJRBF_OBJ;

typedef SJRBF_OBJ     *SJRBF;

static SJRBF_OBJ sjrbf_obj[64];
static SJ_IF sjrbf_vtbl;
static UUID sjrbf_uuid;
static Sint32 sjrbf_init_cnt;

void SJRBF_Error(void);
void SJRBF_Reset(SJRBF sjrbf);  

// 100% matching!
SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize) 
{
    SJRBF sjrbf;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < 64; i++)
    {
        if (sjrbf_obj[i].used == FALSE) 
        {
            break;
        }
    }

    if (i == 64) 
    {
        sjrbf = NULL;
    }
    else 
    {
        sjrbf = &sjrbf_obj[i];
        
        sjrbf->used = TRUE;
        
        sjrbf->sj = (SJ)&sjrbf_vtbl;
        
        sjrbf->buf = buf;
        
        sjrbf->bfsize = bsize;
        sjrbf->xtrsize = xsize;
        
        sjrbf->uuid = &sjrbf_uuid;
        
        sjrbf->err_func = (void*)SJRBF_Error;
        sjrbf->err_obj = sjrbf;
        
        SJRBF_Reset(sjrbf);
    }

    SJCRS_Unlock();
    
    return (SJ)sjrbf;
}

// 100% matching!
void SJRBF_Destroy(SJRBF sjrbf)
{
    SJCRS_Lock();
    
    if (sjrbf != NULL) 
    {
        memset(sjrbf, 0, sizeof(SJRBF_OBJ));
        
        sjrbf->used = FALSE;
    }
    
    SJCRS_Unlock();
}

// 100% matching!
void SJRBF_EntryErrFunc(SJRBF sjrbf, SJRBF_ERRFN func, void* obj) 
{
    sjrbf->err_func = func;
    sjrbf->err_obj = obj;
}

// 99.29% matching
void SJRBF_Error(void) 
{
    while (TRUE);
}

// 100% matching!
void SJRBF_Finish(void) 
{
    if (--sjrbf_init_cnt == 0) 
    {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }
}

// 100% matching!
void* SJRBF_GetBufPtr(SJRBF sjrbf)
{
    return sjrbf->buf;
}

// 100% matching!
Sint32 SJRBF_GetBufSize(SJRBF sjrbf) 
{
    return sjrbf->bfsize;
}

// SJRBF_GetChunk

// 100% matching!
Sint32 SJRBF_GetNumData(SJRBF sjrbf, Sint32 id)  
{
    if (id == 1) 
    {
        return sjrbf->datano;
    }
    else if (id == 0) 
    {
        return sjrbf->unk10;
    } 
    else if (sjrbf->err_func != NULL) 
    {
        sjrbf->err_func(sjrbf->err_obj, -3);
    }
    
    return 0;
}

// 100% matching!
UUID* SJRBF_GetUuid(SJRBF sjrbf)
{
    return sjrbf->uuid;
}

// 100% matching!
Sint32 SJRBF_GetXtrSize(SJRBF sjrbf) 
{
    return sjrbf->xtrsize;
}

// 100% matching!
void SJRBF_Init(void) 
{
    if (sjrbf_init_cnt == 0) 
    {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }
    
    sjrbf_init_cnt++;
}

// SJRBF_IsGetChunk
// SJRBF_PutChunk

// 100% matching!
void SJRBF_Reset(SJRBF sjrbf) 
{
    sjrbf->datano = 0;
    
    sjrbf->unk14 = 0;
    
    sjrbf->unk10 = sjrbf->bfsize;
    
    sjrbf->unk18 = 0; 
}

// SJRBF_UngetChunk
