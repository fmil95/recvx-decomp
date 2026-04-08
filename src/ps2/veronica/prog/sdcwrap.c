#include "../../../ps2/veronica/prog/sdcwrap.h"
#include "../../../ps2/veronica/prog/gdlib.h"
#include "../../../ps2/veronica/prog/ps2_sg_maloc.h"
#include "../../../ps2/veronica/prog/sdc.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/main.h"

/*int GdDaPlayFlag; - unused */

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
