#include "MdlPut.h"
#include "ps2_NaMatrix.h"
#include "ps2_NinjaCnk.h"
#include "main.h"

/*void(*bhJumpCnkDraw)()[4];
unsigned int _nj_control_3d_flag_;
_anon16* sys;*/

// 
// Start address: 0x12ebb0
void bhPutModel(BH_PWORK* ewP)
{
	unsigned int c3df;
	int draw_tp;
	//_anon10* owP;
	//_anon7* mlwP;
	// Line 65, Address: 0x12ebb0, Func Offset: 0
	// Line 66, Address: 0x12ebcc, Func Offset: 0x1c
	// Line 71, Address: 0x12ebd4, Func Offset: 0x24
	// Line 72, Address: 0x12ebe0, Func Offset: 0x30
	// Line 77, Address: 0x12ebe8, Func Offset: 0x38
	// Line 79, Address: 0x12ec10, Func Offset: 0x60
	// Line 81, Address: 0x12ec20, Func Offset: 0x70
	// Line 84, Address: 0x12ec38, Func Offset: 0x88
	// Line 85, Address: 0x12ec44, Func Offset: 0x94
	// Line 86, Address: 0x12ec54, Func Offset: 0xa4
	// Line 87, Address: 0x12ec70, Func Offset: 0xc0
	// Line 88, Address: 0x12ec78, Func Offset: 0xc8
	// Line 90, Address: 0x12ec94, Func Offset: 0xe4
	// Line 91, Address: 0x12ecbc, Func Offset: 0x10c
	// Line 93, Address: 0x12ece4, Func Offset: 0x134
	// Line 94, Address: 0x12ecf8, Func Offset: 0x148
	// Line 95, Address: 0x12ed18, Func Offset: 0x168
	// Line 96, Address: 0x12ed28, Func Offset: 0x178
	// Line 97, Address: 0x12ed30, Func Offset: 0x180
	// Line 98, Address: 0x12ed38, Func Offset: 0x188
	// Line 99, Address: 0x12ed40, Func Offset: 0x190
	// Line 100, Address: 0x12ed4c, Func Offset: 0x19c
	// Line 101, Address: 0x12ed64, Func Offset: 0x1b4
	// Line 102, Address: 0x12ed6c, Func Offset: 0x1bc
	// Line 103, Address: 0x12ed80, Func Offset: 0x1d0
	// Line 104, Address: 0x12ed90, Func Offset: 0x1e0
	// Line 105, Address: 0x12ed98, Func Offset: 0x1e8
	// Line 107, Address: 0x12eda0, Func Offset: 0x1f0
	// Line 108, Address: 0x12edac, Func Offset: 0x1fc
	// Line 111, Address: 0x12edb4, Func Offset: 0x204
	// Line 112, Address: 0x12eddc, Func Offset: 0x22c
	// Line 114, Address: 0x12ee04, Func Offset: 0x254
	// Line 115, Address: 0x12ee18, Func Offset: 0x268
	// Line 116, Address: 0x12ee38, Func Offset: 0x288
	// Line 117, Address: 0x12ee48, Func Offset: 0x298
	// Line 118, Address: 0x12ee50, Func Offset: 0x2a0
	// Line 119, Address: 0x12ee58, Func Offset: 0x2a8
	// Line 120, Address: 0x12ee60, Func Offset: 0x2b0
	// Line 121, Address: 0x12ee6c, Func Offset: 0x2bc
	// Line 122, Address: 0x12ee84, Func Offset: 0x2d4
	// Line 123, Address: 0x12ee8c, Func Offset: 0x2dc
	// Line 124, Address: 0x12eea0, Func Offset: 0x2f0
	// Line 125, Address: 0x12eeb0, Func Offset: 0x300
	// Line 126, Address: 0x12eeb8, Func Offset: 0x308
	// Line 129, Address: 0x12eec0, Func Offset: 0x310
	// Line 131, Address: 0x12eec8, Func Offset: 0x318
	// Line 134, Address: 0x12eed8, Func Offset: 0x328
	// Func End, Address: 0x12eef8, Func Offset: 0x348
	scePrintf("bhPutModel - UNIMPLEMENTED!\n");
}

