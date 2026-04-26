#ifndef _RANKING_H_
#define _RANKING_H_

#include "types.h"

typedef struct RANK_WORK
{
    // total size: 0xA0
	NJS_TEXNAME rktx[2];       // offset 0x0, size 0x18
	NJS_TEXLIST rktx_list;     // offset 0x18, size 0x8
	int hour;                  // offset 0x20, size 0x4
    int min;                   // offset 0x24, size 0x4
    int sec;                   // offset 0x28, size 0x4
    int allscore;              // offset 0x2C, size 0x4
    int ranking;               // offset 0x30, size 0x4
    int mode_00;               // offset 0x34, size 0x4
    int mode_01;               // offset 0x38, size 0x4
    int mode_02;               // offset 0x3C, size 0x4
    int mode_03;               // offset 0x40, size 0x4
    int alcount00;             // offset 0x44, size 0x4
    int errret;                // offset 0x48, size 0x4
    unsigned int cnt00;        // offset 0x4C, size 0x4
    unsigned int cnt01;        // offset 0x50, size 0x4
    int tmbk;                  // offset 0x54, size 0x4
    unsigned int col;          // offset 0x58, size 0x4
    int filebak;               // offset 0x5C, size 0x4
    int mesalpha;              // offset 0x60, size 0x4
    int mescol;                // offset 0x64, size 0x4
    unsigned int mesnum[4];    // offset 0x68, size 0x10
	NJS_POINT2 mespos[4];      // offset 0x78, size 0x20
	unsigned short mesloop;    // offset 0x98, size 0x2
    unsigned char alpha;       // offset 0x9A, size 0x1
    unsigned char gameest00;   // offset 0x9B, size 0x1
    unsigned char gamecarry00; // offset 0x9C, size 0x1
    unsigned char gameest01;   // offset 0x9D, size 0x1
    unsigned char gamecarry01; // offset 0x9E, size 0x1
    unsigned char dummy;       // offset 0x9F, size 0x1
} RANK_WORK;

void ControlRanking();
void RankingInit();
void RankingVmsWait();
void RankingSave();
void RankingErrorMessage();
void RankingMain();
void RankingExit();
void RankingTextureInit();
void WallPaperDisp();
void DispRank(NJS_POINT2* pos, unsigned int color, int rank);
void DispRankingData00();
void DispRankingData01();
void DispNumber(NJS_POINT2* pos, int num, unsigned int col);
void DispTime(NJS_POINT2* pos, int time, unsigned int col, unsigned int mode);
int AllRanking(int score, unsigned int mode);
int GameClearScore(int time);
int RodorigoEventScore();
int SteveEventScore();
int MapScore();
int HealItemUseScore();
int SaveCountScore();
int RetryCountScore();
void GetMessage(unsigned int mesnum, NJS_POINT2* pos);
void RankingBgmSet();

#endif
