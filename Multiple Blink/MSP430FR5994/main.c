#include <msp430fr5994.h>

#define LED1   BIT0     // Defines the LED at P1.0
#define LED2   BIT1     // Defines the LED at P1.1
#define BUTTON  BIT6    // Defines the BUTTON at P5.6
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;               // Disable GPIO default high-impedance mode
        P1DIR  = LED1 + LED2;               // Set  LED1 and LED2 to output


      while( 1 )
      {
          P1OUT ^= LED1;            // Blink LED1
          __delay_cycles(200000);   // Delay to see blinking LEDs
          P1OUT ^= LED2;            // Blink LED2 on P1.6
          __delay_cycles(100000);   // Delay to see blinking LEDs

      }
}
