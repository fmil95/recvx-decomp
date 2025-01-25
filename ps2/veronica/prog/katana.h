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

/*--------------------------------------*/
/*      Basic Define                    */
/*--------------------------------------*/
typedef int     Int;

typedef Sint32  Angle;

typedef Float   NJS_MATRIX[16];

typedef Float NJS_FOG_TABLE[128];

typedef struct {
	Float  x;
	Float  y;
} NJS_POINT2;

typedef struct {
	Float   x;
	Float   y;
	Float   z;
} NJS_POINT3, NJS_VECTOR;

typedef struct {
	Float   a;
	Float   r;
	Float   g;
	Float   b;
} NJS_ARGB;

typedef struct
{
/*************/
	Float       ratten;         /* attenuation rate             */
	Float       ipd;		    /* inner product                */
/*************/
	Float       nrr;            /* limit judgment value         */
	Float       frr;            /* limit judgment value         */
	Float       cosi;           /* limit judgment value         */
	Float       cose;           /* limit judgment value         */
	Float		idev;           /* judgment value of devision   */
	Float		odev;           /* judgment value of devision   */
	Float       rate;           /* attenuation rate(calculated) */
	Float       intns;          /* Intensity (0-1)              */
	Int         exp;            /* exponent(SGI):material       */
/*************/
	Int         reserve;        /*                              */
/*************/
	NJS_POINT3  lpnt;           /* point vector                 */
	NJS_VECTOR  lvctr;          /* directional vector           */
/*************/
	NJS_VECTOR  lmvctr;         /* directional vector           */
/*************/
	NJS_ARGB    atten;          /* intns * argb                 */
	NJS_ARGB    amb;            /* iamb*atten                   */
	NJS_ARGB    dif;            /* idif*atten                   */
	NJS_ARGB    spc;            /* ispc*atten                   */
/*************/
	NJS_ARGB    mamb;           /* amb*material                 */
	NJS_ARGB    mdif;           /* dif*material                 */
	NJS_ARGB    mspc;           /* spc*material                 */
/*************/
} NJS_LIGHT_CAL, *NJS_LIGHT_CAL_PTR;

typedef struct {
	Int             lsrc;       /* the kind of light source     */
	Float           iamb;       /* ambient's intensity          */
	Float           idif;       /* deffuse light's intensity    */
	Float           ispc;       /* specular light's intensity   */
	Float           nrang;      /* limit value (nearest)        */
	Float           frang;      /* limit value (farthest)       */
	void*           func;       /* the pointer of Callback func.*/
	Angle           iang;       /* limit value (inside)         */
	Angle           oang;       /* limit value (outside)        */
	NJS_ARGB        argb;       /* light's color                */
} NJS_LIGHT_ATTR, *NJS_LIGHT_ATTR_PTR;

typedef struct {
	NJS_MATRIX      mtrx;       /* matrix                       */
	NJS_POINT3      pnt;        /* point vector                 */
	NJS_VECTOR      vctr;       /* directional vector           */
	Int             stat;       /* status                       */
	Int             reserve;    /* reserve                      */
	NJS_LIGHT_CAL   ltcal;      /* calculation                  */
	NJS_LIGHT_ATTR  attr;       /* attribute                    */
} NJS_LIGHT, *NJS_LIGHT_PTR;

typedef struct {
	Float   px,py,pz;
	Float   vx,vy,vz;
} NJS_LINE, NJS_PLANE, NJS_PVECTOR;

typedef struct {
	Float	x;
	Float	y;
	Float	z;
	Float	u;
	Float	v;
	Uint32	bcol;
	Uint32	ocol;
} NJS_TEXTUREH_VTX;

typedef struct{
	Uint32 Type;
	Uint32 BitDepth;
	Uint32 PixelFormat;
	Uint32 nWidth;
	Uint32 nHeight;
	Uint32 TextureSize;
	Uint32 fSurfaceFlags;
	Uint32 *pSurface;
	Uint32 *pVirtual;
	Uint32 *pPhysical;
}NJS_TEXSURFACE;
	
typedef struct{
	void*			   texaddr; /* texture address   			*/
	NJS_TEXSURFACE	texsurface;	/* texture surface 				*/
} NJS_TEXINFO;

typedef struct{
    NJS_POINT3 c1;
    NJS_POINT3 c2;
    Float      r;
} NJS_CAPSULE;

