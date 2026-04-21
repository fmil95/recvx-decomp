#ifndef _FILEVIEW_H_
#define _FILEVIEW_H_

#include "types.h"

void ControlFileView();
void FileSelect();
void FileFlagInit01();
void FileFlagInit();
void GetFile();
void FileViewInit();
void FileViewMain();
void FileViewExit();
void FileExit00();
void FileExit01();
int SearchTag(int dir);
void SelectFile();
void SelectTag();
void FileScreenCancel();
void FileScrollSet();
void FileGetWait();
void PageScroll();
void FileEtcDisplay();
void StatusToFileView();
void ReadFstx();
unsigned int FileNumberSwitch(unsigned int num);
int PlayPageCheck();

extern FV_WORK fvwork;

#endif
