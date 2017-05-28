#include "stdlib.h"

typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;

typedef volatile uint8_t* frame_buffer_t;
typedef volatile struct Custom* custom_t;
#define GAME_PAVEMENT_START      66
#define SCREEN_WIDTH             320
#define SCREEN_HEIGHT            256

#define MAP_TILE_WIDTH           100
#define MAP_TILE_HEIGHT          13
#define TILE_WIDTH               16
#define TILE_HEIGHT              16
#define PLAYAREA_HEIGHT          MAP_TILE_HEIGHT*TILE_HEIGHT
#define GAME_WORLD_HEIGHT        (MAP_TILE_HEIGHT*TILE_HEIGHT)
#define GAME_WORLD_WIDTH         (MAP_TILE_WIDTH*TILE_WIDTH)

#define LEVEL1_ENEMY_BOSS_START_Y (7+56)
#define LEVEL1_ENEMY_BOSS_START_X (GAME_WORLD_WIDTH-96)

extern int16_t game_cameraX;

#ifndef __OBJECT_H
#define __OBJECT_H

#define OBJECT_MAX_OBJECTS    12
#define OBJECT_PHYSICS_FACTOR 2
#define OBJECT_WIDTH 32

#define OBJECT_HIT_DISTANCE 31

typedef enum {
  SPRITE_PLAYER1_STAND_RIGHT,
  SPRITE_PLAYER1_RUN_RIGHT_1,
  SPRITE_PLAYER1_RUN_RIGHT_2,
  SPRITE_PLAYER1_RUN_RIGHT_3,
  SPRITE_PLAYER1_RUN_RIGHT_4,
  SPRITE_PLAYER1_STAND_LEFT,
  SPRITE_PLAYER1_RUN_LEFT_1,
  SPRITE_PLAYER1_RUN_LEFT_2,
  SPRITE_PLAYER1_RUN_LEFT_3,
  SPRITE_PLAYER1_RUN_LEFT_4,
  SPRITE_PLAYER1_PUNCH_LEFT_1,
  SPRITE_PLAYER1_PUNCH_LEFT_2,
  SPRITE_PLAYER1_PUNCH_RIGHT_1,
  SPRITE_PLAYER1_PUNCH_RIGHT_2,
  SPRITE_PLAYER1_HIT_LEFT,
  SPRITE_PLAYER1_HIT_RIGHT,

  SPRITE_PLAYER2_STAND_RIGHT,
  SPRITE_PLAYER2_RUN_RIGHT_1,
  SPRITE_PLAYER2_RUN_RIGHT_2,
  SPRITE_PLAYER2_RUN_RIGHT_3,
  SPRITE_PLAYER2_RUN_RIGHT_4,
  SPRITE_PLAYER2_STAND_LEFT,
  SPRITE_PLAYER2_RUN_LEFT_1,
  SPRITE_PLAYER2_RUN_LEFT_2,
  SPRITE_PLAYER2_RUN_LEFT_3,
  SPRITE_PLAYER2_RUN_LEFT_4,   
  SPRITE_PLAYER2_PUNCH_LEFT_1,
  SPRITE_PLAYER2_PUNCH_LEFT_2,
  SPRITE_PLAYER2_PUNCH_RIGHT_1,
  SPRITE_PLAYER2_PUNCH_RIGHT_2,
  SPRITE_PLAYER2_HIT_LEFT,
  SPRITE_PLAYER2_HIT_RIGHT,    
  SPRITE_PLAYER2_KICK_LEFT_1,
  SPRITE_PLAYER2_KICK_LEFT_2,
  SPRITE_PLAYER2_KICK_LEFT_3,  
  SPRITE_PLAYER2_KICK_RIGHT_1,
  SPRITE_PLAYER2_KICK_RIGHT_2,
  SPRITE_PLAYER2_KICK_RIGHT_3,      

  
  SPRITE_PLAYER3_STAND_RIGHT,
  SPRITE_PLAYER3_RUN_RIGHT_1,
  SPRITE_PLAYER3_RUN_RIGHT_2,
  SPRITE_PLAYER3_RUN_RIGHT_3,
  SPRITE_PLAYER3_RUN_RIGHT_4,
  SPRITE_PLAYER3_STAND_LEFT,
  SPRITE_PLAYER3_RUN_LEFT_1,
  SPRITE_PLAYER3_RUN_LEFT_2,
  SPRITE_PLAYER3_RUN_LEFT_3,
  SPRITE_PLAYER3_RUN_LEFT_4 ,
  SPRITE_PLAYER3_PUNCH_LEFT_1,
  SPRITE_PLAYER3_PUNCH_LEFT_2,
  SPRITE_PLAYER3_PUNCH_RIGHT_1,
  SPRITE_PLAYER3_PUNCH_RIGHT_2,
  SPRITE_PLAYER3_HIT_LEFT,
  SPRITE_PLAYER3_HIT_RIGHT,
  SPRITE_PLAYER3_KICK_LEFT_1,
  SPRITE_PLAYER3_KICK_LEFT_2,
  SPRITE_PLAYER3_KICK_LEFT_3,  
  SPRITE_PLAYER3_KICK_RIGHT_1,
  SPRITE_PLAYER3_KICK_RIGHT_2,
  SPRITE_PLAYER3_KICK_RIGHT_3,      

  
  SPRITE_PLAYER4_STAND_RIGHT,
  SPRITE_PLAYER4_RUN_RIGHT_1,
  SPRITE_PLAYER4_RUN_RIGHT_2,
  SPRITE_PLAYER4_RUN_RIGHT_3,
  SPRITE_PLAYER4_RUN_RIGHT_4,
  SPRITE_PLAYER4_STAND_LEFT,
  SPRITE_PLAYER4_RUN_LEFT_1,
  SPRITE_PLAYER4_RUN_LEFT_2,
  SPRITE_PLAYER4_RUN_LEFT_3,
  SPRITE_PLAYER4_RUN_LEFT_4 ,
  SPRITE_PLAYER4_PUNCH_LEFT_1,
  SPRITE_PLAYER4_PUNCH_LEFT_2,
  SPRITE_PLAYER4_PUNCH_RIGHT_1,
  SPRITE_PLAYER4_PUNCH_RIGHT_2,
  SPRITE_PLAYER4_HIT_LEFT,
  SPRITE_PLAYER4_HIT_RIGHT,
  
  SPRITE_BOSS_STAND_RIGHT,
  SPRITE_BOSS_RUN_RIGHT_1,
  SPRITE_BOSS_RUN_RIGHT_2,
  SPRITE_BOSS_RUN_RIGHT_3,
  SPRITE_BOSS_RUN_RIGHT_4,
  SPRITE_BOSS_STAND_LEFT,
  SPRITE_BOSS_RUN_LEFT_1,
  SPRITE_BOSS_RUN_LEFT_2,
  SPRITE_BOSS_RUN_LEFT_3,
  SPRITE_BOSS_RUN_LEFT_4 ,
  SPRITE_BOSS_ATTACK_LEFT_1,
  SPRITE_BOSS_ATTACK_LEFT_2,
  SPRITE_BOSS_ATTACK_LEFT_3,  
  SPRITE_BOSS_ATTACK_RIGHT_1,
  SPRITE_BOSS_ATTACK_RIGHT_2,
  SPRITE_BOSS_ATTACK_RIGHT_3,  
  SPRITE_BOSS_HIT_LEFT,
  SPRITE_BOSS_HIT_RIGHT,      

  SPRITE_HAND,
  SPRITE_DOOR,
  SPRITE_JOYSTICK1,
  SPRITE_JOYSTICK2,
  SPRITE_GAMEOVER,
  SPRITE_GAMECOMPLETE,  

  SPRITE_PHONEBOOTH,
  SPRITE_PHONEBOOTH_BROKEN,
  SPRITE_PHONEBOOTH_JUNK1,
  SPRITE_PHONEBOOTH_JUNK2,
  SPRITE_PHONEBOOTH_JUNK3,
  
  SPRITE_POSTBOX,
  SPRITE_POSTBOX_BROKEN,
  SPRITE_POSTBOX_JUNK1,
  SPRITE_POSTBOX_JUNK2,
  SPRITE_POSTBOX_JUNK3,  

  SPRITE_BONUS_BURGER,
  SPRITE_BONUS_COLA,
  SPRITE_STAR,  
} sprite_id_t;

