typedef struct _anon0;
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

unsigned char sbuff[512];
unsigned int getbuff[4];
_sif_client_data ClientData;
_sif_client_data GetStClientData;
_anon1 sndque_tbl[128];
int sque_r_idx;
int sque_w_idx;
int sbuff_idx;
int ThId_send;
int SmId_send;
int SmId_get;
int SendReqFlag;
unsigned char Stack_send[2048];
unsigned int IOP_hd_size[16];
unsigned int IOP_tq_size[16];
void(*wait_alarm)(int, unsigned short, int);
int iop_data_buff;
int iop_data_adr[16];
int iop_sq_adr[16];
int iop_hd_adr[16];
int iop_data_adr_top;
int get_adrs;
void* _gp;
int(*th_sdrSendReq)();
void(*cb_sifRpc_snd)(int);
void(*cb_sifRpc)(int);
void(*cb_sifRpc2)(int*);
_SND_STATUS get_iop_buff;
_SND_STATUS get_iop_snddata;

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
void cb_sifRpc(int smid);
void cb_sifRpc_snd(int smid);
int SdrGetStateSend(int command, int data);
int SdrGetStateReceive(int mode);
int SdrGetState(int command, int data);
int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch);
int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7);
int makebuff(unsigned int cmd, int n);
int makebuff_ext(unsigned int cmd, int n, int limit);
int sending_req(_anon1* sq_p);
int get_iopsnd_info();

// 
// Start address: 0x2e98a0
void wait_alarm(int thid)
{
	// Line 3075, Address: 0x2e98a0, Func Offset: 0
	// Line 3076, Address: 0x2e98a8, Func Offset: 0x8
	// Line 3077, Address: 0x2e98b0, Func Offset: 0x10
	// Line 3078, Address: 0x2e98b8, Func Offset: 0x18
	// Func End, Address: 0x2e98c4, Func Offset: 0x24
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
}

// 
// Start address: 0x2e9930
void sdr_initQue()
{
	int i;
	// Line 3156, Address: 0x2e9930, Func Offset: 0
	// Line 3157, Address: 0x2e9938, Func Offset: 0x8
	// Line 3158, Address: 0x2e9944, Func Offset: 0x14
	// Line 3159, Address: 0x2e9948, Func Offset: 0x18
	// Line 3158, Address: 0x2e9950, Func Offset: 0x20
	// Line 3159, Address: 0x2e9954, Func Offset: 0x24
	// Line 3160, Address: 0x2e9974, Func Offset: 0x44
	// Func End, Address: 0x2e997c, Func Offset: 0x4c
}

// 
// Start address: 0x2e9980
int sdr_initDev(_sif_client_data* cd_p, unsigned int dev)
{
	int i;
	// Line 3180, Address: 0x2e9980, Func Offset: 0
	// Line 3184, Address: 0x2e9994, Func Offset: 0x14
	// Line 3185, Address: 0x2e99a0, Func Offset: 0x20
	// Line 3186, Address: 0x2e99c0, Func Offset: 0x40
	// Line 3191, Address: 0x2e99cc, Func Offset: 0x4c
	// Line 3192, Address: 0x2e99d8, Func Offset: 0x58
	// Line 3193, Address: 0x2e99f0, Func Offset: 0x70
	// Line 3194, Address: 0x2e9a00, Func Offset: 0x80
	// Line 3195, Address: 0x2e9a04, Func Offset: 0x84
	// Func End, Address: 0x2e9a1c, Func Offset: 0x9c
}

