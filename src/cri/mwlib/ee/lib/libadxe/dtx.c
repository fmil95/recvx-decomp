
#define SSIZE 0x20

typedef struct _dtx 
{
    Sint8  used;
    Sint8  unk1;
    Sint8  unk2;
    Sint8  unk3;
    Sint32 rmt;
    Sint32 unk8;
    void*  eewk;
    Sint32 eewkln;
    Sint32 unk14;
    void*  iopwk;
    Sint32 wklen;
    void*  rcvcbf;
    Sint32 unk24;
    void*  sndcbf;
    Sint32 unk2C;
    Sint32 unk30;
    Sint32 unk34;
    Sint32 unk38;
    Sint32 unk3C;
    Sint32 unk40;
} DTX_OBJ;

typedef DTX_OBJ *DTX;

static sceSifClientData dtx_cd = { 0 };
static u_int dtx_rbuf[SSIZE/sizeof(u_int)] __attribute__((aligned(64)));
static u_int dtx_sbuf[SSIZE/sizeof(u_int)] __attribute__((aligned(64)));

DTX_OBJ dtx_clnt[8] = { 0 };
Sint32 dtx_init_cnt;
Sint32 dtx_rpc_id;

void dtx_def_rcvcbf(void);
void dtx_def_sndcbf(void);

void* DTX_CallUrpc(Sint32 arg0, void* sjrtm, Sint32 arg2, void* arg3, Sint32 arg4)
{
    scePrintf("DTX_CallUrpc - UNIMPLEMENTED!\n");
}

// 100% matching!
void DTX_Close(DTX dtx) 
{
    dtx->rcvcbf = NULL;
    dtx->unk24 = 0;
    
    dtx->sndcbf = NULL;
    dtx->unk2C = 0;
}

// 100% matching!
DTX DTX_Create(Uint32 id, void* eewk, void* iopwk, Sint32 wklen)
{
    DTX dtx;

    if (((Sint32)eewk & 0x3F)) 
    {
        printf("eewk is not alignment 64 byte\n");
        
        return NULL;
    }

    if (((Sint32)iopwk & 0x1F))
    {
        printf("iopwk is not alignment 32 byte\n");
        
        return NULL;
    }

    if ((wklen & 0x3F))
    {
        printf("wklen=%d is not 64*N\n", wklen);
        
        return NULL;
    }

    if (id >= 8) 
    {
        printf("illeagal ID (%d) \n", id);
        
        return NULL;
    }

    dtx = &dtx_clnt[id];

    if (dtx->used != FALSE)
    {
        return NULL;
    }

    dtx->rmt = dtx_create_rmt(id, eewk, iopwk, wklen);

    if (dtx->rmt == 0) 
    {
        printf("DTX_Create: can't create DTX of server\n");
        
        return NULL;
    }

    dtx->unk8 = 0;
    
    dtx->eewkln = wklen - 64;
    dtx->wklen = wklen;
    
    dtx->iopwk = iopwk;
    
    dtx->unk14 = ((Sint32)eewk + dtx->eewkln) | UNCBASE;
    
    dtx->eewk = eewk;
    
    dtx->unk1 = 0;
    
    memset(eewk, 0, dtx->eewkln);
    
    SyncDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) + 63));
    InvalidDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) + 63));
    
    dtx->rcvcbf = dtx_def_rcvcbf;
    dtx->sndcbf = dtx_def_sndcbf;
    
    dtx->unk24 = 0;
    
    dtx->unk2C = 0;
    
    dtx->used = TRUE;

    return dtx;
}

// 100% matching!
Sint32 dtx_create_rmt(Uint32 id, void* eewk, void* iopwk, Sint32 wklen)
{
    dtx_sbuf[0] = id;
    dtx_sbuf[1] = (Sint32)eewk;
    dtx_sbuf[2] = (Sint32)iopwk;
    dtx_sbuf[3] = wklen;
    
    sceSifCallRpc(&dtx_cd, 2, 0, dtx_sbuf, 4 * sizeof(u_int), dtx_rbuf, sizeof(u_int), NULL, NULL);
    
    return dtx_rbuf[0];
}

void dtx_def_rcvcbf(void)
{
    scePrintf("dtx_def_rcvcbf - UNIMPLEMENTED!\n");
}

void dtx_def_sndcbf(void)
{
    scePrintf("dtx_def_sndcbf - UNIMPLEMENTED!\n");
}

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

// 99.76% matching
void DTX_Init(void) 
{
    Sint32 i;

    if (dtx_init_cnt == 0)
    {
        while (TRUE) 
        {
            if (sceSifBindRpc(&dtx_cd, dtx_rpc_id, 0) < 0) 
            {
                printf("E0092101: DTX_Init bind errr\n");
                
                while (TRUE);
            }
    
            if (dtx_cd.serve != NULL) 
            {
                break;
            }

            for (i = 65536; i != -1; i--);
        }
    }

    dtx_init_cnt++;
}

// 100% matching!
DTX DTX_Open(Uint32 id)
{
    if (id >= 8) 
    {
        return NULL;
    }
    
    return &dtx_clnt[id];
}

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
