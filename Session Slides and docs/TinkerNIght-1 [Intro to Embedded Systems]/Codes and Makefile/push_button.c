/*****************************  Varun Kumar  *********************************/
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>


int main(void)
{
    	DDRB = 0x20;                                      // declare pin 13 as output
	
	while(1)
    	{
    		input_from_push_button = PINB & ~(1<<PB0) // Takes input from pin 8
    		_delay_ms(100);                           // delay of 100ms for debouncing
    		
    		if(input_from_push_button)
    		{PORTB |= 1<<PB5;}                        // set pin 13
    		
    		else
    		{PORTB &= ~(1<<PB5);}                     // clear pin 13 but  *** Why Like This ...???    		
    	}
	return 0;                                         // Just for the sake of good coding pratice
}

