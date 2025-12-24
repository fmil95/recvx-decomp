#include "message.h"
#include "ps2_NaDraw2D.h"
#include "main.h"

/*float mes_spos[4][3];*/
float FontScaleX;
float FontScaleY;
float FontScaleCR;
const unsigned char FontSz[126];

// 
// Start address: 0x2b7510
void bhSetMessage(int mes_typ, int mes_idx)
{
	// Line 119, Address: 0x2b7510, Func Offset: 0
	// Line 121, Address: 0x2b752c, Func Offset: 0x1c
	// Line 122, Address: 0x2b7548, Func Offset: 0x38
	// Line 124, Address: 0x2b7550, Func Offset: 0x40
	// Line 125, Address: 0x2b756c, Func Offset: 0x5c
	// Line 127, Address: 0x2b7574, Func Offset: 0x64
	// Line 130, Address: 0x2b757c, Func Offset: 0x6c
	// Line 145, Address: 0x2b7588, Func Offset: 0x78
	// Line 146, Address: 0x2b7590, Func Offset: 0x80
	// Line 130, Address: 0x2b7598, Func Offset: 0x88
	// Line 131, Address: 0x2b75a4, Func Offset: 0x94
	// Line 135, Address: 0x2b75d4, Func Offset: 0xc4
	// Line 131, Address: 0x2b75d8, Func Offset: 0xc8
	// Line 135, Address: 0x2b75e0, Func Offset: 0xd0
	// Line 136, Address: 0x2b75f0, Func Offset: 0xe0
	// Line 137, Address: 0x2b7604, Func Offset: 0xf4
	// Line 138, Address: 0x2b7618, Func Offset: 0x108
	// Line 139, Address: 0x2b762c, Func Offset: 0x11c
	// Line 145, Address: 0x2b7638, Func Offset: 0x128
	// Line 139, Address: 0x2b763c, Func Offset: 0x12c
	// Line 145, Address: 0x2b7644, Func Offset: 0x134
	// Line 146, Address: 0x2b764c, Func Offset: 0x13c
	// Line 145, Address: 0x2b7650, Func Offset: 0x140
	// Line 146, Address: 0x2b7658, Func Offset: 0x148
	// Line 147, Address: 0x2b7668, Func Offset: 0x158
	// Func End, Address: 0x2b7670, Func Offset: 0x160
    scePrintf("bhSetMessage - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b7670
void bhControlMessage(int mode)
{
	int itn;
	int end;
	int col;
	int mct;
	unsigned short id;
	unsigned short cd;
	unsigned short* dt;
	//_anon2 pos;
	// Line 160, Address: 0x2b7670, Func Offset: 0
	// Line 164, Address: 0x2b7698, Func Offset: 0x28
	// Line 165, Address: 0x2b76ac, Func Offset: 0x3c
	// Line 166, Address: 0x2b76b4, Func Offset: 0x44
	// Line 167, Address: 0x2b76e8, Func Offset: 0x78
	// Line 168, Address: 0x2b76fc, Func Offset: 0x8c
	// Line 167, Address: 0x2b7708, Func Offset: 0x98
	// Line 168, Address: 0x2b770c, Func Offset: 0x9c
	// Line 169, Address: 0x2b7714, Func Offset: 0xa4
	// Line 170, Address: 0x2b7718, Func Offset: 0xa8
	// Line 171, Address: 0x2b771c, Func Offset: 0xac
	// Line 172, Address: 0x2b7720, Func Offset: 0xb0
	// Line 174, Address: 0x2b7728, Func Offset: 0xb8
	// Line 176, Address: 0x2b772c, Func Offset: 0xbc
	// Line 178, Address: 0x2b7838, Func Offset: 0x1c8
	// Line 180, Address: 0x2b7858, Func Offset: 0x1e8
	// Line 179, Address: 0x2b785c, Func Offset: 0x1ec
	// Line 180, Address: 0x2b7860, Func Offset: 0x1f0
	// Line 181, Address: 0x2b7868, Func Offset: 0x1f8
	// Line 183, Address: 0x2b7870, Func Offset: 0x200
	// Line 184, Address: 0x2b7874, Func Offset: 0x204
	// Line 183, Address: 0x2b7884, Func Offset: 0x214
	// Line 184, Address: 0x2b7888, Func Offset: 0x218
	// Line 185, Address: 0x2b7894, Func Offset: 0x224
	// Line 188, Address: 0x2b789c, Func Offset: 0x22c
	// Line 189, Address: 0x2b78b4, Func Offset: 0x244
	// Line 192, Address: 0x2b78bc, Func Offset: 0x24c
	// Line 195, Address: 0x2b78e8, Func Offset: 0x278
	// Line 196, Address: 0x2b78ec, Func Offset: 0x27c
	// Line 198, Address: 0x2b78f4, Func Offset: 0x284
	// Line 199, Address: 0x2b78f8, Func Offset: 0x288
	// Line 198, Address: 0x2b78fc, Func Offset: 0x28c
	// Line 199, Address: 0x2b7900, Func Offset: 0x290
	// Line 201, Address: 0x2b7918, Func Offset: 0x2a8
	// Line 202, Address: 0x2b791c, Func Offset: 0x2ac
	// Line 201, Address: 0x2b7920, Func Offset: 0x2b0
	// Line 203, Address: 0x2b7924, Func Offset: 0x2b4
	// Line 205, Address: 0x2b792c, Func Offset: 0x2bc
	// Line 206, Address: 0x2b7934, Func Offset: 0x2c4
	// Line 209, Address: 0x2b793c, Func Offset: 0x2cc
	// Line 210, Address: 0x2b7940, Func Offset: 0x2d0
	// Line 215, Address: 0x2b7960, Func Offset: 0x2f0
	// Line 217, Address: 0x2b7984, Func Offset: 0x314
	// Line 219, Address: 0x2b798c, Func Offset: 0x31c
	// Line 222, Address: 0x2b7994, Func Offset: 0x324
	// Line 225, Address: 0x2b799c, Func Offset: 0x32c
	// Line 226, Address: 0x2b79ac, Func Offset: 0x33c
	// Line 227, Address: 0x2b79b0, Func Offset: 0x340
	// Line 226, Address: 0x2b79b8, Func Offset: 0x348
	// Line 227, Address: 0x2b79c0, Func Offset: 0x350
	// Line 229, Address: 0x2b79e0, Func Offset: 0x370
	// Line 232, Address: 0x2b79e8, Func Offset: 0x378
	// Line 229, Address: 0x2b79f0, Func Offset: 0x380
	// Line 230, Address: 0x2b7a14, Func Offset: 0x3a4
	// Line 231, Address: 0x2b7a40, Func Offset: 0x3d0
	// Line 232, Address: 0x2b7a64, Func Offset: 0x3f4
	// Line 233, Address: 0x2b7a78, Func Offset: 0x408
	// Line 237, Address: 0x2b7a80, Func Offset: 0x410
	// Line 238, Address: 0x2b7a88, Func Offset: 0x418
	// Line 239, Address: 0x2b7a90, Func Offset: 0x420
	// Line 238, Address: 0x2b7a94, Func Offset: 0x424
	// Line 239, Address: 0x2b7a9c, Func Offset: 0x42c
	// Line 240, Address: 0x2b7aa8, Func Offset: 0x438
	// Line 244, Address: 0x2b7ab0, Func Offset: 0x440
	// Line 248, Address: 0x2b7ab8, Func Offset: 0x448
	// Line 252, Address: 0x2b7ac0, Func Offset: 0x450
	// Line 256, Address: 0x2b7ac8, Func Offset: 0x458
	// Line 260, Address: 0x2b7ad0, Func Offset: 0x460
	// Line 269, Address: 0x2b7ad8, Func Offset: 0x468
	// Line 270, Address: 0x2b7ae8, Func Offset: 0x478
	// Line 271, Address: 0x2b7af4, Func Offset: 0x484
	// Line 272, Address: 0x2b7b00, Func Offset: 0x490
	// Line 271, Address: 0x2b7b04, Func Offset: 0x494
	// Line 273, Address: 0x2b7b0c, Func Offset: 0x49c
	// Line 276, Address: 0x2b7b14, Func Offset: 0x4a4
	// Line 280, Address: 0x2b7b1c, Func Offset: 0x4ac
	// Line 281, Address: 0x2b7b30, Func Offset: 0x4c0
	// Line 282, Address: 0x2b7b34, Func Offset: 0x4c4
	// Line 281, Address: 0x2b7b38, Func Offset: 0x4c8
	// Line 282, Address: 0x2b7b40, Func Offset: 0x4d0
	// Line 284, Address: 0x2b7b58, Func Offset: 0x4e8
	// Line 305, Address: 0x2b7b60, Func Offset: 0x4f0
	// Line 307, Address: 0x2b7b68, Func Offset: 0x4f8
	// Line 308, Address: 0x2b7b84, Func Offset: 0x514
	// Line 309, Address: 0x2b7b98, Func Offset: 0x528
	// Line 308, Address: 0x2b7b9c, Func Offset: 0x52c
	// Line 310, Address: 0x2b7ba8, Func Offset: 0x538
	// Line 311, Address: 0x2b7bd0, Func Offset: 0x560
	// Line 313, Address: 0x2b7bf0, Func Offset: 0x580
	// Line 314, Address: 0x2b7c00, Func Offset: 0x590
	// Line 316, Address: 0x2b7c18, Func Offset: 0x5a8
	// Line 317, Address: 0x2b7c3c, Func Offset: 0x5cc
	// Line 319, Address: 0x2b7c50, Func Offset: 0x5e0
	// Line 317, Address: 0x2b7c54, Func Offset: 0x5e4
	// Line 319, Address: 0x2b7c5c, Func Offset: 0x5ec
	// Line 321, Address: 0x2b7c70, Func Offset: 0x600
	// Line 322, Address: 0x2b7c74, Func Offset: 0x604
	// Line 321, Address: 0x2b7c78, Func Offset: 0x608
	// Line 322, Address: 0x2b7c80, Func Offset: 0x610
	// Line 323, Address: 0x2b7c8c, Func Offset: 0x61c
	// Line 325, Address: 0x2b7c94, Func Offset: 0x624
	// Line 326, Address: 0x2b7cb8, Func Offset: 0x648
	// Line 327, Address: 0x2b7cc4, Func Offset: 0x654
	// Line 328, Address: 0x2b7cd8, Func Offset: 0x668
	// Line 327, Address: 0x2b7cdc, Func Offset: 0x66c
	// Line 328, Address: 0x2b7ce4, Func Offset: 0x674
	// Line 329, Address: 0x2b7d0c, Func Offset: 0x69c
	// Line 332, Address: 0x2b7d20, Func Offset: 0x6b0
	// Line 334, Address: 0x2b7d28, Func Offset: 0x6b8
	// Line 336, Address: 0x2b7d30, Func Offset: 0x6c0
	// Line 334, Address: 0x2b7d34, Func Offset: 0x6c4
	// Line 336, Address: 0x2b7d3c, Func Offset: 0x6cc
	// Line 337, Address: 0x2b7d58, Func Offset: 0x6e8
	// Line 339, Address: 0x2b7d64, Func Offset: 0x6f4
	// Line 337, Address: 0x2b7d6c, Func Offset: 0x6fc
	// Line 338, Address: 0x2b7d7c, Func Offset: 0x70c
	// Line 339, Address: 0x2b7d8c, Func Offset: 0x71c
	// Line 341, Address: 0x2b7d94, Func Offset: 0x724
	// Line 342, Address: 0x2b7db4, Func Offset: 0x744
	// Line 344, Address: 0x2b7dc0, Func Offset: 0x750
	// Line 342, Address: 0x2b7dc8, Func Offset: 0x758
	// Line 343, Address: 0x2b7dd8, Func Offset: 0x768
	// Line 344, Address: 0x2b7de8, Func Offset: 0x778
	// Line 346, Address: 0x2b7df0, Func Offset: 0x780
	// Line 347, Address: 0x2b7e28, Func Offset: 0x7b8
	// Line 348, Address: 0x2b7e58, Func Offset: 0x7e8
	// Line 349, Address: 0x2b7e78, Func Offset: 0x808
	// Line 351, Address: 0x2b7e88, Func Offset: 0x818
	// Line 349, Address: 0x2b7e94, Func Offset: 0x824
	// Line 351, Address: 0x2b7e98, Func Offset: 0x828
	// Line 349, Address: 0x2b7e9c, Func Offset: 0x82c
	// Line 351, Address: 0x2b7eac, Func Offset: 0x83c
	// Line 349, Address: 0x2b7eb4, Func Offset: 0x844
	// Line 350, Address: 0x2b7eb8, Func Offset: 0x848
	// Line 351, Address: 0x2b7ed0, Func Offset: 0x860
	// Line 353, Address: 0x2b7ed8, Func Offset: 0x868
	// Line 354, Address: 0x2b7ef8, Func Offset: 0x888
	// Line 357, Address: 0x2b7f00, Func Offset: 0x890
	// Line 358, Address: 0x2b7f14, Func Offset: 0x8a4
	// Line 359, Address: 0x2b7f1c, Func Offset: 0x8ac
	// Line 358, Address: 0x2b7f20, Func Offset: 0x8b0
	// Line 359, Address: 0x2b7f28, Func Offset: 0x8b8
	// Line 360, Address: 0x2b7f30, Func Offset: 0x8c0
	// Line 359, Address: 0x2b7f34, Func Offset: 0x8c4
	// Line 360, Address: 0x2b7f3c, Func Offset: 0x8cc
	// Line 361, Address: 0x2b7f50, Func Offset: 0x8e0
	// Line 362, Address: 0x2b7f54, Func Offset: 0x8e4
	// Line 363, Address: 0x2b7f64, Func Offset: 0x8f4
	// Line 362, Address: 0x2b7f68, Func Offset: 0x8f8
	// Line 363, Address: 0x2b7f70, Func Offset: 0x900
	// Line 364, Address: 0x2b7f8c, Func Offset: 0x91c
	// Line 365, Address: 0x2b7fac, Func Offset: 0x93c
	// Line 367, Address: 0x2b7fc8, Func Offset: 0x958
	// Line 370, Address: 0x2b7fd0, Func Offset: 0x960
	// Line 371, Address: 0x2b7fe4, Func Offset: 0x974
	// Line 372, Address: 0x2b7ffc, Func Offset: 0x98c
	// Line 373, Address: 0x2b8008, Func Offset: 0x998
	// Line 377, Address: 0x2b8010, Func Offset: 0x9a0
	// Line 373, Address: 0x2b8014, Func Offset: 0x9a4
	// Line 374, Address: 0x2b8020, Func Offset: 0x9b0
	// Line 375, Address: 0x2b8034, Func Offset: 0x9c4
	// Line 376, Address: 0x2b8048, Func Offset: 0x9d8
	// Line 377, Address: 0x2b805c, Func Offset: 0x9ec
	// Line 379, Address: 0x2b8070, Func Offset: 0xa00
	// Line 380, Address: 0x2b8090, Func Offset: 0xa20
	// Line 382, Address: 0x2b80a0, Func Offset: 0xa30
	// Line 381, Address: 0x2b80ac, Func Offset: 0xa3c
	// Line 380, Address: 0x2b80b8, Func Offset: 0xa48
	// Line 381, Address: 0x2b80bc, Func Offset: 0xa4c
	// Line 382, Address: 0x2b80c0, Func Offset: 0xa50
	// Line 384, Address: 0x2b80d4, Func Offset: 0xa64
	// Line 385, Address: 0x2b80f4, Func Offset: 0xa84
	// Line 388, Address: 0x2b80fc, Func Offset: 0xa8c
	// Line 389, Address: 0x2b811c, Func Offset: 0xaac
	// Line 391, Address: 0x2b813c, Func Offset: 0xacc
	// Line 392, Address: 0x2b8150, Func Offset: 0xae0
	// Line 393, Address: 0x2b8158, Func Offset: 0xae8
	// Line 395, Address: 0x2b815c, Func Offset: 0xaec
	// Func End, Address: 0x2b8188, Func Offset: 0xb18
	scePrintf("bhControlMessage - UNIMPLEMENTED!\n");
}

// 100% matching! 
void bhDispFont(NJS_POINT2* pos, int code, int color, float pri)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];  
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    
    njSetTextureNum(code / 324);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = pos->x + (28.0f * FontScaleX);
    p[1].y = pos->y;
    
    p[2].x = pos->x + (28.0f * FontScaleX);
    p[2].y = pos->y + (28.0f * FontScaleY);
    
    p[3].x = pos->x;
    p[3].y = pos->y + (28.0f * FontScaleY);
    
    switch (color) 
    {                              
    case 1:
        col[0].color = 0xFF20E0FF;
        col[1].color = 0xFF20E0FF;
        col[2].color = 0xFF20E0FF;
        col[3].color = 0xFF20E0FF;
        break;
    case 2:
        col[0].color = 0xFFFF2020;
        col[1].color = 0xFFFF2020;
        col[2].color = 0xFFFF2020;
        col[3].color = 0xFFFF2020;
        break;
    case 3:
        col[0].color = 0xFF20FF20;
        col[1].color = 0xFF20FF20;
        col[2].color = 0xFF20FF20;
        col[3].color = 0xFF20FF20;
        break;
    case 4:
        col[0].color = 0xFF606060;
        col[1].color = 0xFF606060;
        col[2].color = 0xFF606060;
        col[3].color = 0xFF606060;
        break;
    default:
        col[0].color = 0xFFFFFFFF;
        col[1].color = 0xFFFFFFFF;
        col[2].color = 0xFFFFFFFF;
        col[3].color = 0xFFFFFFFF;
        break;
    }

    code %= 324;
    
    uv[0].tex.u = (code % 18) * 14;
    uv[0].tex.v = (code / 18) * 14;
    
    uv[1].tex.u = uv[0].tex.u + 14;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u; 
    uv[3].tex.v = uv[0].tex.v + 14;
    
    njDrawPolygon2DM(&p2c, 4, pri, 0x80000060);
}

