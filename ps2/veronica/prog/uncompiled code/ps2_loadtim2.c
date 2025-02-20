typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct tagTIM2_FILEHEADER;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;


typedef unsigned long type_0[64];
typedef unsigned long type_1[64];
typedef unsigned int type_2[4];
typedef int type_3[3];
typedef char type_4[4];
typedef unsigned long type_5[64];
typedef char type_6[8];
typedef int type_7[5];
typedef int type_8[3];
typedef unsigned int type_9[2];
typedef unsigned int type_10[2];
typedef unsigned long type_11[64];
typedef int type_12[3];
typedef unsigned long type_13[64];
typedef unsigned char type_14[1024];

struct _anon0
{
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned int GsTex0[2];
	unsigned int GsTex1[2];
	unsigned int GsRegs;
	unsigned int GsTexClut;
};

struct _anon1
{
	_anon8 giftag0;
	_anon3 bitbltbuf;
	long bitbltbufaddr;
	_anon6 trxpos;
	long trxposaddr;
	_anon7 trxreg;
	long trxregaddr;
	_anon4 trxdir;
	long trxdiraddr;
	_anon8 giftag1;
};

struct _anon2
{
	unsigned long pad00;
};

struct _anon3
{
	struct
	{
		unsigned long SBP : 14;
		unsigned long pad14 : 2;
		unsigned long SBW : 6;
		unsigned long pad22 : 2;
		unsigned long SPSM : 6;
		unsigned long pad30 : 2;
		unsigned long DBP : 14;
		unsigned long pad46 : 2;
		unsigned long DBW : 6;
		unsigned long pad54 : 2;
		unsigned long DPSM : 6;
		unsigned long pad62 : 2;
	};
};

struct _anon4
{
	struct
	{
		unsigned long XDR : 2;
		unsigned long pad02 : 62;
	};
};

struct _anon5
{
	unsigned int vifcode[4];
	_anon8 giftag;
	_anon3 bitbltbuf;
	long bitbltbufaddr;
	_anon6 trxpos;
	long trxposaddr;
	_anon7 trxreg;
	long trxregaddr;
	_anon2 finish;
	long finishaddr;
	_anon4 trxdir;
	long trxdiraddr;
};

struct tagTIM2_FILEHEADER
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	char Reserved[8];
};

struct _anon6
{
	struct
	{
		unsigned long SSAX : 11;
		unsigned long pad11 : 5;
		unsigned long SSAY : 11;
		unsigned long pad27 : 5;
		unsigned long DSAX : 11;
		unsigned long pad43 : 5;
		unsigned long DSAY : 11;
		unsigned long DIR : 2;
		unsigned long pad61 : 3;
	};
};

struct _anon7
{
	struct
	{
		unsigned long RRW : 12;
		unsigned long pad12 : 20;
		unsigned long RRH : 12;
		unsigned long pad44 : 20;
	};
};

struct _anon8
{
	struct
	{
		unsigned long NLOOP : 15;
		unsigned long EOP : 1;
		unsigned long pad16 : 16;
		unsigned long id : 14;
		unsigned long PRE : 1;
		unsigned long PRIM : 11;
		unsigned long FLG : 2;
		unsigned long NREG : 4;
	};
	struct
	{
		unsigned long REGS0 : 4;
		unsigned long REGS1 : 4;
		unsigned long REGS2 : 4;
		unsigned long REGS3 : 4;
		unsigned long REGS4 : 4;
		unsigned long REGS5 : 4;
		unsigned long REGS6 : 4;
		unsigned long REGS7 : 4;
		unsigned long REGS8 : 4;
		unsigned long REGS9 : 4;
		unsigned long REGS10 : 4;
		unsigned long REGS11 : 4;
		unsigned long REGS12 : 4;
		unsigned long REGS13 : 4;
		unsigned long REGS14 : 4;
		unsigned long REGS15 : 4;
	};
};

unsigned char clear_buff[1024];

int Tim2CalcBufWidth(int psm, int w);
void Set_GsTex(_anon0* ph, unsigned long send_image_adr, unsigned long send_clut_adr);
<unknown fundamental type (0xa510)>* MakeRenderTexHeader(void* tex_adr);
void StoreRenderTex(void* tex_adr);
int LoadToVram(unsigned long tbp, <unknown fundamental type (0xa510)>* addr, int tbw, int psm, int pos, int width, int height, int size);
int Send_1024_Clut_data(void* clt_adr, unsigned long send_clut_adr);
int Send_Tim2_dataEx(void* tim2_top_adr, unsigned long send_image_adr, unsigned long send_clut_adr);
int Clut_Load_Func(_anon0* ph, unsigned long clut_addr);
int P32_Image_Load(_anon0* ph, unsigned long image_addr);
int Tim2_Image_Load(_anon0* ph, unsigned long image_addr);
void Ps2PxlconvCheck(void* timadr);
void SyncPath();
void D2_SyncTag();
void loadImage(void* tags);
void ClearVram();

