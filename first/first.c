#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
{
    DDRD = 0b00001000; //set input-output

    while(1)//loop
    {
        PORTD = 0b00001000; //set PD3 = 1
        _delay_ms(500);
        PORTD = 0b00000000; //set PD3 = 0
        _delay_ms(500);

    }
    return 0;
}
