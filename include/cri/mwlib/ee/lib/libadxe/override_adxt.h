#ifndef _OVERRIDE_ADXT_H_
#define _OVERRIDE_ADXT_H_

/* The purpose of this file is to properly define the ADXSJD struct, since the cri_adxt header defines an opaque handle for it. */

/* adx_xpnd structs */

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

/* adx_bsc structs */

typedef struct _adx_dec_para 
{ 
    Sint8 *ibuf; 
    Sint32 niblk;
    Sint32 nch;
	Sint32 blksize;
	Sint32 blknsmpl;
	Sint8 *pcmbuf;
    Sint32 pcmbsize;
    Sint32 pcmbdist;
    Sint32 wpos;
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
    Sint16 unk48;
    Sint16 unk4A;
    Sint32 unk4C;
    AdxDecPara dp;   
    Sint16 unk7C;
    Sint16 unk7E;
    Sint32 unk80;
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

/* adx_sjd struct */

#ifndef ADXSJD_DEFINED
#define ADXSJD_DEFINED
typedef struct 
{ 
	Sint8 used;
	Sint8 stat;
	Sint8 maxnch;
	Sint8 empty_end;
	ADXB adxb;
	SJ sji;
	SJ sjo[2];
	SJCK cki;
	SJCK cko[2];
	Sint32 total_decsmpl;
	Sint32 total_decdtlen;
	Sint32 decpos;
	Sint32 maxdecsmpl;
	Sint32 dtrpsmpl;
	Sint32 dtrpcnt;
	Sint32 dtrpdtlen;
	void (*dtrpfunc)();
	void *dtrpobj;
	void (*dfltfunc)();
	void *dfltobj;
	Sint8 spsdinfo[64];
	Sint32 hdrlen;
} ADX_SJDEC;
typedef ADX_SJDEC *ADXSJD;
#endif

#endif
