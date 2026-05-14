#ifndef _OBJITM_H_
#define _OBJITM_H_

#include "types.h"

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
