#include "vibman.h"

char PortIdTbl[4];
int EnadleVibrationFlag;
unsigned int VibStopTime;

/* 100% match */
void InitVibrationUnit() { // Line 16, Address: 0x2c84e0
    int i;

    VibStopTime = 20; // Line 19, Address: 0x2c84f0

    for (i = 0; i < 4; ++i) { // Line 21, Address: 0x2c8504
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) { // Line 22, Address: 0x2c8508
            pdVibMxSetStopTime(PortIdTbl[i], VibStopTime); // Line 23, Address: 0x2c851c
        } // Line 24, Address: 0x2c852c
    } // Line 25, Address: 0x2c8530

    EnadleVibrationFlag = 0; // Line 27, Address: 0x2c8540
} // Line 28, Address: 0x2c8548

/* 100% match */
void ExitVibrationUnit() { // Line 31, Address: 0x2c8560
    int i;

    for (i = 0; i < 4; ++i) { // Line 34, Address: 0x2c8578
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) { // Line 35, Address: 0x2c857c
            StopVibration(PortIdTbl[i]); // Line 36, Address: 0x2c8590
        }
    } // Line 38, Address: 0x2c8598
} // Line 39, Address: 0x2c85a8

/* 100% match */
void SetUseVibrationUnit(int Flag) {
    EnadleVibrationFlag = Flag; // Line 43, Address: 0x2c85c0
} // Line 44, Address: 0x2c85c4

/* 100% match */
int GetUseVibrationUnit() {
    return EnadleVibrationFlag; // Line 48, Address: 0x2c85d0
} // Line 49, Address: 0x2c85d4

/* 100% match */
int CheckVibrationUnit(unsigned int PortId) {
    return pdVibMxIsReady(); // Line 53, Address: 0x2c85e0
}






/* 100% match */
int StartVibration(unsigned int PortId, VibrationInfo* vpp) { // Line 62, Address: 0x2c85f0


    if (EnadleVibrationFlag == 0) { // Line 65, Address: 0x2c8600
        return 0; // Line 66, Address: 0x2c8614
    }

    if (PortId % 6 != 2) { // Line 69, Address: 0x2c861c
        return -3; // Line 70, Address: 0x2c863c
    }

    if (CheckVibrationUnit(PortId) != 1) { // Line 73, Address: 0x2c8644
        return -2; // Line 74, Address: 0x2c8658
    }





    vpp->unit = 1; // Line 81, Address: 0x2c8660
    pdVibMxStart(PortId, vpp); // Line 82, Address: 0x2c8664
} // Line 83, Address: 0x2c8670

/* 100% match */
int StopVibration(unsigned int PortId) { // Line 86, Address: 0x2c8690
  if (EnadleVibrationFlag == 0) { // Line 87, Address: 0x2c869c
    return 0; // Line 88, Address: 0x2c86ac
  }

  if (PortId % 6 != 2) { // Line 91, Address: 0x2c86b4
    return -3; // Line 92, Address: 0x2c86d4
  }


  if (CheckVibrationUnit(PortId) != 1) return -2; return pdVibMxStop(PortId); // Line 96, Address: 0x2c86dc



} // Line 100, Address: 0x2c8704
