#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
{
    DDRD = 0b00100011; //set input-output

    while(1)//loop
    {
        PORTD = 0b00100000; 
        _delay_ms(500);
        PORTD = 0b00000010; 
        _delay_ms(500);
        PORTD = 0b00000001; 
        _delay_ms(500);

    }
    return 0;
}
