#ifndef _EN19_H_
#define _EN19_H_

#include "types.h"

void bhEne19(BH_PWORK* ewP);
void bhEne19_Init(BH_PWORK* ewP);
void bhEne19_Move(BH_PWORK* ewP);
void bhEne19_Damage();
void bhEne19_Die(BH_PWORK* ewP);
void bhEne19_Event(BH_PWORK* ewP);
void bhEne19_Br00(BH_PWORK* ewP);
void bhEne19_Br01(BH_PWORK* ewP);
void bhEne19_Br02(BH_PWORK* ewP);
void bhEne19_Mv00();
void bhEne19_Mv01();
/*void bhEne19_Mv02(_anon4* fwP, int count);*/
void bhEne19_Mv03();
/*void bhEne19_Mv04a(_anon4* fwP, int count);
void bhEne19_Mv04b(_anon4* fwP, int count);
void bhEne19_Mv05(_anon4* fwP, int count);*/
void bhEne19_Mv06();
/*void bhEne19_Mv07(BH_PWORK* ewP, _anon4* fwP, int count);
void bhEne19_Mv08(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_Mv09(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_Mv10(BH_PWORK* ewP, _anon4* fwP, int count);
void bhEne19_Mv11(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_Mv12(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_Mv13(BH_PWORK* ewP, _anon4* fwP, int count);
void bhEne19_Mv14(BH_PWORK* ewP, _anon4* fwP, int count);
void bhEne19_Mv15(_anon4* fwP, int count);
void bhEne19_Mv16(_anon4* fwP, int count);
void bhEne19_Mv17(_anon4* fwP, int count);
void bhEne19_Mv18(BH_PWORK* ewP, _anon4* fwP, int count);
void bhEne19_Mv19(_anon4* fwP, int count);
void bhEne19_Mv20(BH_PWORK* ewP, _anon4* fwP, int count);
_anon48* bhEne19_ActionSearch(int act_nw, int act_no);
int bhEne19_ActionChange(BH_PWORK* ewP, _anon4* fwP, int act_dst);
int bhEne19_ActionMain(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_TargetAnalyze(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_PositonFix(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_HeadTurn(BH_PWORK* ewP, _anon4* fwP, int mode);
int bhEne19_AttackHitCheck(BH_PWORK* ewP, _enum_2 arm_no, float ar, int* angP);
void bhEne19_CalcEnemy(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_DmgCheck(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, _anon6* dirP);
int bhEne19_CollisionCircle2Oval(float basP[16], float ra, float rb, _anon6* posP, float rc);
void bhEne19_TyBloodSet(_anon21* ebP);
void bhEne19_ClawReset(BH_PWORK* ewP, _anon4* fwP);
void bhEne19_SoundSet(BH_PWORK* ewP, _anon4* fwP);*/
int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP);
/*int bhEne19_PlySetDamage(BH_PWORK* plP, _anon4* fwP, int dmg_mod);
void bhEne19_PlyMoveMain(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg042(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg043(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg044(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg045(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg046_047(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg050_051(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg052_053(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmg117_118(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmgDie(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmgRtn(BH_PWORK* plP, _anon4* fwP);
void bhEne19_PlyDmgFal(BH_PWORK* plP, _anon4* fwP);
void bhEne_PlyActionInit(BH_PWORK* ewP, _anon1* pawP, _anon2* act_tblP, int tbl_num);
void bhEne_PlyActionMain(BH_PWORK* plP, _anon1* pawP);
int bhEne_PlyActionChange(BH_PWORK* plP, _anon1* pawP, int act_no);
int bhEne_CalcCombRate(BH_PWORK* ewP, _anon47* cwP);
_enum_4 bhEne19_CheckDmgLvl0(BH_PWORK* ewP, _anon4* fwP);
_enum_4 bhEne19_CheckDmgLvl1(BH_PWORK* ewP, _anon4* fwP);
_enum_4 bhEne19_CheckDmgLvl2(BH_PWORK* ewP, _anon4* fwP);
_anon13* bhEne19_SetLeftClaw(_anon17* mlwP, _enum_6 tgt_bas, _enum_6 tgt_obj);*/
void bhEne19_SetClawPlane(BH_PWORK* ewP, float mtxP[16], int col, int tim, float src_x, float dst_x);

#endif
