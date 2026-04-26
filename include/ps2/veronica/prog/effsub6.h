#ifndef _EFFSUB6_H_
#define _EFFSUB6_H_

#include "types.h"

typedef struct P_WORK
{
    // total size: 0x49C
    unsigned int flg;   // offset 0x0, size 0x4
    unsigned int col;   // offset 0x4, size 0x4
    float sx;           // offset 0x8, size 0x4
    float sy;           // offset 0xC, size 0x4
    int num;            // offset 0x10, size 0x4
    NJS_TEXLIST* txp;   // offset 0x14, size 0x4
    int tex_id;         // offset 0x18, size 0x4
    NJS_POINT3 pos[48]; // offset 0x1C, size 0x240
    NJS_POINT3 vec[48]; // offset 0x25C, size 0x240
} P_WORK;

void bhEff085(O_WRK* op);
void bhEff145(O_WRK* op);
void bhEff146_Init(O_WRK* op);
void bhEff_Sub146(O_WRK* op);
void bhEff147(O_WRK* op);
void bhEff148(O_WRK* op);
void bhEff149(O_WRK* op);
void bhEff144(O_WRK* op);
void bhEff143_sub(O_WRK* op);
void bhEff143(O_WRK* op);

#endif
