#ifndef _ADX_FS_H_
#define _ADX_FS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxf.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxf.h>

ADXF adxf_AllocAdxFs(void);
Sint32 adxf_ChkPrmGfr(Uint32 ptid, Sint32 flid);
Sint32 adxf_ChkPrmPt(Uint32 ptid, ADXF_PTINFO* ptinfo);
void ADXF_Close(ADXF adxf);
void ADXF_CloseAll(void);
void adxf_CloseLdptnwHn(void);
void adxf_CloseSjStm(ADXF adxf);
ADXF adxf_CreateAdxFs(void);
void adxf_ExecOne(ADXF adxf);
void ADXF_ExecServer(void);
Sint32 ADXF_GetFnameRange(Sint32 ptid, Sint32 flid, Char8 *fname, Sint32 *ofst, Sint32 *fnsct);
Sint32 ADXF_GetFnameRangeEx(Sint32 ptid, Sint32 flid, Char8 *fname, void **dir, Sint32 *ofst, Sint32 *fnsct);
Sint32 ADXF_GetFsizeByte(ADXF adxf);
Sint32 ADXF_GetFsizeSct(ADXF adxf);
Sint32 ADXF_GetNumReadSct(ADXF adxf);
Sint32 ADXF_GetNumReqSct(ADXF adxf, Sint32 *seekpos);
Sint32 ADXF_GetPtinfoSize(Sint32 ptid);
Sint32 ADXF_GetPtStat(Sint32 ptid);
Sint32 ADXF_GetStat(ADXF adxf);
void adxf_LoadData(ADXF adxf, Sint32 nsct, void *buf);
Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo);
ADXF ADXF_Open(Char8 *fname, void *atr);
ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid);
Sint32 adxf_read_sj32(ADXF adxf, Sint32 nsct, SJ sj);
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf);
Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf);
Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj);
Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type);
Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid);
void adxf_SetCmdHstry(Sint32 ncall, Sint32 fg, Sint32 ptid, Sint32 flid, Sint32 type);
Sint32 adxf_SetFileInfoEx(ADXF_ROFS rofs, Char8* fname, void* atr);
void ADXF_SetOcbiSw(Sint32 fg);
void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct);
Sint32 ADXF_Stop(ADXF adxf);
void ADXF_StopPtLd(void);
Sint32 ADXF_Tell(ADXF adxf);
void adxf_wait_1ms(void);

#endif
