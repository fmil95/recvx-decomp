#include "../../../ps2/veronica/prog/weapon.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/sub1.h"
#include "../../../ps2/veronica/prog/main.h"

const short EneDamNear[31][22] = 
{
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,  10,  18,  18,  15, 250,  25,   4,  20,  12,  70,   8,  80,  50, 120, 180,  30, 999, 150, 999,   0 },
    {    0,   0,   4,  13,  13,  13, 150,  10,   1,  12,  12,  60,   4,  40,  10,  50,  80,  30, 999,  80, 999,   0 },
    {    0,   0,  10,  13,  13,  13, 250,  13,   3,  15,  12,  50,   4,  70,  40, 120,  70,  30, 999, 100, 999,   0 },
    {    0,   0,   8,  20,  20,  20, 250,  25,   5,  25,  12,  80,   8,  80,  40,  80, 140,  30, 999, 150, 999,   0 },
    {    0,   0,  10,  13,  13,  13, 250,  15,   3,  10,  12,  60,   4,  70,  50, 140, 100,  30, 999,  80, 999,   0 },
    {    0,   0,  10,  13,  13,  13, 250,  15,   5,   8,  12,  40,   4,  70,  40, 140, 120,  30, 999, 120, 999,   0 },
    {    0,   0,  10,  13,  15,  15, 250,  15,   5,   8,  12,  60,   8,  80,  40, 140, 120,  30, 999, 150, 999,   0 },
    {    0,   0,   8,  13,  10,  10,  80,  10,   2,   8,  12,  30,   4,  80,  40,  40,  80,  30, 999, 150, 999,   0 },
    {    0,   0,  10,  13,  13,  13, 250,  13,   3,  16,  12,  60,   8,  80,  50,  80, 140,  30, 999,  80, 999,   0 },
    {    0,   0,   8,  13,  15,  15, 250,  15,   3,   8,  12,  60,   8,  80,  40, 140,  80,  30, 999, 150, 999,   0 },
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,   6,  16,  16,  16,  80,  16,   3,   4,   6,  40,   4,  50,  25,  25,  15,  10, 999,  30, 999,   0 },
    {    0,   0,   6,  16,  16,  16, 150,  16,   3,  15,   6,  60,   4,  80,  25,  15,  30,  10, 999,  30, 999,   0 },
    {    0,   0,   3,  14,  14,  14,  80,  14,   2,  17,  12,  50,   3,  60,  15,  70,  30,  10, 999,  30, 999,   0 },
    {    0,   0,   3,   4,   4,   2,  30,   2,   1,   2,   3,  16,   1,  40,  12,  24,  12,   2, 999,  20, 999,   0 },
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,  10,  20,  20,  20,  60,  20,   4,   8,  20,  60,   8,  20,  60,  60,  60,  10, 999,  60, 999,   0 },
    {    0,   0,   6,   8,   8,   8, 100,   8,   3,   8,   6,  40,   4,  80,  25,  15,  40,  10, 999,  25, 999,   0 },
    {    0,   0,  16,  14,  14,  10, 100,  14,   4,  10,   7,  40,   6,  80,  15,  40,  20,  20, 999,  30, 999,   0 },
    {    0,   0,   5,  15,  15,  15, 150,  15,   5,   8,  12,  60,   8,  80,  40,  40,  80,  30, 999,  60, 999,   0 },
    {    0,   0,   4,  15,  15,  15, 150,  15,   3,  13,  12,  60,   8,  80,  40, 120,  80,  30, 999,  60, 999,   0 },
    {    0,   0,   5,  13,  13,  13, 100,  13,   3,   8,   7,  30,   5,  60,  40,  40,  80,   5, 999,  20, 999,   0 },
    {    0,   0,   5,  15,  15,  15, 150,  15,   3,  15,  12,  50,   8,  70,  25, 100,  50,  10, 999,  50, 999,   0 },
    {    0,   0,   5,  15,  15,  15, 250,  15,   3,  15,  12,  60,   8,  80,  40,  40,  80,  30, 999,  40, 999,   0 },
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,   5,  15,  15,  13, 250,  15,   3,  20,   8,  50,   8,  80,  40, 120,  80,  30, 999,  80, 999,   0 },
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    {    0,   0,   5,  15,  15,  15, 150,  15,   3,  10,  12,  60,   8,  80,  25,  40,  60,   5, 999, 120, 999,   0 },
    {    0,   0,   5,  15,  15,  15, 180,  15,   3,  10,  12,  60,   8,  80,  25,  25,  25,   5, 999, 120, 999,   0 }
};
const short EneDamMid[31][22]  = 
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 15, 15, 15, 220, 20, 4, 17, 12, 30, 8, 80, 50, 120, 180, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 10, 10, 10, 130, 8, 1, 10, 12, 30, 4, 40, 10, 50, 80, 30, 999, 80, 999, 0 },
	{ 0, 0, 0, 8, 8, 8, 220, 8, 3, 15, 8, 20, 4, 70, 40, 120, 70, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 17, 17, 17, 220, 20, 5, 20, 12, 30, 8, 80, 40, 80, 140, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 10, 10, 10, 220, 18, 3, 8, 12, 30, 4, 70, 50, 140, 100, 30, 999, 60, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 220, 13, 5, 8, 12, 30, 4, 70, 40, 140, 120, 30, 999, 150, 999, 0 },
	{ 0, 0, 5, 15, 15, 15, 220, 15, 5, 8, 12, 60, 8, 80, 40, 140, 120, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 8, 8, 8, 40, 8, 2, 8, 12, 10, 4, 80, 40, 40, 80, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 10, 10, 10, 220, 10, 3, 8, 12, 30, 8, 80, 50, 80, 140, 30, 999, 80, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 220, 13, 3, 8, 12, 30, 8, 80, 40, 40, 80, 30, 999, 150, 999, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 13, 13, 13, 70, 13, 3, 4, 6, 30, 4, 50, 25, 25, 15, 10, 999, 30, 999, 0 },
	{ 0, 0, 0, 16, 16, 16, 100, 16, 3, 12, 6, 30, 4, 80, 25, 15, 30, 10, 999, 30, 999, 0 },
	{ 0, 0, 0, 10, 10, 10, 50, 10, 2, 13, 12, 25, 3, 60, 15, 70, 30, 10, 999, 30, 999, 0 },
	{ 0, 0, 0, 4, 4, 2, 26, 2, 1, 2, 3, 8, 1, 40, 12, 24, 12, 2, 999, 20, 999, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 20, 20, 20, 60, 20, 4, 8, 10, 60, 8, 20, 60, 60, 60, 10, 999, 60, 999, 0 },
	{ 0, 0, 0, 5, 5, 5, 60, 5, 3, 4, 6, 20, 4, 80, 25, 15, 40, 10, 999, 25, 999, 0 },
	{ 0, 0, 0, 10, 10, 8, 80, 10, 4, 6, 6, 20, 6, 80, 15, 40, 20, 20, 999, 30, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 220, 13, 5, 8, 12, 30, 8, 80, 50, 50, 120, 50, 999, 120, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 130, 13, 3, 8, 12, 30, 8, 80, 25, 100, 60, 50, 999, 60, 999, 0 },
	{ 0, 0, 0, 10, 10, 10, 80, 10, 3, 8, 6, 20, 5, 60, 15, 10, 40, 5, 999, 20, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 80, 13, 3, 8, 12, 30, 8, 80, 40, 100, 50, 10, 999, 50, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 220, 13, 3, 8, 12, 30, 8, 80, 40, 40, 80, 30, 999, 40, 999, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 15, 15, 13, 220, 20, 3, 13, 8, 30, 8, 80, 40, 120, 80, 30, 999, 80, 999, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 13, 13, 13, 130, 13, 3, 10, 12, 30, 8, 80, 25, 40, 60, 5, 999, 120, 999, 0 },
	{ 0, 0, 0, 13, 13, 13, 130, 13, 3, 10, 12, 30, 8, 80, 25, 25, 25, 5, 999, 120, 999, 0 }
};
const short EneDamFar[31][22] = 
{
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 0,   0,   0,   0, 0 }, 
    { 0, 0, 0, 12, 12, 12, 200, 15, 4, 15, 12, 10, 8, 80, 0, 0,  1, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0,  8,  8,  8,  80,  6, 1,  8, 12, 10, 4, 40, 0, 0,  3, 1, 999,  80, 999, 0 }, 
    { 0, 0, 0,  5,  5,  5, 200,  8, 3,  8,  8, 10, 4, 70, 0, 0,  1, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0, 13, 13, 13, 200, 17, 5, 15, 12, 10, 8, 80, 0, 0,  3, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0,  8,  8,  8, 200, 15, 3,  8, 12, 10, 4, 80, 0, 0,  3, 1, 999,  60, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 10, 5,  8, 12, 10, 4, 70, 0, 0,  1, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 10, 5,  8, 12, 10, 8, 80, 0, 0,  1, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0,  5,  5,  5,  10,  5, 2,  8, 12,  0, 4, 80, 0, 0,  0, 1, 999, 150, 999, 0 }, 
    { 0, 0, 0,  8,  8,  8, 200,  8, 3,  8, 12, 10, 8, 80, 0, 0,  2, 1, 999,  80, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 10, 3,  8, 12, 10, 8, 80, 0, 0,  1, 0, 999, 150, 999, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 0,   0,   0,   0, 0 }, 
    { 0, 0, 0, 10, 10, 10,  60, 10, 3,  8,  6, 10, 4, 50, 0, 0,  0, 0, 999,  30, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10,  80, 10, 3,  8,  6, 10, 4, 80, 0, 0,  1, 0, 999,  30, 999, 0 }, 
    { 0, 0, 0,  8,  8,  8,  30,  8, 2, 10, 12, 10, 3, 60, 0, 0,  0, 0, 999,  30, 999, 0 }, 
    { 0, 0, 0,  3,  3,  3,  16,  2, 1,  2,  3,  4, 1, 40, 0, 0,  1, 0, 999,  20, 999, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  8,  0,  0, 0,  0, 0, 0,  0, 0,   0,   0,   0, 0 }, 
    { 0, 0, 0, 20, 20, 20,  60, 20, 4,  8, 12, 60, 8, 20, 0, 0, 20, 0, 999,  20, 999, 0 }, 
    { 0, 0, 0,  3,  3,  3,  20,  3, 3,  4,  6, 20, 4, 80, 0, 0,  1, 0, 999,  25, 999, 0 }, 
    { 0, 0, 0,  6,  6,  6,  60,  6, 4,  4,  6, 10, 6, 80, 0, 0,  1, 1, 999,  30, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 10, 5,  8, 12, 10, 8, 80, 0, 0,  1, 0, 999, 120, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10,  80, 10, 3,  8,  6, 10, 8, 80, 0, 0,  3, 1, 999,  60, 999, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 0,   0,   0,   0, 0 }, 
    { 0, 0, 0, 10, 10, 10,  50, 10, 3,  8, 12, 10, 8, 80, 0, 0,  1, 1, 999,  50, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 10, 3,  8, 12, 10, 8, 80, 0, 0,  1, 0, 999,  40, 999, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 0,   0,   0,   0, 0 }, 
    { 0, 0, 0, 10, 10, 10, 200, 15, 5,  6, 12, 10, 8, 80, 0, 0,  1, 1, 999,  80, 999, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 1,   0,   0,   0, 0 }, 
    { 0, 0, 0,  0,  0,  0,   0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0, 1,   0,   0,   0, 0 }, 
    { 0, 0, 0, 10, 10, 10,  80, 10, 3,  8, 12, 10, 8, 80, 0, 0,  1, 0, 999, 120, 999, 0 }, 
    { 0, 0, 0, 10, 10, 10,  80, 10, 3,  8, 12, 10, 8, 80, 0, 0,  1, 0, 999, 120, 999, 0 }  
};
const int WpnAngTab[21][3] = 
{
    {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 },  
    {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 }, {     0,     0,   0 }, {  4551,  1092,   0 }, {     0,   364,   0 },  
    {     0,   364,   0 }, {     0, 61167,   0 }, {     0, 60439, 546 }, {     0, 60439, 546 }, {     0, 60439, 546 }, {     0, 60439, 546 },  
    {     0,     0,   0 }, {  4551,  1092,   0 }, {     0,     0,   0 }  
};
/*unsigned int HitWalEff[8]; - unused */

