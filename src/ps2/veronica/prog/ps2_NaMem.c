#include "ps2_NaMem.h"

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

// 100% matching! 
void	njMemCopy4( void *dst, const void *src, Sint32 num )
{ 
    int* lpSrc;
    int* lpDst;

    lpSrc = (int*)src;
    lpDst = (int*)dst;
    
    for ( ; num != 0; num--)
    { 
        *lpDst++ = *lpSrc++;
    } 
}
