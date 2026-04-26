#include "../../../ps2/veronica/prog/ranking.h"
#include "../../../ps2/veronica/prog/bup_00.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/event.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_SystemSaveScreen.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/room.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/sub1.h"
#include "../../../ps2/veronica/prog/system.h"
#include "../../../ps2/veronica/prog/main.h"

void bhDispFontEx(NJS_POINT2* pos, int code, unsigned int argb, float pri); // see message.h for more info about why this is being included here

SYSSAVE_SCREEN RankingSys;
SYSSAVE_SCREEN* pRankingSys;
RANK_WORK rkw;

typedef void (*RankingMode_proc)();
RankingMode_proc RankingMode[6] =
{
	RankingInit,
	RankingVmsWait,
	RankingSave,
	RankingErrorMessage,
	RankingMain,
	RankingExit
};

// 100% matching!
void ControlRanking()
{
    RankingMode[sys->typ_md0]();
}

// 
// Start address: 0x2bb240
void RankingInit()
{
	unsigned int ply_id;
	int j;
	//_anon6* sfe;
	//_anon5* rk;
	// Line 151, Address: 0x2bb240, Func Offset: 0
	// Line 152, Address: 0x2bb254, Func Offset: 0x14
	// Line 153, Address: 0x2bb25c, Func Offset: 0x1c
	// Line 161, Address: 0x2bb264, Func Offset: 0x24
	// Line 162, Address: 0x2bb26c, Func Offset: 0x2c
	// Line 163, Address: 0x2bb284, Func Offset: 0x44
	// Line 165, Address: 0x2bb28c, Func Offset: 0x4c
	// Line 163, Address: 0x2bb294, Func Offset: 0x54
	// Line 165, Address: 0x2bb29c, Func Offset: 0x5c
	// Line 166, Address: 0x2bb2a4, Func Offset: 0x64
	// Line 167, Address: 0x2bb2ac, Func Offset: 0x6c
	// Line 169, Address: 0x2bb2b0, Func Offset: 0x70
	// Line 166, Address: 0x2bb2b4, Func Offset: 0x74
	// Line 167, Address: 0x2bb2b8, Func Offset: 0x78
	// Line 166, Address: 0x2bb2bc, Func Offset: 0x7c
	// Line 167, Address: 0x2bb2c8, Func Offset: 0x88
	// Line 169, Address: 0x2bb2d0, Func Offset: 0x90
	// Line 170, Address: 0x2bb2e4, Func Offset: 0xa4
	// Line 172, Address: 0x2bb2ec, Func Offset: 0xac
	// Line 173, Address: 0x2bb2f4, Func Offset: 0xb4
	// Line 174, Address: 0x2bb2f8, Func Offset: 0xb8
	// Line 176, Address: 0x2bb300, Func Offset: 0xc0
	// Line 177, Address: 0x2bb304, Func Offset: 0xc4
	// Line 178, Address: 0x2bb308, Func Offset: 0xc8
	// Line 179, Address: 0x2bb30c, Func Offset: 0xcc
	// Line 180, Address: 0x2bb324, Func Offset: 0xe4
	// Line 181, Address: 0x2bb334, Func Offset: 0xf4
	// Line 182, Address: 0x2bb344, Func Offset: 0x104
	// Line 183, Address: 0x2bb354, Func Offset: 0x114
	// Line 184, Address: 0x2bb364, Func Offset: 0x124
	// Line 185, Address: 0x2bb374, Func Offset: 0x134
	// Line 186, Address: 0x2bb388, Func Offset: 0x148
	// Line 187, Address: 0x2bb398, Func Offset: 0x158
	// Line 188, Address: 0x2bb3ac, Func Offset: 0x16c
	// Line 189, Address: 0x2bb3bc, Func Offset: 0x17c
	// Line 190, Address: 0x2bb3cc, Func Offset: 0x18c
	// Line 191, Address: 0x2bb3d0, Func Offset: 0x190
	// Line 192, Address: 0x2bb3d4, Func Offset: 0x194
	// Line 193, Address: 0x2bb3d8, Func Offset: 0x198
	// Line 194, Address: 0x2bb3dc, Func Offset: 0x19c
	// Line 190, Address: 0x2bb3e0, Func Offset: 0x1a0
	// Line 191, Address: 0x2bb3e8, Func Offset: 0x1a8
	// Line 192, Address: 0x2bb3ec, Func Offset: 0x1ac
	// Line 193, Address: 0x2bb3f0, Func Offset: 0x1b0
	// Line 199, Address: 0x2bb3f4, Func Offset: 0x1b4
	// Line 200, Address: 0x2bb410, Func Offset: 0x1d0
	// Line 201, Address: 0x2bb414, Func Offset: 0x1d4
	// Line 200, Address: 0x2bb420, Func Offset: 0x1e0
	// Line 201, Address: 0x2bb428, Func Offset: 0x1e8
	// Line 202, Address: 0x2bb42c, Func Offset: 0x1ec
	// Line 203, Address: 0x2bb43c, Func Offset: 0x1fc
	// Line 204, Address: 0x2bb440, Func Offset: 0x200
	// Line 203, Address: 0x2bb444, Func Offset: 0x204
	// Line 206, Address: 0x2bb448, Func Offset: 0x208
	// Line 207, Address: 0x2bb464, Func Offset: 0x224
	// Line 208, Address: 0x2bb480, Func Offset: 0x240
	// Line 213, Address: 0x2bb48c, Func Offset: 0x24c
	// Line 212, Address: 0x2bb490, Func Offset: 0x250
	// Line 215, Address: 0x2bb494, Func Offset: 0x254
	// Line 216, Address: 0x2bb4a4, Func Offset: 0x264
	// Line 218, Address: 0x2bb4ac, Func Offset: 0x26c
	// Line 219, Address: 0x2bb4b4, Func Offset: 0x274
	// Line 220, Address: 0x2bb4b8, Func Offset: 0x278
	// Line 223, Address: 0x2bb4c0, Func Offset: 0x280
	// Line 226, Address: 0x2bb4ec, Func Offset: 0x2ac
	// Line 230, Address: 0x2bb4f0, Func Offset: 0x2b0
	// Line 226, Address: 0x2bb4f4, Func Offset: 0x2b4
	// Line 227, Address: 0x2bb4fc, Func Offset: 0x2bc
	// Line 228, Address: 0x2bb500, Func Offset: 0x2c0
	// Line 229, Address: 0x2bb504, Func Offset: 0x2c4
	// Line 230, Address: 0x2bb508, Func Offset: 0x2c8
	// Line 231, Address: 0x2bb520, Func Offset: 0x2e0
	// Line 233, Address: 0x2bb530, Func Offset: 0x2f0
	// Line 234, Address: 0x2bb54c, Func Offset: 0x30c
	// Line 235, Address: 0x2bb568, Func Offset: 0x328
	// Line 238, Address: 0x2bb574, Func Offset: 0x334
	// Line 239, Address: 0x2bb57c, Func Offset: 0x33c
	// Line 242, Address: 0x2bb580, Func Offset: 0x340
	// Line 259, Address: 0x2bb588, Func Offset: 0x348
	// Line 260, Address: 0x2bb5a8, Func Offset: 0x368
	// Line 261, Address: 0x2bb5ac, Func Offset: 0x36c
	// Line 260, Address: 0x2bb5b0, Func Offset: 0x370
	// Line 262, Address: 0x2bb5b8, Func Offset: 0x378
	// Line 263, Address: 0x2bb5d0, Func Offset: 0x390
	// Line 264, Address: 0x2bb5d4, Func Offset: 0x394
	// Line 263, Address: 0x2bb5d8, Func Offset: 0x398
	// Line 265, Address: 0x2bb5dc, Func Offset: 0x39c
	// Line 266, Address: 0x2bb5e4, Func Offset: 0x3a4
	// Line 267, Address: 0x2bb5e8, Func Offset: 0x3a8
	// Line 289, Address: 0x2bb5ec, Func Offset: 0x3ac
	// Line 290, Address: 0x2bb5fc, Func Offset: 0x3bc
	// Line 292, Address: 0x2bb638, Func Offset: 0x3f8
	// Line 293, Address: 0x2bb648, Func Offset: 0x408
	// Line 295, Address: 0x2bb650, Func Offset: 0x410
	// Line 296, Address: 0x2bb660, Func Offset: 0x420
	// Line 298, Address: 0x2bb668, Func Offset: 0x428
	// Line 299, Address: 0x2bb678, Func Offset: 0x438
	// Line 301, Address: 0x2bb680, Func Offset: 0x440
	// Line 302, Address: 0x2bb690, Func Offset: 0x450
	// Line 304, Address: 0x2bb698, Func Offset: 0x458
	// Line 316, Address: 0x2bb6ac, Func Offset: 0x46c
	// Line 317, Address: 0x2bb6cc, Func Offset: 0x48c
	// Line 318, Address: 0x2bb6e0, Func Offset: 0x4a0
	// Line 319, Address: 0x2bb6e8, Func Offset: 0x4a8
	// Line 320, Address: 0x2bb6f0, Func Offset: 0x4b0
	// Line 321, Address: 0x2bb6f8, Func Offset: 0x4b8
	// Line 322, Address: 0x2bb6fc, Func Offset: 0x4bc
	// Line 321, Address: 0x2bb700, Func Offset: 0x4c0
	// Line 327, Address: 0x2bb704, Func Offset: 0x4c4
	// Line 329, Address: 0x2bb720, Func Offset: 0x4e0
	// Line 330, Address: 0x2bb73c, Func Offset: 0x4fc
	// Line 331, Address: 0x2bb740, Func Offset: 0x500
	// Line 330, Address: 0x2bb74c, Func Offset: 0x50c
	// Line 331, Address: 0x2bb754, Func Offset: 0x514
	// Line 332, Address: 0x2bb758, Func Offset: 0x518
	// Line 333, Address: 0x2bb768, Func Offset: 0x528
	// Line 334, Address: 0x2bb76c, Func Offset: 0x52c
	// Line 336, Address: 0x2bb770, Func Offset: 0x530
	// Line 338, Address: 0x2bb778, Func Offset: 0x538
	// Line 339, Address: 0x2bb794, Func Offset: 0x554
	// Line 340, Address: 0x2bb798, Func Offset: 0x558
	// Line 339, Address: 0x2bb7a4, Func Offset: 0x564
	// Line 340, Address: 0x2bb7ac, Func Offset: 0x56c
	// Line 341, Address: 0x2bb7b0, Func Offset: 0x570
	// Line 342, Address: 0x2bb7c0, Func Offset: 0x580
	// Line 343, Address: 0x2bb7c4, Func Offset: 0x584
	// Line 342, Address: 0x2bb7c8, Func Offset: 0x588
	// Line 348, Address: 0x2bb7cc, Func Offset: 0x58c
	// Line 347, Address: 0x2bb7d0, Func Offset: 0x590
	// Line 348, Address: 0x2bb7d4, Func Offset: 0x594
	// Line 351, Address: 0x2bb7d8, Func Offset: 0x598
	// Func End, Address: 0x2bb7f0, Func Offset: 0x5b0
	scePrintf("RankingInit - UNIMPLEMENTED!\n");
}

