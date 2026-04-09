#ifndef _ITEM_H_
#define _ITEM_H_

#include "types.h"

typedef struct ITEM_WORK 
{
    // total size: 0x6
    unsigned short max;  // offset 0x0, size 0x2
    short cmb;           // offset 0x2, size 0x2
    unsigned short type; // offset 0x4, size 0x2
} ITEM_WORK;

typedef struct DSP_WORK 
{
    // total size: 0x8
    short ax;   // offset 0x0, size 0x2
    short ay;   // offset 0x2, size 0x2
    short az;   // offset 0x4, size 0x2
    short hide; // offset 0x6, size 0x2
} DSP_WORK;

extern const unsigned int getbulletmax[156][4];
extern const NJS_POINT3 hoseipos[10];
extern const unsigned short idsettbl[16];
extern const unsigned short getmestbl[16];
extern const unsigned short itemidtbl[16];
extern const unsigned char itemflg[41][8];
extern const unsigned short mestbl[14];
extern const short c_a[14][6];
extern const unsigned char curedata[10];
extern const DSP_WORK dsptbl[160];
extern const ITEM_WORK itemdata[156];
extern const short combidata[410];

#endif
