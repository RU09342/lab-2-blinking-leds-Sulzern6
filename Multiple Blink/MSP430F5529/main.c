#include <msp430F5529.h>

#define LED1    BIT0    // Defines the LED at P1.0
#define BUTTON  BIT1    // Defines BUTTON  at  P1.1
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
        P1DIR  = LED1;                      // Set  LED1 and LED2 to output
        P4DIR  = LED2;


      while( 1 )
      {
          P1OUT ^= LED1;            // Blink LED1
          __delay_cycles(200000);   // Delay to see blinking LEDs
          P4OUT ^= LED2;            // Blink LED2 on P1.6
          __delay_cycles(100000);   // Delay to see blinking LEDs

      }
}
