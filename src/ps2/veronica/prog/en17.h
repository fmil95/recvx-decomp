#ifndef _EN17_H_
#define _EN17_H_

#include "types.h"

void bhEne17_DmmyBrain();
void bhEne17(BH_PWORK* epw);
void bhEne17_EneToPlyDist(BH_PWORK* epw);
void bhEne17_MainLoop(BH_PWORK* epw);
int bhEne17_DmgChk(BH_PWORK* epw);
void bhEne17_ChgDmgMode(BH_PWORK* epw);
void bhEne17_DamageAdd(BH_PWORK* epw);
int bhEne17_SetMtn(BH_PWORK* epw);
void bhEne17_MtnTblPlay(BH_PWORK* epw, int frm);
void bhEne17_CollCheck(BH_PWORK* epw);
void bhEne17_CollCheckWall(BH_PWORK* epw);
void bhEne17_CalcEnemy(BH_PWORK* epw);
void bhEne17_Init(BH_PWORK* epw);
void bhEne17_InitType00();
BH_PWORK* bhEne17_SetLinkWork(BH_PWORK* epw, int lnk_obj, int mdl_no, int id);
void bhEne17_Move(BH_PWORK* epw);
void bhEne17_Damage(BH_PWORK* epw);
void bhEne17_Nage();
void bhEne17_Die();
void bhEne17_Brain(BH_PWORK* epw);
void bhEne17_Brain00(BH_PWORK* epw);
void bhEne17_MVType00(BH_PWORK* epw);
void bhEne17_MV00(BH_PWORK* epw);
void bhEne17_MV01(BH_PWORK* epw);
void bhEne17_MV02(BH_PWORK* epw);
void bhEne17_MV03(BH_PWORK* epw);
void bhEne17_MV04(BH_PWORK* epw);
void bhEne17_MV05(BH_PWORK* epw);
void bhEne17_MV06(BH_PWORK* epw);
void bhEne17_DGType00(BH_PWORK* epw);
void bhEne17_DG00(BH_PWORK* epw);
void bhEne17_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne17_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
int bhEne17_PlayerDGCheck(BH_PWORK* epw, BH_PWORK* pl);
void bhEne17_SePlay(BH_PWORK* epw, int no);
int bhEne17_CameraControl(BH_PWORK* epw);
/*void bhEne17_AfterimageAxEffect(BH_PWORK* epw, float mtx[16], _anon15* ofs, unsigned int argb);
void bhEne17_SetSmokeEffect(BH_PWORK* epw, int lnk_onj, _anon15* ofs);
void bhEne17_SetSmokeEffect2(BH_PWORK* epw, _anon15* ofs, int rot);
void bhEne17_SetSmokeEffect3(BH_PWORK* epw, _anon15* ofs, int rot);
void bhEne17_SetLight(_anon15* ofs);*/

#endif