// 
// Start address: 0x2e6be0
int Tim2CalcBufWidth(int psm, int w)
{
	// Line 304, Address: 0x2e6be0, Func Offset: 0
	// Line 317, Address: 0x2e6c80, Func Offset: 0xa0
	// Line 322, Address: 0x2e6c8c, Func Offset: 0xac
	// Line 323, Address: 0x2e6c94, Func Offset: 0xb4
	// Line 324, Address: 0x2e6ca0, Func Offset: 0xc0
	// Line 326, Address: 0x2e6ca4, Func Offset: 0xc4
	// Line 329, Address: 0x2e6cb0, Func Offset: 0xd0
	// Line 330, Address: 0x2e6cb4, Func Offset: 0xd4
	// Func End, Address: 0x2e6cbc, Func Offset: 0xdc
}

// 
// Start address: 0x2e6cc0
void Set_GsTex(_anon0* ph, unsigned long send_image_adr, unsigned long send_clut_adr)
{
	unsigned int i;
	// Line 430, Address: 0x2e6cc0, Func Offset: 0
	// Line 433, Address: 0x2e6cd0, Func Offset: 0x10
	// Line 437, Address: 0x2e6cd4, Func Offset: 0x14
	// Line 433, Address: 0x2e6cdc, Func Offset: 0x1c
	// Line 434, Address: 0x2e6cf4, Func Offset: 0x34
	// Line 435, Address: 0x2e6cfc, Func Offset: 0x3c
	// Line 434, Address: 0x2e6d04, Func Offset: 0x44
	// Line 436, Address: 0x2e6d14, Func Offset: 0x54
	// Line 437, Address: 0x2e6d1c, Func Offset: 0x5c
	// Line 435, Address: 0x2e6d24, Func Offset: 0x64
	// Line 437, Address: 0x2e6d2c, Func Offset: 0x6c
	// Line 436, Address: 0x2e6d30, Func Offset: 0x70
	// Line 435, Address: 0x2e6d34, Func Offset: 0x74
	// Line 436, Address: 0x2e6d40, Func Offset: 0x80
	// Line 437, Address: 0x2e6d44, Func Offset: 0x84
	// Line 438, Address: 0x2e6d54, Func Offset: 0x94
	// Line 436, Address: 0x2e6d58, Func Offset: 0x98
	// Line 437, Address: 0x2e6d64, Func Offset: 0xa4
	// Line 438, Address: 0x2e6d68, Func Offset: 0xa8
	// Line 439, Address: 0x2e6d70, Func Offset: 0xb0
	// Line 437, Address: 0x2e6d74, Func Offset: 0xb4
	// Line 438, Address: 0x2e6d80, Func Offset: 0xc0
	// Line 439, Address: 0x2e6d84, Func Offset: 0xc4
	// Line 441, Address: 0x2e6d88, Func Offset: 0xc8
	// Line 438, Address: 0x2e6d90, Func Offset: 0xd0
	// Line 439, Address: 0x2e6d9c, Func Offset: 0xdc
	// Line 441, Address: 0x2e6dac, Func Offset: 0xec
	// Line 443, Address: 0x2e6dd8, Func Offset: 0x118
	// Line 444, Address: 0x2e6de0, Func Offset: 0x120
	// Line 445, Address: 0x2e6dec, Func Offset: 0x12c
	// Line 446, Address: 0x2e6df4, Func Offset: 0x134
	// Line 447, Address: 0x2e6dfc, Func Offset: 0x13c
	// Line 450, Address: 0x2e6e18, Func Offset: 0x158
	// Line 452, Address: 0x2e6e48, Func Offset: 0x188
	// Line 453, Address: 0x2e6e50, Func Offset: 0x190
	// Line 454, Address: 0x2e6e5c, Func Offset: 0x19c
	// Line 455, Address: 0x2e6e64, Func Offset: 0x1a4
	// Line 456, Address: 0x2e6e6c, Func Offset: 0x1ac
	// Line 459, Address: 0x2e6e98, Func Offset: 0x1d8
	// Line 461, Address: 0x2e6ee0, Func Offset: 0x220
	// Line 462, Address: 0x2e6ef4, Func Offset: 0x234
	// Line 464, Address: 0x2e6efc, Func Offset: 0x23c
	// Line 465, Address: 0x2e6f10, Func Offset: 0x250
	// Line 467, Address: 0x2e6f18, Func Offset: 0x258
	// Line 468, Address: 0x2e6f30, Func Offset: 0x270
	// Line 470, Address: 0x2e6f38, Func Offset: 0x278
	// Line 471, Address: 0x2e6f4c, Func Offset: 0x28c
	// Line 473, Address: 0x2e6f54, Func Offset: 0x294
	// Line 476, Address: 0x2e6f6c, Func Offset: 0x2ac
	// Line 477, Address: 0x2e6f84, Func Offset: 0x2c4
	// Line 478, Address: 0x2e6fc0, Func Offset: 0x300
	// Func End, Address: 0x2e6fd4, Func Offset: 0x314
}

