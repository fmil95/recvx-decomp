#ifndef _SYSTEM_H_
#define _SYSTEM_H_

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

#endif