// 100% matching! 
void bhDispFontEx(NJS_POINT2* pos, int code, unsigned int argb, float pri)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];  
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    
    njSetTextureNum(code / 324);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = pos->x + (28.0f * FontScaleX);
    p[1].y = pos->y;
    
    p[2].x = pos->x + (28.0f * FontScaleX);
    p[2].y = pos->y + (28.0f * FontScaleY);
    
    p[3].x = pos->x;
    p[3].y = pos->y + (28.0f * FontScaleY);
    
    code %= 324;

    col[0].color = argb;
    col[1].color = argb;
    col[2].color = argb;
    col[3].color = argb;
    
    uv[0].tex.u = (code % 18) * 14;
    uv[0].tex.v = (code / 18) * 14;
    
    uv[1].tex.u = uv[0].tex.u + 14;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u; 
    uv[3].tex.v = uv[0].tex.v + 14;
    
    njDrawPolygon2DM(&p2c, 4, pri, 0x80000060);
}

/*// 
// Start address: 0x2b8620
int bhDispItemName(_anon2* pos, int id, int color, int count, float pri)
{
	int num;
	int cflg;
	unsigned short cd;
	unsigned short* dp;
	// Line 543, Address: 0x2b8620, Func Offset: 0
	// Line 547, Address: 0x2b8648, Func Offset: 0x28
	// Line 549, Address: 0x2b8654, Func Offset: 0x34
	// Line 547, Address: 0x2b8664, Func Offset: 0x44
	// Line 546, Address: 0x2b8674, Func Offset: 0x54
	// Line 547, Address: 0x2b867c, Func Offset: 0x5c
	// Line 551, Address: 0x2b8688, Func Offset: 0x68
	// Line 552, Address: 0x2b868c, Func Offset: 0x6c
	// Line 559, Address: 0x2b869c, Func Offset: 0x7c
	// Line 560, Address: 0x2b86a8, Func Offset: 0x88
	// Line 561, Address: 0x2b86b8, Func Offset: 0x98
	// Line 562, Address: 0x2b86d4, Func Offset: 0xb4
	// Line 563, Address: 0x2b86dc, Func Offset: 0xbc
	// Line 567, Address: 0x2b86f8, Func Offset: 0xd8
	// Line 568, Address: 0x2b8700, Func Offset: 0xe0
	// Line 569, Address: 0x2b8704, Func Offset: 0xe4
	// Line 572, Address: 0x2b8714, Func Offset: 0xf4
	// Line 573, Address: 0x2b8718, Func Offset: 0xf8
	// Func End, Address: 0x2b8744, Func Offset: 0x124
}*/

