typedef struct GDS_DCF;
typedef struct _anon0;
typedef struct GDS_FS_WORK;
typedef struct GDS_FS_LIF;
typedef struct GDS_FS_HANDLE;
typedef struct _anon1;
typedef struct _anon2;
typedef struct GDS_FS_DIRREC_ENT;
typedef struct GDS_FS_DIRREC_TBL;
typedef struct GDS_FS_DIRINFO;

typedef void(*type_1)(void*);
typedef void(*type_4)(void*);
typedef void(*type_6)(void*, int);
typedef void(*type_15)(void*, int);

typedef GDS_FS_HANDLE type_0[1];
typedef char type_2[16];
typedef unsigned char type_3[8];
typedef char type_5[2048];
typedef char type_7[2048];
typedef _anon1 type_8[0];
typedef char type_9[256];
typedef char type_10[32];
typedef char type_11[2];
typedef GDS_FS_DIRREC_ENT type_12[1];
typedef unsigned char type_13[3];
typedef char type_14[256];
typedef unsigned int type_16[1040];

struct GDS_DCF
{
};

struct _anon0
{
	unsigned char trycount;
	unsigned char spindlctrl;
	unsigned char datapattern;
	unsigned char pad;
};

struct GDS_FS_WORK
{
	int max_open;
	int pathtbl_fad;
	int pathtbl_size;
	GDS_DCF* dcf;
	GDS_FS_DIRREC_TBL* curdir;
	GDS_FS_HANDLE* syshdl;
	GDS_FS_HANDLE* hndtbl;
	GDS_FS_HANDLE* now_work;
	int f_svr;
	void(*g_errcb)(void*, int);
	void* g_errcb_1st;
	int gdc_ver;
	int errstat;
	int istray;
	short f_init;
	short daplayed;
	GDS_FS_LIF* liftbl;
	unsigned int sctbuf[1040];
	GDS_FS_HANDLE hndlist[1];
};

struct GDS_FS_LIF
{
};

struct GDS_FS_HANDLE
{
	GDS_FS_WORK* wk;
	int fid;
	int fad;
	int fsize;
	int fsctsize;
	int ofs;
	int trnsed;
	int rsize;
	int trsize;
	void(*rdendcb)(void*);
	void* rdcb_1st;
	void(*trendcb)(void*);
	void* trcb_1st;
	void(*errcb)(void*, int);
	void* errcb_1st;
	int gdchn;
	int gdchn_wait;
	int ex_errcode;
	short act;
	short trflag;
	short used;
	short tmode;
	short stat;
	short err;
};

struct _anon1
{
	char* file_name;
	char* link_file;
};

struct _anon2
{
	unsigned int lsn;
	unsigned int size;
	char name[16];
	unsigned char date[8];
};

struct GDS_FS_DIRREC_ENT
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char sid;
	char fname[32];
	char pad[2];
};

struct GDS_FS_DIRREC_TBL
{
	int dir_num;
	int max_ent;
	int dir_fad;
	int pad;
	GDS_FS_DIRREC_ENT dirrec_tbl[1];
};

struct GDS_FS_DIRINFO
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char pad[3];
};

GDS_FS_HANDLE* __file_handle;
GDS_FS_WORK* __gds_fs_work;
GDS_FS_DIRREC_TBL* __current_dir;
GDS_FS_DIRREC_ENT* __gdfs_dir_ent;
int dvd_image_data_max;
_anon1 dvd_image_data[0];

void gdFsClose(GDS_FS_HANDLE* gdfs);
GDS_FS_DIRREC_TBL* gdFsCreateDirhn();
void gdFsFinish();
int gdFsGetDirInfo(char* name, GDS_FS_DIRINFO* dirinfo);
int gdFsGetDrvStat();
int gdFsGetFileSize(GDS_FS_HANDLE* gdfs, int* fsize);
int gdFsInit(int max_open, void* gdfs_work, int max_dirent, void* dirbuf);
GDS_FS_HANDLE* gdFsOpen(char* fname);
int gdFsReqDrvStat();
int gdFsSetDir();
void gdFsEntryErrFuncAll();
int gdFsLoadDir();
int gdFsRead(GDS_FS_HANDLE* gdfs, int nsct, void* buf);

