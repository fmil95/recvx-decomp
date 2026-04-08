#ifndef _EN26_H_
#define _EN26_H_

#include "types.h"

void bhEne26(BH_PWORK* epw);
void bhEne26_DmgCheck(BH_PWORK* epw);
/*void bhEne26_DamageAdd(BH_PWORK* epw, _anon25* wp_tbl);*/
void bhEne26_LinkFireEffect(BH_PWORK* epw, int type);
/*void bhEne26_DmgCheckType00(BH_PWORK* epw, _anon25* wp_tbl);*/
int bhEne26_CheckExpHead(BH_PWORK* epw);
/*void bhEne26_SetBlood(BH_PWORK* epw, _anon25* wp_tbl);*/
void bhEne26_MainLoop(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_PlayerControl(BH_PWORK* epw, BH_PWORK* pl);
int bhEne26_SetMtn(BH_PWORK* epw);
void bhEne26_CheckMtnTbl(BH_PWORK* epw, int frm);
void bhEne26_SearchNeck(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_CollCheck(BH_PWORK* epw);
void bhEne26_CollCheckWall(BH_PWORK* epw);
void bhEne26_PlayerLink(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_CalcEnemy(BH_PWORK* epw);
void bhEne26_Init(BH_PWORK* epw);
void bhEne26_Move(BH_PWORK* epw);
void bhEne26_MVType(BH_PWORK* epw);
void bhEne26_EneSearch(BH_PWORK* epw);
void bhEne26_Brain00(BH_PWORK* epw);
int bhEne26_ActionModeCheck(BH_PWORK* epw);
void bhEne26_MV00(BH_PWORK* epw);
void bhEne26_MV01(BH_PWORK* epw);
void bhEne26_MV02(BH_PWORK* epw);
void bhEne26_MV03(BH_PWORK* epw);
void bhEne26_MV05(BH_PWORK* epw);
void bhEne26_MV06(BH_PWORK* epw);
void bhEne26_MV07(BH_PWORK* epw);
void bhEne26_MV16(BH_PWORK* epw);
void bhEne26_Nage(BH_PWORK* epw);
void bhEne26_NGType(BH_PWORK* epw);
void bhEne26_NG00(BH_PWORK* epw);
void bhEne26_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne26_Damage(BH_PWORK* epw);
void bhEne26_DGType(BH_PWORK* epw);
void bhEne26_DG00();
void bhEne26_DG01();
void bhEne26_DG02(BH_PWORK* epw);
void bhEne26_DG03(BH_PWORK* epw);
void bhEne26_DG04(BH_PWORK* epw);
void bhEne26_DG15(BH_PWORK* epw);
void bhEne26_Die(BH_PWORK* epw);
void bhEne26_DDType(BH_PWORK* epw);
void bhEne26_DD00(BH_PWORK* epw);
int bhEne26_EatCheck(BH_PWORK* epw, int rng, float dist, int mode);
void bhEne26_ExpHeadEffect(BH_PWORK* epw);
void bhEne26_NeckBloodEffect(BH_PWORK* epw, int type);
void bhEne26_KamiEffect(BH_PWORK* epw, int frm);
void bhEne26_SePlay(BH_PWORK* epw, int no);

#endif
