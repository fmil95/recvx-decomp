#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/main.h"

unsigned int owk_scn_noG;
/*_anon9 Tex5uv[9];
_anon11* sys;
_anon70 cam;
_anon2 PtclDat00[2];
_anon2 PtclDat01[2];
_anon2 PtclDat02[2];
_anon2 PtclDat03[1];
_anon2 PtclDat04[2];
_anon2 PtclDat05[2];
_anon2 PtclDat06[2];
_anon2 PtclDat07[2];
_anon2 PtclDat08[1];
_anon2 PtclDat09[2];
_anon2 PtclDat10[1];
_anon2 PtclDat11[1];
_anon2 PtclDat12[2];
_anon2 PtclDat13[2];
_anon2 PtclDat14[1];
_anon2 PtclDat15[2];
_anon2 PtclDat16[2];
_anon2 PtclDat17[1];
_anon2 PtclDat18[1];
_anon34 PtclTbl[19];
void(*FuncTbl)(O_WRK*)[4];
_anon7 Eff302Prm[20];
float lcmat[16][0];
void(*bhEff307Drw)(OR_WORK*);
_anon15* rom;
void(*bhEff308Drw)(OR_WORK*);
void(*bhEff309Drw)(OR_WORK*);
void(*bhEff30bDrw)(OR_WORK*);
void(*bhEff30cDrw)(OR_WORK*);*/

