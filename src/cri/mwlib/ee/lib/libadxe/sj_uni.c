#include "sj_uni.h"

#include <string.h>

static const UUID sjuni_uuid = { 0x2E534FA3, 0xAF97, 0x11D2, { 0xA5, 0x27, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC } };
SJ_IF sjuni_vtbl = { NULL, NULL, NULL, (void*)SJUNI_Destroy, (void*)SJUNI_GetUuid, (void*)SJUNI_Reset, (void*)SJUNI_GetChunk,(void*)SJUNI_UngetChunk, (void*)SJUNI_PutChunk, (void*)SJUNI_GetNumData, (void*)SJUNI_IsGetChunk, (void*)SJUNI_EntryErrFunc };
Sint32 sjuni_init_cnt = 0;
SJUNI_OBJ sjuni_obj[64] = { 0 };

// 100% matching!
SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    Sint32 no;
	SJUNI uni;

    for (no = 0; no < 64; no++)
    {
        if (sjuni_obj[no].used == FALSE) 
        {
            break;
        }
    }

    if (no == 64)
    {
        return NULL;
    }
    
    uni = &sjuni_obj[no];
    
    uni->used = TRUE;
    
    uni->vtbl = &sjuni_vtbl;
    
    uni->mode = mode;
    
    uni->uuid = &sjuni_uuid;
    
    uni->ckcnwk = (SJCKCN)work;
    
    uni->nckcn = (Uint32)wksize / 16;
    
    uni->errfunc = (void*)SJUNI_Error;
    uni->errobj = uni;
    
    SJUNI_Reset((SJ)uni);
    
    return (SJ)uni;
}

// 100% matching!
void SJUNI_Destroy(SJ sj)
{
    SJUNI uni;

    uni = (SJUNI)sj;
    
    if (uni != NULL) 
    {
        memset(uni, 0, sizeof(SJUNI_OBJ)); 
        
        uni->used = FALSE;
    }
}

// 100% matching!
void SJUNI_EntryErrFunc(SJ sj, SJUNI_ERRFN func, void *obj)
{
    SJUNI uni;

    uni = (SJUNI)sj;
    
    uni->errfunc = func;
    uni->errobj = obj;
}

// 99.29% matching
void SJUNI_Error(SJUNI uni, Sint32 errcode) 
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

// 99.60% matching
void SJUNI_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
    SJCKCN ckcn;
    SJCK ck0;
    SJCK ck1;
    SJUNI uni;

    uni = (SJUNI)sj;

    if ((Uint32)id >= 4) 
    {
        if (uni->errfunc != NULL)
        {
            uni->errfunc(uni->errobj, -3);
        }

        ck->data = NULL;
        
        ck->len = 0;
        return;
    }

    SJCRS_Lock();
    
    ckcn = uni->lin[id];

    if (ckcn != NULL) 
    {
        ck0 = ckcn->ck;
        
        if (nbyte >= ck0.len)
        {
            *ck = ck0;
            
            uni->lin[id] = ckcn->next;

            ckcn->next = uni->pool;
            
            uni->pool = ckcn;
        } 
        else if (uni->mode == 1)
        {
            SJ_SplitChunk(&ck0, nbyte, &ck0, &ck1);
            
            *ck = ck0;
            
            ckcn->ck = ck1;
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
    SJCKCN ckcn;
	Sint32 i;
    SJUNI uni;

    uni = (SJUNI)sj;

    i = 0;

    for (ckcn = uni->pool; ckcn != NULL; ckcn = ckcn->next) 
    {
        i++;
    }

    return i;
}

// 100% matching!
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id)
{
    SJCKCN ckcn;
	Sint32 i;
    SJUNI uni;

    uni = (SJUNI)sj;

    i = 0;

    for (ckcn = uni->lin[id]; ckcn != NULL; ckcn = ckcn->next) 
    {
        i++;
    }

    return i;
}

// 100% matching!
Sint32 SJUNI_GetNumData(SJ sj, Sint32 id)
{
    Sint32 nbyte;
	SJCKCN ckcn;
    SJUNI uni;

    uni = (SJUNI)sj;

    if ((Uint32)id >= 4) 
    {
        if (uni->errfunc != NULL)
        {
            uni->errfunc(uni->errobj, -3);
        }
    
        return 0;
    }
    
    nbyte = 0;

    for (ckcn = uni->lin[id]; ckcn != NULL; ckcn = ckcn->next)
    {
        nbyte += ckcn->ck.len; 
    } 

    return nbyte;
}

