#include <msp430g2553.h>

#define LED1    BIT0    // Defines LED at P1.0
#define LED2    BIT6    // Defines LED at P1.6
#define BUTTON  BIT3    // Defines BUTTON at P1.3
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	        // stop watchdog timer
	P1DIR  = LED1;                      // Set P1.0 LED to output
	P1REN = BUTTON;                     // Enables resistor for button P1.3
	P1OUT = BUTTON;                     // Makes resistor P1.3 a pull up
	
	while(1)
	{
	    if(!(P1IN & BUTTON))            // Check for button Press
	    {
	        P1OUT ^= LED1;              // Activate LED 1
	    }
	    else
	    {
	        P1OUT ^= 0x00;
	    }
	    _delay_cycles( 100000);

	}
	return 0;
}
