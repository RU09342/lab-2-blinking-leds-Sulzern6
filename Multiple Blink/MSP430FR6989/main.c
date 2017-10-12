#include <msp430fr6989.h>

#define LED1    BIT0    // Defines the LED at P1.0
#define BUTTON  BIT1    // Defines the BUTTON at P1.1
#define LED2    BIT7    // Defines the LED at P9.2
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;        // stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;        // Disable GPIO default high-impedance mode
        P1DIR  = LED1;               // Set  LED1 to output
        P9DIR  = LED2;               // Sets LED2 to output



      while( 1 )
      {
          P1OUT ^= LED1;            // Blink LED1
          __delay_cycles(200000);   // Delay to see blinking LEDs
          P9OUT ^= LED2;            // Blink LED2 on P1.6
          __delay_cycles(100000);   // Delay to see blinking LEDs

      }
}
