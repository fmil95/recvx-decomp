#ifndef _FACE_H_
#define _FACE_H_

#include "types.h"

typedef struct HEAD_WORK 
{
    // total size: 0x40
    char id[4];              // offset 0x0, size 0x4
    unsigned short version;  // offset 0x4, size 0x2
    unsigned short flag;     // offset 0x6, size 0x2
    unsigned short jawId[2]; // offset 0x8, size 0x4
    unsigned int nAttr;      // offset 0xC, size 0x4
    unsigned int nList;      // offset 0x10, size 0x4
    unsigned int nConnect;   // offset 0x14, size 0x4
    unsigned int nJaw;       // offset 0x18, size 0x4
    unsigned int nTang;      // offset 0x1C, size 0x4
    unsigned int nFace;      // offset 0x20, size 0x4
    unsigned int reserve[4]; // offset 0x24, size 0x10
    char faceId;             // offset 0x34, size 0x1
    char tangId;             // offset 0x35, size 0x1
    char toothId;            // offset 0x36, size 0x1
    char eyeId[9];           // offset 0x37, size 0x9
} HEAD_WORK;

typedef struct LIST_WORK
{
    // total size: 0x14
    int id;         // offset 0x0, size 0x4
    NJS_POINT3 vec; // offset 0x4, size 0xC
    float scal;     // offset 0x10, size 0x4
} LIST_WORK;

typedef struct VLIST_WORK
{
    // total size: 0x4
    short id;   // offset 0x0, size 0x2
    char mnum;  // offset 0x2, size 0x1
    char nvnum; // offset 0x3, size 0x1
} VLIST_WORK;

typedef struct TANG_WORK
{
    // total size: 0x8
    int id;     // offset 0x0, size 0x4
    float rate; // offset 0x4, size 0x4
} TANG_WORK;

typedef struct PARAM_WORK
{
    // total size: 0xA4
    float muscle[32]; // offset 0x0, size 0x80
    float jawang;     // offset 0x80, size 0x4
    float jawtrans;   // offset 0x84, size 0x4
    NJS_POINT3 eye;   // offset 0x88, size 0xC
    float tangx;      // offset 0x94, size 0x4
    float tangy;      // offset 0x98, size 0x4
    float tangz;      // offset 0x9C, size 0x4
    short frame;      // offset 0xA0, size 0x2
    short flag;       // offset 0xA2, size 0x2
} PARAM_WORK;

typedef struct MASK_WORK
{
    // total size: 0x740
    NJS_CNK_MODEL* src;        // offset 0x0, size 0x4
    NJS_CNK_MODEL* dst;        // offset 0x4, size 0x4
    LIST_WORK* list;           // offset 0x8, size 0x4
    VLIST_WORK* vlist;         // offset 0xC, size 0x4
    NJS_POINT3* nvpt;          // offset 0x10, size 0x4
    int lnum;                  // offset 0x14, size 0x4
    NJS_CNK_OBJECT* obj;       // offset 0x18, size 0x4
    TANG_WORK* jaw;            // offset 0x1C, size 0x4
    int jnum;                  // offset 0x20, size 0x4
    unsigned int Dummy[3];     // offset 0x24, size 0xC
    NJS_MATRIX jmat1;          // offset 0x30, size 0x40
    NJS_MATRIX jmat2;          // offset 0x70, size 0x40
    PARAM_WORK param;          // offset 0xB0, size 0xA4
    NJS_CNK_OBJECT eye[9];     // offset 0x154, size 0x1D4
    NJS_CNK_OBJECT* eyesrc[9]; // offset 0x328, size 0x24
    float eyepos[9][3];        // offset 0x34C, size 0x6C
    int eyeang[9][3];          // offset 0x3B8, size 0x6C
    unsigned int Dummy2[3];    // offset 0x424, size 0xC
    NJS_MATRIX eyemat[9];      // offset 0x430, size 0x240
    TANG_WORK* tang;           // offset 0x670, size 0x4
    int tnum;                  // offset 0x674, size 0x4
    NJS_CNK_MODEL* tangsrc;    // offset 0x678, size 0x4
    NJS_CNK_MODEL* tangdst;    // offset 0x67C, size 0x4
    NJS_CNK_OBJECT tangobj;    // offset 0x680, size 0x34
    NJS_CNK_OBJECT* tangorg;   // offset 0x6B4, size 0x4
    float tangpos[3];          // offset 0x6B8, size 0xC
    int tangang[3];            // offset 0x6C4, size 0xC
    NJS_CNK_OBJECT tooth;      // offset 0x6D0, size 0x34
    NJS_CNK_OBJECT* toothsrc;  // offset 0x704, size 0x4
    float toothpos[3];         // offset 0x708, size 0xC
    int toothang[3];           // offset 0x714, size 0xC
    unsigned int mode;         // offset 0x720, size 0x4
    PARAM_WORK* face;          // offset 0x724, size 0x4
    int fnum;                  // offset 0x728, size 0x4
    int vtype;                 // offset 0x72C, size 0x4
    int vtop;                  // offset 0x730, size 0x4
    int ntop;                  // offset 0x734, size 0x4
    int vofs;                  // offset 0x738, size 0x4
    HEAD_WORK* head;           // offset 0x73C, size 0x4
} MASK_WORK;

typedef struct LIP_WORK 
{
    // total size: 0x10
    unsigned char* top;  // offset 0x0, size 0x4
    unsigned char* ptr;  // offset 0x4, size 0x4
    short cnt;           // offset 0x8, size 0x2
    short time;          // offset 0xA, size 0x2
    unsigned char cur;   // offset 0xC, size 0x1
    unsigned char next;  // offset 0xD, size 0x1
    unsigned short flag; // offset 0xE, size 0x2
} LIP_WORK;

void bhInitMask(BH_PWORK* pp);
void bhControlMask(BH_PWORK* pp);
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no);
int bhSetLip(BH_PWORK* pp, int mls_no);

#endif
