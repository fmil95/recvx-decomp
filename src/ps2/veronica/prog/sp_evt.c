#include "../../../ps2/veronica/prog/sp_evt.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_sg_syrtc.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

//#include <string.h>

typedef void (*bhCtrSpEvtCom_mode0_proc)();

char* comevt_message_tst[27] = 
{
    "COMPUTER SYSTEM Ver0.01",
    "Test message....",
    "--[Check change color.]--",
    "'Red'   color",
    "'Green' color",
    "'Blue'  color",
    "--[Check wait command.]--",
    "Wait",
    "--[Check scroll text.]--",
    ".A",
    "..B",
    "...C",
    "....D",
    ".....E",
    "......F",
    ".......G",
    "........H",
    "--[Check button wait.]--",
    "--[Check soft keyboard.]--",
    "Enter pass code_A.",
    ">",
    "Enter pass code_B.",
    "JHON",
    "ASTOR",
    "------------- Ok!",
    "---------- Error!",
    "--[ End of script! ]--",
};
unsigned char comevt_script_tst[181] =
{
    0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE0, 0x02, 0xFE, 0xE3, 0xE0, 0x00,
    0x00, 0xE0, 0x03, 0xFE, 0xE3, 0x00, 0xE0, 0x00, 0xE0, 0x04, 0xFE, 0xE3,
    0x00, 0x00, 0xE0, 0xE0, 0x05, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x06,
    0xFE, 0xE0, 0x07, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4,
    0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4,
    0x2E, 0xE1, 0x0F, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09, 0xFE, 0xE0, 0x0A,
    0xFE, 0xE0, 0x0B, 0xFE, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E,
    0xFE, 0xE0, 0x0F, 0xFE, 0xE0, 0x10, 0xFE, 0xFE, 0xE0, 0x11, 0xE2, 0xFE,
    0xE0, 0x12, 0xFE, 0xEB, 0x00, 0xE0, 0x13, 0xFE, 0xE0, 0x14, 0xE5, 0x08,
    0x00, 0xFE, 0xE0, 0x15, 0xFE, 0xE0, 0x14, 0xE9, 0xFE, 0xE6, 0xEA, 0x00,
    0x16, 0x00, 0xEA, 0x01, 0x17, 0x01, 0xED, 0x00, 0x01, 0xEC, 0x02, 0xEB,
    0x01, 0xED, 0x01, 0x03, 0xEB, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x19,
    0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xEC, 0x00, 0xEB, 0x03, 0xE3, 0x00, 0xE0,
    0xE0, 0xE0, 0x18, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xEB, 0x04, 0xE7, 0xEF,
    0x1F, 0x00, 0xEE, 0x00, 0x00, 0x01, 0x00, 0xE2, 0xE0, 0x1A, 0xE1, 0x1E,
    0xFF,
};
QUAD acs_no0[1] = 
{
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no1[19] = 
{
    "Self-destruct Safety ",
    "Lock Release System.",
    "Please enter the ",
    "security code.",
    ">",
    "Verification in progress.",
    "Please wait",
    "The security code has ",
    "been confirmed. The ",
    "Self-destruct Safety",
    "Lock Release System has ",
    "been released.",
    "All door locks have ",
    "been released in order ",
    "to help expedite the ",
    "evacuation process.",
    "ERROR. Security code ",
    "does not match. ",
    "VERONICA",
};
unsigned char comevt_script_no1[141] = 
{
    0xF1, 0x15, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE2, 0xFE, 0xEB,
    0x00, 0xF4, 0xF1, 0x16, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0,
    0x04, 0xE2, 0xF2, 0xE5, 0x08, 0x00, 0xF5, 0xE6, 0xFE, 0xFE, 0xEA, 0x00,
    0x12, 0x00, 0xF1, 0x18, 0x02, 0xE0, 0x05, 0xFE, 0xE0, 0x06, 0xE4, 0x2E,
    0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E,
    0xE1, 0x0F, 0xFE, 0xED, 0x00, 0x01, 0xF1, 0x1B, 0x02, 0xE3, 0xE0, 0x00,
    0x00, 0xFE, 0xE0, 0x10, 0xFE, 0xE0, 0x11, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF,
    0xE2, 0xFE, 0xF3, 0xEC, 0x00, 0xEB, 0x01, 0xF1, 0x19, 0x02, 0xE3, 0x00,
    0xE0, 0xE0, 0xFE, 0xE0, 0x07, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09, 0xFE,
    0xE0, 0x0A, 0xFE, 0xE0, 0x0B, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xE2, 0xFE,
    0xF1, 0x1A, 0x02, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E, 0xFE,
    0xE0, 0x0F, 0xFE, 0xF0, 0x05, 0x00, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no1[8] =
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 448.0f, 64.0f, 608.0f, 216.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 32.0f, 256.0f, 104.0f, 336.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 560.0f, 40.0f, 628.0f, 100.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 560.0f, 120.0f, 628.0f, 180.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no2[17] = 
{
    "Security lock system",          
    "is active.",                    
    "Enter an employee ID to",       
    "activate the unlocking",        
    "device.",                       
    "Please enter your ID",          
    "number.",                       
    ">",                             
    "ID verification in ",           
    "progress. Please wait",         
    "ID verification has been",      
    "confirmed.",                    
    "The Security Lock System",      
    "is deactivated.",               
    "ERROR. ID verification ",       
    "has been rejected.",            
    "NTC0394"                        
};
unsigned char comevt_script_no2[140] = 
{
    0xF1, 0x00, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE2, 0xFE, 0xF1,
    0x01, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE2,
    0xFE, 0xEB, 0x00, 0xF4, 0xF1, 0x0B, 0x02, 0xE0, 0x05, 0xFE, 0xE0, 0x06,
    0xFE, 0xE0, 0x07, 0xE2, 0xF2, 0xE5, 0x08, 0x00, 0xF5, 0xE6, 0xFE, 0xFE,
    0xEA, 0x00, 0x10, 0x00, 0xF1, 0x0C, 0x02, 0xE0, 0x08, 0xFE, 0xE0, 0x09,
    0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F,
    0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xED, 0x00, 0x01, 0xF1, 0x02, 0x02, 0xE3,
    0xE0, 0x00, 0x00, 0xFE, 0xE0, 0x0E, 0xFE, 0xE0, 0x0F, 0xFE, 0xE3, 0xFF,
    0xFF, 0xFF, 0xE2, 0xFE, 0xF3, 0xEC, 0x00, 0xEB, 0x01, 0xF1, 0x03, 0x02,
    0xE3, 0x00, 0xE0, 0xE0, 0xFE, 0xE0, 0x0A, 0xFE, 0xE0, 0x0B, 0xFE, 0xE3,
    0xFF, 0xFF, 0xFF, 0xE2, 0xFE, 0xF1, 0x0F, 0x02, 0xE0, 0x0C, 0xFE, 0xE0,
    0x0D, 0xFE, 0xF0, 0x04, 0x00, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no2[9] = 
{
    { 424.0f, 120.0f, 584.0f, 280.0f, 0.6875f, 0.609375f, 1.0f, 0.921875f },
    { 416.0f, 104.0f, 600.0f, 296.0f, 0.0f, 0.0f, 0.359375f, 0.375f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no3[23] = 
{
    "--- THE ALBINOID ---",              
    "--- DESCRIPTION  ---",              
    "A creature which is",               
    "created by injecting the",          
    "T-virus into the genes of",         
    "a salamander.",                     
    "--- CHARACTERISTICS ---",           
    "Similar to a normal ",              
    "amphibian, an Albinoid's",          
    "body will change as it ",           
    "grows with age.",                   
    "When young, an Albinoid",           
    "is small in size, but it ",         
    "can grow to over seven ",           
    "feet in a very short time",         
    "frame (10+ hours).",                
    "They possess high ",                
    "mobility and are able ",            
    "to discharge electricity.",         
    "These characteristics are",         
    "most notable when they ",           
    "are under water in their",          
    "adult form."                        
};
unsigned char comevt_script_no3[126] = 
{
    0xF1, 0x0B, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xFE, 0xE0, 0x01,
    0xFE, 0xE2, 0xFE, 0xF1, 0x0C, 0x02, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x02,
    0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE0, 0x05, 0xFE, 0xE2, 0xFE,
    0xF1, 0x0D, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x06, 0xFE, 0xE2, 0xFE,
    0xE7, 0xEF, 0x03, 0x00, 0xEE, 0x00, 0x00, 0x01, 0x00, 0xF1, 0x0E, 0x02,
    0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09,
    0xFE, 0xE0, 0x0A, 0xFE, 0xE2, 0xFE, 0xF1, 0x0F, 0x02, 0xE0, 0x0B, 0xFE,
    0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E, 0xFE, 0xE0, 0x0F, 0xFE,
    0xE2, 0xFE, 0xF1, 0x10, 0x02, 0xE0, 0x10, 0xFE, 0xE0, 0x11, 0xFE, 0xE0,
    0x12, 0xFE, 0xE0, 0x13, 0xFE, 0xE0, 0x14, 0xFE, 0xE0, 0x15, 0xFE, 0xE0,
    0x16, 0xFE, 0xE2, 0xFE, 0xF2, 0xFF,
};
QUAD acs_no3[8] = 
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
const char* comevt_message_no4[20] = 
{
    "Activating the enhanced",      
    "3D scanner...",                
    "Please place the material",    
    "you wish to have scanned",     
    "on the scanner portion",       
    "of this machine.",             
    "Scanning in progress.",        
    "Please wait...",               
    "Scanning complete.",           
    "Transmitting the data.",       
    "Please wait",                  
    "Transmission complete.",       
    "Please place the material",    
    "you wish to have",             
    "converted on the",             
    "duplicator portion of",        
    "this machine.",                
    "Duplication in progress.",     
    "Please wait...",               
    "Duplication complete."         
};
unsigned char comevt_script_no4[41] = 
{
    0xF5, 0xF1, 0x05, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xE4, 0x2E, 0xE1,
    0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xFE, 0xF1,
    0x07, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE0,
    0x05, 0xFE, 0xE2, 0xF2, 0xFF,
};
unsigned char comevt_script_no5[83] = 
{
    0xF5, 0xF1, 0x09, 0x02, 0xE3, 0x00, 0xE0, 0xE0, 0xE0, 0x08, 0xFE, 0xE2,
    0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xF1, 0x0A, 0x02, 0xE0, 0x09, 0xFE, 0xE0,
    0x0A, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1,
    0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xFE, 0xF1,
    0x0B, 0x02, 0xE3, 0x00, 0xE0, 0x00, 0xE0, 0x0B, 0xFE, 0xE3, 0xFF, 0xFF,
    0xFF, 0xFE, 0xF1, 0x08, 0x02, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0,
    0x0E, 0xFE, 0xE0, 0x0F, 0xFE, 0xE0, 0x10, 0xFE, 0xE2, 0xF2, 0xFF,
};
unsigned char comevt_script_no6[18] = 
{
    0xF5, 0xF1, 0x0E, 0x02, 0xE3, 0x00, 0xE0, 0xE0, 0xE0, 0x13, 0xFE, 0xE3,
    0xFF, 0xFF, 0xFF, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no4[9] = 
{
    { 424.0f, 120.0f, 584.0f, 280.0f, 0.375f, 0.609375f, 0.6875f, 0.921875f },
    { 416.0f, 104.0f, 600.0f, 296.0f, 0.0f, 0.0f, 0.359375f, 0.375f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no7[4] =
{
    "Please enter the ",
    "password.",        
    ">",                
    "1971"              
};
unsigned char comevt_script_no7[40] = 
{
    0xF1, 0x06, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE0, 0x02, 0xE2,
    0xF2, 0xE5, 0x04, 0x01, 0xF5, 0xE6, 0xFE, 0xFE, 0xEA, 0x00, 0x03, 0x00,
    0xED, 0x00, 0x00, 0xF0, 0x3E, 0x00, 0xEC, 0x01, 0xEB, 0x00, 0xF0, 0x3D,
    0x00, 0xEB, 0x01, 0xFF,
};
QUAD acs_no7[8] = 
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 448.0f, 30.0f, 616.0f, 166.0f, 0.0f, 0.5390625f, 0.328125f, 0.8046875f },
    { 32.0f, 64.0f, 104.0f, 144.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 284.0f, 132.0f, 344.0f, 0.7265625f, 0.0f, 0.859375f, 0.1171875f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.8671875f, 0.0f, 1.0f, 0.1171875f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
void* comevt_message_tab[8] = 
{
	comevt_message_tst,
	comevt_message_no1,
	comevt_message_no2,
	comevt_message_no3,
	comevt_message_no4,
	comevt_message_no4,
	comevt_message_no4,
	comevt_message_no7
};
void* comevt_script_tab[8] = 
{
	comevt_script_tst,
	comevt_script_no1,
	comevt_script_no2,
	comevt_script_no3,
	comevt_script_no4,
	comevt_script_no5,
	comevt_script_no6,
	comevt_script_no7
};
void* comevt_acs_tab[8] = 
{
	acs_no0,
	acs_no1,
	acs_no2,
	acs_no3,
	acs_no4,
	acs_no4,
	acs_no4,
	acs_no7
};
bhCtrSpEvtCom_mode0_proc bhCtrSpEvtCom_mode0[3] = 
{
	bhInitSpEvtComputer,
	bhMainSpEvtComputer,
	bhExitSpEvtComputer
};

// 100% matching!
void bhControlSpEvtComputer()
{
	bhCtrSpEvtCom_mode0[sys->com_md0]();
}

// 100% matching!
void bhKeepSpEvtComputer()
{
    if (!(sys->com_flg & 0x1))
    {
        sys->com_flg |= 0x1;
        
        sys->com_exp = bhGetFreeMemory(sizeof(COM_EVT_WORK), 32);
    }
}

// 100% matching!
void bhInitSpEvtComputer() 
{
    COM_EVT_WORK* ce;
    int i;           
    
    sys->com_flg &= 0x1;
    
    ce = sys->com_exp;
    
    npSetMemory((unsigned char*)ce, sizeof(COM_EVT_WORK), 0);
    
    sys->com_md0 = 1;
    sys->com_md1 = 0;
    
    ce->scp = comevt_script_tab[sys->com_num];
    
    bhInitComEvtScript(1);
    
    njMemCopy4(&palbuf[3072], palbuf, 1024);
    
    ce->com_tlist.textures  = ce->com_tex;
    ce->com_tlist.nbTexture = bhSetMemPvpTexture(&ce->com_tlist, sys->subtxp, 0);
    
    ce->fcol = 0xFF000000;
    ce->fsrc = 1.0f;
    
    bhSetSpEvtComFade(0, 10.0f);
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    for (i = 0; i < 3; i++) 
    {
        ce->bar[i][0] = ce->bar[i][1] = ((7 - (i - 1)) * 6) + (((i + 1) * 30) * (-rand() / -2.1474836E9f));
        
        ce->bar_ct[i] = 30.0f * (-rand() / -2.1474836E9f);
    } 
    
    if (sys->com_num == 1) 
    {
        sys->com_flg |= 0x4;
    }
    
    if (syRtcInit() == 0)
    {
        sys->com_flg |= 0x100;
    }
}

// 100% matching!
void bhMainSpEvtComputer() 
{
    COM_EVT_WORK* ce; 
    NJS_LINE line;    
    
    ce = sys->com_exp;
    
    switch (sys->com_md1)
    {                              
    case 0:
        if (!(sys->com_flg & 0x2))
        {
            break;
        }
        
        sys->com_md1++;
        
        CallSystemSe(0, 0x8000026A);
        
        ce->ct0 = 0;
    case 1: 
        line.px = 32.0f;
        line.py = 32.0f;
        
        line.vx = 512.0f * njSin(ce->ct0 * 2048);
        line.vy = 256.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_flg |= 0x8;
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
    
        break;
    case 2:
        ce->ct0 += 2048;
        
        ce->mwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384) 
        {
            sys->com_md1 = 10;
            
            ce->mwin_alp = 255;
        }
        
        break;
    case 3:
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0 * 2048);
        line.vy = 192.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
        
        break;
    case 4:
        ce->ct0 += 2048;
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384)
        {
            sys->com_md1 = 10;
            
            ce->swin_alp = 255;
        }
        
        break;
    case 5:
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0 * 2048);
        line.vy = 160.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_flg |= 0x20;
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
        
        break;
    case 6:
        ce->ct0 += 2048;
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384) 
        {
            sys->com_md1 = 10;
            
            ce->cwin_alp = 255;
        }
        
        break;
    case 10:
        bhControlComEvtScript(&sys->com_md1);
        
        if (((sys->com_flg & 0x10)) && ((ce->txflg & 0x8))) 
        {
            bhControlComEvtKeyboard();
        }
        
        if (((sys->pad_ps & 0x1000)) && (!(sys->com_flg & 0x200))) 
        {
            ce->ct0 = 0;
            
            sys->com_md1 = 20;
        }
        
        break;
    case 18:
        ce->ct0 -= 2048;
        
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0);
        line.vy = 160.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1 = 10;
            
            ce->cwin_alp = 0;
        }
        
        break;
    case 19:
        ce->ct0 -= 2048;
        
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 192.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1 = 10;
            
            ce->swin_alp = 0;
        }
        
        break;
    case 20:
        sys->com_flg &= ~0x80;
        
        if (!(sys->com_flg & 0x10)) 
        {
            sys->com_md1 = 22;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
        } 
        else 
        {
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1++;
        }
        
        break;
    case 21:
        ce->ct0 -= 2048;
        
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 192.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1++;
            
            ce->swin_alp = 0;
            ce->ct0      = 16384;
        }
        
        break;
    case 22:
        if (!(sys->com_flg & 0x20))
        {
            sys->com_md1 = 24;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
        } 
        else
        {
            sys->com_flg &= ~0x40;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1++;
        }
        
        break;
    case 23:
        ce->ct0 -= 2048;
        
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0);
        line.vy = 160.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1++;
            
            ce->cwin_alp = 0;
            ce->ct0      = 16384;
            
            CallSystemSe(0, 0x8000026A);
        }
        
        break;
    case 24:
        if ((sys->com_flg & 0x8)) 
        {
            sys->com_flg &= ~0x8;
            
            bhClearComEvtText();
        }
        
        ce->ct0 -= 2048;
        
        line.px = 32.0f;
        line.py = 32.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 256.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->mwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            bhSetSpEvtComFade(1.0f, 5.0f);
            
            sys->com_md1 = 30;
            
            ce->mwin_alp = 0;
            ce->ct0      = 0;
        }
        
        break;
    case 30:
        if (!(sys->com_flg & 0x2)) 
        {
            *(int*)&sys->com_md0 = 2;
            return;
        }
        
        break;
    }
    
    bhEntrySpEvtComputer();
    
    if ((sys->com_flg & 0x2)) 
    {
        bhCalcSpEvtComFade();
    }
    
    if (ce->fcol != 0) 
    {
        bhDrawSpEvtComFade();
    }
    
    bhDrawSpEvtBoxLine();
    bhDrawSpEvtComputer();
}

