#ifndef _EN13_H_
#define _EN13_H_

#include "types.h"

void bhEne13(BH_PWORK* epw);
void bhEne13_Init(BH_PWORK* epw);
void bhEne13_Brain(BH_PWORK* epw);
void bhEne13_BR00(BH_PWORK* epw);
void bhEne13_BR01(BH_PWORK* epw);
void bhEne13_Move(BH_PWORK* epw);
void bhEne13_MV00(BH_PWORK* epw);
void bhEne13_MV01(BH_PWORK* epw);
void bhEne13_MV02(BH_PWORK* epw);
void bhEne13_MV03(BH_PWORK* epw);
void bhEne13_Nage();
void bhEne13_Damage(BH_PWORK* epw);
void bhEne13_DG00(BH_PWORK* epw);
void bhEne13_Die(BH_PWORK* epw);
void bhEne13_InitDamage(BH_PWORK* epw);
void bhEne13_Finish(BH_PWORK* epw);
/*void bhEne13_ScaleModel(npobj* pObj, float sx, float sy, float sz);
int bhEne13_StoreObject(BH_PWORK* epw, _anon32* pos, _anon32** v, int no);
int bhEne13_RestoreObject(BH_PWORK* epw, _anon32* pos, _anon32** v, int no);*/
void bhEne13_PutAttacker(BH_PWORK* epw, int no);
void bhEne13_Tentacle(BH_PWORK* epw, int no);
int bhEne13_GetHatchNo(BH_PWORK* epw);
int bhEne13_GetTentaNo(BH_PWORK* epw);
BH_PWORK** bhEne13_GetChild(BH_PWORK* epw, int* num);
void bhEne13_CameraControl(BH_PWORK* epw);
void bhEne13_SetCamera(BH_PWORK* epw, float f);
int bhEne13_SelectTentacle(BH_PWORK* epw);
void bhEne13_PlayerControl(BH_PWORK* epw);

#endif
