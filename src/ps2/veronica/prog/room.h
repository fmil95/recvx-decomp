#ifndef _ROOM_H_
#define _ROOM_H_

#include "types.h"

void bhInitRoom();
void bhInitReadRDT();
void bhSetRDT();
void bhSetRoom();
void bhFinishRoom();
void bhSetEneMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno);
void bhSetEneMtn(unsigned char* datp, BH_PWORK* ep, int id);
void bhSetRoomMtn(unsigned char* datp);
void bhSetObjMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno);
void bhSetItmMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno);
void bhSetEffectTable();
void bhSetEffectLink(EF_WRK* efp, int efid);
void bhSetDoorDemo(unsigned int attr, int stg_no, int rom_no, unsigned int pos_no, unsigned int dor_tp);
void bhStartDoorDemo();
void bhPushGameData();
void bhPopGameData();

#endif
