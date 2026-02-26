#ifndef _SUBPL_H_
#define _SUBPL_H_

#include "types.h"

void bhSubpl(BH_PWORK* epw);
void init_subpl(BH_PWORK* epw);
void em60_init(BH_PWORK* epw);
void move_subpl(BH_PWORK* epw);
void em_sce(BH_PWORK* epw);
void bhEne_Event(BH_PWORK* epw);
void bhEne_Event2(BH_PWORK* epw);
void mv00_subpl0(BH_PWORK* epw);
void mv00_subpl0Ex(BH_PWORK* epw);
void mv00_subpl1(BH_PWORK* epw);
void mv00_subpl2(BH_PWORK* epw);
void mv00_subpl2_0(BH_PWORK* epw);
void mv00_subpl3(BH_PWORK* epw);
void mv00_subpl3_0(BH_PWORK* epw);
void mv00_subpl5(BH_PWORK* epw);
void mv00_subpl6(BH_PWORK* epw);
void mv00_subpl0_1(BH_PWORK* epw);
int bhSub_DirTarget(BH_PWORK* epw, float x, float z, int ay);
void mv00_subpl10(BH_PWORK* epw);
void bhEne28();

#endif