// 100% matching
void RankingVmsWait() 
{
    rkw.errret = 1;
    sys->typ_md0 = 3;
    sys->typ_md1 = 0;
}

// 100% matching
void RankingSave() {}

// 100% matching!
void RankingErrorMessage()
{
    RANK_WORK* rk; 
    FADE* sfe;   
    static unsigned int ulState; 
    static unsigned int SaveCheck; 

    rk = &rkw;
    sfe = &fade;
    
    switch (ulState) 
    {                     
    case 0:                        
        pRankingSys = CreateSysSaveScreen(&RankingSys, vwbmemp, 1, 1);
        
        SaveCheck = 0;
        
        ulState = 1;
        break;
    case 1:                              
        SaveCheck = ExecuteSysSaveScreen(pRankingSys);
        
        if (SaveCheck == 1) 
        {                           
            ulState = 0;
            
            sys->typ_md0 = 4;
            
            sfe->flg |= 0x1;
            
            rk->mode_01 = 0;
            
            RankingBgmSet();
        }
        else if (SaveCheck == 2) 
        {                                    
            ulState = 0;
            
            sys->typ_md0 = 4;
            
            sfe->flg |= 0x1;
            
            rk->mode_01 = 0;
            
            RankingBgmSet();
        }
        
        break;
    }
}

