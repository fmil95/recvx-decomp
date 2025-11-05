#include "sj_rbf.h"

#include <string.h>

static Char8* volatile sj_build = "\nSJ Ver.6.00 Build:Jan 26 2001 09:59:32\n";
static SJRBF_OBJ sjrbf_obj[64] = { 0 };
static SJ_IF sjrbf_vtbl = { NULL, NULL, NULL, (void*)SJRBF_Destroy, (void*)SJRBF_GetUuid, (void*)SJRBF_Reset, (void*)SJRBF_GetChunk,(void*)SJRBF_UngetChunk, (void*)SJRBF_PutChunk, (void*)SJRBF_GetNumData, (void*)SJRBF_IsGetChunk, (void*)SJRBF_EntryErrFunc };
static const UUID sjrbf_uuid = { 0x3B9A9E81, 0x0DBB, 0x11D2, { 0xA6, 0xBF, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } }; 
static Sint32 sjrbf_init_cnt;

// 100% matching!
SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize) // should return SJRBF, but doing so clashes with the header definition
{
    SJRBF sjrbf;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < 64; i++)
    {
        if (sjrbf_obj[i].used == FALSE) 
        {
            break;
        }
    }

    if (i == 64) 
    {
        sjrbf = NULL;
    }
    else 
    {
        sjrbf = &sjrbf_obj[i];
        
        sjrbf->used = TRUE;
        
        sjrbf->sj.vtbl = &sjrbf_vtbl;
        
        sjrbf->buf = buf;
        
        sjrbf->bfsize = bsize;
        sjrbf->xtrsize = xsize;
        
        sjrbf->uuid = &sjrbf_uuid;
        
        sjrbf->err_func = (void*)SJRBF_Error;
        sjrbf->err_obj = sjrbf;
        
        SJRBF_Reset(sjrbf);
    }

    SJCRS_Unlock();
    
    return (SJ)sjrbf;
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

// 100% matching!
void* SJRBF_GetBufPtr(SJRBF sjrbf)
{
    return sjrbf->buf;
}

// 100% matching!
Sint32 SJRBF_GetBufSize(SJRBF sjrbf) 
{
    return sjrbf->bfsize;
}

// 100% matching!
void SJRBF_GetChunk(SJRBF sjrbf, Sint32 id, Sint32 nbyte, SJCK *ck)
{
    SJCRS_Lock();

    if (id == 0)
    {
        ck->len = MIN(MIN(sjrbf->unk10, (sjrbf->bfsize - sjrbf->unk14) + sjrbf->xtrsize), nbyte); // simplify this line
        
        ck->data = (void*)((Sint32)sjrbf->buf + sjrbf->unk14); // simplify this too
        
        sjrbf->unk14 = (sjrbf->unk14 + ck->len) % sjrbf->bfsize;
        
        sjrbf->unk10 -= ck->len;
    }
    else if (id == 1) 
    {
        ck->len = MIN(MIN(sjrbf->datano, (sjrbf->bfsize - sjrbf->unk18) + sjrbf->xtrsize), nbyte); // same as above
        
        ck->data = (void*)((Sint32)sjrbf->buf + sjrbf->unk18);
        
        sjrbf->unk18 = (sjrbf->unk18 + ck->len) % sjrbf->bfsize;
        
        sjrbf->datano -= ck->len;
    }
    else
    {
        ck->len = 0;
        
        ck->data = NULL;

        if (sjrbf->err_func != NULL)
        {
            sjrbf->err_func(sjrbf->err_obj, -3);
        }
    }

    SJCRS_Unlock();
}

// 100% matching!
Sint32 SJRBF_GetNumData(SJRBF sjrbf, Sint32 id)  
{
    if (id == 1) 
    {
        return sjrbf->datano;
    }
    else if (id == 0) 
    {
        return sjrbf->unk10;
    } 
    else if (sjrbf->err_func != NULL) 
    {
        sjrbf->err_func(sjrbf->err_obj, -3);
    }
    
    return 0;
}

// 100% matching!
const UUID* SJRBF_GetUuid(SJRBF sjrbf)
{
    return sjrbf->uuid;
}

// 100% matching!
Sint32 SJRBF_GetXtrSize(SJRBF sjrbf) 
{
    return sjrbf->xtrsize;
}

