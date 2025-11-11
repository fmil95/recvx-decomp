#include "sj_rbf.h"

#include <string.h>

char* volatile sj_build = "\nSJ Ver.6.00 Build:Jan 26 2001 09:59:32\n";
static const UUID sjrbf_uuid = { 0x3B9A9E81, 0x0DBB, 0x11D2, { 0xA6, 0xBF, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } }; 
SJ_IF sjrbf_vtbl = { NULL, NULL, NULL, (void*)SJRBF_Destroy, (void*)SJRBF_GetUuid, (void*)SJRBF_Reset, (void*)SJRBF_GetChunk,(void*)SJRBF_UngetChunk, (void*)SJRBF_PutChunk, (void*)SJRBF_GetNumData, (void*)SJRBF_IsGetChunk, (void*)SJRBF_EntryErrFunc };
Sint32 sjrbf_init_cnt = 0;
SJRBF_OBJ sjrbf_obj[64] = { 0 };

// 100% matching!
SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize)
{
    Sint32 no;
	SJRBF rbf;
    
    SJCRS_Lock();

    for (no = 0; no < 64; no++)
    {
        if (sjrbf_obj[no].used == FALSE) 
        {
            break;
        }
    }

    if (no == 64) 
    {
        rbf = NULL;
    }
    else 
    {
        rbf = &sjrbf_obj[no];
        
        rbf->used = TRUE;
        
        rbf->vtbl = &sjrbf_vtbl;
        
        rbf->buf = buf;
        
        rbf->bsize = bsize;
        rbf->xsize = xsize;
        
        rbf->uuid = &sjrbf_uuid;
        
        rbf->errfunc = (void*)SJRBF_Error;
        rbf->errobj = rbf;
        
        SJRBF_Reset((SJ)rbf);
    }

    SJCRS_Unlock();
    
    return (SJ)rbf;
}

// 100% matching!
void SJRBF_Destroy(SJ sj)
{
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    SJCRS_Lock();
    
    if (rbf != NULL) 
    {
        memset(rbf, 0, sizeof(SJRBF_OBJ));
        
        rbf->used = FALSE;
    }
    
    SJCRS_Unlock();
}

// 100% matching!
void SJRBF_EntryErrFunc(SJ sj, SJRBF_ERRFN func, void *obj)
{
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    rbf->errfunc = func;
    rbf->errobj = obj;
}

// 99.29% matching
void SJRBF_Error(SJRBF rbf, Sint32 errcode)
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
Sint8* SJRBF_GetBufPtr(SJRBF sjrbf)
{
    return sjrbf->buf;
}

// 100% matching!
Sint32 SJRBF_GetBufSize(SJRBF sjrbf)
{
    return sjrbf->bsize;
}

// 100% matching!
void SJRBF_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
    Sint32 pos;
    Sint32 pos2;
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    SJCRS_Lock();

    if (id == 0)
    {
        pos = MIN(rbf->nroom, (rbf->bsize - rbf->wpos) + rbf->xsize);
            
        ck->len = MIN(pos, nbyte); 
        
        ck->data = (void*)&rbf->buf[rbf->wpos]; 
        
        rbf->wpos = (rbf->wpos + ck->len) % rbf->bsize;
        
        rbf->nroom -= ck->len;
    }
    else if (id == 1) 
    {
        pos2 = MIN(rbf->ndata, (rbf->bsize - rbf->rpos) + rbf->xsize);
        
        ck->len = MIN(pos2, nbyte); 
        
        ck->data = (void*)&rbf->buf[rbf->rpos]; 
        
        rbf->rpos = (rbf->rpos + ck->len) % rbf->bsize;
        
        rbf->ndata -= ck->len;
    }
    else
    {
        ck->len = 0;
        
        ck->data = NULL;

        if (rbf->errfunc != NULL)
        {
            rbf->errfunc(rbf->errobj, -3);
        }
    }

    SJCRS_Unlock();
}

// 100% matching!
Sint32 SJRBF_GetNumData(SJ sj, Sint32 id)
{
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    if (id == 1) 
    {
        return rbf->ndata;
    }
    else if (id == 0) 
    {
        return rbf->nroom;
    } 
    else if (rbf->errfunc != NULL) 
    {
        rbf->errfunc(rbf->errobj, -3);
    }
    
    return 0;
}

