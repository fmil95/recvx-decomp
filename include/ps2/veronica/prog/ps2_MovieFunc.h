#ifndef _PS2_MOVIEFUNC_H_
#define _PS2_MOVIEFUNC_H_

#include "types.h"
#include "macros.h"

typedef struct RMI_WORK
{
    // total size: 0x54
    unsigned char* put_ptr;      // offset 0x0, size 0x4
    unsigned char* get_ptr;      // offset 0x4, size 0x4
    int putsize;                 // offset 0x8, size 0x4
    int getsize;                 // offset 0xC, size 0x4
    int readrest;                // offset 0x10, size 0x4
    int writerest;               // offset 0x14, size 0x4
    int count;                   // offset 0x18, size 0x4
    int proceed;                 // offset 0x1C, size 0x4
    unsigned int button_old;     // offset 0x20, size 0x4
    unsigned char cdata[32];     // offset 0x24, size 0x20
    int iMovieState;             // offset 0x44, size 0x4
    int iMovieFrame;             // offset 0x48, size 0x4
    unsigned int uiContFlag;     // offset 0x4C, size 0x4
    unsigned int MVCancelButton; // offset 0x50, size 0x4
} RMI_WORK;

void initAll();
void readMpeg();
int readBufEndGet(READ_BUF *b, int size);
void setImageTag(unsigned int* tags, void* image);
void vbrank_draw();
void videoDecMain(VideoDec *vd);
int decBs0(VideoDec *vd);
static int copy2area(u_char *pd0, int d0, u_char *pd1, int d1, u_char *ps0, int s0, u_char *ps1, int s1);
int audioDecSendToIOP(AudioDec *ad);
static void iopGetArea(int *pd0, int *d0, int *pd1, int *d1, AudioDec *ad, int pos);
static int sendToIOP2area(int pd0, int d0, int pd1, int d1, u_char *ps0, int s0, u_char *ps1, int s1);
int sendToIOP(int dst, u_char *src, int size);
void changeInputVolume(u_int val);
void setD3_CHCR(u_int val);
void setD4_CHCR(u_int val);
void scTag2(QWORD *q, void *addr, u_int id, u_int qwc);
int viBufReset(ViBuf *f);
void *DmaAddr(void *val);
void viBufBeginPut(ViBuf *f, u_char **ptr0, int *len0, u_char **ptr1, int *len1);
void viBufEndPut(ViBuf *f, int size);
int viBufModifyPts(ViBuf *f, TimeStamp *new_ts);
int IsPtsInRegion(int tgt, int pos, int len, int size);
int viBufPutTs(ViBuf *f, TimeStamp *ts);
void voBufIncCount(VoBuf *f);
void audioDecResume(AudioDec *ad);
int getFIFOindex(ViBuf *f, void *addr);
int videoDecPutTs(VideoDec *vd, long pts_val, long dts_val, u_char *start, int len);
void audioDecBeginPut(AudioDec *ad, u_char **ptr0, int *len0, u_char **ptr1, int *len1);
void termAll();
int viBufDelete(ViBuf *f);
int videoDecDelete(VideoDec *vd);
int audioDecDelete(AudioDec *ad);
int GetAllWorkMemory();
void OutPutCdErrorCode(unsigned int* err);
int videoCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data);
int pcmCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data);
int mpegError(sceMpeg *mp, sceMpegCbDataError *cberror, void *anyData);
int mpegNodata(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData);
int mpegStopDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData);
int mpegRestartDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData);
int mpegTS(sceMpeg *mp, sceMpegCbDataTimeStamp *cbts, void *anyData);

extern RMI_WORK rmi;
extern MDSIZE_WORK mdSize;
extern int movie_draw;
extern StrFile infile;
extern u_long128 test_tag[1400];
extern VoBuf voBuf;

#endif
