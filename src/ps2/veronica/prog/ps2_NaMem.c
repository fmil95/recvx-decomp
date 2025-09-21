/*void njMemCopy(void* vpDst, void* vpSrc, int lNum);
void njMemCopy4(void* vpDst, void* vpSrc, int lNum);*/

// 100% matching! 
void	njMemCopy(  void *dst, const void *src, Sint32 num )
{ 
	char* cpSrc;
    char* cpDst;

    cpSrc = (char*)src;
    cpDst = (char*)dst;
    
    for ( ; num != 0; num--) 
    { 
        *cpDst++ = *cpSrc++;
    } 
} 

// 
// Start address: 0x2e3130
void	njMemCopy4( void *dst, const void *src, Sint32 num )
{
	int* lpDst;
	int* lpSrc;
	// Line 106, Address: 0x2e3130, Func Offset: 0
	// Line 117, Address: 0x2e3158, Func Offset: 0x28
	// Func End, Address: 0x2e3160, Func Offset: 0x30
	scePrintf("njMemCopy4 - UNIMPLEMENTED!\n");
}
