#ifndef _GDLIB_H_
#define _GDLIB_H_

void LfInitLib();
void CallbackGdErrorFunc(int param, int err);
unsigned int InitGdSystem();
unsigned int InitGdSystemEx(unsigned int MaxDirNum);
void ExitGdSystem();
int GetFileSize(char* FileName);
int ReadFileEx(char* FileName, void* ReadAddress);
unsigned int CheckOpenTray();

extern unsigned int StatusUpdateCounter;
extern unsigned int DiscOpenTrayFlag;

#endif
