#ifndef	_CRI_LSC_H_INCLUDED
#define	_CRI_LSC_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �A���X�g���[���R���g���[�� ���C�u����					*/
/*				LSC (Linking Stream Controller) Library						*/
/*																			*/
/*			Copyright (c) 1999 CSK Research Institute						*/
/*				1998.7.12		written by S.Hosaka							*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*	�C���N���[�h�t�@�C��													*/
/****************************************************************************/

#include	<sj.h>

/****************************************************************************/
/*	�萔�}�N��																*/
/****************************************************************************/

/*	Version No.					*/
#define	LSC_VER				"0.90"

/*	�ő�X�g���[����			*/
#define	LSC_STM_MAX			(16)

/*	�n���h���̌�				*/
#define	LSC_OBJ_MAX			(8) 

/*	�t�@�C�����̍ő啶����		*/
#define	LSC_FNAME_MAX		(40)

/*	������					*/
#define	LSC_STAT_STOP		(0)
#define	LSC_STAT_WAIT		(1)
#define	LSC_STAT_EXEC		(2)
#define	LSC_STAT_ERR		(3)

/*	�X�g���[���ǂݍ��݂̏��	*/
#define	LSC_STM_STAT_WAIT	(0)
#define	LSC_STM_STAT_READ	(1)
#define	LSC_STM_STAT_END	(2)

/****************************************************************************/
/*	�񋓒萔																*/
/****************************************************************************/

/****************************************************************************/
/*	�����}�N��																*/
/****************************************************************************/

/****************************************************************************/
/*	�f�[�^�^																*/
/****************************************************************************/

typedef Sint32 LSC_CRS;

/*	�G���[�o�^�֐�				*/
typedef void (*LSC_ERRFN)(void *obj, char *msg);
typedef void (*LSC_STATFN)(void *obj1, void *obj2);

/*	�X�g���[�����				*/
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

/*	�n���h��					*/
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
/*	�ϐ��錾																*/
/****************************************************************************/

/****************************************************************************/
/*	�֐��錾																*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*	������					*/
void LSC_Init(void);

/*	�I������				*/
void LSC_Finish(void);

/*	�G���[�����֐��̓o�^	*/
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

/*	�n���h���̐���			*/
LSC LSC_Create(SJ sj);

/*	�n���h���̏���			*/
void LSC_Destroy(LSC lsc);

/*	�X�g���[���̓o�^		*/
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname);

/*	�ǂݍ��݊J�n			*/
void LSC_Start(LSC lsc);

/*	�ǂݍ��ݒ�~			*/
void LSC_Stop(LSC lsc);

/*	�|�[�Y�E�|�[�Y����		*/
void LSC_Pause(LSC lsc, Sint32 sw);

/*	�T�[�o�֐�				*/
void LSC_ExecServer(void);

/*	�n���h����Ԃ̎擾		*/
Sint32 LSC_GetStat(LSC lsc);

/*	�o�^�X�g���[�����̎擾	*/
Sint32 LSC_GetNumStm(LSC lsc);

/*	�ǂݍ��ݒ��̃X�g���[��ID�̎擾	*/
Sint32 LSC_GetStmId(LSC lsc, Sint32 no);

/*	�t�@�C�����̎擾	*/
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid);

/*	�X�g���[���ǂݍ��݂̏�Ԏ擾	*/
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid);

/*	�ǂݍ��񂾃f�[�^�T�C�Y�̎擾(sector)	*/
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid);

/*	�o�b�t�@���ʉ����l�̐ݒ�	*/
void LSC_SetFlowLimit(LSC lsc, Sint32 min);

/*	�o�b�t�@���ʉ����l�̎擾	*/
Sint32 LSC_GetFlowLimit(LSC lsc);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/* _CRI_LSC_H_INCLUDED */
