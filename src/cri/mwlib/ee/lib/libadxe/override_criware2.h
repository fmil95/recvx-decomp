
typedef struct _adx_xpnd_param
{ 
	Sint32 nch;
	Sint8 *ibuf;
	Sint32 nblk;
	Sint16 *obuf_l;
	Sint16 *obuf_r;
} ADXPDPRM;

typedef struct _adx_xpdobj
{ 
	Sint32 used;
	Sint32 xno;
	Sint32 mode;
	Sint32 stat;
	Sint32 ndecblk;
	ADXPDPRM xprm;
	Sint16 dly[2][2];
	Sint16 k[2];
} ADX_XPDOBJ;
typedef ADX_XPDOBJ *ADXPD;

typedef struct _adx_dec_para 
{ 
    // wpos is missing
	Sint16 unk0; // ???
    Sint16 unk2; // ???
    Sint32 ndecsmpl;
	Sint8 *ibuf;
	Sint32 niblk;
    Sint32 nch;
	Sint32 blksize;
	Sint32 blknsmpl;
	Sint8 *pcmbuf;
    Sint32 pcmbsize;
	Sint32 pcmbdist;
	Sint32 nroom;
	Sint32 lp_nsmpl;
} AdxDecPara;

typedef struct _adx_intbuf 
{ 
   Sint16 used;
   Sint16 hdcdflag;
   Sint32 stat;
   ADXPD xpd;
   Sint8 code;
   Sint8 bps;
   Sint8 nch;
   Sint8 blklen;
   Sint32 blknsmpl;
   Sint32 sfreq;
   Sint32 total_nsmpl;
   Sint16 cof;
   Sint16 rsv1;
   Sint32 lp_ins_nsmpl;
   Sint16 nloop;
   Sint16 lp_type;
   Sint32 lp_spos;
   Sint32 lp_sofst;
   Sint32 lp_epos;
   Sint32 lp_eofst;
   Sint32 maxnch;
   Sint16 *pcmbuf;
   Sint32 pcmbsize;
   Sint32 pcmbdist;
   AdxDecPara dp;   
   // k0, km and ka are missing, also ahxdecsmpl and ahxsvrfreq
   Sint32 unk78;
   Sint16 unk7C;
   Sint16 unk7E;
   Sint32 ndeclen;
   Sint32 ndecsmpl;
   void* (*getwrfunc)();
   void *getwrobj;
   void (*addwrfunc)();
   void *addwrobj;
   Sint32 total_ndecsmpl;
   Sint32 curwpos;
   Sint32 total_decsmpl;
   Sint32 total_decdtlen;
   Sint16 fmttype;
   Sint16 cdctype;
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