// 100% matching! 
void bhSetWeapon(O_WRK* op, int wpn_no, int flg)
{
    npSetMemory((unsigned char*)op, sizeof(O_WRK), 0);
    
    op->flg = 0x81;
    
    op->id = 1210;
    
    op->type = wpn_no & 0xFF;
    
    op->flr_no = plp->flr_no;
    
    op->mtx = (void*)op->mtxbuf; // cast was likely to a non-void type
    
    if (wpn_no != 0) 
    {
        op->flg |= 0x40000;
    } 
    else
    {
        op->flg &= ~0x40000;
    }
    
    if (flg == 0) 
    {
        op->lkono = 9;
    }
    else
    {
        op->lkono = 13;
    }
    
    op->lkwkp = (unsigned char*)plp;
    
    if (plp->wpnr_no < 10) 
    {
        *(int*)plp->exp0 = 0;
    } 
    else 
    {
        *(int*)plp->exp0 = 1;
    }
    
    if (plp->wpnr_no > 1)
    {
        plp->flg |= 0x20000;
        
        plp->mlwP->owP[7].flg &= ~0x2;
        plp->mlwP->owP[8].flg &= ~0x2;
        plp->mlwP->owP[9].flg &= ~0x2;
    }
    else 
    {
        plp->flg &= ~0x20000; 

        if (plp->wpnr_no != 1) 
        {
            plp->mlwP->owP[7].flg &= ~0x2;
            plp->mlwP->owP[8].flg &= ~0x2;
            plp->mlwP->owP[9].flg &= ~0x2;
        }
    }
    
    plp->mlwP->owP[11].flg &= ~0x2;
    plp->mlwP->owP[12].flg &= ~0x2;
    plp->mlwP->owP[13].flg &= ~0x2;
}

// 100% matching!
void bhObjWpn(BH_PWORK* op) // should be O_WRK?
{
    if (op->lkono == 9) 
    {
        if ((plp->mode1 == 0) || (plp->mode0 == 7)) 
        {
            op->ax = WpnAngTab[op->type][0];
            op->ay = WpnAngTab[op->type][1];
            op->az = WpnAngTab[op->type][2];
        }
        else
        {
            op->ax = 0;
            op->ay = 0;
            op->az = 0;
        }
    }
}

