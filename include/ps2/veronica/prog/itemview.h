#ifndef _ITEMVIEW_H_
#define _ITEMVIEW_H_

#include "types.h"

void DrawSubItem(S_WORK* st, SITEM* si);
void Model_Read_Start();
void Model_Read_Set(S_WORK* st);
void CameraInit();
void CameraSet();
void ItemView();
void ItemModelChangeZoomIn();
void ItemModelCheck();
void ItemModelActionSet();
void ItemModelChangeZoomOut();
void ItemModelMessageWait();
unsigned char MdlDirChk(short* dirang, short mdlang);
unsigned char MdlAction00(SITEM* si);
unsigned char MdlAction01(SITEM* si);
unsigned char MdlAction02(SITEM* si);
void MdlEvalflagsSet(unsigned short evalchk);
void MdlHideCheck(NJS_CNK_OBJECT* op, unsigned char el, unsigned char chk);
float ModelScaleSet(SITEM* itemmodel, int flg);
void FlagErase(NJS_CNK_OBJECT* op);
void LighterOpen(NJS_CNK_OBJECT* object);
void FileSyu(NJS_CNK_OBJECT* op);
void MakeTag(NJS_CNK_OBJECT* param, unsigned short flg);

#endif
