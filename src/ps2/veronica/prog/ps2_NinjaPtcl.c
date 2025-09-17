/*typedef struct _anon0;
typedef struct tagNJS_SCRVECTOR;
typedef struct _anon1;


typedef float type_0[4][256];
typedef float type_1[4];
typedef float type_2[4][256];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct tagNJS_SCRVECTOR
{
	float x;
	float y;
	float z;
	float iz;
	float fog;
};

struct _anon1
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};*/

unsigned int Ps2_ptcl_poly_col;
int Ps2_ptcl_spr_flag;
unsigned int Ps2_ptcl_spr_col;
/*_anon1 _nj_screen_;*/

void	njPtclPolygonStart( Uint32 col );
void	njPtclPolygonEnd( void );
void	njPtclDrawPolygon( NJS_POINT3 *p, Sint32 n, Float h );
void	njPtclSpriteStart( Sint32 texid, Uint32 col, Sint32 flag );
void	njPtclSpriteEnd( void );
/*void njPtclDrawSprite(_anon0* p, int n, float w, float h);*/

// 100% matching!
void	njPtclPolygonStart( Uint32 col ) 
{
    Ps2_ptcl_poly_col = col; 
}

// 100% matching!
void	njPtclPolygonEnd( void )
{

}

// 100% matching!
void	njPtclDrawPolygon( NJS_POINT3 *p, Sint32 n, Float h ) 
{ 
    float invz; 
    float buff[256][4]; 
    float (* bp)[4];
    unsigned int i; 
    unsigned int col; 
    NJS_SCRVECTOR scr; 
    
    bp = (void*)&buff; 
    
    col = Ps2_ptcl_poly_col; 
    
    for (i = 0; i < n; i++) 
    { 
        *(unsigned int*)&bp[1][0] = ((col >> 16) & 0xFF) + 1; 
        *(unsigned int*)&bp[1][1] = ((col >> 8) & 0xFF) + 1; 
        *(unsigned int*)&bp[1][2] = (col & 0xFF) + 1; 
        *(unsigned int*)&bp[1][3] = (((col >> 24) & 0xFF) + 1) / 2; 
        
        *(unsigned int*)&bp[4][0] = ((col >> 16) & 0xFF) + 1; 
        *(unsigned int*)&bp[4][1] = ((col >> 8) & 0xFF) + 1; 
        *(unsigned int*)&bp[4][2] = (col & 0xFF) + 1;
        *(unsigned int*)&bp[4][3] = (((col >> 24) & 0xFF) + 1) / 2; 
            
        njRotTransPers(&p[i], &scr); 
        
        invz = scr.iz; 
        
        bp[2][0] = scr.x - h; 
        bp[2][1] = scr.y - h;
        bp[2][2] = scr.z; 
        bp[2][3] = scr.fog;
        
        bp[5][0] = scr.x + h; 
        bp[5][1] = scr.y + h; 
        bp[5][2] = scr.z; 
        bp[5][3] = scr.fog; 
        
        bp[0][0] = 0; 
        bp[0][1] = 0;
        bp[0][2] = invz; 
        bp[0][3] = 0; 
        
        bp[3][0] = invz; 
        bp[3][1] = invz; 
        bp[3][2] = invz;  
        bp[3][3] = 0; 
        
        bp += 6; 
    }
    
    if (Ps2_ptcl_spr_flag == 1) 
    { 
        Ps2AddPrim3D(0x33000000000000, &buff, n); 
    } 
    else 
    {
        Ps2AddPrim3D(0x13000000000000, &buff, n);
    } 
}

// 100% matching!
void	njPtclSpriteStart( Sint32 texid, Uint32 col, Sint32 flag )
{ 
    Ps2_ptcl_spr_col = col; 
    Ps2_ptcl_spr_flag = flag;
    
    njSetTextureNumSys(texid); 
}

// 100% matching!
void	njPtclSpriteEnd( void ) 
{

}