// 
// Start address: 0x2e6fe0
<unknown fundamental type (0xa510)>* MakeRenderTexHeader(void* tex_adr)
{
	unsigned int loop;
	unsigned int psize;
	unsigned int fsize;
	unsigned char* work;
	_anon0* pHead;
	tagTIM2_FILEHEADER* fHead;
	// Line 1446, Address: 0x2e6fe0, Func Offset: 0
	// Line 1463, Address: 0x2e6ff0, Func Offset: 0x10
	// Line 1455, Address: 0x2e6ff4, Func Offset: 0x14
	// Line 1463, Address: 0x2e6ff8, Func Offset: 0x18
	// Line 1456, Address: 0x2e6ffc, Func Offset: 0x1c
	// Line 1459, Address: 0x2e7000, Func Offset: 0x20
	// Line 1463, Address: 0x2e7004, Func Offset: 0x24
	// Line 1466, Address: 0x2e700c, Func Offset: 0x2c
	// Line 1469, Address: 0x2e7014, Func Offset: 0x34
	// Line 1472, Address: 0x2e701c, Func Offset: 0x3c
	// Line 1474, Address: 0x2e7020, Func Offset: 0x40
	// Line 1475, Address: 0x2e7024, Func Offset: 0x44
	// Line 1476, Address: 0x2e7028, Func Offset: 0x48
	// Line 1475, Address: 0x2e702c, Func Offset: 0x4c
	// Line 1476, Address: 0x2e7030, Func Offset: 0x50
	// Line 1479, Address: 0x2e7040, Func Offset: 0x60
	// Line 1480, Address: 0x2e704c, Func Offset: 0x6c
	// Line 1482, Address: 0x2e7050, Func Offset: 0x70
	// Line 1484, Address: 0x2e7054, Func Offset: 0x74
	// Line 1485, Address: 0x2e705c, Func Offset: 0x7c
	// Line 1486, Address: 0x2e7060, Func Offset: 0x80
	// Line 1487, Address: 0x2e7064, Func Offset: 0x84
	// Line 1496, Address: 0x2e7068, Func Offset: 0x88
	// Line 1500, Address: 0x2e7078, Func Offset: 0x98
	// Line 1508, Address: 0x2e707c, Func Offset: 0x9c
	// Line 1511, Address: 0x2e7080, Func Offset: 0xa0
	// Line 1514, Address: 0x2e7084, Func Offset: 0xa4
	// Line 1520, Address: 0x2e7088, Func Offset: 0xa8
	// Line 1517, Address: 0x2e708c, Func Offset: 0xac
	// Line 1520, Address: 0x2e7090, Func Offset: 0xb0
	// Line 1531, Address: 0x2e7094, Func Offset: 0xb4
	// Line 1523, Address: 0x2e7098, Func Offset: 0xb8
	// Line 1531, Address: 0x2e709c, Func Offset: 0xbc
	// Line 1534, Address: 0x2e70a0, Func Offset: 0xc0
	// Line 1537, Address: 0x2e70a8, Func Offset: 0xc8
	// Line 1541, Address: 0x2e70ac, Func Offset: 0xcc
	// Line 1542, Address: 0x2e70bc, Func Offset: 0xdc
	// Line 1541, Address: 0x2e70c0, Func Offset: 0xe0
	// Line 1542, Address: 0x2e70cc, Func Offset: 0xec
	// Line 1545, Address: 0x2e70d4, Func Offset: 0xf4
	// Line 1542, Address: 0x2e70dc, Func Offset: 0xfc
	// Line 1548, Address: 0x2e70e8, Func Offset: 0x108
	// Line 1545, Address: 0x2e70ec, Func Offset: 0x10c
	// Line 1548, Address: 0x2e70f0, Func Offset: 0x110
	// Line 1560, Address: 0x2e70f4, Func Offset: 0x114
	// Line 1548, Address: 0x2e70f8, Func Offset: 0x118
	// Line 1545, Address: 0x2e70fc, Func Offset: 0x11c
	// Line 1548, Address: 0x2e7108, Func Offset: 0x128
	// Line 1556, Address: 0x2e7118, Func Offset: 0x138
	// Line 1548, Address: 0x2e711c, Func Offset: 0x13c
	// Line 1556, Address: 0x2e7120, Func Offset: 0x140
	// Line 1548, Address: 0x2e7124, Func Offset: 0x144
	// Line 1556, Address: 0x2e7130, Func Offset: 0x150
	// Line 1560, Address: 0x2e7138, Func Offset: 0x158
	// Line 1556, Address: 0x2e7140, Func Offset: 0x160
	// Line 1560, Address: 0x2e714c, Func Offset: 0x16c
	// Line 1562, Address: 0x2e715c, Func Offset: 0x17c
	// Line 1565, Address: 0x2e7160, Func Offset: 0x180
	// Line 1564, Address: 0x2e7164, Func Offset: 0x184
	// Line 1565, Address: 0x2e7168, Func Offset: 0x188
	// Func End, Address: 0x2e7178, Func Offset: 0x198
}

