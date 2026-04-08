#ifndef	_KATANA_EXTRA_H_
#define	_KATANA_EXTRA_H_

#include <sg_bup.h>

/******** ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽJ?ｿｽ[?ｿｽh?ｿｽ?ｿｽ?ｿｽ\?ｿｽ?ｿｽ?ｿｽ?ｿｽ *******************************************/
/******** Memory card information structure ********************************/
typedef struct {
	Uint16 Ready;               /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽJ?ｿｽ[?ｿｽh?ｿｽ?ｿｽ?ｿｽ}?ｿｽE?ｿｽ?ｿｽ?ｿｽg?ｿｽ?ｿｽ?ｿｽ?ｿｽﾄゑｿｽ?ｿｽ驍ｩ      */
	                            /* Is memory card mounted ?                */
	Uint16 IsFormat;            /* ?ｿｽt?ｿｽH?ｿｽ[?ｿｽ}?ｿｽb?ｿｽg?ｿｽ?ｿｽ?ｿｽ?ｿｽﾄゑｿｽ?ｿｽ驍ｩ?ｿｽﾇゑｿｽ?ｿｽ?ｿｽ          */
	                            /* Is memory card formatted ?              */
	Uint32 LastError;           /* ?ｿｽﾅ鯉ｿｽﾉ費ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽG?ｿｽ?ｿｽ?ｿｽ[?ｿｽR?ｿｽ[?ｿｽh              */
	                            /* Error code which occured last.          */
	Uint32 ProgressCount;       /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽo?ｿｽﾟカ?ｿｽE?ｿｽ?ｿｽ?ｿｽg                        */
	                            /* Operation progress count.               */
	Uint32 ProgressMax;         /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽo?ｿｽﾟカ?ｿｽE?ｿｽ?ｿｽ?ｿｽg?ｿｽﾅ托ｿｽ                    */
	                            /* Operattion progress count maximum.      */
	Uint32 Operation;           /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌオ?ｿｽy?ｿｽ?ｿｽ?ｿｽ[?ｿｽV?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽR?ｿｽ[?ｿｽh            */
	                            /* Operation code in handling now.         */
	BUS_DISKINFO DiskInfo;      /* ?ｿｽh?ｿｽ?ｿｽ?ｿｽC?ｿｽu?ｿｽ?ｿｽ?ｿｽ                            */
	                            /* Drive information.                      */
	Uint32 Connect;             /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽJ?ｿｽ[?ｿｽh?ｿｽ?ｿｽ?ｿｽﾚ托ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾄゑｿｽ?ｿｽ驍ｩ        */
	                            /* Is memory card connected ?              */
	void* Work;                 /* ?ｿｽ?ｿｽ?ｿｽ[?ｿｽN?ｿｽA?ｿｽh?ｿｽ?ｿｽ?ｿｽX                          */
	                            /* Work address.                           */
	Uint32 WorkSize;            /* ?ｿｽ?ｿｽ?ｿｽ[?ｿｽN?ｿｽT?ｿｽC?ｿｽY                            */
	                            /* Work size (bytes).                      */
	Uint32 Capacity;            /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽJ?ｿｽ[?ｿｽh?ｿｽﾌ容?ｿｽﾊフ?ｿｽ?ｿｽ?ｿｽO(BUD_CAPACITY)  */
	                            /* Capacity flag of memory card.           */
    Sint32 MemMode;             // manually added
} BACKUPINFO;

/*===============================================================*/
/* ?ｿｽﾎ会ｿｽ?ｿｽ?ｿｽ?ｿｽ驛??ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽJ?ｿｽ[?ｿｽh?ｿｽﾌ最托ｿｽe?ｿｽ?ｿｽ                              */
/* Mamimum volume to use.                                        */
/*===============================================================*/

#define MAX_CAPS BUD_CAPACITY_1MB

/*===============================================================*/
/* ?ｿｽﾎ会ｿｽ?ｿｽ?ｿｽ?ｿｽ驛??ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽJ?ｿｽ[?ｿｽh?ｿｽﾌド?ｿｽ?ｿｽ?ｿｽC?ｿｽu?ｿｽ?ｿｽ                            */
/* Number of memory card to use.                                 */
/*===============================================================*/

#define MAX_DRIVES 8
#define USE_DRIVES BUD_USE_DRIVE_ALL

#define set_imask(mask)             _builtin_set_imask(mask)

/* SH-4 program area address. */
#define P1AREA   0x80000000

/* Define work RAM end address (16 MB). */
#define WORK_END (((Uint32) _BSG_END) & 0xe0000000 | 0x0d000000)

#define HEAP_AREA ((void*) ((((Uint32) _BSG_END | P1AREA) & 0xffffffe0) + 0x20))
#define HEAP_SIZE (WORK_END - (Uint32) HEAP_AREA)

#endif
