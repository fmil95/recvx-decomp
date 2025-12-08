#include "itemview.h"
#include "njplus.h"

/*unsigned char(*actionprg)(_anon5*)[3];
unsigned int* wp_;
unsigned char flg[3];
int ang_00[3];
int ang_01[3];
int ang_02[3];
_anon32 vec_00;
float check[16];
float testf;*/
NJS_VECTOR whd;
/*unsigned int ItemViewTypeTbl[168];
int ViewType;
_anon33 fvwork;*/
STCAM_WRK st_cam;
/*_anon6 dsptbl[0];
_anon2 swork;
_anon24* sys;
_anon5 sitem;
_anon32 hoseipos[0];
unsigned char itemflg[8][0];
unsigned short getmestbl[0];
_anon23 itemdata[0];
unsigned short mestbl[0];
short c_a[6][0];
_anon41 parts_10b[0];
unsigned short idsettbl[0];

// 
// Start address: 0x2a9870
void DrawSubItem(_anon2* st, _anon5* si)
{
	_anon32 pos00;
	_anon6* dw_a;
	_anon33* fv;
	_anon1* sc;
	float testtest[16];
	// Line 173, Address: 0x2a9870, Func Offset: 0
	// Line 184, Address: 0x2a988c, Func Offset: 0x1c
	// Line 187, Address: 0x2a9894, Func Offset: 0x24
	// Line 185, Address: 0x2a9898, Func Offset: 0x28
	// Line 187, Address: 0x2a98a0, Func Offset: 0x30
	// Line 213, Address: 0x2a98b8, Func Offset: 0x48
	// Line 214, Address: 0x2a98c0, Func Offset: 0x50
	// Line 216, Address: 0x2a98d0, Func Offset: 0x60
	// Line 218, Address: 0x2a98d8, Func Offset: 0x68
	// Line 221, Address: 0x2a9910, Func Offset: 0xa0
	// Line 222, Address: 0x2a9918, Func Offset: 0xa8
	// Line 223, Address: 0x2a994c, Func Offset: 0xdc
	// Line 224, Address: 0x2a9980, Func Offset: 0x110
	// Line 225, Address: 0x2a99b4, Func Offset: 0x144
	// Line 227, Address: 0x2a99bc, Func Offset: 0x14c
	// Line 228, Address: 0x2a99c8, Func Offset: 0x158
	// Line 229, Address: 0x2a99d4, Func Offset: 0x164
	// Line 230, Address: 0x2a99e0, Func Offset: 0x170
	// Line 232, Address: 0x2a99e8, Func Offset: 0x178
	// Line 234, Address: 0x2a99f0, Func Offset: 0x180
	// Line 235, Address: 0x2a9a00, Func Offset: 0x190
	// Line 236, Address: 0x2a9a0c, Func Offset: 0x19c
	// Line 237, Address: 0x2a9a18, Func Offset: 0x1a8
	// Line 238, Address: 0x2a9a24, Func Offset: 0x1b4
	// Line 239, Address: 0x2a9a38, Func Offset: 0x1c8
	// Line 240, Address: 0x2a9a44, Func Offset: 0x1d4
	// Line 241, Address: 0x2a9a50, Func Offset: 0x1e0
	// Line 242, Address: 0x2a9a5c, Func Offset: 0x1ec
	// Line 243, Address: 0x2a9a64, Func Offset: 0x1f4
	// Line 244, Address: 0x2a9a70, Func Offset: 0x200
	// Line 245, Address: 0x2a9a7c, Func Offset: 0x20c
	// Line 249, Address: 0x2a9a88, Func Offset: 0x218
	// Line 250, Address: 0x2a9a94, Func Offset: 0x224
	// Line 251, Address: 0x2a9a9c, Func Offset: 0x22c
	// Line 252, Address: 0x2a9aa8, Func Offset: 0x238
	// Line 254, Address: 0x2a9ab0, Func Offset: 0x240
	// Line 255, Address: 0x2a9aec, Func Offset: 0x27c
	// Line 256, Address: 0x2a9b24, Func Offset: 0x2b4
	// Line 258, Address: 0x2a9b60, Func Offset: 0x2f0
	// Line 259, Address: 0x2a9b6c, Func Offset: 0x2fc
	// Line 260, Address: 0x2a9b78, Func Offset: 0x308
	// Line 262, Address: 0x2a9b84, Func Offset: 0x314
	// Line 272, Address: 0x2a9b8c, Func Offset: 0x31c
	// Line 262, Address: 0x2a9b94, Func Offset: 0x324
	// Line 263, Address: 0x2a9bb8, Func Offset: 0x348
	// Line 264, Address: 0x2a9be4, Func Offset: 0x374
	// Line 272, Address: 0x2a9c0c, Func Offset: 0x39c
	// Line 273, Address: 0x2a9c30, Func Offset: 0x3c0
	// Line 274, Address: 0x2a9c58, Func Offset: 0x3e8
	// Line 276, Address: 0x2a9c80, Func Offset: 0x410
	// Line 280, Address: 0x2a9c88, Func Offset: 0x418
	// Line 276, Address: 0x2a9c8c, Func Offset: 0x41c
	// Line 277, Address: 0x2a9cb0, Func Offset: 0x440
	// Line 278, Address: 0x2a9cdc, Func Offset: 0x46c
	// Line 280, Address: 0x2a9d04, Func Offset: 0x494
	// Line 282, Address: 0x2a9d0c, Func Offset: 0x49c
	// Line 283, Address: 0x2a9d20, Func Offset: 0x4b0
	// Line 285, Address: 0x2a9d2c, Func Offset: 0x4bc
	// Line 286, Address: 0x2a9d34, Func Offset: 0x4c4
	// Line 287, Address: 0x2a9d3c, Func Offset: 0x4cc
	// Line 288, Address: 0x2a9d44, Func Offset: 0x4d4
	// Line 300, Address: 0x2a9d4c, Func Offset: 0x4dc
	// Line 301, Address: 0x2a9d54, Func Offset: 0x4e4
	// Line 302, Address: 0x2a9d6c, Func Offset: 0x4fc
	// Line 303, Address: 0x2a9d84, Func Offset: 0x514
	// Line 304, Address: 0x2a9da0, Func Offset: 0x530
	// Line 305, Address: 0x2a9db8, Func Offset: 0x548
	// Line 307, Address: 0x2a9dc0, Func Offset: 0x550
	// Line 309, Address: 0x2a9dc8, Func Offset: 0x558
	// Line 310, Address: 0x2a9dd0, Func Offset: 0x560
	// Line 312, Address: 0x2a9ddc, Func Offset: 0x56c
	// Line 313, Address: 0x2a9de8, Func Offset: 0x578
	// Line 314, Address: 0x2a9df4, Func Offset: 0x584
	// Line 316, Address: 0x2a9e00, Func Offset: 0x590
	// Line 317, Address: 0x2a9e08, Func Offset: 0x598
	// Line 318, Address: 0x2a9e1c, Func Offset: 0x5ac
	// Line 319, Address: 0x2a9e2c, Func Offset: 0x5bc
	// Line 320, Address: 0x2a9e48, Func Offset: 0x5d8
	// Line 321, Address: 0x2a9e50, Func Offset: 0x5e0
	// Line 323, Address: 0x2a9e68, Func Offset: 0x5f8
	// Line 325, Address: 0x2a9e74, Func Offset: 0x604
	// Line 326, Address: 0x2a9e84, Func Offset: 0x614
	// Line 327, Address: 0x2a9e8c, Func Offset: 0x61c
	// Line 328, Address: 0x2a9eac, Func Offset: 0x63c
	// Line 329, Address: 0x2a9eb8, Func Offset: 0x648
	// Line 330, Address: 0x2a9ec0, Func Offset: 0x650
	// Line 331, Address: 0x2a9ed4, Func Offset: 0x664
	// Line 332, Address: 0x2a9ee8, Func Offset: 0x678
	// Line 333, Address: 0x2a9efc, Func Offset: 0x68c
	// Line 334, Address: 0x2a9f14, Func Offset: 0x6a4
	// Line 335, Address: 0x2a9f1c, Func Offset: 0x6ac
	// Line 336, Address: 0x2a9f30, Func Offset: 0x6c0
	// Line 337, Address: 0x2a9f3c, Func Offset: 0x6cc
	// Line 343, Address: 0x2a9f48, Func Offset: 0x6d8
	// Line 345, Address: 0x2a9f58, Func Offset: 0x6e8
	// Line 347, Address: 0x2a9f68, Func Offset: 0x6f8
	// Line 349, Address: 0x2a9f74, Func Offset: 0x704
	// Line 350, Address: 0x2a9f7c, Func Offset: 0x70c
	// Line 351, Address: 0x2a9fa0, Func Offset: 0x730
	// Line 352, Address: 0x2a9fac, Func Offset: 0x73c
	// Line 353, Address: 0x2a9fb4, Func Offset: 0x744
	// Line 354, Address: 0x2a9fcc, Func Offset: 0x75c
	// Line 355, Address: 0x2a9fe4, Func Offset: 0x774
	// Line 356, Address: 0x2a9ffc, Func Offset: 0x78c
	// Line 359, Address: 0x2aa018, Func Offset: 0x7a8
	// Line 360, Address: 0x2aa020, Func Offset: 0x7b0
	// Line 361, Address: 0x2aa034, Func Offset: 0x7c4
	// Line 362, Address: 0x2aa044, Func Offset: 0x7d4
	// Line 369, Address: 0x2aa050, Func Offset: 0x7e0
	// Line 372, Address: 0x2aa064, Func Offset: 0x7f4
	// Line 375, Address: 0x2aa078, Func Offset: 0x808
	// Line 377, Address: 0x2aa084, Func Offset: 0x814
	// Line 378, Address: 0x2aa08c, Func Offset: 0x81c
	// Line 379, Address: 0x2aa0b0, Func Offset: 0x840
	// Line 380, Address: 0x2aa0bc, Func Offset: 0x84c
	// Line 381, Address: 0x2aa0c4, Func Offset: 0x854
	// Line 382, Address: 0x2aa0e0, Func Offset: 0x870
	// Line 383, Address: 0x2aa0fc, Func Offset: 0x88c
	// Line 384, Address: 0x2aa118, Func Offset: 0x8a8
	// Line 387, Address: 0x2aa138, Func Offset: 0x8c8
	// Line 388, Address: 0x2aa140, Func Offset: 0x8d0
	// Line 389, Address: 0x2aa154, Func Offset: 0x8e4
	// Line 390, Address: 0x2aa164, Func Offset: 0x8f4
	// Line 398, Address: 0x2aa170, Func Offset: 0x900
	// Line 401, Address: 0x2aa188, Func Offset: 0x918
	// Line 404, Address: 0x2aa1a0, Func Offset: 0x930
	// Line 406, Address: 0x2aa1ac, Func Offset: 0x93c
	// Line 409, Address: 0x2aa1b4, Func Offset: 0x944
	// Line 423, Address: 0x2aa1d4, Func Offset: 0x964
	// Line 425, Address: 0x2aa1dc, Func Offset: 0x96c
	// Line 428, Address: 0x2aa204, Func Offset: 0x994
	// Line 429, Address: 0x2aa22c, Func Offset: 0x9bc
	// Line 430, Address: 0x2aa234, Func Offset: 0x9c4
	// Line 431, Address: 0x2aa23c, Func Offset: 0x9cc
	// Line 435, Address: 0x2aa244, Func Offset: 0x9d4
	// Line 436, Address: 0x2aa250, Func Offset: 0x9e0
	// Line 437, Address: 0x2aa258, Func Offset: 0x9e8
	// Line 440, Address: 0x2aa260, Func Offset: 0x9f0
	// Func End, Address: 0x2aa280, Func Offset: 0xa10
}

// 
// Start address: 0x2aa280
void Model_Read_Start()
{
	_anon5* si;
	// Line 448, Address: 0x2aa280, Func Offset: 0
	// Line 444, Address: 0x2aa288, Func Offset: 0x8
	// Line 448, Address: 0x2aa28c, Func Offset: 0xc
	// Line 450, Address: 0x2aa298, Func Offset: 0x18
	// Line 453, Address: 0x2aa2a4, Func Offset: 0x24
	// Line 450, Address: 0x2aa2a8, Func Offset: 0x28
	// Line 451, Address: 0x2aa2b4, Func Offset: 0x34
	// Line 452, Address: 0x2aa2cc, Func Offset: 0x4c
	// Line 453, Address: 0x2aa2e0, Func Offset: 0x60
	// Line 454, Address: 0x2aa2f8, Func Offset: 0x78
	// Line 455, Address: 0x2aa304, Func Offset: 0x84
	// Line 458, Address: 0x2aa310, Func Offset: 0x90
	// Line 459, Address: 0x2aa32c, Func Offset: 0xac
	// Line 460, Address: 0x2aa33c, Func Offset: 0xbc
	// Line 461, Address: 0x2aa344, Func Offset: 0xc4
	// Line 462, Address: 0x2aa35c, Func Offset: 0xdc
	// Line 463, Address: 0x2aa374, Func Offset: 0xf4
	// Line 464, Address: 0x2aa394, Func Offset: 0x114
	// Line 467, Address: 0x2aa3a8, Func Offset: 0x128
	// Func End, Address: 0x2aa3b0, Func Offset: 0x130
}

// 
// Start address: 0x2aa3b0
void Model_Read_Set(_anon2* st)
{
	_anon6* dw;
	_anon5* si;
	// Line 471, Address: 0x2aa3b0, Func Offset: 0
	// Line 472, Address: 0x2aa3c4, Func Offset: 0x14
	// Line 478, Address: 0x2aa3cc, Func Offset: 0x1c
	// Line 480, Address: 0x2aa3e0, Func Offset: 0x30
	// Line 481, Address: 0x2aa3ec, Func Offset: 0x3c
	// Line 482, Address: 0x2aa3fc, Func Offset: 0x4c
	// Line 484, Address: 0x2aa40c, Func Offset: 0x5c
	// Line 485, Address: 0x2aa418, Func Offset: 0x68
	// Line 484, Address: 0x2aa41c, Func Offset: 0x6c
	// Line 485, Address: 0x2aa428, Func Offset: 0x78
	// Line 486, Address: 0x2aa438, Func Offset: 0x88
	// Line 487, Address: 0x2aa440, Func Offset: 0x90
	// Line 489, Address: 0x2aa444, Func Offset: 0x94
	// Line 490, Address: 0x2aa454, Func Offset: 0xa4
	// Line 494, Address: 0x2aa458, Func Offset: 0xa8
	// Line 497, Address: 0x2aa460, Func Offset: 0xb0
	// Line 494, Address: 0x2aa464, Func Offset: 0xb4
	// Line 497, Address: 0x2aa46c, Func Offset: 0xbc
	// Line 499, Address: 0x2aa474, Func Offset: 0xc4
	// Line 501, Address: 0x2aa488, Func Offset: 0xd8
	// Line 502, Address: 0x2aa4a8, Func Offset: 0xf8
	// Line 505, Address: 0x2aa4c4, Func Offset: 0x114
	// Line 509, Address: 0x2aa4ec, Func Offset: 0x13c
	// Line 510, Address: 0x2aa520, Func Offset: 0x170
	// Line 509, Address: 0x2aa52c, Func Offset: 0x17c
	// Line 510, Address: 0x2aa530, Func Offset: 0x180
	// Line 511, Address: 0x2aa534, Func Offset: 0x184
	// Line 510, Address: 0x2aa540, Func Offset: 0x190
	// Line 511, Address: 0x2aa544, Func Offset: 0x194
	// Line 514, Address: 0x2aa54c, Func Offset: 0x19c
	// Line 515, Address: 0x2aa550, Func Offset: 0x1a0
	// Line 516, Address: 0x2aa554, Func Offset: 0x1a4
	// Line 520, Address: 0x2aa558, Func Offset: 0x1a8
	// Line 521, Address: 0x2aa568, Func Offset: 0x1b8
	// Line 522, Address: 0x2aa580, Func Offset: 0x1d0
	// Line 523, Address: 0x2aa58c, Func Offset: 0x1dc
	// Line 524, Address: 0x2aa598, Func Offset: 0x1e8
	// Line 525, Address: 0x2aa5a0, Func Offset: 0x1f0
	// Line 523, Address: 0x2aa5a4, Func Offset: 0x1f4
	// Line 524, Address: 0x2aa5b0, Func Offset: 0x200
	// Line 525, Address: 0x2aa5c4, Func Offset: 0x214
	// Line 527, Address: 0x2aa5d4, Func Offset: 0x224
	// Line 528, Address: 0x2aa5dc, Func Offset: 0x22c
	// Line 529, Address: 0x2aa600, Func Offset: 0x250
	// Line 530, Address: 0x2aa60c, Func Offset: 0x25c
	// Line 531, Address: 0x2aa61c, Func Offset: 0x26c
	// Line 532, Address: 0x2aa620, Func Offset: 0x270
	// Line 530, Address: 0x2aa624, Func Offset: 0x274
	// Line 531, Address: 0x2aa630, Func Offset: 0x280
	// Line 533, Address: 0x2aa638, Func Offset: 0x288
	// Line 531, Address: 0x2aa640, Func Offset: 0x290
	// Line 532, Address: 0x2aa64c, Func Offset: 0x29c
	// Line 533, Address: 0x2aa660, Func Offset: 0x2b0
	// Line 536, Address: 0x2aa674, Func Offset: 0x2c4
	// Func End, Address: 0x2aa68c, Func Offset: 0x2dc
}*/

