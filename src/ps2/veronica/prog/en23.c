#include "../../../ps2/veronica/prog/en23.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/en03sub.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Giant Black Widow 

#pragma divbyzerocheck on 

NJS_POINT3 spl_051[80] = 
{
    { 0.0f,          0.0f,          0.0f },
    { 0.0f, -0.043997999f,          0.0f },
    { 0.0f, -0.123427004f,          0.0f },
    { 0.0f, -0.190007001f,          0.0f },
    { 0.0f, -0.243738994f,          0.0f },
    { 0.0f,    -0.284621f,          0.0f },
    { 0.0f, -0.312653005f,          0.0f },
    { 0.0f,  -0.32783699f,          0.0f },
    { 0.0f, -0.330172986f,          0.0f },
    { 0.0f, -0.319656014f,          0.0f },
    { 0.0f,  -0.29629299f,          0.0f },
    { 0.0f, -0.260078996f,          0.0f },
    { 0.0f, -0.211016998f,          0.0f },
    { 0.0f, -0.149105996f,          0.0f },
    { 0.0f, -0.074346997f,          0.0f },
    { 0.0f,     0.005778f, -0.015845001f },
    { 0.0f,  0.078883998f,     -0.04712f },
    { 0.0f,  0.145785004f,    -0.078342f },
    { 0.0f,  0.205887005f, -0.110159002f },
    { 0.0f,  0.258619994f, -0.143058002f },
    { 0.0f,  0.303436011f, -0.177352995f },
    { 0.0f,  0.339814991f, -0.213191003f },
    { 0.0f,  0.367247999f, -0.250535011f },
    { 0.0f,  0.385280997f, -0.289187998f },
    { 0.0f,  0.393503994f, -0.328774989f },
    { 0.0f,  0.391586989f, -0.368777007f },
    { 0.0f,  0.379301012f,  -0.40853101f },
    { 0.0f,  0.356534988f, -0.447259992f },
    { 0.0f,      0.32332f, -0.484091014f },
    { 0.0f,   0.27985099f, -0.518110991f },
    { 0.0f,  0.226494998f,  -0.54836601f },
    { 0.0f,  0.163798004f, -0.573920012f },
    { 0.0f,  0.092472002f, -0.593909025f },
    { 0.0f,     0.013408f, -0.607558012f },
    { 0.0f,    -0.072349f,  -0.61423099f },
    { 0.0f, -0.163657993f, -0.613456011f },
    { 0.0f, -0.259267986f, -0.604954004f },
    { 0.0f, -0.357311994f, -0.588689029f },
    { 0.0f, -0.446521997f, -0.564808011f },
    { 0.0f, -0.527827024f, -0.533720016f },
    { 0.0f,    -0.602651f, -0.496035993f },
    { 0.0f, -0.669950008f, -0.452576011f },
    { 0.0f, -0.728837013f, -0.404316008f },
    { 0.0f, -0.778612971f, -0.352382988f },
    { 0.0f, -0.818789005f, -0.297989011f },
    { 0.0f, -0.849110007f, -0.242401004f },
    { 0.0f, -0.869520009f, -0.186892003f },
    { 0.0f, -0.880186021f, -0.132695004f },
    { 0.0f, -0.881483018f,    -0.080978f },
    { 0.0f, -0.873930991f,    -0.032785f },
    { 0.0f,  -0.85819602f,     0.010963f },
    { 0.0f, -0.835048974f,     0.049513f },
    { 0.0f, -0.805310011f,     0.082278f },
    { 0.0f, -0.769832015f,     0.108834f },
    { 0.0f, -0.729451001f,     0.128943f },
    { 0.0f, -0.684931993f,     0.142512f },
    { 0.0f, -0.636990011f,     0.149603f },
    { 0.0f, -0.586210012f,     0.150407f },
    { 0.0f, -0.533039987f,     0.145226f },
    { 0.0f, -0.477804005f,     0.134455f },
    { 0.0f, -0.420648992f,     0.118571f },
    { 0.0f, -0.361571997f,     0.098123f },
    { 0.0f, -0.300401002f,     0.073717f },
    { 0.0f, -0.236799002f,     0.046018f },
    { 0.0f, -0.170291007f,      0.01577f },
    { 0.0f, -0.104172997f,     0.000002f },
    { 0.0f, -0.042123001f,     0.000003f },
    { 0.0f,     0.011841f,     0.000005f },
    { 0.0f,  0.057665002f,     0.000004f },
    { 0.0f,      0.09535f,     0.000005f },
    { 0.0f,  0.124898002f,     0.000006f },
    { 0.0f,  0.146304995f,     0.000006f },
    { 0.0f,  0.159574002f,     0.000006f },
    { 0.0f,  0.164702997f,     0.000007f },
    { 0.0f,  0.161695004f,     0.000006f },
    { 0.0f,  0.150545999f,     0.000004f },
    { 0.0f,  0.131259993f,     0.000005f },
    { 0.0f,  0.103832997f,     0.000002f },
    { 0.0f,     0.068269f,     0.000003f },
    { 0.0f,     0.024565f,     0.000001f }
};
NJS_POINT3 spl_052[21] = 
{
    {          0.0f,          0.0f,       0.0f },
    {  0.323074013f,   1.16421604f, -0.000003f },
    {  0.862697005f,   1.27816403f, -0.000003f },
    {   1.17025101f,   1.04479098f, -0.000004f },
    {     1.121099f,  0.545728981f, -0.000004f },
    {  0.680630982f,     0.022164f, -0.000004f },
    {     0.010563f, -0.280977994f, -0.000005f },
    { -0.589628994f, -0.296923995f, -0.000004f },
    { -0.868438005f, -0.179964006f, -0.000004f },
    { -0.754297972f, -0.167448997f, -0.000004f },
    { -0.488382012f, -0.711363971f, -0.000004f },
    { -0.407911003f,    -1.540488f, -0.000004f },
    { -0.329908013f,  -2.07722092f, -0.000004f },
    {    -0.255604f,  -2.31096101f, -0.000003f },
    { -0.188733995f,  -2.23500705f, -0.000004f },
    { -0.131156996f,  -1.84400296f, -0.000003f },
    { -0.083714001f,  -1.29996598f, -0.000002f },
    {    -0.046722f, -0.543478012f, -0.000002f },
    {    -0.020282f,  0.497803003f, -0.000002f },
    {    -0.004415f,  0.938849986f, -0.000001f },
    {     0.000878f,  0.506936014f,       0.0f }
};

