#include <msp430fr2311.h>

#define LED1    BIT0    // Defines the BIt corresponding to the LED used P1.0
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;               // Disable GPIO default high-impedance mode
    P1DIR  = LED1;                      // Set P1.0 LED to output
    while(1)
    {
            P1OUT ^= LED1;              // Activate LED 1
            _delay_cycles( 200000);     //Provides delay for blinking
    }
}
