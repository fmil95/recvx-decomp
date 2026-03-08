#ifndef _EN21_H_
#define _EN21_H_

#include "types.h"

void bhEne21(BH_PWORK* epw);
void bhEne21_Init(BH_PWORK* epw);
void bhEne21_SearchPlayer(BH_PWORK* epw);
void bhEne21_Brain(BH_PWORK* epw);
void bhEne21_BR00(BH_PWORK* epw);
void bhEne21_Move(BH_PWORK* epw);
void bhEne21_MV00(BH_PWORK* epw);
void bhEne21_MV01(BH_PWORK* epw);
void bhEne21_MV02(BH_PWORK* epw);
void bhEne21_MV03(BH_PWORK* epw);
void bhEne21_MV04(BH_PWORK* epw);
void bhEne21_MV05(BH_PWORK* epw);
void bhEne21_MV06(BH_PWORK* epw);
void bhEne21_MV07();
void bhEne21_MV08(BH_PWORK* epw);
void bhEne21_Nage(BH_PWORK* epw);
void bhEne21_NG00(BH_PWORK* epw);
void bhEne21_Damage(BH_PWORK* epw);
void bhEne21_Die(BH_PWORK* epw);
void bhEne21_DD00(BH_PWORK* epw);
void bhEne21_PlayerControl(BH_PWORK* epw);
unsigned char bhEne21_AllWayWallCheck(BH_PWORK* epw, float dist);
void bhEne21_SetSparkEff(BH_PWORK* epw, int num, int flg, unsigned int ofy);
void bhEff_E21_Spark(O_WRK* op);
void bhEne21_SetMarkEff(BH_PWORK* epw);
void bhEff_E21_Mark(O_WRK* op);

#endif
