#include <msp430F5529.h>

#define LED1    BIT0    // Defines the LED at 1.0
#define BUTTON  BIT1    // Defines BUTTON at  1.1
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer
    P1DIR  = LED1;                      // Set LED at P1.0 to output
    while(1)
    {
            P1OUT ^= LED1;     // Activate LED 1 RED
            _delay_cycles( 200000);
    }
}
