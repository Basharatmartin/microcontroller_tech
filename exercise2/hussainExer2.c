
//	Exercise Nr. 2 
//	Name :	Syed Sagheer Hussain


#include <msp430.h>				
#include "templateEMP.h"


#define	BLUELED		BIT0
#define	BUTTONPB5	BIT3
#define	BUTTONPB6	BIT4
#define	REDLED		BIT5
#define	GREENLED	BIT6
#define YELLOWLED	BIT7

void init_leds ();
unsigned char mode = 0;
unsigned char button_state =0;


int main(void)
{
	initMSP();		// initializing 1MHz Clock
	init_leds();		// invoking the led function
	__enable_interrupt();	// enabling the all interrupts
	
}

void red_led ()
{

	P1OUT |= REDLED;					// turn on the Red LED
	__delay_cycles (93844);					// 125ms delay to visible the LED    ! Note:->> 375375 delay cycles = 500 ms on Linux
	while ((P1IN&BUTTONPB5)==0 && (P1IN&BUTTONPB6)!=0){	// checking if button PB5 is still being pressed then turn off the LED
		P1OUT &= ~0x60;					// turn OFF all the LEDS except LED Yellow
		P1OUT |= YELLOWLED;				// turn ON the LED Yellow
	}
}


void init_leds (){

	P1SEL &= ~(BIT0+BIT3+BIT4+BIT5+BIT6+BIT7);		// P1.0, P1.3, P1.4, P1.5, P1.6 and P1.7 are as I/O function 
	P1DIR |= (BIT0+BIT5+BIT6+BIT7);				// P1.0, P1.5, P1.6 and P1.7 set the output direction for LEDS
	P1DIR &= ~(BUTTONPB5 + BUTTONPB6);			// P1.3 and P1.4 :-> set input direction for Buttons PB5 & PB6
	P1REN |= (BIT3+BIT4);					// P1.3 and P1.4 pullup/pulldown resistors are enabled 
	P1OUT |= (BIT3+BIT4);					// Pullup Resiters for P1.3 and P1.4 
	P1OUT &= ~(BIT5+BIT6+BIT7);				// P1.5, P1.6 and P1.7 LEDs are turned OFF
	P1OUT |= BIT0;						// P1.0 blue LED is turned OFF (on active High, LED is OFF)

	// Enable the interrupt

	P1IE  |= BIT4;		// Enable the interrupt 
	P1IES |= BIT4;		// High / Low Edge
	P1IFG &= ~BIT4;		// Clear interrupt flag


	
	while (1) { 
		
		//  Interrupt enabled 

		if ((P1IN&BUTTONPB5)==0 && (P1IN&BUTTONPB6)!=0 ){	// checking if button PB5 is pressed interrupt enabled ! PB6 should be checked as well !
			red_led();					// call the red_led () function 
		}
		if ( (P1IN&BUTTONPB6)==0 && (P1IN&BUTTONPB5)!=0 ){	// checking if button PB6 is pressed ! PB5 should be checked as well !
			P1OUT |= 0x41;					// turn on the Green LED
			__delay_cycles (93844);				// 125ms delay to visible the LED     
			while ( (P1IN&BUTTONPB6)==0 && (P1IN&BUTTONPB5)!= 0) {	// checking if button PB6 is still being pressed then turn off the LED
				P1OUT &= ~0xE0;
			}
		}
		if ( (P1IN&(BUTTONPB5+BUTTONPB6)== 0)){			// checking if buttons PB5 & PB6 are kept pressed
			P1OUT &= ~(BLUELED);				// turn-on state of the Blue LED when both Buttons PB5 & PB6 are kept pressed
			P1OUT &= ~0xE0;					// Rest LEDS are turned OFF
		}	
		else {
			P1OUT |= BIT0;					// Turning OFF all led in case if no button is pressed
			P1OUT &= ~0xE0;
		}
	}

}


# pragma vector = PORT1_VECTOR
__interrupt void Port_1 ( void ) {
	
	P1IFG &= ~BUTTONPB5;				// Clear interrupt Flag
	P1IE  &= ~BUTTONPB5;				// Interrupt OFF for PB5

	if (!mode){
		button_state = 1;
		mode = 1;
		P1IES &= ~BUTTONPB5;			// Interrupt Low -> High
	}
	else {
		button_state = 0;
        	mode = 0;
		P1IES |= BUTTONPB5;      		// Interrupt High -> Low
	}
}

