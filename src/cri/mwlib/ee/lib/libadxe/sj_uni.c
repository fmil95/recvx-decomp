
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
    SJ_OBJ        sj;
    Sint8         used;
    Sint8         mode;
    Sint8         unk6;
    Sint8         unk7;
    UUID*         uuid;
    void*         work;
    Sint32        wksize;
    void*         unk14;
    SJUNI_CKLIST  cklist[4];
    SJUNI_ERRFN   err_func;
    void*         err_obj;
} SJUNI_OBJ;

typedef SJUNI_OBJ *SJUNI;

void SJUNI_Error(void);
void SJUNI_Reset(SJUNI sjuni);

static SJUNI_OBJ sjuni_obj[64];
static SJ_IF sjuni_vtbl;
static UUID sjuni_uuid;
static Sint32 sjuni_init_cnt;

// 100% matching!
SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize) // should return SJUNI, but doing so clashes with the header definition
{
    SJUNI sjuni;
    Sint32 i;

    for (i = 0; i < 64; i++)
    {
        if (sjuni_obj[i].used == FALSE) 
        {
            break;
        }
    }

    if (i == 64)
    {
        return NULL;
    }
    
    sjuni = &sjuni_obj[i];
    
    sjuni->used = TRUE;
    
    sjuni->sj.vtbl = &sjuni_vtbl;
    
    sjuni->mode = mode;
    
    sjuni->uuid = &sjuni_uuid;
    
    sjuni->work = work;
    
    sjuni->wksize = (Uint32)wksize / 16;
    
    sjuni->err_func = (void*)SJUNI_Error;
    sjuni->err_obj = sjuni;
    
    SJUNI_Reset(sjuni);
    
    return (SJ)sjuni;
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

void SJUNI_Reset(SJUNI sjuni)
{
    scePrintf("SJUNI_Reset - UNIMPLEMENTED!\n");
}

// SJUNI_UngetChunk
