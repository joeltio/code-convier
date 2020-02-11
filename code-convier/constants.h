
#ifndef _CONSTANTS_H            // prevent multiple definitions if this
#define _CONSTANTS_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)
// mapped as VKs and not Char to prevent confusion later on
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// graphic images
const char MAINMENU_IMAGE[] = "MainMenuBackground.png";
const char CREDITS_BUTTON[] = "Credits.png";
const char MENU_BUTTON[] = "Menu.png";
const char QUIT_BUTTON[] = "Quit.png";
const char RESUME_BUTTON[] = "Resume.png";
const char START_BUTTON[] = "Start.png";

const char PLAYER_IDLE_IMAGE[] = "Player_Idle.png";
const char PLAYER_DYING_IMAGE[] = "Player_Dying.png";
const char PLAYER_JUMP_IMAGE[] = "Player_Jump.png";
const char PLAYER_JUMP_SHOOT_IMAGE[] = "Player_Jump_Shooting.png";
const char PLAYER_MELEE_IMAGE[] = "Player_Melee.png";
const char PLAYER_MELEE_JUMP_IMAGE[] = "Player_Melee_Jump.png";
const char PLAYER_RUN_IMAGE[] = "Player_Run.png";
const char PLAYER_RUN_SHOOT_IMAGE[] = "Player_Run_Shooting.png";
const char PLAYER_SHOOT_IMAGE[] = "Player_Shoot.png";
const char PLAYER_SLIDE_IMAGE[] = "Player_Slide.png";

// window
const char CLASS_NAME[] = "Code::Convier";
const char GAME_TITLE[] = "Code::Convier";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 1024;               // width of game in pixels
const UINT GAME_HEIGHT = 768;               // height of game in pixels
const float SCALE_FACTOR = 1;

// game
const float PI = 3.14159265f;
const float UP_ANGLE = 0.0f;
const float LEFT_ANGLE = PI * 3 / 2.0f;
const float RIGHT_ANGLE = PI / 2.0f;
const float DOWN_ANGLE = PI;
const float FRAME_RATE = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const int levelWidth = 50;
const int levelHeight = 20;
const int tileHeight = 48;
const int tileWidth = 48;
const int visibleX = GAME_WIDTH / tileWidth;
const int visibleY = GAME_HEIGHT / tileHeight;

const int BUTTON_MARGIN = 30;

const float PLAYER_SPEED = 150.0f;
const float ENEMY_SPEED = 150.0f;


// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key
const UCHAR LEFT_KEY = VK_A;
const UCHAR RIGHT_KEY = VK_D;
const UCHAR UP_KEY = VK_W;
const UCHAR DOWN_KEY = VK_S;

#endif