// 99.84% matching
void RankingMain()
{
    static unsigned int flg;
    RANK_WORK* rk;
    FADE* sfe;
    int num;

    rk = &rkw;
    sfe = &fade;

    if (sys->gm_mode == 0) 
    {
        DispRankingData00();
    } 
    else if (sys->gm_mode == 3)
    {
        DispRankingData01();
    }
    
    WallPaperDisp();
    FadePolyDisp();
    
    switch (rk->mode_01) 
    {                          
    case 0:
        if (!(sfe->flg & 0x1)) 
        {
            rk->mode_01 = 1;
            
            rk->cnt00 = 45;
            rk->cnt01 = 21;
            
            rk->alpha = 0;
            
            flg = 0;
        }
        
        break;
    case 1:
        if (rk->cnt00 == 0) 
        {
            if ((sys->pad_ps & 0x1800)) 
            {
                if (rk->cnt01 == 0)
                {
                    rk->alpha = 255;
                    
                    rk->mode_01 = 2;
                    
                    sfe->flg |= 0x1;
                    
                    sfe->cnt01 = 12;
                    
                    rk->mesalpha = 1;
                    rk->mescol = 12;
                    
                    StopBgm(200);
                } 
                else 
                {
                    flg = 1;
                }
            }
            
            if ((flg != 0) && (rk->cnt01 != 0)) 
            {
                rk->cnt01--;
                
                rk->alpha += 12;
            }
        }
        else if (rk->cnt00 != 0)
        {
            rk->cnt00--;
        }
        
        break;
    case 2:
        if (!(sfe->flg & 0x1)) 
        {
            if (rk->mesloop != 0) 
            {
                num = (rk->mesloop & 0xFFFF) - 1;
                
                GetMessage(rk->mesnum[num], &rk->mespos[num]);
                
                if (rk->mescol != 0)
                {
                    rk->mesalpha += rk->mescol;
                    
                    if (rk->mesalpha > 255)
                    {
                        rk->mesalpha = 255;
                        rk->mescol = 0;
                    }
                    
                    if (rk->mesalpha < 0) 
                    {
                        rk->mesalpha = 0;
                        
                        rk->mesloop--;
                        
                        rk->mescol = 12; 
                    }
                } 
                else if ((rk->mesalpha == 255) || (rk->mesalpha == 0)) 
                {
                    rk->mescol = 0;
                    
                    if (rk->mesalpha == 0)
                    {
                        rk->mesloop--;
                        
                        rk->mescol = 12;
                    }
                }
                
                if (((sys->pad_ps & 0x1800)) && (rk->mescol == 0)) 
                {
                    rk->mescol = -12;
                }
            } 
            else 
            {
                rk->mode_01 = 3;
            }
        }
        
        break;
    case 3:
        if (!(sfe->flg & 0x1)) 
        {
            sys->typ_md0 = 5;
        }
        
        break;
    }
}

