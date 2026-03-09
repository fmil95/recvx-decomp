#ifndef _EN11_H_
#define _EN11_H_

#include "types.h"

void bhEne11(BH_PWORK* epw);
void bhEne11_Init(BH_PWORK* epw);
void bhEne11_Brain(BH_PWORK* epw);
void bhEne11_BR00(BH_PWORK* epw);
void bhEne11_Move(BH_PWORK* epw);
void bhEne11_MV00(BH_PWORK* epw);
void bhEne11_MV01(BH_PWORK* epw);
void bhEne11_MV02(BH_PWORK* epw);
void bhEne11_MV03(BH_PWORK* epw);
void bhEne11_MV04(BH_PWORK* epw);
void bhEne11_MV05(BH_PWORK* epw);
void bhEne11_MV06(BH_PWORK* epw);
void bhEne11_MV07(BH_PWORK* epw);
void bhEne11_MV08(BH_PWORK* epw);
void bhEne11_MV09(BH_PWORK* epw);
void bhEne11_Nage();
void bhEne11_Damage();
void bhEne11_Die();
void bhEne11_GoFoward(BH_PWORK* epw);
void bhEne11_CollisionWalls(BH_PWORK* epw);
int bhEne11_CollisionBoxEdge2(BH_PWORK* epw);
/*void bhEne11_CameraSet(BH_PWORK* epw, _anon3* vec, int hcnt);*/
void bhEne11_MoveNearWall(BH_PWORK* epw);
void bhEne11_LightControl(BH_PWORK* epw, int flg);
int bhEne11_SelectDir(BH_PWORK* epw);

#endif
