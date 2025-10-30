#ifndef _DTR_H_
#define _DTR_H_

typedef struct _dtr_obj
{
    Sint8          used;
    Sint8          stat; 
    Sint8          trnflg;
    Sint8          unk3;  /* unused */
    SJ             sjo;
    SJ             sji;
    SJCK           ck1;
    SJCK           ck2;
    sceSifDmaData  sdd;
    Sint32         dma_id;
    Sint32         unk30;
    Sint32         unk34; // buf?
    Sint32         unk38; // bufsize?
    Sint32         unk3C; // datano?
} DTR_OBJ;

typedef DTR_OBJ *DTR;

DTR DTR_Create(SJ sjo, SJ sji);
void DTR_Destroy(DTR dtr);
void DTR_ExecHndl(DTR dtr);
void DTR_ExecServer(void);
void DTR_Finish(void);
void DTR_Init(void);
void DTR_Start(DTR dtr);
void DTR_Stop(DTR dtr);

#endif