// 
// Start address: 0x2d8d50
void gdFsClose(GDS_FS_HANDLE* gdfs)
{
	// Line 71, Address: 0x2d8d50, Func Offset: 0
	// Line 79, Address: 0x2d8d54, Func Offset: 0x4
	// Line 80, Address: 0x2d8d58, Func Offset: 0x8
	// Line 82, Address: 0x2d8d5c, Func Offset: 0xc
	// Func End, Address: 0x2d8d64, Func Offset: 0x14
}

// 
// Start address: 0x2d8d70
GDS_FS_DIRREC_TBL* gdFsCreateDirhn()
{
	// Line 106, Address: 0x2d8d70, Func Offset: 0
	// Line 107, Address: 0x2d8d74, Func Offset: 0x4
	// Func End, Address: 0x2d8d7c, Func Offset: 0xc
}

// 
// Start address: 0x2d8d80
void gdFsFinish()
{
	// Line 132, Address: 0x2d8d80, Func Offset: 0
	// Func End, Address: 0x2d8d88, Func Offset: 0x8
}

// 
// Start address: 0x2d8d90
int gdFsGetDirInfo(char* name, GDS_FS_DIRINFO* dirinfo)
{
	char read_name[256];
	int i;
	// Line 156, Address: 0x2d8d90, Func Offset: 0
	// Line 161, Address: 0x2d8db0, Func Offset: 0x20
	// Line 163, Address: 0x2d8dc8, Func Offset: 0x38
	// Line 164, Address: 0x2d8de8, Func Offset: 0x58
	// Line 165, Address: 0x2d8dec, Func Offset: 0x5c
	// Line 167, Address: 0x2d8df4, Func Offset: 0x64
	// Line 169, Address: 0x2d8dfc, Func Offset: 0x6c
	// Line 170, Address: 0x2d8e18, Func Offset: 0x88
	// Line 174, Address: 0x2d8e20, Func Offset: 0x90
	// Line 177, Address: 0x2d8e2c, Func Offset: 0x9c
	// Line 179, Address: 0x2d8e4c, Func Offset: 0xbc
	// Line 182, Address: 0x2d8e68, Func Offset: 0xd8
	// Line 179, Address: 0x2d8e6c, Func Offset: 0xdc
	// Line 180, Address: 0x2d8e74, Func Offset: 0xe4
	// Line 179, Address: 0x2d8e78, Func Offset: 0xe8
	// Line 180, Address: 0x2d8e7c, Func Offset: 0xec
	// Line 181, Address: 0x2d8e88, Func Offset: 0xf8
	// Line 180, Address: 0x2d8e8c, Func Offset: 0xfc
	// Line 181, Address: 0x2d8e90, Func Offset: 0x100
	// Line 182, Address: 0x2d8e9c, Func Offset: 0x10c
	// Line 184, Address: 0x2d8ea8, Func Offset: 0x118
	// Line 185, Address: 0x2d8ec8, Func Offset: 0x138
	// Line 186, Address: 0x2d8ecc, Func Offset: 0x13c
	// Func End, Address: 0x2d8ee8, Func Offset: 0x158
}

// 
// Start address: 0x2d8ef0
int gdFsGetDrvStat()
{
	// Line 260, Address: 0x2d8ef0, Func Offset: 0
	// Func End, Address: 0x2d8ef8, Func Offset: 0x8
}

// 
// Start address: 0x2d8f00
int gdFsGetFileSize(GDS_FS_HANDLE* gdfs, int* fsize)
{
	// Line 284, Address: 0x2d8f00, Func Offset: 0
	// Line 286, Address: 0x2d8f08, Func Offset: 0x8
	// Line 291, Address: 0x2d8f10, Func Offset: 0x10
	// Line 293, Address: 0x2d8f14, Func Offset: 0x14
	// Line 291, Address: 0x2d8f18, Func Offset: 0x18
	// Line 295, Address: 0x2d8f1c, Func Offset: 0x1c
	// Func End, Address: 0x2d8f24, Func Offset: 0x24
}