// 100% matching!
void CameraInit()
{
    njUnitMatrix(&st_cam.cmat1);
    njUnitMatrix(&st_cam.rotmat);
    
    st_cam.dis = 20;
    
    st_cam.pos_0.x = 0;
    st_cam.pos_0.y = 0;
    st_cam.pos_0.z = 12;
    
    st_cam.pos_1.x = 0;
    st_cam.pos_1.y = 0;
    st_cam.pos_1.z = 0;
    
    st_cam.ax = 0;
    st_cam.ay = 0;
    st_cam.az = 0;
    
    st_cam.cax = 0;
    st_cam.cay = 0;
    st_cam.caz = 0;
}

// 99.64% matching
void CameraSet()
{
    njClearMatrix();
    
    njUnitMatrix(NULL);
    
    njTranslate(NULL, st_cam.pos_0.x, st_cam.pos_0.y, -st_cam.pos_0.z + st_cam.pos_1.z);
    
    njRotateX(NULL, st_cam.ax);
    njRotateY(NULL, st_cam.ay);
    njRotateZ(NULL, st_cam.az);
    
    njTranslate(NULL, 0, 0, st_cam.dis);
    
    njGetMatrix(&st_cam.cmat1);
}

/*// 
// Start address: 0x2aa7e0
void ItemView()
{
	_anon2* st;
	// Line 576, Address: 0x2aa7e0, Func Offset: 0
	// Line 585, Address: 0x2aa7e8, Func Offset: 0x8
	// Line 577, Address: 0x2aa7ec, Func Offset: 0xc
	// Line 585, Address: 0x2aa7f4, Func Offset: 0x14
	// Line 586, Address: 0x2aa804, Func Offset: 0x24
	// Line 588, Address: 0x2aa808, Func Offset: 0x28
	// Line 590, Address: 0x2aa834, Func Offset: 0x54
	// Line 591, Address: 0x2aa844, Func Offset: 0x64
	// Line 592, Address: 0x2aa848, Func Offset: 0x68
	// Line 593, Address: 0x2aa850, Func Offset: 0x70
	// Line 595, Address: 0x2aa854, Func Offset: 0x74
	// Line 597, Address: 0x2aa85c, Func Offset: 0x7c
	// Line 598, Address: 0x2aa864, Func Offset: 0x84
	// Line 600, Address: 0x2aa86c, Func Offset: 0x8c
	// Line 601, Address: 0x2aa874, Func Offset: 0x94
	// Line 605, Address: 0x2aa87c, Func Offset: 0x9c
	// Line 606, Address: 0x2aa884, Func Offset: 0xa4
	// Line 608, Address: 0x2aa88c, Func Offset: 0xac
	// Line 609, Address: 0x2aa894, Func Offset: 0xb4
	// Line 611, Address: 0x2aa89c, Func Offset: 0xbc
	// Line 612, Address: 0x2aa8a4, Func Offset: 0xc4
	// Line 614, Address: 0x2aa8ac, Func Offset: 0xcc
	// Line 615, Address: 0x2aa8c4, Func Offset: 0xe4
	// Line 616, Address: 0x2aa8c8, Func Offset: 0xe8
	// Line 617, Address: 0x2aa8d0, Func Offset: 0xf0
	// Line 618, Address: 0x2aa8d8, Func Offset: 0xf8
	// Line 620, Address: 0x2aa8e0, Func Offset: 0x100
	// Line 622, Address: 0x2aa8e8, Func Offset: 0x108
	// Line 623, Address: 0x2aa8f0, Func Offset: 0x110
	// Line 625, Address: 0x2aa8f8, Func Offset: 0x118
	// Line 628, Address: 0x2aa900, Func Offset: 0x120
	// Func End, Address: 0x2aa90c, Func Offset: 0x12c
}

// 
// Start address: 0x2aa910
void ItemModelChangeZoomIn()
{
	_anon1* sc;
	_anon2* st;
	// Line 630, Address: 0x2aa910, Func Offset: 0
	// Line 638, Address: 0x2aa91c, Func Offset: 0xc
	// Line 631, Address: 0x2aa924, Func Offset: 0x14
	// Line 633, Address: 0x2aa92c, Func Offset: 0x1c
	// Line 639, Address: 0x2aa934, Func Offset: 0x24
	// Line 638, Address: 0x2aa93c, Func Offset: 0x2c
	// Line 640, Address: 0x2aa950, Func Offset: 0x40
	// Line 639, Address: 0x2aa958, Func Offset: 0x48
	// Line 638, Address: 0x2aa964, Func Offset: 0x54
	// Line 640, Address: 0x2aa96c, Func Offset: 0x5c
	// Line 642, Address: 0x2aa970, Func Offset: 0x60
	// Line 640, Address: 0x2aa978, Func Offset: 0x68
	// Line 641, Address: 0x2aa980, Func Offset: 0x70
	// Line 642, Address: 0x2aa990, Func Offset: 0x80
	// Line 643, Address: 0x2aa998, Func Offset: 0x88
	// Line 645, Address: 0x2aa99c, Func Offset: 0x8c
	// Line 644, Address: 0x2aa9a0, Func Offset: 0x90
	// Line 645, Address: 0x2aa9a4, Func Offset: 0x94
	// Line 647, Address: 0x2aa9a8, Func Offset: 0x98
	// Line 649, Address: 0x2aa9b8, Func Offset: 0xa8
	// Line 647, Address: 0x2aa9bc, Func Offset: 0xac
	// Line 649, Address: 0x2aa9d8, Func Offset: 0xc8
	// Line 647, Address: 0x2aa9dc, Func Offset: 0xcc
	// Line 649, Address: 0x2aa9e4, Func Offset: 0xd4
	// Line 652, Address: 0x2aa9fc, Func Offset: 0xec
	// Line 654, Address: 0x2aaa14, Func Offset: 0x104
	// Func End, Address: 0x2aaa24, Func Offset: 0x114
}

// 
// Start address: 0x2aaa30
void ItemModelCheck()
{
	unsigned char chkcode;
	unsigned char y;
	unsigned char x;
	unsigned short mesnum;
	short* d_a;
	unsigned int* wp;
	int c01;
	int c00;
	_anon6* dw;
	_anon1* sc;
	_anon5* si;
	_anon2* st;
	short at_ang;
	// Line 656, Address: 0x2aaa30, Func Offset: 0
	// Line 660, Address: 0x2aaa5c, Func Offset: 0x2c
	// Line 657, Address: 0x2aaa64, Func Offset: 0x34
	// Line 658, Address: 0x2aaa6c, Func Offset: 0x3c
	// Line 671, Address: 0x2aaa74, Func Offset: 0x44
	// Line 660, Address: 0x2aaa7c, Func Offset: 0x4c
	// Line 671, Address: 0x2aaa8c, Func Offset: 0x5c
	// Line 659, Address: 0x2aaa90, Func Offset: 0x60
	// Line 660, Address: 0x2aaa94, Func Offset: 0x64
	// Line 659, Address: 0x2aaa98, Func Offset: 0x68
	// Line 668, Address: 0x2aaa9c, Func Offset: 0x6c
	// Line 671, Address: 0x2aaaa0, Func Offset: 0x70
	// Line 672, Address: 0x2aaaac, Func Offset: 0x7c
	// Line 673, Address: 0x2aaac0, Func Offset: 0x90
	// Line 676, Address: 0x2aaad8, Func Offset: 0xa8
	// Line 677, Address: 0x2aaae8, Func Offset: 0xb8
	// Line 679, Address: 0x2aaaf8, Func Offset: 0xc8
	// Line 677, Address: 0x2aab08, Func Offset: 0xd8
	// Line 680, Address: 0x2aab14, Func Offset: 0xe4
	// Line 681, Address: 0x2aab1c, Func Offset: 0xec
	// Line 682, Address: 0x2aab24, Func Offset: 0xf4
	// Line 683, Address: 0x2aab2c, Func Offset: 0xfc
	// Line 684, Address: 0x2aab34, Func Offset: 0x104
	// Line 685, Address: 0x2aab3c, Func Offset: 0x10c
	// Line 686, Address: 0x2aab44, Func Offset: 0x114
	// Line 687, Address: 0x2aab4c, Func Offset: 0x11c
	// Line 688, Address: 0x2aab54, Func Offset: 0x124
	// Line 689, Address: 0x2aab5c, Func Offset: 0x12c
	// Line 690, Address: 0x2aab64, Func Offset: 0x134
	// Line 691, Address: 0x2aab6c, Func Offset: 0x13c
	// Line 692, Address: 0x2aab84, Func Offset: 0x154
	// Line 693, Address: 0x2aab8c, Func Offset: 0x15c
	// Line 694, Address: 0x2aab98, Func Offset: 0x168
	// Line 695, Address: 0x2aaba0, Func Offset: 0x170
	// Line 696, Address: 0x2aaba4, Func Offset: 0x174
	// Line 697, Address: 0x2aabb8, Func Offset: 0x188
	// Line 698, Address: 0x2aabc0, Func Offset: 0x190
	// Line 699, Address: 0x2aabcc, Func Offset: 0x19c
	// Line 700, Address: 0x2aabd4, Func Offset: 0x1a4
	// Line 701, Address: 0x2aabd8, Func Offset: 0x1a8
	// Line 702, Address: 0x2aabe0, Func Offset: 0x1b0
	// Line 705, Address: 0x2aabe4, Func Offset: 0x1b4
	// Line 706, Address: 0x2aac04, Func Offset: 0x1d4
	// Line 707, Address: 0x2aac0c, Func Offset: 0x1dc
	// Line 708, Address: 0x2aac18, Func Offset: 0x1e8
	// Line 709, Address: 0x2aac20, Func Offset: 0x1f0
	// Line 710, Address: 0x2aac24, Func Offset: 0x1f4
	// Line 711, Address: 0x2aac38, Func Offset: 0x208
	// Line 712, Address: 0x2aac40, Func Offset: 0x210
	// Line 713, Address: 0x2aac4c, Func Offset: 0x21c
	// Line 714, Address: 0x2aac54, Func Offset: 0x224
	// Line 715, Address: 0x2aac58, Func Offset: 0x228
	// Line 716, Address: 0x2aac60, Func Offset: 0x230
	// Line 719, Address: 0x2aac64, Func Offset: 0x234
	// Line 720, Address: 0x2aac84, Func Offset: 0x254
	// Line 721, Address: 0x2aac90, Func Offset: 0x260
	// Line 722, Address: 0x2aacb0, Func Offset: 0x280
	// Line 724, Address: 0x2aacc4, Func Offset: 0x294
	// Line 725, Address: 0x2aacd8, Func Offset: 0x2a8
	// Line 726, Address: 0x2aacf8, Func Offset: 0x2c8
	// Line 799, Address: 0x2aad0c, Func Offset: 0x2dc
	// Line 800, Address: 0x2aad14, Func Offset: 0x2e4
	// Line 801, Address: 0x2aad18, Func Offset: 0x2e8
	// Line 802, Address: 0x2aad1c, Func Offset: 0x2ec
	// Line 803, Address: 0x2aad20, Func Offset: 0x2f0
	// Line 804, Address: 0x2aad40, Func Offset: 0x310
	// Line 805, Address: 0x2aad48, Func Offset: 0x318
	// Line 807, Address: 0x2aad50, Func Offset: 0x320
	// Line 804, Address: 0x2aad58, Func Offset: 0x328
	// Line 805, Address: 0x2aad68, Func Offset: 0x338
	// Line 807, Address: 0x2aad7c, Func Offset: 0x34c
	// Line 808, Address: 0x2aad94, Func Offset: 0x364
	// Line 809, Address: 0x2aad98, Func Offset: 0x368
	// Line 810, Address: 0x2aada0, Func Offset: 0x370
	// Line 811, Address: 0x2aada8, Func Offset: 0x378
	// Line 812, Address: 0x2aadc4, Func Offset: 0x394
	// Line 813, Address: 0x2aadd4, Func Offset: 0x3a4
	// Line 815, Address: 0x2aade8, Func Offset: 0x3b8
	// Line 814, Address: 0x2aadec, Func Offset: 0x3bc
	// Line 815, Address: 0x2aadf4, Func Offset: 0x3c4
	// Line 816, Address: 0x2aae08, Func Offset: 0x3d8
	// Line 817, Address: 0x2aae30, Func Offset: 0x400
	// Line 820, Address: 0x2aae38, Func Offset: 0x408
	// Line 824, Address: 0x2aae70, Func Offset: 0x440
	// Line 826, Address: 0x2aae74, Func Offset: 0x444
	// Line 827, Address: 0x2aae84, Func Offset: 0x454
	// Line 829, Address: 0x2aae98, Func Offset: 0x468
	// Line 827, Address: 0x2aae9c, Func Offset: 0x46c
	// Line 829, Address: 0x2aaea0, Func Offset: 0x470
	// Line 830, Address: 0x2aaed4, Func Offset: 0x4a4
	// Line 832, Address: 0x2aaee4, Func Offset: 0x4b4
	// Line 833, Address: 0x2aaef4, Func Offset: 0x4c4
	// Line 834, Address: 0x2aaf00, Func Offset: 0x4d0
	// Line 835, Address: 0x2aaf08, Func Offset: 0x4d8
	// Line 838, Address: 0x2aaf14, Func Offset: 0x4e4
	// Line 839, Address: 0x2aaf1c, Func Offset: 0x4ec
	// Line 840, Address: 0x2aaf38, Func Offset: 0x508
	// Line 841, Address: 0x2aaf44, Func Offset: 0x514
	// Line 845, Address: 0x2aaf64, Func Offset: 0x534
	// Line 846, Address: 0x2aaf78, Func Offset: 0x548
	// Line 847, Address: 0x2aaf7c, Func Offset: 0x54c
	// Line 848, Address: 0x2aaf80, Func Offset: 0x550
	// Line 846, Address: 0x2aaf84, Func Offset: 0x554
	// Line 847, Address: 0x2aaf88, Func Offset: 0x558
	// Line 849, Address: 0x2aaf8c, Func Offset: 0x55c
	// Line 850, Address: 0x2aaf94, Func Offset: 0x564
	// Line 851, Address: 0x2aaf9c, Func Offset: 0x56c
	// Line 852, Address: 0x2aafa4, Func Offset: 0x574
	// Line 853, Address: 0x2aafb4, Func Offset: 0x584
	// Line 857, Address: 0x2aafb8, Func Offset: 0x588
	// Line 859, Address: 0x2aafc0, Func Offset: 0x590
	// Line 860, Address: 0x2aafcc, Func Offset: 0x59c
	// Line 861, Address: 0x2aafd4, Func Offset: 0x5a4
	// Line 862, Address: 0x2aafdc, Func Offset: 0x5ac
	// Line 863, Address: 0x2aaff8, Func Offset: 0x5c8
	// Line 864, Address: 0x2ab000, Func Offset: 0x5d0
	// Line 865, Address: 0x2ab008, Func Offset: 0x5d8
	// Line 869, Address: 0x2ab014, Func Offset: 0x5e4
	// Line 870, Address: 0x2ab028, Func Offset: 0x5f8
	// Line 871, Address: 0x2ab030, Func Offset: 0x600
	// Line 872, Address: 0x2ab034, Func Offset: 0x604
	// Line 873, Address: 0x2ab03c, Func Offset: 0x60c
	// Line 874, Address: 0x2ab040, Func Offset: 0x610
	// Line 875, Address: 0x2ab04c, Func Offset: 0x61c
	// Line 874, Address: 0x2ab050, Func Offset: 0x620
	// Line 875, Address: 0x2ab05c, Func Offset: 0x62c
	// Line 876, Address: 0x2ab068, Func Offset: 0x638
	// Line 877, Address: 0x2ab070, Func Offset: 0x640
	// Line 878, Address: 0x2ab078, Func Offset: 0x648
	// Line 883, Address: 0x2ab0a0, Func Offset: 0x670
	// Line 884, Address: 0x2ab0a8, Func Offset: 0x678
	// Line 885, Address: 0x2ab0ac, Func Offset: 0x67c
	// Line 886, Address: 0x2ab0b0, Func Offset: 0x680
	// Line 888, Address: 0x2ab0b4, Func Offset: 0x684
	// Func End, Address: 0x2ab0e4, Func Offset: 0x6b4
}

// 
// Start address: 0x2ab0f0
void ItemModelActionSet()
{
	_anon6* dw;
	_anon2* st;
	// Line 891, Address: 0x2ab0f0, Func Offset: 0
	// Line 895, Address: 0x2ab0fc, Func Offset: 0xc
	// Line 892, Address: 0x2ab104, Func Offset: 0x14
	// Line 895, Address: 0x2ab10c, Func Offset: 0x1c
	// Line 897, Address: 0x2ab114, Func Offset: 0x24
	// Line 895, Address: 0x2ab120, Func Offset: 0x30
	// Line 899, Address: 0x2ab128, Func Offset: 0x38
	// Line 897, Address: 0x2ab12c, Func Offset: 0x3c
	// Line 899, Address: 0x2ab138, Func Offset: 0x48
	// Line 900, Address: 0x2ab178, Func Offset: 0x88
	// Line 901, Address: 0x2ab180, Func Offset: 0x90
	// Line 903, Address: 0x2ab188, Func Offset: 0x98
	// Func End, Address: 0x2ab198, Func Offset: 0xa8
}

// 
// Start address: 0x2ab1a0
void ItemModelChangeZoomOut()
{
	int chkang;
	_anon6* dw;
	_anon5* si;
	_anon1* sc;
	_anon2* st;
	// Line 906, Address: 0x2ab1a0, Func Offset: 0
	// Line 915, Address: 0x2ab1b8, Func Offset: 0x18
	// Line 907, Address: 0x2ab1c0, Func Offset: 0x20
	// Line 908, Address: 0x2ab1c8, Func Offset: 0x28
	// Line 916, Address: 0x2ab1d0, Func Offset: 0x30
	// Line 909, Address: 0x2ab1d8, Func Offset: 0x38
	// Line 915, Address: 0x2ab1e0, Func Offset: 0x40
	// Line 918, Address: 0x2ab1e4, Func Offset: 0x44
	// Line 915, Address: 0x2ab1ec, Func Offset: 0x4c
	// Line 916, Address: 0x2ab1f4, Func Offset: 0x54
	// Line 918, Address: 0x2ab200, Func Offset: 0x60
	// Line 916, Address: 0x2ab204, Func Offset: 0x64
	// Line 918, Address: 0x2ab208, Func Offset: 0x68
	// Line 919, Address: 0x2ab210, Func Offset: 0x70
	// Line 921, Address: 0x2ab218, Func Offset: 0x78
	// Line 919, Address: 0x2ab220, Func Offset: 0x80
	// Line 916, Address: 0x2ab224, Func Offset: 0x84
	// Line 919, Address: 0x2ab22c, Func Offset: 0x8c
	// Line 921, Address: 0x2ab230, Func Offset: 0x90
	// Line 924, Address: 0x2ab238, Func Offset: 0x98
	// Line 927, Address: 0x2ab240, Func Offset: 0xa0
	// Line 924, Address: 0x2ab248, Func Offset: 0xa8
	// Line 927, Address: 0x2ab258, Func Offset: 0xb8
	// Line 928, Address: 0x2ab264, Func Offset: 0xc4
	// Line 927, Address: 0x2ab26c, Func Offset: 0xcc
	// Line 929, Address: 0x2ab278, Func Offset: 0xd8
	// Line 927, Address: 0x2ab280, Func Offset: 0xe0
	// Line 928, Address: 0x2ab290, Func Offset: 0xf0
	// Line 929, Address: 0x2ab2a4, Func Offset: 0x104
	// Line 932, Address: 0x2ab2b0, Func Offset: 0x110
	// Line 933, Address: 0x2ab2bc, Func Offset: 0x11c
	// Line 934, Address: 0x2ab2c4, Func Offset: 0x124
	// Line 936, Address: 0x2ab2d0, Func Offset: 0x130
	// Line 934, Address: 0x2ab2d8, Func Offset: 0x138
	// Line 936, Address: 0x2ab2e0, Func Offset: 0x140
	// Line 938, Address: 0x2ab300, Func Offset: 0x160
	// Line 939, Address: 0x2ab308, Func Offset: 0x168
	// Line 940, Address: 0x2ab328, Func Offset: 0x188
	// Line 939, Address: 0x2ab338, Func Offset: 0x198
	// Line 943, Address: 0x2ab34c, Func Offset: 0x1ac
	// Line 939, Address: 0x2ab350, Func Offset: 0x1b0
	// Line 940, Address: 0x2ab354, Func Offset: 0x1b4
	// Line 941, Address: 0x2ab358, Func Offset: 0x1b8
	// Line 940, Address: 0x2ab368, Func Offset: 0x1c8
	// Line 942, Address: 0x2ab374, Func Offset: 0x1d4
	// Line 940, Address: 0x2ab378, Func Offset: 0x1d8
	// Line 941, Address: 0x2ab390, Func Offset: 0x1f0
	// Line 943, Address: 0x2ab3b8, Func Offset: 0x218
	// Line 944, Address: 0x2ab3c0, Func Offset: 0x220
	// Line 946, Address: 0x2ab3c8, Func Offset: 0x228
	// Line 947, Address: 0x2ab3cc, Func Offset: 0x22c
	// Line 948, Address: 0x2ab3d0, Func Offset: 0x230
	// Line 949, Address: 0x2ab3d4, Func Offset: 0x234
	// Line 952, Address: 0x2ab3fc, Func Offset: 0x25c
	// Line 953, Address: 0x2ab400, Func Offset: 0x260
	// Line 954, Address: 0x2ab408, Func Offset: 0x268
	// Line 957, Address: 0x2ab410, Func Offset: 0x270
	// Line 958, Address: 0x2ab414, Func Offset: 0x274
	// Line 959, Address: 0x2ab418, Func Offset: 0x278
	// Line 960, Address: 0x2ab41c, Func Offset: 0x27c
	// Line 962, Address: 0x2ab428, Func Offset: 0x288
	// Func End, Address: 0x2ab444, Func Offset: 0x2a4
}

// 
// Start address: 0x2ab450
void ItemModelMessageWait()
{
	_anon6* dw;
	_anon2* st;
	// Line 966, Address: 0x2ab450, Func Offset: 0
	// Line 965, Address: 0x2ab45c, Func Offset: 0xc
	// Line 966, Address: 0x2ab460, Func Offset: 0x10
	// Line 968, Address: 0x2ab464, Func Offset: 0x14
	// Line 966, Address: 0x2ab46c, Func Offset: 0x1c
	// Line 968, Address: 0x2ab474, Func Offset: 0x24
	// Line 969, Address: 0x2ab494, Func Offset: 0x44
	// Line 970, Address: 0x2ab49c, Func Offset: 0x4c
	// Line 969, Address: 0x2ab4a4, Func Offset: 0x54
	// Line 970, Address: 0x2ab4ac, Func Offset: 0x5c
	// Line 971, Address: 0x2ab4b0, Func Offset: 0x60
	// Line 970, Address: 0x2ab4b4, Func Offset: 0x64
	// Line 971, Address: 0x2ab4b8, Func Offset: 0x68
	// Line 970, Address: 0x2ab4bc, Func Offset: 0x6c
	// Line 971, Address: 0x2ab4c4, Func Offset: 0x74
	// Line 973, Address: 0x2ab4f0, Func Offset: 0xa0
	// Line 975, Address: 0x2ab4f4, Func Offset: 0xa4
	// Line 973, Address: 0x2ab4fc, Func Offset: 0xac
	// Line 975, Address: 0x2ab500, Func Offset: 0xb0
	// Line 976, Address: 0x2ab518, Func Offset: 0xc8
	// Line 977, Address: 0x2ab51c, Func Offset: 0xcc
	// Line 978, Address: 0x2ab524, Func Offset: 0xd4
	// Line 979, Address: 0x2ab52c, Func Offset: 0xdc
	// Line 981, Address: 0x2ab530, Func Offset: 0xe0
	// Line 983, Address: 0x2ab538, Func Offset: 0xe8
	// Line 987, Address: 0x2ab540, Func Offset: 0xf0
	// Func End, Address: 0x2ab548, Func Offset: 0xf8
}

// 
// Start address: 0x2ab550
unsigned char MdlDirChk(short* dirang, short mdlang)
{
	// Line 994, Address: 0x2ab550, Func Offset: 0
	// Line 999, Address: 0x2ab55c, Func Offset: 0xc
	// Line 997, Address: 0x2ab560, Func Offset: 0x10
	// Line 999, Address: 0x2ab570, Func Offset: 0x20
	// Line 1005, Address: 0x2ab590, Func Offset: 0x40
	// Func End, Address: 0x2ab598, Func Offset: 0x48
}

// 
// Start address: 0x2ab5a0
unsigned char MdlAction00(_anon5* si)
{
	// Line 1009, Address: 0x2ab5a0, Func Offset: 0
	// Line 1011, Address: 0x2ab5dc, Func Offset: 0x3c
	// Line 1013, Address: 0x2ab5e0, Func Offset: 0x40
	// Line 1015, Address: 0x2ab5e8, Func Offset: 0x48
	// Line 1017, Address: 0x2ab5ec, Func Offset: 0x4c
	// Line 1015, Address: 0x2ab5f0, Func Offset: 0x50
	// Line 1016, Address: 0x2ab608, Func Offset: 0x68
	// Line 1017, Address: 0x2ab61c, Func Offset: 0x7c
	// Line 1018, Address: 0x2ab63c, Func Offset: 0x9c
	// Line 1020, Address: 0x2ab644, Func Offset: 0xa4
	// Line 1021, Address: 0x2ab668, Func Offset: 0xc8
	// Line 1022, Address: 0x2ab67c, Func Offset: 0xdc
	// Line 1026, Address: 0x2ab68c, Func Offset: 0xec
	// Line 1028, Address: 0x2ab694, Func Offset: 0xf4
	// Line 1030, Address: 0x2ab6a0, Func Offset: 0x100
	// Line 1032, Address: 0x2ab6a4, Func Offset: 0x104
	// Func End, Address: 0x2ab6ac, Func Offset: 0x10c
}

// 
// Start address: 0x2ab6b0
unsigned char MdlAction01(_anon5* si)
{
	// Line 1036, Address: 0x2ab6b0, Func Offset: 0
	// Line 1038, Address: 0x2ab6e0, Func Offset: 0x30
	// Line 1040, Address: 0x2ab6e8, Func Offset: 0x38
	// Line 1041, Address: 0x2ab6fc, Func Offset: 0x4c
	// Line 1043, Address: 0x2ab700, Func Offset: 0x50
	// Line 1041, Address: 0x2ab704, Func Offset: 0x54
	// Line 1042, Address: 0x2ab724, Func Offset: 0x74
	// Line 1043, Address: 0x2ab738, Func Offset: 0x88
	// Line 1044, Address: 0x2ab760, Func Offset: 0xb0
	// Line 1046, Address: 0x2ab768, Func Offset: 0xb8
	// Line 1047, Address: 0x2ab77c, Func Offset: 0xcc
	// Line 1049, Address: 0x2ab780, Func Offset: 0xd0
	// Line 1047, Address: 0x2ab784, Func Offset: 0xd4
	// Line 1048, Address: 0x2ab7a0, Func Offset: 0xf0
	// Line 1049, Address: 0x2ab7b4, Func Offset: 0x104
	// Line 1050, Address: 0x2ab7d8, Func Offset: 0x128
	// Line 1052, Address: 0x2ab7e0, Func Offset: 0x130
	// Line 1053, Address: 0x2ab7f4, Func Offset: 0x144
	// Line 1055, Address: 0x2ab7f8, Func Offset: 0x148
	// Line 1053, Address: 0x2ab7fc, Func Offset: 0x14c
	// Line 1054, Address: 0x2ab814, Func Offset: 0x164
	// Line 1055, Address: 0x2ab828, Func Offset: 0x178
	// Line 1056, Address: 0x2ab848, Func Offset: 0x198
	// Line 1058, Address: 0x2ab850, Func Offset: 0x1a0
	// Line 1059, Address: 0x2ab858, Func Offset: 0x1a8
	// Line 1061, Address: 0x2ab85c, Func Offset: 0x1ac
	// Line 1059, Address: 0x2ab860, Func Offset: 0x1b0
	// Line 1060, Address: 0x2ab878, Func Offset: 0x1c8
	// Line 1061, Address: 0x2ab88c, Func Offset: 0x1dc
	// Line 1062, Address: 0x2ab8ac, Func Offset: 0x1fc
	// Line 1065, Address: 0x2ab8b8, Func Offset: 0x208
	// Line 1066, Address: 0x2ab8dc, Func Offset: 0x22c
	// Line 1067, Address: 0x2ab8f0, Func Offset: 0x240
	// Line 1072, Address: 0x2ab900, Func Offset: 0x250
	// Line 1074, Address: 0x2ab908, Func Offset: 0x258
	// Line 1076, Address: 0x2ab914, Func Offset: 0x264
	// Line 1077, Address: 0x2ab918, Func Offset: 0x268
	// Func End, Address: 0x2ab920, Func Offset: 0x270
}

// 
// Start address: 0x2ab920
unsigned char MdlAction02(_anon5* si)
{
	// Line 1081, Address: 0x2ab920, Func Offset: 0
	// Line 1083, Address: 0x2ab950, Func Offset: 0x30
	// Line 1085, Address: 0x2ab958, Func Offset: 0x38
	// Line 1087, Address: 0x2ab95c, Func Offset: 0x3c
	// Line 1085, Address: 0x2ab960, Func Offset: 0x40
	// Line 1086, Address: 0x2ab978, Func Offset: 0x58
	// Line 1087, Address: 0x2ab98c, Func Offset: 0x6c
	// Line 1088, Address: 0x2ab9ac, Func Offset: 0x8c
	// Line 1090, Address: 0x2ab9b8, Func Offset: 0x98
	// Line 1091, Address: 0x2ab9dc, Func Offset: 0xbc
	// Line 1092, Address: 0x2ab9f0, Func Offset: 0xd0
	// Line 1096, Address: 0x2aba00, Func Offset: 0xe0
	// Line 1098, Address: 0x2aba08, Func Offset: 0xe8
	// Line 1100, Address: 0x2aba14, Func Offset: 0xf4
	// Line 1101, Address: 0x2aba18, Func Offset: 0xf8
	// Func End, Address: 0x2aba20, Func Offset: 0x100
}

// 
// Start address: 0x2aba20
void MdlEvalflagsSet(unsigned short evalchk)
{
	// Line 1108, Address: 0x2aba20, Func Offset: 0
	// Func End, Address: 0x2aba48, Func Offset: 0x28
}

// 
// Start address: 0x2aba50
void MdlHideCheck(npobj* op, unsigned char el, unsigned char chk)
{
	// Line 1112, Address: 0x2aba50, Func Offset: 0
	// Line 1113, Address: 0x2aba68, Func Offset: 0x18
	// Line 1114, Address: 0x2aba80, Func Offset: 0x30
	// Line 1116, Address: 0x2aba84, Func Offset: 0x34
	// Line 1117, Address: 0x2aba90, Func Offset: 0x40
	// Line 1114, Address: 0x2aba98, Func Offset: 0x48
	// Line 1119, Address: 0x2aba9c, Func Offset: 0x4c
	// Line 1120, Address: 0x2ababc, Func Offset: 0x6c
	// Line 1121, Address: 0x2abadc, Func Offset: 0x8c
	// Line 1123, Address: 0x2abaec, Func Offset: 0x9c
	// Line 1122, Address: 0x2abaf0, Func Offset: 0xa0
	// Line 1123, Address: 0x2abaf4, Func Offset: 0xa4
	// Line 1124, Address: 0x2abb04, Func Offset: 0xb4
	// Line 1127, Address: 0x2abb1c, Func Offset: 0xcc
	// Func End, Address: 0x2abb34, Func Offset: 0xe4
}*/

