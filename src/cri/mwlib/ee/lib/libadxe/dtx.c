
typedef struct _dtx 
{
    Sint32 unk0;
    Sint32 unk4;
    Sint32 unk8;
    Sint32 unkC;
    Sint32 unk10;
    Sint32 unk14;
    Sint32 unk18;
    Sint32 unk1C;
    Sint32 unk20;
    Sint32 unk24;
    Sint32 unk28;
    Sint32 unk2C;
} DTX_OBJ;

typedef DTX_OBJ *DTX;

void* DTX_CallUrpc(Sint32 arg0, void* sjrtm, Sint32 arg2, void* arg3, Sint32 arg4)
{
    scePrintf("DTX_CallUrpc - UNIMPLEMENTED!\n");
}

// 100% matching!
void DTX_Close(DTX dtx) 
{
    dtx->unk20 = 0;
    
    dtx->unk24 = 0;
    
    dtx->unk28 = 0;
    
    dtx->unk2C = 0;
}

void* DTX_Create(Sint32 maxnch, void* eewk, void* iopwk, Sint32 wklen)
{
    scePrintf("DTX_Create - UNIMPLEMENTED!\n");
}

// dtx_create_rmt
// dtx_def_rcvcbf
// dtx_def_sndcbf
// DTX_Destroy
// dtx_destroy_rmt
// DTX_ExecHndl
// DTX_ExecServer

void DTX_Finish(void)
{
    scePrintf("DTX_Finish - UNIMPLEMENTED!\n");
}

void DTX_Init(void)
{
    scePrintf("DTX_Init - UNIMPLEMENTED!\n");
}

// DTX_Open
// dtx_rpc_func

void DTX_SetRcvCbf(void* dtx, void* cbf, Sint32 bfsize)
{
    scePrintf("DTX_SetRcvCbf - UNIMPLEMENTED!\n");
}

void DTX_SetSndCbf(void* dtx, void* cbf, Sint32 bfsize)
{
    scePrintf("DTX_SetSndCbf - UNIMPLEMENTED!\n");
}

// dtx_svr_proc
