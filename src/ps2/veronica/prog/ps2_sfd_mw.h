#ifndef _PS2_SFD_MW_H_
#define _PS2_SFD_MW_H_

#include "types.h"

MWPLY ps2mwPlyCreateSofdec(MWS_PLY_CPRM_SFD* cprm, char* fname);

/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _UUID;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _sj_vtbl;
typedef enum _mwe_ply_stat;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _mwply_if;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;

typedef void(*type_0)(_anon0*, int*, int*);
typedef void(*type_1)(_anon0*, int);
typedef void(*type_2)(_anon0*, int);
typedef int(*type_3)(_anon0*);
typedef void(*type_4)(_anon0*, int, int);
typedef int(*type_5)(_anon0*, int);
typedef void(*type_7)(_anon0*, _anon3*);
typedef void(*type_9)(_anon0*, void*, int);
typedef void(*type_11)();
typedef void(*type_12)();
typedef void(*type_13)();
typedef void(*type_14)(_anon3*);
typedef _UUID*(*type_15)(_anon3*);
typedef void(*type_17)(_anon3*);
typedef void(*type_19)(_anon3*, int, int, _anon4*);
typedef void(*type_21)(_anon3*, int, _anon4*);
typedef void(*type_22)();
typedef void(*type_23)();
typedef void(*type_24)();
typedef void(*type_25)(_anon3*, int, _anon4*);
typedef void(*type_26)(_anon0*);
typedef void(*type_27)(_anon0*);
typedef int(*type_29)(_anon3*, int);
typedef void(*type_30)(_anon0*);
typedef int(*type_31)(_anon3*, int, int, int*);
typedef void(*type_32)(_anon0*, char*);
typedef void(*type_33)(_anon0*);
typedef void(*type_34)(_anon3*, void(*)(void*, int), void*);
typedef void(*type_35)(void*, int);
typedef _mwe_ply_stat(*type_36)(_anon0*);

typedef char type_6[256];
typedef unsigned char type_8[8];
typedef unsigned char type_10[32];
typedef unsigned char type_16[450560];
typedef int type_18[15];
typedef <unknown fundamental type (0xa510)> type_20[1400];
typedef int type_28[4];
typedef char type_37[16];
typedef unsigned char type_38[8];
typedef char type_39[256];

struct _anon0
{
	_mwply_if* vtbl;
};

struct _anon1
{
	int isOnCD;
	int size;
	_anon11 fp;
	unsigned char* iopBuf;
	int fd;
};

struct _UUID
{
	unsigned int Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
};

struct _anon2
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

struct _anon3
{
	_sj_vtbl* vtbl;
};

struct _anon4
{
	char* data;
	int len;
};

struct _sj_vtbl
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*Destroy)(_anon3*);
	_UUID*(*GetUuid)(_anon3*);
	void(*Reset)(_anon3*);
	void(*GetChunk)(_anon3*, int, int, _anon4*);
	void(*UngetChunk)(_anon3*, int, _anon4*);
	void(*PutChunk)(_anon3*, int, _anon4*);
	int(*GetNumData)(_anon3*, int);
	int(*IsGetChunk)(_anon3*, int, int, int*);
	void(*EntryErrFunc)(_anon3*, void(*)(void*, int), void*);
};

enum _mwe_ply_stat
{
	MWE_PLY_STAT_STOP,
	MWE_PLY_STAT_PREP,
	MWE_PLY_STAT_PLAYING,
	MWE_PLY_STAT_PLAYEND,
	MWE_PLY_STAT_ERROR
};

struct _anon5
{
	short sWidth;
	short sHeight;
	short sDispX;
	short sDispY;
};

struct _anon6
{
	unsigned char v[450560];
};

struct _mwply_if
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*VsyncHndl)(_anon0*);
	void(*ExecSvrHndl)(_anon0*);
	void(*Destroy)(_anon0*);
	void(*StartFname)(_anon0*, char*);
	void(*Stop)(_anon0*);
	_mwe_ply_stat(*GetStat)(_anon0*);
	void(*GetTime)(_anon0*, int*, int*);
	void(*Pause)(_anon0*, int);
	void(*SetOutVol)(_anon0*, int);
	int(*GetOutVol)(_anon0*);
	void(*SetOutPan)(_anon0*, int, int);
	int(*GetOutPan)(_anon0*, int);
	void(*StartSj)(_anon0*, _anon3*);
	void(*StartMem)(_anon0*, void*, int);
};

struct _anon7
{
	int status;
	int dummy[15];
};

struct _anon8
{
	_anon6* data;
	_anon7* tag;
	int write;
	int count;
	int size;
};

struct _anon9
{
	unsigned char trycount;
	unsigned char spindlctrl;
	unsigned char datapattern;
	unsigned char pad;
};

struct _anon10
{
	int mode;
	int frame;
	int count;
	int latency;
	int rsv[4];
};

struct _anon11
{
	unsigned int lsn;
	unsigned int size;
	char name[16];
	unsigned char date[8];
};*/

#endif
