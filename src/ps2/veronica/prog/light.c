#include "light.h"
#include "main.h"

/*_anon40 lgttab[5];
_anon26* sys;
_anon37 cam;
float fNaViwOffsetY;
float fNaViwOffsetX;
_anon0 eff[0];
BH_PWORK ene[0];
BH_PWORK* plp;

// 
// Start address: 0x280ed0
void bhInitLight()
{
	int i;
	_anon12* lp;
	// Line 75, Address: 0x280ed0, Func Offset: 0
	// Line 76, Address: 0x280ed8, Func Offset: 0x8
	// Line 75, Address: 0x280edc, Func Offset: 0xc
	// Line 76, Address: 0x280ee0, Func Offset: 0x10
	// Line 77, Address: 0x280ee8, Func Offset: 0x18
	// Line 78, Address: 0x280ef4, Func Offset: 0x24
	// Line 80, Address: 0x280f00, Func Offset: 0x30
	// Line 81, Address: 0x280f04, Func Offset: 0x34
	// Line 82, Address: 0x280f14, Func Offset: 0x44
	// Line 83, Address: 0x280f18, Func Offset: 0x48
	// Line 84, Address: 0x280f38, Func Offset: 0x68
	// Func End, Address: 0x280f40, Func Offset: 0x70
}*/

// 100% matching! 
void bhSetLightTab(NO_NAME_8* lt, int lno) 
{ 
    NO_NAME_8* lp;

    lp = &rom->lgtp[lno];

    lp->flg =  lt->flg;
    
    lp->type =  lt->type;
    
    lp->aspd =  lt->aspd;
    
    lp->lkflg =  lt->lkflg;
    
    lp->lkno = lt->lkno;
	lp->lkono = lt->lkono;
	
    lp->lsrc = lt->lsrc;
	
    lp->px = lt->px;
	lp->py = lt->py;
	lp->pz = lt->pz;
    
	lp->lx = lt->lx;
	lp->ly = lt->ly;
	lp->lz = lt->lz;
    
	lp->vx = lt->vx;
	lp->vy = lt->vy;
	lp->vz = lt->vz;
    
	lp->spc = lt->spc;
    
	lp->dif = lt->dif;
    
	lp->amb = lt->amb;
    
	lp->r = lt->r;
	lp->g = lt->g;
	lp->b = lt->b;
    
	lp->nr = lt->nr;
	lp->fr = lt->fr;
    
	lp->iang = lt->iang;
	lp->oang = lt-> oang;
    
	lp->ax = lt->ax;
	lp->ay = lt->ay;
	lp->az = lt->az;
    
    lp->mode = 0;
    
    lp->ct0 = lp->ct1 = lp->ct2 = lp->ct3 = 0;
    
    lp->wspc = lp->spc;
    
    lp->wdif = lp->dif;
    
    lp->wamb = lp->amb;
    
    lp->wr = lp->r;
    lp->wg = lp->g;
    lp->wb = lp->b;
    
    lp->wnr = lp->nr;
    lp->wfr = lp->fr;
    
    lp->wiang = lp->iang;
    lp->woang = lp->oang;
    
    lp->wax = lp->ax;
    lp->way = lp->ay;
    lp->waz = lp->az;
    
    lp->lkwkp =  NULL;
    
    lp->light = NULL;
    
    bhGetLightVector(lt->ax, lt->ay, lt->az, (NJS_VECTOR*)&lp->vx);
}

/*// 
// Start address: 0x2810e0
void bhSetEasyDirLight(float it)
{
	float fl;
	_anon12* lp;
	// Line 240, Address: 0x2810e0, Func Offset: 0
	// Line 245, Address: 0x2810f0, Func Offset: 0x10
	// Line 247, Address: 0x2810fc, Func Offset: 0x1c
	// Line 248, Address: 0x28110c, Func Offset: 0x2c
	// Line 250, Address: 0x281130, Func Offset: 0x50
	// Line 253, Address: 0x281150, Func Offset: 0x70
	// Line 252, Address: 0x281158, Func Offset: 0x78
	// Line 254, Address: 0x281160, Func Offset: 0x80
	// Line 256, Address: 0x281168, Func Offset: 0x88
	// Line 259, Address: 0x281170, Func Offset: 0x90
	// Line 261, Address: 0x281178, Func Offset: 0x98
	// Line 262, Address: 0x281188, Func Offset: 0xa8
	// Line 263, Address: 0x28119c, Func Offset: 0xbc
	// Line 264, Address: 0x2811ac, Func Offset: 0xcc
	// Line 271, Address: 0x2811bc, Func Offset: 0xdc
	// Line 272, Address: 0x2811d4, Func Offset: 0xf4
	// Line 273, Address: 0x2811e8, Func Offset: 0x108
	// Line 275, Address: 0x28120c, Func Offset: 0x12c
	// Line 276, Address: 0x281224, Func Offset: 0x144
	// Line 277, Address: 0x281238, Func Offset: 0x158
	// Line 278, Address: 0x28125c, Func Offset: 0x17c
	// Func End, Address: 0x281270, Func Offset: 0x190
}*/

