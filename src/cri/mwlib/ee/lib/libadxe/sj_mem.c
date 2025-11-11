#include "sj_mem.h"

#include <string.h>

static const UUID sjmem_uuid = { 0xDD9EEE41, 0x1679, 0x11D2, { 0x93, 0x6C, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC } };
SJ_IF sjmem_vtbl = { NULL, NULL, NULL, (void*)SJMEM_Destroy, (void*)SJMEM_GetUuid, (void*)SJMEM_Reset, (void*)SJMEM_GetChunk,(void*)SJMEM_UngetChunk, (void*)SJMEM_PutChunk, (void*)SJMEM_GetNumData, (void*)SJMEM_IsGetChunk, (void*)SJMEM_EntryErrFunc };
Sint32 sjmem_init_cnt = 0;
SJMEM_OBJ sjmem_obj[32] = { 0 };

// 100% matching!
SJ SJMEM_Create(Sint8 *data, Sint32 dtsize)
{
    Sint32 no;
    SJMEM sjmem;

    for (no = 0; no < 32; no++) 
    {
        if (sjmem_obj[no].used == FALSE) 
        {
            break;
        }
    }

    if (no == 32) 
    {
        return NULL;
    }

    sjmem = &sjmem_obj[no];
    
    sjmem->used = TRUE;
    
    sjmem->vtbl = &sjmem_vtbl; 
    
    sjmem->buf = data;
    sjmem->bsize = dtsize;
    
    sjmem->uuid = &sjmem_uuid;
    
    sjmem->errfunc = (void*)SJMEM_Error;
    sjmem->errobj = sjmem;
    
    SJMEM_Reset((SJ)sjmem);
    
    return (SJ)sjmem;
}

// 100% matching!
void SJMEM_Destroy(SJ sj)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    if (sjmem != NULL) 
    {
        memset(sjmem, 0, sizeof(SJMEM_OBJ));
        
        sjmem->used = FALSE;
    }
}

// 100% matching!
void SJMEM_EntryErrFunc(SJ sj, SJMEM_ERRFN func, void *obj)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    sjmem->errfunc = func;
    sjmem->errobj = obj;
}

// 99.29% matching
void SJMEM_Error(void *obj, Sint32 errcode)
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
Sint8* SJMEM_GetBufPtr(SJMEM sjmem)
{
    return sjmem->buf;
}

// 100% matching!
Sint32 SJMEM_GetBufSize(SJMEM sjmem) 
{
    return sjmem->bsize;
}

// 100% matching!
void SJMEM_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    SJCRS_Lock();
    
    if (id == 0)
    {
        ck->len = 0;
        
        ck->data = NULL;
    } 
    else if (id == 1)
    {
        ck->len = MIN(sjmem->ndata, nbyte);
        
        ck->data = (void*)((Sint32)sjmem->buf + sjmem->rpos); // casts added for MWCC compatibility
        
        sjmem->rpos += ck->len;
        
        sjmem->ndata -= ck->len;
    }
    else 
    {
        ck->len = 0;
        
        ck->data = NULL;
        
        if (sjmem->errfunc != NULL)
        {
            sjmem->errfunc(sjmem->errobj, -3);
        }
    }
    
    SJCRS_Unlock();
}

// 100% matching!
Sint32 SJMEM_GetNumData(SJ sj, Sint32 id)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    if (id == 1) 
    {
        return sjmem->ndata;
    }

    if ((id != 0) && (sjmem->errfunc != NULL)) 
    {
        sjmem->errfunc(sjmem->errobj, -3);
    }

    return 0;
}

// 100% matching!
const UUID* SJMEM_GetUuid(SJ sj)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
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
Sint32 SJMEM_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    Sint32 cklen;
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    SJCRS_Lock();
    
    if (id == 0)
    {
        cklen = 0;
    } 
    else if (id == 1)
    {
        cklen = MIN(sjmem->ndata, nbyte);
    }
    else 
    {
        cklen = 0;
        
        if (sjmem->errfunc != NULL)
        {
            sjmem->errfunc(sjmem->errobj, -3);
        }
    }

    *rbyte = cklen; 
    
    SJCRS_Unlock();

    return cklen == nbyte;
}

// 100% matching!
void SJMEM_PutChunk(SJ sj, Sint32 id, SJCK *ck)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
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
    
        if (sjmem->errfunc != NULL) 
        {
            sjmem->errfunc(sjmem->errobj, -3);
        }
    
    label:
        SJCRS_Unlock();
    }
}

// 100% matching!
void SJMEM_Reset(SJ sj)
{
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    sjmem->rpos = 0;
    
    sjmem->ndata = sjmem->bsize;
}

// 100% matching!
void SJMEM_UngetChunk(SJ sj, Sint32 id, SJCK *ck)
{
    Sint32 pos;
    Sint32 pos2;
    SJMEM sjmem;

    sjmem = (SJMEM)sj;
    
    if ((ck->len > 0) && (ck->data != NULL))
    {
        SJCRS_Lock();
    
        if (id == 0) 
        {
            if (sjmem->errfunc != NULL) 
            {
                sjmem->errfunc(sjmem->errobj, -3);
            }
        } 
        else if (id == 1) 
        {
            pos = sjmem->rpos - ck->len;
            
            sjmem->rpos = MAX(pos, 0);
            
            sjmem->ndata = MIN(sjmem->bsize, sjmem->ndata + ck->len);

            pos2 = (Sint32)ck->data - (Sint32)sjmem->buf; // casts added for MWCC compatibility
            
            if ((sjmem->rpos != pos2) && (sjmem->errfunc != NULL))
            {
                sjmem->errfunc(sjmem->errobj, -3);
            }
        } 
        else 
        {
            ck->len = 0;
            
            ck->data = NULL;
    
            if (sjmem->errfunc != NULL) 
            {
                sjmem->errfunc(sjmem->errobj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}
