#ifndef _DTX_H_
#define _DTX_H_

#include <cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <sif.h>
#include <sifrpc.h>

// TODO: move the following typedef and the three defines below somewhere else
typedef unsigned int u_int;

#define UNCBASE 0x20000000

#define SSIZE 32
#define RSIZE 32

typedef void (*DTX_RCVCBF)(Sint32 bfsize, void* eewk, Sint32 eewkln);
typedef void (*DTX_SNDCBF)(Sint32 bfsize, void* eewk, Sint32 eewkln);

typedef struct _dtx_obj
{
    Sint8          used;
    Sint8          stat;
    Sint8          unk2;      /* unused */
    Sint8          unk3;      /* unused */
    Sint32         rmt;
    Sint32         unk8;
    void*          eewk;
    Sint32         eewkln;
    Sint32*        unk14;
    void*          iopwk;
    Sint32         iopwkln;
    DTX_RCVCBF     rcvcbf;
    Sint32         rcbfsz;
    DTX_SNDCBF     sndcbf;
    Sint32         snbfsz;
    sceSifDmaData  sdd;
    Sint32         did;
} DTX_OBJ;

typedef DTX_OBJ *DTX;

typedef struct _dtx_rpc_obj
{
    DTX     dtx;
    void*   eewk;
    void*   iopwk;
    Sint32  wklen;
} DTX_RPC_OBJ;

typedef DTX_RPC_OBJ *DTX_RPC;

Sint32 DTX_CallUrpc(Sint32 cmd, Sint32* sbuf, Sint32 ssize, Sint32* rbuf, Sint32 rsize);
void DTX_Close(DTX dtx);
DTX DTX_Create(Uint32 id, void* eewk, void* iopwk, Sint32 wklen);
Sint32 dtx_create_rmt(Uint32 id, void* eewk, void* iopwk, Sint32 wklen);
void dtx_def_rcvcbf(DTX dtx, void* buf, Sint32 bfsize);
void dtx_def_sndcbf(DTX dtx, void* buf, Sint32 bfsize);
void DTX_Destroy(DTX dtx);
void dtx_destroy_rmt(Uint32 id);
void DTX_ExecHndl(DTX dtx);
void DTX_ExecServer(void);
void DTX_Finish(void);
void DTX_Init(void);
DTX DTX_Open(Uint32 id);
void* dtx_rpc_func(Uint32 fno, DTX_RPC data, Uint32 size);
void DTX_SetRcvCbf(DTX dtx, void* buf, Sint32 bfsize);
void DTX_SetSndCbf(DTX dtx, void* buf, Sint32 bfsize);
Sint32 dtx_svr_proc(void);

#endif
