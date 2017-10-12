#include <msp430fr5994.h>

#define LED1   BIT0     // Defines the LED at P1.0
#define BUTTON  BIT6    // Defines the BUTTON at P5.6
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;             // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                 // Disable GPIO default high-impedance mode
    P1DIR  = LED1;                        // Set P1.0 LED to output
    P5REN = BUTTON;                       // Enables resistor for button P5.6
    P5OUT = BUTTON;                       // Makes resistor P5.6 a pull up

    while(1)
    {
        if(!(P5IN & BUTTON))              // Check for button Press
        {
            P1OUT ^= LED1;                // Activate LED 1 blinking
            _delay_cycles( 100000);            // Sets delay how long led is on/off when blinking
        }


    }
}
