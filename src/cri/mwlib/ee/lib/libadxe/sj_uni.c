
typedef struct SJUNI_WORK 
{
    struct SJUNI_WORK  *next;
    Sint32             unk4;
    Sint32             unk8;
    Sint32             len;
} SJUNI_WORK_OBJ;

typedef SJUNI_WORK_OBJ *SJUNI_WORK;

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
    SJUNI_WORK   wk[4];
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

// 100% matching!
Sint32 SJUNI_GetNumData(SJUNI sjuni, Sint32 id)
{
    SJUNI_WORK cur;
    Sint32 datano;

    if ((Uint32)id >= 4) 
    {
        if (sjuni->err_func != NULL)
        {
            sjuni->err_func(sjuni->err_obj, -3);
        }
    
        return 0;
    }
    
    datano = 0;

    for (cur = sjuni->wk[id]; cur != NULL; cur = cur->next)
    {
        datano += cur->len; 
    } 

    return datano;
}

// 100% matching!
UUID* SJUNI_GetUuid(SJUNI sjuni) 
{
    return sjuni->uuid;
}

// 100% matching!
void SJUNI_Init(void) 
{ 
    if (sjuni_init_cnt == 0)
    {
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }
    
    sjuni_init_cnt++;
}

// SJUNI_IsGetChunk
// SJUNI_PutChunk
// SJUNI_Reset
// SJUNI_UngetChunk