// 100% matching!
float ModelScaleSet(SITEM* itemmodel, int flg)
{
    float scale00;

    if (flg != 0) 
    {
        itemmodel->mdl.objP->pos[2] = itemmodel->mdl.objP->pos[1] = itemmodel->mdl.objP->pos[0] = 0;

        itemmodel->mdl.objP->child->pos[2] = itemmodel->mdl.objP->child->pos[1] = itemmodel->mdl.objP->child->pos[0] = 0;
    }
    
    npGetWHDSize(itemmodel->mdl.objP, &whd);
    
    scale00 = njScalor(&whd);
   
    if ((itemmodel->mw.rdid != 1) && (itemmodel->mw.rdid != 2) && (itemmodel->mw.rdid != 3) && (itemmodel->mw.rdid != 4) && (itemmodel->mw.rdid != 6) && (itemmodel->mw.rdid != 10) && (itemmodel->mw.rdid != 11) && (itemmodel->mw.rdid != 103)) 
    {
        return 1.52f / scale00;
    }
    
    return 1.84f / scale00;
}

// 100% matching! 
void FlagErase(NJS_CNK_OBJECT* op) 
{
    op->evalflags &= ~0x2;
    op->evalflags &= ~0x1;
    
    if (op->child != NULL) 
    {
        FlagErase(op->child);
    }

    if (op->sibling != NULL) 
    {
        FlagErase(op->sibling);
    }
}

