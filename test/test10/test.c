typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;

#define STAR_WIDTH 16
//#define STAR_HEIGHT 3
#define STAR_MAX_STARS 6
#define SPRITE_SPRITESHEET_Y 547
#define SPRITE_SPRITESHEET_X 112 
#define OBJECT_WIDTH 44
#define OBJECT_STATE_ALIVE 42

static uint16_t star_count;

typedef enum {
  FACING_LEFT,
  FACING_RIGHT
} object_direction_t;

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
  uint8_t vStartLo;
  uint8_t hStartHi;
  uint8_t vStopLo;
  uint8_t attach:1;
  uint8_t unused:4;
  uint8_t vStartHi:1;
  uint8_t vStopHi:1;
  uint8_t hStartLow:1;
} star_sprite_control_t;

 typedef struct star {
  struct star* next;
  struct star* prev;
  int16_t x;
  int16_t y;
  object_velocity_t velocity;
  uint16_t _state;
  int16_t startY;
  star_sprite_control_t* sprite;
  uint16_t spriteHi;
  uint16_t spriteLo;
  uint16_t index;
} star_t;

extern star_t*
star_getFree(void) ;

extern void
star_addToActive(star_t* ptr);

inline int16_t object_x(object_t* actor) {
	return actor->_x;
} 

inline int16_t object_y(object_t* actor) {
	return actor->_y;
} 

static inline void
star_addStar(object_t* actor, int16_t dx, int16_t dy, int16_t yOffset)
{
  if (star_count >= STAR_MAX_STARS) {
    return;
  }
  
  int16_t x = object_x(actor) + OBJECT_WIDTH/2;
  int16_t y = object_y(actor)-40-yOffset;
  
  star_t* ptr = star_getFree();
  ptr->_state = OBJECT_STATE_ALIVE;
  ptr->velocity.x = dx;
  ptr->velocity.y = dy;
  ptr->x = x;
  ptr->y = y;
  ptr->startY = object_y(actor)-10;
  star_addToActive(ptr);
}

int 
star_add(object_t* ptr, int16_t dx)
{
  static int star_cycle = 0;
  switch (star_cycle) {
  case 0:    
    star_addStar(ptr, dx*4, -10, 0);
    star_addStar(ptr, -dx*4, -8, 2);
    star_addStar(ptr, dx*2, -10, 10);    
    break;
  case 1:
    star_addStar(ptr, dx*4, -10, 0);
    break;
  case 2:
    star_addStar(ptr, -dx*4, -8, 2);
    star_addStar(ptr, dx*2, -10, 10);
    break;
  }

  star_cycle++;
  if (star_cycle > 2) {
    star_cycle = 0;
  }
  
  return dx;
}
 