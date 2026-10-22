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
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Black Widow 

#pragma divbyzerocheck on 

NJS_POINT3 spm_016[45] =
{
    { 0.0f,             0.0f,           0.0f },
    { 0.0f,    -0.218743995f,           0.0f },
    { 0.0f,     -0.26177001f,           0.0f },
    { 0.0f,    -0.283394009f,           0.0f },
    { 0.0f,    -0.283618003f,           0.0f },
    { 0.0f,    -0.262441009f,           0.0f },
    { 0.0f,    -0.219705999f,           0.0f },
    { 0.0f,     0.537151992f, -0.0567060001f },
    { 0.0f,     0.950820029f, -0.0633549988f },
    { 0.0f,     0.462606013f, -0.0712549984f },
    { 0.0f,     0.289056987f, -0.0788789988f },
    { 0.0f,     0.259640008f, -0.0861949995f },
    { 0.0f,     0.227210999f, -0.0931779966f },
    { 0.0f,     0.180557996f, -0.0997989997f },
    { 0.0f,     0.126130998f,  -0.106032997f },
    { 0.0f,     0.128854007f,  -0.111854002f },
    { 0.0f,     0.181151003f,  -0.117241003f },
    { 0.0f,     0.132466003f,  -0.122172996f },
    { 0.0f,    0.0634640008f,  -0.126628995f },
    { 0.0f,    0.0191810001f,  -0.130595997f },
    { 0.0f, -0.000353999989f,  -0.134051993f },
    { 0.0f,   0.00609100005f,  -0.136989996f },
    { 0.0f,    0.0735360011f,  -0.139393002f },
    { 0.0f,    0.0920139998f,  -0.141257003f },
    { 0.0f,    0.0102890003f,  -0.142570004f },
    { 0.0f,   -0.0898019969f,  -0.143329993f },
    { 0.0f,    -0.125242993f,  -0.206928998f },
    { 0.0f,    -0.160959005f,  -0.470672011f },
    { 0.0f,    -0.197161004f,  -0.469761014f },
    { 0.0f,    -0.233820006f,  -0.468297005f },
    { 0.0f,    -0.291278005f,   -0.46628499f },
    { 0.0f,    -0.333431005f,  -0.463735998f },
    { 0.0f,    -0.308402002f,  -0.460655004f },
    { 0.0f,     -0.25276199f,  -0.457060993f },
    { 0.0f,    -0.226135999f,  -0.452955991f },
    { 0.0f,    -0.215074003f,   -0.44837001f },
    { 0.0f,    -0.266965002f,  -0.501981974f },
    { 0.0f,    -0.387537003f,  -0.263983011f },
    { 0.0f,    -0.568105996f,  -0.222800002f },
    { 0.0f,    -0.956220984f,  -0.176549003f },
    { 0.0f,     -1.12237203f,  -0.126333997f },
    { 0.0f,    -0.834299982f, -0.0733570009f },
    { 0.0f,    -0.609296978f, -0.0188759994f },
    { 0.0f,    -0.450051993f,  0.0358089991f },
    { 0.0f,    -0.356626987f,  0.0893910006f }
};
NJS_POINT3 spm_023[25] = 
{
    { 0.0f,           0.0f,             0.0f },
    { 0.0f,   0.224094003f,    -0.125722006f },
    { 0.0f,   0.981598973f,    -0.273948997f },
    { 0.0f,    2.12025094f,    -0.204677001f },
    { 0.0f,    2.59201503f,     0.103661999f },
    { 0.0f,    1.87202299f,     0.563848972f },
    { 0.0f,   0.737565994f,     0.995473027f },
    { 0.0f, 0.00721199997f,        1.204216f },
    { 0.0f,  -0.587921977f,      1.12663901f },
    { 0.0f,  -0.884258986f,     0.848743975f },
    { 0.0f,  -0.827269971f,     0.509276986f },
    { 0.0f,  -0.459913999f,     0.189154997f },
    { 0.0f,     -0.119617f,    0.0278840009f },
    { 0.0f, -0.0057359999f,    0.0189759992f },
    { 0.0f,  0.0569400005f,    0.0112309996f },
    { 0.0f,  0.0684129968f,   0.00464700023f },
    { 0.0f,   0.185518995f, -0.000774000015f },
    { 0.0f,   0.156975999f,  -0.00503499992f },
    { 0.0f, -0.0356190018f,  -0.00813299976f },
    { 0.0f, -0.0849379972f,   -0.0100689996f },
    { 0.0f,  -0.101379998f,   -0.0108430004f },
    { 0.0f, -0.0849379972f,   -0.0104569998f },
    { 0.0f, -0.0356200002f,   -0.0089069996f },
    { 0.0f,           0.0f,  -0.00619600015f },
    { 0.0f,           0.0f,       -0.002324f }
};
NJS_POINT3 spm_026[16] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,    0.30459401f,  -1.17761803f },
    { 0.0f,   0.844596028f,  -1.61228299f },
    { 0.0f,    1.18923604f,    -2.095191f },
    { 0.0f,    1.14049196f,  -2.58198094f },
    { 0.0f,   0.903213024f,  -2.77993989f },
    { 0.0f, -0.0704019964f,  -1.82634902f },
    { 0.0f,     -0.180464f, -0.808885992f },
    { 0.0f,   0.594169021f, -0.379321009f },
    { 0.0f,  -0.137284994f, -0.686769009f },
    { 0.0f,   0.586520016f,  -2.03712106f },
    { 0.0f,   -1.14873302f,  -2.89061999f },
    { 0.0f,   -1.01687205f,  -3.97540689f },
    { 0.0f,   -1.09641302f,  -3.57847905f },
    { 0.0f,   -1.72937405f, -0.468986988f },
    { 0.0f,  -0.183275998f, -0.220272005f }
};
NJS_POINT3 spm_028[13] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,  -0.151141003f, 0.0439810008f },
    { 0.0f,     -0.316551f, 0.0733029991f },
    { 0.0f,  -0.276656002f, 0.0146599999f },
    { 0.0f, -0.0314540006f, -0.131944001f },
    { 0.0f,   0.250993013f,  -0.27502501f },
    { 0.0f,      0.392113f, -0.341735989f },
    { 0.0f,   0.470683008f, -0.387134999f },
    { 0.0f,   0.486701995f, -0.411226004f },
    { 0.0f,   0.440171003f, -0.414005011f },
    { 0.0f,   0.331088006f, -0.395476013f },
    { 0.0f,   0.159455001f, -0.355636001f },
    { 0.0f, -0.0862509981f, -0.348071992f }
};
NJS_POINT3 spm_029[20] = 
{
    { 0.0f,           0.0f,           0.0f },
    { 0.0f,  -0.393936992f,  -0.350028008f },
    { 0.0f,  -0.526373029f,  -0.362201005f },
    { 0.0f,  -0.617738008f,  -0.370819002f },
    { 0.0f,  -0.668031991f,  -0.375883013f },
    { 0.0f,  -0.677253008f,  -0.377393007f },
    { 0.0f,  -0.645403981f,  -0.375348002f },
    { 0.0f,   -0.57248199f,  -0.369747996f },
    { 0.0f,  -0.458487004f,  -0.360596001f },
    { 0.0f,  -0.303422004f,  -0.347887009f },
    { 0.0f,  -0.148374006f,  -0.331624001f },
    { 0.0f, -0.0359250009f,  -0.311807007f },
    { 0.0f,  0.0537150018f,  -0.288435996f },
    { 0.0f,   0.120548002f,  -0.261510015f },
    { 0.0f,   0.164574996f,  -0.231029004f },
    { 0.0f,   0.185794994f,  -0.196994007f },
    { 0.0f,   0.184208006f,  -0.159407005f },
    { 0.0f,      0.159814f,  -0.118261002f },
    { 0.0f,   0.112613998f, -0.0735640004f },
    { 0.0f,  0.0426059999f, -0.0253110006f }
};
NJS_POINT3 spmh_026[16] = 
{
    { 0.0f,          0.0f,          0.0f },
    { 0.0f,  0.203879997f,   1.05717099f },
    { 0.0f,  0.607263982f,   1.96484005f },
    { 0.0f,  0.976207018f,   1.15935194f },
    { 0.0f,     1.159971f,   2.03937006f },
    { 0.0f,  0.946618974f,   3.05633402f },
    { 0.0f,  0.392645001f,   2.22015095f },
    { 0.0f,  0.428660005f,   1.87996101f },
    { 0.0f, -0.874442995f,  0.907414019f },
    { 0.0f,  0.206529006f,     1.272668f },
    { 0.0f,  0.258655995f,   1.68754995f },
    { 0.0f, -0.430880994f,   3.26340199f },
    { 0.0f,  -1.18263304f,    -1.137707f },
    { 0.0f,  -1.22665501f, -0.229169995f },
    { 0.0f,  -1.02153397f,  0.262127012f },
    { 0.0f, -0.444285005f, -0.108080998f }
};
NJS_POINT3 spmh_013[10] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,  -0.242614999f, -0.224384993f },
    { 0.0f,  -0.404422998f, -0.304396003f },
    { 0.0f, -0.0810950026f, -0.374191999f },
    { 0.0f,    0.72736901f, -0.433775991f },
    { 0.0f,    1.38212895f, -0.483148009f },
    { 0.0f,    1.51324797f, -0.522302985f },
    { 0.0f,    1.57458794f, -0.530400991f },
    { 0.0f,    1.56615698f, -0.546994984f },
    { 0.0f,    1.48794401f, -0.618399024f }
};
NJS_POINT3 spmh_015[30] = 
{
    { 0.0f,           0.0f,           0.0f },
    { 0.0f,    1.12219799f,  -0.925270021f },
    { 0.0f,   0.860957026f,   -1.11558104f },
    { 0.0f,   0.615898013f,      -1.17758f },
    { 0.0f,   0.389692008f,   -1.01981294f },
    { 0.0f,   0.125657007f,  -0.875569999f },
    { 0.0f,      -0.19438f,  -0.744898021f },
    { 0.0f,  -0.510737002f,  -0.627790987f },
    { 0.0f,  -0.775402009f,  -0.524253011f },
    { 0.0f,  -0.988370001f,  -0.434282988f },
    { 0.0f,   -1.14964795f,  -0.357879996f },
    { 0.0f,   -1.25923097f,  -0.295046002f },
    { 0.0f,   -1.31712306f,  -0.245778993f },
    { 0.0f,   -1.32331705f,  -0.210078999f },
    { 0.0f,   -3.11279607f,  -0.187948003f },
    { 0.0f,   -2.46084905f,  -0.163435996f },
    { 0.0f,   0.801108003f,  -0.129717007f },
    { 0.0f,   0.968285978f,  -0.099326998f },
    { 0.0f,   0.263590008f, -0.0722640008f },
    { 0.0f,   0.144869998f, -0.0485250019f },
    { 0.0f,  0.0444109999f, -0.0281119999f },
    { 0.0f, -0.0377870016f, -0.0110309999f },
    { 0.0f,  -0.101727001f, 0.00272800005f },
    { 0.0f,  -0.147406995f,  0.0131569998f },
    { 0.0f,  -0.174825996f,  0.0202600006f },
    { 0.0f,  -0.183984995f,      0.024038f },
    { 0.0f,  -0.174886003f,  0.0244859997f },
    { 0.0f,  -0.147525996f,  0.0216090009f },
    { 0.0f,  -0.101906002f,  0.0154050002f },
    { 0.0f, -0.0380269997f,  0.0058749998f }
};

