static Sint32 sjrmt_init_cnt;

// SJMEM_CreateRmt
// SJRBF_CreateRmt

void SJRMT_Destroy(void* sjrmt)
{
    scePrintf("SJRMT_Destroy - UNIMPLEMENTED!\n");
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

void SJRMT_Reset(void* sjrmt)
{
    scePrintf("SJRMT_Reset - UNIMPLEMENTED!\n");
}

// SJRMT_UngetChunk

void* SJUNI_CreateRmt(Sint32 mode, Sint8 *work, Sint32 wksize)
{
    scePrintf("SJUNI_CreateRmt - UNIMPLEMENTED!\n");
}