// 100% matching!
void bhExitSpEvtComputer()
{
    COM_EVT_WORK* ce;
    
    ce = sys->com_exp;

    if ((sys->com_flg & 0x100))
    {
        syRtcFinish();
    }
    
    njReleaseTexture(&ce->com_tlist);
    
    bhGarbageTexture(NULL, 0);

    if (rom->mdl.texP != NULL)
    {
        bhCopyMainmem2Texmem(rom->mdl.texP);
    }
    
    njMemCopy4(palbuf, &palbuf[3072], 1024);
    
    sys->gm_flg |= 0x4;
    
    bhSetScreenFade(sys->fade_pbk, 3.0f);
    
    sys->sp_flg = -1;
    
    sys->bcl_ct = 0;
    
    sys->gm_flg |=  0x8000;
    
    sys->st_flg &= ~0x4000000;
    
    sys->cb_flg &= ~0x400000;   
    
    sys->ts_flg |=  0x20000;
    sys->ts_flg &= ~0x80;
    
    sys->memp = sys->sbs_sp;
    
    bhStandPlayerMotion();
}

// 
// Start address: 0x2bdf70
void bhEntrySpEvtComputer()
{
	float on;
	float cy;
	unsigned int a;
	unsigned int asc;
	unsigned int dat;
	int qtect;
	int j;
	int i;
	//_anon7* ce;
	unsigned int* qtbcol;
	//_anon20* tbl;
	//_anon20* qt;
	// Line 416, Address: 0x2bdf70, Func Offset: 0
	// Line 419, Address: 0x2bdf8c, Func Offset: 0x1c
	// Line 429, Address: 0x2bdf94, Func Offset: 0x24
	// Line 430, Address: 0x2bdf98, Func Offset: 0x28
	// Line 419, Address: 0x2bdf9c, Func Offset: 0x2c
	// Line 427, Address: 0x2bdfa8, Func Offset: 0x38
	// Line 428, Address: 0x2bdfac, Func Offset: 0x3c
	// Line 429, Address: 0x2bdfb0, Func Offset: 0x40
	// Line 430, Address: 0x2bdfb4, Func Offset: 0x44
	// Line 431, Address: 0x2bdfb8, Func Offset: 0x48
	// Line 423, Address: 0x2bdfc0, Func Offset: 0x50
	// Line 431, Address: 0x2bdfc4, Func Offset: 0x54
	// Line 432, Address: 0x2bdfdc, Func Offset: 0x6c
	// Line 433, Address: 0x2bdfe0, Func Offset: 0x70
	// Line 434, Address: 0x2bdfe4, Func Offset: 0x74
	// Line 435, Address: 0x2bdfec, Func Offset: 0x7c
	// Line 436, Address: 0x2bdff0, Func Offset: 0x80
	// Line 437, Address: 0x2bdff8, Func Offset: 0x88
	// Line 438, Address: 0x2bdffc, Func Offset: 0x8c
	// Line 439, Address: 0x2be004, Func Offset: 0x94
	// Line 440, Address: 0x2be00c, Func Offset: 0x9c
	// Line 443, Address: 0x2be014, Func Offset: 0xa4
	// Line 445, Address: 0x2be020, Func Offset: 0xb0
	// Line 449, Address: 0x2be028, Func Offset: 0xb8
	// Line 450, Address: 0x2be030, Func Offset: 0xc0
	// Line 451, Address: 0x2be034, Func Offset: 0xc4
	// Line 452, Address: 0x2be03c, Func Offset: 0xcc
	// Line 453, Address: 0x2be044, Func Offset: 0xd4
	// Line 454, Address: 0x2be048, Func Offset: 0xd8
	// Line 455, Address: 0x2be050, Func Offset: 0xe0
	// Line 456, Address: 0x2be058, Func Offset: 0xe8
	// Line 458, Address: 0x2be060, Func Offset: 0xf0
	// Line 463, Address: 0x2be06c, Func Offset: 0xfc
	// Line 461, Address: 0x2be070, Func Offset: 0x100
	// Line 463, Address: 0x2be074, Func Offset: 0x104
	// Line 458, Address: 0x2be078, Func Offset: 0x108
	// Line 461, Address: 0x2be084, Func Offset: 0x114
	// Line 462, Address: 0x2be088, Func Offset: 0x118
	// Line 463, Address: 0x2be08c, Func Offset: 0x11c
	// Line 464, Address: 0x2be090, Func Offset: 0x120
	// Line 465, Address: 0x2be098, Func Offset: 0x128
	// Line 466, Address: 0x2be09c, Func Offset: 0x12c
	// Line 467, Address: 0x2be0a0, Func Offset: 0x130
	// Line 468, Address: 0x2be0a8, Func Offset: 0x138
	// Line 470, Address: 0x2be0ac, Func Offset: 0x13c
	// Line 469, Address: 0x2be0b8, Func Offset: 0x148
	// Line 448, Address: 0x2be0bc, Func Offset: 0x14c
	// Line 470, Address: 0x2be0c0, Func Offset: 0x150
	// Line 473, Address: 0x2be0dc, Func Offset: 0x16c
	// Line 470, Address: 0x2be0e4, Func Offset: 0x174
	// Line 473, Address: 0x2be0e8, Func Offset: 0x178
	// Line 474, Address: 0x2be100, Func Offset: 0x190
	// Line 475, Address: 0x2be108, Func Offset: 0x198
	// Line 476, Address: 0x2be110, Func Offset: 0x1a0
	// Line 477, Address: 0x2be118, Func Offset: 0x1a8
	// Line 478, Address: 0x2be120, Func Offset: 0x1b0
	// Line 479, Address: 0x2be124, Func Offset: 0x1b4
	// Line 480, Address: 0x2be12c, Func Offset: 0x1bc
	// Line 481, Address: 0x2be134, Func Offset: 0x1c4
	// Line 483, Address: 0x2be138, Func Offset: 0x1c8
	// Line 485, Address: 0x2be150, Func Offset: 0x1e0
	// Line 486, Address: 0x2be160, Func Offset: 0x1f0
	// Line 487, Address: 0x2be16c, Func Offset: 0x1fc
	// Line 488, Address: 0x2be174, Func Offset: 0x204
	// Line 489, Address: 0x2be180, Func Offset: 0x210
	// Line 491, Address: 0x2be1bc, Func Offset: 0x24c
	// Line 494, Address: 0x2be1c8, Func Offset: 0x258
	// Line 491, Address: 0x2be1cc, Func Offset: 0x25c
	// Line 492, Address: 0x2be1d0, Func Offset: 0x260
	// Line 493, Address: 0x2be1d8, Func Offset: 0x268
	// Line 491, Address: 0x2be1dc, Func Offset: 0x26c
	// Line 492, Address: 0x2be1e0, Func Offset: 0x270
	// Line 493, Address: 0x2be1e4, Func Offset: 0x274
	// Line 492, Address: 0x2be1e8, Func Offset: 0x278
	// Line 495, Address: 0x2be1ec, Func Offset: 0x27c
	// Line 496, Address: 0x2be1f4, Func Offset: 0x284
	// Line 492, Address: 0x2be1f8, Func Offset: 0x288
	// Line 493, Address: 0x2be1fc, Func Offset: 0x28c
	// Line 494, Address: 0x2be200, Func Offset: 0x290
	// Line 496, Address: 0x2be204, Func Offset: 0x294
	// Line 497, Address: 0x2be208, Func Offset: 0x298
	// Line 493, Address: 0x2be210, Func Offset: 0x2a0
	// Line 498, Address: 0x2be214, Func Offset: 0x2a4
	// Line 493, Address: 0x2be218, Func Offset: 0x2a8
	// Line 494, Address: 0x2be220, Func Offset: 0x2b0
	// Line 498, Address: 0x2be224, Func Offset: 0x2b4
	// Line 494, Address: 0x2be228, Func Offset: 0x2b8
	// Line 495, Address: 0x2be234, Func Offset: 0x2c4
	// Line 496, Address: 0x2be238, Func Offset: 0x2c8
	// Line 497, Address: 0x2be23c, Func Offset: 0x2cc
	// Line 498, Address: 0x2be248, Func Offset: 0x2d8
	// Line 499, Address: 0x2be250, Func Offset: 0x2e0
	// Line 501, Address: 0x2be258, Func Offset: 0x2e8
	// Line 502, Address: 0x2be27c, Func Offset: 0x30c
	// Line 503, Address: 0x2be284, Func Offset: 0x314
	// Line 504, Address: 0x2be288, Func Offset: 0x318
	// Line 501, Address: 0x2be28c, Func Offset: 0x31c
	// Line 505, Address: 0x2be298, Func Offset: 0x328
	// Line 507, Address: 0x2be29c, Func Offset: 0x32c
	// Line 508, Address: 0x2be2a0, Func Offset: 0x330
	// Line 501, Address: 0x2be2a4, Func Offset: 0x334
	// Line 507, Address: 0x2be2b0, Func Offset: 0x340
	// Line 508, Address: 0x2be2b4, Func Offset: 0x344
	// Line 502, Address: 0x2be2b8, Func Offset: 0x348
	// Line 503, Address: 0x2be2c4, Func Offset: 0x354
	// Line 504, Address: 0x2be2c8, Func Offset: 0x358
	// Line 505, Address: 0x2be2cc, Func Offset: 0x35c
	// Line 502, Address: 0x2be2d0, Func Offset: 0x360
	// Line 503, Address: 0x2be2f8, Func Offset: 0x388
	// Line 504, Address: 0x2be308, Func Offset: 0x398
	// Line 505, Address: 0x2be318, Func Offset: 0x3a8
	// Line 506, Address: 0x2be348, Func Offset: 0x3d8
	// Line 507, Address: 0x2be370, Func Offset: 0x400
	// Line 508, Address: 0x2be37c, Func Offset: 0x40c
	// Line 511, Address: 0x2be388, Func Offset: 0x418
	// Line 510, Address: 0x2be38c, Func Offset: 0x41c
	// Line 511, Address: 0x2be390, Func Offset: 0x420
	// Line 512, Address: 0x2be3b0, Func Offset: 0x440
	// Line 511, Address: 0x2be3b4, Func Offset: 0x444
	// Line 512, Address: 0x2be3b8, Func Offset: 0x448
	// Line 513, Address: 0x2be3c0, Func Offset: 0x450
	// Line 512, Address: 0x2be3c4, Func Offset: 0x454
	// Line 516, Address: 0x2be3dc, Func Offset: 0x46c
	// Line 517, Address: 0x2be3fc, Func Offset: 0x48c
	// Line 518, Address: 0x2be404, Func Offset: 0x494
	// Line 519, Address: 0x2be40c, Func Offset: 0x49c
	// Line 520, Address: 0x2be414, Func Offset: 0x4a4
	// Line 521, Address: 0x2be41c, Func Offset: 0x4ac
	// Line 522, Address: 0x2be420, Func Offset: 0x4b0
	// Line 523, Address: 0x2be424, Func Offset: 0x4b4
	// Line 524, Address: 0x2be42c, Func Offset: 0x4bc
	// Line 526, Address: 0x2be430, Func Offset: 0x4c0
	// Line 528, Address: 0x2be434, Func Offset: 0x4c4
	// Line 529, Address: 0x2be438, Func Offset: 0x4c8
	// Line 530, Address: 0x2be43c, Func Offset: 0x4cc
	// Line 531, Address: 0x2be440, Func Offset: 0x4d0
	// Line 534, Address: 0x2be444, Func Offset: 0x4d4
	// Line 526, Address: 0x2be448, Func Offset: 0x4d8
	// Line 528, Address: 0x2be454, Func Offset: 0x4e4
	// Line 529, Address: 0x2be458, Func Offset: 0x4e8
	// Line 530, Address: 0x2be45c, Func Offset: 0x4ec
	// Line 531, Address: 0x2be460, Func Offset: 0x4f0
	// Line 532, Address: 0x2be464, Func Offset: 0x4f4
	// Line 533, Address: 0x2be468, Func Offset: 0x4f8
	// Line 534, Address: 0x2be46c, Func Offset: 0x4fc
	// Line 535, Address: 0x2be470, Func Offset: 0x500
	// Line 537, Address: 0x2be478, Func Offset: 0x508
	// Line 536, Address: 0x2be484, Func Offset: 0x514
	// Line 538, Address: 0x2be488, Func Offset: 0x518
	// Line 537, Address: 0x2be48c, Func Offset: 0x51c
	// Line 541, Address: 0x2be49c, Func Offset: 0x52c
	// Line 542, Address: 0x2be4ac, Func Offset: 0x53c
	// Line 543, Address: 0x2be4b8, Func Offset: 0x548
	// Line 544, Address: 0x2be4c8, Func Offset: 0x558
	// Line 545, Address: 0x2be4d0, Func Offset: 0x560
	// Line 546, Address: 0x2be4d4, Func Offset: 0x564
	// Line 544, Address: 0x2be4dc, Func Offset: 0x56c
	// Line 546, Address: 0x2be4e0, Func Offset: 0x570
	// Line 547, Address: 0x2be4ec, Func Offset: 0x57c
	// Line 548, Address: 0x2be4fc, Func Offset: 0x58c
	// Line 549, Address: 0x2be504, Func Offset: 0x594
	// Line 551, Address: 0x2be50c, Func Offset: 0x59c
	// Line 552, Address: 0x2be514, Func Offset: 0x5a4
	// Line 554, Address: 0x2be518, Func Offset: 0x5a8
	// Line 555, Address: 0x2be52c, Func Offset: 0x5bc
	// Line 556, Address: 0x2be560, Func Offset: 0x5f0
	// Line 557, Address: 0x2be564, Func Offset: 0x5f4
	// Line 558, Address: 0x2be568, Func Offset: 0x5f8
	// Line 559, Address: 0x2be570, Func Offset: 0x600
	// Line 561, Address: 0x2be57c, Func Offset: 0x60c
	// Line 559, Address: 0x2be580, Func Offset: 0x610
	// Line 562, Address: 0x2be584, Func Offset: 0x614
	// Line 563, Address: 0x2be588, Func Offset: 0x618
	// Line 559, Address: 0x2be58c, Func Offset: 0x61c
	// Line 561, Address: 0x2be590, Func Offset: 0x620
	// Line 559, Address: 0x2be598, Func Offset: 0x628
	// Line 563, Address: 0x2be59c, Func Offset: 0x62c
	// Line 559, Address: 0x2be5a0, Func Offset: 0x630
	// Line 560, Address: 0x2be5b0, Func Offset: 0x640
	// Line 561, Address: 0x2be5b4, Func Offset: 0x644
	// Line 562, Address: 0x2be5b8, Func Offset: 0x648
	// Line 561, Address: 0x2be5bc, Func Offset: 0x64c
	// Line 562, Address: 0x2be5c4, Func Offset: 0x654
	// Line 563, Address: 0x2be5cc, Func Offset: 0x65c
	// Line 564, Address: 0x2be604, Func Offset: 0x694
	// Line 563, Address: 0x2be608, Func Offset: 0x698
	// Line 564, Address: 0x2be60c, Func Offset: 0x69c
	// Line 565, Address: 0x2be650, Func Offset: 0x6e0
	// Line 564, Address: 0x2be654, Func Offset: 0x6e4
	// Line 565, Address: 0x2be658, Func Offset: 0x6e8
	// Line 564, Address: 0x2be65c, Func Offset: 0x6ec
	// Line 565, Address: 0x2be664, Func Offset: 0x6f4
	// Line 566, Address: 0x2be69c, Func Offset: 0x72c
	// Line 565, Address: 0x2be6a0, Func Offset: 0x730
	// Line 566, Address: 0x2be6ac, Func Offset: 0x73c
	// Line 572, Address: 0x2be6e4, Func Offset: 0x774
	// Line 566, Address: 0x2be6e8, Func Offset: 0x778
	// Line 568, Address: 0x2be6ec, Func Offset: 0x77c
	// Line 572, Address: 0x2be6f0, Func Offset: 0x780
	// Line 568, Address: 0x2be6f4, Func Offset: 0x784
	// Line 572, Address: 0x2be6f8, Func Offset: 0x788
	// Line 568, Address: 0x2be6fc, Func Offset: 0x78c
	// Line 572, Address: 0x2be700, Func Offset: 0x790
	// Line 573, Address: 0x2be730, Func Offset: 0x7c0
	// Line 566, Address: 0x2be734, Func Offset: 0x7c4
	// Line 572, Address: 0x2be738, Func Offset: 0x7c8
	// Line 567, Address: 0x2be73c, Func Offset: 0x7cc
	// Line 573, Address: 0x2be740, Func Offset: 0x7d0
	// Line 574, Address: 0x2be748, Func Offset: 0x7d8
	// Line 575, Address: 0x2be74c, Func Offset: 0x7dc
	// Line 576, Address: 0x2be760, Func Offset: 0x7f0
	// Line 577, Address: 0x2be764, Func Offset: 0x7f4
	// Line 576, Address: 0x2be768, Func Offset: 0x7f8
	// Line 577, Address: 0x2be774, Func Offset: 0x804
	// Line 579, Address: 0x2be780, Func Offset: 0x810
	// Line 580, Address: 0x2be784, Func Offset: 0x814
	// Line 581, Address: 0x2be788, Func Offset: 0x818
	// Line 579, Address: 0x2be790, Func Offset: 0x820
	// Line 581, Address: 0x2be794, Func Offset: 0x824
	// Line 582, Address: 0x2be79c, Func Offset: 0x82c
	// Line 581, Address: 0x2be7a4, Func Offset: 0x834
	// Line 582, Address: 0x2be7a8, Func Offset: 0x838
	// Line 584, Address: 0x2be7b0, Func Offset: 0x840
	// Line 586, Address: 0x2be7bc, Func Offset: 0x84c
	// Line 584, Address: 0x2be7c0, Func Offset: 0x850
	// Line 585, Address: 0x2be7d0, Func Offset: 0x860
	// Line 584, Address: 0x2be7d4, Func Offset: 0x864
	// Line 587, Address: 0x2be7d8, Func Offset: 0x868
	// Line 588, Address: 0x2be7dc, Func Offset: 0x86c
	// Line 589, Address: 0x2be7e0, Func Offset: 0x870
	// Line 590, Address: 0x2be7e4, Func Offset: 0x874
	// Line 584, Address: 0x2be7e8, Func Offset: 0x878
	// Line 586, Address: 0x2be7f0, Func Offset: 0x880
	// Line 584, Address: 0x2be7f4, Func Offset: 0x884
	// Line 585, Address: 0x2be7f8, Func Offset: 0x888
	// Line 587, Address: 0x2be7fc, Func Offset: 0x88c
	// Line 585, Address: 0x2be800, Func Offset: 0x890
	// Line 591, Address: 0x2be804, Func Offset: 0x894
	// Line 585, Address: 0x2be808, Func Offset: 0x898
	// Line 586, Address: 0x2be830, Func Offset: 0x8c0
	// Line 587, Address: 0x2be83c, Func Offset: 0x8cc
	// Line 588, Address: 0x2be848, Func Offset: 0x8d8
	// Line 589, Address: 0x2be84c, Func Offset: 0x8dc
	// Line 590, Address: 0x2be850, Func Offset: 0x8e0
	// Line 591, Address: 0x2be854, Func Offset: 0x8e4
	// Line 593, Address: 0x2be858, Func Offset: 0x8e8
	// Line 594, Address: 0x2be878, Func Offset: 0x908
	// Line 595, Address: 0x2be8a8, Func Offset: 0x938
	// Line 596, Address: 0x2be8c4, Func Offset: 0x954
	// Line 598, Address: 0x2be8cc, Func Offset: 0x95c
	// Line 602, Address: 0x2be8d0, Func Offset: 0x960
	// Line 599, Address: 0x2be8d4, Func Offset: 0x964
	// Line 604, Address: 0x2be8d8, Func Offset: 0x968
	// Line 605, Address: 0x2be8dc, Func Offset: 0x96c
	// Line 598, Address: 0x2be8e0, Func Offset: 0x970
	// Line 599, Address: 0x2be8ec, Func Offset: 0x97c
	// Line 603, Address: 0x2be8f0, Func Offset: 0x980
	// Line 604, Address: 0x2be8f4, Func Offset: 0x984
	// Line 606, Address: 0x2be8f8, Func Offset: 0x988
	// Line 605, Address: 0x2be8fc, Func Offset: 0x98c
	// Line 606, Address: 0x2be900, Func Offset: 0x990
	// Line 608, Address: 0x2be904, Func Offset: 0x994
	// Line 607, Address: 0x2be908, Func Offset: 0x998
	// Line 608, Address: 0x2be90c, Func Offset: 0x99c
	// Line 609, Address: 0x2be910, Func Offset: 0x9a0
	// Line 610, Address: 0x2be918, Func Offset: 0x9a8
	// Line 612, Address: 0x2be91c, Func Offset: 0x9ac
	// Line 610, Address: 0x2be920, Func Offset: 0x9b0
	// Line 612, Address: 0x2be924, Func Offset: 0x9b4
	// Line 614, Address: 0x2be928, Func Offset: 0x9b8
	// Line 615, Address: 0x2be92c, Func Offset: 0x9bc
	// Line 616, Address: 0x2be930, Func Offset: 0x9c0
	// Line 617, Address: 0x2be938, Func Offset: 0x9c8
	// Line 618, Address: 0x2be93c, Func Offset: 0x9cc
	// Line 619, Address: 0x2be940, Func Offset: 0x9d0
	// Line 620, Address: 0x2be944, Func Offset: 0x9d4
	// Line 621, Address: 0x2be94c, Func Offset: 0x9dc
	// Line 623, Address: 0x2be950, Func Offset: 0x9e0
	// Line 627, Address: 0x2be954, Func Offset: 0x9e4
	// Line 622, Address: 0x2be95c, Func Offset: 0x9ec
	// Line 623, Address: 0x2be960, Func Offset: 0x9f0
	// Line 624, Address: 0x2be964, Func Offset: 0x9f4
	// Line 627, Address: 0x2be968, Func Offset: 0x9f8
	// Line 626, Address: 0x2be97c, Func Offset: 0xa0c
	// Line 627, Address: 0x2be980, Func Offset: 0xa10
	// Line 645, Address: 0x2be990, Func Offset: 0xa20
	// Line 646, Address: 0x2be998, Func Offset: 0xa28
	// Line 629, Address: 0x2be99c, Func Offset: 0xa2c
	// Line 646, Address: 0x2be9a0, Func Offset: 0xa30
	// Line 629, Address: 0x2be9a4, Func Offset: 0xa34
	// Line 630, Address: 0x2be9b8, Func Offset: 0xa48
	// Line 631, Address: 0x2be9c8, Func Offset: 0xa58
	// Line 633, Address: 0x2be9cc, Func Offset: 0xa5c
	// Line 635, Address: 0x2be9d4, Func Offset: 0xa64
	// Line 636, Address: 0x2be9d8, Func Offset: 0xa68
	// Line 637, Address: 0x2be9e0, Func Offset: 0xa70
	// Line 638, Address: 0x2be9e8, Func Offset: 0xa78
	// Line 639, Address: 0x2be9f0, Func Offset: 0xa80
	// Line 640, Address: 0x2be9f8, Func Offset: 0xa88
	// Line 641, Address: 0x2bea00, Func Offset: 0xa90
	// Line 642, Address: 0x2bea08, Func Offset: 0xa98
	// Line 644, Address: 0x2bea10, Func Offset: 0xaa0
	// Line 645, Address: 0x2bea18, Func Offset: 0xaa8
	// Line 646, Address: 0x2bea34, Func Offset: 0xac4
	// Line 647, Address: 0x2bea38, Func Offset: 0xac8
	// Line 648, Address: 0x2bea40, Func Offset: 0xad0
	// Line 650, Address: 0x2bea48, Func Offset: 0xad8
	// Line 651, Address: 0x2bea4c, Func Offset: 0xadc
	// Line 653, Address: 0x2bea50, Func Offset: 0xae0
	// Line 655, Address: 0x2bea58, Func Offset: 0xae8
	// Line 657, Address: 0x2bea5c, Func Offset: 0xaec
	// Line 658, Address: 0x2bea68, Func Offset: 0xaf8
	// Func End, Address: 0x2bea88, Func Offset: 0xb18
	scePrintf("bhEntrySpEvtComputer - UNIMPLEMENTED!\n");
}

