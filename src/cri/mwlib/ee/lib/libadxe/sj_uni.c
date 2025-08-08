
typedef struct SJUNI_CKLIST 
{
    struct SJUNI_CKLIST*  next; 
    struct SJUNI_CKLIST*  prev; 
    SJCK                  ck; 
} SJUNI_CKLIST_OBJ;

typedef SJUNI_CKLIST_OBJ *SJUNI_CKLIST;

typedef void (*SJUNI_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjuni 
{
    SJ            sj;
    Sint8         used;
    Sint8         unk5;
    Sint8         unk6;
    Sint8         unk7;
    UUID*         uuid;
    Sint32        datano;
    Sint32        unk10;
    void*         unk14;
    SJUNI_CKLIST  cklist[4];
    SJUNI_ERRFN   err_func;
    void*         err_obj;
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

// 100% matching!
Sint32 SJUNI_GetNumChainPool(SJ sj)
{
    SJUNI sjuni;
    SJUNI_CKLIST cur;
    Sint32 ncpool;

    sjuni = (SJUNI)sj;

    ncpool = 0;

    for (cur = sjuni->unk14; cur != NULL; cur = cur->next) 
    {
        ncpool++;
    }

    return ncpool;
}

// 100% matching!
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id) 
{
    SJUNI sjuni;
    SJUNI_CKLIST cur;
    Sint32 nck;

    sjuni = (SJUNI)sj;

    nck = 0;

    for (cur = sjuni->cklist[id]; cur != NULL; cur = cur->next) 
    {
        nck++;
    }

    return nck;
}

// 100% matching!
Sint32 SJUNI_GetNumData(SJUNI sjuni, Sint32 id)
{
    SJUNI_CKLIST cur;
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

    for (cur = sjuni->cklist[id]; cur != NULL; cur = cur->next)
    {
        datano += cur->ck.len; 
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
