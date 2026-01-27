#ifndef _PS2_EVENT_H_
#define _PS2_EVENT_H_

#include "types.h"

typedef struct EVT_WRK 
{
    // total size: 0x10
    char room;           // offset 0x0, size 0x1
    char rcase;          // offset 0x1, size 0x1
    char evc_no;         // offset 0x2, size 0x1
    char flag;           // offset 0x3, size 0x1
    char ev_flag;        // offset 0x4, size 0x1
    unsigned int col;    // offset 0x8, size 0x4
    unsigned int ev_col; // offset 0xC, size 0x4
} EVT_WRK; 

void bhChangeBackColor();
void bhChangeBackColorEvt();

extern unsigned char BackColorFlag;

#endif
