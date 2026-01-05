#ifndef _PS2_NAFOG_H_
#define _PS2_NAFOG_H_

#include "types.h"

void	njFogEnable();
void	njFogDisable();
void	njSetFogColor(Uint32 c);
void	njSetFogTable(NJS_FOG_TABLE fog);
void	njGenerateFogTable3(NJS_FOG_TABLE fog, Float n, Float f);
float njCalcFogPowerEx(float INVZ);
float njCalcFogPower(float fVSZ);

/*typedef int type_0[4];
typedef float type_1[8];
typedef float type_2[128];
typedef float type_3[8];*/

#endif
