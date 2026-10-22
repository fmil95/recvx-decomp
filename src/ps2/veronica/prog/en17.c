#include "../../../ps2/veronica/prog/en17.h"
#include "../../../ps2/veronica/prog/en17sub.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: Monster Steve 

char En17_SdwTab[7] = { 2, 5, 15, 20, 9, 13, 255 };
WPNDAMAGE_WORK En17_WpnDamageTbl[22] = 
{
    {  0,  0,  0,  0,  0 },
    {  0,  0,  0,  0,  0 },
    {  0,  4,  3,  3,  3 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  2, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4,  7,  3,  7 },
    {  0,  2,  5,  3,  5 },
    {  0,  4, 10,  3, 10 },
    {  0,  2,  3,  3,  3 },
    {  0,  2, 10,  3, 10 },
    { 12,  2,  1,  3,  3 },
    {  5,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 },
    {  6,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 },
    {  6,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 }
};

static COMBWEP_WORK CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 }, 0, 0 },
    {  0, {  0,  0,  0 }, 0, 0 },
    { 60, { 10,  0,  0 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, {  4,  4,  4 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 10, 10 }, 0, 0 },
    { 60, { 60, 60, 30 }, 0, 0 },
    { 60, {  8,  8,  8 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60,  0 }, 0, 0 },
    { 60, { 60, 60,  0 }, 0, 0 },
    { 60, { 60, 60, 20 }, 0, 0 },
    { 60, { 10, 10,  0 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 }
};
static COMBJOINT_WORK CombJointTbl[24] = { 0 };

CPCL Ene17CapColTab[25] = 
{
    {   1,   2,  20 },
    {   3,   3,  25 },
    {   0,  10,   0 },
    {   3,   3,  30 },
    {   0,  40,  16 },
    {   6,   6,  23 },
    { -30,  24,   0 },
    {  10,  10,  23 },
    {  30,  24,   0 },
    {   4,   5,   8 },
    {   5,   5,  13 },
    {   0,  10,  -5 },
    {   7,   8,  10 },
    {   8,   9,   7 },
    {  11,  12,  10 },
    {  12,  13,   7 },
    {  14,  15,  14 },
    {  15,  16,  10 },
    {  16,  17,   7 },
    {  17,  18,  10 },
    {  19,  20,  14 },
    {  20,  21,  10 },
    {  21,  22,   7 },
    {  22,  23,  10 },
    {   0,   0,   0 }
};
BT_WORK en17prt_blood_tbl[24] = 
{
    {  0,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f },
    {  1,  0.0f, -1.0f,  1.0f,  1.5f,  1.0f,  3.0f,  1.0f },
    {  2,  0.0f,  1.0f,  1.5f,  1.0f,  0.5f,  2.0f,  1.0f },
    {  3,  0.0f,  2.5f,  2.5f,  1.0f,  1.0f,  3.0f,  1.0f },
    {  4,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  4.0f,  1.0f },
    {  5,  0.0f,  1.0f,  2.0f,  0.5f,  0.5f,  2.0f,  0.5f },
    {  6,  0.3f,  0.0f,  2.0f,  0.0f,  0.5f,  2.0f,  1.0f },
    {  7,  0.0f,  0.0f,  1.5f,  0.5f,  0.5f,  4.0f,  0.5f },
    {  8,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  4.0f,  1.0f },
    {  9,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  3.0f,  0.5f },
    { 10, -0.3f,  0.0f,  2.0f,  0.0f,  0.5f,  2.0f,  1.0f },
    { 11,  0.0f,  0.0f,  1.5f,  0.5f,  0.5f,  4.0f,  0.5f },
    { 12,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  4.0f,  1.0f },
    { 13,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  3.0f,  0.5f },
    { 14,  0.0f, -3.0f,  1.5f,  0.5f,  1.5f,  5.0f,  1.0f },
    { 15,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  3.0f,  1.0f },
    { 16,  0.0f, -1.0f,  0.5f,  0.5f,  1.0f,  3.0f,  1.0f },
    { 17,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  2.0f,  1.0f },
    { 18,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  4.0f,  1.0f },
    { 19,  0.0f, -3.0f,  1.5f,  0.5f,  1.5f,  5.0f,  1.0f },
    { 20,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  3.0f,  1.0f },
    { 21,  0.0f, -1.0f,  0.5f,  0.5f,  1.0f,  3.0f,  1.0f },
    { 22,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  2.0f,  1.0f },
    { 23,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  4.0f,  1.0f }
};
MTBL_WRK en17_mtn_tbl[10] = 
{
    {  3, { {  1, 0,  11 }, {  0, 12, 24 }, {  1,  25,  35 }, {  0,  36,  49 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 15, { {  1, 0,  44 }, {  0, 48, 96 }, {  1, 100, 140 }, {  0, 144, 195 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  6, { {  0, 0,  45 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  1, { {  0, 0,  29 }, {  1, 30, 59 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  2, { {  0, 0,  59 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  5, { {  0, 0,  79 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 16, { {  2, 0, 319 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 11, { {  0, 0,  44 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 12, { {  1, 0,  21 }, {  0, 22, 70 }, { -1,   0,  -1 }, {  0,  -1,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, {  0, 0 } } },
    { -1, { { -1, 0,   0 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,  -1 } }, { {  0, -1 }, {  0, 0 }, {  0, 0 }, {  0, 0 } } }
};
MTBL_WORK en17_mtn_tbl2[7] = 
{
    { 15, { {   0, 74496 }, {  48,    74496 }, { 72, 74500 }, { 100, 74496 }, { 140, 74500 }, { 144, 74496 } } },
    {  1, { {   0, 74496 }, {  30,    74496 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    {  2, { {  32, 74499 }, {  35, 16786185 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 16, { { 132, 74499 }, { 160, 16786185 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 11, { {  19, 74503 }, {  22,    74499 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 17, { {  25, 74499 }, {  -1,        0 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { -1, { {  -1,     0 }, {  -1,        0 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } }
};
POS_WORK ply_mtn42_pos[20] = 
{
    { 0.0f,           0.0f },
    { 0.0f,   -2.12480998f },
    { 0.0f,   -2.18794179f },
    { 0.0f,     -2.072721f },
    { 0.0f,   -1.78017569f },
    { 0.0f,   -1.31060696f },
    { 0.0f,   -1.02873039f },
    { 0.0f,   -1.01653862f },
    { 0.0f,   -1.00815964f },
    { 0.0f,    -1.0035944f },
    { 0.0f,   -1.00283909f },
    { 0.0f,   -1.00589752f },
    { 0.0f,    -1.0127697f },
    { 0.0f,  -0.807430267f },
    { 0.0f,  -0.420703888f },
    { 0.0f,  -0.267501831f },
    { 0.0f,  -0.218467712f },
    { 0.0f,  -0.169967651f },
    { 0.0f,  -0.121238708f },
    { 0.0f, -0.0722846985f }
};
POS_WORK ply_mtn43_pos[20] = 
{
    { 0.0f,  5.57899809f },
    { 0.0f,  1.89403009f },
    { 0.0f,  1.89615822f },
    { 0.0f,  1.89056587f },
    { 0.0f,  1.87725449f },
    { 0.0f,  1.85622406f },
    { 0.0f,  1.82747269f },
    { 0.0f,  1.79100037f },
    { 0.0f,  1.45895195f },
    { 0.0f, 0.900272369f },
    { 0.0f, 0.492113113f },
    { 0.0f, 0.234746933f },
    { 0.0f, 0.128166199f },
    { 0.0f, 0.172372818f },
    { 0.0f, 0.339530945f },
    { 0.0f, 0.408201218f },
    { 0.0f, 0.416120529f },
    { 0.0f,  0.38740921f },
    { 0.0f, 0.322071075f },
    { 0.0f, 0.220104218f }
};
POS_WORK ply_mtn44_pos[51] = 
{
    {            0.0f,     -2.6063652f },
    { -0.00109499996f,  -0.0548400879f },
    { -0.00294700009f,  -0.0579090118f },
    {  -0.0042940001f,  -0.0601291656f },
    { -0.00513700023f,  -0.0614967346f },
    { -0.00547399931f,  -0.0620174408f },
    { -0.00530499965f,  -0.0616855621f },
    {  -0.0046310015f,  -0.0605049133f },
    { -0.00345199741f,   -0.058473587f },
    { -0.00176900253f,  -0.0555915833f },
    { 0.000421002507f,  -0.0518627167f },
    {  0.00311599858f,  -0.0472793579f },
    {  0.00631500036f,  -0.0418510437f },
    {   0.0100209992f,  -0.0355682373f },
    {   0.0142310001f,  -0.0284366608f },
    {   0.0187749993f,  -0.0231723785f },
    {   0.0229530018f,  -0.0203113556f },
    {   0.0265810005f,  -0.0173988342f },
    {   0.0296639949f,  -0.0144405365f },
    {   0.0321990028f,  -0.0114307404f },
    {   0.0341860056f,  -0.0083732605f },
    {   0.0356269926f, -0.00526809692f },
    {   0.0365200043f, -0.00211334229f },
    {   0.0368660092f,  0.00109100342f },
    {   0.0366629958f,  0.00434303284f },
    {   0.0359149873f,  0.00764274597f },
    {   0.0346190035f,   0.0109920502f },
    {   0.0327759981f,   0.0143909454f },
    {   0.0303840041f,   0.0178394318f },
    {   0.0274469852f,   0.0213336945f },
    {   0.0239610076f,   0.0248775482f },
    {   0.0188489854f,   0.0315227509f },
    {   0.0127390027f,   0.0407295227f },
    {  0.00702399015f,   0.0491752625f },
    {  0.00170201063f,   0.0568599701f },
    { -0.00322598219f,   0.0637836456f },
    { -0.00775802135f,   0.0699443817f },
    {  -0.0118969679f,   0.0753479004f },
    {  -0.0156410038f,   0.0799865723f },
    {  -0.0189909935f,   0.0838661194f },
    {   -0.021946013f,   0.0869846344f },
    {  -0.0245069861f,   0.0893440247f },
    {  -0.0266750157f,   0.0909385681f },
    {  -0.0303269923f,    0.106515884f },
    {  -0.0353450179f,    0.130146027f },
    {  -0.0397799909f,    0.144119263f },
    {  -0.0436370075f,    0.148435593f },
    {  -0.0469129831f,    0.143100739f },
    {  -0.0496090055f,    0.128105164f },
    {  -0.0517240018f,    0.103460312f },
    {  -0.0532590002f,   0.0691566467f }
};
POS_WORK ply_mtn45_pos[51] = 
{
    {            0.0f,    0.0815086365f },
    { 0.000188999998f,    0.0247268677f },
    { 0.000134999995f,    0.0163879395f },
    { -0.00057199999f,   0.00716018677f },
    { -0.00242500007f,  -0.00296020508f },
    { -0.00393699994f,    -0.013967514f },
    {  -0.0065960004f,   -0.0258655548f },
    { -0.00990600046f,   -0.0386543274f },
    {  -0.0138679985f,   -0.0523319244f },
    {  -0.0184790008f,   -0.0669002533f },
    {  -0.0237429962f,   -0.0823554993f },
    {  -0.0296570063f,   -0.0987052917f },
    {  -0.0419429988f,    -0.115940094f },
    {  -0.0572379977f,    -0.134067535f },
    {  -0.0681459904f,    -0.156576157f },
    {    -0.07466501f,     -0.18034935f },
    {  -0.0767939985f,    -0.200340271f },
    {  -0.0745350122f,    -0.216550827f },
    {  -0.0678870082f,    -0.228973389f },
    {  -0.0568509698f,    -0.237615585f },
    {   -0.041424036f,     -0.24247551f },
    {  -0.0216109753f,    -0.243551254f },
    { -0.00201100111f,    -0.240844727f },
    {   0.0130140185f,    -0.234354019f },
    {   0.0258889794f,    -0.224081039f },
    {   0.0366160274f,     -0.21002388f },
    {   0.0451929569f,    -0.200519562f },
    {   0.0516210198f,     -0.19443512f },
    {   0.0558989942f,     -0.18286705f },
    {   0.0580269992f,    -0.165821075f },
    {   0.0580070019f,    -0.143297195f },
    {   0.0557470024f,    -0.115289688f },
    {   0.0508189946f,   -0.0818042755f },
    {   0.0454149991f,   -0.0428390503f },
    {  0.04004999995f,   -0.0143680573f },
    {   0.0347240046f, -0.000867843628f },
    {   0.0294359997f,    0.0113964081f },
    {   0.0241890028f,    0.0224246979f },
    {   0.0189800002f,    0.0322189331f },
    {   0.0138109997f,    0.0407733917f },
    {  0.00868099928f,    0.0480957031f },
    {  0.00565600023f,    0.0541801453f },
    {  0.00475900061f,    0.0590305328f },
    {  0.00393799972f,    0.0626430511f },
    {  0.00319300033f,    0.0650215149f },
    {  0.00252299989f,    0.0661621094f },
    {  0.00192700000f,    0.0660686493f },
    {  0.00140899990f,    0.0647392273f },
    { 0.000964000006f,    0.0621738434f },
    { 0.000594999990f,    0.0583705902f },
    { 0.000302000000f,    0.0533351898f }
};
void (*bhEne17_Mode0[6])(BH_PWORK*) = 
{
	bhEne17_Init,
	bhEne17_Move,
	bhEne17_Nage,
	bhEne17_Damage,
	bhEne17_Die,
	bhEne_Event
};
void (*bhEne17_InitType[1])(BH_PWORK*) = { bhEne17_InitType00 };
void (*bhEne17_MoveType[1])(BH_PWORK*) = { bhEne17_MVType00 };
void (*bhEne17_BrainMode2[7])(BH_PWORK*) = 
{
	bhEne17_Brain00,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_Brain00
};
void (*bhEne17_MoveMode2[7])(BH_PWORK*) = 
{
	bhEne17_MV00,
	bhEne17_MV01,
	bhEne17_MV02,
	bhEne17_MV03,
	bhEne17_MV04,
	bhEne17_MV05,
	bhEne17_MV06
};
void (*bhEne17_DamageType[1])(BH_PWORK*) = { bhEne17_DGType00 };
void (*bhEne17_DamageMode2[1])(BH_PWORK*) = { bhEne17_DG00 };
/* unused below */
/*void (*bhEne17_NageType[1])(BH_PWORK*);
void (*bhEne17_NageMode2[1])(BH_PWORK*);
void (*bhEne17_DieType[1])(BH_PWORK*);
void (*bhEne17_DieMode2[1])(BH_PWORK*);
int eff_flg;*/

const char en17_flipTree[25] = { 0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 6, 7, 8, 9, 19, 20, 21, 22, 23, 14, 15, 16, 17, 18, 255 };
const char en17_tree[2][8] = { { 0, 1, 19, 20, 21, 22, 23, 255 }, { 0, 1, 14, 15, 16, 17, 18, 255 } };

// 100% matching!
void bhEne17_DmmyBrain()
{
}

// 100% matching!
void bhEne17(BH_PWORK* epw) 
{
    int i;
    O_WORK* owk;
    NJS_POINT3 ps;
    NJS_POINT3 pd;

    bhEne17_MainLoop(epw);
    if ((plp->mode0 == 4) || (plp->mode0 == 6)) {
        if (plp->mode2 == 0) {
            bhEne17_PlyDG00(plp, epw);
        } else {
            bhEne17_PlyDG01(plp, epw);
        }
    }

    bhEne17_EneToPlyDist(epw);
    if (epw->flg & 4) {
        for (i = 0; i < 64; i++) {
            epw->dam[i] = 0;
        }
        epw->flg = (epw->flg & ~4);
    }

    bhEne17_CollCheck(epw);
    bhEne17_CalcEnemy(epw);
    if (epw->mode0 < 5) {
        bhEne17_CameraControl(epw);
    }

    if (((int*)epw->exp0)[3] > 0) {
        ((int*)epw->exp0)[3] -= 1;
    }

    if (((int*)epw->exp0)[4] > 0) {
        ((int*)epw->exp0)[4] -= 1;
    }

    if (((int*)epw->exp0)[2] & 0x20000000) {
        owk = &((O_WRK*)epw->exp2)->mlwP->owP[1];
        ps.x = 0;
        ps.y = 0;
        ps.z = -17.4f;

        njCalcPoint(&owk->mtx, &ps, &pd);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);

        ((int*)epw->exp0)[2] &= ~0x20000000;
        bhEne17_SetLight(epw, &pd);
        bhEne17_SePlay(epw, 0x01002309);
    }
}

// 100% matching!
void bhEne17_EneToPlyDist(BH_PWORK* epw) 
{
    O_WORK* owk;
    NJS_POINT3 pos;
    
    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    EXP0_F(20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
}

// 100% matching!
void bhEne17_MainLoop(BH_PWORK* epw) 
{
    bhEne17_DmgChk(epw);
    bhEne17_Mode0[epw->mode0](epw);
    bhEne17_SetMtn(epw);
}

// 100% matching!
int bhEne17_DmgChk(BH_PWORK* epw) 
{
    if ((epw->flg & 4) && !(epw->flg & 2)) {
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if (epw->total_dam != 0) {
            bhEne17_DamageAdd(epw);
            
            if (EXP0_UC(1) != 0) {
                EXP0_I(8) |= 0x200;
                EXP0_C(1) = 0;
            } else {
                EXP0_C(1) = 1;
            }
            
            if (epw->mode0 == 1) {
                if (epw->comb_flg & 4) {
                    EXP0_I(8) |= 0x80;
                } else {
                    EXP0_I(8) &= ~0x80;
                }
                
                bhEne17_ChgDmgMode(epw);
            }
        }
    }

    // no return
}

// 100% matching
void bhEne17_ChgDmgMode(BH_PWORK* epw) 
{
    WPNDAMAGE_WORK* wp_tbl = En17_WpnDamageTbl;
    int act;
    
    wp_tbl += epw->wpnr_no;
    act = wp_tbl->nm_act;
    
    if (epw->hp < 0) {
        epw->comb_flg |= 1;
        epw->comb_timeout = 0;
        epw->comb_pnt = 0;
    }

    if (epw->comb_flg & 1) {
        act = wp_tbl->cb_act;
    }

    if (act >= 4U) {
        return;
    }
    
    if ((epw->wpnr_no == 17 || epw->wpnr_no == 16) && !(epw->flg2 & 4)) {
        return;
    }
    
    epw->mode0 = 3;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne17_DamageAdd(BH_PWORK *epw)
{
    WPNDAMAGE_WORK *wp_tbl = En17_WpnDamageTbl;
    int *d;
    int i;

    if (epw->hp >= 0) {
        bhEne17_SePlay(epw, 0x01002302);
        wp_tbl = &wp_tbl[epw->comb_wep];
        d = &epw->dam[1];

        for (i = 1; i < (int)epw->mlwP->obj_num; i++, d++) {
            if (*d > 0) {
                epw->djnt_no = i;
                if (!(wp_tbl->flg & 4)) {
                    if ((epw->comb_flg & 1) || (epw->hp < 0)) {
                        bhEne_SetBlood(epw, wp_tbl->cb_blood, en17prt_blood_tbl);
                    } else {
                        bhEne_SetBlood(epw, wp_tbl->nm_blood, en17prt_blood_tbl);
                    }
                }
            }
        }
    }

    if ((wp_tbl->flg & 1) || (wp_tbl->flg & 2)) {
        if (EXP0_I(16) <= 0) {
            EXP0_I(16) = 10;
            if (wp_tbl->flg & 2) {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en17prt_blood_tbl, 2);
            } else {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en17prt_blood_tbl, 1);
            }
        }
    }

    if (wp_tbl->flg & 8) {
        if (EXP0_I(16) <= 0) {
            EXP0_I(16) = 10;
            bhEne_SetSanEffect(epw, epw->djnt_no, en17prt_blood_tbl);
        }
    }
}

// 100% matching!
int bhEne17_SetMtn(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT* obj;
	int ret; 
	int frm;
	int lnk_obj;    
	BH_PWORK* armp;
	int sfrm_no;
	NJS_POINT3 ofs;
    int i;
	NJS_POINT3 ps;
    O_WORK* owk;

    // NOT IN DWARF
    unsigned int argb = 0;
    
    lnk_obj = -1;
    
    if (EXP0_I(8) & 0x20) {
        return 0;
    }

    sfrm_no = epw->frm_no;
    frm = epw->frm_no / 65536;
    
    if (sys->rmthp != epw->mnwP) {
        
        if (epw->type == 0 &&
            (epw->mtn_no == 16 || epw->mtn_no == 15) &&
            frm >= 8) {
            
            for(i = 0; i < 7; i++, argb += 0x10000000) {
                argb = (i << 28) + 0x20FFFFFF;
                epw->frm_no = sfrm_no - ((7 - i) * 65536);
                bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp);
                bhCalcModel(epw);
                
                armp = (BH_PWORK*)epw->exp2;
                bhCalcModel(armp);
                
                owk = &armp->mlwP->owP[1];
                
                ofs.x = 0.0f;                       
                ofs.y = 0.0f;                       
                ofs.z = -16.15572f;

                bhEne17_AfterimageAxEffect(epw, &owk->mtx, &ofs, argb);
            } 

            epw->frm_no = sfrm_no + 0xFFFC0000;
            bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp);
            bhCalcModel(epw);
            epw->frm_no = sfrm_no;
        }


        if (epw->mtn_no == 16) {
            if (frm == 168) {
                EXP0_I(8)     |= 0x800;
                EXP0_I(24)   = 0x40000000;
            }
        } else if (epw->mtn_no == 11) {
            if (frm == 25) {
                EXP0_I(8)     |= 0x800;
                EXP0_I(24)   = 0x40000000;
            }
        } else if (epw->mtn_no == 5) {
            if (frm == 42) {
                EXP0_I(8)     |= 0x800;
                EXP0_I(24)   = 0x40000000;
            }
        } else if (epw->mtn_no == 2) {
            if (frm == 35) {
                EXP0_I(8)     |= 0x800;
                EXP0_I(24)   = 0x40000000;
            }
        } else if (epw->mtn_no == 15) {
            if (frm == 0 || frm == 48 || frm == 100 || frm == 144) {
                EXP0_I(8) |= 0x800;
                EXP0_F(24) = 1.0f;       
            }
        }

        if (epw->mtn_no == 15) {
            if (frm == 0 || frm == 100) {
                lnk_obj = 17;
            } else if (frm == 48 || frm == 144) {
                lnk_obj = 22;
            }

            if (frm == 0 || frm == 25){
                for(i = 0; i < 4; i++) {
                    ps.x = epw->px + ((80.0f * njRandom()) - 40.0f);
                    ps.y = 45.0f;
                    ps.z = epw->pz + ((40.0f * njRandom()) - 20.0f);
                    bhEff_SetPtcl(epw, &ps, 8);
                }
            }
        } else if (epw->mtn_no == 1) {
           if (frm == 0) {
                lnk_obj = 23;
           }  else if (frm == 30) {
                lnk_obj = 18;
           }
        }

        
        if (lnk_obj != -1) {
            O_WORK* owk;
            NJS_POINT3 ps;
            
            owk = &epw->mlwP->owP[lnk_obj];
            ps.x = owk->mtx[12];
            ps.y = 1.0f;
            ps.z = owk->mtx[14];
            bhEne17_SetSmokeEffect3(epw, (NJS_VECTOR* ) &ps, epw->ay + 32768);
        }
    }
    
    ret = bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (EXP0_I(8) & 0x40000000) {
        obj = epw->mlwP->objP;        
        obj->pos[0] = obj->pos[2] = 0.0f;
        bhEne_GetTranslateMtn(epw, frm, 0);
    }
    
    bhEne17_MtnTblPlay(epw, frm);
    
    if (ret != 0) {
        epw->flg |= 0x2000000;
    } else {
        epw->flg &= ~0x2000000;
    }
    
    return ret;
}

// 100% matching!
void bhEne17_MtnTblPlay(BH_PWORK* epw, int frm)
{
    MTBL_WRK* mtbl = en17_mtn_tbl;
    MTBL_WORK* mtbl2 = en17_mtn_tbl2;
    NJS_VECTOR vec  = { 0 };
    NJS_VECTOR vec1 = { 0 };
    NJS_VECTOR vec2 = { 0, -0.8f, -2.5f };
    int i;

    if (sys->rmthp != epw->mnwP) {
        if (epw->flg & 0x40000) {
            while(mtbl->no != -1) {
                if (mtbl->no == epw->mtn_no) {
                    for (i = 0; i < 4; i++) {
                        if (mtbl->fmtn[i].type != -1 &&
                            frm >= mtbl->fmtn[i].s_frm &&
                            frm <= mtbl->fmtn[i].e_frm) {

                            switch (mtbl->fmtn[i].type) {
                            case 0:
                                bhCalcFixOffset(epw, en17_tree[0], &vec2, &vec);
                                break;
                            case 1:
                                bhCalcFixOffset(epw, en17_tree[1], &vec2, &vec);
                                break;
                            case 2:
                                bhCalcFixOffset(epw, en17_tree[0], &vec1, &vec);
                                break;
                            case 3:
                                bhCalcFixOffset(epw, en17_tree[1], &vec1, &vec);
                                break;
                            }

                            if (epw->mtn_no == 0xF) {
                                epw->px -= 1.2f * vec.x;
                                epw->pz -= 1.2f * vec.z;
                            } else {
                                epw->px -= vec.x;
                                epw->pz -= vec.z;
                            }

                            break; 
                        }
                    }
                }

                mtbl++;
            }
        }

        while (mtbl2->no != -1) {
            if (mtbl2->no == epw->mtn_no) {
                for (i = 0; i < 6; i++) {
                    if (mtbl2->atb[i].frm == -1) {
                        break;
                    }
                    
                    if (mtbl2->atb[i].frm == frm) {
                        bhEne17_SePlay(epw, mtbl2->atb[i].act);
                    }
                }
            }
            
            mtbl2++;
        }
    }
}

// 100% matching!
void bhEne17_CollCheck(BH_PWORK* epw) 
{
    
    if (!(epw->flg & 2)) {
        if ((epw->flg & 8) && (((unsigned int*)epw->exp0)[2] & 0x10)) {
            bhCheckPlayer(epw);
        }
        bhEne17_CollCheckWall(epw);
    }
}

// 100% matching!
void bhEne17_CollCheckWall(BH_PWORK* ewp) 
{
    *(ATR_WORK**)((char*)ewp->exp0 + 64) = bhCheckWallType((NJS_POINT3*)&ewp->px, ewp->flg, ewp->ar, ewp->ah);
    
    if ((((unsigned int*)(ewp->exp0))[2] & 0xF) == 1 && (ewp->flg & 0x10)) {
        bhCheckDansa(ewp);
        bhCheckWall(ewp);
    }
}

// 100% matching!
void bhEne17_CalcEnemy(BH_PWORK* epw) 
{
    O_WORK* owk;
    
    bhCalcModel(epw);
    owk = &epw->mlwP->owP[5];
    epw->cah = epw->ah = owk->mtx[13] - epw->py;
    owk = &epw->mlwP->owP[5];
    
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13] - 5.0f;
    epw->watr.c1.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[16];
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[21];
    epw->watr.c2.x = (epw->watr.c2.x + owk->mtx[12]) / 2.0f;
    epw->watr.c2.y = (epw->watr.c2.y + owk->mtx[13]) / 2.0f;
    epw->watr.c2.z = (epw->watr.c2.z + owk->mtx[14]) / 2.0f;
    epw->watr.r = 4.0f;
}

// 100% matching!
void bhEne17_Init(BH_PWORK* epw) 
{	
    int i;
    unsigned char *addr;
    int size;

    epw->ar = 8.0f;
    epw->ah = 25.0f;
    epw->aw = 0;
    epw->ad = 0;
    epw->car = 10.0f;
    epw->cah = 25.0f;
    epw->hp = 250;
    epw->stflg = 0;
    
    for(size = 0; size < 64; size++) 
    {
        epw->dam[size] = 0;
    }
    
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = (unsigned char*)en17_flipTree;
    epw->mtn_md = 0;

    addr = epw->exp0;
        
    if (addr == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x54, 8);
        epw->exp1 = bhEne_CallocWork(0x270, 8);
        
        if (!(epw->flg & 0x80)) 
        {
            epw->exp2 = (unsigned char*)bhEne17_SetLinkWork(epw, 0xD, 4, 0x1F);
            bhEne_SetCallFunc(bhEne17LArm, 0x1F);
            epw->exp3 = (unsigned char*)bhEne17_SetLinkWork(epw, 9, 3, 0x20);
            bhEne_SetCallFunc(bhEne17RArm, 0x20);
        }
    } else {
        i = 84;
        while (i--) {
            *addr = 0;
            addr++;
        }
    }
    

    EXP0_I(0x8) |= 0x11;
    epw->flg |= 0x78;
    epw->flg &= ~2;
    
    if (!(epw->flg & 0x800)) 
    {
        bhSetShadow(En17_SdwTab, (unsigned char *)epw, 1, 10.0f, 5.0f, 10.0f);
        epw->flg |= 0x800;
    }
    
    epw->clp_jno[0] = 5;
    epw->clp_jno[1] = 1;
    epw->clp_jno[2] = 12;
    epw->clp_jno[3] = 8;
    epw->clp_jno[4] = 21;
    epw->clp_jno[5] = 16;
    epw->clp_jno[6] = -1;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->lok_jno = 4;
    epw->mlwP->objP = *epw->mbp;
    epw->mdflg = 0;
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];
    epw->cpcl = Ene17CapColTab;
    
    bhEne17_InitType[0](epw);
    bhSetMotion((BH_PWORK* ) epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    bhEne17_CalcEnemy(epw);
}

// 100% matching!
void bhEne17_InitType00()
{
}

// 100% matching!
BH_PWORK* bhEne17_SetLinkWork(BH_PWORK* epw, int lnk_obj, int mdl_no, int id) 
{
    BH_PWORK* epp;
    ETTY_WORK  lnk_tbl;

    npSetMemoryL((unsigned int*)&lnk_tbl, 9, 0);
    lnk_tbl.flg = 0x80A1;
    lnk_tbl.id  = (unsigned short)id;

    epp = bhSetEnemy(&lnk_tbl, rom->ene_n);

    epp->lkwkp = (unsigned char*)epw;
    epp->lkono = lnk_obj;
    epp->lox = 0.0f;
    epp->loy = 0.0f;
    epp->loz = 0.0f;

    epp->mdl[0] = epw->mdl[mdl_no];
    epp->mlwP   = &epp->mdl[0];

    epp->mnwP = epw->mnwP;

    return epp;
}

// 100% matching!
void bhEne17_Move(BH_PWORK* epw) 
{
    bhEne17_MoveType[0](epw);
}

// 100% matching!
void bhEne17_Damage(BH_PWORK* epw) 
{
    bhEne17_DamageType[0](epw);
}

// 100% matching!
void bhEne17_Nage()
{
}

// 100% matching!
void bhEne17_Die()
{
}

// 100% matching!
void bhEne17_Brain(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    EXP0_UC(0) = 64;
    if (EXP0_UC(0) & 0x40) {
        if ((bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos)) != 255) {
            EXP0_F(28) = pos.x;
            EXP0_F(36) = pos.z;
        } else {
            EXP0_F(28) = plp->px;
            EXP0_F(36) = plp->pz;
        }
        
        bhEne17_BrainMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne17_Brain00(BH_PWORK* epw) 
{
    if (epw->mode3 != 0) {
        if (!(plp->flg & 2) && !(plp->flg & 4)) {
            
            if (!(EXP0_I(8) & 0x400)) {
                
                if (EXP0_F(20) < 24.0f &&
                    ikou3(epw, (NJS_POINT3*)&plp->px, 0x2000) == 0) {
                    
                    if (EXP0_F(20) < 15.5f && (plp->stflg & 0x400)) {
                        epw->mode1 = 0;
                        epw->mode2 = 4;
                        epw->mode3 = 0;
                    } else {
                        epw->mode1 = 0;
                        epw->mode2 = 3;
                        epw->mode3 = 0;
                    }
                } else {
                    epw->mode1 = 1;
                    epw->mode2 = 2;
                    epw->mode3 = 0;
                }
            }
        }
    }
}

// 100% matching!
void bhEne17_MVType00(BH_PWORK* epw) 
{
    if (epw->mode1 == 1) {
        bhEne17_Brain(epw);
    }
    bhEne17_MoveMode2[epw->mode2](epw);
}


// 100% matching!
void bhEne17_MV00(BH_PWORK* epw)
{
    switch (epw->mode3) {                      
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 7);
        EXP0_I(8) &= ~0x40000000;
        epw->mode1 = 1;
        
        if (EXP0_F(20) < 24.0f) {
            epw->ct0 = 10;
        } else {
            epw->ct0 = 1;
        }
        
        EXP0_I(8) |= 0x400;
        
        epw->ct0 += EXP0_I(4);
        epw->ct1 = 0;
        EXP0_I(4) = 0;
        epw->mode3 += 1;
        
    case 1:
        if (--epw->ct0 < 0) {
            EXP0_I(8) &= ~0x400;
        }
        
        if ((epw->wpnr_no != 14) && (epw->wpnr_no != 15) && (epw->wpnr_no != 16) && (epw->wpnr_no != 17) && (EXP0_I(8) & 0x400) && (plp->stflg & 0x400)) {
            if (++epw->ct1 > 10) {
                EXP0_I(8) &= ~0x400;
            }
        }

        break;
    }
}

// 100% matching!
void bhEne17_MV01(BH_PWORK *epw)
{
    switch (epw->mode3) {
    case 0:
        bhEne_ChgMtn(epw, 1, 1966080, 5);
        epw->flg |= 0x40000;
        epw->ct0 = 0;
        epw->mode3++;

    case 1:
        ikou(epw, (NJS_POINT3 *)&epw->exp0[28], 512);

        if (!(plp->flg & 2) && !(plp->flg & 4) &&
            EXP0_F(20) < 22.0f &&
            !ikou3(epw, (NJS_VECTOR *)&plp->px, 8192)) {
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne17_MV02(BH_PWORK* epw) 
{
    int frm;

    switch (epw->mode3) {                             
    case 0:
        bhEne_ChgMtn(epw, 15, 12320768, 56);
        epw->mtn_add = 262144;
        epw->flg |= 0x40000;
        EXP0_C(1) = 0;
        epw->ct0 = 0;
        epw->mode3 += 1;
        
    case 1:
        ikou(epw, (NJS_VECTOR* ) &plp->px, 728);
        frm = epw->frm_no / 65536;
        
        if ((frm >= 84) && (frm < 177) && (bhEne17_PlayerDGCheck(epw, plp) != 0)) {
            epw->ct0 = 1;
        }
        
        if ((epw->ct0 == 1) && ((epw->flg & 0x02000000) || (frm == 136))) {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne17_MV03(BH_PWORK* epw)
{
    NJS_VECTOR ofs;
    O_WORK* owk;
    int frm;
    int i;

    switch (epw->mode3) {                              
    case 0:
        bhEne_ChgMtn(epw, 16, 0, 80);
        epw->mtn_add = 262144;
        epw->flg  |= 0x40000;
        epw->flg2 |= 1;
        EXP0_UC(1) = 0;
        epw->mode3 += 1;
        
    case 1:
        frm = epw->frm_no / 65536;

        if (frm >= 72) {
            if (frm < 121) {
                ikou(epw, (NJS_POINT3*)&plp->px, 728);
            }
        }

        if (frm == 156) {
            ofs.x = -4.5f;
            ofs.y = 0.0f;
            ofs.z = -15.0f;
            bhEne17_SetSmokeEffect(epw, 0, &ofs);

            owk = &epw->mlwP->owP[1];
            ofs.x = owk->mtx[12];
            ofs.z = owk->mtx[14];
            
            ofs.y = 1.0f;

            for (i = 0; i < 4; i++) {
                bhEne17_SetSmokeEffect2(epw, &ofs, epw->ay + 20480 + (i * 8192));
            }
        }

        if (frm >= 156) {
            if (frm < 169) {
                for (i = 0; i < 2; i++) {
                    ofs.x = epw->px + ((80.0f * ((float)-rand() / -2147483648.0f)) - 40.0f);
                    ofs.y = 45.0f;
                    ofs.z = epw->pz + ((40.0f * ((float)-rand() / -2147483648.0f)) - 20.0f);
                    bhEff_SetPtcl(epw, &ofs, 8);
                }
            }
        }

        if (frm < 144) {
            /* nothing */
        } else if (frm < 169) {
            bhEne17_PlayerDGCheck(epw, plp);
        }

        if (!(EXP0_F(20) < 24.0f) && (plp->hp > 0)) {
            if (frm < 148 || frm > 220) {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                epw->flg2 &= ~1;
                return;
            }
        }

        if ((epw->frm_no / 65536) >= 312) {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg2 &= ~1;
        }
        break;
    }
}

// 100% matching!
void bhEne17_MV04(BH_PWORK* epw) 
{
    int frm;

    switch (epw->mode3) {                          
    case 0:
        bhEne_ChgMtn(epw, 11, 0, 10);
        epw->flg |= 0x40000;
        epw->flg2 |= 1;
        EXP0_C(1) = 0;
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;
        
        if ((frm >= 21) && (frm < 29)) {
            bhEne17_PlayerDGCheck(epw, plp);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num) - 1) {
            epw->mode1 = 1;
            epw->mode2 = 6;
            epw->mode3 = 0;
            EXP0_I(4) = 0;
            epw->flg2 &= ~1;
        }
        break;
    }
}

void bhEne17_MV05(BH_PWORK* epw) 
{
    O_WORK* owk;
    NJS_POINT3 ofs;
    int i;
    int frm;

    switch (epw->mode3) {                        
    case 0:
        bhEne_ChgMtn(epw, 2, 0, 10);
        epw->flg |= 0x40000;
        EXP0_C(1) = 0;
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;
        
        if (frm >= 0) {
            if (frm < 23) {
                ikou(epw, (NJS_POINT3*)&plp->px, 728);
            }
        }
        
        if (frm >= 31) {
            if (frm < 37) {
                bhEne17_PlayerDGCheck(epw, plp);
            }
        }
        
        if (frm == 32) {
            ofs.x = 0.0f;
            ofs.y = 0.0f;
            ofs.z = -15.0f;
            bhEne17_SetSmokeEffect(epw, 0,  &ofs);
            owk = &epw->mlwP->owP[1];
            ofs.x = owk->mtx[12];
            ofs.z = owk->mtx[14];
            ofs.y = 1.0f;
            for(i = 0; i < 4; i++) {
                bhEne17_SetSmokeEffect2(epw, &ofs, epw->ay + 20480 + (i * 8192));
            }
        }
        
        if (frm >= 36) {
            if (frm <= 40) {
                for(i = 0; i < 2; i++) {
                    ofs.x = epw->px + ((80.0f * (-rand() / -2.1474836e9f)) - 40.0f);
                    ofs.y = 45.0f;
                    ofs.z = epw->pz + ((40.0f * (-rand() / -2.1474836e9f)) - 20.0f);
                    bhEff_SetPtcl(epw,  &ofs, 8);
                }
            }
        }
        break;
    }
}

// 100% matching!
void bhEne17_MV06(BH_PWORK* epw)
{
    switch (epw->mode3) {
    case 0:
        bhEne_ChgMtn(epw, 17, 0, 7);
        EXP0_I(8) &= ~0x40000000;
        epw->mode1 = 1;

        if (EXP0_F(20) < 24.0f) {
            epw->ct0 = 10;
        } else {
            epw->ct0 = 1;
        }

        EXP0_I(8) |= 0x400;
        epw->ct0 += EXP0_I(4);
        epw->ct1 = 0;
        EXP0_I(4) = 0;
        epw->mode3++;

    case 1:
        if (--epw->ct0 < 0) {
            EXP0_I(8) &= ~0x400;
        }

        if ((*(int*)&epw->exp0[8] & 0x400) && (plp->stflg & 0x400)) {
            if (++epw->ct1 > 10) {
                EXP0_I(8) &= ~0x400;
            }
        }
        break;
    }
}

// 100% matching!
void bhEne17_DGType00(BH_PWORK* epw)
{
    bhEne17_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne17_DG00(BH_PWORK* epw)
{
    int wcnt_tbl[4] = {0, 5, 20, 35};
    int frm;
    int ang;
    
    switch (epw->mode3) {                             
    case 0:
        if (epw->mtn_no == 15) {
            frm = epw->frm_no / 65536;

            if ((frm >= 0 && frm <= 11)
                || (frm >= 27 && frm <= 37))
            {
                bhEne_ChgMtn(epw, 6, 0, 6);
            } else {
                bhEne_ChgMtn(epw, 12, 0, 6);
            }
        }else {
            bhEne_ChgMtn(epw, 6, 0, 6);
        }

        epw->ayp = 10430.381f * atan2f(epw->dvx, epw->dvz);
        EXP0_I(8) &= ~0x100;
        epw->flg  |= 0x40000;
        epw->flg2 &= ~1;
        epw->mode3 += 1;

    case 1:
        frm = epw->frm_no  / 65536;

        if (frm < 10) {
            ang = (unsigned short)(epw->ayp - epw->ay);
            if (32768 < ang) {
                ang -= NJM_DEG_ANG(360.0f);
            }

            epw->ay += (ang / 2);
        }

        if (epw->wpnr_no != 14) {
            if ((EXP0_I(8) & 0x200) &&
                (frm >= 20) && (frm < 31) &&
                !(plp->flg & 2) && !(plp->flg & 4) &&
                (EXP0_F(20) < 24.0f) &&
                (ikou3(epw, (NJS_POINT3*)&plp->px, 0x2000) == 0))
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
        }

        if (frm != 31) {
            return;
        }

        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 0;
        epw->mode3 = 0;
        
        if (epw->wpnr_no == 19) {
            EXP0_I(4) = wcnt_tbl[0];                   
        } else if (epw->wpnr_no >= 14 && epw->wpnr_no < 18) {
            EXP0_I(4) = wcnt_tbl[3];                    
        } else if ((unsigned int)(epw->wpnr_no - 5) < 2) {
            EXP0_I(4) = wcnt_tbl[1];                     
        } else {
            EXP0_I(4) = wcnt_tbl[2];                       
        }
        break;
    }
}

// 100% matching!
void bhEne17_PlyDG00(BH_PWORK* pl, BH_PWORK* epw) 
{
    O_WORK* owk;
    NJS_POINT3 dv;
    NJS_POINT3 ps;
    int ang;

    switch (pl->mode3) {
    case 0:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg |= 0x200000;
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
        if (bhDGCdirCheck((NJS_VECTOR*) &dv, pl->ay) != 0) {
            pl->mtn_no = 75;
            pl->axp = 32768;
            pl->ayp = (int)(10430.381f * atan2f(-dv.x, -dv.z));
        } else {
            pl->mtn_no = 76;
            pl->axp = 0;
            pl->ayp = (int)(10430.381f * atan2f(dv.x, dv.z));
        }

        pl->spd = 2.0f;
        bhEne_PlayerSePlay(epw, 0x402);
        pl->mode3 += 1;
        break;
        
    case 1:
        if ((pl->frm_no / 65536) < 10) {
            ang = (unsigned short)(pl->ayp - pl->ay);
            if (32768 < ang) {
                ang -= NJM_DEG_ANG(360.0f);
            } 
            pl->ay += (ang / 2);
        }

        if (epw->mtn_no != 16) {
            pl->spd *= 0.8f;
            bhAddSpeed(pl, pl->axp);
            owk = &pl->mlwP->owP[17];
            ps.x = owk->mtx[12];
            ps.y = 1.0f;
            ps.z = owk->mtx[14];
            bhEne17_SetSmokeEffect3(epw, &ps, pl->ayp);
            owk = &pl->mlwP->owP[21];
            ps.x = owk->mtx[12];
            ps.z = owk->mtx[14];
            bhEne17_SetSmokeEffect3(epw, &ps, pl->ayp);
        }
        
        if (((int) pl->frm_no / 65536) == 0) {
            pl->flg &= ~0x200000;
            pl->flg &= ~4;
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->flg |= 8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->mnwP = pl->mnwPb;
            *(int*)&plp->mode0 = 1;
        }
        break;
    }
}

// 100% matching!
void bhEne17_PlyDG01(BH_PWORK* pl, BH_PWORK* epw) 
{
    POS_WORK* mtn_pos[4] = {
        ply_mtn42_pos,
        ply_mtn43_pos,
        ply_mtn44_pos,
        ply_mtn45_pos,
    };
    POS_WORK* pos_p;
    NJS_CNK_OBJECT* obj;
    O_WORK* owk;
    NJS_POINT3 key;
    NJS_POINT3 dv;
    int i;
    int rot; // Moved in DWARF
    int frm;

    switch (pl->mode3) {
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

        if (bhDGCdirCheck(&dv, pl->ay) != 0) {
            pl->mtn_no = 21;
            pl->ayp = (int)(10430.381f * atan2f(-dv.x, -dv.z));
        } else {
            pl->ayp = (int)(10430.381f * atan2f(dv.x, dv.z));
            pl->mtn_no = 20;
            pl->ct0 = 1;
        }
        bhEne_PlayerSePlay(epw, 0x402);
        pl->mode3 += 1;
        break;

    case 1:
        frm = pl->frm_no / 65536;

        if (frm < 10) {
            {
                int delta = (unsigned short)(pl->ayp - pl->ay);
                if (32768 < delta) {
                    delta -= NJM_DEG_ANG(360.0f);
                }
                
                pl->ay += (delta / 2);
            }
        }

        if (frm == 7) {
            owk = &pl->mlwP->owP[1];
            key.x = owk->mtx[12];
            key.z = owk->mtx[14];
            key.y = 1.0f;

            if (pl->ct0 == 0) {
                rot = pl->ay + 16384;
            } else {
                rot = pl->ay - 16384;
            }

            for(i = 0; i < 5; i++) {
                bhEne17_SetSmokeEffect2(epw, &key, rot);
                rot += 8192;
            }
        }

        if (frm == 0) {
            if (pl->mtn_no == 21) {
                pl->mtn_no = 23;
            } else {
                pl->mtn_no = 22;
            }
            pl->mode3 += 1;
        }
        break;

    case 2:
        if ((pl->frm_no / 65536) == 0) {
            obj = pl->mlwP->objP;
            obj->pos[2] = 0;
            obj->pos[0] = 0;
            pl->flg &= ~0x200000;
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->flg |= 8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->mnwP = pl->mnwPb;
            *(unsigned int*)&plp->mode0 = 1;
            pl->flg &= ~4;
        }
        break;
    }

    if ((pl->mode0 == 4) || (pl->mode0 == 6)) {
        pos_p = mtn_pos[pl->mtn_no - 20];
        pos_p += pl->frm_no / 65536;

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
int bhEne17_PlayerDGCheck(BH_PWORK* epw, BH_PWORK* pl) 
{
	NJS_CAPSULE cap;
	int i;
	O_WORK* owk;
	NJS_POINT3 ps;
	NJS_POINT3 pd;
    NJS_VECTOR v;

    // NOT IN DWARF
    int j;


    if ((pl->flg & 4) ||  ((pl->flg & 0x2) != 0) || ((pl->flg & 0x2) != 0) || (((pl->stflg & 0x01000000) != 0)) || (((pl->stflg & 0x80000000) != 0))) {
        return 0;
    }

    i = 0;
    j = 0;
    while(i < 5) {
        cap.c1.x = *(float*)(epw->exp1 + j + 72);
        cap.c1.y = *(float*)(epw->exp1 + j + 76);
        cap.c1.z = *(float*)(epw->exp1 + j + 80);
        cap.c2.x = *(float*)(epw->exp1 + j + 384);
        cap.c2.y = *(float*)(epw->exp1 + j + 388);
        cap.c2.z = *(float*)(epw->exp1 + j + 392);
        cap.r = 1.0f;
            
        if (npCollisionCheckCC(&cap, &pl->watr) != 0) {
            pl->djnt_no = 2;
            pl->dpx = cap.c1.x;
            pl->dpy = cap.c1.y;
            pl->dpz = cap.c1.z;
            bhEne17_SePlay(epw, 0x01002308);
            bhEne_SetVibration(1);
            
            if (epw->mtn_no == 11) {
                pl->mode0 = 4;
                pl->mode1 = 0;
                pl->mode2 = 1;
                pl->mode3 = 0;
                pl->flg |= 4;
                pl->hp -= 30;

                if (pl->hp < 0) {
                    pl->hp = 0;
                }
                return 1;
            }
            
            if (epw->mtn_no == 2) {
                pl->hp = -1;
            } else {
                if (pl->hp < 120) {
                    pl->hp = -1;
                } else {
                    pl->mode0 = 4;
                    pl->mode1 = 0;
                    pl->mode3 = 0;
                    pl->mode2 = 0;
                    pl->hp -= 120;
                }
    
                pl->flg |= 4;
            }
    
            
            owk = &plp->mlwP->owP[3];
            ps.x = 0.0f;
            ps.y = 0.0f;
            ps.z = 0.0f;
            njCalcPoint(&owk->mtx, &ps, &pd);

            
            
            v.x = epw->px - plp->px;
            v.y = 15.0f;
            v.z = epw->pz - plp->pz;
            
            bhEff_SetPtcl2V(plp, &pd, &v, 0);
            bhEff_SetPtcl2V(plp, &pd, &v, 0);
            bhEff_SetPtcl2V(plp, &pd, &v, 1);
            bhEff_SetPtcl2V(plp, &pd, &v, 1);
            bhEff_SetPtcl2V(plp, &pd, &v, 2);
            bhEff_SetPtcl2V(plp, &pd, &v, 2);
            bhEff_SetPtcl2V(plp, &pd, &v, 3);
            bhEff_SetPtcl2V(plp, &pd, &v, 3);
            
            pl->djnt_no = 3;
            bhEne_SetBlood2(pl, 2U,  &ps, 0);
            return 1;
        }
    
        i++;
        j += 12;
    }
}

// 100% matching!
void bhEne17_SePlay(BH_PWORK* epw, int no) 
{
    if (!(epw->flg & 0x10000)) {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&epw->px, no);
    }
}

// 100% matching!
int bhEne17_CameraControl(BH_PWORK* epw) 
{
    if (((unsigned int*)(epw->exp0))[2] & 0x800) {
        if (!(EXP0_F(24) <= 0.01f)) {
            cam.ofy = (EXP0_F(24) * (-rand() / -2.1474836e9f)) - (EXP0_F(24) / 2.0f);
            EXP0_F(24) *= 0.8f;
        }
        else {
            cam.ofx = 0.0f;
            cam.ofy = 0.0f;
            cam.ofz = 0.0f;
            ((unsigned int*)epw->exp0)[2] &= ~0x800;
        }
    }

    // no return
}

// 100% matching!
void bhEne17_AfterimageAxEffect(BH_PWORK* epw, NJS_MATRIX* mtx, NJS_POINT3* ofs, unsigned int argb) 
{
    int eno;

    njCalcPoint(mtx, ofs, (NJS_VECTOR*) &sys->ef.px);
    sys->ef.id = 364;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    sys->ef.ax = 0;
    sys->ef.ay = 0;
    sys->ef.mdlver = 1;

    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);

    if (eno == -1) {
        if (eno >= 512) {
            return;
        }
    }

    eff[eno].stflg |= 0x20;
    eff[eno].tex_id = 0;
    eff[eno].mlwP = &epw->mdl[5];
    eff[eno].txp[0] = eff[eno].mlwP->texP;
    eff[eno].ax = (int)(10430.381f * atan2f(mtx[0][6], mtx[0][10]));
    eff[eno].ay = (int)(10430.381f * asinf(-mtx[0][2]));
    eff[eno].az = (int)(10430.381f * atan2f(mtx[0][1], mtx[0][0]));
    eff[eno].flr_no = 1;
    eff[eno].tv[0].col = argb;
}

// 100% matching!
void bhEne17_SetSmokeEffect(BH_PWORK* epw, int lnk_onj, NJS_POINT3* ofs) 
{
    O_WORK* owk;
    NJS_POINT3 ps;
    int eno;
    int i;
    int j;
    
    sys->ef.id = 369;
    sys->ef.flg = 1;
    sys->ef.type = 0;
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    sys->ef.ax = 0;
    sys->ef.ay = epw->ay;
    sys->ef.mdlver = 0;
    owk = &epw->mlwP->owP[lnk_onj];
    ps.x = ofs->x;
    ps.y = ofs->y;
    ps.z = ofs->z;

    for (j = 0; j < 3; j++) {
        ps.z -= 2.0f;
        njCalcPoint(&owk->mtx, &ps, (NJS_VECTOR* ) &sys->ef.px);
        i = 0;
        sys->ef.py = 1.0f;
        
        for(i = 0; i < 4; i++) { 
            sys->ef.px += (2.0f * (-rand() / -2.1474836e9f)) - 1.0f;
            sys->ef.pz += (2.0f * (-rand() / -2.1474836e9f)) - 1.0f;
            eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            if (eno != -1) {
                eff[eno].stflg |= 0x20;
                eff[eno].txp[0] = epw->mlwP->texP;
                eff[eno].tex_id = 7;
                eff[eno].xn = 0.4f + (0.2f * (-rand() / -2.1474836e9f));
                eff[eno].yn = 0.05f;
                eff[eno].zn = 0.9f;
                eff[eno].ct3 = 0;
            }
        } 
    }
}

// 100% matching!
void bhEne17_SetSmokeEffect2(BH_PWORK* epw, NJS_POINT3* ofs, int rot)
{
    int eno;
    int i;

    // NOT IN DWARF
    int j; 
    O_WRK* owk; 

    i = 0;
    j = 0;

    sys->ef.id = 369;
    sys->ef.flg = 1;
    sys->ef.type = 1;
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    sys->ef.ax = 0;
    sys->ef.ay = rot;
    sys->ef.mdlver = 0;
    sys->ef.py = ofs->y;

    while (i < 4) {
        sys->ef.px = (ofs->x + (2.0f * (-rand() / -2147483648.0f))) - 1.0f;
        sys->ef.pz = (ofs->z + (2.0f * (-rand() / -2147483648.0f))) - 1.0f;

        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);

        if (eno != -1) {
            owk = &eff[eno];
            owk->stflg |= 0x20;
            owk->txp[0] = epw->mlwP->texP;
            owk->tex_id = 7;
            owk->xn = 1.2f + (0.2f * (-rand() / -2147483648.0f));
            owk->yn = 0.05f;
            owk->zn = 0.9f;
            owk->ct3 = j;
        }

        i++;
        j += 2;
    }
}

// 100% matching!
void bhEne17_SetSmokeEffect3(BH_PWORK* epw, NJS_POINT3* ofs, int rot) 
{
    int eno;

    sys->ef.id = 369;
    sys->ef.flg = 1;
    sys->ef.type = 0;
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    sys->ef.ax = 0;
    sys->ef.ay = rot;
    sys->ef.mdlver = 0;

    sys->ef.px = ofs->x;
    sys->ef.py = ofs->y;
    sys->ef.pz = ofs->z;

    sys->ef.px += (2.0f * (-rand() / -2147483648.0f)) - 1.0f;
    sys->ef.pz += (2.0f * (-rand() / -2147483648.0f)) - 1.0f;

    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);

    if (eno != -1) {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = 7;
        eff[eno].xn = 0.1f + (0.2f * (-rand() / -2147483648.0f));
        eff[eno].yn = 0.05f;
        eff[eno].zn = 0.9f;
        eff[eno].ct3 = 0;
    }
}

// 100% matching!
void bhEne17_SetLight(BH_PWORK* epw, NJS_POINT3 *ofs) 
{
    LGT_WORK* lp = &(rom->lgtp[2]);

    lp->flg   = 3;
    lp->aspd  = 8;
    lp->lsrc  = 4;
    lp->type  = 101;

    lp->r  = 6.0f;
    lp->g  = 6.0f;
    lp->b  = 6.0f;
    lp->nr = 10.0f;
    lp->fr = 80.0f;

    lp->light = NULL;

    lp->lkflg = 0;
    lp->lkno  = 0;
    lp->lkono = 0;

    lp->px = ofs->x;
    lp->py = ofs->y;
    lp->pz = ofs->z;

    lp->ct0  = 0;
    lp->mode = 0;
}

