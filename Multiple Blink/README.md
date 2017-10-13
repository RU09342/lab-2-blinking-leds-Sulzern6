# Nathan Sulzer
# Embedded Systems
# Lab 2
# Multiple blink
The purpose of this task was to write a code that could blink more than one LED on the microprocessor at the same time. 
# Example Code
This code functions by blinking an 2 LED at different delays using a simple delay cycle to implement the delays.
```c
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
	WDTCTL = WDTPW | WDTHOLD;	 // stop watchdog timer
	P1DIR  = LED1 + LED2;        // Sets LED at P1.0 and P2.0  as output
	P1OUT  = LED2;               // Turns on LED2 so the LEDs aren't blinking together

	  while( 1 )
	  {
	      P1OUT ^= LED1;            // Blink LED on P1.0
	      __delay_cycles(200000);   // Delay to see blinking LEDs
	      P1OUT ^= LED2;            // Blink LED on P1.6
	      __delay_cycles(100000);   // Delay to see blinking LEDs

	  }
}
```