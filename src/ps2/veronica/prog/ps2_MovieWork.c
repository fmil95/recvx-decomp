#include "../../../ps2/veronica/prog/ps2_MovieWork.h"

unsigned char* mpegWork;
VoTag* voBufTag __attribute__((aligned(64)));
VoData* voBufData;
u_long128* viBufTag;
u_long128* viBufData;
READ_BUF* readBuf;
unsigned char* audioBuff;
char* videoDecStack;
TimeStamp* timeStamp;
/*void* vpWorkMemoryTop; - unused */
