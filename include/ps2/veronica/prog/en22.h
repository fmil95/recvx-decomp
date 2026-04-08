#ifndef _EN22_H_
#define _EN22_H_

#include "types.h"

void bhEne22_DmmyBrain();
void bhEne22(BH_PWORK* epw);
void bhEne22_MainLoop(BH_PWORK* epw);
int bhEne22_DmgChk(BH_PWORK* epw);
void bhEne22_ChgDmgMode(BH_PWORK* epw);
void bhEne22_DamageAdd(BH_PWORK* epw);
void bhEne22_CollCheck(BH_PWORK* epw);
void bhEne22_CollCheckWall(BH_PWORK* epw);
void bhEne22_Init(BH_PWORK* epw);
void bhEne22_InitType00();
void bhEne22_Move(BH_PWORK* epw);
void bhEne22_Nage();
void bhEne22_Damage(BH_PWORK* epw);
void bhEne22_Die(BH_PWORK* epw);
void bhEne22_PlyerHitCheck(BH_PWORK* pl, BH_PWORK* epw);
void bhEne22_EneSearch(BH_PWORK* epw);
void bhEne22_Brain(BH_PWORK* epw);
void bhEne22_Brain00(BH_PWORK* epw);
void bhEne22_Brain01(BH_PWORK* epw);
void bhEne22_Brain02(BH_PWORK* epw);
void bhEne22_Brain04(BH_PWORK* epw);
void bhEne22_MVType00(BH_PWORK* epw);
void bhEne22_MV00(BH_PWORK* epw);
void bhEne22_MV01(BH_PWORK* epw);
void bhEne22_MV02(BH_PWORK* epw);
void bhEne22_MV03();
void bhEne22_MV04(BH_PWORK* epw);
void bhEne22_MV05();
void bhEne22_MV06(BH_PWORK* epw);
void bhEne22_DGType00(BH_PWORK* epw);
void bhEne22_DG00(BH_PWORK* epw);
void bhEne22_DG01(BH_PWORK* epw);
void bhEne22_DG02();
void bhEne22_DDType00(BH_PWORK* epw);
void bhEne22_DD00(BH_PWORK* epw);
void bhEne22_DD01();
void bhEne22_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne22_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
int bhEne22_SetMtn(BH_PWORK* epw);
void bhEne22_CheckMtnTbl(BH_PWORK* epw, int frm);
void bhEne22_GetTranslateMtn(BH_PWORK* epw, int frm);
void bhEne22_SparkEffect(BH_PWORK* epw, int frm);
/*unsigned int* bhEne22_GetDengekiColorAddr(npobj* objp, int no);*/
void bhEne22_SetWaterEffect(BH_PWORK* epw, int mtn_no, int frm);
int bhEne22_GetAreaNo(float px, float pz);
int bhEne22_AreaCheck(float ene_x, float ene_z, float ply_x, float ply_z);
int bhEne22_SetTrgPos(BH_PWORK* epw);
/*void bhEne22_SePlay(BH_PWORK* epw, _anon34* ps, int no);
_anon0* bhEne22_SetDengekiEffect(BH_PWORK* epw, int obj, _anon34* ofs, float size);*/
void bhEne22_SetDengekiEffect2(BH_PWORK* epw);
void bhEne22_SetElectricShockEffect(BH_PWORK* epw, int type);
void bhEne22_SetElectricShockEffect2(BH_PWORK* epw);
/*_anon0* bhEne22_SetElectricLightEffect(BH_PWORK* epw);
void bhEne22_SetLight(BH_PWORK* epw, int lnk_obj, _anon34* ofs, int type);*/
void bhEne22_CtrLight(BH_PWORK* epw);
/*void bhEne22_ChgDengekiColor(npobj* objp, int no, unsigned int argb);*/

#endif
