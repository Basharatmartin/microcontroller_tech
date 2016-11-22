//********************************************************************************
//  Exercise 1 
//  MSP430 Blinking the LEDs red & blue - Toggle P1.4 and P1.5
//  Description; Toggle P1.4 with 2Hz (50% duty cylce) and P1.5 with 1Hz.
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************
//#include <msp430.h>				
#include "templateEMP.h"

void __leds_toggle();
volatile unsigned short counter = 0;

int main(void) {

	initMSP();		// initializing the controller clock with 1MHz
	__leds_toggle();	// calling the leds toggle routine
	
	return 0;
}

void __leds_toggle(){


	P1DIR |= 0x20; 		// 0011 0000 Set P1.4 and P1.5 to output direction

	while(1){

		P1OUT^=0x20;
		//__delay_cycles(500000);
		__delay_cycles(375375);
	}

}