// 
// Start address: 0x2e9a20
int SdrInit()
{
	_sif_receive_data rd;
	SemaParam sem;
	int id;
	int flag_1st;
	// Line 3223, Address: 0x2e9a20, Func Offset: 0
	// Line 3230, Address: 0x2e9a28, Func Offset: 0x8
	// Line 3232, Address: 0x2e9a40, Func Offset: 0x20
	// Line 3238, Address: 0x2e9a48, Func Offset: 0x28
	// Line 3239, Address: 0x2e9a60, Func Offset: 0x40
	// Line 3240, Address: 0x2e9a6c, Func Offset: 0x4c
	// Line 3243, Address: 0x2e9a74, Func Offset: 0x54
	// Line 3244, Address: 0x2e9a8c, Func Offset: 0x6c
	// Line 3245, Address: 0x2e9a98, Func Offset: 0x78
	// Line 3252, Address: 0x2e9aa0, Func Offset: 0x80
	// Line 3248, Address: 0x2e9aa8, Func Offset: 0x88
	// Line 3249, Address: 0x2e9ab0, Func Offset: 0x90
	// Line 3252, Address: 0x2e9ab4, Func Offset: 0x94
	// Line 3253, Address: 0x2e9abc, Func Offset: 0x9c
	// Line 3255, Address: 0x2e9ac4, Func Offset: 0xa4
	// Line 3256, Address: 0x2e9acc, Func Offset: 0xac
	// Line 3257, Address: 0x2e9ad8, Func Offset: 0xb8
	// Line 3260, Address: 0x2e9ae0, Func Offset: 0xc0
	// Line 3263, Address: 0x2e9ae8, Func Offset: 0xc8
	// Line 3264, Address: 0x2e9af8, Func Offset: 0xd8
	// Line 3266, Address: 0x2e9b00, Func Offset: 0xe0
	// Line 3267, Address: 0x2e9b08, Func Offset: 0xe8
	// Line 3268, Address: 0x2e9b14, Func Offset: 0xf4
	// Line 3271, Address: 0x2e9b1c, Func Offset: 0xfc
	// Line 3273, Address: 0x2e9b24, Func Offset: 0x104
	// Line 3298, Address: 0x2e9b30, Func Offset: 0x110
	// Line 3299, Address: 0x2e9b44, Func Offset: 0x124
	// Line 3306, Address: 0x2e9b64, Func Offset: 0x144
	// Line 3308, Address: 0x2e9b74, Func Offset: 0x154
	// Line 3309, Address: 0x2e9b7c, Func Offset: 0x15c
	// Line 3310, Address: 0x2e9b84, Func Offset: 0x164
	// Line 3313, Address: 0x2e9bb0, Func Offset: 0x190
	// Line 3314, Address: 0x2e9bb8, Func Offset: 0x198
	// Line 3315, Address: 0x2e9bc0, Func Offset: 0x1a0
	// Line 3316, Address: 0x2e9bc8, Func Offset: 0x1a8
	// Line 3317, Address: 0x2e9bd0, Func Offset: 0x1b0
	// Line 3318, Address: 0x2e9bd8, Func Offset: 0x1b8
	// Line 3313, Address: 0x2e9be0, Func Offset: 0x1c0
	// Line 3314, Address: 0x2e9be8, Func Offset: 0x1c8
	// Line 3319, Address: 0x2e9bf0, Func Offset: 0x1d0
	// Line 3314, Address: 0x2e9bf8, Func Offset: 0x1d8
	// Line 3320, Address: 0x2e9bfc, Func Offset: 0x1dc
	// Line 3322, Address: 0x2e9c04, Func Offset: 0x1e4
	// Line 3323, Address: 0x2e9c0c, Func Offset: 0x1ec
	// Line 3324, Address: 0x2e9c14, Func Offset: 0x1f4
	// Line 3325, Address: 0x2e9c1c, Func Offset: 0x1fc
	// Line 3314, Address: 0x2e9c24, Func Offset: 0x204
	// Line 3322, Address: 0x2e9c2c, Func Offset: 0x20c
	// Line 3315, Address: 0x2e9c34, Func Offset: 0x214
	// Line 3323, Address: 0x2e9c3c, Func Offset: 0x21c
	// Line 3315, Address: 0x2e9c44, Func Offset: 0x224
	// Line 3326, Address: 0x2e9c48, Func Offset: 0x228
	// Line 3323, Address: 0x2e9c50, Func Offset: 0x230
	// Line 3327, Address: 0x2e9c54, Func Offset: 0x234
	// Line 3328, Address: 0x2e9c5c, Func Offset: 0x23c
	// Line 3329, Address: 0x2e9c64, Func Offset: 0x244
	// Line 3331, Address: 0x2e9c6c, Func Offset: 0x24c
	// Line 3315, Address: 0x2e9c74, Func Offset: 0x254
	// Line 3316, Address: 0x2e9c7c, Func Offset: 0x25c
	// Line 3323, Address: 0x2e9c84, Func Offset: 0x264
	// Line 3324, Address: 0x2e9c8c, Func Offset: 0x26c
	// Line 3316, Address: 0x2e9c94, Func Offset: 0x274
	// Line 3331, Address: 0x2e9c98, Func Offset: 0x278
	// Line 3316, Address: 0x2e9ca0, Func Offset: 0x280
	// Line 3324, Address: 0x2e9ca8, Func Offset: 0x288
	// Line 3317, Address: 0x2e9cac, Func Offset: 0x28c
	// Line 3335, Address: 0x2e9cb4, Func Offset: 0x294
	// Line 3324, Address: 0x2e9cb8, Func Offset: 0x298
	// Line 3325, Address: 0x2e9cc0, Func Offset: 0x2a0
	// Line 3317, Address: 0x2e9cc8, Func Offset: 0x2a8
	// Line 3325, Address: 0x2e9cd4, Func Offset: 0x2b4
	// Line 3318, Address: 0x2e9cd8, Func Offset: 0x2b8
	// Line 3325, Address: 0x2e9ce0, Func Offset: 0x2c0
	// Line 3326, Address: 0x2e9ce8, Func Offset: 0x2c8
	// Line 3318, Address: 0x2e9cf0, Func Offset: 0x2d0
	// Line 3326, Address: 0x2e9cfc, Func Offset: 0x2dc
	// Line 3319, Address: 0x2e9d00, Func Offset: 0x2e0
	// Line 3326, Address: 0x2e9d08, Func Offset: 0x2e8
	// Line 3327, Address: 0x2e9d10, Func Offset: 0x2f0
	// Line 3319, Address: 0x2e9d18, Func Offset: 0x2f8
	// Line 3327, Address: 0x2e9d24, Func Offset: 0x304
	// Line 3320, Address: 0x2e9d28, Func Offset: 0x308
	// Line 3327, Address: 0x2e9d30, Func Offset: 0x310
	// Line 3328, Address: 0x2e9d38, Func Offset: 0x318
	// Line 3320, Address: 0x2e9d40, Func Offset: 0x320
	// Line 3328, Address: 0x2e9d4c, Func Offset: 0x32c
	// Line 3329, Address: 0x2e9d58, Func Offset: 0x338
	// Line 3336, Address: 0x2e9d6c, Func Offset: 0x34c
	// Func End, Address: 0x2e9d78, Func Offset: 0x358
}

