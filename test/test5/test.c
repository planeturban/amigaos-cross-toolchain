#include "test.h"

void 
gfx_screenWidthBitBlitNoMask(frame_buffer_t dest, frame_buffer_t src, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h)
{
  volatile struct Custom* _custom = CUSTOM;
  uint32_t widthWords = ((w+15)>>4)+1;
  int32_t shift = (dx&0xf);
  
  dest +=  (dy * (SCREEN_WIDTH_BYTES*SCREEN_BIT_DEPTH)) + (dx>>3);
  src += (sy * (SCREEN_WIDTH_BYTES*SCREEN_BIT_DEPTH)) + (sx>>3);

  hw_waitBlitter();

  _custom->bltcon0 = (SRCA|DEST|0xf0|shift<<ASHIFTSHIFT);
  _custom->bltcon1 = shift<<BSHIFTSHIFT;
  _custom->bltalwm = 0x0;
  _custom->bltamod = (SCREEN_WIDTH_BYTES-(widthWords<<1));
  _custom->bltdmod = (SCREEN_WIDTH_BYTES-(widthWords<<1));
  _custom->bltapt = (uint8_t*)src;
  _custom->bltdpt = (uint8_t*)dest;
  _custom->bltsize = ((h*SCREEN_BIT_DEPTH)<<6) | widthWords;
}