// 100% matching! 
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx, int color, int count)
{
    NJS_POINT2 pos;      
    unsigned short* dp;  
    unsigned short cd;   
    int cflg;            
    int num;             
    unsigned int* mes_dp;
    float stx;          
    float sty;          

    switch (mes_typ) 
    {                           
    case 0:
        mes_dp = rom->mesp;
        
        dp = (unsigned short*)((char*)mes_dp + rom->mesp[mes_idx + 1]);
        break;
    case 1:
        mes_dp = sys->mes_sp;
        
        dp = (unsigned short*)((char*)mes_dp + sys->mes_sp[mes_idx + 1]);
        break;
    default:
        dp = sys->mes_tp;
        break;
    }
    
    pos.x = px;
    pos.y = py;
    
    num = 0;
    
    if (count == 0) 
    {
        cflg = 0;
    }
    else 
    {
        cflg = 1;
    }
    
    while (TRUE) 
    {
        cd = *dp++;
        
        switch (cd)
        {
        case 65280:
            pos.x = px;
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:   
            continue;
        }
        
        if (cd == 65535) 
        {
            break;
        }
        
        bhDispFont(&pos, cd, color, pri);
        
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        num++;
        
        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    }
    
    return num;
}

// 100% matching! 
int bhDispMessageEx(float px, float py, float pri, int mes_typ, int mes_idx, unsigned int argb, int count)
{
    NJS_POINT2 pos;      
    unsigned short* dp;  
    unsigned short cd;   
    int cflg;            
    int num;             
    unsigned int* mes_dp;
    float stx;          
    float sty;          

    switch (mes_typ) 
    {                           
    case 0:
        mes_dp = rom->mesp;
        
        dp = (unsigned short*)((char*)mes_dp + rom->mesp[mes_idx + 1]);
        break;
    case 1:
        mes_dp = sys->mes_sp;
        
        dp = (unsigned short*)((char*)mes_dp + sys->mes_sp[mes_idx + 1]);
        break;
    default:
        dp = sys->mes_tp;
        break;
    }
    
    pos.x = px;
    pos.y = py;
    
    num = 0;
    
    if (count == 0) 
    {
        cflg = 0;
    }
    else 
    {
        cflg = 1;
    }
    
    while (TRUE) 
    {
        cd = *dp++;
        
        switch (cd)
        {
        case 65280:
            pos.x = px;
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            
            if ((cflg != 0) && (--count <= 0)) 
            {
                return 0;
            }
            
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:   
            continue;
        }
        
        if (cd == 65535) 
        {
            break;
        }
        
        bhDispFontEx(&pos, cd, argb, pri);
        
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        num++;
        
        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    }
    
    return num;
}

