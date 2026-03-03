#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "types.h"

typedef struct EFFECT_INFO
{
	// total size: 0x8
    unsigned int flg; // offset 0x0, size 0x4
    int nbAnim;       // offset 0x4, size 0x4
} EFFECT_INFO;

void bhInitEffect();
void bhSetFontTexture(void* datp);
void bhClearEffect();
void bhClearEventEffect();
void bhClrEff_YT();
int bhPushEffectWork();
void bhPopEffectWork();
unsigned int bhGetGidx(O_WRK* op);
O_WRK* bhSetExtraEffectWork();
void bhDeleteYakkyou();
void bhDrawPARAM2D(NJS_PRIM* prm, NJS_POINT2COL* p2c, float pri);
int bhSetEffect(int effno, POINT* pnt, unsigned char* lkp, int lkono);
int bhSetEffectTb(EF_WORK* efp, NJS_POINT3* off, unsigned char* lkp, int lkono);
int bhSetEffectEvt(int effno, POINT* pnt, unsigned short type, int ax, int ay);
int bhSetShadow(char* jtb, unsigned char* lkp, int lkono, float sx, float sy, float sz);
void bhLinkBlood();
void bhControlEffect();
void bhDrawEffect();
void bhDrawPolEffect(unsigned int* owp, int ct);
void bhDrawMdfEffect(unsigned int* owp, int ct);
void bhDrawLinEffect(unsigned int* owp, int ct);
void bhDrawNtxEffect3D(unsigned int* owp, int ct);
void bhDrawTrsEffect3D(unsigned int* owp, int ct);
void bhDrawOpqEffect3D(unsigned int* owp, int ct);
void bhDrawThlEffect3D(unsigned int* owp, int ct);
void bhDrawNtxEffect2D(unsigned int* owp, int ct);
void bhDrawTrsEffect2D(unsigned int* owp, int ct);
void bhDrawThunder();

#endif