// 100% matching!
void bhActionWeapon(BH_PWORK* op) // should be O_WRK?
{
    NJS_POINT3 pos; 
    NJS_CNK_OBJECT* obp; 
    int ang; 
    int rr; 
    float nn; 

    obp = &op->mlwP->objP[2];
    
    switch (op->flg & 0xC80000)
    {
    case 0x80000:
        switch (op->mode0)
        {
        case 0:
            obp->pos[0] = -0.3f;
            
            op->mode0++;
            break;
        case 1:
            obp->pos[0] = -0.5f;
            
            op->mode0++;
            break;
        case 2:
            obp->pos[0] += 0.1f;
            
            if (obp->pos[0] >= 0)
            {
                obp->pos[0] = 0;
                
                op->flg &= ~0x80000;
                
                op->mode0 = 0;
            }
            
            break;
        }
        
        break;
    case 0x400000:
        if ((plp->mode0 != 1) || (plp->mode1 != 1)) 
        {
            obp->pos[0] = 0;
            
            op->flg &= ~0x400000;
            
            op->mode0 = 0;
            break;
        }
        
        if (sys->ply_id == 0) 
        {
            switch (op->mode0)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                obp->pos[0] = 0.16f * -(1.0f + op->mode0);
                
                op->mode0++;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                obp->pos[0] = 0.16f * -(9.0f - op->mode0);
                
                op->mode0++;
                break;
            case 9:
                obp->pos[0] = 0;
                
                op->flg &= ~0x400000;
                
                op->mode0 = 0;
				break;
            }
        } 
        else 
        {
            switch (op->mode0)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                obp->pos[0] = 0.2f * -(1.0f + op->mode0);
                
                op->mode0++;
                break;
            case 4:
            case 5:
            case 6:
                obp->pos[0] = 0.4f * -(6.0f - op->mode0);
                
                op->mode0++;
                break;
            case 7:
                obp->pos[0] = 0;
                
                op->flg &= ~0x400000;
                
                op->mode0 = 0;
                break;
            }
        }
        
        break;
    case 0x800000:
        if ((plp->mode0 != 1) || (plp->mode1 != 1)) 
        {
            obp->ang[1] = 0;
            
            op->flg &= ~0x800000;
            
            op->mode0 = 0;
            break;
        }
        
        switch (op->mode0)
        {
        case 0:
            rr = (sys->ply_id != 0) ? 21845 : 18204;

            if (obp->ang[1] < rr)
            {
                if (sys->ply_id == 0)
                {
                    obp->ang[1] += 1820;
                }
                else
                {
                    obp->ang[1] += 2730;
                }

                if (obp->ang[1] >= rr)
                {
                    obp->ang[1] = rr;
                }
                
                ang = obp->ang[1];
                
                if (ang > 16384)
                {
                    ang = 16384;
                }
                
                nn = njSin(ang);
                
                bhCalcModel(op);
                
                pos.x = -0.5f;
                pos.y = 0;
                pos.z = 1.0f;
                
                njCalcPoint(&op->mlwP->owP[2].mtx, &pos, (NJS_POINT3*)&sys->ef.px);
                
                sys->ef.id = 2;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.type = 9;
                
                sys->ef.flr_no = 3;
                
                sys->ef.mdlver = 1;
                
                sys->ef.sy = sys->ef.sx = 2.0f * nn;
                sys->ef.sz = 0.4f * nn;
                
                sys->ef.ax = 0;
                sys->ef.ay = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            break;
        case 1:
            if (obp->ang[1] > 0)
            {
                obp->ang[1] -= 4551;
            }
            
            if (obp->ang[1] < 0)
            {
                obp->ang[1] = 0;
                
                op->flg &= ~0x800000;
                
                op->mode0 = 0;
            }
            
            break;
        }
        
        break;
    }
}

// 100% matching!
short bhCheckBullet() 
{
    short iw; 
    short bn;

    iw = swork.pip[0];
    
    bn = swork.pip[iw];
    
    if ((((swork.pip[iw] >> 16) & 0x800)) || ((plp->at_flg & 0x40000000))) 
    {
        bn = -1;
    }
    
    return bn;
}

// 100% matching!
int bhCountBullet()
{
    short iw;
    short bn; 

    iw = swork.pip[0];
	
    bn = swork.pip[iw];
    
    if ((((swork.pip[iw] >> 16) & 0x800)) || ((plp->at_flg & 0x40000000)))
    {
        return 1;
    }
    else if (bn < 1)
    {
        return 0; 
    }
    else
    {
        bn--;
        
        if (bn < 1)
        {
            sys->gm_flg |= 0x40000;
        }
        
        swork.pip[iw] &= 0xFFFF0000;
        swork.pip[iw] |= bn & 0xFFFF;
    }
    
    return 1;
}