static char joint_tree[5][6] = 
{
    {  0, -1,  0,  0,  0,  0 },
    {  0,  1,  4,  5,  6, -1 },
    {  0,  1, 13, 14, 15, -1 },
    {  0,  1, 25, 26, 27, -1 },
    {  0,  1, 28, 29, 30, -1 }
};
static unsigned char flip_tree[37] = 
{
     0,  1, 23, 24, 25, 26, 27, 22,
     8, 10,  9, 12, 11, 28, 29, 30,
    31, 32, 33, 34, 35, 36,  7,  2,
     3,  4,  5,  6, 13, 14, 15, 16,
    17, 18, 19, 20, 21
};
static char SdwTab[6] = 
{
    1, 27, 36, 6, 21, -1
};
static ETTY_WORK ene23_child = 
{
    0x1, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static char BrokenParts[2][2] = { { 28, 31 }, { 13, 16 } };
static BP_WORK BloodParam = 
{
    { 0.0f, 0.1f, 0.0f }, 0, 0.0f, 0.2f, { 0.5f, 0.1f, 0.6f, 0.3f, 0.5f }, { 0, 3, 6, 9, 12 }
};
static BLOOD_TBL BloodTbl[37] = 
{
    { 1, {  0.0f,  0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 0, {  0.0f,  3.0f, -5.0f }, 3.0f, 0.0f, 4.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  5.0f,  8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },   
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f }
};
static CPCL CapColTabA[25] = 
{
    {    1,    1,   32 },
    {    0,    0,  -40 },
    {    1,    1,   30 },
    {    0,    0,  -75 },
    {    1,    1,   25 },
    {    0,    0, -100 },
    {    8,    8,   75 },
    {    0,   30,   65 },
    {    4,    5,    6 },
    {    5,    6,    6 },
    {   25,   26,    6 },
    {   26,   27,    6 },
    {   13,   14,    6 },
    {   14,   15,    6 },
    {   28,   29,    6 },
    {   29,   30,    6 },
    {   16,   17,    6 },
    {   17,   18,    6 },
    {   31,   32,    6 },
    {   32,   33,    6 },
    {   19,   20,    6 },
    {   20,   21,    6 },
    {   34,   35,    6 },
    {   35,   36,    6 },
    {    0,    0,    0 }
};
static CPCL CapColTabB[23] = 
{
    {    1,    1,   32 },
    {    0,    0,  -40 },
    {    1,    1,   30 },
    {    0,    0,  -75 },
    {    1,    1,   25 },
    {    0,    0, -100 },
    {    4,    5,    6 },
    {    5,    6,    6 },
    {   25,   26,    6 },
    {   26,   27,    6 },
    {   13,   14,    6 },
    {   14,   15,    6 },
    {   28,   29,    6 },
    {   29,   30,    6 },
    {   16,   17,    6 },
    {   17,   18,    6 },
    {   31,   32,    6 },
    {   32,   33,    6 },
    {   19,   20,    6 },
    {   20,   21,    6 },
    {   34,   35,    6 },
    {   35,   36,    6 },
    {    0,    0,    0 }
};
static DMG_REACT DmgReact[21] = 
{
    { {  0,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  2,  1,  0 }, { 1, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  2,  1,  0 }, { 1, 1, 1 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 2 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 0 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 5 },
    { {  2,  2,  2 }, { 0, 0, 0 }, 1 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 5 }
};
static COMBWEP_WORK CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  4, {  1,  0,  0 }, 30, 20 },
    { 10, {  4,  3,  1 }, 20, 10 },
    { 10, {  4,  3,  1 }, 20, 10 },
    { 10, {  4,  3,  1 }, 10,  0 },
    {  0, {  0,  0,  0 }, 25,  0 },
    {  0, {  0,  0,  0 }, 25,  0 },
    { 25, {  5,  3,  1 },  5,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 }, 10,  0 },
    {  0, {  0,  0,  0 }, 30,  0 },
    { 25, {  5,  4,  2 }, 10,  0 },
    {  0, {  0,  0,  0 }, 60,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    { 15, {  1,  1,  1 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 }
};
static COMBJOINT_WORK CombJointTbl[37] = { 0 };

void (*bhEne23_Mode0[6])(BH_PWORK*) = 
{
	bhEne23_Init,
	bhEne23_Move,
	bhEne23_Nage,
	bhEne23_Damage,
	bhEne23_Die,
	bhEne_Event
};
void (*bhEne23_BrainType[2])(BH_PWORK*) = 
{
	bhEne23_BR00,
	bhEne23_BR01
};
void (*bhEne23_MoveMode2[13])(BH_PWORK*) = 
{
	bhEne23_MV00,
	bhEne23_MV01,
	bhEne23_MV02,
	bhEne23_MV03,
	bhEne23_MV04,
	bhEne23_MV05,
	bhEne23_MV06,
	bhEne23_MV07,
	bhEne23_MV08,
	bhEne23_MV09,
	bhEne23_MV10,
	bhEne23_MV11,
	bhEne23_MV12
};
void (*bhEne23_NageMode2[1])(BH_PWORK*) = 
{
	bhEne23_NG00
};
void (*bhEne23_DamageMode2[8])(BH_PWORK*) = 
{
	bhEne23_DG00,
	bhEne23_DG01,
	bhEne23_DG02,
	bhEne23_DG03,
	bhEne23_DG04,
	bhEne23_DG05,
	bhEne23_DG06,
	bhEne23_DG07
};
void (*bhEne23_DeadMode2[4])(BH_PWORK*) = 
{
	bhEne23_DD00,
	bhEne23_DD01,
	bhEne23_DD02,
	bhEne23_DD03
};
/* unused below */
/*ETTY_WORK ene24;
NJS_POINT3 spl_016[20];
NJS_POINT3 spl_023[25];*/

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne23(BH_PWORK* epw)
{
    NJS_POINT3 pos;   
    unsigned int flg;

    epw->flg &= ~0x100;

    bhEne23_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhEne23_CallSE(epw);
    
    if ((epw->flg & 0x800000)) 
    {
        bhEne03_GetPartsPos(epw, joint_tree[0], &pos);
        
        epw->aox = pos.x - epw->px;
        epw->aoy = pos.y - epw->py;
        epw->aoz = pos.z - epw->pz;
        
        if (!(epw->flg & 0x1000000)) 
        {
            epw->aoy = 0;
        }
    }
    else 
    {
        epw->aox = 0;
        epw->aoy = 0;
        epw->aoz = 0;
    }
    
    if (!(epw->flg & 0x400000)) 
    {
        bhCheckPlayer(epw);
    }

    if (!(epw->flg & 0x4000000)) 
    {
        bhEne23_CollisionLine(epw);
    }
 
    if ((epw->flg & 0x10)) 
    {
        bhEne23_CollisionWalls(epw);
    }
    
    njUnitMatrix(epw->mtx);
    
    njTranslate(epw->mtx, epw->px, epw->py, epw->pz);
    
    njMultiMatrix(epw->mtx, (NJS_MATRIX*)epw->exp0);
    
    if (epw->mnwP != epw->mnwPb) 
    {
        flg = epw->flg;
        
        epw->flg &= ~0x1000;
        
        bhCalcModel(epw);
        
        epw->flg = flg;
        
        epw->mdflg &= ~0x4;
    } 
    else 
    {
        epw->mdflg |=  0x4;
    }
    
    if ((epw->type & 0x1)) 
    {
        bhEne_SetWeponAtr(epw, 22, 1,  8.0f);
    }
    else
    {
        bhEne_SetWeponAtr(epw, 22, 12, 8.0f);
    }

    bhEne23_Shape(epw);
    
    bhEne23_PlayerControl(epw);
}

// 99.44% matching
void bhEne23_Init(BH_PWORK* epw)
{
    BH_PWORK** epw2, *ep;    
    O_WORK* owk;         
    int i;              
    NJS_POINT3 p;
    int sdw;

    epw->flg |=  0x1078;
    epw->flg &= ~0x6;

    epw->mdflg |= 0x4;

    epw->ar = 14.0f;
    epw->ah = 20.0f;
    
    epw->car = 15.0f;
    epw->cah = 8.0f;

    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;

    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;

    epw->frm_no = 0;

    epw->mtn_tp = (unsigned char*)flip_tree;

    bhCalcModel(epw);

    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;     
    epw->mode3 = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(304, 8);  

        epw2 = (BH_PWORK**)&EXP0_C(248);      

        for (i = 0; i < 2; i++)               
        {
            *epw2 = bhSetEnemy(&ene23_child, rom->ene_n);

            (*epw2)->type = 1;                 

            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = i;                 

            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;

            (*epw2)->mdflg |= 0x1;

            ((unsigned char*)epw->exp0)[i + 256] = BrokenParts[i][(int)(2.0f * (-rand() / -2147483648.0f))];

            owk = &epw->mlwP->owP[((unsigned char*)epw->exp0)[i + 256]];

            (*epw2)->mtx = &owk->mtx;

            (*epw2++)->exp1 = (unsigned char*)owk;
        }

        bhEne_SetCallFunc(bhEne03s, 31);
    }

    EXP0_F(108) = 14.0f;
    EXP0_I(272) = (int)(30.0f * (-rand() / -2147483648.0f)) + 30;
    EXP0_F(280) = 10.4f;

    if ((epw->type & 0x1))
    {
        epw->hp = ((sys->gm_mode != 2) ? 250 : 160) - ((sys->gm_mode != 2) ? 100 : 50);
    }
    else
    {
        epw->hp     = (sys->gm_mode != 2) ? 250 : 160;
        EXP0_I(276) = (sys->gm_mode != 2) ? 100 : 50;
    }

    EXP0_I(268) = 0;

    ep = ene;

    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 24))
        {
            ((BH_PWORK**)epw->exp0)[32 + EXP0_I(268)] = ep;
            
            EXP0_I(268)++;

            ep->lkwkp = (unsigned char*)epw;
            ep->lkono = 0;

            ep->lox = 0;
            ep->loy = 0;
            ep->loz = 0;

            ep->mlwP = &epw->mdl[2];
        }
    }

    for (i = 0; i < 8; i++)
    {
        ((char*)epw->exp0)[258 + i] = 0;  
    }

    njUnitMatrix((NJS_MATRIX*)epw->exp0);
    
    njRotateY((NJS_MATRIX*)epw->exp0, epw->ay);

    epw->flg &= ~0x4000000; 

    if ((epw->type & 0x2))
    {
        p.x = epw->px;
        p.y = epw->py + 999.0f;
        p.z = epw->pz;

        if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &p) != NULL)
        {
            EXP0_C(105) = 1;

            bhEne03_MakeMatrix(epw);

            epw->py = p.y;

            epw->flg |= 0x4000000;
        }

        epw->type &= ~0x2;
    }

    if (!(epw->flg & 0x4000000))
    {
        EXP0_C(105) = 0;
        
        epw->flg |= 0x4000000;
    }

    epw->pxb = epw->px;
    epw->pyb = epw->py;
    epw->pzb = epw->pz;

    *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);

    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 10;
    epw->clp_jno[2] = 27;
    epw->clp_jno[3] = 36;
    epw->clp_jno[4] = 6;
    epw->clp_jno[5] = 21;
    epw->clp_jno[6] = 24;
    epw->clp_jno[7] = 3;

    epw->mdflg &= ~0x20;

    if (!(epw->flg & 0x800))
    {
        sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 16.0f, 18.0f, 18.0f);

        eff[sdw].id = 258;

        epw->flg |= 0x800;
    }

    epw->stflg &= ~0x8;

    if ((epw->type & 0x4))
    {
        epw->type &= ~0x4;

        epw->flg &= ~0x60;    
        epw->flg |=  0x8000000; 

        epw->stflg |= 0x8;

        epw->ar = 13.0f;       
    }
    else
    {
        epw->flg &= ~0x8000000; 
    }

    if ((epw->type & 0x1))
    {
        epw->cpcl = CapColTabB;
    }
    else
    {
        epw->cpcl = CapColTabA;
    }

    bhEne03_HideParts(epw, 1, 0);

    if ((epw->type & 0x1))
    {
        bhEne03_HideParts(epw, 8, 1);
    }
    
    bhEne03_SetModelFlg(epw, -4, 0);

    sys->rm_flg &= ~0x1;

    if (!(epw->type & 0x1))
    {
        epw->mlwP = epw->mdl;

        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;

        epw->mdflg |= 0x2;

        epw->shp_ct = 0;
    }
}

// 100% matching!
void bhEne23_Brain(BH_PWORK* epw)
{
	bhEne23_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne23_BR00(BH_PWORK* epw)
{
	EXP0_F(64) = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    bhEne23_SearchPlayer(epw, 8192);

    if ((epw->flg & 0x8000000))
    {
        return;
    }

    if (EXP0_I(272) != 0)
    {
        EXP0_I(272)--;
    }

    if (EXP0_C(105) == 0)
    {
        if ((epw->flr_no != plp->flr_no) && (!(plp->stflg & 0x20)))
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            return;
        }

        if (((plp->stflg & 0x80000000)) || ((epw->flg & 0x4)))
        {
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 30.0f) && (bhEne23_SearchPlayer(epw, 5461) != 0) && (fabsf(epw->py - plp->py) < 5.0f))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
            return;
        }

        if ((EXP0_F(64) > 35.0f) && (bhEne23_SearchPlayer(epw, 5461) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
        }
    }
    else if (EXP0_C(105) == 1)
    {
        if ((plp->flr_no == 0) && (!(plp->stflg & 0x20)))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 28.0f) && (fabsf(plp->py - epw->py) < 45.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 40;
            return;
        }

        if ((EXP0_F(64) < 35.0f) && (bhEne23_SearchPlayer(epw, 10922) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 20;
        }
    }
}

