#include "../../../ps2/veronica/prog/en22.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Albinoid Adult

const char en22_flipTree[43] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    19, 20, 21, 22, 23, 24, 25,
    12, 13, 14, 15, 16, 17, 18,
    34, 35, 36, 37, 38, 39, 40, 41,
    26, 27, 28, 29, 30, 31, 32, 33,
    -1
};

EN22_MTN_WORK en22_mtn_tbl[12] = {
    { 2, {{ 0,    74504}, {38,    74504}, {-1, 0}, {-1, 0}}},
    { 5, {{ 9,    74496}, {-1,        0}, {-1, 0}, {-1, 0}}},
    { 6, {{ 0,    74504}, {36,    74504}, {-1, 0}, {-1, 0}}},
    { 7, {{ 4,    74504}, {-1,        0}, {-1, 0}, {-1, 0}}},
    { 8, {{ 0,    74504}, {-1,        0}, {-1, 0}, {-1, 0}}},
    { 9, {{10, 16851713}, {-1,        0}, {-1, 0}, {-1, 0}}},
    {10, {{ 0, 16786180}, {20,    74505}, {-1, 0}, {-1, 0}}},
    {11, {{ 0, 16786180}, {-1,        0}, {-1, 0}, {-1, 0}}},
    {13, {{ 0, 16786186}, {-1,        0}, {-1, 0}, {-1, 0}}},
    {19, {{ 0,    74505}, {85, 16786181}, {-1, 0}, {-1, 0}}},
    {20, {{ 0, 16786187}, {-1,        0}, {-1, 0}, {-1, 0}}},
    {-1, {{ 0,        0}, { 0,        0}, { 0, 0}, { 0, 0}}}
};

WPNDAMAGE_WORK En22_WpnDamageTbl[22] = {
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0},
	{ 0, 4, 3, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 0, 5, 3, 5},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 3, 3, 3},
	{ 0, 0, 1, 3, 3},
	{12, 0, 1, 3, 3},
	{ 4, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3}
};