// 98.46% matching
void bhDrawSpEvtComputer() 
{
    NJS_POINT2 sp[2];     
    QUAD* qt;          
    unsigned int* qtbcol; 
    COM_EVT_WORK* ce;    
    int i, j;               
    float pri;            

    ce = sys->com_exp;
    
    njSetTexture(&ce->com_tlist);
    
    sp[0].x = 0;
    sp[0].y = 0;
    
    sp[1].x = 20.0f;
    
    qt     = ce->qt;
    qtbcol = ce->qtbcol;
    
    sp[1].y = 15.0f;
    
    njUserClipping(0, sp);
    
    njQuadTextureStart(0);
    
    njSetQuadTexture(0, qtbcol[0]);
    
    njDrawQuadTexture(&qt[0], 0.1f);
    
    njQuadTextureEnd();
    
    njQuadTextureStart(1);
    
    njSetQuadTexture(1, qtbcol[1]);
    
    njDrawQuadTexture(&qt[1], 0.25f);
    
    njSetQuadTexture(1, qtbcol[2]);
    
    njDrawQuadTexture(&qt[2], 0.2f);
    
    qt     += 3;
    qtbcol += 3;
    
    if ((sys->com_flg & 0x10)) 
    {
        njSetQuadTexture(1, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], 0.3f);
        
        njSetQuadTexture(1, qtbcol[1]);
        
        njDrawQuadTexture(&qt[1], 0.31f);
        
        qt     += 2;
        qtbcol += 2;
    }
    
    if ((sys->com_flg & 0x20)) 
    {
        njSetQuadTexture(1, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], 0.26f);
        
        njSetQuadTexture(2, qtbcol[1]);
        
        njDrawQuadTexture(&qt[1], 0.27f);
        
        qt     += 2;
        qtbcol += 2; 
    }
    
    njQuadTextureEnd();
    
    if ((sys->com_flg & 0x40)) 
    {
        sp[0].x = 14.0f;
        sp[0].y = 8.0f;
        
        sp[1].x = 18.0f;
        sp[1].y = 12.0f;
        
        njUserClipping(2, sp);
        
        bhDrawSpEvtComCharacter();
        
        sp[0].x = 0;
        sp[0].y = 0;
        
        sp[1].x = 20.0f;
        sp[1].y = 15.0f;
        
        njUserClipping(0, sp);
    }
    
    njQuadTextureStart(1);
    
    for (i = 0; i < 11; i++) 
    {
        for (j = 0; j < 29; j++) 
        {
            if ((unsigned char)ce->txt[i][j] != 0) 
            {
                njSetQuadTexture(1, qtbcol[0]);
                
                njDrawQuadTexture(&qt[0], 0.21f);
                
                qt     += 1;
                qtbcol += 1;
            }
        }
    } 
    
    njSetQuadTexture(1, qtbcol[0]);
    
    njDrawQuadTexture(&qt[0], 0.22f);
    
    qt     += 1;
    qtbcol += 1;
    
    njQuadTextureEnd();
    
    pri = 0.11f;
    
    njQuadTextureStart(1);
    
    for (i = 0; i < ce->qten[2]; i++) 
    {
        njSetQuadTexture(2, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], pri);
        
        pri += 0.001f;
        
        qt     += 1;
        qtbcol += 1;
    }
    
    njQuadTextureEnd();
    
    sp[0].x = 0;
    sp[0].y = 0;
    
    sp[1].x = 20.0f;
    sp[1].y = 15.0f;
    
    njUserClipping(0, sp);
    
    bhDrawSpEvtComTime();
    
    for (i = 0; i < 3; i++) 
    {
        if ((ce->bar_ct[i] & 0x1)) 
        {
            ce->bar[i][1] = ((7 - i) * 6) + (((i + 1) * 30) * (-rand() / -2.1474836E9f));
        }
        
        ce->bar[i][0] += 0.5f * (ce->bar[i][1] - ce->bar[i][0]);
        
        ce->bar_ct[i] = (ce->bar_ct[i] + 1) & 0x3F;
        
        if (ce->bar_ct[i] == 0) 
        {
            ce->bar[i][2] = ce->bar[i][0];
        } 
        else
        {
            if (ce->bar[i][2] < ce->bar[i][0]) 
            {
                ce->bar[i][2] = ce->bar[i][0];
            }
        }
    }
    
    bhDrawSpEvtComBar(0, 0, 2);
    bhDrawSpEvtComBar(1, 1, 3);
    bhDrawSpEvtComBar(2, 3, 0);
    
    if ((sys->com_flg & 0x80))
    {
        bhDispMessage(68.0f, 434 - (ce->mes_ln * 30), -0.9f, 0, ce->mes_no, 0, 0);
    }
}

