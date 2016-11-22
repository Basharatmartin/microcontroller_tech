//********************************************************************************
//  Exercise 2 
//  MSP430 
//  Description; According to Exercise Nr. 2 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"



/* Global variable */

void __dirty_leds ();
unsigned short flag = 0;
unsigned short pb5_flag =0;


int main(void) {

	initMSP();		// initializing the controller clock with 1MHz
	__dirty_leds();		// calling the function routine
	__enable_interrupt();	// enable the interrupt
	
	return 0;
}

void __red_led(){

	P1OUT |= 0x21;					// turn on the Red LED
	__delay_cycles (93844);				// 125ms delay to visible the LED    ! Note:->> 375375 delay cycles = 500 ms on Linux
	while ((P1IN&0x08)==0 && (P1IN&0x10)!=0){	// checking if button PB5 is still being pressed then turn off the LED
		P1OUT &= ~0x60;				// turn OFF all the LEDS except LED Yellow
		P1OUT |= 0x80;				// turn ON the LED Yellow
	}
}


void __dirty_leds (){

	P1SEL &= ~(0xF9);	// 1111 1xx1  P1.0, P1.3, P1.4, P1.5, P1.6 and P1.7 are as I/O function 
	P1DIR |= 0xE1;		// 111x xxx1  P1.0, P1.5, P1.6 and P1.7 :-> set the output direction for LEDS
	P1DIR &= ~(0x18);	// xxx0 0xxx  P1.3 and P1.4 :-> set input direction for Buttons PB5 & PB6
	P1REN |= 0x18;		// xxx0 0xxx  For P1.3 and P1.4 pullup/pulldown resistors are enabled :-> Buttons
	P1OUT |= 0x18;		// xxx1 1xxx  Set the Pullup Resiters for P1.3 and P1.4 :-> Buttons
	P1OUT &= ~(0xE0);	// 000x xxxx  P1.5, P1.6 and P1.7 LEDs are turned OFF
	P1OUT |= 0x01;		// xxxx xxx1  P1.0 blue LED is turned OFF (on active High, LED is OFF)

	// Enabling the interrupt for PB5 :-> Button

	P1IE  |= 0x08;		// xxxx 1xxx  Enable the interrupt 
	P1IES |= 0x08;		// 	      High / Low Edge
	P1IFG &= ~0x08;		//	      Clear interrupt flag


	/*******************************************************************************
	      <<<- Polling for PB6 Button ->>   ! interrupt enabled for PB5 Button !
	********************************************************************************/
	
	for (;;) { 
		
		/*  Interrupt enabled for PB5 */

		if ((P1IN&0x08)==0 && (P1IN&0x10)!=0 ){// checking if button PB5 is pressed ! PB6 should be checked as well !
			__red_led();			// call the __red_led () function routine
		}
		else 
		if ( (P1IN&0x10)==0 && (P1IN&0x08)!=0 ){// checking if button PB6 is pressed ! PB5 should be checked as well !
			P1OUT |= 0x41;			// turn on the Green LED
			__delay_cycles (93844);		// 125ms delay to visible the LED     
			//serialPrintInt(P1IN);		// checking the value of input register on Serial OUTPUT
			while ( (P1IN&0x10)==0 && (P1IN&0x08)!= 0) {	// checking if button PB6 is still being pressed then turn off the LED
				P1OUT &= ~0xE0;
			}
		}
		else if ( (P1IN&0x18)== 0){		// checking if both buttons PB5 & PB6 are pressed
			P1OUT &= ~(0x01);		// hold the turn-on state of the Blue LED when both Buttons PB5 & PB6 are kept pressed
			P1OUT &= ~0xE0;			// Rest LEDS are turned OFF
			//__delay_cycles (187688);
			//serialPrintInt(P1IN);
		}	
		else {
			P1OUT |= 0x01;			// Turning OFF the all LEDS in case if no button is pressed
			P1OUT &= ~0xE0;
		}
	}

}


# pragma vector = PORT1_VECTOR
__interrupt void Port_1 ( void ) {
	
	P1IFG &= ~0x08;				// Clear interrupt flag
	P1IE  &= ~0x08;				// Interrupt for PB5 is OFF

	if (!flag){
		pb5_flag = 1;
		flag = 1;
		P1IES &= ~0x08;			// Interrupt Port 1 -- Low to High
	}
	else {
		pb5_flag = 0;
        	flag = 0;
		P1IES |= 0x08;      		// Interrupt Port 1 -- High to Low
	}
}

