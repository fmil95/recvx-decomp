
typedef void (*SJUNI_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjuni 
{
    SJ           sj;
    Sint8        used;
    Sint8        unk5;
    Sint8        unk6;
    Sint8        unk7;
    UUID*        uuid;
    Sint32       datano;
    Sint32       unk10;
    Sint32       unk14;
    Sint32       unk18;
    void*        buf;
    Sint32       bfsize;
    Sint32       xtrsize;
    SJUNI_ERRFN  err_func;
    void*        err_obj;
} SJUNI_OBJ;

typedef SJUNI_OBJ *SJUNI;

static SJUNI_OBJ sjuni_obj[64];
static Sint32 sjuni_init_cnt;

SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    scePrintf("SJUNI_Create - UNIMPLEMENTED!\n");
}

// 100% matching!
void SJUNI_Destroy(SJUNI sjuni)
{
    if (sjuni != NULL) 
    {
        memset(sjuni, 0, sizeof(SJUNI_OBJ)); 
        
        sjuni->used = FALSE;
    }
}

// 100% matching!
void SJUNI_EntryErrFunc(SJUNI sjuni, SJUNI_ERRFN func, void* obj) 
{
    sjuni->err_func = func;
    sjuni->err_obj = obj;
}

// 99.29% matching
void SJUNI_Error(void) 
{
    while (TRUE);
}

// 100% matching!
void SJUNI_Finish(void)
{
    if (--sjuni_init_cnt == 0) 
    { 
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }
}

// SJUNI_GetChunk
// SJUNI_GetNumChainPool
// SJUNI_GetNumChunk
// SJUNI_GetNumData
// SJUNI_GetUuid

void SJUNI_Init(void)
{
    scePrintf("SJUNI_Init - UNIMPLEMENTED!\n");
}

// SJUNI_IsGetChunk
// SJUNI_PutChunk
// SJUNI_Reset
// SJUNI_UngetChunk
