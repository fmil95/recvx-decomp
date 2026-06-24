#include "../../../ps2/veronica/prog/sp_evt.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
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

// 
// Start address: 0x2bd370
void bhMainSpEvtComputer()
{
	//_anon41 line;
	//_anon7* ce;
	// Line 156, Address: 0x2bd370, Func Offset: 0
	// Line 157, Address: 0x2bd37c, Func Offset: 0xc
	// Line 160, Address: 0x2bd384, Func Offset: 0x14
	// Line 157, Address: 0x2bd388, Func Offset: 0x18
	// Line 160, Address: 0x2bd394, Func Offset: 0x24
	// Line 162, Address: 0x2bd464, Func Offset: 0xf4
	// Line 163, Address: 0x2bd47c, Func Offset: 0x10c
	// Line 164, Address: 0x2bd484, Func Offset: 0x114
	// Line 165, Address: 0x2bd494, Func Offset: 0x124
	// Line 170, Address: 0x2bd498, Func Offset: 0x128
	// Line 171, Address: 0x2bd4a0, Func Offset: 0x130
	// Line 172, Address: 0x2bd4a4, Func Offset: 0x134
	// Line 173, Address: 0x2bd4c4, Func Offset: 0x154
	// Line 174, Address: 0x2bd4d8, Func Offset: 0x168
	// Line 173, Address: 0x2bd4dc, Func Offset: 0x16c
	// Line 174, Address: 0x2bd4e0, Func Offset: 0x170
	// Line 175, Address: 0x2bd4e8, Func Offset: 0x178
	// Line 176, Address: 0x2bd4f4, Func Offset: 0x184
	// Line 177, Address: 0x2bd504, Func Offset: 0x194
	// Line 178, Address: 0x2bd528, Func Offset: 0x1b8
	// Line 181, Address: 0x2bd54c, Func Offset: 0x1dc
	// Line 183, Address: 0x2bd554, Func Offset: 0x1e4
	// Line 184, Address: 0x2bd560, Func Offset: 0x1f0
	// Line 185, Address: 0x2bd57c, Func Offset: 0x20c
	// Line 186, Address: 0x2bd58c, Func Offset: 0x21c
	// Line 187, Address: 0x2bd598, Func Offset: 0x228
	// Line 186, Address: 0x2bd59c, Func Offset: 0x22c
	// Line 189, Address: 0x2bd5a8, Func Offset: 0x238
	// Line 191, Address: 0x2bd5b0, Func Offset: 0x240
	// Line 192, Address: 0x2bd5b8, Func Offset: 0x248
	// Line 193, Address: 0x2bd5c0, Func Offset: 0x250
	// Line 194, Address: 0x2bd5e0, Func Offset: 0x270
	// Line 195, Address: 0x2bd5f4, Func Offset: 0x284
	// Line 194, Address: 0x2bd5f8, Func Offset: 0x288
	// Line 195, Address: 0x2bd5fc, Func Offset: 0x28c
	// Line 196, Address: 0x2bd604, Func Offset: 0x294
	// Line 197, Address: 0x2bd610, Func Offset: 0x2a0
	// Line 198, Address: 0x2bd620, Func Offset: 0x2b0
	// Line 201, Address: 0x2bd644, Func Offset: 0x2d4
	// Line 203, Address: 0x2bd64c, Func Offset: 0x2dc
	// Line 204, Address: 0x2bd658, Func Offset: 0x2e8
	// Line 205, Address: 0x2bd674, Func Offset: 0x304
	// Line 206, Address: 0x2bd684, Func Offset: 0x314
	// Line 207, Address: 0x2bd690, Func Offset: 0x320
	// Line 206, Address: 0x2bd694, Func Offset: 0x324
	// Line 209, Address: 0x2bd6a0, Func Offset: 0x330
	// Line 211, Address: 0x2bd6a8, Func Offset: 0x338
	// Line 212, Address: 0x2bd6b0, Func Offset: 0x340
	// Line 213, Address: 0x2bd6b8, Func Offset: 0x348
	// Line 214, Address: 0x2bd6d8, Func Offset: 0x368
	// Line 215, Address: 0x2bd6ec, Func Offset: 0x37c
	// Line 214, Address: 0x2bd6f0, Func Offset: 0x380
	// Line 215, Address: 0x2bd6f4, Func Offset: 0x384
	// Line 216, Address: 0x2bd6fc, Func Offset: 0x38c
	// Line 217, Address: 0x2bd708, Func Offset: 0x398
	// Line 218, Address: 0x2bd718, Func Offset: 0x3a8
	// Line 219, Address: 0x2bd73c, Func Offset: 0x3cc
	// Line 222, Address: 0x2bd760, Func Offset: 0x3f0
	// Line 224, Address: 0x2bd768, Func Offset: 0x3f8
	// Line 225, Address: 0x2bd774, Func Offset: 0x404
	// Line 226, Address: 0x2bd790, Func Offset: 0x420
	// Line 227, Address: 0x2bd7a0, Func Offset: 0x430
	// Line 228, Address: 0x2bd7ac, Func Offset: 0x43c
	// Line 227, Address: 0x2bd7b0, Func Offset: 0x440
	// Line 230, Address: 0x2bd7bc, Func Offset: 0x44c
	// Line 235, Address: 0x2bd7c4, Func Offset: 0x454
	// Line 237, Address: 0x2bd7cc, Func Offset: 0x45c
	// Line 238, Address: 0x2bd7fc, Func Offset: 0x48c
	// Line 241, Address: 0x2bd804, Func Offset: 0x494
	// Line 244, Address: 0x2bd83c, Func Offset: 0x4cc
	// Line 245, Address: 0x2bd840, Func Offset: 0x4d0
	// Line 246, Address: 0x2bd854, Func Offset: 0x4e4
	// Line 253, Address: 0x2bd85c, Func Offset: 0x4ec
	// Line 254, Address: 0x2bd860, Func Offset: 0x4f0
	// Line 255, Address: 0x2bd864, Func Offset: 0x4f4
	// Line 253, Address: 0x2bd868, Func Offset: 0x4f8
	// Line 254, Address: 0x2bd870, Func Offset: 0x500
	// Line 255, Address: 0x2bd874, Func Offset: 0x504
	// Line 256, Address: 0x2bd878, Func Offset: 0x508
	// Line 257, Address: 0x2bd894, Func Offset: 0x524
	// Line 258, Address: 0x2bd8a4, Func Offset: 0x534
	// Line 257, Address: 0x2bd8a8, Func Offset: 0x538
	// Line 258, Address: 0x2bd8ac, Func Offset: 0x53c
	// Line 259, Address: 0x2bd8b4, Func Offset: 0x544
	// Line 260, Address: 0x2bd8d0, Func Offset: 0x560
	// Line 261, Address: 0x2bd8dc, Func Offset: 0x56c
	// Line 264, Address: 0x2bd8f4, Func Offset: 0x584
	// Line 269, Address: 0x2bd8fc, Func Offset: 0x58c
	// Line 270, Address: 0x2bd900, Func Offset: 0x590
	// Line 271, Address: 0x2bd904, Func Offset: 0x594
	// Line 269, Address: 0x2bd908, Func Offset: 0x598
	// Line 270, Address: 0x2bd910, Func Offset: 0x5a0
	// Line 271, Address: 0x2bd914, Func Offset: 0x5a4
	// Line 272, Address: 0x2bd918, Func Offset: 0x5a8
	// Line 273, Address: 0x2bd934, Func Offset: 0x5c4
	// Line 274, Address: 0x2bd944, Func Offset: 0x5d4
	// Line 273, Address: 0x2bd948, Func Offset: 0x5d8
	// Line 274, Address: 0x2bd94c, Func Offset: 0x5dc
	// Line 275, Address: 0x2bd954, Func Offset: 0x5e4
	// Line 276, Address: 0x2bd970, Func Offset: 0x600
	// Line 277, Address: 0x2bd97c, Func Offset: 0x60c
	// Line 280, Address: 0x2bd994, Func Offset: 0x624
	// Line 285, Address: 0x2bd99c, Func Offset: 0x62c
	// Line 286, Address: 0x2bd9bc, Func Offset: 0x64c
	// Line 287, Address: 0x2bd9dc, Func Offset: 0x66c
	// Line 288, Address: 0x2bd9e4, Func Offset: 0x674
	// Line 287, Address: 0x2bd9e8, Func Offset: 0x678
	// Line 288, Address: 0x2bd9ec, Func Offset: 0x67c
	// Line 289, Address: 0x2bd9f0, Func Offset: 0x680
	// Line 290, Address: 0x2bda00, Func Offset: 0x690
	// Line 292, Address: 0x2bda08, Func Offset: 0x698
	// Line 293, Address: 0x2bda10, Func Offset: 0x6a0
	// Line 294, Address: 0x2bda20, Func Offset: 0x6b0
	// Line 295, Address: 0x2bda40, Func Offset: 0x6d0
	// Line 297, Address: 0x2bda48, Func Offset: 0x6d8
	// Line 298, Address: 0x2bda4c, Func Offset: 0x6dc
	// Line 299, Address: 0x2bda50, Func Offset: 0x6e0
	// Line 297, Address: 0x2bda54, Func Offset: 0x6e4
	// Line 298, Address: 0x2bda5c, Func Offset: 0x6ec
	// Line 299, Address: 0x2bda60, Func Offset: 0x6f0
	// Line 300, Address: 0x2bda64, Func Offset: 0x6f4
	// Line 301, Address: 0x2bda80, Func Offset: 0x710
	// Line 302, Address: 0x2bda90, Func Offset: 0x720
	// Line 301, Address: 0x2bda94, Func Offset: 0x724
	// Line 302, Address: 0x2bda98, Func Offset: 0x728
	// Line 303, Address: 0x2bdaa0, Func Offset: 0x730
	// Line 304, Address: 0x2bdabc, Func Offset: 0x74c
	// Line 305, Address: 0x2bdac8, Func Offset: 0x758
	// Line 307, Address: 0x2bdad0, Func Offset: 0x760
	// Line 305, Address: 0x2bdad4, Func Offset: 0x764
	// Line 306, Address: 0x2bdaf0, Func Offset: 0x780
	// Line 309, Address: 0x2bdaf4, Func Offset: 0x784
	// Line 311, Address: 0x2bdafc, Func Offset: 0x78c
	// Line 313, Address: 0x2bdb18, Func Offset: 0x7a8
	// Line 312, Address: 0x2bdb1c, Func Offset: 0x7ac
	// Line 313, Address: 0x2bdb20, Func Offset: 0x7b0
	// Line 314, Address: 0x2bdb24, Func Offset: 0x7b4
	// Line 315, Address: 0x2bdb34, Func Offset: 0x7c4
	// Line 317, Address: 0x2bdb3c, Func Offset: 0x7cc
	// Line 318, Address: 0x2bdb48, Func Offset: 0x7d8
	// Line 319, Address: 0x2bdb50, Func Offset: 0x7e0
	// Line 320, Address: 0x2bdb60, Func Offset: 0x7f0
	// Line 321, Address: 0x2bdb80, Func Offset: 0x810
	// Line 323, Address: 0x2bdb88, Func Offset: 0x818
	// Line 324, Address: 0x2bdb8c, Func Offset: 0x81c
	// Line 325, Address: 0x2bdb90, Func Offset: 0x820
	// Line 323, Address: 0x2bdb94, Func Offset: 0x824
	// Line 324, Address: 0x2bdb9c, Func Offset: 0x82c
	// Line 325, Address: 0x2bdba0, Func Offset: 0x830
	// Line 326, Address: 0x2bdba4, Func Offset: 0x834
	// Line 327, Address: 0x2bdbc0, Func Offset: 0x850
	// Line 328, Address: 0x2bdbd0, Func Offset: 0x860
	// Line 327, Address: 0x2bdbd4, Func Offset: 0x864
	// Line 328, Address: 0x2bdbd8, Func Offset: 0x868
	// Line 329, Address: 0x2bdbe0, Func Offset: 0x870
	// Line 330, Address: 0x2bdbfc, Func Offset: 0x88c
	// Line 331, Address: 0x2bdc08, Func Offset: 0x898
	// Line 334, Address: 0x2bdc10, Func Offset: 0x8a0
	// Line 333, Address: 0x2bdc18, Func Offset: 0x8a8
	// Line 334, Address: 0x2bdc1c, Func Offset: 0x8ac
	// Line 331, Address: 0x2bdc20, Func Offset: 0x8b0
	// Line 332, Address: 0x2bdc3c, Func Offset: 0x8cc
	// Line 334, Address: 0x2bdc40, Func Offset: 0x8d0
	// Line 336, Address: 0x2bdc48, Func Offset: 0x8d8
	// Line 338, Address: 0x2bdc50, Func Offset: 0x8e0
	// Line 339, Address: 0x2bdc6c, Func Offset: 0x8fc
	// Line 340, Address: 0x2bdc74, Func Offset: 0x904
	// Line 342, Address: 0x2bdc7c, Func Offset: 0x90c
	// Line 343, Address: 0x2bdc80, Func Offset: 0x910
	// Line 342, Address: 0x2bdc84, Func Offset: 0x914
	// Line 343, Address: 0x2bdc8c, Func Offset: 0x91c
	// Line 344, Address: 0x2bdc90, Func Offset: 0x920
	// Line 345, Address: 0x2bdc94, Func Offset: 0x924
	// Line 346, Address: 0x2bdcb0, Func Offset: 0x940
	// Line 347, Address: 0x2bdcc0, Func Offset: 0x950
	// Line 346, Address: 0x2bdcc4, Func Offset: 0x954
	// Line 347, Address: 0x2bdcc8, Func Offset: 0x958
	// Line 348, Address: 0x2bdcd0, Func Offset: 0x960
	// Line 349, Address: 0x2bdcec, Func Offset: 0x97c
	// Line 350, Address: 0x2bdcf8, Func Offset: 0x988
	// Line 351, Address: 0x2bdd10, Func Offset: 0x9a0
	// Line 352, Address: 0x2bdd28, Func Offset: 0x9b8
	// Line 355, Address: 0x2bdd2c, Func Offset: 0x9bc
	// Line 360, Address: 0x2bdd34, Func Offset: 0x9c4
	// Line 361, Address: 0x2bdd4c, Func Offset: 0x9dc
	// Line 362, Address: 0x2bdd5c, Func Offset: 0x9ec
	// Line 367, Address: 0x2bdd64, Func Offset: 0x9f4
	// Line 369, Address: 0x2bdd6c, Func Offset: 0x9fc
	// Line 371, Address: 0x2bdd94, Func Offset: 0xa24
	// Line 373, Address: 0x2bdda8, Func Offset: 0xa38
	// Line 375, Address: 0x2bddb0, Func Offset: 0xa40
	// Line 376, Address: 0x2bddb8, Func Offset: 0xa48
	// Func End, Address: 0x2bddc8, Func Offset: 0xa58
	scePrintf("bhMainSpEvtComputer - UNIMPLEMENTED!\n");
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

/*// 
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
	_anon7* ce;
	unsigned int* qtbcol;
	_anon20* tbl;
	_anon20* qt;
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
}

// 
// Start address: 0x2bea90
void bhDrawSpEvtComputer()
{
	float pri;
	int j;
	int i;
	_anon7* ce;
	unsigned int* qtbcol;
	_anon20* qt;
	_anon37 sp[2];
	// Line 665, Address: 0x2bea90, Func Offset: 0
	// Line 669, Address: 0x2beac0, Func Offset: 0x30
	// Line 672, Address: 0x2bead4, Func Offset: 0x44
	// Line 677, Address: 0x2beadc, Func Offset: 0x4c
	// Line 676, Address: 0x2beae0, Func Offset: 0x50
	// Line 677, Address: 0x2beae4, Func Offset: 0x54
	// Line 678, Address: 0x2beae8, Func Offset: 0x58
	// Line 679, Address: 0x2beaf4, Func Offset: 0x64
	// Line 680, Address: 0x2beafc, Func Offset: 0x6c
	// Line 673, Address: 0x2beb00, Func Offset: 0x70
	// Line 674, Address: 0x2beb04, Func Offset: 0x74
	// Line 679, Address: 0x2beb08, Func Offset: 0x78
	// Line 680, Address: 0x2beb0c, Func Offset: 0x7c
	// Line 681, Address: 0x2beb14, Func Offset: 0x84
	// Line 682, Address: 0x2beb1c, Func Offset: 0x8c
	// Line 683, Address: 0x2beb28, Func Offset: 0x98
	// Line 686, Address: 0x2beb3c, Func Offset: 0xac
	// Line 689, Address: 0x2beb44, Func Offset: 0xb4
	// Line 690, Address: 0x2beb4c, Func Offset: 0xbc
	// Line 691, Address: 0x2beb58, Func Offset: 0xc8
	// Line 695, Address: 0x2beb68, Func Offset: 0xd8
	// Line 696, Address: 0x2beb74, Func Offset: 0xe4
	// Line 700, Address: 0x2beb88, Func Offset: 0xf8
	// Line 697, Address: 0x2beb90, Func Offset: 0x100
	// Line 700, Address: 0x2beb94, Func Offset: 0x104
	// Line 701, Address: 0x2bebac, Func Offset: 0x11c
	// Line 702, Address: 0x2bebb8, Func Offset: 0x128
	// Line 705, Address: 0x2bebcc, Func Offset: 0x13c
	// Line 706, Address: 0x2bebd8, Func Offset: 0x148
	// Line 707, Address: 0x2bebec, Func Offset: 0x15c
	// Line 708, Address: 0x2bebf0, Func Offset: 0x160
	// Line 711, Address: 0x2bebf4, Func Offset: 0x164
	// Line 712, Address: 0x2bec14, Func Offset: 0x184
	// Line 713, Address: 0x2bec20, Func Offset: 0x190
	// Line 716, Address: 0x2bec34, Func Offset: 0x1a4
	// Line 717, Address: 0x2bec40, Func Offset: 0x1b0
	// Line 718, Address: 0x2bec54, Func Offset: 0x1c4
	// Line 719, Address: 0x2bec58, Func Offset: 0x1c8
	// Line 721, Address: 0x2bec5c, Func Offset: 0x1cc
	// Line 723, Address: 0x2bec64, Func Offset: 0x1d4
	// Line 725, Address: 0x2bec84, Func Offset: 0x1f4
	// Line 726, Address: 0x2bec8c, Func Offset: 0x1fc
	// Line 727, Address: 0x2bec98, Func Offset: 0x208
	// Line 728, Address: 0x2beca0, Func Offset: 0x210
	// Line 729, Address: 0x2beca4, Func Offset: 0x214
	// Line 730, Address: 0x2becb4, Func Offset: 0x224
	// Line 732, Address: 0x2becbc, Func Offset: 0x22c
	// Line 731, Address: 0x2becc0, Func Offset: 0x230
	// Line 732, Address: 0x2becc4, Func Offset: 0x234
	// Line 733, Address: 0x2becc8, Func Offset: 0x238
	// Line 734, Address: 0x2becd0, Func Offset: 0x240
	// Line 735, Address: 0x2becd4, Func Offset: 0x244
	// Line 734, Address: 0x2becd8, Func Offset: 0x248
	// Line 735, Address: 0x2becdc, Func Offset: 0x24c
	// Line 738, Address: 0x2bece4, Func Offset: 0x254
	// Line 739, Address: 0x2becf0, Func Offset: 0x260
	// Line 740, Address: 0x2becf8, Func Offset: 0x268
	// Line 741, Address: 0x2bed00, Func Offset: 0x270
	// Line 742, Address: 0x2bed0c, Func Offset: 0x27c
	// Line 743, Address: 0x2bed18, Func Offset: 0x288
	// Line 744, Address: 0x2bed2c, Func Offset: 0x29c
	// Line 745, Address: 0x2bed30, Func Offset: 0x2a0
	// Line 746, Address: 0x2bed34, Func Offset: 0x2a4
	// Line 747, Address: 0x2bed38, Func Offset: 0x2a8
	// Line 748, Address: 0x2bed48, Func Offset: 0x2b8
	// Line 750, Address: 0x2bed58, Func Offset: 0x2c8
	// Line 751, Address: 0x2bed64, Func Offset: 0x2d4
	// Line 752, Address: 0x2bed78, Func Offset: 0x2e8
	// Line 754, Address: 0x2bed7c, Func Offset: 0x2ec
	// Line 756, Address: 0x2bed84, Func Offset: 0x2f4
	// Line 757, Address: 0x2bed90, Func Offset: 0x300
	// Line 758, Address: 0x2bed98, Func Offset: 0x308
	// Line 759, Address: 0x2beda0, Func Offset: 0x310
	// Line 760, Address: 0x2bedac, Func Offset: 0x31c
	// Line 761, Address: 0x2bedb8, Func Offset: 0x328
	// Line 762, Address: 0x2bedc4, Func Offset: 0x334
	// Line 761, Address: 0x2bedc8, Func Offset: 0x338
	// Line 763, Address: 0x2bedcc, Func Offset: 0x33c
	// Line 764, Address: 0x2bedd0, Func Offset: 0x340
	// Line 765, Address: 0x2bede8, Func Offset: 0x358
	// Line 768, Address: 0x2bedf0, Func Offset: 0x360
	// Line 767, Address: 0x2bedf4, Func Offset: 0x364
	// Line 768, Address: 0x2bedf8, Func Offset: 0x368
	// Line 769, Address: 0x2bedfc, Func Offset: 0x36c
	// Line 770, Address: 0x2bee04, Func Offset: 0x374
	// Line 771, Address: 0x2bee08, Func Offset: 0x378
	// Line 770, Address: 0x2bee0c, Func Offset: 0x37c
	// Line 771, Address: 0x2bee10, Func Offset: 0x380
	// Line 773, Address: 0x2bee18, Func Offset: 0x388
	// Line 775, Address: 0x2bee20, Func Offset: 0x390
	// Line 777, Address: 0x2bee2c, Func Offset: 0x39c
	// Line 778, Address: 0x2bee3c, Func Offset: 0x3ac
	// Line 779, Address: 0x2beea8, Func Offset: 0x418
	// Line 780, Address: 0x2beecc, Func Offset: 0x43c
	// Line 781, Address: 0x2beedc, Func Offset: 0x44c
	// Line 783, Address: 0x2beef4, Func Offset: 0x464
	// Line 785, Address: 0x2bef10, Func Offset: 0x480
	// Line 783, Address: 0x2bef18, Func Offset: 0x488
	// Line 785, Address: 0x2bef1c, Func Offset: 0x48c
	// Line 786, Address: 0x2bef24, Func Offset: 0x494
	// Line 787, Address: 0x2bef34, Func Offset: 0x4a4
	// Line 788, Address: 0x2bef44, Func Offset: 0x4b4
	// Line 790, Address: 0x2bef54, Func Offset: 0x4c4
	// Line 796, Address: 0x2bef74, Func Offset: 0x4e4
	// Line 800, Address: 0x2befbc, Func Offset: 0x52c
	// Func End, Address: 0x2beff0, Func Offset: 0x560
}*/

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

/*// 
// Start address: 0x2bfdd0
void bhControlComEvtScript()
{
	char* wcpb;
	char* wcpa;
	unsigned short flgno;
	unsigned int* mstb;
	unsigned int bit;
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char cmd;
	_anon7* ce;
	// Line 1202, Address: 0x2bfdd0, Func Offset: 0
	// Line 1203, Address: 0x2bfde0, Func Offset: 0x10
	// Line 1209, Address: 0x2bfdf4, Func Offset: 0x24
	// Line 1211, Address: 0x2bfe24, Func Offset: 0x54
	// Line 1212, Address: 0x2bfe2c, Func Offset: 0x5c
	// Line 1213, Address: 0x2bfe38, Func Offset: 0x68
	// Line 1215, Address: 0x2bfe50, Func Offset: 0x80
	// Line 1217, Address: 0x2bfe5c, Func Offset: 0x8c
	// Line 1219, Address: 0x2bfe64, Func Offset: 0x94
	// Line 1220, Address: 0x2bfe6c, Func Offset: 0x9c
	// Line 1221, Address: 0x2bfe74, Func Offset: 0xa4
	// Line 1222, Address: 0x2bfe78, Func Offset: 0xa8
	// Line 1221, Address: 0x2bfe84, Func Offset: 0xb4
	// Line 1222, Address: 0x2bfec4, Func Offset: 0xf4
	// Line 1223, Address: 0x2bfecc, Func Offset: 0xfc
	// Line 1224, Address: 0x2bfed8, Func Offset: 0x108
	// Line 1227, Address: 0x2bfef8, Func Offset: 0x128
	// Line 1228, Address: 0x2bff04, Func Offset: 0x134
	// Line 1229, Address: 0x2bff08, Func Offset: 0x138
	// Line 1231, Address: 0x2bff10, Func Offset: 0x140
	// Line 1232, Address: 0x2bff20, Func Offset: 0x150
	// Line 1234, Address: 0x2bff48, Func Offset: 0x178
	// Line 1237, Address: 0x2bff4c, Func Offset: 0x17c
	// Line 1234, Address: 0x2bff58, Func Offset: 0x188
	// Line 1235, Address: 0x2bff60, Func Offset: 0x190
	// Line 1237, Address: 0x2bff74, Func Offset: 0x1a4
	// Line 1238, Address: 0x2bffa0, Func Offset: 0x1d0
	// Line 1240, Address: 0x2bffa8, Func Offset: 0x1d8
	// Line 1241, Address: 0x2bffb8, Func Offset: 0x1e8
	// Line 1243, Address: 0x2bffc0, Func Offset: 0x1f0
	// Line 1244, Address: 0x2bffc8, Func Offset: 0x1f8
	// Line 1246, Address: 0x2bffd0, Func Offset: 0x200
	// Line 1247, Address: 0x2bffe0, Func Offset: 0x210
	// Line 1249, Address: 0x2bffe4, Func Offset: 0x214
	// Line 1247, Address: 0x2bffec, Func Offset: 0x21c
	// Line 1248, Address: 0x2bfff8, Func Offset: 0x228
	// Line 1249, Address: 0x2bfffc, Func Offset: 0x22c
	// Line 1248, Address: 0x2c0008, Func Offset: 0x238
	// Line 1249, Address: 0x2c0014, Func Offset: 0x244
	// Line 1250, Address: 0x2c0020, Func Offset: 0x250
	// Line 1252, Address: 0x2c0028, Func Offset: 0x258
	// Line 1253, Address: 0x2c002c, Func Offset: 0x25c
	// Line 1252, Address: 0x2c0038, Func Offset: 0x268
	// Line 1253, Address: 0x2c0078, Func Offset: 0x2a8
	// Line 1254, Address: 0x2c0080, Func Offset: 0x2b0
	// Line 1255, Address: 0x2c0088, Func Offset: 0x2b8
	// Line 1257, Address: 0x2c0090, Func Offset: 0x2c0
	// Line 1258, Address: 0x2c00a4, Func Offset: 0x2d4
	// Line 1259, Address: 0x2c00e4, Func Offset: 0x314
	// Line 1260, Address: 0x2c0108, Func Offset: 0x338
	// Line 1262, Address: 0x2c010c, Func Offset: 0x33c
	// Line 1265, Address: 0x2c0110, Func Offset: 0x340
	// Line 1267, Address: 0x2c0114, Func Offset: 0x344
	// Line 1260, Address: 0x2c0118, Func Offset: 0x348
	// Line 1261, Address: 0x2c011c, Func Offset: 0x34c
	// Line 1272, Address: 0x2c0120, Func Offset: 0x350
	// Line 1261, Address: 0x2c012c, Func Offset: 0x35c
	// Line 1262, Address: 0x2c0130, Func Offset: 0x360
	// Line 1263, Address: 0x2c0150, Func Offset: 0x380
	// Line 1264, Address: 0x2c015c, Func Offset: 0x38c
	// Line 1265, Address: 0x2c0168, Func Offset: 0x398
	// Line 1266, Address: 0x2c016c, Func Offset: 0x39c
	// Line 1267, Address: 0x2c0170, Func Offset: 0x3a0
	// Line 1268, Address: 0x2c0174, Func Offset: 0x3a4
	// Line 1269, Address: 0x2c0178, Func Offset: 0x3a8
	// Line 1270, Address: 0x2c017c, Func Offset: 0x3ac
	// Line 1272, Address: 0x2c0180, Func Offset: 0x3b0
	// Line 1273, Address: 0x2c0188, Func Offset: 0x3b8
	// Line 1274, Address: 0x2c019c, Func Offset: 0x3cc
	// Line 1276, Address: 0x2c01a4, Func Offset: 0x3d4
	// Line 1278, Address: 0x2c01ac, Func Offset: 0x3dc
	// Line 1276, Address: 0x2c01b0, Func Offset: 0x3e0
	// Line 1278, Address: 0x2c01b4, Func Offset: 0x3e4
	// Line 1277, Address: 0x2c01b8, Func Offset: 0x3e8
	// Line 1276, Address: 0x2c01bc, Func Offset: 0x3ec
	// Line 1278, Address: 0x2c01c8, Func Offset: 0x3f8
	// Line 1276, Address: 0x2c01cc, Func Offset: 0x3fc
	// Line 1278, Address: 0x2c01dc, Func Offset: 0x40c
	// Line 1279, Address: 0x2c01e4, Func Offset: 0x414
	// Line 1280, Address: 0x2c01f8, Func Offset: 0x428
	// Line 1283, Address: 0x2c0200, Func Offset: 0x430
	// Line 1284, Address: 0x2c0214, Func Offset: 0x444
	// Line 1285, Address: 0x2c0228, Func Offset: 0x458
	// Line 1287, Address: 0x2c0230, Func Offset: 0x460
	// Line 1289, Address: 0x2c0238, Func Offset: 0x468
	// Line 1287, Address: 0x2c023c, Func Offset: 0x46c
	// Line 1289, Address: 0x2c0240, Func Offset: 0x470
	// Line 1288, Address: 0x2c0244, Func Offset: 0x474
	// Line 1287, Address: 0x2c0248, Func Offset: 0x478
	// Line 1289, Address: 0x2c0254, Func Offset: 0x484
	// Line 1287, Address: 0x2c0258, Func Offset: 0x488
	// Line 1289, Address: 0x2c0268, Func Offset: 0x498
	// Line 1290, Address: 0x2c0270, Func Offset: 0x4a0
	// Line 1291, Address: 0x2c0284, Func Offset: 0x4b4
	// Line 1293, Address: 0x2c028c, Func Offset: 0x4bc
	// Line 1294, Address: 0x2c0294, Func Offset: 0x4c4
	// Line 1296, Address: 0x2c029c, Func Offset: 0x4cc
	// Line 1297, Address: 0x2c02ac, Func Offset: 0x4dc
	// Line 1296, Address: 0x2c02b0, Func Offset: 0x4e0
	// Line 1297, Address: 0x2c02bc, Func Offset: 0x4ec
	// Line 1296, Address: 0x2c02c0, Func Offset: 0x4f0
	// Line 1297, Address: 0x2c02cc, Func Offset: 0x4fc
	// Line 1298, Address: 0x2c02d4, Func Offset: 0x504
	// Line 1297, Address: 0x2c02d8, Func Offset: 0x508
	// Line 1298, Address: 0x2c02e4, Func Offset: 0x514
	// Line 1299, Address: 0x2c02f8, Func Offset: 0x528
	// Line 1298, Address: 0x2c02fc, Func Offset: 0x52c
	// Line 1299, Address: 0x2c0300, Func Offset: 0x530
	// Line 1300, Address: 0x2c0308, Func Offset: 0x538
	// Line 1301, Address: 0x2c0318, Func Offset: 0x548
	// Line 1304, Address: 0x2c0328, Func Offset: 0x558
	// Line 1305, Address: 0x2c0330, Func Offset: 0x560
	// Line 1309, Address: 0x2c0344, Func Offset: 0x574
	// Line 1311, Address: 0x2c034c, Func Offset: 0x57c
	// Line 1312, Address: 0x2c0354, Func Offset: 0x584
	// Line 1314, Address: 0x2c035c, Func Offset: 0x58c
	// Line 1315, Address: 0x2c0378, Func Offset: 0x5a8
	// Line 1317, Address: 0x2c0380, Func Offset: 0x5b0
	// Line 1318, Address: 0x2c0384, Func Offset: 0x5b4
	// Line 1317, Address: 0x2c0388, Func Offset: 0x5b8
	// Line 1318, Address: 0x2c0394, Func Offset: 0x5c4
	// Line 1320, Address: 0x2c03a8, Func Offset: 0x5d8
	// Line 1323, Address: 0x2c03cc, Func Offset: 0x5fc
	// Line 1324, Address: 0x2c03d4, Func Offset: 0x604
	// Line 1326, Address: 0x2c03dc, Func Offset: 0x60c
	// Line 1335, Address: 0x2c03e4, Func Offset: 0x614
	// Line 1336, Address: 0x2c03ec, Func Offset: 0x61c
	// Line 1337, Address: 0x2c03f4, Func Offset: 0x624
	// Line 1326, Address: 0x2c03f8, Func Offset: 0x628
	// Line 1327, Address: 0x2c0414, Func Offset: 0x644
	// Line 1328, Address: 0x2c0428, Func Offset: 0x658
	// Line 1329, Address: 0x2c0440, Func Offset: 0x670
	// Line 1330, Address: 0x2c0458, Func Offset: 0x688
	// Line 1334, Address: 0x2c0470, Func Offset: 0x6a0
	// Line 1335, Address: 0x2c0474, Func Offset: 0x6a4
	// Line 1336, Address: 0x2c0478, Func Offset: 0x6a8
	// Line 1337, Address: 0x2c047c, Func Offset: 0x6ac
	// Line 1338, Address: 0x2c0480, Func Offset: 0x6b0
	// Line 1340, Address: 0x2c0484, Func Offset: 0x6b4
	// Line 1342, Address: 0x2c048c, Func Offset: 0x6bc
	// Line 1343, Address: 0x2c04a0, Func Offset: 0x6d0
	// Line 1344, Address: 0x2c04b0, Func Offset: 0x6e0
	// Line 1346, Address: 0x2c04b8, Func Offset: 0x6e8
	// Line 1348, Address: 0x2c04bc, Func Offset: 0x6ec
	// Line 1346, Address: 0x2c04c0, Func Offset: 0x6f0
	// Line 1347, Address: 0x2c04cc, Func Offset: 0x6fc
	// Line 1348, Address: 0x2c04dc, Func Offset: 0x70c
	// Line 1347, Address: 0x2c04e0, Func Offset: 0x710
	// Line 1348, Address: 0x2c04e8, Func Offset: 0x718
	// Line 1349, Address: 0x2c04f4, Func Offset: 0x724
	// Line 1351, Address: 0x2c04fc, Func Offset: 0x72c
	// Line 1353, Address: 0x2c0500, Func Offset: 0x730
	// Line 1351, Address: 0x2c0504, Func Offset: 0x734
	// Line 1352, Address: 0x2c0514, Func Offset: 0x744
	// Line 1353, Address: 0x2c0528, Func Offset: 0x758
	// Line 1354, Address: 0x2c0544, Func Offset: 0x774
	// Line 1356, Address: 0x2c054c, Func Offset: 0x77c
	// Line 1357, Address: 0x2c0570, Func Offset: 0x7a0
	// Line 1360, Address: 0x2c0578, Func Offset: 0x7a8
	// Line 1362, Address: 0x2c0580, Func Offset: 0x7b0
	// Line 1363, Address: 0x2c05a4, Func Offset: 0x7d4
	// Line 1365, Address: 0x2c05ac, Func Offset: 0x7dc
	// Line 1366, Address: 0x2c05cc, Func Offset: 0x7fc
	// Line 1368, Address: 0x2c05d4, Func Offset: 0x804
	// Line 1369, Address: 0x2c05e4, Func Offset: 0x814
	// Line 1370, Address: 0x2c05e8, Func Offset: 0x818
	// Line 1371, Address: 0x2c05f4, Func Offset: 0x824
	// Line 1373, Address: 0x2c0604, Func Offset: 0x834
	// Line 1374, Address: 0x2c0608, Func Offset: 0x838
	// Line 1377, Address: 0x2c0614, Func Offset: 0x844
	// Line 1379, Address: 0x2c061c, Func Offset: 0x84c
	// Line 1380, Address: 0x2c0620, Func Offset: 0x850
	// Line 1383, Address: 0x2c0638, Func Offset: 0x868
	// Func End, Address: 0x2c064c, Func Offset: 0x87c
}

// 
// Start address: 0x2c0650
void bhControlComEvtKeyboard()
{
	int adt;
	int sel;
	int i;
	_anon7* ce;
	// Line 1389, Address: 0x2c0650, Func Offset: 0
	// Line 1390, Address: 0x2c0660, Func Offset: 0x10
	// Line 1395, Address: 0x2c0674, Func Offset: 0x24
	// Line 1397, Address: 0x2c06ac, Func Offset: 0x5c
	// Line 1398, Address: 0x2c06b8, Func Offset: 0x68
	// Line 1399, Address: 0x2c06c8, Func Offset: 0x78
	// Line 1400, Address: 0x2c06cc, Func Offset: 0x7c
	// Line 1403, Address: 0x2c06d4, Func Offset: 0x84
	// Line 1404, Address: 0x2c06d8, Func Offset: 0x88
	// Line 1406, Address: 0x2c06dc, Func Offset: 0x8c
	// Line 1407, Address: 0x2c0708, Func Offset: 0xb8
	// Line 1408, Address: 0x2c0714, Func Offset: 0xc4
	// Line 1409, Address: 0x2c0724, Func Offset: 0xd4
	// Line 1411, Address: 0x2c072c, Func Offset: 0xdc
	// Line 1412, Address: 0x2c073c, Func Offset: 0xec
	// Line 1413, Address: 0x2c074c, Func Offset: 0xfc
	// Line 1414, Address: 0x2c0750, Func Offset: 0x100
	// Line 1417, Address: 0x2c0758, Func Offset: 0x108
	// Line 1418, Address: 0x2c075c, Func Offset: 0x10c
	// Line 1420, Address: 0x2c0760, Func Offset: 0x110
	// Line 1422, Address: 0x2c0764, Func Offset: 0x114
	// Line 1420, Address: 0x2c0770, Func Offset: 0x120
	// Line 1421, Address: 0x2c0778, Func Offset: 0x128
	// Line 1422, Address: 0x2c0780, Func Offset: 0x130
	// Line 1423, Address: 0x2c0788, Func Offset: 0x138
	// Line 1425, Address: 0x2c0790, Func Offset: 0x140
	// Line 1426, Address: 0x2c07a0, Func Offset: 0x150
	// Line 1427, Address: 0x2c07b0, Func Offset: 0x160
	// Line 1428, Address: 0x2c07b4, Func Offset: 0x164
	// Line 1431, Address: 0x2c07bc, Func Offset: 0x16c
	// Line 1432, Address: 0x2c07c0, Func Offset: 0x170
	// Line 1434, Address: 0x2c07c4, Func Offset: 0x174
	// Line 1435, Address: 0x2c07c8, Func Offset: 0x178
	// Line 1434, Address: 0x2c07d4, Func Offset: 0x184
	// Line 1435, Address: 0x2c07d8, Func Offset: 0x188
	// Line 1436, Address: 0x2c07e0, Func Offset: 0x190
	// Line 1438, Address: 0x2c07e8, Func Offset: 0x198
	// Line 1439, Address: 0x2c07f8, Func Offset: 0x1a8
	// Line 1440, Address: 0x2c0808, Func Offset: 0x1b8
	// Line 1441, Address: 0x2c080c, Func Offset: 0x1bc
	// Line 1444, Address: 0x2c0814, Func Offset: 0x1c4
	// Line 1445, Address: 0x2c0818, Func Offset: 0x1c8
	// Line 1447, Address: 0x2c081c, Func Offset: 0x1cc
	// Line 1449, Address: 0x2c0820, Func Offset: 0x1d0
	// Line 1447, Address: 0x2c082c, Func Offset: 0x1dc
	// Line 1448, Address: 0x2c0834, Func Offset: 0x1e4
	// Line 1449, Address: 0x2c083c, Func Offset: 0x1ec
	// Line 1450, Address: 0x2c0844, Func Offset: 0x1f4
	// Line 1452, Address: 0x2c084c, Func Offset: 0x1fc
	// Line 1453, Address: 0x2c085c, Func Offset: 0x20c
	// Line 1454, Address: 0x2c086c, Func Offset: 0x21c
	// Line 1455, Address: 0x2c0870, Func Offset: 0x220
	// Line 1458, Address: 0x2c0878, Func Offset: 0x228
	// Line 1459, Address: 0x2c087c, Func Offset: 0x22c
	// Line 1461, Address: 0x2c0880, Func Offset: 0x230
	// Line 1462, Address: 0x2c08ac, Func Offset: 0x25c
	// Line 1463, Address: 0x2c08b8, Func Offset: 0x268
	// Line 1464, Address: 0x2c08c8, Func Offset: 0x278
	// Line 1466, Address: 0x2c08d0, Func Offset: 0x280
	// Line 1467, Address: 0x2c08e0, Func Offset: 0x290
	// Line 1468, Address: 0x2c08f0, Func Offset: 0x2a0
	// Line 1469, Address: 0x2c08f4, Func Offset: 0x2a4
	// Line 1472, Address: 0x2c08fc, Func Offset: 0x2ac
	// Line 1473, Address: 0x2c0900, Func Offset: 0x2b0
	// Line 1475, Address: 0x2c0904, Func Offset: 0x2b4
	// Line 1477, Address: 0x2c0908, Func Offset: 0x2b8
	// Line 1475, Address: 0x2c0914, Func Offset: 0x2c4
	// Line 1476, Address: 0x2c091c, Func Offset: 0x2cc
	// Line 1477, Address: 0x2c0924, Func Offset: 0x2d4
	// Line 1478, Address: 0x2c092c, Func Offset: 0x2dc
	// Line 1480, Address: 0x2c0934, Func Offset: 0x2e4
	// Line 1481, Address: 0x2c0944, Func Offset: 0x2f4
	// Line 1482, Address: 0x2c0954, Func Offset: 0x304
	// Line 1483, Address: 0x2c0958, Func Offset: 0x308
	// Line 1486, Address: 0x2c0960, Func Offset: 0x310
	// Line 1487, Address: 0x2c0964, Func Offset: 0x314
	// Line 1489, Address: 0x2c0968, Func Offset: 0x318
	// Line 1490, Address: 0x2c096c, Func Offset: 0x31c
	// Line 1489, Address: 0x2c0978, Func Offset: 0x328
	// Line 1490, Address: 0x2c097c, Func Offset: 0x32c
	// Line 1491, Address: 0x2c0984, Func Offset: 0x334
	// Line 1493, Address: 0x2c098c, Func Offset: 0x33c
	// Line 1494, Address: 0x2c099c, Func Offset: 0x34c
	// Line 1495, Address: 0x2c09ac, Func Offset: 0x35c
	// Line 1496, Address: 0x2c09b0, Func Offset: 0x360
	// Line 1499, Address: 0x2c09b8, Func Offset: 0x368
	// Line 1500, Address: 0x2c09bc, Func Offset: 0x36c
	// Line 1502, Address: 0x2c09c0, Func Offset: 0x370
	// Line 1504, Address: 0x2c09c4, Func Offset: 0x374
	// Line 1502, Address: 0x2c09d0, Func Offset: 0x380
	// Line 1503, Address: 0x2c09d8, Func Offset: 0x388
	// Line 1504, Address: 0x2c09e0, Func Offset: 0x390
	// Line 1505, Address: 0x2c09e8, Func Offset: 0x398
	// Line 1507, Address: 0x2c09f0, Func Offset: 0x3a0
	// Line 1508, Address: 0x2c09f8, Func Offset: 0x3a8
	// Line 1511, Address: 0x2c09fc, Func Offset: 0x3ac
	// Line 1512, Address: 0x2c0a10, Func Offset: 0x3c0
	// Line 1513, Address: 0x2c0a24, Func Offset: 0x3d4
	// Line 1514, Address: 0x2c0a38, Func Offset: 0x3e8
	// Line 1516, Address: 0x2c0a4c, Func Offset: 0x3fc
	// Line 1518, Address: 0x2c0a6c, Func Offset: 0x41c
	// Line 1520, Address: 0x2c0a70, Func Offset: 0x420
	// Line 1518, Address: 0x2c0a74, Func Offset: 0x424
	// Line 1519, Address: 0x2c0a7c, Func Offset: 0x42c
	// Line 1520, Address: 0x2c0a94, Func Offset: 0x444
	// Line 1522, Address: 0x2c0ac8, Func Offset: 0x478
	// Line 1523, Address: 0x2c0acc, Func Offset: 0x47c
	// Line 1524, Address: 0x2c0ae0, Func Offset: 0x490
	// Line 1526, Address: 0x2c0ae8, Func Offset: 0x498
	// Line 1527, Address: 0x2c0af4, Func Offset: 0x4a4
	// Line 1528, Address: 0x2c0b04, Func Offset: 0x4b4
	// Line 1529, Address: 0x2c0b10, Func Offset: 0x4c0
	// Line 1530, Address: 0x2c0b28, Func Offset: 0x4d8
	// Line 1531, Address: 0x2c0b34, Func Offset: 0x4e4
	// Line 1532, Address: 0x2c0b60, Func Offset: 0x510
	// Line 1535, Address: 0x2c0b68, Func Offset: 0x518
	// Line 1536, Address: 0x2c0b78, Func Offset: 0x528
	// Line 1537, Address: 0x2c0b88, Func Offset: 0x538
	// Line 1539, Address: 0x2c0b94, Func Offset: 0x544
	// Line 1541, Address: 0x2c0b9c, Func Offset: 0x54c
	// Line 1542, Address: 0x2c0bac, Func Offset: 0x55c
	// Line 1543, Address: 0x2c0bc0, Func Offset: 0x570
	// Line 1545, Address: 0x2c0bcc, Func Offset: 0x57c
	// Line 1546, Address: 0x2c0be4, Func Offset: 0x594
	// Line 1548, Address: 0x2c0bec, Func Offset: 0x59c
	// Line 1550, Address: 0x2c0bf8, Func Offset: 0x5a8
	// Line 1551, Address: 0x2c0c00, Func Offset: 0x5b0
	// Line 1553, Address: 0x2c0c0c, Func Offset: 0x5bc
	// Line 1554, Address: 0x2c0c14, Func Offset: 0x5c4
	// Line 1557, Address: 0x2c0c18, Func Offset: 0x5c8
	// Line 1559, Address: 0x2c0c1c, Func Offset: 0x5cc
	// Line 1560, Address: 0x2c0c24, Func Offset: 0x5d4
	// Line 1559, Address: 0x2c0c28, Func Offset: 0x5d8
	// Line 1560, Address: 0x2c0c54, Func Offset: 0x604
	// Line 1561, Address: 0x2c0c6c, Func Offset: 0x61c
	// Line 1562, Address: 0x2c0c84, Func Offset: 0x634
	// Line 1563, Address: 0x2c0c90, Func Offset: 0x640
	// Line 1568, Address: 0x2c0c9c, Func Offset: 0x64c
	// Line 1569, Address: 0x2c0cbc, Func Offset: 0x66c
	// Line 1570, Address: 0x2c0cc4, Func Offset: 0x674
	// Line 1571, Address: 0x2c0d00, Func Offset: 0x6b0
	// Line 1572, Address: 0x2c0d0c, Func Offset: 0x6bc
	// Line 1573, Address: 0x2c0d10, Func Offset: 0x6c0
	// Line 1575, Address: 0x2c0d28, Func Offset: 0x6d8
	// Func End, Address: 0x2c0d3c, Func Offset: 0x6ec
}*/
