#ifndef _SJ_MEM_H_
#define _SJ_MEM_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "macros.h"

typedef void (*SJMEM_ERRFN)(void *obj, Sint32 errcode);

typedef struct 
{ 
	SJIF vtbl;
	Sint32 used;
	const UUID *uuid;
	Sint32 ndata;
	Sint32 rpos;
	Sint8 *buf;
	Sint32 bsize;
	SJMEM_ERRFN errfunc;
	void *errobj;
} SJMEM_OBJ;
typedef SJMEM_OBJ *SJMEM;

SJ SJMEM_Create(Sint8 *data, Sint32 dtsize);
void SJMEM_Destroy(SJ sj);
void SJMEM_EntryErrFunc(SJ sj, SJMEM_ERRFN func, void *obj);
void SJMEM_Error(void *obj, Sint32 errcode);
void SJMEM_Finish(void);
Sint8* SJMEM_GetBufPtr(SJMEM sjmem);
Sint32 SJMEM_GetBufSize(SJMEM sjmem);
void SJMEM_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJMEM_GetNumData(SJ sj, Sint32 id);
const UUID* SJMEM_GetUuid(SJ sj);
void SJMEM_Init(void);
Sint32 SJMEM_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJMEM_PutChunk(SJ sj, Sint32 id, SJCK *ck);
void SJMEM_Reset(SJ sj);
void SJMEM_UngetChunk(SJ sj, Sint32 id, SJCK *ck);

#endif
