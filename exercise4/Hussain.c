
//	Exercise Nr. 4
//	Name : Syed Sagheer Hussain 


#include <msp430.h>				
#include "templateEMP.h"

void Clock();
void LEDs(unsigned short);
unsigned int POTEN_METER(unsigned int);
unsigned int LIGHT_DEP_RES(unsigned int);
unsigned int ADC_ARRAY[2] = {0};	
unsigned int POTI = 0;
unsigned int LDR = 0;

int main () {

	/* MSP initialization */
	initMSP();

	/* Setting P1 + P2 + P3 register Input/ Output registers */
	P1SEL &= ~(BIT4 + BIT5);
	P1SEL2 &= ~(BIT4 + BIT5);
	P2SEL &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P2SEL2 &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P3SEL &= (BIT0 + BIT1 + BIT2);
	P3SEL2 &= (BIT0 + BIT1 + BIT2);

	/* Setting Registers directions */
	P1DIR &= ~(BIT4 + BIT5);
	P2DIR |= (BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P2DIR |= (BIT0 + BIT1 +BIT2);
	P3DIR |= (BIT0 + BIT1 + BIT2); 

	ADC10CTL0 = ADC10ON + ADC10SHT_2 + MSC ; 	// Turn on ADC with 16 clocks and Multiple Samples Conversion
	ADC10AE0 |=  (BIT4 + BIT5); 			// Enabling the P1.4 and P1.5 for ADC input
	ADC10DTC0 |=  (BIT4 + BIT5);			// Enabling the data transfer control register 0 
	ADC10CTL1 = INCH_5 + CONSEQ_1 ;			// Select Channel 4 and channel 5
	P3OUT = ~BIT2;					// Turn on leds red, blue and green

	while (1){

		P2OUT &= ~BIT5;					// Shift register CLR
		P2OUT = BIT0 + BIT2 + BIT3 + BIT5 + BIT6;	// For shift register

		while ( ADC10CTL1 & ADC10BUSY ) ;		// Wait until Result is ready		
		ADC10SA = (unsigned int)ADC_ARRAY;		// Initiliaze DTC and stores values in ADC10SA to ADC_ARRAY for Potentiometer and LDR
		ADC10CTL0 |= ENC + ADC10SC ;			// Start Conversion
		P2OUT &= ~BIT6;					// Set SR to 0
		POTI = ADC_ARRAY[0];				// Store value to POTI 
		LDR  = ADC_ARRAY[1];				// Store value to LDR
		

		/* Turning on D1 to D4 dividing 1023 by 5 sections */

		switch(POTEN_METER(POTI)){
			case 1:
				LEDs(1);
				break;
			case 2:
				LEDs(2);
				break;
			case 3:
				LEDs(3);
				break;
			case 4:
				LEDs(4);
				break;
			default:
				break;
		}
	
		/* Printing Chip Colors */		
	
		switch(LIGHT_DEP_RES(LDR)){
			case 1:
				serialPrintln("White chip");
				serialPrintln ( " " ) ;
				break;
			case 2:
				serialPrintln("Black chip");
				serialPrintln ( " " ) ;
				break;
			case 3:
				serialPrintln("Red chip");
				serialPrintln ( " " ) ;
				break;
			case 4:
				serialPrintln("Green chip");
				serialPrintln ( " " ) ;
				break;
			case 5:
				serialPrintln("Blue chip");
				serialPrintln ( " " ) ;
				break;
			default:
				break;
		}

		__delay_cycles(375375);				// 500 ms delay
	}	
}

void Clock (){
	P2OUT |= BIT4;
	P2OUT &= ~BIT4;
}

unsigned short LIGHT_DEP_RES(unsigned int LDR){
	if ( (LDR >= 520) & (LDR <= 535))
		return 1;
	if ( (LDR >= 290) & (LDR <= 305))
		return 2;
	if ( (LDR >= 366) & (LDR <= 378))
		return 3;
	if ( (LDR >= 360) & (LDR <= 365))
		return 4;
	if ( (LDR >= 381) & (LDR <= 390))
		return 5;

	else return 0;

}

unsigned short POTEN_METER(unsigned int POTI){
	if (POTI>203 && POTI<409)
		return 1;
	if (POTI>409 && POTI<613)
		return 2;
	if (POTI>613 && POTI<818)
		return 3;
	if (POTI>818)
		return 4;
	else return 0;
}

void LEDs(unsigned short Nr){
	unsigned short i;
	for(i=0; i<Nr; i++){
		P2OUT |= BIT6 ;
		Clock();
	}
}