// 
// Start address: 0x2e7180
void StoreRenderTex(void* tex_adr)
{
	<unknown fundamental type (0xa510)>* imagetop;
	<unknown fundamental type (0xa510)>* p;
	int l;
	int loop;
	_anon5 gs_simage;
	// Line 1623, Address: 0x2e7180, Func Offset: 0
	// Line 1634, Address: 0x2e7194, Func Offset: 0x14
	// Line 1645, Address: 0x2e719c, Func Offset: 0x1c
	// Line 1634, Address: 0x2e71a0, Func Offset: 0x20
	// Line 1647, Address: 0x2e71a4, Func Offset: 0x24
	// Line 1650, Address: 0x2e71a8, Func Offset: 0x28
	// Line 1652, Address: 0x2e71b0, Func Offset: 0x30
	// Line 1653, Address: 0x2e71c0, Func Offset: 0x40
	// Line 1656, Address: 0x2e71c8, Func Offset: 0x48
	// Line 1659, Address: 0x2e71f4, Func Offset: 0x74
	// Line 1662, Address: 0x2e71fc, Func Offset: 0x7c
	// Line 1663, Address: 0x2e7208, Func Offset: 0x88
	// Line 1665, Address: 0x2e7218, Func Offset: 0x98
	// Line 1666, Address: 0x2e7220, Func Offset: 0xa0
	// Func End, Address: 0x2e723c, Func Offset: 0xbc
}