// 78.98% matching (matches on NGC)
void bhDrawSpEvtComTime()
{
    SYS_RTC_DATE date; 
    int hour, min, sec;         
  
    if (!(sys->com_flg & 0x100)) 
    {
        hour = 21;
        min  = 35;
        sec  = 12;
    } 
    else 
    {
        syRtcGetDate(&date);
        
        hour = date.hour;
        min  = date.minute;
        sec  = date.second;
    }
    
    bhDrawSpEvtComVal(hour / 10, 364.0f, 304.0f);
    bhDrawSpEvtComVal(hour % 10, 380.0f, 304.0f);
    bhDrawSpEvtComVal(min / 10,  400.0f, 304.0f);
    bhDrawSpEvtComVal(min % 10,  416.0f, 304.0f);
    bhDrawSpEvtComVal(11,        432.0f, 304.0f);
    bhDrawSpEvtComVal(sec / 10,  440.0f, 304.0f);
    bhDrawSpEvtComVal(sec % 10,  456.0f, 304.0f);
}

// 100% matching!
void bhDrawSpEvtComVal(int val, float px, float py)
{
    QUAD qt; 

    qt.x1 = px;
    qt.y1 = py;
    
    qt.x2 = 16.0f + px;
    qt.y2 = 20.0f + py;
    
    qt.u1 = (((val % 8) * 16) + 204) / 512.0f;
    qt.v1 = (((val / 8) * 24) + 208) / 512.0f;
    
    qt.u2 = 0.03125f  + qt.u1;
    qt.v2 = 0.046875f + qt.v1;
    
    njQuadTextureStart(1);
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.15f);
    
    njQuadTextureEnd();
}