// 100% matching!
void bhEne23_BR01(BH_PWORK* epw)
{
    EXP0_F(64) = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    bhEne23_SearchPlayer(epw, 8192);

    if ((!(epw->flg & 0x8000000)) && (EXP0_I(272) != 0))
    {
        EXP0_I(272)--;
    }

    if (EXP0_C(105) == 0)
    {
        if ((epw->flr_no != plp->flr_no) && (!(plp->stflg & 0x20)))
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            return;
        }

        if (((plp->stflg & 0x80000000)) || ((epw->flg & 0x4)))
        {
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 30.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0) && (fabsf(epw->py - plp->py) < 5.0f))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
        }
    }
    else if (EXP0_C(105) == 1)
    {
        if ((plp->flr_no == 0) && (!(plp->stflg & 0x20)))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 28.0f) && (fabsf(plp->py - epw->py) < 45.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 40;
        }
    }
}

// 100% matching!
void bhEne23_Move(BH_PWORK* epw)
{
	if (epw->mode1 == 1)
    {
        bhEne23_Brain(epw);
    }

    if (epw->mode0 == 1)
    {
        bhEne23_MoveMode2[epw->mode2](epw);
    }

	if (((epw->flg & 0x4)) && (!(epw->flg & 0x2)))
    {
        bhEne23_DamageInit(epw);
    }
}