// 100% matching!
const UUID* SJRBF_GetUuid(SJ sj)
{
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    return rbf->uuid;
}

// 100% matching!
Sint32 SJRBF_GetXtrSize(SJRBF sjrbf) 
{
    return sjrbf->xsize;
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
Sint32 SJRBF_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    Sint32 cklen;
    SJRBF rbf;

    rbf = (SJRBF)sj;

    SJCRS_Lock();
    
    if (id == 0) 
    {
        cklen = MIN(rbf->nroom, (rbf->bsize - rbf->wpos) + rbf->xsize);
        cklen = MIN(cklen, nbyte);
    } 
    else if (id == 1) 
    {
        cklen = MIN(rbf->ndata, (rbf->bsize - rbf->rpos) + rbf->xsize);
        cklen = MIN(cklen, nbyte);
    } 
    else 
    {
        cklen = 0;

        if (rbf->errfunc != NULL)
        {
            rbf->errfunc(rbf->errobj, -3); 
        }
    }

    *rbyte = cklen;
    
    SJCRS_Unlock();
    
    return cklen == nbyte;
}

// 100% matching!
void SJRBF_PutChunk(SJ sj, Sint32 id, SJCK *ck)
{
    Sint32 pos;
    Sint32 pos2;
    Sint32 len;
    SJRBF rbf;

    rbf = (SJRBF)sj;

    if ((ck->len > 0) && (ck->data != NULL)) 
    {
        SJCRS_Lock();
    
        if (id == 1) 
        {
            len = (Sint32)ck->data - (Sint32)rbf->buf; // casts added for MWCC compatibility
            
            rbf->ndata += ck->len;
    
            if (len < rbf->xsize) 
            {
                pos = MIN(ck->len, rbf->xsize - len);
                
                memcpy((void*)((Sint32)rbf->buf + (rbf->bsize + len)), ck->data, pos); // same as above
            }
     
            len = ((Sint32)ck->data - (Sint32)rbf->buf) + ck->len; 
     
            if (len > rbf->bsize) 
            {
                pos2 = MIN(ck->len, len - rbf->bsize);
                
                memcpy(rbf->buf, (void*)((Sint32)rbf->buf + (len - pos2)), pos2); 
            }
        } 
        else if (id == 0)
        {
            rbf->nroom += ck->len;
        }
        else
        {
            ck->len = 0;
            
            ck->data = NULL;
    
            if (rbf->errfunc != NULL) 
            {
                rbf->errfunc(rbf->errobj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}

// 100% matching!
void SJRBF_Reset(SJ sj)
{
    SJRBF rbf;

    rbf = (SJRBF)sj;
    
    rbf->ndata = 0;
    
    rbf->wpos = 0;
    
    rbf->nroom = rbf->bsize;
    
    rbf->rpos = 0; 
}

// 100% matching!
void SJRBF_UngetChunk(SJ sj, Sint32 id, SJCK *ck)
{
    Sint32 pos;
    Sint32 pos2;
    SJRBF rbf;

    rbf = (SJRBF)sj;

    if ((ck->len > 0) && (ck->data != NULL)) 
    {
        SJCRS_Lock();

        if (id == 0) 
        {
            pos = ((rbf->wpos + rbf->bsize) - ck->len) % rbf->bsize;
            pos2 = ((Sint32)ck->data - (Sint32)rbf->buf) % rbf->bsize; // casts added for MWCC compatibility
    
            if (pos == pos2) 
            {
                rbf->wpos = pos;
                
                rbf->nroom += ck->len;
            }
            else if (rbf->errfunc != NULL) 
            {
                rbf->errfunc(rbf->errobj, -3);
            }
        }
        else if (id == 1)
        {
            pos = ((rbf->rpos + rbf->bsize) - ck->len) % rbf->bsize;
            pos2 = ((Sint32)ck->data - (Sint32)rbf->buf) % rbf->bsize; // same as above
    
            if (pos == pos2) 
            {
                rbf->rpos = pos;
                
                rbf->ndata += ck->len;
            } 
            else if (rbf->errfunc != NULL)  
            {
                rbf->errfunc(rbf->errobj, -3);
            }
        } 
        else 
        { 
            ck->len = 0;
            
            ck->data = NULL; 
    
            if (rbf->errfunc != NULL) 
            {
                rbf->errfunc(rbf->errobj, -3);
            }
        }
    
        SJCRS_Unlock();
    }
}
