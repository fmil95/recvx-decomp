#include "../../../ps2/veronica/prog/pl_evt.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/player.h"

unsigned char basic_motion_pl[32][2] = 
{
    { 0, 200 },
    { 0, 201 },
    { 0, 202 },
    { 0, 203 },
    { 0, 204 },
    { 1, 205 },
    { 1, 206 },
    { 1, 207 },
    { 1, 208 },
    { 1, 209 },
    { 0, 210 },
    { 0, 211 },
    { 0, 212 },
    { 0, 213 },
    { 0, 214 },
    { 1, 215 },
    { 1, 216 },
    { 1, 217 },
    { 1, 218 },
    { 1, 219 },
    { 0, 220 },
    { 0, 221 },
    { 0, 222 },
    { 0, 223 },
    { 0, 224 },
    { 1, 225 },
    { 1, 226 },
    { 1, 227 },
    { 1, 228 },
    { 1, 229 },
    { 0,   0 },
    { 0,   0 }
};
void (*bhCPM0_event_tbl[10])() = 
{
	pl_smove00,
	pl_smove01,
	pl_smove02,
	pl_smove03,
	pl_smove04,
	pl_smove05,
	pl_smove06,
	pl_smove07,
	pl_smove08,
	pl_smove00
};

// 100% matching!
void bhCPM0_event()
{
	bhCPM0_event_tbl[plp->mode2]();
}

// 100% matching!
void pl_smove00() 
{
    switch (plp->mode3)
    {                         
    case 0:
        plp->flg |= 0xD0000;
        
        EXP1_I(0x0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6];
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->mode3++;
    case 1:
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6] + 1;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    }
}

