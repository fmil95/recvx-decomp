#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"

float fNaFogNear;
float fNaFogFar;
float fNaFogA;
float fNaFogR;
float fNaFogG;
float fNaFogB;
unsigned int ulNaFogA;
unsigned int ulNaFogR;
unsigned int ulNaFogG;
unsigned int ulNaFogB;
float* fpNaFogTblTop;
float fNaFogTbl[128] = { 254.8735046f, 254.7428131f, 254.6076202f, 254.4675751f, 254.3222351f, 254.1712036f, 254.013916f, 253.849823f, 253.6782074f, 253.4983368f, 253.3092957f, 253.1100464f, 252.8993683f, 252.6757812f, 252.4375763f, 252.1826172f, 251.9586487f, 251.7265015f, 251.4855652f, 251.2351227f, 250.9743347f, 250.702301f, 250.4179688f, 250.1201477f, 249.8074951f, 249.4784393f, 249.131134f, 248.7634735f, 248.3729248f, 247.956543f, 247.5107727f, 247.03125f, 246.6507416f, 246.2555237f, 245.8444519f, 245.4161835f, 244.9692078f, 244.5018616f, 244.0122223f, 243.4981079f, 242.9569855f, 242.3859863f, 241.7817383f, 241.1403351f, 240.4571075f, 239.7265625f, 238.9421082f, 238.0957184f, 237.4674377f, 236.8139038f, 236.1330719f, 235.4226227f, 234.6799774f, 233.9021912f, 233.0859375f, 232.2274017f, 231.3222046f, 230.3653259f, 229.3508759f, 228.2720032f, 227.1206055f, 225.887085f, 224.5598755f, 223.125f, 222.1089478f, 221.0508881f, 219.9473419f, 218.7944489f, 217.5878754f, 216.3226624f, 214.9932251f, 213.5931702f, 212.1151276f, 210.5506287f, 208.889801f, 207.1211395f, 205.2309723f, 203.203125f, 201.018158f, 198.6524353f, 197.0351868f, 195.3495789f, 193.5899811f, 191.75f, 189.8225708f, 187.7995758f, 185.671875f, 183.4289703f, 181.0588226f, 178.5475616f, 175.8789673f, 173.0341492f, 169.9907227f, 166.7221375f, 163.1964722f, 159.375f, 156.8328705f, 154.1814117f, 151.4115448f, 148.5131073f, 145.4746246f, 142.2831879f, 138.9240112f, 135.380249f, 131.6325531f, 127.6585541f, 123.4322739f, 118.9232407f, 114.0954895f, 108.9062424f, 103.3041458f, 97.22679901f, 93.27104187f, 89.14274597f, 84.82763672f, 80.30953979f, 75.57035828f, 70.58953857f, 65.34374237f, 59.80628204f, 53.9464798f, 47.72891998f, 41.11236572f, 34.04853058f, 26.4804287f, 18.34020233f, 9.546380043f, 0 };
float fNaFogDensity;
unsigned int ulNaFogState;
/* float fNaFogDist; - unused */

// 100% matching! 
void	njFogEnable()
{ 
    ulNaFogState = 1; 
} 

// 100% matching! 
void	njFogDisable()
{ 
    ulNaFogState = 0; 
} 

// 100% matching! 
void	njSetFogColor(Uint32 c) 
{
    ulNaFogA = (c >> 24) & 0xFF;
    ulNaFogR = (c >> 16) & 0xFF;
    ulNaFogG = (c >> 8) & 0xFF;
    ulNaFogB = c & 0xFF;
    
    fNaFogA = ulNaFogA / 255.0f;
    fNaFogR = ulNaFogR / 255.0f;
    fNaFogG = ulNaFogG / 255.0f;
    fNaFogB = ulNaFogB / 255.0f;
    
    Ps2SetFogColor();
}

// 100% matching! 
void	njSetFogTable(NJS_FOG_TABLE fog)
{
    fpNaFogTblTop = fog; 
} 