// 100% matching!
void bhEne23_MV00(BH_PWORK* epw)
{
    int mno;               
	int mtn[2] = { 0, 53 }; 
	float dist;            

    switch (epw->mode3)
    {
    case 0:
    {
        mno = mtn[epw->type];

        if (epw->mtn_no != mno)
        {
            epw->mtn_no = mno;
            epw->frm_no = 0;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }

        epw->mtn_add = 65536;
        
        epw->flg |= 0x10000000;

        epw->ct0 = (int)(30.0f * (-rand() / -2147483648.0f)) + 20;

        epw->mode3++;
    }
    case 1:
        EXP0_I(280) = 0;

        if (epw->ct0 != 0)
        {
            epw->ct0--;
        }
        else
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));

            if (EXP0_C(105) == 0)
            {
                dist -= 30.0f;
            }
            
            if (EXP0_C(105) == 1)
            {
                dist -= 28.0f;
            }

            if ((dist > 0) || (bhEne23_SearchPlayer(epw, 1820) == 0))
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV01(BH_PWORK* epw) 
{
    NJS_POINT3 pos;                
	int mno;                     
	int mtn[2] = { 2, 22 };       
	float dist;                   
	float spd[2] = { 0.7f, 1.0f }; 
	NJS_POINT3 dp, sp;               

    switch (epw->mode3) 
    {
    case 0:
        mno = mtn[epw->type];
        
        if (epw->mtn_no != mno) 
        {
            epw->frm_no = 0;
            epw->mtn_no = mno;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            if ((epw->mtn_md & 0x2)) 
            {
                epw->frm_no = 589824;
                
                epw->mtn_md &= ~0x2;
            }
        }
        
        epw->mtn_add = 65536;
        
        epw->flg |= 0x10000000;
        
        epw->ct0 = 47.0f * (-rand() / -2147483648.0f);
        epw->ct1 =  ((-rand() / -2147483648.0f) < 0.5f) ? -1 : 1;
        
        epw->spd = spd[epw->type];
        
        if (EXP0_C(105) == 0) 
        {
            EXP0_F(108) = 14.0f;
        } 
        else 
        {
            EXP0_F(108) = 20.0f;
        }
        
        if ((epw->flg & 0x8000000)) 
        {
            epw->mtn_no = 56;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            epw->spd = 0.35f;
        }
        
        epw->ct0 = (int)(30.0f * (-rand() / -2147483648.0f)) + 20;
        
        epw->mode3++;
    case 1:
        bhEne03_GoAHead(epw);
        
        EXP0_I(280) = 0;
        
        if ((epw->flg & 0x8000000)) 
        {
            sp.x = epw->px;
            sp.y = 0;
            sp.z = epw->pz;
            
            dp.x = plp->px;
            dp.y = 0;
            dp.z = plp->pz;
            
            if (bhCheckRoute(&sp, &dp, &pos) != 0xFF) 
            {
                epw->xn += (pos.x - epw->xn) / 32.0f;
                epw->zn += (pos.z - epw->zn) / 32.0f;
            } 
            else 
            {
                epw->xn = plp->px;
                epw->zn = plp->pz;
            }
            
            epw->way = bhEne03_DirTarget(epw, (NJS_POINT3*)&epw->xn, 227);
        } 
        else 
        {
            if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) != 0xFF) 
            {
                epw->xn += (pos.x - epw->xn) / 16.0f;
                epw->zn += (pos.z - epw->zn) / 16.0f;
            } 
            else
            {
                epw->xn = plp->px;
                epw->zn = plp->pz; 
            }

            dist = njSqrt(((epw->xn - epw->px) * (epw->xn - epw->px)) + ((epw->zn - epw->pz) * (epw->zn - epw->pz)));
            
            if (dist > 30.0f) 
            {
                epw->way = bhEne03_DirTarget(epw, (NJS_POINT3*)&epw->xn, 455);
            }
            else 
            {
                epw->way = bhEne03_DirTarget(epw, (NJS_POINT3*)&epw->xn, 728);
            }
        }
        
        njRotateY((NJS_MATRIX*)epw->exp0, epw->way);
        
        if (epw->ct0 != 0) 
        {
            epw->ct0--; 
            return;
        }
        
        epw->mode1 = 1;
        
        dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
        
        if (EXP0_C(105) == 0) 
        {
            dist -= 32.0f;
        } 
        
        if (EXP0_C(105) == 1) 
        {
            dist -= 30.0f;
        }
        
        if ((dist < 0) && (bhEne23_SearchPlayer(epw, 3640) != 0)) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne23_MV02(BH_PWORK* epw)
{
	int mno;
	int mtn[2] = { 2, 22 };
	float spd[2] = { 0.7f, 1.0f };
	ATR_WORK* fp;
	int i;
	int flr_n;
	float min;
	float dist;
	float dx, dz;
	int fno;
    
    switch (epw->mode3)
    {
    case 0:
        mno = mtn[epw->type];

        if (epw->mtn_no != mno)
        {
            epw->frm_no = 0;
            epw->mtn_no = mno;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;

            if ((epw->mtn_md & 0x2))
            {
                epw->frm_no = 589824;
                
                epw->mtn_md &= ~0x2;
            }
        }

        epw->mtn_add = 65536;
        
        epw->flg |= 0x10000000;

        epw->ct0 = (int)(47.0f * (-rand() / -2147483648.0f)) + 30;
        epw->ct1 = ((-rand() / -2147483648.0f) < 0.5f) ? -1 : 1;

        epw->spd = spd[epw->type];

        min = 9999.0f;
        
        flr_n = rom->flr_n + sys->mflr_n;

        for (i = 0; i < flr_n; i++)
        {
            if (i < rom->flr_n)
            {
                fp = &rom->flrp[i];
            }
            else
            {
                fp = &sys->mflrp[i - rom->flr_n];
            }

            if (((fp->flg & 0x1)) && (fp->type == 2) && ((fp->prm0 == 23) && (fp->prm1 < 4)))
            {
                dx = (fp->px + (fp->w / 2.0f)) - epw->px;
                dz = (fp->pz + (fp->d / 2.0f)) - epw->pz;
                
                dist = (dx * dx) + (dz * dz);

                if (dist < min)
                {
                    min = dist;

                    EXP0_F(72) = fp->px + (fp->w / 2.0f);
                    EXP0_F(76) = epw->py;
                    EXP0_F(80) = fp->pz + (fp->d / 2.0f);
                }
            }
        }

        epw->mode3++;
    case 1:
        bhEne03_GoAHead(epw);

        fno = epw->frm_no / 65536;

        if ((fno >= 0) && (fno <= 10))
        {
            EXP0_I(264) =  bhEne23_CheckClimbWall(epw,  1);
        }
        else
        {
            EXP0_I(264) = -bhEne23_CheckClimbWall(epw, -1);
        }

        if (EXP0_I(264) != 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 6;
            epw->mode3 = 0;
            break;
        }

        if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&EXP0_F(72), (NJS_POINT3*)&epw->xn) == 0xFF)
        {
            epw->xn = EXP0_F(72);
            epw->zn = EXP0_F(80);
        }

        epw->way = bhEne03_DirTarget(epw, (NJS_POINT3*)&epw->xn, 455);

        njRotateY((NJS_MATRIX*)epw->exp0, epw->way);

        if (epw->ct0 == 0)
        {
            epw->mode1 = 1;

            if (plp->flr_no == epw->flr_no)
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
        else
        {
            epw->ct0--;
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV03(BH_PWORK* epw)
{
	int mno;                      
	int mtn[2] = { 2, 22 };       
	float spd[2] = { 0.7f, 1.0f }; 
	ATR_WORK* fp;                 
	int i;                       
	int flr_n;                    
	float min;                  
	float dist;                   
	float dx, dz;                 
	NJS_POINT3 p1, p2;               
    
    switch (epw->mode3)
    {
    case 0:
        mno = mtn[epw->type];

        if (epw->mtn_no != mno)
        {
            epw->frm_no = 0;
            epw->mtn_no = mno;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;

            if ((epw->mtn_md & 0x2))
            {
                epw->frm_no = 589824;
                
                epw->mtn_md &= ~0x2;
            }
        }

        epw->mtn_add = 65536;
        
        epw->flg |= 0x10000000;

        epw->ct0 = (int)(47.0f * (-rand() / -2147483648.0f)) + 30;
        epw->ct1 = ((-rand() / -2147483648.0f) < 0.5f) ? -1 : 1;

        epw->spd = spd[epw->type];

        min = 9999.0f; 
        
        flr_n = rom->flr_n + sys->mflr_n; 

        for (i = 0; i < flr_n; i++)
        {
            if (i < rom->flr_n)
            {
                fp = &rom->flrp[i];
            }
            else
            {
                fp = &sys->mflrp[i - rom->flr_n];
            }

            if (((fp->flg & 0x1)) && (fp->type == 2) && ((fp->prm0 == 23) && (fp->prm1 == 4)))
            {
                dx = (fp->px + (fp->w / 2.0f)) - epw->px; 
                dz = (fp->pz + (fp->d / 2.0f)) - epw->pz; 
                
                dist = (dx * dx) + (dz * dz); 

                if (dist < min)
                {
                    min = dist;

                    EXP0_F(72) = fp->px + (fp->w / 2.0f);
                    EXP0_F(76) = fp->py + (fp->h / 2.0f);
                    EXP0_F(80) = fp->pz + (fp->d / 2.0f);
                }
            }
        }

        epw->mode3++;
    case 1:
        bhEne03_GoAHead(epw);

        p1.x = epw->px;
        p1.y = plp->py;
        p1.z = epw->pz;

        p2.x = EXP0_F(72);
        p2.y = EXP0_F(76);
        p2.z = EXP0_F(80);

        if (bhCheckRoute(&p1, &p2, (NJS_POINT3*)&epw->xn) == 0xFF)
        {
            epw->xn = EXP0_F(72);
            epw->zn = EXP0_F(80);
        }

        epw->way = bhEne03_DirTarget(epw, (NJS_POINT3*)&epw->xn, 455);

        njRotateY((NJS_MATRIX*)epw->exp0, epw->way);

        if (bhEne23_CheckDiving(epw) != 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 11;
            epw->mode3 = 0;
        }

        if (epw->ct0 == 0) 
        {
            epw->mode1 = 1;

            if (plp->flr_no != 0)
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
        else
        {
            epw->ct0--;
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV04()
{

}

// 100% matching!
void bhEne23_MV05(BH_PWORK* epw)
{
    int mtn[2] = { 3, 24 }; 
    
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x400000;

        if (EXP0_I(264) > 0)
        { 
            epw->mtn_no = (EXP0_I(264) + mtn[epw->type]) - 1;
        }
        else
        {
            epw->mtn_no = (mtn[epw->type] - EXP0_I(264)) - 1;

            epw->mtn_md |= 0x2;
        }

        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg &= ~0x18;
        epw->flg |=  0x180000;
        epw->flg |=  0x10000000;

        epw->flg2 |= 0x1;

        epw->flg  |= 0x1800000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;

        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0)
        {
            bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

            njSetMatrix((NJS_MATRIX*)epw->exp0, &epw->mlwP->owP->mtx);

            EXP0_C(105) = 1;

            bhEne03_MakeMatrix(epw);

            epw->flg &= ~0x180000;

            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 1;

            if (epw->type == 0)
            {
                epw->mtn_no = 2;
                epw->frm_no = 0;
                
                epw->ct0 = 10;

                epw->spd = 0.7f;
            }
            else
            {
                epw->mtn_no = 22;
                epw->frm_no = 0;
                
                epw->ct0 = 10;

                epw->spd = 1.0f;
            }

            bhEne03_GoAHead(epw);

            epw->flg |=  0x18;
            epw->flg &= ~0x1800000;
            
            epw->flg |=  0x4000000;
            epw->flg &= ~0x400000;

            *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
            
            EXP0_F(108) = 20.0f;
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV06(BH_PWORK* epw) 
{
    int mno;                
    int mtn[2] = { 2, 22 };

    switch (epw->mode3)
    {
    case 0:
    {
        mno = mtn[epw->type];

        if (epw->mtn_no != mno)
        {
            epw->frm_no = 0;
            epw->mtn_no = mno;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }

        epw->flg |= 0x10000000;
        
        epw->mtn_add = 65536;

        epw->ayp = (short)((((ATR_WORK*)EXP0_I(260))->prm1 & 0x3) * -16384);

        epw->ct0 = 8;

        epw->mode3++;
    }
    case 1:
        if (epw->ct0 > 0)
        {
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            njRotateY((NJS_MATRIX*)epw->exp0, (short)(epw->ayp - epw->ay) / epw->ct0);

            epw->px += (epw->xn - epw->px) / epw->ct0;
            epw->pz += (epw->zn - epw->pz) / epw->ct0;

            epw->ct0--;
        }
        else
        {
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV07()
{

}

// 100% matching!
void bhEne23_MV08()
{

}

// 100% matching!
void bhEne23_MV09(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {                         
    case 0:
        epw->mtn_no = 11;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->mtn_add = 65536;
        
        epw->flg |= 0x10000000;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        
        if ((epw->frm_no > 1835008) && (epw->frm_no < 3014656)) 
        {
            bhEne23_Acid(epw);
        }
        
        break;
    }
}

// 100% matching!
void bhEne23_MV10(BH_PWORK* epw) 
{
    NJS_POINT3 pos; 
    int mtn[2][2] = { { 10, 12 }, { 27, 28 } };
    
    switch (epw->mode3) 
    {
    case 0:
        if (EXP0_C(105) == 0)
        {
            epw->mtn_no = mtn[epw->type][0];
        } 
        else 
        {
            epw->mtn_no = mtn[epw->type][1];
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->mtn_add = 65536;
        
        epw->flg &= ~0x10000000;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            if (epw->ct1 != 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 0;
                epw->mode3 = 0;
            } 
            else 
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
        
        break;
    }

    EXP0_I(280) = 0;

    if ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x80000000)))
    {
        switch ((plp->stflg & 0x30)) 
        {
        case 0:
            if (((EXP0_C(105) == 0) && ((epw->frm_no >= 589824) && (epw->frm_no <= 720896))) || ((EXP0_C(105) == 1) && ((epw->frm_no >= 327680) && (epw->frm_no <= 589824)))) 
            {
                pos.x = -7.0f;
                pos.y = 0;
                pos.z = 0;
                
                njCalcPoint(&epw->mlwP->owP[6].mtx, &pos, &pos);
                epw->ct1 = bhEne_AttackHitCheck(plp, &pos, 5.0f);

                bhEne03_GetPartsPos(epw, joint_tree[1], &pos);
                epw->ct1 |= bhEne_AttackHitCheck(plp, &pos, 5.0f);

                pos.x = 7.0f;
                pos.y = 0;
                pos.z = 0;
                
                njCalcPoint(&epw->mlwP->owP[27].mtx, &pos, &pos);
                epw->ct1 |= bhEne_AttackHitCheck(plp, &pos, 5.0f);

                bhEne03_GetPartsPos(epw, joint_tree[3], &pos);
                epw->ct1 |= bhEne_AttackHitCheck(plp, &pos, 5.0f);

                if (epw->ct1 != 0)
                {
                    EXP0_I(272) += 20;
                    
                    bhEne_SetBloodEffect5(plp, 9, 2);

                    if (!(plp->flg & 0x80000000))
                    {
                        plp->hp -= 40;
                    }

                    plp->flg   |= 0x10004;
                    plp->stflg |= 0x10000;

                    if (plp->hp >= 0)
                    {
                        epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

                        if (EXP0_C(105) == 0) 
                        {
                            plp->mode0 = 2;
                            plp->mode2 = 1;
                            plp->mode3 = 0;

                            if (abs((short)(epw->ay - plp->ay)) > 16384) 
                            {
                                plp->mode1 = 0;
                            } 
                            else 
                            {
                                plp->mode1 = 1;
                            }
                        } 
                        else
                        {
                            plp->mode0 = 4;
                            plp->mode1 = 0;
                            plp->mode3 = 0;

                            if (abs((short)(epw->ay - plp->ay)) > 16384) 
                            {
                                plp->mode2 = 0;
                            } 
                            else 
                            {
                                plp->mode2 = 1;
                                return; 
                            }
                        }
                    }
                }
            }
            
            break;
        }
    }
}

// 100% matching!
void bhEne23_MV11(BH_PWORK* epw) 
{
    int mtn[2][2] = { { 37, 0 }, { 42, 53 } };
    NJS_POINT3 trans;                         

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn[epw->type][0];
        epw->frm_no = 0;
        
        epw->mtn_add = 65536;

        EXP0_F(108) = 14.0f;
        epw->ar     = 14.0f;

        epw->flg &= ~0x20;
        epw->flg &= ~0x4100000;
        
        epw->flg |=  0x10000000;

        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;

            bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

            epw->mtn_no = mtn[epw->type][1];
            epw->frm_no = 0;

            njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
            njSubVector((NJS_VECTOR*)&epw->px, &trans);

            EXP0_C(105) = 0;

            if (!(epw->type & 0x1))
            {
                njRotateY((NJS_MATRIX*)epw->exp0, 32768);
            }

            bhEne03_MakeMatrix(epw);

            EXP0_I(280) = 0;

            epw->py += 1.0f;

            *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
            
            epw->py = ((ATR_WORK*)EXP0_I(96))->py;

            epw->flg  |=  0x20;
            epw->flg  |=  0x4000000;

            epw->flg2 &= ~0x1;
        }

        break;
    }
}

// 100% matching!
void bhEne23_MV12(BH_PWORK* epw)
{
	int mtn[2] = { 0, 53 };
    NJS_POINT3 trans;

    epw->flg |=  0x1078;
    
    epw->flg &= ~0x6;
    epw->flg &= ~0x8000000;

    epw->stflg &= ~0x8;
    epw->mdflg |=  0x4;

    epw->flg |= 0x4000000;

    njUnitMatrix((NJS_MATRIX*)epw->exp0);

    bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

    epw->type &= 0x1;

    epw->mtn_no = mtn[epw->type];
    epw->frm_no = 0;
    
    epw->mtn_add = 65536;

    epw->mtn_md &= ~0x20;

    njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
    njSubVector((NJS_VECTOR*)&epw->px, &trans);

    epw->pxb = epw->px;
    epw->pyb = epw->py;
    epw->pzb = epw->pz;

    if (epw->mlwP->owP->mtx[5] > 0)
    {
        EXP0_C(105) = 0;
    }
    else
    {
        EXP0_C(105) = 1;
    }

    bhEne03_MakeMatrix(epw);

    *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);

    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;
    epw->mode3 = 0;

    if ((epw->type & 0x4))
    {
        epw->type &= ~0x4;

        epw->flg |=  0x8000000;
        epw->flg &= ~0x60;

        epw->stflg |= 0x8;

        epw->ar = 13.0f;
    }
    else
    {
        epw->flg &= ~0x8000000;
    }

    if ((epw->type & 0x1))
    {
        epw->cpcl = CapColTabB;
    }
    else
    {
        epw->cpcl = CapColTabA;
    }

    bhEne03_HideParts(epw, 1, 0);

    if ((epw->type & 0x1))
    {
        bhEne03_HideParts(epw, 8, 1);
    }
}

// 100% matching!
void bhEne23_Nage(BH_PWORK* epw)
{
	bhEne23_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_NG00()
{

}

// 100% matching!
void bhEne23_Damage(BH_PWORK* epw)
{
    if ((epw->flg & 0x4))
    {
        epw->flg &= ~0x4;
        
        epw->comb_flg &= ~0xC;

        if (bhEne03_DGDirCheck(epw) != 0) 
        {
            epw->comb_flg |= 0x8;
        } 
        else 
        {
            epw->comb_flg |= 0x4;
        }

        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4)) || (epw->comb_pnt == 1)) 
        {
            if (epw->total_dam != 0) 
            {
                if (epw->type == 0) 
                {
                    if ((epw->comb_flg & 0x8)) 
                    {
                        EXP0_I(276) -= epw->total_dam;
        
                        epw->hp -= epw->total_dam;
                    } 
                    else 
                    {
                        epw->hp -= epw->total_dam;
                    }
                } 
                else
                {
                    epw->hp -= epw->total_dam;
                }
            }
        
            if ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4))) 
            {
                bhEne23_HitMark(epw);
            } 
        }
    }
    
    bhEne23_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_DG00()
{

}

// 100% matching!
void bhEne23_DG01(BH_PWORK* epw)
{
	int mtn[2][2] = { { 14, 18 }, { 29, 33 } };
    
    switch (epw->mode3)
    {
    case 0:
        if (EXP0_C(105) == 0)
        {
            epw->mtn_no = mtn[epw->type][0] + bhEne03_DGDirCheck(epw);
        }
        else
        {
            epw->mtn_no = mtn[epw->type][1] + bhEne03_DGDirCheck(epw);
        }

        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg |= 0x10000000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;

            epw->flg &= ~0x4;

            EXP0_I(272) -= 20;

            if (EXP0_I(272) < 0)
            {
                EXP0_I(272) = 0;
            }
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DG02()
{

}

// 100% matching!
void bhEne23_DG03(BH_PWORK* epw)
{
	int mtn[2] = { 16, 31 };
    
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn[epw->type] + bhEne03_DGDirCheck(epw);
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg |= 0x10000000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;

            epw->flg &= ~0x4;

            EXP0_I(272) -= 20;

            if (EXP0_I(272) < 0)
            {
                EXP0_I(272) = 0;
            }
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DG04(BH_PWORK* epw)
{
    int i;          
    NJS_POINT3 pos;
	O_WORK* owk;   

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 17;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg |= 0x10000000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 0;

        epw->mode3++;

        bhEne03_HideParts(epw, 8, 1);
        
        bhEne_EraseArrow(epw, 8);

        epw->cpcl = CapColTabB;
        
        epw->type = 1;

        owk = &epw->mlwP->owP[8];

        pos.x = 0;
        pos.y = 6.0f;
        pos.z = 8.0f;

        njCalcPoint(&owk->mtx, &pos, &pos);

        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);
        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 1);
        bhEne_SetBloodstain(epw, 0, 8, NULL);
        bhEne_SetBloodstain(epw, 0, 8, NULL);
        bhEne_SetBloodstain(epw, 0, 8, NULL);

        for (i = 0; i < 6; i++)
        {
            owk = &epw->mlwP->owP[8];
            
            pos.x =         (8.0f * (-rand() / -2147483648.0f))  - 4.0f;
            pos.y = (8.0f + (8.0f  * (-rand() / -2147483648.0f))) - 4.0f;
            pos.z = (8.0f + (12.0f * (-rand() / -2147483648.0f))) - 6.0f;

            njCalcPoint(&owk->mtx, &pos, (NJS_POINT3*)&epw->dpx);

            bhEne_SetMinceEffect2(epw, 258, 0.5f, 1);
            bhEne_SetMinceEffect2(epw, 259, 0.5f, 1);
        }

        bhEne23_InitChild(epw);

        sys->rm_flg |= 0x1;

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74516);
    case 1:
        if (epw->ct1 == 0)
        {
            owk = &epw->mlwP->owP[8];
            
            pos.x =          (8.0f * (-rand() / -2147483648.0f))  - 4.0f;
            pos.y = (8.0f + (8.0f  * (-rand() / -2147483648.0f))) - 4.0f;
            pos.z = (8.0f + (12.0f * (-rand() / -2147483648.0f))) - 6.0f;

            njCalcPoint(&owk->mtx, &pos, &pos);

            bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);

            pos.x =         (12.0f * (-rand() / -2147483648.0f))  - 6.0f;
            pos.y = (8.0f + (12.0f * (-rand() / -2147483648.0f))) - 8.0f;
            pos.z = (8.0f + (16.0f * (-rand() / -2147483648.0f))) - 8.0f;

            njCalcPoint(&owk->mtx, &pos, &pos);

            bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);

            epw->ct1 = 3;
        }
        else
        {
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;

            epw->flg &= ~0x4;

            EXP0_I(272) -= 20;

            if (EXP0_I(272) < 0)
            {
                EXP0_I(272) = 0;
            }
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DG05()
{

}

// 100% matching!
void bhEne23_DG06(BH_PWORK* epw) 
{
	int mtn[2][2] = { { 40, 51 }, { 45, 52 } }; 
	NJS_POINT3* trans[2] = { spl_051, spl_052 }; 
    
    switch (epw->mode3)
    {
    case 0:
    {
        NJS_MKEY_A_MOD* mkaP; 

        bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;

        if ((epw->mtn_md & 0x2))
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, -*mkaP->key++, -*mkaP->key++);
        }
        else
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }
        
        if ((epw->flg & 0x400000))
        {
            EXP0_F(84) = 3.0f * EXP0_F(16);
            EXP0_F(88) = 0;
            EXP0_F(92) = 3.0f * EXP0_F(24);
        }
        else
        {
            EXP0_F(84) = 0;
            EXP0_F(88) = 0;
            EXP0_F(92) = 0;
        }

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        epw->mtn_md |= 0x100;

        epw->mtn_no = mtn[epw->type][0];
        epw->frm_no = 0;
        
        epw->mtn_add = 0;

        epw->mtn_md &= ~0x2;          

        epw->hokan_count = 30;
        epw->hokan_rate  = 45875;

        {
        NJS_MKEY_A_MOD* mkaP; 

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;
        }

        {
        NJS_POINT3 trans; 

        njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);
        }

        epw->flg &= ~0x4000000;

        if ((epw->flg & 0x400000))
        {
            EXP0_I(96) = EXP0_I(100);
        }

        epw->flg |=  0x30;
        
        epw->flg &= ~0x400000;
        epw->flg &= ~0x180000;
        epw->flg &= ~0x1800000;

        EXP0_F(108) = 14.0f;
        epw->ar     = 1.0f;

        epw->flg |= 0x10000000;

        epw->ct0 = 8;

        epw->mode3++;
    }
    case 1:
    {
        NJS_VECTOR v, ov;  
        float out;    
    	int ang;
        
        if (epw->ct0 > 0)
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;

            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);

            if (out > 0)
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);

                ang = 10430.381f * asinf(out);

                if (EXP0_F(20) < 0)
                {
                    ang = 32768 - ang;
                }

                njRotate(NULL, &ov, ang / epw->ct0);
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            else
            {
                njUnitMatrix(NULL);

                njRotateX(NULL, 32768 / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }

            epw->ct0--;
        }

        if ((epw->flg & 0x4000000))
        {
            EXP0_C(105) = 0;

            bhEne03_MakeMatrix(epw);

            epw->mtn_add = 65536;
            
            epw->frm_no = 0;

            epw->mtn_md &= ~0x100;   

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->flg2 &= ~0x1;

            epw->mode3++;
        }
        else
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);

            EXP0_F(88) -= 0.6f;
        }

        break;
    }
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = mtn[epw->type][1];
            epw->frm_no = 0;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;

            if ((epw->type & 0x1))
            {
                NJS_MKEY_A_MOD* mkaP; 

                njRotateY((NJS_MATRIX*)epw->exp0, 32768);

                mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

                epw->mlwP->objP->ang[0] = *mkaP->key++;
                epw->mlwP->objP->ang[1] = *mkaP->key++;
                epw->mlwP->objP->ang[2] = *mkaP->key++;
            }
        }

        break;
    case 3:
        bhEne03_AddNullTrans(epw, trans[epw->type]);

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;

            epw->flg &= ~0x4;

            epw->ar = 14.0f;

            EXP0_I(272) -= 20;

            if (EXP0_I(272) < 0)
            {
                EXP0_I(272) = 0;
            }
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DG07(BH_PWORK* epw)
{
    int mtn[2] = { 54, 55 }; 

    switch (epw->mode3)
    {
    case 0:
    {
        NJS_MKEY_A_MOD* mkaP; 

        bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;

        if ((epw->mtn_md & 0x2))
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, -*mkaP->key++, -*mkaP->key++);
        }
        else
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }

        EXP0_F(84) = 3.0f * EXP0_F(16);
        EXP0_F(88) = 0;
        EXP0_F(92) = 3.0f * EXP0_F(24);

        epw->mtn_md |= 0x100;

        epw->mtn_no = mtn[epw->type];
        epw->frm_no = 0;
        
        epw->mtn_add = 0;

        epw->mtn_md &= ~0x2;          

        epw->hokan_count = 30;
        epw->hokan_rate  = 45875;

        {
        NJS_MKEY_A_MOD* mkaP; 

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;
        }

        {
        NJS_POINT3 trans; 

        njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);
        }

        epw->flg &= ~0x4000000;
        
        epw->flg |=  0x30;
        
        epw->flg &= ~0x400000;
        epw->flg &= ~0x180000;
        epw->flg &= ~0x1800000;

        EXP0_F(108) = 14.0f;
        epw->ar     = 14.0f;

        epw->flg |= 0x10000000;

        epw->ct0 = 8;

        epw->mode3++;
    }
    case 1:
    {
        NJS_VECTOR v, ov;  
        float out;    
    	int ang;
        
        if (epw->ct0 > 0)
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;

            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);

            if (out > 0)
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);

                ang = (int)(10430.381f * asinf(out)) / epw->ct0;

                njRotate(NULL, &ov, ang);
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            else
            {
                njUnitMatrix(NULL);

                njRotateX(NULL, 32768 / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }

            epw->ct0--;
        }

        if ((epw->flg & 0x4000000))
        {
            EXP0_C(105) = 0;

            bhEne03_MakeMatrix(epw);

            epw->mtn_add = 65536;
            
            epw->frm_no = 0;

            epw->mtn_md &= ~0x100;   

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->flg2 &= ~0x1;

            epw->mode3++;
        }
        else
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);

            EXP0_F(88) -= 0.6f;
        }

        break;
    }
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;

            epw->flg &= ~0x4;

            epw->ar = 14.0f;

            EXP0_I(272) -= 20;

            if (EXP0_I(272) < 0)
            {
                EXP0_I(272) = 0;
            }
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_Die(BH_PWORK* epw)
{
	bhEne23_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_DD00(BH_PWORK* epw)
{
    int mtn[2] = { 48, 50 }; 
    
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn[epw->type];
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg |= 0x10000000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;

            epw->mode3++;

            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DD01(BH_PWORK* epw) 
{
    int mtn[2][2] = { { 40, 47 }, { 45, 49 } }; 
    
    switch (epw->mode3)
    {
    case 0:
    {
        NJS_MKEY_A_MOD* mkaP;
        
        bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;

        if ((epw->mtn_md & 0x2))
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, -*mkaP->key++, -*mkaP->key++);
        }
        else
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }

        if ((epw->flg & 0x400000))
        {
            EXP0_F(84) = 3.0f * EXP0_F(16);
            EXP0_F(88) = 0;
            EXP0_F(92) = 3.0f * EXP0_F(24);
        }
        else
        {
            EXP0_F(84) = 0;
            EXP0_F(88) = 0;
            EXP0_F(92) = 0;
        }

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        epw->mtn_md |= 0x100;

        epw->mtn_no = mtn[epw->type][0];
        epw->frm_no = 0;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;

        epw->hokan_count = 30;
        epw->hokan_rate  = 45875;

        {
        NJS_MKEY_A_MOD* mkaP; 
        NJS_POINT3 trans;     

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);

        epw->flg &= ~0x4000000;

        if ((epw->flg & 0x400000))
        {
            EXP0_I(96) = EXP0_I(100);
        }

        epw->flg |=  0x30;
            
        epw->flg &= ~0x400000;
        epw->flg &= ~0x180000;
        epw->flg &= ~0x1800000;

        EXP0_F(108) = 14.0f;
        epw->ar     = 14.0f;

        epw->flg |= 0x10000000;

        epw->ct0 = 8;

        epw->mode3++;
        }
    }
    case 1:
    {
        NJS_VECTOR v, ov; 
        float out;     
        int ang;      

        if (epw->ct0 > 0)
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);

            if (out > 0)
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);

                ang = (int)(10430.381f * asinf(out)) / epw->ct0;

                njRotate(NULL, &ov, ang);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            else
            {
                njUnitMatrix(NULL);

                njRotateX(NULL, 32768 / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }

            epw->ct0--;
        }

        if ((epw->flg & 0x4000000))
        {
            EXP0_C(105) = 0;

            bhEne03_MakeMatrix(epw);

            epw->mtn_add = 65536;
            
            epw->frm_no = 65536;

            epw->mtn_md &= ~0x100;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;
        }
        else
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);

            EXP0_F(88) -= 0.6f;
        }

        break;
    }
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = mtn[epw->type][1];
            epw->frm_no = 0;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;
        }

        break;
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);

            epw->hokan_count = 0;
            
            epw->mtn_add = 0;

            epw->flg &= ~0x40;

            epw->mode3++;

            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_DD02()
{
	
}

