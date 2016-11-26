//********************************************************************************
//  Exercise 4 
//  MSP430 --- Analog to Digital Conversion
//  Description; According to Exercise Nr. 4 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"

void _clock();
void turn_on(unsigned short);
unsigned short value_poti(unsigned int);
unsigned short value_ldr(unsigned int);
unsigned int adc_value[2] = {0};	
unsigned int poti = 0;
unsigned int ldr = 0;

int main () {

	/* MSP initialization */
	initMSP();

	/* Registers P1, P2, P3 I/O initialization */
	P1SEL &= ~(BIT4 + BIT5);
	P1SEL2 &= ~(BIT4 + BIT5);
	P2SEL &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P2SEL2 &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P3SEL &= (BIT0 + BIT1 + BIT2);
	P3SEL2 &= (BIT0 + BIT1 + BIT2);

	/* Registers P1, P2, P3 INPUT / OUTPUT directions */
	P1DIR &= ~(BIT4 + BIT5);
	P2DIR |= (BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P2DIR |= (BIT0 + BIT1 +BIT2);
	P3DIR |= (BIT0 + BIT1 + BIT2); 

	ADC10CTL0 = ADC10ON + ADC10SHT_2 + MSC ; // Turn on ADC with 16 clocks and hold time + Multiple samples and conversion
	//ADC10AE0 |=  BIT5;
	//ADC10CTL1 = INCH_5 ;
	ADC10AE0 |=  (BIT4 + BIT5); 		// enable P1.4 and P1.5 for AD input
	ADC10DTC1 |=  (BIT4 + BIT5);		// enable data transfer control register 1 
	ADC10CTL1 = INCH_5 + CONSEQ_1 ;		// select channel 5 and sequence of channels (channel 4)
	P3OUT = ~BIT2;				// turn on led (red, green and blue);

	while (1){

		P2OUT &= ~BIT5;					// clear for shift register
		P2OUT = BIT0 + BIT2 + BIT3 + BIT5 + BIT6;	// control mode, clear 1 to start shifting, and data SR

		//ADC10CTL0 &= ~ENC;				// disable the ADC10
		// Wait until result is ready
		while ( ADC10CTL1 & ADC10BUSY ) ;		// wait until result is ready		
		ADC10SA = (unsigned int)adc_value;		// initiliaze DTC and stores values in ADC10SA to adc_value array for poti and ldr
		// Start c o n v e r s i o n
		ADC10CTL0 |= ENC + ADC10SC ;			// start conversion
		P2OUT &= ~BIT6;					// set SR to 0
		poti = adc_value[0];				// store adc_value[0] to poti ... it's value from potentiometer 
		ldr  = adc_value[1];				// store adc_value[1] to ldr  ... it's value from ldr
		

		/* switching from D1 to D4 by dividing 1023 with 5 = 204.6 */

		switch(value_poti(poti)){
			case 1:
				turn_on(1);
				break;
			case 2:
				turn_on(2);
				break;
			case 3:
				turn_on(3);
				break;
			case 4:
				turn_on(4);
				break;
			default:
				break;
		}
	
		/* printing the chip color by detecting the colors seperately first and printing according to the values */		
	
		switch(value_ldr(ldr)){
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

		serialPrintInt ( ldr ) ;
		serialPrintln ( " " ) ;
		//serialFlush();
		__delay_cycles(375375);				// 500 ms delay in case of visualizing the values on serial interface
	}	
}

void _clock (){
	P2OUT &= ~BIT4;
	P2OUT |= BIT4;
}

unsigned short value_ldr(unsigned int ldr){
	if ( (ldr >= 520) & (ldr <= 535))
		return 1;
	if ( (ldr >= 290) & (ldr <= 305))
		return 2;
	if ( (ldr >= 366) & (ldr <= 378))
		return 3;
	if ( (ldr >= 360) & (ldr <= 365))
		return 4;
	if ( (ldr >= 381) & (ldr <= 390))
		return 5;

	else return 0;

}

unsigned short value_poti(unsigned int poti){
	if (poti>203 && poti<409)
		return 1;
	if (poti>409 && poti<613)
		return 2;
	if (poti>613 && poti<818)
		return 3;
	if (poti>818)
		return 4;
	else return 0;
}

void turn_on(unsigned short nr){
	unsigned short i;
	for(i=0; i<nr; i++){
		P2OUT |= BIT6 ;
		_clock();
	}
}

