
typedef void (*SJMEM_ERRFN)(void *obj, Char8 *msg);

typedef struct _sjmem 
{
    SJ           sj;
    Sint32       used;
    Sint32*      uuid;
    Sint32       unkC;
    Sint32       unk10;
    void*        buf;
    Sint32       bfsize;
    SJMEM_ERRFN  err_func;
    void*        err_obj;
} SJMEM_OBJ;

typedef SJMEM_OBJ     *SJMEM;

static SJMEM_OBJ sjmem_obj[32];
static void* sjmem_vtbl[12];
static Sint32 sjmem_uuid[4];
static Sint32 sjmem_init_cnt;

void SJMEM_Error(void);
void SJMEM_Reset(SJMEM sjmem);

// 100% matching!
SJ SJMEM_Create(Sint8 *data, Sint32 bsize)
{
    SJMEM sjmem;
    Sint32 i;

    for (i = 0; i < 32; i++) 
    {
        if (sjmem_obj[i].used == FALSE) 
        {
            break;
        }
    }

    if (i == 32) 
    {
        return NULL;
    }

    sjmem = &sjmem_obj[i];
    
    sjmem->used = TRUE;
    
    sjmem->sj = (SJ)sjmem_vtbl;
    
    sjmem->buf = data;
    sjmem->bfsize = bsize;
    
    sjmem->uuid = sjmem_uuid;
    
    sjmem->err_func = (void*)SJMEM_Error;
    sjmem->err_obj = sjmem;
    
    SJMEM_Reset(sjmem);
    
    return (SJ)sjmem;
}

// 100% matching!
void SJMEM_Destroy(SJMEM sjmem) 
{
    if (sjmem != NULL) 
    {
        memset(sjmem, 0, sizeof(SJMEM_OBJ));
        
        sjmem->used = FALSE;
    }
}

// 100% matching!
void SJMEM_EntryErrFunc(SJMEM sjmem, SJMEM_ERRFN func, void* obj)
{
    sjmem->err_func = func;
    sjmem->err_obj = obj;
}

// 99.29% matching
void SJMEM_Error(void) 
{
    while (TRUE);
}

// 100% matching!
void SJMEM_Finish(void)
{
    if (--sjmem_init_cnt == 0)
    {
        memset(sjmem_obj, 0, sizeof(sjmem_obj));
    }
}

// 100% matching!
void* SJMEM_GetBufPtr(SJMEM sjmem) 
{
    return sjmem->buf;
}

// 100% matching!
Sint32 SJMEM_GetBufSize(SJMEM sjmem) 
{
    return sjmem->bfsize;
}

// SJMEM_GetChunk
// SJMEM_GetNumData

// 100% matching!
Sint32* SJMEM_GetUuid(SJMEM sjmem)
{
    return sjmem->uuid;
}

// 100% matching!
void SJMEM_Init(void) 
{
    if (sjmem_init_cnt == 0) 
    {
        memset(sjmem_obj, 0, sizeof(sjmem_obj));
    }
    
    sjmem_init_cnt++;
}

// SJMEM_IsGetChunk
// SJMEM_PutChunk

void SJMEM_Reset(SJMEM sjmem)
{
    scePrintf("SJMEM_Reset - UNIMPLEMENTED!\n");
}

// SJMEM_UngetChunk