typedef enum {
  OBJECT_ID_ENEMY = 0,
  OBJECT_ID_PLAYER1 = 1,
  OBJECT_ID_PLAYER2 = 2,
  OBJECT_ID_BOSS = 3,  
  OBJECT_ID_HAND = 4,
  OBJECT_ID_DOOR = 5,
  OBJECT_ID_JOYSTICK = 6,
  OBJECT_ID_GAMEOVER = 7,
  OBJECT_ID_GAMECOMPLETE = 8,  
  OBJECT_ID_PHONEBOOTH = 9,
  OBJECT_ID_POSTBOX = 10,  
  OBJECT_ID_JUNK = 11,
  OBJECT_ID_BONUS = 12,
} object_id_t;

typedef enum {
  OBJECT_STAND_RIGHT = 0,
  OBJECT_RUN_RIGHT = 1,
  OBJECT_RUN_LEFT = 2,
  OBJECT_STAND_LEFT = 3,
  OBJECT_PUNCH_LEFT1 = 4,
  OBJECT_PUNCH_LEFT2 = 5,
  OBJECT_KICK_LEFT = 6,
  OBJECT_PUNCH_RIGHT1 = 7,
  OBJECT_PUNCH_RIGHT2 = 8,
  OBJECT_KICK_RIGHT = 9,    
  OBJECT_HIT_LEFT = 10,
  OBJECT_HIT_RIGHT = 11,

} object_action_t;

