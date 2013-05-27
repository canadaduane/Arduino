#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#define SPACE_SHIP_THRUST_MAX 5
#define SPACE_SHIP_ANGULAR_THRUST_MAX 0.5

#include "SpaceThing.h"

class SpaceShip : public SpaceThing {
public:
  int _danger_level;
  float _precise_screen_x, _precise_screen_y;
  float _screen_direction, _screen_thrust;

  SpaceShip() : SpaceThing() {};
  SpaceShip(float x, float y) : SpaceThing(x, y) {};

  virtual void erase(Adafruit_ST7735 tft, Viewport view);
  virtual void draw(Adafruit_ST7735 tft, Viewport view);
  virtual void draw_hov(Adafruit_ST7735 tft);
  void draw_in_color(Adafruit_ST7735 tft,
    float cx, float cy, float dir, float thrust,
    int outline_color, int fill_color, int thrust_color);
  void reset(void);

};

#endif
