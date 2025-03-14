/*typedef enum SDE_DATA_TYPE;



enum SDE_DATA_TYPE
{
	SDE_DATA_TYPE_SND_DRV = 0x56524453,
	SDE_DATA_TYPE_MULTI_UNIT = 0x544c4d53,
	SDE_DATA_TYPE_MIDI_DRM_BANK = 0x42444d53,
	SDE_DATA_TYPE_MIDI_SEQ_BANK = 0x42534d53,
	SDE_DATA_TYPE_MIDI_PRG_BANK = 0x42504d53,
	SDE_DATA_TYPE_SHOT_BANK = 0x42534f53,
	SDE_DATA_TYPE_PSTM_RING_BUF = 0x52535053,
	SDE_DATA_TYPE_FX_OUT_BANK = 0x424f4653,
	SDE_DATA_TYPE_FX_PRG_BANK = 0x42504653,
	SDE_DATA_TYPE_FX_PRG_WRK = 0x57504653
};

int GdDaPlayFlag;
unsigned int SddFirstFlag;
char SdcGdDaVolume;

void InitSdcParameter();
int InitSoundDriver(char* SddFileName, char* MufFileName);*/

// 
// Start address: 0x290810
void InitSdcParameter()
{
	// Line 23, Address: 0x290810, Func Offset: 0
	// Line 24, Address: 0x290818, Func Offset: 0x8
	// Line 26, Address: 0x290828, Func Offset: 0x18
	// Line 27, Address: 0x290830, Func Offset: 0x20
	// Line 28, Address: 0x290838, Func Offset: 0x28
	// Line 29, Address: 0x290840, Func Offset: 0x30
	// Line 31, Address: 0x290848, Func Offset: 0x38
	// Line 32, Address: 0x290850, Func Offset: 0x40
	// Line 34, Address: 0x290858, Func Offset: 0x48
	// Line 35, Address: 0x290864, Func Offset: 0x54
	// Func End, Address: 0x290870, Func Offset: 0x60
	scePrintf("InitSdcParameter - UNIMPLEMENTED!\n");
}

// 100% matching! 
int InitSoundDriver(char* SddFileName, char* MufFileName)
{ 
    unsigned int* Address;
    int FileSize;

    FileSize = GetFileSize(SddFileName);
    
    Address = syMalloc(FileSize); 
    
    QuickGetDiscTrayStatus(); 
    
    if (ReadFileEx(SddFileName, Address) != 0) 
    { 
        ExitApplication(); 
    }
    
    SetupSoundDriver(Address, FileSize); 
    
    syFree(Address); 
    
    if (MufFileName != NULL)
    { 
        FileSize = GetFileSize(MufFileName); 
        
        Address = syMalloc(FileSize); 
        
        QuickGetDiscTrayStatus(); 
        
        if (ReadFileEx(MufFileName, Address) != 0)
        { 
            ExitApplication(); 
        }
        
        SetMultiUnit(Address, FileSize); 
        
        syFree(Address); 
    }
    
    InitSdcParameter(); 
    
    return 0; 
} 
