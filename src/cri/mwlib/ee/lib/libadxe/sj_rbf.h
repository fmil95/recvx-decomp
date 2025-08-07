#ifndef _SJ_RBF_H_
#define _SJ_RBF_H_

typedef void (*SJRBF_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjrbf 
{
    SJ           sj;
    Sint32       used;
    UUID*        uuid;
    Sint32       datano;
    Sint32       unk10;
    Sint32       unk14;
    Sint32       unk18;    // roomno?
    void*        buf;
    Sint32       bfsize;
    Sint32       xtrsize;
    SJRBF_ERRFN  err_func;
    void*        err_obj;
} SJRBF_OBJ;

typedef SJRBF_OBJ *SJRBF;

SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize);
void SJRBF_Destroy(SJRBF sjrbf);
void SJRBF_EntryErrFunc(SJRBF sjrbf, SJRBF_ERRFN func, void* obj);
void SJRBF_Error(void);
void SJRBF_Finish(void);
void* SJRBF_GetBufPtr(SJRBF sjrbf);
Sint32 SJRBF_GetBufSize(SJRBF sjrbf);
void SJRBF_GetChunk(SJRBF sjrbf, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJRBF_GetNumData(SJRBF sjrbf, Sint32 id);
UUID* SJRBF_GetUuid(SJRBF sjrbf);
Sint32 SJRBF_GetXtrSize(SJRBF sjrbf);
void SJRBF_Init(void);
Sint32 SJRBF_IsGetChunk(SJRBF sjrbf, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJRBF_PutChunk(SJRBF sjrbf, Sint32 id, SJCK *ck);
void SJRBF_Reset(SJRBF sjrbf);  
void SJRBF_UngetChunk(SJRBF sjrbf, Sint32 id, SJCK *ck);

#endif
