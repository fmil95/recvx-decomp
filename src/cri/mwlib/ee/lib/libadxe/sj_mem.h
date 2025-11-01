#ifndef _SJ_MEM_H_
#define _SJ_MEM_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>

typedef void (*SJMEM_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjmem 
{
    SJ_OBJ       sj;
    Sint32       used;
    const UUID*  uuid;
    Sint32       datano;
    Sint32       unk10;    // roomno?
    void*        buf;
    Sint32       bfsize;
    SJMEM_ERRFN  err_func;
    void*        err_obj;
} SJMEM_OBJ;

typedef SJMEM_OBJ *SJMEM;

SJ SJMEM_Create(Sint8 *data, Sint32 bsize);
void SJMEM_Destroy(SJMEM sjmem);
void SJMEM_EntryErrFunc(SJMEM sjmem, SJMEM_ERRFN func, void* obj);
void SJMEM_Error(void);
void SJMEM_Finish(void);
void* SJMEM_GetBufPtr(SJMEM sjmem);
Sint32 SJMEM_GetBufSize(SJMEM sjmem);
void SJMEM_GetChunk(SJMEM sjmem, Sint32 id, Sint32 nbyte, SJCK* ck);
Sint32 SJMEM_GetNumData(SJMEM sjmem, Sint32 id);
const UUID* SJMEM_GetUuid(SJMEM sjmem);
void SJMEM_Init(void);
Sint32 SJMEM_IsGetChunk(SJMEM sjmem, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJMEM_PutChunk(SJMEM sjmem, Sint32 id, SJCK *ck);
void SJMEM_Reset(SJMEM sjmem);
void SJMEM_UngetChunk(SJMEM sjmem, Sint32 id, SJCK *ck);

#endif
