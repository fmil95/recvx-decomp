#ifndef	_LSC_H_
#define	_LSC_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>

#define	LSC_VER				"2.00"

#define	LSC_STM_MAX			(16)

#define	LSC_OBJ_MAX			(8) 

#define	LSC_FNAME_MAX		(40)

#define	LSC_STAT_STOP		(0)
#define	LSC_STAT_WAIT		(1)
#define	LSC_STAT_EXEC		(2)
#define	LSC_STAT_ERR		(3)

#define	LSC_STM_STAT_WAIT	(0)
#define	LSC_STM_STAT_READ	(1)
#define	LSC_STM_STAT_END	(2)

typedef Sint32 LSC_CRS;

typedef void (*LSC_ERRFN)(void *obj, Sint8 *msg);
typedef void (*LSC_STATFN)(void *obj1, void *obj2);

typedef struct _lsc_sinfo
 {
	Sint32 sid;
    Sint8 fname[LSC_FNAME_MAX];
    void *dir;
    Sint32 ofst;
    Sint32 fsct;
    Sint32 stat;
    Sint32 rdsct;
} LSC_SINFO;
typedef void	*LSC_FP;

typedef struct _lsc_obj
{
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

LSC lsc_Alloc(void);
void LSC_CallStatFunc(void);
LSC LSC_Create(SJ sj);
void LSC_Destroy(LSC lsc);
void LSC_EntryChgStatFunc(LSC_STATFN statfn, void *obj1, void *obj2);
Sint32 LSC_EntryFileRange(LSC lsc, Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname);
void LSC_ExecServer(void);
Sint32 LSC_GetFlowLimit(LSC lsc);
Sint32 LSC_GetNumStm(LSC lsc);
Sint32 LSC_GetStat(LSC lsc);
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmId(LSC lsc, Sint32 no);
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid);
void LSC_Pause(LSC lsc, Sint32 sw);
void LSC_SetFlowLimit(LSC lsc, Sint32 min);
void LSC_SetLpFlg(LSC lsc, Sint32 flg);
void LSC_Start(LSC lsc);
void LSC_Stop(LSC lsc);

#endif
