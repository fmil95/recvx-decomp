#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/main.h"

/*void njDrawPolygon(_anon5* polygon, int count, int trans);
void njDrawTextureSub(NJS_TEXTURE_VTX* polygon, int count, int flag);
void njDrawTexture(NJS_TEXTURE_VTX* polygon, int count, int tex, int flag);
void njDrawTextureSubH(NJS_TEXTUREH_VTX* polygon, int count, int flag);
void njDrawTextureH(NJS_TEXTUREH_VTX* polygon, int count, int tex, int flag);
void njDrawPolygon3DEx(_anon5* p, int count, int trans);
void njDrawPolygon3DExStart(int trans);
void njDrawPolygonSub3D(_anon5* polygon, int count, int flag);
void njDrawPolygon3DExSetData(_anon5* p, int count);
void njDrawPolygon3DExEnd();
void njDrawTexture3DEx(NJS_TEXTURE_VTX* p, int count, int trans);
void njDrawTexture3DEx1P(NJS_TEXTURE_VTX* p, int count, int trans);
void njDrawTexture3DExStart(int trans);
void njDrawTextureSub3D(NJS_TEXTURE_VTX* polygon, int count, int flag);
void njDrawTextureSub3D1P(NJS_TEXTURE_VTX* polygon, int count, int flag);
void njDrawTexture3DExSetData(NJS_TEXTURE_VTX* p, int count);*/
void njDrawTexture3DExSetData1P(NJS_TEXTURE_VTX* p, int count);
/*void njDrawTexture3DExEnd();
void njDrawTextureSub3DH(NJS_TEXTUREH_VTX* polygon, int count, int flag);
void njDrawTexture3DHEx(NJS_TEXTUREH_VTX* p, int count, int trans);
void njQuadTextureStart(int trans);
void njQuadTextureEnd();
void njSetQuadTexture(int texid, unsigned int col);
void njDrawQuadTexture(_anon4* q, float z);*/

// 100% matching!
void    njDrawPolygon( NJS_POLYGON_VTX *polygon, Int count, Int trans )
{
    float sz;          
    float buff[64][4]; 
    float (* bp)[4];   
    unsigned int i;    

    bp = buff;
    
    for (i = 0; i < count; i++, bp += 3) 
    {
        bp[0][0] = 0;
        bp[0][1] = 0;
        bp[0][2] = 0;
        bp[0][3] = 0;
        
        *(unsigned int*)&bp[1][0] = polygon[i].col >> 16;
        *(unsigned int*)&bp[1][1] = polygon[i].col >> 8;
        *(unsigned int*)&bp[1][2] = polygon[i].col;
        *(unsigned int*)&bp[1][3] = polygon[i].col >> 25;
        
        bp[2][0] = 1728.0f + polygon[i].x;
        bp[2][1] = 1808.0f + polygon[i].y;
        
        if (polygon[i].z) 
        {
            sz = -1.0f / polygon[i].z;
            
            if (sz < -65534.0f)
            {
                sz = -65534.0f; 
            }
        }
        else 
        {
            sz = -65534.0f;
        }
        
        bp[2][2] = sz;
        bp[2][3] = 0;
    }
    
    if (trans == 1) 
    {
        Ps2AddPrim2D(0x26000000000000, buff, count);
    } 
    else 
    {
        Ps2AddPrim2D(0x6000000000000, buff, count);
    }
}

// 100% matching!
void njDrawTextureSub(NJS_TEXTURE_VTX* polygon, int count, int flag)
{
    float sz;        
    float buff[128][4]; 
    float (*bp)[4];    
    unsigned int i;     
    
    bp = buff;
    
    for (i = 0; i < count; i++, bp += 3) 
    {
        bp[0][0] = polygon[i].u;
        bp[0][1] = polygon[i].v;
        bp[0][2] = 1.0f;
        bp[0][3] = 0;
        
        *(unsigned int*)&bp[1][0] = (((polygon[i].col >> 16) & 0xFF) + 1) >> 1;
        *(unsigned int*)&bp[1][1] = (((polygon[i].col >>  8) & 0xFF) + 1) >> 1;
        *(unsigned int*)&bp[1][2] = (((polygon[i].col >>  0) & 0xFF) + 1) >> 1;
        *(unsigned int*)&bp[1][3] = (((polygon[i].col >> 24) & 0xFF) + 1) >> 1;  

        bp[2][0] = 1728.0f + polygon[i].x;
        bp[2][1] = 1808.0f + polygon[i].y;
        
        if (polygon[i].z < 1.0f) 
        {
            polygon[i].z = 1.0f;
        }
        
        if (polygon[i].z) 
        {
            sz = -1.0f / polygon[i].z;
            
            if (sz < -65534.0f) 
            {
                sz = -65534.0f;
            }
        } 
        else 
        {
            sz = -65534.0f;
        }
        
        bp[2][2] = sz;
        bp[2][3] = 0;
    }
    
    if (flag == 1) 
    {
        Ps2AddPrim2D(0x2E000000000000, buff, count);
    }
    else 
    {
        Ps2AddPrim2D(0xE000000000000, buff, count);
    }
}

