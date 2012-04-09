const int pin_data = 6;
const int pin_clock = 3;
const int pin_latch = 4;
const int pin_clear = 2;
const int pin_enable = 5;

#include "display.h"

#define LOOP(x, times) for(int ii = 0; ii < times; ++ii) { x; } 

Display* disp = NULL;

void setup()
{
  pinMode(pin_data, OUTPUT);
  pinMode(pin_clock, OUTPUT);
  pinMode(pin_latch, OUTPUT);
  pinMode(pin_clear, OUTPUT);
  pinMode(pin_enable, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  disp = new Display();
}

void effect_shimmer_tumble()
{
    for (int j = 0; j < 100; j++)
    {
        disp->clear();
        disp->pxOn(j     , 0);
        disp->pxOn(100-j , 1);
        disp->pxOn(j     , 2);
        disp->pxOn(100-j , 3);
        disp->draw();
    }
}

void effect_walls()
{
    for (int i = 0; i < 10; ++i)
    {
        disp->clear();
        disp->wall_horizontal(i);
        disp->draw(10);
    }
    for (int i = 9; i > 0; --i)
    {
        disp->clear();
        disp->wall_horizontal(i);
        disp->draw(10);
    }
}

void loop()
{
    LOOP(effect_walls(), 5);
    //LOOP(effect_shimmer_tumble(), 5);
}
