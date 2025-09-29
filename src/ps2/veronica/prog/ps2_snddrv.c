/*typedef struct _anon0;
typedef struct _sif_serve_data;
typedef struct _sif_receive_data;
typedef struct _sif_client_data;
typedef struct _anon1;
typedef struct _SND_STATUS;
typedef struct _sif_queue_data;
typedef struct ThreadParam;
typedef struct _sif_rpc_data;
typedef struct SemaParam;

typedef void*(*type_2)(unsigned int, void*, int);
typedef void(*type_14)(int, unsigned short, int);
typedef void(*type_15)(int*);
typedef void(*type_17)(int);
typedef void(*type_19)(int);
typedef int(*type_20)();
typedef void(*type_22)(void*);

typedef unsigned char type_0[512];
typedef char type_1[4];
typedef unsigned int type_3[16];
typedef unsigned short type_4[6];
typedef short type_5[8];
typedef short type_6[4];
typedef short type_7[5];
typedef unsigned int type_8[4];
typedef unsigned short type_9[9];
typedef int type_10[2];
typedef int type_11[16];
typedef int type_12[16];
typedef int type_13[16];
typedef unsigned char type_16[2048];
typedef _anon1 type_18[128];
typedef unsigned int type_21[16];

struct _anon0
{
	int cmd;
	char data[4];
};

struct _sif_serve_data
{
	unsigned int command;
	void*(*func)(unsigned int, void*, int);
	void* buff;
	int size;
	void*(*cfunc)(unsigned int, void*, int);
	void* cbuff;
	int csize;
	_sif_client_data* client;
	void* paddr;
	unsigned int fno;
	void* receive;
	int rsize;
	int rmode;
	unsigned int rid;
	_sif_serve_data* link;
	_sif_serve_data* next;
	_sif_queue_data* base;
};

struct _sif_receive_data
{
	_sif_rpc_data rpcd;
	void* src;
	void* dest;
	int size;
};

struct _sif_client_data
{
	_sif_rpc_data rpcd;
	unsigned int command;
	void* buff;
	void* cbuff;
	void(*func)(void*);
	void* para;
	_sif_serve_data* serve;
};

struct _anon1
{
	int cmd;
	char vol;
	char pan;
	short pitch;
};

struct _SND_STATUS
{
	unsigned short se_info[6];
	unsigned short midi_info;
	short port_info[8];
	short midi_sum[4];
	short se_sum[5];
	unsigned short dummy[9];
};

struct _sif_queue_data
{
	int key;
	int active;
	_sif_serve_data* link;
	_sif_serve_data* start;
	_sif_serve_data* end;
	_sif_queue_data* next;
};

struct ThreadParam
{
	int status;
	void* entry;
	void* stack;
	int stackSize;
	void* gpReg;
	int initPriority;
	int currentPriority;
	unsigned int attr;
	unsigned int option;
	int waitType;
	int waitId;
	int wakeupCount;
};

struct _sif_rpc_data
{
	void* paddr;
	unsigned int pid;
	int tid;
	unsigned int mode;
};

struct SemaParam
{
	int currentCount;
	int maxCount;
	int initCount;
	int numWaitThreads;
	unsigned int attr;
	unsigned int option;
};
*/

unsigned char sbuff[512];
unsigned int getbuff[4];
sceSifClientData ClientData;
sceSifClientData GetStClientData;
int sque_r_idx;
SND_QUE sndque_tbl[128];
int sque_w_idx;
int sbuff_idx;
int ThId_send;
int SmId_send = -1;
int SmId_get = -1;
int SendReqFlag;
/*
unsigned char Stack_send[2048];
*/

unsigned int IOP_hd_size[16] = {
    0x00000700,  
    0x00000300,  
    0x00003000,  
    0x00000B00,  
    0x00000A00,  
    0x00000B00,  
    0x00001800,  
    0x00000300,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000   
};

unsigned int IOP_tq_size[16] = {
    0x00000000,  
    0x00000200,  
    0x00002000,  
    0x00000C00,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000   
};
/*
void(*wait_alarm)(int, unsigned short, int);
*/
int iop_data_buff;
int iop_data_adr[16];
int iop_sq_adr[16];
int iop_hd_adr[16];
int iop_data_adr_top;
int get_adrs;
/*void* _gp;
int(*th_sdrSendReq)();
void(*cb_sifRpc_snd)(int);
void(*cb_sifRpc)(int);
void(*cb_sifRpc2)(int*);
*/