// 
// Start address: 0x281270
void bhControlLight()
{
	float clp;
	//_anon32 lpos;
	//_anon4 npos;
	float fl;
	int dirf;
	int lct;
	int i;
	int lgt_n;
	float fr;
	float nr;
	float b;
	float g;
	float r;
	float vz;
	float vy;
	float vx;
	float pz;
	float py;
	float px;
	//_anon4 vec;
	//_anon17* ci;
	//_anon9* lptb;
	//_anon12* lp;
	BH_PWORK* pwp;
	// Line 284, Address: 0x281270, Func Offset: 0
	// Line 308, Address: 0x2812cc, Func Offset: 0x5c
	// Line 309, Address: 0x2812e0, Func Offset: 0x70
	// Line 310, Address: 0x2812e8, Func Offset: 0x78
	// Line 309, Address: 0x2812ec, Func Offset: 0x7c
	// Line 310, Address: 0x281304, Func Offset: 0x94
	// Line 311, Address: 0x281314, Func Offset: 0xa4
	// Line 312, Address: 0x28131c, Func Offset: 0xac
	// Line 313, Address: 0x281324, Func Offset: 0xb4
	// Line 312, Address: 0x28132c, Func Offset: 0xbc
	// Line 313, Address: 0x281344, Func Offset: 0xd4
	// Line 319, Address: 0x281358, Func Offset: 0xe8
	// Line 320, Address: 0x28136c, Func Offset: 0xfc
	// Line 321, Address: 0x281384, Func Offset: 0x114
	// Line 322, Address: 0x281394, Func Offset: 0x124
	// Line 327, Address: 0x28139c, Func Offset: 0x12c
	// Line 332, Address: 0x2813a8, Func Offset: 0x138
	// Line 328, Address: 0x2813ac, Func Offset: 0x13c
	// Line 330, Address: 0x2813b4, Func Offset: 0x144
	// Line 328, Address: 0x2813b8, Func Offset: 0x148
	// Line 332, Address: 0x281400, Func Offset: 0x190
	// Line 333, Address: 0x281428, Func Offset: 0x1b8
	// Line 334, Address: 0x28143c, Func Offset: 0x1cc
	// Line 335, Address: 0x281458, Func Offset: 0x1e8
	// Line 336, Address: 0x281478, Func Offset: 0x208
	// Line 337, Address: 0x281494, Func Offset: 0x224
	// Line 338, Address: 0x28149c, Func Offset: 0x22c
	// Line 339, Address: 0x2814ac, Func Offset: 0x23c
	// Line 340, Address: 0x2814b0, Func Offset: 0x240
	// Line 342, Address: 0x2814c0, Func Offset: 0x250
	// Line 343, Address: 0x2814cc, Func Offset: 0x25c
	// Line 356, Address: 0x2814dc, Func Offset: 0x26c
	// Line 345, Address: 0x2814e0, Func Offset: 0x270
	// Line 346, Address: 0x2814e4, Func Offset: 0x274
	// Line 347, Address: 0x2814e8, Func Offset: 0x278
	// Line 348, Address: 0x2814ec, Func Offset: 0x27c
	// Line 349, Address: 0x2814f0, Func Offset: 0x280
	// Line 350, Address: 0x2814f4, Func Offset: 0x284
	// Line 351, Address: 0x2814f8, Func Offset: 0x288
	// Line 352, Address: 0x2814fc, Func Offset: 0x28c
	// Line 353, Address: 0x281500, Func Offset: 0x290
	// Line 354, Address: 0x281504, Func Offset: 0x294
	// Line 356, Address: 0x281508, Func Offset: 0x298
	// Line 360, Address: 0x2815cc, Func Offset: 0x35c
	// Line 364, Address: 0x2815dc, Func Offset: 0x36c
	// Line 360, Address: 0x2815e0, Func Offset: 0x370
	// Line 361, Address: 0x2815e4, Func Offset: 0x374
	// Line 362, Address: 0x2815ec, Func Offset: 0x37c
	// Line 363, Address: 0x2815f0, Func Offset: 0x380
	// Line 361, Address: 0x2815f4, Func Offset: 0x384
	// Line 364, Address: 0x2815f8, Func Offset: 0x388
	// Line 361, Address: 0x281600, Func Offset: 0x390
	// Line 362, Address: 0x281608, Func Offset: 0x398
	// Line 363, Address: 0x281610, Func Offset: 0x3a0
	// Line 364, Address: 0x281614, Func Offset: 0x3a4
	// Line 363, Address: 0x281618, Func Offset: 0x3a8
	// Line 364, Address: 0x28161c, Func Offset: 0x3ac
	// Line 365, Address: 0x281620, Func Offset: 0x3b0
	// Line 367, Address: 0x281628, Func Offset: 0x3b8
	// Line 368, Address: 0x281638, Func Offset: 0x3c8
	// Line 367, Address: 0x28163c, Func Offset: 0x3cc
	// Line 371, Address: 0x281640, Func Offset: 0x3d0
	// Line 370, Address: 0x281648, Func Offset: 0x3d8
	// Line 369, Address: 0x28164c, Func Offset: 0x3dc
	// Line 368, Address: 0x281650, Func Offset: 0x3e0
	// Line 371, Address: 0x281658, Func Offset: 0x3e8
	// Line 369, Address: 0x281660, Func Offset: 0x3f0
	// Line 370, Address: 0x281668, Func Offset: 0x3f8
	// Line 371, Address: 0x28166c, Func Offset: 0x3fc
	// Line 370, Address: 0x281670, Func Offset: 0x400
	// Line 372, Address: 0x281674, Func Offset: 0x404
	// Line 374, Address: 0x28167c, Func Offset: 0x40c
	// Line 375, Address: 0x281684, Func Offset: 0x414
	// Line 376, Address: 0x281688, Func Offset: 0x418
	// Line 377, Address: 0x28168c, Func Offset: 0x41c
	// Line 378, Address: 0x281690, Func Offset: 0x420
	// Line 375, Address: 0x281698, Func Offset: 0x428
	// Line 378, Address: 0x28169c, Func Offset: 0x42c
	// Line 376, Address: 0x2816a4, Func Offset: 0x434
	// Line 378, Address: 0x2816a8, Func Offset: 0x438
	// Line 379, Address: 0x2816b0, Func Offset: 0x440
	// Line 381, Address: 0x2816b8, Func Offset: 0x448
	// Line 382, Address: 0x2816c8, Func Offset: 0x458
	// Line 381, Address: 0x2816cc, Func Offset: 0x45c
	// Line 382, Address: 0x2816d0, Func Offset: 0x460
	// Line 384, Address: 0x2816d4, Func Offset: 0x464
	// Line 383, Address: 0x2816d8, Func Offset: 0x468
	// Line 382, Address: 0x2816dc, Func Offset: 0x46c
	// Line 383, Address: 0x2816ec, Func Offset: 0x47c
	// Line 384, Address: 0x2816f4, Func Offset: 0x484
	// Line 385, Address: 0x2816f8, Func Offset: 0x488
	// Line 386, Address: 0x281740, Func Offset: 0x4d0
	// Line 388, Address: 0x281748, Func Offset: 0x4d8
	// Line 389, Address: 0x281758, Func Offset: 0x4e8
	// Line 388, Address: 0x28175c, Func Offset: 0x4ec
	// Line 391, Address: 0x281760, Func Offset: 0x4f0
	// Line 390, Address: 0x281764, Func Offset: 0x4f4
	// Line 389, Address: 0x281768, Func Offset: 0x4f8
	// Line 390, Address: 0x281770, Func Offset: 0x500
	// Line 391, Address: 0x281778, Func Offset: 0x508
	// Line 392, Address: 0x28177c, Func Offset: 0x50c
	// Line 393, Address: 0x2817c4, Func Offset: 0x554
	// Line 395, Address: 0x2817cc, Func Offset: 0x55c
	// Line 396, Address: 0x2817d4, Func Offset: 0x564
	// Line 397, Address: 0x2817d8, Func Offset: 0x568
	// Line 398, Address: 0x2817dc, Func Offset: 0x56c
	// Line 396, Address: 0x2817e0, Func Offset: 0x570
	// Line 397, Address: 0x2817e4, Func Offset: 0x574
	// Line 399, Address: 0x2817e8, Func Offset: 0x578
	// Line 400, Address: 0x281830, Func Offset: 0x5c0
	// Line 402, Address: 0x281838, Func Offset: 0x5c8
	// Line 403, Address: 0x281854, Func Offset: 0x5e4
	// Line 404, Address: 0x281858, Func Offset: 0x5e8
	// Line 406, Address: 0x28185c, Func Offset: 0x5ec
	// Line 408, Address: 0x281864, Func Offset: 0x5f4
	// Line 409, Address: 0x28189c, Func Offset: 0x62c
	// Line 411, Address: 0x2818b0, Func Offset: 0x640
	// Line 412, Address: 0x2818b4, Func Offset: 0x644
	// Line 413, Address: 0x2818b8, Func Offset: 0x648
	// Line 415, Address: 0x2818c0, Func Offset: 0x650
	// Line 416, Address: 0x2818f8, Func Offset: 0x688
	// Line 418, Address: 0x28190c, Func Offset: 0x69c
	// Line 419, Address: 0x281910, Func Offset: 0x6a0
	// Line 420, Address: 0x281914, Func Offset: 0x6a4
	// Line 422, Address: 0x28191c, Func Offset: 0x6ac
	// Line 424, Address: 0x281954, Func Offset: 0x6e4
	// Line 425, Address: 0x281958, Func Offset: 0x6e8
	// Line 426, Address: 0x281960, Func Offset: 0x6f0
	// Line 427, Address: 0x281968, Func Offset: 0x6f8
	// Line 428, Address: 0x281970, Func Offset: 0x700
	// Line 430, Address: 0x281978, Func Offset: 0x708
	// Line 431, Address: 0x28197c, Func Offset: 0x70c
	// Line 432, Address: 0x281984, Func Offset: 0x714
	// Line 433, Address: 0x281988, Func Offset: 0x718
	// Line 435, Address: 0x281a04, Func Offset: 0x794
	// Line 439, Address: 0x281a48, Func Offset: 0x7d8
	// Line 441, Address: 0x281a50, Func Offset: 0x7e0
	// Line 443, Address: 0x281a58, Func Offset: 0x7e8
	// Line 444, Address: 0x281a88, Func Offset: 0x818
	// Line 445, Address: 0x281aa4, Func Offset: 0x834
	// Line 446, Address: 0x281ac0, Func Offset: 0x850
	// Line 447, Address: 0x281acc, Func Offset: 0x85c
	// Line 448, Address: 0x281ad8, Func Offset: 0x868
	// Line 449, Address: 0x281ae0, Func Offset: 0x870
	// Line 450, Address: 0x281ae8, Func Offset: 0x878
	// Line 452, Address: 0x281aec, Func Offset: 0x87c
	// Line 456, Address: 0x281b30, Func Offset: 0x8c0
	// Line 458, Address: 0x281b38, Func Offset: 0x8c8
	// Line 460, Address: 0x281b40, Func Offset: 0x8d0
	// Line 461, Address: 0x281b70, Func Offset: 0x900
	// Line 462, Address: 0x281b8c, Func Offset: 0x91c
	// Line 463, Address: 0x281ba8, Func Offset: 0x938
	// Line 464, Address: 0x281bb4, Func Offset: 0x944
	// Line 465, Address: 0x281bc0, Func Offset: 0x950
	// Line 468, Address: 0x281bc4, Func Offset: 0x954
	// Line 465, Address: 0x281bc8, Func Offset: 0x958
	// Line 466, Address: 0x281bcc, Func Offset: 0x95c
	// Line 467, Address: 0x281bd4, Func Offset: 0x964
	// Line 468, Address: 0x281bdc, Func Offset: 0x96c
	// Line 472, Address: 0x281be0, Func Offset: 0x970
	// Line 474, Address: 0x281be4, Func Offset: 0x974
	// Line 475, Address: 0x281be8, Func Offset: 0x978
	// Line 477, Address: 0x281bf0, Func Offset: 0x980
	// Line 479, Address: 0x281c1c, Func Offset: 0x9ac
	// Line 480, Address: 0x281c20, Func Offset: 0x9b0
	// Line 481, Address: 0x281c28, Func Offset: 0x9b8
	// Line 482, Address: 0x281c30, Func Offset: 0x9c0
	// Line 483, Address: 0x281c38, Func Offset: 0x9c8
	// Line 485, Address: 0x281c40, Func Offset: 0x9d0
	// Line 486, Address: 0x281c70, Func Offset: 0xa00
	// Line 487, Address: 0x281c8c, Func Offset: 0xa1c
	// Line 488, Address: 0x281ca4, Func Offset: 0xa34
	// Line 489, Address: 0x281d20, Func Offset: 0xab0
	// Line 490, Address: 0x281d28, Func Offset: 0xab8
	// Line 491, Address: 0x281d30, Func Offset: 0xac0
	// Line 493, Address: 0x281d34, Func Offset: 0xac4
	// Line 497, Address: 0x281d78, Func Offset: 0xb08
	// Line 499, Address: 0x281d80, Func Offset: 0xb10
	// Line 501, Address: 0x281d88, Func Offset: 0xb18
	// Line 502, Address: 0x281db8, Func Offset: 0xb48
	// Line 503, Address: 0x281dd4, Func Offset: 0xb64
	// Line 504, Address: 0x281df0, Func Offset: 0xb80
	// Line 505, Address: 0x281dfc, Func Offset: 0xb8c
	// Line 506, Address: 0x281e08, Func Offset: 0xb98
	// Line 509, Address: 0x281e0c, Func Offset: 0xb9c
	// Line 506, Address: 0x281e10, Func Offset: 0xba0
	// Line 507, Address: 0x281e14, Func Offset: 0xba4
	// Line 508, Address: 0x281e1c, Func Offset: 0xbac
	// Line 509, Address: 0x281e24, Func Offset: 0xbb4
	// Line 513, Address: 0x281e28, Func Offset: 0xbb8
	// Line 515, Address: 0x281e2c, Func Offset: 0xbbc
	// Line 516, Address: 0x281e30, Func Offset: 0xbc0
	// Line 518, Address: 0x281e38, Func Offset: 0xbc8
	// Line 520, Address: 0x281e58, Func Offset: 0xbe8
	// Line 521, Address: 0x281e64, Func Offset: 0xbf4
	// Line 522, Address: 0x281e70, Func Offset: 0xc00
	// Line 523, Address: 0x281eb4, Func Offset: 0xc44
	// Line 525, Address: 0x281ebc, Func Offset: 0xc4c
	// Line 527, Address: 0x281ec4, Func Offset: 0xc54
	// Line 530, Address: 0x281ecc, Func Offset: 0xc5c
	// Line 527, Address: 0x281ed0, Func Offset: 0xc60
	// Line 530, Address: 0x281ed4, Func Offset: 0xc64
	// Line 528, Address: 0x281ed8, Func Offset: 0xc68
	// Line 530, Address: 0x281edc, Func Offset: 0xc6c
	// Line 531, Address: 0x281ee0, Func Offset: 0xc70
	// Line 532, Address: 0x281eec, Func Offset: 0xc7c
	// Line 537, Address: 0x281f30, Func Offset: 0xcc0
	// Line 539, Address: 0x281f38, Func Offset: 0xcc8
	// Line 543, Address: 0x281f40, Func Offset: 0xcd0
	// Line 540, Address: 0x281f48, Func Offset: 0xcd8
	// Line 541, Address: 0x281f4c, Func Offset: 0xcdc
	// Line 542, Address: 0x281f50, Func Offset: 0xce0
	// Line 543, Address: 0x281f54, Func Offset: 0xce4
	// Line 540, Address: 0x281f5c, Func Offset: 0xcec
	// Line 543, Address: 0x281f60, Func Offset: 0xcf0
	// Line 544, Address: 0x281f64, Func Offset: 0xcf4
	// Line 541, Address: 0x281f68, Func Offset: 0xcf8
	// Line 544, Address: 0x281f6c, Func Offset: 0xcfc
	// Line 545, Address: 0x281f78, Func Offset: 0xd08
	// Line 547, Address: 0x281f84, Func Offset: 0xd14
	// Line 549, Address: 0x281f8c, Func Offset: 0xd1c
	// Line 551, Address: 0x281fac, Func Offset: 0xd3c
	// Line 552, Address: 0x281fb0, Func Offset: 0xd40
	// Line 554, Address: 0x281fb8, Func Offset: 0xd48
	// Line 557, Address: 0x281fc0, Func Offset: 0xd50
	// Line 559, Address: 0x281fc8, Func Offset: 0xd58
	// Line 563, Address: 0x281fd0, Func Offset: 0xd60
	// Line 560, Address: 0x281fd8, Func Offset: 0xd68
	// Line 561, Address: 0x281fdc, Func Offset: 0xd6c
	// Line 562, Address: 0x281fe0, Func Offset: 0xd70
	// Line 563, Address: 0x281fe4, Func Offset: 0xd74
	// Line 560, Address: 0x281fec, Func Offset: 0xd7c
	// Line 563, Address: 0x281ff0, Func Offset: 0xd80
	// Line 564, Address: 0x281ff4, Func Offset: 0xd84
	// Line 561, Address: 0x281ff8, Func Offset: 0xd88
	// Line 564, Address: 0x281ffc, Func Offset: 0xd8c
	// Line 565, Address: 0x282008, Func Offset: 0xd98
	// Line 569, Address: 0x282014, Func Offset: 0xda4
	// Line 570, Address: 0x28201c, Func Offset: 0xdac
	// Line 571, Address: 0x282020, Func Offset: 0xdb0
	// Line 572, Address: 0x282024, Func Offset: 0xdb4
	// Line 573, Address: 0x282028, Func Offset: 0xdb8
	// Line 574, Address: 0x28202c, Func Offset: 0xdbc
	// Line 575, Address: 0x282030, Func Offset: 0xdc0
	// Line 576, Address: 0x282034, Func Offset: 0xdc4
	// Line 577, Address: 0x282038, Func Offset: 0xdc8
	// Line 578, Address: 0x28203c, Func Offset: 0xdcc
	// Line 579, Address: 0x282040, Func Offset: 0xdd0
	// Line 580, Address: 0x282044, Func Offset: 0xdd4
	// Line 581, Address: 0x28204c, Func Offset: 0xddc
	// Line 583, Address: 0x282050, Func Offset: 0xde0
	// Line 586, Address: 0x28207c, Func Offset: 0xe0c
	// Line 590, Address: 0x282080, Func Offset: 0xe10
	// Line 591, Address: 0x282084, Func Offset: 0xe14
	// Line 597, Address: 0x28208c, Func Offset: 0xe1c
	// Line 598, Address: 0x2820cc, Func Offset: 0xe5c
	// Line 604, Address: 0x2820d4, Func Offset: 0xe64
	// Line 605, Address: 0x282100, Func Offset: 0xe90
	// Line 611, Address: 0x282108, Func Offset: 0xe98
	// Line 612, Address: 0x282134, Func Offset: 0xec4
	// Line 618, Address: 0x28213c, Func Offset: 0xecc
	// Line 619, Address: 0x282178, Func Offset: 0xf08
	// Line 621, Address: 0x282180, Func Offset: 0xf10
	// Line 622, Address: 0x282184, Func Offset: 0xf14
	// Line 625, Address: 0x282188, Func Offset: 0xf18
	// Line 626, Address: 0x282194, Func Offset: 0xf24
	// Line 628, Address: 0x2821a4, Func Offset: 0xf34
	// Line 630, Address: 0x2821b0, Func Offset: 0xf40
	// Line 632, Address: 0x2821b8, Func Offset: 0xf48
	// Line 634, Address: 0x2821c4, Func Offset: 0xf54
	// Line 636, Address: 0x2821d4, Func Offset: 0xf64
	// Line 642, Address: 0x2821dc, Func Offset: 0xf6c
	// Line 644, Address: 0x282204, Func Offset: 0xf94
	// Line 645, Address: 0x282208, Func Offset: 0xf98
	// Line 646, Address: 0x28220c, Func Offset: 0xf9c
	// Line 647, Address: 0x282210, Func Offset: 0xfa0
	// Line 650, Address: 0x282218, Func Offset: 0xfa8
	// Line 652, Address: 0x28223c, Func Offset: 0xfcc
	// Line 654, Address: 0x282244, Func Offset: 0xfd4
	// Line 653, Address: 0x28224c, Func Offset: 0xfdc
	// Line 654, Address: 0x282250, Func Offset: 0xfe0
	// Line 655, Address: 0x28225c, Func Offset: 0xfec
	// Line 656, Address: 0x282270, Func Offset: 0x1000
	// Line 657, Address: 0x282284, Func Offset: 0x1014
	// Line 658, Address: 0x282298, Func Offset: 0x1028
	// Line 659, Address: 0x2822ac, Func Offset: 0x103c
	// Line 661, Address: 0x2822bc, Func Offset: 0x104c
	// Line 663, Address: 0x2822c4, Func Offset: 0x1054
	// Line 665, Address: 0x2822d0, Func Offset: 0x1060
	// Line 670, Address: 0x2822fc, Func Offset: 0x108c
	// Line 671, Address: 0x282300, Func Offset: 0x1090
	// Line 672, Address: 0x282304, Func Offset: 0x1094
	// Line 674, Address: 0x282308, Func Offset: 0x1098
	// Line 678, Address: 0x282344, Func Offset: 0x10d4
	// Line 674, Address: 0x28234c, Func Offset: 0x10dc
	// Line 678, Address: 0x282350, Func Offset: 0x10e0
	// Line 686, Address: 0x28235c, Func Offset: 0x10ec
	// Line 701, Address: 0x282408, Func Offset: 0x1198
	// Line 702, Address: 0x28241c, Func Offset: 0x11ac
	// Line 703, Address: 0x28242c, Func Offset: 0x11bc
	// Line 704, Address: 0x282440, Func Offset: 0x11d0
	// Line 706, Address: 0x28244c, Func Offset: 0x11dc
	// Line 707, Address: 0x282460, Func Offset: 0x11f0
	// Line 708, Address: 0x282470, Func Offset: 0x1200
	// Line 709, Address: 0x282484, Func Offset: 0x1214
	// Line 710, Address: 0x282490, Func Offset: 0x1220
	// Line 711, Address: 0x282494, Func Offset: 0x1224
	// Line 712, Address: 0x282498, Func Offset: 0x1228
	// Line 713, Address: 0x28249c, Func Offset: 0x122c
	// Line 714, Address: 0x2824a0, Func Offset: 0x1230
	// Line 715, Address: 0x2824a4, Func Offset: 0x1234
	// Line 716, Address: 0x2824a8, Func Offset: 0x1238
	// Line 717, Address: 0x2824ac, Func Offset: 0x123c
	// Line 719, Address: 0x2824b0, Func Offset: 0x1240
	// Line 718, Address: 0x2824b8, Func Offset: 0x1248
	// Line 720, Address: 0x2824bc, Func Offset: 0x124c
	// Line 719, Address: 0x2824c0, Func Offset: 0x1250
	// Line 723, Address: 0x2824dc, Func Offset: 0x126c
	// Line 724, Address: 0x2824e0, Func Offset: 0x1270
	// Line 725, Address: 0x2824f8, Func Offset: 0x1288
	// Line 726, Address: 0x2824fc, Func Offset: 0x128c
	// Line 727, Address: 0x282500, Func Offset: 0x1290
	// Line 728, Address: 0x282504, Func Offset: 0x1294
	// Line 729, Address: 0x282508, Func Offset: 0x1298
	// Line 730, Address: 0x28250c, Func Offset: 0x129c
	// Line 731, Address: 0x282510, Func Offset: 0x12a0
	// Line 732, Address: 0x282514, Func Offset: 0x12a4
	// Line 733, Address: 0x282518, Func Offset: 0x12a8
	// Line 734, Address: 0x28251c, Func Offset: 0x12ac
	// Line 735, Address: 0x282520, Func Offset: 0x12b0
	// Line 738, Address: 0x282524, Func Offset: 0x12b4
	// Line 740, Address: 0x282540, Func Offset: 0x12d0
	// Line 742, Address: 0x282550, Func Offset: 0x12e0
	// Line 743, Address: 0x282558, Func Offset: 0x12e8
	// Line 745, Address: 0x282560, Func Offset: 0x12f0
	// Line 743, Address: 0x282564, Func Offset: 0x12f4
	// Line 745, Address: 0x28256c, Func Offset: 0x12fc
	// Line 743, Address: 0x282574, Func Offset: 0x1304
	// Line 745, Address: 0x282578, Func Offset: 0x1308
	// Line 743, Address: 0x28257c, Func Offset: 0x130c
	// Line 745, Address: 0x282580, Func Offset: 0x1310
	// Line 746, Address: 0x282588, Func Offset: 0x1318
	// Line 748, Address: 0x282594, Func Offset: 0x1324
	// Line 749, Address: 0x2825a8, Func Offset: 0x1338
	// Line 751, Address: 0x2825b4, Func Offset: 0x1344
	// Line 752, Address: 0x2825c8, Func Offset: 0x1358
	// Line 753, Address: 0x2825d4, Func Offset: 0x1364
	// Line 755, Address: 0x2825e8, Func Offset: 0x1378
	// Line 756, Address: 0x2825fc, Func Offset: 0x138c
	// Line 757, Address: 0x282608, Func Offset: 0x1398
	// Line 758, Address: 0x28261c, Func Offset: 0x13ac
	// Line 759, Address: 0x282630, Func Offset: 0x13c0
	// Line 760, Address: 0x282644, Func Offset: 0x13d4
	// Line 761, Address: 0x282658, Func Offset: 0x13e8
	// Line 762, Address: 0x28266c, Func Offset: 0x13fc
	// Line 763, Address: 0x282680, Func Offset: 0x1410
	// Line 764, Address: 0x282690, Func Offset: 0x1420
	// Line 765, Address: 0x282698, Func Offset: 0x1428
	// Line 767, Address: 0x2826a8, Func Offset: 0x1438
	// Line 765, Address: 0x2826ac, Func Offset: 0x143c
	// Line 767, Address: 0x2826b4, Func Offset: 0x1444
	// Line 768, Address: 0x2826e4, Func Offset: 0x1474
	// Line 769, Address: 0x282714, Func Offset: 0x14a4
	// Line 771, Address: 0x282720, Func Offset: 0x14b0
	// Line 772, Address: 0x282754, Func Offset: 0x14e4
	// Line 773, Address: 0x282784, Func Offset: 0x1514
	// Line 775, Address: 0x282790, Func Offset: 0x1520
	// Line 776, Address: 0x2827b4, Func Offset: 0x1544
	// Line 777, Address: 0x2827e4, Func Offset: 0x1574
	// Line 778, Address: 0x2827f8, Func Offset: 0x1588
	// Line 780, Address: 0x282810, Func Offset: 0x15a0
	// Line 781, Address: 0x282840, Func Offset: 0x15d0
	// Line 782, Address: 0x282854, Func Offset: 0x15e4
	// Line 785, Address: 0x282864, Func Offset: 0x15f4
	// Line 786, Address: 0x282870, Func Offset: 0x1600
	// Line 787, Address: 0x28287c, Func Offset: 0x160c
	// Line 788, Address: 0x282888, Func Offset: 0x1618
	// Line 789, Address: 0x282894, Func Offset: 0x1624
	// Line 790, Address: 0x2828a4, Func Offset: 0x1634
	// Line 792, Address: 0x2828a8, Func Offset: 0x1638
	// Line 793, Address: 0x2828b4, Func Offset: 0x1644
	// Line 795, Address: 0x2828bc, Func Offset: 0x164c
	// Line 796, Address: 0x2828c4, Func Offset: 0x1654
	// Line 797, Address: 0x2828cc, Func Offset: 0x165c
	// Func End, Address: 0x28292c, Func Offset: 0x16bc
	scePrintf("bhControlLight - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x282930
void bhSetLight()
{
	int i;
	//_anon4 vec;
	//_anon9* lptb;
	// Line 1059, Address: 0x282930, Func Offset: 0
	// Line 1070, Address: 0x282940, Func Offset: 0x10
	// Line 1071, Address: 0x282958, Func Offset: 0x28
	// Line 1072, Address: 0x282968, Func Offset: 0x38
	// Line 1078, Address: 0x282970, Func Offset: 0x40
	// Line 1080, Address: 0x282984, Func Offset: 0x54
	// Line 1081, Address: 0x282998, Func Offset: 0x68
	// Line 1083, Address: 0x2829a4, Func Offset: 0x74
	// Line 1084, Address: 0x2829b8, Func Offset: 0x88
	// Line 1086, Address: 0x2829c4, Func Offset: 0x94
	// Line 1087, Address: 0x2829d8, Func Offset: 0xa8
	// Line 1088, Address: 0x2829e4, Func Offset: 0xb4
	// Line 1090, Address: 0x2829f8, Func Offset: 0xc8
	// Line 1091, Address: 0x282a0c, Func Offset: 0xdc
	// Line 1092, Address: 0x282a18, Func Offset: 0xe8
	// Line 1093, Address: 0x282a2c, Func Offset: 0xfc
	// Line 1095, Address: 0x282a34, Func Offset: 0x104
	// Line 1096, Address: 0x282a60, Func Offset: 0x130
	// Line 1097, Address: 0x282a90, Func Offset: 0x160
	// Line 1099, Address: 0x282a9c, Func Offset: 0x16c
	// Line 1100, Address: 0x282ad0, Func Offset: 0x1a0
	// Line 1101, Address: 0x282b00, Func Offset: 0x1d0
	// Line 1103, Address: 0x282b0c, Func Offset: 0x1dc
	// Line 1104, Address: 0x282b30, Func Offset: 0x200
	// Line 1105, Address: 0x282b60, Func Offset: 0x230
	// Line 1106, Address: 0x282b74, Func Offset: 0x244
	// Line 1108, Address: 0x282b8c, Func Offset: 0x25c
	// Line 1109, Address: 0x282bbc, Func Offset: 0x28c
	// Line 1110, Address: 0x282bd0, Func Offset: 0x2a0
	// Line 1113, Address: 0x282be0, Func Offset: 0x2b0
	// Line 1114, Address: 0x282be8, Func Offset: 0x2b8
	// Line 1113, Address: 0x282bec, Func Offset: 0x2bc
	// Line 1114, Address: 0x282bf4, Func Offset: 0x2c4
	// Line 1116, Address: 0x282bfc, Func Offset: 0x2cc
	// Line 1118, Address: 0x282c10, Func Offset: 0x2e0
	// Line 1119, Address: 0x282c24, Func Offset: 0x2f4
	// Line 1121, Address: 0x282c50, Func Offset: 0x320
	// Line 1123, Address: 0x282c60, Func Offset: 0x330
	// Line 1125, Address: 0x282c68, Func Offset: 0x338
	// Line 1126, Address: 0x282c70, Func Offset: 0x340
	// Func End, Address: 0x282c84, Func Offset: 0x354
	scePrintf("bhSetLight - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x282c90
void bhSetHalfLight()
{
	int i;
	float b;
	float g;
	float r;
	//_anon4 vec;
	//_anon9* lptb;
	// Line 1134, Address: 0x282c90, Func Offset: 0
	// Line 1145, Address: 0x282cac, Func Offset: 0x1c
	// Line 1146, Address: 0x282cc4, Func Offset: 0x34
	// Line 1147, Address: 0x282cd8, Func Offset: 0x48
	// Line 1153, Address: 0x282ce0, Func Offset: 0x50
	// Line 1155, Address: 0x282cf4, Func Offset: 0x64
	// Line 1156, Address: 0x282d08, Func Offset: 0x78
	// Line 1158, Address: 0x282d14, Func Offset: 0x84
	// Line 1159, Address: 0x282d28, Func Offset: 0x98
	// Line 1161, Address: 0x282d34, Func Offset: 0xa4
	// Line 1162, Address: 0x282d48, Func Offset: 0xb8
	// Line 1163, Address: 0x282d54, Func Offset: 0xc4
	// Line 1165, Address: 0x282d68, Func Offset: 0xd8
	// Line 1166, Address: 0x282d7c, Func Offset: 0xec
	// Line 1167, Address: 0x282d88, Func Offset: 0xf8
	// Line 1168, Address: 0x282d9c, Func Offset: 0x10c
	// Line 1169, Address: 0x282da4, Func Offset: 0x114
	// Line 1170, Address: 0x282db8, Func Offset: 0x128
	// Line 1169, Address: 0x282dc0, Func Offset: 0x130
	// Line 1170, Address: 0x282dc4, Func Offset: 0x134
	// Line 1173, Address: 0x282dc8, Func Offset: 0x138
	// Line 1171, Address: 0x282dcc, Func Offset: 0x13c
	// Line 1170, Address: 0x282dd4, Func Offset: 0x144
	// Line 1171, Address: 0x282dd8, Func Offset: 0x148
	// Line 1173, Address: 0x282ddc, Func Offset: 0x14c
	// Line 1171, Address: 0x282de4, Func Offset: 0x154
	// Line 1173, Address: 0x282de8, Func Offset: 0x158
	// Line 1174, Address: 0x282df0, Func Offset: 0x160
	// Line 1175, Address: 0x282e20, Func Offset: 0x190
	// Line 1177, Address: 0x282e2c, Func Offset: 0x19c
	// Line 1178, Address: 0x282e40, Func Offset: 0x1b0
	// Line 1179, Address: 0x282e70, Func Offset: 0x1e0
	// Line 1181, Address: 0x282e7c, Func Offset: 0x1ec
	// Line 1182, Address: 0x282ea0, Func Offset: 0x210
	// Line 1183, Address: 0x282eb0, Func Offset: 0x220
	// Line 1184, Address: 0x282ec4, Func Offset: 0x234
	// Line 1186, Address: 0x282edc, Func Offset: 0x24c
	// Line 1187, Address: 0x282eec, Func Offset: 0x25c
	// Line 1188, Address: 0x282f00, Func Offset: 0x270
	// Line 1191, Address: 0x282f10, Func Offset: 0x280
	// Line 1192, Address: 0x282f18, Func Offset: 0x288
	// Line 1191, Address: 0x282f1c, Func Offset: 0x28c
	// Line 1192, Address: 0x282f24, Func Offset: 0x294
	// Line 1193, Address: 0x282f2c, Func Offset: 0x29c
	// Line 1194, Address: 0x282f30, Func Offset: 0x2a0
	// Line 1195, Address: 0x282f34, Func Offset: 0x2a4
	// Line 1193, Address: 0x282f38, Func Offset: 0x2a8
	// Line 1197, Address: 0x282f40, Func Offset: 0x2b0
	// Line 1193, Address: 0x282f44, Func Offset: 0x2b4
	// Line 1194, Address: 0x282f48, Func Offset: 0x2b8
	// Line 1195, Address: 0x282f4c, Func Offset: 0x2bc
	// Line 1197, Address: 0x282f50, Func Offset: 0x2c0
	// Line 1199, Address: 0x282f60, Func Offset: 0x2d0
	// Line 1200, Address: 0x282f74, Func Offset: 0x2e4
	// Line 1202, Address: 0x282fa0, Func Offset: 0x310
	// Line 1204, Address: 0x282fb0, Func Offset: 0x320
	// Line 1206, Address: 0x282fb8, Func Offset: 0x328
	// Line 1207, Address: 0x282fc0, Func Offset: 0x330
	// Func End, Address: 0x282fe0, Func Offset: 0x350
	scePrintf("bhSetHalfLight - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x282fe0
void bhGetLightVector(int xr, int yr, int zr, NJS_VECTOR* vec)
{
	//_anon4 pos;
	// Line 1216, Address: 0x282fe0, Func Offset: 0
	// Line 1217, Address: 0x282ffc, Func Offset: 0x1c
	// Line 1218, Address: 0x283020, Func Offset: 0x40
	// Line 1219, Address: 0x28302c, Func Offset: 0x4c
	// Line 1220, Address: 0x283038, Func Offset: 0x58
	// Line 1221, Address: 0x283044, Func Offset: 0x64
	// Line 1222, Address: 0x283050, Func Offset: 0x70
	// Line 1223, Address: 0x283060, Func Offset: 0x80
	// Func End, Address: 0x28307c, Func Offset: 0x9c
	scePrintf("bhGetLightVector - UNIMPLEMENTED!\n");
}
