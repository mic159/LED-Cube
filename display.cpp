#include "Arduino.h"

#include "display.h"

Display::Display()
{
    pin_data = 6;
    pin_clock = 3;
    pin_latch = 4;
    pin_clear = 2;
    pin_enable = 5;
    
    digitalWrite(pin_clear, HIGH);
    digitalWrite(pin_enable, LOW);
    
    // Clear the buffer
    this->clear();
}

void Display::draw()
{
    for (int l = 0; l < depth; ++l)
    {
        digitalWrite(pin_latch, LOW);
        
        // Select the layer on the last register
        //pxOn(l-3, l);
        pxOn((width*height) + l, l);
        
        // The registeres are chained, we feed them in reverse order.
        for (int i = num_registers - 1; i >= 0; --i)
        //for (int i = 0; i < num_registers; ++i)
        {
            shiftOut(pin_data, pin_clock, MSBFIRST, data[l][i]);
        }
        // Latch now!
        digitalWrite(pin_latch, HIGH);
    }
}

void Display::wall_horizontal(int a)
{
    for (int l = 0; l < depth ; ++l)
        for (int y = 0; y < height; ++y)
            pxOn(a, y, l);
}

