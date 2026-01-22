#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "types.h"
#include "enums.h"
#include "macros.h"

typedef struct RDT_WORK
{
	// total size: 0x80
    float ver;          // offset 0x0, size 0x4
    unsigned int flg;   // offset 0x4, size 0x4
    unsigned int dat0;  // offset 0x8, size 0x4
    unsigned int dat1;  // offset 0xC, size 0x4
    unsigned int hed00; // offset 0x10, size 0x4
    unsigned int hed01; // offset 0x14, size 0x4
    unsigned int hed02; // offset 0x18, size 0x4
    unsigned int hed03; // offset 0x1C, size 0x4
    unsigned int hed04; // offset 0x20, size 0x4
    unsigned int hed05; // offset 0x24, size 0x4
    unsigned int hed06; // offset 0x28, size 0x4
    unsigned int hed07; // offset 0x2C, size 0x4
    unsigned int hed08; // offset 0x30, size 0x4
    unsigned int hed09; // offset 0x34, size 0x4
    unsigned int hed10; // offset 0x38, size 0x4
    unsigned int hed11; // offset 0x3C, size 0x4
    unsigned int hed12; // offset 0x40, size 0x4
    unsigned int hed13; // offset 0x44, size 0x4
    unsigned int hed14; // offset 0x48, size 0x4
    unsigned int hed15; // offset 0x4C, size 0x4
    unsigned int hed16; // offset 0x50, size 0x4
    unsigned int hed17; // offset 0x54, size 0x4
    unsigned int hed18; // offset 0x58, size 0x4
    unsigned int hed19; // offset 0x5C, size 0x4
    char usrname[32];   // offset 0x60, size 0x20
} RDT_WORK;

int bhCalcVtxBuffer();
void bhChangeHWSetting();
void bhInitSystem();
void bhInitRoomChangeSystem();
void bhSysCallInit();
void bhSysCallDiscChange();
void bhSysCallSoundMuseum();
void bhSysCallWarning();
void bhSysCallIpl();
void bhSysCallFirstmovie();
void bhSysCallTitle();
void bhSysCallOpening();
void bhFirstGameStart();
void bhSysCallPad();
void bhSysCallGame();
void bhCheckSubTask();
void bhSysCallEvent();
void bhSysCallMap();
void bhSysCallItemselect();
void bhSysCallDoordemo();
void bhSysCallMovie();
void bhSysCallEnding();
void bhSysCallGameover();
void bhSysCallTypewriter();
void bhSysCallOption();
void bhSysCallCompEvent();
void bhSysCallMonitor();
void bhSysCallSndMonitor();
void bhSysCallScreenSaver();
void bhReturnTitle();
void bhExitGame();
void bhSetEventTimer(int mode);
void EasyDispMessage(float PosY, unsigned int MessageNo);

extern unsigned char pl_sleep_cnt;
extern unsigned char Pause_Flag;

#endif
