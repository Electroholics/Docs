#include <avr/io.h>
#include <avr/eeprom.h>
#define LTHRES 1
  
// initialize adc
void adc_init()
{
    // AREF = AVcc
    ADMUX = (1<<REFS0);		//Assignining reference voltage = 5v
  
    // ADC Enable and prescaler of 128
    // 16000000/128 = 125000
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
  
	// read adc value
uint16_t adc_read(uint8_t ch)
{
    	// select the corresponding channel 0~7
    	// ANDing with '6' will always keep the value of 'ch' between 0 and 5
    	ch &= 0b00000111;  // AND operation with 6
    	ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ORing
  
    	// start single conversion

    	ADCSRA |= (1<<ADSC);	// write '1' to ADSC
  
    	// wait for conversion to complete
    	// ADSC becomes '0' again
    	// till then, run loop continuously
    	while(ADCSRA & (1<<ADSC));
  
    	return (ADC);
}
  
int main()
{
    	uint16_t adc_result0;
    	DDRB = 0x20 ; //0x01;           // to connect led to PB0
    
	unsigned int value1;
	unsigned int value2;
	adc_init();		// initialize adc
    	while(1)
    	{
        	adc_result0 = adc_read(0);      // read adc value at PA0
              	
  
        	// condition for led to glow
        	if (adc_result0 > LTHRES) 
            		{PORTB |= 1<<PB5;}
        	else
            		{PORTB &= ~(1<<PB5);}



	}
}
