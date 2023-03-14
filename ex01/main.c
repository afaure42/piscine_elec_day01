#include <avr/io.h>

//every page reference to the atmega238p datasheet is based on this link 
//https://pdf1.alldatasheet.fr/datasheet-pdf/download/1425004/MICROCHIP/ATMEGA328.html

int main()
{
	//we want to output to the led on PB1 wich is by luck OC1A as well

	//set port PB1 to output ( true ) using direction register DDRB
	DDRB = 1 << PB1;

	//clearing registers
	TCCR1B = 0;
	TCCR1A = 0;
	//as per the table 16-5 found in section 16.11.2 page 142-143
	//setting the clock source as the base clock on the timer counter control register B
	//with a prescaler set at 1024
	TCCR1B |= (1 << CS10) | (1 << CS12);

	//setting fast pwm mode ( mode 14) as per the table 16-4 secion 16.11.1 page 141
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
	TCCR1A |= (1 << WGM11);

	//as per the table 16-1 in section 16.11.1 page 140
	//setting port OC1A as output clear on match set a bottom
	TCCR1A |= (1 << COM1A1);

	//as per the CTC mode, specified on table 16-4 page 141
	//setting TOP value for the counter at one second, knowing the prescaler is set at 1024
	ICR1 = F_CPU / 1024;

	//setting the output compare register at 1/10th of a second
	OCR1A = F_CPU / 1024 / 10;

	//setting 
	while (1)
	{
		//nothing
	}
}