// 
// Start address: 0x2e7240
int LoadToVram(unsigned long tbp, <unknown fundamental type (0xa510)>* addr, int tbw, int psm, int pos, int width, int height, int size)
{
	unsigned long* pBuff;
	unsigned long data[64];
	// Line 1869, Address: 0x2e7240, Func Offset: 0
	// Line 1873, Address: 0x2e726c, Func Offset: 0x2c
	// Line 1876, Address: 0x2e7298, Func Offset: 0x58
	// Line 1885, Address: 0x2e72a0, Func Offset: 0x60
	// Line 1888, Address: 0x2e72c4, Func Offset: 0x84
	// Line 1891, Address: 0x2e72d0, Func Offset: 0x90
	// Line 1879, Address: 0x2e72e8, Func Offset: 0xa8
	// Line 1882, Address: 0x2e72f4, Func Offset: 0xb4
	// Line 1880, Address: 0x2e7300, Func Offset: 0xc0
	// Line 1882, Address: 0x2e7304, Func Offset: 0xc4
	// Line 1883, Address: 0x2e730c, Func Offset: 0xcc
	// Line 1885, Address: 0x2e7314, Func Offset: 0xd4
	// Line 1886, Address: 0x2e7318, Func Offset: 0xd8
	// Line 1888, Address: 0x2e7320, Func Offset: 0xe0
	// Line 1889, Address: 0x2e7324, Func Offset: 0xe4
	// Line 1891, Address: 0x2e732c, Func Offset: 0xec
	// Line 1892, Address: 0x2e7330, Func Offset: 0xf0
	// Line 1897, Address: 0x2e7338, Func Offset: 0xf8
	// Line 1895, Address: 0x2e733c, Func Offset: 0xfc
	// Line 1894, Address: 0x2e7340, Func Offset: 0x100
	// Line 1895, Address: 0x2e7344, Func Offset: 0x104
	// Line 1897, Address: 0x2e7348, Func Offset: 0x108
	// Line 1900, Address: 0x2e734c, Func Offset: 0x10c
	// Line 1897, Address: 0x2e7354, Func Offset: 0x114
	// Line 1900, Address: 0x2e7364, Func Offset: 0x124
	// Line 1898, Address: 0x2e7378, Func Offset: 0x138
	// Line 1900, Address: 0x2e737c, Func Offset: 0x13c
	// Line 1904, Address: 0x2e7384, Func Offset: 0x144
	// Line 1901, Address: 0x2e7388, Func Offset: 0x148
	// Line 1904, Address: 0x2e738c, Func Offset: 0x14c
	// Line 1906, Address: 0x2e7394, Func Offset: 0x154
	// Line 1905, Address: 0x2e739c, Func Offset: 0x15c
	// Line 1906, Address: 0x2e73a0, Func Offset: 0x160
	// Line 1907, Address: 0x2e73a8, Func Offset: 0x168
	// Line 1909, Address: 0x2e73b0, Func Offset: 0x170
	// Line 1908, Address: 0x2e73b4, Func Offset: 0x174
	// Line 1913, Address: 0x2e73b8, Func Offset: 0x178
	// Line 1916, Address: 0x2e73c0, Func Offset: 0x180
	// Line 1918, Address: 0x2e73cc, Func Offset: 0x18c
	// Line 1917, Address: 0x2e73f4, Func Offset: 0x1b4
	// Line 1918, Address: 0x2e73f8, Func Offset: 0x1b8
	// Func End, Address: 0x2e7400, Func Offset: 0x1c0
}

// 
// Start address: 0x2e7420
int Send_1024_Clut_data(void* clt_adr, unsigned long send_clut_adr)
{
	<unknown fundamental type (0xa510)>* pClut;
	unsigned int clt_lp;
	unsigned int loop;
	unsigned long* pBuff;
	unsigned long data[64];
	// Line 2068, Address: 0x2e7420, Func Offset: 0
	// Line 2075, Address: 0x2e7454, Func Offset: 0x34
	// Line 2078, Address: 0x2e7458, Func Offset: 0x38
	// Line 2080, Address: 0x2e746c, Func Offset: 0x4c
	// Line 2088, Address: 0x2e7488, Func Offset: 0x68
	// Line 2092, Address: 0x2e7490, Func Offset: 0x70
	// Line 2119, Address: 0x2e749c, Func Offset: 0x7c
	// Line 2095, Address: 0x2e74a0, Func Offset: 0x80
	// Line 2093, Address: 0x2e74ac, Func Offset: 0x8c
	// Line 2095, Address: 0x2e74b0, Func Offset: 0x90
	// Line 2096, Address: 0x2e74b8, Func Offset: 0x98
	// Line 2099, Address: 0x2e74c0, Func Offset: 0xa0
	// Line 2098, Address: 0x2e74c4, Func Offset: 0xa4
	// Line 2099, Address: 0x2e74c8, Func Offset: 0xa8
	// Line 2101, Address: 0x2e74cc, Func Offset: 0xac
	// Line 2102, Address: 0x2e74fc, Func Offset: 0xdc
	// Line 2104, Address: 0x2e7504, Func Offset: 0xe4
	// Line 2105, Address: 0x2e7518, Func Offset: 0xf8
	// Line 2108, Address: 0x2e7520, Func Offset: 0x100
	// Line 2107, Address: 0x2e7524, Func Offset: 0x104
	// Line 2108, Address: 0x2e7528, Func Offset: 0x108
	// Line 2110, Address: 0x2e752c, Func Offset: 0x10c
	// Line 2113, Address: 0x2e7540, Func Offset: 0x120
	// Line 2111, Address: 0x2e7554, Func Offset: 0x134
	// Line 2113, Address: 0x2e7558, Func Offset: 0x138
	// Line 2117, Address: 0x2e7560, Func Offset: 0x140
	// Line 2114, Address: 0x2e7564, Func Offset: 0x144
	// Line 2117, Address: 0x2e7568, Func Offset: 0x148
	// Line 2119, Address: 0x2e7570, Func Offset: 0x150
	// Line 2118, Address: 0x2e7574, Func Offset: 0x154
	// Line 2119, Address: 0x2e7578, Func Offset: 0x158
	// Line 2120, Address: 0x2e7580, Func Offset: 0x160
	// Line 2122, Address: 0x2e7588, Func Offset: 0x168
	// Line 2121, Address: 0x2e758c, Func Offset: 0x16c
	// Line 2126, Address: 0x2e7590, Func Offset: 0x170
	// Line 2128, Address: 0x2e7598, Func Offset: 0x178
	// Line 2133, Address: 0x2e75a4, Func Offset: 0x184
	// Line 2134, Address: 0x2e75b4, Func Offset: 0x194
	// Line 2135, Address: 0x2e75c4, Func Offset: 0x1a4
	// Func End, Address: 0x2e75ec, Func Offset: 0x1cc
}

