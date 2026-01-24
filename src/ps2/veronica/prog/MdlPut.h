#ifndef _MDLPUT_H_
#define _MDLPUT_H_

#include "types.h"

void bhPutModel(BH_PWORK* ewP);
static void DrawTreeBsc(NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num);
static void EasyMultiDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num);
static void SimpleMultiDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num);
static void EasyDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num);
static void SimpleDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num);
void bhCalcModel(BH_PWORK* ewP);
void bhCalcTree(NJS_MATRIX* basP, ML_WORK* mlwP);

#endif
