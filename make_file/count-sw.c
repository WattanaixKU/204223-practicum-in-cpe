//https://www.youtube.com/watch?embed=no&v=ZvJrOgB8rQM
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
    uint8_t count = 0;
    init_peri();
    set_led_value(0);
    while(1)
    {
        while(!SWITCH_PRESSED())
            ;
        _delay_ms(50);
        count++;
        set_led_value(count);
        while(SWITCH_PRESSED())
            ;
        _delay_ms(50);
    }
}