typedef enum {
  OBJECT_ANIM_PLAYER1_STAND_RIGHT = 0,
  OBJECT_ANIM_PLAYER1_RUN_RIGHT = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER1_STAND_LEFT = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER1_RUN_LEFT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER1_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER1_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER1_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER1_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER1_HIT_LEFT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER1_HIT_RIGHT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_PLAYER2_STAND_RIGHT = OBJECT_ANIM_PLAYER1_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER2_RUN_RIGHT = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER2_STAND_LEFT = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER2_RUN_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER2_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER2_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER2_KICK_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_KICK_LEFT,
  OBJECT_ANIM_PLAYER2_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER2_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER2_KICK_RIGHT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_KICK_RIGHT,
  OBJECT_ANIM_PLAYER2_HIT_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER2_HIT_RIGHT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_HIT_RIGHT,

  
  OBJECT_ANIM_PLAYER3_STAND_RIGHT = OBJECT_ANIM_PLAYER2_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER3_RUN_RIGHT = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER3_STAND_LEFT = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER3_RUN_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER3_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER3_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER3_KICK_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_KICK_LEFT,
  OBJECT_ANIM_PLAYER3_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER3_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER3_KICK_RIGHT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_KICK_RIGHT,  
  OBJECT_ANIM_PLAYER3_HIT_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER3_HIT_RIGHT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_PLAYER4_STAND_RIGHT = OBJECT_ANIM_PLAYER3_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER4_RUN_RIGHT = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER4_STAND_LEFT = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER4_RUN_LEFT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER4_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER4_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER4_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER4_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,  
  OBJECT_ANIM_PLAYER4_HIT_LEFT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER4_HIT_RIGHT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_BOSS_STAND_RIGHT = OBJECT_ANIM_PLAYER4_HIT_RIGHT + 1,
  OBJECT_ANIM_BOSS_RUN_RIGHT = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_BOSS_STAND_LEFT = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_BOSS_RUN_LEFT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_BOSS_ATTACK_LEFT1  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_BOSS_ATTACK_LEFT2  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_BOSS_ATTACK_RIGHT1  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_BOSS_ATTACK_RIGHT2  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,  
  OBJECT_ANIM_BOSS_HIT_LEFT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_BOSS_HIT_RIGHT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_HIT_RIGHT,  

  OBJECT_ANIM_HAND = OBJECT_ANIM_BOSS_HIT_RIGHT + 1,
  OBJECT_ANIM_DOOR = OBJECT_ANIM_HAND + 1,
  OBJECT_ANIM_JOYSTICK = OBJECT_ANIM_DOOR + 1,
  OBJECT_ANIM_GAMEOVER = OBJECT_ANIM_JOYSTICK + 1,
  OBJECT_ANIM_GAMECOMPLETE = OBJECT_ANIM_GAMEOVER + 1,  

  OBJECT_ANIM_PHONEBOOTH = OBJECT_ANIM_GAMECOMPLETE + 1,
  OBJECT_ANIM_PHONEBOOTH_BROKEN = OBJECT_ANIM_PHONEBOOTH + 1,

  OBJECT_ANIM_PHONEBOOTH_JUNK1 = OBJECT_ANIM_PHONEBOOTH_BROKEN + 1,
  OBJECT_ANIM_PHONEBOOTH_JUNK2 = OBJECT_ANIM_PHONEBOOTH_JUNK1 + 1,
  OBJECT_ANIM_PHONEBOOTH_JUNK3 = OBJECT_ANIM_PHONEBOOTH_JUNK2 + 1,

  OBJECT_ANIM_POSTBOX = OBJECT_ANIM_PHONEBOOTH_JUNK3 + 1,
  OBJECT_ANIM_POSTBOX_BROKEN = OBJECT_ANIM_POSTBOX + 1,

  OBJECT_ANIM_POSTBOX_JUNK1 = OBJECT_ANIM_POSTBOX_BROKEN + 1,
  OBJECT_ANIM_POSTBOX_JUNK2 = OBJECT_ANIM_POSTBOX_JUNK1 + 1,
  OBJECT_ANIM_POSTBOX_JUNK3 = OBJECT_ANIM_POSTBOX_JUNK2 + 1,

  
  OBJECT_ANIM_BONUS_BURGER = OBJECT_ANIM_POSTBOX_JUNK3 + 1,
  OBJECT_ANIM_BONUS_COLA = OBJECT_ANIM_BONUS_BURGER + 1,

  OBJECT_ANIM_STAR = OBJECT_ANIM_BONUS_COLA + 1,      
  
} object_animation_id_t;

