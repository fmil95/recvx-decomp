
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
    void*         data;
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

// 98.60% matching
void SJUNI_GetChunk(SJUNI sjuni, Sint32 id, Sint32 nbyte, SJCK *ck) 
{
    SJUNI_CKLIST cklist;
    SJCK ck1;
    SJCK ck2;

    if ((Uint32)id >= 4) 
    {
        if (sjuni->err_func != NULL)
        {
            sjuni->err_func(sjuni->err_obj, -3);
        }

        ck->data = NULL;
        
        ck->len = 0;
        return;
    }

    SJCRS_Lock();
    
    cklist = sjuni->cklist[id];

    if (cklist != NULL) 
    {
        ck1 = cklist->ck;
        
        if (nbyte >= ck1.len)
        {
            *ck = ck1;
            
            sjuni->cklist[id] = cklist->next;

            /* this line is currently causing a matching issue, because it seems that the SJUNI_OBJ struct needs to be 
               arranged differently. Changing the type of data from void* to SJUNI_CKLIST in the struct gives a higher match. */
            cklist->next = sjuni->data;
            
            sjuni->data = cklist;
        } 
        else if (sjuni->mode == 1)
        {
            SJ_SplitChunk(&ck1, nbyte, &ck1, &ck2);
            
            *ck = ck1;
            
            cklist->ck = ck2;
        }
        else 
        {
            ck->data = NULL;
            
            ck->len = 0;
        }
    } 
    else 
    {
        ck->data = NULL;
        
        ck->len = 0;
    }

    SJCRS_Unlock();
}

// 100% matching!
Sint32 SJUNI_GetNumChainPool(SJ sj)
{
    SJUNI sjuni;
    SJUNI_CKLIST cur;
    Sint32 ncpool;

    sjuni = (SJUNI)sj;

    ncpool = 0;

    for (cur = sjuni->data; cur != NULL; cur = cur->next) 
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

// 100% matching!
Sint32 SJUNI_IsGetChunk(SJUNI sjuni, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    SJCK ck;

    *rbyte = 0;

    if ((Uint32)id >= 4) 
    {
        if (sjuni->err_func != NULL)
        {
            sjuni->err_func(sjuni->err_obj, -3);
        }

        return 0;
    }

    if (sjuni->cklist[id] == NULL) 
    {
        return 0;
    }

    ck = sjuni->cklist[id]->ck;
    
    *rbyte = ck.len;

    if (sjuni->mode == 1)
    {
        if (ck.len >= nbyte) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    } 
    else if (ck.len == nbyte)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// SJUNI_PutChunk

// 100% matching!
void SJUNI_Reset(SJUNI sjuni)
{
    Sint32 i;
    SJUNI_CKLIST cklist;

    cklist = (SJUNI_CKLIST)sjuni->work;

    sjuni->data = cklist;

    for (i = 0; i < (sjuni->wksize - 1); i++)
    {
        cklist[i].next = &cklist[i + 1];
        
        cklist[i].ck.data = NULL;
        
        cklist[i].ck.len = 0;
    }

    cklist[i].next = NULL;
    
    cklist[i].ck.data = NULL;
    
    cklist[i].ck.len = 0;

    for (i = 0; i < 4; i++) 
    {
        sjuni->cklist[i] = NULL;
    }
}

// SJUNI_UngetChunk