static int ENE03_HITPOINT[4][16] = 
{
    { 130, 130, 130, 130, 130, 150, 150, 150, 150, 150, 150, 180, 180, 180, 180, 180 },
    {  50,  50,  50,  50,  50,  70,  70,  70,  70,  70,  70,  90,  90,  90,  90,  90 },
    {  90,  90,  90,  90,  90, 110, 110, 110, 130, 130, 130, 130, 130, 150, 150, 150 },
    {  30,  30,  30,  30,  30,  50,  50,  50,  60,  60,  60,  60,  60,  70,  70,  70 }
};
static char spider_tree[5][6] = 
{
    {  0, -1,  0,  0,  0,  0 },
    {  0,  1,  7,  8,  9, -1 },
    {  0,  1, 25, 26, 27, -1 },
    {  0,  1, 10, 11, 12, -1 },
    {  0,  1, 28, 29, 30, -1 }
};
static char SdwTab[6] = 
{
    1, 12, 30, 9, 27, -1
};
static char flip_tree[37] = 
{
     0,  1,  2,  5,  6,  3,  4, 10,
    11, 12,  7,  8,  9, 16, 17, 18,
    13, 14, 15, 22, 23, 24, 19, 20,
    21, 28, 29, 30, 25, 26, 27, 33,
    34, 31, 32, 36, 35
};
static ETTY_WORK ene03_child = 
{
    0x8001, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static char BrokenParts[8] = 
{
    10, 16, 22, 28, 7, 13, 19, 25
};
static ETTY_WORK ene24 =
{
    0x8001, 24, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static ETTY_WORK ene03_leader = 
{
    0x4008001, 3, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static BP_WORK BloodParam = 
{
    { 0.0f, 0.1f, 0.0f }, 0, 0.0f, 0.07f, { 0.4f, 0.1f, 0.4f, 0.3f, 0.2f }, { 0, 3, 6, 9, 12 }
};
static BLOOD_TBL BloodTbl[37] = 
{
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 3.0f,  0.0f }, 2.0f, 0.0f, 2.0f },
    { 1, {  0.0f, 6.0f,  8.0f }, 3.0f, 0.0f, 4.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f }
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
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  4, { 1, 0, 0 }, 30, 20 },
    { 10, { 4, 3, 1 }, 20, 10 },
    { 10, { 4, 3, 1 }, 20, 10 },
    { 10, { 4, 3, 1 }, 10,  0 },
    {  0, { 0, 0, 0 }, 25,  0 },
    {  0, { 0, 0, 0 }, 25,  0 },
    { 25, { 5, 3, 1 },  5,  0 },
    {  0, { 0, 0, 0 }, 60,  0 },
    {  0, { 0, 0, 0 }, 10,  0 },
    {  0, { 0, 0, 0 }, 30,  0 },
    { 25, { 5, 4, 2 }, 10,  0 },
    {  0, { 0, 0, 0 }, 60,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    { 15, { 1, 1, 1 },  5,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 }
};
static COMBJOINT_WORK CombJointTbl[37] = { 0 };
static CPCL CapColTabA[23] = 
{
    {  1,  1,  16 },
    {  0,  0, -20 },
    {  1,  1,  11 },
    {  0,  0, -38 },
    {  2,  2,  30 },
    {  0, 15,  20 },
    {  7,  8,   3 },
    {  8,  9,   3 },
    { 10, 11,   3 },
    { 11, 12,   3 },
    { 13, 14,   3 },
    { 14, 15,   3 },
    { 16, 17,   3 },
    { 17, 18,   3 },
    { 19, 20,   3 },
    { 20, 21,   3 },
    { 22, 23,   3 },
    { 23, 24,   3 },
    { 25, 26,   3 },
    { 26, 27,   3 },
    { 28, 29,   3 },
    { 29, 30,   3 },
    {  0,  0,   0 }
};
static CPCL CapColTabB[21] = 
{
    {  1,  1,  16 },
    {  0,  0, -20 },
    {  1,  1,  11 },
    {  0,  0, -38 },
    {  7,  8,   3 },
    {  8,  9,   3 },
    { 10, 11,   3 },
    { 11, 12,   3 },
    { 13, 14,   3 },
    { 14, 15,   3 },
    { 16, 17,   3 },
    { 17, 18,   3 },
    { 19, 20,   3 },
    { 20, 21,   3 },
    { 22, 23,   3 },
    { 23, 24,   3 },
    { 25, 26,   3 },
    { 26, 27,   3 },
    { 28, 29,   3 },
    { 29, 30,   3 },
    {  0,  0,   0 }
};

void (*bhEne03_Mode0[6])(BH_PWORK*) = 
{
	bhEne03_Init,
	bhEne03_Move,
	bhEne03_Nage,
	bhEne03_Damage,
	bhEne03_Die,
	bhEne_Event
};
void (*bhEne03_BrainType[3])(BH_PWORK*) = 
{
	bhEne03_BR00,
	bhEne03_BR01,
	bhEne03_BR02
};
void (*bhEne03_MoveMode2[20])(BH_PWORK*) = 
{
	bhEne03_MV00,
	bhEne03_MV01,
	bhEne03_MV02,
	bhEne03_MV03,
	bhEne03_MV04,
	bhEne03_MV05,
	bhEne03_MV06,
	bhEne03_MV07,
	bhEne03_MV08,
	bhEne03_MV09,
	bhEne03_MV10,
	bhEne03_MV11,
	bhEne03_MV12,
	bhEne03_MV13,
	bhEne03_MV14,
	bhEne03_MV15,
	bhEne03_MV16,
	bhEne03_MV17,
	bhEne03_MV18,
	bhEne03_MV19
};
void (*bhEne03_NageMode2[2])(BH_PWORK*) = 
{
	bhEne03_NG00,
	bhEne03_NG01
};
void (*bhEne03_DamageMode2[13])(BH_PWORK*) = 
{
	bhEne03_DG00,
	bhEne03_DG01,
	bhEne03_DG02,
	bhEne03_DG03,
	bhEne03_DG04,
	bhEne03_DG05,
	bhEne03_DG06,
	bhEne03_DG07,
	bhEne03_DG08,
	bhEne03_DG09,
	bhEne03_DG10,
	bhEne03_DG11,
	bhEne03_DG12
};
void (*bhEne03_DeadMode2[6])(BH_PWORK*) = 
{
	bhEne03_DD00,
	bhEne03_DD01,
	bhEne03_DD02,
	bhEne03_DD03,
	bhEne03_DD04,
	bhEne03_DD05
};

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEne03(BH_PWORK* epw)
{
    NJS_POINT3 pos;   
    unsigned int flg;
    float px, py, pz; // not from DWARF

    if ((epw->flg & 0x4000000)) 
    {
        if ((EPW_EXP1_I(0) & 0x4))
        {
            bhEne03_PlayerControl(epw);
        }
        
        if (EPW_EXP1_I(8) != 0)
        {
            EPW_EXP1_I(8)--;
        }
    }
    else 
    {
        bhEne03_Mode0[epw->mode0](epw);
        
        bhEne03_CallSE(epw);
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        px = epw->px;
        py = epw->py;
        pz = epw->pz;
        
        if ((epw->flg & 0x100000)) 
        {
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->aox = pos.x - epw->px;
            epw->aoy = pos.y - epw->py;
            epw->aoz = pos.z - epw->pz;
            
            if (!(epw->flg & 0x200000)) 
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
        
        switch (EXP0_C(105))
        {
        case 0:
            epw->car = 6.0f;
            epw->cah = 6.0f;
            break;
        case 1:
            epw->car = 6.0f;
            epw->cah = 6.0f;
            
            epw->aoy -= 6.0f;
            break;
        default:
            epw->car = 6.0f;
            epw->cah = 12.0f;
            
            epw->aoy -= 6.0f;
            break;
        }
        
        if ((epw->flg & 0x8)) 
        {
            bhCheckPlayer(epw);
            
            bhEne_CheckEnemiesBall(epw);
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL)
        {
            switch (EXP0_C(105))
            {
            case 0:           
            case 1:           
                epw->py = py;
                break;
            case 2:           
            case 4:           
                epw->px = px;
                break;
            case 3:           
            case 5:           
                epw->pz = pz;
                break;
            }
        }
        
        if ((ATR_WORK*)EXP0_I(96) == NULL)
        {
            bhEne03_CollisionLine(epw);
            
            if (((epw->flg & 0x10)) && (bhEne03_CollisionWalls(epw) != 0)) 
            {
                bhEne03_CollisionLine(epw);
            }
        }
        else if ((epw->flg & 0x10)) 
        {
            bhEne03_CollisionWalls(epw);
            bhEne03_CollisionLine2(epw);
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
            bhEne_SetWeponAtr(epw, 35, 1, 5.0f);
        }
        else
        {
            bhEne_SetWeponAtr(epw, 35, 6, 5.0f);
            return;
        }
    }
}

// 100% matching!
void bhEne03_Init(BH_PWORK* epw)
{
    BH_PWORK** epw2, *ep, *ep_leader;    
    O_WORK* owk;         
    int i;              

    epw->flg |=  0x1078;
    epw->flg &= ~0x8006;
    
    epw->flg = (unsigned short)epw->flg;
    
    epw->mdflg |= 0x4;
    
    epw->ar = 6.0f;
    epw->ah = 6.0f;
    
    epw->car = 6.0f;
    epw->cah = 6.0f;
    
    epw->aox = 0;
    epw->aoy = 0;
    epw->aoz = 0;
    
    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    epw->mtn_tp = (unsigned char*)flip_tree;
    epw->mtn_md &= ~0x2;
    
    bhCalcModel(epw);
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;

    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(240, 8);
        
        ep = ene;
        
        for (i = 0; i < sys->ewk_n; i++, ep++) 
        {
            if (((ep->flg & 0x1)) && (ep->id == 3)) 
            {
                if (ep->exp1 != NULL)
                {
                    epw->exp1 = ep->exp1;
                } 
                else 
                {
                    epw->exp1 = bhEne_CallocWork(12, 8);
                }
                
                if (ep->exp2 != NULL) 
                {
                    epw->exp2 = ep->exp2;
                } 
                else 
                {
                    ep_leader = bhSetEnemy(&ene03_leader, rom->ene_n);
                    
                    epw->exp2 = (unsigned char*)ep_leader;
                    
                    ep_leader->mdflg |= 0x1;
                    ep_leader->mdflg |= 0x20;
                    
                    ep_leader->exp1 = epw->exp1;
                    
                    ep_leader->mnwP = epw->mnwP;
                }
                
                break;
            }
        }

        epw2 = (BH_PWORK**)&EXP0_C(128); 
        
        for (i = 0; i < 8; i++) 
        {
            *epw2 = bhSetEnemy(&ene03_child, rom->ene_n);
            
            (*epw2)->type = 0;
            
            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = i >= 4;
            
            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;
            
            (*epw2)->mdflg |= 0x1;
            (*epw2)->mdflg |= 0x20;
            
            owk = &epw->mlwP->owP[BrokenParts[i]];
            
            (*epw2)->mtx = &owk->mtx;
            
            (*epw2++)->exp1 = (unsigned char*)owk;
        }

        bhEne_SetCallFunc(bhEne03s, 31);
        
        epw2 = (BH_PWORK**)&EXP0_C(168);
        
        for (i = 0; i < 15; i++) 
        {
            *epw2 = bhSetEnemy(&ene24, rom->ene_n);
            
            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = 0;
            
            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;
            
            (*epw2++)->mlwP = &epw->mdl[1];
        }
    }

    EXP0_C(104) = 0;
    
    EXP0_F(64) = 999.0f;
    
    EXP0_I(68) = 0;

    EXP0_F(72) = 0;
    EXP0_F(76) = 0;
    EXP0_F(80) = 0;
    
    EXP0_I(228) = (rand() % 90) + 60;
    EXP0_I(232) = 0;

    i = rand() % 16;
    
    if (sys->gm_mode != 2) 
    {
        epw->hp     = ENE03_HITPOINT[0][i];
        EXP0_I(124) = ENE03_HITPOINT[1][i];
    } 
    else 
    {
        epw->hp     = ENE03_HITPOINT[2][i];
        EXP0_I(124) = ENE03_HITPOINT[3][i];
    }

    for (i = 0; i < 8; i++) 
    {
        ((char*)epw->exp0)[i + 160] = 0;
    }
    
    {
    int i;      
    NJS_POINT3 p; 
	int sdw;      

    epw2 = (BH_PWORK**)&EXP0_C(168);
        
    for (i = 0; i < 15; i++) 
    {
        (*epw2++)->mdflg |= 0x1;
    }

    EPW_EXP1_I(0) = 0;
    EPW_EXP1_I(8) = (rand() % 30) + 60;
        
    njUnitMatrix((NJS_MATRIX*)epw->exp0);
        
    njRotateY((NJS_MATRIX*)epw->exp0, epw->ay);

    *(ATR_WORK**)&EXP0_I(96) = NULL;
        
    if ((epw->type & 0x2))
    {
        p.x = epw->px;
        p.y = epw->py + 999.0f;
        p.z = epw->pz;
        
        if ((*(ATR_WORK**)&EXP0_I(96) = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &p)) != NULL) 
        {
            EXP0_C(105) = 1;
            
            bhEne03_MakeMatrix(epw); 
            
            epw->py = p.y;
        }
        
        epw->type &= ~0x2;
    }
    
    if ((ATR_WORK*)EXP0_I(96) == NULL) 
    {
        EXP0_C(105) = 0;
        
        *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
    }

    epw->pxb = epw->px;
    epw->pyb = epw->py;
    epw->pzb = epw->pz;
        
    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 5;
    epw->clp_jno[2] = 12;
    epw->clp_jno[3] = 30;
    epw->clp_jno[4] = 9;
    epw->clp_jno[5] = 27;
    epw->clp_jno[6] = 32;
    epw->clp_jno[7] = 34;
        
    epw->mdflg &= ~0x20;

    if (!(epw->flg & 0x800))
    {
        sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 8.0f, 8.0f, 9.0f);
        
        eff[sdw].id = 258;
        
        epw->flg |= 0x800;
    }
        
    epw->stflg &= ~0x8;

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
        bhEne03_HideParts(epw, 2, 1);
    }
        
    bhEne03_SetModelFlg(epw, -4, 0);

    if ((epw->type & 0x4)) 
    {
        epw->type &= ~0x4;
        
        epw->flg   |= 0x2000000;
        epw->stflg |= 0x8;
        
        epw->flg &= ~0x28;
    }
    }
}

// 100% matching!
void bhEne03_Brain(BH_PWORK* epw)
{
	if ((epw->flg & 0x2000000))
    {
        bhEne03_BrainType[2](epw);
    }
    else 
	{
		bhEne03_BrainType[epw->type](epw);
	}
}

// 100% matching!
void bhEne03_BR00(BH_PWORK* epw)
{
	float dist;

    EXP0_F(64) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);
    
    bhEne03_SearchPlayer(epw, 21845);
    
    if ((EXP0_UC(104) == 0) && (epw->mode2 != 4) && (EXP0_F(64) < 20.0f)) 
    {
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 4;
        epw->mode3 = 0;
    }
    
    if (plp->hp >= 0) 
    {
        if (EXP0_C(105) == 0)
        { 
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 12.0f) && (epw->mode2 != 3))
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
            
            if (((plp->stflg & 0x80000000)) || (((plp->flg & 0x4)) || ((epw->flg & 0x4))))
            {
                return;
            }
            
            if ((bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) == NULL) && (EPW_EXP1_I(8) == 0))
            {
                if ((EXP0_F(64) < 20.0f) && (abs(EXP0_I(68)) < 5461) && (fabsf(epw->py - plp->py) < 0.01f)) 
                {
                    epw->mode1 = 0;
                    epw->mode2 = 19;
                    epw->mode3 = 0;
                    
                    EPW_EXP1_I(8) = (rand() % 30) + 60;
                    return;
                }
            }
            
            if (EXP0_I(228) == 0) 
            {
                if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640)) 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 9;
                    epw->mode3 = 0;
                    
                    EXP0_I(228) = (rand() % 90) + 60;
                }
            } 
            else 
            {
                EXP0_I(228)--;
            }
        }
        else if (EXP0_C(105) == 1)
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
            
            if ((epw->py > plp->py) && (dist < 40.0f) && (abs(EXP0_I(68)) > 16384) && (bhEne03_DiveSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 11;
                epw->mode3 = 0;
            }
            
            if (EXP0_I(228) == 0) 
            {
                if ((epw->py > plp->py) && (dist < 25.0f) && (abs(EXP0_I(68)) < 3640))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 9;
                    epw->mode3 = 0;
                    
                    EXP0_I(228) = (rand() % 90) + 60;
                }
            } 
            else 
            {
                EXP0_I(228)--;
            }
        }
        else
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
            
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 12.0f) && (epw->mode2 != 3)) 
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne03_BR01(BH_PWORK* epw) 
{
    float dx, dy, dz; 
    
    dx = epw->px - plp->px;
    dy = epw->py - plp->py;
    dz = epw->pz - plp->pz;

    switch (EXP0_C(105)) 
    {
    case 0:
    case 1:
        EXP0_F(64) = njSqrt((dx * dx) + (dz * dz));
        break;
    case 2:
    case 4:
        EXP0_F(64) = njSqrt((dy * dy) + (dz * dz));
        break;
    case 3:
    case 5:
        EXP0_F(64) = njSqrt((dx * dx) + (dy * dy));
        break;
    }

    bhEne03_SearchPlayer(epw, 21845);

    if (plp->hp >= 0) 
    {
        if (EXP0_UC(104) == 1) 
        {
            if ((EXP0_F(64) > 12.0f) && (epw->mode2 != 3)) 
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
            
            if ((epw->mode2 != 4) && (EXP0_F(64) < 20.0f) && (abs(EXP0_I(68)) > 3640)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 4;
                epw->mode3 = 0;
            }
        }
        
        if (EXP0_C(105) == 0) 
        {
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 20.0f) && (bhEne03_CheckJumpSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 14;
                epw->mode3 = 0;
            }
            
            if ((((plp->stflg & 0x80000000)) || ((plp->flg & 0x4))) || ((epw->flg & 0x4))) 
            {
                return;
            }
            
            if (bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) != NULL) 
            {
                if (EXP0_I(228) == 0) 
                {
                    if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640)) 
                    {
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        epw->mode2 = 9;
                        epw->mode3 = 0;
                        
                        EXP0_I(228) = 20;
                    }
                } 
                else 
                {
                    EXP0_I(228)--;
                }
            }
            else if (EPW_EXP1_I(8) == 0) 
            {
                if ((EXP0_F(64) < 30.0f) && ((abs(EXP0_I(68)) <= 7280) && (fabsf(epw->py - plp->py) < 0.01f))) 
                {
                    epw->mode1 = 0;
                    epw->mode2 = 19;
                    epw->mode3 = 0;
                    
                    EPW_EXP1_I(8) = (rand() % 30) + 60;
                }
            }
        } 
        else if (EXP0_C(105) == 1)
        {
            if ((epw->py > plp->py) && (EXP0_F(64) < 40.0f) && (bhEne03_DiveSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 11;
                epw->mode3 = 0;
            }
        } 
        else if ((EXP0_UC(104) == 1) && (EXP0_F(36) > 0) && (bhEne03_CheckJumpSpace(epw) != 0)) 
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 15;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne03_BR02(BH_PWORK* epw)
{
    EXP0_F(64) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);

    bhEne03_SearchPlayer(epw, 21845);

    EXP0_C(104) = 1;

    if (EXP0_I(228) == 0)
    {
        if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;

            EXP0_I(228) = (rand() % 90) + 60;
        }
    }
    else
    {
        EXP0_I(228)--;
    }
}

