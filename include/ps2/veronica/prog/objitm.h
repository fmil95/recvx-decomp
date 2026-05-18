#ifndef _OBJITM_H_
#define _OBJITM_H_

#include "types.h"
#include "macros.h"

typedef struct HAIR_WORK 
{
    // total size: 0x30
    float ox;  // offset 0x0, size 0x4
    float oy;  // offset 0x4, size 0x4
    float oz;  // offset 0x8, size 0x4
    float oxb; // offset 0xC, size 0x4
    float oyb; // offset 0x10, size 0x4
    float ozb; // offset 0x14, size 0x4
    short ax;  // offset 0x18, size 0x2
    short ay;  // offset 0x1A, size 0x2
    short az;  // offset 0x1C, size 0x2
    short axb; // offset 0x1E, size 0x2
    short ayb; // offset 0x20, size 0x2
    short azb; // offset 0x22, size 0x2
    float spx; // offset 0x24, size 0x4
    float spy; // offset 0x28, size 0x4
    float spz; // offset 0x2C, size 0x4
} HAIR_WORK;

void bhInitObjItm();
O_WRK* bhSetObject(ETTY_WORK* otp, int no, unsigned char* lkp);
O_WRK* bhSetItem(ETTY_WORK* itp, int no, unsigned char* lkp);
void bhControlObjItm();
void bhDrawGeneralPurposeWater();
void bhDrawObjItm();
void bhDrawObject(O_WRK* op);
void bhDrawSpObject(O_WRK* op);
void bhSetAlphaFadeObject(O_WRK* op, int jntno, int jnt_n, int alpha, int count);
void bhControlAlphaFadeObject(O_WRK* op);
void bhObjDmy();
void bhObjItmBox(O_WRK* op);
void bhObj001(O_WRK* op);
void bhObj002(O_WRK* op);
void bhObj003(O_WRK* op);
void bhObj004(O_WRK* op);
void bhObj005(O_WRK* op);
void bhObj006(O_WRK* op);
void bhObj007(O_WRK* op);
void bhObj008(O_WRK* op);
void bhObj009(O_WRK* op);
void bhObj010(O_WRK* op);
void bhObj011(O_WRK* op);
void bhObj012(O_WRK* op);
void bhObjClpn(O_WRK* op);
void bhObjWssg();

extern unsigned int ulDrawGeneralPurposeWater;

#endif
