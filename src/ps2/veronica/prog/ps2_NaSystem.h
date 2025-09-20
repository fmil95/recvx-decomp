#ifndef _PS2_NASYSTEM_H_
#define _PS2_NASYSTEM_H_

void	njSetTextureMemorySize(Uint32 size );
void	njSetVertexBuffer(Uint32 *buffer,Sint32 size);
void	njInitSystem( Int, Int, Int );
void	njInitVertexBuffer( Sint32 op, Sint32 om, Sint32 tp, Sint32 tm ,Sint32 pt);
void njWaitVSync(void);
void null_func();
void Ps2InitFunc();
void 	njSetEORFunction( void (*func)(void) );
void Ps2SwapDBuff();
int vsync_func(int);
void Ps2SetVSyncCounter();
void	njSetVSyncFunction( void (*func)(void) );
void	njExitSystem( void );
void	njSetBackColor( Uint32 col1, Uint32 col2, Uint32 col3 );
void	njTextureFilterMode( Int mode );
void    njPolygonCullingMode( Int mode );
void njColorBlendingModeSys(int s_mode, int d_mode);
void    njColorBlendingMode( Int target, Int mode );
void    njTextureShadingMode( Int mode );
void    njSetCheapShadowMode( Int mode );
void	njUserClipping(Int mode ,NJS_POINT2 *p);
void    njGetSystemAttr(NJS_SYS_ATTR *attr);
void    njSetSystemAttr(NJS_SYS_ATTR *attr);
void    njChangeSystem( Int mode, Int frame, Int count );
void	njAdjustDisplay(Sint32 xadjust,Sint32 yadjust );
void	njSetBorderColor(Uint32 color );

#endif
