static Sint32 sjrmt_sbuf[1];
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

// SJRMT_GetChunk
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
