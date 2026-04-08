#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "types.h"

void bhInitLight();
void bhSetLightTab(LGT_WORK* lt, int lno);
void bhSetEasyDirLight(float it);
void bhControlLight();
void bhSetLight();
void bhSetHalfLight();
void bhGetLightVector(int xr, int yr, int zr, NJS_VECTOR* vec);

#endif