typedef enum {
  FACING_LEFT,
  FACING_RIGHT
} object_direction_t;

typedef enum {
  OBJECT_STATE_ALIVE,
  OBJECT_STATE_REMOVED,
  OBJECT_STATE_DEAD,
  OBJECT_STATE_HIT,
  OBJECT_STATE_FLASHING
} object_state_t;

typedef struct {
  int16_t start;
  int16_t stop;
  int16_t speed;
  object_direction_t facing;
} object_animation_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
  int16_t dx;
  int16_t dy;
} object_image_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t dx;
  int16_t dy;
  int16_t ix;
} object_velocity_t;

typedef enum {
  OBJECT_CLASS_FIGHTER,
  OBJECT_CLASS_THING,
  OBJECT_CLASS_JUNK,  
  OBJECT_CLASS_DECORATION
} object_class_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
} object_position_t;

typedef struct {
  object_position_t positions[2];
  object_position_t* position;
} object_save_t;

typedef struct object {
  uint16_t id;
  uint16_t class;
  void* data;
  struct object* next;
  struct object* prev;
  int16_t _x;
  int16_t _y;
  int16_t _z;
  int16_t _px;
  int16_t _py;
  object_velocity_t velocity;
  int16_t imageIndex;
  object_image_t* image;
  uint16_t baseId;
  uint16_t animId;
  uint16_t actionId;
  object_animation_t* anim;  
  object_save_t save;
  uint16_t frameCounter;
  uint16_t deadRenderCount;
  uint16_t _state;
  void (*update)(uint16_t deltaT, struct object* ptr);
  void (*freeData)(void* data);
  uint16_t visible;
  uint16_t tileRender;

  uint16_t widthOffset;
  uint16_t width;

  uint16_t collidable;
} object_t;