// 100% matching!
void bhDrawSpEvtComBar(int barno, int col0, int col1)
{
    QUAD qt;         
    COM_EVT_WORK* ce;
    
    ce = sys->com_exp;
    
    njQuadTextureStart(1);
    
    qt.x1 = 364.0f;
    qt.y1 = (barno * 20) + 344;
    
    qt.x2 = qt.x1 + ce->bar[barno][2];
    qt.y2 = 12.0f + qt.y1;
    
    qt.u1 = 0.40039063f;
    qt.v1 = ((col1 * 12) + 156) / 512.0f;
    
    qt.u2 = 0.6796875f;
    qt.v2 = ((col1 * 12) + 168) / 512.0f;
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.15f);
    
    qt.x1 = 364.0f;
    qt.y1 = (barno * 20) + 344;
    
    qt.x2 = qt.x1 + ce->bar[barno][0];
    qt.y2 = 12.0f + qt.y1;
    
    qt.u1 = 0.40039063f;
    qt.v1 = ((col0 * 12) + 156) / 512.0f;
    
    qt.u2 = 0.6796875f;
    qt.v2 = ((col0 * 12) + 168) / 512.0f;
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.151f);
    
    njQuadTextureEnd();
}

// 99.39% matching
void bhDrawSpEvtComCharacter() 
{
    COM_EVT_WORK* ce; 
    NJS_SCREEN scrn;  
    BH_PWORK* pp;    
    float near;       
 
    ce = sys->com_exp;
    
    near = fNaViwClipNear;
    
    njClipZ(-1.0f, fNaViwClipFar);
    
    scrn.dist = 600.0f;
    
    scrn.w = 608.0f;
    scrn.h = 416.0f;
    
    scrn.cx = 528.0f;
    scrn.cy = 336.0f;
    
    njSetScreen(&scrn);
    
    pp = &ene[rom->enep[ce->chr_no].wrk_no];
    
    pp->mtn_no = ce->mtn_no;
    pp->frm_no = ce->frm_no;
    
    pp->ax = pp->ay = pp->az = 0;
    pp->px = pp->py = pp->pz = 0;
    
    if (pp->skp[pp->mdl_no] != NULL) 
    {
        npRetSkinConvert(pp->mlwP->objP, pp->skp[pp->mdl_no]);
    }
    
    pp->mlwP->objP[1].ang[0] = 0;
    pp->mlwP->objP[1].ang[1] = 0;
    pp->mlwP->objP[1].ang[2] = 0;
    
    njSetMatrix(NULL, cmat);
    
    njCnkSetEasyLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetEasyLightIntensity(1.0f, 0.2f);
    njCnkSetEasyLight(4.0f, 6.0f, 10.0f);
    
    njTranslate(NULL, ce->cox, ce->coy, ce->coz);
    njRotateXYZ(NULL, ce->cax, ce->cay, ce->caz);
    
    njScale(NULL, 0.05f, 0.05f, 0.05f);
    
    if (pp->mlwP->texP != NULL) 
    {
        njSetTexture(pp->mlwP->texP);
    }
    
    njCnkEasyDrawObject(pp->mlwP->objP);
    
    ce->cax += ce->caxn;
    ce->cay += ce->cayn;
    ce->caz += ce->cazn;
    
    if (pp->skp[pp->mdl_no] != NULL) 
    {
        npSkinConvert(pp->mlwP->objP, pp->skp[pp->mdl_no]);
    }
    
    njSetTexture(&ce->com_tlist);
    
    scrn.w = 640.0f;
    scrn.h = 480.0f;
    
    scrn.cx = 320.0f;
    scrn.cy = 240.0f;
    
    njSetScreen(&scrn);
    
    njClipZ(near, fNaViwClipFar);
}

