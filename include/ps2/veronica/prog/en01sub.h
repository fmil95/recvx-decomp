#ifndef _EN01SUB_H_
#define _EN01SUB_H_

#include "types.h"

void bhEne01Parent(BH_PWORK* epw);
void bhEne01Parent_Init(BH_PWORK* epw);
void bhEne01Parent_Move();
void bhEne01Parent_NearestCheck();
void bhEne01Parent_NoKaidanCheck();
void bhEne01Arm(BH_PWORK* epw);
void bhEne01Arm_Init(BH_PWORK* epw);
void bhEne01Arm_Move(BH_PWORK* epw);
void bhEne01Arm_MV00();
void bhEne01Arm_Damage(BH_PWORK* epw);
void bhEne01Arm_DG00(BH_PWORK* epw);
void bhEne01Arm_DG01(BH_PWORK* epw);
void bhEne01Leg(BH_PWORK* epw);
void bhEne01Leg_Init(BH_PWORK* epw);
void bhEne01Leg_Move(BH_PWORK* epw);
void bhEne01Leg_MV00();
void bhEne01Leg_Damage(BH_PWORK* epw);
void bhEne01Leg_DG00(BH_PWORK* epw);
void bhEne01Head(BH_PWORK* epw);
void bhEne01Head_Init(BH_PWORK* epw);
void bhEne01Head_Move(BH_PWORK* epw);
void bhEne01Head_MV00();
void bhEne01Head_Damage(BH_PWORK* epw);
void bhEne01Head_DG00(BH_PWORK* epw);
void bhEne01Cap(BH_PWORK* epw);
void bhEne01Cap_Init(BH_PWORK* epw);
void bhEne01Cap_Move(BH_PWORK* epw);
void bhEne01Cap_MV00();
void bhEne01Cap_Damage(BH_PWORK* epw);
void bhEne01Cap_DG00(BH_PWORK* epw);
void bhEne01Cap_DG01(BH_PWORK* epw);
void bhEne01Worm(BH_PWORK* epw);
void bhEne01Worm_Init(BH_PWORK* epw);
void bhEne01Worm_Move(BH_PWORK* epw);
void bhEne01Worm_MV00();
void bhEne01Worm_MV01(BH_PWORK* epw);
void bhEne01Worm_MV02(BH_PWORK* epw);
void bhEne01Bom(BH_PWORK* epw);
void bhEne01Bom_Init(BH_PWORK* epw);
void bhEne01Bom_Move(BH_PWORK* epw);
void bhEne01Scope(BH_PWORK* epw);
void bhEne01Scope_Init(BH_PWORK* epw);
void bhEne01Scope_Move();
void bhEne01Scope_Effect(BH_PWORK* epw);

#endif
