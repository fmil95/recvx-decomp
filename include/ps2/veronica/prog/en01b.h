#ifndef _EN01B_H_
#define _EN01B_H_

#include "types.h"

void bhEne01_Dummy();
void bhEne01_Brain02B(BH_PWORK* epw);
void bhEne01_MVType00B(BH_PWORK* epw);
void bhEne01_MVType02B(BH_PWORK* epw);
void bhEne01_MV13B(BH_PWORK* epw);
void bhEne01_NGType00B(BH_PWORK* epw);
void bhEne01_NG03B(BH_PWORK* epw);
void bhEne01_DGType00B(BH_PWORK* epw);
void bhEne01_DGType02B(BH_PWORK* epw);
void bhEne01_DDType00B(BH_PWORK* epw);
void bhEne01_DDType02B(BH_PWORK* epw);
void bhEne01_DG05B(BH_PWORK* epw);
void bhEne01_DG09B(BH_PWORK* epw);
void bhEne01_DG12B(BH_PWORK* epw);
void bhEne01_DG13B(BH_PWORK* epw);
void bhEne01_DD02B(BH_PWORK* epw);
void bhEne01_RotNeck(BH_PWORK* epw, int neck_no, BH_PWORK* ply, int ply_neck_no);
/*int bhEne01_SideRotNeck(BH_PWORK* epw, int neck_no, _anon14* trg, int neck_ry, int neck_ry_max, int ang);
int bhSearchPlayer2(BH_PWORK* epw, _anon14* pp, int pp_r, int r);*/

#endif
