static Sint32 sjrmt_rbuf[2];
static Sint32 sjrmt_sbuf[3];
static Sint32 sjrmt_init_cnt;

// SJMEM_CreateRmt
// SJRBF_CreateRmt

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

// SJRMT_GetNumData
// SJRMT_GetUuid

// 100% matching!
void SJRMT_Init(void) 
{
    if (sjrmt_init_cnt == 0) 
    {
        DTX_Init();
    }
    
    sjrmt_init_cnt++;
}

// SJRMT_IsGetChunk
// SJRMT_PutChunk

// 100% matching!
void SJRMT_Reset(void* sjrmt) 
{
    sjrmt_sbuf[0] = (Sint32)sjrmt;
    
    DTX_CallUrpc(37, sjrmt_sbuf, 1, NULL, 0);
}

// SJRMT_UngetChunk

void* SJUNI_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    scePrintf("SJUNI_CreateRmt - UNIMPLEMENTED!\n");
}