// 100% matching!
void bhEne03_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne03_Brain(epw);
    }

    if (((epw->flg & 0x4)) && (!(epw->flg & 0x2)))
    {
        bhEne03_DamageInit(epw);
    }

    if (epw->mode0 == 1)
    {
        bhEne03_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne03_MV00(BH_PWORK* epw) 
{
    static unsigned char action_table[2][6] = 
	{
		{ 1,  1,  2, 2, 0, 0 },
		{ 1, 17, 17, 2, 0, 0 }
	};

    switch (epw->mode3) 
    {                     
    case 0:
        if (epw->type == 0)
        {
            if (epw->mtn_no != 0) 
            {
                epw->mtn_no = 0;
                epw->frm_no = 0;
                
                epw->hokan_count = 10;
                epw->hokan_rate  = 32768;
            }
        } 
        else if (epw->mtn_no != 30) 
        {
            epw->mtn_no = 30;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }
        
        epw->ct0 = (rand() % 63) + 40;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = action_table[epw->type][rand() % 4];
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV01(BH_PWORK* epw)
{
	NJS_POINT3 pos;

    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0)
        {
            if (epw->mtn_no != 1) 
            {
                if ((epw->mtn_no != 6) && (epw->mtn_no != 7))
                {
                    epw->frm_no = 0;
                }
                
                epw->mtn_no = 1;
                
                epw->hokan_count = 10;
                epw->hokan_rate  = 32768;
            }
        } 
        else if (epw->mtn_no != 31) 
        {
            epw->mtn_no = 31;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }

        epw->ct0 = rand() % 47;

        if (EXP0_UC(104) == 1) 
        {
            epw->ct1 = (EXP0_I(68) < 0) ? -1 : 1;
        } 
        else
        {
            epw->ct1 = ((-rand() / -2.1474836E9f) < 0.5f) ? -1 : 1;
        }

        epw->spd = 0.4f;
        
        epw->mode3++;
    case 1:
        bhEne03_GoAHead(epw);

        if (EXP0_I(232) == 0) 
        {
            if (bhEne03_CheckClimbWall(epw) != 0) 
            {
                epw->mode1 = 0;
                epw->mode2 = 6;
                epw->mode3 = 0;
                break;
            }
            
            if (bhEne03_CheckClimbDownWall(epw) != 0) 
            {
                epw->mode1 = 0;
                epw->mode2 = 8;
                epw->mode3 = 0;
                break;
            }
        }
        else 
        {
            EXP0_I(232)--;
        }

        bhEne03_AvoidWall(epw, epw->ct1);

        if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) != 0xFF) 
        {
            EXP0_F(72) = pos.x;
            EXP0_F(80) = pos.z;
        } 
        else
        {
            EXP0_F(72) = plp->px;
            EXP0_F(80) = plp->pz;
        }

        if (EXP0_UC(104) == 1)
        {
            epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&EXP0_F(72), 819);
            
            njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);
        }

        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV02(BH_PWORK* epw)
{
	int dir;
	
    dir = (rand() % 63) & 1;

    switch (epw->mode3)                              
    {
    case 0:
        if (epw->mtn_no != (dir + 6))
        {
            epw->mtn_no = dir + 6;
            epw->frm_no = 0;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }

        epw->ct0 = rand() % 63;

        epw->ayp = ((dir != 0) ? 1 : -1) * 819;

        epw->mode3++;
    case 1:
        njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne03_MV03(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0) 
        {
            if (epw->mtn_no != 4) 
            {
                epw->mtn_no = 4;
                epw->frm_no = 0;
                
                epw->hokan_count = 10;
                epw->hokan_rate  = 32768;
                
                epw->spd = 0.6f;
            }
            
            epw->ct0 = (rand() % 60) + 30;
        }
        else 
        {
            if (epw->mtn_no != 40) 
            {
                epw->mtn_no = 40;
                epw->frm_no = 0;
                
                epw->hokan_count = 10;
                epw->hokan_rate  = 32768;
                
                epw->spd = 0.8f;
            }
            
            epw->ct0 = (rand() % 60) + 90;
        }

        epw->ct1 = (EXP0_I(68) < 0) ? -1 : 1;
        
        epw->mode3++;
    case 1:
        bhEne03_GoAHead(epw);

        if (EXP0_I(232) == 0) 
        {
            if (bhEne03_CheckClimbWall(epw) != 0)
            {
                epw->mode1 = 0;
                epw->mode2 = 6;
                epw->mode3 = 0;
                break;
            }
            
            if (bhEne03_CheckClimbDownWall(epw) != 0) 
            {
                epw->mode1 = 0;
                epw->mode2 = 8;
                epw->mode3 = 0;
                break;
            }
        } 
        else 
        {
            EXP0_I(232)--;
        }

        if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) != 0xFF) 
        {
            EXP0_F(72) = pos.x;
            EXP0_F(80) = pos.z;
            
            epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&EXP0_F(72), 819);
            
            njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);
        } 
        else 
        {
            EXP0_F(72) = plp->px;
            EXP0_F(80) = plp->pz;
            
            if (bhEne03_AvoidWall(epw, epw->ct1) == 0) 
            {
                epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&EXP0_F(72), 819);
                
                njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);
            }
        }

        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        
        return;
    }
}

// 100% matching!
void bhEne03_MV04(BH_PWORK* epw)
{
	int wang;
	
    switch (epw->mode3)                         
    {
    case 0:
		wang = bhEne03_DirTarget(epw, (NJS_POINT3*)&plp->px, 32768) < 0;

        epw->mtn_no = wang + 6;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->ct0 = rand() % 31;

        epw->mode3++;
    case 1:
        epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&plp->px, 819);

        njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

        if ((epw->ct0-- == 0) || (abs(epw->ayp) < 273))
        {
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne03_MV05(BH_PWORK* epw)
{
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0) 
        {
            epw->mtn_no = 2;
        }
        else 
        {
            epw->mtn_no = 32;
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x10;
        
        epw->flg  |= 0x1800000;
        epw->flg  |= 0x300000;
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_POINT3*)&epw->px);
            
            njRotateX((NJS_MATRIX*)epw->exp0, 16384);

            switch (EXP0_C(106))
            {     
            case 0:
                hp = (ATR_WORK*)EXP0_I(100);    
                
                if (hp->type == 0)
                {
                    h = hp->h;
                    
                    if (h == 0)
                    {
                        h = rom->h;
                    }
                    
                    epw->py = hp->py + h;
                } 
                else 
                {
                    epw->py = hp->py;
                }
                
                break;
            case 1:
                if (((ATR_WORK*)EXP0_I(100))->type == 0) 
                {
                    epw->py = ((ATR_WORK*)EXP0_I(100))->py;
                } 
                else 
                {
                    epw->py = ((ATR_WORK*)EXP0_I(100))->py + ((ATR_WORK*)EXP0_I(100))->h;
                }
                
                break;
            case 5:
                epw->pz = ((ATR_WORK*)EXP0_I(100))->pz + ((ATR_WORK*)EXP0_I(100))->d;
                break;
            case 3:
                epw->pz = ((ATR_WORK*)EXP0_I(100))->pz;
                break;
            case 4:
                epw->px = ((ATR_WORK*)EXP0_I(100))->px;
                break;
            case 2:
                epw->px = ((ATR_WORK*)EXP0_I(100))->px + ((ATR_WORK*)EXP0_I(100))->w;
                break;
            }

            EXP0_C(105) = EXP0_C(106); 
            
            bhEne03_MakeMatrix(epw);
            
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
            
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 1;
            
            epw->mtn_no = 1;
            
            epw->ct0 = 10;
            
            epw->spd = 0.4f;
            
            bhEne03_GoAHead(epw);
            
            epw->flg |= 0x30;
            
            EPW_EXP1_I(0) &= ~0x2;
            
            epw->flg &= ~0x80000;
            
            EXP0_I(96) = EXP0_I(100);      

            if (EXP0_C(105) == 0)
            {        
                epw->flg2 &= ~0x1;
            } 
            else 
            {
                epw->flg2 |=  0x1;
            }
            
            EXP0_I(232) = 20;            
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV06(BH_PWORK* epw)
{
    NJS_VECTOR ov; 
	float out;   
    
    switch (epw->mode3) 
    {
    case 0:
        EPW_EXP1_I(0) |= 0x2;
        
        epw->flg |= 0x80000;

        if (epw->mtn_no != 1) 
        {
            epw->mtn_no = 1;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }
        
        epw->ct0 = 12;
        
        epw->mode3++;
    case 1:
        if (epw->ct0 != 0) 
        {
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(32), (NJS_VECTOR*)&EXP0_I(108), &ov);

            if (njInnerProduct((NJS_VECTOR*)&EXP0_I(16), &ov) > 0)
            {
                epw->ayp =  (int)(10430.381f * asinf(out)) / epw->ct0;
            } 
            else
            {
                epw->ayp = -(int)(10430.381f * asinf(out)) / epw->ct0;
            }
            
            njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

            epw->px += (EXP0_F(72) - epw->px) / epw->ct0;
            epw->py += (EXP0_F(76) - epw->py) / epw->ct0;
            epw->pz += (EXP0_F(80) - epw->pz) / epw->ct0;

            epw->ct0--;
            break;
        }

        epw->mode1 = 0;
        epw->mode2 = 5;
        epw->mode3 = 0;
        
        if ((EXP0_C(105) == 0) && (epw->type == 1)) 
        {
            epw->mode2 = 18;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV07(BH_PWORK* epw) 
{
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0)
        {
            epw->mtn_no = 3;
        }
        else 
        {
            epw->mtn_no = 33;
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x10;
        
        epw->flg  |= 0x1800000;
        epw->flg  |= 0x300000;
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_POINT3*)&epw->px);
            
            njRotateX((NJS_MATRIX*)epw->exp0, -16384);

            switch (EXP0_C(106)) 
            {
            case 0:
                hp = (ATR_WORK*)EXP0_I(100);
                
                if (hp->type == 0) 
                {
                    h = hp->h;
                    
                    if (h == 0)
                    {
                        h = rom->h;
                    }
                    
                    epw->py = hp->py + h;
                } 
                else 
                {
                    epw->py = hp->py;
                }
                
                break;
            case 1:
                if (((ATR_WORK*)EXP0_I(100))->type == 0) 
                {
                    epw->py = ((ATR_WORK*)EXP0_I(100))->py;
                } 
                else 
                {
                    epw->py = ((ATR_WORK*)EXP0_I(100))->py + ((ATR_WORK*)EXP0_I(100))->h;
                }
                
                break;
            case 5:
                epw->pz = ((ATR_WORK*)EXP0_I(100))->pz + ((ATR_WORK*)EXP0_I(100))->d;
                break;
            case 3:
                epw->pz = ((ATR_WORK*)EXP0_I(100))->pz;
                break;
            case 4:
                epw->px = ((ATR_WORK*)EXP0_I(100))->px;
                break;
            case 2:
                epw->px = ((ATR_WORK*)EXP0_I(100))->px + ((ATR_WORK*)EXP0_I(100))->w;
                break;
            }

            epw->pxb = epw->px;
            epw->pyb = epw->py;
            epw->pzb = epw->pz;

            EXP0_C(105) = EXP0_C(106); 
            
            bhEne03_MakeMatrix(epw);
            
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
            
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 1;
            
            epw->mtn_no = 1;
            
            epw->ct0 = 10;
            
            epw->spd = 0.4f;
            
            bhEne03_GoAHead(epw);
            
            epw->flg |= 0x30;
            
            EPW_EXP1_I(0) &= ~0x2;
            
            epw->flg &= ~0x80000;
            
            EXP0_I(96) = EXP0_I(100);      

            if (EXP0_C(105) == 0)
            {        
                epw->flg2 &= ~0x1;
            } 
            else 
            {
                epw->flg2 |=  0x1;
            }
            
            EXP0_I(232) = 20;   
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV08(BH_PWORK* epw)
{
    NJS_VECTOR vd, ov; 
	float out;     

    switch (epw->mode3)
    {
    case 0:
        EPW_EXP1_I(0) |= 0x2;
        
        epw->flg |= 0x80000;

        if (epw->mtn_no != 1) 
        {
            epw->mtn_no = 1;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }
        
        epw->ct0 = 12;
        
        epw->mode3++;
    case 1:
        if (epw->ct0 != 0) 
        {
            vd.x = -EXP0_F(32);
            vd.y = -EXP0_F(36);
            vd.z = -EXP0_F(40);

            out = njOuterProduct(&vd, (NJS_VECTOR*)&EXP0_I(108), &ov);

            if (njInnerProduct((NJS_VECTOR*)&EXP0_I(16), &ov) > 0)
            {
                epw->ayp =  (int)(10430.381f * asinf(out)) / epw->ct0;
            } 
            else 
            {
                epw->ayp = -(int)(10430.381f * asinf(out)) / epw->ct0;
            }
            
            njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

            epw->px += (EXP0_F(72) - epw->px) / epw->ct0;
            epw->py += (EXP0_F(76) - epw->py) / epw->ct0;
            epw->pz += (EXP0_F(80) - epw->pz) / epw->ct0;

            epw->ct0--;
            break;
        }

        epw->mode1 = 0;
        epw->mode2 = 7;
        epw->mode3 = 0;
        break;
    }
}

// 100% matching!
void bhEne03_MV09(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0)
        { 
            epw->mtn_no = 11; 
        }
        else 
        { 
            epw->mtn_no = 57; 
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            if (epw->type == 0) 
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            } 
            else
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 0;
                epw->mode3 = 0;
            }
        }

        if (epw->type == 0) 
        {
            if ((epw->frm_no >= 2818048) && (epw->frm_no <= 3014656)) 
            {
                bhEne03_Acid(epw, 0);
            }
        }
        else if (((epw->frm_no >= 983040) && (epw->frm_no <= 1179648)) || ((epw->frm_no >= 1441792) && (epw->frm_no <= 1638400)) || ((epw->frm_no >= 1835008) && (epw->frm_no <= 1966080)))
        {
            bhEne03_Acid(epw, 0);
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 12;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

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

        if ((epw->frm_no >= 3407872) && (epw->frm_no <= 3604480))
        {
            bhEne03_Acid(epw, 1);
        }

        break;
    }
}

