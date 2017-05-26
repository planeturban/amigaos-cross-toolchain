#define HISCORE_NUM_SCORES 10

typedef short int int16_t;
typedef unsigned long uint32_t;

typedef struct {
  uint32_t score;
  char name[4];
} hiscore_t;

typedef struct {
  hiscore_t scores[HISCORE_NUM_SCORES];
} hiscore_buffer_t;

extern char* hiscore_prompt(char* buffer);
extern void hiscore_saveData(int);
extern void popup(char* popup, void (*callback)(void));
extern uint32_t game_score;

uint32_t game_collisions, game_over;
static hiscore_buffer_t hiscore;


char *
strcpy(char *dest, const char *src)
{
  char *s = dest;
  while ((*s++ = *src++) != 0);
  return dest;
}


__attribute__((externally_visible))
void
hiscore_addScore(uint32_t score)
{
  int16_t i;
  char* name;

  for (i = HISCORE_NUM_SCORES-1; i >= 0; i--) {

    if (score >= hiscore.scores[i].score) {
      if (i > 0) {
        strcpy(hiscore.scores[i].name, hiscore.scores[i-1].name);
      } else if (i == 0) {
        name = hiscore_prompt("A NEW HIGH SCORE!!!");
        strcpy(hiscore.scores[i].name, name);
      }
    } else 
 
    {
      if (i < HISCORE_NUM_SCORES-1) {
        name = hiscore_prompt("YOU ARE ON THE SCORE BOARD!");
        strcpy(hiscore.scores[i+1].name, name);
      }
      break;
    }
  }
}
