/*typedef struct GDS_DCF;*/
typedef struct _anon0;
/*typedef struct GDS_FS_WORK;
typedef struct GDS_FS_LIF;
typedef struct GDS_FS_HANDLE;
typedef struct _anon1;*/
typedef struct _anon2;
/*typedef struct GDS_FS_DIRREC_ENT;
typedef struct GDS_FS_DIRREC_TBL;
typedef struct GDS_FS_DIRINFO;

typedef void(*type_1)(void*);
typedef void(*type_4)(void*);
typedef void(*type_6)(void*, int);
typedef void(*type_15)(void*, int);

typedef GDS_FS_HANDLE type_0[1];
typedef char type_2[16];
typedef unsigned char type_3[8];
typedef char type_5[2048];
typedef char type_7[2048];
typedef _anon1 type_8[0];
typedef char type_9[256];
typedef char type_10[32];
typedef char type_11[2];
typedef GDS_FS_DIRREC_ENT type_12[1];
typedef unsigned char type_13[3];
typedef char type_14[256];
typedef unsigned int type_16[1040];

struct GDS_DCF
{
};*/

typedef struct _anon0
{
	unsigned char trycount;
	unsigned char spindlctrl;
	unsigned char datapattern;
	unsigned char pad;
} _anon0;

/*struct GDS_FS_WORK
{
	int max_open;
	int pathtbl_fad;
	int pathtbl_size;
	GDS_DCF* dcf;
	GDS_FS_DIRREC_TBL* curdir;
	GDS_FS_HANDLE* syshdl;
	GDS_FS_HANDLE* hndtbl;
	GDS_FS_HANDLE* now_work;
	int f_svr;
	void(*g_errcb)(void*, int);
	void* g_errcb_1st;
	int gdc_ver;
	int errstat;
	int istray;
	short f_init;
	short daplayed;
	GDS_FS_LIF* liftbl;
	unsigned int sctbuf[1040];
	GDS_FS_HANDLE hndlist[1];
};

struct GDS_FS_LIF
{
};

struct GDS_FS_HANDLE
{
	GDS_FS_WORK* wk;
	int fid;
	int fad;
	int fsize;
	int fsctsize;
	int ofs;
	int trnsed;
	int rsize;
	int trsize;
	void(*rdendcb)(void*);
	void* rdcb_1st;
	void(*trendcb)(void*);
	void* trcb_1st;
	void(*errcb)(void*, int);
	void* errcb_1st;
	int gdchn;
	int gdchn_wait;
	int ex_errcode;
	short act;
	short trflag;
	short used;
	short tmode;
	short stat;
	short err;
};

struct _anon1
{
	char* file_name;
	char* link_file;
};*/

typedef struct _anon2
{
	unsigned int lsn;
	unsigned int size;
	char name[16];
	unsigned char date[8];
} _anon2;

/*struct GDS_FS_DIRREC_ENT
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char sid;
	char fname[32];
	char pad[2];
};

struct GDS_FS_DIRREC_TBL
{
	int dir_num;
	int max_ent;
	int dir_fad;
	int pad;
	GDS_FS_DIRREC_ENT dirrec_tbl[1];
};

struct GDS_FS_DIRINFO
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char pad[3];
};*/

GDFS_HANDLE* __file_handle;
GDFS_WORK* __gds_fs_work;
GDFS_DIRREC_TBL* __current_dir;
GDFS_DIRREC_ENT* __gdfs_dir_ent;
int dvd_image_data_max = 19;
DVDISO_DATA dvd_image_data[19] = {
	{ "RDX_LNK.AFS" , rdx_files },
    { "SYSTEM.AFS"  , 0 },
    { "MRY.AFS"     , 0 },
    { "ADV.AFS"     , 0 },
	{ "BGM1.AFS"    , 0 },
	{ "ITEM1.AFS"   , 0 },
	{ "MULTSPQ1.AFS", 0 },
	{ "VOICE1.AFS"  , 0 },
	{ "MULTSPQ1.IDX", 0 },
	{ "DISCID.BIN"  , 0 },
	{ "MANATEE.DRV" , 0 },
	{ "COMMON.MLT"  , 0 },
	{ "SYSMES.ALD"  , 0 },
	{ "BIO_CV.ICO"  , 0 },
	{ "BGM2.AFS"    , 0 },
	{ "ITEM2.AFS"   , 0 },
	{ "MULTSPQ2.AFS", 0 },
	{ "VOICE2.AFS"  , 0 },
	{ "MULTSPQ2.IDX", 0 }
}; 

