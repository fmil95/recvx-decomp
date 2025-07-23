/*	ファイル名の文字列長				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX    		(256)

typedef struct _adxf_finfo {
    Uint16 flid;
    Uint16 fnsct;
    Sint32 ofst;
} ADXF_FINFO;

/*	パーティション情報		*/
/*	Partition information	*/
#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
	struct _adxf_ptinfo	*next;		/*	次のパーティション(NULL:オリジナル)	*/
	Sint32				size;		/*	パーティション情報領域サイズ		*/
	Sint32				nfile;		/*	パーティション内のファイル数		*/
	Uint16				nentry;		/*	パーティション内の登録ファイル数	*/
	Sint8				type;		/*	オリジナルか追記かのフラグ			*/
	Sint8				rev;		/*	予約領域							*/
	/*	ADXSTM_OpenRange -> ADXSTM_OpenFileRange(1999.8.19)	*/
	Sint8				fname[ADXF_FNAME_MAX];	/*	AFSファイル名			*/
	void				*curdir;
	// Sint32			top;		/*	ファイル情報の先頭					*/
    ADXF_FINFO          finfo[0];
} ADXF_PTINFO;
#endif 

/*	最大同時発音数						*/
/*	Maximum number of ADXT handle		*/
//	2001.09.14	S.Hosaka
//	バンドル数を8->16
#define	ADXT_MAX_OBJ		(8)
