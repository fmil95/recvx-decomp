/*	ファイル名の文字列長				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX    		(256)

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
	Sint16				top;		/*	ファイル情報の先頭					*/
	Sint16				btm[1];		
} ADXF_PTINFO;
#endif