// 
// Start address: 0x2e9d80
int SdrSeReq(int req, char vol, char pan, short pitch)
{
	// Line 3418, Address: 0x2e9d80, Func Offset: 0
	// Line 3422, Address: 0x2e9d88, Func Offset: 0x8
	// Line 3423, Address: 0x2e9dac, Func Offset: 0x2c
	// Line 3424, Address: 0x2e9db8, Func Offset: 0x38
	// Line 3428, Address: 0x2e9dc0, Func Offset: 0x40
	// Line 3432, Address: 0x2e9e14, Func Offset: 0x94
	// Line 3433, Address: 0x2e9e4c, Func Offset: 0xcc
	// Line 3434, Address: 0x2e9e5c, Func Offset: 0xdc
	// Line 3435, Address: 0x2e9e6c, Func Offset: 0xec
	// Line 3437, Address: 0x2e9e7c, Func Offset: 0xfc
	// Line 3439, Address: 0x2e9eac, Func Offset: 0x12c
	// Line 3440, Address: 0x2e9eb0, Func Offset: 0x130
	// Func End, Address: 0x2e9ebc, Func Offset: 0x13c
}

// 
// Start address: 0x2e9ec0
int SdrSeCancel(int req)
{
	// Line 3461, Address: 0x2e9ec0, Func Offset: 0
	// Line 3513, Address: 0x2e9ec8, Func Offset: 0x8
	// Line 3514, Address: 0x2e9eec, Func Offset: 0x2c
	// Line 3515, Address: 0x2e9ef8, Func Offset: 0x38
	// Line 3518, Address: 0x2e9f00, Func Offset: 0x40
	// Line 3520, Address: 0x2e9f14, Func Offset: 0x54
	// Line 3522, Address: 0x2e9f44, Func Offset: 0x84
	// Line 3523, Address: 0x2e9f48, Func Offset: 0x88
	// Func End, Address: 0x2e9f54, Func Offset: 0x94
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
}