// 100% matching!
void bhEne23_DD03(BH_PWORK* epw)
{
    int mtn[2][2] = { { 54, 48 }, { 55, 50 } }; 
    
    switch (epw->mode3)
    {
    case 0:
    {
        NJS_MKEY_A_MOD* mkaP;
        
        bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;

        if ((epw->mtn_md & 0x2))
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, -*mkaP->key++, -*mkaP->key++);
        }
        else
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }

        EXP0_F(84) = 3.0f * EXP0_F(16);
        EXP0_F(88) = 3.0f * EXP0_F(20);
        EXP0_F(92) = 3.0f * EXP0_F(24);

        epw->mtn_md |= 0x100;

        epw->mtn_no = mtn[epw->type][0];
        epw->frm_no = 0;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;

        epw->hokan_count = 30;
        epw->hokan_rate  = 45875;

        {
        NJS_MKEY_A_MOD* mkaP; 
        NJS_POINT3 trans;     

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);

        epw->flg &= ~0x4000000;

        epw->flg |=  0x30;
            
        epw->flg &= ~0x400000;
        epw->flg &= ~0x180000;
        epw->flg &= ~0x1800000;

        EXP0_F(108) = 14.0f;
        epw->ar     = 14.0f;

        epw->flg |= 0x10000000;

        epw->ct0 = 8;

        epw->mode3++;
        }
    }
    case 1:
    {
        NJS_VECTOR v, ov; 
        float out;     
        int ang;      

        if (epw->ct0 > 0)
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);

            if (out > 0)
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);

                ang = (int)(10430.381f * asinf(out)) / epw->ct0;

                njRotate(NULL, &ov, ang);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            else
            {
                njUnitMatrix(NULL);

                njRotateX(NULL, 32768 / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }

            epw->ct0--;
        }

        if ((epw->flg & 0x4000000))
        {
            EXP0_C(105) = 0;

            bhEne03_MakeMatrix(epw);

            epw->mtn_add = 65536;
            
            epw->frm_no = 65536;

            epw->mtn_md &= ~0x100;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;
        }
        else
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);

            EXP0_F(88) -= 0.6f;
        }

        break;
    }
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = mtn[epw->type][1];
            epw->frm_no = 0;

            epw->hokan_count = 0;

            epw->mtn_add = 65536;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

            epw->mode3++;
        }

        break;
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);

            epw->hokan_count = 0;
            
            epw->mtn_add = 0;

            epw->flg &= ~0x40;

            epw->mode3++;

            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }

        break;
    }

    EXP0_I(280) = 0;
}

