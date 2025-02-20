typedef struct _anon0;
typedef struct _anon1;


typedef unsigned int type_0[3];
typedef unsigned char type_1[2];
typedef char type_2[32];
typedef char type_3[64];

struct _anon0
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon1
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon0* info;
};


_anon1* njGetPeripheral(unsigned int port);

// 
// Start address: 0x2d82d0
_anon1* njGetPeripheral(unsigned int port)
{
	// Line 28, Address: 0x2d82d0, Func Offset: 0
	// Func End, Address: 0x2d82d8, Func Offset: 0x8
}