// 100% matching!
void DrawTreeBsc(NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        njMultiMatrix(NULL, &owP->mtx);
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8))) 
        {
            njDrawModel((NJS_MODEL*)objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
void EasyMultiDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkEasyMultiDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

/*// 
// Start address: 0x12f070
void SimpleMultiDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num)
{
	// Line 189, Address: 0x12f070, Func Offset: 0
	// Line 191, Address: 0x12f094, Func Offset: 0x24
	// Line 192, Address: 0x12f09c, Func Offset: 0x2c
	// Line 193, Address: 0x12f0a8, Func Offset: 0x38
	// Line 194, Address: 0x12f0bc, Func Offset: 0x4c
	// Line 196, Address: 0x12f0d0, Func Offset: 0x60
	// Line 197, Address: 0x12f0e4, Func Offset: 0x74
	// Line 198, Address: 0x12f0e8, Func Offset: 0x78
	// Line 199, Address: 0x12f104, Func Offset: 0x94
	// Line 200, Address: 0x12f110, Func Offset: 0xa0
	// Line 201, Address: 0x12f118, Func Offset: 0xa8
	// Line 203, Address: 0x12f128, Func Offset: 0xb8
	// Func End, Address: 0x12f144, Func Offset: 0xd4
}*/

// 100% matching! 
void EasyDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkEasyDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
void SimpleDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkSimpleDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
void bhCalcModel(BH_PWORK* ewP) 
{
    if ((ewP->flg & 0x80))
    {
        njSetMatrix(ewP->mtx, &((BH_PWORK*)ewP->lkwkp)->mlwP->owP[ewP->lkono].mtx);
        
        njTranslate(ewP->mtx, ewP->lox, ewP->loy, ewP->loz);
        
        if ((ewP->flg & 0x1000)) 
        {
            njUnitRotPortion(ewP->mtx);
        }
        
        njRotateXYZ(ewP->mtx, ewP->ax, ewP->ay, ewP->az);
    }
    else if (!(ewP->flg & 0x1000))
    {
        njUnitMatrix(ewP->mtx);
        
        njTranslate(ewP->mtx, ewP->px, ewP->py, ewP->pz);
        
        njRotateXYZ(ewP->mtx, ewP->ax, ewP->ay, ewP->az);
    }
    
    bhCalcTree(ewP->mtx, ewP->mlwP);
}

// 
// Start address: 0x12f400
void bhCalcTree(NJS_MATRIX* basP, ML_WORK* mlwP)
{
	int obj_num;
	//npobj* objP;
	//_anon10* owP;
	// Line 286, Address: 0x12f400, Func Offset: 0
	// Line 287, Address: 0x12f418, Func Offset: 0x18
	// Line 288, Address: 0x12f41c, Func Offset: 0x1c
	// Line 291, Address: 0x12f424, Func Offset: 0x24
	// Line 293, Address: 0x12f42c, Func Offset: 0x2c
	// Line 295, Address: 0x12f43c, Func Offset: 0x3c
	// Line 297, Address: 0x12f448, Func Offset: 0x48
	// Line 299, Address: 0x12f460, Func Offset: 0x60
	// Line 300, Address: 0x12f474, Func Offset: 0x74
	// Line 301, Address: 0x12f488, Func Offset: 0x88
	// Line 302, Address: 0x12f4a8, Func Offset: 0xa8
	// Line 304, Address: 0x12f4b8, Func Offset: 0xb8
	// Line 305, Address: 0x12f4d0, Func Offset: 0xd0
	// Line 307, Address: 0x12f4e0, Func Offset: 0xe0
	// Line 309, Address: 0x12f4e8, Func Offset: 0xe8
	// Func End, Address: 0x12f504, Func Offset: 0x104
	scePrintf("bhCalcTree - UNIMPLEMENTED!\n");
}
