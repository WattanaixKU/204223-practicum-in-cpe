#include <avr/io.h>
#include "peri.h"

void init_peri()
{
    // PC0-PC2 as output
    DDRC |= (1<<PC2) | (1<<PC1) | (1<<PC0);
    // PC3-PC4 as input
    DDRC &= ~((1<<PC3) | (1<<PC4));

    // enable pull-up resistor on PC3 https://www.youtube.com/watch?embed=no&v=ZvJrOgB8rQM
    PORTC |= (1<<PC3);
}

void set_led_value(uint8_t value)
{
    PORTC &= ~(0b111);
    PORTC |= (value & 0b111);
}

uint16_t read_adc(uint8_t channel)
{
    //https://theory.cpe.ku.ac.th/wiki/index.php/%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%A7%E0%B8%B1%E0%B8%94%E0%B8%AA%E0%B8%B1%E0%B8%8D%E0%B8%8D%E0%B8%B2%E0%B8%93%E0%B9%81%E0%B8%AD%E0%B8%99%E0%B8%B0%E0%B8%A5%E0%B9%87%E0%B8%AD%E0%B8%81%E0%B8%94%E0%B9%89%E0%B8%A7%E0%B8%A2%E0%B9%84%E0%B8%A1%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%84%E0%B8%AD%E0%B8%99%E0%B9%82%E0%B8%97%E0%B8%A3%E0%B8%A5%E0%B9%80%E0%B8%A5%E0%B8%AD%E0%B8%A3%E0%B9%8C
    ADMUX = (0<<REFS1)|(1<<REFS0) // ระบุให้ใช้ VCC เป็นแรงดันอ้างอิง (Vref) และ
          | (0<<ADLAR)            // บันทึกผลลัพธ์ชิดขวาในคู่รีจีสเตอร์ ADCH/ADCL
          | (channel & 0b1111);   // ตั้งค่า MUX เป็นค่า channel

    ADCSRA = (1<<ADEN)            // เปิดวงจร ADC
           | (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0) // ใช้ความเร็ว 1/128 ของคล็อกระบบ
           | (1<<ADSC);           // สั่งวงจร ADC ให้เริ่มต้นการแปลง

    while ((ADCSRA & (1<<ADSC)))  // รอจนบิต ADSC กลายเป็น 0 ซึ่งหมายถึงการแปลงเสร็จสิ้น
       ;

    return ADCL + ADCH*256;  // ผลลัพธ์ถูกเก็บอยู่ในรีจีสเตอร์ ADCL และ ADCH
    // สามารถใช้ return ADC ได้เช่นกัน
}
