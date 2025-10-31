#ifndef _OVERRIDE_ADXF_H_
#define _OVERRIDE_ADXF_H_

/*	ファイル名の文字列長				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX    		(256)

typedef struct _adxf_finfo {
    Uint16 flid;
    Uint16 fnsct;
    Sint32 ofst;
} ADXF_FINFO;

/*	パ拏ティション晟報		*/
/*	Partition information	*/
#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
	struct _adxf_ptinfo	*next;		/*	次のパ拏ティション(NULL:オリジナル)	*/
	Sint32				size;		/*	パ拏ティション晟報領域サイズ		*/
	Sint32				nfile;		/*	パ拏ティション内のファイル摧		*/
	Uint16				nentry;		/*	パ拏ティション内の登録ファイル摧	*/
	Sint8				type;		/*	オリジナルか追記かのフラグ			*/
	Sint8				rev;		/*	予約領域							*/
	/*	ADXSTM_OpenRange -> ADXSTM_OpenFileRange(1999.8.19)	*/
	Sint8				fname[ADXF_FNAME_MAX];	/*	AFSファイル名			*/
	void				*curdir;
	// Sint32			top;		/*	ファイル晟報の晄頭					*/
    ADXF_FINFO          finfo[0];
} ADXF_PTINFO;
#endif 

/*	敘大同時発音摧						*/
/*	Maximum number of ADXT handle		*/
//	2001.09.14	S.Hosaka
//	バンドル摧を8->16
#define	ADXT_MAX_OBJ		(8)

#endif