// 
// Start address: 0x2ea150
int SdrMasterVol(unsigned short mvol)
{
	// Line 3686, Address: 0x2ea150, Func Offset: 0
	// Line 3687, Address: 0x2ea158, Func Offset: 0x8
	// Line 3688, Address: 0x2ea17c, Func Offset: 0x2c
	// Line 3689, Address: 0x2ea188, Func Offset: 0x38
	// Line 3692, Address: 0x2ea190, Func Offset: 0x40
	// Line 3694, Address: 0x2ea1ac, Func Offset: 0x5c
	// Line 3696, Address: 0x2ea1dc, Func Offset: 0x8c
	// Line 3697, Address: 0x2ea1e0, Func Offset: 0x90
	// Func End, Address: 0x2ea1ec, Func Offset: 0x9c
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
}

// 
// Start address: 0x2ea350
int SdrBgmChg(int req, char vol, char pan, short pitch)
{
	// Line 3990, Address: 0x2ea350, Func Offset: 0
	// Line 3994, Address: 0x2ea358, Func Offset: 0x8
	// Line 3995, Address: 0x2ea37c, Func Offset: 0x2c
	// Line 3996, Address: 0x2ea388, Func Offset: 0x38
	// Line 4000, Address: 0x2ea390, Func Offset: 0x40
	// Line 4001, Address: 0x2ea3a8, Func Offset: 0x58
	// Line 4002, Address: 0x2ea3b8, Func Offset: 0x68
	// Line 4003, Address: 0x2ea3c8, Func Offset: 0x78
	// Line 4005, Address: 0x2ea3e8, Func Offset: 0x98
	// Line 4007, Address: 0x2ea418, Func Offset: 0xc8
	// Line 4008, Address: 0x2ea41c, Func Offset: 0xcc
	// Func End, Address: 0x2ea428, Func Offset: 0xd8
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
}

// 
// Start address: 0x2ea830
int SdrSetIopData()
{
	// Line 4112, Address: 0x2ea830, Func Offset: 0
	// Line 4116, Address: 0x2ea838, Func Offset: 0x8
	// Line 4117, Address: 0x2ea85c, Func Offset: 0x2c
	// Line 4118, Address: 0x2ea868, Func Offset: 0x38
	// Line 4122, Address: 0x2ea870, Func Offset: 0x40
	// Line 4123, Address: 0x2ea878, Func Offset: 0x48
	// Line 4124, Address: 0x2ea888, Func Offset: 0x58
	// Line 4125, Address: 0x2ea898, Func Offset: 0x68
	// Line 4127, Address: 0x2ea8a8, Func Offset: 0x78
	// Line 4129, Address: 0x2ea8d8, Func Offset: 0xa8
	// Line 4130, Address: 0x2ea8dc, Func Offset: 0xac
	// Func End, Address: 0x2ea8e8, Func Offset: 0xb8
}

// 
// Start address: 0x2ea8f0
int SdrSetOutputMode(int mode)
{
	// Line 4636, Address: 0x2ea8f0, Func Offset: 0
	// Line 4637, Address: 0x2ea8f8, Func Offset: 0x8
	// Line 4638, Address: 0x2ea91c, Func Offset: 0x2c
	// Line 4639, Address: 0x2ea928, Func Offset: 0x38
	// Line 4642, Address: 0x2ea930, Func Offset: 0x40
	// Line 4645, Address: 0x2ea950, Func Offset: 0x60
	// Line 4647, Address: 0x2ea980, Func Offset: 0x90
	// Line 4648, Address: 0x2ea984, Func Offset: 0x94
	// Func End, Address: 0x2ea990, Func Offset: 0xa0
}