// 100% matching!
void    njDrawTexture( NJS_TEXTURE_VTX *polygon, Int count, Int tex, Int flag )
{
	Ps2GlobalIndexTexLoad(tex);

	njDrawTextureSub(polygon, count, flag);
}

// 100% matching!
void njDrawTextureSubH(NJS_TEXTUREH_VTX* polygon, int count, int flag)
{
	float sz;        
    float buff[128][4]; 
    float (*bp)[4];    
    unsigned int i;     
    
    bp = buff;
    
    for (i = 0; i < count; i++, bp += 3) 
    {
        bp[0][0] = polygon[i].u;
        bp[0][1] = polygon[i].v;
        bp[0][2] = 1.0f;
        bp[0][3] = 0;
        
        *(unsigned int*)&bp[1][0] = polygon[i].ocol >> 16;
        *(unsigned int*)&bp[1][1] = polygon[i].ocol >>  8;
        *(unsigned int*)&bp[1][2] = polygon[i].ocol >>  0;
        *(unsigned int*)&bp[1][3] = polygon[i].ocol >> 25;  

        bp[2][0] = 1728.0f + polygon[i].x;
        bp[2][1] = 1808.0f + polygon[i].y;
        
        if (polygon[i].z) 
        {
            sz = -1.0f / polygon[i].z;
            
            if (sz < -65534.0f) 
            {
                sz = -65534.0f;
            }
        } 
        else 
        {
            sz = -65534.0f;
        }
        
		bp[2][2] = sz;
        bp[2][3] = polygon[i].bcol;
    }
    
    if (flag == 1) 
    {
        Ps2AddPrim2D(0x3E000000000000, buff, count);
    }
    else 
    {
        Ps2AddPrim2D(0x1E000000000000, buff, count);
    }
}

// 100% matching!
void    njDrawTextureH( NJS_TEXTUREH_VTX *polygon, Int count, Int tex, Int flag )
{
    NJS_TEXTUREH_VTX poly[32];
    int i;
	
    Ps2SetFogColorSys((polygon->ocol >> 16) & 0xFF, (polygon->ocol >> 8) & 0xFF, (polygon->ocol >> 0) & 0xFF);
    
    Ps2GlobalIndexTexLoad(tex);
    
    for (i = 0; i < count; i++) 
    {
        poly[i].x = polygon[i].x;
        poly[i].y = polygon[i].y;
        poly[i].z = polygon[i].z;
        
        poly[i].u = polygon[i].u;
        poly[i].v = polygon[i].v;
        
        poly[i].ocol = (((polygon[i].bcol >> 24) & 0xFF) << 24) | ((((((polygon[i].bcol >> 16) & 0xFF) << 8) >> 8) << 16) | ((((polygon[i].bcol & 0xFF) << 8) >> 8) | (((((polygon[i].bcol >> 8) & 0xFF) << 8) >> 8) << 8)));
        poly[i].bcol = 0x80;
    } 
    
    njDrawTextureSubH(poly, count, flag);
    
    Ps2SetFogColor();
}

// 100% matching!
void    njDrawPolygon3DEx( NJS_POLYGON_VTX *p, Int count, Int trans )
{
	njDrawPolygon3DExStart(trans);

	njDrawPolygon3DExSetData(p, count);
}

// 100% matching!
void	njDrawPolygon3DExStart(Int trans)
{
	Ps2_3DEx_trans = trans;
}

