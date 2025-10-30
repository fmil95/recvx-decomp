#include "ps2_snddrv.h"

static unsigned char sbuff[512] __attribute__((aligned(64)));
static unsigned int getbuff[4] __attribute__((aligned(64)));
static sceSifClientData ClientData;
static sceSifClientData GetStClientData;
static volatile int sque_r_idx;
static SND_QUE sndque_tbl[128];
static int sque_w_idx;
static int sbuff_idx;
static int ThId_send;
static int SmId_send = -1;
static int SmId_get = -1;
int SendReqFlag;
static unsigned char Stack_send[2048]; /* unused */
unsigned int IOP_hd_size[16] = { 1792, 768, 12288, 2816, 2560, 2816, 6144, 768, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned int IOP_tq_size[16] = { 0, 512, 8192, 3072, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int iop_data_buff;
int iop_data_adr[16];
int iop_sq_adr[16];
int iop_hd_adr[16];
int iop_data_adr_top;
int get_adrs;
//void* _gp; /* enabling this makes the emulator go potty, and is otherwise unused */
SND_STATUS get_iop_buff;
SND_STATUS get_iop_snddata;

static void wait_alarm(int id, unsigned short time, int thid);
int SdrDelayThread(int hsync);
static void sdr_initQue();
static int sdr_initDev(sceSifClientData* cd_p, unsigned int dev);
int SdrInit();
int SdrSeReq(int req, char vol, char pan, short pitch);
int SdrSeCancel(int req);
int SdrSeChg(int req, char vol, char pan, short pitch);
/*int SdrSeAllStop();
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
int SdrSendReq(int mode);*/
void cb_sifRpc(int smid);
void cb_sifRpc_snd(int smid);
/*int SdrGetStateSend(int command, int data);
int SdrGetStateReceive(int mode);
int SdrGetState(int command, int data);
int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch);
int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7);
int makebuff(unsigned int cmd, int n);
int makebuff_ext(unsigned int cmd, int n, int limit);*/
int sending_req(SND_QUE* sq_p);
int get_iopsnd_info();

// 100% matching!
static void wait_alarm(int id, unsigned short time, int thid)
{ 
	iWakeupThread(thid); 
    
	ExitHandler(); 
} 

// 100% matching!
int SdrDelayThread(int hsync)
{ 
	if (SetAlarm(hsync, (AlarmCallBack)wait_alarm, (void*)GetThreadId()) < 0) 
    { 
        printf("SDR: SdrDelayThread: Error: SetAlarm faild.\n"); 
        
		return -2;
	}
    
	return SleepThread(); 
} 

// 100% matching!
static void sdr_initQue()
{
	int i;

	sbuff_idx = 0; 
    
	sque_w_idx = sque_r_idx = 0; 
    
	for (i = 127; i >= 0; sndque_tbl[i--].cmd = -1); 
} 

// 100% matching!
static int sdr_initDev(sceSifClientData* cd_p, unsigned int dev)
{
	int	i;
    
	for (i = 1024; i > 0; i--) 
    { 
		if (sceSifBindRpc(cd_p, dev, 0) < 0) 
        {
            return -1;
        }
		
        if (cd_p->serve != NULL) 
        {
            break; 
        }
        
		printf("SDR:  BindRpc: Just wait.\n"); 
		
        if (SdrDelayThread(1) < 0) 
        {
            return -1;
        }
	} 
    
	return 0; 
} 

void CpEEWait(int val); // TODO: remove this function declaration
// 99.91% matching
int SdrInit() 
{
    static int flag_1st = 0; 
    int id;
    struct SemaParam sem;
    sceSifReceiveData rd;

    if (flag_1st != 0) 
    {
        return 0;
    }
    
    sdr_initQue();
    
    id = sdr_initDev(&ClientData, 0);
    
    if (id < 0) 
    {
        printf("SDR: SdrInit: Error: TSNDDRV_DEV: sceSifBindRpc faild.\n");
        
        return -1;
    }
    
    id = sdr_initDev(&GetStClientData, 1);
    
    if (id < 0)
    {
        printf("SDR: SdrInit: Error: TSNDGET_DEV: sceSifBindRpc faild.\n");
        
        return -1;
    }
    
    sem.initCount = 1;
    sem.maxCount = 1;
    
    sem.option = 0;
    
    if (SmId_send < 0) 
    {
        id = CreateSema(&sem);
        
        if (id <= 0) 
        {
            printf("SDR: SdrInit: Error: SmId_send faild.\n");
            
            return -1;
        }
        
        SmId_send = id;
    }

    if (SmId_get < 0)
    {
        id = CreateSema(&sem);
        
        if (id <= 0) 
        {
            printf("SDR: SdrInit: Error: SmId_get faild.\n");
            
            return -1;
        }
        
        SmId_get = id;
    }
    
    flag_1st = 1;
    
    do 
    {
        get_adrs = SdrGetState(18, 0);
    } while ((get_adrs <= 0) || (get_adrs >= 0x200000));
    
    iop_data_adr_top = SdrGetState(19, 0);

    while (sceSifGetOtherData(&rd, (void*)iop_data_adr_top, (void*)iop_data_adr, 64, 0) != 0)
    {
        CpEEWait(1000);
    }
    
    iop_hd_adr[0] = iop_data_adr[0];
    
    iop_hd_adr[1] = iop_hd_adr[0] + IOP_hd_size[0];
    iop_hd_adr[2] = iop_hd_adr[1] + IOP_hd_size[1]; 
    iop_hd_adr[3] = iop_hd_adr[2] + IOP_hd_size[2];
    iop_hd_adr[4] = iop_hd_adr[3] + IOP_hd_size[3];
    iop_hd_adr[5] = iop_hd_adr[4] + IOP_hd_size[4];
    iop_hd_adr[6] = iop_hd_adr[5] + IOP_hd_size[5];
    iop_hd_adr[7] = iop_hd_adr[6] + IOP_hd_size[6];
    
    iop_sq_adr[0] = iop_data_adr[1];
    
    iop_sq_adr[1] = iop_sq_adr[0] + IOP_tq_size[0];
    iop_sq_adr[2] = iop_sq_adr[1] + IOP_tq_size[1];
    iop_sq_adr[3] = iop_sq_adr[2] + IOP_tq_size[2];
    iop_sq_adr[4] = iop_sq_adr[3] + IOP_tq_size[3];
    iop_sq_adr[5] = iop_sq_adr[4] + IOP_tq_size[4];
    iop_sq_adr[6] = iop_sq_adr[5] + IOP_tq_size[5];
    iop_sq_adr[7] = iop_sq_adr[6] + IOP_tq_size[6];
    
    iop_data_buff = iop_data_adr[2];

    return 0;
}

// 100% matching!
int SdrSeReq(int req, char vol, char pan, short pitch)
{ 
	char temp; // not from the debugging symbols
    
	if (sndque_tbl[sque_w_idx].cmd >= 0) 
    { 
		printf("SDR: SdrSeReq: Warning: sndque overflow!\n"); 
        
		return -1; 
	}
    
	temp = CheckCmdReq((vol >= 0) ? 1 : 0, (pan >= 0) ? 1 : 0, (pitch >= 0) ? 1 : 0); 
    
    sndque_tbl[sque_w_idx].cmd = (temp << 24) | (req & 0xFFFFFF); 
    
	sndque_tbl[sque_w_idx].vol = vol; 
    
	sndque_tbl[sque_w_idx].pan = pan; 
    
	sndque_tbl[sque_w_idx].pitch = pitch; 

	sque_w_idx = ++sque_w_idx % 128; 

	return 0; 
} 

// 100% matching!
int SdrSeCancel(int req) 
{
    if (sndque_tbl[sque_w_idx].cmd >= 0) 
    {
        printf("SDR: SdrSeCancel: Warning: sndque overflow!\n");
        
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = 0x8000000 | (req & 0xFFFFFF);
    
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrSeChg(int req, char vol, char pan, short pitch)
{
	char temp; // not from the debugging symbols

	if (sndque_tbl[sque_w_idx].cmd >= 0)
    {
		printf("SDR: SdrSeChg: Warning: sndque overflow!\n");
        
		return -1;
	}

	temp = CheckCmdChg((vol >= 0) ? 1 : 0, (pan >= 0) ? 1 : 0, (pitch >= 0) ? 1 : 0);

	if (temp == (0 | 8)) 
    {
        return 1;
    }

	sndque_tbl[sque_w_idx].cmd = (temp << 24) | (req & 0xFFFFFF);
    
	sndque_tbl[sque_w_idx].vol = vol;
    
	sndque_tbl[sque_w_idx].pan = pan;
    
	sndque_tbl[sque_w_idx].pitch = pitch;

	sque_w_idx = ++sque_w_idx % 128;

	return 0;
}

// 100% matching!
int SdrSeAllStop() {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrSeAllStop: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = (0x10000000);
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrMasterVol(unsigned short mvol) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrMasterVol: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = (0x4B000000 | ((mvol << 0x8) & 0xFFFFFF));
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrBgmReq(unsigned char port, unsigned char bank, unsigned char vol, unsigned char block) {

    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrBgmReq: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd =  ((port << 16) & 0xFFFFFF)  | ((bank << 8) & 0xFFFFFF) | (vol & 0xFFFFFF) | 0x20000000;
    *(unsigned char*)(&sndque_tbl[sque_w_idx].vol) = block;
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrBgmStop(unsigned char port) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrBgmStop: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = (0x21000000 | ((port << 0x10) & 0xFFFFFF));
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrBgmChg(int req, char vol, char pan, int pitch) {

    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrBgmChg: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = ((req << 16) & 0xFFFFFF) | 0x27000000;
    sndque_tbl[sque_w_idx].vol = vol;
    sndque_tbl[sque_w_idx].pan = pan;
    sndque_tbl[sque_w_idx].pitch = ((pitch & 0x3F80) << 1) | (pitch & 0x7F);
    
    sque_w_idx = ++sque_w_idx % 128;
    return 0;
}

// 100% matching!
int SdrHDDataSet(int port, int size) {
    
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = ((port << 16) & 0xFFFFFF) | 0x28000000;
    *(int*)(&sndque_tbl[sque_w_idx].vol) = size; 
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrHDDataSet2(int port, int size) {

    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = ((port << 16) & 0xFFFFFF) | 0x29000000;
    *(int*)(&sndque_tbl[sque_w_idx].vol) = size; 
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrBDDataSet(int port) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = (0x2A000000 | ((port << 0x10) & 0xFFFFFF));
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrBDDataSet2(int port) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = (0x2B000000 | ((port << 0x10) & 0xFFFFFF));
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching
int SdrBDDataTrans(int port, int adrs, int size, int flag) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = ((((adrs & 0xFF) << 8 | ((port & 0x7F) << 16 | flag << 23)))  | (adrs & 0xFF00) >> 8) & 0xFFFFFF | 0x2C000000;
    *(int*)&sndque_tbl[sque_w_idx].vol = (size & 0xFFFFFF) << 8 | (adrs & 0xFF0000) >> 16;

    sque_w_idx = ++sque_w_idx % 128;

    return 0;
}

// 100% matching!
int SdrSQDataSet(int port, int size) {

    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrLoadReq: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = ((port << 16) & 0xFFFFFF) | 0x2D000000;
    *(int*)(&sndque_tbl[sque_w_idx].vol) = size; 
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching
int SdrSetIopData() {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrSetIopData: Warning: sndque overflow!\n");
        return -1;
    }

    sndque_tbl[sque_w_idx].cmd = 0x2F000000;
    sndque_tbl[sque_w_idx].vol= 0;
    sndque_tbl[sque_w_idx].pan= 0;
    sndque_tbl[sque_w_idx].pitch= 0;
    
    sque_w_idx = ++sque_w_idx % 128;
    return 0;
    
}

// 100% matching!
int SdrSetOutputMode(int mode) {
    int temp;
    
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrSetOutputMode: Warning: sndque overflow!\n");
        return -1;
    }
    
    temp = (mode != 0) ? 1 :  0;
    sndque_tbl[sque_w_idx].cmd = 0x42000000 | ((temp << 16) & 0xFFFFFF);
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrSetRev(unsigned int core, unsigned int mode, short depth, unsigned char delay, unsigned char feedback) {
    SND_QUE_DATA* sqd_p;
    
    if (core > 2) {
        printf("SDR: SdrSetRev: Error: core invalid.\n");
        return -3;
    }
    
    if (mode >= 10) {
        printf("SDR: SdrSetRev: Error: mode invalid.\n");
        return -2;
    }

    
    sqd_p = (SND_QUE_DATA*)&sndque_tbl[sque_w_idx];
    if (sqd_p->cmd >= 0) {
        printf("SDR: SdrSetRev: Warning: sndque overflow!\n");
        return -1;
    }

    mode = (mode | ++core << 6);
    sqd_p->cmd = 0x44000000 | (mode << 16 | depth & 0xFFFF) & 0xFFFFFF;
    sqd_p->data[0] = delay;
    sqd_p->data[1] = feedback;
    
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 100% matching!
int SdrSendReq(int mode) {
    int r_idx;
    int dma_size;
    
    if (mode != 0) {
        if (PollSema(SmId_send) < 0) {
            return -1;
        }
    } else {
        WaitSema(SmId_send);
    }
    
    r_idx = sque_r_idx;
    
    while (sndque_tbl[r_idx].cmd >= 0) {
        if (sending_req(&sndque_tbl[r_idx]) < 0) {
            printf("SDR: SdrSendReq: Caution: sbuff overflow.\n     I carry forward the request to next time.\n");
            break;
        }
        
        sndque_tbl[r_idx].cmd = -1;
        r_idx = ++r_idx % 128;
    }
    
    sque_r_idx = r_idx;
    
    if (sbuff_idx != 0) {
        dma_size = (sbuff_idx + 0x10) & -0x10;
        if (mode != 0) {
            mode = 1;
        }
        
        if (sceSifCallRpc(&ClientData, 0, mode, (void*)&sbuff, dma_size, (void*)&sbuff, 0,(sceSifEndFunc)&cb_sifRpc_snd, (void*)SmId_send) < 0) {
            printf("SDR: SdrSendReq: Error: Rpc faild.\n");
            SignalSema(SmId_send);
            return -1;
        }
        
        sbuff_idx = 0;
        if (mode != 0) {
            SendReqFlag = 1;
        }
    } else {
        SignalSema(SmId_send);
    }
    
    return 0;
}

// 100% matching!
static void cb_sifRpc(int smid)
{
    iSignalSema(smid);
}

// 100% matching!
static void cb_sifRpc_snd(int smid)
{
    iSignalSema(smid);
    
    SendReqFlag = 0;
}

// 100% matching!
int SdrGetStateSend(int command, int data) {
      WaitSema(SmId_get);
      getbuff[0] = data;

      if (sceSifCallRpc(&GetStClientData, command, 1, getbuff, 0x10, getbuff, 0x10, (sceSifEndFunc)&cb_sifRpc, (void*)SmId_get) < 0) {
          printf("SDR: SdrGetStateSend: Error: Rpc faild.\n");
          SignalSema(SmId_get);
          return -9;
      }

      return 0;
}

// 100% matching!
int SdrGetStateReceive(int mode) {
    int ret;
    
    if (mode != 0) {
        if (PollSema(SmId_get) < 0) {
            return -1;
        }
    } else {
        WaitSema(SmId_get);
    }
    
    ret = getbuff[0];
    SignalSema(SmId_get);
    return ret;
}

// 100% matching!
int SdrGetState(int command, int data) {
    int ret2;
    int i;
    
    ret2 = SdrGetStateSend(command, data);
    
    if (ret2 < 0) {
        return ret2;
    }

    i = 0;
    do {
        ret2 = SdrGetStateReceive(1);
        if (ret2 != -1) {
            break;
        }
        i++;
    } while (i < 100000);
    
    if (i == 100000) {
        printf("SdrGetState: time out\n");
        SignalSema(SmId_get);
    }
    
    return ret2;
}

// 100% matching!
int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch) {
    int cd;
    int len;
    unsigned char* sb_p;
    
    cd = (cmd >> 24);
    
    len = 4;
    
    if (cd & 0x1) {
        len += 1;
    }
    
    if (cd & 0x2) {
        len += 1;
    }
    
    if (cd & 0x4) {
        len += 2;
    }
    
    if ((sbuff_idx + len) >= 0x200) {
        return -1;
    }
    
    sb_p = &sbuff[sbuff_idx];
    
    *sb_p++ = (cmd >> 24);
    *sb_p++ = (cmd >> 16) & 0xFF;
    *sb_p++ = (cmd >> 8) & 0xFF;
    *sb_p++ = cmd & 0xFF;
    
    if (cd & 0x1) {
        *sb_p++ = vol;
    }
    
    if (cd & 0x2) {
        *sb_p++ = pan;
    }
    
    if (cd & 0x4) {
        *sb_p++ = (pitch >> 8) & 0xFF;
        *sb_p++ = pitch & 0xFF;
    }
    
    sbuff_idx += len;
    
    *sb_p = 0xFF;
    
    return 0;
}

// 100% matching!
int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7) {
    int shift;
    int count;
    
    if (n > 8) {
        printf("SDR: snddrv.c: makebuff8: Error: Length over\n");
        return -1;
    }
    
    if ((sbuff_idx + n) >= 0x200) {
        return -1;
    }
    
    shift = 0x18;
    count = 4;
    
    while (count > 0 && n > 0) {
        sbuff[sbuff_idx] = cmd >> shift;
        sbuff_idx++;
        shift -= 8;
        count--;
        n--;
    }
    
    if (n-- > 0) {
        sbuff[sbuff_idx] = data4;
        sbuff_idx++;
    }
    
    if (n-- > 0) {
        sbuff[sbuff_idx] = data5;
        sbuff_idx++;
    }
    
    if (n-- > 0) {
        sbuff[sbuff_idx] = data6;
        sbuff_idx++;
    }
    
    if (n > 0) {
        sbuff[sbuff_idx] = data7;
        sbuff_idx++;
    }
    
    sbuff[sbuff_idx] = 0xFF;
    
    return 0;
}

// 100% matching!
int makebuff(unsigned int cmd, int n) {
    int shift;
    
    if (n > 4) {
        printf("SDR: snddrv.c: makebuff: Error: Length over\n");
        return -1;
    }

    if ((sbuff_idx + n) >= 0x200) {
        return -1;
    }
    
    shift = 0x18;  
    
    if (n > 0) {
        do {
            sbuff[sbuff_idx] = (cmd >> shift) ;
            sbuff_idx++;
            n--;
            shift -= 8;  
        } while (n > 0);
    }

    sbuff[sbuff_idx] = 0xFF;
    return 0;
}

// 100% matching!
int makebuff_ext(unsigned int cmd, int n, int limit) {
    int shift_n;

    if ((n >= limit) || (n > 4)) {
        printf("SDR: snddrv.c: makebuff_ext: Error: Length invalid\n");
        return -1;
    }
    
    if ((sbuff_idx + limit) >= 0x200) {
        return -1;
    }
    
    shift_n = 0x18;
    
    if (n > 0) {
        do {
            sbuff[sbuff_idx] = cmd >> shift_n;
            sbuff_idx++;
            n--;
            shift_n -= 8;
        } while (n > 0);
    }
    return 0;
}

// 100% matching!
int sending_req(SND_QUE* sq_p) {
    int cd;
    SND_QUE_DATA* sqd_p;

    sqd_p = (SND_QUE_DATA*)sq_p;
    cd = sq_p->cmd >> 0x18;
    
    if (cd == 0x7F) {
        return 0;
    }
    
    if (cd == -1) {
        return 0;
    }
    
    switch (cd & 0xF0) {
    case 0x0:
        return makebuff_tq(sq_p->cmd, sq_p->vol, sq_p->pan, sq_p->pitch);
        
    case 0x10:
        if (cd == 0x11) {
            return makebuff(sq_p->cmd, 3);
        } else {
            return makebuff(sq_p->cmd, 1);
        }
        
    case 0x20:
        if ((cd - 0x22) < 4U) {
            return makebuff(sq_p->cmd, 3);
        }
        
        if (cd == 0x26) {
            return makebuff(sq_p->cmd, 4);
        }
        
        if (cd == 0x20) {
            return makebuff8(sq_p->cmd, 5, sq_p->vol, 0, 0, 0);
        }
        
        if (((cd - 0x27) <= 2U) || ((cd - 0x2C) < 2U)) {
            return makebuff8(sq_p->cmd, 8, sqd_p->data[0], sqd_p->data[1], sqd_p->data[2], sqd_p->data[3]);
        }
        
        return makebuff(sq_p->cmd, 2);
        
    case 0x40:
        if ( (cd - 0x47) <= 3U ||  (cd - 0x41) < 2U) {
            return makebuff(sq_p->cmd, 2);
        }
        
        if (cd == 0x4B) {
            return makebuff(sq_p->cmd, 3);
        }
        
        if (cd == 0x45 || cd == 0x4C) {
            return makebuff(sq_p->cmd, 4);
        }
        
        if (cd == 0x44) {
            return makebuff8(sq_p->cmd, 6, sq_p->vol, sq_p->pan, 0, 0);
        }
        
        if ((cd - 0x4D) < 2U) {
            return makebuff_ext(sq_p->cmd, 3, 0x15);
        }
        
        if (cd == 0x4F) {
            return makebuff8(*(int*)((char*)sq_p+4), 6, (sq_p->cmd >> 8) & 0xFF, sq_p->cmd & 0xFF, 0, 0);
        }
        
        return makebuff(sq_p->cmd, 1);
        
    case 0x60:
    case 0x50:
        if ((cd - 0x51) < 4U) {
            return makebuff8(sq_p->cmd, 8, sqd_p->data[0], sqd_p->data[1], sqd_p->data[2], sqd_p->data[3]);
        }
        else {
            return makebuff(sq_p->cmd, 2);
        }
        
    default:
        printf("SDR: snddrv.c: sending_req: Error: unknown command\n");
        return -1;
    }
}

// 100% matching
int get_iopsnd_info() {
    sceSifReceiveData rd;

    if (!sceSifGetOtherData(&rd, (int*)get_adrs, (void*) (&get_iop_buff), 0x42, 0)) {
        memcpy(&get_iop_snddata, &get_iop_buff, 0x42);
        return 0;
    }
    
    return -1;
}

