#include "common.h"

void	njWaitVSync( void );
void	njInitVertexBuffer( Sint32 op, Sint32 om, Sint32 tp, Sint32 tm ,Sint32 pt);
void    njPolygonCullingMode( Int mode );
void	njSetBackColor( Uint32 col1, Uint32 col2, Uint32 col3 );
void	njSetBorderColor(Uint32 color );
void	njSetVertexBuffer(Uint32 *buffer,Sint32 size);
void    njTextureShadingMode( Int mode );
