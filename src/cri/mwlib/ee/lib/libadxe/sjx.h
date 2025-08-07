#ifndef _SJX_H_
#define _SJX_H_

typedef struct _sjx 
{
    Sint8   used;
    Sint8   unk1;   /* unused */
    Sint16  unk2;
    SJ      sj;
    void*   work;
    Sint32  wksize;
    Sint32  urpc;
} SJX_OBJ;

typedef SJX_OBJ *SJX;

typedef struct _sjx_work
{
    Sint8   unk0;
    Sint8   id;
    Sint16  unk2;
    SJX     sjx;
    SJCK    ck;
} SJX_WORK_OBJ; 

typedef SJX_WORK_OBJ *SJX_WORK;

typedef struct _sjx_buf
{
    Sint32        size;
    Sint32        unk4;  /* unused */
    Sint32        unk8;  /* unused */
    Sint32        unkC;  /* unused */
    SJX_WORK_OBJ  wk[0];
} SJX_BUF_OBJ;

typedef SJX_BUF_OBJ *SJX_RCVCBF;
typedef SJX_BUF_OBJ *SJX_SNDCBF;

SJX SJX_Create(SJ sj, Sint8 *work, Sint32 wksize);
void SJX_Destroy(SJX sjx);
void SJX_ExecServer(void);
void SJX_Finish(void);
void SJX_Init(void);
void sjx_rcvcbf(SJX sjx, SJX_RCVCBF buf, Sint32 bfsize);
void SJX_Reset(SJX sjx);
void sjx_sndcbf(SJX sjx, SJX_SNDCBF buf, Sint32 bfsize);

#endif
