#ifndef _PS2_SG_PAD_H_
#define _PS2_SG_PAD_H_

#include "types.h"

typedef struct PAD_WORK
{
	// total size: 0x42
    unsigned short on;      // offset 0x0, size 0x2
    unsigned short old;     // offset 0x2, size 0x2
    unsigned short push;    // offset 0x4, size 0x2
    unsigned short release; // offset 0x6, size 0x2
    short send;             // offset 0x8, size 0x2
    unsigned short ad_flag; // offset 0xA, size 0x2
    unsigned char buff[2];  // offset 0xC, size 0x2
    unsigned short onon;    // offset 0xE, size 0x2
    unsigned short repeat;  // offset 0x10, size 0x2
    char time1[16];         // offset 0x12, size 0x10
    char time2[16];         // offset 0x22, size 0x10
    unsigned char rh;       // offset 0x32, size 0x1
    unsigned char rv;       // offset 0x33, size 0x1
    unsigned char lh;       // offset 0x34, size 0x1
    unsigned char lv;       // offset 0x35, size 0x1
    unsigned char au;       // offset 0x36, size 0x1
    unsigned char ad;       // offset 0x37, size 0x1
    unsigned char al;       // offset 0x38, size 0x1
    unsigned char ar;       // offset 0x39, size 0x1
    unsigned char abu;      // offset 0x3A, size 0x1
    unsigned char abd;      // offset 0x3B, size 0x1
    unsigned char abl;      // offset 0x3C, size 0x1
    unsigned char abr;      // offset 0x3D, size 0x1
    unsigned char al1;      // offset 0x3E, size 0x1
    unsigned char al2;      // offset 0x3F, size 0x1
    unsigned char ar1;      // offset 0x40, size 0x1
    unsigned char ar2;      // offset 0x41, size 0x1
} PAD_WORK;

typedef struct PAD_INFO
{
    // total size: 0x84
	PAD_WORK pad1; // offset 0x0, size 0x42
	PAD_WORK pad2; // offset 0x42, size 0x42
} PAD_INFO;

typedef struct PAD_STATUS
{
	// total size: 0x12
    unsigned short routine_0;  // offset 0x0, size 0x2
    unsigned short type;       // offset 0x2, size 0x2
    unsigned short act_lv[2];  // offset 0x4, size 0x4
    unsigned short be_flag;    // offset 0x8, size 0x2
    unsigned char act_data[8]; // offset 0xA, size 0x8
} PAD_STATUS;

typedef struct BUTTON_INFO
{
	// total size: 0x8
    int Type;            // offset 0x0, size 0x4
    unsigned int Button; // offset 0x4, size 0x4
} BUTTON_INFO;

void pdInitPeripheral(Sint32 logic, void* recvbuf, void* sendbuf);
void pdExitPeripheral(void);
const PDS_PERIPHERAL* pdGetPeripheral(Uint32 port);
const PDS_PERIPHERALINFO* pdGetPeripheralInfo(Uint32 port);
void pdSetMode(Sint32 mode);
void Ps2_pad_read();
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk);
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk);
static void Pad_set(PAD_WORK* pbt, unsigned short pad_num);
void Pad_init();

extern PAD_INFO Ps2_pad;

#endif