/*// 
// Start address: 0x172070
void pl_smove01()
{
	// Line 214, Address: 0x172070, Func Offset: 0
	// Line 217, Address: 0x17207c, Func Offset: 0xc
	// Line 219, Address: 0x1720b0, Func Offset: 0x40
	// Line 221, Address: 0x1720cc, Func Offset: 0x5c
	// Line 228, Address: 0x1720d8, Func Offset: 0x68
	// Line 221, Address: 0x1720e0, Func Offset: 0x70
	// Line 228, Address: 0x1720e4, Func Offset: 0x74
	// Line 221, Address: 0x1720e8, Func Offset: 0x78
	// Line 222, Address: 0x1720ec, Func Offset: 0x7c
	// Line 223, Address: 0x1720f4, Func Offset: 0x84
	// Line 221, Address: 0x1720f8, Func Offset: 0x88
	// Line 224, Address: 0x172124, Func Offset: 0xb4
	// Line 221, Address: 0x172128, Func Offset: 0xb8
	// Line 222, Address: 0x17212c, Func Offset: 0xbc
	// Line 223, Address: 0x172134, Func Offset: 0xc4
	// Line 224, Address: 0x172140, Func Offset: 0xd0
	// Line 225, Address: 0x17214c, Func Offset: 0xdc
	// Line 226, Address: 0x172158, Func Offset: 0xe8
	// Line 227, Address: 0x172164, Func Offset: 0xf4
	// Line 228, Address: 0x172170, Func Offset: 0x100
	// Line 227, Address: 0x172174, Func Offset: 0x104
	// Line 228, Address: 0x172178, Func Offset: 0x108
	// Line 229, Address: 0x172184, Func Offset: 0x114
	// Line 228, Address: 0x172188, Func Offset: 0x118
	// Line 229, Address: 0x172198, Func Offset: 0x128
	// Line 230, Address: 0x1721a4, Func Offset: 0x134
	// Line 229, Address: 0x1721a8, Func Offset: 0x138
	// Line 230, Address: 0x1721b8, Func Offset: 0x148
	// Line 232, Address: 0x1721c8, Func Offset: 0x158
	// Line 233, Address: 0x1721dc, Func Offset: 0x16c
	// Line 234, Address: 0x1721ec, Func Offset: 0x17c
	// Line 235, Address: 0x1721f4, Func Offset: 0x184
	// Line 236, Address: 0x172200, Func Offset: 0x190
	// Line 237, Address: 0x172208, Func Offset: 0x198
	// Line 236, Address: 0x17220c, Func Offset: 0x19c
	// Line 237, Address: 0x172218, Func Offset: 0x1a8
	// Line 241, Address: 0x17222c, Func Offset: 0x1bc
	// Line 243, Address: 0x172234, Func Offset: 0x1c4
	// Line 245, Address: 0x172250, Func Offset: 0x1e0
	// Line 246, Address: 0x17225c, Func Offset: 0x1ec
	// Line 245, Address: 0x172268, Func Offset: 0x1f8
	// Line 246, Address: 0x172270, Func Offset: 0x200
	// Line 247, Address: 0x172274, Func Offset: 0x204
	// Line 248, Address: 0x172278, Func Offset: 0x208
	// Line 249, Address: 0x17227c, Func Offset: 0x20c
	// Line 246, Address: 0x172280, Func Offset: 0x210
	// Line 247, Address: 0x172284, Func Offset: 0x214
	// Line 246, Address: 0x172288, Func Offset: 0x218
	// Line 247, Address: 0x1722c0, Func Offset: 0x250
	// Line 248, Address: 0x1722c8, Func Offset: 0x258
	// Line 249, Address: 0x1722d4, Func Offset: 0x264
	// Line 250, Address: 0x1722e0, Func Offset: 0x270
	// Line 251, Address: 0x1722ec, Func Offset: 0x27c
	// Line 252, Address: 0x1722f8, Func Offset: 0x288
	// Line 251, Address: 0x1722fc, Func Offset: 0x28c
	// Line 252, Address: 0x172300, Func Offset: 0x290
	// Line 256, Address: 0x172310, Func Offset: 0x2a0
	// Line 257, Address: 0x172348, Func Offset: 0x2d8
	// Line 258, Address: 0x172350, Func Offset: 0x2e0
	// Line 256, Address: 0x172354, Func Offset: 0x2e4
	// Line 257, Address: 0x17235c, Func Offset: 0x2ec
	// Line 258, Address: 0x172364, Func Offset: 0x2f4
	// Line 260, Address: 0x1723a4, Func Offset: 0x334
	// Line 261, Address: 0x1723b4, Func Offset: 0x344
	// Line 263, Address: 0x1723bc, Func Offset: 0x34c
	// Line 265, Address: 0x1723dc, Func Offset: 0x36c
	// Line 266, Address: 0x1723e8, Func Offset: 0x378
	// Line 265, Address: 0x1723f4, Func Offset: 0x384
	// Line 266, Address: 0x1723fc, Func Offset: 0x38c
	// Line 267, Address: 0x172400, Func Offset: 0x390
	// Line 268, Address: 0x172404, Func Offset: 0x394
	// Line 269, Address: 0x172408, Func Offset: 0x398
	// Line 266, Address: 0x17240c, Func Offset: 0x39c
	// Line 267, Address: 0x172410, Func Offset: 0x3a0
	// Line 266, Address: 0x172414, Func Offset: 0x3a4
	// Line 267, Address: 0x17244c, Func Offset: 0x3dc
	// Line 268, Address: 0x172454, Func Offset: 0x3e4
	// Line 269, Address: 0x172460, Func Offset: 0x3f0
	// Line 270, Address: 0x17246c, Func Offset: 0x3fc
	// Line 271, Address: 0x172478, Func Offset: 0x408
	// Line 272, Address: 0x172484, Func Offset: 0x414
	// Line 271, Address: 0x172488, Func Offset: 0x418
	// Line 272, Address: 0x17248c, Func Offset: 0x41c
	// Line 276, Address: 0x17249c, Func Offset: 0x42c
	// Line 277, Address: 0x1724d4, Func Offset: 0x464
	// Line 278, Address: 0x1724dc, Func Offset: 0x46c
	// Line 276, Address: 0x1724e0, Func Offset: 0x470
	// Line 277, Address: 0x1724e8, Func Offset: 0x478
	// Line 278, Address: 0x1724f0, Func Offset: 0x480
	// Line 280, Address: 0x172530, Func Offset: 0x4c0
	// Line 283, Address: 0x172540, Func Offset: 0x4d0
	// Line 284, Address: 0x17255c, Func Offset: 0x4ec
	// Func End, Address: 0x17256c, Func Offset: 0x4fc
}

// 
// Start address: 0x172570
void pl_smove02()
{
	int fsnd;
	// Line 294, Address: 0x172570, Func Offset: 0
	// Line 298, Address: 0x17257c, Func Offset: 0xc
	// Line 300, Address: 0x1725a4, Func Offset: 0x34
	// Line 301, Address: 0x1725b0, Func Offset: 0x40
	// Line 300, Address: 0x1725b8, Func Offset: 0x48
	// Line 301, Address: 0x1725c0, Func Offset: 0x50
	// Line 302, Address: 0x1725d4, Func Offset: 0x64
	// Line 303, Address: 0x1725d8, Func Offset: 0x68
	// Line 304, Address: 0x1725e0, Func Offset: 0x70
	// Line 308, Address: 0x172668, Func Offset: 0xf8
	// Line 310, Address: 0x172678, Func Offset: 0x108
	// Line 308, Address: 0x172680, Func Offset: 0x110
	// Line 309, Address: 0x172684, Func Offset: 0x114
	// Line 311, Address: 0x172688, Func Offset: 0x118
	// Line 312, Address: 0x17268c, Func Offset: 0x11c
	// Line 313, Address: 0x172690, Func Offset: 0x120
	// Line 308, Address: 0x172694, Func Offset: 0x124
	// Line 309, Address: 0x17269c, Func Offset: 0x12c
	// Line 314, Address: 0x1726a0, Func Offset: 0x130
	// Line 315, Address: 0x1726a4, Func Offset: 0x134
	// Line 309, Address: 0x1726a8, Func Offset: 0x138
	// Line 310, Address: 0x1726ac, Func Offset: 0x13c
	// Line 309, Address: 0x1726b0, Func Offset: 0x140
	// Line 310, Address: 0x1726bc, Func Offset: 0x14c
	// Line 311, Address: 0x1726c4, Func Offset: 0x154
	// Line 310, Address: 0x1726c8, Func Offset: 0x158
	// Line 311, Address: 0x172700, Func Offset: 0x190
	// Line 312, Address: 0x172708, Func Offset: 0x198
	// Line 313, Address: 0x172714, Func Offset: 0x1a4
	// Line 314, Address: 0x172720, Func Offset: 0x1b0
	// Line 315, Address: 0x17272c, Func Offset: 0x1bc
	// Line 314, Address: 0x172730, Func Offset: 0x1c0
	// Line 315, Address: 0x172734, Func Offset: 0x1c4
	// Line 316, Address: 0x172748, Func Offset: 0x1d8
	// Line 317, Address: 0x17275c, Func Offset: 0x1ec
	// Line 320, Address: 0x172770, Func Offset: 0x200
	// Line 327, Address: 0x1727e4, Func Offset: 0x274
	// Line 320, Address: 0x1727e8, Func Offset: 0x278
	// Line 327, Address: 0x1727ec, Func Offset: 0x27c
	// Line 328, Address: 0x172820, Func Offset: 0x2b0
	// Line 330, Address: 0x17284c, Func Offset: 0x2dc
	// Line 331, Address: 0x172880, Func Offset: 0x310
	// Line 333, Address: 0x172888, Func Offset: 0x318
	// Line 337, Address: 0x1728c0, Func Offset: 0x350
	// Line 338, Address: 0x172900, Func Offset: 0x390
	// Line 341, Address: 0x172918, Func Offset: 0x3a8
	// Line 342, Address: 0x172928, Func Offset: 0x3b8
	// Line 343, Address: 0x172930, Func Offset: 0x3c0
	// Line 342, Address: 0x172934, Func Offset: 0x3c4
	// Line 343, Address: 0x172938, Func Offset: 0x3c8
	// Line 342, Address: 0x17293c, Func Offset: 0x3cc
	// Line 343, Address: 0x172944, Func Offset: 0x3d4
	// Line 344, Address: 0x172958, Func Offset: 0x3e8
	// Line 345, Address: 0x17296c, Func Offset: 0x3fc
	// Line 349, Address: 0x172994, Func Offset: 0x424
	// Line 350, Address: 0x1729d4, Func Offset: 0x464
	// Line 353, Address: 0x1729ec, Func Offset: 0x47c
	// Line 354, Address: 0x1729fc, Func Offset: 0x48c
	// Line 355, Address: 0x172a04, Func Offset: 0x494
	// Line 354, Address: 0x172a08, Func Offset: 0x498
	// Line 355, Address: 0x172a0c, Func Offset: 0x49c
	// Line 354, Address: 0x172a10, Func Offset: 0x4a0
	// Line 355, Address: 0x172a18, Func Offset: 0x4a8
	// Line 356, Address: 0x172a2c, Func Offset: 0x4bc
	// Line 357, Address: 0x172a40, Func Offset: 0x4d0
	// Line 362, Address: 0x172a68, Func Offset: 0x4f8
	// Line 364, Address: 0x172a78, Func Offset: 0x508
	// Func End, Address: 0x172a88, Func Offset: 0x518
}

// 
// Start address: 0x172a90
void pl_smove03()
{
	int fsnd;
	// Line 374, Address: 0x172a90, Func Offset: 0
	// Line 377, Address: 0x172a9c, Func Offset: 0xc
	// Line 379, Address: 0x172ac4, Func Offset: 0x34
	// Line 381, Address: 0x172ad0, Func Offset: 0x40
	// Line 379, Address: 0x172ad8, Func Offset: 0x48
	// Line 380, Address: 0x172ae0, Func Offset: 0x50
	// Line 381, Address: 0x172aec, Func Offset: 0x5c
	// Line 380, Address: 0x172af0, Func Offset: 0x60
	// Line 381, Address: 0x172afc, Func Offset: 0x6c
	// Line 384, Address: 0x172b7c, Func Offset: 0xec
	// Line 385, Address: 0x172b84, Func Offset: 0xf4
	// Line 386, Address: 0x172b88, Func Offset: 0xf8
	// Line 381, Address: 0x172b8c, Func Offset: 0xfc
	// Line 384, Address: 0x172b90, Func Offset: 0x100
	// Line 387, Address: 0x172b98, Func Offset: 0x108
	// Line 388, Address: 0x172b9c, Func Offset: 0x10c
	// Line 384, Address: 0x172ba0, Func Offset: 0x110
	// Line 385, Address: 0x172ba4, Func Offset: 0x114
	// Line 384, Address: 0x172ba8, Func Offset: 0x118
	// Line 385, Address: 0x172be0, Func Offset: 0x150
	// Line 386, Address: 0x172be8, Func Offset: 0x158
	// Line 387, Address: 0x172bf4, Func Offset: 0x164
	// Line 388, Address: 0x172c00, Func Offset: 0x170
	// Line 389, Address: 0x172c0c, Func Offset: 0x17c
	// Line 388, Address: 0x172c10, Func Offset: 0x180
	// Line 389, Address: 0x172c14, Func Offset: 0x184
	// Line 391, Address: 0x172c24, Func Offset: 0x194
	// Line 393, Address: 0x172c98, Func Offset: 0x208
	// Line 391, Address: 0x172c9c, Func Offset: 0x20c
	// Line 393, Address: 0x172ca0, Func Offset: 0x210
	// Line 394, Address: 0x172cd4, Func Offset: 0x244
	// Line 395, Address: 0x172d0c, Func Offset: 0x27c
	// Line 397, Address: 0x172d38, Func Offset: 0x2a8
	// Line 398, Address: 0x172d6c, Func Offset: 0x2dc
	// Line 400, Address: 0x172d74, Func Offset: 0x2e4
	// Line 404, Address: 0x172dac, Func Offset: 0x31c
	// Line 405, Address: 0x172dec, Func Offset: 0x35c
	// Line 408, Address: 0x172e04, Func Offset: 0x374
	// Line 409, Address: 0x172e14, Func Offset: 0x384
	// Line 410, Address: 0x172e1c, Func Offset: 0x38c
	// Line 409, Address: 0x172e20, Func Offset: 0x390
	// Line 410, Address: 0x172e24, Func Offset: 0x394
	// Line 409, Address: 0x172e28, Func Offset: 0x398
	// Line 410, Address: 0x172e30, Func Offset: 0x3a0
	// Line 411, Address: 0x172e44, Func Offset: 0x3b4
	// Line 412, Address: 0x172e58, Func Offset: 0x3c8
	// Line 416, Address: 0x172e80, Func Offset: 0x3f0
	// Line 417, Address: 0x172ec0, Func Offset: 0x430
	// Line 420, Address: 0x172ed8, Func Offset: 0x448
	// Line 421, Address: 0x172ee8, Func Offset: 0x458
	// Line 422, Address: 0x172ef0, Func Offset: 0x460
	// Line 421, Address: 0x172ef4, Func Offset: 0x464
	// Line 422, Address: 0x172ef8, Func Offset: 0x468
	// Line 421, Address: 0x172efc, Func Offset: 0x46c
	// Line 422, Address: 0x172f04, Func Offset: 0x474
	// Line 423, Address: 0x172f18, Func Offset: 0x488
	// Line 424, Address: 0x172f2c, Func Offset: 0x49c
	// Line 429, Address: 0x172f54, Func Offset: 0x4c4
	// Line 430, Address: 0x172f64, Func Offset: 0x4d4
	// Func End, Address: 0x172f74, Func Offset: 0x4e4
}

// 
// Start address: 0x172f80
void pl_smove04()
{
	int fsnd;
	// Line 441, Address: 0x172f80, Func Offset: 0
	// Line 445, Address: 0x172f8c, Func Offset: 0xc
	// Line 447, Address: 0x172fb4, Func Offset: 0x34
	// Line 448, Address: 0x172fc0, Func Offset: 0x40
	// Line 447, Address: 0x172fc4, Func Offset: 0x44
	// Line 448, Address: 0x172fcc, Func Offset: 0x4c
	// Line 449, Address: 0x172fd4, Func Offset: 0x54
	// Line 448, Address: 0x172fd8, Func Offset: 0x58
	// Line 449, Address: 0x172fe4, Func Offset: 0x64
	// Line 451, Address: 0x17301c, Func Offset: 0x9c
	// Line 452, Address: 0x173020, Func Offset: 0xa0
	// Line 453, Address: 0x173028, Func Offset: 0xa8
	// Line 457, Address: 0x1730b8, Func Offset: 0x138
	// Line 458, Address: 0x1730c8, Func Offset: 0x148
	// Line 457, Address: 0x1730d0, Func Offset: 0x150
	// Line 458, Address: 0x1730d4, Func Offset: 0x154
	// Line 459, Address: 0x1730d8, Func Offset: 0x158
	// Line 460, Address: 0x1730dc, Func Offset: 0x15c
	// Line 461, Address: 0x1730e0, Func Offset: 0x160
	// Line 457, Address: 0x1730e4, Func Offset: 0x164
	// Line 458, Address: 0x1730ec, Func Offset: 0x16c
	// Line 463, Address: 0x1730f0, Func Offset: 0x170
	// Line 464, Address: 0x1730f4, Func Offset: 0x174
	// Line 458, Address: 0x1730f8, Func Offset: 0x178
	// Line 459, Address: 0x1730fc, Func Offset: 0x17c
	// Line 458, Address: 0x173100, Func Offset: 0x180
	// Line 459, Address: 0x173138, Func Offset: 0x1b8
	// Line 460, Address: 0x173140, Func Offset: 0x1c0
	// Line 461, Address: 0x17314c, Func Offset: 0x1cc
	// Line 462, Address: 0x173158, Func Offset: 0x1d8
	// Line 463, Address: 0x173164, Func Offset: 0x1e4
	// Line 464, Address: 0x173170, Func Offset: 0x1f0
	// Line 463, Address: 0x173174, Func Offset: 0x1f4
	// Line 464, Address: 0x173178, Func Offset: 0x1f8
	// Line 465, Address: 0x17318c, Func Offset: 0x20c
	// Line 466, Address: 0x1731a0, Func Offset: 0x220
	// Line 484, Address: 0x1731b4, Func Offset: 0x234
	// Line 490, Address: 0x173228, Func Offset: 0x2a8
	// Line 484, Address: 0x17322c, Func Offset: 0x2ac
	// Line 490, Address: 0x173230, Func Offset: 0x2b0
	// Line 492, Address: 0x173264, Func Offset: 0x2e4
	// Line 494, Address: 0x173290, Func Offset: 0x310
	// Line 495, Address: 0x1732c4, Func Offset: 0x344
	// Line 497, Address: 0x1732cc, Func Offset: 0x34c
	// Line 501, Address: 0x173304, Func Offset: 0x384
	// Line 502, Address: 0x173344, Func Offset: 0x3c4
	// Line 505, Address: 0x17335c, Func Offset: 0x3dc
	// Line 506, Address: 0x17336c, Func Offset: 0x3ec
	// Line 507, Address: 0x173374, Func Offset: 0x3f4
	// Line 506, Address: 0x173378, Func Offset: 0x3f8
	// Line 507, Address: 0x17337c, Func Offset: 0x3fc
	// Line 506, Address: 0x173380, Func Offset: 0x400
	// Line 507, Address: 0x173388, Func Offset: 0x408
	// Line 508, Address: 0x17339c, Func Offset: 0x41c
	// Line 509, Address: 0x1733b0, Func Offset: 0x430
	// Line 513, Address: 0x1733d8, Func Offset: 0x458
	// Line 514, Address: 0x173418, Func Offset: 0x498
	// Line 517, Address: 0x173430, Func Offset: 0x4b0
	// Line 518, Address: 0x173440, Func Offset: 0x4c0
	// Line 519, Address: 0x173448, Func Offset: 0x4c8
	// Line 518, Address: 0x17344c, Func Offset: 0x4cc
	// Line 519, Address: 0x173450, Func Offset: 0x4d0
	// Line 518, Address: 0x173454, Func Offset: 0x4d4
	// Line 519, Address: 0x17345c, Func Offset: 0x4dc
	// Line 520, Address: 0x173470, Func Offset: 0x4f0
	// Line 521, Address: 0x173484, Func Offset: 0x504
	// Line 526, Address: 0x1734ac, Func Offset: 0x52c
	// Line 527, Address: 0x1734bc, Func Offset: 0x53c
	// Func End, Address: 0x1734cc, Func Offset: 0x54c
}*/