typedef struct {
  object_t* up;
  object_t* down;
  object_t* left;
  object_t* right;
} object_collision_t;


extern object_image_t object_imageAtlas[];
extern object_animation_t object_animations[];
extern object_t* object_activeList;
extern int16_t object_count;
extern object_t* object_zBuffer[OBJECT_MAX_OBJECTS];
//extern uint16_t object_zBufferValid;

void
object_init(void);
object_t*
object_add(uint16_t id, uint16_t class, int16_t x, int16_t y, int16_t dx, int16_t anim, void (*update)(uint16_t deltaT, object_t* ptr), void* data, void (*freeData)(void*));
void
object_free(object_t* ptr);
void
object_render(frame_buffer_t fb, uint16_t deltaT);
void
object_restoreBackground(frame_buffer_t fb);
void
object_updatePosition(uint16_t deltaT, object_t* ptr);
void
object_setAction(object_t* ptr, object_action_t action);

inline static int16_t
object_x(object_t* ptr) {
  return ptr->_x;
}

inline static int16_t
object_y(object_t* ptr) {
  return ptr->_y;
}

inline static int16_t
object_z(object_t* ptr) {
  return ptr->_z;
}

inline static int16_t
object_px(object_t* ptr) {
  return ptr->_px;
}

inline static int16_t
object_py(object_t* ptr) {
  return ptr->_py;
}

inline static uint16_t
object_get_state(object_t* ptr) {
  return ptr->_state;
}

inline static void
object_set_state(object_t* ptr, uint16_t state) {  
  ptr->_state = state;
  if (state == OBJECT_STATE_ALIVE) {
    if (ptr->class == OBJECT_CLASS_FIGHTER || ptr->class == OBJECT_CLASS_THING) {
      ptr->collidable = 1;
      return;
    }
  } 
  ptr->collidable = 0;
}

#define object_screenx(ptr) (ptr->image->dx + 0xf + ptr->_x-game_cameraX-game_screenScrollX)
#define object_screeny(ptr) (ptr->image->dy + (ptr->_y-ptr->image->h))

inline static void
object_set_px(object_t* ptr, int16_t px)
{
  ptr->_px = px;  
  int16_t oldX = ptr->_x - game_cameraX;
  ptr->_x = ptr->_px / OBJECT_PHYSICS_FACTOR;
  
  if (oldX + OBJECT_WIDTH < SCREEN_WIDTH && (ptr->_x + OBJECT_WIDTH - game_cameraX)>= SCREEN_WIDTH) {
    ptr->_x = game_cameraX + (SCREEN_WIDTH - OBJECT_WIDTH - 1);
    ptr->_px = ptr->_x * OBJECT_PHYSICS_FACTOR;
  } else if (oldX >= 0 && ptr->_x - game_cameraX < 0) {
    ptr->_x = game_cameraX;
    ptr->_px = ptr->_x * OBJECT_PHYSICS_FACTOR;
  }  
}

