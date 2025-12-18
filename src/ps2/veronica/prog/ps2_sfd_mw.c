#include "ps2_sfd_mw.h"
#include "ps2_MovieFunc.h"
#include "ps2_NaSystem.h"
#include "main.h"

#include <string.h>

MW_PLY_OBJ MwObj;
StrFile infile;
MWPLY MwHandle = &MwObj;
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

// 100% matching!
void mwPlyExecServer(void)
{
    movie_draw = 0;

    do 
    {
        readMpeg();
    } while ((movie_draw == 0) && (rmi.iMovieState != 3));
    
    sceGsSyncPath(0, 0);
    
    setImageTag((unsigned int*)test_tag, voBuf.data);
    
    vbrank_draw();
    
    voBuf.count--;
}

// 100% matching!
void mwPlyFinishSofdec(void)
{

}

// 100% matching!
Sint32 mwPlyGetBright(MWPLY mwply)
{

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

// 100% matching!
void ps2mwPlyGetTime(MWPLY mwply, Sint32 *ncount, Sint32 *tscale)
{
    *ncount = Ps2_vcount - rmi.iMovieFrame;
    
    *tscale = 29;
}

// 100% matching!
void ps2mwPlyPause(MWPLY mwply, Sint32 sw)
{
    if (sw != 0) 
    {
        rmi.uiContFlag |= 0x2;
    }
    else 
    {
        rmi.uiContFlag &= ~0x2;
    }
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

// 100% matching!
Sint32 ps2mwPlyGetOutVol(MWPLY mwply)
{

}

// 100% matching!
void ps2mwErrorStop()
{
    printf("-\nMW Error Stop...\nThis function is no supported...\n");
}

// 100% matching!
void Setps2FuncTbl(MWPLY mwply) {
    mwply->vtbl = &Ps2Func;
}
