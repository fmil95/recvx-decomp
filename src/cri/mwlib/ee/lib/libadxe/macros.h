#ifndef	_MACROS_H_
#define	_MACROS_H_

// TODO: use all these a little bit more throughout the code

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define CLAMP(val, min, max) (MAX(MIN((val), (max)), (min))) 

#define AIFF_IMAGIC (0x46464941) /* 'AIFF', endian swapped */
#define COMM_IMAGIC (0x4d4d4f43) /* 'COMM', endian swapped */
#define FORM_IMAGIC (0x4D524F46) /* 'FORM', endian swapped */
#define SSND_IMAGIC (0x444E5353) /* 'SSND', endian swapped */

#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8)) 
#define BSWAP_U16_EX(_val) (Uint16)(((_val & 0xFF00) >> 8) | ((_val << 8) & 0xFF00)) 
#define BSWAP_S16(_val) (((_val & 0xFF00) >> 8) | ((_val << 8) & 0xFF00))
#define BSWAP_U32(_val) (((_val >> 24) & 0xFF) | ((_val >> 8) & 0xFF00) | ((_val << 8) & 0xFF0000) | (_val << 24))
#define BSWAP_S32(_val) (Sint32)(((Uint32)_val >> 24) | (_val << 24) | (((_val << 8) & 0xFF0000) | ((_val >> 8) & 0xFF00))) 

#define READ_INT16(buf) (buf[0] | (buf[1] << 8))
#define READ_INT16_EX(buf, i) (buf[i * 2] | (buf[(i * 2) + 1] << 8))
#define READ_INT32(buf) (buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24))
#define READ_INT32_EX(buf, i) (buf[i * 4] | (buf[(i * 4) + 1] << 8) | (buf[(i * 4) + 2] << 16) | (buf[(i * 4) + 3] << 24))

#endif
