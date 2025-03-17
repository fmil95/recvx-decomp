/*typedef struct _anon0;


typedef unsigned char type_0[3];
typedef char type_1[4];

struct _anon0
{
	unsigned char unit;
	unsigned char flag;
	char power;
	unsigned char freq;
	unsigned char inc;
	unsigned char reserved[3];
};*/

char PortIdTbl[4] = {
    0x02, 0x08, 0x0E, 0x14
};
int EnadleVibrationFlag;
unsigned int VibStopTime;

/*void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();*/
int CheckVibrationUnit(unsigned int PortId);
/*int StartVibration(unsigned int PortId, _anon0* vpp);*/
int StopVibration(unsigned int PortId);

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
    
    pdVibMxStart(PortId, vpp); 
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