/*void gdFsClose(GDS_FS_HANDLE* gdfs);
GDS_FS_DIRREC_TBL* gdFsCreateDirhn();
void gdFsFinish();
int gdFsGetDirInfo(char* name, GDS_FS_DIRINFO* dirinfo);
int gdFsGetDrvStat();
int gdFsGetFileSize(GDS_FS_HANDLE* gdfs, int* fsize);
int gdFsInit(int max_open, void* gdfs_work, int max_dirent, void* dirbuf);
GDS_FS_HANDLE* gdFsOpen(char* fname);
int gdFsReqDrvStat();
int gdFsSetDir();
void gdFsEntryErrFuncAll();
int gdFsLoadDir();
int gdFsRead(GDS_FS_HANDLE* gdfs, int nsct, void* buf);*/

// 100% matching! 
void  gdFsClose(GDFS gdfs)
{
    gdfs->used = 0;
    
    gdfs->fad = 0;
    
    gdfs->fsize = 0;
    gdfs->fsctsize = 0;
}

// 100% matching!
GDFS_DIRREC  gdFsCreateDirhn(void *dirbuf, Sint32 max_dirent)
{
    return __current_dir;
}

// 100% matching! 
void  gdFsFinish(void)
{
    sceCdInit(SCECdEXIT);
}

// 100% matching! 
Sint32  gdFsGetDirInfo(const char *name, GDFS_DIRINFO *dirinfo)
{
    int i; 
    char read_name[256]; 

    for (i = 0; i < (unsigned int)strlen(name); i++) 
    {
        if ((name[i] >= 'a') && (name[i] <= 'z')) 
        {
            read_name[i] = name[i] - ' ';
        } 
        else
        {
            read_name[i] = name[i];
        }
    } 

    read_name[i] = 0; 
    
    for (i = 0; i < __current_dir->dir_num; i++) 
    {
        if (strcmp(&read_name, __gdfs_dir_ent[i].fname) == 0)
        {
            dirinfo->fad = __gdfs_dir_ent[i].fad;
            
            dirinfo->fsize = __gdfs_dir_ent[i].fsize;
            
            dirinfo->flag = __gdfs_dir_ent[i].flag;
            
            return 0;
        }
    }
    
    return -8; 
}

// 100% matching! 
Sint32  gdFsGetDrvStat(void)
{
    return 2;
}

// 100% matching! 
Bool  gdFsGetFileSize(GDFS gdfs, Sint32 *fsize)
{
    if (gdfs == NULL) 
    {
        return 0;
    }
    
    *fsize = gdfs->fsize;
    
    return 1;
}

