#ifndef _EXPAND_H_
#define _EXPAND_H_

#include "types.h"

// TODO: these structs need to be refactored, some of them are actually unions
typedef struct BUF_QUEUE 
{
    // total size: 0x8
    char* from;        // offset 0x0, size 0x4
    unsigned char* to; // offset 0x4, size 0x4     
} BUF_QUEUE;

typedef struct EXPAND_STATUS 
{
    // total size: 0x2
    char active; // offset 0x0, size 0x1
    char mode;   // offset 0x1, size 0x1              
} EXPAND_STATUS;

typedef union EXPAND_CTRL 
{
    EXPAND_STATUS sb; // offset 0x0, size 0x2    
    short check;      // offset 0x0, size 0x2              
} EXPAND_CTRL;

typedef union EXPAND_FLAG
{
    struct 
    {
        EXPAND_CTRL uw; // offset 0x0, size 0x2
        char in;        // offset 0x2, size 0x1
        char out;       // offset 0x3, size 0x1            
    } sl;               // offset 0x0, size 0x4
    int abort;          // offset 0x0, size 0x4              
} EXPAND_FLAG;

typedef struct EXPAND_CTRL_BUF
{
    // total size: 0x2C
    EXPAND_FLAG flag;           // offset 0x0, size 0x4 
    int code;                   // offset 0x4, size 0x4
    int counter;                // offset 0x8, size 0x4
    int repeat;                 // offset 0xC, size 0x4
    unsigned char* offset;      // offset 0x10, size 0x4
    char* source;               // offset 0x14, size 0x4
    unsigned char* destination; // offset 0x18, size 0x4
    BUF_QUEUE que[2];           // offset 0x1C, size 0x10       
} EXPAND_CTRL_BUF;

void Init_Expand();
int Expand(register char* s, register unsigned char* d);

#endif
