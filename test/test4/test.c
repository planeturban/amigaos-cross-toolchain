typedef unsigned short uint16_t;
typedef short int16_t;

extern uint16_t conductor_scrollTarget;
extern uint16_t conductor_instructionIndex;
extern int16_t game_cameraX;

typedef enum {
  CONDUCTOR_INSTRUCTION_END = 0,
  CONDUCTOR_INSTRUCTION_CAMERAX = 1
} conductor_instruction_type;

typedef struct {
  uint16_t type;
  uint16_t cameraX;
  uint16_t argument;
  int16_t (*callback)(uint16_t arg);
} conductor_instruction_t;

void
conductor_init(conductor_instruction_t* instructions);

void
conductor_process();

uint16_t
conductor_complete(void);


uint16_t conductor_scrollTarget;
uint16_t conductor_instructionIndex;
static conductor_instruction_t* conductor_instructions;

void
conductor_init(conductor_instruction_t* instructions)
{
  conductor_scrollTarget = 0;
  conductor_instructions = instructions;
  conductor_instructionIndex = 0;
  conductor_process();
}

void
conductor_process(void)
{
  for (; conductor_instructions[conductor_instructionIndex].type != CONDUCTOR_INSTRUCTION_END; conductor_instructionIndex++) {
    conductor_instruction_t *ptr = &conductor_instructions[conductor_instructionIndex];
    if (ptr->cameraX <= game_cameraX) {
      if (!ptr->callback(ptr->argument)) {
	break;
      }
    } else {
      break;
    }
  }
}

uint16_t
conductor_complete(void)
{
  return conductor_instructions[conductor_instructionIndex].type == CONDUCTOR_INSTRUCTION_END;
}

void
conductor_setScrollTarget(uint16_t target)
{
  conductor_scrollTarget = target;
}