// 100% matching!
static O_WRK* AllocOwork()
{
    O_WRK* oP;
    int o_no;

    o_no = owk_scn_noG;
    
    for (oP = &eff[o_no]; o_no < 512; o_no++, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            owk_scn_noG = o_no + 1;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
O_WRK* AllocOworkOne()
{
    O_WRK* oP;
    int o_no;

    o_no = 512;

    oP = eff;
    
    for ( ; o_no > 0; o_no--, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
void bhClrEff_RY()
{
    O_WRK* oP;
	int i;

    oP = eff;
    
    for (i = 0; i < 512; i++, oP++) 
    {
        if ((oP->flg & 0x1))
        {
            switch (oP->id) 
            {                     
            case 301:
                oP->flg = 0;
                break;
            case 302:
                *(int*)oP->exp1 = 0;
                *(int*)oP->exp0 = 0;
                
                oP->flg = 0;
                break;
            }
        }
    }
}

// 
// Start address: 0x2469a0
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk)
{
	//_anon60* e17P;
	int eff_no;
	O_WRK* o1P;
	O_WRK* o0P;
	// Line 319, Address: 0x2469a0, Func Offset: 0
	// Line 322, Address: 0x2469d4, Func Offset: 0x34
	// Line 323, Address: 0x2469e4, Func Offset: 0x44
	// Line 325, Address: 0x2469f4, Func Offset: 0x54
	// Line 328, Address: 0x2469f8, Func Offset: 0x58
	// Line 324, Address: 0x246a04, Func Offset: 0x64
	// Line 329, Address: 0x246a08, Func Offset: 0x68
	// Line 331, Address: 0x246a0c, Func Offset: 0x6c
	// Line 330, Address: 0x246a10, Func Offset: 0x70
	// Line 331, Address: 0x246a14, Func Offset: 0x74
	// Line 332, Address: 0x246a18, Func Offset: 0x78
	// Line 333, Address: 0x246a1c, Func Offset: 0x7c
	// Line 334, Address: 0x246a20, Func Offset: 0x80
	// Line 336, Address: 0x246a2c, Func Offset: 0x8c
	// Line 338, Address: 0x246a38, Func Offset: 0x98
	// Line 334, Address: 0x246a3c, Func Offset: 0x9c
	// Line 336, Address: 0x246a48, Func Offset: 0xa8
	// Line 338, Address: 0x246a4c, Func Offset: 0xac
	// Line 336, Address: 0x246a50, Func Offset: 0xb0
	// Line 338, Address: 0x246a54, Func Offset: 0xb4
	// Line 339, Address: 0x246a5c, Func Offset: 0xbc
	// Line 342, Address: 0x246a74, Func Offset: 0xd4
	// Line 339, Address: 0x246a78, Func Offset: 0xd8
	// Line 349, Address: 0x246a84, Func Offset: 0xe4
	// Line 354, Address: 0x246a88, Func Offset: 0xe8
	// Line 355, Address: 0x246a8c, Func Offset: 0xec
	// Line 339, Address: 0x246a90, Func Offset: 0xf0
	// Line 340, Address: 0x246a94, Func Offset: 0xf4
	// Line 356, Address: 0x246a98, Func Offset: 0xf8
	// Line 357, Address: 0x246a9c, Func Offset: 0xfc
	// Line 339, Address: 0x246aa0, Func Offset: 0x100
	// Line 358, Address: 0x246aa4, Func Offset: 0x104
	// Line 382, Address: 0x246aa8, Func Offset: 0x108
	// Line 339, Address: 0x246aac, Func Offset: 0x10c
	// Line 340, Address: 0x246ab4, Func Offset: 0x114
	// Line 344, Address: 0x246ac8, Func Offset: 0x128
	// Line 340, Address: 0x246acc, Func Offset: 0x12c
	// Line 341, Address: 0x246ad8, Func Offset: 0x138
	// Line 342, Address: 0x246ae4, Func Offset: 0x144
	// Line 343, Address: 0x246af0, Func Offset: 0x150
	// Line 344, Address: 0x246afc, Func Offset: 0x15c
	// Line 345, Address: 0x246b10, Func Offset: 0x170
	// Line 346, Address: 0x246b14, Func Offset: 0x174
	// Line 349, Address: 0x246b18, Func Offset: 0x178
	// Line 354, Address: 0x246b1c, Func Offset: 0x17c
	// Line 355, Address: 0x246b20, Func Offset: 0x180
	// Line 356, Address: 0x246b24, Func Offset: 0x184
	// Line 357, Address: 0x246b28, Func Offset: 0x188
	// Line 358, Address: 0x246b2c, Func Offset: 0x18c
	// Line 360, Address: 0x246b30, Func Offset: 0x190
	// Line 361, Address: 0x246b34, Func Offset: 0x194
	// Line 362, Address: 0x246b38, Func Offset: 0x198
	// Line 365, Address: 0x246b3c, Func Offset: 0x19c
	// Line 366, Address: 0x246b40, Func Offset: 0x1a0
	// Line 367, Address: 0x246b48, Func Offset: 0x1a8
	// Line 368, Address: 0x246b50, Func Offset: 0x1b0
	// Line 370, Address: 0x246b58, Func Offset: 0x1b8
	// Line 371, Address: 0x246b60, Func Offset: 0x1c0
	// Line 372, Address: 0x246b68, Func Offset: 0x1c8
	// Line 373, Address: 0x246b70, Func Offset: 0x1d0
	// Line 374, Address: 0x246b78, Func Offset: 0x1d8
	// Line 376, Address: 0x246b80, Func Offset: 0x1e0
	// Line 377, Address: 0x246b88, Func Offset: 0x1e8
	// Line 378, Address: 0x246b90, Func Offset: 0x1f0
	// Line 379, Address: 0x246b98, Func Offset: 0x1f8
	// Line 380, Address: 0x246ba0, Func Offset: 0x200
	// Line 382, Address: 0x246ba4, Func Offset: 0x204
	// Line 384, Address: 0x246bac, Func Offset: 0x20c
	// Line 387, Address: 0x246bb0, Func Offset: 0x210
	// Line 388, Address: 0x246bb4, Func Offset: 0x214
	// Func End, Address: 0x246bdc, Func Offset: 0x23c
	scePrintf("bhSetBloodPoolLnk - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x246be0
void bhEff300(O_WRK* oP)
{
	BH_PWORK* ewP;
	NJS_POINT3 pos;
	int pnt;
	//_anon6* tvP;
	NJS_POINT3 add;
	float spd;
	int srt_no;
	int i;
	//_anon6* tvP;
	NJS_POINT3* addP;
	//float spd;
	int tmp;
	int ang;
	//int i;
	NJS_POINT3* spdP;
	//_anon6* tvP;
	//int ang;
	//float spd;
	NJS_POINT3 center;
	//_anon60* e17P;
	int VtxTbl[16];
	// Line 404, Address: 0x246be0, Func Offset: 0
	// Line 409, Address: 0x246c0c, Func Offset: 0x2c
	// Line 418, Address: 0x246c14, Func Offset: 0x34
	// Line 425, Address: 0x246c40, Func Offset: 0x60
	// Line 426, Address: 0x246c48, Func Offset: 0x68
	// Line 425, Address: 0x246c4c, Func Offset: 0x6c
	// Line 428, Address: 0x246c50, Func Offset: 0x70
	// Line 430, Address: 0x246c60, Func Offset: 0x80
	// Line 428, Address: 0x246c64, Func Offset: 0x84
	// Line 430, Address: 0x246c68, Func Offset: 0x88
	// Line 434, Address: 0x246c74, Func Offset: 0x94
	// Line 435, Address: 0x246c78, Func Offset: 0x98
	// Line 430, Address: 0x246c7c, Func Offset: 0x9c
	// Line 436, Address: 0x246c80, Func Offset: 0xa0
	// Line 438, Address: 0x246c84, Func Offset: 0xa4
	// Line 436, Address: 0x246c8c, Func Offset: 0xac
	// Line 441, Address: 0x246c90, Func Offset: 0xb0
	// Line 443, Address: 0x246c94, Func Offset: 0xb4
	// Line 444, Address: 0x246ca8, Func Offset: 0xc8
	// Line 446, Address: 0x246cac, Func Offset: 0xcc
	// Line 447, Address: 0x246cb4, Func Offset: 0xd4
	// Line 448, Address: 0x246cc8, Func Offset: 0xe8
	// Line 447, Address: 0x246ccc, Func Offset: 0xec
	// Line 448, Address: 0x246cd4, Func Offset: 0xf4
	// Line 451, Address: 0x246ce4, Func Offset: 0x104
	// Line 448, Address: 0x246ce8, Func Offset: 0x108
	// Line 449, Address: 0x246cec, Func Offset: 0x10c
	// Line 448, Address: 0x246cf4, Func Offset: 0x114
	// Line 451, Address: 0x246cfc, Func Offset: 0x11c
	// Line 453, Address: 0x246d08, Func Offset: 0x128
	// Line 451, Address: 0x246d0c, Func Offset: 0x12c
	// Line 453, Address: 0x246d10, Func Offset: 0x130
	// Line 454, Address: 0x246d20, Func Offset: 0x140
	// Line 455, Address: 0x246d30, Func Offset: 0x150
	// Line 454, Address: 0x246d38, Func Offset: 0x158
	// Line 455, Address: 0x246d3c, Func Offset: 0x15c
	// Line 458, Address: 0x246d48, Func Offset: 0x168
	// Line 460, Address: 0x246d4c, Func Offset: 0x16c
	// Line 461, Address: 0x246d54, Func Offset: 0x174
	// Line 466, Address: 0x246d5c, Func Offset: 0x17c
	// Line 467, Address: 0x246d60, Func Offset: 0x180
	// Line 470, Address: 0x246d64, Func Offset: 0x184
	// Line 471, Address: 0x246d68, Func Offset: 0x188
	// Line 472, Address: 0x246d74, Func Offset: 0x194
	// Line 473, Address: 0x246d84, Func Offset: 0x1a4
	// Line 472, Address: 0x246d88, Func Offset: 0x1a8
	// Line 473, Address: 0x246d8c, Func Offset: 0x1ac
	// Line 472, Address: 0x246d94, Func Offset: 0x1b4
	// Line 473, Address: 0x246da4, Func Offset: 0x1c4
	// Line 480, Address: 0x246dac, Func Offset: 0x1cc
	// Line 481, Address: 0x246db4, Func Offset: 0x1d4
	// Line 483, Address: 0x246db8, Func Offset: 0x1d8
	// Line 487, Address: 0x246dd0, Func Offset: 0x1f0
	// Line 489, Address: 0x246dd4, Func Offset: 0x1f4
	// Line 495, Address: 0x246dec, Func Offset: 0x20c
	// Line 486, Address: 0x246df0, Func Offset: 0x210
	// Line 496, Address: 0x246df4, Func Offset: 0x214
	// Line 489, Address: 0x246e08, Func Offset: 0x228
	// Line 495, Address: 0x246e30, Func Offset: 0x250
	// Line 496, Address: 0x246e48, Func Offset: 0x268
	// Line 498, Address: 0x246e60, Func Offset: 0x280
	// Line 500, Address: 0x246e84, Func Offset: 0x2a4
	// Line 504, Address: 0x246e8c, Func Offset: 0x2ac
	// Line 505, Address: 0x246e94, Func Offset: 0x2b4
	// Line 504, Address: 0x246e98, Func Offset: 0x2b8
	// Line 505, Address: 0x246eac, Func Offset: 0x2cc
	// Line 507, Address: 0x246ec4, Func Offset: 0x2e4
	// Line 508, Address: 0x246ed4, Func Offset: 0x2f4
	// Line 507, Address: 0x246ed8, Func Offset: 0x2f8
	// Line 508, Address: 0x246edc, Func Offset: 0x2fc
	// Line 507, Address: 0x246ee8, Func Offset: 0x308
	// Line 508, Address: 0x246ef0, Func Offset: 0x310
	// Line 507, Address: 0x246efc, Func Offset: 0x31c
	// Line 508, Address: 0x246f04, Func Offset: 0x324
	// Line 509, Address: 0x246f1c, Func Offset: 0x33c
	// Line 511, Address: 0x246f50, Func Offset: 0x370
	// Line 512, Address: 0x246f60, Func Offset: 0x380
	// Line 511, Address: 0x246f64, Func Offset: 0x384
	// Line 512, Address: 0x246f68, Func Offset: 0x388
	// Line 511, Address: 0x246f74, Func Offset: 0x394
	// Line 512, Address: 0x246f7c, Func Offset: 0x39c
	// Line 511, Address: 0x246f88, Func Offset: 0x3a8
	// Line 512, Address: 0x246f90, Func Offset: 0x3b0
	// Line 513, Address: 0x246fa8, Func Offset: 0x3c8
	// Line 515, Address: 0x246fdc, Func Offset: 0x3fc
	// Line 516, Address: 0x246fec, Func Offset: 0x40c
	// Line 515, Address: 0x246ff0, Func Offset: 0x410
	// Line 516, Address: 0x246ff4, Func Offset: 0x414
	// Line 515, Address: 0x247000, Func Offset: 0x420
	// Line 516, Address: 0x247008, Func Offset: 0x428
	// Line 515, Address: 0x247014, Func Offset: 0x434
	// Line 516, Address: 0x24701c, Func Offset: 0x43c
	// Line 517, Address: 0x247034, Func Offset: 0x454
	// Line 519, Address: 0x247068, Func Offset: 0x488
	// Line 521, Address: 0x247078, Func Offset: 0x498
	// Line 522, Address: 0x24708c, Func Offset: 0x4ac
	// Line 523, Address: 0x247098, Func Offset: 0x4b8
	// Line 530, Address: 0x24709c, Func Offset: 0x4bc
	// Line 533, Address: 0x2470a0, Func Offset: 0x4c0
	// Line 535, Address: 0x2470d4, Func Offset: 0x4f4
	// Line 546, Address: 0x24710c, Func Offset: 0x52c
	// Func End, Address: 0x24713c, Func Offset: 0x55c
	scePrintf("bhEff300 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x247140
void bhEff301(O_WRK* oP)
{
	//_anon9* uvP;
	float siz_y;
	float siz_x;
	//float siz_y;
	//float siz_x;
	int ay;
	float off_set;
	//_anon36* htP;
	float adj;
	NJS_POINT3 pos;
	float rng;
	//int ay;
	int ax;
	//_anon36* htP;
	//_anon67* prmP;
	unsigned char AnmTbl[2][4];
	//_anon67 Eff301Prm[7];
	// Line 556, Address: 0x247140, Func Offset: 0
	// Line 585, Address: 0x247164, Func Offset: 0x24
	// Line 587, Address: 0x247180, Func Offset: 0x40
	// Line 598, Address: 0x247188, Func Offset: 0x48
	// Line 602, Address: 0x247244, Func Offset: 0x104
	// Line 606, Address: 0x247250, Func Offset: 0x110
	// Line 605, Address: 0x247258, Func Offset: 0x118
	// Line 606, Address: 0x24725c, Func Offset: 0x11c
	// Line 602, Address: 0x247260, Func Offset: 0x120
	// Line 607, Address: 0x247264, Func Offset: 0x124
	// Line 602, Address: 0x247268, Func Offset: 0x128
	// Line 608, Address: 0x24726c, Func Offset: 0x12c
	// Line 609, Address: 0x247270, Func Offset: 0x130
	// Line 602, Address: 0x247274, Func Offset: 0x134
	// Line 614, Address: 0x24727c, Func Offset: 0x13c
	// Line 615, Address: 0x2472d0, Func Offset: 0x190
	// Line 616, Address: 0x247320, Func Offset: 0x1e0
	// Line 615, Address: 0x247324, Func Offset: 0x1e4
	// Line 621, Address: 0x247328, Func Offset: 0x1e8
	// Line 622, Address: 0x247344, Func Offset: 0x204
	// Line 621, Address: 0x247348, Func Offset: 0x208
	// Line 622, Address: 0x24734c, Func Offset: 0x20c
	// Line 623, Address: 0x247358, Func Offset: 0x218
	// Line 629, Address: 0x24737c, Func Offset: 0x23c
	// Line 630, Address: 0x2473b0, Func Offset: 0x270
	// Line 632, Address: 0x2473f4, Func Offset: 0x2b4
	// Line 631, Address: 0x2473f8, Func Offset: 0x2b8
	// Line 632, Address: 0x2473fc, Func Offset: 0x2bc
	// Line 633, Address: 0x247414, Func Offset: 0x2d4
	// Line 634, Address: 0x247418, Func Offset: 0x2d8
	// Line 635, Address: 0x247424, Func Offset: 0x2e4
	// Line 636, Address: 0x247440, Func Offset: 0x300
	// Line 635, Address: 0x24744c, Func Offset: 0x30c
	// Line 636, Address: 0x247450, Func Offset: 0x310
	// Line 635, Address: 0x247454, Func Offset: 0x314
	// Line 636, Address: 0x247458, Func Offset: 0x318
	// Line 639, Address: 0x247460, Func Offset: 0x320
	// Line 635, Address: 0x247464, Func Offset: 0x324
	// Line 639, Address: 0x247468, Func Offset: 0x328
	// Line 635, Address: 0x24746c, Func Offset: 0x32c
	// Line 639, Address: 0x24747c, Func Offset: 0x33c
	// Line 635, Address: 0x247484, Func Offset: 0x344
	// Line 636, Address: 0x24748c, Func Offset: 0x34c
	// Line 637, Address: 0x247490, Func Offset: 0x350
	// Line 638, Address: 0x247494, Func Offset: 0x354
	// Line 639, Address: 0x247498, Func Offset: 0x358
	// Line 640, Address: 0x2474b0, Func Offset: 0x370
	// Line 641, Address: 0x2474b4, Func Offset: 0x374
	// Line 640, Address: 0x2474b8, Func Offset: 0x378
	// Line 641, Address: 0x2474c0, Func Offset: 0x380
	// Line 643, Address: 0x2474cc, Func Offset: 0x38c
	// Line 644, Address: 0x2474d4, Func Offset: 0x394
	// Line 650, Address: 0x2474dc, Func Offset: 0x39c
	// Line 653, Address: 0x2474e8, Func Offset: 0x3a8
	// Line 655, Address: 0x247504, Func Offset: 0x3c4
	// Line 656, Address: 0x247514, Func Offset: 0x3d4
	// Line 657, Address: 0x247534, Func Offset: 0x3f4
	// Line 656, Address: 0x24753c, Func Offset: 0x3fc
	// Line 657, Address: 0x24755c, Func Offset: 0x41c
	// Line 658, Address: 0x247564, Func Offset: 0x424
	// Line 660, Address: 0x247570, Func Offset: 0x430
	// Line 661, Address: 0x24758c, Func Offset: 0x44c
	// Line 662, Address: 0x247590, Func Offset: 0x450
	// Line 663, Address: 0x247594, Func Offset: 0x454
	// Line 664, Address: 0x2475c0, Func Offset: 0x480
	// Line 665, Address: 0x2475cc, Func Offset: 0x48c
	// Line 667, Address: 0x2475d4, Func Offset: 0x494
	// Line 668, Address: 0x2475dc, Func Offset: 0x49c
	// Line 670, Address: 0x2475e4, Func Offset: 0x4a4
	// Line 674, Address: 0x2475ec, Func Offset: 0x4ac
	// Line 677, Address: 0x2475f4, Func Offset: 0x4b4
	// Line 679, Address: 0x24760c, Func Offset: 0x4cc
	// Line 680, Address: 0x247640, Func Offset: 0x500
	// Line 679, Address: 0x247644, Func Offset: 0x504
	// Line 680, Address: 0x247648, Func Offset: 0x508
	// Line 682, Address: 0x247650, Func Offset: 0x510
	// Line 683, Address: 0x247658, Func Offset: 0x518
	// Line 684, Address: 0x24766c, Func Offset: 0x52c
	// Line 685, Address: 0x247680, Func Offset: 0x540
	// Line 689, Address: 0x247694, Func Offset: 0x554
	// Line 691, Address: 0x247698, Func Offset: 0x558
	// Line 693, Address: 0x2476ac, Func Offset: 0x56c
	// Line 694, Address: 0x2476bc, Func Offset: 0x57c
	// Line 695, Address: 0x2476c0, Func Offset: 0x580
	// Line 696, Address: 0x2476c8, Func Offset: 0x588
	// Line 698, Address: 0x2476f0, Func Offset: 0x5b0
	// Line 700, Address: 0x247704, Func Offset: 0x5c4
	// Line 702, Address: 0x247724, Func Offset: 0x5e4
	// Line 700, Address: 0x247728, Func Offset: 0x5e8
	// Line 703, Address: 0x247748, Func Offset: 0x608
	// Line 704, Address: 0x247750, Func Offset: 0x610
	// Line 708, Address: 0x247754, Func Offset: 0x614
	// Line 715, Address: 0x24775c, Func Offset: 0x61c
	// Line 716, Address: 0x247764, Func Offset: 0x624
	// Line 719, Address: 0x247768, Func Offset: 0x628
	// Line 716, Address: 0x247774, Func Offset: 0x634
	// Line 719, Address: 0x247778, Func Offset: 0x638
	// Line 720, Address: 0x24777c, Func Offset: 0x63c
	// Line 719, Address: 0x247780, Func Offset: 0x640
	// Line 720, Address: 0x247784, Func Offset: 0x644
	// Line 721, Address: 0x24778c, Func Offset: 0x64c
	// Line 722, Address: 0x247798, Func Offset: 0x658
	// Line 723, Address: 0x2477a4, Func Offset: 0x664
	// Line 724, Address: 0x2477b0, Func Offset: 0x670
	// Line 726, Address: 0x2477bc, Func Offset: 0x67c
	// Line 731, Address: 0x2477c8, Func Offset: 0x688
	// Line 732, Address: 0x2477e0, Func Offset: 0x6a0
	// Line 733, Address: 0x2477ec, Func Offset: 0x6ac
	// Line 734, Address: 0x247810, Func Offset: 0x6d0
	// Line 735, Address: 0x247844, Func Offset: 0x704
	// Line 738, Address: 0x24784c, Func Offset: 0x70c
	// Line 739, Address: 0x247850, Func Offset: 0x710
	// Line 738, Address: 0x24785c, Func Offset: 0x71c
	// Line 741, Address: 0x247860, Func Offset: 0x720
	// Line 738, Address: 0x247864, Func Offset: 0x724
	// Line 739, Address: 0x24786c, Func Offset: 0x72c
	// Line 740, Address: 0x247878, Func Offset: 0x738
	// Line 741, Address: 0x247884, Func Offset: 0x744
	// Line 742, Address: 0x24789c, Func Offset: 0x75c
	// Line 743, Address: 0x2478d0, Func Offset: 0x790
	// Line 747, Address: 0x2478d8, Func Offset: 0x798
	// Line 748, Address: 0x2478f8, Func Offset: 0x7b8
	// Line 750, Address: 0x24791c, Func Offset: 0x7dc
	// Line 751, Address: 0x247928, Func Offset: 0x7e8
	// Line 752, Address: 0x247930, Func Offset: 0x7f0
	// Line 754, Address: 0x24793c, Func Offset: 0x7fc
	// Line 758, Address: 0x247948, Func Offset: 0x808
	// Line 759, Address: 0x247960, Func Offset: 0x820
	// Line 760, Address: 0x24796c, Func Offset: 0x82c
	// Line 761, Address: 0x247990, Func Offset: 0x850
	// Line 762, Address: 0x2479c4, Func Offset: 0x884
	// Line 765, Address: 0x2479cc, Func Offset: 0x88c
	// Line 766, Address: 0x2479d4, Func Offset: 0x894
	// Line 768, Address: 0x2479e0, Func Offset: 0x8a0
	// Line 765, Address: 0x2479e4, Func Offset: 0x8a4
	// Line 766, Address: 0x2479ec, Func Offset: 0x8ac
	// Line 767, Address: 0x2479f0, Func Offset: 0x8b0
	// Line 766, Address: 0x247a00, Func Offset: 0x8c0
	// Line 767, Address: 0x247a08, Func Offset: 0x8c8
	// Line 768, Address: 0x247a14, Func Offset: 0x8d4
	// Line 769, Address: 0x247a2c, Func Offset: 0x8ec
	// Line 770, Address: 0x247a60, Func Offset: 0x920
	// Line 777, Address: 0x247a68, Func Offset: 0x928
	// Line 780, Address: 0x247a70, Func Offset: 0x930
	// Line 777, Address: 0x247a74, Func Offset: 0x934
	// Line 779, Address: 0x247a7c, Func Offset: 0x93c
	// Line 780, Address: 0x247a8c, Func Offset: 0x94c
	// Line 783, Address: 0x247a94, Func Offset: 0x954
	// Line 784, Address: 0x247af0, Func Offset: 0x9b0
	// Line 786, Address: 0x247b08, Func Offset: 0x9c8
	// Line 784, Address: 0x247b0c, Func Offset: 0x9cc
	// Line 785, Address: 0x247b10, Func Offset: 0x9d0
	// Line 784, Address: 0x247b18, Func Offset: 0x9d8
	// Line 786, Address: 0x247b1c, Func Offset: 0x9dc
	// Line 788, Address: 0x247b40, Func Offset: 0xa00
	// Line 792, Address: 0x247b4c, Func Offset: 0xa0c
	// Line 793, Address: 0x247b64, Func Offset: 0xa24
	// Line 794, Address: 0x247b70, Func Offset: 0xa30
	// Line 795, Address: 0x247b94, Func Offset: 0xa54
	// Line 796, Address: 0x247bc8, Func Offset: 0xa88
	// Line 799, Address: 0x247bd0, Func Offset: 0xa90
	// Line 800, Address: 0x247bd4, Func Offset: 0xa94
	// Line 799, Address: 0x247be0, Func Offset: 0xaa0
	// Line 802, Address: 0x247be4, Func Offset: 0xaa4
	// Line 799, Address: 0x247be8, Func Offset: 0xaa8
	// Line 800, Address: 0x247bf0, Func Offset: 0xab0
	// Line 801, Address: 0x247bfc, Func Offset: 0xabc
	// Line 802, Address: 0x247c08, Func Offset: 0xac8
	// Line 803, Address: 0x247c20, Func Offset: 0xae0
	// Line 805, Address: 0x247c58, Func Offset: 0xb18
	// Line 806, Address: 0x247c64, Func Offset: 0xb24
	// Line 810, Address: 0x247c6c, Func Offset: 0xb2c
	// Line 811, Address: 0x247c90, Func Offset: 0xb50
	// Line 812, Address: 0x247cb4, Func Offset: 0xb74
	// Line 813, Address: 0x247cc0, Func Offset: 0xb80
	// Line 817, Address: 0x247ccc, Func Offset: 0xb8c
	// Line 818, Address: 0x247ce4, Func Offset: 0xba4
	// Line 819, Address: 0x247cf0, Func Offset: 0xbb0
	// Line 820, Address: 0x247d10, Func Offset: 0xbd0
	// Line 821, Address: 0x247d44, Func Offset: 0xc04
	// Line 825, Address: 0x247d4c, Func Offset: 0xc0c
	// Line 826, Address: 0x247d58, Func Offset: 0xc18
	// Line 831, Address: 0x247d64, Func Offset: 0xc24
	// Line 827, Address: 0x247d68, Func Offset: 0xc28
	// Line 826, Address: 0x247d70, Func Offset: 0xc30
	// Line 832, Address: 0x247d74, Func Offset: 0xc34
	// Line 826, Address: 0x247d78, Func Offset: 0xc38
	// Line 827, Address: 0x247d88, Func Offset: 0xc48
	// Line 831, Address: 0x247d8c, Func Offset: 0xc4c
	// Line 832, Address: 0x247d90, Func Offset: 0xc50
	// Line 827, Address: 0x247d98, Func Offset: 0xc58
	// Line 828, Address: 0x247da0, Func Offset: 0xc60
	// Line 831, Address: 0x247dac, Func Offset: 0xc6c
	// Line 832, Address: 0x247db0, Func Offset: 0xc70
	// Line 834, Address: 0x247db4, Func Offset: 0xc74
	// Line 831, Address: 0x247db8, Func Offset: 0xc78
	// Line 834, Address: 0x247dbc, Func Offset: 0xc7c
	// Line 832, Address: 0x247dc0, Func Offset: 0xc80
	// Line 834, Address: 0x247dc4, Func Offset: 0xc84
	// Line 835, Address: 0x247dc8, Func Offset: 0xc88
	// Line 832, Address: 0x247dcc, Func Offset: 0xc8c
	// Line 835, Address: 0x247dd0, Func Offset: 0xc90
	// Line 836, Address: 0x247dd8, Func Offset: 0xc98
	// Line 837, Address: 0x247de4, Func Offset: 0xca4
	// Line 838, Address: 0x247df0, Func Offset: 0xcb0
	// Line 839, Address: 0x247dfc, Func Offset: 0xcbc
	// Line 840, Address: 0x247e04, Func Offset: 0xcc4
	// Line 841, Address: 0x247e10, Func Offset: 0xcd0
	// Line 844, Address: 0x247e18, Func Offset: 0xcd8
	// Line 846, Address: 0x247e3c, Func Offset: 0xcfc
	// Line 847, Address: 0x247e54, Func Offset: 0xd14
	// Line 848, Address: 0x247e80, Func Offset: 0xd40
	// Line 851, Address: 0x247e88, Func Offset: 0xd48
	// Line 854, Address: 0x247e90, Func Offset: 0xd50
	// Line 855, Address: 0x247e98, Func Offset: 0xd58
	// Line 872, Address: 0x247ea4, Func Offset: 0xd64
	// Line 854, Address: 0x247ea8, Func Offset: 0xd68
	// Line 855, Address: 0x247eb0, Func Offset: 0xd70
	// Line 856, Address: 0x247eb4, Func Offset: 0xd74
	// Line 859, Address: 0x247ec0, Func Offset: 0xd80
	// Line 855, Address: 0x247ec4, Func Offset: 0xd84
	// Line 856, Address: 0x247ecc, Func Offset: 0xd8c
	// Line 859, Address: 0x247ed0, Func Offset: 0xd90
	// Line 860, Address: 0x247ed4, Func Offset: 0xd94
	// Line 856, Address: 0x247ee0, Func Offset: 0xda0
	// Line 859, Address: 0x247ee8, Func Offset: 0xda8
	// Line 860, Address: 0x247eec, Func Offset: 0xdac
	// Line 862, Address: 0x247ef0, Func Offset: 0xdb0
	// Line 859, Address: 0x247ef4, Func Offset: 0xdb4
	// Line 862, Address: 0x247ef8, Func Offset: 0xdb8
	// Line 860, Address: 0x247efc, Func Offset: 0xdbc
	// Line 862, Address: 0x247f00, Func Offset: 0xdc0
	// Line 863, Address: 0x247f04, Func Offset: 0xdc4
	// Line 860, Address: 0x247f08, Func Offset: 0xdc8
	// Line 863, Address: 0x247f0c, Func Offset: 0xdcc
	// Line 864, Address: 0x247f14, Func Offset: 0xdd4
	// Line 865, Address: 0x247f20, Func Offset: 0xde0
	// Line 866, Address: 0x247f2c, Func Offset: 0xdec
	// Line 867, Address: 0x247f38, Func Offset: 0xdf8
	// Line 868, Address: 0x247f40, Func Offset: 0xe00
	// Line 869, Address: 0x247f4c, Func Offset: 0xe0c
	// Line 872, Address: 0x247f54, Func Offset: 0xe14
	// Line 873, Address: 0x247f80, Func Offset: 0xe40
	// Line 874, Address: 0x247fac, Func Offset: 0xe6c
	// Line 875, Address: 0x247fb4, Func Offset: 0xe74
	// Line 882, Address: 0x247fb8, Func Offset: 0xe78
	// Line 884, Address: 0x247fc4, Func Offset: 0xe84
	// Line 882, Address: 0x247fc8, Func Offset: 0xe88
	// Line 884, Address: 0x247fd0, Func Offset: 0xe90
	// Line 885, Address: 0x247fdc, Func Offset: 0xe9c
	// Line 887, Address: 0x247fec, Func Offset: 0xeac
	// Line 888, Address: 0x247ffc, Func Offset: 0xebc
	// Line 889, Address: 0x24800c, Func Offset: 0xecc
	// Line 890, Address: 0x248014, Func Offset: 0xed4
	// Line 891, Address: 0x248024, Func Offset: 0xee4
	// Line 892, Address: 0x248034, Func Offset: 0xef4
	// Line 893, Address: 0x24803c, Func Offset: 0xefc
	// Line 894, Address: 0x248044, Func Offset: 0xf04
	// Line 895, Address: 0x24804c, Func Offset: 0xf0c
	// Line 898, Address: 0x248060, Func Offset: 0xf20
	// Func End, Address: 0x248088, Func Offset: 0xf48
	scePrintf("bhEff301 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x248090
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no)
{
	unsigned int tmp;
	//_anon3* e02bP;
	//_anon18* e02aP;
	int set_no;
	O_WRK* oP;
	//_anon2* pdP;
	//_anon34* ptP;
	// Line 967, Address: 0x248090, Func Offset: 0
	// Line 968, Address: 0x2480ac, Func Offset: 0x1c
	// Line 967, Address: 0x2480b0, Func Offset: 0x20
	// Line 968, Address: 0x2480bc, Func Offset: 0x2c
	// Line 967, Address: 0x2480c8, Func Offset: 0x38
	// Line 969, Address: 0x2480cc, Func Offset: 0x3c
	// Line 973, Address: 0x2480d0, Func Offset: 0x40
	// Line 975, Address: 0x2480e4, Func Offset: 0x54
	// Line 979, Address: 0x248104, Func Offset: 0x74
	// Line 980, Address: 0x24810c, Func Offset: 0x7c
	// Line 981, Address: 0x248114, Func Offset: 0x84
	// Line 984, Address: 0x24811c, Func Offset: 0x8c
	// Line 985, Address: 0x248138, Func Offset: 0xa8
	// Line 986, Address: 0x248144, Func Offset: 0xb4
	// Line 987, Address: 0x248150, Func Offset: 0xc0
	// Line 989, Address: 0x24815c, Func Offset: 0xcc
	// Line 993, Address: 0x248168, Func Offset: 0xd8
	// Line 994, Address: 0x24816c, Func Offset: 0xdc
	// Line 995, Address: 0x248170, Func Offset: 0xe0
	// Line 997, Address: 0x24817c, Func Offset: 0xec
	// Line 995, Address: 0x248180, Func Offset: 0xf0
	// Line 998, Address: 0x24818c, Func Offset: 0xfc
	// Line 1011, Address: 0x248190, Func Offset: 0x100
	// Line 1015, Address: 0x248194, Func Offset: 0x104
	// Line 1007, Address: 0x248198, Func Offset: 0x108
	// Line 995, Address: 0x2481a0, Func Offset: 0x110
	// Line 996, Address: 0x2481a4, Func Offset: 0x114
	// Line 997, Address: 0x2481ac, Func Offset: 0x11c
	// Line 998, Address: 0x2481b0, Func Offset: 0x120
	// Line 999, Address: 0x2481c4, Func Offset: 0x134
	// Line 1005, Address: 0x2481dc, Func Offset: 0x14c
	// Line 1006, Address: 0x2481e4, Func Offset: 0x154
	// Line 1007, Address: 0x2481f0, Func Offset: 0x160
	// Line 1009, Address: 0x2481f8, Func Offset: 0x168
	// Line 1011, Address: 0x2481fc, Func Offset: 0x16c
	// Line 1009, Address: 0x248200, Func Offset: 0x170
	// Line 1010, Address: 0x248204, Func Offset: 0x174
	// Line 1011, Address: 0x24820c, Func Offset: 0x17c
	// Line 1015, Address: 0x24821c, Func Offset: 0x18c
	// Line 1018, Address: 0x24822c, Func Offset: 0x19c
	// Line 1019, Address: 0x248234, Func Offset: 0x1a4
	// Line 1020, Address: 0x24823c, Func Offset: 0x1ac
	// Line 1023, Address: 0x248240, Func Offset: 0x1b0
	// Line 1024, Address: 0x248264, Func Offset: 0x1d4
	// Line 1025, Address: 0x24826c, Func Offset: 0x1dc
	// Line 1026, Address: 0x248274, Func Offset: 0x1e4
	// Line 1027, Address: 0x24827c, Func Offset: 0x1ec
	// Line 1028, Address: 0x248280, Func Offset: 0x1f0
	// Line 1030, Address: 0x248284, Func Offset: 0x1f4
	// Line 1031, Address: 0x24829c, Func Offset: 0x20c
	// Line 1035, Address: 0x2482a0, Func Offset: 0x210
	// Line 1041, Address: 0x2482a8, Func Offset: 0x218
	// Line 1042, Address: 0x2482b4, Func Offset: 0x224
	// Line 1041, Address: 0x2482b8, Func Offset: 0x228
	// Line 1042, Address: 0x2482c0, Func Offset: 0x230
	// Line 1043, Address: 0x2482c8, Func Offset: 0x238
	// Line 1047, Address: 0x2482d8, Func Offset: 0x248
	// Line 1048, Address: 0x2482dc, Func Offset: 0x24c
	// Func End, Address: 0x24830c, Func Offset: 0x27c
	scePrintf("bhSetEffParticle - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x248310
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
	unsigned int tmp;
	//_anon3* e02bP;
	//_anon18* e02aP;
	int set_no;
	O_WRK* oP;
	//_anon2* pdP;
	//_anon34* ptP;
	// Line 1054, Address: 0x248310, Func Offset: 0
	// Line 1059, Address: 0x24832c, Func Offset: 0x1c
	// Line 1054, Address: 0x248330, Func Offset: 0x20
	// Line 1059, Address: 0x24833c, Func Offset: 0x2c
	// Line 1054, Address: 0x248348, Func Offset: 0x38
	// Line 1060, Address: 0x24834c, Func Offset: 0x3c
	// Line 1065, Address: 0x248350, Func Offset: 0x40
	// Line 1067, Address: 0x248368, Func Offset: 0x58
	// Line 1071, Address: 0x24838c, Func Offset: 0x7c
	// Line 1072, Address: 0x248394, Func Offset: 0x84
	// Line 1073, Address: 0x24839c, Func Offset: 0x8c
	// Line 1076, Address: 0x2483a4, Func Offset: 0x94
	// Line 1077, Address: 0x2483c0, Func Offset: 0xb0
	// Line 1078, Address: 0x2483cc, Func Offset: 0xbc
	// Line 1079, Address: 0x2483d8, Func Offset: 0xc8
	// Line 1081, Address: 0x2483e4, Func Offset: 0xd4
	// Line 1085, Address: 0x2483f0, Func Offset: 0xe0
	// Line 1086, Address: 0x2483f4, Func Offset: 0xe4
	// Line 1087, Address: 0x2483f8, Func Offset: 0xe8
	// Line 1089, Address: 0x248404, Func Offset: 0xf4
	// Line 1087, Address: 0x248408, Func Offset: 0xf8
	// Line 1090, Address: 0x248414, Func Offset: 0x104
	// Line 1103, Address: 0x248418, Func Offset: 0x108
	// Line 1099, Address: 0x24841c, Func Offset: 0x10c
	// Line 1087, Address: 0x248424, Func Offset: 0x114
	// Line 1088, Address: 0x248428, Func Offset: 0x118
	// Line 1089, Address: 0x248430, Func Offset: 0x120
	// Line 1090, Address: 0x248434, Func Offset: 0x124
	// Line 1091, Address: 0x248448, Func Offset: 0x138
	// Line 1097, Address: 0x248460, Func Offset: 0x150
	// Line 1098, Address: 0x248468, Func Offset: 0x158
	// Line 1099, Address: 0x248474, Func Offset: 0x164
	// Line 1101, Address: 0x24847c, Func Offset: 0x16c
	// Line 1103, Address: 0x248480, Func Offset: 0x170
	// Line 1101, Address: 0x248484, Func Offset: 0x174
	// Line 1102, Address: 0x248488, Func Offset: 0x178
	// Line 1103, Address: 0x248494, Func Offset: 0x184
	// Line 1110, Address: 0x2484a4, Func Offset: 0x194
	// Line 1111, Address: 0x2484ac, Func Offset: 0x19c
	// Line 1112, Address: 0x2484b4, Func Offset: 0x1a4
	// Line 1119, Address: 0x2484b8, Func Offset: 0x1a8
	// Line 1120, Address: 0x2484dc, Func Offset: 0x1cc
	// Line 1121, Address: 0x2484e4, Func Offset: 0x1d4
	// Line 1122, Address: 0x2484ec, Func Offset: 0x1dc
	// Line 1123, Address: 0x2484f4, Func Offset: 0x1e4
	// Line 1124, Address: 0x2484f8, Func Offset: 0x1e8
	// Line 1126, Address: 0x2484fc, Func Offset: 0x1ec
	// Line 1127, Address: 0x248514, Func Offset: 0x204
	// Line 1131, Address: 0x248518, Func Offset: 0x208
	// Line 1137, Address: 0x248520, Func Offset: 0x210
	// Line 1138, Address: 0x24852c, Func Offset: 0x21c
	// Line 1137, Address: 0x248530, Func Offset: 0x220
	// Line 1138, Address: 0x248538, Func Offset: 0x228
	// Line 1139, Address: 0x248540, Func Offset: 0x230
	// Line 1143, Address: 0x248550, Func Offset: 0x240
	// Line 1145, Address: 0x248554, Func Offset: 0x244
	// Func End, Address: 0x248584, Func Offset: 0x274
	scePrintf("bhSetEffParticleMk2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x248590
void bhEff302(O_WRK* oP)
{
	float spd;
	NJS_POINT3* dP;
	int stg_stt;
	float* spdP;
	NJS_POINT3* dirP;
	NJS_POINT3* grvP;
	NJS_POINT3* posP;
	int stg_vtx;
	int vtx_num;
	float s_rnd;
	float p_rnd;
	float b_spd;
	//float* spdP;
	//NJS_POINT3* posP;
	int i;
	//NJS_POINT3* grvP;
	int* timP;
	int stg_no;
	//_anon18* e02aP;
	int* subP;
	int* addP;
	int cnt;
	int dst;
	int src;
	int tmp;
	int az;
	int ay;
	int ax;
	//NJS_POINT3* dirP;
	float** spdPP;
	NJS_POINT3** bufPP;
	//int* timP;
	//int i;
	//_anon7* prmP;
	//_anon3* e02bP;
	//_anon18* e02aP;
	// Line 1201, Address: 0x248590, Func Offset: 0
	// Line 1203, Address: 0x2485cc, Func Offset: 0x3c
	// Line 1207, Address: 0x2485ec, Func Offset: 0x5c
	// Line 1209, Address: 0x2485f0, Func Offset: 0x60
	// Line 1208, Address: 0x2485f8, Func Offset: 0x68
	// Line 1209, Address: 0x2485fc, Func Offset: 0x6c
	// Line 1227, Address: 0x248600, Func Offset: 0x70
	// Line 1230, Address: 0x248608, Func Offset: 0x78
	// Line 1231, Address: 0x24860c, Func Offset: 0x7c
	// Line 1214, Address: 0x248610, Func Offset: 0x80
	// Line 1209, Address: 0x248614, Func Offset: 0x84
	// Line 1214, Address: 0x248618, Func Offset: 0x88
	// Line 1209, Address: 0x24861c, Func Offset: 0x8c
	// Line 1214, Address: 0x248620, Func Offset: 0x90
	// Line 1215, Address: 0x248624, Func Offset: 0x94
	// Line 1209, Address: 0x248628, Func Offset: 0x98
	// Line 1232, Address: 0x248630, Func Offset: 0xa0
	// Line 1215, Address: 0x248634, Func Offset: 0xa4
	// Line 1216, Address: 0x248638, Func Offset: 0xa8
	// Line 1234, Address: 0x24863c, Func Offset: 0xac
	// Line 1216, Address: 0x248644, Func Offset: 0xb4
	// Line 1217, Address: 0x248648, Func Offset: 0xb8
	// Line 1218, Address: 0x248650, Func Offset: 0xc0
	// Line 1219, Address: 0x248658, Func Offset: 0xc8
	// Line 1220, Address: 0x248670, Func Offset: 0xe0
	// Line 1221, Address: 0x248678, Func Offset: 0xe8
	// Line 1222, Address: 0x248680, Func Offset: 0xf0
	// Line 1223, Address: 0x248688, Func Offset: 0xf8
	// Line 1224, Address: 0x2486a0, Func Offset: 0x110
	// Line 1226, Address: 0x2486a8, Func Offset: 0x118
	// Line 1227, Address: 0x2486b0, Func Offset: 0x120
	// Line 1235, Address: 0x2486bc, Func Offset: 0x12c
	// Line 1236, Address: 0x2486c4, Func Offset: 0x134
	// Line 1235, Address: 0x2486c8, Func Offset: 0x138
	// Line 1237, Address: 0x2486d0, Func Offset: 0x140
	// Line 1236, Address: 0x2486d4, Func Offset: 0x144
	// Line 1237, Address: 0x2486d8, Func Offset: 0x148
	// Line 1238, Address: 0x2486dc, Func Offset: 0x14c
	// Line 1239, Address: 0x2486f0, Func Offset: 0x160
	// Line 1238, Address: 0x2486f8, Func Offset: 0x168
	// Line 1239, Address: 0x248700, Func Offset: 0x170
	// Line 1243, Address: 0x248710, Func Offset: 0x180
	// Line 1245, Address: 0x248714, Func Offset: 0x184
	// Line 1246, Address: 0x248718, Func Offset: 0x188
	// Line 1247, Address: 0x248764, Func Offset: 0x1d4
	// Line 1248, Address: 0x2487b0, Func Offset: 0x220
	// Line 1250, Address: 0x2487fc, Func Offset: 0x26c
	// Line 1248, Address: 0x248808, Func Offset: 0x278
	// Line 1251, Address: 0x24880c, Func Offset: 0x27c
	// Line 1250, Address: 0x248814, Func Offset: 0x284
	// Line 1251, Address: 0x24881c, Func Offset: 0x28c
	// Line 1252, Address: 0x248824, Func Offset: 0x294
	// Line 1253, Address: 0x24883c, Func Offset: 0x2ac
	// Line 1254, Address: 0x248850, Func Offset: 0x2c0
	// Line 1262, Address: 0x24885c, Func Offset: 0x2cc
	// Line 1263, Address: 0x248860, Func Offset: 0x2d0
	// Line 1261, Address: 0x248864, Func Offset: 0x2d4
	// Line 1264, Address: 0x248868, Func Offset: 0x2d8
	// Line 1265, Address: 0x24886c, Func Offset: 0x2dc
	// Line 1267, Address: 0x248870, Func Offset: 0x2e0
	// Line 1268, Address: 0x24888c, Func Offset: 0x2fc
	// Line 1269, Address: 0x2488a8, Func Offset: 0x318
	// Line 1271, Address: 0x2488b0, Func Offset: 0x320
	// Line 1272, Address: 0x2488cc, Func Offset: 0x33c
	// Line 1273, Address: 0x2488f0, Func Offset: 0x360
	// Line 1275, Address: 0x248900, Func Offset: 0x370
	// Line 1276, Address: 0x248920, Func Offset: 0x390
	// Line 1277, Address: 0x24894c, Func Offset: 0x3bc
	// Line 1279, Address: 0x248960, Func Offset: 0x3d0
	// Line 1280, Address: 0x248968, Func Offset: 0x3d8
	// Line 1281, Address: 0x248984, Func Offset: 0x3f4
	// Line 1282, Address: 0x2489ac, Func Offset: 0x41c
	// Line 1287, Address: 0x2489c0, Func Offset: 0x430
	// Line 1288, Address: 0x2489c8, Func Offset: 0x438
	// Line 1292, Address: 0x2489d0, Func Offset: 0x440
	// Line 1306, Address: 0x2489d4, Func Offset: 0x444
	// Line 1307, Address: 0x2489d8, Func Offset: 0x448
	// Line 1308, Address: 0x2489e0, Func Offset: 0x450
	// Line 1310, Address: 0x2489f0, Func Offset: 0x460
	// Line 1307, Address: 0x2489f4, Func Offset: 0x464
	// Line 1310, Address: 0x2489f8, Func Offset: 0x468
	// Line 1312, Address: 0x248a00, Func Offset: 0x470
	// Line 1315, Address: 0x248a0c, Func Offset: 0x47c
	// Line 1317, Address: 0x248a14, Func Offset: 0x484
	// Line 1318, Address: 0x248a18, Func Offset: 0x488
	// Line 1319, Address: 0x248a1c, Func Offset: 0x48c
	// Line 1320, Address: 0x248a20, Func Offset: 0x490
	// Line 1321, Address: 0x248a24, Func Offset: 0x494
	// Line 1323, Address: 0x248a28, Func Offset: 0x498
	// Line 1324, Address: 0x248a30, Func Offset: 0x4a0
	// Line 1325, Address: 0x248a44, Func Offset: 0x4b4
	// Line 1326, Address: 0x248a7c, Func Offset: 0x4ec
	// Line 1327, Address: 0x248ab4, Func Offset: 0x524
	// Line 1329, Address: 0x248aec, Func Offset: 0x55c
	// Line 1330, Address: 0x248b08, Func Offset: 0x578
	// Line 1329, Address: 0x248b10, Func Offset: 0x580
	// Line 1330, Address: 0x248b34, Func Offset: 0x5a4
	// Line 1332, Address: 0x248b3c, Func Offset: 0x5ac
	// Line 1333, Address: 0x248b48, Func Offset: 0x5b8
	// Line 1334, Address: 0x248b54, Func Offset: 0x5c4
	// Line 1335, Address: 0x248b5c, Func Offset: 0x5cc
	// Line 1337, Address: 0x248b60, Func Offset: 0x5d0
	// Line 1338, Address: 0x248b68, Func Offset: 0x5d8
	// Line 1340, Address: 0x248b78, Func Offset: 0x5e8
	// Line 1343, Address: 0x248b84, Func Offset: 0x5f4
	// Line 1344, Address: 0x248b94, Func Offset: 0x604
	// Line 1347, Address: 0x248ba4, Func Offset: 0x614
	// Line 1348, Address: 0x248bd0, Func Offset: 0x640
	// Line 1350, Address: 0x248bdc, Func Offset: 0x64c
	// Line 1351, Address: 0x248be4, Func Offset: 0x654
	// Line 1352, Address: 0x248bec, Func Offset: 0x65c
	// Line 1354, Address: 0x248bf0, Func Offset: 0x660
	// Line 1352, Address: 0x248bf4, Func Offset: 0x664
	// Line 1353, Address: 0x248bfc, Func Offset: 0x66c
	// Line 1354, Address: 0x248c08, Func Offset: 0x678
	// Line 1357, Address: 0x248c0c, Func Offset: 0x67c
	// Line 1359, Address: 0x248c10, Func Offset: 0x680
	// Line 1360, Address: 0x248c14, Func Offset: 0x684
	// Line 1359, Address: 0x248c18, Func Offset: 0x688
	// Line 1360, Address: 0x248c1c, Func Offset: 0x68c
	// Line 1359, Address: 0x248c20, Func Offset: 0x690
	// Line 1360, Address: 0x248c28, Func Offset: 0x698
	// Line 1363, Address: 0x248c38, Func Offset: 0x6a8
	// Line 1371, Address: 0x248c44, Func Offset: 0x6b4
	// Line 1379, Address: 0x248c48, Func Offset: 0x6b8
	// Line 1377, Address: 0x248c4c, Func Offset: 0x6bc
	// Line 1373, Address: 0x248c50, Func Offset: 0x6c0
	// Line 1374, Address: 0x248c5c, Func Offset: 0x6cc
	// Line 1375, Address: 0x248c60, Func Offset: 0x6d0
	// Line 1379, Address: 0x248c70, Func Offset: 0x6e0
	// Line 1382, Address: 0x248c78, Func Offset: 0x6e8
	// Line 1383, Address: 0x248c7c, Func Offset: 0x6ec
	// Line 1386, Address: 0x248cb4, Func Offset: 0x724
	// Line 1387, Address: 0x248cc4, Func Offset: 0x734
	// Line 1390, Address: 0x248cc8, Func Offset: 0x738
	// Line 1391, Address: 0x248cd4, Func Offset: 0x744
	// Line 1390, Address: 0x248cd8, Func Offset: 0x748
	// Line 1393, Address: 0x248ce0, Func Offset: 0x750
	// Line 1397, Address: 0x248ce8, Func Offset: 0x758
	// Line 1393, Address: 0x248cf0, Func Offset: 0x760
	// Line 1394, Address: 0x248cfc, Func Offset: 0x76c
	// Line 1395, Address: 0x248d10, Func Offset: 0x780
	// Line 1397, Address: 0x248d20, Func Offset: 0x790
	// Line 1398, Address: 0x248d28, Func Offset: 0x798
	// Line 1399, Address: 0x248d2c, Func Offset: 0x79c
	// Line 1398, Address: 0x248d38, Func Offset: 0x7a8
	// Line 1399, Address: 0x248d40, Func Offset: 0x7b0
	// Line 1400, Address: 0x248d48, Func Offset: 0x7b8
	// Line 1403, Address: 0x248d50, Func Offset: 0x7c0
	// Line 1405, Address: 0x248d58, Func Offset: 0x7c8
	// Line 1412, Address: 0x248d6c, Func Offset: 0x7dc
	// Func End, Address: 0x248da8, Func Offset: 0x818
	scePrintf("bhEff302 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x248db0
void bhEff_PtclSpriteDrawB(O_WRK* oP)
{
	NJS_POINT3* bufP;
	float scl;
	int stg_num;
	int stg_no;
	//_anon18* e02aP;
	// Line 1422, Address: 0x248db0, Func Offset: 0
	// Line 1423, Address: 0x248dd4, Func Offset: 0x24
	// Line 1426, Address: 0x248ddc, Func Offset: 0x2c
	// Line 1427, Address: 0x248de4, Func Offset: 0x34
	// Line 1428, Address: 0x248df0, Func Offset: 0x40
	// Line 1431, Address: 0x248dfc, Func Offset: 0x4c
	// Line 1432, Address: 0x248e04, Func Offset: 0x54
	// Line 1433, Address: 0x248e14, Func Offset: 0x64
	// Line 1463, Address: 0x248e1c, Func Offset: 0x6c
	// Line 1467, Address: 0x248e30, Func Offset: 0x80
	// Line 1464, Address: 0x248e3c, Func Offset: 0x8c
	// Line 1465, Address: 0x248e40, Func Offset: 0x90
	// Line 1467, Address: 0x248e44, Func Offset: 0x94
	// Line 1468, Address: 0x248e54, Func Offset: 0xa4
	// Line 1469, Address: 0x248e68, Func Offset: 0xb8
	// Line 1470, Address: 0x248e7c, Func Offset: 0xcc
	// Line 1471, Address: 0x248e90, Func Offset: 0xe0
	// Line 1472, Address: 0x248ea4, Func Offset: 0xf4
	// Line 1473, Address: 0x248eac, Func Offset: 0xfc
	// Line 1472, Address: 0x248eb0, Func Offset: 0x100
	// Line 1473, Address: 0x248eb4, Func Offset: 0x104
	// Line 1479, Address: 0x248ec0, Func Offset: 0x110
	// Line 1481, Address: 0x248ec8, Func Offset: 0x118
	// Func End, Address: 0x248ef0, Func Offset: 0x140
	scePrintf("bhEff_PtclSpriteDrawB - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x248ef0
void bhEff_PtclLineDraw(O_WRK* oP)
{
	float* pntP;
	float scl;
	float spd;
	NJS_POINT3 vct;
	NJS_POINT3* grvP;
	NJS_POINT3* p3P;
	NJS_POINT3* dirP;
	float* spdP;
	int i;
	int col;
	int* colP;
	//_anon62* p3cP;
	int stg_no;
	int stg_num;
	//_anon18* e02aP;
	// Line 1491, Address: 0x248ef0, Func Offset: 0
	// Line 1492, Address: 0x248f20, Func Offset: 0x30
	// Line 1494, Address: 0x248f24, Func Offset: 0x34
	// Line 1497, Address: 0x248f34, Func Offset: 0x44
	// Line 1501, Address: 0x248f38, Func Offset: 0x48
	// Line 1497, Address: 0x248f3c, Func Offset: 0x4c
	// Line 1498, Address: 0x248f40, Func Offset: 0x50
	// Line 1502, Address: 0x248f48, Func Offset: 0x58
	// Line 1501, Address: 0x248f4c, Func Offset: 0x5c
	// Line 1502, Address: 0x248f50, Func Offset: 0x60
	// Line 1504, Address: 0x248f54, Func Offset: 0x64
	// Line 1503, Address: 0x248f58, Func Offset: 0x68
	// Line 1504, Address: 0x248f5c, Func Offset: 0x6c
	// Line 1506, Address: 0x248f60, Func Offset: 0x70
	// Line 1522, Address: 0x248f90, Func Offset: 0xa0
	// Line 1510, Address: 0x248f94, Func Offset: 0xa4
	// Line 1520, Address: 0x248f98, Func Offset: 0xa8
	// Line 1524, Address: 0x248f9c, Func Offset: 0xac
	// Line 1522, Address: 0x248fa0, Func Offset: 0xb0
	// Line 1512, Address: 0x248fa4, Func Offset: 0xb4
	// Line 1513, Address: 0x248fb0, Func Offset: 0xc0
	// Line 1519, Address: 0x248fb4, Func Offset: 0xc4
	// Line 1521, Address: 0x248fb8, Func Offset: 0xc8
	// Line 1526, Address: 0x248fc0, Func Offset: 0xd0
	// Line 1527, Address: 0x248fc4, Func Offset: 0xd4
	// Line 1530, Address: 0x248fc8, Func Offset: 0xd8
	// Line 1527, Address: 0x248fcc, Func Offset: 0xdc
	// Line 1532, Address: 0x248fd4, Func Offset: 0xe4
	// Line 1527, Address: 0x248fd8, Func Offset: 0xe8
	// Line 1530, Address: 0x248fdc, Func Offset: 0xec
	// Line 1531, Address: 0x248fe4, Func Offset: 0xf4
	// Line 1527, Address: 0x248fe8, Func Offset: 0xf8
	// Line 1528, Address: 0x248fec, Func Offset: 0xfc
	// Line 1530, Address: 0x248ff0, Func Offset: 0x100
	// Line 1532, Address: 0x248ff8, Func Offset: 0x108
	// Line 1530, Address: 0x248ffc, Func Offset: 0x10c
	// Line 1531, Address: 0x249000, Func Offset: 0x110
	// Line 1532, Address: 0x249024, Func Offset: 0x134
	// Line 1534, Address: 0x24902c, Func Offset: 0x13c
	// Line 1535, Address: 0x249034, Func Offset: 0x144
	// Line 1538, Address: 0x249038, Func Offset: 0x148
	// Line 1534, Address: 0x24903c, Func Offset: 0x14c
	// Line 1535, Address: 0x249048, Func Offset: 0x158
	// Line 1536, Address: 0x249054, Func Offset: 0x164
	// Line 1535, Address: 0x249058, Func Offset: 0x168
	// Line 1536, Address: 0x249060, Func Offset: 0x170
	// Line 1538, Address: 0x249074, Func Offset: 0x184
	// Line 1539, Address: 0x249080, Func Offset: 0x190
	// Line 1542, Address: 0x2490a4, Func Offset: 0x1b4
	// Line 1547, Address: 0x2490c8, Func Offset: 0x1d8
	// Func End, Address: 0x2490fc, Func Offset: 0x20c
	scePrintf("bhEff_PtclLineDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x249100
void bhEff303(O_WRK* oP)
{
	//_anon40* prmP;
	//_anon21* dspP;
	//_anon20* anmP;
	//_anon40 PrmTbl[8];
	// Line 1557, Address: 0x249100, Func Offset: 0
	// Line 1581, Address: 0x249118, Func Offset: 0x18
	// Line 1571, Address: 0x249120, Func Offset: 0x20
	// Line 1581, Address: 0x249124, Func Offset: 0x24
	// Line 1588, Address: 0x249154, Func Offset: 0x54
	// Line 1585, Address: 0x249158, Func Offset: 0x58
	// Line 1588, Address: 0x24915c, Func Offset: 0x5c
	// Line 1585, Address: 0x249160, Func Offset: 0x60
	// Line 1589, Address: 0x249168, Func Offset: 0x68
	// Line 1588, Address: 0x249174, Func Offset: 0x74
	// Line 1585, Address: 0x24917c, Func Offset: 0x7c
	// Line 1588, Address: 0x249184, Func Offset: 0x84
	// Line 1593, Address: 0x249188, Func Offset: 0x88
	// Line 1588, Address: 0x24918c, Func Offset: 0x8c
	// Line 1593, Address: 0x249190, Func Offset: 0x90
	// Line 1589, Address: 0x249194, Func Offset: 0x94
	// Line 1592, Address: 0x249198, Func Offset: 0x98
	// Line 1594, Address: 0x24919c, Func Offset: 0x9c
	// Line 1588, Address: 0x2491a0, Func Offset: 0xa0
	// Line 1589, Address: 0x2491ac, Func Offset: 0xac
	// Line 1595, Address: 0x2491b4, Func Offset: 0xb4
	// Line 1599, Address: 0x2491b8, Func Offset: 0xb8
	// Line 1589, Address: 0x2491bc, Func Offset: 0xbc
	// Line 1601, Address: 0x2491c8, Func Offset: 0xc8
	// Line 1608, Address: 0x2491d0, Func Offset: 0xd0
	// Line 1611, Address: 0x2491d4, Func Offset: 0xd4
	// Line 1589, Address: 0x2491d8, Func Offset: 0xd8
	// Line 1611, Address: 0x2491dc, Func Offset: 0xdc
	// Line 1613, Address: 0x2491e0, Func Offset: 0xe0
	// Line 1589, Address: 0x2491e4, Func Offset: 0xe4
	// Line 1592, Address: 0x2491f0, Func Offset: 0xf0
	// Line 1593, Address: 0x2491f4, Func Offset: 0xf4
	// Line 1594, Address: 0x2491f8, Func Offset: 0xf8
	// Line 1595, Address: 0x2491fc, Func Offset: 0xfc
	// Line 1596, Address: 0x249200, Func Offset: 0x100
	// Line 1597, Address: 0x24920c, Func Offset: 0x10c
	// Line 1598, Address: 0x249214, Func Offset: 0x114
	// Line 1599, Address: 0x24921c, Func Offset: 0x11c
	// Line 1601, Address: 0x249220, Func Offset: 0x120
	// Line 1602, Address: 0x24922c, Func Offset: 0x12c
	// Line 1605, Address: 0x249238, Func Offset: 0x138
	// Line 1608, Address: 0x249240, Func Offset: 0x140
	// Line 1609, Address: 0x249244, Func Offset: 0x144
	// Line 1611, Address: 0x249250, Func Offset: 0x150
	// Line 1612, Address: 0x249254, Func Offset: 0x154
	// Line 1613, Address: 0x24925c, Func Offset: 0x15c
	// Line 1615, Address: 0x249270, Func Offset: 0x170
	// Line 1617, Address: 0x249284, Func Offset: 0x184
	// Line 1619, Address: 0x249294, Func Offset: 0x194
	// Line 1620, Address: 0x24929c, Func Offset: 0x19c
	// Line 1623, Address: 0x2492a4, Func Offset: 0x1a4
	// Line 1625, Address: 0x2492dc, Func Offset: 0x1dc
	// Line 1626, Address: 0x2492ec, Func Offset: 0x1ec
	// Line 1628, Address: 0x249308, Func Offset: 0x208
	// Line 1629, Address: 0x24933c, Func Offset: 0x23c
	// Line 1632, Address: 0x249344, Func Offset: 0x244
	// Line 1633, Address: 0x24937c, Func Offset: 0x27c
	// Line 1634, Address: 0x249388, Func Offset: 0x288
	// Line 1636, Address: 0x24939c, Func Offset: 0x29c
	// Line 1639, Address: 0x2493a4, Func Offset: 0x2a4
	// Line 1640, Address: 0x2493b4, Func Offset: 0x2b4
	// Line 1642, Address: 0x2493bc, Func Offset: 0x2bc
	// Line 1640, Address: 0x2493c8, Func Offset: 0x2c8
	// Line 1641, Address: 0x2493d0, Func Offset: 0x2d0
	// Line 1642, Address: 0x2493dc, Func Offset: 0x2dc
	// Line 1643, Address: 0x2493e4, Func Offset: 0x2e4
	// Line 1644, Address: 0x249418, Func Offset: 0x318
	// Line 1645, Address: 0x249420, Func Offset: 0x320
	// Line 1649, Address: 0x249424, Func Offset: 0x324
	// Func End, Address: 0x24943c, Func Offset: 0x33c
	scePrintf("bhEff303 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x249440
int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y)
{
	//_anon73 lne;
	//_anon73 pln;
	// Line 1663, Address: 0x249440, Func Offset: 0
	// Line 1671, Address: 0x24945c, Func Offset: 0x1c
	// Line 1672, Address: 0x24947c, Func Offset: 0x3c
	// Line 1674, Address: 0x249494, Func Offset: 0x54
	// Line 1675, Address: 0x2494bc, Func Offset: 0x7c
	// Line 1676, Address: 0x2494e8, Func Offset: 0xa8
	// Line 1677, Address: 0x249510, Func Offset: 0xd0
	// Line 1678, Address: 0x249538, Func Offset: 0xf8
	// Line 1679, Address: 0x249548, Func Offset: 0x108
	// Line 1680, Address: 0x249554, Func Offset: 0x114
	// Line 1679, Address: 0x249560, Func Offset: 0x120
	// Line 1681, Address: 0x249564, Func Offset: 0x124
	// Line 1679, Address: 0x249568, Func Offset: 0x128
	// Line 1680, Address: 0x249574, Func Offset: 0x134
	// Line 1681, Address: 0x249584, Func Offset: 0x144
	// Line 1686, Address: 0x24958c, Func Offset: 0x14c
	// Line 1687, Address: 0x249590, Func Offset: 0x150
	// Func End, Address: 0x2495ac, Func Offset: 0x16c
	scePrintf("bhCheckCamWall2D - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2495b0
O_WRK* rySetShadow(BH_PWORK* ewP, int obj0, int obj1, int obj2, float off_a, float off_b)
{
	//_anon53* owP;
	O_WRK* oP;
	// Line 1708, Address: 0x2495b0, Func Offset: 0
	// Line 1712, Address: 0x2495e4, Func Offset: 0x34
	// Line 1713, Address: 0x2495f4, Func Offset: 0x44
	// Line 1714, Address: 0x249600, Func Offset: 0x50
	// Line 1716, Address: 0x249608, Func Offset: 0x58
	// Line 1715, Address: 0x24960c, Func Offset: 0x5c
	// Line 1716, Address: 0x249610, Func Offset: 0x60
	// Line 1717, Address: 0x249614, Func Offset: 0x64
	// Line 1718, Address: 0x249618, Func Offset: 0x68
	// Line 1719, Address: 0x249628, Func Offset: 0x78
	// Line 1720, Address: 0x249634, Func Offset: 0x84
	// Line 1722, Address: 0x249640, Func Offset: 0x90
	// Line 1738, Address: 0x249648, Func Offset: 0x98
	// Line 1727, Address: 0x24964c, Func Offset: 0x9c
	// Line 1738, Address: 0x249650, Func Offset: 0xa0
	// Line 1722, Address: 0x249654, Func Offset: 0xa4
	// Line 1723, Address: 0x249664, Func Offset: 0xb4
	// Line 1724, Address: 0x249668, Func Offset: 0xb8
	// Line 1727, Address: 0x24966c, Func Offset: 0xbc
	// Line 1733, Address: 0x249670, Func Offset: 0xc0
	// Line 1734, Address: 0x249674, Func Offset: 0xc4
	// Line 1737, Address: 0x249678, Func Offset: 0xc8
	// Line 1738, Address: 0x24967c, Func Offset: 0xcc
	// Line 1739, Address: 0x249680, Func Offset: 0xd0
	// Line 1737, Address: 0x24968c, Func Offset: 0xdc
	// Line 1740, Address: 0x249690, Func Offset: 0xe0
	// Line 1738, Address: 0x24969c, Func Offset: 0xec
	// Line 1739, Address: 0x2496a0, Func Offset: 0xf0
	// Line 1738, Address: 0x2496a4, Func Offset: 0xf4
	// Line 1740, Address: 0x2496a8, Func Offset: 0xf8
	// Line 1739, Address: 0x2496ac, Func Offset: 0xfc
	// Line 1738, Address: 0x2496b0, Func Offset: 0x100
	// Line 1740, Address: 0x2496b4, Func Offset: 0x104
	// Line 1739, Address: 0x2496b8, Func Offset: 0x108
	// Line 1740, Address: 0x2496bc, Func Offset: 0x10c
	// Line 1744, Address: 0x2496c0, Func Offset: 0x110
	// Func End, Address: 0x2496e4, Func Offset: 0x134
	scePrintf("rySetShadow - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2496f0
void bhEff304(O_WRK* oP)
{
	BH_PWORK* ewP;
	NJS_POINT3 dlt;
	NJS_POINT3 pos;
	NJS_POINT3 vct;
	float tmp;
	NJS_POINT3* p2P;
	//float tmp;
	NJS_POINT3* p1P;
	NJS_POINT3* p0P;
	float rb;
	float ra;
	NJS_POINT3* pbP;
	NJS_POINT3* paP;
	NJS_POINT3 pp;
	// Line 1754, Address: 0x2496f0, Func Offset: 0
	// Line 1764, Address: 0x249714, Func Offset: 0x24
	// Line 1765, Address: 0x249718, Func Offset: 0x28
	// Line 1768, Address: 0x24971c, Func Offset: 0x2c
	// Line 1770, Address: 0x249724, Func Offset: 0x34
	// Line 1768, Address: 0x249728, Func Offset: 0x38
	// Line 1769, Address: 0x24973c, Func Offset: 0x4c
	// Line 1770, Address: 0x249750, Func Offset: 0x60
	// Line 1782, Address: 0x249764, Func Offset: 0x74
	// Line 1788, Address: 0x249768, Func Offset: 0x78
	// Line 1772, Address: 0x24976c, Func Offset: 0x7c
	// Line 1774, Address: 0x249774, Func Offset: 0x84
	// Line 1788, Address: 0x24977c, Func Offset: 0x8c
	// Line 1786, Address: 0x249780, Func Offset: 0x90
	// Line 1772, Address: 0x249788, Func Offset: 0x98
	// Line 1774, Address: 0x24978c, Func Offset: 0x9c
	// Line 1786, Address: 0x249790, Func Offset: 0xa0
	// Line 1788, Address: 0x249794, Func Offset: 0xa4
	// Line 1775, Address: 0x249798, Func Offset: 0xa8
	// Line 1773, Address: 0x24979c, Func Offset: 0xac
	// Line 1787, Address: 0x2497a0, Func Offset: 0xb0
	// Line 1789, Address: 0x2497a4, Func Offset: 0xb4
	// Line 1775, Address: 0x2497ac, Func Offset: 0xbc
	// Line 1791, Address: 0x2497b0, Func Offset: 0xc0
	// Line 1795, Address: 0x2497c0, Func Offset: 0xd0
	// Line 1796, Address: 0x2497c4, Func Offset: 0xd4
	// Line 1793, Address: 0x2497c8, Func Offset: 0xd8
	// Line 1797, Address: 0x2497cc, Func Offset: 0xdc
	// Line 1792, Address: 0x2497d0, Func Offset: 0xe0
	// Line 1801, Address: 0x2497d4, Func Offset: 0xe4
	// Line 1802, Address: 0x2497dc, Func Offset: 0xec
	// Line 1808, Address: 0x2497ec, Func Offset: 0xfc
	// Line 1809, Address: 0x2497fc, Func Offset: 0x10c
	// Line 1808, Address: 0x249800, Func Offset: 0x110
	// Line 1809, Address: 0x249808, Func Offset: 0x118
	// Line 1811, Address: 0x249810, Func Offset: 0x120
	// Line 1817, Address: 0x249838, Func Offset: 0x148
	// Line 1820, Address: 0x249848, Func Offset: 0x158
	// Line 1817, Address: 0x24984c, Func Offset: 0x15c
	// Line 1829, Address: 0x249850, Func Offset: 0x160
	// Line 1830, Address: 0x249854, Func Offset: 0x164
	// Line 1817, Address: 0x249858, Func Offset: 0x168
	// Line 1832, Address: 0x24985c, Func Offset: 0x16c
	// Line 1817, Address: 0x249864, Func Offset: 0x174
	// Line 1818, Address: 0x24986c, Func Offset: 0x17c
	// Line 1820, Address: 0x249884, Func Offset: 0x194
	// Line 1828, Address: 0x24989c, Func Offset: 0x1ac
	// Line 1829, Address: 0x2498a4, Func Offset: 0x1b4
	// Line 1828, Address: 0x2498a8, Func Offset: 0x1b8
	// Line 1829, Address: 0x2498b4, Func Offset: 0x1c4
	// Line 1830, Address: 0x2498c4, Func Offset: 0x1d4
	// Line 1832, Address: 0x2498d4, Func Offset: 0x1e4
	// Line 1833, Address: 0x2498ec, Func Offset: 0x1fc
	// Line 1834, Address: 0x249908, Func Offset: 0x218
	// Line 1835, Address: 0x24991c, Func Offset: 0x22c
	// Line 1836, Address: 0x24992c, Func Offset: 0x23c
	// Line 1837, Address: 0x249934, Func Offset: 0x244
	// Line 1841, Address: 0x249950, Func Offset: 0x260
	// Line 1842, Address: 0x24995c, Func Offset: 0x26c
	// Line 1849, Address: 0x249968, Func Offset: 0x278
	// Line 1851, Address: 0x24996c, Func Offset: 0x27c
	// Line 1853, Address: 0x249984, Func Offset: 0x294
	// Line 1854, Address: 0x2499b4, Func Offset: 0x2c4
	// Line 1856, Address: 0x2499c8, Func Offset: 0x2d8
	// Line 1857, Address: 0x2499d4, Func Offset: 0x2e4
	// Line 1856, Address: 0x2499d8, Func Offset: 0x2e8
	// Line 1857, Address: 0x2499e0, Func Offset: 0x2f0
	// Line 1862, Address: 0x249a14, Func Offset: 0x324
	// Func End, Address: 0x249a3c, Func Offset: 0x34c
	scePrintf("bhEff304 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x249a40
void bhEff305(O_WRK* oP)
{
	unsigned int col;
	//_anon6* tvP;
	//_anon9* uvP;
	float sp;
	int ay;
	float spd;
	int ax;
	//int ay;
	float dst;
	NJS_POINT3 vct;
	//_anon47* prmP;
	//_anon9 Tex2uv[8];
	//_anon47 Eff305Prm[4];
	// Line 1872, Address: 0x249a40, Func Offset: 0
	// Line 1892, Address: 0x249a5c, Func Offset: 0x1c
	// Line 1895, Address: 0x249a7c, Func Offset: 0x3c
	// Line 1896, Address: 0x249a88, Func Offset: 0x48
	// Line 1898, Address: 0x249a90, Func Offset: 0x50
	// Line 1897, Address: 0x249a94, Func Offset: 0x54
	// Line 1898, Address: 0x249a98, Func Offset: 0x58
	// Line 1899, Address: 0x249a9c, Func Offset: 0x5c
	// Line 1902, Address: 0x249aa4, Func Offset: 0x64
	// Line 1904, Address: 0x249ac0, Func Offset: 0x80
	// Line 1905, Address: 0x249ac8, Func Offset: 0x88
	// Line 1906, Address: 0x249ad0, Func Offset: 0x90
	// Line 1907, Address: 0x249ad8, Func Offset: 0x98
	// Line 1908, Address: 0x249ae0, Func Offset: 0xa0
	// Line 1917, Address: 0x249afc, Func Offset: 0xbc
	// Line 1908, Address: 0x249b00, Func Offset: 0xc0
	// Line 1909, Address: 0x249b08, Func Offset: 0xc8
	// Line 1910, Address: 0x249b0c, Func Offset: 0xcc
	// Line 1917, Address: 0x249b10, Func Offset: 0xd0
	// Line 1923, Address: 0x249b1c, Func Offset: 0xdc
	// Line 1910, Address: 0x249b24, Func Offset: 0xe4
	// Line 1911, Address: 0x249b2c, Func Offset: 0xec
	// Line 1923, Address: 0x249b30, Func Offset: 0xf0
	// Line 1924, Address: 0x249b34, Func Offset: 0xf4
	// Line 1911, Address: 0x249b38, Func Offset: 0xf8
	// Line 1912, Address: 0x249b40, Func Offset: 0x100
	// Line 1913, Address: 0x249b50, Func Offset: 0x110
	// Line 1914, Address: 0x249b5c, Func Offset: 0x11c
	// Line 1915, Address: 0x249b7c, Func Offset: 0x13c
	// Line 1916, Address: 0x249ba0, Func Offset: 0x160
	// Line 1917, Address: 0x249bac, Func Offset: 0x16c
	// Line 1921, Address: 0x249bc8, Func Offset: 0x188
	// Line 1923, Address: 0x249bcc, Func Offset: 0x18c
	// Line 1924, Address: 0x249be0, Func Offset: 0x1a0
	// Line 1925, Address: 0x249be8, Func Offset: 0x1a8
	// Line 1927, Address: 0x249bf0, Func Offset: 0x1b0
	// Line 1928, Address: 0x249c04, Func Offset: 0x1c4
	// Line 1929, Address: 0x249c18, Func Offset: 0x1d8
	// Line 1933, Address: 0x249c2c, Func Offset: 0x1ec
	// Line 1934, Address: 0x249c30, Func Offset: 0x1f0
	// Line 1936, Address: 0x249c34, Func Offset: 0x1f4
	// Line 1937, Address: 0x249c4c, Func Offset: 0x20c
	// Line 1938, Address: 0x249c5c, Func Offset: 0x21c
	// Line 1941, Address: 0x249c78, Func Offset: 0x238
	// Line 1945, Address: 0x249c84, Func Offset: 0x244
	// Line 1949, Address: 0x249c9c, Func Offset: 0x25c
	// Line 1952, Address: 0x249ca0, Func Offset: 0x260
	// Line 1957, Address: 0x249ca8, Func Offset: 0x268
	// Line 1952, Address: 0x249cb0, Func Offset: 0x270
	// Line 1953, Address: 0x249cbc, Func Offset: 0x27c
	// Line 1954, Address: 0x249cd0, Func Offset: 0x290
	// Line 1957, Address: 0x249ce0, Func Offset: 0x2a0
	// Line 1958, Address: 0x249ce8, Func Offset: 0x2a8
	// Line 1962, Address: 0x249cf8, Func Offset: 0x2b8
	// Line 1958, Address: 0x249d00, Func Offset: 0x2c0
	// Line 1961, Address: 0x249d08, Func Offset: 0x2c8
	// Line 1962, Address: 0x249d10, Func Offset: 0x2d0
	// Line 1966, Address: 0x249d24, Func Offset: 0x2e4
	// Line 1967, Address: 0x249d2c, Func Offset: 0x2ec
	// Line 1966, Address: 0x249d30, Func Offset: 0x2f0
	// Line 1969, Address: 0x249d3c, Func Offset: 0x2fc
	// Line 1970, Address: 0x249d4c, Func Offset: 0x30c
	// Line 1969, Address: 0x249d50, Func Offset: 0x310
	// Line 1970, Address: 0x249d58, Func Offset: 0x318
	// Line 1977, Address: 0x249d68, Func Offset: 0x328
	// Line 1970, Address: 0x249d70, Func Offset: 0x330
	// Line 1972, Address: 0x249d7c, Func Offset: 0x33c
	// Line 1977, Address: 0x249d8c, Func Offset: 0x34c
	// Line 1979, Address: 0x249d90, Func Offset: 0x350
	// Line 1977, Address: 0x249d94, Func Offset: 0x354
	// Line 1981, Address: 0x249d9c, Func Offset: 0x35c
	// Line 1982, Address: 0x249dac, Func Offset: 0x36c
	// Line 1984, Address: 0x249db0, Func Offset: 0x370
	// Line 1985, Address: 0x249dc8, Func Offset: 0x388
	// Line 1987, Address: 0x249dcc, Func Offset: 0x38c
	// Line 1988, Address: 0x249de4, Func Offset: 0x3a4
	// Line 1990, Address: 0x249de8, Func Offset: 0x3a8
	// Line 1991, Address: 0x249e08, Func Offset: 0x3c8
	// Line 1994, Address: 0x249e0c, Func Offset: 0x3cc
	// Line 1995, Address: 0x249e1c, Func Offset: 0x3dc
	// Line 1996, Address: 0x249e2c, Func Offset: 0x3ec
	// Line 1997, Address: 0x249e3c, Func Offset: 0x3fc
	// Line 1999, Address: 0x249e54, Func Offset: 0x414
	// Line 2004, Address: 0x249e8c, Func Offset: 0x44c
	// Func End, Address: 0x249ea8, Func Offset: 0x468
	scePrintf("bhEff305 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x249eb0
void bhEff306(O_WRK* oP)
{
	unsigned int col;
	//_anon6* tvP;
	//_anon9* uvP;
	float dst;
	NJS_POINT3 vct;
	float rnd;
	float dst_scl;
	//_anon57* prmP;
	int ColTbl[4];
	//_anon9* TexTab[10];
	//_anon57 Eff306Prm[8];
	// Line 2014, Address: 0x249eb0, Func Offset: 0
	// Line 2073, Address: 0x249ec4, Func Offset: 0x14
	// Line 2076, Address: 0x249f08, Func Offset: 0x58
	// Line 2078, Address: 0x249f14, Func Offset: 0x64
	// Line 2077, Address: 0x249f18, Func Offset: 0x68
	// Line 2078, Address: 0x249f1c, Func Offset: 0x6c
	// Line 2079, Address: 0x249f20, Func Offset: 0x70
	// Line 2083, Address: 0x249f28, Func Offset: 0x78
	// Line 2085, Address: 0x249f78, Func Offset: 0xc8
	// Line 2089, Address: 0x249f84, Func Offset: 0xd4
	// Line 2085, Address: 0x249f8c, Func Offset: 0xdc
	// Line 2086, Address: 0x249f9c, Func Offset: 0xec
	// Line 2088, Address: 0x249fa0, Func Offset: 0xf0
	// Line 2089, Address: 0x249fa8, Func Offset: 0xf8
	// Line 2090, Address: 0x249fbc, Func Offset: 0x10c
	// Line 2091, Address: 0x249fc8, Func Offset: 0x118
	// Line 2092, Address: 0x249fd0, Func Offset: 0x120
	// Line 2093, Address: 0x249fd8, Func Offset: 0x128
	// Line 2094, Address: 0x249fec, Func Offset: 0x13c
	// Line 2095, Address: 0x24a004, Func Offset: 0x154
	// Line 2097, Address: 0x24a00c, Func Offset: 0x15c
	// Line 2098, Address: 0x24a054, Func Offset: 0x1a4
	// Line 2100, Address: 0x24a060, Func Offset: 0x1b0
	// Line 2105, Address: 0x24a06c, Func Offset: 0x1bc
	// Line 2107, Address: 0x24a084, Func Offset: 0x1d4
	// Line 2108, Address: 0x24a08c, Func Offset: 0x1dc
	// Line 2107, Address: 0x24a094, Func Offset: 0x1e4
	// Line 2108, Address: 0x24a09c, Func Offset: 0x1ec
	// Line 2109, Address: 0x24a0c4, Func Offset: 0x214
	// Line 2111, Address: 0x24a0fc, Func Offset: 0x24c
	// Line 2113, Address: 0x24a114, Func Offset: 0x264
	// Line 2116, Address: 0x24a11c, Func Offset: 0x26c
	// Line 2117, Address: 0x24a14c, Func Offset: 0x29c
	// Line 2118, Address: 0x24a184, Func Offset: 0x2d4
	// Line 2119, Address: 0x24a194, Func Offset: 0x2e4
	// Line 2120, Address: 0x24a198, Func Offset: 0x2e8
	// Line 2119, Address: 0x24a1a0, Func Offset: 0x2f0
	// Line 2120, Address: 0x24a1a4, Func Offset: 0x2f4
	// Line 2121, Address: 0x24a1b0, Func Offset: 0x300
	// Line 2123, Address: 0x24a1b8, Func Offset: 0x308
	// Line 2126, Address: 0x24a1c0, Func Offset: 0x310
	// Line 2131, Address: 0x24a1c4, Func Offset: 0x314
	// Line 2133, Address: 0x24a1d4, Func Offset: 0x324
	// Line 2135, Address: 0x24a1f4, Func Offset: 0x344
	// Line 2133, Address: 0x24a1f8, Func Offset: 0x348
	// Line 2143, Address: 0x24a1fc, Func Offset: 0x34c
	// Line 2135, Address: 0x24a208, Func Offset: 0x358
	// Line 2144, Address: 0x24a214, Func Offset: 0x364
	// Line 2135, Address: 0x24a218, Func Offset: 0x368
	// Line 2136, Address: 0x24a220, Func Offset: 0x370
	// Line 2141, Address: 0x24a230, Func Offset: 0x380
	// Line 2143, Address: 0x24a234, Func Offset: 0x384
	// Line 2144, Address: 0x24a248, Func Offset: 0x398
	// Line 2145, Address: 0x24a250, Func Offset: 0x3a0
	// Line 2147, Address: 0x24a258, Func Offset: 0x3a8
	// Line 2156, Address: 0x24a25c, Func Offset: 0x3ac
	// Line 2147, Address: 0x24a260, Func Offset: 0x3b0
	// Line 2156, Address: 0x24a264, Func Offset: 0x3b4
	// Line 2147, Address: 0x24a268, Func Offset: 0x3b8
	// Line 2148, Address: 0x24a274, Func Offset: 0x3c4
	// Line 2149, Address: 0x24a288, Func Offset: 0x3d8
	// Line 2156, Address: 0x24a29c, Func Offset: 0x3ec
	// Line 2153, Address: 0x24a2a0, Func Offset: 0x3f0
	// Line 2156, Address: 0x24a2a8, Func Offset: 0x3f8
	// Line 2153, Address: 0x24a2b0, Func Offset: 0x400
	// Line 2156, Address: 0x24a2b4, Func Offset: 0x404
	// Line 2153, Address: 0x24a2b8, Func Offset: 0x408
	// Line 2156, Address: 0x24a2bc, Func Offset: 0x40c
	// Line 2158, Address: 0x24a2c0, Func Offset: 0x410
	// Line 2156, Address: 0x24a2c4, Func Offset: 0x414
	// Line 2158, Address: 0x24a2c8, Func Offset: 0x418
	// Line 2159, Address: 0x24a2d4, Func Offset: 0x424
	// Line 2161, Address: 0x24a2d8, Func Offset: 0x428
	// Line 2162, Address: 0x24a2f0, Func Offset: 0x440
	// Line 2164, Address: 0x24a2f4, Func Offset: 0x444
	// Line 2165, Address: 0x24a30c, Func Offset: 0x45c
	// Line 2167, Address: 0x24a310, Func Offset: 0x460
	// Line 2168, Address: 0x24a330, Func Offset: 0x480
	// Line 2171, Address: 0x24a334, Func Offset: 0x484
	// Line 2174, Address: 0x24a354, Func Offset: 0x4a4
	// Func End, Address: 0x24a368, Func Offset: 0x4b8
	scePrintf("bhEff306 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24a370
OR_WORK* bhSetRapEff(int eff_no, void* datP, int lng_siz)
{
	OR_WORK* orP;
	// Line 2180, Address: 0x24a370, Func Offset: 0
	// Line 2183, Address: 0x24a390, Func Offset: 0x20
	// Line 2184, Address: 0x24a3a0, Func Offset: 0x30
	// Line 2187, Address: 0x24a3a8, Func Offset: 0x38
	// Line 2189, Address: 0x24a3b0, Func Offset: 0x40
	// Line 2193, Address: 0x24a3c0, Func Offset: 0x50
	// Line 2194, Address: 0x24a3c4, Func Offset: 0x54
	// Func End, Address: 0x24a3e0, Func Offset: 0x70
	scePrintf("bhSetRapEff - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24a3e0
void bhEff307(OR_WORK* orP)
{
	int* colP;
	int* alpP;
	int flg;
	int idx;
	float sp;
	int ay;
	NJS_POINT3 wnd;
	NJS_POINT3* vctP;
	//int idx;
	int vtx;
	//_anon51* r07P;
	// Line 2200, Address: 0x24a3e0, Func Offset: 0
	// Line 2204, Address: 0x24a40c, Func Offset: 0x2c
	// Line 2207, Address: 0x24a438, Func Offset: 0x58
	// Line 2208, Address: 0x24a444, Func Offset: 0x64
	// Line 2209, Address: 0x24a448, Func Offset: 0x68
	// Line 2210, Address: 0x24a44c, Func Offset: 0x6c
	// Line 2214, Address: 0x24a458, Func Offset: 0x78
	// Line 2210, Address: 0x24a464, Func Offset: 0x84
	// Line 2214, Address: 0x24a46c, Func Offset: 0x8c
	// Line 2210, Address: 0x24a474, Func Offset: 0x94
	// Line 2211, Address: 0x24a478, Func Offset: 0x98
	// Line 2214, Address: 0x24a484, Func Offset: 0xa4
	// Line 2223, Address: 0x24a49c, Func Offset: 0xbc
	// Line 2224, Address: 0x24a4bc, Func Offset: 0xdc
	// Line 2225, Address: 0x24a4e0, Func Offset: 0x100
	// Line 2227, Address: 0x24a4f0, Func Offset: 0x110
	// Line 2228, Address: 0x24a500, Func Offset: 0x120
	// Line 2227, Address: 0x24a508, Func Offset: 0x128
	// Line 2228, Address: 0x24a518, Func Offset: 0x138
	// Line 2229, Address: 0x24a524, Func Offset: 0x144
	// Line 2231, Address: 0x24a52c, Func Offset: 0x14c
	// Line 2233, Address: 0x24a538, Func Offset: 0x158
	// Line 2231, Address: 0x24a53c, Func Offset: 0x15c
	// Line 2232, Address: 0x24a544, Func Offset: 0x164
	// Line 2241, Address: 0x24a554, Func Offset: 0x174
	// Line 2232, Address: 0x24a558, Func Offset: 0x178
	// Line 2233, Address: 0x24a560, Func Offset: 0x180
	// Line 2234, Address: 0x24a56c, Func Offset: 0x18c
	// Line 2235, Address: 0x24a578, Func Offset: 0x198
	// Line 2236, Address: 0x24a590, Func Offset: 0x1b0
	// Line 2238, Address: 0x24a5a8, Func Offset: 0x1c8
	// Line 2242, Address: 0x24a5ac, Func Offset: 0x1cc
	// Line 2243, Address: 0x24a5b4, Func Offset: 0x1d4
	// Line 2254, Address: 0x24a5c0, Func Offset: 0x1e0
	// Line 2255, Address: 0x24a5d0, Func Offset: 0x1f0
	// Line 2256, Address: 0x24a5d4, Func Offset: 0x1f4
	// Line 2258, Address: 0x24a5ec, Func Offset: 0x20c
	// Line 2259, Address: 0x24a5f4, Func Offset: 0x214
	// Line 2260, Address: 0x24a600, Func Offset: 0x220
	// Line 2262, Address: 0x24a60c, Func Offset: 0x22c
	// Line 2263, Address: 0x24a618, Func Offset: 0x238
	// Line 2269, Address: 0x24a628, Func Offset: 0x248
	// Line 2263, Address: 0x24a62c, Func Offset: 0x24c
	// Line 2269, Address: 0x24a64c, Func Offset: 0x26c
	// Line 2270, Address: 0x24a650, Func Offset: 0x270
	// Line 2269, Address: 0x24a654, Func Offset: 0x274
	// Line 2272, Address: 0x24a660, Func Offset: 0x280
	// Line 2274, Address: 0x24a670, Func Offset: 0x290
	// Line 2272, Address: 0x24a674, Func Offset: 0x294
	// Line 2274, Address: 0x24a678, Func Offset: 0x298
	// Line 2278, Address: 0x24a688, Func Offset: 0x2a8
	// Line 2274, Address: 0x24a690, Func Offset: 0x2b0
	// Line 2276, Address: 0x24a694, Func Offset: 0x2b4
	// Line 2278, Address: 0x24a69c, Func Offset: 0x2bc
	// Line 2279, Address: 0x24a6a4, Func Offset: 0x2c4
	// Line 2281, Address: 0x24a6b8, Func Offset: 0x2d8
	// Line 2288, Address: 0x24a6d0, Func Offset: 0x2f0
	// Line 2289, Address: 0x24a6d4, Func Offset: 0x2f4
	// Line 2287, Address: 0x24a6d8, Func Offset: 0x2f8
	// Line 2290, Address: 0x24a6dc, Func Offset: 0x2fc
	// Line 2292, Address: 0x24a6e4, Func Offset: 0x304
	// Line 2293, Address: 0x24a700, Func Offset: 0x320
	// Line 2295, Address: 0x24a710, Func Offset: 0x330
	// Line 2296, Address: 0x24a724, Func Offset: 0x344
	// Line 2298, Address: 0x24a728, Func Offset: 0x348
	// Line 2299, Address: 0x24a730, Func Offset: 0x350
	// Line 2298, Address: 0x24a734, Func Offset: 0x354
	// Line 2299, Address: 0x24a748, Func Offset: 0x368
	// Line 2301, Address: 0x24a760, Func Offset: 0x380
	// Line 2302, Address: 0x24a76c, Func Offset: 0x38c
	// Line 2306, Address: 0x24a7b4, Func Offset: 0x3d4
	// Func End, Address: 0x24a7e0, Func Offset: 0x400
	scePrintf("bhEff307 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24a7e0
void bhEff307Drw(OR_WORK* orP)
{
	int col;
	float tu_r;
	float tu_l;
	float frm;
	int idx;
	int tgr;
	int vtx;
	//_anon51* r07P;
	// Line 2312, Address: 0x24a7e0, Func Offset: 0
	// Line 2316, Address: 0x24a80c, Func Offset: 0x2c
	// Line 2313, Address: 0x24a810, Func Offset: 0x30
	// Line 2319, Address: 0x24a814, Func Offset: 0x34
	// Line 2320, Address: 0x24a81c, Func Offset: 0x3c
	// Line 2321, Address: 0x24a828, Func Offset: 0x48
	// Line 2322, Address: 0x24a834, Func Offset: 0x54
	// Line 2324, Address: 0x24a83c, Func Offset: 0x5c
	// Line 2325, Address: 0x24a848, Func Offset: 0x68
	// Line 2326, Address: 0x24a850, Func Offset: 0x70
	// Line 2332, Address: 0x24a858, Func Offset: 0x78
	// Line 2334, Address: 0x24a85c, Func Offset: 0x7c
	// Line 2330, Address: 0x24a86c, Func Offset: 0x8c
	// Line 2334, Address: 0x24a870, Func Offset: 0x90
	// Line 2335, Address: 0x24a878, Func Offset: 0x98
	// Line 2337, Address: 0x24a894, Func Offset: 0xb4
	// Line 2338, Address: 0x24a898, Func Offset: 0xb8
	// Line 2337, Address: 0x24a8a4, Func Offset: 0xc4
	// Line 2338, Address: 0x24a8a8, Func Offset: 0xc8
	// Line 2339, Address: 0x24a8b8, Func Offset: 0xd8
	// Line 2340, Address: 0x24a8c4, Func Offset: 0xe4
	// Line 2343, Address: 0x24a8c8, Func Offset: 0xe8
	// Line 2344, Address: 0x24a8d8, Func Offset: 0xf8
	// Line 2346, Address: 0x24a8dc, Func Offset: 0xfc
	// Line 2347, Address: 0x24a900, Func Offset: 0x120
	// Line 2349, Address: 0x24a928, Func Offset: 0x148
	// Line 2352, Address: 0x24a934, Func Offset: 0x154
	// Line 2354, Address: 0x24a940, Func Offset: 0x160
	// Line 2353, Address: 0x24a944, Func Offset: 0x164
	// Line 2355, Address: 0x24a948, Func Offset: 0x168
	// Line 2357, Address: 0x24a950, Func Offset: 0x170
	// Line 2356, Address: 0x24a954, Func Offset: 0x174
	// Line 2357, Address: 0x24a958, Func Offset: 0x178
	// Line 2358, Address: 0x24a95c, Func Offset: 0x17c
	// Line 2360, Address: 0x24a960, Func Offset: 0x180
	// Line 2361, Address: 0x24a978, Func Offset: 0x198
	// Line 2362, Address: 0x24a990, Func Offset: 0x1b0
	// Line 2363, Address: 0x24a998, Func Offset: 0x1b8
	// Line 2364, Address: 0x24a9a4, Func Offset: 0x1c4
	// Line 2365, Address: 0x24a9ac, Func Offset: 0x1cc
	// Line 2366, Address: 0x24a9b0, Func Offset: 0x1d0
	// Line 2368, Address: 0x24a9c4, Func Offset: 0x1e4
	// Line 2369, Address: 0x24a9cc, Func Offset: 0x1ec
	// Line 2371, Address: 0x24a9dc, Func Offset: 0x1fc
	// Line 2374, Address: 0x24a9f4, Func Offset: 0x214
	// Line 2386, Address: 0x24a9fc, Func Offset: 0x21c
	// Line 2388, Address: 0x24aa04, Func Offset: 0x224
	// Func End, Address: 0x24aa34, Func Offset: 0x254
	scePrintf("bhEff307Drw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24aa40
void bhSetEffGunSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
	//_anon16* pmbP;
	OR_WORK* orP;
	//_anon12 Eff308Prm[4];
	// Line 2394, Address: 0x24aa40, Func Offset: 0
	// Line 2406, Address: 0x24aa44, Func Offset: 0x4
	// Line 2394, Address: 0x24aa4c, Func Offset: 0xc
	// Line 2406, Address: 0x24aa5c, Func Offset: 0x1c
	// Line 2394, Address: 0x24aa6c, Func Offset: 0x2c
	// Line 2406, Address: 0x24aa70, Func Offset: 0x30
	// Line 2408, Address: 0x24aa94, Func Offset: 0x54
	// Line 2413, Address: 0x24aaa0, Func Offset: 0x60
	// Line 2408, Address: 0x24aaa8, Func Offset: 0x68
	// Line 2409, Address: 0x24aab4, Func Offset: 0x74
	// Line 2410, Address: 0x24aacc, Func Offset: 0x8c
	// Line 2411, Address: 0x24aad0, Func Offset: 0x90
	// Line 2413, Address: 0x24aad4, Func Offset: 0x94
	// Line 2415, Address: 0x24aae0, Func Offset: 0xa0
	// Func End, Address: 0x24aafc, Func Offset: 0xbc
	scePrintf("bhSetEffGunSpark - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ab00
void bhSetEffSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
	//_anon30* lP;
	//_anon16* pmbP;
	OR_WORK* orP;
	//_anon12 Eff308Prm[2];
	// Line 2421, Address: 0x24ab00, Func Offset: 0
	// Line 2431, Address: 0x24ab04, Func Offset: 0x4
	// Line 2421, Address: 0x24ab08, Func Offset: 0x8
	// Line 2431, Address: 0x24ab0c, Func Offset: 0xc
	// Line 2421, Address: 0x24ab10, Func Offset: 0x10
	// Line 2431, Address: 0x24ab20, Func Offset: 0x20
	// Line 2421, Address: 0x24ab30, Func Offset: 0x30
	// Line 2431, Address: 0x24ab34, Func Offset: 0x34
	// Line 2433, Address: 0x24ab58, Func Offset: 0x58
	// Line 2432, Address: 0x24ab64, Func Offset: 0x64
	// Line 2437, Address: 0x24ab6c, Func Offset: 0x6c
	// Line 2433, Address: 0x24ab70, Func Offset: 0x70
	// Line 2434, Address: 0x24ab7c, Func Offset: 0x7c
	// Line 2435, Address: 0x24ab94, Func Offset: 0x94
	// Line 2437, Address: 0x24ab98, Func Offset: 0x98
	// Line 2440, Address: 0x24aba4, Func Offset: 0xa4
	// Line 2441, Address: 0x24abb4, Func Offset: 0xb4
	// Line 2443, Address: 0x24abc4, Func Offset: 0xc4
	// Line 2444, Address: 0x24abc8, Func Offset: 0xc8
	// Line 2445, Address: 0x24abcc, Func Offset: 0xcc
	// Line 2447, Address: 0x24abd8, Func Offset: 0xd8
	// Line 2449, Address: 0x24abdc, Func Offset: 0xdc
	// Line 2450, Address: 0x24abe0, Func Offset: 0xe0
	// Line 2452, Address: 0x24abe4, Func Offset: 0xe4
	// Line 2447, Address: 0x24abe8, Func Offset: 0xe8
	// Line 2448, Address: 0x24abf0, Func Offset: 0xf0
	// Line 2458, Address: 0x24abf4, Func Offset: 0xf4
	// Line 2453, Address: 0x24abfc, Func Offset: 0xfc
	// Line 2454, Address: 0x24ac00, Func Offset: 0x100
	// Line 2457, Address: 0x24ac04, Func Offset: 0x104
	// Line 2448, Address: 0x24ac08, Func Offset: 0x108
	// Line 2449, Address: 0x24ac10, Func Offset: 0x110
	// Line 2450, Address: 0x24ac14, Func Offset: 0x114
	// Line 2451, Address: 0x24ac18, Func Offset: 0x118
	// Line 2452, Address: 0x24ac1c, Func Offset: 0x11c
	// Line 2453, Address: 0x24ac20, Func Offset: 0x120
	// Line 2454, Address: 0x24ac24, Func Offset: 0x124
	// Line 2455, Address: 0x24ac28, Func Offset: 0x128
	// Line 2459, Address: 0x24ac34, Func Offset: 0x134
	// Line 2455, Address: 0x24ac3c, Func Offset: 0x13c
	// Line 2456, Address: 0x24ac48, Func Offset: 0x148
	// Line 2457, Address: 0x24ac60, Func Offset: 0x160
	// Line 2458, Address: 0x24ac64, Func Offset: 0x164
	// Line 2459, Address: 0x24ac68, Func Offset: 0x168
	// Line 2462, Address: 0x24ac6c, Func Offset: 0x16c
	// Func End, Address: 0x24ac8c, Func Offset: 0x18c
	scePrintf("bhSetEffSpark - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ac90
void bhEff308(OR_WORK* orP)
{
	float sp;
	int ay;
	unsigned int* colP;
	NJS_POINT3* dirP;
	NJS_POINT3* vtxP;
	NJS_POINT3 wnd;
	int i;
	int tmp;
	int dst;
	int src;
	int tim;
	int* subP;
	int* addP;
	int* timP;
	//int i;
	//unsigned int* colP;
	//NJS_POINT3* vtxP;
	//int i;
	//float sp;
	//int ay;
	int ax;
	//NJS_POINT3* dirP;
	//int i;
	//_anon16* pmbP;
	//_anon4* r08P;
	// Line 2468, Address: 0x24ac90, Func Offset: 0
	// Line 2473, Address: 0x24acc0, Func Offset: 0x30
	// Line 2469, Address: 0x24acc4, Func Offset: 0x34
	// Line 2473, Address: 0x24acc8, Func Offset: 0x38
	// Line 2476, Address: 0x24ace4, Func Offset: 0x54
	// Line 2477, Address: 0x24acf0, Func Offset: 0x60
	// Line 2483, Address: 0x24acfc, Func Offset: 0x6c
	// Line 2484, Address: 0x24ad08, Func Offset: 0x78
	// Line 2485, Address: 0x24ad54, Func Offset: 0xc4
	// Line 2486, Address: 0x24ada0, Func Offset: 0x110
	// Line 2488, Address: 0x24adbc, Func Offset: 0x12c
	// Line 2486, Address: 0x24adc0, Func Offset: 0x130
	// Line 2488, Address: 0x24adc4, Func Offset: 0x134
	// Line 2486, Address: 0x24adc8, Func Offset: 0x138
	// Line 2488, Address: 0x24ade4, Func Offset: 0x154
	// Line 2489, Address: 0x24adec, Func Offset: 0x15c
	// Line 2490, Address: 0x24adfc, Func Offset: 0x16c
	// Line 2491, Address: 0x24ae0c, Func Offset: 0x17c
	// Line 2492, Address: 0x24ae20, Func Offset: 0x190
	// Line 2493, Address: 0x24ae24, Func Offset: 0x194
	// Line 2492, Address: 0x24ae28, Func Offset: 0x198
	// Line 2493, Address: 0x24ae48, Func Offset: 0x1b8
	// Line 2501, Address: 0x24ae50, Func Offset: 0x1c0
	// Line 2498, Address: 0x24ae54, Func Offset: 0x1c4
	// Line 2501, Address: 0x24ae58, Func Offset: 0x1c8
	// Line 2502, Address: 0x24ae60, Func Offset: 0x1d0
	// Line 2506, Address: 0x24ae6c, Func Offset: 0x1dc
	// Line 2502, Address: 0x24ae70, Func Offset: 0x1e0
	// Line 2503, Address: 0x24ae7c, Func Offset: 0x1ec
	// Line 2506, Address: 0x24ae80, Func Offset: 0x1f0
	// Line 2503, Address: 0x24ae84, Func Offset: 0x1f4
	// Line 2504, Address: 0x24ae88, Func Offset: 0x1f8
	// Line 2506, Address: 0x24ae98, Func Offset: 0x208
	// Line 2515, Address: 0x24aea0, Func Offset: 0x210
	// Line 2511, Address: 0x24aea4, Func Offset: 0x214
	// Line 2512, Address: 0x24aea8, Func Offset: 0x218
	// Line 2515, Address: 0x24aeac, Func Offset: 0x21c
	// Line 2518, Address: 0x24aeb4, Func Offset: 0x224
	// Line 2519, Address: 0x24aefc, Func Offset: 0x26c
	// Line 2520, Address: 0x24af00, Func Offset: 0x270
	// Line 2522, Address: 0x24af04, Func Offset: 0x274
	// Line 2523, Address: 0x24af20, Func Offset: 0x290
	// Line 2524, Address: 0x24af38, Func Offset: 0x2a8
	// Line 2526, Address: 0x24af40, Func Offset: 0x2b0
	// Line 2527, Address: 0x24af5c, Func Offset: 0x2cc
	// Line 2528, Address: 0x24af7c, Func Offset: 0x2ec
	// Line 2530, Address: 0x24af90, Func Offset: 0x300
	// Line 2531, Address: 0x24afb0, Func Offset: 0x320
	// Line 2532, Address: 0x24afd4, Func Offset: 0x344
	// Line 2534, Address: 0x24afe8, Func Offset: 0x358
	// Line 2535, Address: 0x24aff0, Func Offset: 0x360
	// Line 2536, Address: 0x24b00c, Func Offset: 0x37c
	// Line 2537, Address: 0x24b030, Func Offset: 0x3a0
	// Line 2538, Address: 0x24b048, Func Offset: 0x3b8
	// Line 2542, Address: 0x24b060, Func Offset: 0x3d0
	// Line 2543, Address: 0x24b064, Func Offset: 0x3d4
	// Line 2545, Address: 0x24b08c, Func Offset: 0x3fc
	// Line 2557, Address: 0x24b098, Func Offset: 0x408
	// Line 2561, Address: 0x24b09c, Func Offset: 0x40c
	// Line 2562, Address: 0x24b0a4, Func Offset: 0x414
	// Line 2553, Address: 0x24b0a8, Func Offset: 0x418
	// Line 2554, Address: 0x24b0ac, Func Offset: 0x41c
	// Line 2561, Address: 0x24b0b0, Func Offset: 0x420
	// Line 2555, Address: 0x24b0bc, Func Offset: 0x42c
	// Line 2564, Address: 0x24b0c0, Func Offset: 0x430
	// Line 2566, Address: 0x24b0d0, Func Offset: 0x440
	// Line 2564, Address: 0x24b0d4, Func Offset: 0x444
	// Line 2566, Address: 0x24b0d8, Func Offset: 0x448
	// Line 2572, Address: 0x24b0e8, Func Offset: 0x458
	// Line 2566, Address: 0x24b0f0, Func Offset: 0x460
	// Line 2568, Address: 0x24b0f4, Func Offset: 0x464
	// Line 2572, Address: 0x24b0fc, Func Offset: 0x46c
	// Line 2573, Address: 0x24b104, Func Offset: 0x474
	// Line 2574, Address: 0x24b110, Func Offset: 0x480
	// Line 2575, Address: 0x24b118, Func Offset: 0x488
	// Line 2580, Address: 0x24b11c, Func Offset: 0x48c
	// Line 2575, Address: 0x24b124, Func Offset: 0x494
	// Line 2578, Address: 0x24b12c, Func Offset: 0x49c
	// Line 2580, Address: 0x24b140, Func Offset: 0x4b0
	// Line 2581, Address: 0x24b148, Func Offset: 0x4b8
	// Line 2583, Address: 0x24b154, Func Offset: 0x4c4
	// Line 2584, Address: 0x24b164, Func Offset: 0x4d4
	// Line 2585, Address: 0x24b174, Func Offset: 0x4e4
	// Line 2586, Address: 0x24b184, Func Offset: 0x4f4
	// Line 2588, Address: 0x24b194, Func Offset: 0x504
	// Line 2589, Address: 0x24b1a4, Func Offset: 0x514
	// Line 2591, Address: 0x24b1b4, Func Offset: 0x524
	// Line 2592, Address: 0x24b1cc, Func Offset: 0x53c
	// Line 2593, Address: 0x24b1e4, Func Offset: 0x554
	// Line 2595, Address: 0x24b1ec, Func Offset: 0x55c
	// Line 2593, Address: 0x24b1f0, Func Offset: 0x560
	// Line 2596, Address: 0x24b1f4, Func Offset: 0x564
	// Line 2599, Address: 0x24b218, Func Offset: 0x588
	// Line 2600, Address: 0x24b22c, Func Offset: 0x59c
	// Line 2605, Address: 0x24b264, Func Offset: 0x5d4
	// Func End, Address: 0x24b294, Func Offset: 0x604
	scePrintf("bhEff308 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24b2a0
void bhEff308Drw(OR_WORK* orP)
{
	int* timP;
	//_anon62* p3cP;
	int i;
	//_anon4* r08P;
	// Line 2611, Address: 0x24b2a0, Func Offset: 0
	// Line 2616, Address: 0x24b2c0, Func Offset: 0x20
	// Line 2612, Address: 0x24b2c8, Func Offset: 0x28
	// Line 2616, Address: 0x24b2cc, Func Offset: 0x2c
	// Line 2620, Address: 0x24b2d4, Func Offset: 0x34
	// Line 2621, Address: 0x24b2d8, Func Offset: 0x38
	// Line 2624, Address: 0x24b2dc, Func Offset: 0x3c
	// Line 2625, Address: 0x24b2ec, Func Offset: 0x4c
	// Line 2626, Address: 0x24b2f8, Func Offset: 0x58
	// Line 2627, Address: 0x24b300, Func Offset: 0x60
	// Line 2629, Address: 0x24b308, Func Offset: 0x68
	// Line 2628, Address: 0x24b30c, Func Offset: 0x6c
	// Line 2629, Address: 0x24b310, Func Offset: 0x70
	// Line 2630, Address: 0x24b314, Func Offset: 0x74
	// Line 2631, Address: 0x24b324, Func Offset: 0x84
	// Line 2630, Address: 0x24b328, Func Offset: 0x88
	// Line 2632, Address: 0x24b330, Func Offset: 0x90
	// Line 2635, Address: 0x24b348, Func Offset: 0xa8
	// Func End, Address: 0x24b36c, Func Offset: 0xcc
	scePrintf("bhEff308Drw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24b370
int ryLinerColor(int src_col, int dst_col, float rate)
{
	int col;
	int tmp;
	int rte;
	// Line 2644, Address: 0x24b370, Func Offset: 0
	// Line 2641, Address: 0x24b378, Func Offset: 0x8
	// Line 2644, Address: 0x24b37c, Func Offset: 0xc
	// Line 2641, Address: 0x24b380, Func Offset: 0x10
	// Line 2644, Address: 0x24b390, Func Offset: 0x20
	// Line 2646, Address: 0x24b398, Func Offset: 0x28
	// Line 2648, Address: 0x24b3a8, Func Offset: 0x38
	// Line 2651, Address: 0x24b3ac, Func Offset: 0x3c
	// Line 2659, Address: 0x24b3b0, Func Offset: 0x40
	// Line 2648, Address: 0x24b3b4, Func Offset: 0x44
	// Line 2646, Address: 0x24b3c0, Func Offset: 0x50
	// Line 2648, Address: 0x24b3c4, Func Offset: 0x54
	// Line 2646, Address: 0x24b3c8, Func Offset: 0x58
	// Line 2648, Address: 0x24b3cc, Func Offset: 0x5c
	// Line 2647, Address: 0x24b3d0, Func Offset: 0x60
	// Line 2649, Address: 0x24b3d4, Func Offset: 0x64
	// Line 2651, Address: 0x24b3dc, Func Offset: 0x6c
	// Line 2654, Address: 0x24b3ec, Func Offset: 0x7c
	// Line 2656, Address: 0x24b3f0, Func Offset: 0x80
	// Line 2659, Address: 0x24b3f4, Func Offset: 0x84
	// Line 2651, Address: 0x24b3f8, Func Offset: 0x88
	// Line 2653, Address: 0x24b408, Func Offset: 0x98
	// Line 2656, Address: 0x24b40c, Func Offset: 0x9c
	// Line 2659, Address: 0x24b424, Func Offset: 0xb4
	// Line 2656, Address: 0x24b428, Func Offset: 0xb8
	// Line 2658, Address: 0x24b434, Func Offset: 0xc4
	// Line 2659, Address: 0x24b438, Func Offset: 0xc8
	// Func End, Address: 0x24b440, Func Offset: 0xd0
	scePrintf("ryLinerColor - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24b440
OR_WORK* rySetEffBlood(float mtxP[16], NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
	//_anon56* r09P;
	int mode;
	//_anon50* pmbP;
	OR_WORK* orP;
	//_anon71 Eff309Prm[6];
	// Line 2665, Address: 0x24b440, Func Offset: 0
	// Line 2697, Address: 0x24b454, Func Offset: 0x14
	// Line 2665, Address: 0x24b458, Func Offset: 0x18
	// Line 2697, Address: 0x24b45c, Func Offset: 0x1c
	// Line 2698, Address: 0x24b478, Func Offset: 0x38
	// Line 2699, Address: 0x24b48c, Func Offset: 0x4c
	// Line 2702, Address: 0x24b494, Func Offset: 0x54
	// Line 2704, Address: 0x24b4c0, Func Offset: 0x80
	// Line 2705, Address: 0x24b4c4, Func Offset: 0x84
	// Line 2711, Address: 0x24b4d0, Func Offset: 0x90
	// Line 2705, Address: 0x24b4d4, Func Offset: 0x94
	// Line 2706, Address: 0x24b4e0, Func Offset: 0xa0
	// Line 2711, Address: 0x24b4f8, Func Offset: 0xb8
	// Line 2712, Address: 0x24b50c, Func Offset: 0xcc
	// Line 2713, Address: 0x24b524, Func Offset: 0xe4
	// Line 2718, Address: 0x24b528, Func Offset: 0xe8
	// Func End, Address: 0x24b544, Func Offset: 0x104
	scePrintf("rySetEffBlood - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24b550
void bhEff309(OR_WORK* orP)
{
	float acl;
	NJS_POINT3* dirP;
	//_rap_tex_typ* rtP;
	int i;
	float sp;
	//NJS_POINT3* dirP;
	NJS_POINT3 pos;
	//_rap_tex_typ* rtP;
	char* timP;
	//int i;
	//_rap_tex_typ* rtP;
	//int i;
	//_anon50* pmbP;
	//_anon56* r09P;
	//_anon9 Tex5Buv[12];
	// Line 2724, Address: 0x24b550, Func Offset: 0
	// Line 2748, Address: 0x24b57c, Func Offset: 0x2c
	// Line 2744, Address: 0x24b580, Func Offset: 0x30
	// Line 2748, Address: 0x24b584, Func Offset: 0x34
	// Line 2751, Address: 0x24b5ac, Func Offset: 0x5c
	// Line 2755, Address: 0x24b5b4, Func Offset: 0x64
	// Line 2751, Address: 0x24b5b8, Func Offset: 0x68
	// Line 2759, Address: 0x24b5bc, Func Offset: 0x6c
	// Line 2757, Address: 0x24b5c0, Func Offset: 0x70
	// Line 2761, Address: 0x24b5c4, Func Offset: 0x74
	// Line 2760, Address: 0x24b5c8, Func Offset: 0x78
	// Line 2761, Address: 0x24b5cc, Func Offset: 0x7c
	// Line 2762, Address: 0x24b5d0, Func Offset: 0x80
	// Line 2763, Address: 0x24b5e0, Func Offset: 0x90
	// Line 2764, Address: 0x24b5e4, Func Offset: 0x94
	// Line 2767, Address: 0x24b5e8, Func Offset: 0x98
	// Line 2768, Address: 0x24b5f8, Func Offset: 0xa8
	// Line 2769, Address: 0x24b604, Func Offset: 0xb4
	// Line 2770, Address: 0x24b628, Func Offset: 0xd8
	// Line 2771, Address: 0x24b64c, Func Offset: 0xfc
	// Line 2773, Address: 0x24b658, Func Offset: 0x108
	// Line 2779, Address: 0x24b664, Func Offset: 0x114
	// Line 2781, Address: 0x24b668, Func Offset: 0x118
	// Line 2782, Address: 0x24b66c, Func Offset: 0x11c
	// Line 2785, Address: 0x24b67c, Func Offset: 0x12c
	// Line 2787, Address: 0x24b680, Func Offset: 0x130
	// Line 2792, Address: 0x24b684, Func Offset: 0x134
	// Line 2786, Address: 0x24b688, Func Offset: 0x138
	// Line 2787, Address: 0x24b690, Func Offset: 0x140
	// Line 2792, Address: 0x24b694, Func Offset: 0x144
	// Line 2793, Address: 0x24b6a0, Func Offset: 0x150
	// Line 2797, Address: 0x24b6b0, Func Offset: 0x160
	// Line 2798, Address: 0x24b6c0, Func Offset: 0x170
	// Line 2799, Address: 0x24b71c, Func Offset: 0x1cc
	// Line 2802, Address: 0x24b778, Func Offset: 0x228
	// Line 2804, Address: 0x24b794, Func Offset: 0x244
	// Line 2802, Address: 0x24b798, Func Offset: 0x248
	// Line 2804, Address: 0x24b79c, Func Offset: 0x24c
	// Line 2802, Address: 0x24b7a0, Func Offset: 0x250
	// Line 2804, Address: 0x24b7b4, Func Offset: 0x264
	// Line 2802, Address: 0x24b7bc, Func Offset: 0x26c
	// Line 2804, Address: 0x24b7c4, Func Offset: 0x274
	// Line 2805, Address: 0x24b7cc, Func Offset: 0x27c
	// Line 2809, Address: 0x24b7d0, Func Offset: 0x280
	// Line 2810, Address: 0x24b7d8, Func Offset: 0x288
	// Line 2805, Address: 0x24b7dc, Func Offset: 0x28c
	// Line 2809, Address: 0x24b7fc, Func Offset: 0x2ac
	// Line 2810, Address: 0x24b800, Func Offset: 0x2b0
	// Line 2811, Address: 0x24b804, Func Offset: 0x2b4
	// Line 2812, Address: 0x24b814, Func Offset: 0x2c4
	// Line 2813, Address: 0x24b818, Func Offset: 0x2c8
	// Line 2818, Address: 0x24b824, Func Offset: 0x2d4
	// Line 2823, Address: 0x24b828, Func Offset: 0x2d8
	// Line 2826, Address: 0x24b82c, Func Offset: 0x2dc
	// Line 2824, Address: 0x24b830, Func Offset: 0x2e0
	// Line 2827, Address: 0x24b834, Func Offset: 0x2e4
	// Line 2830, Address: 0x24b840, Func Offset: 0x2f0
	// Line 2829, Address: 0x24b844, Func Offset: 0x2f4
	// Line 2832, Address: 0x24b848, Func Offset: 0x2f8
	// Line 2834, Address: 0x24b854, Func Offset: 0x304
	// Line 2842, Address: 0x24b858, Func Offset: 0x308
	// Line 2834, Address: 0x24b864, Func Offset: 0x314
	// Line 2835, Address: 0x24b86c, Func Offset: 0x31c
	// Line 2836, Address: 0x24b878, Func Offset: 0x328
	// Line 2837, Address: 0x24b884, Func Offset: 0x334
	// Line 2840, Address: 0x24b894, Func Offset: 0x344
	// Line 2842, Address: 0x24b8a0, Func Offset: 0x350
	// Line 2843, Address: 0x24b8b0, Func Offset: 0x360
	// Line 2845, Address: 0x24b8b8, Func Offset: 0x368
	// Line 2846, Address: 0x24b8c0, Func Offset: 0x370
	// Line 2848, Address: 0x24b8c4, Func Offset: 0x374
	// Line 2849, Address: 0x24b8c8, Func Offset: 0x378
	// Line 2851, Address: 0x24b8d4, Func Offset: 0x384
	// Line 2852, Address: 0x24b8e8, Func Offset: 0x398
	// Line 2854, Address: 0x24b920, Func Offset: 0x3d0
	// Func End, Address: 0x24b94c, Func Offset: 0x3fc
	scePrintf("bhEff309 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24b950
void bhEff309Drw(OR_WORK* orP)
{
	//_anon56* r09P;
	// Line 2860, Address: 0x24b950, Func Offset: 0
	// Line 2861, Address: 0x24b95c, Func Offset: 0xc
	// Line 2866, Address: 0x24b960, Func Offset: 0x10
	// Line 2867, Address: 0x24b968, Func Offset: 0x18
	// Line 2868, Address: 0x24b974, Func Offset: 0x24
	// Line 2869, Address: 0x24b980, Func Offset: 0x30
	// Line 2875, Address: 0x24b998, Func Offset: 0x48
	// Func End, Address: 0x24b9a8, Func Offset: 0x58
	scePrintf("bhEff309Drw - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x24b9b0
void ryRapTexDrw(_anon5* texP, int tex_id, _rap_tex_typ* rtP)
{
	NJS_POINT3 scl;
	// Line 2881, Address: 0x24b9b0, Func Offset: 0
	// Line 2883, Address: 0x24b9c4, Func Offset: 0x14
	// Line 2884, Address: 0x24b9cc, Func Offset: 0x1c
	// Line 2886, Address: 0x24b9d4, Func Offset: 0x24
	// Line 2888, Address: 0x24b9dc, Func Offset: 0x2c
	// Line 2890, Address: 0x24b9e4, Func Offset: 0x34
	// Line 2892, Address: 0x24b9ec, Func Offset: 0x3c
	// Line 2893, Address: 0x24b9fc, Func Offset: 0x4c
	// Line 2894, Address: 0x24ba08, Func Offset: 0x58
	// Line 2897, Address: 0x24ba10, Func Offset: 0x60
	// Line 2898, Address: 0x24ba14, Func Offset: 0x64
	// Line 2897, Address: 0x24ba18, Func Offset: 0x68
	// Line 2898, Address: 0x24ba20, Func Offset: 0x70
	// Line 2900, Address: 0x24ba28, Func Offset: 0x78
	// Line 2901, Address: 0x24ba34, Func Offset: 0x84
	// Line 2902, Address: 0x24ba38, Func Offset: 0x88
	// Line 2904, Address: 0x24ba40, Func Offset: 0x90
	// Line 2906, Address: 0x24ba48, Func Offset: 0x98
	// Line 2907, Address: 0x24ba50, Func Offset: 0xa0
	// Func End, Address: 0x24ba64, Func Offset: 0xb4
	scePrintf("ryRapTexDrw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ba70
int ryRapTexAnm(_anon20* anmP, _anon21* dspP, int bol)
{
	unsigned int col;
	float* tvP;
	_anon9* uvP;
	int anm_no;
	// Line 2921, Address: 0x24ba70, Func Offset: 0
	// Line 2923, Address: 0x24ba74, Func Offset: 0x4
	// Line 2924, Address: 0x24ba7c, Func Offset: 0xc
	// Line 2926, Address: 0x24ba84, Func Offset: 0x14
	// Line 2924, Address: 0x24ba88, Func Offset: 0x18
	// Line 2930, Address: 0x24ba8c, Func Offset: 0x1c
	// Line 2931, Address: 0x24ba94, Func Offset: 0x24
	// Line 2932, Address: 0x24ba9c, Func Offset: 0x2c
	// Line 2935, Address: 0x24baa0, Func Offset: 0x30
	// Line 2936, Address: 0x24baa8, Func Offset: 0x38
	// Line 2937, Address: 0x24bab8, Func Offset: 0x48
	// Line 2940, Address: 0x24babc, Func Offset: 0x4c
	// Line 2941, Address: 0x24bacc, Func Offset: 0x5c
	// Line 2942, Address: 0x24bad4, Func Offset: 0x64
	// Line 2945, Address: 0x24bad8, Func Offset: 0x68
	// Line 2946, Address: 0x24bae8, Func Offset: 0x78
	// Line 2949, Address: 0x24baf8, Func Offset: 0x88
	// Line 2950, Address: 0x24bb00, Func Offset: 0x90
	// Line 2951, Address: 0x24bb0c, Func Offset: 0x9c
	// Line 2952, Address: 0x24bb1c, Func Offset: 0xac
	// Line 2957, Address: 0x24bb2c, Func Offset: 0xbc
	// Func End, Address: 0x24bb34, Func Offset: 0xc4
	scePrintf("ryRapTexAnm - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24bb40
void ryRapDspSet(NJS_POINT3* posP, _anon21* dspP, float scl)
{
	float* vbP;
	// Line 2967, Address: 0x24bb40, Func Offset: 0
	// Line 2968, Address: 0x24bb44, Func Offset: 0x4
	// Line 2972, Address: 0x24bb50, Func Offset: 0x10
	// Line 2968, Address: 0x24bb60, Func Offset: 0x20
	// Line 2972, Address: 0x24bb6c, Func Offset: 0x2c
	// Line 2973, Address: 0x24bb70, Func Offset: 0x30
	// Line 2974, Address: 0x24bb74, Func Offset: 0x34
	// Line 2977, Address: 0x24bb78, Func Offset: 0x38
	// Line 2978, Address: 0x24bb7c, Func Offset: 0x3c
	// Line 2979, Address: 0x24bb80, Func Offset: 0x40
	// Line 2982, Address: 0x24bb84, Func Offset: 0x44
	// Line 2983, Address: 0x24bb88, Func Offset: 0x48
	// Line 2984, Address: 0x24bb8c, Func Offset: 0x4c
	// Line 2987, Address: 0x24bb90, Func Offset: 0x50
	// Line 2988, Address: 0x24bb94, Func Offset: 0x54
	// Line 2991, Address: 0x24bb98, Func Offset: 0x58
	// Func End, Address: 0x24bba0, Func Offset: 0x60
	scePrintf("ryRapDspSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24bba0
void ryRapAnmColSet(_anon20* anmP, int src_col, int dst_col, int col_cnt)
{
	unsigned int* subP;
	unsigned int* addP;
	int tmp;
	// Line 3005, Address: 0x24bba0, Func Offset: 0
	// Line 3000, Address: 0x24bbb0, Func Offset: 0x10
	// Line 3003, Address: 0x24bbb4, Func Offset: 0x14
	// Line 3005, Address: 0x24bbb8, Func Offset: 0x18
	// Line 3006, Address: 0x24bbc8, Func Offset: 0x28
	// Line 3007, Address: 0x24bbe0, Func Offset: 0x40
	// Line 3009, Address: 0x24bbe8, Func Offset: 0x48
	// Line 3010, Address: 0x24bc04, Func Offset: 0x64
	// Line 3011, Address: 0x24bc24, Func Offset: 0x84
	// Line 3013, Address: 0x24bc34, Func Offset: 0x94
	// Line 3014, Address: 0x24bc54, Func Offset: 0xb4
	// Line 3015, Address: 0x24bc78, Func Offset: 0xd8
	// Line 3017, Address: 0x24bc8c, Func Offset: 0xec
	// Line 3018, Address: 0x24bc94, Func Offset: 0xf4
	// Line 3019, Address: 0x24bcb0, Func Offset: 0x110
	// Line 3020, Address: 0x24bcd4, Func Offset: 0x134
	// Line 3022, Address: 0x24bce8, Func Offset: 0x148
	// Func End, Address: 0x24bcf0, Func Offset: 0x150
	scePrintf("ryRapAnmColSet - UNIMPLEMENTED!\n");
}*/

// 
// Start address: 0x24bcf0
void bhEff30a(OR_WORK* orP)
{
	//_anon8* r0aP;
	// Line 3028, Address: 0x24bcf0, Func Offset: 0
	// Line 3045, Address: 0x24bd04, Func Offset: 0x14
	// Line 3051, Address: 0x24bd30, Func Offset: 0x40
	// Line 3052, Address: 0x24bd44, Func Offset: 0x54
	// Line 3056, Address: 0x24bd4c, Func Offset: 0x5c
	// Line 3059, Address: 0x24bd6c, Func Offset: 0x7c
	// Line 3061, Address: 0x24bd7c, Func Offset: 0x8c
	// Line 3064, Address: 0x24bd9c, Func Offset: 0xac
	// Line 3065, Address: 0x24bda8, Func Offset: 0xb8
	// Line 3068, Address: 0x24bdb4, Func Offset: 0xc4
	// Line 3069, Address: 0x24bdc8, Func Offset: 0xd8
	// Line 3070, Address: 0x24bddc, Func Offset: 0xec
	// Line 3072, Address: 0x24bde8, Func Offset: 0xf8
	// Line 3070, Address: 0x24bdf4, Func Offset: 0x104
	// Line 3072, Address: 0x24bdf8, Func Offset: 0x108
	// Line 3070, Address: 0x24bdfc, Func Offset: 0x10c
	// Line 3072, Address: 0x24be00, Func Offset: 0x110
	// Line 3074, Address: 0x24be08, Func Offset: 0x118
	// Line 3079, Address: 0x24be10, Func Offset: 0x120
	// Line 3074, Address: 0x24be1c, Func Offset: 0x12c
	// Line 3075, Address: 0x24be24, Func Offset: 0x134
	// Line 3076, Address: 0x24be34, Func Offset: 0x144
	// Line 3077, Address: 0x24be44, Func Offset: 0x154
	// Line 3079, Address: 0x24be54, Func Offset: 0x164
	// Line 3080, Address: 0x24be70, Func Offset: 0x180
	// Line 3081, Address: 0x24be7c, Func Offset: 0x18c
	// Line 3085, Address: 0x24be80, Func Offset: 0x190
	// Line 3090, Address: 0x24be90, Func Offset: 0x1a0
	// Func End, Address: 0x24bea4, Func Offset: 0x1b4
	scePrintf("bhEff30a - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24beb0
void bhEff349(OR_WORK* orP)
{
	//_anon74* r49P;
	// Line 3100, Address: 0x24beb0, Func Offset: 0
	// Line 3110, Address: 0x24bec0, Func Offset: 0x10
	// Line 3111, Address: 0x24bed8, Func Offset: 0x28
	// Line 3112, Address: 0x24bee4, Func Offset: 0x34
	// Line 3113, Address: 0x24bee8, Func Offset: 0x38
	// Line 3115, Address: 0x24bf20, Func Offset: 0x70
	// Func End, Address: 0x24bf34, Func Offset: 0x84
	scePrintf("bhEff349 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24bf40
OR_WORK* rySetEffBlood2(float mtxP[16], NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
	//_anon19* r0bP;
	int mode;
	//_anon38* pmbP;
	OR_WORK* orP;
	//_anon41 Eff30bPrm[6];
	// Line 3121, Address: 0x24bf40, Func Offset: 0
	// Line 3141, Address: 0x24bf60, Func Offset: 0x20
	// Line 3121, Address: 0x24bf70, Func Offset: 0x30
	// Line 3141, Address: 0x24bf74, Func Offset: 0x34
	// Line 3160, Address: 0x24bf94, Func Offset: 0x54
	// Line 3161, Address: 0x24bfa8, Func Offset: 0x68
	// Line 3162, Address: 0x24bfbc, Func Offset: 0x7c
	// Line 3165, Address: 0x24bfc4, Func Offset: 0x84
	// Line 3167, Address: 0x24bfec, Func Offset: 0xac
	// Line 3168, Address: 0x24bff0, Func Offset: 0xb0
	// Line 3174, Address: 0x24bffc, Func Offset: 0xbc
	// Line 3168, Address: 0x24c000, Func Offset: 0xc0
	// Line 3169, Address: 0x24c00c, Func Offset: 0xcc
	// Line 3174, Address: 0x24c024, Func Offset: 0xe4
	// Line 3175, Address: 0x24c038, Func Offset: 0xf8
	// Line 3176, Address: 0x24c050, Func Offset: 0x110
	// Line 3180, Address: 0x24c054, Func Offset: 0x114
	// Func End, Address: 0x24c070, Func Offset: 0x130
	scePrintf("rySetEffBlood2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24c070
void bhEff30b(OR_WORK* orP)
{
	//_eff30b_vtx_buf_typ* vbP;
	NJS_POINT3* dirP;
	float max;
	float min;
	float rng;
	//_anon25* vtxP;
	int num;
	//_eff30b_vtx_buf_typ* vbP;
	//int num;
	//_eff30b_vtx_buf_typ* vbP;
	//_anon38* pmbP;
	//_anon19* r0bP;
	// Line 3191, Address: 0x24c070, Func Offset: 0
	// Line 3196, Address: 0x24c0a8, Func Offset: 0x38
	// Line 3192, Address: 0x24c0ac, Func Offset: 0x3c
	// Line 3196, Address: 0x24c0b0, Func Offset: 0x40
	// Line 3199, Address: 0x24c0cc, Func Offset: 0x5c
	// Line 3201, Address: 0x24c0d8, Func Offset: 0x68
	// Line 3204, Address: 0x24c0dc, Func Offset: 0x6c
	// Line 3202, Address: 0x24c0e0, Func Offset: 0x70
	// Line 3201, Address: 0x24c0e4, Func Offset: 0x74
	// Line 3202, Address: 0x24c0e8, Func Offset: 0x78
	// Line 3204, Address: 0x24c0ec, Func Offset: 0x7c
	// Line 3205, Address: 0x24c0f8, Func Offset: 0x88
	// Line 3206, Address: 0x24c104, Func Offset: 0x94
	// Line 3207, Address: 0x24c128, Func Offset: 0xb8
	// Line 3208, Address: 0x24c14c, Func Offset: 0xdc
	// Line 3215, Address: 0x24c158, Func Offset: 0xe8
	// Line 3217, Address: 0x24c160, Func Offset: 0xf0
	// Line 3215, Address: 0x24c164, Func Offset: 0xf4
	// Line 3217, Address: 0x24c170, Func Offset: 0x100
	// Line 3215, Address: 0x24c178, Func Offset: 0x108
	// Line 3219, Address: 0x24c188, Func Offset: 0x118
	// Line 3220, Address: 0x24c19c, Func Offset: 0x12c
	// Line 3221, Address: 0x24c1a8, Func Offset: 0x138
	// Line 3222, Address: 0x24c1b4, Func Offset: 0x144
	// Line 3223, Address: 0x24c1c0, Func Offset: 0x150
	// Line 3224, Address: 0x24c1d0, Func Offset: 0x160
	// Line 3225, Address: 0x24c1d8, Func Offset: 0x168
	// Line 3230, Address: 0x24c1dc, Func Offset: 0x16c
	// Line 3237, Address: 0x24c1e8, Func Offset: 0x178
	// Line 3239, Address: 0x24c1f4, Func Offset: 0x184
	// Line 3241, Address: 0x24c1f8, Func Offset: 0x188
	// Line 3244, Address: 0x24c200, Func Offset: 0x190
	// Line 3246, Address: 0x24c20c, Func Offset: 0x19c
	// Line 3247, Address: 0x24c214, Func Offset: 0x1a4
	// Line 3248, Address: 0x24c264, Func Offset: 0x1f4
	// Line 3252, Address: 0x24c270, Func Offset: 0x200
	// Line 3254, Address: 0x24c278, Func Offset: 0x208
	// Line 3255, Address: 0x24c2c0, Func Offset: 0x250
	// Line 3256, Address: 0x24c308, Func Offset: 0x298
	// Line 3258, Address: 0x24c354, Func Offset: 0x2e4
	// Line 3259, Address: 0x24c360, Func Offset: 0x2f0
	// Line 3262, Address: 0x24c378, Func Offset: 0x308
	// Line 3265, Address: 0x24c388, Func Offset: 0x318
	// Line 3266, Address: 0x24c38c, Func Offset: 0x31c
	// Line 3267, Address: 0x24c390, Func Offset: 0x320
	// Line 3269, Address: 0x24c394, Func Offset: 0x324
	// Line 3270, Address: 0x24c3a8, Func Offset: 0x338
	// Line 3272, Address: 0x24c3b8, Func Offset: 0x348
	// Line 3273, Address: 0x24c3e0, Func Offset: 0x370
	// Line 3274, Address: 0x24c3e8, Func Offset: 0x378
	// Line 3278, Address: 0x24c3f4, Func Offset: 0x384
	// Line 3279, Address: 0x24c434, Func Offset: 0x3c4
	// Line 3284, Address: 0x24c438, Func Offset: 0x3c8
	// Line 3286, Address: 0x24c444, Func Offset: 0x3d4
	// Line 3287, Address: 0x24c45c, Func Offset: 0x3ec
	// Line 3288, Address: 0x24c47c, Func Offset: 0x40c
	// Line 3290, Address: 0x24c494, Func Offset: 0x424
	// Line 3291, Address: 0x24c4a4, Func Offset: 0x434
	// Line 3293, Address: 0x24c4b4, Func Offset: 0x444
	// Line 3294, Address: 0x24c4dc, Func Offset: 0x46c
	// Line 3296, Address: 0x24c4f8, Func Offset: 0x488
	// Line 3297, Address: 0x24c504, Func Offset: 0x494
	// Line 3300, Address: 0x24c510, Func Offset: 0x4a0
	// Line 3301, Address: 0x24c528, Func Offset: 0x4b8
	// Line 3303, Address: 0x24c538, Func Offset: 0x4c8
	// Line 3307, Address: 0x24c598, Func Offset: 0x528
	// Line 3308, Address: 0x24c59c, Func Offset: 0x52c
	// Line 3311, Address: 0x24c5c4, Func Offset: 0x554
	// Line 3312, Address: 0x24c5c8, Func Offset: 0x558
	// Func End, Address: 0x24c600, Func Offset: 0x590
	scePrintf("bhEff30b - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24c600
void bhEff30bDrw(OR_WORK* orP)
{
	float scl;
	//_eff30b_vtx_buf_typ* vbP;
	int num;
	//_anon25* vtxP;
	//_anon19* r0bP;
	//_anon6 VtxBuf[4];
	// Line 3316, Address: 0x24c600, Func Offset: 0
	// Line 3317, Address: 0x24c618, Func Offset: 0x18
	// Line 3324, Address: 0x24c61c, Func Offset: 0x1c
	// Line 3325, Address: 0x24c62c, Func Offset: 0x2c
	// Line 3327, Address: 0x24c638, Func Offset: 0x38
	// Line 3328, Address: 0x24c640, Func Offset: 0x40
	// Line 3329, Address: 0x24c650, Func Offset: 0x50
	// Line 3347, Address: 0x24c658, Func Offset: 0x58
	// Line 3350, Address: 0x24c660, Func Offset: 0x60
	// Line 3351, Address: 0x24c66c, Func Offset: 0x6c
	// Line 3360, Address: 0x24c678, Func Offset: 0x78
	// Line 3363, Address: 0x24c680, Func Offset: 0x80
	// Line 3364, Address: 0x24c694, Func Offset: 0x94
	// Line 3365, Address: 0x24c6a0, Func Offset: 0xa0
	// Line 3366, Address: 0x24c6a8, Func Offset: 0xa8
	// Line 3367, Address: 0x24c6bc, Func Offset: 0xbc
	// Line 3369, Address: 0x24c6e0, Func Offset: 0xe0
	// Line 3370, Address: 0x24c6f4, Func Offset: 0xf4
	// Line 3371, Address: 0x24c708, Func Offset: 0x108
	// Line 3372, Address: 0x24c714, Func Offset: 0x114
	// Line 3374, Address: 0x24c720, Func Offset: 0x120
	// Line 3382, Address: 0x24c728, Func Offset: 0x128
	// Func End, Address: 0x24c748, Func Offset: 0x148
	scePrintf("bhEff30bDrw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24c750
void bhEff30c(OR_WORK* orP)
{
	//_anon61* r0cP;
	// Line 3388, Address: 0x24c750, Func Offset: 0
	// Line 3399, Address: 0x24c764, Func Offset: 0x14
	// Line 3402, Address: 0x24c784, Func Offset: 0x34
	// Line 3403, Address: 0x24c790, Func Offset: 0x40
	// Line 3406, Address: 0x24c798, Func Offset: 0x48
	// Line 3412, Address: 0x24c7a0, Func Offset: 0x50
	// Line 3416, Address: 0x24c7ac, Func Offset: 0x5c
	// Line 3417, Address: 0x24c7b8, Func Offset: 0x68
	// Line 3418, Address: 0x24c7cc, Func Offset: 0x7c
	// Line 3420, Address: 0x24c7e0, Func Offset: 0x90
	// Line 3421, Address: 0x24c7f4, Func Offset: 0xa4
	// Line 3425, Address: 0x24c82c, Func Offset: 0xdc
	// Func End, Address: 0x24c840, Func Offset: 0xf0
	scePrintf("bhEff30c - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24c840
void bhEff30cDrw(OR_WORK* orP)
{
	//_anon61* r0cP;
	// Line 3431, Address: 0x24c840, Func Offset: 0
	// Line 3432, Address: 0x24c84c, Func Offset: 0xc
	// Line 3435, Address: 0x24c850, Func Offset: 0x10
	// Line 3437, Address: 0x24c864, Func Offset: 0x24
	// Line 3439, Address: 0x24c870, Func Offset: 0x30
	// Line 3440, Address: 0x24c87c, Func Offset: 0x3c
	// Line 3442, Address: 0x24c884, Func Offset: 0x44
	// Line 3443, Address: 0x24c88c, Func Offset: 0x4c
	// Func End, Address: 0x24c89c, Func Offset: 0x5c
	scePrintf("bhEff30cDrw - UNIMPLEMENTED!\n");
}