// 100% matching! 
void RankingExit()
{
    RANK_WORK* rk;

    rk = &rkw; 
    
    if (sys->gm_mode == 0) 
    {
        rk->gameest01 = (rk->allscore / 38) & 0xFE;
        
        rk->gamecarry01 = 254;

        if (rk->gameest00 == 255) 
        {
            rk->gameest00 = 0;
        }
        
        if (rk->gameest01 >= rk->gameest00) 
        {
            WritePlayLog(rk->gameest01, rk->gamecarry01);
        }
        else 
        {
            WritePlayLog(rk->gameest00, rk->gamecarry01);
        }
    } 
    else if (sys->gm_mode == 3) 
    {
        WritePlayLog(rk->gameest00, rk->gamecarry01);
    } 
    else 
    {
        WritePlayLog(rk->gameest00, rk->gamecarry01); 
    }
    
    if (sys->gm_mode < 3) 
    {
        bhReturnTitle();
    } 
    else 
    {
        bhPopGameData();
    }
    
    sys->typ_md1 = sys->typ_md0 = 0;
}

// 100% matching! 
void RankingTextureInit() 
{
    RANK_WORK* rk;      
    int sz;             
    int no;           
    unsigned int dt;    
    unsigned char* datp;

    rk = &rkw;

    if (!(sys->typ_flg & 0x80000000)) 
    {
        rk->mode_00 = 0;
        
        sys->typ_flg |= 0x80000000;
    }
    
    if (!(sys->ss_flg & 0x1)) 
    {
        if (sys->costume != 0) 
        {
            no = 4;
        } 
        else 
        {
            no = sys->ply_id;
        }
    }
    else 
    {
        no = 0;
    }
    
    switch (rk->mode_00) 
    {
    case 0:
        sz = GetIsoFileSize("sysmes.ald");
        
        if (sz != 0)
        {
            sys->memp = (unsigned char*)(((int)sys->memp + 0x3F) & ~0x3F);
             
            RequestReadIsoFile("sysmes.ald", sys->memp);
            
            sys->mes_ip = (unsigned int*)sys->memp;
            
            sys->memp += sz;
            
            sys->doordp = bhGetFreeMemory(0x2A000, 0x20);
            
            rk->mode_00 = 1;
        }
        
        break;
    default:
        break;
    case 1:
        if (GetReadFileStatus() == 0) 
        {
            datp = (unsigned char*)sys->mes_ip; 
                
            dt = *sys->mes_ip; 
            
            datp += 4; 
            
            sys->mes_ip = (unsigned int*)datp; 
            
            datp += dt; 
            
            sys->mes_sp = (unsigned int*)(datp + 4);
            
            rk->mode_00 = 2;
        }
        
        break;
    case 2:
        if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->sys_partid, 1) != 0)) 
        {
            sys->memp = (unsigned char*)(((int)sys->memp + 0x3F) & ~0x3F);
            
            RequestReadInsideFile(sys->sys_partid, 1, sys->memp);
            
            rk->mode_00 = 3;
        }
		
        break;
    case 3:
        if (GetReadFileStatus() == 0) 
        {
            bhSetFontTexture(sys->memp);
            
            rk->mode_00 = 4;
        }
        
        break;
    case 4:
        if (GetReadFileStatus() != 1) 
        {
            sys->sbs_sp = sys->memp;
            
            sys->memp = (unsigned char*)(((int)sys->memp + 0x3F) & ~0x3F);
            
            rk->mode_00 = 5;
        }
        
        break;
    case 5:
        if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->itm_partid, no + 277) != 0))
        {
            sys->memp = (unsigned char*)(((int)sys->memp + 0x3F) & ~0x3F);
            
            RequestReadInsideFile(sys->itm_partid, no + 277, sys->memp);
            
            sys->subtxp = sys->memp;
            
            rk->mode_00 = 6;
        }
        
        break;
    case 6:
        if (!(sys->ts_flg & 0x80)) 
        {
            sys->ts_flg |= 0x80;
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
        }
        
        if (GetReadFileStatus() == 0)
        {
            rk->mode_00 = 7;
        }
        
        break;
    case 7:
        rk->rktx_list.textures = rk->rktx;
        rk->rktx_list.nbTexture = bhSetMemPvpTexture(&rk->rktx_list, sys->subtxp, 0);
        
        rk->mode_00 = 8;
        break;
    case 8:
        sys->typ_md0 = 2;
        
        rk->mode_01 = 0;
        break;
    }
}

