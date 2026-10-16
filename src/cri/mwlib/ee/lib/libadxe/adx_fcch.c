#include "../../../cri/mwlib/ee/lib/libadxe/adx_fcch.h"

#include <eetypes.h>
#include <eekernel.h>
#include <sifrpc.h>

// 100% byte-matching object! 

void ADXF_Ocbi(void *address, Uint64 size)
{
    InvalidDCache(address, &address[size] - 1);
}