// 100% matching!
void bhEne23_CollisionWalls(BH_PWORK* epw)
{
    NJS_POINT3 body, trans;      
    float ar, ah;            
    NJS_MKEY_A_MOD* mkaP;
    NJS_CNK_OBJECT* objP; 
    float px, py, pz; // not from DWARF
    float dx, dz;     // not from DWARF
    NJS_MATRIX* mtxP; // not from DWARF

    px = epw->px;
    py = epw->py;
    pz = epw->pz;

    body.x = 0;
    body.y = epw->ar;
    body.z = 0;

    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    if ((epw->flg & 0x100000)) 
    {
        mkaP  = (NJS_MKEY_A_MOD*)epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;
        
        njRotateXYZ(NULL, *mkaP->key++, *mkaP->key++, *mkaP->key++);
    }

    njCalcVector(NULL, &body, &body);

    if ((epw->flg & 0x10000000)) 
    {
        objP = epw->mlwP->objP;
        
        trans.x = objP->pos[0];
        trans.y = objP->pos[1];
        trans.z = objP->pos[2];
    
        if (!(epw->flg & 0x80000)) 
        {
            trans.y = 0;
        }
    
        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);
    
        epw->px += trans.x;
        epw->py += trans.y;
        epw->pz += trans.z;
    } 
    else 
    {
        trans.x = 0;
        trans.y = 0;
        trans.z = 0;
    }

    if (((epw->flg & 0x4000000)) && (EXP0_C(105) == 0)) 
    {
        mtxP = (NJS_MATRIX*)epw->exp0;
    
        dx = mtxP[0][8]  * -((float*)mtxP)[70];
        dz = mtxP[0][10] * -((float*)mtxP)[70];
        
        epw->px += dx;
        epw->py += 5.0f;
        epw->pz += dz;
    
        ar = epw->ar;
        ah = epw->ah;
        
        epw->ah = 20.0f;
        epw->ar = 12.0f;
    
        bhCheckWall(epw);
    
        epw->px -= dx;
        epw->py -= 5.0f;
        epw->pz -= dz;
    
        epw->ar = ar;
        epw->ah = ah;
    
        EXP0_F(280) += (10.4f - EXP0_F(280)) / 16.0f;
    }
    
    if (!(epw->flg & 0x4000000)) 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96));

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    } 
    else 
    {
        if ((EXP0_C(105) == 0) || ((epw->flg & 0x8000000))) 
        {
            epw->px += body.x;
            epw->py += body.y;
            epw->pz += body.z;
    
            bhEne03_Collision(epw);
    
            epw->px -= body.x;
            epw->py -= body.y;
            epw->pz -= body.z;
        } 
        else 
        {
            bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96));
        }
    }

    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;

    if ((epw->flg & 0x4000000)) 
    {
        epw->py = py;
    }

    if (!(epw->flg & 0x8000000)) 
    {
        epw->ar += (EXP0_F(108) - epw->ar) / 8.0f;
    }
}