inline static void
object_set_py(object_t* ptr, int16_t py)
{
  int16_t oldY = ptr->_y;
  ptr->_py = py;  
  ptr->_y = ptr->_py / OBJECT_PHYSICS_FACTOR;


  if (ptr->_y >= PLAYAREA_HEIGHT) {
    ptr->_y = PLAYAREA_HEIGHT-2;
    ptr->_py = ptr->_y * OBJECT_PHYSICS_FACTOR;
  }

  if (oldY >= GAME_PAVEMENT_START && ptr->_y < GAME_PAVEMENT_START) {
    ptr->_y = GAME_PAVEMENT_START;
    ptr->_py = ptr->_y * OBJECT_PHYSICS_FACTOR;
  }
}

inline static void
object_set_py_no_checks(object_t* ptr, int16_t py)
{
  ptr->_py = py;  
  ptr->_y = ptr->_py / OBJECT_PHYSICS_FACTOR;
}

inline static void
object_set_z(object_t* ptr, int16_t z)
{
  ptr->_z = z;
}

void
object_setAnim(object_t* ptr, int16_t anim);

void
object_clear(frame_buffer_t fb, int16_t ox, int16_t oy, int16_t ow, int16_t oh);

int16_t
object_collision(int16_t deltaT, object_t* a, object_collision_t* collision, uint16_t thresholdx, uint16_t thresholdy);
#endif 

#ifndef __FIGHTER_H
#define __FIGHTER_H

#define FIGHTER_MAX_FIGHTERS         8
#define FIGHTER_LONG_PUNCH_RANGE     13
#define FIGHTER_SHORT_PUNCH_RANGE    8
//#define FIGHTER_Y_ATTACK_THRESHOLD   6
#define FIGHTER_ENEMY_Y_ATTACK_RANGE 6
#define FIGHTER_SPAWN_FLASH_COUNT_TICS 5
#define FIGHTER_SPAWN_FLASH_DURATION_TICS 100
#define FIGHTER_HIT_FLASH_COUNT_TICS 5
#define FIGHTER_HIT_FLASH_DURATION_TICS 75

typedef struct {
  uint16_t hitAnimTic;  
  uint16_t durationTics;
  uint16_t dammage;
  uint16_t rangeX;
  uint16_t vx;
  uint16_t vy;
  uint16_t jump;
} fighter_attack_config_t;
  

typedef struct fighter_data {
  struct fighter_data* prev;
  struct fighter_data* next;  
  uint16_t attackCount;
  uint16_t attackChecked;
  uint16_t attackType;
  int16_t attackRangeY;
  uint16_t numAttacks;
  int16_t attack_py;
  uint16_t (*intelligence)(uint16_t deltaT, object_t* ptr, struct fighter_data* data);
  int16_t walkAbout; // todo: move to enemy data  
  int16_t health;
  uint16_t buttonReleased;
  uint16_t attackQueued;
  uint16_t attackJump;
  int16_t attackJumpY;
  int16_t flashCount;
  int16_t flashDurationTics;
  int16_t enemyAttackWait;
  int16_t enemyAttackWaitTics;  
  int16_t postAttackInvincibleTics;
  int16_t postAttackCount;
  int16_t speed;
  fighter_attack_config_t* attackConfig;
} fighter_data_t;


void
fighter_init(void);

object_t*
fighter_add(uint16_t id, uint16_t animId, int16_t x, int16_t y, uint16_t initialHealth, fighter_attack_config_t* attackConfig, uint16_t (*intelligence)(uint16_t deltaT, object_t* ptr, struct fighter_data* data));


void
fighter_update(uint16_t deltaT, object_t* ptr);

#endif 
#ifndef __ENEMY_H
#define __ENEMY_H

#define ENEMY_WIDTH                 22
#define ENEMY_ATTACK_WAIT_TICS      25
#define ENEMY_INTERCEPT_Y_THRESHOLD 1
#define ENEMY_INTERCEPT_X_RANGE     1
#define ENEMY_WALKABOUT_TICS        50 // if an enemy collides but cannot attack, go for a walk for this many units
#define ENEMY_ATTACK_DURATION_TICS  20
#define ENEMY_INITIAL_HEALTH        100

