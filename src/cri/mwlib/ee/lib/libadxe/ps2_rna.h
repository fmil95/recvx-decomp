#ifndef _PS2_RNA_H_
#define _PS2_RNA_H_

#include "dtr.h"
#include "sjx.h"

typedef struct _ps2_psj 
{
    Sint8  used;
    Sint8  unk1;  /* unused */ 
    Sint8  unk2;  /* unused */ 
    Sint8  unk3;  /* unused */ 
    void*  sjiop;
    SJ     sjtmp;
    SJX    sjx; 
    SJCK   ck;
} PS2PSJ_OBJ;

typedef PS2PSJ_OBJ *PS2PSJ; 

typedef struct _ps2_rna 
{
    Sint8   used;
    Sint8   unk1;      /* unused */
    Sint8   unk2;      /* unused */
    Sint8   unk3;      /* unused */
    Sint32  maxnch;
    PS2PSJ  psj[2];
    DTR     dtr[2];
    SJ      sjo[2];
    void*   urpc;
    Sint8   playsw;
    Sint8   playsw2;
    Sint8   nch;
    Sint8   nch2;
    Sint32  sfreq;
    Sint32  sfreq2;
    Sint32  vol;
    Sint32  vol2;
    Sint32  pan[2];
    Sint32  pan2[2];
    Sint8   trnsw;
    Sint8   dtrstop_flg;
    Sint8   unk4A;     /* unused */
    Sint8   unk4B;     /* unused */
    Sint32  unk4C;     // roomno?
    Sint32  datano;
} PS2RNA_OBJ;

typedef PS2RNA_OBJ *PS2RNA;

typedef struct _ps2rna_work
{
    Sint16  id; 
    Sint16  unk2; /* unused */ 
    void*   urpc;
    Sint32  unk8;
    Sint32  db;
} PS2RNA_WORK_OBJ;

typedef PS2RNA_WORK_OBJ *PS2RNA_WORK;

typedef struct _ps2rna_buf
{
    Sint32           size;
    Sint32           unk4;  /* unused */
    Sint32           unk8;  /* unused */
    Sint32           unkC;  /* unused */
    PS2RNA_WORK_OBJ  wk[0];
} PS2RNA_BUF_OBJ;

typedef PS2RNA_BUF_OBJ *PS2RNA_RCVCBF; 
typedef PS2RNA_BUF_OBJ *PS2RNA_SNDCBF; 

void PS2RNA_ClearBuf(PS2RNA ps2rna);
void PS2RNA_ClearOverflow(PS2RNA ps2rna);
PS2RNA PS2RNA_Create(SJ* sjo, Sint32 maxnch);
void PS2RNA_Destroy(PS2RNA ps2rna);
Sint32 PS2RNA_DiscardData(PS2RNA rna, Sint32 nsmpl);
void PS2RNA_ExecHndl(PS2RNA ps2rna);
void PS2RNA_ExecServer(void);
void PS2RNA_Finish(void);
void ps2rna_finish_psj(void);
void PS2RNA_Flush(void);
PS2PSJ ps2rna_get_psj(void);
Sint32 PS2RNA_GetBitPerSmpl(PS2RNA ps2rna);
Sint32 PS2RNA_GetNumData(PS2RNA ps2rna);
Sint32 PS2RNA_GetNumRoom(PS2RNA ps2rna);
Sint32 PS2RNA_GetOutPan(PS2RNA ps2rna, Sint32 ch);
Sint32 PS2RNA_GetOutVol(PS2RNA ps2rna);
Sint32 PS2RNA_GetSfreq(PS2RNA ps2rna);
void* PS2RNA_GetSjiop(PS2RNA ps2rna, Sint32 ch);
void* PS2RNA_GetSjtmp(PS2RNA ps2rna, Sint32 ch);
Sint32 PS2RNA_GetStartSmpl(PS2RNA ps2rna);
void PS2RNA_GetTime(PS2RNA ps2rna, Sint32 *ncount, Sint32 *tscale);
void PS2RNA_Init(void);
void ps2rna_init_psj(void);
void PS2RNA_IsOverflow(PS2RNA ps2rna);
Sint32 PS2RNA_IsPlySwOff(PS2RNA ps2rna);
void ps2rna_rcvcbf(void* unused, PS2RNA_RCVCBF buf);
void ps2rna_release_psj(PS2PSJ ps2psj);
void PS2RNA_SetBitPerSmpl(PS2RNA ps2rna, Sint32 bps);
void PS2RNA_SetNumChan(PS2RNA ps2rna, Sint32 nch);
void PS2RNA_SetOutPan(PS2RNA ps2rna, Sint32 ch, Sint32 pan);
void PS2RNA_SetOutVol(PS2RNA ps2rna, Sint32 vol);
void PS2RNA_SetPcmType(PS2RNA ps2rna, Sint32 type);
void PS2RNA_SetPlaySw(PS2RNA ps2rna, Sint32 sw);
void PS2RNA_SetSfreq(PS2RNA ps2rna, Sint32 sfreq);
void PS2RNA_SetStartSmpl(PS2RNA ps2rna, Sint32 smpl);
void PS2RNA_SetStmHdInfo(PS2RNA ps2rna, void* hinfo);
void PS2RNA_SetTotalNumSmpl(PS2RNA ps2rna, Sint32 nsmpl);
void PS2RNA_SetTransSw(PS2RNA ps2rna, Sint32 sw);
void ps2rna_sndcbf(void* unused, PS2RNA_SNDCBF buf);
void PS2RNA_Start(PS2RNA ps2rna);
void PS2RNA_Stop(PS2RNA ps2rna);

#endif