// 
// Start address: 0x2e75f0
int Send_Tim2_dataEx(void* tim2_top_adr, unsigned long send_image_adr, unsigned long send_clut_adr)
{
	_anon0* pPhead;
	// Line 2154, Address: 0x2e75f0, Func Offset: 0
	// Line 2167, Address: 0x2e7604, Func Offset: 0x14
	// Line 2170, Address: 0x2e7620, Func Offset: 0x30
	// Line 2171, Address: 0x2e762c, Func Offset: 0x3c
	// Line 2172, Address: 0x2e7640, Func Offset: 0x50
	// Line 2173, Address: 0x2e764c, Func Offset: 0x5c
	// Line 2178, Address: 0x2e7654, Func Offset: 0x64
	// Line 2182, Address: 0x2e768c, Func Offset: 0x9c
	// Line 2184, Address: 0x2e76a8, Func Offset: 0xb8
	// Line 2186, Address: 0x2e76b4, Func Offset: 0xc4
	// Line 2187, Address: 0x2e76c4, Func Offset: 0xd4
	// Line 2191, Address: 0x2e76cc, Func Offset: 0xdc
	// Line 2193, Address: 0x2e76d8, Func Offset: 0xe8
	// Line 2195, Address: 0x2e76e8, Func Offset: 0xf8
	// Line 2196, Address: 0x2e76ec, Func Offset: 0xfc
	// Func End, Address: 0x2e7704, Func Offset: 0x114
}

// 
// Start address: 0x2e7710
int Clut_Load_Func(_anon0* ph, unsigned long clut_addr)
{
	int h;
	int loop;
	<unknown fundamental type (0xa510)>* pClut;
	// Line 2215, Address: 0x2e7710, Func Offset: 0
	// Line 2221, Address: 0x2e772c, Func Offset: 0x1c
	// Line 2224, Address: 0x2e7734, Func Offset: 0x24
	// Line 2221, Address: 0x2e7744, Func Offset: 0x34
	// Line 2224, Address: 0x2e774c, Func Offset: 0x3c
	// Line 2228, Address: 0x2e7770, Func Offset: 0x60
	// Line 2232, Address: 0x2e777c, Func Offset: 0x6c
	// Line 2235, Address: 0x2e7784, Func Offset: 0x74
	// Line 2236, Address: 0x2e77b8, Func Offset: 0xa8
	// Line 2237, Address: 0x2e77d0, Func Offset: 0xc0
	// Line 2242, Address: 0x2e77d8, Func Offset: 0xc8
	// Line 2245, Address: 0x2e77e4, Func Offset: 0xd4
	// Line 2246, Address: 0x2e77e8, Func Offset: 0xd8
	// Func End, Address: 0x2e7804, Func Offset: 0xf4
}

// 
// Start address: 0x2e7810
int P32_Image_Load(_anon0* ph, unsigned long image_addr)
{
	int size;
	int rrh;
	int rrw;
	int tbw;
	int h;
	int w;
	<unknown fundamental type (0xa510)>* pImage;
	// Line 2261, Address: 0x2e7810, Func Offset: 0
	// Line 2269, Address: 0x2e7818, Func Offset: 0x8
	// Line 2273, Address: 0x2e781c, Func Offset: 0xc
	// Line 2270, Address: 0x2e7820, Func Offset: 0x10
	// Line 2276, Address: 0x2e7824, Func Offset: 0x14
	// Line 2278, Address: 0x2e7828, Func Offset: 0x18
	// Line 2284, Address: 0x2e7834, Func Offset: 0x24
	// Line 2286, Address: 0x2e7844, Func Offset: 0x34
	// Line 2285, Address: 0x2e7848, Func Offset: 0x38
	// Line 2287, Address: 0x2e784c, Func Offset: 0x3c
	// Line 2289, Address: 0x2e7854, Func Offset: 0x44
	// Line 2288, Address: 0x2e7858, Func Offset: 0x48
	// Line 2289, Address: 0x2e785c, Func Offset: 0x4c
	// Line 2292, Address: 0x2e7860, Func Offset: 0x50
	// Line 2295, Address: 0x2e7874, Func Offset: 0x64
	// Line 2294, Address: 0x2e7878, Func Offset: 0x68
	// Line 2295, Address: 0x2e787c, Func Offset: 0x6c
	// Func End, Address: 0x2e7884, Func Offset: 0x74
}

