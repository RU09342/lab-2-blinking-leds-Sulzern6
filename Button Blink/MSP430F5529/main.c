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
    P1DIR  = LED1;                      // Set P1.0 RED LED to output
    P1REN = BUTTON;                     // Enables resistor for button P1.1
    P1OUT = BUTTON;                     // Makes resistor P1.1 a pull up

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
