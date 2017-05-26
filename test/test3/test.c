#include "test.h"

void
gfx_fillRectSmallScreen(uint8_t * fb, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
  static custom_t _custom = CUSTOM;
  static uint16_t startBitPatterns[] = { 0xffff,
			       0x7fff, 0x3fff, 0x1fff, 0x0fff, 
			       0x07ff, 0x03ff, 0x01ff, 0x00ff,
			       0x007f, 0x003f, 0x001f, 0x000f,
			       0x0007, 0x0003, 0x0001, 0x0000 };

  static uint16_t endBitPatterns[] = { 0xffff, 
				    0x8000, 0xc000, 0xe000, 0xf000,
				    0xf800, 0xfc00, 0xfe00, 0xff00,
				    0xff80, 0xffc0, 0xffe0, 0xfff0,
				    0xfff8, 0xfffc, 0xfffe, 0xffff};

  uint16_t startMask = startBitPatterns[x & 0xf]; 
  uint16_t endMask = endBitPatterns[(x+w) & 0xf]; 
  uint32_t widthWords = (((x&0x0f)+w)+15)>>4;
  
  if (widthWords == 1) {
    startMask &= endMask;
  }
  
  fb += y*(SCREEN_WIDTH_BYTES*SCREEN_BIT_DEPTH)/*gfx_dyOffsetsLUT[y]*/ + (x>>3);

  int32_t colorInPlane;
  for (int32_t plane = 0; plane < SCREEN_BIT_DEPTH; plane++) {
    colorInPlane = (1<<plane) & color;
    hw_waitBlitter();
    
    _custom->bltcon0 = (SRCC|DEST|0xca);
    _custom->bltcon1 = 0;
    _custom->bltafwm = 0xffff;
    _custom->bltalwm = 0xffff;
    _custom->bltdmod = (SCREEN_WIDTH_BYTES*(SCREEN_BIT_DEPTH-1))+(SCREEN_WIDTH_BYTES-2);
    _custom->bltcmod = (SCREEN_WIDTH_BYTES*(SCREEN_BIT_DEPTH-1))+(SCREEN_WIDTH_BYTES-2);
    _custom->bltbmod = 0;
    _custom->bltamod = 0;
    _custom->bltadat = startMask;
    _custom->bltbdat = colorInPlane ? 0xffff : 0x0;
    _custom->bltcpt = (uint8_t*)fb;
    _custom->bltdpt = (uint8_t*)fb;
    _custom->bltsize = h<<6 | 1;
    
    if (widthWords > 1) {
      hw_waitBlitter();    
      _custom->bltcon0 = (SRCC|DEST|0xca);
      _custom->bltadat = endMask;
      _custom->bltcpt = (uint8_t*)fb+((widthWords-1)<<1);
      _custom->bltdpt = (uint8_t*)fb+((widthWords-1)<<1);
      _custom->bltsize = h<<6 | 1;
    }
    
    if (widthWords > 2) {
      hw_waitBlitter();    
      _custom->bltcon0 = (DEST|(colorInPlane ? 0xff : 0x00));
      _custom->bltdmod = (SCREEN_WIDTH_BYTES*(SCREEN_BIT_DEPTH-1))+(SCREEN_WIDTH_BYTES-((widthWords-2)<<1));
      _custom->bltdpt = (uint8_t*)fb+2;
      _custom->bltsize = h<<6 | (widthWords-2);
    }    

    fb += SCREEN_WIDTH_BYTES;
  }
}
