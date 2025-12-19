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
/*int copy2area(unsigned char* pd0, int d0, unsigned char* pd1, int d1, unsigned char* ps0, int s0, unsigned char* ps1, int s1);*/
int audioDecSendToIOP(AudioDec *ad);
static void iopGetArea(int *pd0, int *d0, int *pd1, int *d1, AudioDec *ad, int pos);
/*int sendToIOP2area(int pd0, int d0, int pd1, int d1, unsigned char* ps0, int s0, unsigned char* ps1, int s1);*/
int sendToIOP(int dst, u_char *src, int size);
void changeInputVolume(u_int val);
/*void setD3_CHCR(unsigned int val);*/
void setD4_CHCR(u_int val);
void scTag2(QWORD *q, void *addr, u_int id, u_int qwc);
int viBufReset(ViBuf *f);
/*void viBufBeginPut(_anon7* f, unsigned char** ptr0, int* len0, unsigned char** ptr1, int* len1);
void viBufEndPut(_anon7* f, int size);
int viBufModifyPts(_anon7* f, _anon8* new_ts);*/
int IsPtsInRegion(int tgt, int pos, int len, int size);
/*int viBufPutTs(_anon7* f, _anon8* ts);*/
void voBufIncCount(VoBuf *f);
void audioDecResume(AudioDec *ad);
/*int getFIFOindex(_anon7* f, void* addr);
int videoDecPutTs(_anon17* vd, long pts_val, long dts_val, unsigned char* start, int len);
void audioDecBeginPut(_anon12* ad, unsigned char** ptr0, int* len0, unsigned char** ptr1, int* len1);*/
void termAll();
int viBufDelete(ViBuf *f);
/*int videoDecDelete(_anon17* vd);
int audioDecDelete();*/
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

