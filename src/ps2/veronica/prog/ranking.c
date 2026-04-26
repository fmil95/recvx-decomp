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

// 100% matching!
void RankingInit()
{
    RANK_WORK* rk;      
    FADE* sfe;           
    int j;              
    unsigned int ply_id; 
    unsigned int* flg; // not from DWARF
    
    rk = &rkw;
    sfe = &fade;

    j = 0;
    
    RankingTextureInit();
    
    if (sys->typ_md0 == 2)
    {
        sys->cb_flg &= ~0x4;
        
        rk->mesloop = 0;
        
        ReadPlayLog(&rk->gameest00, &rk->gamecarry00);
        
        sys->typ_flg &= 0x7FFFFFFF;
        sys->typ_md0 = 1;
        
        if (sys->gm_mode != 3)
        {
            DispFadeInit();
            
            sfe->alphaset = 255.0f;
            
            sfe->cnt00 = 255.0f;
            sfe->cnt01 = -12.0f;
            
            rk->alpha = 0;
            
            rk->filebak = 0;
            
            rk->allscore = 0;
            
            rk->allscore += GameClearScore(sys->time);
            rk->allscore += RodorigoEventScore();
            rk->allscore += SteveEventScore();
            rk->allscore += MapScore();
            rk->allscore += HealItemUseScore();
            rk->allscore += SaveCountScore();
            rk->allscore += RetryCountScore();
            
            rk->ranking = AllRanking(rk->allscore, 0);
            
            if ((sys->gm_mode == 0) && (rk->ranking == 1) && (!(sys->ssd_flg & 0x2))) 
            {
                sys->ssd_flg |= 0x2;
                
                rk->mesnum[0] = 273;
                
                rk->mespos[0].x = 112.0f;
                rk->mespos[0].y = 368.0f;
                
                j++; 
            }
            
            if (!(sys->ssd_flg & 0x1)) 
            {
                sys->ssd_flg |= 0xD;
                
                rk->mesnum[j] = 276;
                
                rk->mespos[j].x = 112.0f;
                rk->mespos[j].y = 368.0f;
                
                j++;
            }
            
            if ((bhCkFlg(sys->it_flg, 326) != 0) && (!(sys->ssd_flg & 0x10))) 
            {
                sys->ssd_flg |= 0x10;
            }
            
            rk->mesloop = j;
            rk->mescol = 12;
        }
        else if (sys->gm_mode == 3) 
        {
            DispFadeInit();
            
            sfe->alphaset = 255.0f;
            
            sfe->cnt00 = 255.0f;
            sfe->cnt01 = -12.0f;
            
            if (sys->costume != 0) 
            {
                ply_id = 4;
            } 
            else 
            {
                ply_id = sys->ply_id;
            }
            
            sys->ssd_flg |= 0x1;
            
            rk->alpha = 0;
            
            rk->filebak = 0;
            
            rk->allscore = 0;
            
            rk->allscore += GameClearScore(sys->time);
            
            rk->ranking = AllRanking(rk->allscore, 0);
            
            if (bhCkFlg(sys->ev_flg, 75) != 0) 
            {
                if (sys->best_tm[ply_id] == 0) 
                {
                    rk->tmbk = 0x354E4;
                    
                    rk->col = 0;
                } 
                else
                {
                    rk->tmbk = sys->best_tm[ply_id];
                    
                    rk->col = 0;
                }
            }
            else if (sys->best_tm[ply_id] == 0) 
            {
                rk->tmbk = sys->best_tm[ply_id] = sys->time;
                
                rk->col = 2;
            } 
            else if (sys->time < sys->best_tm[ply_id]) 
            {
                rk->tmbk = sys->best_tm[ply_id] = sys->time;
                
                rk->col = 1; 
            }
            else 
            {
                rk->tmbk = sys->best_tm[ply_id];
                
                rk->col = 0;
            }
            
            if (rk->ranking == 1)
            {
                switch (ply_id) 
                {                   
                case 0:                             
                    sys->ssd_flg |= 0x80;
                    break;
                case 1:                             
                    sys->ssd_flg |= 0x100;
                    break;
                case 2:                             
                    sys->ssd_flg |= 0x200;
                    break;
                case 3:                             
                    sys->ssd_flg |= 0x800;
                    break;
                case 4:                             
                    sys->ssd_flg |= 0x400;
                    break;
                }
            }

            if ((sys->ssd_flg & 0xF80) == 0xF80) 
            {
                flg = &sys->ssd_flg; // I'm as puzzled as you are
                
                if (!(*flg & 0x80000000))
                {
                    *flg |= 0x80000000;
                    
                    rk->mesnum[j] = 279;
                    
                    rk->mespos[j].x = 128.0f; 
                    rk->mespos[j].y = 368.0f;
                    
                    j++;
                }
            }
            
            switch (ply_id) 
            {                       
            case 0:                                 
                if (!(sys->ssd_flg & 0x20)) 
                {
                    sys->ssd_flg |= 0x20;
                    
                    rk->mesnum[j] = 277;
                    
                    rk->mespos[j].x = 80.0f;
                    rk->mespos[j].y = 368.0f;
                    
                    j++;
                }
                
                break;
            case 1:                                 
                if (!(sys->ssd_flg & 0x40)) 
                {
                    sys->ssd_flg |= 0x40;
                    
                    rk->mesnum[j] = 278;
                    
                    rk->mespos[j].x = 208.0f;
                    rk->mespos[j].y = 368.0f;
                    
                    j++;
                }
                
                break;
            }
            
            rk->mesloop = j;
            rk->mescol = 12;
        }
    }
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

// 100% matching!
int GameClearScore(int time)
{
    int ret = 0;               
    int i;                  
    int gm_mode;              
    int cleartime[48][2] = // TODO: verify this 2D array and the one below are correctly defined
    {
        { 0,       972060  },
        { 972060,  1080572 },
        { 1080572, 1187036 },
        { 1187036, 1317660 },
        { 1317660, 1620060 },
        { 1620060, 0       },
        { 0,       0       },
        { 0,       22200   },
        { 22200,   22800   },
        { 22800,   23400   },
        { 23400,   24000   },
        { 24000,   24000   },
        { 24000,   24000   },
        { 24000,   24000   },
        { 24000,   24000   },
        { 0,       23400   },
        { 23400,   30600   },
        { 30600,   34200   },
        { 23400,   37800   },
        { 37800,   37800   },
        { 37800,   37800   },
        { 37800,   37800   },
        { 37800,   37800   },
        { 0,       36000   },
        { 36000,   45000   },
        { 45000,   48600   },
        { 48600,   52200   },
        { 52200,   52200   },
        { 52200,   52200   },
        { 52200,   52200   },
        { 52200,   0       },
        { 218340,  218340  },
        { 218340,  218340  },
        { 218340,  218340  },
        { 218340,  218340  },
        { 218340,  218340  },
        { 218340,  218340  },
        { 218340,  218340  },
        { 0,       28740   },
        { 28740,   32340   },
        { 32340,   35940   },
        { 35940,   39540   },
        { 39540,   43140   },
        { 43140,   43140   },
        { 43140,   43140   },
        { 43140,   43140   },
        { 43140,   43140   },
        { 43140,   43140   }
    };
    int timescore[2][8] = 
    {
        { 7550, 7000, 6450, 5500, 5000, 2500, 2000, 10000 },
        { 8000, 6000, 4000,    0,    0,    0,    0,     0 }
    };
    unsigned int ply_id; // not from DWARF

    gm_mode = sys->gm_mode;
    
    if (gm_mode != 0)
    {
        i = 1;
    } 
    else 
    {
        i = 0;
    }
    
    if (gm_mode == 0)
    {
        ply_id = 0;
    } 
    else if (gm_mode == 3)
    {
        if (sys->costume != 0) 
        {
            ply_id = 5;
        } 
        else
        { 
            ply_id = sys->ply_id + 1;
        }
    }
    
    if ((time >= cleartime[8 * ply_id][0]) && (time < cleartime[8 * ply_id][1]))
    {
        ret = timescore[i][0]; 
    } 
    else if ((time >= cleartime[(8 * ply_id) + 1][0]) && (time < cleartime[(8 * ply_id) + 1][1]))
    {
        ret = timescore[i][1]; 
    }
    else if ((time >= cleartime[(8 * ply_id) + 2][0]) && (time < cleartime[(8 * ply_id) + 2][1])) 
    {
        ret = timescore[i][2]; 
    } 
    else if ((time >= cleartime[(8 * ply_id) + 3][0]) && (time < cleartime[(8 * ply_id) + 3][1]))
    {
        ret = timescore[i][3]; 
    } 
    else if ((time >= cleartime[(8 * ply_id) + 4][0]) && (time < cleartime[(8 * ply_id) + 4][1])) 
    {
        ret = timescore[i][4];  
    } 
    else if ((time >= cleartime[(8 * ply_id) + 5][0]) && (time < cleartime[(8 * ply_id) + 5][1])) 
    {
        ret = timescore[i][5]; 
    } 
    else if ((time >= cleartime[(8 * ply_id) + 6][0]) && (time < cleartime[(8 * ply_id) + 6][1])) 
    {
        ret = timescore[i][6]; 
    } 
    else if (time >= cleartime[(8 * ply_id) + 7][0]) 
    {
        ret = timescore[i][7];  
    }
    
    return ret;
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
