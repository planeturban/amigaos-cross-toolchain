typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;

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


#define _min(a, b) (d[a]->_z<d[b]->_z?d[a]:d[b])
#define _max(a, b) (d[a]->_z<d[b]->_z?d[b]:d[a]) 
#define SWAP(x,y) { object_t* a = _min(x,y);object_t* b = _max(x,y); d[x] = a; d[y] = b; }


void sort5(object_t **d){
  SWAP(0,1);
  SWAP(3,4);
  SWAP(2,4);
  SWAP(2,3);
  SWAP(1,4);
  SWAP(0,3);
  SWAP(0,2);
  SWAP(1,3);
  SWAP(1,2);
}
