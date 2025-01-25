/****** GLOBAL DECLARATION **********************************************/
#ifndef _TYPEDEF_Uint8
#define _TYPEDEF_Uint8
typedef unsigned char     Uint8;        /*  unsigned 1 byte integer     */
#endif
#ifndef _TYPEDEF_Sint8
#define _TYPEDEF_Sint8
typedef signed char     Sint8;          /*  signed 1 byte integer       */
#endif
#ifndef _TYPEDEF_Uint16
#define _TYPEDEF_Uint16
typedef unsigned short  Uint16;         /*  unsigned 2 byte integer     */
#endif
#ifndef _TYPEDEF_Sint16
#define _TYPEDEF_Sint16
typedef signed short    Sint16;         /*  signed 2 byte integer       */
#endif
#ifndef _TYPEDEF_Uint32
#define _TYPEDEF_Uint32
typedef unsigned long   Uint32;         /*  unsigned 4 byte integer     */
#endif
#ifndef _TYPEDEF_Sint32
#define _TYPEDEF_Sint32
typedef signed long     Sint32;         /*  signed 4 byte integer       */
#endif
#ifndef _TYPEDEF_Float32
#define _TYPEDEF_Float32
typedef float           Float32;        /*  4 byte real number          */
#endif
#ifndef _TYPEDEF_Float64
#define _TYPEDEF_Float64
typedef double          Float64;        /*  8 byte real number          */
#endif
#ifndef _TYPEDEF_Float
#define _TYPEDEF_Float
typedef float           Float;          /*  4 byte real number          */
#endif
#ifndef _TYPEDEF_Double
#define _TYPEDEF_Double
typedef double           Double;        /*  8 byte real number          */
#endif
#ifndef _TYPEDEF_Void
#define _TYPEDEF_Void
typedef void            Void;           /*  void                        */
#endif

#if !defined(__cplusplus)
#ifdef false
#undef false
#endif
#ifdef true
#undef true
#endif
enum bool
{
    false,
    true
};
typedef enum bool   bool;
#endif

#ifndef _TYPEDEF_Bool
#define _TYPEDEF_Bool
typedef Sint32 Bool ;					/*  Bool                        */
#endif

/****** GLOBAL CONSTANT *************************************************/
#ifndef  NULL
#ifdef  __cplusplus
#define  NULL           (0)
#else
#define  NULL           ((void *)0)
#endif
#endif

#ifndef NO
#define NO              (0)
#endif
#ifndef YES
#define YES             (1)
#endif

#ifndef FALSE
#define FALSE           (0)
#endif
#ifndef TRUE
#define TRUE            (1)
#endif

#ifndef OFF
#define OFF             (0)
#endif
#ifndef ON
#define ON              (1)
#endif

#ifndef OK
#define OK              (0)
#endif
#ifndef NG
#define NG              (-1)
#endif

/****** GLOBAL MACRO ****************************************************/
#ifndef MAX
#define MAX(x, y)       ((x) > (y) ? (x) : (y))             /* maximum  */
#endif
#ifndef MIN
#define MIN(x, y)       ((x) < (y) ? (x) : (y))             /* minimum  */
#endif
#ifndef ABS
#define ABS(x)          ((x) < 0 ? -(x) : (x))              /* absolute */
#endif
