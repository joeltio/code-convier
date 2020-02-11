
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
const char MAINMENU_IMAGE[] = "MainMenu.png";
const char PAUSEMENU_IMAGE[] = "PauseMenu.png";
const char CREDITS_BUTTON[] = "Credits.png";
const char MENU_BUTTON[] = "Menu.png";
const char QUIT_BUTTON[] = "Quit.png";
const char RESUME_BUTTON[] = "Resume.png";
const char START_BUTTON[] = "Start.png";

const char PLAYER_IMAGE[] = "Player_Idle.png";
const char PLAYER_DYING_IMAGE[] = "Player_Dying.png";
const char PLAYER_JUMP_IMAGE[] = "Player_Jump.png";
const char PLAYER_JUMP_SHOOT_IMAGE[] = "Player_Jump_Shooting.png";
const char PLAYER_MELEE_IMAGE[] = "Player_Melee.png";
const char PLAYER_MELEE_JUMP_IMAGE[] = "Player_Melee_Jump.png";
const char PLAYER_RUN_IMAGE[] = "Player_Run.png";
const char PLAYER_RUN_SHOOT_IMAGE[] = "Player_Run_Shooting.png";
const char PLAYER_SHOOT_IMAGE[] = "Player_Shoot.png";
const char PLAYER_SLIDE_IMAGE[] = "Player_Slide.png";

//Enemy
const char SKELETON_ATTACK_IMAGE[] = "Skeleton_Attack.png";
const char SKELETON_DEAD_IMAGE[] = "Skeleton_Dead.png";
const char SKELETON_HIT_IMAGE[] = "Skeleton_Hit.png";
const char SKELETON_IDLE_IMAGE[] = "Skeleton_Idle.png";
const char SKELETON_REACT_IMAGE[] = "Skeleton_React.png";
const char SKELETON_WALK_IMAGE[] = "Skeleton_Walk.png";

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
const int levelHeight = 12;
const int tileHeight = 48;
const int tileWidth = 48;
const int visibleX = GAME_WIDTH / tileWidth;
const int visibleY = GAME_HEIGHT / tileHeight;

const int BUTTON_MARGIN = 30;

const float PLAYER_SPEED = 100.0f;
const float PLAYER_CHARGE_SPEED = 200.0f;
const float RUN_MULTIPLIER = 1.5f;
const float JUMP_SPEED = 50.0f;
const int PLAYER_HEALTH = 100;
const int HEALTH_TICK = 3;
const int RUNNING_HEATLH_TICK = 4;
const int CHARGE_HEALTH_TICK = 2;
const float ENEMY_SPEED = 100.0f;

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key
const UCHAR LSHIFT_KEY = VK_LSHIFT;

#endif
