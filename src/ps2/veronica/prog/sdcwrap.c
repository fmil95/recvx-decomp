// TODO: compile and link this file separatedly to remove the "sdcwrap.c" include in main.c  

int GdDaPlayFlag;
unsigned int SddFirstFlag;
char SdcGdDaVolume;

void InitSdcParameter();
int InitSoundDriver(char* SddFileName, char* MufFileName);

// 100% matching!
void InitSdcParameter()
{ 
    SetSoundMode(GetSoundMode()); 
    
    SetMasterVolume(15); 
    SetGdDaVolume(127); 
    SetMidiDefaultVolume(0); 
    SetSeDefaultVolume(0); 
    
    InitMidiInfo();
    InitSeInfo(); 
    
    SddFirstFlag = 1; 
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