// 100% matching!
void bhEne23_CollisionLine(BH_PWORK* epw)
{
	NJS_VECTOR n;
	ATR_WORK* hp;

    hp = bhCollisionCheckLine2((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px, 17408, -1);

    if ((hp != NULL) && ((hp->type == 7) && (!(epw->flg & 0x4000000))))
    {        
		bhGetHitCollisionNormal(&n);

		if (n.y > 0)
		{
			epw->flg |= 0x4000000;

			*(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
		}
    }
}

// 100% matching!
int bhEne23_CheckClimbWall(BH_PWORK* epw, int flg)
{
    ATR_WORK* hp;          
    NJS_POINT3 pos, pos2;       
    int ang, ang2;             
    int i;               
    int root;              
    int mtn[2] = { 3, 24 }; 
	NJS_MKEY* mkfP;        

    if (EXP0_C(105) != 0)
    {
        return 0;
    }

    epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

    if (epw->way > 910)
    {
        ang = (short)((epw->ay + 16384) & ~0x3FFF);
    }
    else if (epw->way < -910)
    {
        ang = (short)(epw->ay & ~0x3FFF);
    }
    else
    {
        ang = (short)((epw->ay + 8192) & ~0x3FFF);
    }

    ang2 = (short)(ang - epw->ay);

    if ((ang2 < -5461) || (ang2 > 5461))
    {
        return 0;
    }

    pos.x = epw->px - (27.0f * njSin(ang));
    pos.z = epw->pz - (27.0f * njCos(ang));

    hp = bhCheckFloorEnemy(epw->flr_no, pos.x, pos.z);

    if (((hp != NULL) && (hp->prm0 == 23) && (hp->prm1 < 4)) && (ang == (short)((-(hp->prm1 & 0x3)) * 16384)))
    {
        *(ATR_WORK**)&EXP0_I(260) = hp;
    
        epw->xn = epw->px;
        epw->yn = epw->py;
        epw->zn = epw->pz;
    
        switch (hp->prm1)
        {
        case 0:
            epw->zn = (hp->pz + hp->d) + 22.4f;
            break;
        case 1:
            epw->xn = hp->px - 22.4f;
            break;
        case 2:
            epw->zn = hp->pz - 22.4f;
            break;
        case 3:
            epw->xn = (hp->px + hp->w) + 22.4f;
            break;
        }
    
        root = 2.0f * (-rand() / -2147483648.0f);
    
        for (i = 0; i < 2; i++)
        {
            mkfP  = epw->mnwP[root + mtn[epw->type]].md2P->p[0];
            mkfP += epw->mnwP[root + mtn[epw->type]].frm_num - 1;
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, ang);
    
            pos = *(NJS_POINT3*)&mkfP->key[0];
            
            pos.x *= flg;
    
            njCalcVector(NULL, &pos, &pos);
            
            njAddVector(&pos, (NJS_POINT3*)&epw->xn);
    
            pos.y -= 23.0f;
    
            if (bhCheckWallType(&pos, 0, 18.199999f, 20.0f) == NULL)
            {
                pos2.x = pos.x;
                pos2.y = pos.y + 999.0f;
                pos2.z = pos.z;
    
                *(ATR_WORK**)&EXP0_I(100) = bhCollisionCheckLine(&pos, &pos2);
    
                return root + 1;
            }
    
            if (++root > 1)
            {
                root = 0;
            }
        }
    }

    return 0;
}

// 99.75% matching
int bhEne23_CheckDiving(BH_PWORK* epw) 
{
    NJS_MKEY* mkfP;
    NJS_POINT3 pos;
    float dist;    

    if (plp->flr_no != 0) 
    {
        return 0;
    }

    if ((epw->flg & 0x8000000)) 
    {
        return 0;
    }

    mkfP  = (NJS_MKEY*)epw->mnwP[37].md2P->p[0];
    mkfP += epw->mnwP[37].frm_num - 1;

    njCalcVector((NJS_MATRIX*)epw->exp0, (NJS_POINT3*)mkfP, &pos);

    pos.x += epw->px;
    pos.z += epw->pz;
    
    pos.y = plp->py;

    if (bhCheckWallType(&pos, 0, 14.0f, 20.0f) != NULL) 
    {
        return 0;
    }

    dist = njSqrt(((pos.x - plp->px) * (pos.x - plp->px)) + ((pos.z - plp->pz) * (pos.z - plp->pz)));

    if (dist < 15.0f) 
    {
        return 0;
    }

    return 1;
}

// 100% matching!
void bhEne23_DamageInit(BH_PWORK* epw)
{
	int flg;

    epw->flg &= ~0x4;

    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);

    epw->comb_flg &= ~0xC;

    if (bhEne03_DGDirCheck(epw) != 0)
    {
        epw->comb_flg |= 0x8;
    }
    else
    {
        epw->comb_flg |= 0x4;
    }

    if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4)) || (epw->comb_pnt == 1))
    {
        if (epw->total_dam != 0)
        {
            if (epw->type == 0)
            {
                if ((epw->comb_flg & 0x8))
                {
                    EXP0_I(276) -= epw->total_dam;
                }
                else
                {
                    if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8)))
                    {
                        EXP0_I(276) -= epw->total_dam;
                    }

                    epw->hp -= epw->total_dam;
                }
            }
            else
            {
                epw->hp -= epw->total_dam;
            }
        }

        if ((epw->wpnr_no == 17) && (!(epw->flg2 & 0x4)))
        {
            return;
        }

        bhEne23_HitMark(epw);

        if ((EXP0_C(105) == 0) && (!(epw->flg & 0x400000)) && (epw->total_dam > 50) && ((-rand() / -2147483648.0f) < 0.3f))
        {
            bhEne23_LegBreak(epw);
        }

        if (epw->hp < 0)
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;

            switch (EXP0_C(105)) 
            {
            case 0:
                epw->mode2 = 0;
                break;
            case 1:
                epw->mode2 = 1;
                break;
            }

            if ((epw->flg & 0x400000))
            {
                if (epw->mlwP->owP->mtx[5] < 0)
                {
                    epw->mode2 = 1;
                }
                else
                {
                    epw->mode2 = 3;
                }
            }

            epw->flg |=  0x2;
            epw->flg &= ~0x20;
            return;
        }

        flg = 0;

        if (((epw->flg & 0x400000)) && ((epw->total_dam < 40) || ((-rand() / -2147483648.0f) > 0.5f)))
        {
            return;
        }

        if ((epw->type == 0) && (EXP0_I(276) < 0))
        {
            switch (epw->wpnr_no)
            {
            case 8:
            case 9:
            case 12:
                if (epw->comb_pnt > 5)
                {
                    flg = 1;
                    
                    epw->mode2 = 4;
                }
                
                break;
            case 5:
            case 6:
            case 10:
            case 11:
            case 13:
            case 14:
            case 15:
            case 16:
            case 20:
                flg = 1;
                
                epw->mode2 = 4;
                break;
            }
        }

        if (flg == 0)
        {
            if (epw->total_dam > 40)
            {
                epw->mode2 = 3;
            }
            else
            {
                if (epw->total_dam <= 20)
                {
                    return;
                }

                epw->mode2 = 1;
            }
        }

        if ((EXP0_C(105) == 1) && ((-rand() / -2147483648.0f) > 0.5f))
        {
            epw->mode2 = 6;
        }

        if ((epw->flg & 0x400000))
        {
            if (epw->mlwP->owP->mtx[5] < 0)
            {
                epw->mode2 = 6;
            }
            else
            {
                epw->mode2 = 7;
            }
        }

        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne23_LegBreak(BH_PWORK* epw) 
{
    int i;
    O_WORK* owk;

    i = (int)(2.0f * (-rand() / -2147483648.0f));  

    if (((unsigned char*)epw->exp0)[i + 258] == 0)   
    {
        ((unsigned char*)epw->exp0)[i + 258] = 1;

        owk = &epw->mlwP->owP[((unsigned char*)epw->exp0)[i + 256]];

        owk[0].flg |= 0x3;
        owk[1].flg |= 0x2;
        owk[2].flg |= 0x2;

        ((BH_PWORK**)epw->exp0)[62 + i]->mode0 = 1;
        ((BH_PWORK**)epw->exp0)[62 + i]->mode2 = 0;
        ((BH_PWORK**)epw->exp0)[62 + i]->mode3 = 0;

        epw->mdflg |= 0x20;

        bhEne_SetBloodstain(epw, 0, ((unsigned char*)epw->exp0)[i + 256], NULL);

        bhEne_SetMinceEffect(epw, 2, 3);
        bhEne_SetMinceEffect(epw, 3, 2);
    }
}

