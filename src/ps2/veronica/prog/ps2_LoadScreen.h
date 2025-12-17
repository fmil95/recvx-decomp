#ifndef _PS2_LOADSCREEN_H_
#define _PS2_LOADSCREEN_H_

LOAD_SCREEN* CreateLoadScreen(LOAD_SCREEN* pLoad, void* vpWorkPtrSys);
void DispLoadMessageSelect(char cSelectMes);
void DispLoadTexture(LOAD_SCREEN* pLoad);
int ExecuteLoadScreen(LOAD_SCREEN* pLoad);
void SetStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenTitleExit(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenTitleExit(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad);
void SetStateLoadScreenDirCheck(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirCheck(LOAD_SCREEN* pLoad);
void SetStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectFile(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectFile(LOAD_SCREEN* pLoad);
void LoadScreenCheckSave(LOAD_SCREEN* pLoad);
void SetStateLoadScreenNoSave(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenNoSave(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoad(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoad(LOAD_SCREEN* pLoad);
void SetStateLoadScreenFileBroken(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenFileBroken(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadExit(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadExit(LOAD_SCREEN* pLoad);
void SetDispLoadSelectMessage();
void CheckDispLoadMemoryCard(LOAD_SCREEN* pLoad);

#endif
