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

MW_PLY_OBJ MwObj;
StrFile infile;
int iop_read_buff;
MWPLY MwHandle = &MwObj;
int iRingBufNum;
/*
_anon8 voBuf;
<unknown fundamental type (0xa510)> test_tag[1400];
_anon2 rmi;
int movie_draw;
_anon5 mdSize;
unsigned int Ps2_vcount;
_anon10 __sfd_mw_conf__;
*/

/*
int mwPlyCalcWorkSofdec();
MWPLY ps2mwPlyCreateSofdec(char* fname);
void mwPlyExecServer();
void mwPlyFinishSofdec();
int mwPlyGetBright();
void mwPlyInitSofdec();
void mwPlyPreInitSofdec();
void mwPlySetDispMode();
void mwPlySetDispPos(float lx, float ly);
void mwPlySetFastHalfpel();
void mwPlyStartFrame();
void mwPlySetDispSize(float sx, float sy);
*/
void ps2mwPlyVsyncHndl();
void ps2mwPlyExecSvrHndl();
void ps2mwPlyDestroy();
void ps2mwPlyStartFname(MWPLY mwply, signed char* fname);
void ps2mwPlyStop();
MWE_PLY_STAT ps2mwPlyGetStat();
void ps2mwPlyGetTime(MWPLY mwply, int* ncount, int* tscale);
void ps2mwPlyPause(MWPLY mwply, int sw);
void ps2mwPlySetOutVol(MWPLY mwply, int vol);
int ps2mwPlyGetOutVol();
void ps2mwErrorStop();
void Setps2FuncTbl(MWPLY mwply);

extern MWD_IF Ps2Func = { 
    ps2mwErrorStop, 
    ps2mwErrorStop, 
    ps2mwErrorStop, 
    ps2mwPlyVsyncHndl,  
    ps2mwPlyExecSvrHndl,
    ps2mwPlyDestroy,
    ps2mwPlyStartFname,
    ps2mwPlyStop,
    ps2mwPlyGetStat,
    ps2mwPlyGetTime,
    ps2mwPlyPause,
    ps2mwPlySetOutVol,
    ps2mwPlyGetOutVol,
    ps2mwErrorStop,
};

// 100% matching!
Sint32 mwPlyCalcWorkSofdec(Sint32 ftype, Sint32 max_bps, Sint32 max_sx, Sint32 max_sy, Sint32 nfb){

}

// 100% matching!
MWPLY ps2mwPlyCreateSofdec(MWS_PLY_CPRM_SFD* cprm, char* fname) {
    char read_name[256];
    sceCdRMode mode;
    int i;
    int loop;
    
    sceGsSyncV(0);
    sceGsSyncV(0);

    i = 0;
    while (i < strlen(fname)) {
        
        if (fname[i] >= 'a' && fname[i] <= 'z') {
            fname[i] = fname[i] - 0x20;
        }
        
        i++;
    }
    
    sprintf((char*)read_name, "%s%s;1", "\\MOVIE\\", fname);
    infile.iopBuf = (unsigned char*)iop_read_buff;
    sceCdStInit(iRingBufNum * 16, iRingBufNum, ((unsigned int)infile.iopBuf + 0xF >> 4) * 16);

     while (!sceCdSearchFile(&infile.fp, read_name)){
        printf("Cannot open '%s'(sceCdSearchFile)\n", &read_name);

        while (sceCdPause() == 0) {
            
            loop = 0;
             while (loop < 0x186A0){
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                loop++;
            }
        }

        sceCdSync(0x10);

        loop = 0;
        while (loop < 0x186A0) {
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            loop++;
        }
    }
    
    printf("[%s] is open!\n", read_name);
    mode.trycount = 0;
    mode.spindlctrl = 0;
    mode.datapattern = 0;
    infile.size = infile.fp.size;
    sceCdStStart(infile.fp.lsn, &mode);
    Setps2FuncTbl(MwHandle);
    return MwHandle;
}

