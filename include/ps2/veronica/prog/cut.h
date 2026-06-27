#ifndef _CUT_H_
#define _CUT_H_

#include "types.h"

// TODO: move the defines below somewhere else
#define NJD_PI  3.141592f
#define NJM_RAD_ANG(n)  ((Angle)((n) * (65536.0f / (2 * NJD_PI))))
#define NJM_ANG_DEG(n)  ((n) * (360.0f / 65536.0f))
#define NJM_DEG_ANG(n)  ((Angle)((n) * (65536.0f / 360.0f)))
#define njArcTan2(y,x)   ((Angle)NJM_RAD_ANG(atan2f ((Float)(y),(Float)(x)) ))

void bhCheckCut(int flg);
int bhCheckCutArea(float px, float pz, char flr_no);
int bhCheckCutAreaInnerTriangle(float px, float pz, CUT_WRK* ct);
unsigned int bhCheckCutAttribute(float px, float pz, int flr_no);
void bhSetCut(int cno, int flg);
void bhSetFixedCut(int cno);
void bhSetRenderCut(int cno);
void bhSetHideObjLgt(int cno);
void bhSetHideObject(int offset);
void bhInitActiveCamera(int flg);
void bhCheckNearAttrOffCutRange(CUT_WORK* cp, unsigned int sft, float* px, float* pz);
void bhControlActiveCamera();
void bhSetEventCamera(int evc_no, int key_no);
void bhSetEventFixedCut(int cno, int kno);
void bhSetEventHideObjLgt(int cno, int kno);
void bhInitEventCamera();
void bhControlEventCamera();
void bhCheckEvtCamLockPosition();
void bhGetEvtCamLockPosition(CAM_KEYF_WORK* kfp, NJS_POINT3* pos);
void bhControlPlEyeCamera(unsigned int attr);
void bhInitPlEyeCamera();
void bhSetPlEyeCamera();
void bhControlMonitorCamera();
float bhCalcActiveYpos(CUT_WORK* cp);
short bhCalcActiveZang(CUT_WORK* cp);
short bhCalcActivePers(CUT_WORK* cp);

#endif