static COMBWEP_WORK CombWepTbl[21] = {
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 90, {10, 8, 5}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    {160, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 80, {10, 8, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {160, {10, 8, 5}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0}
};

static COMBJOINT_WORK CombJointTbl[42] = {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};

CPCL Ene22CapColTab[27] = {
    {  2,  2, 20},
    {  0,  0, 20},
    {  2,  2, 23},
    {-25,  0, 20},
    {  2,  2, 23},
    { 25,  0, 20},
    {  3,  4, 30},
    {  4,  5, 22},
    {  5,  6, 15},
    {  6,  7, 18},
    {  7,  8, 12},
    {  8,  9, 11},
    {  9, 10, 11},
    { 10, 11, 10},
    { 19, 20, 11},
    { 20, 21,  9},
    { 12, 13, 11},
    { 13, 14,  9},
    { 34, 34, 20},
    {  8,  0,  0},
    { 35, 36,  8},
    { 36, 37,  8},
    { 26, 26, 20},
    { -8,  0,  0},
    { 27, 28,  8},
    { 28, 29,  8},
    {  0,  0,  0}
};

BT_WORK en22prt_blood_tbl[42] = {
    { 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    { 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    { 2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 3, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 4, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 5, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 6, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 7, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 8, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 9, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {10, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {11, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {12, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {13, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {14, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {15, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {17, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {18, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {19, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {20, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {21, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {22, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {23, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {24, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {25, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {26, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {27, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {28, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {29, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {30, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {31, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {32, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {33, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {34, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {35, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {36, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {37, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {38, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {39, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {40, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {41, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f}
};

char En22SdwTab[7] = {
    2, 7, 13, 20, 28, 36, -1
};

static EN22_WSP_WORK ene22_wsp_tbl[57] = {
    {13,  5, 37},
    {13,  6, 35},
    {13,  6, 29},
    {13,  6,  6},
    {13,  7,  2},
    {13,  8,  4},
    {13,  8,  9},
    {13, 10, 13},
    {13, 10, 20},
    {10,  0,  2},
    {10,  3, 11},
    {10,  5, 29},
    {10,  5,  9},
    {10,  7,  7},
    {10, 10, 37},
    {10, 12,  0},
    {10, 17,  0},
    {11,  3, 28},
    {11,  4,  0},
    {11,  5, 13},
    {11,  6,  7},
    {11,  9, 36},
    {11, 10, 20},
    {11, 11, 10},
    {11, 13, 11},
    {19,  5,  2},
    {19, 10, 10},
    {19, 11,  4},
    {19, 12, 29},
    {19, 12, 11},
    {19, 16, 37},
    {19, 25,  0},
    {19, 38,  0},
    {19, 51,  0},
    {19, 65,  0},
    {19, 77, 29},
    {19, 79, 37},
    {19, 83,  4},
    {19, 88,  2},
    {20,  3, 13},
    {20,  3,  4},
    {20,  4, 20},
    {20,  5, 28},
    {20,  5, 36},
    {20,  6,  2},
    {20,  6, 10},
    {20, 24,  2},
    {20, 27, 28},
    {20, 29, 36},
    {20, 29,  6},
    {20, 31,  9},
    {20, 45,  3},
    {20, 50,  0},
    {20, 52,  9},
    {20, 52, 28},
    {20, 52, 36},
    {-1,  0,  0}
};

static EN22_WEFF_WORK en22_weff_tbl[14] = {
    { 2,  0, 28},
    { 2, 34, 36},
    { 5, 17,  2},
    { 6, 23,  2},
    { 6, 10,  2},
    { 9, 37,  4},
    {10, 20,  4},
    {11, 13,  2},
    {13,  8,  2},
    {19,  8,  4},
    {19, 88,  4},
    {20, 16,  3},
    {20, 36,  3},
    {-1,  0,  0}
};

EN22_POINT2_XZ ply_mtn42b_pos[20] = {
    { 0.0f,            -3.220037f   },
    { 0.0f,            -1.4619832f  },
    { 0.0f,            -1.447103f   },
    { 0.0f,            -1.4290719f  },
    { 0.0f,            -1.4078922f  },
    { 0.0f,            -1.383564f   },
    { 0.0f,            -1.3560877f  },
    { 0.0f,            -1.3254604f  },
    { 0.0f,            -1.2916822f  },
    { 0.0f,            -1.2547579f  },
    { 0.0f,            -1.2146845f  },
    { 0.0f,            -1.1714611f  },
    { 0.0f,            -1.1250877f  },
    { 0.000066f,       -0.9541111f  },
    { 0.00015499999f,  -0.6899109f  },
    { 0.000176f,       -0.46962357f },
    { 0.00013200002f,  -0.29325867f },
    { 0.000021999993f, -0.16081047f },
    {-0.00015400001f,  -0.07228279f },
    {-0.000397f,       -0.027669907f}
};

EN22_POINT2_XZ ply_mtn43b_pos[20] = {
    {0.0f, 5.8285589f },
    {0.0f, 2.0167189f },
    {0.0f, 1.8550768f },
    {0.0f, 1.7206335f },
    {0.0f, 1.6133881f },
    {0.0f, 1.5333433f },
    {0.0f, 1.4804945f },
    {0.0f, 1.4548454f },
    {0.0f, 1.4563942f },
    {0.0f, 0.95617104f},
    {0.0f, 0.57528687f},
    {0.0f, 0.7033367f },
    {0.0f, 0.6761093f },
    {0.0f, 0.61144829f},
    {0.0f, 0.49389648f},
    {0.0f, 0.34840584f},
    {0.0f, 0.27017784f},
    {0.0f, 0.24227142f},
    {0.0f, 0.18896675f},
    {0.0f, 0.1102581f }
};

EN22_POINT2_XZ ply_mtn44b_pos[50] = {
    {-0.00059f,        -0.0079956055f},
    {-0.00068f,         0.014802933f },
    {-0.00075900008f,   0.035778046f },
    {-0.000825f,        0.054922104f },
    {-0.00087899994f,   0.072244644f },
    {-0.00091999979f,   0.08773613f  },
    {-0.00095000025f,   0.10140228f  },
    {-0.00096700015f,   0.11324501f  },
    {-0.00097199995f,   0.12325668f  },
    {-0.00096500013f,   0.13144493f  },
    {-0.00094499998f,   0.13780403f  },
    {-0.00091299973f,   0.1423397f   },
    {-0.00086900033f,   0.14504623f  },
    {-0.0008129999f,    0.14592743f  },
    {-0.00074400008f,   0.14580154f  },
    {-0.00066300016f,   0.16204071f  },
    {-0.0005699992f,    0.18796539f  },
    {-0.00046500005f,   0.21744347f  },
    {-0.00034700055f,   0.25047493f  },
    {-0.00021700002f,   0.28705788f  },
    {-0.000075999647f,  0.32719803f  },
    { 0.000049999915f,  0.3674984f   },
    { 0.00014299992f,   0.34771347f  },
    { 0.00023099966f,   0.30610847f  },
    { 0.0003120005f,    0.26638985f  },
    { 0.00038500037f,   0.22855759f  },
    { 0.00045299996f,   0.19260406f  },
    { 0.00051299948f,   0.15853691f  },
    { 0.00056700036f,   0.12635422f  },
    { 0.00061399955f,   0.09605789f  },
    { 0.0006550001f,    0.067640305f },
    { 0.00068799965f,   0.041110992f },
    { 0.00071500055f,   0.01646614f  },
    { 0.00073499978f,  -0.006298065f },
    { 0.0007480001f,   -0.027175903f },
    { 0.00075600017f,  -0.04616928f  },
    { 0.0007549999f,   -0.063278198f },
    { 0.00074899988f,  -0.07850647f  },
    { 0.00073500024f,  -0.09184837f  },
    { 0.0007149996f,   -0.10330391f  },
    { 0.0006880001f,   -0.11288071f  },
    { 0.00065400009f,  -0.12056732f  },
    { 0.000614f,       -0.1263752f   },
    { 0.00056699989f,  -0.1302967f   },
    { 0.00051400007f,  -0.13233185f  },
    { 0.00045199995f,  -0.13248825f  },
    { 0.00038600003f,  -0.13075447f  },
    { 0.000311f,       -0.12714195f  },
    { 0.000231f,       -0.12164116f  },
    { 0.000144f,       -0.11425972f  }
};

EN22_POINT2_XZ ply_mtn45b_pos[50] = {
    { 0.0051699998f,  0.051181793f  },
    { 0.014990001f,   0.03083229f   },
    { 0.02403f,       0.013719559f  },
    { 0.032290999f,  -0.00015449524f},
    { 0.039773002f,  -0.010793686f  },
    { 0.046472996f,  -0.018190384f  },
    { 0.052395999f,  -0.022354126f  },
    { 0.057539016f,  -0.023277283f  },
    { 0.061900973f,  -0.020963669f  },
    { 0.065484017f,  -0.027778625f  },
    { 0.06828898f,   -0.049476624f  },
    { 0.07031202f,   -0.076560974f  },
    { 0.07155597f,   -0.109041214f  },
    { 0.072021008f,  -0.1469059f    },
    { 0.07833004f,   -0.17226791f   },
    { 0.08751994f,   -0.18546867f   },
    { 0.09148502f,   -0.20457649f   },
    { 0.090228975f,  -0.22959328f   },
    { 0.083749056f,  -0.2605896f    },
    { 0.072044015f,  -0.29907799f   },
    { 0.055117965f,  -0.32930183f   },
    { 0.03296697f,   -0.34487152f   },
    { 0.009256005f,  -0.34578705f   },
    { 0.0026700497f, -0.33204842f   },
    {-0.0010420084f, -0.30365753f   },
    {-0.0048240423f, -0.26327515f   },
    {-0.0086729527f, -0.22501564f   },
    {-0.012591004f,  -0.19028473f   },
    {-0.016576052f,  -0.15877151f   },
    {-0.020630002f,  -0.13047409f   },
    {-0.02475202f,   -0.10539436f   },
    {-0.028941989f,  -0.08353424f   },
    {-0.033199906f,  -0.064891815f  },
    {-0.03752601f,   -0.049465179f  },
    {-0.04192102f,   -0.037258148f  },
    {-0.04638207f,   -0.028268814f  },
    {-0.050912976f,  -0.022497177f  },
    {-0.055512965f,  -0.01994133f   },
    {-0.06017804f,   -0.020606995f  },
    {-0.063638985f,  -0.0031776428f },
    {-0.065679014f,   0.030195236f  },
    {-0.067460954f,   0.057128906f  },
    {-0.068989038f,   0.077625275f  },
    {-0.070258975f,   0.09168434f   },
    {-0.071274996f,   0.099300385f  },
    {-0.072033018f,   0.10048103f   },
    {-0.072537005f,   0.095220566f  },
    {-0.07278399f,    0.083524704f  },
    {-0.07277499f,    0.065385818f  },
    {-0.072509006f,   0.040813446f  }
};

void (*bhEne22_Mode0[6])(BH_PWORK*) = {
    bhEne22_Init,
    bhEne22_Move,
    bhEne22_Nage,
    bhEne22_Damage,
    bhEne22_Die,
    bhEne_Event
};

void (*bhEne22_InitType[1])(BH_PWORK*) = {
    bhEne22_InitType00
};

void (*bhEne22_MoveType[1])(BH_PWORK*) = {
    bhEne22_MVType00
};

void (*bhEne22_BrainMode2[6])(BH_PWORK*) = {
    bhEne22_Brain00,
    bhEne22_Brain01,
    bhEne22_Brain02,
    bhEne22_DmmyBrain,
    bhEne22_Brain04,
    bhEne22_DmmyBrain
};

void (*bhEne22_MoveMode2[7])(BH_PWORK*) = {
    bhEne22_MV00,
    bhEne22_MV01,
    bhEne22_MV02,
    bhEne22_MV03,
    bhEne22_MV04,
    bhEne22_MV05,
    bhEne22_MV06
};

void (*bhEne22_DamageType[1])(BH_PWORK*) = {
    bhEne22_DGType00
};

void (*bhEne22_DamageMode2[3])(BH_PWORK*) = {
    bhEne22_DG00,
    bhEne22_DG01,
    bhEne22_DG02
};

void (*bhEne22_DieType[1])(BH_PWORK*) = {
    bhEne22_DDType00
};

void (*bhEne22_DieMode2[2])(BH_PWORK*) = {
    bhEne22_DD00,
    bhEne22_DD01
};

// Unused (present in DWARF)
// char en22_tree[16][4];
// int en22_hp_tbl[16];
// void(*bhEne22_NageType)(BH_PWORK*)[1];
// void(*bhEne22_NageMode2)(BH_PWORK*)[1];
// float en22_mogmog[20];

// 100% matching!
void bhEne22_DmmyBrain(BH_PWORK* epw)
{
	return;
}

// 100% matching!
void bhEne22(BH_PWORK* epw)
{
    O_WORK* owk;
    int i;

    bhEne22_MainLoop(epw);

    if ((plp->mode0 == 4) || (plp->mode0 == 6))
    {
        if (plp->mode2 == 0)
        {
            bhEne22_PlyDG00(plp, epw);
        }
        else
        {
            bhEne22_PlyDG01(plp, epw);
        }
    }

    if (epw->flg & 0x4)
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        epw->flg &= ~0x4;
    }

    bhEne22_CollCheck(epw);
    bhCalcModel(epw);

    owk = epw->mlwP->owP + 4;
    epw->aox = owk->mtx[12] - epw->px;
    epw->aoz = owk->mtx[14] - epw->pz;

    owk = epw->mlwP->owP + 3;
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = epw->py + 2.0f;
    epw->watr.c1.z = owk->mtx[14];

    owk = epw->mlwP->owP + 9;
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = epw->py + 2.0f;
    epw->watr.c2.z = owk->mtx[14];
    epw->watr.r = 5.5f;

    if (EXP0_I(0xC) > 0)
    {
        EXP0_I(0xC)--;
    }

    if (EXP0_I(0x10) > 0)
    {
        EXP0_I(0x10)--;
    }

    if (EXP0_I(0x14) > 0)
    {
        EXP0_I(0x14)--;
    }

    if (EXP0_I(0x1C) > 0)
    {
        EXP0_I(0x1C)--;
    }

    bhEne22_CtrLight(epw);
}

// 100% matching!
void bhEne22_MainLoop(BH_PWORK* epw)
{
    bhEne22_DmgChk(epw);

    bhEne22_Mode0[epw->mode0](epw);

    bhEne22_SetMtn(epw);
}

// 100% matching!
int bhEne22_DmgChk(BH_PWORK* epw)
{
    int houkou;

    if ((epw->flg & 0x4) && ((epw->flg & 0x2) == 0) && ((EXP0_I(0x8) & 0x20000) == 0))
    {
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        if (epw->total_dam == 0)
        {
            return 1;
        }

        bhEne22_DamageAdd(epw);
        if (epw->mode0 != 1)
        {
            return 1;
        }

        houkou = bhDGCdirCheck3((NJS_VECTOR*)&epw->dvx, epw->ay);
        EXP0_I(0x8) &= ~0x30;
        if (houkou == 0)
        {
            EXP0_I(0x8) |= 0x0;
        }
        else if (houkou == 1)
        {
            EXP0_I(0x8) |= 0x10;
        }
        else if (houkou == 2)
        {
            EXP0_I(0x8) |= 0x20;
        }
        else if (houkou == 3)
        {
            EXP0_I(0x8) |= 0x30;
        }

        bhEne22_ChgDmgMode(epw);

        return 1;
    }

    return 0;
}

// 100% matching!
void bhEne22_ChgDmgMode(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl = En22_WpnDamageTbl;
    int act;

    wp_tbl += epw->wpnr_no;
    act = wp_tbl->nm_act;

    if (epw->hp < 0)
    {
        epw->comb_flg |= 0x1;
        epw->comb_timeout = 0;
        epw->comb_pnt = 0;
    }

    if (epw->comb_flg & 0x1)
    {
        act = wp_tbl->cb_act;
    }

    if (act < 4U)
    {
        if (EXP0_I(0x8) & 0x1000)
        {
            if (((*(O_WRK**)(epw->exp0 + 0x4C))->flg != 0)
                && ((*(O_WRK**)(epw->exp0 + 0x4C))->id == 353)
                && ((BH_PWORK*)(*(O_WRK**)(epw->exp0 + 0x4C))->lkwkp == epw))
            {
                (*(O_WRK**)(epw->exp0 + 0x4C))->mode0 = 4;
            }

            if (EXP0_I(0x8) & 0x80000)
            {
                rom->lgtp[2].flg &= ~0x3;
                EXP0_I(0x8) &= ~0x80000;
            }

            EXP0_I(0x8) &= ~0x1000;
        }

        if (epw->hp < 0)
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        else
        {
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode3 = 0;
            if (EXP0_I(0x8) & 0x100)
            {
                epw->mode2 = 0;
            }
            else
            {
                epw->mode2 = 1;
            }
        }
    }
}

// 100% matching!
void bhEne22_DamageAdd(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl = En22_WpnDamageTbl;
    int* d;
    int i;

    if (epw->hp >= 0)
    {
        epw->hp -= epw->total_dam;
        wp_tbl += epw->comb_wep;

        for (d = epw->dam + 2, i = 2; i < (int)epw->mlwP->obj_num; i++, d++)
        {
            if (*d <= 0) continue;

            epw->djnt_no = i;

            if (wp_tbl->flg & 0x4) continue;

            if ((epw->comb_flg & 0x1) || (epw->hp < 0))
            {
                bhEne_SetBlood(epw, wp_tbl->cb_blood, en22prt_blood_tbl);
            }
            else
            {
                bhEne_SetBlood(epw, wp_tbl->nm_blood, en22prt_blood_tbl);
            }
        }
    }

    if (((wp_tbl->flg & 0x1) || (wp_tbl->flg & 0x2)) && (EXP0_I(0x10) <= 0))
    {
        EXP0_I(0x10) = 10;

        if (wp_tbl->flg & 0x2)
        {
            bhEne_SetDFireEffect(epw, epw->djnt_no, en22prt_blood_tbl, 2);
        }
        else
        {
            bhEne_SetDFireEffect(epw, epw->djnt_no, en22prt_blood_tbl, 1);
        }
    }

    if ((wp_tbl->flg & 0x8) && (EXP0_I(0x10) <= 0))
    {
        EXP0_I(0x10) = 10;

        bhEne_SetSanEffect(epw, epw->djnt_no, en22prt_blood_tbl);
    }
}

// 100% matching!
void bhEne22_CollCheck(BH_PWORK* epw)
{
    if ((epw->flg & 0x2) == 0)
    {
        if ((epw->flg & 0x8) && (EXP0_I(0x8) & 0x40))
        {
            bhCheckPlayer(epw);
        }

        bhEne22_CollCheckWall(epw);
    }
}

// 100% matching!
void bhEne22_CollCheckWall(BH_PWORK* epw)
{
    NJS_POINT3 ps, pd;
    O_WORK* owk;

    if ((sys->st_flg & 0x40) && ((epw->stflg & 0x100000) == 0) && (bhCheckWater((NJS_POINT3*)&epw->px) != NULL))
    {
        epw->stflg |= 0x100000;
    }

    EXP0_ATR(17) = bhCheckWallType((NJS_POINT3*)&epw->px, epw->flg, epw->ar, epw->ah);

    if (((EXP0_I(0x8) & 0xF) == 0x1) && (epw->flg & 0x10))
    {
        ps.x = epw->px + epw->aox;
        ps.z = epw->pz + epw->aoz;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, epw->ar, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 28;
        ps.x = owk->mtx[12];
        ps.z = owk->mtx[14];
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 29;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 36;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 37;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 13;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 14;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 20;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 21;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }
    }
    else if ((EXP0_I(0x8) & 0xF) == 2)
    {
        bhCheckDansa(epw);

        owk = epw->mlwP->owP + 21;
        ps.x = owk->mtx[12];
        ps.z = owk->mtx[14];
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 14;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }
    }
}

// 100% matching!
void bhEne22_Init(BH_PWORK* epw)
{
    int i;
    unsigned char* addr;
    int size;

    epw->ar = 7.0f;
    epw->ah = 6.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 7.0f;
    epw->cah = 6.0f;
    epw->stflg = 0;

    if (sys->gm_mode != 2)
    {
        epw->hp = 250;
    }
    else
    {
        epw->hp = 160;
    }

    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }

    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = (unsigned char*)en22_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0xB0, 8);
    }
    else
    {
        if (EXP0_I(0x8) & 0x80000)
        {
            rom->lgtp[2].flg &= ~0x3;
            EXP0_I(0x8) &= ~0x80000;
        }

        addr = epw->exp0;
        size = 0xB0;
        while (size-- != 0)
        {
            *addr = 0;
            addr++;
        }
    }

    EXP0_I(0x8) |= 0x41;
    epw->flg |= 0x78;
    epw->flg &= ~0x2;

    if ((epw->flg & 0x800) == 0)
    {
        addr = (unsigned char*)epw;
        bhSetShadow(En22SdwTab, addr, 4, 4.0f, 4.0f, 8.0f);
        epw->flg |= 0x800;
    }

    epw->clp_jno[0] = -1;
    epw->mdflg |= 0x20;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->lok_jno = 2;
    epw->cpcl = Ene22CapColTab;

    bhEne22_InitType[epw->type](epw);
}

// 100% matching!
void bhEne22_InitType00(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_Move(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos, epos;

    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];

    epos.x = epw->px + epw->aox;
    epos.z = epw->pz + epw->aoz;
    epos.y = epw->py;

    EXP0_F(0x20) = njDistanceP2P(&pos, &epos);

    bhEne22_MoveType[epw->type](epw);

    if ((EXP0_I(0x14) == 0) && (epw->mode2 != 4))
    {
        bhEne22_SetElectricShockEffect(epw, 3);

        EXP0_I(0x14) = rand() % 30 + 60;
        EXP0_I(0x1C) = 15;

        pos.x = 0.0f;
        pos.y = 5.0f;
        pos.z = 0.0f;

        bhEne22_SetLight(epw, 4, &pos, 0);
        bhEne22_SePlay(epw, (NJS_POINT3*)&epw->px, 0x1012302);
    }

    bhEne22_PlyerHitCheck(plp, epw);
}

// 100% matching!
void bhEne22_Nage(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_Damage(BH_PWORK* epw)
{
    bhEne22_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne22_Die(BH_PWORK* epw)
{
    bhEne22_DieType[epw->type](epw);
}

// 100% matching!
void bhEne22_PlyerHitCheck(BH_PWORK* pl, BH_PWORK* epw)
{
    NJS_POINT3 ps;

    if ((EXP0_I(0x1C) > 0)
        && (EXP0_F(0x20) <= 20.0f)
        && (pl->flr_no == epw->flr_no)
        && ((pl->flg & 0x2) == 0)
        && ((pl->flg & 0x4) == 0)
        && ((pl->stflg & 0x80000000) == 0))
    {
        EXP0_I(0x8) |= 0x40000;

        pl->mode0 = 4;
        pl->mode1 = 0;
        pl->mode2 = 0;
        pl->mode3 = 0;
        pl->flg |= 0x4;
        pl->hp -= 30;

        bhEne22_SetElectricShockEffect2(epw);
        bhEne22_SePlay(epw, (NJS_POINT3*)&pl->px, 0x1012302);

        ps.x = plp->px;
        ps.y = 10.0f;
        ps.z = plp->pz;

        bhEne22_SetLight(epw, -1, &ps, 0);

        EXP0_I(0x1C) = 0;
    }

    if ((EXP0_F(0x20) <= 10.0f)
        && (ikou3(epw, (NJS_POINT3*)&plp->px, NJM_DEG_ANG(30.0f)) == 0)
        && (pl->flr_no == epw->flr_no)
        && ((pl->flg & 0x2) == 0)
        && ((pl->flg & 0x4) == 0)
        && ((pl->stflg & 0x80000000) == 0))
    {
        EXP0_I(0x8) |= 0x40000;

        if ((epw->mtn_no == 5) || (epw->mtn_no - 6 < 2))
        {
            pl->mode0 = 4;
            pl->mode1 = 0;
            pl->mode2 = 1;
            pl->mode3 = 0;
        }
        else
        {
            pl->mode0 = 4;
            pl->mode1 = 0;
            pl->mode2 = 0;
            pl->mode3 = 0;
        }

        pl->flg |= 0x4;
        pl->hp -= 30;

        bhEne22_SetElectricShockEffect2(epw);
        bhEne22_SetElectricShockEffect(epw, 1);
        bhEne22_SePlay(epw, (NJS_POINT3*)&pl->px, 0x1012302);

        ps.x = plp->px;
        ps.y = 10.0f;
        ps.z = plp->pz;

        bhEne22_SetLight(epw, -1, &ps, 0);
    }
}

// 100% matching!
void bhEne22_EneSearch(BH_PWORK* epw)
{
    EXP0_UC(0x0) |= 0x80;

    if ((EXP0_UC(0x0) & 0x1F) < 0x4)
    {
        if (bhSearchPlayer(epw, 18204) != -1)
        {
            EXP0_UC(0x0) |= 0x20;
        }

        if ((EXP0_UC(0x0) & 0x1F) == 3)
        {
            if (EXP0_UC(0x0) & 0x20)
            {
                EXP0_UC(0x0) |= 0x40;
            }
            else
            {
                EXP0_UC(0x0) &= ~0x40;
            }

            EXP0_UC(0x0) &= ~0xA0;
        }
    }

    EXP0_UC(0x0)++;

    if ((EXP0_UC(0x0) & 0x1F) > 0xF)
    {
        EXP0_UC(0x0) &= ~0x1F;
    }
}

// 100% matching!
void bhEne22_Brain(BH_PWORK* epw)
{
    if ((EXP0_UC(0x0) & 0x40) == 0)
    {
        bhEne22_EneSearch(epw);
    }

    bhEne22_BrainMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_Brain00(BH_PWORK* epw)
{
    if (epw->mode3 == 0) return;

    if (plp->flr_no == 0)
    {
        if (EXP0_F(0x20) <= 40.0f)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        else if (((plp->stflg & 0x80000000) == 0) && (EXP0_F(0x20) > 40.0f))
        {
            epw->mode1 = 1;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }

        epw->ct0 = rand() % 60 + 120;
    }
    else
    {
        epw->ct0--;

        if (bhEne22_AreaCheck(epw->px, epw->pz, plp->px, plp->pz) || (epw->ct0 < 0) || (EXP0_F(0x20) < 42.0f))
        {
            bhEne22_SetTrgPos(epw);

            if (epw->ct0 < 0)
            {
                if (rand() % 2)
                {
                    epw->mode2 = 1;
                }
                else
                {
                    epw->mode2 = 2;
                }
            }
            else
            {
                epw->mode2 = 2;
            }
            epw->mode1 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne22_Brain01(BH_PWORK* epw)
{
    if (bhEne22_AreaCheck(EXP0_F(0x24), EXP0_F(0x2C), plp->px, plp->pz))
    {
        bhEne22_SetTrgPos(epw);
    }

    if (plp->flr_no == 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne22_Brain02(BH_PWORK* epw)
{
    if (plp->flr_no == 0)
    {
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
    }
    else
    {
        if (bhEne22_AreaCheck(EXP0_F(0x24), EXP0_F(0x2C), plp->px, plp->pz))
        {
            bhEne22_SetTrgPos(epw);
        }
    }
}

// 100% matching!
void bhEne22_Brain04(BH_PWORK* epw)
{
    if (EXP0_F(0x20) < 20.0f)
    {
        EXP0_I(0x8) |= 0x10000;
    }
}

// 100% matching!
void bhEne22_MVType00(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne22_Brain(epw);
    }

    bhEne22_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 7);

        if (EXP0_UC(0x0) & 0x40)
        {
            epw->ct0 = rand() % 60 + 30;
        }
        else
        {
            epw->ct0 = rand() % 60 + 120;
        }

        if (EXP0_I(0x8) & 0x4000)
        {
            EXP0_I(0x8) &= ~0x4000;
            epw->ct0 = rand() % 60 + 90;
            epw->ct1 = 1;
        }
        else
        {
            epw->ct1 = 0;
        }
        epw->ct2 = 0;
        epw->mode1 = 1;
        epw->mode3++;
        break;

    case 1:
        break;
    }

    if ((epw->flg & 0x2000000) && (rand() % 2))
    {
        bhEne22_SePlay(epw, (NJS_POINT3*)&epw->px, 0x1012306);
    }
}

// 100% matching!
void bhEne22_MV01(BH_PWORK* epw)
{
    int hit;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 1, 0, 5);
        epw->way = 384;
        epw->wax = 0;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->spd = 0.0f;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            epw->ct1 = rand() % 30 + 40;
            epw->mode3++;
        }

        epw->spd += 0.02f;
        if (epw->spd >= 0.4f)
        {
            epw->spd = 0.4f;
        }

        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
        bhAddSpeed(epw, 0);
        break;

    case 2:
        if (bhEne_CheckDirWall2(epw, 0, 18.0f) != NULL)
        {
            hit = bhEne_CheckSideWall2(epw, 18.0f, 0);
            if (hit == 0)
            {
                epw->way = (rand() % 2) ? 384 : -384;
            }
            else
            {
                epw->way = hit * 384;
            }

            if (epw->way < 0)
            {
                epw->wax = -256;
            }
            else
            {
                epw->wax = 256;
            }
            EXP0_I(0x8) |= 0x2000;
            bhEne_ChgMtn(epw, 2, 0, 5);
            epw->ct1 = 42;
            epw->mode3++;
        }
        else
        {
            if ((epw->flg & 0x2000000)
                && (((fabsf(EXP0_F(0x24) - epw->px) < 10.0f) && (fabsf(EXP0_F(0x2C) - epw->pz) < 10.0f))
                    || (EXP0_I(0x8) & 0x8000)))
            {
                bhEne_ChgMtn(epw, 4, 0, 5);
                epw->ct1 = 0;
                epw->mode3 = 4;
                EXP0_I(0x8) &= ~0x8000;
            }

            ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
            bhAddSpeed(epw, 0);
        }
        break;

    case 3:
        epw->ay += epw->way;
        bhAddSpeed(epw, -epw->way);
        if (--epw->ct1 < 0)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->mode3 = 2;
        }
        break;

    case 4:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }

        epw->spd -= 0.02f;
        if (epw->spd < 0.0f)
        {
            epw->spd = 0.0f;
        }
        bhAddSpeed(epw, 0);
        break;
    }
}

// 100% matching!
void bhEne22_MV02(BH_PWORK* epw)
{
    ATR_WORK* hp;
    NJS_POINT3 pos;
    int frm;
    int hit;

    switch (epw->mode3)
    {
    case 0:
        epw->way = 768;
        epw->wax = 0;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        epw->ct3 = 0;
        EXP0_I(0x8) |= 0x100;

        if (EXP0_I(0x8) & 0x200)
        {
            bhEne_ChgMtn(epw, 6, 0, 5);
            EXP0_I(0x8) &= ~0x200;
            epw->ct0 = 0;
            epw->spd = 1.2f;
            epw->mode3 = 2;
            return;
        }

        bhEne_ChgMtn(epw, 5, 0, 5);
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
        epw->spd = 0.0f;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 6, 0, 0);
            epw->ct0 = 0;
            epw->ct2 = 300;
            epw->mode3++;
        }

        epw->spd += 0.05f;
        if (epw->spd >= 1.2f)
        {
            epw->spd = 1.2f;
        }

        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 768);
        bhAddSpeed(epw, 0);
        break;

    case 2:
        epw->spd = 1.2f - epw->ct0 * 0.01f;
        epw->ct0++;
        if (epw->spd < 0.8f)
        {
            epw->ct0 = 0;
            epw->spd = 0.8f;
            if (ikou3(epw, (NJS_POINT3*)&plp->px, NJM_DEG_ANG(112.5f)) && (EXP0_F(0x20) > 20.0f))
            {
                epw->mode3 = 6;
                return;
            }
        }

        if (EXP0_I(0x8) & 0x40000)
        {
            EXP0_I(0x8) &= ~0x40000;
            epw->way = (rand() % 2) ? 768 : -768;
            EXP0_I(0x8) |= 0x2000;
            bhEne_ChgMtn(epw, 7, 0, 5);
            if (epw->way > 0)
            {
                epw->mtn_md |= 0x2;
            }
            epw->ct1 = 32;
            epw->mode3 = 4;
            epw->ct2 = 0;
        }
        else
        {
            hp = bhEne_CheckDirWall2(epw, 0, 18.0f);
            if (hp != NULL)
            {
                pos.x = epw->px + 18.0f * -njSin(epw->ay);
                pos.z = epw->pz + 18.0f * -njCos(epw->ay);
                pos.y = epw->py;

                hit = bhEne_CheckSideWall3(epw, &pos, 18.0f, 0);
                if (hit == 0)
                {
                    epw->way = (rand() % 2) ? 768 : -768;
                }
                else
                {
                    epw->way = hit * 768;
                }

                if (epw->way < 0)
                {
                    epw->wax = -1024;
                }
                else
                {
                    epw->wax = 1024;
                }

                EXP0_I(0x8) |= 0x2000;
                bhEne_ChgMtn(epw, 7, 0, 5);
                if (epw->wax > 0)
                {
                    epw->mtn_md |= 0x2;
                }
                epw->ct1 = 21;
                epw->mode3 = 4;
            }
            else
            {
                if ((plp->flr_no == 0) && (EXP0_F(0x20) >= 40.0f))
                {
                    bhEne_ChgMtn(epw, 8, 0, 5);
                    epw->mode3 = 3;
                }
                else
                {
                    if ((fabsf(EXP0_F(0x24) - epw->px) < 5.0f) && (fabsf(EXP0_F(0x2C) - epw->pz) < 5.0f))
                    {
                        bhEne_ChgMtn(epw, 8, 0, 5);
                        epw->mode3 = 3;
                    }

                    ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
                    bhAddSpeed(epw, 0);
                }
            }
        }
        break;

    case 3:
        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) &= ~0x100;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }

        epw->spd -= 0.05f;
        if (epw->spd < 0.0f)
        {
            epw->spd = 0.0f;
        }
        bhAddSpeed(epw, 0);
        break;

    case 4:
        frm = epw->frm_no / 65536;
        if (frm == 20)
        {
            epw->mtn_add = 0;
        }

        if (epw->spd > 0.5f)
        {
            epw->spd -= 0.02f;
            epw->ct0++;
        }
        else
        {
            epw->spd = 0.5f;
        }

        hp = bhEne_CheckDirWall2(epw, 0, 18.0f);
        if ((hp == NULL) && (frm >= 16))
        {
            epw->mtn_add = 65536;
            epw->mode3++;
        }
        else
        {
            epw->ay += epw->way;
        }
        bhAddSpeed(epw, -epw->way);
        break;

    case 5:
        frm = epw->frm_no / 65536;

        epw->spd += 0.05f;
        if (epw->spd >= 1.2f)
        {
            epw->spd = 1.2f;
        }

        epw->ay += epw->way;

        if (frm == 31)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->ct0 = 0;
            epw->mode3 = 2;
            if (epw->mtn_md & 0x2)
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                epw->mtn_md |= 0x2;
            }
        }
        bhAddSpeed(epw, 0);
        break;

    case 6:
        bhEne_ChgMtn(epw, 7, 0, 5);
        epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        epw->ayp = (epw->ayp - epw->ay) & 0xFFFF;
        if (epw->ayp <= NJM_DEG_ANG(180.0f))
        {
            epw->ayp /= 32;
            epw->mtn_md |= 0x2;
        }
        else
        {
            epw->ayp = -(NJM_DEG_ANG(360.0f) - epw->ayp) / 32;
        }
        epw->ct0 = 32;
        epw->mode3++;

    case 7:
        if (epw->spd > 0.5f)
        {
            epw->spd -= 0.02f;
        }
        else
        {
            epw->spd = 0.5f;
        }

        epw->ay += epw->ayp;

        if (--epw->ct0 < 0)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->ct0 = 0;
            epw->mode3 = 2;
            if (epw->mtn_md & 0x2)
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                epw->mtn_md |= 0x2;
            }
        }
        bhAddSpeed(epw, -epw->way);
        break;
    }
}

// 100% matching!
void bhEne22_MV03(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_MV04(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 9, 0, 5);
        epw->ct0 = 30;
        epw->ct1 = 0;
        epw->ct2 = 0;
        EXP0_I(0x5C) = 0;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if (EXP0_I(0x8) & 0x10000)
        {
            EXP0_I(0x8) &= ~0x10000;
            if (frm <= 20)
            {
                EXP0_I(0x8) &= ~0x1000;
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;

                if (((*(O_WRK**)(epw->exp0 + 0x4C))->flg != 0)
                    && ((*(O_WRK**)(epw->exp0 + 0x4C))->id == 353)
                    && ((BH_PWORK*)(*(O_WRK**)(epw->exp0 + 0x4C))->lkwkp == epw))
                {
                    (*(O_WRK**)(epw->exp0 + 0x4C))->mode0 = 4;
                }

                if (EXP0_I(0x8) & 0x80000)
                {
                    rom->lgtp[2].flg &= ~0x3;
                    EXP0_I(0x8) &= ~0x80000;
                }
                break;
            }
        }

        if (epw->ct0 <= 0)
        {
            epw->ct1++;
        }
        else
        {
            epw->ct0--;
        }

        EXP0_F(0x50) = 4.0f * epw->ct1 + 24.0f;

        if ((frm >= 21) && (frm <= 60))
        {
            EXP0_I(0x8) |= 0x20000;

            if ((EXP0_F(0x20) <= EXP0_F(0x50)) && (EXP0_F(0x20) >= EXP0_F(0x50) - 8.0f)
                && ((plp->flg & 0x2) == 0) && ((plp->flg & 0x4) == 0)
                && ((plp->stflg & 0x80000000) == 0))
            {
                plp->flg |= 0x4;
                plp->mode0 = 4;
                plp->mode1 = 0;
                plp->mode2 = 0;
                plp->mode3 = 0;
                plp->hp -= 30;

                bhEne22_SetElectricShockEffect2(epw);
                bhEne22_SePlay(epw, (NJS_POINT3*)&plp->px, 0x1012302);
            }
        }
        else
        {
            EXP0_I(0x8) &= ~0x20000;
        }

        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) &= ~0x1000;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_MV05(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_MV06(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 2, 0, 7);
        epw->ct1 = 0;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 0) && (frm <= 30))
        {
            epw->ay -= NJM_DEG_ANG(3.0f);
        }

        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) |= 0x200;
            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct3 = 0;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_DGType00(BH_PWORK* epw)
{
    bhEne22_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if ((EXP0_I(0x8) & 0x30) == 0)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x10)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x20)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x30)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) |= 0x200;
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        epw->spd = 0.6f;
        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
        bhAddSpeed(epw, 0);
    }
}

// 100% matching!
void bhEne22_DG01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if ((EXP0_I(0x8) & 0x30) == 0)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
            if ((rand() % 2) == 0)
            {
                epw->mtn_md |= 0x2;
            }
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x10)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x20)
        {
            bhEne_ChgMtn(epw, 11, 0, 5);
            if ((rand() % 2) == 0)
            {
                epw->mtn_md |= 0x2;
            }
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x30)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
        }
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_DG02(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_DDType00(BH_PWORK* epw)
{
    bhEne22_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_DD00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (EXP0_I(0x8) & 0x100)
        {
            bhEne_ChgMtn(epw, 20, 0, 5);
        }
        else
        {
            bhEne_ChgMtn(epw, 19, 0, 5);
        }
        epw->spd = 0.8f;
        epw->ct0 = 0;
        epw->mode3++;

    case 1:
        if (epw->mtn_no == 20)
        {
            epw->spd -= 0.01f;
            epw->ct0++;
            if (epw->spd < 0.0f)
            {
                epw->spd = 0.0f;
            }
            bhAddSpeed(epw, 0);
        }

        if (epw->flg & 0x2000000)
        {
            epw->flg |= 0x2;
            epw->flg &= ~0x28;
            bhEne_ChgMtn(epw, 22, 0, 0);
            epw->mode3++;
        }
        break;

    case 2:
        break;
    }
}

// 100% matching!
void bhEne22_DD01(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
    NJS_VECTOR dv;

    switch (pl->mode3)
    {
    case 0:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg |= 0x200000;
        pl->frm_no = 65536;
        pl->hokan_count = 0;
        pl->hokan_rate = 49152;
        pl->mtn_add = 65536;
        pl->mtn_md = 0;
        pl->ct0 = 2;
        pl->ct1 = 0;

        dv.x = epw->px - pl->px;
        dv.y = epw->py - pl->py;
        dv.z = epw->pz - pl->pz;
        if (bhDGCdirCheck(&dv, pl->ay))
        {
            pl->mtn_no = 73;
        }
        else
        {
            pl->mtn_no = 74;
        }

        bhEne_SetVibration(1);
        bhEne_PlayerSePlay(epw, 1026);

        pl->mode3++;
        break;

    case 1:
        if ((pl->frm_no / 65536) == 0)
        {
            pl->ct0--;
            if (pl->ct0 != 0)
            {
                bhEne_SetVibration(1);
            }
        }

        if (pl->ct0 == 0)
        {
            pl->flg &= ~0x200000;
            pl->flg &= ~0x4;

            sys->pad_on &= ~0xF;

            pl->flg &= ~0x10000;
            pl->flg |= 0x8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;

            *(int*)&plp->mode0 = 1;
        }
        break;
    }
}

// 100% matching!
void bhEne22_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
    EN22_POINT2_XZ* mtn_pos[4] = {
        ply_mtn42b_pos,
        ply_mtn43b_pos,
        ply_mtn44b_pos,
        ply_mtn45b_pos
    };
    EN22_POINT2_XZ* pos_p;
    NJS_CNK_OBJECT* obj;
    O_WORK* owk;
    NJS_POINT3 key;
    NJS_VECTOR dv;
    int rot;
    int frm;
    POINT eff_pos;

    switch (pl->mode3)
    {
    case 0:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg |= 0x200000;
        pl->mnwP = epw->mnwP;
        pl->frm_no = 65536;
        pl->hokan_count = 0;
        pl->hokan_rate = 49152;
        pl->mtn_add = 65536;
        pl->mtn_md = 0;
        pl->ct0 = 0;
        pl->ct1 = 0;

        dv.x = epw->px - pl->px;
        dv.y = epw->py - pl->py;
        dv.z = epw->pz - pl->pz;
        if (bhDGCdirCheck(&dv, pl->ay))
        {
            pl->mtn_no = 31;
            pl->ayp = NJM_RAD_ANG(atan2f(-dv.x, -dv.z));
        }
        else
        {
            pl->mtn_no = 30;
            pl->ayp = NJM_RAD_ANG(atan2f(dv.x, dv.z));
            pl->ct0 = 1;
        }

        bhEne_PlayerSePlay(epw, 1026);
        bhEne_SetVibration(1);

        pl->mode3++;
        break;

    case 1:
        frm = pl->frm_no / 65536;
        if (frm < 10)
        {
            rot = (pl->ayp - pl->ay) & 0xFFFF;
            if (rot > NJM_DEG_ANG(180.0f))
            {
                rot -= NJM_DEG_ANG(360.0f);
            }
            pl->ay += rot / 2;
        }

        if ((frm >= 6) && (frm <= 18) && ((frm % 3) == 0))
        {
            owk = pl->mlwP->owP;
            owk += 1;
            eff_pos.px = owk->mtx[12];
            eff_pos.py = owk->mtx[13];
            eff_pos.pz = owk->mtx[14];
            eff_pos.ox = eff_pos.oy = eff_pos.oz = 0.0f;
            bhSetEffect(108, &eff_pos, NULL, 15);
            bhSetWaterSplash2(pl, (NJS_POINT3*)&eff_pos.px, 1, 2.0f, 2.0f, 2.0f);
        }

        if (frm == 0)
        {
            if (pl->mtn_no == 31)
            {
                pl->mtn_no = 33;
            }
            else
            {
                pl->mtn_no = 32;
            }
            pl->mode3++;
        }
        break;

    case 2:
        frm = pl->frm_no / 65536;
        if (frm == 0)
        {
            obj = pl->mlwP->objP;
            obj->pos[0] = obj->pos[2] = 0.0f;
            pl->flg &= ~0x200000;
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->flg |= 0x8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->mnwP = pl->mnwPb;
            *(int*)&plp->mode0 = 1;
            pl->flg &= ~0x4;
        }
        break;
    }

    if ((pl->mode0 == 4) || (pl->mode0 == 6))
    {
        pos_p = mtn_pos[pl->mtn_no - 30];
        frm = pl->frm_no / 65536;
        pos_p += frm;
        key.x = pos_p->px;
        key.y = 0.0f;
        key.z = pos_p->pz;
        njUnitMatrix(NULL);
        njTranslate(NULL, pl->px, pl->py, pl->pz);
        njRotateXYZ(NULL, pl->ax, pl->ay, pl->az);
        njCalcPoint(NULL, &key, (NJS_POINT3*)&pl->px);
    }
}

// 100% matching!
int bhEne22_SetMtn(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* obj;
    int frm;
    int ret;

    if (EXP0_I(0x8) & 0x80)
    {
        return 0;
    }

    frm = epw->frm_no / 65536;
    ret = bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    if (ret != 0)
    {
        epw->flg |= 0x2000000;
    }
    else
    {
        epw->flg &= ~0x2000000;
    }

    if (EXP0_I(0x8) & 0x20000000)
    {
        obj = epw->mlwP->objP;
        obj->pos[0] = obj->pos[2] = 0.0f;
        bhEne22_GetTranslateMtn(epw, frm);
    }

    if ((epw->mode0 < 5) && (epw->stflg & 0x100000))
    {
        bhEne22_SetWaterEffect(epw, epw->mtn_no, frm);
    }

    if (epw->mtn_no == 9)
    {
        bhEne22_SparkEffect(epw, frm);
    }

    bhEne22_CheckMtnTbl(epw, frm);

    return ret;
}

// 100% matching!
void bhEne22_CheckMtnTbl(BH_PWORK* epw, int frm)
{
    EN22_MTN_WORK* mtbl = &en22_mtn_tbl[0];
    int i;

    if (sys->rmthp == epw->mnwP)
    {
        return;
    }

    while (mtbl->no != -1)
    {
        if (mtbl->no == epw->mtn_no)
        {
            for (i = 0; i < 4; i++)
            {
                if (mtbl->atb[i].frm == -1)
                {
                    break;
                }

                if (mtbl->atb[i].frm == frm)
                {
                    bhEne22_SePlay(epw, (NJS_POINT3*)&epw->px, mtbl->atb[i].act);
                }
            }
        }
        mtbl++;
    }
}

// 100% matching!
void bhEne22_GetTranslateMtn(BH_PWORK* epw, int frm)
{
    NJS_POINT3 pos;
    NJS_MKEY_F_MOD* mkfP;
    MN_WORK* mnwP; // Not from DWARF

    mnwP = &epw->mnwP[epw->mtn_no];
    mkfP = (NJS_MKEY_F_MOD*)mnwP->md2P->p[0] + frm;

    if ((epw->mtn_add != 0) || ((epw->frm_no / 65536) != frm))
    {
        if (frm == 0)
        {
            if (EXP0_I(0x8) & 0x40000000)
            {
                pos.x = mkfP->key[0] - EXP0_F(0x3C);
                pos.y = 0.0f;
                pos.z = mkfP->key[2] - EXP0_F(0x44);
            }
            else
            {
                pos.x = mkfP->key[0];
                pos.y = 0.0f;
                pos.z = mkfP->key[2];
            }
        }
        else
        {
            pos.x = mkfP->key[0] - EXP0_F(0x3C);
            pos.y = 0.0f;
            pos.z = mkfP->key[2] - EXP0_F(0x44);
        }

        if (epw->mtn_md & 0x2)
        {
            pos.x *= -1.0f;
        }

        EXP0_F(0x3C) = mkfP->key[0];
        EXP0_F(0x40) = mkfP->key[1];
        EXP0_F(0x44) = mkfP->key[2];

        njUnitMatrix(NULL);
        njTranslate(NULL, epw->px, epw->py, epw->pz);
        njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
        njCalcPoint(NULL, &pos, (NJS_POINT3*)&epw->px);
    }
}

// 100% matching!
void bhEne22_SparkEffect(BH_PWORK* epw, int frm)
{
    static unsigned int ene22_eff_col[20] = {
        0x60B2B2FF,
        0xC0B2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xFFB2B2FF,
        0xE0B2B2FF,
        0xC0B2B2FF,
        0xAFB2B2FF,
        0x80B2B2FF,
        0x60B2B2FF,
        0x40B2B2FF,
        0x20B2B2FF
    };
    static unsigned int* ulpMatAdrTbl[6][40][2];
    NJS_CNK_OBJECT* obj;
    NJS_POINT3 ps = {0.0f, 10.0f, 0.0f};
    unsigned int* argb;
    int i, j;
    int no;

    if (frm == 0)
    {
        for (j = 0; j < 6; j++)
        {
            obj = epw->mdl[j + 1].objP + 1;
            argb = (unsigned int*)(epw->exp0 + 0x60);
            for (i = 0; i < 20; argb++, i++)
            {
                *argb = 0xB2B2B2;
                bhEne22_ChgDengekiColor(obj, 4 * i, *argb);
                bhEne22_ChgDengekiColor(obj, 4 * i + 1, *argb);
            }
        }

        for (j = 0; j < 6; j++)
        {
            obj = epw->mdl[j + 1].objP + 1;
            for (i = 0; i < 20; i++)
            {
                no = (2 * i + 20) % 40;
                ulpMatAdrTbl[j][no][0] = bhEne22_GetDengekiColorAddr(obj, no);
                ulpMatAdrTbl[j][no][1] = bhEne22_GetDengekiColorAddr(obj, no + 1);
            }
        }

        EXP0_I(0x18) = 0;
        *(O_WRK**)(epw->exp0 + 0x4C) = NULL;
    }
    else if ((frm >= 30) && (frm < 70))
    {
        for (j = 0; j < 6; j++)
        {
            argb = (unsigned int*)(epw->exp0 + 0x60);
            for (i = 0; i < 20; argb++, i++)
            {
                if (i <= EXP0_I(0x18))
                {
                    if (EXP0_I(0x18) - i < 20)
                    {
                        *argb = ene22_eff_col[EXP0_I(0x18) - i];
                    }
                    else
                    {
                        *argb = 0xB2B2FF;
                    }
                }
                else
                {
                    *argb = 0xB2B2FF;
                }
            }
        }

        EXP0_I(0x18)++;

        for (j = 0; j < 6; j++)
        {
            argb = (unsigned int*)(epw->exp0 + 0x60);
            for (i = 0; i < 20; argb++, i++)
            {
                no = (2 * i + 20) % 40;
                *ulpMatAdrTbl[j][no][0] = *argb;
                *ulpMatAdrTbl[j][no][1] = *argb;
            }
        }

        bhEne22_SetDengekiEffect2(epw);
    }

    if ((frm >= 11) && (frm < 55))
    {
        if ((frm % 2) == 0)
        {
            bhEne22_SetElectricShockEffect(epw, 0);
        }

        if (frm == 21)
        {
            bhEne22_SetElectricShockEffect(epw, 2);
        }
    }

    if (frm == 11)
    {
        *(O_WRK**)(epw->exp0 + 0x4C) = bhEne22_SetElectricLightEffect(epw);
        bhEne22_SetLight(epw, 4, &ps, 1);
        EXP0_I(0x8) |= 0x1000;
    }
}

// 100% matching!
unsigned int* bhEne22_GetDengekiColorAddr(NJS_CNK_OBJECT* objp, int no)
{
    int offset;
    short* plp;
    int max;
    short head;

    max = 0;
    plp = objp->model->plist;
    while (1)
    {
        head = *(unsigned char*)plp++;
        if ((head >= 64) && (head < 67))
        {
            offset = *plp++;
            plp += offset;
        }
        else if (head == 8)
        {
            plp++;
        }
        else if ((head >= 17) && (head < 24))
        {
            if (no == max)
            {
                plp++;
                return (unsigned int*)plp;
            }
            else
            {
                max++;
                offset = *plp++;
                plp += offset;
            }
        }
        else if ((head >= 56) && (head <= 58))
        {
            offset = *plp++;
            plp += offset;
        }
        else if (head == 255)
        {
            break;
        }
    }

    // no return 
}

// 100% matching!
void bhEne22_SetWaterEffect(BH_PWORK* epw, int mtn_no, int frm)
{
    EN22_WEFF_WORK* eff;
    EN22_WSP_WORK* eff2;
    O_WORK* owk;
    POINT eff_pos;
    float size;
    int i;

    eff = en22_weff_tbl;
    i = 0;
    while (1)
    {
        if (eff->mtn == -1) break;

        if ((eff->mtn == mtn_no) && (eff->frm == frm))
        {
            owk = epw->mlwP->owP + eff->obj;
            eff_pos.px = owk->mtx[12];
            eff_pos.py = owk->mtx[13];
            eff_pos.pz = owk->mtx[14];
            eff_pos.ox = eff_pos.oy = eff_pos.oz = 0.0f;
            bhSetEffect(108, &eff_pos, 0, 15);
        }

        eff++;
        i++;
    }

    eff2 = ene22_wsp_tbl;
    i = 0;
    while (1)
    {
        if (eff2->mtn == -1) break;

        if ((eff2->mtn == mtn_no) && (eff2->frm == frm))
        {
            size = 2.0f + njRandom();
            owk = epw->mlwP->owP + eff2->obj;
            bhSetWaterSplash2(epw, (NJS_POINT3*)&owk->mtx[12], 1, size, size, size);
        }

        eff2++;
        i++;
    }
}

// 100% matching!
int bhEne22_GetAreaNo(float px, float pz)
{
    UV_WORK trg_atari[4] = {
        { 0.0f,  0.0f, 70.0f, 70.0f},
        {70.0f,  0.0f, 70.0f, 70.0f},
        { 0.0f, 70.0f, 70.0f, 70.0f},
        {70.0f, 70.0f, 70.0f, 70.0f}
    };
    UV_WORK* at;
    int i;

    at = trg_atari;
    for (i = 0; i < 4; at++, i++)
    {
        if (bhEne_PosCheck(px, pz, at->u, at->v, at->xs, at->ys) != 0)
        {
            return i;
        }
    }

    return -1;
}

// 100% matching!
int bhEne22_AreaCheck(float ene_x, float ene_z, float ply_x, float ply_z)
{
    int ene_at, ply_at;

    ene_at = bhEne22_GetAreaNo(ene_x, ene_z);
    ply_at = bhEne22_GetAreaNo(ply_x, ply_z);

    return (ene_at == ply_at) ? 1 : 0;
}

// 100% matching!
int bhEne22_SetTrgPos(BH_PWORK* epw)
{
    UV_WORK trg_atari[4] = {
        {30.0f, 30.0f, 40.0f, 40.0f},
        {70.0f, 30.0f, 40.0f, 40.0f},
        {30.0f, 70.0f, 40.0f, 40.0f},
        {70.0f, 70.0f, 40.0f, 40.0f}
    };
    UV_WORK* at;
    NJS_POINT3 epos, pos;
    float near_dist, dist;
    int ene_at, ply_at;
    int i;
    float x, z; // Not from DWARF

    near_dist = 0.0f;
    at = trg_atari;
    ene_at = bhEne22_GetAreaNo(epw->px, epw->pz);
    ply_at = bhEne22_GetAreaNo(plp->px, plp->pz);

    if (ene_at == -1)
    {
        return 0;
    }

    epos.x = epw->px;
    epos.y = epw->py;
    epos.z = epw->pz;

    for (i = 0; i < 4; at++, i++)
    {
        if ((i != ene_at) && (i != ply_at))
        {
            pos.x = at->u + at->xs / 2.0f;
            pos.y = epw->py;
            pos.z = at->v + at->ys / 2.0f;

            dist = njDistanceP2P(&pos, &epos);
            if ((near_dist > dist) || (near_dist == 0.0f))
            {
                near_dist = dist;
                x = pos.x;
                z = pos.z;
            }
        }
    }

    if (near_dist != -1.0f)
    {
        EXP0_F(0x24) = x;
        EXP0_F(0x2C) = z;
        return 1;
    }

    return 0;
}

// 100% matching!
void bhEne22_SePlay(BH_PWORK* epw, NJS_POINT3* ps, int no)
{
    if ((epw->flg & 0x10000) == 0)
    {
        RequestEnemySe(sys->enow, ps, no);
    }
}

// 100% matching!
O_WRK* bhEne22_SetDengekiEffect(BH_PWORK* epw, int obj, NJS_POINT3* ofs, float size)
{
    int eno;

    sys->ef.id = 354;
    sys->ef.flg = 0x1;
    sys->ef.type = 0;
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = size;
    sys->ef.ay = 0;

    if (obj == -1)
    {
        sys->ef.px = ofs->x;
        sys->ef.py = ofs->y;
        sys->ef.pz = ofs->z;
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    else
    {
        sys->ef.px = 0.0f;
        sys->ef.py = 0.0f;
        sys->ef.pz = 0.0f;
        eno = bhSetEffectTb(&sys->ef, ofs, (unsigned char*)epw, obj);
    }

    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = 6;
        eff[eno].ct3 = 0;
        eff[eno].zn = 1.5f;

        return &eff[eno];
    }
    else
    {
        return NULL;
    }
}

// 100% matching!
void bhEne22_SetDengekiEffect2(BH_PWORK* epw)
{
    int eno;
    int i;
    int ang;

    sys->ef.id = 364;
    sys->ef.type = 1;
    sys->ef.flg = 0x1;
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    sys->ef.ax = 0;
    sys->ef.ay = 0;
    sys->ef.px = epw->px + epw->aox;
    sys->ef.pz = epw->pz + epw->aoz;
    sys->ef.py = epw->py + 4.5f;
    sys->ef.mdlver = 1;

    ang = epw->ay + (rand() % 2) * NJM_DEG_ANG(22.5f);
    for (i = 0; i < 8; i++)
    {
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if ((eno != -1) || (eno < 512))
        {
            eff[eno].stflg |= 0x20;
            eff[eno].tex_id = 0;
            eff[eno].mlwP = &epw->mdl[(rand() % 6) + 1];
            eff[eno].txp[0] = eff[eno].mlwP->texP;
            eff[eno].flr_no = 0;
            eff[eno].ax = 0;
            eff[eno].ay = ang & 0xFFFF;
            eff[eno].az = 0;

            ang += NJM_DEG_ANG(45.0f);
        }
    }
}

// 100% matching!
void bhEne22_SetElectricShockEffect(BH_PWORK* epw, int type)
{
    static EN22_DEN_WORK en22_den_tbl[20] = {
        { 2,  0, {0.0f, 0.0f, 1.0f}},
        { 3,  0, {0.0f, 1.0f, 0.0f}},
        { 4,  0, {0.0f, 1.0f, 0.0f}},
        { 5,  0, {0.0f, 0.0f, 0.0f}},
        { 6,  0, {0.0f, 0.0f, 0.0f}},
        {26,  4, {0.0f, 0.0f, 0.0f}},
        {27, 12, {0.0f, 0.0f, 0.0f}},
        {28, 20, {0.0f, 0.0f, 0.0f}},
        {29, 28, {0.0f, 0.0f, 0.0f}},
        {34,  6, {0.0f, 0.0f, 0.0f}},
        {35, 14, {0.0f, 0.0f, 0.0f}},
        {36, 22, {0.0f, 0.0f, 0.0f}},
        {37, 30, {0.0f, 0.0f, 0.0f}},
        {12,  6, {0.0f, 0.0f, 0.0f}},
        {13, 14, {0.0f, 0.0f, 0.0f}},
        {14, 20, {0.0f, 0.0f, 0.0f}},
        {19,  4, {0.0f, 0.0f, 0.0f}},
        {20, 12, {0.0f, 0.0f, 0.0f}},
        {21, 20, {0.0f, 0.0f, 0.0f}},
        {-1,  0, {0.0f, 0.0f, 0.0f}}
    };
    EN22_DEN_WORK* eff_tbl;
    O_WRK* op;
    NJS_POINT3 ps;
    int i;

    if (type == 0)
    {
        eff_tbl = &en22_den_tbl[rand() % 5];

        ps.x = eff_tbl->ofs.x + 6.0 * njRandom() - 3.0f;
        ps.y = eff_tbl->ofs.y;
        ps.z = eff_tbl->ofs.z;

        bhEne22_SetDengekiEffect(epw, eff_tbl->obj, &ps, 2.0f * njRandom() + 6.0f);
    }
    else if (type == 1)
    {
        for (i = 0; i < 4; i++)
        {
            eff_tbl = &en22_den_tbl[rand() % 2];

            ps.x = eff_tbl->ofs.x + 6.0 * njRandom() - 3.0f;
            ps.y = eff_tbl->ofs.y;
            ps.z = eff_tbl->ofs.z;

            op = bhEne22_SetDengekiEffect(epw, eff_tbl->obj, &ps, 2.0f * njRandom() + 6.0f);
            if (op != NULL)
            {
                op->ct3 = 2 * i;
            }
        }
    }
    else if (type == 2)
    {
        eff_tbl = &en22_den_tbl[5];
        i = 0;
        while (1)
        {
            if (eff_tbl->obj == -1)
            {
                break;
            }

            op = bhEne22_SetDengekiEffect(epw, eff_tbl->obj, &eff_tbl->ofs, 5.0f);
            if (op != NULL)
            {
                op->ct3 = eff_tbl->wait;
            }

            eff_tbl++;
            i++;
        }
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            eff_tbl = &en22_den_tbl[rand() % 5];

            ps.x = eff_tbl->ofs.x + 6.0 * njRandom() - 3.0f;
            ps.y = eff_tbl->ofs.y;
            ps.z = eff_tbl->ofs.z;

            op = bhEne22_SetDengekiEffect(epw, eff_tbl->obj, &ps, 2.0f * njRandom() + 6.0f);
            if (op != NULL)
            {
                op->ct3 = 2 * i;
            }
        }
    }
}

// 100% matching!
void bhEne22_SetElectricShockEffect2(BH_PWORK* epw)
{
    int obj[4] = {
        1, 1, 2, 3
    };
    float ply_ofs[4] = {
        -3.0f, 0.0f, 0.0f, 1.0f
    };
    O_WRK* op;
    NJS_POINT3 ps;
    int i;

    for (i = 0; i < 4; i++)
    {
        ps.y = ply_ofs[i];
        ps.x = njRandom() - 0.5;
        ps.z = njRandom() - 0.5;

        op = bhEne22_SetDengekiEffect(plp, obj[i], &ps, 7.0f);
        if (op != NULL)
        {
            op->txp[0] = epw->mlwP->texP;
            op->ct3 = 4 * i;
        }
    }
}

// 100% matching!
O_WRK* bhEne22_SetElectricLightEffect(BH_PWORK* epw)
{
    NJS_POINT3 ofs = {
        0.0f, 0.1f, -5.0f
    };
    int eno;

    sys->ef.id = 353;
    sys->ef.flg = 0x1;
    sys->ef.type = 0;
    sys->ef.sx = 25.0f;
    sys->ef.sy = 25.0f;
    sys->ef.sz = 25.0f;
    sys->ef.ay = 0;
    sys->ef.px = 0.0f;
    sys->ef.py = 0.0f;
    sys->ef.pz = 0.0f;

    eno = bhSetEffectTb(&sys->ef, &ofs, (unsigned char*)epw, 0);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = 5;
        eff[eno].ct3 = 0;
        return &eff[eno];
    }
    else
    {
        return NULL;
    }
}

// 100% matching!
void bhEne22_SetLight(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int type)
{
    LGT_WORK* lp;

    lp = rom->lgtp + 2;

    EXP0_I(0x8) |= 0x80000;

    lp->flg = 0x3;
    lp->aspd = 4;
    lp->lsrc = 4;
    lp->type = 0;
    lp->r = 0.0f;
    lp->g = 0.0f;
    lp->b = 0.0f;
    lp->nr = 20.0f;
    lp->fr = 40.0f;
    lp->light = NULL;

    if (lnk_obj == -1) {
        lp->lkflg = 0;
        lp->lkno = 0;
        lp->lkono = 0;
        lp->px = ofs->x;
        lp->py = ofs->y;
        lp->pz = ofs->z;
    }
    else {
        lp->lkflg = 0x2;
        lp->lkno = epw->idx_ct;
        lp->lkono = 3;
        lp->lx = ofs->x;
        lp->ly = ofs->y;
        lp->lz = ofs->z;
        lp->px = 0.0f;
        lp->py = 0.0f;
        lp->pz = 0.0f;
    }

    if (type == 0) {
        lp->mode = 0;
    }
    else {
        lp->mode = 2;
    }
}

// 100% matching!
void bhEne22_CtrLight(BH_PWORK* epw)
{
    float rgb[3] = {
        1.0f, 1.0f, 6.375f
    };
    LGT_WORK* lp;
    float fl;

    if (EXP0_I(0x8) & 0x80000)
    {
        lp = rom->lgtp + 2;
        if ((lp->flg & 0x1) && (lp->flg & 0x2))
        {
            switch (lp->mode)
            {
            case 0:
                lp->ct0 = 0;
                lp->ct1 = 16;
                lp->aspd = 8;
                lp->mode++;

            case 1:
                fl = njSin(lp->ct0);
                lp->r = fl * rgb[0];
                lp->g = fl * rgb[1];
                lp->b = fl * rgb[2];
                lp->ct0 = (lp->ct0 + 256 * lp->aspd) & 0x7FFF;
                if (--lp->ct1 < 0)
                {
                    lp->flg &= ~0x3;
                    EXP0_I(0x8) &= ~0x80000;
                }
                break;

            case 2:
                lp->aspd = 4;
                lp->ct0 = 0;
                lp->ct1 = 16;
                lp->mode++;

            case 3:
                fl = njSin(lp->ct0);
                lp->r = fl * rgb[0];
                lp->g = fl * rgb[1];
                lp->b = fl * rgb[2];
                lp->ct0 = (lp->ct0 + 256 * lp->aspd) & 0x7FFF;
                if (--lp->ct1 < 0)
                {
                    lp->mode++;
                    lp->ct1 = 4;
                }
                break;

            case 4:
                if (--lp->ct1 < 0)
                {
                    lp->mode++;
                    lp->ct1 = 22;
                }

            case 5:
                lp->nr += 0.8f;
                lp->fr += 4.0f;
                if (--lp->ct1 < 0)
                {
                    lp->mode++;
                    lp->ct1 = 15;
                }
                break;

            case 6:
                fl = njSin(lp->ct0);
                lp->r = fl * rgb[0];
                lp->g = fl * rgb[1];
                lp->b = fl * rgb[2];
                lp->ct0 = (lp->ct0 + 256 * lp->aspd) & 0x7FFF;
                if (--lp->ct1 < 0)
                {
                    lp->flg &= ~0x3;
                    EXP0_I(0x8) &= ~0x80000;
                }
                break;
            }
        }
    }
}

// 100% matching!
void bhEne22_ChgDengekiColor(NJS_CNK_OBJECT* objp, int no, unsigned int argb)
{
    int offset;
    short* plp;
    unsigned char* mat;
    int max;
    short head;
    unsigned char a;
    unsigned char r;
    unsigned char g;
    unsigned char b;

    a = (argb & 0xFF000000) >> 0x18;
    r = (argb & 0xFF0000) >> 0x10;
    g = (argb & 0xFF00) >> 0x8;
    b = argb & 0xFF;
    plp = objp->model->plist;
    max = 0;

    while (1)
    {
        head = *(unsigned char*)plp++;
        if ((head >= 64) && (head < 67))
        {
            offset = *plp++;
            plp += offset;
        }
        else if (head == 8)
        {
            plp++;
        }
        else if ((head >= 17) && (head < 24))
        {
            if (no == max)
            {
                plp++;
                mat = (unsigned char*)plp;
                switch (head)
                {
                case 17:
                case 21:
                    *mat++ = b;
                    *mat++ = g;
                    *mat++ = r;
                    *mat++ = a;
                    break;

                case 19:
                case 23:
                    *mat++ = b;
                    *mat++ = g;
                    *mat++ = r;
                    *mat++ = a;
                    *mat++ = b;
                    *mat++ = g;
                    *mat++ = r;
                    *mat++ = a;
                    break;
                }
                return;
            }
            else
            {
                max++;
                offset = *plp++;
                plp += offset;
            }
        }
        else if ((head >= 56) && (head <= 58))
        {
            offset = *plp++;
            plp += offset;
        }
        else if (head == 255)
        {
            return;
        }
    }
}