// 
// Start address: 0x2d8900
void mwPlyExecServer(void)
{
	// Line 366, Address: 0x2d8900, Func Offset: 0
	// Line 378, Address: 0x2d8908, Func Offset: 0x8
	// Line 383, Address: 0x2d8910, Func Offset: 0x10
	// Line 384, Address: 0x2d8918, Func Offset: 0x18
	// Line 390, Address: 0x2d8940, Func Offset: 0x40
	// Line 394, Address: 0x2d894c, Func Offset: 0x4c
	// Line 395, Address: 0x2d8960, Func Offset: 0x60
	// Line 396, Address: 0x2d8968, Func Offset: 0x68
	// Line 399, Address: 0x2d897c, Func Offset: 0x7c
	// Func End, Address: 0x2d8988, Func Offset: 0x88
	scePrintf("mwPlyExecServer - UNIMPLEMENTED!\n");
}

// 100% matching!
void mwPlyFinishSofdec(void)
{

}

// 
// Start address: 0x2d89a0
Sint32 mwPlyGetBright(MWPLY mwply)
{
	// Line 459, Address: 0x2d89a0, Func Offset: 0
	// Func End, Address: 0x2d89a8, Func Offset: 0x8
	scePrintf("mwPlyGetBright - UNIMPLEMENTED!\n");
}

// 100% matching!
void mwPlyInitSofdec(MWS_PLY_INIT_SFD *iprm)
{

}

// 100% matching!
void mwPlyPreInitSofdec() 
{

}

