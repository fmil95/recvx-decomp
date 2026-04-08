#ifndef _DTR_H_
#define _DTR_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <sif.h>
#include "macros.h"

typedef enum 
{
	DTR_DTXFNO_CREATE = 0,
	DTR_DTXFNO_DESTROY = 1
} DTR_DTXFNO;

typedef enum 
{
	DTR_STAT_STOP = 0,
	DTR_STAT_EXEC = 1
} DTR_STAT;

typedef struct dtr_obj
{ 
	Sint8 used;
	Sint8 stat;
	Sint8 trnflg;
	Sint8 rsv;
	SJ sjsrc;
	SJ sjdst;
	SJCK cks;
	SJCK ckd;
	sceSifDmaData dma;
	Sint32 dma_id;
	Sint32 srclin;
	Sint32 dstlin;
	Sint32 blklen;
	Sint32 total_tbyte;
} DTR_OBJ;
typedef DTR_OBJ *DTR;

DTR DTR_Create(SJ sjsrc, SJ sjdst);
void DTR_Destroy(DTR dtr);
void DTR_ExecHndl(DTR dtr);
void DTR_ExecServer(void);
void DTR_Finish(void);
void DTR_Init(void);
void DTR_Start(DTR dtr);
void DTR_Stop(DTR dtr);

#endif
