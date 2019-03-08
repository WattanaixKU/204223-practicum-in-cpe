#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
{
    DDRD = 0b00100011; //set input-output
    PORTD = 0b00000000;

    while(1)//loop
    {
        if(PORTD&0b00000010 && PORTD&0b00000001)
            PORTD ^= (1<<5); 
        if(PORTD&0b00000001)
            PORTD ^= (2); 
        PORTD ^= (1); 
        _delay_ms(500);
    }
    return 0;
}
