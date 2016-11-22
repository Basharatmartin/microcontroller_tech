//********************************************************************************
//  Exercise 1 
//  MSP430 Blinking the LEDs red & blue - Toggle P1.4 and P1.5
//  Description; Toggle P1.4 with 2Hz (50% duty cylce) and P1.5 with 1Hz.
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************
#include <msp430.h>				
#include "templateEMP.h"

void __leds_toggle();
volatile unsigned short counter = 0;

int main(void) {

	initMSP();		// initializing the controller clock with 1MHz
	__leds_toggle();	// calling the leds toggle routine
	
	return 0;
}

void __leds_toggle(){


	//P1SEL &= ~(BIT4 + BIT5);		// select the port 1.4 1.5
	P1DIR |= 0x30; 		// 0011 0000 Set P1.4 and P1.5 to output direction
	//P1OUT &= ~(BIT4 + BIT5);		// select the port 1.4 1.5
				/* P1.5 and Heater are connected to the same voltage EZ_VBUS_5V
				   to activate the led blue, we need to break the Jumper 4, which
				   avails the option to us if we want to toggle the blue led 
				   by connecting the P1.5 with the pin on JP4 (either 2 or 3)
				   Heater can be used via this pin.
				*/
	for(;;) {		// forever loop

		P1OUT ^= 0x10; 		// 0001 0000 Toggle P1.4 using exclusive-OR (2Hz with duty cycle 50%)
		counter++;		// built a counter which counts up to 2 and toggles P1.5 with (1Hz -- half of 2Hz) 
		if (counter == 2){
			P1OUT ^= 0x20;	// 0010 0000 Toggle P1.5 using exclusive-OR	
			counter = 0;			
		}
		if (serialRead() != -1){
			if (P1IN & (P1OUT&=0x20) == 0x20) 	// checking the P1.5 if it is ON / OFF and displaying it using serialPrintln
				serialPrintln("led blue is ON");
			else
				serialPrintln("led blue is OFF");
		}
		__delay_cycles(500000);
	}
}
