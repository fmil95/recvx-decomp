/*typedef struct tag_SYS_BT_SYSTEMID;


typedef char type[16];

struct tag_SYS_BT_SYSTEMID
{
	int nNo;
	int nAll;
	char szProduct[16];
};


void syBtExit();
int syBtGetBootSystemID(tag_SYS_BT_SYSTEMID* pData);*/

// 100% matching!
Void   syBtExit     ( Void )
{

}

// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

// 
// Start address: 0x2ddea0
Sint32 syBtGetBootSystemID   ( SYS_BT_SYSTEMID* pData ) 
{ 
    int i;
	// Line 88, Address: 0x2ddea0, Func Offset: 0
	// Line 90, Address: 0x2ddea8, Func Offset: 0x8
	// Line 97, Address: 0x2ddeb0, Func Offset: 0x10
	// Line 98, Address: 0x2ddeb8, Func Offset: 0x18
	// Line 99, Address: 0x2ddec0, Func Offset: 0x20
	// Line 101, Address: 0x2ddec4, Func Offset: 0x24
	// Line 102, Address: 0x2ddec8, Func Offset: 0x28
	// Line 101, Address: 0x2ddecc, Func Offset: 0x2c
	// Line 102, Address: 0x2dded0, Func Offset: 0x30
	// Line 103, Address: 0x2ddee0, Func Offset: 0x40
	// Line 105, Address: 0x2ddee4, Func Offset: 0x44
	// Func End, Address: 0x2ddeec, Func Offset: 0x4c
	scePrintf("syBtGetBootSystemID - UNIMPLEMENTED!\n");
}
