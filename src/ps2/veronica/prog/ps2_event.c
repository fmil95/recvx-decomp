#include "ps2_event.h"
#include "ps2_NaSystem.h"
#include "main.h"

/*_anon44 cam;
_anon10* sys;
_anon11* rom;*/
unsigned char BackColorFlag;

/*void bhChangeBackColor();
void bhChangeBackColorEvt();*/

// 100% matching!
void bhChangeBackColor()
{
    int i;                           
    unsigned int BackCol;             
    char ev_flag; // not from the debugging symbols
    static EVT_WRK* BackColTbl;
    static EVT_WRK BackColSt0[5] =
    {
        { 12,  0,  1, 0, 0, 0x1E1A10, 0 },
        { 12,  0,  2, 0, 0, 0x1E1A10, 0 },
        { 12,  0,  3, 0, 0, 0x1E1A10, 0 },
        { 12,  0,  4, 0, 0, 0x1E1A10, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt1[4] =
    {
        {  7,  0,  0, 0, 0, 0x202015, 0 },
        {  7,  0,  1, 0, 0, 0x202018, 0 },
        { 11,  0,  2, 0, 0, 0x1A1910, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt2[4] = 
    {
        {  4,  0,  0, 0, 0, 0x201921, 0 },
        {  4,  0,  1, 0, 0, 0x201921, 0 },
        {  6,  0,  0, 0, 0, 0x201321, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt3[16] = 
    {
        {  3,  0,  0, 0, 0,  0x31010, 0 },
        {  4,  0,  1, 0, 0, 0x181310, 0 },
        {  6,  0,  0, 0, 0, 0x303030, 0 },
        {  6,  0,  1, 0, 0, 0x282828, 0 },
        {  6,  0,  3, 0, 0, 0x202020, 0 },
        {  6,  0,  4, 0, 0, 0x505030, 0 },
        {  8,  0,  1, 0, 0, 0x202028, 0 },
        {  8,  0,  3, 0, 0, 0x141621, 0 },
        { 10,  0,  6, 0, 0, 0x18181C, 0 },
        { 10,  0,  8, 0, 0, 0x101219, 0 },
        { 15,  0,  0, 0, 0, 0x202018, 0 },
        { 15,  0,  1, 0, 0, 0x181818, 0 },
        { 16,  0,  0, 0, 0,  0xC0C1C, 0 },
        { 16,  0,  1, 0, 0,  0xC0C1C, 0 },
        { 21,  0,  0, 0, 0, 0x101318, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt4[4] =
    { 
        {  0,  0,  0, 0, 0, 0x101E20, 0 },
        {  0,  0,  1, 0, 0, 0x101E20, 0 },
        {  0,  0,  2, 0, 0, 0x101E20, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt5[18] =
    {
        { 60,  0,  0, 0, 0, 0x10363B, 0 },
        { 60,  0,  2, 0, 0, 0x10363B, 0 },
        { 60,  0,  5, 0, 0, 0x10363B, 0 },
        { 60,  0,  6, 0, 0, 0x10363B, 0 },
        { 60,  0,  8, 0, 0, 0x10363B, 0 },
        { 60,  0,  9, 0, 0, 0x10363B, 0 },
        { 64,  0,  1, 0, 0, 0x201F20, 0 },
        { 66,  0,  0, 0, 0, 0x202018, 0 },
        { 66,  0,  1, 0, 0, 0x181818, 0 },
        { 68,  0,  0, 0, 0, 0xB0C0D0, 0 },
        { 68,  0,  1, 0, 0, 0x90A0B0, 0 },
        { 68,  0,  2, 0, 0, 0x90A0B0, 0 },
        { 68,  0,  3, 0, 0, 0x606870, 0 },
        { 69,  0,  0, 0, 0, 0x15110A, 0 },
        { 71,  0,  0, 0, 0, 0x101E20, 0 },
        { 71,  0,  1, 0, 0, 0x101E20, 0 },
        { 71,  0,  2, 0, 0, 0x101E20, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt6[24] =
    {
        {  1,  0,  0, 0, 0, 0x404040,        0 },
        {  1,  0,  1, 0, 0, 0x404040,        0 },
        {  1,  0,  2, 0, 0, 0x404040,        0 },
        {  1,  0,  4, 0, 0, 0x404040,        0 },
        {  1,  0,  6, 0, 0, 0x404040,        0 },
        {  3,  0,  0, 0, 1, 0x10272C, 0x21343A },
        {  3,  0,  1, 0, 1, 0x1B3C43, 0x21343A },
        {  3,  0,  2, 0, 1, 0x1B3C43, 0x21343A },
        {  3,  0,  4, 0, 1, 0x10272C, 0x1A2324 },
        {  5,  0,  0, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  1, 0, 1, 0x12181F, 0x10363B },
        {  5,  1,  1, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  2, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  3, 0, 0, 0x12120F,        0 },
        {  5,  0,  5, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  6, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  8, 0, 1, 0x12181F, 0x10363B },
        {  5,  0,  9, 0, 1, 0x12181F, 0x10363B },
        {  6,  0,  0, 0, 1, 0x25404B, 0x50807A },
        {  6,  0,  1, 0, 1, 0x1D343C, 0x49716E },
        {  6,  0,  2, 0, 3, 0x304D50,        0 },
        {  6,  0,  2, 0, 3, 0x5A8781, 0x889850 },
        {  6,  0,  3, 0, 1, 0x304D50, 0x5A8781 },
        { -1, -1, -1, 0, 0,        0,        0 },
    };
    static EVT_WRK BackColSt7[11] = 
    {
        {  5,  0,  1, 0, 0,   0x110E, 0 },
        {  7,  0,  0, 0, 0, 0x205070, 0 },
        {  7,  0,  2, 0, 0, 0x205070, 0 },
        {  7,  0,  3, 0, 0, 0x103C50, 0 },
        {  7,  1,  0, 0, 0, 0x205070, 0 },
        {  7,  1,  2, 0, 0, 0x205070, 0 },
        {  7,  1,  3, 0, 0, 0x103C50, 0 },
        { 11,  0,  2, 0, 0, 0x181818, 0 },
        { 11,  0,  4, 0, 0, 0x181818, 0 },
        { 15,  0,  4, 0, 0, 0x1D1D00, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt8[4] = 
    {
        {  0,  0,  0, 0, 0, 0x101E20, 0 },
        {  0,  0,  1, 0, 0, 0x101E20, 0 },
        {  0,  0,  2, 0, 0, 0x101E20, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt9[22] = 
    {
        {  1,  0,  0, 0, 0, 0x404040,        0 },
        {  1,  0,  1, 0, 0, 0x404040,        0 },
        {  1,  0,  2, 0, 0, 0x404040,        0 },
        {  1,  0,  4, 0, 0, 0x404040,        0 },
        {  1,  0,  6, 0, 0, 0x404040,        0 },
        {  3,  0,  0, 0, 0, 0x21343A,        0 },
        {  3,  0,  1, 0, 0, 0x21343A,        0 },
        {  3,  0,  2, 0, 0, 0x21343A,        0 },
        {  3,  0,  4, 0, 0, 0x1A2324,        0 },
        {  9,  0,  0, 0, 0, 0x23292C,        0 },
        { 10,  0,  0, 0, 0, 0x293735,        0 },
        { 10,  0,  1, 0, 0, 0x162A23,        0 },
        { 10,  0,  3, 0, 0,  0xE1A18,        0 },
        { 12,  0,  0, 0, 2, 0x102025, 0xB0C0D0 },
        { 12,  0,  2, 0, 2,     0x60, 0xE1F2FE },
        { 12,  0,  3, 0, 2, 0x222729, 0x606870 },
        { 17,  0,  1, 0, 0,  0x82424,        0 },
        { 17,  0,  3, 0, 0,  0x82424,        0 },
        { 17,  0,  4, 0, 0,  0x82424,        0 },
        { 20,  0,  0, 0, 0, 0x242424,        0 },
        { 27,  0,  1, 0, 0, 0x201F20,        0 },
        { -1, -1, -1, 0, 0,        0,        0 },
    };
	static EVT_WRK* BackColStage[10] =
    {
        BackColSt0,
        BackColSt1,
        BackColSt2,
        BackColSt3,
        BackColSt4,
        BackColSt5,
        BackColSt6,
        BackColSt7,
        BackColSt8,
        BackColSt9 
    };

    if (BackColorFlag == 0) 
    {
        return;
    }
    
    BackCol = rom->bak_col;
    
    BackColTbl = BackColStage[sys->stg_no];
    
    for (i = 0; ; i++) 
    {
        if ((sys->rom_no == BackColTbl[i].room) && (sys->rcase == BackColTbl[i].rcase) && (cam.ncut == BackColTbl[i].evc_no)) 
        {
            if (BackColTbl[i].flag != 0) 
            {
                BackCol = cam.fog_col;
                break;
            }
            
            ev_flag = BackColTbl[i].ev_flag;
            
            if (BackColTbl[i].ev_flag == 0) 
            {
                BackCol = BackColTbl[i].col;
            } 
            else if (ev_flag == 1)
            {
                if ((sys->ev_flg[9] & 0x400000)) 
                {
                    BackCol = BackColTbl[i].ev_col;
                } 
                else 
                {
                    BackCol = BackColTbl[i].col;
                }
            }
            else if (ev_flag == 2)
            {
                if ((sys->ev_flg[12] & 0x20)) 
                {
                    BackCol = BackColTbl[i].ev_col;
                } 
                else
                {
                    BackCol = BackColTbl[i].col;
                }
            }
            else if (ev_flag == 3)
            {
                if ((sys->ev_flg[9] & 0x400000))
                {
                    if (((sys->ev_flg[9] & 0x8000000)) && (!(sys->ev_flg[9] & 0x10000000)))
                    {
                        BackCol = BackColTbl[i + 1].ev_col;
                    }
                    else 
                    {
                       BackCol = BackColTbl[i + 1].col;
                    }
                }
                else
                {
                    BackCol = BackColTbl[i].col;
                }
            }
            
            break;
        }
        
        if (BackColTbl[i].room < 0)
        {
            break;
        }
    }
    
    njSetBackColor(BackCol, BackCol, BackCol);
}

// 
// Start address: 0x2e7f50
void bhChangeBackColorEvt()
{
	unsigned int BackCol;
	int i;
	//_anon1* BackColTbl;
	//_anon1* BackColStage[10];
	// Line 1088, Address: 0x2e7f50, Func Offset: 0
	// Line 1165, Address: 0x2e7f58, Func Offset: 0x8
	// Line 1166, Address: 0x2e7f68, Func Offset: 0x18
	// Line 1168, Address: 0x2e7f70, Func Offset: 0x20
	// Line 1167, Address: 0x2e7f78, Func Offset: 0x28
	// Line 1168, Address: 0x2e7f7c, Func Offset: 0x2c
	// Line 1166, Address: 0x2e7f84, Func Offset: 0x34
	// Line 1168, Address: 0x2e7f88, Func Offset: 0x38
	// Line 1170, Address: 0x2e7fb8, Func Offset: 0x68
	// Line 1173, Address: 0x2e7fe0, Func Offset: 0x90
	// Line 1174, Address: 0x2e7ff4, Func Offset: 0xa4
	// Line 1176, Address: 0x2e8000, Func Offset: 0xb0
	// Line 1177, Address: 0x2e800c, Func Offset: 0xbc
	// Line 1178, Address: 0x2e8014, Func Offset: 0xc4
	// Line 1179, Address: 0x2e8028, Func Offset: 0xd8
	// Line 1180, Address: 0x2e803c, Func Offset: 0xec
	// Line 1183, Address: 0x2e8044, Func Offset: 0xf4
	// Line 1184, Address: 0x2e8058, Func Offset: 0x108
	// Line 1185, Address: 0x2e8068, Func Offset: 0x118
	// Line 1190, Address: 0x2e8070, Func Offset: 0x120
	// Line 1191, Address: 0x2e8078, Func Offset: 0x128
	// Line 1195, Address: 0x2e8084, Func Offset: 0x134
	// Line 1199, Address: 0x2e808c, Func Offset: 0x13c
	// Line 1200, Address: 0x2e8098, Func Offset: 0x148
	// Func End, Address: 0x2e80a4, Func Offset: 0x154
	scePrintf("bhChangeBackColorEvt - UNIMPLEMENTED!\n");
}

