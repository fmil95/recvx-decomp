#ifndef _MWWRAP_H_
#define _MWWRAP_H_

/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _UUID;
typedef struct _sj_vtbl;
typedef enum _mwe_ply_stat;
typedef struct _mwply_if;

typedef void(*type_0)(_anon1*, int, int, _anon0*);
typedef void(*type_1)();
typedef void(*type_2)(_anon1*, int, _anon0*);
typedef void(*type_3)();
typedef void(*type_4)();
typedef void(*type_5)(_anon2*);
typedef void(*type_6)(_anon1*, int, _anon0*);
typedef void(*type_7)(_anon2*);
typedef int(*type_9)(_anon1*, int);
typedef void(*type_10)(_anon2*);
typedef void(*type_11)(_anon2*, char*);
typedef int(*type_12)(_anon1*, int, int, int*);
typedef void(*type_13)(_anon2*);
typedef void(*type_14)(_anon1*, void(*)(void*, int), void*);
typedef _mwe_ply_stat(*type_15)(_anon2*);
typedef void(*type_16)(void*, int);
typedef void(*type_17)(_anon2*, int*, int*);
typedef void(*type_18)(_anon2*, int);
typedef void(*type_19)(_anon2*, int);
typedef int(*type_20)(_anon2*);
typedef void(*type_21)(_anon2*, int, int);
typedef int(*type_22)(_anon2*, int);
typedef void(*type_23)(_anon2*, _anon1*);
typedef void(*type_25)(_anon2*, void*, int);
typedef void(*type_26)();
typedef void(*type_27)();
typedef void(*type_28)();
typedef void(*type_29)(_anon1*);
typedef _UUID*(*type_30)(_anon1*);
typedef void(*type_31)(_anon1*);
typedef void(*type_32)();

typedef int type_8[4];
typedef unsigned char type_24[8];

struct _anon0
{
	char* data;
	int len;
};

struct _anon1
{
	_sj_vtbl* vtbl;
};

struct _anon2
{
	_mwply_if* vtbl;
};

struct _anon3
{
	int mode;
	int frame;
	int count;
	int latency;
	int rsv[4];
};

struct _anon4
{
	int ftype;
	int max_bps;
	int max_width;
	int max_height;
	int nfrm_pool_wk;
	char* work;
	int wksize;
	int dtype;
};

struct _UUID
{
	unsigned int Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
};

struct _sj_vtbl
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*Destroy)(_anon1*);
	_UUID*(*GetUuid)(_anon1*);
	void(*Reset)(_anon1*);
	void(*GetChunk)(_anon1*, int, int, _anon0*);
	void(*UngetChunk)(_anon1*, int, _anon0*);
	void(*PutChunk)(_anon1*, int, _anon0*);
	int(*GetNumData)(_anon1*, int);
	int(*IsGetChunk)(_anon1*, int, int, int*);
	void(*EntryErrFunc)(_anon1*, void(*)(void*, int), void*);
};

enum _mwe_ply_stat
{
	MWE_PLY_STAT_STOP,
	MWE_PLY_STAT_PREP,
	MWE_PLY_STAT_PLAYING,
	MWE_PLY_STAT_PLAYEND,
	MWE_PLY_STAT_ERROR
};

struct _mwply_if
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*VsyncHndl)(_anon2*);
	void(*ExecSvrHndl)(_anon2*);
	void(*Destroy)(_anon2*);
	void(*StartFname)(_anon2*, char*);
	void(*Stop)(_anon2*);
	_mwe_ply_stat(*GetStat)(_anon2*);
	void(*GetTime)(_anon2*, int*, int*);
	void(*Pause)(_anon2*, int);
	void(*SetOutVol)(_anon2*, int);
	int(*GetOutVol)(_anon2*);
	void(*SetOutPan)(_anon2*, int, int);
	int(*GetOutPan)(_anon2*, int);
	void(*StartSj)(_anon2*, _anon1*);
	void(*StartMem)(_anon2*, void*, int);
};*/

#endif
