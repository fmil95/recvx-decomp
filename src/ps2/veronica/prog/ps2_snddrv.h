#ifndef _PS2_SNDDRV_H_
#define _PS2_SNDDRV_H_

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
};*/

#endif
