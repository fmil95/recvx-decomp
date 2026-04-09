#ifndef _PS2_SG_SYBT_H_
#define _PS2_SG_SYBT_H_

#include "types.h"
#include "katana_extra.h"
#include "main.h"

// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

Void   syBtExit     ( Void );
Sint32 syBtGetBootSystemID   ( SYS_BT_SYSTEMID* pData );

#endif
