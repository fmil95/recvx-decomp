#ifndef _VIBMAN_H_
#define _VIBMAN_H_

#include "override_katana.h"
#include <sg_pdvib.h>

void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();
int CheckVibrationUnit(unsigned int PortId);
int StartVibration(unsigned int PortId, PDS_VIBPARAM* vpp);
int StopVibration(unsigned int PortId);

#endif