// 
// Start address: 0x2ea990
int SdrSetRev(unsigned int core, unsigned int mode, short depth, unsigned char delay, unsigned char feedback)
{
	_anon0* sqd_p;
	// Line 4744, Address: 0x2ea990, Func Offset: 0
	// Line 4748, Address: 0x2ea994, Func Offset: 0x4
	// Line 4749, Address: 0x2ea9a0, Func Offset: 0x10
	// Line 4750, Address: 0x2ea9ac, Func Offset: 0x1c
	// Line 4753, Address: 0x2ea9b4, Func Offset: 0x24
	// Line 4754, Address: 0x2ea9c0, Func Offset: 0x30
	// Line 4755, Address: 0x2ea9cc, Func Offset: 0x3c
	// Line 4757, Address: 0x2ea9d4, Func Offset: 0x44
	// Line 4758, Address: 0x2ea9f8, Func Offset: 0x68
	// Line 4759, Address: 0x2eaa04, Func Offset: 0x74
	// Line 4762, Address: 0x2eaa0c, Func Offset: 0x7c
	// Line 4764, Address: 0x2eaa10, Func Offset: 0x80
	// Line 4762, Address: 0x2eaa14, Func Offset: 0x84
	// Line 4764, Address: 0x2eaa18, Func Offset: 0x88
	// Line 4762, Address: 0x2eaa1c, Func Offset: 0x8c
	// Line 4764, Address: 0x2eaa20, Func Offset: 0x90
	// Line 4765, Address: 0x2eaa40, Func Offset: 0xb0
	// Line 4766, Address: 0x2eaa44, Func Offset: 0xb4
	// Line 4768, Address: 0x2eaa48, Func Offset: 0xb8
	// Line 4770, Address: 0x2eaa78, Func Offset: 0xe8
	// Line 4771, Address: 0x2eaa7c, Func Offset: 0xec
	// Func End, Address: 0x2eaa88, Func Offset: 0xf8
}

// 
// Start address: 0x2eaa90
int SdrSendReq(int mode)
{
	int dma_size;
	int r_idx;
	// Line 4803, Address: 0x2eaa90, Func Offset: 0
	// Line 4806, Address: 0x2eaaa4, Func Offset: 0x14
	// Line 4808, Address: 0x2eaaac, Func Offset: 0x1c
	// Line 4811, Address: 0x2eaac8, Func Offset: 0x38
	// Line 4813, Address: 0x2eaad4, Func Offset: 0x44
	// Line 4816, Address: 0x2eaad8, Func Offset: 0x48
	// Line 4817, Address: 0x2eaae0, Func Offset: 0x50
	// Line 4820, Address: 0x2eaaf0, Func Offset: 0x60
	// Line 4821, Address: 0x2eaafc, Func Offset: 0x6c
	// Line 4823, Address: 0x2eab04, Func Offset: 0x74
	// Line 4824, Address: 0x2eab08, Func Offset: 0x78
	// Line 4823, Address: 0x2eab0c, Func Offset: 0x7c
	// Line 4824, Address: 0x2eab10, Func Offset: 0x80
	// Line 4825, Address: 0x2eab28, Func Offset: 0x98
	// Line 4826, Address: 0x2eab48, Func Offset: 0xb8
	// Line 4829, Address: 0x2eab50, Func Offset: 0xc0
	// Line 4831, Address: 0x2eab60, Func Offset: 0xd0
	// Line 4832, Address: 0x2eab68, Func Offset: 0xd8
	// Line 4850, Address: 0x2eab74, Func Offset: 0xe4
	// Line 4865, Address: 0x2eabb8, Func Offset: 0x128
	// Line 4866, Address: 0x2eabc4, Func Offset: 0x134
	// Line 4867, Address: 0x2eabd0, Func Offset: 0x140
	// Line 4870, Address: 0x2eabd8, Func Offset: 0x148
	// Line 4875, Address: 0x2eabdc, Func Offset: 0x14c
	// Line 4877, Address: 0x2eabe4, Func Offset: 0x154
	// Line 4881, Address: 0x2eabec, Func Offset: 0x15c
	// Line 4883, Address: 0x2eabf4, Func Offset: 0x164
	// Line 4885, Address: 0x2eac00, Func Offset: 0x170
	// Line 4886, Address: 0x2eac04, Func Offset: 0x174
	// Func End, Address: 0x2eac1c, Func Offset: 0x18c
}