// 100% matching!
void bhSetSpEvtComFade(float fdst, float fcnt)
{
	COM_EVT_WORK* ce;

	ce = sys->com_exp;

    ce->fdst = fdst;

    ce->fcal = (fdst - ce->fsrc) / fcnt;

    ce->fcnt = fcnt;

    sys->com_flg |= 0x2;
}

// 99.71% matching
void bhCalcSpEvtComFade() 
{
	COM_EVT_WORK* ce;
    int nn;
    
    ce = sys->com_exp;
    
    ce->fsrc += ce->fcal;

    ce->fcnt -= 1.0f;
    
    if (ce->fcnt <= 0)
    {
        sys->com_flg &= ~0x2;
        
        ce->fsrc = ce->fdst;
    }

    nn = (unsigned int)(ce->fsrc * 255.0f);

    if (nn < 0)
    {
        nn = 0;
    } 
    
    if (nn > 255)
    {
        nn = 255;
    }

    ce->fcol = nn << 24;
}

// 100% matching!
void bhDrawSpEvtComFade()
{
    COM_EVT_WORK* ce; 
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  

    ce = sys->com_exp;
    
    p2c.p   = p;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 1;
    
    p2c.col[0].color = ce->fcol;
    p2c.col[1].color = ce->fcol;
    p2c.col[2].color = ce->fcol;
    p2c.col[3].color = ce->fcol;
    
    p[0].x = 0;
    p[0].y = 0;
    
    p[1].x = 640.0f; 
    p[1].y = 0;
    
    p[2].x = 640.0f;
    p[2].y = 480.0f;
    
    p[3].x = 0;
    p[3].y = 480.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.8f, 0x60);
}