// 100% matching!
Sint32  gdFsInit(Sint32 max_open, void *gdfs_work, Sint32 max_dirent, void *dirbuf) 
{
	char local_sector_buffer[2048]; 
	char read_f_name[2048]; 
	sceCdlFILE file_data; 
	unsigned int i; 
	unsigned int j; 
	int link_file_max; 
	int sector_top; 
	int sector_size; 
	int file_size; 
	int file_count; 
    sceCdRMode file_read_mode = 
    {
        0,
        1,
        0,
        0
    }; 
    
    __file_handle = (GDFS_HANDLE*)((int)gdfs_work + 4308);
    
    __gds_fs_work = gdfs_work;
    
    __gds_fs_work->max_open = max_open;
    
    __gds_fs_work->pathtbl_fad = 0;
    __gds_fs_work->pathtbl_size = 0;
    
    __gds_fs_work->dcf = NULL;
    
    __gds_fs_work->curdir = dirbuf;
    
    __gds_fs_work->syshdl = NULL;
    
    __gds_fs_work->hndtbl = NULL;
    
    __gds_fs_work->now_work = NULL;
    
    __gds_fs_work->f_svr = 0;
    
    __gds_fs_work->g_errcb = NULL;
    __gds_fs_work->g_errcb_1st = NULL;
    
    __gds_fs_work->gdc_ver = 65792;
    
    __gds_fs_work->errstat = 0;
    
    __gds_fs_work->istray = 0;
    
    __gds_fs_work->f_init = 1;
    
    __gds_fs_work->daplayed = 0;
    
    __gds_fs_work->liftbl = NULL;

    for (i = 0; i < 1040; i++) 
    {
        __gds_fs_work->sctbuf[i] = 0;
    }
    
    for (i = 0; i < max_open; i++) 
    {
        __file_handle[i].wk = gdfs_work;
        
        __file_handle[i].fid = 0;
        __file_handle[i].fad = 0;
        
        __file_handle[i].fsize = 0;
        __file_handle[i].fsctsize = 0;
        
        __file_handle[i].ofs = 0;
        
        __file_handle[i].trnsed = 0;
        
        __file_handle[i].rsize = 0;
        __file_handle[i].trsize = 0;
        
        __file_handle[i].rdendcb = NULL;
        __file_handle[i].rdcb_1st = NULL;
        
        __file_handle[i].trendcb = NULL;
        __file_handle[i].trcb_1st = NULL;
        
        __file_handle[i].errcb = NULL;
        __file_handle[i].errcb_1st = NULL;
        
        __file_handle[i].gdchn = 0;
        __file_handle[i].gdchn_wait = 0;
        
        __file_handle[i].ex_errcode = 0;
        
        __file_handle[i].act = 0;
        
        __file_handle[i].trflag = 0;
        
        __file_handle[i].used = 0;
        
        __file_handle[i].tmode = 0;
        
        __file_handle[i].stat = 0;
        
        __file_handle[i].err = 0;
    }
    
    __current_dir = dirbuf;
    
    __gdfs_dir_ent = (GDFS_DIRREC_ENT*)((int)dirbuf + 104);
    
    __current_dir->dir_num = 0;
    
    __current_dir->max_ent = max_dirent;
    
    __current_dir->dir_fad = 0;
    
    for (i = 0; i < max_dirent; i++) 
    {
        __gdfs_dir_ent[i].fad = 0;
        
        __gdfs_dir_ent[i].fsize = 0;
        
        __gdfs_dir_ent[i].flag = 0;
        
        __gdfs_dir_ent[i].sid = 0;
        
        __gdfs_dir_ent[i].fname[0] = 0; 
    }
    
    sceCdDiskReady(0);
    
    file_count = 0;

    for (i = 0; i < dvd_image_data_max; i++) 
    {
        for (j = 0; j < strlen(dvd_image_data[i].file_name); j++) 
        {
            if ((dvd_image_data[i].file_name[j] >= 'a') && (dvd_image_data[i].file_name[j] <= 'z')) 
            {
                dvd_image_data[i].file_name[j] = dvd_image_data[i].file_name[j] - 32;
            }
        }
        
        dvd_image_data[i].file_name[j] = 0;
        
        sprintf(read_f_name, "%s%s;1", "\\", dvd_image_data[i].file_name);
        
        while (sceCdSearchFile(&file_data, read_f_name) == 0) 
        {
            int loop;
            
            for (loop = 0; loop < 20; loop++) 
            {
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
            }
            
            printf("found_serach %s\n", read_f_name);
        }
        
        if (dvd_image_data[i].link_file != 0) 
        {
            __gdfs_dir_ent[file_count].fad = file_data.lsn;
            
            __gdfs_dir_ent[file_count].fsize = file_data.size;
            
            __gdfs_dir_ent[file_count].flag = 0;
            
            __gdfs_dir_ent[file_count].sid = 0;
            
            sprintf((char*)__gdfs_dir_ent[file_count].fname, "%s", dvd_image_data[i].file_name);
            
            file_count++;
            
            do 
            {
                while (sceCdRead(file_data.lsn, 1, &local_sector_buffer, &file_read_mode) == 0) 
                {
                    int loop;
                    
                    for (loop = 0; loop < 20; loop++) 
                    {
                        asm("nop");
                        asm("nop");
                        asm("nop");
                        asm("nop");
                    }
                }
                
                sceCdSync(0);
            } while (sceCdGetError() != 0);
            
            link_file_max = ((int*)local_sector_buffer)[1];
            
            sector_top = ((int*)local_sector_buffer)[2] / 2048; 
            
            for (j = 0; j < link_file_max; j++) 
            {
                file_size = ((int*)local_sector_buffer)[(j * 2) + 3]; // fuck knows
                sector_size = (file_size + 2047) / 2048;
                
                __gdfs_dir_ent[file_count].fad = file_data.lsn + sector_top;
                
                __gdfs_dir_ent[file_count].fsize = file_size;
                
                __gdfs_dir_ent[file_count].flag = 0;
                
                __gdfs_dir_ent[file_count].sid = i;
                
                sprintf((char*)__gdfs_dir_ent[file_count].fname, "%s", dvd_image_data[i].link_file[j]);
                
                sector_top += sector_size;
                
                file_count++;
            }
        }
        else
        {
            __gdfs_dir_ent[file_count].fad = file_data.lsn;
            
            __gdfs_dir_ent[file_count].fsize = file_data.size;
            
            __gdfs_dir_ent[file_count].flag = 0;
            
            __gdfs_dir_ent[file_count].sid = 0; 
            
            sprintf((char*)__gdfs_dir_ent[file_count].fname, "%s", dvd_image_data[i].file_name);
            
            file_count++;
        }
    }
    
    __current_dir->dir_num = file_count;
    
    return 0;
}