/*// 
// Start address: 0x2d84f0
void njPtclDrawSprite(_anon0* p, int n, float w, float h)
{
	tagNJS_SCRVECTOR scr;
	unsigned int col;
	unsigned int i;
	float bp[4];
	float buff[4][256];
	float invz;
	// Line 164, Address: 0x2d84f0, Func Offset: 0
	// Line 175, Address: 0x2d8520, Func Offset: 0x30
	// Line 176, Address: 0x2d852c, Func Offset: 0x3c
	// Line 178, Address: 0x2d8584, Func Offset: 0x94
	// Line 179, Address: 0x2d8588, Func Offset: 0x98
	// Line 180, Address: 0x2d858c, Func Offset: 0x9c
	// Line 181, Address: 0x2d8590, Func Offset: 0xa0
	// Line 182, Address: 0x2d8594, Func Offset: 0xa4
	// Line 183, Address: 0x2d8598, Func Offset: 0xa8
	// Line 184, Address: 0x2d859c, Func Offset: 0xac
	// Line 187, Address: 0x2d85a0, Func Offset: 0xb0
	// Line 189, Address: 0x2d85b0, Func Offset: 0xc0
	// Line 207, Address: 0x2d85b8, Func Offset: 0xc8
	// Line 188, Address: 0x2d85bc, Func Offset: 0xcc
	// Line 189, Address: 0x2d85c0, Func Offset: 0xd0
	// Line 190, Address: 0x2d85c4, Func Offset: 0xd4
	// Line 189, Address: 0x2d85c8, Func Offset: 0xd8
	// Line 190, Address: 0x2d85cc, Func Offset: 0xdc
	// Line 191, Address: 0x2d85d0, Func Offset: 0xe0
	// Line 192, Address: 0x2d85d4, Func Offset: 0xe4
	// Line 189, Address: 0x2d85d8, Func Offset: 0xe8
	// Line 206, Address: 0x2d85dc, Func Offset: 0xec
	// Line 207, Address: 0x2d85e0, Func Offset: 0xf0
	// Line 189, Address: 0x2d85e4, Func Offset: 0xf4
	// Line 190, Address: 0x2d85ec, Func Offset: 0xfc
	// Line 193, Address: 0x2d85f8, Func Offset: 0x108
	// Line 190, Address: 0x2d85fc, Func Offset: 0x10c
	// Line 191, Address: 0x2d8608, Func Offset: 0x118
	// Line 192, Address: 0x2d8610, Func Offset: 0x120
	// Line 193, Address: 0x2d8618, Func Offset: 0x128
	// Line 194, Address: 0x2d8624, Func Offset: 0x134
	// Line 193, Address: 0x2d8628, Func Offset: 0x138
	// Line 194, Address: 0x2d8634, Func Offset: 0x144
	// Line 195, Address: 0x2d864c, Func Offset: 0x15c
	// Line 196, Address: 0x2d8654, Func Offset: 0x164
	// Line 198, Address: 0x2d865c, Func Offset: 0x16c
	// Line 199, Address: 0x2d8660, Func Offset: 0x170
	// Line 200, Address: 0x2d8664, Func Offset: 0x174
	// Line 201, Address: 0x2d8668, Func Offset: 0x178
	// Line 203, Address: 0x2d866c, Func Offset: 0x17c
	// Line 204, Address: 0x2d8670, Func Offset: 0x180
	// Line 205, Address: 0x2d8674, Func Offset: 0x184
	// Line 206, Address: 0x2d8678, Func Offset: 0x188
	// Line 207, Address: 0x2d867c, Func Offset: 0x18c
	// Line 209, Address: 0x2d8688, Func Offset: 0x198
	// Line 210, Address: 0x2d869c, Func Offset: 0x1ac
	// Line 212, Address: 0x2d86b0, Func Offset: 0x1c0
	// Line 213, Address: 0x2d86b8, Func Offset: 0x1c8
	// Line 216, Address: 0x2d86cc, Func Offset: 0x1dc
	// Func End, Address: 0x2d8700, Func Offset: 0x210
}*/
