#include "rutchk.h"

/*_anon10* rom;
_anon15* sys;

unsigned char bhCheckRoute(_anon25* ps0, _anon25* ps1, _anon25* ps2);
unsigned char bhCheckRouteID(_anon25* ps);

// 
// Start address: 0x26b8d0
unsigned char bhCheckRoute(_anon25* ps0, _anon25* ps1, _anon25* ps2)
{
	unsigned char rid;
	unsigned char nxt;
	unsigned char now;
	_anon0* rp;
	// Line 69, Address: 0x26b8d0, Func Offset: 0
	// Line 72, Address: 0x26b8e8, Func Offset: 0x18
	// Line 73, Address: 0x26b8f4, Func Offset: 0x24
	// Line 74, Address: 0x26b908, Func Offset: 0x38
	// Line 75, Address: 0x26b918, Func Offset: 0x48
	// Line 76, Address: 0x26b92c, Func Offset: 0x5c
	// Line 78, Address: 0x26b934, Func Offset: 0x64
	// Line 79, Address: 0x26b93c, Func Offset: 0x6c
	// Line 80, Address: 0x26b944, Func Offset: 0x74
	// Line 81, Address: 0x26b948, Func Offset: 0x78
	// Line 83, Address: 0x26b950, Func Offset: 0x80
	// Line 85, Address: 0x26b958, Func Offset: 0x88
	// Line 83, Address: 0x26b960, Func Offset: 0x90
	// Line 84, Address: 0x26b970, Func Offset: 0xa0
	// Line 83, Address: 0x26b974, Func Offset: 0xa4
	// Line 84, Address: 0x26b980, Func Offset: 0xb0
	// Line 85, Address: 0x26b990, Func Offset: 0xc0
	// Line 86, Address: 0x26b9a4, Func Offset: 0xd4
	// Line 87, Address: 0x26b9b8, Func Offset: 0xe8
	// Line 89, Address: 0x26b9cc, Func Offset: 0xfc
	// Func End, Address: 0x26b9e4, Func Offset: 0x114
}*/

// 100% matching!
unsigned char bhCheckRouteID(NJS_POINT3* ps)
{
    ATR_WORK* rp;
    int i;

    rp = rom->rutp;
    
    for (i = 0; i < rom->rut_n; i++, rp++) 
    {
        if (((rp->px <= ps->x) && ((rp->px + rp->w) >= ps->x)) && ((rp->py <= ps->y) && ((rp->py + rp->h) >= ps->y)) && ((rp->pz <= ps->z) && ((rp->pz + rp->d) >= ps->z)))
        {
            return i;
        }
    }

    return 0xFF;
}
