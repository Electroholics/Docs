/*****************************  Varun Kumar  *********************************/
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>


int main(void)
{
    	DDRB = 0x20;                 // declare pin 13 as output
	
	while(1)
    	{
    		PORTB |= 1<<PB5;     // set pin 13
    		_delay_ms(1000);     // delay of 1000ms
    		
    		PORTB &= ~(1<<PB5);  // clear pin 13 but Why This ...???
    		_delay_ms(1000);     // delay of 1000ms
    		
    	}
	return 0;                    // Just for the sake of good coding practice
}

