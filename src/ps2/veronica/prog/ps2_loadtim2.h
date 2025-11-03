#ifndef _PS2_LOADTIM2_H_
#define _PS2_LOADTIM2_H_

#include "types.h"

/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct tagTIM2_FILEHEADER;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;


typedef unsigned long type_0[64];
typedef unsigned long type_1[64];
typedef unsigned int type_2[4];
typedef int type_3[3];
typedef char type_4[4];
typedef unsigned long type_5[64];
typedef char type_6[8];
typedef int type_7[5];
typedef int type_8[3];
typedef unsigned int type_9[2];
typedef unsigned int type_10[2];
typedef unsigned long type_11[64];
typedef int type_12[3];
typedef unsigned long type_13[64];
typedef unsigned char type_14[1024];

struct _anon0
{
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned int GsTex0[2];
	unsigned int GsTex1[2];
	unsigned int GsRegs;
	unsigned int GsTexClut;
};

struct _anon1
{
	_anon8 giftag0;
	_anon3 bitbltbuf;
	long bitbltbufaddr;
	_anon6 trxpos;
	long trxposaddr;
	_anon7 trxreg;
	long trxregaddr;
	_anon4 trxdir;
	long trxdiraddr;
	_anon8 giftag1;
};

struct _anon2
{
	unsigned long pad00;
};

struct _anon3
{
	struct
	{
		unsigned long SBP : 14;
		unsigned long pad14 : 2;
		unsigned long SBW : 6;
		unsigned long pad22 : 2;
		unsigned long SPSM : 6;
		unsigned long pad30 : 2;
		unsigned long DBP : 14;
		unsigned long pad46 : 2;
		unsigned long DBW : 6;
		unsigned long pad54 : 2;
		unsigned long DPSM : 6;
		unsigned long pad62 : 2;
	};
};

struct _anon4
{
	struct
	{
		unsigned long XDR : 2;
		unsigned long pad02 : 62;
	};
};

struct _anon5
{
	unsigned int vifcode[4];
	_anon8 giftag;
	_anon3 bitbltbuf;
	long bitbltbufaddr;
	_anon6 trxpos;
	long trxposaddr;
	_anon7 trxreg;
	long trxregaddr;
	_anon2 finish;
	long finishaddr;
	_anon4 trxdir;
	long trxdiraddr;
};

struct tagTIM2_FILEHEADER
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	char Reserved[8];
};

struct _anon6
{
	struct
	{
		unsigned long SSAX : 11;
		unsigned long pad11 : 5;
		unsigned long SSAY : 11;
		unsigned long pad27 : 5;
		unsigned long DSAX : 11;
		unsigned long pad43 : 5;
		unsigned long DSAY : 11;
		unsigned long DIR : 2;
		unsigned long pad61 : 3;
	};
};

struct _anon7
{
	struct
	{
		unsigned long RRW : 12;
		unsigned long pad12 : 20;
		unsigned long RRH : 12;
		unsigned long pad44 : 20;
	};
};

struct _anon8
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
};*/

// 100% matching!
void *UncAddr(void *val)
{
    return (void*)(((u_int)val & UNCMASK)|UNCBASE);
}

#endif
