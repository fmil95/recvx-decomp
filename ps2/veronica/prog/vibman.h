#include "common.h"

void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();
int CheckVibrationUnit(unsigned int PortId);
int StartVibration(unsigned int PortId, VibrationInfo* vpp);
int StopVibration(unsigned int PortId);