// 100% matching!
void bhEntrySpEvtBoxLine(NJS_LINE* line)
{
    COM_EVT_WORK* ce; 
    int i;           
    
    ce = sys->com_exp;
    
    for (i = 0; i < 128; i++) 
    {
        if (!(ce->lnfg[i] & 0x1))
        {
            ce->lnfg[i] = 1;
            
            ce->line[i].px = line->px;
            ce->line[i].py = line->py;
            ce->line[i].pz = line->pz;
            
            ce->line[i].vx = line->vx;
            ce->line[i].vy = line->vy;
            ce->line[i].vz = line->vz;
            
            ce->lnct[i] = 240;
            break;
        }
    }
}

// 100% matching!
void bhDrawSpEvtBoxLine()
{
    COM_EVT_WORK* ce;  
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];  
    NJS_COLOR col[4]; 
    int i;            
    unsigned int argb;

    ce = sys->com_exp;
    
    p2c.p   = p;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 1;
    
    for (i = 0; i < 128; i++)
    {
        if ((ce->lnfg[i] & 0x1)) 
        {
            argb = (ce->lnct[i] << 0) | ((ce->lnct[i] << 8) | ((ce->lnct[i] << 24) | (ce->lnct[i] << 16)));
            
            p2c.col[0].color = argb;
            p2c.col[1].color = argb;
            p2c.col[2].color = argb;
            p2c.col[3].color = argb;
            
            p[0].x = ce->line[i].px;
            p[0].y = ce->line[i].py;
            
            p[1].x = ce->line[i].px + ce->line[i].vx;
            p[1].y = ce->line[i].py;
            
            p[2].x = ce->line[i].px + ce->line[i].vx;
            p[2].y = ce->line[i].py + ce->line[i].vy;
            
            p[3].x = ce->line[i].px;
            p[3].y = ce->line[i].py + ce->line[i].vy;
            
            njDrawPolygon2D(&p2c, 4, -0.85f, 0x40);
            
            ce->lnct[i] -= 30;
            
            if (ce->lnct[i] <= 0) 
            {
                ce->lnfg[i] = 0;
            }
        }
    } 
}

// 100% matching!
void bhClearComEvtText()
{
	COM_EVT_WORK* ce; // not from DWARF

	ce = sys->com_exp;

    npSetMemoryL((unsigned int*)ce->txt, sizeof(ce->txt) / 4, 0);
}

// 100% matching!
void bhInitComEvtScript()
{
    COM_EVT_WORK* ce;
	unsigned char* scp;
	unsigned char cmd;    
	int end;

    ce = sys->com_exp;
    
    scp = ce->scp;
    
    ce->txcol = 0xFFFF00;
    ce->txflg = 0;
    
    end = 1;
    
    while (end != 0)
    {
        cmd = *scp++;
        
        switch (cmd)
        {
        case 224:
            scp++;
            break;
        case 225:
            scp++;
            break;
        case 227:
            scp += 3;
            break;
        case 228:
            scp++;
            break;
        case 229:
            scp += 2;
            break;
        case 234:
            scp += 3;
            break;
        case 235:
            ce->sclb[*scp] = scp + 1;
            
            scp++;
            break;
        case 236:
            scp++;
            break;
        case 237:
            scp += 2;
            break;
        case 238:
            scp += 4;
            break;
        case 239:
            scp += 2;
            break;
        case 240:
            scp += 2;
            break;
        case 241:
            scp += 2;
            break;
        case 255:
            end = 0;
            break;
        }
    } 
}

