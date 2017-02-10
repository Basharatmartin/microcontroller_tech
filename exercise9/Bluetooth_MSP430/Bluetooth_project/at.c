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


	unsigned int a;

	//while (1){
		
		__delay_cycles(500000);
		//a=serialRead();


		serialPrintln("AT");
		__delay_cycles(500000);
		serialPrintInt(P1IN);
	
		/*
		if (UCA0RXBUF=="OK"){
			__delay_cycles(500000);
			serialPrintln("AT+NAME?");
		}*/

		//serialPrintln("sent at+name");
		//serialPrintln("\n");

		
		//serialPrintln("\n\r");
		//serialPrintInt(a);
		//serialPrintln("\n");
	//}	
	return 0;
}
