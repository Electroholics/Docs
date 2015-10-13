/*****************************  Varun Kumar  *********************************/
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#include<string.h>
#include<avr/interrupt.h>

void timer();

int count=0;

int main(void)
{
    	DDRB = 0x02; // declare pin 9 as output
	//_delay_ms(100000);
	timer();              // Initialises Timer
	
	while(1)
    	{}
	return 0;
}

void timer()
{
	OCR1A = 0;              // 50% duty cycle, 2^16=65536
	
	TCCR1A |= 1<<COM1A0;      // selects OC1A and toggles it on every compare and match
	                          
	TCCR1B |= (1 << WGM12);   // Now TOP == OCR1A ie, freq of OC1A is F_clk/(N*1)
	
	TCCR1B |= (1 << CS02);    // prescalar 256
	TCNT1 = 0;                // 16 bit register
}

