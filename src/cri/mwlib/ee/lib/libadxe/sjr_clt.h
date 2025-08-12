#ifndef _SJR_CLT_H_
#define _SJR_CLT_H_

void* SJMEM_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize);
void* SJRBF_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize);
void SJRMT_Destroy(void* sjrmt);
void SJRMT_Finish(void);
void SJRMT_GetChunk(void* sjrmt, Sint32 id, Sint32 nbyte, SJCK *ck);
Sint32 SJRMT_GetNumData(void* sjrmt, Sint32 id);
UUID* SJRMT_GetUuid(void* sjrmt);
void SJRMT_Init(void);
Sint32 SJRMT_IsGetChunk(void* sjrmt, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
void SJRMT_PutChunk(void* sjrmt, Sint32 id, SJCK *ck);
void SJRMT_Reset(void* sjrmt);
void SJRMT_UngetChunk(void* sjrmt, Sint32 id, SJCK *ck);
void* SJUNI_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize);

#endif
