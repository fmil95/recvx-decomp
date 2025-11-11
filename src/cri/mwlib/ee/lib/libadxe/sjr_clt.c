#include "sjr_clt.h"
#include "dtx.h"

Char8* volatile sjrmt_build = "\nSJRMT Ver 0.93 Build:Jan 26 2001 09:59:44\n";
Sint32 sjrmt_init_cnt = 0;
static Sint32 sjrmt_sbuf[4]; // TODO: double-check the array size is correct here, and whether there should be 64-bit alignment
static Sint32 sjrmt_rbuf[4];

// 100% matching!
SJ SJMEM_CreateRmt(Sint8 *data, Sint32 dtsize)
{
    sjrmt_sbuf[0] = (Sint32)data;
    sjrmt_sbuf[1] = dtsize;
    
    DTX_CallUrpc(SJRMT_MEM_CREATE, sjrmt_sbuf, 2, sjrmt_rbuf, 1);
    
    return (SJ)sjrmt_rbuf[0];
}

// 100% matching!
SJ SJRBF_CreateRmt(Sint8 *buf, Sint32 bsize, Sint32 xsize)
{
    sjrmt_sbuf[0] = (Sint32)buf;
    sjrmt_sbuf[1] = bsize;
    sjrmt_sbuf[2] = xsize;
    
    DTX_CallUrpc(SJRMT_RBF_CREATE, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    return (SJ)sjrmt_rbuf[0];
}

// 100% matching!
void SJRMT_Destroy(SJ sj)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    
    DTX_CallUrpc(SJRMT_DESTROY, sjrmt_sbuf, 1, NULL, 0);
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
void SJRMT_GetChunk(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = nbyte;
    
    DTX_CallUrpc(SJRMT_GET_CHUNK, sjrmt_sbuf, 3, sjrmt_rbuf, 2);
    
    ck->data = (void*)sjrmt_rbuf[0];
    
    ck->len = sjrmt_rbuf[1];
}

// 100% matching!
Sint32 SJRMT_GetNumData(SJ sj, Sint32 id)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    sjrmt_sbuf[1] = id;
    
    DTX_CallUrpc(SJRMT_GET_NUM_DATA, sjrmt_sbuf, 2, sjrmt_rbuf, 1);
    
    return sjrmt_rbuf[0];
}

// 100% matching!
const UUID* SJRMT_GetUuid(SJ sj)
{
    static UUID uuid; 
    Sint32 *tmp;
    
    sjrmt_sbuf[0] = (Sint32)sj;
    
    DTX_CallUrpc(SJRMT_GET_UUID, sjrmt_sbuf, 1, sjrmt_rbuf, 4);

    tmp = (Sint32*)&uuid;
    
    tmp[0] = sjrmt_rbuf[0];
    tmp[1] = sjrmt_rbuf[1];
    tmp[2] = sjrmt_rbuf[2];
    tmp[3] = sjrmt_rbuf[3];
    
    return &uuid; // maybe should return tmp instead?
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
Sint32 SJRMT_IsGetChunk(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = nbyte;
    
    DTX_CallUrpc(SJRMT_IS_GET_CHUNK, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    *rbyte = sjrmt_rbuf[1];

    return sjrmt_rbuf[0];
}

// 100% matching!
void SJRMT_PutChunk(SJ sj, Sint32 id, SJCK *ck)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = (Sint32)ck->data;
    sjrmt_sbuf[3] = ck->len; 
    
    DTX_CallUrpc(SJRMT_PUT_CHUNK, sjrmt_sbuf, 4, NULL, 0);
}

// 100% matching!
void SJRMT_Reset(SJ sj)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    
    DTX_CallUrpc(SJRMT_RESET, sjrmt_sbuf, 1, NULL, 0);
}

// 100% matching!
void SJRMT_UngetChunk(SJ sj, Sint32 id, SJCK *ck)
{
    sjrmt_sbuf[0] = (Sint32)sj;
    sjrmt_sbuf[1] = id;
    sjrmt_sbuf[2] = (Sint32)ck->data;
    sjrmt_sbuf[3] = ck->len; 
    
    DTX_CallUrpc(SJRMT_UNGET_CHUNK, sjrmt_sbuf, 4, NULL, 0);
}

// 100% matching!
SJ SJUNI_CreateRmt(Sint32 mode, Sint8 *wk, Sint32 wksize)
{
    sjrmt_sbuf[0] = mode;
    sjrmt_sbuf[1] = (Sint32)wk;
    sjrmt_sbuf[2] = wksize;
    
    DTX_CallUrpc(SJRMT_UNI_CREATE, sjrmt_sbuf, 3, sjrmt_rbuf, 1);
    
    return (SJ)sjrmt_rbuf[0];
}