// 
// Start address: 0x2d8f30
int gdFsInit(int max_open, void* gdfs_work, int max_dirent, void* dirbuf)
{
	int loop;
	int loop;
	_anon0 file_read_mode;
	int file_count;
	int file_size;
	int sector_size;
	int sector_top;
	int link_file_max;
	unsigned int j;
	unsigned int i;
	_anon2 file_data;
	char read_f_name[2048];
	char local_sector_buffer[2048];
	// Line 319, Address: 0x2d8f30, Func Offset: 0
	// Line 330, Address: 0x2d8f4c, Func Offset: 0x1c
	// Line 319, Address: 0x2d8f54, Func Offset: 0x24
	// Line 330, Address: 0x2d8f58, Func Offset: 0x28
	// Line 349, Address: 0x2d8f60, Func Offset: 0x30
	// Line 330, Address: 0x2d8f68, Func Offset: 0x38
	// Line 349, Address: 0x2d8f6c, Func Offset: 0x3c
	// Line 348, Address: 0x2d8f70, Func Offset: 0x40
	// Line 362, Address: 0x2d8f74, Func Offset: 0x44
	// Line 348, Address: 0x2d8f78, Func Offset: 0x48
	// Line 362, Address: 0x2d8f7c, Func Offset: 0x4c
	// Line 351, Address: 0x2d8f80, Func Offset: 0x50
	// Line 365, Address: 0x2d8f88, Func Offset: 0x58
	// Line 369, Address: 0x2d8f8c, Func Offset: 0x5c
	// Line 351, Address: 0x2d8f90, Func Offset: 0x60
	// Line 352, Address: 0x2d8f94, Func Offset: 0x64
	// Line 353, Address: 0x2d8fa0, Func Offset: 0x70
	// Line 354, Address: 0x2d8fac, Func Offset: 0x7c
	// Line 355, Address: 0x2d8fb8, Func Offset: 0x88
	// Line 356, Address: 0x2d8fc4, Func Offset: 0x94
	// Line 357, Address: 0x2d8fd0, Func Offset: 0xa0
	// Line 358, Address: 0x2d8fdc, Func Offset: 0xac
	// Line 359, Address: 0x2d8fe8, Func Offset: 0xb8
	// Line 360, Address: 0x2d8ff4, Func Offset: 0xc4
	// Line 361, Address: 0x2d9000, Func Offset: 0xd0
	// Line 362, Address: 0x2d900c, Func Offset: 0xdc
	// Line 363, Address: 0x2d9018, Func Offset: 0xe8
	// Line 364, Address: 0x2d9024, Func Offset: 0xf4
	// Line 365, Address: 0x2d9030, Func Offset: 0x100
	// Line 366, Address: 0x2d903c, Func Offset: 0x10c
	// Line 367, Address: 0x2d9048, Func Offset: 0x118
	// Line 369, Address: 0x2d9050, Func Offset: 0x120
	// Line 370, Address: 0x2d9058, Func Offset: 0x128
	// Line 371, Address: 0x2d9064, Func Offset: 0x134
	// Line 370, Address: 0x2d9068, Func Offset: 0x138
	// Line 371, Address: 0x2d9070, Func Offset: 0x140
	// Line 373, Address: 0x2d907c, Func Offset: 0x14c
	// Line 374, Address: 0x2d9084, Func Offset: 0x154
	// Line 398, Address: 0x2d90a0, Func Offset: 0x170
	// Line 374, Address: 0x2d90a4, Func Offset: 0x174
	// Line 375, Address: 0x2d90ac, Func Offset: 0x17c
	// Line 376, Address: 0x2d90bc, Func Offset: 0x18c
	// Line 377, Address: 0x2d90cc, Func Offset: 0x19c
	// Line 378, Address: 0x2d90dc, Func Offset: 0x1ac
	// Line 379, Address: 0x2d90ec, Func Offset: 0x1bc
	// Line 380, Address: 0x2d90fc, Func Offset: 0x1cc
	// Line 381, Address: 0x2d910c, Func Offset: 0x1dc
	// Line 382, Address: 0x2d911c, Func Offset: 0x1ec
	// Line 383, Address: 0x2d912c, Func Offset: 0x1fc
	// Line 384, Address: 0x2d913c, Func Offset: 0x20c
	// Line 385, Address: 0x2d914c, Func Offset: 0x21c
	// Line 386, Address: 0x2d915c, Func Offset: 0x22c
	// Line 387, Address: 0x2d916c, Func Offset: 0x23c
	// Line 388, Address: 0x2d917c, Func Offset: 0x24c
	// Line 389, Address: 0x2d918c, Func Offset: 0x25c
	// Line 390, Address: 0x2d919c, Func Offset: 0x26c
	// Line 391, Address: 0x2d91ac, Func Offset: 0x27c
	// Line 392, Address: 0x2d91bc, Func Offset: 0x28c
	// Line 393, Address: 0x2d91cc, Func Offset: 0x29c
	// Line 394, Address: 0x2d91dc, Func Offset: 0x2ac
	// Line 395, Address: 0x2d91ec, Func Offset: 0x2bc
	// Line 396, Address: 0x2d91fc, Func Offset: 0x2cc
	// Line 397, Address: 0x2d920c, Func Offset: 0x2dc
	// Line 398, Address: 0x2d921c, Func Offset: 0x2ec
	// Line 401, Address: 0x2d922c, Func Offset: 0x2fc
	// Line 404, Address: 0x2d9234, Func Offset: 0x304
	// Line 402, Address: 0x2d923c, Func Offset: 0x30c
	// Line 409, Address: 0x2d9240, Func Offset: 0x310
	// Line 402, Address: 0x2d9244, Func Offset: 0x314
	// Line 404, Address: 0x2d924c, Func Offset: 0x31c
	// Line 405, Address: 0x2d9250, Func Offset: 0x320
	// Line 406, Address: 0x2d925c, Func Offset: 0x32c
	// Line 409, Address: 0x2d9264, Func Offset: 0x334
	// Line 411, Address: 0x2d926c, Func Offset: 0x33c
	// Line 416, Address: 0x2d9288, Func Offset: 0x358
	// Line 411, Address: 0x2d928c, Func Offset: 0x35c
	// Line 412, Address: 0x2d9294, Func Offset: 0x364
	// Line 413, Address: 0x2d92a4, Func Offset: 0x374
	// Line 414, Address: 0x2d92b4, Func Offset: 0x384
	// Line 415, Address: 0x2d92c4, Func Offset: 0x394
	// Line 416, Address: 0x2d92d4, Func Offset: 0x3a4
	// Line 429, Address: 0x2d92e4, Func Offset: 0x3b4
	// Line 432, Address: 0x2d92ec, Func Offset: 0x3bc
	// Line 433, Address: 0x2d92f0, Func Offset: 0x3c0
	// Line 435, Address: 0x2d92f8, Func Offset: 0x3c8
	// Line 437, Address: 0x2d9300, Func Offset: 0x3d0
	// Line 438, Address: 0x2d934c, Func Offset: 0x41c
	// Line 440, Address: 0x2d9380, Func Offset: 0x450
	// Line 441, Address: 0x2d93ac, Func Offset: 0x47c
	// Line 443, Address: 0x2d93c0, Func Offset: 0x490
	// Line 441, Address: 0x2d93c8, Func Offset: 0x498
	// Line 443, Address: 0x2d93cc, Func Offset: 0x49c
	// Line 441, Address: 0x2d93d0, Func Offset: 0x4a0
	// Line 443, Address: 0x2d93d4, Func Offset: 0x4a4
	// Line 449, Address: 0x2d93f0, Func Offset: 0x4c0
	// Line 454, Address: 0x2d93f8, Func Offset: 0x4c8
	// Line 455, Address: 0x2d9400, Func Offset: 0x4d0
	// Line 456, Address: 0x2d9404, Func Offset: 0x4d4
	// Line 457, Address: 0x2d9408, Func Offset: 0x4d8
	// Line 458, Address: 0x2d940c, Func Offset: 0x4dc
	// Line 459, Address: 0x2d9410, Func Offset: 0x4e0
	// Line 460, Address: 0x2d9424, Func Offset: 0x4f4
	// Line 461, Address: 0x2d9434, Func Offset: 0x504
	// Line 475, Address: 0x2d944c, Func Offset: 0x51c
	// Line 478, Address: 0x2d9468, Func Offset: 0x538
	// Line 482, Address: 0x2d9488, Func Offset: 0x558
	// Line 478, Address: 0x2d948c, Func Offset: 0x55c
	// Line 482, Address: 0x2d9490, Func Offset: 0x560
	// Line 478, Address: 0x2d9494, Func Offset: 0x564
	// Line 479, Address: 0x2d9498, Func Offset: 0x568
	// Line 482, Address: 0x2d94a0, Func Offset: 0x570
	// Line 479, Address: 0x2d94a4, Func Offset: 0x574
	// Line 482, Address: 0x2d94a8, Func Offset: 0x578
	// Line 479, Address: 0x2d94b0, Func Offset: 0x580
	// Line 480, Address: 0x2d94b8, Func Offset: 0x588
	// Line 481, Address: 0x2d94c8, Func Offset: 0x598
	// Line 482, Address: 0x2d94d8, Func Offset: 0x5a8
	// Line 492, Address: 0x2d94f0, Func Offset: 0x5c0
	// Line 496, Address: 0x2d94f8, Func Offset: 0x5c8
	// Line 497, Address: 0x2d9500, Func Offset: 0x5d0
	// Line 498, Address: 0x2d9504, Func Offset: 0x5d4
	// Line 499, Address: 0x2d9508, Func Offset: 0x5d8
	// Line 500, Address: 0x2d950c, Func Offset: 0x5dc
	// Line 501, Address: 0x2d9510, Func Offset: 0x5e0
	// Line 502, Address: 0x2d9524, Func Offset: 0x5f4
	// Line 505, Address: 0x2d9544, Func Offset: 0x614
	// Line 508, Address: 0x2d954c, Func Offset: 0x61c
	// Line 513, Address: 0x2d955c, Func Offset: 0x62c
	// Line 518, Address: 0x2d9564, Func Offset: 0x634
	// Line 515, Address: 0x2d9568, Func Offset: 0x638
	// Line 518, Address: 0x2d956c, Func Offset: 0x63c
	// Line 521, Address: 0x2d9574, Func Offset: 0x644
	// Line 524, Address: 0x2d9578, Func Offset: 0x648
	// Line 521, Address: 0x2d957c, Func Offset: 0x64c
	// Line 524, Address: 0x2d9588, Func Offset: 0x658
	// Line 522, Address: 0x2d95b0, Func Offset: 0x680
	// Line 525, Address: 0x2d95b4, Func Offset: 0x684
	// Line 522, Address: 0x2d95bc, Func Offset: 0x68c
	// Line 528, Address: 0x2d95c0, Func Offset: 0x690
	// Line 525, Address: 0x2d95d0, Func Offset: 0x6a0
	// Line 526, Address: 0x2d95d8, Func Offset: 0x6a8
	// Line 528, Address: 0x2d95e0, Func Offset: 0x6b0
	// Line 526, Address: 0x2d95ec, Func Offset: 0x6bc
	// Line 527, Address: 0x2d95f4, Func Offset: 0x6c4
	// Line 528, Address: 0x2d9604, Func Offset: 0x6d4
	// Line 531, Address: 0x2d9624, Func Offset: 0x6f4
	// Line 534, Address: 0x2d9628, Func Offset: 0x6f8
	// Line 535, Address: 0x2d962c, Func Offset: 0x6fc
	// Line 536, Address: 0x2d963c, Func Offset: 0x70c
	// Line 538, Address: 0x2d9644, Func Offset: 0x714
	// Line 542, Address: 0x2d9664, Func Offset: 0x734
	// Line 538, Address: 0x2d9668, Func Offset: 0x738
	// Line 542, Address: 0x2d966c, Func Offset: 0x73c
	// Line 538, Address: 0x2d9670, Func Offset: 0x740
	// Line 539, Address: 0x2d9674, Func Offset: 0x744
	// Line 542, Address: 0x2d967c, Func Offset: 0x74c
	// Line 539, Address: 0x2d9680, Func Offset: 0x750
	// Line 542, Address: 0x2d9684, Func Offset: 0x754
	// Line 539, Address: 0x2d968c, Func Offset: 0x75c
	// Line 540, Address: 0x2d9694, Func Offset: 0x764
	// Line 541, Address: 0x2d96a4, Func Offset: 0x774
	// Line 542, Address: 0x2d96b4, Func Offset: 0x784
	// Line 545, Address: 0x2d96cc, Func Offset: 0x79c
	// Line 547, Address: 0x2d96d0, Func Offset: 0x7a0
	// Line 670, Address: 0x2d96ec, Func Offset: 0x7bc
	// Line 672, Address: 0x2d96f4, Func Offset: 0x7c4
	// Line 670, Address: 0x2d96f8, Func Offset: 0x7c8
	// Line 673, Address: 0x2d96fc, Func Offset: 0x7cc
	// Func End, Address: 0x2d9720, Func Offset: 0x7f0
}