// 100% matching!
void LighterOpen(NJS_CNK_OBJECT* object) 
{
    object->ang[2] = 29127;
}

// 100% matching!
void FileSyu(NJS_CNK_OBJECT* op)
{
    op->ang[0] = 32768;
    op->ang[1] = 32768;
    
    op->sibling->ang[0] = 32768;
    op->sibling->sibling->ang[0] = 32768;
    
    op->sibling->ang[1] = 32768;
    op->sibling->sibling->ang[1] = 32768;
}

/*// 
// Start address: 0x2abd20
void MakeTag(unsigned short flg)
{
	float zpos;
	float ypos;
	int tagcol;
	int i;
	_anon38 p3c;
	_anon18 col[4];
	_anon32 p[4];
	_anon33* fv;
	_anon2* st;
	// Line 1254, Address: 0x2abd20, Func Offset: 0
	// Line 1256, Address: 0x2abd3c, Func Offset: 0x1c
	// Line 1258, Address: 0x2abd44, Func Offset: 0x24
	// Line 1254, Address: 0x2abd4c, Func Offset: 0x2c
	// Line 1275, Address: 0x2abd50, Func Offset: 0x30
	// Line 1254, Address: 0x2abd54, Func Offset: 0x34
	// Line 1277, Address: 0x2abd58, Func Offset: 0x38
	// Line 1275, Address: 0x2abd5c, Func Offset: 0x3c
	// Line 1277, Address: 0x2abd60, Func Offset: 0x40
	// Line 1275, Address: 0x2abd64, Func Offset: 0x44
	// Line 1278, Address: 0x2abd74, Func Offset: 0x54
	// Line 1277, Address: 0x2abd78, Func Offset: 0x58
	// Line 1278, Address: 0x2abd84, Func Offset: 0x64
	// Line 1279, Address: 0x2abd98, Func Offset: 0x78
	// Line 1282, Address: 0x2abdac, Func Offset: 0x8c
	// Line 1284, Address: 0x2abdb0, Func Offset: 0x90
	// Line 1285, Address: 0x2abdd4, Func Offset: 0xb4
	// Line 1286, Address: 0x2abde4, Func Offset: 0xc4
	// Line 1289, Address: 0x2abe04, Func Offset: 0xe4
	// Line 1290, Address: 0x2abe0c, Func Offset: 0xec
	// Line 1292, Address: 0x2abe10, Func Offset: 0xf0
	// Line 1293, Address: 0x2abe18, Func Offset: 0xf8
	// Line 1295, Address: 0x2abe20, Func Offset: 0x100
	// Line 1298, Address: 0x2abe54, Func Offset: 0x134
	// Line 1299, Address: 0x2abe5c, Func Offset: 0x13c
	// Line 1303, Address: 0x2abe60, Func Offset: 0x140
	// Line 1304, Address: 0x2abe68, Func Offset: 0x148
	// Line 1306, Address: 0x2abe70, Func Offset: 0x150
	// Line 1305, Address: 0x2abe74, Func Offset: 0x154
	// Line 1306, Address: 0x2abe78, Func Offset: 0x158
	// Line 1309, Address: 0x2abe7c, Func Offset: 0x15c
	// Line 1308, Address: 0x2abe80, Func Offset: 0x160
	// Line 1310, Address: 0x2abe84, Func Offset: 0x164
	// Line 1309, Address: 0x2abe88, Func Offset: 0x168
	// Line 1310, Address: 0x2abe8c, Func Offset: 0x16c
	// Line 1311, Address: 0x2abe90, Func Offset: 0x170
	// Line 1312, Address: 0x2abe94, Func Offset: 0x174
	// Line 1340, Address: 0x2abea0, Func Offset: 0x180
	// Line 1314, Address: 0x2abea4, Func Offset: 0x184
	// Line 1311, Address: 0x2abea8, Func Offset: 0x188
	// Line 1312, Address: 0x2abeac, Func Offset: 0x18c
	// Line 1314, Address: 0x2abeb0, Func Offset: 0x190
	// Line 1321, Address: 0x2abeb8, Func Offset: 0x198
	// Line 1312, Address: 0x2abebc, Func Offset: 0x19c
	// Line 1313, Address: 0x2abec4, Func Offset: 0x1a4
	// Line 1314, Address: 0x2abecc, Func Offset: 0x1ac
	// Line 1315, Address: 0x2abed8, Func Offset: 0x1b8
	// Line 1316, Address: 0x2abee4, Func Offset: 0x1c4
	// Line 1317, Address: 0x2abeec, Func Offset: 0x1cc
	// Line 1318, Address: 0x2abef8, Func Offset: 0x1d8
	// Line 1319, Address: 0x2abf00, Func Offset: 0x1e0
	// Line 1321, Address: 0x2abf04, Func Offset: 0x1e4
	// Line 1322, Address: 0x2abf08, Func Offset: 0x1e8
	// Line 1323, Address: 0x2abf0c, Func Offset: 0x1ec
	// Line 1324, Address: 0x2abf10, Func Offset: 0x1f0
	// Line 1326, Address: 0x2abf14, Func Offset: 0x1f4
	// Line 1327, Address: 0x2abf18, Func Offset: 0x1f8
	// Line 1328, Address: 0x2abf1c, Func Offset: 0x1fc
	// Line 1329, Address: 0x2abf20, Func Offset: 0x200
	// Line 1331, Address: 0x2abf24, Func Offset: 0x204
	// Line 1332, Address: 0x2abf28, Func Offset: 0x208
	// Line 1333, Address: 0x2abf2c, Func Offset: 0x20c
	// Line 1334, Address: 0x2abf30, Func Offset: 0x210
	// Line 1336, Address: 0x2abf34, Func Offset: 0x214
	// Line 1337, Address: 0x2abf38, Func Offset: 0x218
	// Line 1338, Address: 0x2abf3c, Func Offset: 0x21c
	// Line 1319, Address: 0x2abf40, Func Offset: 0x220
	// Line 1340, Address: 0x2abf44, Func Offset: 0x224
	// Line 1341, Address: 0x2abf4c, Func Offset: 0x22c
	// Line 1342, Address: 0x2abf5c, Func Offset: 0x23c
	// Line 1343, Address: 0x2abf64, Func Offset: 0x244
	// Line 1344, Address: 0x2abf68, Func Offset: 0x248
	// Line 1346, Address: 0x2abf74, Func Offset: 0x254
	// Line 1344, Address: 0x2abf78, Func Offset: 0x258
	// Line 1345, Address: 0x2abf7c, Func Offset: 0x25c
	// Line 1346, Address: 0x2abf88, Func Offset: 0x268
	// Line 1348, Address: 0x2abf94, Func Offset: 0x274
	// Func End, Address: 0x2abfbc, Func Offset: 0x29c
}*/
