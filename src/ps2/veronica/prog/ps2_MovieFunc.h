#ifndef _PS2_MOVIEFUNC_H_
#define _PS2_MOVIEFUNC_H_

#include "types.h"
#include "macros.h"

/* audiodec.h - move these to types.h */

typedef struct {
    char id[4];		// 'S''S''h''d'
    int size;		// 24
    int type;		// 0: 16bit big endian
    			// 1: 16bit little endian
			// 2: SPU2-ADPCM (VAG) 
    int rate;		// sampling rate
    int ch;		// number of channels
    int interSize;	// interleave size ... needs to be 512
    int loopStart;	// loop start block address
    int loopEnd;	// loop end block sddress
} SpuStreamHeader;

typedef struct {
    char id[4];		// 'S''S''b''d'
    int size;		// size of audio data
} SpuStreamBody;

typedef struct {

    int state;

    // header of ADS format
    SpuStreamHeader sshd;
    SpuStreamBody   ssbd;
    int hdrCount;

    // audio buffer
    u_char *data;
    int put;
    int count;
    int size;
    int totalBytes;

    // buffer on IOP
    int iopBuff;
    int iopBuffSize;
    int iopLastPos;
    int iopPausePos;
    int totalBytesSent;
    int iopZero;

} AudioDec;

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

// 0% matching
static inline void *DmaAddr(void *val)
{
    return (void*)((u_int)val & UNCMASK);
}

#endif
