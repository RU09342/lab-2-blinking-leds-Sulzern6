# Nathan Sulzer
# Embedded Systems
# Lab 2 
# Simple Blink
This task consisted of creating a simple code that can blink an LED continuously.

# Basic Code
The Code functions by blinking an LED on the microprocessor.
```c
#include <msp430g2553.h>

#define LED1    BIT0    // Defines LED at P1.0
#define LED2    BIT6    // Defines LED at P1.6
#define BUTTON  BIT3    // Defines BUTTON at P1.3
/**
 * Nathan Sulzer
 * Into to Embedded Systems
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer
    P1DIR  = LED1;                      // Set P1.0 RED LED to output
    while(1)
    {
            P1OUT ^= LED1;     // Activate LED 1 RED
            _delay_cycles( 200000);
    }
}
```
