#ifndef _ADX_FS_H_
#define _ADX_FS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxf.h>

#define REG_RCNT0_COUNT     (volatile int *)0x10000000

#define getRcnt0CountShort() *REG_RCNT0_COUNT & 0xFFFF

Sint32 ADXF_AddPartition(Sint32 ptid, Char8 *fname, void *ptinfo, Sint32 nfile);
ADXF adxf_AllocAdxFs(void);
Sint32 adxf_ChkPrmGfr(Sint32 ptid, Sint32 flid);
Sint32 adxf_ChkPrmPt(Sint32 ptid, void *ptinfo);
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
Sint32 adxf_LoadData(ADXF adxf, Sint32 nsct, void *rdbuf);
Sint32 ADXF_LoadPartition(Sint32 ptid, Char8 *fname, void *ptinfo, Sint32 nfile);
Sint32 ADXF_LoadPartitionEx(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo);
Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo);
ADXF ADXF_Open(Char8 *fname, void *atr);
ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid);
Sint32 adxf_read_sj32(ADXF adxf, Sint32 nsct, SJ sj);
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf);
Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf);
Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj);
Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type);
Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid);
void adxf_SetCmdHstry(Sint32 cmdid, Sint32 fg, Sint32 prm0, Sint32 prm1, Sint32 prm2);
Sint32 adxf_SetFileInfoEx(ADXF adxf, Sint8 *fname, void *atr);
void ADXF_SetOcbiSw(Sint32 sw);
void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct);
Sint32 ADXF_Stop(ADXF adxf);
void ADXF_StopPtLd(void);
Sint32 ADXF_Tell(ADXF adxf);
void adxf_wait_1ms(void);

#endif
