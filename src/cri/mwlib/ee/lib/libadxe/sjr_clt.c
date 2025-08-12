#include "sjr_clt.h"

static Char8* volatile sjrmt_build = "\nSJRMT Ver 0.93 Build:Jan 26 2001 09:59:44\n";
static Sint32 sjrmt_rbuf[4];
static Sint32 sjrmt_sbuf[4];
static Sint32 sjrmt_init_cnt = 0;

// 100% matching!
void* SJMEM_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    sjrmt_sbuf[0] = mode;
    sjrmt_sbuf[1] = (Sint32)work;
    
    DTX_CallUrpc(33, sjrmt_sbuf, 2, sjrmt_rbuf, 1);
    
    return (void*)sjrmt_rbuf[0];
}

// 100% matching!
void* SJRBF_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    sjrmt_sbuf[0] = mode;
    sjrmt_sbuf[1] = (Sint32)work;
    sjrmt_sbuf[2] = wksize;
    
    DTX_CallUrpc(32, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    return (void*)sjrmt_rbuf[0];
}

// 100% matching!
void SJRMT_Destroy(void* sjrmt)
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    
    DTX_CallUrpc(35, sjrmt_sbuf, 1, NULL, 0);
}

// 100% matching!
void SJRMT_Finish(void) 
{
    if (--sjrmt_init_cnt == 0) 
    {
        DTX_Finish();
    }
}

// 100% matching!
void SJRMT_GetChunk(void* sjrmt, Sint32 id, Sint32 nbyte, SJCK *ck) 
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = nbyte;
    
    DTX_CallUrpc(38, sjrmt_sbuf, 3, sjrmt_rbuf, 2);
    
    ck->data = (void*)sjrmt_rbuf[0];
    
    ck->len = sjrmt_rbuf[1];
}

// 100% matching!
Sint32 SJRMT_GetNumData(void* sjrmt, Sint32 id) 
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    sjrmt_sbuf[1] = id;
    
    DTX_CallUrpc(41, sjrmt_sbuf, 2, sjrmt_rbuf, 1);
    
    return sjrmt_rbuf[0];
}

// 100% matching!
UUID* SJRMT_GetUuid(void* sjrmt) 
{
    static UUID uuid; 
    
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    
    DTX_CallUrpc(36, sjrmt_sbuf, 1, sjrmt_rbuf, 4);

    // the following lines are copying bytes manually, but likely there was some use of memcpy here 
    uuid.Data1 = sjrmt_rbuf[0];
    *(int*)&uuid.Data2 = sjrmt_rbuf[1];
    *(int*)&uuid.Data4[0] = sjrmt_rbuf[2];
    *(int*)&uuid.Data4[4] = sjrmt_rbuf[3];
    
    return &uuid; 
}

// 100% matching!
void SJRMT_Init(void) 
{
    if (sjrmt_init_cnt == 0) 
    {
        DTX_Init();
    }
    
    sjrmt_init_cnt++;
}

// 100% matching!
Sint32 SJRMT_IsGetChunk(void* sjrmt, Sint32 id, Sint32 nbyte, Sint32 *rbyte) 
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = nbyte;
    
    DTX_CallUrpc(42, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    *rbyte = sjrmt_rbuf[1];

    return sjrmt_rbuf[0];
}

// 100% matching!
void SJRMT_PutChunk(void* sjrmt, Sint32 id, SJCK *ck)
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = (Sint32)ck->data;
    sjrmt_sbuf[3] = ck->len; 
    
    DTX_CallUrpc(40, sjrmt_sbuf, 4, NULL, 0);
}

// 100% matching!
void SJRMT_Reset(void* sjrmt) 
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    
    DTX_CallUrpc(37, sjrmt_sbuf, 1, NULL, 0);
}

// 100% matching!
void SJRMT_UngetChunk(void* sjrmt, Sint32 id, SJCK *ck)
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = (Sint32)ck->data;
    sjrmt_sbuf[3] = ck->len; 
    
    DTX_CallUrpc(39, sjrmt_sbuf, 4, NULL, 0);
}

// 100% matching!
void* SJUNI_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    sjrmt_sbuf[0] = mode;
    sjrmt_sbuf[1] = (Sint32)work;
    sjrmt_sbuf[2] = wksize;
    
    DTX_CallUrpc(34, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    return (void*)sjrmt_rbuf[0];
}
