#ifndef _EFFSUB2_H_
#define _EFFSUB2_H_

#include "types.h"

typedef struct P_WK
{
	// total size: 0x10
    short type1; // offset 0x0, size 0x2
    short type2; // offset 0x2, size 0x2
    float size;  // offset 0x4, size 0x4
    float spd;   // offset 0x8, size 0x4
    short wait;  // offset 0xC, size 0x2
} P_WK;  

typedef struct ACID_WORK
{
    // total size: 0xC
    int dam;      // offset 0x0, size 0x4
    float poison; // offset 0x4, size 0x4
    int se;       // offset 0x8, size 0x4
} ACID_WORK;

void bhEff_E00_Mince(O_WRK* op);
void bhEff_E00_DrawParticleSpr(O_WRK* op);
void bhEff_E00_DrawParticlePly(O_WRK* op);
void bhEff_E00_DropBlood(O_WRK* op);
void bhEff_E00_Fire(O_WRK* op);
void bhEff_E00_Acid(O_WRK* op);
void bhEff_E00_AcidGenerator(O_WRK* op);
void bhEff_E00_BloodBurst(O_WRK* op);
void bhEff_E00_Blood(O_WRK* op);
void bhEff_E00_Dust(O_WRK* op);
void bhEff_E02_SandDust(O_WRK* op);
void bhEff_E02_SandParticle(O_WRK* op);
void bhEff_E02_SandParticle2(O_WRK* op);
void bhEff_E03_Acid(O_WRK* op);
void bhEff_E03_Shadow(O_WRK* op);
void bhEff_E05_Blood(O_WRK* op);
void bhEff_E06_Rinpun(O_WRK* op);
void bhEff_E11_SearchLight(O_WRK* op);
void bhEff_E11_SearchLightDraw(O_WRK* op);
int bhEff_E11_CheckCollisionPlayer(NJS_POINT3* p1, NJS_POINT3* p2);
void bhEff_E16_LaserSight(O_WRK* op);
void bhEff_E16_LaserSightDraw(O_WRK* op);
void bhEff_E12_Fire(O_WRK* op);
void bhEff_E12_FrameLiquid(O_WRK* op);
void bhEff_E12_FloorBlood2(O_WRK* op);
void bhEff_E12_FireSpark(O_WRK* op);
void bhEff_E12_FireManager(O_WRK* op);
void bhEff_E12_FireBurstDraw(O_WRK* owp);
void bhEff_E12_Fire2(O_WRK* op);
void bhEff_E12_Fire3(O_WRK* op);
void bhEff_E12_BintaEffControl(O_WRK* op);
void bhEff_E13_Fluid(O_WRK* op);
void bhEff_E14_Explosion(O_WRK* op);
void bhEff_E14_Fire(O_WRK* op);
void bhEff_E14_Fire2(O_WRK* op);
void bhEff_E14_Mucus(O_WRK* op);
void bhEff_E14_MucusDraw(O_WRK* op);
void bhEff_DamagePoint(O_WRK* op);
void bhEff_DamagePointDraw(O_WRK* op);
void bhEff_Draw3DSprite(O_WRK* op);
void bhEff_SetUVInfo(O_WRK* op, UV_WORK* uvp, float BaseSize);
void bhEff_SetAlign(O_WRK* op, unsigned int flg);
void bhEff_SetBaseColor(O_WRK* op, unsigned int col);
void bhClrEff_YG();

#endif
