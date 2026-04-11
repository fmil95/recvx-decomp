#ifndef _PS2_NADRAW_H_
#define _PS2_NADRAW_H_

#include "types.h"

void    njDrawPolygon( NJS_POLYGON_VTX *polygon, Int count, Int trans );
void njDrawTextureSub(NJS_TEXTURE_VTX* polygon, int count, int flag);
void    njDrawTexture( NJS_TEXTURE_VTX *polygon, Int count, Int tex, Int flag );
void njDrawTextureSubH(NJS_TEXTUREH_VTX* polygon, int count, int flag);
void    njDrawTextureH( NJS_TEXTUREH_VTX *polygon, Int count, Int tex, Int flag );
void    njDrawPolygon3DEx( NJS_POLYGON_VTX *p, Int count, Int trans );
void	njDrawPolygon3DExStart(Int trans);
void njDrawPolygonSub3D(NJS_POLYGON_VTX* polygon, int count, int flag);
void    njDrawPolygon3DExSetData( NJS_POLYGON_VTX *p, Int count);
void	njDrawPolygon3DExEnd(void);
void	njDrawTexture3DEx( NJS_TEXTURE_VTX *p, Int count, Int trans );
void njDrawTexture3DEx1P(NJS_TEXTURE_VTX* p, int count, int trans);
void	njDrawTexture3DExStart(Int trans);
void njDrawTextureSub3D(NJS_TEXTURE_VTX* polygon, int count, int flag);
void njDrawTextureSub3D1P(NJS_TEXTURE_VTX* polygon, int count, int flag);
void	njDrawTexture3DExSetData( NJS_TEXTURE_VTX *p, Int count);
void njDrawTexture3DExSetData1P(NJS_TEXTURE_VTX* p, int count);
void	njDrawTexture3DExEnd(void);
void njDrawTextureSub3DH(NJS_TEXTUREH_VTX* polygon, int count, int flag);
void njDrawTexture3DHEx(NJS_TEXTUREH_VTX* p, int count, int trans);
void njQuadTextureStart(int trans);
void njQuadTextureEnd();
void njSetQuadTexture(int texid, unsigned int col);
void njDrawQuadTexture(QUAD* q, float z);

#endif
