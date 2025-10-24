
typedef struct _adx_xpnd_param
{ // 0x14
	/* 0x00 */ Sint32 nch;
	/* 0x04 */ Sint8 *ibuf;
	/* 0x08 */ Sint32 nblk;
	/* 0x0c */ Sint16 *obuf_l;
	/* 0x10 */ Sint16 *obuf_r;
} ADXPDPRM;

typedef struct _adx_xpdobj
{ // 0x3c
	/* 0x00 */ Sint32 used;
	/* 0x04 */ Sint32 xno;
	/* 0x08 */ Sint32 mode;
	/* 0x0c */ Sint32 stat;
	/* 0x10 */ Sint32 ndecblk;
	/* 0x14 */ ADXPDPRM xprm;
	/* 0x28 */ Sint16 dly[2][2];
	/* 0x30 */ Sint16 k[2];
	/* 0x34 */ Sint16 key;
	/* 0x36 */ Sint16 km;
	/* 0x38 */ Sint16 ka;
} ADX_XPDOBJ;
typedef ADX_XPDOBJ *ADXPD;

typedef struct _adx_dec_para 
{ // 0x30
	/* 0x00 */ Sint8 *ibuf;
	/* 0x04 */ Sint32 niblk;
	/* 0x08 */ Sint32 nch;
	/* 0x0c */ Sint32 blksize;
	/* 0x10 */ Sint32 blknsmpl;
	/* 0x14 */ Sint8 *pcmbuf;
	/* 0x18 */ Sint32 pcmbsize;
	/* 0x1c */ Sint32 pcmbdist;
	/* 0x20 */ Sint32 wpos;
	/* 0x24 */ Sint32 nroom;
	/* 0x28 */ Sint32 lp_nsmpl;
	/* 0x2c */ Sint32 ndecsmpl;
} AdxDecPara;
typedef void *AHXSJD;

typedef struct _adx_intbuf 
{ // 0xb0
	/* 0x00 */ Sint16 used;
	/* 0x02 */ Sint16 hdcdflag;
	/* 0x04 */ Sint32 stat;
	/* 0x08 */ ADXPD xpd;
	/* 0x0c */ Sint8 code;
	/* 0x0d */ Sint8 bps;
	/* 0x0e */ Sint8 nch;
	/* 0x0f */ Sint8 blklen;
	/* 0x10 */ Sint32 blknsmpl;
	/* 0x14 */ Sint32 sfreq;
	/* 0x18 */ Sint32 total_nsmpl;
	/* 0x1c */ Sint16 cof;
	/* 0x1e */ Sint16 rsv1;
	/* 0x20 */ Sint32 lp_ins_nsmpl;
	/* 0x24 */ Sint16 nloop;
	/* 0x26 */ Sint16 lp_type;
	/* 0x28 */ Sint32 lp_spos;
	/* 0x2c */ Sint32 lp_sofst;
	/* 0x30 */ Sint32 lp_epos;
	/* 0x34 */ Sint32 lp_eofst;
	/* 0x38 */ Sint32 maxnch;
	/* 0x3c */ Sint16 *pcmbuf;
	/* 0x40 */ Sint32 pcmbsize;
	/* 0x44 */ Sint32 pcmbdist;
	/* 0x48 */ AdxDecPara dp;
	/* 0x78 */ void* (*getwrfunc)(/* parameters unknown */);
	/* 0x7c */ void *getwrobj;
	/* 0x80 */ void (*addwrfunc)(/* parameters unknown */);
	/* 0x84 */ void *addwrobj;
	/* 0x88 */ Sint32 total_ndecsmpl;
	/* 0x8c */ Sint32 curwpos;
	/* 0x90 */ Sint32 ndecsmpl;
	/* 0x94 */ Sint32 ndeclen;
	/* 0x98 */ Sint16 fmttype;
	/* 0x9a */ Sint16 cdctype;
	/* 0x9c */ Sint16 k0;
	/* 0x9e */ Sint16 km;
	/* 0xa0 */ Sint16 ka;
	/* 0xa4 */ AHXSJD sjdh;
	/* 0xa8 */ Sint32 ahxdecsmpl;
	/* 0xac */ //Sint32 ahxsvrfreq;
} ADX_BASIC;
typedef ADX_BASIC *ADXB;

#ifndef ADXSJD_DEFINED
#define ADXSJD_DEFINED
typedef struct 
{ // 0x9c
	/* 0x00 */ Sint8 used;
	/* 0x01 */ Sint8 stat;
	/* 0x02 */ Sint8 maxnch;
	/* 0x03 */ Sint8 empty_end;
	/* 0x04 */ ADXB adxb;
	/* 0x08 */ SJ sji;
	/* 0x0c */ SJ sjo[2];
	/* 0x14 */ SJCK cki;
	/* 0x1c */ SJCK cko[2];
	/* 0x2c */ Sint32 total_decsmpl;
	/* 0x30 */ Sint32 total_decdtlen;
	/* 0x34 */ Sint32 decpos;
	/* 0x38 */ Sint32 maxdecsmpl;
	/* 0x3c */ Sint32 dtrpsmpl;
	/* 0x40 */ Sint32 dtrpcnt;
	/* 0x44 */ Sint32 dtrpdtlen;
	/* 0x48 */ void (*dtrpfunc)(/* parameters unknown */);
	/* 0x4c */ void *dtrpobj;
	/* 0x50 */ void (*dfltfunc)(/* parameters unknown */);
	/* 0x54 */ void *dfltobj;
	/* 0x58 */ Sint8 spsdinfo[64];
	/* 0x98 */ Sint32 hdrlen;
} ADX_SJDEC;
typedef ADX_SJDEC *ADXSJD;
#endif
