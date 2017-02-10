
//********************************************************************************
//  Exercise 9 
//  MSP430 --- Communication b/w two dev boards Via bluetooth devices (HC-05)
//  Description; According to Exercise Nr. 9 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

#include <msp430g2553.h>                           


void delay(unsigned int);






	










/* Delay Function  */
void delay(unsigned int ms)
{
    for (;ms--;)
    {
        __delay_cycles(1000);
    }
}