SND_STATUS get_iop_buff;
SND_STATUS get_iop_snddata;

/*
void wait_alarm(int thid);
int SdrDelayThread(int hsync);
void sdr_initQue();
int sdr_initDev(_sif_client_data* cd_p, unsigned int dev);
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
*/
void cb_sifRpc(int smid);
void cb_sifRpc_snd(int smid);
/*
int SdrGetStateSend(int command, int data);
int SdrGetStateReceive(int mode);
int SdrGetState(int command, int data);
int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch);
int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7);
int makebuff(unsigned int cmd, int n);
int makebuff_ext(unsigned int cmd, int n, int limit);
*/
int sending_req(SND_QUE* sq_p);
int get_iopsnd_info();

void CpEEWait(int val);

#define	CheckCmdReq(vol, pan, pitch)	(0x00|0|((vol)&1)|(((pan)&1)<<1)|(((pitch)&1)<<2))

// 
// Start address: 0x2e98a0
void wait_alarm(int thid)
{
	// Line 3075, Address: 0x2e98a0, Func Offset: 0
	// Line 3076, Address: 0x2e98a8, Func Offset: 0x8
	// Line 3077, Address: 0x2e98b0, Func Offset: 0x10
	// Line 3078, Address: 0x2e98b8, Func Offset: 0x18
	// Func End, Address: 0x2e98c4, Func Offset: 0x24
	scePrintf("wait_alarm - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2e98d0
int SdrDelayThread(int hsync)
{
	// Line 3097, Address: 0x2e98d0, Func Offset: 0
	// Line 3098, Address: 0x2e98dc, Func Offset: 0xc
	// Line 3100, Address: 0x2e9900, Func Offset: 0x30
	// Line 3101, Address: 0x2e990c, Func Offset: 0x3c
	// Line 3103, Address: 0x2e9914, Func Offset: 0x44
	// Line 3104, Address: 0x2e991c, Func Offset: 0x4c
	// Func End, Address: 0x2e992c, Func Offset: 0x5c
	scePrintf("SdrDelayThread - UNIMPLEMENTED!\n");
}

// 100% matching
void sdr_initQue() {
	int i;

	sbuff_idx = 0; 
	sque_r_idx = 0; 
	sque_w_idx = 0; 
	for (i = 127; i >= 0; sndque_tbl[i--].cmd = -1); 
} 

// 100% matching
int sdr_initDev(sceSifClientData *cd_p, unsigned int dev) { 
	int	i;
    
	for (i = 1024; i > 0; i--) { 
		if (sceSifBindRpc(cd_p, dev, 0) < 0) return -1; 
		if (cd_p->serve != NULL) break; 

		printf("SDR:  BindRpc: Just wait.\n"); 
		if (SdrDelayThread(1) < 0) return -1; 
	} 

	return 0; 
} 


// 99.91% matching
int SdrInit() {
    static int flag_1st; 
    struct SemaParam sm;
    sceSifReceiveData rd;
    int result;

    if (flag_1st != 0) {
        return 0;
    }
    
    sdr_initQue();
    
    result = sdr_initDev(&ClientData, 0);
    if (result < 0) {
        printf("SDR: SdrInit: Error: TSNDDRV_DEV: sceSifBindRpc faild.\n");
        return -1;
    }
    
    result = sdr_initDev(&GetStClientData, 1);
    if (result < 0) {
        printf("SDR: SdrInit: Error: TSNDGET_DEV: sceSifBindRpc faild.\n");
        return -1;
    }
    
    sm.initCount = 1;
    sm.maxCount = 1;
    sm.option = 0;
    
    if (SmId_send < 0) {
        result = CreateSema(&sm);
        if (result <= 0) {
            printf("SDR: SdrInit: Error: SmId_send faild.\n");
            return -1;
        }
        SmId_send = result;
    }

    if (SmId_get < 0) {
        result = CreateSema(&sm);
        if (result <= 0) {
            printf("SDR: SdrInit: Error: SmId_get faild.\n");
            return -1;
        }
        SmId_get = result;
    }
    
    flag_1st = 1;
    
    do {
        get_adrs = SdrGetState(0x12, 0);
    } while (get_adrs <= 0 || get_adrs >= 0x200000);
    
    iop_data_adr_top = SdrGetState(0x13, 0);

    while (sceSifGetOtherData(&rd, (void*)iop_data_adr_top, (void*)iop_data_adr, 0x40, 0) != 0) {
        CpEEWait(0x3E8);
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
int SdrSeReq(int req, char vol, char pan, short pitch) { 
	char temp; // not originally outputted by dwarf2cpp

	if (sndque_tbl[sque_w_idx].cmd >= 0) { 
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
int SdrSeCancel(int req) {
    if (sndque_tbl[sque_w_idx].cmd >= 0) {
        printf("SDR: SdrSeCancel: Warning: sndque overflow!\n");
        return -1;
    }
    
    sndque_tbl[sque_w_idx].cmd = (0x08000000 | (req & 0xFFFFFF));
    sque_w_idx = ++sque_w_idx % 128;
    
    return 0;
}

// 
// Start address: 0x2e9f60
int SdrSeChg(int req, char vol, char pan, short pitch)
{
	// Line 3551, Address: 0x2e9f60, Func Offset: 0
	// Line 3555, Address: 0x2e9f68, Func Offset: 0x8
	// Line 3556, Address: 0x2e9f8c, Func Offset: 0x2c
	// Line 3557, Address: 0x2e9f98, Func Offset: 0x38
	// Line 3560, Address: 0x2e9fa0, Func Offset: 0x40
	// Line 3564, Address: 0x2e9ff4, Func Offset: 0x94
	// Line 3567, Address: 0x2ea030, Func Offset: 0xd0
	// Line 3568, Address: 0x2ea044, Func Offset: 0xe4
	// Line 3569, Address: 0x2ea054, Func Offset: 0xf4
	// Line 3570, Address: 0x2ea064, Func Offset: 0x104
	// Line 3572, Address: 0x2ea074, Func Offset: 0x114
	// Line 3574, Address: 0x2ea0a4, Func Offset: 0x144
	// Line 3575, Address: 0x2ea0a8, Func Offset: 0x148
	// Func End, Address: 0x2ea0b4, Func Offset: 0x154
	scePrintf("SdrSeChg - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea0c0
int SdrSeAllStop()
{
	// Line 3594, Address: 0x2ea0c0, Func Offset: 0
	// Line 3595, Address: 0x2ea0c8, Func Offset: 0x8
	// Line 3596, Address: 0x2ea0ec, Func Offset: 0x2c
	// Line 3597, Address: 0x2ea0f8, Func Offset: 0x38
	// Line 3600, Address: 0x2ea100, Func Offset: 0x40
	// Line 3602, Address: 0x2ea108, Func Offset: 0x48
	// Line 3604, Address: 0x2ea138, Func Offset: 0x78
	// Line 3605, Address: 0x2ea13c, Func Offset: 0x7c
	// Func End, Address: 0x2ea148, Func Offset: 0x88
	scePrintf("SdrSeAllStop - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x2ea1f0
int SdrBgmReq(unsigned char port, unsigned char bank, unsigned char vol, unsigned char block)
{
	// Line 3789, Address: 0x2ea1f0, Func Offset: 0
	// Line 3792, Address: 0x2ea1f8, Func Offset: 0x8
	// Line 3793, Address: 0x2ea21c, Func Offset: 0x2c
	// Line 3794, Address: 0x2ea228, Func Offset: 0x38
	// Line 3797, Address: 0x2ea230, Func Offset: 0x40
	// Line 3801, Address: 0x2ea260, Func Offset: 0x70
	// Line 3802, Address: 0x2ea264, Func Offset: 0x74
	// Line 3803, Address: 0x2ea294, Func Offset: 0xa4
	// Line 3804, Address: 0x2ea298, Func Offset: 0xa8
	// Func End, Address: 0x2ea2a4, Func Offset: 0xb4
	scePrintf("SdrBgmReq - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea2b0
int SdrBgmStop(unsigned char port)
{
	// Line 3823, Address: 0x2ea2b0, Func Offset: 0
	// Line 3824, Address: 0x2ea2b8, Func Offset: 0x8
	// Line 3825, Address: 0x2ea2dc, Func Offset: 0x2c
	// Line 3826, Address: 0x2ea2e8, Func Offset: 0x38
	// Line 3829, Address: 0x2ea2f0, Func Offset: 0x40
	// Line 3831, Address: 0x2ea30c, Func Offset: 0x5c
	// Line 3833, Address: 0x2ea33c, Func Offset: 0x8c
	// Line 3834, Address: 0x2ea340, Func Offset: 0x90
	// Func End, Address: 0x2ea34c, Func Offset: 0x9c
	scePrintf("SdrBgmStop - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x2ea430
int SdrHDDataSet(int port, int size)
{
	// Line 4011, Address: 0x2ea430, Func Offset: 0
	// Line 4012, Address: 0x2ea438, Func Offset: 0x8
	// Line 4013, Address: 0x2ea45c, Func Offset: 0x2c
	// Line 4014, Address: 0x2ea468, Func Offset: 0x38
	// Line 4017, Address: 0x2ea470, Func Offset: 0x40
	// Line 4018, Address: 0x2ea488, Func Offset: 0x58
	// Line 4019, Address: 0x2ea48c, Func Offset: 0x5c
	// Line 4021, Address: 0x2ea4bc, Func Offset: 0x8c
	// Line 4022, Address: 0x2ea4c0, Func Offset: 0x90
	// Func End, Address: 0x2ea4cc, Func Offset: 0x9c
	scePrintf("SdrHDDataSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea4d0
int SdrHDDataSet2(int port, int size)
{
	// Line 4025, Address: 0x2ea4d0, Func Offset: 0
	// Line 4026, Address: 0x2ea4d8, Func Offset: 0x8
	// Line 4027, Address: 0x2ea4fc, Func Offset: 0x2c
	// Line 4028, Address: 0x2ea508, Func Offset: 0x38
	// Line 4031, Address: 0x2ea510, Func Offset: 0x40
	// Line 4032, Address: 0x2ea528, Func Offset: 0x58
	// Line 4033, Address: 0x2ea52c, Func Offset: 0x5c
	// Line 4035, Address: 0x2ea55c, Func Offset: 0x8c
	// Line 4036, Address: 0x2ea560, Func Offset: 0x90
	// Func End, Address: 0x2ea56c, Func Offset: 0x9c
	scePrintf("SdrHDDataSet2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea570
int SdrBDDataSet(int port)
{
	// Line 4039, Address: 0x2ea570, Func Offset: 0
	// Line 4040, Address: 0x2ea578, Func Offset: 0x8
	// Line 4041, Address: 0x2ea59c, Func Offset: 0x2c
	// Line 4042, Address: 0x2ea5a8, Func Offset: 0x38
	// Line 4045, Address: 0x2ea5b0, Func Offset: 0x40
	// Line 4046, Address: 0x2ea5c8, Func Offset: 0x58
	// Line 4048, Address: 0x2ea5f8, Func Offset: 0x88
	// Line 4049, Address: 0x2ea5fc, Func Offset: 0x8c
	// Func End, Address: 0x2ea608, Func Offset: 0x98
	scePrintf("SdrBDDataSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea610
int SdrBDDataSet2(int port)
{
	// Line 4050, Address: 0x2ea610, Func Offset: 0
	// Line 4051, Address: 0x2ea618, Func Offset: 0x8
	// Line 4052, Address: 0x2ea63c, Func Offset: 0x2c
	// Line 4053, Address: 0x2ea648, Func Offset: 0x38
	// Line 4056, Address: 0x2ea650, Func Offset: 0x40
	// Line 4057, Address: 0x2ea668, Func Offset: 0x58
	// Line 4059, Address: 0x2ea698, Func Offset: 0x88
	// Line 4060, Address: 0x2ea69c, Func Offset: 0x8c
	// Func End, Address: 0x2ea6a8, Func Offset: 0x98
	scePrintf("SdrBDDataSet2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea6b0
int SdrBDDataTrans(int port, int adrs, int size, int flag)
{
	// Line 4063, Address: 0x2ea6b0, Func Offset: 0
	// Line 4064, Address: 0x2ea6b8, Func Offset: 0x8
	// Line 4065, Address: 0x2ea6dc, Func Offset: 0x2c
	// Line 4066, Address: 0x2ea6e8, Func Offset: 0x38
	// Line 4069, Address: 0x2ea6f0, Func Offset: 0x40
	// Line 4070, Address: 0x2ea700, Func Offset: 0x50
	// Line 4069, Address: 0x2ea70c, Func Offset: 0x5c
	// Line 4070, Address: 0x2ea738, Func Offset: 0x88
	// Line 4071, Address: 0x2ea74c, Func Offset: 0x9c
	// Line 4073, Address: 0x2ea77c, Func Offset: 0xcc
	// Line 4074, Address: 0x2ea780, Func Offset: 0xd0
	// Func End, Address: 0x2ea78c, Func Offset: 0xdc
	scePrintf("SdrBDDataTrans - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ea790
int SdrSQDataSet(int port, int size)
{
	// Line 4078, Address: 0x2ea790, Func Offset: 0
	// Line 4079, Address: 0x2ea798, Func Offset: 0x8
	// Line 4080, Address: 0x2ea7bc, Func Offset: 0x2c
	// Line 4081, Address: 0x2ea7c8, Func Offset: 0x38
	// Line 4084, Address: 0x2ea7d0, Func Offset: 0x40
	// Line 4085, Address: 0x2ea7e8, Func Offset: 0x58
	// Line 4086, Address: 0x2ea7ec, Func Offset: 0x5c
	// Line 4088, Address: 0x2ea81c, Func Offset: 0x8c
	// Line 4089, Address: 0x2ea820, Func Offset: 0x90
	// Func End, Address: 0x2ea82c, Func Offset: 0x9c
	scePrintf("SdrSQDataSet - UNIMPLEMENTED!\n");
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
    goto skip_wait;
  }

  WaitSema(SmId_send);

skip_wait:
  r_idx = sque_r_idx;

  while (1) {
    while (sndque_tbl[r_idx].cmd >= 0) {
      if (sending_req(&sndque_tbl[r_idx]) < 0) {
        printf("SDR: SdrSendReq: Caution: sbuff overflow.\n     I carry "
               "forward the request to next time.\n");
        break;
      }

      sndque_tbl[r_idx].cmd = -1;
      r_idx = ++r_idx % 128;
    }

    break;
  }

next_loop:
  sque_r_idx = r_idx;

  if (sbuff_idx != 0) {
    dma_size = (sbuff_idx + 0x10) & -0x10;

    if (mode != 0) {
      mode = 1;
    }

    if (sceSifCallRpc(&ClientData, 0, mode, (void *)&sbuff, dma_size,
                      (void *)&sbuff, 0, (sceSifEndFunc)&cb_sifRpc_snd,
                      (void *)SmId_send) < 0) {
      printf("SDR: SdrSendReq: Error: Rpc faild.\n");
      SignalSema(SmId_send);
      return -1;
    }

    sbuff_idx = 0;
    if (mode != 0) {
      SendReqFlag = 1;
    }
    goto return_zero;
  }

  SignalSema(SmId_send);
return_zero:
  return 0;
}

// 100% matching!
void cb_sifRpc(int smid)
{
    iSignalSema(smid);
}

// 100% matching!
void cb_sifRpc_snd(int smid)
{
    iSignalSema(smid);
    
    *(int*)0x1E212C8 = 0;
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
        goto block_4;
    }
    
    WaitSema(SmId_get);
    
block_4:
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

int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch) {
    /*
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
    */
	scePrintf("makebuff_tq - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x2eb150
int makebuff_ext(unsigned int cmd, int n, int limit)
{
	int shift_n;
	// Line 5604, Address: 0x2eb150, Func Offset: 0
	// Line 5607, Address: 0x2eb154, Func Offset: 0x4
	// Line 5608, Address: 0x2eb16c, Func Offset: 0x1c
	// Line 5609, Address: 0x2eb178, Func Offset: 0x28
	// Line 5611, Address: 0x2eb180, Func Offset: 0x30
	// Line 5613, Address: 0x2eb1a0, Func Offset: 0x50
	// Line 5614, Address: 0x2eb1a4, Func Offset: 0x54
	// Line 5615, Address: 0x2eb1b8, Func Offset: 0x68
	// Line 5617, Address: 0x2eb1c8, Func Offset: 0x78
	// Line 5615, Address: 0x2eb1cc, Func Offset: 0x7c
	// Line 5616, Address: 0x2eb1d0, Func Offset: 0x80
	// Line 5615, Address: 0x2eb1d4, Func Offset: 0x84
	// Line 5617, Address: 0x2eb1dc, Func Offset: 0x8c
	// Line 5619, Address: 0x2eb1e8, Func Offset: 0x98
	// Line 5620, Address: 0x2eb1ec, Func Offset: 0x9c
	// Func End, Address: 0x2eb1f8, Func Offset: 0xa8
	scePrintf("makebuff_ext - UNIMPLEMENTED!\n");
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

