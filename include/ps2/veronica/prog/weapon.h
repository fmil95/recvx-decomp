#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "types.h"

void bhSetWeapon(O_WRK* op, int wpn_no, int flg);
void bhObjWpn(BH_PWORK* op);
void bhActionWeapon(BH_PWORK* op);
short bhCheckBullet();
int bhCountBullet();
int bhCheckGunAtari(GA_WORK* gap);
void bhCheckKnifeAtari(GA_WORK* gap);
int bhCheckFlyAtari(GA_WORK* gap, int eidx);
void bhSetBowDamage();
void bhCheckBombAtari(NJS_POINT3* pos, float ar, int dmax, int dmin);
int bhCheckCapCol2Capsule(BH_PWORK* pp, NJS_CAPSULE* cap, NJS_POINT3* hps);
void bhSetGunSplash(GA_WORK* gap, NJS_POINT3* pos, int wattr);
void bhSetExplosion(NJS_POINT3* pos);
void bhSetExplosionEffect(NJS_POINT3* pos);
void bhSetExplosionEffectEx(NJS_POINT3* pos, float scl);

#endif
