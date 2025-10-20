#ifndef	_CRI_LSC_H_INCLUDED
#define	_CRI_LSC_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ 連結ストリームコントローラ ライブラリ					*/
/*				LSC (Linking Stream Controller) Library						*/
/*																			*/
/*			Copyright (c) 1999 CSK Research Institute						*/
/*				1998.7.12		written by S.Hosaka							*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*	インクルードファイル													*/
/****************************************************************************/

#include	<sj.h>

/****************************************************************************/
/*	定数マクロ																*/
/****************************************************************************/

/*	Version No.					*/
#define	LSC_VER				"0.90"

/*	最大ストリーム数			*/
#define	LSC_STM_MAX			(16)

/*	ハンドルの個数				*/
#define	LSC_OBJ_MAX			(8) 

/*	ファイル名の最大文字数		*/
#define	LSC_FNAME_MAX		(40)

/*	動作状態					*/
#define	LSC_STAT_STOP		(0)
#define	LSC_STAT_WAIT		(1)
#define	LSC_STAT_EXEC		(2)
#define	LSC_STAT_ERR		(3)

/*	ストリーム読み込みの状態	*/
#define	LSC_STM_STAT_WAIT	(0)
#define	LSC_STM_STAT_READ	(1)
#define	LSC_STM_STAT_END	(2)

/****************************************************************************/
/*	列挙定数																*/
/****************************************************************************/

/****************************************************************************/
/*	処理マクロ																*/
/****************************************************************************/

/****************************************************************************/
/*	データ型																*/
/****************************************************************************/

typedef Sint32 LSC_CRS;

/*	エラー登録関数				*/
typedef void (*LSC_ERRFN)(void *obj, char *msg);
typedef void (*LSC_STATFN)(void *obj1, void *obj2);

/*	ストリーム情報				*/
#ifndef LSC_SINFO_DEFINED
#define LSC_SINFO_DEFINED
typedef struct _lsc_sinfo {
	Sint32 sid;
    Sint8 fname[LSC_FNAME_MAX];
    void *dir;
    Sint32 ofst;
    Sint32 fsct;
    Sint32 stat;
    Sint32 rdsct;
} LSC_SINFO;
#endif

#ifndef LSC_FP_DEFINED
#define LSC_FP_DEFINED
typedef void	*LSC_FP;
#endif

/*	ハンドル					*/
#ifndef LSC_DEFINED
#define LSC_DEFINED
typedef struct _lsc_obj {
    Sint8       used;
    Sint8       stat;
    Sint8       rdflg;
    Sint8       lpflg;
    Sint8       pause;
    Sint8       rsv1;
    Sint16      rsv2;
    SJ          sj;
    SJCK        ck;
    Sint32      bufmin;
    Sint32      bsize;
    Sint32      wpos;
    Sint32      rpos;
    Sint32      nstm;
    LSC_FP      fp;
    Sint32      fsct;
    Sint32      reqsct;
    Sint32      errcnt;
    LSC_SINFO   sinfo[16];
} LSC_OBJ;
typedef LSC_OBJ *LSC;
#endif

/****************************************************************************/
/*	変数宣言																*/
/****************************************************************************/

/****************************************************************************/
/*	関数宣言																*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*	初期化					*/
void LSC_Init(void);

/*	終了処理				*/
void LSC_Finish(void);

/*	エラー処理関数の登録	*/
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

/*	ハンドルの生成			*/
LSC LSC_Create(SJ sj);

/*	ハンドルの消去			*/
void LSC_Destroy(LSC lsc);

/*	ストリームの登録		*/
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname);

/*	読み込み開始			*/
void LSC_Start(LSC lsc);

/*	読み込み停止			*/
void LSC_Stop(LSC lsc);

/*	ポーズ・ポーズ解除		*/
void LSC_Pause(LSC lsc, Sint32 sw);

/*	サーバ関数				*/
void LSC_ExecServer(void);

/*	ハンドル状態の取得		*/
Sint32 LSC_GetStat(LSC lsc);

/*	登録ストリーム数の取得	*/
Sint32 LSC_GetNumStm(LSC lsc);

/*	読み込み中のストリームIDの取得	*/
Sint32 LSC_GetStmId(LSC lsc, Sint32 no);

/*	ファイル名の取得	*/
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid);

/*	ストリーム読み込みの状態取得	*/
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid);

/*	読み込んだデータサイズの取得(sector)	*/
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid);

/*	バッファ流量下限値の設定	*/
void LSC_SetFlowLimit(LSC lsc, Sint32 min);

/*	バッファ流量下限値の取得	*/
Sint32 LSC_GetFlowLimit(LSC lsc);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/* _CRI_LSC_H_INCLUDED */
