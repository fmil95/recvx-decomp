
typedef struct _sjmem 
{
    Sint8   unk0;
    Sint8   unk1;
    Sint8   unk2;
    Sint8   unk3;
    Sint32  unk4;
    Sint32  uuid;
    Sint32  unkC;
    Sint32  unk10;
    void*   buf;
    Sint32  bfsize;
    Sint32  unk1C;
    Sint32  unk20;
} SJMEM_OBJ;

typedef SJMEM_OBJ     *SJMEM;

SJ SJMEM_Create(Sint8 *data, Sint32 bsize)
{
    scePrintf("SJMEM_Create - UNIMPLEMENTED!\n");
}

// 100% matching!
void SJMEM_Destroy(SJMEM sjmem) 
{
    if (sjmem != NULL) 
    {
        memset(sjmem, 0, sizeof(SJMEM_OBJ));
        
        sjmem->unk4 = 0;
    }
}

// SJMEM_EntryErrFunc
// SJMEM_Error

void SJMEM_Finish(void)
{
    scePrintf("SJMEM_Finish - UNIMPLEMENTED!\n");
}

// 100% matching!
void* SJMEM_GetBufPtr(SJMEM sjmem) 
{
    return sjmem->buf;
}

// 100% matching!
Sint32 SJMEM_GetBufSize(SJMEM sjmem) 
{
    return sjmem->bfsize;
}

// SJMEM_GetChunk
// SJMEM_GetNumData

// 100% matching!
Sint32 SJMEM_GetUuid(SJMEM sjmem)
{
    return sjmem->uuid;
}

void SJMEM_Init(void)
{
    scePrintf("SJMEM_Init - UNIMPLEMENTED!\n");
}

// SJMEM_IsGetChunk
// SJMEM_PutChunk
// SJMEM_Reset
// SJMEM_UngetChunk