// 100% matching!
void njDrawPolygonSub3D(NJS_POLYGON_VTX* polygon, int count, int flag)
{
    float invz;       
    float buff[64][4]; 
    float (*bp)[4];    
    unsigned int i;    
    NJS_SCRVECTOR scr; 
    
    bp = buff;
    
    for (i = 0; i < count; i++, bp += 3) 
    {
        *(unsigned int*)&bp[1][0] = polygon[i].col >> 16;
        *(unsigned int*)&bp[1][1] = polygon[i].col >> 8;
        *(unsigned int*)&bp[1][2] = polygon[i].col >> 0;
        *(unsigned int*)&bp[1][3] = polygon[i].col >> 25;
        
        njRotTransPers((NJS_POINT3*)&polygon[i].x, &scr);
        
        bp[2][0] = scr.x;
        bp[2][1] = scr.y;
        bp[2][2] = scr.z;
        bp[2][3] = scr.fog;
       
        invz = scr.iz;
        
        bp[0][0] = 0;
        bp[0][1] = 0;
        bp[0][2] = invz;
        bp[0][3] = 0; 
    }
    
    if (flag == 1) 
    {
        Ps2AddPrim3D(0x26000000000000, buff, count);
    }
    else 
    {
        Ps2AddPrim3D(0x6000000000000, buff, count);
    }
}

// 100% matching!
void    njDrawPolygon3DExSetData( NJS_POLYGON_VTX *p, Int count)
{
	Ps2_3DEx_p = p;
	Ps2_3DEx_count = count;

	njDrawPolygonSub3D(p, count, Ps2_3DEx_trans);
}

// 100% matching!
void	njDrawPolygon3DExEnd(void)
{

}

// 100% matching!
void	njDrawTexture3DEx( NJS_TEXTURE_VTX *p, Int count, Int trans )
{
	njDrawTexture3DExStart(trans);

	njDrawTexture3DExSetData(p, count);
}

// 100% matching!
void njDrawTexture3DEx1P(NJS_TEXTURE_VTX* p, int count, int trans)
{
	njDrawTexture3DExStart(trans);
	
	njDrawTexture3DExSetData1P(p, count);
}

// 100% matching!
void	njDrawTexture3DExStart(Int trans)
{
	Ps2_tex3DEx_trans = trans;
}