// 100% matching!
void WallPaperDisp()
{
    QUAD twt[4]; 
  
    njSetTexture(&rkw.rktx_list);
    
    njQuadTextureStart(0);
    
    twt[0].x1 = 0;
    twt[0].y1 = 0;
    
    twt[0].x2 = 512.0f;
    twt[0].y2 = 480.0f;
    
    twt[0].u1 = 0;
    twt[0].v1 = 0;
    
    twt[0].u2 = 1.0f;
    twt[0].v2 = 0.93f;
    
    njSetQuadTexture(0, 0xFF808080);
    
    njDrawQuadTexture(&twt[0], 0.1f);
    
    twt[1].x1 = 512.0f;
    twt[1].y1 = 0;
    
    twt[1].x2 = 640.0f;
    twt[1].y2 = 480.0f;
    
    twt[1].u1 = 0;
    twt[1].v1 = 0;
    
    twt[1].u2 = 0.5f;
    twt[1].v2 = 0.93f;
    
    njSetQuadTexture(1, 0xFF808080);
    
    njDrawQuadTexture(&twt[1], 0.1f);
    
    njQuadTextureEnd();
}

// 100% matching!
void DispRank(NJS_POINT2* pos, unsigned int color, int rank) 
{
    int code;

    code = color;

    switch (rank)
    {
    case 1:
        code = 33;
        break;
    case 2:
        code = 34;
        break;
    case 4:
        code = 35;
        break;
    case 8:
        code = 36;
        break;
    case 16:
        code = 37;
        break;
    case 32:
        code = 38;
        break;
    }

    bhDispFontEx(pos, code, color, -2);
}