// 
// Start address: 0x2d89d0
void mwPlySetDispMode()
{
	// Line 602, Address: 0x2d89d0, Func Offset: 0
	// Func End, Address: 0x2d89d8, Func Offset: 0x8
	scePrintf("mwPlySetDispMode - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d89e0
void mwPlySetDispPos(MWPLY mwply, float lx, float ly)
{
	// Line 629, Address: 0x2d89e0, Func Offset: 0
	// Line 630, Address: 0x2d89ec, Func Offset: 0xc
	// Line 631, Address: 0x2d89fc, Func Offset: 0x1c
	// Line 632, Address: 0x2d8a0c, Func Offset: 0x2c
	// Func End, Address: 0x2d8a1c, Func Offset: 0x3c
	scePrintf("mwPlySetDispPos - UNIMPLEMENTED!\n");
}

// 100% matching!
void mwPlySetFastHalfpel(MWPLY mwply, Sint32 sw) {

}

// 
// Start address: 0x2d8a30
void mwPlyStartFrame(void)
{
	// Line 688, Address: 0x2d8a30, Func Offset: 0
	// Func End, Address: 0x2d8a38, Func Offset: 0x8
	scePrintf("mwPlyStartFrame - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8a40
void mwPlySetDispSize(MWPLY mwply, float sx, float sy)
{
	// Line 715, Address: 0x2d8a40, Func Offset: 0
	// Line 716, Address: 0x2d8a4c, Func Offset: 0xc
	// Line 717, Address: 0x2d8a5c, Func Offset: 0x1c
	// Line 718, Address: 0x2d8a6c, Func Offset: 0x2c
	// Func End, Address: 0x2d8a7c, Func Offset: 0x3c
	scePrintf("mwPlySetDispSize - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8a80
void ps2mwPlyVsyncHndl()
{
	// Line 744, Address: 0x2d8a80, Func Offset: 0
	// Func End, Address: 0x2d8a88, Func Offset: 0x8
	scePrintf("ps2mwPlyVsyncHndl - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8a90
void ps2mwPlyExecSvrHndl()
{
	// Line 770, Address: 0x2d8a90, Func Offset: 0
	// Func End, Address: 0x2d8a98, Func Offset: 0x8
	scePrintf("ps2mwPlyExecSvrHndl - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8aa0
void ps2mwPlyDestroy()
{
	// Line 796, Address: 0x2d8aa0, Func Offset: 0
	// Func End, Address: 0x2d8aa8, Func Offset: 0x8
	scePrintf("ps2mwPlyDestroy - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8ab0
void ps2mwPlyStartFname(MWPLY mwply, signed char* fname)
{
	char* src;
	char* dest;
	char nameBuf[256];
	// Line 822, Address: 0x2d8ab0, Func Offset: 0
	// Line 827, Address: 0x2d8abc, Func Offset: 0xc
	// Line 829, Address: 0x2d8ac4, Func Offset: 0x14
	// Line 833, Address: 0x2d8ad4, Func Offset: 0x24
	// Line 834, Address: 0x2d8adc, Func Offset: 0x2c
	// Line 837, Address: 0x2d8af8, Func Offset: 0x48
	// Line 838, Address: 0x2d8b10, Func Offset: 0x60
	// Line 840, Address: 0x2d8b20, Func Offset: 0x70
	// Line 842, Address: 0x2d8b2c, Func Offset: 0x7c
	// Func End, Address: 0x2d8b3c, Func Offset: 0x8c
	scePrintf("ps2mwPlyStartFname - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8b40
void ps2mwPlyStop()
{
	// Line 868, Address: 0x2d8b40, Func Offset: 0
	// Func End, Address: 0x2d8b48, Func Offset: 0x8
	scePrintf("ps2mwPlyStop - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8b50
MWE_PLY_STAT ps2mwPlyGetStat()
{
	// Line 895, Address: 0x2d8b50, Func Offset: 0
	// Line 896, Address: 0x2d8b54, Func Offset: 0x4
	// Func End, Address: 0x2d8b5c, Func Offset: 0xc
	scePrintf("ps2mwPlyGetStat - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8b60
void ps2mwPlyGetTime(MWPLY ply, int* ncount, int* tscale)
{
	// Line 928, Address: 0x2d8b60, Func Offset: 0
	// Line 931, Address: 0x2d8b68, Func Offset: 0x8
	// Line 928, Address: 0x2d8b6c, Func Offset: 0xc
	// Line 932, Address: 0x2d8b7c, Func Offset: 0x1c
	// Func End, Address: 0x2d8b84, Func Offset: 0x24
	scePrintf("ps2mwPlyGetTime - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8b90
void ps2mwPlyPause(MWPLY ply, int sw)
{
	// Line 959, Address: 0x2d8b90, Func Offset: 0
	// Line 960, Address: 0x2d8b98, Func Offset: 0x8
	// Line 962, Address: 0x2d8bb0, Func Offset: 0x20
	// Line 963, Address: 0x2d8bc8, Func Offset: 0x38
	// Func End, Address: 0x2d8bd0, Func Offset: 0x40
	scePrintf("ps2mwPlyPause - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8bd0
void ps2mwPlySetOutVol(MWPLY ply, int vol)
{
	// Line 990, Address: 0x2d8bd0, Func Offset: 0
	// Line 994, Address: 0x2d8bd8, Func Offset: 0x8
	// Line 995, Address: 0x2d8c10, Func Offset: 0x40
	// Func End, Address: 0x2d8c1c, Func Offset: 0x4c
	scePrintf("ps2mwSetOutVol - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8c20
int ps2mwPlyGetOutVol()
{
	// Line 1021, Address: 0x2d8c20, Func Offset: 0
	// Func End, Address: 0x2d8c28, Func Offset: 0x8
	scePrintf("ps2mwGetOutVol - UNIMPLEMENTED!\n");
}

// Start address: 0x2d8c30
void ps2mwErrorStop()
{
	// Line 1028, Address: 0x2d8c30, Func Offset: 0
	// Func End, Address: 0x2d8c3c, Func Offset: 0xc
	scePrintf("ps2mwErrorStop - UNIMPLEMENTED!\n");
}

// 100% matching!
void Setps2FuncTbl(MWPLY mwply) {
    mwply->vtbl = &Ps2Func;
}