/*typedef struct _anon0;
typedef struct _anon1;
typedef union _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef union _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct ThreadParam;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct SemaParam;
typedef enum _enum;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;

typedef int(*type_0)(_anon0*, _anon2*, void*);
typedef int(*type_3)(_anon0*, _anon5*, void*);
typedef int(*type_15)(_anon0*, _anon11*, void*);
typedef int(*type_18)(_anon0*, _anon11*, void*);
typedef void(*type_20)(_anon17*);
typedef int(*type_21)(_anon0*, _anon1*, void*);
typedef int(*type_23)(_anon0*, _anon2*, void*);
typedef int(*type_26)(_anon0*, _anon2*, void*);

typedef unsigned char type_1[450560];
typedef int type_2[15];
typedef unsigned long type_4[2];
typedef unsigned long type_5[2];
typedef char type_6[4];
typedef char type_7[4];
typedef unsigned long type_8[2];
typedef unsigned int type_9[4];
typedef unsigned short type_10[8];
typedef unsigned char type_11[16];
typedef _anon36 type_12[2];
typedef <unknown fundamental type (0xa510)> type_13[1400];
typedef unsigned char type_14[4];
typedef char type_16[0];
typedef unsigned char type_17[16384];
typedef <unknown fundamental type (0xa510)> type_19[64];
typedef unsigned char type_22[32];
typedef char type_24[16];
typedef unsigned char type_25[8];

struct _anon0
{
	int width;
	int height;
	int frameCount;
	long pts;
	long dts;
	unsigned long flags;
	long pts2nd;
	long dts2nd;
	unsigned long flags2nd;
	void* sys;
};

struct _anon1
{
	_enum type;
	char* errMessage;
};

union _anon2
{
	_enum type;
	_anon1 error;
	_anon5 ts;
	_anon11 str;
};

struct _anon3
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int A : 8;
	};
	float Q;
};

struct _anon4
{
	struct
	{
		unsigned long DTHE : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon5
{
	_enum type;
	long pts;
	long dts;
};

struct _anon6
{
	unsigned char v[450560];
};

struct _anon7
{
	<unknown fundamental type (0xa510)>* data;
	<unknown fundamental type (0xa510)>* tag;
	int n;
	int dmaStart;
	int dmaN;
	int readBytes;
	int buffSize;
	_anon38 env;
	int sema;
	int isActive;
	long totalBytes;
	_anon8* ts;
	int n_ts;
	int count_ts;
	int wt_ts;
};

struct _anon8
{
	long pts;
	long dts;
	int pos;
	int len;
};

struct _anon9
{
	int status;
	int dummy[15];
};

struct _anon10
{
	struct
	{
		unsigned int DX : 12;
		unsigned int DY : 11;
		unsigned int MAGH : 4;
		unsigned int MAGV : 2;
		unsigned int p0 : 3;
	};
	struct
	{
		unsigned int DW : 12;
		unsigned int DH : 11;
		unsigned int p1 : 9;
	};
};

struct _anon11
{
	_enum type;
	unsigned char* header;
	unsigned char* data;
	unsigned int len;
	long pts;
	long dts;
};

struct _anon12
{
	int state;
	_anon19 sshd;
	_anon21 ssbd;
	int hdrCount;
	unsigned char* data;
	int put;
	int count;
	int size;
	int totalBytes;
	int iopBuff;
	int iopBuffSize;
	int iopLastPos;
	int iopPausePos;
	int totalBytesSent;
	int iopZero;
};

struct _anon13
{
	_anon6* data;
	_anon9* tag;
	int write;
	int count;
	int size;
};

struct _anon14
{
	struct
	{
		unsigned long SCAX0 : 11;
		unsigned long pad11 : 5;
		unsigned long SCAX1 : 11;
		unsigned long pad27 : 5;
		unsigned long SCAY0 : 11;
		unsigned long pad43 : 5;
		unsigned long SCAY1 : 11;
		unsigned long pad59 : 5;
	};
};

struct _anon15
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int p0 : 8;
	};
	unsigned int p1;
};

struct _anon16
{
	unsigned char data[16384];
	_anon28 Ipu_header;
	int status;
	int put;
	int count;
	int size;
};

struct _anon17
{
	_anon0 mpeg;
	_anon7 vibuf;
	unsigned int state;
	int sema;
	int hid_vblank;
};

struct _anon18
{
	struct
	{
		unsigned long FBP : 9;
		unsigned long pad09 : 7;
		unsigned long FBW : 6;
		unsigned long pad22 : 2;
		unsigned long PSM : 6;
		unsigned long pad30 : 2;
		unsigned long FBMSK : 32;
	};
};

struct _anon19
{
	char id[4];
	int size;
	int type;
	int rate;
	int ch;
	int interSize;
	int loopStart;
	int loopEnd;
};

struct _anon20
{
	_anon23 testa;
	long testaaddr;
	_anon32 prim;
	long primaddr;
	_anon3 rgbaq;
	long rgbaqaddr;
	_anon29 xyz2a;
	long xyz2aaddr;
	_anon29 xyz2b;
	long xyz2baddr;
	_anon23 testb;
	long testbaddr;
};

struct _anon21
{
	char id[4];
	int size;
};

union _anon22
{
	<unknown fundamental type (0xa510)> q;
	unsigned long l[2];
	unsigned int i[4];
	unsigned short s[8];
	unsigned char c[16];
};

struct _anon23
{
	struct
	{
		unsigned long ATE : 1;
		unsigned long ATST : 3;
		unsigned long AREF : 8;
		unsigned long AFAIL : 2;
		unsigned long DATE : 1;
		unsigned long DATM : 1;
		unsigned long ZTE : 1;
		unsigned long ZTST : 2;
		unsigned long pad19 : 45;
	};
};

struct _anon24
{
	_anon36 disp[2];
	_anon27 giftag0;
	_anon39 draw0;
	_anon20 clear0;
	_anon27 giftag1;
	_anon39 draw1;
	_anon20 clear1;
};

struct _anon25
{
	struct
	{
		unsigned long CLAMP : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon26
{
	struct
	{
		unsigned long OFX : 16;
		unsigned long pad16 : 16;
		unsigned long OFY : 16;
		unsigned long pad48 : 16;
	};
};

struct _anon27
{
	struct
	{
		unsigned long NLOOP : 15;
		unsigned long EOP : 1;
		unsigned long pad16 : 16;
		unsigned long id : 14;
		unsigned long PRE : 1;
		unsigned long PRIM : 11;
		unsigned long FLG : 2;
		unsigned long NREG : 4;
	};
	struct
	{
		unsigned long REGS0 : 4;
		unsigned long REGS1 : 4;
		unsigned long REGS2 : 4;
		unsigned long REGS3 : 4;
		unsigned long REGS4 : 4;
		unsigned long REGS5 : 4;
		unsigned long REGS6 : 4;
		unsigned long REGS7 : 4;
		unsigned long REGS8 : 4;
		unsigned long REGS9 : 4;
		unsigned long REGS10 : 4;
		unsigned long REGS11 : 4;
		unsigned long REGS12 : 4;
		unsigned long REGS13 : 4;
		unsigned long REGS14 : 4;
		unsigned long REGS15 : 4;
	};
};

struct _anon28
{
	int Frame_rate;
	int Data_size;
	short Width;
	short Height;
	int Nframe;
};

struct _anon29
{
	struct
	{
		unsigned long X : 16;
		unsigned long Y : 16;
		unsigned long Z : 32;
	};
};

struct ThreadParam
{
	int status;
	void* entry;
	void* stack;
	int stackSize;
	void* gpReg;
	int initPriority;
	int currentPriority;
	unsigned int attr;
	unsigned int option;
	int waitType;
	int waitId;
	int wakeupCount;
};

struct _anon30
{
	int isOnCD;
	int size;
	_anon40 fp;
	unsigned char* iopBuf;
	int fd;
};

struct _anon31
{
	struct
	{
		unsigned long ZBP : 9;
		unsigned long pad09 : 15;
		unsigned long PSM : 4;
		unsigned long pad28 : 4;
		unsigned long ZMSK : 1;
		unsigned long pad33 : 31;
	};
};

struct _anon32
{
	struct
	{
		unsigned long PRIM : 3;
		unsigned long IIP : 1;
		unsigned long TME : 1;
		unsigned long FGE : 1;
		unsigned long ABE : 1;
		unsigned long AA1 : 1;
		unsigned long FST : 1;
		unsigned long CTXT : 1;
		unsigned long FIX : 1;
		unsigned long pad11 : 53;
	};
};

struct _anon33
{
	struct
	{
		unsigned int EN1 : 1;
		unsigned int EN2 : 1;
		unsigned int CRTMD : 3;
		unsigned int MMOD : 1;
		unsigned int AMOD : 1;
		unsigned int SLBG : 1;
		unsigned int ALP : 8;
		unsigned int p0 : 16;
	};
	unsigned int p1;
};

struct _anon34
{
	unsigned int data;
	unsigned int addr;
	unsigned int size;
	unsigned int mode;
};

struct _anon35
{
	unsigned char* put_ptr;
	unsigned char* get_ptr;
	int putsize;
	int getsize;
	int readrest;
	int writerest;
	int count;
	int proceed;
	unsigned int button_old;
	unsigned char cdata[32];
	int iMovieState;
	int iMovieFrame;
	unsigned int uiContFlag;
	unsigned int MVCancelButton;
};

struct _anon36
{
	_anon33 pmode;
	_anon42 smode2;
	_anon37 dispfb;
	_anon10 display;
	_anon15 bgcolor;
};

struct _anon37
{
	struct
	{
		unsigned int FBP : 9;
		unsigned int FBW : 6;
		unsigned int PSM : 5;
		unsigned int p0 : 12;
	};
	struct
	{
		unsigned int DBX : 11;
		unsigned int DBY : 11;
		unsigned int p1 : 10;
	};
};

struct _anon38
{
	unsigned int d4madr;
	unsigned int d4tadr;
	unsigned int d4qwc;
	unsigned int d4chcr;
	unsigned int d3madr;
	unsigned int d3qwc;
	unsigned int d3chcr;
	unsigned int ipubp;
	unsigned int ipuctrl;
};

struct SemaParam
{
	int currentCount;
	int maxCount;
	int initCount;
	int numWaitThreads;
	unsigned int attr;
	unsigned int option;
};

enum _enum
{
	sceMpegCbError,
	sceMpegCbNodata,
	sceMpegCbStopDMA,
	sceMpegCbRestartDMA,
	sceMpegCbBackground,
	sceMpegCbTimeStamp,
	sceMpegCbStr
};

struct _anon39
{
	_anon18 frame1;
	unsigned long frame1addr;
	_anon31 zbuf1;
	long zbuf1addr;
	_anon26 xyoffset1;
	long xyoffset1addr;
	_anon14 scissor1;
	long scissor1addr;
	_anon43 prmodecont;
	long prmodecontaddr;
	_anon25 colclamp;
	long colclampaddr;
	_anon4 dthe;
	long dtheaddr;
	_anon23 test1;
	long test1addr;
};

struct _anon40
{
	unsigned int lsn;
	unsigned int size;
	char name[16];
	unsigned char date[8];
};

struct _anon41
{
	short sWidth;
	short sHeight;
	short sDispX;
	short sDispY;
};

struct _anon42
{
	struct
	{
		unsigned int INT : 1;
		unsigned int FFMD : 1;
		unsigned int DPMS : 2;
		unsigned int p0 : 28;
	};
	unsigned int p1;
};

struct _anon43
{
	struct
	{
		unsigned long AC : 1;
		unsigned long pad01 : 63;
	};
};*/

#endif
