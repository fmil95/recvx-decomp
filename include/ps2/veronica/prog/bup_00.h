#ifndef _BUP_00_H_
#define _BUP_00_H_

#include "types.h"
#include "katana_extra.h"

typedef struct TYP_WORK
{
    // total size: 0x320
	NJS_TEXNAME twtx[3];        // offset 0x0, size 0x24
	NJS_TEXLIST twtx_list;      // offset 0x24, size 0x8
	int mode_00;                // offset 0x2C, size 0x4
    int mode_02;                // offset 0x30, size 0x4
    int mode_03;                // offset 0x34, size 0x4
    int nextmode00;             // offset 0x38, size 0x4
    int nextmode01;             // offset 0x3C, size 0x4
    int savecsr;                // offset 0x40, size 0x4
    int mesnum;                 // offset 0x44, size 0x4
    int errorcode;              // offset 0x48, size 0x4
    unsigned int pertype[4][3]; // offset 0x4C, size 0x30
    unsigned int ptbak[4][3];   // offset 0x7C, size 0x30
    int vmscsr;                 // offset 0xAC, size 0x4
    int drive;                  // offset 0xB0, size 0x4
    int gamesavesize;           // offset 0xB4, size 0x4
    int stg[15];                // offset 0xB8, size 0x3C
    int saveversion[15];        // offset 0xF4, size 0x3C
    int savenamework[32];       // offset 0x130, size 0x80
    int savecount[15];          // offset 0x1B0, size 0x3C
    int playername[15];         // offset 0x1EC, size 0x3C
    int gamemode[15];           // offset 0x228, size 0x3C
    int timer[8];               // offset 0x264, size 0x20
    int fileimagesize;          // offset 0x284, size 0x4
    int freeaddress;            // offset 0x288, size 0x4
    int buffersize;             // offset 0x28C, size 0x4
    short keywait00;            // offset 0x290, size 0x2
    short keywait01;            // offset 0x292, size 0x2
    short count00;              // offset 0x294, size 0x2
    short count01;              // offset 0x296, size 0x2
    short count02;              // offset 0x298, size 0x2
    short count03;              // offset 0x29A, size 0x2
    short count04;              // offset 0x29C, size 0x2
    short count05;              // offset 0x29E, size 0x2
    short count06;              // offset 0x2A0, size 0x2
    short count07;              // offset 0x2A2, size 0x2
    short count08;              // offset 0x2A4, size 0x2
    short csr_00;               // offset 0x2A6, size 0x2
    short csr_01;               // offset 0x2A8, size 0x2
    short cur_cnt[4];           // offset 0x2AA, size 0x8
    short cur_flg[4];           // offset 0x2B2, size 0x8
    short vmsretry;             // offset 0x2BA, size 0x2
    unsigned char* savemem;     // offset 0x2BC, size 0x4
    char mestype;               // offset 0x2C0, size 0x1
    unsigned char dirbuf[4][2]; // offset 0x2C1, size 0x8
    unsigned char* mountbuf;    // offset 0x2CC, size 0x4
    unsigned char* mountbak;    // offset 0x2D0, size 0x4
    unsigned int version;       // offset 0x2D4, size 0x4
    int save_ct;                // offset 0x2D8, size 0x4
    char ply_id;                // offset 0x2DC, size 0x1
    char stg_no;                // offset 0x2DD, size 0x1
    char rom_no;                // offset 0x2DE, size 0x1
    char rcase;                 // offset 0x2DF, size 0x1
    char pos_no;                // offset 0x2E0, size 0x1
    char cut_no;                // offset 0x2E1, size 0x1
    char flr_no;                // offset 0x2E2, size 0x1
    char reserve0;              // offset 0x2E3, size 0x1
    int gm_mode;                // offset 0x2E4, size 0x4
    unsigned int end;           // offset 0x2E8, size 0x4
    unsigned int ssd_ver;       // offset 0x2EC, size 0x4
    unsigned int ssd_flg;       // offset 0x2F0, size 0x4
    unsigned int ssd_reserve;   // offset 0x2F4, size 0x4
    char keytype;               // offset 0x2F8, size 0x1
    char adjust_x;              // offset 0x2F9, size 0x1
    char adjust_y;              // offset 0x2FA, size 0x1
    char vibration;             // offset 0x2FB, size 0x1
    unsigned int best_tm[8];    // offset 0x2FC, size 0x20
    unsigned int sys_end;       // offset 0x31C, size 0x4
} TYP_WORK;

void ControlTypewriter();
void TypewriterKeepMemory();
void CountDisplay(int disppoint, NJS_POINT2* pos, unsigned int col, int param);
unsigned int RoomNameSwitch(unsigned int name);
void TypeWriterTextureInit();
void TypewriterInit();
void TypewriterMain();
void TypewriterExit();

#endif
