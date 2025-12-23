#include "dtx.h"

#include <stdio.h>
#include <string.h>

#include <eetypes.h>
#include <eekernel.h>
#include <sifrpc.h>

Char8* volatile dtx_build = "\nDTX Ver.0.95 Build:Jan 26 2001 09:57:12\n";
Sint32 dtx_rpc_id = 0x7D000000;
Sint32 volatile dtx_proc_init_flag = 0;
Sint32 dtx_init_cnt = 0;
DTX_OBJ dtx_clnt[8] = { 0 };
DTX_OBJ dtx_svr[8] = { 0 }; /* unused */
sceSifClientData dtx_cd = { 0 };
sceSifServeData dtx_sd = { 0 };
u_long128 dtx_svrbuf[16] = { 0 };
sceSifRpcFunc dtx_urpc_fn[64] = { 0 };
void *dtx_urpc_obj[64] = { 0 }; 
static Uint32 dtx_sbuf[64] __attribute__((aligned(64))); 
static Uint32 dtx_rbuf[64] __attribute__((aligned(64)));

// 100% matching!
Sint32 DTX_CallUrpc(Sint32 fno, Sint32 *in, Sint32 nin, Sint32 *out, Sint32 nout)
{
    Sint32 i;

    for (i = 0; i < nin; i++)
    {
        dtx_sbuf[i] = in[i];
    }

    sceSifCallRpc(&dtx_cd, fno + 1024, 0, dtx_sbuf, nin * sizeof(Uint32), dtx_rbuf, nout * sizeof(Uint32), NULL, NULL);

    for (i = 0; i < nout; i++)
    {
        out[i] = dtx_rbuf[i];
    }
    
    return dtx_rbuf[0]; 
}

// 100% matching!
void DTX_Close(DTX dtx) 
{
    dtx->rcvcbf = NULL;
    dtx->rcvcbo = NULL;
    
    dtx->sndcbf = NULL;
    dtx->sndcbo = NULL;
}

// 100% matching!
DTX DTX_Create(Sint32 id, Sint8 *eewk, Sint8 *iopwk, Sint32 wklen)
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

    if ((Uint32)id >= 8) 
    {
        printf("illeagal ID (%d) \n", id);
        
        return NULL;
    }

    dtx = &dtx_clnt[id];

    if (dtx->used != FALSE)
    {
        return NULL;
    }

    dtx->dtxsvr = dtx_create_rmt(id, eewk, iopwk, wklen);

    if (dtx->dtxsvr == NULL) 
    {
        printf("DTX_Create: can't create DTX of server\n");
        
        return NULL;
    }

    dtx->ticket_no = 0;
    
    dtx->dtlen = wklen - 64;
    dtx->trlen = wklen;
    
    dtx->trdt = iopwk;
    
    dtx->ftr = (void*)(((Sint32)eewk + dtx->dtlen) | UNCBASE); // casts added for MWCC compatibility
    
    dtx->dt = eewk;
    
    dtx->wait_flag = 0;
    
    memset(eewk, 0, dtx->dtlen);
    
    SyncDCache(dtx->dt, (void*)(((Sint8*)dtx->dt + dtx->dtlen) + 63)); // same as above 
    InvalidDCache(dtx->dt, (void*)(((Sint8*)dtx->dt + dtx->dtlen) + 63)); 
    
    dtx->rcvcbf = (void*)dtx_def_rcvcbf;
    dtx->sndcbf = (void*)dtx_def_sndcbf;
    
    dtx->rcvcbo = NULL;
    dtx->sndcbo = NULL;
    
    dtx->used = TRUE;

    return dtx;
}

// 100% matching!
DTX dtx_create_rmt(Sint32 id, Sint8 *eewk, Sint8 *iopwk, Sint32 wklen)
{
    dtx_sbuf[0] = id;
    dtx_sbuf[1] = (Sint32)eewk;
    dtx_sbuf[2] = (Sint32)iopwk;
    dtx_sbuf[3] = wklen;
    
    sceSifCallRpc(&dtx_cd, 2, 0, dtx_sbuf, 4 * sizeof(Uint32), dtx_rbuf, sizeof(Uint32), NULL, NULL);
    
    return (DTX)dtx_rbuf[0];
}

// 100% matching!
void dtx_def_rcvcbf(void *obj, void *dt, Sint32 dtlen)
{
    static Sint32 cnt = 0;
    
    cnt++;
}