// 100% matching!
void bhEne03_MV11(BH_PWORK* epw)
{
	NJS_POINT3 pos;
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 13;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        EXP0_F(84) = 0;
        EXP0_F(88) = -5.0f;
        EXP0_F(92) = 0;

        epw->flg |= 0x1800000;
        
        EPW_EXP1_I(0) |= 0x1;
        
        epw->flg &= ~0x20;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;

            epw->mtn_no = 14;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->mode3++;

            EXP0_C(105) = 0;
            
            njRotateY((NJS_MATRIX*)epw->exp0, 32768);
            
            bhEne03_MakeMatrix(epw);
            
            epw->flg |= 0x20;
        }
        
        break;
    case 2:
        hp = (ATR_WORK*)EXP0_I(96);
        
        if (hp != NULL) 
        {
            epw->flg &= ~0x1800000;
            
            epw->mtn_no = 15;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            epw->mode3++;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

            hp = (ATR_WORK*)EXP0_I(96);
            
            if (hp->type == 7) 
            {
                epw->py = hp->py;
                break;
            }
            
            h = hp->h;
            
            if (h == 0)
            {
                h = rom->h;
            }
            
            epw->py = hp->py + h;
            break;
        }
        
        epw->py += EXP0_F(88);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 3:
        if (epw->ct0-- == 0) 
        {
            EPW_EXP1_I(0) &= ~0x1;
            
            epw->mtn_no = 0;
            epw->frm_no = 0;
            
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg2 &= ~0x1;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV12()
{

}

// 100% matching!
void bhEne03_MV13()
{

}

// 100% matching!
void bhEne03_MV14(BH_PWORK* epw) 
{
    NJS_VECTOR v = { 0.0f, 3.0f, -1.3f };
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 41;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        
        epw->mode3++;
    case 1:
        epw->ct0--;
        
        if ((epw->frm_no / 65536) == 12) 
        {
            njCalcVector((NJS_MATRIX*)epw->exp0, &v, (NJS_VECTOR*)&EXP0_F(84));
            
            *(ATR_WORK**)&EXP0_I(96) = NULL;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_add = 0;
            
            epw->mode3++;
        }
    case 3:
        if (EXP0_F(88) < 0)
        {
            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 8;
            epw->hokan_rate  = 45875;
            
            epw->mtn_add = 0;
            
            epw->mode3++;
        }
    case 4:
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;

            hp = (ATR_WORK*)EXP0_I(96);
            
            if (hp->type == 7) 
            {
                epw->py = hp->py;
            } 
            else 
            {
                h = hp->h;
                
                if (h == 0)
                {
                    h = rom->h;
                }
                
                epw->py = hp->py + h;
            }
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3 = 5;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 5:
        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV15(BH_PWORK* epw)
{
    NJS_VECTOR vwork = { 0.0f, 0.8f, 0.0f }, ov;
	float out;           
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 41;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if ((epw->frm_no / 65536) == 12)
        {
            njCalcVector((NJS_MATRIX*)epw->exp0, &vwork, (NJS_VECTOR*)&EXP0_F(84));
            
            *(ATR_WORK**)&EXP0_I(96) = NULL;
            
            EXP0_I(108) = 0;
            EXP0_F(112) = 1.0f; 
            EXP0_I(116) = 0;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 48;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            epw->mode3++;
        }
    case 3:
        out = njOuterProduct((NJS_VECTOR*)&EXP0_F(16), (NJS_VECTOR*)&EXP0_F(108), &ov);
        
        if (out > 0)
        {
            njUnitVector(&ov);
            njUnitMatrix(NULL);
            
            njRotate(NULL, &ov, (int)(10430.381f * asinf(out)) / 8);
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }

        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);

            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;

            hp = (ATR_WORK*)EXP0_I(96);   
            
            if (hp->type == 7) 
            {
                epw->py = hp->py;
            } 
            else 
            {
                h = hp->h;
                
                if (h == 0)
                {
                    h = rom->h;
                }
                
                epw->py = hp->py + h;
            }

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3 = 4;
            break;
        }

        epw->px += EXP0_F(84);  
        epw->py += EXP0_F(88);           
        epw->pz += EXP0_F(92);   
        
        EXP0_F(88) -= 0.33f;
        break;
    case 4:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg2 &= ~0x1;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV16(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 47;
        epw->frm_no = 0;
        
        epw->hokan_count = 3;
        epw->hokan_rate  = 32768;

        EXP0_F(84) = 0;
        EXP0_F(88) = -1.0f;
        EXP0_F(92) = 0;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 8;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_add = 0;
            
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);
        }

        if (epw->ct1 > 0) 
        {
            epw->ct1--;
            
            njRotateX((NJS_MATRIX*)epw->exp0, 4004);
        }

        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->mtn_add = 65536;
            
            epw->flg2 &= ~0x1;
            break;
        }
        
        epw->py += EXP0_F(88);
        
        EXP0_F(88) -= 0.33f;
        break;
    }
}

// 100% matching!
void bhEne03_MV17(BH_PWORK* epw)
{
	NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 37;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = rand() % 47;
        
        epw->mode3++;
        
        epw->spd = 0.6f;

        if (EXP0_UC(104) == 1) 
        {  
            epw->ct1 = (EXP0_I(68) < 0) ? -1 : 1;
        }
        else 
        {
            epw->ct1 = ((-rand() / -2.1474836E9f) < 0.5f) ? -1 : 1;
        }
    case 1:
        bhEne03_GoAHead(epw);

        if (bhEne03_CheckClimbWall(epw) != 0) 
        {
            epw->mode1 = 0;
            epw->mode2 = 6;
            epw->mode3 = 0;
            break;
        }
        
        if (bhEne03_CheckClimbDownWall(epw) != 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 8;
            epw->mode3 = 0;
            break;
        }

        if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) != 0xFF) 
        {
            EXP0_F(72) = pos.x;
            EXP0_F(80) = pos.z;
        } 
        else 
        {
            EXP0_F(72) = plp->px;
            EXP0_F(80) = plp->pz;
        }

        if ((bhEne03_AvoidWall(epw, epw->ct1) == 0) && (EXP0_UC(104) == 1)) 
        {
            epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&EXP0_F(72), 1547);
            
            njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV18(BH_PWORK* epw) 
{
    NJS_VECTOR v, ov;
    float out;   

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 41;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg2 |= 0x1;
        
        epw->mode3++;
        break;
    case 1:
        if ((epw->frm_no / 65536) == 12) 
        {
            v.x = 0;
            v.y = 3.0f;  
            v.z = -0.9f;  

            njCalcVector((NJS_MATRIX*)epw->exp0, &v, (NJS_VECTOR*)&EXP0_F(84));

            epw->flg &= ~0x10;
            
            *(ATR_WORK**)&EXP0_I(96) = NULL;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->frm_no == 0)
        {
            epw->mtn_no = 48;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            epw->ct0 = 9;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        out = njOuterProduct((NJS_VECTOR*)&EXP0_F(16), (NJS_VECTOR*)&EXP0_F(108), &ov);
        
        if (out > 0) 
        {
            njUnitVector(&ov);
            njUnitMatrix(NULL);
            
            njRotate(NULL, &ov, (int)(10430.381f * asinf(out)) / 8);
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }

        if (epw->ct0-- == 0) 
        {
            EXP0_I(96) = EXP0_I(100);

            EXP0_C(105) = EXP0_C(106);

            bhEne03_MakeMatrix(epw);

            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3 = 4;
            break;
        }

        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 4:
        if (epw->ct0-- == 0) 
        {
            epw->flg |= 0x30;
            
            EPW_EXP1_I(0) &= ~0x2;
            
            epw->flg &= ~0x80000;
            
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            EXP0_I(232) = 20;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_MV19(BH_PWORK* epw)
{
    float dist;   
    NJS_POINT3 p1, p2;
    
    switch (epw->mode3) 
    {
    case 0:
        if (epw->type == 0)
        {
            epw->mtn_no = 28;
        }
        else 
        {
            epw->mtn_no = 43;
        }
        
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->mtn_add = 65536;
        
        epw->ar = 0.1f;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->type == 0) 
        {
            bhEne03_AddNullTrans(epw, spm_028);
        }
        else
        {
            bhEne03_AddNullTrans(epw, spmh_013);
        }

        if (epw->frm_no == 0) 
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne03_GetPartsPos(epw, spider_tree[0], &p1);
            
            p2.x = plp->px;
            p2.y = 10.0f + plp->py;
            p2.z = plp->pz;

            if (epw->type == 0) 
            {
                if ((bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) == NULL) && (dist < 10.0f) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 9102) != 0) && (fabsf(epw->py - plp->py) < 0.01f) && (bhCollisionCheckLine(&p1, &p2) == NULL)) 
                {
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    
                    bhEne03_Nage(epw);
                    break;
                }
                
                epw->mtn_no = 29;
                
                epw->mode3++;
                break;
            }

            if ((bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) == NULL) && (dist < 20.0f) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 5461) != 0) && (fabsf(epw->py - plp->py) < 0.01f) && (bhCollisionCheckLine(&p1, &p2) == NULL)) 
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 1;
                epw->mode3 = 0;
                
                bhEne03_Nage(epw);
                break;
            }
            
            epw->mtn_no = 45;
            
            *(ATR_WORK**)&EXP0_I(96) = NULL;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->type == 0)
        {
            bhEne03_AddNullTrans(epw, spm_029);
        } 
        else 
        {
            bhEne03_AddNullTrans(epw, spmh_015);
        }
        
        epw->ar += (6.0f - epw->ar) / 16.0f;

        if (epw->frm_no == 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
            
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->ar = 6.0f;
            
            if (epw->type == 1) 
            {
                *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_Nage(BH_PWORK* epw)
{
	bhEne03_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne03_NG00(BH_PWORK* epw) 
{
	NJS_POINT3 trg_pos[4][2] = 
	{
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		}
	};
    NJS_POINT3 pos;            

    switch (epw->mode3) 
    {                               
    case 0:
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        
        EPW_EXP1_I(0) |= 0x4;
        
        plp->flg   |= 0x10004;
        plp->stflg |= 0x10000;
        
        plp->mode0 = 4;
        plp->mode3 = 0;
        
        if (abs((short)(epw->ayp - plp->ay)) < 16384) 
        {
            plp->mode2 = 1;
            
            plp->ayp = epw->ayp;
        } 
        else
        {
            plp->mode2 = 0;
            
            plp->ayp = (short)(epw->ayp + 32768);
        }
        
        epw->mtn_no = 8;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x60;
        epw->flg |=  0x100000;
        epw->flg &= ~0x200000;
        
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 0;
        epw->ct2 = 6;
        
        epw->mode3++;
    case 1:
        epw->ct1 += bhEne_LeverCheck();
        
        if ((epw->ct0-- == 0) || (epw->ct1 > 30)) 
        {
            epw->mtn_no = 9;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        epw->ct1 += bhEne_LeverCheck();
        
        if (epw->frm_no == 0)
        {
            if (plp->hp < 0) 
            {
                plp->mode0 = 6;
                
                if (plp->mode2 == 0) 
                {
                    plp->mode2 = 0;
                } 
                else 
                {
                    plp->mode2 = 1;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 25;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->mode3 = 4;
                return;
            }
            
            epw->ct0++;
            
            if ((epw->ct0 == 3) || (epw->ct1 > 30)) 
            {
                if (plp->mode2 == 0) 
                {
                    plp->mode2 = 4;
                }
                else 
                {
                    plp->mode2 = 5;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 10;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                
                epw->mode3++;
                return;
            }
        }
        
        if ((epw->frm_no / 65536) == 19) 
        {
            plp->hp -= 12;
            
            if (plp->hp < 0) 
            {
                plp->stflg |= 0x40000;
            }
            
            plp->dvx = -njSin(epw->ay);
            plp->dvy = -1.0f;
            plp->dvz = -njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        break;
    case 3:
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 & 0x1], &pos);
        
        epw->px = plp->px - pos.x;
        epw->pz = plp->pz - pos.z;
        
        if (epw->ct0-- == 0) 
        {
            epw->flg |= 0x20;
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            epw->mtn_no = 0;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->px = pos.x;
            epw->pz = pos.z;
            
            epw->flg  |=  0x60;
            epw->flg2 &= ~0x1;
            
            epw->ar = 6.0f;
            
            EPW_EXP1_I(8) += 30;
        }
        
        break;
    case 4:
        if (epw->frm_no == 0) 
        {
            epw->frm_no = 2031616;
            
            plp->flg |= 0x2;
        }
        
        if (((epw->frm_no / 65536) == 32) || ((epw->frm_no / 65536) == 51)) 
        {
            plp->dvx = njSin(epw->ay);
            plp->dvy = -2.0f;
            plp->dvz = njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2], &pos);
        
        plp->px = epw->px + pos.x;
        plp->pz = epw->pz + pos.z;
        break;
    }

    if ((epw->mode3 == 1) || (epw->mode3 == 2))
    {
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 & 0x1], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct2 > 0)
        {
            epw->px += (epw->xn - epw->px) / epw->ct2;
            epw->pz += (epw->zn - epw->pz) / epw->ct2;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            njRotateY((NJS_MATRIX*)epw->exp0, (short)(epw->ayp - epw->ay) / epw->ct2);
            
            epw->ct2--;
        }
        else
        {
            epw->px = epw->xn;
            epw->pz = epw->zn;
        }
    }
}

// 100% matching!
void bhEne03_NG01(BH_PWORK* epw)
{
	NJS_POINT3 trg_pos[4][2] = 
	{
		{
			{ 0.063656f, -0.090291f, -12.650927f },
			{ 0.063656f, -0.090291f, -11.614147f }
		},
		{
			{ 0.063656f, -0.090291f, -13.150927f },
			{ 0.063656f, -0.090291f, -12.114147f }
		},
		{
			{ 0.063656f, -0.090291f, -12.650927f },
			{ 0.063656f, -0.090291f, -11.614147f }
		},
		{
			{ 0.063656f, -0.090291f, -13.150927f },
			{ 0.063656f, -0.090291f, -12.114147f }
		}
	};     
    NJS_POINT3 pos;

    switch (epw->mode3) 
    {                               
    case 0:
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        
        EPW_EXP1_I(0) |= 0x4;
        
        plp->flg   |= 0x10004;
        plp->stflg |= 0x10000;
        
        plp->mode0 = 4;
        plp->mode3 = 0;
        
        if (abs((short)(epw->ayp - plp->ay)) < 16384) 
        {
            plp->mode2 = 3;
            
            plp->ayp = epw->ayp;
        } 
        else
        {
            plp->mode2 = 2;
            
            plp->ayp = (short)(epw->ayp + 32768);
        }
        
        epw->mtn_no = 44;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x60;
        epw->flg |=  0x100000;
        epw->flg &= ~0x200000;
        
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 0;
        epw->ct2 = 6;

        epw->stflg |= 0x8;
        
        epw->mode3++;
    case 1:
        epw->ct1 += bhEne_LeverCheck();
        
        if (epw->ct0-- == 0)
        {
            epw->stflg &= ~0x8;
            
            if (plp->hp < 0) 
            {
                plp->mode0 = 6;
                
                if (plp->mode2 == 2) 
                {
                    plp->mode2 = 2;
                } 
                else 
                {
                    plp->mode2 = 3;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 55;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->mode3 = 3;
            } 
            else 
            {
                epw->mtn_no = 46;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                
                epw->mode3++;
            }
            
            return;
        }

        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct2 > 0) 
        {
            epw->px += (epw->xn - epw->px) / epw->ct2;
            epw->pz += (epw->zn - epw->pz) / epw->ct2;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            njRotateY((NJS_MATRIX*)epw->exp0, (short)(epw->ayp - epw->ay) / epw->ct2);
            
            epw->ct2--;
        } 
        else
        {
            epw->px = epw->xn;
            epw->pz = epw->zn;
        }
        
        if ((epw->frm_no == 720896) || (epw->frm_no == 1900544) || (epw->frm_no == 3342336))
        {
            plp->dvx = -njSin(epw->ay);
            plp->dvy = -0.5f;
            plp->dvz = -njCos(epw->ay);
            
            if (epw->ct1 > 30) 
            {
                plp->hp -= 5;
                
                bhEne_SetBloodEffectBurst(plp, 5, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            }
            else 
            {
                plp->hp -= 12;
                
                bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            }

            if (plp->hp < 0) 
            {
                plp->stflg |= 0x40000;
            }
            
            StartVibrationEx(1, 9);
        }
        
        break;
    case 2:
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct0-- == 0) 
        {
            epw->flg |= 0x20;
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->px = pos.x;
            epw->pz = pos.z;

            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->hokan_count = 0;
            
            epw->flg  |=  0x60;
            epw->flg2 &= ~0x1;
            
            epw->ar = 6.0f;

            epw->flg &= ~0x100000;
            
            EPW_EXP1_I(8) += 20;
        }
        
        break;
    case 3:
        if (epw->frm_no == 0) 
        {
            epw->frm_no = 11206656;
        }

        if (epw->frm_no == 3932160) 
        {
            plp->flg |= 0x2;
        }
        
        if (((epw->frm_no / 65536) == 183) || ((epw->frm_no / 65536) == 194) || ((epw->frm_no / 65536) == 210)) 
        {
            plp->dvx = njSin(epw->ay);
            plp->dvy = -2.0f;
            plp->dvz = njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        plp->px = epw->px + pos.x;
        plp->pz = epw->pz + pos.z;
        break;
    }
}

// 100% matching!
void bhEne03_Damage(BH_PWORK* epw)
{
    if ((epw->flg & 0x4))
    {
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
            if (epw->type == 0) 
            {
                if ((epw->comb_flg & 0x8)) 
                {
                    EXP0_I(124) -= epw->total_dam;
                } 
                else 
                {
                    if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8))) 
                    {
                        EXP0_I(124) -= epw->total_dam;
                    }
                    
                    epw->hp -= epw->total_dam;
                }
            } 
            else
            {
                epw->hp -= epw->total_dam;
            }
            
            if ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4))) 
            {
                bhEne03_HitMark(epw);
            } 
        }
    }
    
    bhEne03_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne03_DG00()
{

}