// 
// Start address: 0x2d9720
GDS_FS_HANDLE* gdFsOpen(char* fname)
{
	char read_name[256];
	int j;
	int i;
	// Line 695, Address: 0x2d9720, Func Offset: 0
	// Line 701, Address: 0x2d9738, Func Offset: 0x18
	// Line 703, Address: 0x2d9750, Func Offset: 0x30
	// Line 704, Address: 0x2d9770, Func Offset: 0x50
	// Line 705, Address: 0x2d9774, Func Offset: 0x54
	// Line 707, Address: 0x2d977c, Func Offset: 0x5c
	// Line 709, Address: 0x2d9784, Func Offset: 0x64
	// Line 710, Address: 0x2d97a0, Func Offset: 0x80
	// Line 714, Address: 0x2d97a8, Func Offset: 0x88
	// Line 717, Address: 0x2d97b4, Func Offset: 0x94
	// Line 720, Address: 0x2d97d4, Func Offset: 0xb4
	// Line 723, Address: 0x2d97f4, Func Offset: 0xd4
	// Line 725, Address: 0x2d9800, Func Offset: 0xe0
	// Line 729, Address: 0x2d9820, Func Offset: 0x100
	// Line 730, Address: 0x2d9850, Func Offset: 0x130
	// Line 729, Address: 0x2d9854, Func Offset: 0x134
	// Line 730, Address: 0x2d9858, Func Offset: 0x138
	// Line 731, Address: 0x2d9870, Func Offset: 0x150
	// Line 730, Address: 0x2d9874, Func Offset: 0x154
	// Line 731, Address: 0x2d9878, Func Offset: 0x158
	// Line 751, Address: 0x2d989c, Func Offset: 0x17c
	// Line 753, Address: 0x2d98b0, Func Offset: 0x190
	// Line 754, Address: 0x2d98c4, Func Offset: 0x1a4
	// Line 753, Address: 0x2d98c8, Func Offset: 0x1a8
	// Line 755, Address: 0x2d98cc, Func Offset: 0x1ac
	// Line 756, Address: 0x2d98e8, Func Offset: 0x1c8
	// Func End, Address: 0x2d9900, Func Offset: 0x1e0
}

