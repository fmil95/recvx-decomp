// MWCC has long as 8 bytes, so we need to change the following typedefs to use int instead

#ifndef _TYPEDEF_Uint32
#define _TYPEDEF_Uint32
typedef unsigned int   Uint32;         /*  unsigned 4 byte integer     */
#endif
#ifndef _TYPEDEF_Sint32
#define _TYPEDEF_Sint32
typedef signed int     Sint32;         /*  signed 4 byte integer       */
#endif