// 
// Start address: 0x2de970
void njDrawTextureSub3D(NJS_TEXTURE_VTX* polygon, int count, int flag)
{
	unsigned int cflag;
	NJS_SCRVECTOR scr;
	unsigned int col;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	// Line 507, Address: 0x2de970, Func Offset: 0
	// Line 512, Address: 0x2de994, Func Offset: 0x24
	// Line 520, Address: 0x2de998, Func Offset: 0x28
	// Line 524, Address: 0x2de9b0, Func Offset: 0x40
	// Line 546, Address: 0x2de9b4, Func Offset: 0x44
	// Line 525, Address: 0x2de9bc, Func Offset: 0x4c
	// Line 526, Address: 0x2de9d0, Func Offset: 0x60
	// Line 527, Address: 0x2de9e4, Func Offset: 0x74
	// Line 528, Address: 0x2de9f4, Func Offset: 0x84
	// Line 546, Address: 0x2dea04, Func Offset: 0x94
	// Line 548, Address: 0x2dea0c, Func Offset: 0x9c
	// Line 555, Address: 0x2dea28, Func Offset: 0xb8
	// Line 560, Address: 0x2dea2c, Func Offset: 0xbc
	// Line 555, Address: 0x2dea30, Func Offset: 0xc0
	// Line 556, Address: 0x2dea34, Func Offset: 0xc4
	// Line 557, Address: 0x2dea3c, Func Offset: 0xcc
	// Line 558, Address: 0x2dea44, Func Offset: 0xd4
	// Line 560, Address: 0x2dea48, Func Offset: 0xd8
	// Line 563, Address: 0x2dea50, Func Offset: 0xe0
	// Line 564, Address: 0x2dea54, Func Offset: 0xe4
	// Line 568, Address: 0x2dea58, Func Offset: 0xe8
	// Line 560, Address: 0x2dea60, Func Offset: 0xf0
	// Line 564, Address: 0x2dea64, Func Offset: 0xf4
	// Line 565, Address: 0x2dea6c, Func Offset: 0xfc
	// Line 567, Address: 0x2dea74, Func Offset: 0x104
	// Line 565, Address: 0x2dea78, Func Offset: 0x108
	// Line 566, Address: 0x2dea7c, Func Offset: 0x10c
	// Line 567, Address: 0x2dea80, Func Offset: 0x110
	// Line 568, Address: 0x2dea84, Func Offset: 0x114
	// Line 570, Address: 0x2dea90, Func Offset: 0x120
	// Line 573, Address: 0x2dea98, Func Offset: 0x128
	// Line 574, Address: 0x2deaa4, Func Offset: 0x134
	// Line 576, Address: 0x2deab8, Func Offset: 0x148
	// Line 577, Address: 0x2deac0, Func Offset: 0x150
	// Line 583, Address: 0x2dead4, Func Offset: 0x164
	// Func End, Address: 0x2deaf8, Func Offset: 0x188
	scePrintf("njDrawTextureSub3D - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2deb00
void njDrawTextureSub3D1P(NJS_TEXTURE_VTX* polygon, int count, int flag)
{
	VU1_STRIP_BUF* vp;
	unsigned long prim;
	unsigned int i;
	VU1_STRIP_BUF vb[256];
	// Line 643, Address: 0x2deb00, Func Offset: 0
	// Line 660, Address: 0x2deb1c, Func Offset: 0x1c
	// Line 643, Address: 0x2deb20, Func Offset: 0x20
	// Line 660, Address: 0x2deb24, Func Offset: 0x24
	// Line 677, Address: 0x2deb3c, Func Offset: 0x3c
	// Line 678, Address: 0x2deb94, Func Offset: 0x94
	// Line 679, Address: 0x2debec, Func Offset: 0xec
	// Line 680, Address: 0x2dec3c, Func Offset: 0x13c
	// Line 682, Address: 0x2dec88, Func Offset: 0x188
	// Line 680, Address: 0x2dec8c, Func Offset: 0x18c
	// Line 682, Address: 0x2dec90, Func Offset: 0x190
	// Line 684, Address: 0x2deca0, Func Offset: 0x1a0
	// Line 687, Address: 0x2deca4, Func Offset: 0x1a4
	// Line 684, Address: 0x2decac, Func Offset: 0x1ac
	// Line 685, Address: 0x2decb0, Func Offset: 0x1b0
	// Line 687, Address: 0x2decbc, Func Offset: 0x1bc
	// Line 689, Address: 0x2decc8, Func Offset: 0x1c8
	// Line 690, Address: 0x2decd0, Func Offset: 0x1d0
	// Line 691, Address: 0x2dece8, Func Offset: 0x1e8
	// Line 695, Address: 0x2decfc, Func Offset: 0x1fc
	// Func End, Address: 0x2ded1c, Func Offset: 0x21c
	scePrintf("njDrawTextureSub3D1P - UNIMPLEMENTED!\n");
}

// 100% matching!
void	njDrawTexture3DExSetData( NJS_TEXTURE_VTX *p, Int count)
{
	Ps2_tex3DEx_p = p;
	Ps2_tex3DEx_count = count;

	njDrawTextureSub3D(p, count, Ps2_tex3DEx_trans);
}

// 100% matching!
void njDrawTexture3DExSetData1P(NJS_TEXTURE_VTX* p, int count)
{
	Ps2_tex3DEx_p = p;
	Ps2_tex3DEx_count = count;

	njDrawTextureSub3D1P(p, count, Ps2_tex3DEx_trans);
}

// 100% matching!
void	njDrawTexture3DExEnd(void) 
{

}

// 100% matching!
void njDrawTextureSub3DH(NJS_TEXTUREH_VTX* polygon, int count, int flag)
{
    float invz;       
    float buff[64][4]; 
    float (*bp)[4];    
    unsigned int i;    
    NJS_SCRVECTOR scr; 
    
    bp = buff;
    
    for (i = 0; i < count; i++, bp += 3) 
    {
        *(unsigned int*)&bp[1][0] = (((polygon[i].ocol >> 16) & 0xFF) + 1) >> 1; 
        *(unsigned int*)&bp[1][1] = (((polygon[i].ocol >>  8) & 0xFF) + 1) >> 1;
        *(unsigned int*)&bp[1][2] = (((polygon[i].ocol >>  0) & 0xFF) + 1) >> 1;
        *(unsigned int*)&bp[1][3] = (((polygon[i].ocol >> 24) & 0xFF) + 1) >> 1;
        
        njRotTransPers((NJS_POINT3*)&polygon[i].x, &scr);
        
        bp[2][0] = scr.x;
        bp[2][1] = scr.y;
        bp[2][2] = scr.z;
        bp[2][3] = 128.0f;
       
        invz = scr.iz;
        
        bp[0][0] = invz * polygon[i].u;
        bp[0][1] = invz * polygon[i].v;
        bp[0][2] = invz;
        bp[0][3] = 0; 
    }
    
    if (flag == 1) 
    {
        Ps2AddPrim3D(0x3E000000000000, buff, count);
    }
    else 
    {
        Ps2AddPrim3D(0x1E000000000000, buff, count);
    }
}

// 100% matching!
void njDrawTexture3DHEx(NJS_TEXTUREH_VTX* p, int count, int trans)
{
    NJS_TEXTUREH_VTX poly[4];
    int i;
	
    Ps2SetFogColorSys((p->ocol >> 16) & 0xFF, (p->ocol >> 8) & 0xFF, (p->ocol >> 0) & 0xFF);
    
    for (i = 0; i < count; i++) 
    {
        poly[i].x = p[i].x;
        poly[i].y = p[i].y;
        poly[i].z = p[i].z;
        
        poly[i].u = p[i].u;
        poly[i].v = p[i].v;
        
        poly[i].ocol = (((p[i].bcol >> 24) & 0xFF) << 24) | ((((((p[i].bcol >> 16) & 0xFF) << 8) >> 8) << 16) | ((((p[i].bcol & 0xFF) << 8) >> 8) | (((((p[i].bcol >> 8) & 0xFF) << 8) >> 8) << 8)));
        poly[i].bcol = 0x80;
    } 
    
    njDrawTextureSub3DH(poly, count, trans);
    
    Ps2SetFogColor();
}

// 100% matching!
void njQuadTextureStart(int trans)
{
    Ps2_quad_trans = trans;
    
    Ps2_current_texlist_bk = Ps2_current_texlist;
    Ps2_current_texno_bk = Ps2_current_texno;
}

// 100% matching!
void njQuadTextureEnd()
{
    Ps2_current_texlist = Ps2_current_texlist_bk;
    Ps2_current_texno = Ps2_current_texno_bk;
}

// 100% matching!
void njSetQuadTexture(int texid, unsigned int col)
{
    Ps2_quad_color = col; 
    
    njSetTextureNumSys(texid);
}

// 100% matching!
void njDrawQuadTexture(QUAD* q, float z)
{
    float sz;     
    float buff[6][4];  
    unsigned int rgba; 
    
    if (z) 
    {
        sz = -1.0f / z;
        
        if (sz < -65535.0f) 
        {
            sz = -65535.0f;
        }
    }
    else 
    {
        sz = -65535.0f;
    }

    rgba = Ps2_quad_color; 
    
    buff[0][0] = q->u1;
    buff[0][1] = q->v1;
    buff[0][2] = 1.0f;
    buff[0][3] = 0;
    
    buff[3][0] = q->u2;
    buff[3][1] = q->v2;
    buff[3][2] = 1.0f;
    buff[3][3] = 0;
    
    *(unsigned int*)&buff[4][0] = (((rgba >> 16) & 0xFF) + 1) >> 1;
    *(unsigned int*)&buff[4][1] = (((rgba >> 8) & 0xFF) + 1) >> 1;
    *(unsigned int*)&buff[4][2] = ((rgba & 0xFF) + 1) >> 1;
    *(unsigned int*)&buff[4][3] = (((rgba >> 24) & 0xFF) + 1) >> 1;  
    
    buff[2][0] = 1728.0f + q->x1;
    buff[2][1] = 1808.0f + q->y1;
    buff[2][2] = sz;
    buff[2][3] = 0;
    
    buff[5][0] = 1728.0f + q->x2;
    buff[5][1] = 1808.0f + q->y2;
    buff[5][2] = sz;
    buff[5][3] = 0;
    
    if (Ps2_quad_trans == 1) 
    {
        Ps2AddPrim2D(0x2B000000000000, buff, 2);
    }
    else 
    {
        Ps2AddPrim2D(0xB000000000000, buff, 2);
    }
}
