unsigned int KeyWaitFirst = 10;
unsigned int KeyWaitNext = 4;
BUTTON_INFO ButtonInfo[5]; 
int SoftResetFlag;
int CurrentPortId;
PAD_INFO Pad[4];
int MaxContorolPlayer;
REPEAT_INFO RepeatInfo[4][6];

void InitReadKeyEx(int MaxPlayer);
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer);
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

// 100% matching! 
void InitReadKeyEx(int MaxPlayer) 
{
    unsigned int i; 
    unsigned int j; 

    for (i = 0; i < 4; i++) 
    { 
        RepeatInfo[i][0].Key = 0x8000; 
        RepeatInfo[i][1].Key = 0x2000; 
        RepeatInfo[i][2].Key = 0x1000; 
        RepeatInfo[i][3].Key = 0x4000; 
        RepeatInfo[i][4].Key = 0x4; 
        RepeatInfo[i][5].Key = 0x8; 
        
        for (j = 0; j < 6; j++)
        { 
            RepeatInfo[i][j].WaitFlag = 0; 
            RepeatInfo[i][j].WaitCnt = 0; 
        } 
        
        Pad[i].on2 = 0; 
        Pad[i].press2 = 0; 
        
        Pad[i].Calibrate = 64; 
        
        Pad[i].Flag = 1; 
        
        Pad[i].SoftReset = 0; 
    }   

    MaxContorolPlayer = MaxPlayer; 

    for (i = 0; i < MaxPlayer; i++) 
    { 
        Pad[i].Flag = 0; 
    } 
    
    CurrentPortId = 0; 
    
    SoftResetFlag = 0; 
} 

// 100% matching! 
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer)
{
    KeyWaitFirst = FirstTimer; 
    KeyWaitNext = NextTimer; 
} 

// 100% matching! 
int CheckSoftResetKeyFlag(int ControllerId)
{
    if (ControllerId < 0) 
    {
        return Pad[CurrentPortId].SoftReset; 
    }
    else 
    {
        return Pad[ControllerId].SoftReset;
    }
}

// 100% matching! 
void ClearSoftResetKeyFlag(int ControllerId)
{
    int i;

    if (ControllerId < 0) 
    { 
        for (i = 0; i < 4; i++) 
        { 
            Pad[i].SoftReset = 0; 
        } 
    } 
    else 
    {
        Pad[ControllerId].SoftReset = 0; 
    }

    SoftResetFlag = 0; 
} 