// 100% matching!
void dtx_def_sndcbf(void *obj, void *dt, Sint32 dtlen)
{
    static Sint32 cnt = 0;
    Sint32 i;

    for (i = 0; i < dtlen; i++) 
    {
        ((Sint8*)dt)[i] = -86;
    }
    
    sprintf(dt, "Hello from EE (%d)", cnt);
    
    cnt++; 
}

// 100% matching!
void DTX_Destroy(DTX dtx)
{
    dtx_destroy_rmt(dtx->dtxsvr);
    
    memset(dtx, 0, sizeof(DTX_OBJ)); 
}

// 100% matching!
void dtx_destroy_rmt(DTX dtx)
{
    dtx_sbuf[0] = (Sint32)dtx;
    
    sceSifCallRpc(&dtx_cd, 3, 0, dtx_sbuf, sizeof(Uint32), dtx_rbuf, 0, NULL, NULL);
}

// 100% matching!
void DTX_ExecHndl(DTX dtx)
{
    static Sint32 cnt = 0;
    
    cnt++;

    if ((dtx->wait_flag == 1) && (dtx->ticket_no < dtx->ftr->ticket_no)) 
    {
        InvalidDCache(dtx->dt, (void*)((Sint8*)dtx->dt + (dtx->dtlen - 1))); // casts added for MWCC compatibility
        
        dtx->rcvcbf(dtx->rcvcbo, dtx->dt, dtx->dtlen);
        
        dtx->ticket_no = dtx->ftr->ticket_no;
        
        dtx->wait_flag = 0;
    }

    if (dtx->wait_flag == 0) 
    {
        dtx->sndcbf(dtx->sndcbo, dtx->dt, dtx->dtlen);
        
        dtx->ticket_no++;
        
        dtx->ftr->ticket_no = dtx->ticket_no;
        
        SyncDCache(dtx->dt, (void*)(((Sint8*)dtx->dt + dtx->dtlen) - 1)); // same as above
        InvalidDCache(dtx->dt, (void*)(((Sint8*)dtx->dt + dtx->dtlen) + 63)); 
        
        dtx->dma.data = (Sint32)dtx->dt & 0xFFFFFFF;
        
        dtx->dma.addr = (Sint32)dtx->trdt;
        
        dtx->dma.size = dtx->trlen; 
        
        dtx->dma.mode = 0;
        
        dtx->dma_id = sceSifSetDma(&dtx->dma, 1);
        
        dtx->wait_flag = 1;
    }
}

// 100% matching!
void DTX_ExecServer(void)
{
    Sint32 i;
    DTX dtx;

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
    Sint32 i;
    DTX dtx;

    dtx = NULL;

    if (--dtx_init_cnt == 0) 
    {
        dtx++; // FAKE: this operation is invalid, it's only allowed for match purposes
        
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
    int i;

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
DTX DTX_Open(Sint32 id)
{
    if ((Uint32)id >= 8) 
    {
        return NULL;
    }
    
    return &dtx_clnt[id];
}

// 100% matching!
void* dtx_rpc_func(unsigned int fno, void *data, int size)
{
    Sint32 *arg;
    sceSifRpcFunc fn;

    arg = data;

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
                fn((Uint32)dtx_urpc_obj[fno - 1024], arg, (Uint32)size / 4);
            }
        }         
        
        break;
    case 2:
        arg[0] = (Sint32)DTX_Create(arg[0], (Sint8*)arg[1], (Sint8*)arg[2], arg[3]); 
        break;
    case 3:
        DTX_Destroy((DTX)arg[0]);
        break;
    }
    
    SJCRS_Unlock();
    
    return arg; 
}

// 100% matching!
void DTX_SetRcvCbf(DTX dtx, DTX_RCVCBF fn, void *obj)
{
    dtx->rcvcbf = fn;
    dtx->rcvcbo = obj;
}

// 100% matching!
void DTX_SetSndCbf(DTX dtx, DTX_SNDCBF fn, void *obj)
{
    dtx->sndcbf = fn;
    dtx->sndcbo = obj;
}

// 100% matching!
int dtx_svr_proc()
{
    sceSifQueueData qd;
    sceSifQueueData qd0;

    sceSifSetRpcQueue(&qd, GetThreadId());
    sceSifSetRpcQueue(&qd0, GetThreadId());
    
    sceSifRegisterRpc(&dtx_sd, dtx_rpc_id, (sceSifRpcFunc)dtx_rpc_func, dtx_svrbuf, NULL, NULL, &qd);
    
    dtx_proc_init_flag = 1;
    
    sceSifRpcLoop(&qd);
    
    return 0;
}
