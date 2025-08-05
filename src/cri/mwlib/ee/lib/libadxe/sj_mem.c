
typedef void (*SJMEM_ERRFN)(void *obj, Char8 *msg);

typedef struct _sjmem 
{
    Sint8        unk0;
    Sint8        unk1;
    Sint8        unk2;
    Sint8        unk3;
    Sint32       unk4;
    Sint32       uuid;
    Sint32       unkC;
    Sint32       unk10;
    void*        buf;
    Sint32       bfsize;
    SJMEM_ERRFN  err_func;
    void*        err_obj;
} SJMEM_OBJ;

typedef SJMEM_OBJ     *SJMEM;

static Sint32 sjmem_init_cnt;
static SJMEM_OBJ sjmem_obj[32];

SJ SJMEM_Create(Sint8 *data, Sint32 bsize)
{
    scePrintf("SJMEM_Create - UNIMPLEMENTED!\n");
}

// 100% matching!
void SJMEM_Destroy(SJMEM sjmem) 
{
    if (sjmem != NULL) 
    {
        memset(sjmem, 0, sizeof(SJMEM_OBJ));
        
        sjmem->unk4 = 0;
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
Sint32 SJMEM_GetUuid(SJMEM sjmem)
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
// SJMEM_Reset
// SJMEM_UngetChunk
