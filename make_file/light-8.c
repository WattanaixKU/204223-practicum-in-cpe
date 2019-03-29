#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
    uint8_t level;
    uint16_t light;
    init_peri();
    while(1)
    {
        light = read_adc(PC4);
        //level = (light/128);
        if(light<500)
            level = 0;
        else if(light<600)
            level = 1;
        else if(light<700)
            level = 2;
        else if(light<740)
            level = 3;
        else if(light<780)
            level = 4;
        else if(light<820)
            level = 5;
        else if(light<840)
            level = 6;
        else
            level = 7;
        set_led_value(level);
    }
}