/*// 
// Start address: 0x2d9720
GDS_FS_HANDLE* gdFsOpen(char* fname)
{
	char read_name[256];
	int j;
	int i;
	// Line 695, Address: 0x2d9720, Func Offset: 0
	// Line 701, Address: 0x2d9738, Func Offset: 0x18
	// Line 703, Address: 0x2d9750, Func Offset: 0x30
	// Line 704, Address: 0x2d9770, Func Offset: 0x50
	// Line 705, Address: 0x2d9774, Func Offset: 0x54
	// Line 707, Address: 0x2d977c, Func Offset: 0x5c
	// Line 709, Address: 0x2d9784, Func Offset: 0x64
	// Line 710, Address: 0x2d97a0, Func Offset: 0x80
	// Line 714, Address: 0x2d97a8, Func Offset: 0x88
	// Line 717, Address: 0x2d97b4, Func Offset: 0x94
	// Line 720, Address: 0x2d97d4, Func Offset: 0xb4
	// Line 723, Address: 0x2d97f4, Func Offset: 0xd4
	// Line 725, Address: 0x2d9800, Func Offset: 0xe0
	// Line 729, Address: 0x2d9820, Func Offset: 0x100
	// Line 730, Address: 0x2d9850, Func Offset: 0x130
	// Line 729, Address: 0x2d9854, Func Offset: 0x134
	// Line 730, Address: 0x2d9858, Func Offset: 0x138
	// Line 731, Address: 0x2d9870, Func Offset: 0x150
	// Line 730, Address: 0x2d9874, Func Offset: 0x154
	// Line 731, Address: 0x2d9878, Func Offset: 0x158
	// Line 751, Address: 0x2d989c, Func Offset: 0x17c
	// Line 753, Address: 0x2d98b0, Func Offset: 0x190
	// Line 754, Address: 0x2d98c4, Func Offset: 0x1a4
	// Line 753, Address: 0x2d98c8, Func Offset: 0x1a8
	// Line 755, Address: 0x2d98cc, Func Offset: 0x1ac
	// Line 756, Address: 0x2d98e8, Func Offset: 0x1c8
	// Func End, Address: 0x2d9900, Func Offset: 0x1e0
}*/

// 100% matching! 
Sint32  gdFsReqDrvStat(void)
{
    return 0;
}

// 100% matching!
Sint32  gdFsSetDir(GDFS_DIRREC gf_dirrec)
{
    return 0;
}

// 100% matching!
void  gdFsEntryErrFuncAll(GDFS_ERRFUNC erfunc, void *obj)
{

}

// 100% matching!
Sint32  gdFsLoadDir(const char *dirname, GDFS_DIRREC gf_dirrec)
{
    return 0;
}

// 100% matching! 
Sint32  gdFsRead(GDFS gdfs, Sint32 nsct, void *buf)
{
    sceCdRMode read_mode;
    int loop;

    read_mode.trycount = 0;
    
    read_mode.spindlctrl = 1;
    
    read_mode.datapattern = 0;
    
    do 
    {
        while (sceCdRead(gdfs->fad, nsct, buf, &read_mode) == 0)
        {
            for (loop = 0; loop < 20; loop++) 
            {
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
            }
        }
        
        sceCdSync(0);
    } while (sceCdGetError() != 0);
    
    return 0;
}