typedef struct {
	Float	x;
	Float	y;
	Float	z;
	Uint32	col;
} NJS_POLYGON_VTX;

typedef struct {
	Float	x;
	Float	y;
	Float	z;
	Float	u;
	Float	v;
	Uint32	col;
} NJS_TEXTURE_VTX;

typedef struct{
    NJS_POINT3 c;
    Float      r;
} NJS_SPHERE;

/* 2 factors : pos and ang, pos and vec(light motion), etc      */
typedef struct {
	void            *p[2];      /* factor pointer               */
	Uint32          nb[2];      /* factor count                 */
} NJS_MDATA2;

typedef struct {
    Sint32            *vlist;   /* vertex list                  */
    Sint16            *plist;   /* polygon list                 */
    NJS_POINT3        center;   /* model center                 */
    Float                  r;   /* radius                       */
} NJS_CNK_MODEL;

typedef struct cnkobj {
    Uint32          evalflags;  /* evalation flags              */
    NJS_CNK_MODEL   *model;     /* model data pointer           */
    Float           pos[3];     /* translation                  */
    Angle           ang[3];     /* rotation                     */
    Float           scl[3];     /* scaling                      */
    struct cnkobj   *child;     /* child object                 */
    struct cnkobj   *sibling;   /* sibling object               */
} NJS_CNK_OBJECT;

typedef struct {
	Uint32 type;                /* �y���t�F�����̃^�C�v                    */
	                            /* Peripheral type                         */
	Uint32 reserved[3];         /* �\��                                    */
	                            /* Reserved                                */
	Uint8 is_root;              /* ���[�g�f�o�C�X���ǂ�����\��            */
	                            /* Is root device ?                        */
	Uint8 area_code;            /* �G���A�R�[�h                            */
	                            /* Area code                               */
	Uint8 connector_dir[2];     /* �R�l�N�^�̌���                          */
	                            /* Connector direction                     */
	char product_name[32];      /* ���i��                                  */
	                            /* Product name                            */
	char license[64];           /* ���C�Z���X                              */
	                            /* License string                          */
	Uint16 stdby_pow;           /* �X�^���o�C����d��                      */
	                            /* Standby power                           */
	Uint16 max_pow;             /* �ő����d��                            */
	                            /* Max power                               */
} PDS_PERIPHERALINFO;

typedef struct {
	Uint32 id;                            /* �f�o�C�XID                    */
	Uint32 support;                       /* �{�^���̃T�|�[�g���          */
	Uint32 on;                            /* ���݉�����Ă���{�^��        */
	Uint32 off;                           /* ���ݕ�����Ă���{�^��        */
#ifdef USE_UNION
	union {
		Uint32 push;                      /* ���݉����ꂽ�u�Ԃɂ���{�^��  */
#endif
		Uint32 press;
#ifdef USE_UNION
	};
#endif
#ifdef USE_UNION
	union {
		Uint32 pull;                      /* ���ݕ����ꂽ�u�Ԃɂ���{�^��  */
#endif
		Uint32 release;
#ifdef USE_UNION
	};
#endif
	Uint16 r;                             /* ���f�[�^R     (     0�`255  ) */
	Uint16 l;                             /* ���f�[�^L     (     0�`255  ) */
	Sint16 x1;                            /* ���f�[�^X1    (  -128�`127  ) */
	Sint16 y1;                            /* ���f�[�^Y1    (  -128�`127  ) */
	Sint16 x2;                            /* ���f�[�^X2    (  -128�`127  ) */
	Sint16 y2;                            /* ���f�[�^Y2    (  -128�`127  ) */
	char* name;                           /* �f�o�C�X����                  */
	void* extend;                         /* �g���f�[�^�A�h���X            */
	Uint32 old;                           /* �\��                          */
	PDS_PERIPHERALINFO* info;             /* �y���t�F�������ւ̃|�C���^  */
} PDS_PERIPHERAL;

typedef struct {
	void            *filename;  /* texture filename strings     */
	Uint32               attr;  /* texture attribute            */
	Uint32            texaddr;  /* texture memory list address  */
} NJS_TEXNAME;

typedef struct {
	NJS_TEXNAME     *textures;  /* texture array                */
	Uint32          nbTexture;  /* texture count                */
} NJS_TEXLIST;