// 100% matching!
void bhControlComEvtScript()
{
    COM_EVT_WORK* ce;     
    unsigned char cmd;    
    unsigned char r, g, b;   
    unsigned int bit;   
    unsigned int* mstb; 
    unsigned short flgno;
    char* wcpa, *wcpb;         
 
    ce = sys->com_exp;
    
    if (!(ce->txflg & 0x2)) 
    {
        if ((sys->com_flg & 0x10)) 
        {
            switch (ce->txflg & 0x8) 
            {
            case 0:
                break;
            default:
                return;
            }
        }
        
        if ((ce->txflg & 0x4)) 
        {
            if ((sys->pad_ps & 0x800)) 
            {
                ce->txflg &= ~0x4;
            }
            
            return;
        } 
        else if ((ce->txflg & 0x1)) 
        {
            ce->curct = 16384;
            
            ce->txt[ce->ty][ce->tx] = ce->txcol | (*ce->mesp++ - 32);
            
            CallSystemSe(0, 0x8000026E);
            
            ce->tx++;
            
            if (*ce->mesp)
            {
                return;
            }
            
            ce->txflg &= ~0x1;
        }
        
        if (ce->txwait != 0)
        {
            ce->txwait--;
            return;
        }
        
        switch (*ce->scp++) 
        {
        case 224:
            ce->txflg |= 0x1;
            ce->txmes = *ce->scp++;

            ce->mesp = ((unsigned char***)comevt_message_tab)[sys->com_num][ce->txmes];
            break;
        case 225:
            ce->txwait = *ce->scp++;
            break;
        case 226:
            ce->txflg |= 0x4;
            break;
        case 227:
            r = *ce->scp++;
            g = *ce->scp++;
            b = *ce->scp++;
            
            ce->txcol = ((r & 0xF8) << 16) | ((g & 0xFC) << 11) | ((b & 0xF8) << 5);
            break;
        case 228:
            ce->txt[ce->ty][ce->tx] = ce->txcol | (*ce->scp++ - 32);
            
            CallSystemSe(0, 0x8000026E);
            
            ce->tx++;
            break;
        case 229:
            ce->wordmax = *ce->scp++;
            
            if (*ce->scp++ != 0)
            {
                sys->com_flg |=  0x400;
            } 
            else 
            {
                sys->com_flg &= ~0x400;
            }
            
            ce->wdx = ce->tx;
            ce->wdy = ce->ty;
            
            sys->com_flg |= 0x10;
            
            ce->txflg &= 0x7;
            ce->txflg |= 0x8;
            
            ce->kx = 1;
            ce->ky = 1;
            
            ce->khk  = -1;
            ce->krep = 0;
            ce->kbn  = 0;
            
            ce->wordn = 0;
            
            ce->ct0 = 0;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 3; 
            break;
        case 230:
            sys->com_flg &= ~0x10;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 19; 
            break;
        case 231:
            ce->ct0 = 0;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 5; 
            break;
        case 232:
            sys->com_flg &= ~0x60;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 18; 
            break;
        case 233:
            ce->txflg |= 0x8;
            break;
        case 234:
            mstb = comevt_message_tab[sys->com_num];
            
            wcpa = (char*)ce->word[*ce->scp++];
            wcpb = (char*)mstb[*ce->scp++];
            
            bit = *ce->scp++;
            
            if (strcmp(wcpa, wcpb) == 0) 
            {
                ce->lcflg |= 1 << bit;
            }
            else 
            {
                ce->lcflg &= ~(1 << bit);
            }
            
            break;
        case 235:
            ce->scp++;
            break;
        case 236:
            ce->scp = ce->sclb[*ce->scp++];
            break;
        case 237:
            if ((ce->lcflg & (1 << *ce->scp++))) 
            {
                ce->scp = ce->sclb[*ce->scp++];
            }
            else 
            {
                ce->scp++;
            }
            
            break;
        case 238:
            sys->com_flg |= 0x40;
            
            ce->chr_no = *ce->scp++;
            
            ce->caxn = (char)*ce->scp++ << 8;
            ce->cayn = (char)*ce->scp++ << 8;
            ce->cazn = (char)*ce->scp++ << 8;
            
            ce->cox =  0;
            ce->coy =  0.1f;
            ce->coz = -1.4f;
            
            ce->cax = 16384;
            ce->cay = 0;
            ce->caz = 0;
            break;
        case 239:
            ce->mtn_no = *ce->scp++;
            ce->frm_no = *ce->scp++;
            break;
        case 240:
            flgno = *ce->scp++ | (*ce->scp++ << 8);
            
            bhStFlg(sys->ev_flg, flgno);
            break;
        case 241:
            ce->mes_no = *ce->scp++;
            ce->mes_ln = *ce->scp++;
            
            sys->com_flg |= 0x80;
            break;
        case 242:
            sys->com_flg &= ~0x80;
            break;
        case 243:
            ce->lcflg = 0;
            break;
        case 244:
            sys->com_flg &= ~0x200;
            break;
        case 245:
            sys->com_flg |= 0x200;
            break;
        case 246:
            CallSystemSe(0, 0x8000026E);
            
            ce->tx = 0;
            ce->ty++;
            
            if (ce->ty >= 11) 
            {
                ce->ty--;
                
                ce->txflg |= 0x2;
                ce->txsct  = 0;
            }
            
            break;
        case 0xFF:
            ce->ct0 = 0;
            
            sys->com_md1 = 20; 
            break;
        }
    }
}

// 100% matching!
void bhControlComEvtKeyboard()
{
    COM_EVT_WORK* ce;
    int i;
    int sel;
    int adt;

    ce = sys->com_exp;
    
    switch (sys->pad_on & 0xF) 
    {
    case 1:
        if (ce->khk == 0)
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else 
        {
            ce->khk  = 0;
            ce->krep = 0;
        }
        
        if ((ce->kx == 9) && (ce->ky == 3))
        {
            ce->ky -= 2;
        }
        else 
        {
            ce->ky--;
        }
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 9:
        if (ce->khk == 1)
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 1;
            ce->krep = 0;
        }
        
        ce->kx++;
        ce->ky--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 8:
        if (ce->khk == 2) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 2;
            ce->krep = 0;
        }
        
        ce->kx++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 10:
        if (ce->khk == 3) 
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 3;
            ce->krep = 0;
        }
        
        ce->kx++;
        ce->ky++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 2:
        if (ce->khk == 4) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else 
        {
            ce->khk  = 4;
            ce->krep = 0;
        }
        
        if ((ce->kx == 9) && (ce->ky == 2)) 
        {
            ce->ky += 2;
        } 
        else
        {
            ce->ky++;
        }
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 6:
        if (ce->khk == 5)
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        }
        else
        {
            ce->khk  = 5;
            ce->krep = 0;
        }
        
        ce->kx--;
        ce->ky++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 4:
        if (ce->khk == 6)
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 6;
            ce->krep = 0;
        }
        
        ce->kx--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 5:
        if (ce->khk == 7) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        }
        else 
        {
            ce->khk  = 7;
            ce->krep = 0;
        }
        
        ce->kx--;
        ce->ky--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    default:
        ce->khk  = -1;
        ce->krep = 0;
        break;
    }
    
    if (ce->kx < 0) 
    {
        ce->kx = 9;
    }
    
    if (ce->kx > 9) 
    {
        ce->kx = 0;
    }
    
    if (ce->ky < 0) 
    {
        ce->ky = 3;
    }
    
    if (ce->ky > 3) 
    {
        ce->ky = 0;
    }
    
    if ((sys->pad_ps & 0x800)) 
    {
        ce->txflg |= 0x10;
        
        sel = ce->kx + (ce->ky * 10);
        
        switch (sel) 
        {
        case 10:
            ce->ct0 = 0;
            
            sys->com_md1 = 20;
            break;
        case 19:
            if (ce->kbn > 0) 
            {
                CallSystemSe(0, 0x8000026C);
                
                ce->kbn--;
                
                ce->word[ce->wordn][ce->kbn] = 0;
                
                ce->tx--;
                
                ce->txt[ce->ty][ce->tx] = ce->txcol;
            }
            
            break;
        case 29:
        case 39:
            CallSystemSe(0, 0x8000026D);
            
            ce->txflg &= ~0x8;
            
            ce->wordn++;
            
            ce->kbn = 0;
            break;
        default:
            CallSystemSe(0, 0x8000026B);
            
            if (ce->kbn < ce->wordmax)
            {
                if (sel < 10)
                {
                    adt = ((sel + 1) % 10) + 16;
                } 
                else
                {
                    if (sel < 19) 
                    {
                        adt = sel - 11;
                    } 
                    else if (sel < 29)
                    {
                        adt = sel - 12;
                    }
                    else 
                    {
                        adt = sel - 13;
                    }
                    
                    adt += 33;
                }
                
                ce->txt[ce->ty][ce->tx] = ce->txcol | adt;
                
                ce->word[ce->wordn][ce->kbn]     = adt + 32;
                ce->word[ce->wordn][ce->kbn + 1] = 0;
                
                ce->tx++;
                ce->kbn++;
            }
            
            break;
        }
    }
    
    if ((sys->com_flg & 0x400)) 
    {
        for (i = 0; i < ce->wordmax; i++) 
        {
            if ((unsigned char)ce->txt[ce->wdy][ce->wdx + i] == 0)
            {
                ce->txt[ce->wdy][ce->wdx + i] = ce->txcol | 60;
            }
        }
    }
}
