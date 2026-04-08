#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "types.h"

void bhSetScreenFade(unsigned int argb, float ct);
void bhControlScreenFade();
void bhDrawScreenFade();
void bhInitScreenSaver();
void bhSetScreenSaver(unsigned int alpha, float ct);
void bhControlScreenSaver();
void bhDrawScreenSaver();
void bhControlCinesco();
void bhDrawCinesco();
void bhDrawScope();
void bhDrawScopeNumber(float px, float py, int num);
void bhDrawThermometer();
void bhDrawThermoNumber(float px, float py, int num, unsigned int argb);
void bhDrawFullScreenRenderTexture();
void bhDrawSmallScreenRenderTexture();

extern unsigned int Ps2_rendertex_initflag;

#endif
