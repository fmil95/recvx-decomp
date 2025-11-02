#ifndef	_MACROS_H_
#define	_MACROS_H_

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define CLAMP(val, min, max) (MAX(MIN((val), (max)), (min))) 

#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8)) 
#define BSWAP_U16_EX(_val) (Uint16)(((_val & 0xFF00) >> 8) | ((_val << 8) & 0xFF00)) 
#define BSWAP_S32(_val) (Sint32)(((Uint32)_val >> 24) | (_val << 24) | (((_val << 8) & 0xFF0000) | ((_val >> 8) & 0xFF00))) 

#endif
