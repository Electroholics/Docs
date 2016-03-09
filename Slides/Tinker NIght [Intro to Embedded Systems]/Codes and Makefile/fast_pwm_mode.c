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
	sei();                // Allows interupt
	timer();              // Initialises Timer
	
	while(1)
    	{}
	return 0;
}

void timer()
{
	OCR1A = 512;            // 50% duty cycle, 2^10=1024
	
	TCCR1A |= 1<<COM1A1;             // selects OC1A and in non-inverting mode
	TCCR1A |= 1<<WGM11 | 1<<WGM10;   // selects fast pwm with 10 bits
	TCCR1B |= (1 << WGM12);          // selects fast pwm with 10 bits
	
	TCCR1B |= (1 << CS02);    // prescalar 256
	TCNT1 = 0;                // 16 bit register
}

