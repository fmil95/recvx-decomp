#ifndef _SJX_H_
#define _SJX_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <sifdev.h>

typedef enum 
{
	SJX_DTXFNO_CREATE = 0,
	SJX_DTXFNO_DESTROY = 1,
	SJX_DTXFNO_RESET = 2,
	SJX_DTXFNO_REINIT = 3
} SJX_DTXFNO;

typedef enum
{
	SJX_CMD_PUT_CHUNK = 0
} SJX_CMDNO;

typedef struct 
{ 
	Sint8 no;
	Sint8 lin;
	Sint16 xid;
	SJ sj;
	SJCK ck;
} SJX_DTXCMD;

typedef struct 
{ 
	Sint32 ncmd;
	Sint32 rsv;
	Sint32 rsv2;
	Sint32 rsv3;
	SJX_DTXCMD cmd[128];
} SJX_DTXFMT;

typedef struct sjx_obj
{ 
	Sint8 used;
	Sint8 rsv;
	Sint16 xid;
	SJ sjsrc;
	SJ sjdst;
	Sint32 lin;
	void *iopsjx;
} SJX_OBJ;
typedef SJX_OBJ *SJX;

SJX SJX_Create(SJ sjsrc, SJ sjdst, Sint32 lin);
void SJX_Destroy(SJX sjx);
void SJX_ExecServer(void);
void SJX_Finish(void);
void SJX_Init(void);
void sjx_rcvcbf(void *obj, void *dt, Sint32 dtlen);
void SJX_Reset(SJX sjx);
void sjx_sndcbf(void *obj, void *dt, Sint32 dtlen);

#endif