// 100% matching!
void SJRBF_Init(void) 
{
    if (sjrbf_init_cnt == 0) 
    {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }
    
    sjrbf_init_cnt++;
}

// 100% matching!
Sint32 SJRBF_IsGetChunk(SJRBF sjrbf, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    Sint32 len;

    SJCRS_Lock();
    
    if (id == 0) 
    {
        len = MIN(sjrbf->unk10, (sjrbf->bfsize - sjrbf->unk14) + sjrbf->xtrsize);
        len = MIN(len, nbyte);
    } 
    else if (id == 1) 
    {
        len = MIN(sjrbf->datano, (sjrbf->bfsize - sjrbf->unk18) + sjrbf->xtrsize);
        len = MIN(len, nbyte);
    } 
    else 
    {
        len = 0;

        if (sjrbf->err_func != NULL)
        {
            sjrbf->err_func(sjrbf->err_obj, -3); 
        }
    }

    *rbyte = len;
    
    SJCRS_Unlock();
    
    return len == nbyte;
}

// 100% matching!
void SJRBF_PutChunk(SJRBF sjrbf, Sint32 id, SJCK *ck)
{
    Sint32 len;
    Sint32 size;

    if ((ck->len > 0) && (ck->data != NULL)) 
    {
        SJCRS_Lock();
    
        if (id == 1) 
        {
            len = (Sint32)ck->data - (Sint32)sjrbf->buf;
            
            sjrbf->datano += ck->len;
    
            if (len < sjrbf->xtrsize) 
            {
                memcpy((void*)((Sint32)sjrbf->buf + (sjrbf->bfsize + len)), ck->data, MIN(ck->len, sjrbf->xtrsize - len)); // simplify this line
            }
     
            len = ((Sint32)ck->data - (Sint32)sjrbf->buf) + ck->len; 
     
            if (len > sjrbf->bfsize) 
            {
                size = MIN(ck->len, len - sjrbf->bfsize);
                
                memcpy(sjrbf->buf, (void*)((Sint32)sjrbf->buf + (len - size)), size); // same as above
            }
        } 
        else if (id == 0)
        {
            sjrbf->unk10 += ck->len;
        }
        else
        {
            ck->len = 0;
            
            ck->data = NULL;
    
            if (sjrbf->err_func != NULL) 
            {
                sjrbf->err_func(sjrbf->err_obj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}

// 100% matching!
void SJRBF_Reset(SJRBF sjrbf) 
{
    sjrbf->datano = 0;
    
    sjrbf->unk14 = 0;
    
    sjrbf->unk10 = sjrbf->bfsize;
    
    sjrbf->unk18 = 0; 
}

// 100% matching!
void SJRBF_UngetChunk(SJRBF sjrbf, Sint32 id, SJCK *ck)
{
    Sint32 mod1;
    Sint32 mod2;

    if ((ck->len > 0) && (ck->data != NULL)) 
    {
        SJCRS_Lock();

        if (id == 0) 
        {
            mod1 = ((sjrbf->unk14 + sjrbf->bfsize) - ck->len) % sjrbf->bfsize;
            mod2 = ((Sint32)ck->data - (Sint32)sjrbf->buf) % sjrbf->bfsize;
    
            if (mod1 == mod2) 
            {
                sjrbf->unk14 = mod1;
                
                sjrbf->unk10 += ck->len;
            }
            else if (sjrbf->err_func != NULL) 
            {
                sjrbf->err_func(sjrbf->err_obj, -3);
            }
        }
        else if (id == 1)
        {
            mod1 = ((sjrbf->unk18 + sjrbf->bfsize) - ck->len) % sjrbf->bfsize;
            mod2 = ((Sint32)ck->data - (Sint32)sjrbf->buf) % sjrbf->bfsize;
    
            if (mod1 == mod2) 
            {
                sjrbf->unk18 = mod1;
                
                sjrbf->datano += ck->len;
            } 
            else if (sjrbf->err_func != NULL)  
            {
                sjrbf->err_func(sjrbf->err_obj, -3);
            }
        } 
        else 
        { 
            ck->len = 0;
            
            ck->data = NULL; 
    
            if (sjrbf->err_func != NULL) 
            {
                sjrbf->err_func(sjrbf->err_obj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}