#define ENEMY_BOSS_RUN_ANIM_SPEED 4
#define ENEMY_BOSS_NUM_ATTACK_FRAMES 3
#define ENEMY_BOSS_ATTACK_TICS_PER_FRAME 8
#define ENEMY_BOSS_ATTACK_DAMMAGE   20
#define ENEMY_BOSS_ATTACK_RANGE     20

// the following are temporary and will be refactored
#define ENEMY_ATTACK_DAMMAGE        5


extern uint16_t enemy_count;

#ifdef DEBUG
extern uint16_t enemy_pause;
#endif

extern fighter_attack_config_t enemy_attackConfig1[];
extern fighter_attack_config_t enemy_attackConfig2[];
extern fighter_attack_config_t enemy_bossAttackConfig[];

void
enemy_init(void);

void
enemy_add(uint16_t animId, uint16_t x, uint16_t y, fighter_attack_config_t* attackConfig, uint16_t attackWait, uint16_t (*intelligence)(uint16_t deltaT, object_t* ptr, fighter_data_t* data));

uint16_t
enemy_intelligence(uint16_t deltaT, object_t* ptr, fighter_data_t* data);
#endif 


extern object_t* game_player1;
extern object_t* game_player2;

int16_t
object_collision(int16_t deltaT, object_t* a, object_collision_t* collision, uint16_t thresholdx, uint16_t thresholdy)
{
  int16_t vy = a->velocity.y;
  int16_t vx = a->velocity.x;
  
  if (deltaT == 2) {
    vx *= 2;
    vy *= 2;
  }
  
  int16_t _collision = 0;
  object_t* b = object_activeList;
  
  collision->up = collision->down = collision->left = collision->right = 0;

#ifdef DEBUG
  if (!game_collisions) {
    return 0;
  }
#endif

  int16_t a_y = ((object_py(a) + vy) / OBJECT_PHYSICS_FACTOR);
  int16_t a_x1 = (((object_px(a) + vx) / OBJECT_PHYSICS_FACTOR) + a->widthOffset)-thresholdx;
  int16_t a_x2 = (((object_px(a) + vx) / OBJECT_PHYSICS_FACTOR) + (a->width - a->widthOffset)) + thresholdx;
  
  while (b) {
    if (b->collidable && b != a) {
      int16_t b_y = ((object_y(b)));

      if (abs(a_y - b_y) <= thresholdy) {
	int16_t b_x1 = ((object_x(b))) + b->widthOffset;
	int16_t b_x2 = ((object_x(b))) + (b->width - b->widthOffset);
	
	if (a_x1 < b_x2 && a_x2 > b_x1) {		  
	  if (b_y >= a_y) {
	    collision->up = b;
	  } else if (b_y < a_y) {
	    collision->down = b;
	  }
	  if (b_x1 >= a_x1) {
	    collision->right = b;
	  } else if (b_x1 < a_x1) {
	    collision->left = b;
	  }
	  _collision = 1;
	}
      }
    }
    b = b->next;
  }
  
  return _collision;
}
 

object_t*
enemy_closestPlayer(object_t* ptr)
{
  if (game_player2 == 0) {
    if (game_player1) {
      return game_player1;
    } else {
      return 0;
    }
  } else if (game_player1 == 0) {
    return game_player2;
  } 

  if (object_get_state(game_player1) == OBJECT_STATE_REMOVED &&
      object_get_state(game_player2) != OBJECT_STATE_REMOVED) {
    return game_player2;
  } else  if (object_get_state(game_player2) == OBJECT_STATE_REMOVED &&
	      object_get_state(game_player1) != OBJECT_STATE_REMOVED) {
    return game_player1;
  } else if (object_get_state(game_player2) == OBJECT_STATE_REMOVED &&
	     object_get_state(game_player1) == OBJECT_STATE_REMOVED) {
    return 0;
  }

  int player1Diff = abs(object_x(ptr)-object_x(game_player1)) + abs(object_y(ptr)-object_y(game_player1));
  int player2Diff = abs(object_x(ptr)-object_x(game_player2)) + abs(object_y(ptr)-object_y(game_player2));

  if (player1Diff < player2Diff) {
    return game_player1;
  } else {
    return game_player2;
  }
} 

