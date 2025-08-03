#include "dtx.h"

DTX_OBJ dtx_clnt[8] = { 0 };
Sint32 dtx_svr[136] = { 0 }; /* unused */
static sceSifClientData dtx_cd = { 0 };
sceSifServeData dtx_sd = { 0 };
Uint32 dtx_svrbuf[64] = { 0 };
sceSifRpcFunc dtx_urpc_fn[64] = { 0 };
Uint32 dtx_urpc_obj[64] = { 0 }; 
static u_int dtx_rbuf[RSIZE/sizeof(u_int)] __attribute__((aligned(64)));
static u_int dtx_sbuf[SSIZE/sizeof(u_int)] __attribute__((aligned(64)));
Sint32 dtx_init_cnt;
Uint32 dtx_rpc_id;
Sint32 volatile dtx_proc_init_flag;

// 100% matching!
Sint32 DTX_CallUrpc(Sint32 cmd, Sint32* sbuf, Sint32 ssize, Sint32* rbuf, Sint32 rsize)
{
    Sint32 i;

    for (i = 0; i < ssize; i++)
    {
        dtx_sbuf[i] = sbuf[i];
    }

    sceSifCallRpc(&dtx_cd, cmd + 1024, 0, dtx_sbuf, ssize * sizeof(Uint32), dtx_rbuf, rsize * sizeof(Uint32), NULL, NULL);

    for (i = 0; i < rsize; i++)
    {
        rbuf[i] = dtx_rbuf[i];
    }
    
    return dtx_rbuf[0]; 
}

// 100% matching!
void DTX_Close(DTX dtx) 
{
    dtx->rcvcbf = NULL;
    dtx->rcvbfsz = 0;
    
    dtx->sndcbf = NULL;
    dtx->sndbfsz = 0;
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
    dtx->iopwkln = wklen;
    
    dtx->iopwk = iopwk;
    
    dtx->unk14 = (Sint32*)(((Sint32)eewk + dtx->eewkln) | UNCBASE);
    
    dtx->eewk = eewk;
    
    dtx->stat = 0;
    
    memset(eewk, 0, dtx->eewkln);
    
    SyncDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) + 63));
    InvalidDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) + 63));
    
    dtx->rcvcbf = (void*)dtx_def_rcvcbf;
    dtx->sndcbf = (void*)dtx_def_sndcbf;
    
    dtx->rcvbfsz = 0;
    dtx->sndbfsz = 0;
    
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

// 100% matching!
void dtx_def_rcvcbf(DTX dtx, void* buf, Sint32 bfsize) 
{
    static Sint32 cnt = 0;
    
    cnt++;
}

// 100% matching!
void dtx_def_sndcbf(DTX dtx, void* buf, Sint32 bfsize)
{
    static Sint32 cnt = 0;
    Sint32 i;

    for (i = 0; i < bfsize; i++) 
    {
        ((Sint8*)buf)[i] = -86;
    }
    
    sprintf(buf, "Hello from EE (%d)", cnt);
    
    cnt++; 
}

// 100% matching!
void DTX_Destroy(DTX dtx)
{
    dtx_destroy_rmt(dtx->rmt);
    
    memset(dtx, 0, sizeof(DTX_OBJ)); 
}

// 100% matching!
void dtx_destroy_rmt(Uint32 id) 
{
    dtx_sbuf[0] = id;
    
    sceSifCallRpc(&dtx_cd, 3, 0, dtx_sbuf, sizeof(u_int), dtx_rbuf, 0, NULL, NULL);
}

// 99.54% matching
void DTX_ExecHndl(DTX dtx)
{
    static Sint32 cnt = 0;
    
    cnt++;

    if ((dtx->stat == 1) && (dtx->unk8 < dtx->unk14[15])) 
    {
        InvalidDCache(dtx->eewk, (void*)((Sint32)dtx->eewk + (dtx->eewkln - 1))); // remove cast to match 100%
        
        dtx->rcvcbf(dtx->rcvbfsz, dtx->eewk, dtx->eewkln);
        
        dtx->unk8 = dtx->unk14[15];
        
        dtx->stat = 0;
    }

    if (dtx->stat == 0) 
    {
        dtx->sndcbf(dtx->sndbfsz, dtx->eewk, dtx->eewkln);
        
        dtx->unk8++;
        
        dtx->unk14[15] = dtx->unk8;
        
        SyncDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) - 1));
        InvalidDCache(dtx->eewk, (void*)(((Sint32)dtx->eewk + dtx->eewkln) + 63));
        
        dtx->transData.data = (Sint32)dtx->eewk & 0xFFFFFFF;
        dtx->transData.addr = (Sint32)dtx->iopwk;
        dtx->transData.size = dtx->iopwkln; 
        dtx->transData.mode = 0;
        
        dtx->did = sceSifSetDma(&dtx->transData, 1);
        
        dtx->stat = 1;
    }
}

// 100% matching!
void DTX_ExecServer(void)
{
    DTX dtx;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < 8; i++) 
    {
        dtx = &dtx_clnt[i];

        if (dtx->used == TRUE) 
        {
            DTX_ExecHndl(dtx);
        }
    }

    SJCRS_Unlock();
}

// 100% matching!
void DTX_Finish(void)
{
    DTX dtx;
    Sint32 i;

    if (--dtx_init_cnt == 0) 
    {
        dtx++;
        
        for (i = 0; i < 8; i++) 
        {
            dtx = &dtx_clnt[i];
    
            if (dtx->used == TRUE)
            {
                DTX_Destroy(dtx);
            }
        }
    }
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

// 100% matching!
void* dtx_rpc_func(Uint32 fno, DTX_RPC data, Uint32 size)
{
    sceSifRpcFunc fn;

    SJCRS_Lock();

    switch (fno) 
    {
    case 0:
    case 1:
        break;
    default:
        if ((fno >= 1024) && (fno < 1088)) 
        {
            fn = dtx_urpc_fn[fno - 1024];
            
            if (fn != NULL) 
            {
                fn(dtx_urpc_obj[fno - 1024], data, size / 4);
            }
        }         
        
        break;
    case 2:
        data->dtx = DTX_Create((Sint32)data->dtx, data->eewk, data->iopwk, data->wklen);
        break;
    case 3:
        DTX_Destroy(data->dtx);
        break;
    }
    
    SJCRS_Unlock();
    
    return data; 
}

// 100% matching!
void DTX_SetRcvCbf(DTX dtx, void* buf, Sint32 bfsize) 
{
    dtx->rcvcbf = buf;
    dtx->rcvbfsz = bfsize;
}

// 100% matching!
void DTX_SetSndCbf(DTX dtx, void* buf, Sint32 bfsize)
{
    dtx->sndcbf = buf;
    dtx->sndbfsz = bfsize;
}

// 100% matching!
Sint32 dtx_svr_proc(void)
{
    sceSifQueueData qd1;
    sceSifQueueData qd2;

    sceSifSetRpcQueue(&qd1, GetThreadId());
    sceSifSetRpcQueue(&qd2, GetThreadId());
    
    sceSifRegisterRpc(&dtx_sd, dtx_rpc_id, (sceSifRpcFunc)dtx_rpc_func, dtx_svrbuf, NULL, NULL, &qd1);
    
    dtx_proc_init_flag = 1;
    
    sceSifRpcLoop(&qd1);
    
    return 0;
}
