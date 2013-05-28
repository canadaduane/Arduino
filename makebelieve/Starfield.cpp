#include "Starfield.h"
#include "Colors.h"

Starfield::Starfield(float cx, float cy, int count)
: SpaceThing(cx, cy, ST7735_TFTWIDTH, ST7735_TFTHEIGHT), _count(count) {
  _seed = analogRead(0);
}


void Starfield::draw(Adafruit_ST7735 tft, Viewport view) {
  _screen_cx = _x - view.x1();
  _screen_cy = _y - view.y1();
  draw_or_erase(tft, _screen_cx, _screen_cy, false);
}

void Starfield::erase(Adafruit_ST7735 tft, Viewport view) {
  draw_or_erase(tft, _screen_cx, _screen_cy, true);
}

void Starfield::draw_or_erase(Adafruit_ST7735 tft, int cx, int cy, bool erase = false) {
  int i, x, y, color;
  randomSeed(_seed);
  for (i = 0; i < _count; i++) {
    x = cx + random(_w);
    y = cy + random(_h);
    color = (random(2) == 0) ? GRAY : DARK_GRAY;
    if (erase) color = BLACK;
    tft.drawPixel(x, y, color);
  }
}

void Starfield::step(void) {
  // Starfields don't move or turn, so do nothing
}