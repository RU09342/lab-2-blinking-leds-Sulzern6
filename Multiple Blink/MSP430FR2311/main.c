#include <msp430fr2311.h>

#define LED1    BIT0    // Defines the BIt corresponding to the LED used P1.0
#define BUTTON  BIT1    // Defines the BIT corresponding to the LED used P1.1
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;               // Disable GPIO default high-impedance mode
        P1DIR  = LED;                       // Set  LED on p1 to output
        P2DIR  = LED;                       // Set  LED on p2 to output



      while( 1 )
      {
          P1OUT ^= LED;             // Blink LED1
          __delay_cycles(200000);   // Delay to see blinking LEDs
          P2OUT ^= LED;             // Blink LED2 on P1.6
          __delay_cycles(100000);   // Delay to see blinking LEDs

      }
}