// 
// Start address: 0x2e7890
int Tim2_Image_Load(_anon0* ph, unsigned long image_addr)
{
	int param;
	int tbw;
	int i;
	int l;
	int n;
	int h;
	int w;
	int psm;
	<unknown fundamental type (0xa510)>* p;
	<unknown fundamental type (0xa510)>* pImage;
	int psmtbl[3];
	// Line 2310, Address: 0x2e7890, Func Offset: 0
	// Line 2324, Address: 0x2e78c0, Func Offset: 0x30
	// Line 2327, Address: 0x2e78cc, Func Offset: 0x3c
	// Line 2331, Address: 0x2e78d0, Func Offset: 0x40
	// Line 2328, Address: 0x2e78d4, Func Offset: 0x44
	// Line 2324, Address: 0x2e78d8, Func Offset: 0x48
	// Line 2331, Address: 0x2e78e4, Func Offset: 0x54
	// Line 2337, Address: 0x2e78ec, Func Offset: 0x5c
	// Line 2335, Address: 0x2e78f0, Func Offset: 0x60
	// Line 2337, Address: 0x2e78f4, Func Offset: 0x64
	// Line 2338, Address: 0x2e7900, Func Offset: 0x70
	// Line 2342, Address: 0x2e7910, Func Offset: 0x80
	// Line 2344, Address: 0x2e7938, Func Offset: 0xa8
	// Line 2346, Address: 0x2e793c, Func Offset: 0xac
	// Line 2349, Address: 0x2e7944, Func Offset: 0xb4
	// Line 2351, Address: 0x2e7948, Func Offset: 0xb8
	// Line 2354, Address: 0x2e7950, Func Offset: 0xc0
	// Line 2355, Address: 0x2e7954, Func Offset: 0xc4
	// Line 2359, Address: 0x2e7958, Func Offset: 0xc8
	// Line 2360, Address: 0x2e7970, Func Offset: 0xe0
	// Line 2361, Address: 0x2e7988, Func Offset: 0xf8
	// Line 2363, Address: 0x2e7994, Func Offset: 0x104
	// Line 2365, Address: 0x2e799c, Func Offset: 0x10c
	// Line 2366, Address: 0x2e79ac, Func Offset: 0x11c
	// Line 2375, Address: 0x2e79b0, Func Offset: 0x120
	// Line 2376, Address: 0x2e79ec, Func Offset: 0x15c
	// Line 2377, Address: 0x2e79fc, Func Offset: 0x16c
	// Line 2381, Address: 0x2e7a04, Func Offset: 0x174
	// Line 2384, Address: 0x2e7a2c, Func Offset: 0x19c
	// Line 2383, Address: 0x2e7a54, Func Offset: 0x1c4
	// Line 2384, Address: 0x2e7a58, Func Offset: 0x1c8
	// Func End, Address: 0x2e7a60, Func Offset: 0x1d0
}

// 
// Start address: 0x2e7a60
void Ps2PxlconvCheck(void* timadr)
{
	_anon0* ph;
	// Line 2856, Address: 0x2e7a60, Func Offset: 0
	// Line 2865, Address: 0x2e7a68, Func Offset: 0x8
	// Line 2868, Address: 0x2e7a80, Func Offset: 0x20
	// Line 2872, Address: 0x2e7ab8, Func Offset: 0x58
	// Line 2873, Address: 0x2e7ad4, Func Offset: 0x74
	// Line 2876, Address: 0x2e7adc, Func Offset: 0x7c
	// Func End, Address: 0x2e7ae8, Func Offset: 0x88
}

