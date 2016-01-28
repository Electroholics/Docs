PROJ = main
# Name of project without extension 
SRC = main.c
# List all Source Files here.
CC = avr-gcc
#Compiler used
MCU = atmega328p
#Microcontroller used

main:
	$(CC) $(SRC) -mmcu=$(MCU) -c
	$(CC) -mmcu=$(MCU) *.o -o $(PROJ).out 
	avr-objcopy -O ihex $(PROJ).out $(PROJ).hex
program:
	avrdude -p $(MCU) -P com4 -c arduino -U flash:w:$(PROJ).hex
clean:
	rm *.o *.out *.hex
￼