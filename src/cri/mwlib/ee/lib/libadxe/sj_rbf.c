
typedef void (*SJRBF_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjrbf 
{
    SJ           sj;
    Sint32       used;
    UUID*        uuid;
    Sint32       datano;
    Sint32       unk10;
    void*        buf;
    Sint32       bfsize;
    Sint32       unk1C;
    Sint32       unk20;
    Sint32       unk24;
    SJRBF_ERRFN  err_func;
    void*        err_obj;
} SJRBF_OBJ;

typedef SJRBF_OBJ     *SJRBF;

static SJRBF_OBJ sjrbf_obj[64];
static Sint32 sjrbf_init_cnt;

SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize)
{
    scePrintf("SJRBF_Create - UNIMPLEMENTED!\n");
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

// SJRBF_GetBufPtr
// SJRBF_GetBufSize
// SJRBF_GetChunk
// SJRBF_GetNumData
// SJRBF_GetUuid
// SJRBF_GetXtrSize

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
// SJRBF_Reset
// SJRBF_UngetChunk
