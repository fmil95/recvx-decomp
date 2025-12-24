#include "vibman.h"

unsigned int VibStopTime;
int EnadleVibrationFlag;
char PortIdTbl[4] = {2, 8, 14, 20};

// 100% matching! 
void InitVibrationUnit()
{ 
    int i;

    VibStopTime = 20;

    for (i = 0; i < 4; i++) 
    { 
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) 
        { 
            pdVibMxSetStopTime(PortIdTbl[i], VibStopTime); 
        } 
    } 

    EnadleVibrationFlag = 0; 
} 

// 100% matching! 
void ExitVibrationUnit()
{ 
    int i;

    for (i = 0; i < 4; i++) 
    { 
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) 
        { 
            StopVibration(PortIdTbl[i]); 
        }
    } 
} 

// 100% matching! 
void SetUseVibrationUnit(int Flag)
{
    EnadleVibrationFlag = Flag;
}

// 100% matching! 
int GetUseVibrationUnit()
{
    return EnadleVibrationFlag; 
} 

// 100% matching!
int CheckVibrationUnit(unsigned int PortId)
{
    return pdVibMxIsReady(PortId); 
}

// 100% matching! 
int StartVibration(unsigned int PortId, PDS_VIBPARAM* vpp) 
{ 
    if (EnadleVibrationFlag == 0) 
    { 
        return 0; 
    }

    if ((PortId % 6) != 2) 
    { 
        return -3; 
    }

    if (CheckVibrationUnit(PortId) != 1)
    { 
        return -2; 
    }

    vpp->unit = 1; 
    
    return pdVibMxStart(PortId, vpp); 
} 

// 100% matching! 
int StopVibration(unsigned int PortId)
{
    if (EnadleVibrationFlag == 0)
    { 
        return 0; 
    }
    
    if ((PortId % 6) != 2) 
    { 
        return -3;
    }

    if (CheckVibrationUnit(PortId) != 1) 
    {
        return -2;
    }
    
    return pdVibMxStop(PortId);
}
