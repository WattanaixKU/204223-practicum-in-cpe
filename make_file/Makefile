MCU=atmega328p

all: count-sw.hex light-3.hex light-8.hex

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

%.flash: %.hex
	avrdude -p $(MCU) -c usbasp -U flash:w:$<

%.elf: %.o peri.o
	avr-gcc -mmcu=$(MCU) -O2 -o $@ $^

%.o: %.c peri.h
	avr-gcc -mmcu=$(MCU) -O2 -c -o $@ $<

clean:
	rm -f *~ *.o *.elf *.hex
