
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
const char CREDITSBACKGROUND_IMAGE[] = "CreditsBackground.png";
const char TEMPORARY_AUGMENTATION_IMAGE[] = "TemporaryAugmentation.png";
const char PLAYER_DEATH_SCREEN_IMAGE[] = "PlayerDeathScreen.png";

const char PLAYER_CHARGING_ICON[] = "ChargingSprite.png";
const char PLAYER_RUNNING_ICON[] = "RunningSprite.png";

const char ENERGY_EFFICIENT_IMAGE[] = "EnergyEfficient.png";
const char INCREASED_DAMAGE_IMAGE[] = "IncreasedDamage.png";
const char MULTIHIT_IMAGE[] = "MultiHit.png";

const char CREDITS_BUTTON[] = "Credits.png";
const char MENU_BUTTON[] = "Menu.png";
const char QUIT_BUTTON[] = "Quit.png";
const char RESUME_BUTTON[] = "Resume.png";
const char START_BUTTON[] = "Start.png";

const char HEALTHBAR_IMAGE[] = "Healthbar.png";

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

//Tile
const char JAIL_IMAGE[] = "./sprites/jail.png";
const char DOOR_IMAGE[] = "./sprites/door.png";
const char PLATFORM_START_IMAGE[] = "./sprites/{.png";
const char PLATFORM1_IMAGE[] = "./sprites/1.png";
const char PLATFORM2_IMAGE[] = "./sprites/2.png";
const char PLATFORM3_IMAGE[] = "./sprites/3.png";
const char PLATFORM4_IMAGE[] = "./sprites/4.png";
const char PLATFORM_END_IMAGE[] = "./sprites/}.png";
const char BACKGROUND_TILE_IMAGE[] = "./sprites/background.png";
const char NORMAL_WALL_IMAGE[] = "./sprites/C wall.png";
const char LEFT_WALL_IMAGE[] = "./sprites/CL wall.png";
const char RIGHT_WALL_IMAGE[] = "./sprites/CR wall.png";
const char BOTTOM_WALL_IMAGE[] = "./sprites/TC wall.png";
const char TOP_WALL_IMAGE[] = "./sprites/BC wall.png";
const char TOP_LEFT_CORNER_IMAGE[] = "./sprites/BR wall.png";
const char TOP_RIGHT_CORNER_IMAGE[] = "./sprites/BL wall.png";
const char BOTTOM_LEFT_CORNER_IMAGE[] = "./sprites/TR wall.png";
const char BOTTOM_RIGHT_CORNER_IMAGE[] = "./sprites/TL wall.png";
const char SOLID_TILES[] = ".-_/\\{}()<>1234";
const char DECORATIVE_TILES[] = " *$";

// Energy Orb
const char XP_1_IMAGE[] = "./sprites/XP-Yellow.png";
const char XP_2_IMAGE[] = "./sprites/XP-Lime.png";
const char XP_3_IMAGE[] = "./sprites/XP-Green.png";
const char XP_4_IMAGE[] = "./sprites/XP-BrightGreen.png";

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
const int mapFragment = 3;
const int levelWidth = mapFragment + 40;
const int levelHeight = 12;
const int tileHeight = 64;
const int tileWidth = 64;
const int visibleX = GAME_WIDTH / tileWidth;
const int visibleY = GAME_HEIGHT / tileHeight;

const int BUTTON_MARGIN = 30;
const int CARD_SIDE_MARGIN = 65;
const int CARD_MARGIN = 87;

const float PLAYER_SPEED = 100.0f;
const float PLAYER_CHARGE_SPEED = 200.0f;
const float RUN_MULTIPLIER = 1.5f;
const float JUMP_SPEED = 1000.0f;
const int PLAYER_DAMAGE = 10;
const float PLAYER_ATTACK_COOLDOWN = 4.0f;
const float PLAYER_ATTACK_RANGE = 50.0f;
const int PLAYER_HEALTH = 100;
const int HEALTH_TICK = 3;
const int RUNNING_HEATLH_TICK = 4;
const int CHARGE_HEALTH_TICK = 2;
const int AUGMENTATED_HEAL = 1;
const float AUGMENTATED_COOLDOWN_REDUCTION = 0.5f;
const float AUGMENTATED_DAMAGE_MULTIPLIER = 0.5f;
const float AUGMENTATED_SPEED_MULTIPLIER = 0.1f;

const float ENEMY_SPEED = 100.0f;
const int ENEMY_HEALTH = 40;
const float ENEMY_ATTACK_DAMAGE = 6.0f;
const float ENEMY_ATTACK_COOLDOWN = 1.5f;
const int ENEMY_COUNT = 20;

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key
const UCHAR LSHIFT_KEY = VK_LSHIFT;

#endif
