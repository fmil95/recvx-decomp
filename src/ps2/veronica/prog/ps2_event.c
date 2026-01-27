#include "ps2_event.h"
#include "ps2_NaSystem.h"
#include "main.h"

unsigned char BackColorFlag;

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

// 100% matching!
void bhChangeBackColorEvt()
{
    int i;                           
    unsigned int BackCol;             
    char ev_flag; // not from the debugging symbols
    static EVT_WRK* BackColTbl;
    static EVT_WRK BackColSt0[1] = 
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt1[1] = 
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt2[1] = 
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt3[4] = 
    {
        { 23,  0,  6, 0, 0, 0x386880, 0 },
        { 23,  0, 10, 0, 0, 0x386880, 0 },
        { 23,  0, 11, 0, 0, 0x386880, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt4[1] =
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt5[1] = 
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt6[2] = 
    {
        {  3,  0,  0, 0, 0, 0x10272C, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt7[14] = 
    {
        {  7,  0,  0, 0, 0, 0x506070, 0 },
        {  7,  0,  2, 0, 0, 0x304060, 0 },
        {  7,  0, 10, 0, 0, 0x304860, 0 },
        {  7,  0, 11, 0, 0, 0x506070, 0 },
        {  7,  0, 14, 0, 0, 0x505860, 0 },
        {  7,  0, 15, 0, 0, 0x305050, 0 },
        {  7,  0, 19, 0, 0, 0x305060, 0 },
        {  7,  0, 20, 0, 0, 0x608090, 0 },
        {  7,  0, 24, 0, 0, 0x274359, 0 },
        {  7,  0, 25, 0, 0, 0x304040, 0 },
        {  7,  0, 26, 0, 0, 0x306080, 0 },
        {  7,  0, 28, 0, 0, 0x306078, 0 },
        {  7,  0, 30, 0, 0, 0x304040, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
    };
    static EVT_WRK BackColSt8[1] =
    {
        { -1, -1, -1, 0, 0, 0, 0 },
    };
    static EVT_WRK BackColSt9[14] = 
    {
        {  9,  0, 44, 0, 0, 0x14171A, 0 },
        {  9,  0, 58, 0, 0, 0x14171A, 0 },
        { 28,  0, 10, 0, 0,  0xA121B, 0 },
        { 28,  0, 34, 0, 0,  0xA121B, 0 },
        { 35,  0,  1, 0, 0, 0x909870, 0 },
        { 35,  0,  6, 0, 0, 0x909870, 0 },
        { 35,  0, 11, 0, 0, 0x5B6C8A, 0 },
        { 35,  0, 18, 0, 0, 0x181C20, 0 },
        { 35,  0, 32, 0, 0, 0x181C20, 0 },
        { 35,  0, 37, 0, 0, 0x181C20, 0 },
        { 35,  0, 38, 0, 0, 0x404040, 0 },
        { 35,  0, 44, 0, 0, 0x181C20, 0 },
        { 35,  0, 45, 0, 0, 0x909870, 0 },
        { -1, -1, -1, 0, 0,        0, 0 },
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
            
            break;
        }
        
        if (BackColTbl[i].room < 0)
        {
            break;
        }
    }
    
    njSetBackColor(BackCol, BackCol, BackCol);
}