// 
// Start address: 0x2eac20
void cb_sifRpc(int smid)
{
	// Line 4946, Address: 0x2eac20, Func Offset: 0
	// Func End, Address: 0x2eac28, Func Offset: 0x8
}

// 
// Start address: 0x2eac30
void cb_sifRpc_snd(int smid)
{
	// Line 4950, Address: 0x2eac30, Func Offset: 0
	// Line 4951, Address: 0x2eac38, Func Offset: 0x8
	// Line 4955, Address: 0x2eac40, Func Offset: 0x10
	// Line 4958, Address: 0x2eac48, Func Offset: 0x18
	// Func End, Address: 0x2eac54, Func Offset: 0x24
}

// 
// Start address: 0x2eac60
int SdrGetStateSend(int command, int data)
{
	// Line 5167, Address: 0x2eac60, Func Offset: 0
	// Line 5168, Address: 0x2eac74, Func Offset: 0x14
	// Line 5171, Address: 0x2eac84, Func Offset: 0x24
	// Line 5169, Address: 0x2eac8c, Func Offset: 0x2c
	// Line 5171, Address: 0x2eac94, Func Offset: 0x34
	// Line 5183, Address: 0x2eacd4, Func Offset: 0x74
	// Line 5184, Address: 0x2eace0, Func Offset: 0x80
	// Line 5185, Address: 0x2eacec, Func Offset: 0x8c
	// Line 5188, Address: 0x2eacf4, Func Offset: 0x94
	// Line 5189, Address: 0x2eacf8, Func Offset: 0x98
	// Func End, Address: 0x2ead0c, Func Offset: 0xac
}

// 
// Start address: 0x2ead10
int SdrGetStateReceive(int mode)
{
	int ret;
	// Line 5221, Address: 0x2ead10, Func Offset: 0
	// Line 5225, Address: 0x2ead18, Func Offset: 0x8
	// Line 5226, Address: 0x2ead20, Func Offset: 0x10
	// Line 5228, Address: 0x2ead3c, Func Offset: 0x2c
	// Line 5230, Address: 0x2ead48, Func Offset: 0x38
	// Line 5231, Address: 0x2ead50, Func Offset: 0x40
	// Line 5233, Address: 0x2ead5c, Func Offset: 0x4c
	// Line 5234, Address: 0x2ead60, Func Offset: 0x50
	// Func End, Address: 0x2ead70, Func Offset: 0x60
}

// 
// Start address: 0x2ead70
int SdrGetState(int command, int data)
{
	int ret;
	int i;
	int ret;
	// Line 5261, Address: 0x2ead70, Func Offset: 0
	// Line 5264, Address: 0x2ead7c, Func Offset: 0xc
	// Line 5265, Address: 0x2ead84, Func Offset: 0x14
	// Line 5273, Address: 0x2ead94, Func Offset: 0x24
	// Line 5274, Address: 0x2ead98, Func Offset: 0x28
	// Line 5275, Address: 0x2eada4, Func Offset: 0x34
	// Line 5277, Address: 0x2eadb0, Func Offset: 0x40
	// Line 5278, Address: 0x2eadc8, Func Offset: 0x58
	// Line 5279, Address: 0x2eadd8, Func Offset: 0x68
	// Line 5280, Address: 0x2eade4, Func Offset: 0x74
	// Line 5282, Address: 0x2eadf0, Func Offset: 0x80
	// Line 5286, Address: 0x2eadf4, Func Offset: 0x84
	// Func End, Address: 0x2eae08, Func Offset: 0x98
}