// 96.95% matching
void DispRankingData00()
{
    NJS_POINT2 pos;
    unsigned int argb;
	
    argb = (rkw.alpha << 24) | 0xFFFFFF;
    
    bhDispMessageEx(64.0f,  64.0f, -3.0f, 1, 265, argb, 0);
    bhDispMessageEx(32.0f, 175.0f, -3.0f, 1, 269, argb, 0);
    bhDispMessageEx(32.0f, 240.0f, -3.0f, 1, 270, argb, 0);
    bhDispMessageEx(32.0f, 304.0f, -3.0f, 1, 271, argb, 0);
    bhDispMessageEx(32.0f, 368.0f, -3.0f, 1, 272, argb, 0);
    
    pos.x = 576.0f;
    pos.y = 175.0f;
    
    DispRank(&pos, argb, rkw.ranking);
    
    pos.x = 416.0f;
    pos.y = 240.0f;
    
    DispTime(&pos, sys->time, argb, 14); 
    
    pos.x = 544.0f;
    pos.y = 304.0f; 
    
    DispNumber(&pos, sys->save_ct, argb);
    
    pos.x = 544.0f;
    pos.y = 368.0f;
    
    DispNumber(&pos, sys->retry_ct, argb);
}

// 96.93% matching
void DispRankingData01()
{
    RANK_WORK* rk; 
    NJS_POINT2 pos;    
    int score;       
    int ranking;       
    unsigned int argb; 
    
    rk = &rkw;

    argb = (rk->alpha << 24) | 0xFFFFFF;
    
    bhDispMessageEx(121.0f, 64.0f, -2.0f, 1, 264, argb, 0);
    bhDispMessageEx(40.0f, 128.0f, -2.0f, 1, 266, argb, 0);
    bhDispMessageEx(119.0f, 224.0f, -2.0f, 1, 268, argb, 0);
    bhDispMessageEx(78.0f, 328.0f, -2.0f, 1, 269, argb, 0);
    
    argb = (rk->alpha << 24) | 0x20FF20;
    
    bhDispMessageEx(360.0f, 128.0f, -2.0f, 1, 267, argb, 0);
    bhDispMessageEx(439.0f, 224.0f, -2.0f, 1, 268, argb, 0);
    bhDispMessageEx(398.0f, 328.0f, -2.0f, 1, 269, argb, 0);
    
    pos.x = 88.0f;
    pos.y = 264.0f;
    
    if (rk->col != 0) 
    {
        argb = (rk->alpha << 24) | 0xFF2020;
    } 
    else
    {
        argb = (rk->alpha << 24) | 0xFFFFFF;
    }
    
    // sys->time gets placed correctly in the ASM of the GC version using this same code
    DispTime(&pos, sys->time, argb, 7);
    
    pos.x = 408.0f;
    pos.y = 264.0f;
    
    if (rk->col == 2)
    {
        argb = (rk->alpha << 24) | 0xFF2020;
    } 
    else
    {
        argb = (rk->alpha << 24) | 0x20FF20;
    }
    
    DispTime(&pos, rk->tmbk, argb, 7);
    
    pos.x = 149.0f;
    pos.y = 368.0f;
    
    argb = (rk->alpha << 24) | 0xFFFFFF;
    
    if (bhCkFlg(sys->ev_flg, 75) == 0)
    {
        DispRank(&pos, argb, rk->ranking);
    }
    
    pos.x = 469.0f;
    pos.y = 368.0f;
    
    argb = (rk->alpha << 24) | 0x20FF20;
    
    score = GameClearScore(rk->tmbk);
    
    ranking = AllRanking(score, 1);
    
    if (ranking != 32) 
    {
        DispRank(&pos, argb, ranking);
    }
}

