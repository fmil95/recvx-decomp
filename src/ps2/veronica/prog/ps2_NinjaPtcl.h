#ifndef _PS2_NINJA_PTCL_H_
#define _PS2_NINJA_PTCL_H_

void	njPtclPolygonStart( Uint32 col );
void	njPtclPolygonEnd( void );
void	njPtclDrawPolygon( NJS_POINT3 *p, Sint32 n, Float h );
void	njPtclSpriteStart( Sint32 texid, Uint32 col, Sint32 flag );
void	njPtclSpriteEnd( void );
void	njPtclDrawSprite( NJS_POINT3 *p, Sint32 n, Float w, Float h );

#endif
