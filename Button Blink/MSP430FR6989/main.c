#include <msp430fr6989.h>

#define LED1    BIT0    // Defines the LED at P1.0
#define BUTTON  BIT1    // Defines the BUTTON at P1.1
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
    P1REN = BUTTON;                       // Enables resistor for button P1.1
    P1OUT = BUTTON;                       // Makes resistor P1.1 a pull up

    while(1)
    {
        if(!(P1IN & BUTTON))              // Check for button Press
        {
            P1OUT ^= LED1;                // Activate LED 1 blinking
             _delay_cycles( 100000);      // Sets delay how long led is on/off when blinking
        }
    }
}