// 
// Start address: 0x2d9900
int gdFsReqDrvStat()
{
	// Line 806, Address: 0x2d9900, Func Offset: 0
	// Func End, Address: 0x2d9908, Func Offset: 0x8
}

// 
// Start address: 0x2d9910
int gdFsSetDir()
{
	// Line 833, Address: 0x2d9910, Func Offset: 0
	// Func End, Address: 0x2d9918, Func Offset: 0x8
}

// 
// Start address: 0x2d9920
void gdFsEntryErrFuncAll()
{
	// Line 859, Address: 0x2d9920, Func Offset: 0
	// Func End, Address: 0x2d9928, Func Offset: 0x8
}

// 
// Start address: 0x2d9930
int gdFsLoadDir()
{
	// Line 884, Address: 0x2d9930, Func Offset: 0
	// Func End, Address: 0x2d9938, Func Offset: 0x8
}

// 
// Start address: 0x2d9940
int gdFsRead(GDS_FS_HANDLE* gdfs, int nsct, void* buf)
{
	int loop;
	_anon0 read_mode;
	// Line 907, Address: 0x2d9940, Func Offset: 0
	// Line 913, Address: 0x2d9954, Func Offset: 0x14
	// Line 912, Address: 0x2d9958, Func Offset: 0x18
	// Line 913, Address: 0x2d995c, Func Offset: 0x1c
	// Line 924, Address: 0x2d996c, Func Offset: 0x2c
	// Line 928, Address: 0x2d9974, Func Offset: 0x34
	// Line 929, Address: 0x2d997c, Func Offset: 0x3c
	// Line 930, Address: 0x2d9980, Func Offset: 0x40
	// Line 931, Address: 0x2d9984, Func Offset: 0x44
	// Line 932, Address: 0x2d9988, Func Offset: 0x48
	// Line 933, Address: 0x2d998c, Func Offset: 0x4c
	// Line 934, Address: 0x2d999c, Func Offset: 0x5c
	// Line 938, Address: 0x2d99bc, Func Offset: 0x7c
	// Line 941, Address: 0x2d99c4, Func Offset: 0x84
	// Line 956, Address: 0x2d99d4, Func Offset: 0x94
	// Line 955, Address: 0x2d99e4, Func Offset: 0xa4
	// Line 956, Address: 0x2d99e8, Func Offset: 0xa8
	// Func End, Address: 0x2d99f0, Func Offset: 0xb0
}

