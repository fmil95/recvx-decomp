#ifndef _PS2_RNA_H_
#define _PS2_RNA_H_

#include "dtr.h"
#include "sjx.h"

typedef void (*PSMOUT_TRANSFN)();

typedef struct _psmout_obj
{ 
	Sint8 used;
	Sint8 stat;
	Sint8 core_no;
	Sint8 rsv;
	SJ sj[2];
	Sint8 *buf;
	Sint32 bsize;
	Sint32 nblk;
	Sint32 bank;
	PSMOUT_TRANSFN transfn;
	void *transobj;
	Sint8 sjwk[2][64];
} PSMOUT_OBJ;
typedef PSMOUT_OBJ *PSMOUT;

typedef struct _rcv_obj
{ 
	Sint32 used;
	Sint32 stat;
	SJ sj_in;
	SJ sj_out;
	Sint32 pitch;
	Sint32 gap;
	Sint32 last;
	Sint16 cache[4];
	Sint32 max_smpl;
	Sint32 min_smpl;
	Sint32 total_in;
	Sint32 total_out;
	Sint32 sfreq_in;
	Sint32 sfreq_out;
	Sint32 cnv_rate;
	void (*cnv_func)();
} RCV_OBJ;
typedef RCV_OBJ *RCV;

typedef struct _psmmix_obj
{ 
	Sint8 used;
	Sint8 stat;
	Sint16 rsv;
	Sint32 nch;
	Sint32 ntpi;
	Sint32 bsize;
	SJ sji[16];
	SJ sjo[2];
	Sint32 vol[16][2];
} PSMMIX_OBJ;
typedef PSMMIX_OBJ *PSMMIX;

typedef struct _psmslt_obj
{ 
	Sint8 used;
	Sint8 stat;
	Sint16 rsv;
	SJ sji;
	SJ sjo;
	Sint32 sfreq;
	Sint32 tssmpl;
	Sint32 tdsmpl;
	Sint32 rdsmpl;
	Sint32 wrsmpl;
	RCV rcv;
} PSMSLT_OBJ;
typedef PSMSLT_OBJ *PSMSLT;

typedef struct _psmtbf_obj 
{ 
	Sint32 used;
	Sint8 *buf;
} PSMTBF_OBJ;
typedef PSMTBF_OBJ *PSMTBF;

typedef struct _psm_obj
{
	Sint8 used;
	Sint8 stat;
	Sint8 maxnch;
	Sint8 nch;
	PSMSLT slt[2];
	SJ sji[2];
	SJ sjtp[2];
	Sint32 tp[2];
	PSMTBF ptbf[2];
	Sint8 *buf[2];
	Sint32 sfreq;
	Sint32 vol[2];
	Sint32 pan[2];
	Sint32 core_no;
} PSM_OBJ;
typedef PSM_OBJ *PSM;

typedef enum 
{
	IOPRNA_STAT_STOP = 0,
	IOPRNA_STAT_WAIT = 1,
	IOPRNA_STAT_EXEC = 2
} IOPRNA_STAT;

typedef enum 
{
	IOPRNA_DTXFNO_CREATE = 8,
	IOPRNA_DTXFNO_DESTROY = 9,
	IOPRNA_DTXFNO_REINIT = 10
} IOPRNA_DTXFNO;

typedef enum
{
	IOPRNA_CMD_START = 0,
	IOPRNA_CMD_STOP = 1,
	IOPRNA_CMD_SETPSW = 2,
	IOPRNA_CMD_SETNCH = 3,
	IOPRNA_CMD_SETSFREQ = 4,
	IOPRNA_CMD_SETVOL = 5,
	IOPRNA_CMD_SETMIX = 7,
	IOPRNA_CMD_SETTHRU = 8,
	IOPRNA_CMD_SETPAN = 9
} IOPRNA_CMDNO;
typedef IOPRNA_CMDNO PS2RNA_CMDNO;

typedef struct ioprna_obj 
{ 
	Sint8 used;
	Sint8 thru_flag;
	Sint16 rsv2;
	Sint32 nch;
	SJ sj[2];
	PSM psm;
} IOPRNA_OBJ;
typedef IOPRNA_OBJ *IOPRNA;

typedef struct 
{
	Sint16 no;
	Sint16 rsv;
	IOPRNA rna;
	Sint32 arg1;
	Sint32 arg2;
} IOPRNA_DTXCMD;
typedef IOPRNA_DTXCMD PS2RNA_DTXCMD;

typedef struct 
{ 
	Sint32 ncmd;
	Sint32 rsv;
	Sint32 rsv2;
	Sint32 rsv3;
	IOPRNA_DTXCMD cmd[128];
} IOPRNA_DTXFMT;
typedef IOPRNA_DTXFMT PS2RNA_DTXFMT;