// 100% matching!
void pl_smove05()
{
    switch (plp->mode3)
    { 
    case 0:
        plp->mtn_md &= ~0x2;
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        switch (plp->ct0)
        {
        case 0:
            plp->mode3 = 1;
            break;
        case 1:
            plp->mode3 = 3;
            break;
        case 2:
            plp->mode3 = 4;
            break;
        }
        
        plp->mtn_no = basic_motion_pl[plp->mode1][1];
        break;
    case 1:
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;

            plp->mtn_add = 65536;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    case 3:
        if ((plp->ct2 - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = (plp->ct2 - 2) * 65536;
        }
        
        break;
    case 4:
        plp->ct2 = (unsigned int)plp->frm_no / 65536;
        
        plp->frm_no = (plp->ct2 - 1) * 65536;
        break;
    }
}

/*// 
// Start address: 0x1736c0
void pl_smove06()
{
	int fsnd;
	// Line 644, Address: 0x1736c0, Func Offset: 0
	// Line 649, Address: 0x1736c8, Func Offset: 0x8
	// Line 651, Address: 0x1736f0, Func Offset: 0x30
	// Line 652, Address: 0x1736f8, Func Offset: 0x38
	// Line 651, Address: 0x173704, Func Offset: 0x44
	// Line 652, Address: 0x17370c, Func Offset: 0x4c
	// Line 653, Address: 0x173710, Func Offset: 0x50
	// Line 652, Address: 0x173718, Func Offset: 0x58
	// Line 653, Address: 0x17371c, Func Offset: 0x5c
	// Line 652, Address: 0x173720, Func Offset: 0x60
	// Line 653, Address: 0x173728, Func Offset: 0x68
	// Line 656, Address: 0x1737a8, Func Offset: 0xe8
	// Line 658, Address: 0x1737b0, Func Offset: 0xf0
	// Line 653, Address: 0x1737b8, Func Offset: 0xf8
	// Line 656, Address: 0x1737bc, Func Offset: 0xfc
	// Line 659, Address: 0x1737c4, Func Offset: 0x104
	// Line 660, Address: 0x1737c8, Func Offset: 0x108
	// Line 661, Address: 0x1737cc, Func Offset: 0x10c
	// Line 663, Address: 0x1737d0, Func Offset: 0x110
	// Line 656, Address: 0x1737d4, Func Offset: 0x114
	// Line 658, Address: 0x1737d8, Func Offset: 0x118
	// Line 656, Address: 0x1737dc, Func Offset: 0x11c
	// Line 658, Address: 0x1737e4, Func Offset: 0x124
	// Line 659, Address: 0x1737f0, Func Offset: 0x130
	// Line 658, Address: 0x1737f4, Func Offset: 0x134
	// Line 659, Address: 0x173828, Func Offset: 0x168
	// Line 660, Address: 0x173830, Func Offset: 0x170
	// Line 661, Address: 0x17383c, Func Offset: 0x17c
	// Line 662, Address: 0x173848, Func Offset: 0x188
	// Line 663, Address: 0x173854, Func Offset: 0x194
	// Line 662, Address: 0x173858, Func Offset: 0x198
	// Line 663, Address: 0x173860, Func Offset: 0x1a0
	// Line 665, Address: 0x173870, Func Offset: 0x1b0
	// Line 672, Address: 0x1738e4, Func Offset: 0x224
	// Line 665, Address: 0x1738f8, Func Offset: 0x238
	// Line 672, Address: 0x1738fc, Func Offset: 0x23c
	// Line 688, Address: 0x17393c, Func Offset: 0x27c
	// Line 672, Address: 0x173940, Func Offset: 0x280
	// Line 688, Address: 0x173944, Func Offset: 0x284
	// Line 672, Address: 0x173948, Func Offset: 0x288
	// Line 688, Address: 0x173950, Func Offset: 0x290
	// Line 689, Address: 0x173964, Func Offset: 0x2a4
	// Line 692, Address: 0x17397c, Func Offset: 0x2bc
	// Line 695, Address: 0x17398c, Func Offset: 0x2cc
	// Line 696, Address: 0x1739a8, Func Offset: 0x2e8
	// Line 699, Address: 0x1739c0, Func Offset: 0x300
	// Line 703, Address: 0x1739d0, Func Offset: 0x310
	// Line 705, Address: 0x1739e0, Func Offset: 0x320
	// Func End, Address: 0x1739ec, Func Offset: 0x32c
}

// 
// Start address: 0x1739f0
void pl_smove07()
{
	int fsnd;
	// Line 715, Address: 0x1739f0, Func Offset: 0
	// Line 720, Address: 0x1739f8, Func Offset: 0x8
	// Line 722, Address: 0x173a20, Func Offset: 0x30
	// Line 723, Address: 0x173a2c, Func Offset: 0x3c
	// Line 722, Address: 0x173a34, Func Offset: 0x44
	// Line 723, Address: 0x173a3c, Func Offset: 0x4c
	// Line 726, Address: 0x173ac0, Func Offset: 0xd0
	// Line 727, Address: 0x173ac8, Func Offset: 0xd8
	// Line 728, Address: 0x173acc, Func Offset: 0xdc
	// Line 723, Address: 0x173ad0, Func Offset: 0xe0
	// Line 726, Address: 0x173ad4, Func Offset: 0xe4
	// Line 729, Address: 0x173adc, Func Offset: 0xec
	// Line 726, Address: 0x173ae0, Func Offset: 0xf0
	// Line 727, Address: 0x173ae8, Func Offset: 0xf8
	// Line 726, Address: 0x173aec, Func Offset: 0xfc
	// Line 727, Address: 0x173b20, Func Offset: 0x130
	// Line 728, Address: 0x173b28, Func Offset: 0x138
	// Line 729, Address: 0x173b34, Func Offset: 0x144
	// Line 730, Address: 0x173b40, Func Offset: 0x150
	// Line 732, Address: 0x173b54, Func Offset: 0x164
	// Line 739, Address: 0x173bc8, Func Offset: 0x1d8
	// Line 732, Address: 0x173bdc, Func Offset: 0x1ec
	// Line 739, Address: 0x173be0, Func Offset: 0x1f0
	// Line 755, Address: 0x173c20, Func Offset: 0x230
	// Line 739, Address: 0x173c24, Func Offset: 0x234
	// Line 755, Address: 0x173c28, Func Offset: 0x238
	// Line 739, Address: 0x173c2c, Func Offset: 0x23c
	// Line 755, Address: 0x173c34, Func Offset: 0x244
	// Line 756, Address: 0x173c48, Func Offset: 0x258
	// Line 759, Address: 0x173c60, Func Offset: 0x270
	// Line 762, Address: 0x173c70, Func Offset: 0x280
	// Line 763, Address: 0x173c88, Func Offset: 0x298
	// Line 766, Address: 0x173ca0, Func Offset: 0x2b0
	// Line 770, Address: 0x173cb0, Func Offset: 0x2c0
	// Line 771, Address: 0x173cc0, Func Offset: 0x2d0
	// Func End, Address: 0x173ccc, Func Offset: 0x2dc
}*/

// 100% matching!
void pl_smove08()
{
    switch (plp->mode3)
    { 
    case 0:
        plp->mtn_md &= ~0x2;
        
        plp->hokan_rate = 49152;
        
        switch (plp->ct0)
        {
        case 0:
            plp->mode3 = 1;
            break;
        case 1:
            plp->mode3 = 3;
            break;
        case 2:
            plp->mode3 = 4;
            break;
        }
        
        plp->mtn_no = plp->mode1;
        
        if (plp->mode1 == 42) 
        {
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
        }
        
        break;
    case 1:
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    case 3:
        if ((plp->ct2 - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->frm_no = (plp->ct2 - 2) * 65536;
        }
        
        break;
    case 4:
        plp->ct2 = (unsigned int)plp->frm_no / 65536;
        
        plp->frm_no = (plp->ct2 - 1) * 65536;
        break;
    }
}
