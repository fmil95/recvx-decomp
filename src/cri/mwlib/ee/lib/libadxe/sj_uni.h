#ifndef _SJ_UNI_H_
#define _SJ_UNI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>

typedef struct _sjck_chain
{ 
	struct _sjck_chain *next;
	Sint32 rsv;
	SJCK ck;
} SJCK_CHAIN;
typedef SJCK_CHAIN *SJCKCN;

typedef void (*SJUNI_ERRFN)(void *obj, Sint32 errcode);

typedef struct 
{ 
	SJIF vtbl;
	Sint8 used;
	Sint8 mode;
	Sint16 rsv1;
	const UUID *uuid;
	SJCKCN ckcnwk;
	Sint32 nckcn;
	SJCKCN pool;
	SJCKCN lin[4];
	SJUNI_ERRFN errfunc;
	void *errobj;
} SJUNI_OBJ;
typedef SJUNI_OBJ *SJUNI;

SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize);
void SJUNI_Destroy(SJ sj);
void SJUNI_EntryErrFunc(SJ sj, SJUNI_ERRFN func, void *obj);
void SJUNI_Error(SJUNI uni, Sint32 errcode);
void SJUNI_Finish(void);
void SJUNI_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJUNI_GetNumChainPool(SJ sj);
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id);
Sint32 SJUNI_GetNumData(SJ sj, Sint32 id);
const UUID* SJUNI_GetUuid(SJ sj);
void SJUNI_Init(void);
Sint32 SJUNI_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJUNI_PutChunk(SJ sj, Sint32 id, SJCK *ck);
void SJUNI_Reset(SJ sj);
void SJUNI_UngetChunk(SJ sj, Sint32 id, SJCK *ck);

#endif
