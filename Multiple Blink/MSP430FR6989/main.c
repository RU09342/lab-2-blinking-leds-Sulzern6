#include <msp430fr6989.h>

#define LED1    BIT0    // Defines the LED at P1.0
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;               // Disable GPIO default high-impedance mode
    P1DIR  = LED;                      // Set P1.0 RED LED to output
    int i = 0x0001;
    while(1)
    {
        if(i == 1)
        {
            P1OUT ^= LED;     // Activate LED 1 RED
            _delay_cycles( 200000);
            i == 0x00;
        }
        else
        {
            P1OUT ^= 0x00;
            _delay_cycles( 200000);
            i = i++;
        }
    }
}