// 100% matching!
const UUID* SJUNI_GetUuid(SJ sj) 
{
    SJUNI uni;

    uni = (SJUNI)sj;
    
    return uni->uuid;
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
Sint32 SJUNI_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    SJCKCN ckcn;
	SJCK ck0;
    SJUNI uni;

    uni = (SJUNI)sj;

    *rbyte = 0;

    if ((Uint32)id >= 4) 
    {
        if (uni->errfunc != NULL)
        {
            uni->errfunc(uni->errobj, -3);
        }

        return 0;
    }

    if (uni->lin[id] == NULL) 
    {
        return 0;
    }

    ckcn = uni->lin[id];

    ck0 = ckcn->ck;
    
    *rbyte = ck0.len;

    if (uni->mode == 1)
    {
        if (ck0.len >= nbyte) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    } 
    else if (ck0.len == nbyte)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 97.64% matching
void SJUNI_PutChunk(SJ sj, Sint32 id, SJCK *ck)
{
    SJCKCN ckcn;
    SJCKCN ckcn2;
	SJCKCN *ckcnp;
    SJUNI uni;

    uni = (SJUNI)sj;

    if ((Uint32)id >= 4) 
    {
        if (uni->errfunc != NULL)
        {
            uni->errfunc(uni->errobj, -3);
        }

        return;
    }

    if ((ck->len <= 0) || (ck->data == NULL)) 
    {
        return;
    }

    SJCRS_Lock();
    
    ckcnp = &uni->lin[id];
    
    ckcn = NULL;

    for (ckcn2 = *ckcnp; ckcn2 != NULL; ckcn2 = ckcn2->next) 
    {
        ckcn = ckcn2;
        
        ckcnp = &ckcn->next;
    }

    if ((uni->mode == 1) && (ckcn != NULL) && ((ckcn->ck.data + ckcn->ck.len) == ck->data)) 
    {
        ckcn->ck.len += ck->len;
    } 
    else 
    {
        ckcn = uni->pool;
        
        if (ckcn == NULL) 
        {
            if (uni->errfunc != NULL) 
            {
                uni->errfunc(uni->errobj, -3);
            }
        } 
        else 
        {
            uni->pool = ckcn->next;
            
            ckcn->ck = *ck;
            
            ckcn->next = NULL;
            
            *ckcnp = ckcn;
        }
    }

    SJCRS_Unlock();
}

// 100% matching!
void SJUNI_Reset(SJ sj)
{
    SJUNI uni;
	Sint32 i;
	SJCK_CHAIN *ckchain;

    uni = (SJUNI)sj;

    ckchain = (SJCK_CHAIN*)uni->ckcnwk;

    uni->pool = ckchain;

    for (i = 0; i < (uni->nckcn - 1); i++)
    {
        ckchain[i].next = &ckchain[i + 1];
        
        ckchain[i].ck.data = NULL;
        
        ckchain[i].ck.len = 0;
    }

    ckchain[i].next = NULL;
    
    ckchain[i].ck.data = NULL;
    
    ckchain[i].ck.len = 0;

    for (i = 0; i < 4; i++) 
    {
        uni->lin[i] = NULL;
    }
}

// 99.36% matching
void SJUNI_UngetChunk(SJ sj, Sint32 id, SJCK *ck)
{
    SJCKCN ckcn;
    SJUNI uni;

    uni = (SJUNI)sj;

    if ((Uint32)id >= 4)
    {
        if (uni->errfunc != NULL) 
        {
            uni->errfunc(uni->errobj, -3);
        }

        return;
    }

    if ((ck->len <= 0) || (ck->data == NULL)) 
    {
        return;
    }

    SJCRS_Lock();
    
    ckcn = uni->lin[id];

    if ((uni->mode == 1) && (ckcn != NULL) && ((ck->data + ck->len) == ckcn->ck.data)) 
    {
        ckcn->ck.data = ck->data;
        
        ckcn->ck.len += ck->len;
    } 
    else 
    {
        ckcn = uni->pool;
        
        if (ckcn == NULL)
        {
            if (uni->errfunc != NULL) 
            {
                uni->errfunc(uni->errobj, -3);
            }
        }
        else 
        {
            uni->pool = ckcn->next;

            ckcn->next = NULL;
            
            ckcn->ck = *ck;
            
            ckcn->next = uni->lin[id];
            
            uni->lin[id] = ckcn;
        }
    }

    SJCRS_Unlock();
}