// 
// Start address: 0x2eae10
int makebuff_tq(unsigned int cmd, unsigned char vol, unsigned char pan, unsigned short pitch)
{
	unsigned char* sb_p;
	int len;
	int cd;
	// Line 5464, Address: 0x2eae10, Func Offset: 0
	// Line 5466, Address: 0x2eae14, Func Offset: 0x4
	// Line 5467, Address: 0x2eae24, Func Offset: 0x14
	// Line 5468, Address: 0x2eae34, Func Offset: 0x24
	// Line 5470, Address: 0x2eae44, Func Offset: 0x34
	// Line 5472, Address: 0x2eae64, Func Offset: 0x54
	// Line 5473, Address: 0x2eae70, Func Offset: 0x60
	// Line 5474, Address: 0x2eae74, Func Offset: 0x64
	// Line 5475, Address: 0x2eae7c, Func Offset: 0x6c
	// Line 5476, Address: 0x2eae84, Func Offset: 0x74
	// Line 5478, Address: 0x2eae88, Func Offset: 0x78
	// Line 5479, Address: 0x2eae98, Func Offset: 0x88
	// Line 5480, Address: 0x2eaea8, Func Offset: 0x98
	// Line 5481, Address: 0x2eaeb0, Func Offset: 0xa0
	// Line 5482, Address: 0x2eaebc, Func Offset: 0xac
	// Line 5485, Address: 0x2eaec4, Func Offset: 0xb4
	// Line 5486, Address: 0x2eaecc, Func Offset: 0xbc
	// Line 5488, Address: 0x2eaed0, Func Offset: 0xc0
	// Line 5485, Address: 0x2eaed4, Func Offset: 0xc4
	// Line 5486, Address: 0x2eaee0, Func Offset: 0xd0
	// Line 5489, Address: 0x2eaee4, Func Offset: 0xd4
	// Func End, Address: 0x2eaeec, Func Offset: 0xdc
}

// 
// Start address: 0x2eaef0
int makebuff8(unsigned int cmd, int n, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7)
{
	int i;
	int shift_n;
	// Line 5515, Address: 0x2eaef0, Func Offset: 0
	// Line 5518, Address: 0x2eaef4, Func Offset: 0x4
	// Line 5519, Address: 0x2eaf00, Func Offset: 0x10
	// Line 5520, Address: 0x2eaf0c, Func Offset: 0x1c
	// Line 5522, Address: 0x2eaf14, Func Offset: 0x24
	// Line 5524, Address: 0x2eaf3c, Func Offset: 0x4c
	// Line 5525, Address: 0x2eaf40, Func Offset: 0x50
	// Line 5526, Address: 0x2eaf4c, Func Offset: 0x5c
	// Line 5527, Address: 0x2eaf60, Func Offset: 0x70
	// Line 5528, Address: 0x2eaf64, Func Offset: 0x74
	// Line 5526, Address: 0x2eaf68, Func Offset: 0x78
	// Line 5528, Address: 0x2eaf70, Func Offset: 0x80
	// Line 5526, Address: 0x2eaf74, Func Offset: 0x84
	// Line 5528, Address: 0x2eaf78, Func Offset: 0x88
	// Line 5529, Address: 0x2eaf88, Func Offset: 0x98
	// Line 5530, Address: 0x2eafc0, Func Offset: 0xd0
	// Line 5531, Address: 0x2eaff8, Func Offset: 0x108
	// Line 5532, Address: 0x2eb030, Func Offset: 0x140
	// Line 5534, Address: 0x2eb064, Func Offset: 0x174
	// Line 5536, Address: 0x2eb07c, Func Offset: 0x18c
	// Line 5534, Address: 0x2eb080, Func Offset: 0x190
	// Line 5537, Address: 0x2eb084, Func Offset: 0x194
	// Func End, Address: 0x2eb090, Func Offset: 0x1a0
}

// 
// Start address: 0x2eb090
int makebuff(unsigned int cmd, int n)
{
	int shift_n;
	// Line 5557, Address: 0x2eb090, Func Offset: 0
	// Line 5560, Address: 0x2eb094, Func Offset: 0x4
	// Line 5561, Address: 0x2eb0a0, Func Offset: 0x10
	// Line 5562, Address: 0x2eb0ac, Func Offset: 0x1c
	// Line 5564, Address: 0x2eb0b4, Func Offset: 0x24
	// Line 5566, Address: 0x2eb0d4, Func Offset: 0x44
	// Line 5567, Address: 0x2eb0d8, Func Offset: 0x48
	// Line 5568, Address: 0x2eb0ec, Func Offset: 0x5c
	// Line 5570, Address: 0x2eb0fc, Func Offset: 0x6c
	// Line 5568, Address: 0x2eb100, Func Offset: 0x70
	// Line 5569, Address: 0x2eb104, Func Offset: 0x74
	// Line 5568, Address: 0x2eb108, Func Offset: 0x78
	// Line 5570, Address: 0x2eb110, Func Offset: 0x80
	// Line 5572, Address: 0x2eb118, Func Offset: 0x88
	// Line 5574, Address: 0x2eb130, Func Offset: 0xa0
	// Line 5572, Address: 0x2eb134, Func Offset: 0xa4
	// Line 5575, Address: 0x2eb138, Func Offset: 0xa8
	// Func End, Address: 0x2eb144, Func Offset: 0xb4
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
}

