


int SoundMode;

/*int syCfgExit();
int syCfgGetSoundMode(int* pnMode);
int syCfgInit();
int syCfgSetSoundMode(int nMode);*/

// 100% matching! 
Sint32 syCfgExit( Void  )
{

}

// 
// Start address: 0x2ddf10
int syCfgGetSoundMode(int* pnMode)
{
	// Line 11, Address: 0x2ddf10, Func Offset: 0
	// Line 13, Address: 0x2ddf18, Func Offset: 0x8
	// Line 14, Address: 0x2ddf1c, Func Offset: 0xc
	// Func End, Address: 0x2ddf24, Func Offset: 0x14
	scePrintf("syCfgGetSoundMode - UNIMPLEMENTED!\n");
}

// 100% matching! 
Sint32 syCfgInit( Void* )
{

}

// 100% matching! 
Sint32 syCfgSetSoundMode( Sint32 nMode )
{ 
    SoundMode = nMode; 
}