// 100% matching!
void bhEne03_DG01(BH_PWORK* epw)
{
	switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 20;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG02(BH_PWORK* epw)
{
    NJS_MKEY* mkfP;     
    NJS_POINT3 trans;    
	NJS_MKEY_A_MOD* mkaP;

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;
        
        epw->mtn_add = 65536;

        EXP0_F(84) = 0;
        EXP0_F(88) = -1.0f;
        EXP0_F(92) = 0;

        EXP0_C(105) = 0;
        
        bhEne03_MakeMatrix(epw);

        njRotateY((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;

        epw->mtn_md |= 0x100;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ar = 0.1f;
        
        epw->mode3++;
    case 1:
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            epw->mtn_no = 18;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            epw->hokan_rate  = 0;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
        } 
        else 
        {
            epw->py += EXP0_F(88);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            epw->hokan_rate  = 0;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        bhEne03_AddNullTrans(epw, spm_016);
        
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DG03(BH_PWORK* epw)
{
	switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 19;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG04(BH_PWORK* epw) 
{
    int i;        
    NJS_POINT3 pos; 
    O_WORK* owk;    

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 22;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 0;
        
        epw->mode3++;

        owk = &epw->mlwP->owP[2];
        
        pos.x = 0;
        pos.y = 3.0f;
        pos.z = 4.0f;
        
        njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, &pos);
        
        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);
        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 1);
        bhEne_SetBloodstain(epw, 1, 2, NULL);

        for (i = 0; i < 6; i++) 
        {
            owk = &epw->mlwP->owP[2];
            
            pos.x =         (4.0f * (-rand() / -2147483648.0f))  - 2.0f;
            pos.y = (3.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            pos.z = (4.0f + (6.0f * (-rand() / -2147483648.0f))) - 3.0f;
            
            njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, (NJS_POINT3*)&epw->dpx);
            
            bhEne_SetMinceEffect2(epw, 258, 0.3f, 1);
            bhEne_SetMinceEffect2(epw, 259, 0.3f, 1);
        }

        epw->type = 1;
        
        epw->cpcl = CapColTabB;
        
        bhEne03_HideParts(epw, 2, 1);
        
        bhEne_EraseArrow(epw, 2);
    case 1:
        if (epw->ct1 < 4) 
        {
            owk = &epw->mlwP->owP[2];
            
            pos.x =         (6.0f * (-rand() / -2147483648.0f))  - 3.0f;
            pos.y = (3.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            pos.z = (4.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            
            njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, &pos);
            
            bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);
            
            epw->ct1++;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DG05()
{

}

// 100% matching!
void bhEne03_DG06(BH_PWORK* epw)
{
    switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 52;
        epw->frm_no = 0;

        epw->hokan_count = 4;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG07(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {                            
    case 0:                                         
        epw->mtn_no = 50;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->mtn_add = 0;
        
        EXP0_F(84) = EXP0_F(16);
        EXP0_F(88) = EXP0_F(20);
        EXP0_F(92) = EXP0_F(24);
        
        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ct0 = 8;
        
        epw->mode3++;
    case 1:                                         
        if (epw->ct0 > 0) 
        {
            epw->ct0--;
            
            njUnitMatrix(NULL);
            
            switch (EXP0_C(105)) 
            {                    
            case 5:                                 
                njRotateX(NULL, -2048);
                break;
            case 3:                                 
                njRotateX(NULL,  2048);
                break;
            case 4:                                 
                njRotateZ(NULL, -2048);
                break;
            case 2:                                 
                njRotateZ(NULL,  2048);
                break;
            case 1:                                
                njRotateX(NULL,  4096);
                break;
            }
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 2:                                    
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DG08(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 26;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spm_026);

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG09(BH_PWORK* epw)
{
	switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 56;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spmh_026);

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG10(BH_PWORK* epw)
{    
    NJS_VECTOR v, ov;  
    float out; 
	int ang;      

    switch (epw->mode3) 
    {                    
    case 0:
        epw->mtn_no = 56;
        epw->frm_no = 0;
        
        epw->mtn_add = 65536;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        
        if ((epw->flg & 0x80000)) 
        {
            if ((EXP0_C(105) == 0) || (EXP0_C(105) == 1))
            {
                *(NJS_POINT3*)&EXP0_F(84) = *(NJS_POINT3*)&EXP0_F(108);
            } 
            else 
            {
                EXP0_F(84) = EXP0_F(16);
                EXP0_F(88) = EXP0_F(20);
                EXP0_F(92) = EXP0_F(24);
            }
            
            epw->flg |= 0x30;
            
            epw->flg &= ~0x80000;
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
        } 
        else
        {
            EXP0_F(84) = epw->dvx;
            EXP0_F(88) = epw->dvy;
            EXP0_F(92) = epw->dvz;
            
            njUnitVector((NJS_VECTOR*)&EXP0_I(84));
            
            EXP0_F(84) *= 2.0f;
            EXP0_F(92) *= 2.0f;
        }
        
        epw->ct1 = 8;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct1 > 0) 
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);
            
            if (out > 0) 
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);
                
                ang = (int)(10430.381f * asinf(out)) / epw->ct1;
                
                njRotate(NULL, &ov, ang);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            
            epw->ct1--;
        }
        
        if (epw->ct0 == 0) 
        {
            epw->mtn_add = 0;
        } 
        else
        {
            epw->ct0--;
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 2:
        bhEne03_AddNullTrans(epw, spmh_026);
        
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
            
            epw->mtn_no = 4;
            epw->frm_no = 0;
            
            epw->hokan_count = 5;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DG11(BH_PWORK* epw)
{
    NJS_MKEY_A_MOD* mkaP;   
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_VECTOR*)&epw->px);
        
        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;
        
        njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        
        epw->mtn_md |= 0x100;
        
        epw->mtn_no = 50;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;
        
        {
        NJS_MKEY_A_MOD* mkaP; 
            
        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;
        }
        
        if ((EXP0_C(105) == 0) || (EXP0_C(105) == 1)) 
        {
            *(NJS_POINT3*)&EXP0_F(84) = *(NJS_POINT3*)&EXP0_F(108);
        }
        else 
        {
            EXP0_F(84) = EXP0_F(16);
            EXP0_F(88) = EXP0_F(20);
            EXP0_F(92) = EXP0_F(24); 
        }
        
        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg |= 0x30;
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x1800000;
        epw->flg &= ~0x300000;
        
        epw->ar = 3.0f;
        
        epw->ct0 = 8;
        
        epw->mode3++;
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
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            hp = (ATR_WORK*)EXP0_I(96);
            
            if (hp->type == 7) 
            {
                epw->py = hp->py;
            } 
            else
            {
                h = hp->h;
                
                if (h == 0) 
                {
                    h = rom->h;
                }
                
                epw->py = hp->py + h;
            }
            
            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
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
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    }
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
            
            epw->ar = 6.0f;
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DG12(BH_PWORK* epw)
{
    NJS_MKEY_A_MOD* mkaP;  
    
    switch (epw->mode3) 
    {                        
    case 0:
        bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_VECTOR* ) &epw->px);
        
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
        
        if ((epw->flg & 0x80000)) 
        {
            EXP0_F(84) = EXP0_F(16);
            EXP0_F(88) = 0;
            EXP0_F(92) = EXP0_F(24);
        } 
        else 
        {
            EXP0_F(84) = 0;
            EXP0_F(88) = 0;
            EXP0_F(92) = 0;
        }
        
        njRotateX((NJS_MATRIX*)epw->exp0, 32768);
        
        epw->mtn_md |= 0x100;
        
        epw->mtn_no = 18;
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
        
        njCalcVector((NJS_MATRIX*)epw->exp0, (NJS_VECTOR*)epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);
        }
        
        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg |= 0x30;
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x1800000;
        epw->flg &= ~0x300000;
        
        epw->ct0 = 8;
        
        epw->mode3++;
    case 1:
        if (epw->ct0 > 0) 
        {
            NJS_VECTOR v, ov;          
            float out;           
        	int ang;              
            
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_F(16), &v, &ov);
            
            if (out > 0) 
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);
                
                njRotate(NULL, &ov, (int)(10430.381f * asinf(out)) / epw->ct0);
                
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
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_add = 65536;
            
            epw->frm_no = 0;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        bhEne03_AddNullTrans(epw, spm_016);
        
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_Die(BH_PWORK* epw)
{
	bhEne03_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne03_DD00(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {                        
    case 0:
        epw->mtn_no = 23;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spm_023);
        
        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);
            
            epw->mtn_add = 0;
            
            epw->mode3++;
            
            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DD01(BH_PWORK* epw) 
{
    NJS_MKEY_A_MOD* mkaP;   
    
    switch (epw->mode3) 
    {
    case 0:
        if ((epw->flg & 0x80000)) 
        {
            epw->flg |= 0x30;
            
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_POINT3*)&epw->px);
            
            mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
            mkaP += epw->frm_no / 65536;
            
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }
        
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;
        
        epw->mtn_md |= 0x100;

        {
        NJS_MKEY_A_MOD* mkaP;
        NJS_MKEY* mkfP;       
        NJS_POINT3 trans;       
            
        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        EXP0_F(84) = EXP0_F(16) / 2.0f;
        EXP0_F(88) = EXP0_F(20) / 2.0f;
        EXP0_F(92) = EXP0_F(24) / 2.0f;

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        }

        if ((epw->flg & 0x80000)) 
        {
            epw->flg &= ~0x80000;
            
            epw->pxb = epw->px;
            epw->pyb = epw->py;
            epw->pzb = epw->pz;
        }

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ar = 0.1f;
        
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->ct0 = 8;
        
        epw->mode3++;
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

            out = njOuterProduct((NJS_VECTOR*)&EXP0_F(16), &v, &ov);
            
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
            
            epw->ct0--;
        }

        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 45875;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        } 
        else 
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    }
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_add = 0;
            
            epw->mode3++;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DD02(BH_PWORK* epw)
{
    NJS_MKEY* mkfP;    
    NJS_POINT3 trans;    
	NJS_MKEY_A_MOD* mkaP; 

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;

        EXP0_F(84) = 0;
        EXP0_F(92) = 0;
        EXP0_F(88) = -1.0f;

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;

        epw->mtn_md |= 0x100;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->ar = 0.1f;
        
        epw->mode3++;
    case 1:
        if ((ATR_WORK*)EXP0_I(96) != NULL)
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->mode3++;
        } 
        else 
        {
            epw->py += EXP0_F(88);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->frm_no = (epw->mnwP[epw->mtn_no].frm_num - 1) * 65536.0f;
            
            epw->hokan_count = 0;
            
            epw->mtn_add = 0;
            
            epw->mode3++;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    case 3:
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DD03(BH_PWORK* epw)
{
    O_WORK* owk;       
    unsigned int i;    
	NJS_CNK_OBJECT* p;

    switch (epw->mode3) 
    {
    case 0:
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->flg |= 0x8000;
    
        bhEne_SetMinceEffect2(epw, 2,   0.5f, 6);
        bhEne_SetMinceEffect2(epw, 259, 0.3f, 8);
    
        bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->px, 1, 9, 1);
        bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->px, 1, 9, 2);
    
        for (i = 0; i < 8; i++) 
        {
            if (((unsigned char*)epw->exp0)[160 + i] == 0) 
            {
                owk = epw->mlwP->owP;
    					
                owk[BrokenParts[i]].flg     |= 0x3;
                owk[BrokenParts[i] + 1].flg |= 0x2;
                owk[BrokenParts[i] + 2].flg |= 0x2;
    
                EXP0_BYTE(i, 12) = 1;
                EXP0_BYTE(i, 14) = 0;
                EXP0_BYTE(i, 15) = 0; 
                
                EXP0_INT(i, 980) = EXP0_C(105);
            }
        }
    
        epw->mdflg |= 0x20;
        epw->stflg |= 0x8;
    
        p = epw->mlwP->objP;

        p[1].evalflags  |= 0x8;
        p[2].evalflags  |= 0x8;
        p[31].evalflags |= 0x8;
        p[32].evalflags |= 0x8;
        p[33].evalflags |= 0x8;
        p[34].evalflags |= 0x8;
        p[35].evalflags |= 0x8;
        p[36].evalflags |= 0x8;
    
        bhEne_EraseArrow(epw, 1);
        bhEne_EraseArrow(epw, 2);
        bhEne_EraseArrow(epw, 31);
        bhEne_EraseArrow(epw, 32);
        bhEne_EraseArrow(epw, 33);
        bhEne_EraseArrow(epw, 34);
        bhEne_EraseArrow(epw, 35);
        bhEne_EraseArrow(epw, 36);
    
        epw->mtn_no  = 0;
        epw->mtn_add = 0;
        
        epw->frm_no = 0;
        
        epw->mode3++;
        break;
    }
}

// 100% matching!
void bhEne03_DD04(BH_PWORK* epw)
{
    NJS_POINT3 pos;      
	NJS_MKEY_A_MOD* mkaP;
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
        
        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;

        epw->mtn_md |= 0x100;
        
        epw->mtn_no = 50;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 52428;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;

        if ((EXP0_C(105) == 0) || (EXP0_C(105) == 1)) 
        {
            *(NJS_POINT3*)&EXP0_F(84) = *(NJS_POINT3*)&EXP0_F(108);
        } 
        else 
        {
            EXP0_F(84) = EXP0_F(16);
            EXP0_F(88) = EXP0_F(20);
            EXP0_F(92) = EXP0_F(24);
        }

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg |= 0x30;
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x1800000;
        epw->flg &= ~0x300000;
        
        epw->ar = 3.0f;
        
        epw->ct0 = 8;
        
        epw->mode3++;
    case 1:
        if (epw->ct0 > 0) 
        {
            epw->ct0--;
            
            njUnitMatrix(NULL);

            switch (EXP0_C(105)) 
            {
            case 5: 
                njRotateX(NULL, -2048); 
                break;
            case 3: 
                njRotateX(NULL,  2048); 
                break;
            case 4: 
                njRotateZ(NULL, -2048); 
                break;
            case 2: 
                njRotateZ(NULL,  2048); 
                break;
            case 1: 
                njRotateX(NULL,  4096); 
                break;
            }
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }

        hp = (ATR_WORK*)EXP0_I(96);
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);

            hp = (ATR_WORK*)EXP0_I(96);
            
            if (hp->type == 7)
            {
                epw->py = hp->py;
            } 
            else 
            {
                h = hp->h;
                
                if (h == 0.0f) 
                {
                    h = rom->h;
                }
                
                epw->py = hp->py + h;
            }

            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        } 
        else 
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;
            
            epw->ar = 6.0f;
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DD05(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 27;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

        epw->mode3++;
        break;
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
}

// 100% matching!
int bhEne03_DGDirCheck(BH_PWORK* epw)
{
	NJS_VECTOR v;
	
    v.x = -EXP0_F(32);
    v.y = -EXP0_F(36);
    v.z = -EXP0_F(40);

    if (njInnerProduct(&v, (NJS_VECTOR*)&epw->dvx) < 0)
    {
        return 0;
    }

    return 1;
}

