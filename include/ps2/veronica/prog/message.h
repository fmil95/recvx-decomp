#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "types.h"

void bhSetMessage(int mes_typ, int mes_idx);
void bhControlMessage(int mode);
void bhDispFont(NJS_POINT2* pos, int code, int color, float pri);
/*void bhDispFontEx(NJS_POINT2* pos, int code, unsigned int argb, float pri); - commented out, since the original codebase didn't have this prototype according to ps2_McSaveFile */
int bhDispItemName(NJS_POINT2* pos, int id, int color, int count, float pri);
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx, int color, int count);
int bhDispMessageEx(float px, float py, float pri, int mes_typ, int mes_idx, unsigned int argb, int count);
void bhDispTime(NJS_POINT2 *pos, unsigned int flg, int time, int color, float pri);
void bhDispTimeEx(NJS_POINT2* pos, unsigned int flg, int time, unsigned int argb, float pri);
float bhGetFontSize(unsigned short code);
float bhMesLen(unsigned short* dp);
void bhFontScaleSet(float ScaleX, float ScaleY, float ScaleCR);

extern float FontScaleX;
extern float FontScaleCR;
extern const unsigned char FontSz[126];

#endif
