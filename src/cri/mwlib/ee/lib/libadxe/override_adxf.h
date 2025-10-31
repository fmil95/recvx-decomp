#ifndef _OVERRIDE_ADXF_H_
#define _OVERRIDE_ADXF_H_

#define ADXF_FNAME_MAX    		(256)

typedef struct _adxf_finfo {
    Uint16 flid;
    Uint16 fnsct;
    Sint32 ofst;
} ADXF_FINFO;

#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
	struct _adxf_ptinfo	*next;		
	Sint32				size;		
	Sint32				nfile;		
	Uint16				nentry;		
	Sint8				type;		
	Sint8				rev;		
	Sint8				fname[ADXF_FNAME_MAX];	
	void				*curdir;
	// Sint32			top;	
    ADXF_FINFO          finfo[0];
} ADXF_PTINFO;
#endif 

#define	ADXT_MAX_OBJ		(8)

#endif
