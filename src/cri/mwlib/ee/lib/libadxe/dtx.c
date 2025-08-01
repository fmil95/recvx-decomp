
#define SSIZE 0x20

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

static sceSifClientData dtx_cd;
static u_int dtx_rbuf[SSIZE/sizeof(u_int)] __attribute__((aligned(64)));
static u_int dtx_sbuf[SSIZE/sizeof(u_int)] __attribute__((aligned(64)));

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

// 100% matching!
Sint32 dtx_create_rmt(Sint32 id, void* eewk, void* iopwk, Sint32 wklen)
{
    dtx_sbuf[0] = id;
    dtx_sbuf[1] = (Sint32)eewk;
    dtx_sbuf[2] = (Sint32)iopwk;
    dtx_sbuf[3] = wklen;
    
    sceSifCallRpc(&dtx_cd, 2, 0, dtx_sbuf, 4 * sizeof(u_int), dtx_rbuf, sizeof(u_int), NULL, NULL);
    
    return dtx_rbuf[0];
}

// dtx_def_rcvcbf
// dtx_def_sndcbf
// DTX_Destroy

// 100% matching!
void dtx_destroy_rmt(Sint32 no) 
{
    dtx_sbuf[0] = no;
    
    sceSifCallRpc(&dtx_cd, 3, 0, dtx_sbuf, sizeof(u_int), dtx_rbuf, 0, NULL, NULL);
}

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