// 98.84% matching (matches on NGC)
int bhCheckGunAtari(GA_WORK* gap)
{
    NJS_CAPSULE gatr;    
    NJS_CAPSULE wal;    
    NJS_POINT3 ap;  
    NJS_POINT3 ps;       
    NJS_VECTOR sca;     
    NJS_POINT3 wps;   
    NJS_VECTOR gvec;     
    NJS_LINE gline;      
    float rn, rmax;           
    float a;           
    float nr;       
    float ll;           
    float knr;          
    float len;         
    BH_PWORK* pp;      
    ATR_WORK* wlp;        
    int i, j;         
    int id;            
    int kno;           
    int walhit;         
    int wp_hef;         
    int jno;             
    int watflg;       
    int wno;         
    unsigned int wp_flg; 
    NJS_VECTOR vec0, vec1;    
    NJS_LINE wtln;      
    O_WRK* op;        // not from DWARF
    float px, py, pz; // not from DWARF 
    static int igct;     
    
    wno = gap->wpn_no;
    
    if ((gap->at_flg & 0x100)) 
    {
        wno = 6;
    }
    
    wp_flg = WpnTab[wno].flg;
    wp_hef = WpnTab[wno].hiteff;
    
    if (((gap->at_flg & 0x4)) && ((wp_flg & 0x5000))) 
    {
        gap->px = gap->gx;
        gap->py = gap->gy - 1.0f;
        gap->pz = gap->gz;
    }
    
    gline.px = gap->gx;
    gline.py = gap->gy;
    gline.pz = gap->gz;
    
    gline.vx = gap->vx;
    gline.vy = gap->vy;
    gline.vz = gap->vz;
    
    gvec.x = gap->vx;
    gvec.y = gap->vy;
    gvec.z = gap->vz;
    
    njUnitVector(&gvec);
    
    if ((wp_flg & 0x20000000))
    {
        wps.x = gap->px + gap->vx;
        wps.y = gap->py + gap->vy;
        wps.z = gap->pz + gap->vz;
        
        len = gap->l;
        
        walhit = 0;
    }
    else if (bhCheckL2Wall(&gline, 0x400, &len) != 0)
    {
        len += 10.0f;
        
        wps = sys->apos;
        wlp = sys->ahtp;
        
        if ((wlp->attr & 0x1000000)) 
        {
            ps.x = wlp->px;
            ps.y = 10.0f + wlp->py;
            ps.z = wlp->pz;
            
            bhSetExplosion(&ps);
            
            op = &sys->obwp[wlp->prm3];
            
            op->mdflg |= 0x1; 
            
            wlp->flg &= ~0x1;
        }
        
        walhit = 1;
    } 
    else 
    {
        wps.x = gap->gx + gap->vx;
        wps.y = gap->gy + gap->vy;
        wps.z = gap->gz + gap->vz;
        
        len = gap->l;
        
        walhit = 0;
    } 
    
    rn   = gap->rn;
    rmax = gap->rmax;
    
    if (((gap->at_flg & 0x4)) || ((gap->at_flg & 0x8))) 
    {
        rn   *= 2.0f;
        rmax *= 1.2f;
    }
    
    ps.x = gap->vx;
    ps.y = gap->vy;
    ps.z = gap->vz;
    
    njUnitVector(&ps);
    
    ps.x *= len;
    ps.y *= len;
    ps.z *= len; 
    
    gatr.c1.x = gap->px;
    gatr.c1.y = gap->py;
    gatr.c1.z = gap->pz;
    
    gatr.c2.x = gap->px + ps.x;
    gatr.c2.y = gap->py + ps.y; 
    gatr.c2.z = gap->pz + ps.z; 
    
    gatr.r = gap->r; 
    
    nr = 0;
    
    id = -1;
    
    pp = ene;
    
    for (i = 0; i < sys->ewk_n; i++, pp++) 
    {
        if ((((pp->flg & 0x1)) && ((pp->flg & 0x20)) && (!(pp->flg & 0x2))) && (!(pp->stflg & 0x1000000)) && (((!(pp->flg & 0x80)) || (!(((O_WRK*)pp->lkwkp)->stflg & 0x1000000))) && (!(pp->flg & 0x4))))
        {
            ap.x = 0.5f * (pp->watr.c1.x + pp->watr.c2.x);
            ap.y = 0.5f * (pp->watr.c1.y + pp->watr.c2.y);
            ap.z = 0.5f * (pp->watr.c1.z + pp->watr.c2.z);
            
            njDistanceP2L(&ap, (NJS_LINE*)&gap->px, &ps);
            
            sca.x = ps.x - gap->gx;
            sca.y = ps.y - gap->gy;
            sca.z = ps.z - gap->gz;
            
            ll = rn * njScalor(&sca);
            
            if (ll > rmax) 
            {
                ll = rmax;
            }
            
            gatr.r = gap->r + ll; 
            
            if (!(wp_flg & 0x20000000)) 
            {
                vec0.x = gap->vx;
                vec0.y = 0;
                vec0.z = gap->vz;
                
                vec1.x = ps.x - (gap->px - (gvec.x * gap->r));
                vec1.y = 0;
                vec1.z = ps.z - (gap->pz - (gvec.z * gap->r));
                
                njUnitVector(&vec0);
                njUnitVector(&vec1);
                
                if (njInnerProduct(&vec0, &vec1) >= 0) 
                {
                    goto label_1;
                } 
            } 
            else 
            {
label_1:
                if (!(wp_flg & 0x8)) 
                { 
                    if (npCollisionCheckCCEx(&gatr, &pp->watr, &ap) != 0)
                    {
                        npDistanceP2C(&ap, &pp->watr, &ps);
                        
                        if (((pp->flg & 0x100)) && (pp->py > ps.y))
                        {
                            ps.y = 1.0f + pp->py;
                        }
                        
                        goto label_2;
                    }
                } 
                else 
                { 
                    if ((kno = bhCheckCapCol2Capsule(pp, &gatr, &ps)) >= 0) 
                    {
label_2:
                        wal.c1.x = ps.x;
                        wal.c1.y = ps.y;
                        wal.c1.z = ps.z;
                        
                        wal.c2.x = gap->gx;
                        wal.c2.y = gap->gy;
                        wal.c2.z = gap->gz;
                        
                        wal.r = 0.1f;
                        
                        if (bhCheckC2WallN(&wal, 0x400) == 0) 
                        {
                            sca.x = gap->gx - ps.x;
                            sca.y = gap->gy - ps.y;
                            sca.z = gap->gz - ps.z;
                            
                            ll = njScalor(&sca);
                            
                            if (ll < (len + gatr.r)) 
                            { 
                                if ((ll < nr) || (nr == 0))
                                {
                                    nr = ll;
                                    
                                    id = i;
                                    
                                    px = ps.x;
                                    py = ps.y;
                                    pz = ps.z;
                                    
                                    jno = kno;
                                }
                                
                                if ((wp_flg & 0x80000000))
                                {
                                    pp->flg |= 0x4;
                                    
                                    pp->dpx = px;
                                    pp->dpy = py;
                                    pp->dpz = pz;
                                    
                                    pp->dvx = gap->vx;
                                    pp->dvy = gap->vy;
                                    pp->dvz = gap->vz;
                                    
                                    pp->dax = gap->ax;
                                    pp->day = gap->ay;
                                    
                                    pp->wpnr_no = gap->wpn_no;
                                    
                                    if (!(wp_flg & 0x8)) 
                                    {
                                        kno = 0;
                                        knr = 0;
                                        
                                        for (j = 1; j < (int)pp->mlwP->obj_num; j++) 
                                        {
                                            sca.x = px - pp->mlwP->owP[j].mtx[12];
                                            sca.y = py - pp->mlwP->owP[j].mtx[13];
                                            sca.z = pz - pp->mlwP->owP[j].mtx[14];
                                            
                                            ll = njScalor(&sca); 
                                            
                                            if ((knr == 0) || (knr > ll)) 
                                            {
                                                kno = j;
                                                knr = ll;
                                            }
                                        }
                                    } 
                                    else
                                    {
                                        kno = jno;
                                    }
                                    
                                    pp->djnt_no = kno;
                                    
                                    if (nr < 15.0f) 
                                    {
                                        pp->dam[kno] += EneDamNear[pp->id][wno];
                                        
                                        pp->comb_flg |= 0x10;
                                    } 
                                    else if (nr < 40.0f)
                                    {
                                        pp->dam[kno] += EneDamMid[pp->id][wno];
                                        
                                        pp->comb_flg |= 0x20;
                                    }
                                    else 
                                    {
                                        pp->dam[kno] += EneDamFar[pp->id][wno];
                                        
                                        pp->comb_flg |= 0x40;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    if ((!(wp_flg & 0x80000000)) && (id != -1)) 
    {
        pp = &ene[id];
        
        pp->flg |= 0x4;
        
        pp->dpx = px;
        pp->dpy = py;
        pp->dpz = pz;
        
        pp->dvx = gap->vx;
        pp->dvy = gap->vy;
        pp->dvz = gap->vz;
        
        pp->dax = gap->ax;
        pp->day = gap->ay;
        
        pp->wpnr_no = gap->wpn_no;
        
        if (!(wp_flg & 0x8)) 
        {
            kno = 0; 
            knr = 0;
            
            for (i = 1; i < (int)pp->mlwP->obj_num; i++) 
            {
                sca.x = px - pp->mlwP->owP[i].mtx[12];
                sca.y = py - pp->mlwP->owP[i].mtx[13];
                sca.z = pz - pp->mlwP->owP[i].mtx[14]; 
                
                ll = njScalor(&sca);
                
                if ((knr == 0) || (knr > ll))
                {
                    kno = i;
                    knr = ll; 
                }
            }
        } 
        else 
        {
            kno = jno;
        }
        
        pp->djnt_no = kno;
        
        if (nr < 15.0f)
        {
            pp->dam[kno] += EneDamNear[pp->id][wno];
            
            pp->comb_flg |= 0x10;
        } 
        else if (nr < 40.0f) 
        {
            pp->dam[kno] += EneDamMid[pp->id][wno];
            
            pp->comb_flg |= 0x20;
        } 
        else 
        {
            pp->dam[kno] += EneDamFar[pp->id][wno];
            
            pp->comb_flg |= 0x40;
        } 
        
        if ((wp_flg & 0x20000000))
        {
            ps.x = pp->dpx - pp->mlwP->owP[kno].mtx[12];
            ps.y = pp->dpy - pp->mlwP->owP[kno].mtx[13];
            ps.z = pp->dpz - pp->mlwP->owP[kno].mtx[14];
            
            njSetMatrix(NULL, &pp->mlwP->owP[kno].mtx);
            
            njInvertMatrix(NULL);
            
            njCalcVector(NULL, &ps, (NJS_VECTOR*)&gap->px);
            njCalcVector(NULL, (NJS_VECTOR*)&gap->vx, &ps);
            
            gap->at_flg = kno;
            
            gap->wpn_no = id;
            
            gap->ay = (int)(10430.381f * atan2f(ps.x, ps.z)) + 32768;
            
            knr = ps.y; // assigning ps.y directly below causes very different code-gen
            
            gap->ax = (int)(10430.381f * atan2f(knr, njSqrt((ps.x * ps.x) + (ps.z * ps.z)))); 
        }
    }
    
    watflg = 0;
    
    if (((id == -1) && ((sys->st_flg & 0x40))) || (((wp_flg & 0x80000000)) && ((sys->st_flg & 0x40))))
    {
        wtln.px = gline.px; 
        wtln.py = gline.py;
        wtln.pz = gline.pz;
        
        wtln.vx = wps.x - gline.px;
        wtln.vy = wps.y - gline.py; 
        wtln.vz = wps.z - gline.pz;
        
        if (bhCheckL2Water(&wtln, &ps) != NULL)
        {
            watflg = 1;
            
            if (gap->wpn_no == 11) 
            {
                j = 32;
            }
            else 
            {
                j = 1;
            }
            
            i = j;
            
            while (i--) 
            {
                sys->ef.id = 15;
                
                sys->ef.flg = 1;
                
                sys->ef.mdlver = 0;
                
                sys->ef.type = 2;
                
                sys->ef.flr_no = (i & 3) * 2;
                
                if (gap->wpn_no == 11)
                {
                    sca.x = gap->px - ps.x;
                    sca.y = gap->py - ps.y;
                    sca.z = gap->pz - ps.z;
                    
                    ll = njScalor(&sca);
                    ll = gap->r + (gap->rn * ll);
                    
                    sys->ef.px = ps.x + (((2.0f * ll) * (-rand() / -2.1474836E9f)) - ll);
                    sys->ef.pz = ps.z + (((2.0f * ll) * (-rand() / -2.1474836E9f)) - ll);
                    sys->ef.py = ps.y - 0.1f;
                    
                    if (bhCheckWater((NJS_POINT3*)&sys->ef.px) != NULL) 
                    {
                        sys->ef.ay = 0;
                        
                        sys->ef.sx = 0.4f;
                        sys->ef.sy = 0.6f + (0.2f * (-rand() / -2.1474836E9f));
                        sys->ef.sz = 0.4f; 
                        
                        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                    }
                } 
                else 
                {
                    sys->ef.px = ps.x + ((-rand() / -2.1474836E9f) - 0.5f);
                    sys->ef.pz = ps.z + ((-rand() / -2.1474836E9f) - 0.5f);
                    sys->ef.py = ps.y;
                    
                    sys->ef.ay = 0;
                    
                    if (WpnTab[gap->wpn_no].ef_scale < 1.5f) 
                    {
                        sys->ef.sx = 0.8f;
                        sys->ef.sy = 0.8f + (0.2f * (-rand() / -2.1474836E9f));
                        sys->ef.sz = 0.8f;
                        
                        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                        bhSetWaterSplash4((NJS_POINT3*)&sys->ef.px, gap->ay, 0, 0.8f, 0.8f, 0.8f);
                    }
                    else
                    {
                        sys->ef.sx = 1.2f;
                        sys->ef.sy = 1.0f + (0.25f * (-rand() / -2.1474836E9f));
                        sys->ef.sz = 1.2f;
                        
                        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                        bhSetWaterSplash4((NJS_POINT3*)&sys->ef.px, gap->ay, 1, 1.2f, 1.2f, 1.2f);
                    }
                }
            } 
        }
    }
    
    if (((id == -1) && (walhit != 0) && (wp_hef != 0) && (watflg == 0)) || (((wp_flg & 0x80000000)) && (walhit != 0) && (wp_hef != 0) && (watflg == 0)))
    {
        igct++;
        
        if ((gap->wpn_no == 8) && ((igct % 3) == 0)) 
        {
            if (id == -1) 
            {
                return 0;
            }
            
            return 1;
        }
        
        if (bhCheckWallAttrB89(wlp) != 0) 
        {
            ps.x = -gline.vx;
            ps.y = -gline.vy;
            ps.z = -gline.vz;
            
            bhSetEffGunSpark(&wps, &ps, 0xFFF8F8A0, 0x4CE04010, wp_hef - 4);
            bhSetGunSplash(gap, &wps, wlp->prm0);
        }
    }
    
    if (id == -1)
    {
        return 0;
    }
    
    return 1;
}

// 100% matching!
void bhCheckKnifeAtari(GA_WORK* gap) 
{
    NJS_LINE gline;  
    NJS_CAPSULE cap; 
    NJS_POINT3 sca;  
    NJS_POINT3 ps, wps;   
    float knr;       
    float ll;        
    float len;       
    int i, j;           
    int kno;         
    BH_PWORK* pp;    

    cap.c1.x = gap->px;
    cap.c1.y = gap->py;
    cap.c1.z = gap->pz;
    
    cap.c2.x = gap->gx;
    cap.c2.y = gap->gy;
    cap.c2.z = gap->gz;
    
    cap.r = gap->r;
    
    gline.px = gap->gx;
    gline.py = gap->gy;
    gline.pz = gap->gz;
    
    gline.vx = gap->vx;
    gline.vy = gap->vy;
    gline.vz = gap->vz;
    
    if ((sys->st_flg & 0x40)) 
    {
        if (bhCheckL2Water(&gline, &ps) != NULL)
        {
            sys->ef.id = 11;
            
            sys->ef.flg = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 1;
            
            sys->ef.flr_no = 0;
            
            sys->ef.sx = 2.0f;
            sys->ef.sy = 2.0f;
            sys->ef.sz = 2.0f;
            
            sys->ef.px = ps.x + ((-rand() / -2.1474836E9f) - 0.5f);
            sys->ef.pz = ps.z + ((-rand() / -2.1474836E9f) - 0.5f);
            sys->ef.py = ps.y;
            
            sys->ef.ay = gap->ay - 16384;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 1);
            
            sys->ef.type = 0;
            
            sys->ef.sx = 1.2f;
            sys->ef.sy = 1.2f;
            sys->ef.sz = 1.2f;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 1);
        }
    }
    
    if (bhCheckL2Wall(&gline, 0x400, &len) != 0) 
    {
        wps = sys->apos; 
        
        if (bhCheckWallAttrB89(sys->ahtp) != 0) 
        {
            ps.x = gap->gx - wps.x;
            ps.y = gap->gy - wps.y;
            ps.z = gap->gz - wps.z;
            
            njUnitVector(&ps);
            
            bhSetEffGunSpark(&wps, &ps, 0xFFF8F8A0, 0x4CE04010, WpnTab[gap->wpn_no].hiteff - 4);
        }
        
        CallPlayerWeaponSeEx(&wps, 277, 1);
        
        plp->mode0 = 1;
        plp->mode1 = 1;
        plp->mode2 = 72;
        plp->mode3 = 0;
    }
    else 
    {
        pp = ene;
        
        for (i = 0; i < sys->ewk_n; i++, pp++)
        {
            if ((((pp->flg & 0x1)) && ((pp->flg & 0x20)) && (!(pp->flg & 0x2)) && (!(pp->stflg & 0x1000000)) && ((!(pp->flg & 0x80)) || (!(((BH_PWORK*)pp->lkwkp)->stflg & 0x1000000))) && (!(pp->flg & 0x4))) && (npCollisionCheckCC(&cap, &pp->watr) != 0))
            {
                if (pp->id != 0)
                {
                    CallPlayerWeaponSeEx((NJS_POINT3*)&gap->gx, 275, 1);
                }
                
                pp->flg |= 0x4;

                knr = 0;
                kno = 0;
                
                pp->dpx = gap->px;
                pp->dpy = gap->py;
                pp->dpz = gap->pz;
                
                pp->dvx = gap->vx;
                pp->dvy = gap->vy;
                pp->dvz = gap->vz;
                
                pp->dax = gap->ax;
                pp->day = gap->ay;
                
                pp->wpnr_no = gap->wpn_no;
                
                for (j = 1; j < (int)pp->mlwP->obj_num; j++)
                {
                    sca.x = gap->px - pp->mlwP->owP[j].mtx[12];
                    sca.y = gap->py - pp->mlwP->owP[j].mtx[13];
                    sca.z = gap->pz - pp->mlwP->owP[j].mtx[14];
                    
                    ll = njScalor(&sca);
                    
                    if ((knr == 0) || (knr > ll)) 
                    {
                        knr = ll;
                        kno = j;
                    }
                }
                
                pp->djnt_no = kno;
                
                pp->dam[kno] += EneDamNear[pp->id][gap->wpn_no];
                
                pp->comb_flg |= 0x10; 
            }
        }
    }
}

// 100% matching1
int bhCheckFlyAtari(GA_WORK* gap, int eidx)
{
    NJS_CAPSULE wal; 
    NJS_SPHERE spr;  
    NJS_VECTOR sca;  
    NJS_POINT3 ps;   
    float knr, ll, nr;      
    int i, j;         
    int id;        
    int kno;       
    BH_PWORK* pp;    

    id = -1;
    
    pp = ene;
    
    spr.c.x = gap->px;
    spr.c.y = gap->py;
    spr.c.z = gap->pz;
    spr.r   = gap->r;
    
    for (i = 0; i < sys->ewk_n; i++, pp++)
    {
        if ((((pp->flg & 0x1)) && ((pp->flg & 0x20)) && (!(pp->flg & 0x2)) && (!(pp->stflg & 0x1000000))) && (eidx != i) && ((!(pp->flg & 0x80)) || (!(((O_WRK*)pp->lkwkp)->stflg & 0x1000000))) && (npCollisionCheckSC(&spr, &pp->watr) != 0)) 
        {
            npDistanceP2C((NJS_POINT3*)&gap->px, &pp->watr, &ps);
            
            wal.c1.x = ps.x;
            wal.c1.y = ps.y; 
            wal.c1.z = ps.z;
            
            wal.c2.x = gap->px;
            wal.c2.y = gap->py;
            wal.c2.z = gap->pz;
            
            wal.r    = 0.1f;
            
            if (bhCheckC2WallN(&wal, 0x400) == 0) 
            {
                knr = 0;
                
                pp->flg |= 0x4;
                
                id = i;
                
                kno = 0;
                
                pp->dpx = gap->px;
                pp->dpy = gap->py;
                pp->dpz = gap->pz;
                
                pp->dvx = gap->vx;
                pp->dvy = gap->vy;
                pp->dvz = gap->vz;
                
                pp->dax = gap->ax;
                pp->day = gap->ay;
                
                pp->wpnr_no = gap->wpn_no;
                
                for (j = 1; j < (int)pp->mlwP->obj_num; j++) 
                { 
                    sca.x = gap->px - pp->mlwP->owP[j].mtx[12];
                    sca.y = gap->py - pp->mlwP->owP[j].mtx[13];
                    sca.z = gap->pz - pp->mlwP->owP[j].mtx[14];
                    
                    ll = njScalor(&sca);
                    
                    if ((knr == 0) || (knr > ll))
                    {
                        knr = ll;
                        kno = j;
                    }
                }
                
                pp->djnt_no = kno;
                
                if ((gap->at_flg & 0x80)) 
                {
                    pp->dam[kno] += EneDamFar[pp->id][gap->wpn_no];
                    
                    pp->comb_flg |= 0x40;
                } 
                else
                {
                    sca.x = gap->px - gap->gx;
                    sca.y = gap->py - gap->gy;
                    sca.z = gap->pz - gap->gz;
                    
                    if (njScalor(&sca) < 15.0f)
                    {
                        pp->dam[kno] += EneDamNear[pp->id][gap->wpn_no];
                        
                        pp->comb_flg |= 0x10;
                    }
                    else 
                    {
                        pp->dam[kno] += EneDamMid[pp->id][gap->wpn_no];
                        
                        pp->comb_flg |= 0x20;
                    }
                }
            }
        }
    }
    
    return id;
}

// 99.09% matching (matches on NGC)
void bhSetBowDamage()
{
    NJS_VECTOR sca; 
    float knr;     
    float ll;      
    int i, j;         
    int kno;      
    BH_PWORK* pp;   
    float px, py, pz; // not from DWARF

    pp = ene;  
    
    for (i = 0; i < sys->ewk_n; i++, pp++) 
    {
        if (((((pp->flg & 0x1)) && ((pp->flg & 0x20)) && (!(pp->flg & 0x2))) && (!(pp->stflg & 0x1000000)) && ((!(pp->flg & 0x80)) || (!(((O_WRK*)pp->lkwkp)->stflg & 0x1000000)))) && (EneDamFar[pp->id][17] != 0))
        {
            px = 0.5f * (pp->watr.c1.x + pp->watr.c2.x);
            py = 0.5f * (pp->watr.c1.y + pp->watr.c2.y);
            pz = 0.5f * (pp->watr.c1.z + pp->watr.c2.z);
            
            pp->flg |= 0x4;
            
            pp->dpx = px;
            pp->dpy = py; 
            pp->dpz = pz;
            
            pp->dvx = 0;
            pp->dvy = 1.0f;
            pp->dvz = 0;
            
            pp->dax = 0;
            pp->day = 0;
            
            pp->wpnr_no = 17;
            
            kno = 0;
            knr = 0;
            
            for (j = 1; j < (int)pp->mlwP->obj_num; j++)
            { 
                sca.x = px - pp->mlwP->owP[j].mtx[12];
                sca.y = py - pp->mlwP->owP[j].mtx[13];
                sca.z = pz - pp->mlwP->owP[j].mtx[14];   
                
                ll = njScalor(&sca); 
                
                if ((knr == 0) || (knr > ll)) 
                {
                    kno = j; 
                    knr = ll;
                }
            }
            
            pp->djnt_no = kno;
            
            pp->dam[kno] += (int)(0.5f * pp->hp); 
            
            pp->comb_flg |= 0x40;
        }
    }
}

// 100% matching!
void bhCheckBombAtari(NJS_POINT3* pos, float ar, int dmax, int dmin)
{
    NJS_CAPSULE wal; 
    NJS_SPHERE spr;
    NJS_VECTOR sca;
    NJS_POINT3 ps;   
    float knr;    
    float ll;        
    float nr;       
    int i, j;          
    int kno;        
    BH_PWORK* pp;   
    NJS_VECTOR vec0, vec1; 
    float inn;      

    spr.c.x = pos->x;
    spr.c.y = pos->y;
    spr.c.z = pos->z;
    
    spr.r = ar;
    
    if ((((plp->flg & 0x1)) && (!(plp->flg & 0x2))) && (!(plp->stflg & 0x1000000))) 
    {
        spr.r = 0.7f * ar;
        
        if (npCollisionCheckSC(&spr, &plp->watr) != 0) 
        {
            npDistanceP2C(pos, &plp->watr, &ps);
            
            wal.c1.x = ps.x;
            wal.c1.y = ps.y;
            wal.c1.z = ps.z;
            
            wal.c2.x = pos->x;
            wal.c2.y = pos->y;
            wal.c2.z = pos->z;
            
            wal.r = 0.1f;
            
            if (bhCheckC2WallN(&wal, 0x400) == 0)
            {
                plp->dpx = ps.x;
                plp->dpy = ps.y;
                plp->dpz = ps.z;
                
                plp->dvx = ps.x - pos->x;
                plp->dvy = ps.y - pos->y;
                plp->dvz = ps.z - pos->z;
                
                plp->dax = 0;
                plp->day = (int)(10430.381f * atan2f(-plp->dvx, -plp->dvz));
                
                vec0.x = -njSin(plp->ay);
                vec0.y = 0;
                vec0.z = -njCos(plp->ay);
                
                vec1.x = -plp->dvx;
                vec1.y = 0;
                vec1.z = -plp->dvz;
                
                njUnitVector(&vec1);
                
                inn = njInnerProduct(&vec0, &vec1);
                
                if (inn > 0) 
                {
                    *(int*)&plp->mode0 = 0x20002;
                } 
                else 
                {
                    *(int*)&plp->mode0 = 0x20102;
                }
                
                plp->flg  |= 0x10004;
                plp->flg2 |= 0x200;
                
                sys->st_flg |= 0x4;
                
                sca.x = plp->px - pos->x;
                sca.y = plp->py - pos->y;
                sca.z = plp->pz - pos->z;
                
                if (njScalor(&sca) < (0.5f * spr.r)) 
                {
                    plp->hp -= dmax;
                }
                else 
                {
                    plp->hp -= dmin;
                }
            }
        }
    }
    
    pp = ene;
    
    spr.r = ar;
    
    for (i = 0; i < sys->ewk_n; i++, pp++) 
    {
        if (((((pp->flg & 0x1)) && ((pp->flg & 0x20)) && (!(pp->flg & 0x2))) && (!(pp->stflg & 0x1000000))) && ((!(pp->flg & 0x80)) || (!(((O_WRK*)pp->lkwkp)->stflg & 0x1000000))) && (npCollisionCheckSC(&spr, &pp->watr) != 0)) 
        {
            npDistanceP2C(pos, &pp->watr, &ps);
         
            wal.c1.x = ps.x;
            wal.c1.y = ps.y;
            wal.c1.z = ps.z;
         
            wal.c2.x = pos->x;
            wal.c2.y = pos->y;
            wal.c2.z = pos->z;
         
            wal.r = 0.1f;
         
            if (bhCheckC2WallN(&wal, 0x400) == 0) 
            {
                pp->flg  |= 0x4;
                pp->flg2 |= 0x200;
                
                pp->dpx = ps.x;
                pp->dpy = ps.y;
                pp->dpz = ps.z;
                
                pp->dvx = ps.x - pos->x;
                pp->dvy = ps.y - pos->y;
                pp->dvz = ps.z - pos->z;
                
                pp->dax = 0;
                pp->day = (int)(10430.381f * atan2f(-pp->dvx, -pp->dvz));
                
                knr = 0;
                
                pp->wpnr_no = 20;
                
                kno = 0;
                
                for (j = 1; j < (int)pp->mlwP->obj_num; j++) 
                {
                    sca.x = pp->dpx - pp->mlwP->owP[j].mtx[12];
                    sca.y = pp->dpy - pp->mlwP->owP[j].mtx[13];
                    sca.z = pp->dpz - pp->mlwP->owP[j].mtx[14];
                    
                    ll = njScalor(&sca);
                    
                    if ((knr == 0) || (knr > ll)) 
                    {
                        knr = ll; 
                        kno = j;
                    }
                }
                
                pp->djnt_no = kno;
                
                sca.x = pp->px - pos->x;
                sca.y = pp->py - pos->y;
                sca.z = pp->pz - pos->z;
                
                if (njScalor(&sca) < (0.5f * ar)) 
                {
                    pp->dam[kno] += dmax;
                    
                    pp->comb_flg |= 0x10;
                } 
                else 
                {
                    pp->dam[kno] += dmin;
                    
                    pp->comb_flg |= 0x20;
                }
            }
        }
    }
}

// 100% matching!
int bhCheckCapCol2Capsule(BH_PWORK* pp, NJS_CAPSULE* cap, NJS_POINT3* hps)
{
    CPCL* cpcl;    
    NJS_CAPSULE cp; 
    NJS_SPHERE sp; 
    NJS_LINE gline; 
    NJS_POINT3 ofp; 
    NJS_POINT3 sca;
    NJS_POINT3 htp; 
    int jno;       
    int jnt_a, jnt_b;    
    int cap_r, cpcl_no;      
    int ct;        
    float len;   
    float nr;     
    
    cpcl = pp->cpcl;
    
    if (cpcl == NULL)
    {
        return -1;
    }
    
    nr = 10000.0f;
    
    jno     = -1;
    cpcl_no = -1;

    gline.px = cap->c1.x;;
    gline.py = cap->c1.y;
    gline.pz = cap->c1.z;
    
    gline.vx = cap->c2.x - gline.px;
    gline.vy = cap->c2.y - gline.py;
    gline.vz = cap->c2.z - gline.pz; 
    
    ct = 0;
    
    while (TRUE)  
    {
        jnt_a = cpcl->jnt_a;
        jnt_b = cpcl->jnt_b;
        
        cap_r = cpcl->cap_r;
        
        if (cap_r == 0) 
        {
            break;
        }
        
        if (jnt_a == jnt_b) 
        {
            cpcl++;
            
            ofp.x = 0.1f * cpcl->jnt_a;
            ofp.y = 0.1f * cpcl->jnt_b;
            ofp.z = 0.1f * cpcl->cap_r;
            
            njCalcPoint(&pp->mlwP->owP[jnt_a].mtx, &ofp, (void*)&sp.c); 
            
            sp.r = 0.1f * cap_r;
            
            if (npCollisionCheckSC(&sp, cap) != 0)
            {
                njDistanceP2L(&sp.c, &gline, &htp);
                
                sca.x = htp.x - gline.px;
                sca.y = htp.y - gline.py;
                sca.z = htp.z - gline.pz;
                
                len = njScalor(&sca);
                
                if (len < nr) 
                {
                    nr = len;
                    
                    jno = jnt_a;
                    
                    cpcl_no = ct;
                    
                    hps->x = htp.x;
                    hps->y = htp.y;
                    hps->z = htp.z;
                }
            }
        } 
        else 
        {
            cp.c1.x = pp->mlwP->owP[jnt_a].mtx[12];
            cp.c1.y = pp->mlwP->owP[jnt_a].mtx[13];
            cp.c1.z = pp->mlwP->owP[jnt_a].mtx[14];
            
            cp.c2.x = pp->mlwP->owP[jnt_b].mtx[12];
            cp.c2.y = pp->mlwP->owP[jnt_b].mtx[13];
            cp.c2.z = pp->mlwP->owP[jnt_b].mtx[14];
            
            cp.r = 0.1f * cap_r;
            
            if (npCollisionCheckCCEx(cap, &cp, &htp) != 0) 
            {
                sca.x = htp.x - gline.px;
                sca.y = htp.y - gline.py;
                sca.z = htp.z - gline.pz; 
                
                len = njScalor(&sca);
                
                if (len < nr) 
                {
                    nr = len;
                    
                    jno = jnt_a; 
                    
                    cpcl_no = ct;
                    
                    hps->x = htp.x;
                    hps->y = htp.y;
                    hps->z = htp.z;
                }
            }
        }
        
        cpcl++; 
        ct++;
    }
    
    if (cpcl_no != -1) 
    {
        pp->cpcl_no = cpcl_no;
        
        return jno;
    }
    
    return -1;
}

// 100% matching1
void bhSetGunSplash(GA_WORK* gap, NJS_POINT3* pos, int wattr)
{
    NJS_VECTOR vec; 

    vec.x = -gap->vx;
    vec.y = -gap->vy;
    vec.z = -gap->vz;
    
    njUnitVector(&vec);
    
    sys->ef.id  = 11;
    sys->ef.flg = 1;
    
    sys->ef.mdlver = 1;
    
    sys->ef.type = wattr;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.ax = 0;
    
    switch (wattr)
    {
    case 0:
    case 3:
        sys->ef.type = 5;
        
        sys->ef.flr_no = 0;
        
        sys->ef.sx = 0.75f * WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sy = 0.75f * WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sz = 0.75f * WpnTab[gap->wpn_no].ef_scale;
        
        sys->ef.ay = gap->ay + 32768;
        bhSetEffectTb(&sys->ef, &vec, NULL, 0);
        break;
    case 1:
    case 2:
        sys->ef.flr_no = 1;
        
        sys->ef.sx = WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sy = WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sz = WpnTab[gap->wpn_no].ef_scale;
        
        sys->ef.ay = gap->ay + 16384;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        sys->ef.ay = gap->ay - 16384;
        bhSetEffectTb(&sys->ef, &vec, NULL, 1);
        break;
    case 4:
    case 5:
        sys->ef.id = 10;
        
        sys->ef.flg  = 0x100001;
        sys->ef.type = 1;
        
        sys->ef.px += 2.0f * vec.x;
        sys->ef.py -= 2.0f;
        sys->ef.pz += 2.0f * vec.z;
        
        sys->ef.sx = WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sy = WpnTab[gap->wpn_no].ef_scale;
        sys->ef.sz = WpnTab[gap->wpn_no].ef_scale;
        
        sys->ef.ay = 0;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        break;
    }
}

// 99.93% matching
void bhSetExplosion(NJS_POINT3* pos) 
{
    POINT pnt;    
    LGT_WORK* lp;
    NJS_VECTOR vc0, vc1; 
    int i;          
   
    CallPlayerActionSe(534, 1);
    
    lp = rom->lgtp;
    
    lp->flg = 3;
    lp->type = 101;
    
    lp->aspd = 8;
    
    lp->lkflg = 0;
    lp->lkno = 0;
    lp->lkono = 0;
    
    lp->mode = 0;
    
    lp->lsrc = 4;
    
    lp->r = 4.5f;
    lp->g = 3.0f;
    lp->b = 1.5f;
    
    lp->nr = 30.0f;
    lp->fr = 200.0f;
    
    lp->px = pos->x;
    lp->py = pos->y;
    lp->pz = pos->z;
    
    lp->lx = 0;
    lp->ly = 0;
    lp->lz = 0;
    
    lp->ct0 = 0;
    
    lp->light = NULL;
    
    pnt.px = pos->x;
    pnt.py = pos->y;
    pnt.pz = pos->z;
    
    pnt.ox = 0;
    pnt.oy = 0;
    pnt.oz = 0;
    
    bhSetEffect(16, &pnt, NULL, 16);
    
    sys->ef.id = 23;
    
    sys->ef.flg  = 1;
    sys->ef.type = 1;
    
    sys->ef.mdlver = 1;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sx = 6.0f;
    sys->ef.sy = 6.0f;
    sys->ef.sz = 6.0f;
    
    sys->ef.px = pos->x - (4.0f * cam.vx);
    sys->ef.py = pos->y - (4.0f * cam.vy);
    sys->ef.pz = pos->z - (4.0f * cam.vz);

    sys->ef.ay = 0;
    sys->ef.ax = 0;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    for (i = 0; i < 2; i++) 
    {
        vc0.x = vc0.y = 0;
        vc0.z = -2.0f;
        
        sys->ef.id = 24;
        
        sys->ef.flg  = 1;
        sys->ef.type = 0;
        
        sys->ef.mdlver = 1;
        
        sys->ef.flr_no = i & 3;
        
        sys->ef.sx = 1.0f + (-rand() / -2.1474836E9f);
        sys->ef.sy = sys->ef.sx;
        sys->ef.sz = 0;
        
        sys->ef.ay = (int)(182.04445f * (360.0f * (-rand() / -2.1474836E9f)));
        sys->ef.ax = (int)(182.04445f * (80.0f  * (-rand() / -2.1474836E9f)));
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
    } 
}

// 99.91% matching
void bhSetExplosionEffect(NJS_POINT3* pos) 
{
    NJS_VECTOR vc0; 
    NJS_VECTOR vc1; 
    int i;         

    sys->ef.id = 23;
    
    sys->ef.flg = 1;
    
    sys->ef.type = 1;
    
    sys->ef.mdlver = 1;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sx = 6.0f;
    sys->ef.sy = 6.0f;
    sys->ef.sz = 6.0f;
    
    sys->ef.px = pos->x - (4.0f * cam.vx);
    sys->ef.py = pos->y - (4.0f * cam.vy);
    sys->ef.pz = pos->z - (4.0f * cam.vz);
    
    sys->ef.ay = 0;
    sys->ef.ax = 0;
    
    bhSetEffectTb((EF_WORK*)&sys->ef, NULL, 0, 0);
    
    for (i = 0; i < 2; i++)
    {
        vc0.y = 0;
        vc0.x = 0;
        vc0.z = -2;
        
        sys->ef.id = 24;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.mdlver = 1;
        
        sys->ef.flr_no = i & 0x3;
        
        sys->ef.sx = 1.0f + (-rand() / -2.1474836e9f);
        sys->ef.sy = sys->ef.sx;
        sys->ef.sz = 0;
        
        sys->ef.ay = 182.04445f * (360.0f * (-rand() / -2.1474836e9f));
        sys->ef.ax = 182.04445f * (80.0f * (-rand() / -2.1474836e9f));
        
        njUnitMatrix(NULL);
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        
        njCalcVector(NULL, &vc0, &vc1);
        
        bhSetEffectTb((EF_WORK*)&sys->ef, &vc1, NULL, 0);
    }
}

// 100% matching!
void bhSetExplosionEffectEx(NJS_POINT3* pos, float scl)
{
    sys->ef.id = 23;
    
    sys->ef.flg = 1;
    
    sys->ef.type = 2;
    
    sys->ef.mdlver = 1;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sz = sys->ef.sy = sys->ef.sx = scl;
    
    sys->ef.px = pos->x - (4.0f * cam.vx);
    sys->ef.py = pos->y - (4.0f * cam.vy);
    sys->ef.pz = pos->z - (4.0f * cam.vz);
    
    sys->ef.ay = 0;
    sys->ef.ax = 0;
    
    bhSetEffectTb((EF_WORK*)&sys->ef, NULL, NULL, 0);
}
