#include "sj_mem.h"

static SJMEM_OBJ sjmem_obj[32] = { 0 };
static SJ_IF sjmem_vtbl = { NULL, NULL, NULL, (void*)SJMEM_Destroy, (void*)SJMEM_GetUuid, (void*)SJMEM_Reset, (void*)SJMEM_GetChunk,(void*)SJMEM_UngetChunk, (void*)SJMEM_PutChunk, (void*)SJMEM_GetNumData, (void*)SJMEM_IsGetChunk, (void*)SJMEM_EntryErrFunc };
static const UUID sjmem_uuid = { 0xDD9EEE41, 0x1679, 0x11D2, { 0x93, 0x6C, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC } };
static Sint32 sjmem_init_cnt;

// 100% matching!
SJ SJMEM_Create(Sint8 *data, Sint32 bsize) // should return SJMEM, but doing so clashes with the header definition
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
    
    sjmem->sj.vtbl = &sjmem_vtbl; 
    
    sjmem->buf = data;
    sjmem->bfsize = bsize;
    
    sjmem->uuid = &sjmem_uuid;
    
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

// 100% matching!
void SJMEM_GetChunk(SJMEM sjmem, Sint32 id, Sint32 nbyte, SJCK* ck)
{
    SJCRS_Lock();
    
    if (id == 0)
    {
        ck->len = 0;
        
        ck->data = NULL;
    } 
    else if (id == 1)
    {
        ck->len = MIN(sjmem->datano, nbyte);
        
        ck->data = (void*)((Sint32)sjmem->buf + sjmem->unk10); // simplify this line 
        
        sjmem->unk10 += ck->len;
        
        sjmem->datano -= ck->len;
    }
    else 
    {
        ck->len = 0;
        
        ck->data = NULL;
        
        if (sjmem->err_func != NULL)
        {
            sjmem->err_func(sjmem->err_obj, -3);
        }
    }
    
    SJCRS_Unlock();
}

// 100% matching!
Sint32 SJMEM_GetNumData(SJMEM sjmem, Sint32 id) 
{
    if (id == 1) 
    {
        return sjmem->datano;
    }

    if ((id != 0) && (sjmem->err_func != NULL)) 
    {
        sjmem->err_func(sjmem->err_obj, -3);
    }

    return 0;
}

// 100% matching!
const UUID* SJMEM_GetUuid(SJMEM sjmem)
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

// 100% matching!
Sint32 SJMEM_IsGetChunk(SJMEM sjmem, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    Sint32 len;
    
    SJCRS_Lock();
    
    if (id == 0)
    {
        len = 0;
    } 
    else if (id == 1)
    {
        len = MIN(sjmem->datano, nbyte);
    }
    else 
    {
        len = 0;
        
        if (sjmem->err_func != NULL)
        {
            sjmem->err_func(sjmem->err_obj, -3);
        }
    }

    *rbyte = len; 
    
    SJCRS_Unlock();

    return len == nbyte;
}

// 100% matching!
void SJMEM_PutChunk(SJMEM sjmem, Sint32 id, SJCK *ck)
{
    if ((ck->len > 0) && (ck->data != NULL))
    {
        SJCRS_Lock();

        if (id == 0)
        {
            goto label;
        }
    
        if (id == 1) 
        {
            goto label;
        }
    
        ck->len = 0;
        
        ck->data = NULL;
    
        if (sjmem->err_func != NULL) 
        {
            sjmem->err_func(sjmem->err_obj, -3);
        }
    
    label:
        SJCRS_Unlock();
    }
}

// 100% matching!
void SJMEM_Reset(SJMEM sjmem) 
{
    sjmem->unk10 = 0;
    
    sjmem->datano = sjmem->bfsize;
}

// 100% matching!
void SJMEM_UngetChunk(SJMEM sjmem, Sint32 id, SJCK *ck)
{
    if ((ck->len > 0) && (ck->data != NULL))
    {
        SJCRS_Lock();
    
        if (id == 0) 
        {
            if (sjmem->err_func != NULL) 
            {
                sjmem->err_func(sjmem->err_obj, -3);
            }
        } 
        else if (id == 1) 
        {
            sjmem->unk10 = MAX(sjmem->unk10 - ck->len, 0);
            
            sjmem->datano = MIN(sjmem->bfsize, sjmem->datano + ck->len);
            
            if ((sjmem->unk10 != ((Sint32)ck->data - (Sint32)sjmem->buf)) && (sjmem->err_func != NULL))
            {
                sjmem->err_func(sjmem->err_obj, -3);
            }
        } 
        else 
        {
            ck->len = 0;
            
            ck->data = NULL;
    
            if (sjmem->err_func != NULL) 
            {
                sjmem->err_func(sjmem->err_obj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}