// 99.79% matching
void bhDispTime(NJS_POINT2 *pos, unsigned int flg, int time, int color, float pri) 
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFont(&dps, ntb[hour / 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, ntb[hour % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, 26, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFont(&dps, ntb[min / 10], color, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[min % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFont(&dps, cd, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFont(&dps, ntb[sec / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[sec % 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFont(&dps, 2, color, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFont(&dps, ntb[msc / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[msc % 10], color, pri);
    }
}

// 99.79% matching
void bhDispTimeEx(NJS_POINT2* pos, unsigned int flg, int time, unsigned int argb, float pri)
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFontEx(&dps, ntb[hour / 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, ntb[hour % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, 26, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFontEx(&dps, ntb[min / 10], argb, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[min % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFontEx(&dps, cd, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFontEx(&dps, ntb[sec / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[sec % 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFontEx(&dps, 2, argb, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFontEx(&dps, ntb[msc / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[msc % 10], argb, pri);
    }
}

// 100% matching!
float bhGetFontSize(unsigned short code)
{
    if (code >= 108) 
    {
        return 0;
    }
    
    return FontSz[code];
}

// 100% matching!
float bhMesLen(unsigned short* dp)
{
    unsigned short cd; 
    float len; 
    
    len = 0;

    while (TRUE) 
    {
        cd = *dp++;

        switch (cd) 
        {
        case 65280:
            continue;
        case 65281:
            len += FontScaleX * 14.0f;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:  
            continue;
        }

        if (cd == 65535) 
        {
            break;
        }
        
        len += FontScaleX * bhGetFontSize(cd);
    }

    return len;
}

// 100% matching! 
void bhFontScaleSet(float ScaleX, float ScaleY, float ScaleCR) 
{
    FontScaleX = ScaleX; 
    FontScaleY = ScaleY; 
    
    FontScaleCR = ScaleCR; 
}