// 66.38% matching (matches on GC)
void DispNumber(NJS_POINT2* pos, int num, unsigned int col)
{
	bhDispFontEx(pos, mesdeftbl[num / 10], col, -2.0f);

    pos->x += 28.0f;

    bhDispFontEx(pos, mesdeftbl[num % 10], col, -2.0f);
}

// 100% matching!
void DispTime(NJS_POINT2* pos, int time, unsigned int col, unsigned int mode)
{
	bhDispTimeEx(pos, mode, time, col, -2.0f);
}

// 100% matching!
int AllRanking(int score, unsigned int mode)
{
    unsigned int ply_id;        
    int i;                      
    int ret;               
    int rankscore[5][4] = 
    {
        { -1,   10000, -1,   10000 },
        { 9999, 6999,  9999, 6999  },
        { 6999, 4999,  6999, 4999  },
        { 4999, 1000,  4999, 1000  },
        { 1000, 0,     1000, 0     }
    };
    
    i = 0;
    
    if (sys->gm_mode == 0) 
    {
        i = 0;
    } 
    else if (sys->gm_mode == 3) 
    {
        i = 1;
    }
    
    if (score >= rankscore[0][(2 * i) + 1]) 
    {
        ret = 1;
    } 
    else if ((score <= rankscore[1][2 * i]) && (score > rankscore[1][(2 * i) + 1])) 
    {
        ret = 2;
    }
    else if ((score <= rankscore[2][2 * i]) && (score > rankscore[2][(2 * i) + 1])) 
    {
        ret = 4;
    } 
    else if ((score <= rankscore[3][2 * i]) && (score > rankscore[3][(2 * i) + 1]))
    {
        ret = 8;
    }
    else if ((score <= rankscore[4][2 * i]) && (score > rankscore[4][(2 * i) + 1])) 
    {
        ret = 16;
    }
    else
    {
        ret = 16;
    }
    
    if (sys->gm_mode == 0) 
    {
        if ((bhCkFlg(sys->ev_flg, 75) != 0) && (mode == 0) && (!(ret & 0x10)))
        {
            ret *= 2;
        }
    } 
    else 
    {
        if (sys->costume != 0) 
        {
            ply_id = 4;
        }
        else 
        {
            ply_id = sys->ply_id;
        }
        
        if ((bhCkFlg(sys->ev_flg, 75) != 0) && (sys->best_tm[ply_id] == 0)) 
        {
            ret = 32;
        }
    }
    
    return ret;
}

