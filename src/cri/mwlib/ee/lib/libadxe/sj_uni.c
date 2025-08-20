#include "sj_uni.h"

static SJUNI_OBJ sjuni_obj[64] = { 0 };
static SJ_IF sjuni_vtbl = { NULL, NULL, NULL, (void*)SJUNI_Destroy, (void*)SJUNI_GetUuid, (void*)SJUNI_Reset, (void*)SJUNI_GetChunk,(void*)SJUNI_UngetChunk, (void*)SJUNI_PutChunk, (void*)SJUNI_GetNumData, (void*)SJUNI_IsGetChunk, (void*)SJUNI_EntryErrFunc };
static const UUID sjuni_uuid = { 0x2E534FA3, 0xAF97, 0x11D2, { 0xA5, 0x27, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC } };
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
Sint32 SJUNI_GetNumChainPool(SJ sj) // parameter should be SJUNI, but changing it causes issues with the header definition
{
    SJUNI sjuni;
    SJUNI_CKLIST cklist;
    Sint32 ncpool;

    sjuni = (SJUNI)sj;

    ncpool = 0;

    for (cklist = sjuni->data; cklist != NULL; cklist = cklist->next) 
    {
        ncpool++;
    }

    return ncpool;
}

// 100% matching!
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id) // first parameter should be SJUNI, but changing it causes issues with the header definition
{
    SJUNI sjuni;
    SJUNI_CKLIST cklist;
    Sint32 nck;

    sjuni = (SJUNI)sj;

    nck = 0;

    for (cklist = sjuni->cklist[id]; cklist != NULL; cklist = cklist->next) 
    {
        nck++;
    }

    return nck;
}

// 100% matching!
Sint32 SJUNI_GetNumData(SJUNI sjuni, Sint32 id)
{
    SJUNI_CKLIST cklist;
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

    for (cklist = sjuni->cklist[id]; cklist != NULL; cklist = cklist->next)
    {
        datano += cklist->ck.len; 
    } 

    return datano;
}

// 100% matching!
const UUID* SJUNI_GetUuid(SJUNI sjuni) 
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

// 97.64% matching
void SJUNI_PutChunk(SJUNI sjuni, Sint32 id, SJCK *ck)
{
    SJUNI_CKLIST cklist1;
    SJUNI_CKLIST cklist2;
    SJUNI_CKLIST* pCklist;

    if ((Uint32)id >= 4) 
    {
        if (sjuni->err_func != NULL)
        {
            sjuni->err_func(sjuni->err_obj, -3);
        }

        return;
    }

    if ((ck->len <= 0) || (ck->data == NULL)) 
    {
        return;
    }

    SJCRS_Lock();
    
    pCklist = &sjuni->cklist[id];
    
    cklist1 = NULL;

    for (cklist2 = *pCklist; cklist2 != NULL; cklist2 = cklist2->next) 
    {
        cklist1 = cklist2;
        
        pCklist = &cklist1->next;
    }

    if ((sjuni->mode == 1) && (cklist1 != NULL) && ((cklist1->ck.data + cklist1->ck.len) == ck->data)) 
    {
        cklist1->ck.len += ck->len;
    } 
    else 
    {
        cklist1 = sjuni->data;
        
        if (cklist1 == NULL) 
        {
            if (sjuni->err_func != NULL) 
            {
                sjuni->err_func(sjuni->err_obj, -3);
            }
        } 
        else 
        {
            sjuni->data = cklist1->next;
            
            cklist1->ck = *ck;
            
            cklist1->next = NULL;
            
            *pCklist = cklist1;
        }
    }

    SJCRS_Unlock();
}

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

// 99.36% matching
void SJUNI_UngetChunk(SJUNI sjuni, Sint32 id, SJCK *ck)
{
    SJUNI_CKLIST cklist;

    if ((Uint32)id >= 4)
    {
        if (sjuni->err_func != NULL) 
        {
            sjuni->err_func(sjuni->err_obj, -3);
        }

        return;
    }

    if ((ck->len <= 0) || (ck->data == NULL)) 
    {
        return;
    }

    SJCRS_Lock();
    
    cklist = sjuni->cklist[id];

    if ((sjuni->mode == 1) && (cklist != NULL) && ((ck->data + ck->len) == cklist->ck.data)) 
    {
        cklist->ck.data = ck->data;
        
        cklist->ck.len += ck->len;
    } 
    else 
    {
        cklist = sjuni->data;
        
        if (cklist == NULL)
        {
            if (sjuni->err_func != NULL) 
            {
                sjuni->err_func(sjuni->err_obj, -3);
            }
        }
        else 
        {
            sjuni->data = cklist->next;

            cklist->next = NULL;
            
            cklist->ck = *ck;
            
            cklist->next = sjuni->cklist[id];
            
            sjuni->cklist[id] = cklist;
        }
    }

    SJCRS_Unlock();
}
