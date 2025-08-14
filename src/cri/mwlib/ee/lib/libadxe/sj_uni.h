#ifndef _SJ_UNI_H_
#define _SJ_UNI_H_

typedef struct SJUNI_CKLIST 
{
    struct SJUNI_CKLIST*  next; 
    struct SJUNI_CKLIST*  prev; /* unused */ 
    SJCK                  ck; 
} SJUNI_CKLIST_OBJ;

typedef SJUNI_CKLIST_OBJ *SJUNI_CKLIST;

typedef void (*SJUNI_ERRFN)(void *obj, Sint32 errcode);

typedef struct _sjuni 
{
    SJ_OBJ        sj;
    Sint8         used;
    Sint8         mode;
    Sint8         unk6;      /* unused */ 
    Sint8         unk7;      /* unused */ 
    const UUID*   uuid;
    void*         work;
    Sint32        wksize;
    void*         data;
    SJUNI_CKLIST  cklist[4];
    SJUNI_ERRFN   err_func;
    void*         err_obj;
} SJUNI_OBJ;

typedef SJUNI_OBJ *SJUNI;

SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize);
void SJUNI_Destroy(SJUNI sjuni);
void SJUNI_EntryErrFunc(SJUNI sjuni, SJUNI_ERRFN func, void* obj);
void SJUNI_Error(void);
void SJUNI_Finish(void);
void SJUNI_GetChunk(SJUNI sjuni, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJUNI_GetNumChainPool(SJ sj);
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id);
Sint32 SJUNI_GetNumData(SJUNI sjuni, Sint32 id);
UUID* SJUNI_GetUuid(SJUNI sjuni);
void SJUNI_Init(void);
Sint32 SJUNI_IsGetChunk(SJUNI sjuni, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJUNI_PutChunk(SJUNI sjuni, Sint32 id, SJCK *ck);
void SJUNI_Reset(SJUNI sjuni);   
void SJUNI_UngetChunk(SJUNI sjuni, Sint32 id, SJCK *ck);

#endif