// 
// Start address: 0x2bcaf0
int GameClearScore(int time)
{
	int timescore[8][2];
	int cleartime[2][48];
	int gm_mode;
	int i;
	int ret;
	// Line 1140, Address: 0x2bcaf0, Func Offset: 0
	// Line 1145, Address: 0x2bcaf4, Func Offset: 0x4
	// Line 1142, Address: 0x2bcb04, Func Offset: 0x14
	// Line 1145, Address: 0x2bcb08, Func Offset: 0x18
	// Line 1203, Address: 0x2bcb28, Func Offset: 0x38
	// Line 1210, Address: 0x2bcb44, Func Offset: 0x54
	// Line 1203, Address: 0x2bcb48, Func Offset: 0x58
	// Line 1210, Address: 0x2bcb58, Func Offset: 0x68
	// Line 1212, Address: 0x2bcb64, Func Offset: 0x74
	// Line 1214, Address: 0x2bcb6c, Func Offset: 0x7c
	// Line 1215, Address: 0x2bcb80, Func Offset: 0x90
	// Line 1217, Address: 0x2bcb94, Func Offset: 0xa4
	// Line 1218, Address: 0x2bcb9c, Func Offset: 0xac
	// Line 1222, Address: 0x2bcba4, Func Offset: 0xb4
	// Line 1224, Address: 0x2bcbcc, Func Offset: 0xdc
	// Line 1225, Address: 0x2bcbd4, Func Offset: 0xe4
	// Line 1227, Address: 0x2bcc00, Func Offset: 0x110
	// Line 1228, Address: 0x2bcc08, Func Offset: 0x118
	// Line 1230, Address: 0x2bcc34, Func Offset: 0x144
	// Line 1231, Address: 0x2bcc3c, Func Offset: 0x14c
	// Line 1233, Address: 0x2bcc68, Func Offset: 0x178
	// Line 1234, Address: 0x2bcc70, Func Offset: 0x180
	// Line 1236, Address: 0x2bcc9c, Func Offset: 0x1ac
	// Line 1237, Address: 0x2bcca4, Func Offset: 0x1b4
	// Line 1239, Address: 0x2bccd0, Func Offset: 0x1e0
	// Line 1240, Address: 0x2bccd8, Func Offset: 0x1e8
	// Line 1242, Address: 0x2bcd04, Func Offset: 0x214
	// Line 1243, Address: 0x2bcd0c, Func Offset: 0x21c
	// Line 1244, Address: 0x2bcd28, Func Offset: 0x238
	// Line 1248, Address: 0x2bcd38, Func Offset: 0x248
	// Func End, Address: 0x2bcd44, Func Offset: 0x254
	scePrintf("GameClearScore - UNIMPLEMENTED!\n");
}

// 100% matching
int RodorigoEventScore(void) {
    return (bhCkFlg(sys->ev_flg, 0x60) != 0) ? 0xFA: -0x3E8;
}

// 100% matching 
int SteveEventScore(void) {
    if (bhCkFlg(sys->ev_flg, 0x9B) != 0) {
        return 0x190;
    }
    
    return (bhCkFlg(sys->ev_flg, 0x9C) != 0) ?  -0x3E8: 0;
}

// 100% matching
int MapScore(void) {
    int ret;
    int var_s0;

    var_s0  = 0;
    if (bhFlagCk(8, 6, 0) != 0) {
        var_s0 += 1;
    }
    if (bhFlagCk(8, 7, 0) != 0) {
        var_s0 += 1;
    }
    if (bhFlagCk(8, 0x5D, 0) != 0) {
        var_s0 += 1;
    }
    if (bhFlagCk(8, 0x5E, 0) != 0) {
        var_s0 += 1;
    }
    if (bhFlagCk(8, 0x8F, 0) != 0) {
        var_s0 += 1;
    }

    ret = 0;
    
    if (var_s0 == 5) {
        ret = 0x64;
        return ret;
    }
    
    return ret;
}

// 100% matching
int HealItemUseScore(void) {
    return (sys->spray_ct != 0) ? 0 : 0x708;
}

// 100% matching
int SaveCountScore() {
    int ret = 0;
    int save_ct = sys->save_ct;

    if(save_ct != 0) { 
        ret = -0x3E8; 
        ret = (((save_ct - 1) * -0x32)) + ret; 
    }

    return ret;
}

// 100% matching
int RetryCountScore() { 
    int ret = 0;
    int retry_ct = sys->retry_ct; 
    if(retry_ct != 0) { 
        ret = -0x3E8; 
        ret = (((retry_ct - 1) * -0x32)) + ret; 
    }
    return ret;
}

// 100% matching
void GetMessage(unsigned int mesnum, NJS_POINT2* pos) {
    bhDispMessageEx(pos->x, pos->y, -1.0f, 1, mesnum, (rkw.mesalpha << 0x18) | 0xFFFFFF, 0);
}

// 100% matching
void RankingBgmSet() {
    RANK_WORK* rk = &rkw;
    FADE* sfe = &fade;

    if ((sys->gm_mode == 0) || (sys->gm_mode== 3)) {
        if (rk->ranking & 3) {
            PlayBgm(0x16, 0);
            return;
        }
        PlayBgm(0x20, 0);
        return;
    }
    sfe->flg &= ~1;
    rk->mode_01 = 2;
    rk->mesalpha = 1;
    rk->mescol= 0xC;
}