// 100% matching!
void bhEne03_SearchPlayer(BH_PWORK* epw, int ang)
{
    NJS_POINT3 dist;
    NJS_POINT3 p1, p2;

    dist.x = epw->px - plp->px;
    dist.y = epw->py - plp->py;
    dist.z = epw->pz - plp->pz;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &dist, &dist);
    
    EXP0_I(68) = bhArcTan2(dist.x, dist.z);
    
    if (abs(EXP0_I(68)) < ang) 
    {
        p1.x = epw->px + (5.0f * EXP0_F(16));
        p1.y = epw->py + (5.0f * EXP0_F(20));
        p1.z = epw->pz + (5.0f * EXP0_F(24));
        
        p2.x = plp->px;
        p2.y = 10.0f + plp->py;
        p2.z = plp->pz;
        
        if (bhCollisionCheckLine2(&p1, &p2, 0x4400, -1) == NULL) 
        {
            EXP0_UC(104) = 1;
            return;
        }
    }
    
    if (EXP0_UC(104) != 0) 
    {
        EXP0_UC(104)++;
        
        if (EXP0_UC(104) > 90) 
        {
            EXP0_UC(104) = 0;
        }
    }
}

// 100% matching!
int bhEne03_DirTarget(BH_PWORK* epw, NJS_POINT3* pos, int w)
{
	int ang;
	NJS_VECTOR vec;
	
    vec.x = epw->px - pos->x;
    vec.y = epw->py - pos->y;
    vec.z = epw->pz - pos->z;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &vec, &vec);
    
    ang = bhArcTan2(vec.x, vec.z);
    
    if (w < abs(ang))
    {
        ang = (ang > 0) ? w : -w; 
    }
    
    return ang;
}

// 100% matching!
void bhEne03_GoAHead(BH_PWORK* epw)
{
	epw->px -= EXP0_F(32) * epw->spd;
    epw->py -= EXP0_F(36) * epw->spd;
    epw->pz -= EXP0_F(40) * epw->spd;
}

// 100% matching!
void bhEne03_GetPartsPos(BH_PWORK* epw, char* parts, NJS_POINT3* p)
{
	ML_WORK* mlwP;
	NJS_CNK_OBJECT* objP;

    mlwP = epw->mlwP;

    njPushMatrixEx();

    njUnitMatrix(NULL);

    njTranslateEx((NJS_VECTOR*)&epw->px);

    njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    while (*parts != -1)
    {
        objP = &mlwP->objP[*parts++];

        njTranslateEx((NJS_VECTOR*)objP->pos);
        njRotateEx(objP->ang, 0);
    }

    njGetTranslation(NULL, p);

    njPopMatrixEx();
}

// 100% matching!
void bhEne03_MakeMatrix(BH_PWORK* epw)
{
    int ang; 
    float px, py, pz; // not from DWARF

    px = -EXP0_F(32);
    py = -EXP0_F(36);
    pz = -EXP0_F(40);
    
    njUnitMatrix((NJS_MATRIX*)epw->exp0);
    
    switch (EXP0_C(105)) 
    {
    case 0:
        ang = bhArcTan2(-px, -pz);
        
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 1:
        ang = bhArcTan2(-px, -pz);
        
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    case 3:
        ang = bhArcTan2(-px, py);
        
        njRotateX((NJS_MATRIX*)epw->exp0, 16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    case 5:
        ang = bhArcTan2(-px, py);
        
        njRotateX((NJS_MATRIX*)epw->exp0, 16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 2:
        ang = bhArcTan2(py, -pz);
        
        njRotateZ((NJS_MATRIX*)epw->exp0, -16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 4:
        ang = bhArcTan2(py, -pz);
        
        njRotateZ((NJS_MATRIX*)epw->exp0, -16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    }
}

// 100% matching!
void bhEne03_HidePartsSub0(NJS_CNK_OBJECT* p)
{
    p->evalflags |= 0x8;

    if (p->child != NULL)
    {
        bhEne03_HidePartsSub0(p->child);
    }

    if (p->sibling != NULL)
    {
        bhEne03_HidePartsSub0(p->sibling);
    }
}

// 100% matching!
void bhEne03_HidePartsSub1(NJS_CNK_OBJECT* p)
{
	p->evalflags &= ~0x8;

    if (p->child != NULL)
    {
        bhEne03_HidePartsSub1(p->child);
    }

    if (p->sibling != NULL)
    {
        bhEne03_HidePartsSub1(p->sibling);
    }
}

// 100% matching!
void bhEne03_HideParts(BH_PWORK* epw, unsigned short PartsNo, unsigned short flg)
{
	NJS_CNK_OBJECT* p;

    p = &epw->mlwP->objP[PartsNo];

    if (flg)
    {
        p->evalflags |= 0x8;

        if (p->child != NULL)
        {
            bhEne03_HidePartsSub0(p->child);
        }
    }
    else
    {
        p->evalflags &= ~0x8;

        if (p->child != NULL)
        {
            bhEne03_HidePartsSub1(p->child);
        }
    }
}

// 100% matching!
int bhEne03_CollisionWalls(BH_PWORK* epw)
{
    NJS_POINT3 body, trans;      
    int ret;             
    NJS_MKEY_A_MOD* mkaP; 
    NJS_CNK_OBJECT* objP; 
    float px, py, pz; // not from DWARF

    px = epw->px;
    py = epw->py;
    pz = epw->pz;

    body.x = 0;
    body.y = epw->ar;
    body.z = 0;

    ret = 0; 

    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    if ((epw->flg & 0x1000000)) 
    {
        mkaP =  epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;
        
        njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
    }

    njCalcVector(NULL, &body, &body);

    objP = epw->mlwP->objP;
    
    trans.x = objP->pos[0];
    trans.y = objP->pos[1];
    trans.z = objP->pos[2];

    if (!(epw->flg & 0x800000)) 
    {
        trans.y = 0;
    }

    njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

    epw->px += trans.x;
    epw->py += trans.y;
    epw->pz += trans.z;

    if ((ATR_WORK*)EXP0_I(96) != NULL) 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        epw->px -= 3.0f * EXP0_F(32);
        epw->py -= 3.0f * EXP0_F(36);
        epw->pz -= 3.0f * EXP0_F(40);
        
        if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL)
        {
            ret = 1;
        }

        epw->px += 3.0f * EXP0_F(32);
        epw->py += 3.0f * EXP0_F(36);
        epw->pz += 3.0f * EXP0_F(40);
        
        if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL) 
        {
            ret = 1;
        }

        if (epw->type == 0)
        {
            epw->px += 2.0f * EXP0_F(32);
            epw->py += 2.0f * EXP0_F(36);
            epw->pz += 2.0f * EXP0_F(40);
            
            if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL) 
            {
                ret = 1;
            }

            epw->px -= 2.0f * EXP0_F(32);
            epw->py -= 2.0f * EXP0_F(36);
            epw->pz -= 2.0f * EXP0_F(40);
        }

        if ((EXP0_C(105) != 0) && (EXP0_C(105) != 1)) 
        {
            bhEne03_CollisionBoxEdge2(epw);
        }

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    } 
    else 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        if (bhEne03_Collision(epw) != NULL) 
        {
            ret = 1;
        }

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    }

    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;

    if ((ATR_WORK*)EXP0_I(96) != NULL) 
    {
        switch (EXP0_C(105)) 
        {
        case 0:
        case 1:
            epw->py = py;
            break;
        case 2:
        case 4:
            epw->px = px;
            break;
        case 3:
        case 5:
            epw->pz = pz;
            break;
        }
    }

    return ret;
}

// 100% matching!
ATR_WORK* bhEne03_GetWall(BH_PWORK* epw)
{
	NJS_POINT3 p1;
	NJS_POINT3 p2;

    p1.x = epw->px + EXP0_F(0x10);
    p1.y = epw->py + EXP0_F(0x14);
    p1.z = epw->pz + EXP0_F(0x18);
    
    p2.x = p1.x - (999.0f * EXP0_F(0x10));
    p2.y = p1.y - (999.0f * EXP0_F(0x14));
    p2.z = p1.z - (999.0f * EXP0_F(0x18));
    
    return bhCollisionCheckLine(&p1, &p2);
}

