#ifndef _PS2_SNDDRV_H_
#define _PS2_SNDDRV_H_

#include "types.h"
#include "macros.h"

static void wait_alarm(int id, unsigned short time, int thid);
int SdrDelayThread(int hsync);
static void sdr_initQue();
static int sdr_initDev(sceSifClientData* cd_p, unsigned int dev);
int SdrInit();
int SdrSeReq(int req, char vol, char pan, short pitch);
int SdrSeCancel(int req);
int SdrSeChg(int req, char vol, char pan, short pitch);
int SdrSeAllStop();
int SdrMasterVol(unsigned short mvol);
int SdrBgmReq(unsigned char port, unsigned char bank, unsigned char vol, unsigned char block);
int SdrBgmStop(unsigned char port);
int SdrBgmChg(int req, char vol, char pan, short pitch);
int SdrHDDataSet(int port, int size);
int SdrHDDataSet2(int port, int size);
int SdrBDDataSet(int port);
int SdrBDDataSet2(int port);
int SdrBDDataTrans(int port, int adrs, int size, int flag);
int SdrSQDataSet(int port, int size);
int SdrSetIopData();
int SdrSetOutputMode(int mode);
int SdrSetRev(unsigned int core, unsigned int mode, short depth, unsigned char delay, unsigned char feedback);
int SdrSendReq(int mode);
static void cb_sifRpc(int smid);
static void cb_sifRpc_snd(int smid);
int SdrGetStateSend(int command, int data);
int SdrGetStateReceive(int mode);
int SdrGetState(int command, int data);
static int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch);
static int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7);
static int makebuff(unsigned int cmd, int n);
static int makebuff_ext(unsigned int cmd, int n, int limit);
static int sending_req(SNDQUE* sq_p);
int get_iopsnd_info();

extern int iop_data_buff;
extern SND_STATUS get_iop_snddata;

#endif
