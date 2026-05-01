#ifndef _EFFSUB0_H_
#define _EFFSUB0_H_

#include "types.h"

typedef struct EFF0UV 
{
    // total size: 0x4
    short u; // offset 0x0, size 0x2
    short v; // offset 0x2, size 0x2
} EFF0UV;

typedef struct EFF0UVWHUC 
{
    // total size: 0x4
    unsigned char u; // offset 0x0, size 0x1
    unsigned char v; // offset 0x1, size 0x1
    unsigned char w; // offset 0x2, size 0x1
    unsigned char h; // offset 0x3, size 0x1
} EFF0UVWHUC;

int setentry(unsigned short id, unsigned short type, O_WRK* op);
void effinit(O_WRK* op);
void effset(O_WRK* op, UV_WORK* uvp, unsigned short num);
void getuv(unsigned char type, O_WRK* op);
void bhEff150(O_WRK* op);
void bhEff151(O_WRK* op);
void bhEff152(O_WRK* op);
void bhEff153(O_WRK* op);
void bhEff154(O_WRK* op);
void bhEff155(O_WRK* op);
void bhEff156(O_WRK* op);
void bhEff157(O_WRK* op);
void bhEff158(O_WRK* op);
void bhEff159(O_WRK* op);
void bhEff160(O_WRK* op);
void bhEff161(O_WRK* op);
void bhEff162(O_WRK* op);
void bhEff163(O_WRK* op);
void bhEff164(O_WRK* op);
void bhEff165(O_WRK* op);
void bhEff166(O_WRK* op);
void bhEff167(O_WRK* op);
void bhEff168(O_WRK* op);
void bhEff169(O_WRK* op);
void bhEff170(O_WRK* op);
void bhEff171(O_WRK* op);
void bhEff172(O_WRK* op);
void bhEff173(O_WRK* op);
void bhEff174();
void bhEff175(O_WRK* op);
void bhEff176(O_WRK* op);
void bhEff177(O_WRK* op);
void bhEff178(O_WRK* op);
void bhEff179(O_WRK* op);
void bhEff180(O_WRK* op);
void bhEff181(O_WRK* op);
void bhEff182(O_WRK* op);
void bhEff183(O_WRK* op);
void bhEff184(O_WRK* op);
void bhEff185(O_WRK* op);
void bhEff186(O_WRK* op);
void bhEff187(O_WRK* op);
void bhEff188(O_WRK* op);
void bhEff189(O_WRK* op);
void bhEff190(O_WRK* op);
void bhEff191(O_WRK* op);
void bhEff192(O_WRK* op);
void bhEff193(O_WRK* op);
void bhEff194(O_WRK* op);
void bhEff195(O_WRK* op);
void bhEff196(O_WRK* op);
void bhEff197();
void bhEff198(O_WRK* op);
void bhEff199();

#endif