static int16_t
enemy_strikingDistanceX(object_t* a, object_t* b)
{
  int16_t a_x = object_x(a) + (a->image->w>>2);
  int16_t b_x = object_x(b) + (b->image->w>>2);

  if (abs(a_x - b_x) > OBJECT_HIT_DISTANCE) {
    return (object_x(a) > object_x(b)) ? 1 : -1;
  }
  
  return 0;
} 

__attribute__((externally_visible)) uint16_t
level1_doorIntelligence(uint16_t deltaT, object_t* ptr, fighter_data_t* data)
{
  if (object_y(ptr) == LEVEL1_ENEMY_BOSS_START_Y && object_x(ptr) > GAME_WORLD_WIDTH-144) {
    ptr->velocity.x = -1;
  } else if (object_y(ptr) < GAME_PAVEMENT_START) {
    ptr->velocity.x = 0;
    ptr->velocity.y = 1;
  } else {
    return enemy_intelligence(deltaT, ptr, data);
  }
  
  return 0;
} 

uint16_t
enemy_intelligence(uint16_t deltaT, object_t* ptr, fighter_data_t* data)
{
  if (object_get_state(ptr) != OBJECT_STATE_ALIVE) {
    return 0;
  }
  
#ifdef DEBUG
  if (enemy_pause) {
    ptr->velocity.x = 0;
    ptr->velocity.y = 0;    
    return 0;
  }
#endif
  
  uint16_t attack = 0;
  
  if (data->walkAbout > 0) {
    data->walkAbout-=deltaT;
  } else {
    object_t* player = enemy_closestPlayer(ptr);
    if (!player) {
      ptr->velocity.x = 0;
      ptr->velocity.y = 0;
      return 0;
    }
    object_collision_t collision;

    if (object_x(ptr)-game_cameraX <= 0) {
      data->walkAbout = ENEMY_WALKABOUT_TICS;
      ptr->velocity.x = 1;
    } else if (object_x(ptr)-game_cameraX >= SCREEN_WIDTH) {
      data->walkAbout = ENEMY_WALKABOUT_TICS;
      ptr->velocity.x = -1;      
    } else if ((object_collision(deltaT, ptr, &collision, ENEMY_INTERCEPT_X_RANGE, ENEMY_INTERCEPT_Y_THRESHOLD))) {
      if (collision.left) {
	ptr->velocity.x = 1;
	ptr->velocity.y = 0;
      } else if (collision.right) {
	ptr->velocity.x = -1;
	ptr->velocity.y = 0;
      } else if (collision.up) {
	ptr->velocity.x = 0;
	ptr->velocity.y = 1;
      } else {
	ptr->velocity.x = 0;
	ptr->velocity.y = -1;
      }
      data->walkAbout = ENEMY_WALKABOUT_TICS;
    } else {
      ptr->velocity.x = enemy_strikingDistanceX(player, ptr);

      if (abs(object_y(ptr)-object_y(player)) <= data->attackRangeY) {
	if (ptr->velocity.x == 0) {
	  if (data->enemyAttackWait <= 0) {
	    data->enemyAttackWait = data->enemyAttackWaitTics;
	    attack = 1;
	  } else {
	    data->enemyAttackWait-=deltaT;
	  }
	}
	ptr->velocity.y = 0;
      }
      else if (object_y(ptr) < object_y(player)) {
	ptr->velocity.y = data->speed;
      } else if (object_y(ptr) > object_y(player)) {
	ptr->velocity.y = -data->speed;
      } 
    }
  }

  return attack;
} 