// 
// Start address: 0x2eb200
int sending_req(_anon1* sq_p)
{
	_anon0* sqd_p;
	int cd;
	// Line 5644, Address: 0x2eb200, Func Offset: 0
	// Line 5648, Address: 0x2eb208, Func Offset: 0x8
	// Line 5650, Address: 0x2eb20c, Func Offset: 0xc
	// Line 5648, Address: 0x2eb210, Func Offset: 0x10
	// Line 5650, Address: 0x2eb214, Func Offset: 0x14
	// Line 5651, Address: 0x2eb224, Func Offset: 0x24
	// Line 5653, Address: 0x2eb238, Func Offset: 0x38
	// Line 5655, Address: 0x2eb288, Func Offset: 0x88
	// Line 5659, Address: 0x2eb2a4, Func Offset: 0xa4
	// Line 5664, Address: 0x2eb2d8, Func Offset: 0xd8
	// Line 5668, Address: 0x2eb2e8, Func Offset: 0xe8
	// Line 5670, Address: 0x2eb2fc, Func Offset: 0xfc
	// Line 5671, Address: 0x2eb308, Func Offset: 0x108
	// Line 5673, Address: 0x2eb31c, Func Offset: 0x11c
	// Line 5674, Address: 0x2eb324, Func Offset: 0x124
	// Line 5676, Address: 0x2eb348, Func Offset: 0x148
	// Line 5681, Address: 0x2eb368, Func Offset: 0x168
	// Line 5683, Address: 0x2eb38c, Func Offset: 0x18c
	// Line 5686, Address: 0x2eb3a0, Func Offset: 0x1a0
	// Line 5692, Address: 0x2eb3c0, Func Offset: 0x1c0
	// Line 5694, Address: 0x2eb3d4, Func Offset: 0x1d4
	// Line 5695, Address: 0x2eb3e0, Func Offset: 0x1e0
	// Line 5697, Address: 0x2eb3f4, Func Offset: 0x1f4
	// Line 5699, Address: 0x2eb40c, Func Offset: 0x20c
	// Line 5701, Address: 0x2eb420, Func Offset: 0x220
	// Line 5702, Address: 0x2eb42c, Func Offset: 0x22c
	// Line 5704, Address: 0x2eb450, Func Offset: 0x250
	// Line 5706, Address: 0x2eb460, Func Offset: 0x260
	// Line 5709, Address: 0x2eb478, Func Offset: 0x278
	// Line 5721, Address: 0x2eb4c0, Func Offset: 0x2c0
	// Line 5726, Address: 0x2eb508, Func Offset: 0x308
	// Line 5727, Address: 0x2eb514, Func Offset: 0x314
	// Line 5730, Address: 0x2eb518, Func Offset: 0x318
	// Func End, Address: 0x2eb524, Func Offset: 0x324
}

// 
// Start address: 0x2eb530
int get_iopsnd_info()
{
	_sif_receive_data rd;
	// Line 5753, Address: 0x2eb530, Func Offset: 0
	// Line 5762, Address: 0x2eb538, Func Offset: 0x8
	// Line 5764, Address: 0x2eb560, Func Offset: 0x30
	// Line 5765, Address: 0x2eb578, Func Offset: 0x48
	// Line 5768, Address: 0x2eb580, Func Offset: 0x50
	// Line 5770, Address: 0x2eb584, Func Offset: 0x54
	// Func End, Address: 0x2eb590, Func Offset: 0x60
}