// 
// Start address: 0x2e7af0
void SyncPath()
{
	unsigned int tmp;
	// Line 2897, Address: 0x2e7af0, Func Offset: 0
	// Line 2899, Address: 0x2e7afc, Func Offset: 0xc
	// Line 2902, Address: 0x2e7b04, Func Offset: 0x14
	// Line 2904, Address: 0x2e7b0c, Func Offset: 0x1c
	// Line 2905, Address: 0x2e7b28, Func Offset: 0x38
	// Line 2909, Address: 0x2e7b2c, Func Offset: 0x3c
	// Line 2913, Address: 0x2e7b40, Func Offset: 0x50
	// Line 2915, Address: 0x2e7b44, Func Offset: 0x54
	// Line 2918, Address: 0x2e7b4c, Func Offset: 0x5c
	// Line 2920, Address: 0x2e7b54, Func Offset: 0x64
	// Line 2921, Address: 0x2e7b70, Func Offset: 0x80
	// Line 2925, Address: 0x2e7b74, Func Offset: 0x84
	// Line 2930, Address: 0x2e7b88, Func Offset: 0x98
	// Line 2937, Address: 0x2e7bb0, Func Offset: 0xc0
	// Line 2938, Address: 0x2e7bb4, Func Offset: 0xc4
	// Line 2939, Address: 0x2e7bb8, Func Offset: 0xc8
	// Line 2945, Address: 0x2e7bcc, Func Offset: 0xdc
	// Line 2947, Address: 0x2e7bf0, Func Offset: 0x100
	// Func End, Address: 0x2e7bf8, Func Offset: 0x108
}

// 
// Start address: 0x2e7c00
void D2_SyncTag()
{
	unsigned int tmp;
	// Line 2967, Address: 0x2e7c00, Func Offset: 0
	// Line 2969, Address: 0x2e7c0c, Func Offset: 0xc
	// Line 2971, Address: 0x2e7c18, Func Offset: 0x18
	// Line 2973, Address: 0x2e7c28, Func Offset: 0x28
	// Line 2975, Address: 0x2e7c30, Func Offset: 0x30
	// Line 2976, Address: 0x2e7c4c, Func Offset: 0x4c
	// Line 2981, Address: 0x2e7c50, Func Offset: 0x50
	// Line 2983, Address: 0x2e7c60, Func Offset: 0x60
	// Func End, Address: 0x2e7c68, Func Offset: 0x68
}

// 
// Start address: 0x2e7c70
void loadImage(void* tags)
{
	// Line 3000, Address: 0x2e7c70, Func Offset: 0
	// Line 3005, Address: 0x2e7c78, Func Offset: 0x8
	// Line 3006, Address: 0x2e7c94, Func Offset: 0x24
	// Line 3011, Address: 0x2e7c98, Func Offset: 0x28
	// Line 3013, Address: 0x2e7ca8, Func Offset: 0x38
	// Line 3015, Address: 0x2e7cb0, Func Offset: 0x40
	// Line 3020, Address: 0x2e7cb8, Func Offset: 0x48
	// Line 3022, Address: 0x2e7cc0, Func Offset: 0x50
	// Func End, Address: 0x2e7cc8, Func Offset: 0x58
}

// 
// Start address: 0x2e7cd0
void ClearVram()
{
	int i;
	<unknown fundamental type (0xa510)>* p;
	_anon1 li;
	// Line 3043, Address: 0x2e7cd0, Func Offset: 0
	// Line 3053, Address: 0x2e7cec, Func Offset: 0x1c
	// Line 3055, Address: 0x2e7cf0, Func Offset: 0x20
	// Line 3054, Address: 0x2e7cf4, Func Offset: 0x24
	// Line 3055, Address: 0x2e7cf8, Func Offset: 0x28
	// Line 3054, Address: 0x2e7cfc, Func Offset: 0x2c
	// Line 3055, Address: 0x2e7d00, Func Offset: 0x30
	// Line 3062, Address: 0x2e7d0c, Func Offset: 0x3c
	// Line 3064, Address: 0x2e7d14, Func Offset: 0x44
	// Line 3065, Address: 0x2e7d20, Func Offset: 0x50
	// Line 3066, Address: 0x2e7d48, Func Offset: 0x78
	// Line 3067, Address: 0x2e7d50, Func Offset: 0x80
	// Line 3068, Address: 0x2e7d5c, Func Offset: 0x8c
	// Line 3070, Address: 0x2e7d6c, Func Offset: 0x9c
	// Line 3071, Address: 0x2e7d84, Func Offset: 0xb4
	// Func End, Address: 0x2e7d9c, Func Offset: 0xcc
}

