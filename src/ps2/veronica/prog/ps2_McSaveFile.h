#ifndef _PS2_MCSAVEFILE_H_
#define _PS2_MCSAVEFILE_H_

#include "types.h"

SELECTFILEINFO* mcSelectFileInfoInit(SELECTFILEINFO* pFileInfo);
SAVEFILE* mcCreateSaveFileInit(SAVEFILE* pSaveFile);
CONFIGFILE* mcCreateConfigInit(CONFIGFILE* pConfigFile);
int mcGetSaveFileCapacitySize();
int mcReadStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount);
int mcCheckReadStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char cMode);
int mcWriteStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount);
int mcCheckWriteStartSaveFile(MEMORYCARDSTATE* pCard);
int mcNewCreateSaveFile(MEMORYCARDSTATE* pCard, SAVEFILE* pSaveFile, char** cppFileName, unsigned int ulCreatSaveCount);
int mcGetConfigCapacitySize();
int mcReadStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile);
int mcCheckReadStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile);
int mcWriteStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile);
int mcCheckWriteStartConfigFile(MEMORYCARDSTATE* pCard);
int mcNewCreateConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile);
ICONINFORMATION* mcCreateIconInit(ICONINFORMATION* pIcon, char** cppFileName, unsigned int ulFileNamber);
int mcGetIconCapacitySize();
int mcGetIconFileCapacitySize();
int mcNewCreateIcon(ICONINFORMATION* pIcon, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount);
int mcReadIconData(void* vpReadAddr, char** cppIconFileName, int lFileNum);
int mcWriteIconData(MEMORYCARDSTATE* pCard, void* vpWriteAddr, unsigned int ulDataSize, char** cppFileName, unsigned int ulCreatSaveCount);
int mcGetFreeCapacitySize();
void mcGetPortSelectDirInfo(SAVEFILE* pSaveFile, SELECTFILEWINDOW* pWin, unsigned int ulCheckCounter);
int mcSelectSaveFileCheck(SELECTFILEWINDOW* pWin, unsigned short ulSaveCount);
SELECTFILEWINDOW* mcCreateFileSelectWindow(SELECTFILEWINDOW* pWin, SELECTFILEINFO* pFileInfo, unsigned int ulRecord);
void mcSetFileSelectWindowCursolInit(SELECTFILEWINDOW* pWin);
void mcSetFileSelectWindowCursol(SELECTFILEWINDOW* pWin, int lCurInfo);
int mcGetFileSelectWindowCursol(SELECTFILEWINDOW* pWin);
void mcDisplayFileSelectWindow(SELECTFILEWINDOW* pWin, float fX, float fY, unsigned int port);
void mcMoveFileSelectWindowCursor(SELECTFILEWINDOW* pWin, short slCur);
void mcDisplaySelectFileInfo(SELECTFILEINFO* pFileInfo, float fx, float fy);
void mcDisplaySelectFileInfoMesCount(SELECTFILEINFO* pFileInfo, float fx, float fy, unsigned int CountMes);
void mcCallMessageTypeSe(SELECTFILEINFO* pFileInfo, int CountMes);
void mcDispFileNumber(SELECTFILEINFO* pFileInfo, float fx, float fy);
void mcDispFileName(SELECTFILEINFO* pFileInfo, float fy);
void mcSetTyepWriteMode(SELECTFILEWINDOW* pWin, unsigned int SetState);
int mcSetStringSaveFile(SELECTFILEINFO* pFileInfo);
int mcGetStringEnd(SELECTFILEWINDOW* pWin, unsigned short usSaveEnd);
void mcDispWindowCurSol(SELECTFILEWINDOW* pWin, float fx, float fy);
void DispCursolTexture(float pos_x, float pos_y, unsigned int color);
void DispUpDownCursol(float fx, float fy, unsigned int mode);
void DispBackGroundTexture();
void DispMemoryCardTexture(float fx, float fy, unsigned int type, unsigned int mode);
void mcDispWindowFoundtion(float fx, float fy, float fSizeW, float fSizeH, unsigned int Argb);

#endif
