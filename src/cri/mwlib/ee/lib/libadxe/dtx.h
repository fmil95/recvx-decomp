#ifndef _DTX_H_
#define _DTX_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <eetypes.h>
#include <sif.h>
#include <sifrpc.h>

// TODO: move this define somewhere else
#define UNCBASE 0x20000000

typedef enum
{
	DTX_FNO_INIT = 0,
	DTX_FNO_FINISH = 1,
	DTX_FNO_CREATE = 2,
	DTX_FNO_DESTROY = 3
} DTX_RPCFNO;

typedef struct 
{
	Sint32 ftlen;
	Sint32 dtlen;
	Sint32 rsv2;
	Sint32 rsv3;
	Sint32 rsv4;
	Sint32 rsv5;
	Sint32 rsv6;
	Sint32 rsv7;
	Sint32 rsv8;
	Sint32 rsv9;
	Sint32 rsv10;
	Sint32 rsv11;
	Sint32 rsv12;
	Sint32 rsv13;
	Sint32 rsv14;
	Sint32 ticket_no;
} DTX_FOOTER;

typedef void (*DTX_RCVCBF)(void *obj, void *dt, Sint32 dtlen);
typedef void (*DTX_SNDCBF)(void *obj, void *dt, Sint32 dtlen);

typedef struct dtx_obj 
{ 
	Sint8 used;
	Sint8 wait_flag;
	Sint8 send_flag;
	Sint8 rsv;
	struct dtx_obj *dtxsvr;
	Sint32 ticket_no;
	Sint8 *dt;
	Sint32 dtlen;
	DTX_FOOTER *ftr;
	Sint8 *trdt;
	Sint32 trlen;
	DTX_RCVCBF rcvcbf;
	void *rcvcbo;
	DTX_SNDCBF sndcbf;
	void *sndcbo;
	sceSifDmaData dma;
	Sint32 dma_id;
} DTX_OBJ;
typedef DTX_OBJ *DTX;

Sint32 DTX_CallUrpc(Sint32 fno, Sint32 *in, Sint32 nin, Sint32 *out, Sint32 nout);
void DTX_Close(DTX dtx);
DTX DTX_Create(Sint32 id, Sint8 *eewk, Sint8 *iopwk, Sint32 wklen);
DTX dtx_create_rmt(Sint32 id, Sint8 *eewk, Sint8 *iopwk, Sint32 wklen);
void dtx_def_rcvcbf(void *obj, void *dt, Sint32 dtlen);
void dtx_def_sndcbf(void *obj, void *dt, Sint32 dtlen);
void DTX_Destroy(DTX dtx);
void dtx_destroy_rmt(DTX dtx);
void DTX_ExecHndl(DTX dtx);
void DTX_ExecServer(void);
void DTX_Finish(void);
void DTX_Init(void);
DTX DTX_Open(Sint32 id);
void* dtx_rpc_func(unsigned int fno, void *data, int size);
void DTX_SetRcvCbf(DTX dtx, DTX_RCVCBF fn, void *obj);
void DTX_SetSndCbf(DTX dtx, DTX_SNDCBF fn, void *obj);
int dtx_svr_proc(void);

#endif