// 100% matching!
ATR_WORK* bhEne03_Collision(BH_PWORK* epw)
{
	ATR_WORK* hp;
	ATR_WORK* ret;
    int i;
	int wal_n;

	ret = NULL;
	wal_n = rom->wal_n + sys->mwal_n;

	for (i = 0; i < wal_n; i++)
	{
		if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
			
		if (!(hp->flg & 1)) 
        {
            continue;
        }

		switch (hp->type)
		{
		case 0:
		case 1:
			if ((hp->type & 1) && (epw->flg & 0x400)) 
            {
                continue;
            }
				
			if (bhEne03_CollisionWallBox(hp, (NJS_POINT3*)&epw->px, epw->ar))
            {
                ret = hp;
            }
				
			break;

		case 2:
		case 3:
			if ((hp->type & 1) && (epw->flg & 0x400))
            {
                continue;
            }
            
			if (bhEne03_CollisionWallCylinder(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;

		case 4:
		case 5:
			if ((hp->type & 1) && (epw->flg & 0x400))
            {
                continue;
            }
            
			if (bhEne03_CollisionWallTriangle(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
			break;

		case 6:
			if (bhEne03_CollisionWallSlope(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;

		case 7:
			if (bhEne03_CollisionWallGround(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;
		}
	}
	return ret;
}

// 100% matching!
ATR_WORK* bhEne03_Collision2(BH_PWORK* epw, ATR_WORK* gnd)
{
	ATR_WORK* hp;
	ATR_WORK* ret;
    int i;
	int wal_n;

	ret = NULL;
	wal_n = rom->wal_n + sys->mwal_n;

	for (i = 0; i < wal_n; i++)
	{
		if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
			
		if ((hp->flg & 1) && (hp != gnd)) 
        {
    		switch (hp->type)
    		{
    		case 0:
    		case 1:
    			if ((hp->type & 1) && (epw->flg & 0x400)) 
                {
                    continue;
                }
    				
    			if (bhEne03_CollisionWallBox(hp, (NJS_POINT3*)&epw->px, epw->ar))
                {
                    ret = hp;
                }
    				
    			break;
    
    		case 2:
    		case 3:
    			if ((hp->type & 1) && (epw->flg & 0x400))
                {
                    continue;
                }
                
    			if (bhEne03_CollisionWallCylinder(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 4:
    		case 5:
    			if ((hp->type & 1) && (epw->flg & 0x400))
                {
                    continue;
                }
                
    			if (bhEne03_CollisionWallTriangle(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 6:
    			if (bhEne03_CollisionWallSlope(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 7:
    			if (bhEne03_CollisionWallGround(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    		}
        }
	}
	return ret;
}

// 100% matching!
int bhEne03_CollisionWallBox(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
    // the order of the variables below is different from the one in the DWARF
    float cx;
    float cy;   
    float cz;
    float h;   
    float dx;
    float dy;
    float dz;  
    float px;
    float py;
    float pz;
    float ax;
    float ay;
    float az; 
    float len;


    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    px = hp->px;
    py = hp->py;
    pz = hp->pz;

    dx = px - ar;
    dy = py - ar;
    dz = pz - ar;

    cx = px + (hp->w / 2.0f);
    cy = py + (h / 2.0f);
    cz = pz + (hp->d / 2.0f);
    
    if ((pos->x > dx) && (pos->x < (ar + (px + hp->w)))
        && (pos->y > dy) && (pos->y < (ar + (py + h)))
        && (pos->z > dz) && (pos->z < (ar + (pz + hp->d))))
    {
        if (pos->x > cx)
        {
            dx = ar + (px + hp->w);
            px += hp->w;
        }

        if (pos->z > cz)
        {
            dz = ar + (pz + hp->d);
            pz += hp->d;
        }

        if (pos->y > cy)
        {
            dy = ar + (py + h);
            py += h;
        }

        ax = fabsf(pos->x - dx);
        ay = fabsf(pos->y - dy);
        az = fabsf(pos->z - dz);

        if ((ax < ar) && (ay < ar) && (az < ar))
        {
            dx = pos->x - px;
            dy = pos->y - py;
            dz = pos->z - pz;
            len = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->y = py + ((dy * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ay < ar) && (az < ar))
        {
            dy = pos->y - py;
            dz = pos->z - pz;
            len = njSqrt((dy * dy) + (dz * dz));
            if (len < ar)
            {
                pos->y = py + ((dy * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ax < ar) && (az < ar))
        {
            dx = pos->x - px;
            dz = pos->z - pz;
            len = njSqrt((dx * dx) + (dz * dz));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ax < ar) && (ay < ar))
        {
            dx = pos->x - px;
            dy = pos->y - py;
            len = njSqrt((dx * dx) + (dy * dy));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->y = py + ((dy * ar) / len);
            }
        } 
        else
        {
            if ((ay > ax) && (az > ax)) {
                pos->x = dx;
            }
            if ((ax > ay) && (az > ay)) {
                pos->y = dy;
            }
            if ((ax > az) && (ay > az)) {
                pos->z = dz;
            }
        }

        return 1;
    }

    return 0;
}

// 100% matching!
int bhEne03_CollisionWallGround(ATR_WORK* hp, NJS_POINT3* pos, float ar)
{
    ATR_WORK hp2 = *hp;
    
    hp2.type = 0;
    hp2.py = hp->py + hp->h;

    if (!hp->h)
    {
        hp2.h = 0.01f;
        hp2.py -= 0.01f;
    } 
    else
    {
        hp2.h = -hp->h;
    }
    
    return bhEne03_CollisionWallBox(&hp2, pos, ar);
}

// 100% matching!
int bhEne03_CollisionWallCylinder(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
	float dx;
	float dy;
	float dz;
	float ln;
	float radius;    
	float h;

	h = hp->h;
	if (h == 0.0f)
    {    
        h = rom->h;
    }
		
	dx = hp->px - pos->x;
    dy = hp->py + h - pos->y;
	dz = hp->pz - pos->z;
	
	ln = njSqrt(dx * dx + dz * dz);
	radius = hp->w + ar;

	if ((dy >= 0.0f) && (hp->py < pos->y) && (ln < radius))
	{
		pos->x = hp->px - (dx * radius) / ln;
		pos->z = hp->pz - (dz * radius) / ln;
		return 1;
	}

	if (fabsf(dy) < ar)
	{
		radius = njSqrt(ar * ar - dy * dy);
		if (ln < hp->w + radius)
		{
			radius += hp->w;
			pos->x = hp->px - (dx * radius) / ln;
			pos->z = hp->pz - (dz * radius) / ln;
			return 1;
		}
	}

	return 0;
}

// 100% matching!
int bhEne03_CollisionWallSlope(ATR_WORK* hp, NJS_POINT3* pos, float ar)
{
    float h;
    float len;
    NJS_POINT3 area[4];
    NJS_POINT3 cp;
    NJS_PLANE pl;
    NJS_LINE ln;  
    signed char xf0;
    signed char xf1;
    signed char zf0;
    signed char zf1;  
    signed char idx;  
    signed char idx2;

    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    if (pos->x > hp->px - ar)
    {
        if((pos->x < hp->px + hp->w + ar &&
            pos->z > hp->pz - ar &&
            pos->z < hp->pz + hp->d + ar &&
            pos->y > hp->py - ar &&
            pos->y < hp->py + h + ar))
        {    
        
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
        
            area[1].x = hp->px;
            area[1].y = hp->py;
            area[1].z = hp->pz + hp->d;
        
            area[2].x = hp->px + hp->w;
            area[2].y = hp->py;
            area[2].z = hp->pz + hp->d;
        
            area[3].x = hp->px + hp->w;
            area[3].y = hp->py;
            area[3].z = hp->pz;
        
            switch (hp->id)
            {
            case 0:
                area[2].y = area[3].y = hp->py + h;
                break;
                
            case 1:
                area[0].y = area[3].y = hp->py + h;
                break;
                
            case 2:
                area[1].y = area[2].y = hp->py + h;            
                break;
                
            case 3:
                area[0].y = area[1].y = hp->py + h;            
                break;
            }
        
            njGetPlaneNormal(area, (NJS_VECTOR*)&pl.vx);
            pl.px = area[0].x;
            pl.py = area[0].y;
            pl.pz = area[0].z;
        
            len = njDistanceP2PL(pos, &pl, &cp);
            if ((len < ar))
            {   
                xf0 = zf0 = xf1 = zf1 = 0;
                
                if (cp.x < hp->px)
                {
                    xf0 = 1;
                }
                if (cp.x > (hp->px + hp->w))
                {
                    xf1 = 1;
                }
                if (cp.z < hp->pz) 
                {
                    zf0 = 1;
                }
                if (cp.z > (hp->pz + hp->d))
                {
                    zf1 = 1;
                }

                if (!xf0 && !zf0 && !xf1 && !zf1)
                {
                    njUnitVector((NJS_VECTOR*)&pl.vx);
                    pos->x = cp.x + pl.vx * ar;
                    pos->y = cp.y + pl.vy * ar;
                    pos->z = cp.z + pl.vz * ar;
                    return 1;
                }
            
                if (xf0 + xf1 + zf0 + zf1 == 1)
                {                    
                    if (xf0)
                    {
                        idx = 0;  
                        idx2 = 1;
                    }
                    else if (xf1)
                    {
                        idx = 2;
                        idx2 = 3;
                    } 
                    else if (zf0)
                    {
                        idx = 0;
                        idx2 = 3;
                    } 
                    else
                    {
                        idx = 1;
                        idx2 = 2;
                    }
            
                    ln.px = area[idx].x;
                    ln.py = area[idx].y;
                    ln.pz = area[idx].z;
                    ln.vx = area[idx2].x - ln.px;
                    ln.vy = area[idx2].y - ln.py;
                    ln.vz = area[idx2].z - ln.pz;
            
                    len = njDistanceP2L(pos, &ln, &cp);
                    if (len < ar)
                    {
                        pos->x = cp.x - ar * (cp.x - pos->x) / len;
                        pos->y = cp.y - ar * (cp.y - pos->y) / len;
                        pos->z = cp.z - ar * (cp.z - pos->z) / len;
                        return 1;
                    }
                }
            
                if (xf0 + xf1 + zf0 + zf1 == 2)
                {
                    if (xf0 && zf0)
                    {
                        idx = 0;
                    }                    
                    if (xf0 && zf1)
                    {
                        idx = 1;
                    }
                    if (xf1 && zf1)
                    {
                        idx = 2;
                    }
                    if (xf1 && zf0)
                    {
                        idx = 3;
                    }
                                    
                    len = njDistanceP2P(&area[idx], pos);
                    if (len < ar)
                    {
                        pos->x = area[idx].x - ar * (area[idx].x - pos->x) / len;
                        pos->y = area[idx].y - ar * (area[idx].y - pos->y) / len;
                        pos->z = area[idx].z - ar * (area[idx].z - pos->z) / len;
                        return 1;
                    }
                } 
            } 
        } 
    }
    return 0;
}

// 100% matching!
int bhEne03_CollisionWallTriangle(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
    float h;
    NJS_POINT3 area[4];
    NJS_POINT3 pd;
    NJS_POINT3 vd;
    NJS_LINE ln;
    ATR_WORK bhp;

    // not present in DWARF
    float x1, x2, z1, z2;
    float t;
    float px;

    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    if ((hp->py <= pos->y - ar))
    {
        if (hp->py + h >= pos->y - ar)           
        {
            if ((hp->py <= pos->y) && (hp->py + h >= pos->y))
            {          
                if (hp->w > 0.0f)
                {
                    x1 = hp->px - ar;
                    x2 = hp->px + hp->w + ar;
                } 
                else
                {
                    x1 = hp->px + hp->w - ar;
                    x2 = hp->px + ar;
                }
            
                if (hp->d > 0.0f)
                {
                    z1 = hp->pz - ar;
                    z2 = hp->pz + hp->d + ar;
                } 
                else
                {
                    z1 = hp->pz + hp->d - ar;
                    z2 = hp->pz + ar;
                }
             
                if ((x1 > pos->x || x2 <= pos->x || z1 > pos->z || z2 <= pos->z))
                {
                    return 0;
                }
                    
                
                if (hp->id == 0 || hp->id == 3)
                {
                    vd.x = hp->d;
                    vd.z = hp->w;
                } 
                else
                {
                    vd.x = -hp->d;
                    vd.z = -hp->w;
                }
                
                vd.y = 0.0f;
                njUnitVector(&vd);
            
                vd.x = vd.x * ar;
                vd.z = vd.z * ar;
            
                area[0].x = hp->px + hp->w - vd.x;
                area[0].y = 0.0f;
                area[0].z = hp->pz - vd.z;
            
                area[1].x = hp->px - vd.x;
                area[1].y = 0.0f;
                area[1].z = hp->pz + hp->d - vd.z;
            
                area[2].x = area[1].x + 2.0f * vd.x;
                area[2].y = 0.0f;
                area[2].z = area[1].z + 2.0f * vd.z;
            
                area[3].x = area[0].x + 2.0f * vd.x;
                area[3].y = 0.0f;
                area[3].z = area[0].z + 2.0f * vd.z;
            
                if (bhInOutCheck(pos, area, NULL, 4))
                {
                    ln.px = area[2].x;
                    ln.py = 0.0f;
                    ln.pz = area[2].z;
                    ln.vx = hp->w;
                    ln.vy = 0.0f;
                    ln.vz = -hp->d;
            
                    njDistanceP2L(pos, &ln, &pd);
            
                    pos->x = pd.x;
                    pos->z = pd.z;        
                } 
                else
                {
                    px = pos->x - hp->px;
                    t = hp->d + (px * -hp->d) / hp->w;
                    switch (hp->id)
                    {
                    case 0:
                    case 2:
                        if (t < pos->z - hp->pz)
                        {
                            return 0;
                        }                                
                        break;
                    case 1:
                    case 3:
                        if (t > pos->z - hp->pz)
                        {
                            return 0;
                        }                                
                        break;
                    }
                
                    bhp.type = 0;
                    bhp.w = fabsf(hp->w);
                    bhp.d = fabsf(hp->d);
                    bhp.h = hp->h;
                
                    switch (hp->id)
                    {
                    case 0:
                        bhp.px = hp->px;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz;
                        break;
                        
                    case 1:
                        bhp.px = hp->px;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz + hp->d;
                        break;
                        
                    case 2:
                        bhp.px = hp->px + hp->w;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz;
                        break;
                        
                    case 3:
                        bhp.px = hp->px + hp->w;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz + hp->d;
                        break;
                    }
                    if (bhEne03_CollisionWallBox(&bhp, pos, ar))
                    {
                        return 1;
                    }
                }              
            }
            return 1;
        }                    
    } 
        
    return 0;
}

// 100% matching! 
int bhEne03_CollisionBoxEdge(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
	ATR_WORK ht;
	float h2;
	float r;
    float h1;
	int ret;

	r = ar * 2.0f;
	ret = 0;

	if (hp->type == 7)
	{
		h1 = hp->py;
		h2 = h1 + hp->h;
	}
	else
	{
		if (hp->h)
        {
			h1 = hp->py + hp->h;            
        }
        else
        {
            h1 = hp->py + rom->h;            
        }			
		h2 = hp->py;
	}

	ht.type = 0;

	ht.px = hp->px;
	ht.py = h1;
	ht.pz = hp->pz - r;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px;
	ht.py = h1;
	ht.pz = hp->pz + hp->d;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h1;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h1;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	h1 -= h2;

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.type = 0;
	h2 -= r;

	ht.px = hp->px;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	return ret;
}

// 100% matching!
int bhEne03_CollisionBoxEdge2(BH_PWORK* epw)
{
	NJS_POINT3 p[4];
	NJS_POINT3 p2[4];
	int i;
	float dx;
	float dy;
	float dz;

    // not present in DWARF
    float tmp = 999.0f;

	switch (EXP0_C(0x69))
	{
	case 0:
		dx = 0.0f;
		dy = -tmp;
		dz = 0.0f;
        p[0].x = epw->px - tmp;
		p[0].z = epw->pz - tmp;
		p[1].x = epw->px - tmp;
		p[1].z = epw->pz + tmp;
		p[2].x = epw->px + tmp;
		p[2].z = epw->pz - tmp;
		p[3].x = epw->px + tmp;
		p[3].z = epw->pz + tmp;
        p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
		break;

	case 1:
		dx = 0.0f;
		dy = tmp;
		dz = 0.0f;
        p[0].x = epw->px - tmp;
		p[0].z = epw->pz - tmp;
		p[1].x = epw->px - tmp;
		p[1].z = epw->pz + tmp;
		p[2].x = epw->px + tmp;
		p[2].z = epw->pz - tmp;
		p[3].x = epw->px + tmp;
		p[3].z = epw->pz + tmp;
        p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
		break;

	case 4:
        dx = tmp;
		dy = 0.0f;
		dz = 0.0f;
        p[0].y = epw->py - tmp;
		p[0].z = epw->pz - tmp;
		p[1].y = epw->py - tmp;
		p[1].z = epw->pz + tmp;
		p[2].y = epw->py + tmp;
		p[2].z = epw->pz - tmp;
		p[3].y = epw->py + tmp;
		p[3].z = epw->pz + tmp;
        p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
		break;
                        
    case 2:
		dx = -tmp;
		dy = 0.0f;
		dz = 0.0f;
        p[0].y = epw->py - tmp;
		p[0].z = epw->pz - tmp;
		p[1].y = epw->py - tmp;
		p[1].z = epw->pz + tmp;
		p[2].y = epw->py + tmp;
		p[2].z = epw->pz - tmp;
		p[3].y = epw->py + tmp;
		p[3].z = epw->pz + tmp;
        p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
		break;
        
    case 3:
		dx = 0.0f;
		dy = 0.0f;
        dz = tmp;
        p[0].x = epw->px - tmp;
		p[0].y = epw->py - tmp;
		p[1].x = epw->px - tmp;
		p[1].y = epw->py + tmp;
		p[2].x = epw->px + tmp;
		p[2].y = epw->py - tmp;
		p[3].x = epw->px + tmp;
		p[3].y = epw->py + tmp;
        p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
		break;

	case 5:
		dx = 0.0f;
		dy = 0.0f;
        dz = -tmp;
        p[0].x = epw->px - tmp;
		p[0].y = epw->py - tmp;
		p[1].x = epw->px - tmp;
		p[1].y = epw->py + tmp;
		p[2].x = epw->px + tmp;
		p[2].y = epw->py - tmp;
		p[3].x = epw->px + tmp;
		p[3].y = epw->py + tmp;
        p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
		break;
	}
    
	for (i = 0; i < 4; i++)
	{
		p2[i].x = dx + p[i].x;
		p2[i].y = dy + p[i].y;
		p2[i].z = dz + p[i].z;

		if (bhCollisionCheckLine(&p[i], &p2[i]) == 0)
        {
            *(ATR_WORK **)(epw->exp0 + 0x60) = bhEne03_GetWall(epw);
    		if (*(ATR_WORK **)(epw->exp0 + 0x60) != NULL)
            {
                bhEne03_CollisionBoxEdge(*(ATR_WORK **)(epw->exp0 + 0x60), (NJS_POINT3*)&epw->px, epw->ar);
                break;
            }    			
        }         
	}
	return 0;
}

// 100% matching!
void bhEne03_CollisionLine(BH_PWORK* epw)
{
	NJS_VECTOR n;
	ATR_WORK* hp;

    hp = bhCollisionCheckLine((NJS_VECTOR*) &epw->pxb, (NJS_VECTOR*) &epw->px);
    if (hp != NULL)
    {        
        bhGetHitCollisionNormal(&n);
        if (((*(ATR_WORK **)((char *)epw->exp0 + (0x60))) == NULL) && (n.y > 0.0f))
        {
            (*(ATR_WORK **)((char *)epw->exp0 + (0x60))) = hp;
        }
    }
}

// 100% matching!
void bhEne03_CollisionLine2(BH_PWORK* epw)
{
    NJS_VECTOR v;

    v.x = 0.01f * EXP0_F(0x10);
    v.y = 0.01f * EXP0_F(0x14);
    v.z = 0.01f * EXP0_F(0x18);
    
    njAddVector((NJS_VECTOR*) &epw->pxb, &v);
    njAddVector((NJS_VECTOR*) &epw->px, &v);
    
    bhCollisionCheckLine((NJS_VECTOR*) &epw->pxb, (NJS_VECTOR*) &epw->px);
    
    njSubVector((NJS_VECTOR*) &epw->pxb, &v);
    njSubVector((NJS_VECTOR*) &epw->px, &v);
}

// 100% matching!
void bhEne03_SetModelFlg(BH_PWORK* epw, unsigned int and_flg, unsigned int or_flg)
{
	O_WORK* owk;
	unsigned int i;

    owk = epw->mlwP->owP;

    for (i = 0; i < epw->mnwP->obj_num; i++, owk++)
    {
        owk->flg &= and_flg;
        owk->flg |=  or_flg;
    }
}

// 100% matching!
void bhEne03_AddNullTrans(BH_PWORK* epw, NJS_VECTOR* mtn)
{
	NJS_VECTOR v;

    njCalcVector((NJS_MATRIX*)epw->exp0, &mtn[epw->frm_no / 65536], &v);

    epw->px += v.x;
    epw->pz += v.z;
}

// 100% matching!
int bhEne03_CheckClimbWall()
{
	return 0;
}

// 100% matching!
int bhEne03_CheckClimbDownWall()
{
	return 0;
}

// 100% matching!
int bhEne03_AvoidWall()
{
	return 0;
}

// 99.83% matching
int bhEne03_DiveSpace(BH_PWORK* epw)
{
    NJS_POINT3 pos; 
    BH_PWORK* ep;   
    NJS_MKEY* mkfP;
    float dist;    
    int i;        

    if ((EPW_EXP1_I(0) & 0x3)) 
    {
        return 0;
    }

    mkfP =  epw->mnwP[13].md2P->p[0];
    mkfP += epw->mnwP[13].frm_num - 1;
    
    njCalcVector((NJS_MATRIX*)epw->exp0, (NJS_VECTOR*)&mkfP->key[0], &pos); 

    pos.x += epw->px;
    pos.y += epw->py;
    pos.z += epw->pz;

    dist = ((pos.x - plp->px) * (pos.x - plp->px)) + ((pos.z - plp->pz) * (pos.z - plp->pz));

    if (dist < 25.0f)
    {
        return 0;
    }

    ep = ene;

    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 3) && (ep != epw))
        {
            dist = ((pos.x - ep->px) * (pos.x - ep->px)) + ((pos.z - ep->pz) * (pos.z - ep->pz));
            
            if (dist < 10.0f)
            {
                return 0;
            }
        }
    }

    pos.y = bhGetGroundPosition(&pos);

    if (bhCheckWallType(&pos, 0, 5.0f, (epw->py - pos.y) - 10.0f) != NULL) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

// 100% matching!
int bhEne03_GetWallDir(NJS_VECTOR* v)
{
    if (v->y >= 0.9f)
    {
        return 0;
    }    
    else if (v->y <= -0.9f)
    {
        return 1;
    }

    if (v->x >= 0.9f)
    {
        return 2;
    }    
    else if (v->x <= -0.9f)
    {
        return 4;
    }

    if (v->z >= 0.9f)
    {
        return 5;
    }    
    else if (v->z <= -0.9f)
    {
        return 3;
    }

    // no return 
}

// 100% matching!
void bhEne03_DamageInit(BH_PWORK* epw) 
{
    int i;     
    int pno, num;     
    O_WORK* owk; 
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
        if (epw->type == 0) 
        {
            if ((epw->comb_flg & 0x8)) 
            {
                EXP0_I(124) -= epw->total_dam;
            } 
            else 
            {
                if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8))) 
                {
                    EXP0_I(124) -= epw->total_dam;
                }
                
                epw->hp -= epw->total_dam;
            }
        } 
        else
        {
            epw->hp -= epw->total_dam;
        }
        
        if (epw->wpnr_no == 20) 
        {
            epw->hp = -1;
        }
        
        if ((epw->wpnr_no == 17) && (!(epw->flg2 & 0x4))) 
        {
            return;
        }
        
        bhEne03_HitMark(epw);
        
        if ((epw->total_dam > 15) && ((-rand() / -2147483648.0f) < 0.3f)) 
        {
            switch (epw->wpnr_no) 
            {
            case 11:
            case 20:
            case 14:
            case 15:
            case 16:
                pno = rand() % 8;

                num = 0;
                
                if (pno < 4)
                {
                    for (i = 0; i < 4; i++) 
                    {
                        num += ((unsigned char*)epw->exp0)[i + 160];
                    }
                } 
                else 
                {
                    for (i = 4; i < 8; i++) 
                    {
                        num += ((unsigned char*)epw->exp0)[i + 160];
                    }
                }
        
                if ((num == 0) && (((unsigned char*)epw->exp0)[160 + pno] == 0) && (((pno != 0) && (pno != 4)) || ((pno == 0) && (EXP0_UC(164) == 0)) || ((pno == 4) && (EXP0_UC(160) == 0)))) 
                {
					((unsigned char*)epw->exp0)[160 + pno] = 1;
					
					owk = epw->mlwP->owP;
					
					owk[BrokenParts[pno]].flg     |= 0x3;
					owk[BrokenParts[pno] + 1].flg |= 0x2;
					owk[BrokenParts[pno] + 2].flg |= 0x2;
	
					EXP0_BYTE(pno, 12) = 1;
					EXP0_BYTE(pno, 14) = 0;
					EXP0_BYTE(pno, 15) = 0;
					
					EXP0_INT(pno, 980) = EXP0_C(105);
	
					epw->mdflg |= 0x20;
					
					bhEne_SetMinceEffect(epw,   2, 3);
					bhEne_SetMinceEffect(epw, 259, 2);
					
					bhEne_SetBloodstain(epw, 2, BrokenParts[pno], NULL);
				}
                
                break;
            }
        }
        
        if (epw->hp < 0) 
        {
            epw->flg |=  0x2;
            epw->flg &= ~0x20;
            
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8977);
            
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            if (epw->type == 0) 
            {
                if (epw->wpnr_no == 20)
                {
                    epw->mode2 = 3;
                } 
                else if ((epw->flg & 0x80000)) 
                {
                    if ((EXP0_C(105) == 0) || (EXP0_C(106) == 0)) 
                    { 
                        epw->mode2 = 4; 
                    } 
                    else 
                    { 
                        epw->mode2 = 1; 
                    } 
                } 
                else 
                {
                    switch (EXP0_C(105)) 
                    {
                    case 0:
                        switch (epw->wpnr_no) 
                        {
                        case 5:
                        case 6:
                        case 11:
                        case 20:
                        case 14:
                        case 15:
                        case 16:
                            epw->mode2 = 0;
                            break;
                        default:
                            epw->mode2 = 5;
                            break;
                        }
                        
                        break;
                    case 1:
                        epw->mode2 = 2;
                        break;
                    default:
                        epw->mode2 = 1;
                        break;
                    }
                }
            } 
            else 
            {
                if (epw->total_dam > 25) 
                {
                    epw->mode2 = 3;
                }
                else if ((epw->flg & 0x80000)) 
                {
                    if ((EXP0_C(105) == 0) || (EXP0_C(106) == 0)) 
                    { 
                        epw->mode2 = 4; 
                    }
                    else 
                    { 
                        epw->mode2 = 1; 
                    } 
                }
                else
                {
                    switch (EXP0_C(105)) 
                    {
                    case 0:
                        if (EXP0_I(96) != 0) 
                        { 
                            epw->mode2 = 5; 
                        } 
                        else 
                        { 
                            epw->mode2 = 4; 
                        } 
                        
                        break;
                    case 1:
                        epw->mode2 = 2;
                        break;
                    default:
                        epw->mode2 = 1;
                        break;
                    }
                }
            }
            
            if ((epw->flg & 0x80000)) 
            {
                *(int*)epw->exp1 &= 0x2;
            }
            
            bhEne03_DeadMode2[epw->mode2](epw);
            return;
        }
        
        if (epw->type == 0) 
        {
            flg = 0;
            
            if (EXP0_I(124) < 0) 
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
                if (epw->total_dam < 30) 
                {
                    return;
                }
                
                if (epw->total_dam < 50)
                {
                    epw->mode2 = 1;
                } 
                else 
                {
                    epw->mode2 = (EXP0_C(105) == 1) ? 2 : 3;
                }
            }
            
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8976);
            
            if ((epw->flg & 0x80000)) 
            {
                if (epw->mlwP->owP->mtx[5] > 0) 
                {
                    epw->mode2 = 11; 
                } 
                else 
                { 
                    epw->mode2 = 12; 
                }
            }
            
            if (EXP0_I(96) == 0) 
            {
                epw->mode2 = 10;
            }
        } 
        else 
        {
            if (epw->total_dam < 30) 
            {
                return;
            }
            
            if (epw->total_dam < 50) 
            {
                epw->mode2 = 6;
            } 
            else 
            {
                if (EXP0_C(105) == 0) 
                {
                    if ((epw->comb_flg & 0x4)) 
                    { 
                        epw->mode2 = 9; 
                    } 
                    else 
                    {
                        epw->mode2 = 8;
                    } 
                } 
                else 
                {
                    epw->mode2 = 7;
                }
            }
            
            if ((epw->flg & 0x80000)) 
            {
                epw->mode2 = 11;
            }
            
            if (EXP0_I(96) == 0) 
            {
                epw->mode2 = 10;
            }
        }
        
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        
        if ((epw->flg & 0x80000)) 
        {
            *(int*)epw->exp1 &= 0x2;
        }
        
        bhEne03_DamageMode2[epw->mode2](epw);
    }
}

// 100% matching!
int bhEne03_CheckJumpSpace(BH_PWORK* epw)
{
    NJS_POINT3 p1, p2; 
    float dist;   
    BH_PWORK* ep;  
    int i;         

    if (EXP0_C(105) == 0) 
    {
        dist = epw->px; // may be fake, but matches
        
        p1.x = dist    - (20.0f * EXP0_F(32));
        p1.y = epw->py - (20.0f * EXP0_F(36));
        p1.z = epw->pz - (20.0f * EXP0_F(40)); 
        
        p2.x = epw->px;
        p2.y = epw->py;
        p2.z = epw->pz;
        
        for (i = 0; i < 5; i++) 
        {
            p2.x -= 4.0f * EXP0_F(32);
            p2.z -= 4.0f * EXP0_F(40);
            
            if (bhCheckWallType(&p2, 0, 5.0f, 15.0f) != 0) 
            {
                return 0;
            }
        }
    }
    else 
    {
        dist = epw->px;
        
        p1.x = dist    + (10.0f * EXP0_F(16));
        p1.y = epw->py + (10.0f * EXP0_F(20));
        p1.z = epw->pz + (10.0f * EXP0_F(24));
        
        p1.y = bhGetGroundPosition(&p1);
        
        if (bhCheckWallType(&p1, 0, 5.0f, 10.0f) != 0) 
        {
            return 0;
        }
        
        p1.y += 1.0f;
        
        p2.x = epw->px;
        p2.y = epw->py + 1.0f;
        p2.z = epw->pz;
        
        if (bhCollisionCheckLine(&p2, &p1) != 0) 
        {
            return 0;
        }
    }

    if ((((18.0f + plp->py) + epw->ar) > p1.y) && ((plp->py - epw->ar) < p1.y)) 
    {
        dist = njSqrt(((p1.x - plp->px) * (p1.x - plp->px)) + ((p1.z - plp->pz) * (p1.z - plp->pz)));
        
        if (dist < 10.0f) 
        {
            return 0;
        }
    }

    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++) 
    {
        if ((((ep->flg & 0x1)) && (ep->id == 3) && (ep != epw)) && (njDistanceP2P(&p1, (NJS_POINT3*)&ep->px) < 10.0f))
        {
            return 0;
        }
    }

    return 1;
}

// 100% matching!
void bhEne03_PlayerControl(BH_PWORK* epw) 
{
    float px, pz; // not from DWARF

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
                
                plp->ct1 = 8;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = (sys->ply_id * 14) + 62;
                }
                else
                {
                    plp->mtn_no = (sys->ply_id * 14) + 65;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num;
                
                bhEne_CallPlayerVoice(2);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct1 != 0) 
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
                }
                
                if (plp->ct0-- == 0) 
                {
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 63;
                    } 
                    else 
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 66;
                    }
                    
                    plp->frm_no = 0;
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->ct1 != 0) 
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
                }
                
                break;
            }
            
            break;
        case 2:                                     
        case 3:                                     
            switch (plp->mode3) 
            {                 
            case 0:                                 
                plp->flg &= ~0x40000;
                
                plp->flg  |= 0x10000;
                plp->flg2 |= 0x1;
                
                plp->ct0 = 8;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 58;
                } 
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 59;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                break;
            case 1:                                 
                if (plp->ct0 != 0)
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 2)
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 60;
                    } 
                    else 
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 61;
                    }
                    
                    plp->frm_no = 0;
                    
                    plp->mode3++;
                }
                
                if ((plp->frm_no / 65536) == 4) 
                {
                    bhEne_CallPlayerVoice(2);
                    
                    StartVibrationEx(1, 11);
                }
                
                break;
            case 2:                                 
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
        case 4:                                     
        case 5:                                     
            switch (plp->mode3) 
            {                  
            case 0:                              
                plp->flg &= ~0x40000;
                plp->flg |=  0x10000;
                
                if (plp->mode2 == 4) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 64;
                } 
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 67;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->mode3++;
                break;
            case 1:                              
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = plp->mnwPb;
                    
                    plp->flg  &= ~0x10004;
                    plp->flg2 &= ~0x1;
                    
                    plp->flg |= 0x8;
                    
                    plp->at_flg = 0;
                    
                    plp->stflg &= ~0x10000;
                    
                    *(int*)&plp->mode0 = 1;
                    
                    EPW_EXP1_I(0) &= ~0x4;
                }
                
                break;
            }
            
            break;
        }
        
        px = plp->mlwP->owP[5].mtx[12] - plp->px;
        pz = plp->mlwP->owP[5].mtx[14] - plp->pz;
        
        plp->px += px;
        plp->pz += pz;
        
        bhCheckWall(plp);
        
        plp->px -= px;
        plp->pz -= pz;
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
                plp->flg &= ~0x40000;
                plp->flg |=  0x10000;
                
                plp->ct1 = 10;
                
                if (plp->mode2 == 0) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 71;
                } 
                else
                {
                    plp->mtn_no = (sys->ply_id * 14) + 70;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                }
                
                break;
            }
            
            break;
        case 2:                                     
        case 3:                                     
            switch (plp->mode3) 
            {                   
            case 0:                                 
                plp->flg &= ~0x40000;
                plp->flg |=  0x10000;
                
                plp->ct1 = 10;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 68;
                }
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 69;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                }
                
                break;
            }
            
            break;
        }
    }
}

