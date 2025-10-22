#include "adx_fcch.h"

// 100% matching!
void ADXF_Ocbi(void *address, Uint64 size)
{
    Sint8* temp; // TODO: this variable is not really needed, MWCC doesn't like arithmetic with void pointers, so remove this when GCC is finally added

    temp = address;
    
    InvalidDCache(temp, (temp + size) - 1);
}