// 
// Start address: 0x2d6110
void	njGenerateFogTable3(NJS_FOG_TABLE fog, Float n, Float f)
{
	int exp[4];
	int count;
	int tmp;
	int i;
	float fr1;
	float fr0;
	// Line 151, Address: 0x2d6110, Func Offset: 0
	// Line 158, Address: 0x2d6118, Func Offset: 0x8
	// Line 151, Address: 0x2d611c, Func Offset: 0xc
	// Line 158, Address: 0x2d6124, Func Offset: 0x14
	// Line 151, Address: 0x2d6128, Func Offset: 0x18
	// Line 158, Address: 0x2d612c, Func Offset: 0x1c
	// Line 160, Address: 0x2d6144, Func Offset: 0x34
	// Line 161, Address: 0x2d614c, Func Offset: 0x3c
	// Line 162, Address: 0x2d6154, Func Offset: 0x44
	// Line 164, Address: 0x2d6160, Func Offset: 0x50
	// Line 165, Address: 0x2d6164, Func Offset: 0x54
	// Line 167, Address: 0x2d6174, Func Offset: 0x64
	// Line 169, Address: 0x2d6184, Func Offset: 0x74
	// Line 173, Address: 0x2d618c, Func Offset: 0x7c
	// Line 179, Address: 0x2d61d4, Func Offset: 0xc4
	// Line 181, Address: 0x2d61fc, Func Offset: 0xec
	// Line 182, Address: 0x2d6204, Func Offset: 0xf4
	// Line 186, Address: 0x2d620c, Func Offset: 0xfc
	// Line 185, Address: 0x2d621c, Func Offset: 0x10c
	// Line 189, Address: 0x2d622c, Func Offset: 0x11c
	// Line 190, Address: 0x2d6230, Func Offset: 0x120
	// Line 202, Address: 0x2d6234, Func Offset: 0x124
	// Line 195, Address: 0x2d6240, Func Offset: 0x130
	// Line 202, Address: 0x2d6244, Func Offset: 0x134
	// Line 204, Address: 0x2d6294, Func Offset: 0x184
	// Line 205, Address: 0x2d62a4, Func Offset: 0x194
	// Line 207, Address: 0x2d62a8, Func Offset: 0x198
	// Line 208, Address: 0x2d62ac, Func Offset: 0x19c
	// Line 227, Address: 0x2d62b8, Func Offset: 0x1a8
	// Line 228, Address: 0x2d62c8, Func Offset: 0x1b8
	// Line 229, Address: 0x2d62d4, Func Offset: 0x1c4
	// Line 230, Address: 0x2d62e8, Func Offset: 0x1d8
	// Line 229, Address: 0x2d62f0, Func Offset: 0x1e0
	// Line 233, Address: 0x2d62f8, Func Offset: 0x1e8
	// Line 234, Address: 0x2d6304, Func Offset: 0x1f4
	// Line 235, Address: 0x2d6308, Func Offset: 0x1f8
	// Line 233, Address: 0x2d630c, Func Offset: 0x1fc
	// Line 235, Address: 0x2d631c, Func Offset: 0x20c
	// Line 236, Address: 0x2d6324, Func Offset: 0x214
	// Line 237, Address: 0x2d6338, Func Offset: 0x228
	// Line 239, Address: 0x2d6344, Func Offset: 0x234
	// Line 242, Address: 0x2d6360, Func Offset: 0x250
	// Line 241, Address: 0x2d6364, Func Offset: 0x254
	// Line 243, Address: 0x2d6368, Func Offset: 0x258
	// Line 241, Address: 0x2d636c, Func Offset: 0x25c
	// Line 243, Address: 0x2d6370, Func Offset: 0x260
	// Line 245, Address: 0x2d637c, Func Offset: 0x26c
	// Line 251, Address: 0x2d6388, Func Offset: 0x278
	// Line 252, Address: 0x2d638c, Func Offset: 0x27c
	// Line 253, Address: 0x2d6398, Func Offset: 0x288
	// Line 252, Address: 0x2d63a0, Func Offset: 0x290
	// Line 253, Address: 0x2d63ac, Func Offset: 0x29c
	// Line 256, Address: 0x2d63b4, Func Offset: 0x2a4
	// Func End, Address: 0x2d63cc, Func Offset: 0x2bc
	scePrintf("njGenerateFogTable3 - UNIMPLEMENTED!\n");
}

// 100% matching!
float njCalcFogPowerEx(float INVZ)
{
    float ret;           
    int itmp0;           
    float ftmp2;       
    float v0;            
    float vb;            
    unsigned int tmp;    
    static float inv[8] = { 16.0f, 8.0f, 4.0f, 2.0f, 1.0f, 0.5f, 0.25f, 0.125f }; 

    ret = 255.0f;
    
    if (ulNaFogState != 0) 
    {
        if (INVZ < 0) 
        {
            goto label;
        } 
        else
        {
            ftmp2 = fNaFogDensity * INVZ;
            
            if (ftmp2 < 1.0f) 
            {
                ftmp2 = 1.0f;
            }
            else if (ftmp2 > 255.9999f)
            {
                ftmp2 = 255.9999f;
            }
        }
        
        tmp = *(int*)&ftmp2;
        
        itmp0 = ((tmp >> 19) & 0xF) | (((tmp >> 23) - 127) * 16);
     
        switch (itmp0)
        {
        case 127:
        label:
            ret = fNaFogTbl[127];
            break;
        default:
            *(int*)&v0 = (((itmp0 / 16) + 127) << 23) | ((itmp0 & 0xF) << 19);
            
            vb = inv[itmp0 / 16];
                
            vb *= ftmp2 - v0;    
                
            ret = ((1.0f - vb) * fNaFogTbl[itmp0]) + (vb * fNaFogTbl[itmp0 + 1]);
            break;
        }
    }
    
    return ret;
}

// 100% matching!
float njCalcFogPower(float fVSZ)
{
    float ret;           
    int itmp0;           
    float ftmp2;         
    float v0;            
    float vb;            
    unsigned int tmp;    
    static float inv[8] = { 16.0f, 8.0f, 4.0f, 2.0f, 1.0f, 0.5f, 0.25f, 0.125f };
    
    ret = 255.0f;
    
    if (ulNaFogState != 0)
    {
        if (fVSZ < 0)
        {
            ftmp2 = 255.9999f;
        }
        else
        {
            ftmp2 = fNaFogDensity / fVSZ;
        }
        
        if (ftmp2 < 1.0f)
        {
            ftmp2 = 1.0f;
        }
        else if (ftmp2 > 255.9999f)
        {
            ftmp2 = 255.9999f;
        }
        
        tmp = *(int*)&ftmp2;
        
        itmp0 = ((tmp >> 19) & 0xF) | (((tmp >> 23) - 127) * 16);
        
        if (itmp0 < 0)
        {
            itmp0 = 0;
        }
        else if (itmp0 > 127)
        {
            itmp0 = 127;
        }
        
        switch (itmp0) 
        { 
        case 127:
            ret = fNaFogTbl[itmp0];
            break;
        default:
            *(int*)&v0 = (((itmp0 / 16) + 127) << 23) | ((itmp0 & 0xF) << 19);
            
            vb = inv[itmp0 / 16];
            
            vb *= ftmp2 - v0;
            
            ret = ((1.0f - vb) * fNaFogTbl[itmp0]) + (vb * fNaFogTbl[itmp0 + 1]);
            break;
        }
    }
    
    return ret;
}