// 100% matching!
void bhEne03_CallSE(BH_PWORK* epw) 
{
    int fno;

    if (epw->mnwP == epw->mnwPb) 
    {
        fno = epw->frm_no / 65536;
        
        switch (epw->mtn_no) 
        {                     
        case 1:
        case 31:
            if ((fno == 0) || (fno == 9) || (fno == 14)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 2:
        case 3:
        case 32:
        case 33:
            if ((fno == 8) || (fno == 20) || (fno == 28) || (fno == 34)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 6:
        case 7:
            if ((fno == 7) || (fno == 13) || (fno == 18)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 4:
            if ((fno == 0) || (fno == 7)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 37:
            if ((fno == 0) || (fno == 7)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 40:
            if ((fno == 2) || (fno == 6)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 8:
            if (fno == 10) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74500);
            }
            
            break;
        case 9:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 10:
            if (fno == 30) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74502);
            }
            
            break;
        case 15:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }
            
            break;
        case 18:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8978);
            }
            
            break;
        case 23:
            if (fno == 10) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8978);
            }
            
            break;
        case 25:
            if ((fno == 35) || (fno == 50)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 22:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
            }
            
            break;
        case 41:
            if (fno == 13) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74517);
            }
            
            break;
        case 49:
            if (fno == 1) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74518);
            }
            
            break;
        case 44:
            if (fno == 15) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74519);
            }
            
            if (fno == 43) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 46:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74502);
            }
            
            break;
        case 55:
            if ((fno == 185) || (fno == 195) || (fno == 210))
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        }
    }
}

// 100% matching!
void bhEne03_Acid(BH_PWORK* epw, int type)
{
    int eno;   
    int i;      
    O_WORK* owk; 
    float dt;    
    NJS_POINT3 pos1, pos2; // not from DWARF

    owk = epw->mlwP->owP; 
    
    pos1.x = owk[36].mtx[12];
    pos1.y = owk[36].mtx[13];
    pos1.z = owk[36].mtx[14]; 
    
    pos1.x = (pos1.x + owk[35].mtx[12]) * 0.5f; 
    pos1.y = (pos1.y + owk[35].mtx[13]) * 0.5f;
    pos1.z = (pos1.z + owk[35].mtx[14]) * 0.5f; 

    if (type == 0) 
    {
        pos2.x = -2.5f * EXP0_F(32);
        pos2.y = -2.5f * EXP0_F(40); 
        pos2.z = (EXP0_C(105) == 0) ? 0.5f : 0.0f; 
    } 
    else 
    { 
        pos2.x = -0.5f * EXP0_F(32);
        pos2.y = -0.5f * EXP0_F(40);
        pos2.z = 2.5f;
    }

    sys->ef.id   = 256;
    sys->ef.type = (type != 0) ? 5 : 1;
    
    sys->ef.flg = 1;
    
    sys->ef.px = pos1.x;
    sys->ef.py = pos1.y;
    sys->ef.pz = pos1.z;
    
    for (i = 0; i < 8; i++) 
    {
        dt = 0.5f + (-rand() / -2.1474836E9f);
        
        sys->ef.sx = dt;
        sys->ef.sy = dt;
        sys->ef.sz = dt;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {
            eff[eno].stflg |= 0x20; 
            
            eff[eno].txp[0] = epw->mdl[1].texP; 
            eff[eno].tex_id = 1; 

            eff[eno].xn = pos2.x; 
            eff[eno].yn = pos2.z; 
            eff[eno].zn = pos2.y;
            
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
void bhEne03_HitMark(BH_PWORK* epw)
{
    int i;          
    int range;      
    NJS_POINT3 ofp; 
    BLOOD_TBL* blp;

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
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2.1474836E9f)), (rand() % 40) + 20);
        } 
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 0x2)) 
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
        
        epw->mdflg |= 0x400;
    }
}
