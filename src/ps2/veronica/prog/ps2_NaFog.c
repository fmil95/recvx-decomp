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

// 100% matching!
void	njGenerateFogTable3(NJS_FOG_TABLE fog, Float n, Float f)
{ 
    float fr0, fr1;
    int i; 
    int tmp; 
    int count; 
    int exp[4];
    float x, k, m; // not from DWARF
    int l;         // not from DWARF

    if (-65535.0f > n)
    {
        fNaFogDensity = 65536.0f;
    } 
    else 
    {
        fr0 = frexpf(-f, exp);
        
        count = exp[0] - 1;
        
        k = fr0 * 65536.0f;
        
        tmp = ((int)k & 0xFF00) | count;

        l = 1 << count;
        
        k = (tmp & 0x7F00) / (65536.0f / 2.0f);
        m = (tmp >> 15) * l;
        
        fNaFogDensity = (k * l) + m; 
    }

    if ((f / 256.0f) > n) 
    {
        fr0 = -f;
    } 
    else 
    {
        fr0 = 1.0f;
    }

    fNaFogFar = -f;
    fNaFogNear = -n;
    
    for (count = 0, i = 0; count < 128; count++)
    {
        tmp = count / 16;
        
        if (tmp < 0) 
        {
            fr1 = 1 >> -tmp;
        } 
        else 
        {
            fr1 = 1 << tmp;
        }
        
        x = count & 0xF; 
        x += 16.0f;
        
        fNaFogTbl[count] = fr0 / ((fr1 * x) / 16.0f);

        if (fNaFogTbl[count] >= -n) 
        {
            i++;
        }
    }

    if (-f == fr0) 
    {
        if (i > 1) 
        {
            fr1 = f + fNaFogTbl[i - 1];
            
            count = 0;
            
            do
            {
                fNaFogTbl[count] = 1.0f - ((f + fNaFogTbl[count]) / fr1);
                
                count++;
            } while (count < i);
        } 
        else if (i == 1) 
        {
            fNaFogTbl[0] = 1.0f;
        }
        for ( ; i < 128; i++)
        {
            fNaFogTbl[i] = 0;
        }
    }

    for (count = 0; count < 128; count++) 
    {
        fNaFogTbl[count] = 255.0f - (255.0f * fNaFogTbl[count]);
    }
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
