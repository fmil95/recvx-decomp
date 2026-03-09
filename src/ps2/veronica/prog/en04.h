#ifndef _EN04_H_
#define _EN04_H_

#include "types.h"

void bhEne04_DmmyBrain();
void bhEne04(BH_PWORK* epw);
void bhEne04_MainLoop(BH_PWORK* epw);
void bhEne04_SetCollision(BH_PWORK* epw);
void bhEne04_DmgChk(BH_PWORK* epw);
void bhEne04_ChgDmgMode(BH_PWORK* epw);
void bhEne04_DamageAdd(BH_PWORK* epw);
void bhEne04_PlayerControl(BH_PWORK* pl, BH_PWORK* epw);
void bhEne04_PlayerLink(BH_PWORK* pl, BH_PWORK* epw);
void bhEne04_CollisionCheck(BH_PWORK* epw);
void bhEne04_CollCheckWall(BH_PWORK* epw);
void bhEne04_Init(BH_PWORK* epw);
void bhEne04_Move(BH_PWORK* epw);
void bhEne04_Nage(BH_PWORK* epw);
void bhEne04_Damage(BH_PWORK* epw);
void bhEne04_Die(BH_PWORK* epw);
void bhEne04_MVType00(BH_PWORK* epw);
void bhEne04_MVType01(BH_PWORK* epw);
void bhEne04_MVType02(BH_PWORK* epw);
int bhEne04_AtariCheck(BH_PWORK* epw);
int bhEne04_AtariCheck2(BH_PWORK* epw);
/*_anon12* bhEne04_EnemyAtariCheck2(BH_PWORK* epw, unsigned char type, unsigned char ip);*/
void bhEne04_EneSearch(BH_PWORK* epw);
void bhEne04_Brain(BH_PWORK* epw);
void bhEne04_Brain00(BH_PWORK* epw);
void bhEne04_Brain01(BH_PWORK* epw);
void bhEne04_Brain02(BH_PWORK* epw);
void bhEne04_Brain04(BH_PWORK* epw);
void bhEne04_Brain06(BH_PWORK* epw);
void bhEne04_MV00(BH_PWORK* epw);
void bhEne04_MV01(BH_PWORK* epw);
void bhEne04_MV02(BH_PWORK* epw);
void bhEne04_MV03(BH_PWORK* epw);
void bhEne04_MV04(BH_PWORK* epw);
void bhEne04_MV05(BH_PWORK* epw);
void bhEne04_MV06(BH_PWORK* epw);
void bhEne04_MV07(BH_PWORK* epw);
void bhEne04_MV08(BH_PWORK* epw);
void bhEne04_MV09(BH_PWORK* epw);
void bhEne04_MV10(BH_PWORK* epw);
void bhEne04_MV11(BH_PWORK* epw);
void bhEne04_MV12(BH_PWORK* epw);
int bhEne04_Escape(BH_PWORK* epw, int res, int r);
void bhEne04_NGType00(BH_PWORK* epw);
void bhEne04_NG00(BH_PWORK* epw);
void bhEne04_NG01(BH_PWORK* epw);
void bhEne04_DGType00(BH_PWORK* epw);
void bhEne04_DG00(BH_PWORK* epw);
void bhEne04_DG01(BH_PWORK* epw);
void bhEne04_DDType00(BH_PWORK* epw);
void bhEne04_DD00(BH_PWORK* epw);
void bhEne04_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne04_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
int bhEne04_PlyDamageCheck(BH_PWORK* epw, int type);
void bhEne04_SpeedUp(float* spd, float g, float limit);
void bhEne04_SpeedDown(float* spd, float g, float limit);
void bhEne04_RunMotion(BH_PWORK* epw, int rot);
int bhEne04_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate);
int bhEne04_SetMtn(BH_PWORK* epw);
void bhEne04_CheckMtnTbl(BH_PWORK* epw, int frm);
int bhEne04_KaidanCheck(BH_PWORK* epw);
/*void bhEne04_ShakeWire(_anon0* obwp);*/
void bhEne04_RotNeck(BH_PWORK* epw, int ry);
int bhEne04_SearchNeck(BH_PWORK* epw);
void bhEne04_SePlay(BH_PWORK* epw, int no);

#endif