// 100% matching!
void bhEne23_InitChild(BH_PWORK* epw)
{
    int i;          
    BH_PWORK** epw2; 
    int ang;         
    NJS_VECTOR v;    
	float spd;      
    float px, py, pz; // not from DWARF

    epw2 = (BH_PWORK**)&EXP0_C(128);

    for (i = 0; i < EXP0_I(268); i++, epw2++)
    {
        if (((((BH_PWORK**)epw->exp0)[32 + i]->flg & 0x1)) && (((BH_PWORK**)epw->exp0)[32 + i]->id == 24))
        {
            (*epw2)->mode0 = 1;
            (*epw2)->mode1 = 1;
            (*epw2)->mode2 = 5;
            (*epw2)->mode3 = 0;

            (*epw2)->mdflg &= ~0x1;

            ang = 65536.0f * (-rand() / -2147483648.0f);

            spd = 0.5f + (1.2f * (-rand() / -2147483648.0f));

            (*epw2)->ay = ang;

            (*epw2)->xn = spd * -njSin(ang);
            (*epw2)->yn = 0.5f + (1.5f * (-rand() / -2147483648.0f));
            (*epw2)->zn = spd * -njCos(ang);

            v.x = 0;
            v.y = 5.0f + (10.0f * (-rand() / -2147483648.0f));
            v.z = 10.0f;

            njCalcVector((NJS_MATRIX*)epw->exp0, &v, &v);

            px = epw->px + v.x;
            py = epw->py + v.y;
            pz = epw->pz + v.z;

            spd = 3.0f + (3.0f * (-rand() / -2147483648.0f));

            (*epw2)->px = (*epw2)->pxb = px - (spd * njSin(ang));
            (*epw2)->py = (*epw2)->pyb = py;
            (*epw2)->pz = (*epw2)->pzb = pz - (spd * njCos(ang));
        }
    }
}

// 100% matching!
void bhEne23_PlayerControl(BH_PWORK* epw)
{
	int mtn[3][8] = 
	{
		{ 60, 61, 62, 63, 65, 64, 0, 0 },
		{ 66, 67, 68, 69, 71, 70, 0, 0 },
		{ 66, 67, 68, 69, 71, 70, 0, 0 }
	};
	NJS_POINT3* trans[3][3] = 
	{
		{ cler_042, cler_043, cler_045 },
  	    { cher_060, cher_061, cher_063 },
  	    { cher_060, cher_061, cher_063 }  
	}; 

    if (plp->mode0 == 4) 
    {
        switch (plp->mode2) 
        {
        case 0:
        case 1:
            switch (plp->mode3) 
            {                          
            case 0:                                 
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;
                
                plp->mnwP = epw->mnwP;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                }
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                
                bhEne_CallPlayerVoice(2);
                
                StartVibrationEx(1, 11);
                break;
            case 1:                                 
                if (plp->mode2 == 0)
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][1]);
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = mtn[sys->ply_id][2];
                        
                        plp->flg |= 0xC0000;
                    } 
                    else 
                    {
                        plp->mtn_no = mtn[sys->ply_id][3];
                    }
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->mode2 == 0)
                {
                    if ((plp->frm_no / 65536) == 19)
                    {
                        plp->flg &= ~0x80000;
                    }
                    
                    if ((sys->ply_id == 0) && ((plp->frm_no / 65536) == 41))
                    {
                        plp->flg |= 0x80000;
                    }
                }
                else
                {
                    if (plp->mtn_no == mtn[sys->ply_id][3])
                    {
                        bhEne_AddNullTrans(plp, trans[sys->ply_id][2]);
                    }
                }
                
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = plp->mnwPb;
                    
                    plp->flg  &= ~0x10004;
                    plp->flg2 &= ~0x1;
                    
                    plp->flg |= 0x8;
                    
                    plp->at_flg = 0;
                    
                    plp->stflg &= ~0x10000;
                    
                    *(int*)&plp->mode0 = 1;
                }
                
                break;
            }

            break;
        }
        
        plp->flg |= 0x200000;
    }
    else if (plp->mode0 == 6) 
    {
        switch (plp->mode2) 
        {
        case 0:
        case 1:
            switch (plp->mode3) 
            {                       
            case 0:                                 
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;
                
                plp->mnwP = epw->mnwP;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                } 
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                break;
            case 1:                                 
                if (plp->mode2 == 2)
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][1]);
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 2)
                    {
                        plp->mtn_no = mtn[sys->ply_id][4];
                    }
                    else 
                    {
                        plp->mtn_no = mtn[sys->ply_id][5];
                    }
                    
                    plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 2;
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                    
                    plp->ct0 = 45;
                    
                    plp->mode3++;
                }
                
                break;
            case 3:
                if (plp->ct0-- == 0)
                {
                    plp->flg |= 0x2;
                }
                
                break;
            }

            break;
        }
        
        plp->flg |= 0x200000;
    }
}

// 100% matching!
void bhEne23_Acid(BH_PWORK* epw)
{
    int eno;   
    int i;      
    O_WORK* owk; 
    float dt;    
    NJS_POINT3 pos1, pos2; // not from DWARF

    owk = epw->mlwP->owP; 
    
    pos1.x = owk[7].mtx[12];
    pos1.y = owk[7].mtx[13];
    pos1.z = owk[7].mtx[14]; 
    
    pos1.x = (pos1.x + owk[22].mtx[12]) / 2.0f; 
    pos1.y = (pos1.y + owk[22].mtx[13]) / 2.0f;
    pos1.z = (pos1.z + owk[22].mtx[14]) / 2.0f; 

    if (EXP0_C(105) == 0) 
    {
        pos2.x = -3.5f * EXP0_F(32);
        pos2.y = 0; 
        pos2.z = -3.5f * EXP0_F(40); 
    } 
    else 
    { 
        pos2.x = -4.5f * EXP0_F(32); 
        pos2.y = 1.0f; 
        pos2.z = -4.5f * EXP0_F(40);
    }

    sys->ef.id   = 256;
    sys->ef.type = 2;
    
    sys->ef.flg = 1;
    
    sys->ef.px = pos1.x;
    sys->ef.py = pos1.y;
    sys->ef.pz = pos1.z;
    
    for (i = 0; i < 2; i++) 
    {
        dt = 1.5f + (-rand() / -2.1474836E9f);
        
        sys->ef.sx = dt;
        sys->ef.sy = dt;
        sys->ef.sz = dt;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {
            eff[eno].stflg |= 0x20; 
            
            eff[eno].txp[0] = epw->mdl[6].texP; 
            eff[eno].tex_id = 1; 

            eff[eno].xn = pos2.x; 
            eff[eno].yn = pos2.y; 
            eff[eno].zn = pos2.z;
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, (1820.0f * (-rand() / -2.1474836E9f)) - 910.0f);
            njRotateX(NULL,  1820.0f * (-rand() / -2.1474836E9f));
            
            njCalcVector(NULL, (NJS_VECTOR*)&eff[eno].xn, (NJS_VECTOR*)&eff[eno].xn);
            
            dt = -rand() / -2.1474836E9f;
            
            eff[eno].px += dt * eff[eno].xn;
            eff[eno].py += dt * eff[eno].yn;
            eff[eno].pz += dt * eff[eno].zn;
        }
    }
}

// 100% matching!
unsigned int bhEne23_SearchPlayer(BH_PWORK* epw, int ang)
{
	NJS_POINT3 dist;

    dist.x = epw->px - plp->px;
    dist.y = epw->py - plp->py;
    dist.z = epw->pz - plp->pz;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &dist, &dist);
    
    EXP0_I(68) = bhArcTan2(dist.x, dist.z);
    
	return (abs(EXP0_I(68)) < ang) ? 1 : 0;
}

// 100% matching!
void bhEne23_Shape(BH_PWORK* epw) 
{
    if ((epw->mdflg & 0x2)) 
    {
        if (epw->type != 0)
        {
            epw->mdflg &= ~0x2;
        }
        
        if ((epw->flg & 0x2)) 
        {
            EXP0_I(284) += 91;
        } 
        else 
        {
            EXP0_I(284) += 1456;
        }
        
        epw->shp_ct = 500.0f + (500.0f * njSin(EXP0_I(284)));
    }
}

// 100% matching!
void bhEne23_CallSE(BH_PWORK* epw)
{
    int fno;

    if (epw->mnwP == epw->mnwPb) 
    {
        fno = epw->frm_no / 65536;
        
        switch (epw->mtn_no) 
        {                    
        case 2:
            if ((fno == 0) || (fno == 9) || (fno == 14) || (fno == 23)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 22:
            if ((fno == 0) || (fno == 6)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }       
            
            break;
        case 3:  
        case 4:
        case 24:
        case 25:          
            fno %= 34;
            
            if ((fno == 0) || (fno == 9) || (fno == 14) || (fno == 23)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 11:
            if ((fno == 29) || (fno == 44)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74503);
            }      
            
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px,  8976);
            }     
            
            break;
        case 37:
            if (fno == 13) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }    
            
            break;
        case 42:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }     
            
            break;
        case 40:
        case 45:
        case 54:
        case 55:
            if (fno == 1) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }      
            
            break;
        case 48:            
        case 50:
            if (fno == 26) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px,  8978);
            }           
            
            break;
        }
    }
}

// 100% matching!
void bhEne23_HitMark(BH_PWORK* epw)
{
	NJS_POINT3 ofp;
	BLOOD_TBL* blp;
	int i;          
    int range;      

    blp = &BloodTbl[epw->djnt_no];
    
    range = 0;
    
    if ((epw->comb_flg & 0x10)) 
    {
        range = 0;
    }
    
    if ((epw->comb_flg & 0x20)) 
    {
        range = 1;
    }
    
    if ((epw->comb_flg & 0x40)) 
    {
        range = 2;
    }
    
    if (DmgReact[epw->wpnr_no].type[range] >= 0) 
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
        
        bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
        
        if (DmgReact[epw->wpnr_no].bloodstain[range] != 0) 
        {
            bhEne_SetBloodstain(epw, 0, epw->djnt_no, &ofp);
        }
    }
    
    if (((DmgReact[epw->wpnr_no].exef & 0x1)) && (blp->flg == 0)) 
    {
        for (i = 0; i < 4; i++) 
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;
            
            ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2.1474836E9f)), (int)(40.0f * (-rand() / -2.1474836E9f)) + 20);
        } 
    }
    
    if (((DmgReact[epw->wpnr_no].exef & 0x2)) && (blp->flg == 0)) 
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 0x4)) 
    {
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF201010);
    }
}