typedef enum
{
	PS2RNA_STAT_STOP = 0,
	PS2RNA_STAT_WAIT = 1,
	PS2RNA_STAT_EXEC = 2
} PS2RNA_STAT;

typedef enum 
{
	PS2RNA_DTXFNO_CREATE = 8,
	PS2RNA_DTXFNO_DESTROY = 9,
	PS2RNA_DTXFNO_REINIT = 10
} PS2RNA_DTXFNO;

typedef struct _ps2psj_obj
{ 
	Sint8 used;
	Sint8 rsv;
	Sint16 rsv2;
	SJ sjiop;
	SJ sjtmp;
	SJX sjx;
	SJCK ck;
} PS2PSJ_OBJ;
typedef PS2PSJ_OBJ *PS2PSJ;

typedef struct ps2rna_obj 
{
	Sint8 used;
	Sint8 rsv;
	Sint16 rsv2;
	Sint32 maxnch;
	PS2PSJ psj[2];
	DTR dtr[2];
	SJ sjo[2];
	IOPRNA ioprna;
	Sint8 ee_plysw;
	Sint8 iop_plysw;
	Sint8 ee_nch;
	Sint8 iop_nch;
	Sint32 ee_sfreq;
	Sint32 iop_sfreq;
	Sint32 ee_vol;
	Sint32 iop_vol;
	Sint32 ee_pan[2];
	Sint32 iop_pan[2];
	Sint8 trnsw;
	Sint8 dtrstop_flg;
	Sint8 iop_thru;
	Sint8 ee_thru;
	Sint32 flsh_size;
	Sint32 obuf_size;
} PS2RNA_OBJ;
typedef PS2RNA_OBJ *PS2RNA;

void PS2RNA_ClearBuf(PS2RNA rna);
void PS2RNA_ClearOverflow(PS2RNA rna);
PS2RNA PS2RNA_Create(SJ *sj, Sint32 maxnch);
void PS2RNA_Destroy(PS2RNA ps2rna);
Sint32 PS2RNA_DiscardData(PS2RNA rna, Sint32 nsmpl);
void PS2RNA_ExecHndl(PS2RNA rna);
void PS2RNA_ExecServer(void);
void PS2RNA_Finish(void);
void ps2rna_finish_psj(void);
void PS2RNA_Flush(PS2RNA rna);
PS2PSJ ps2rna_get_psj(void);
Sint32 PS2RNA_GetBitPerSmpl(PS2RNA rna);
Sint32 PS2RNA_GetNumData(PS2RNA rna);
Sint32 PS2RNA_GetNumRoom(PS2RNA rna);
Sint32 PS2RNA_GetOutPan(PS2RNA rna, Sint32 chno);
Sint32 PS2RNA_GetOutVol(PS2RNA rna);
Sint32 PS2RNA_GetSfreq(PS2RNA rna);
SJ PS2RNA_GetSjiop(PS2RNA rna, Sint32 chno);
SJ PS2RNA_GetSjtmp(PS2RNA rna, Sint32 chno);
Sint32 PS2RNA_GetStartSmpl(PS2RNA rna);
void PS2RNA_GetTime(PS2RNA rna, Sint32 *ncount, Sint32 *tscale);
void PS2RNA_Init(void);
void ps2rna_init_psj(void);
Sint32 PS2RNA_IsOverflow(PS2RNA rna);
Sint32 PS2RNA_IsPlySwOff(PS2RNA rna);
void ps2rna_rcvcbf(void *obj, void *dt, Sint32 dtlen);
void ps2rna_release_psj(PS2PSJ psj);
void PS2RNA_SetBitPerSmpl(PS2RNA rna, Sint32 bps);
void PS2RNA_SetNumChan(PS2RNA rna, Sint32 nch);
void PS2RNA_SetOutPan(PS2RNA rna, Sint32 chno, Sint32 pan);
void PS2RNA_SetOutVol(PS2RNA rna, Sint32 vol);
void PS2RNA_SetPcmType(PS2RNA rna, Sint32 type);
void PS2RNA_SetPlaySw(PS2RNA rna, Sint32 sw);
void PS2RNA_SetSfreq(PS2RNA rna, Sint32 sfreq);
void PS2RNA_SetStartSmpl(PS2RNA rna, Sint32 nsmpl);
Sint32 PS2RNA_SetStmHdInfo(PS2RNA rna, void *snddat);
void PS2RNA_SetTotalNumSmpl(PS2RNA rna, Sint32 nsmpl);
void PS2RNA_SetTransSw(PS2RNA rna, Sint32 sw);
void ps2rna_sndcbf(void *obj, void *dt, Sint32 dtlen);
void PS2RNA_Start(PS2RNA rna);
void PS2RNA_Stop(PS2RNA rna);

#endif
