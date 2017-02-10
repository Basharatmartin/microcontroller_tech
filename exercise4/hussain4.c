

//	Exercise Nr:  	4 
//	Name :  	Syed Sagheer Hussain


#include <msp430.h>				
#include "templateEMP.h"


void turn_on(unsigned short);
unsigned short value(unsigned int);

int main () {

	initMSP();

	P1SEL &= ~BIT5;
	P1SEL2 &= ~BIT5;
	P2SEL &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);
	P2SEL2 &= ~(BIT0 + BIT1 + BIT4 + BIT5 + BIT6);

	P1DIR &= ~BIT5;
	P2DIR |= BIT0 + BIT1 + BIT4 + BIT5 + BIT6;


	ADC10CTL0 = ADC10ON + ADC10SHT_2 ;
	ADC10AE0 |= BIT5 ;
	ADC10CTL1 = INCH_5 ;

	while (1){

		P2OUT &= ~BIT5;
		P2OUT = BIT0 + BIT2 + BIT3 + BIT5 + BIT6;
		// Start c o n v e r s i o n
		ADC10CTL0 |= ENC + ADC10SC ;
		// Wait until result is ready
		while ( ADC10CTL1 & ADC10BUSY ) ;
		// If result is ready , copy it to m1
		//int m1 = ADC10MEM ;
		P2OUT &= ~BIT6;
		//unsigned int value = ADC10MEM;
		
		if (ADC10MEM > 203 && ADC10MEM < 408){
			P2OUT |= BIT6 ;
			_clock();
		// Print m1 to the serial console
		}
		if (ADC10MEM > 408 && ADC10MEM < 612){
			int i;
			for (i=0; i<2; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		} 

		if (ADC10MEM > 612 && ADC10MEM < 816){
			int i;
			for (i=0; i<3; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		} 
		if (ADC10MEM > 816){
			int i;
			for (i=0; i<4; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		}
		
		serialPrintInt ( ADC10MEM ) ;
		serialPrintln ( " " ) ;
	}	
}

unsigned short value(unsigned int poti){

	if (poti>203 && poti<408)
		return 1;
	if (poti>408 && poti<612)
		return 2;
	if (poti>612 && poti<816)
		return 3;
	if (poti>816)
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

void Clock (){
	P2OUT |= BIT4;
	P2OUT &= ~BIT4;
}

/*
		if (ADC10MEM > 203 && ADC10MEM < 408){
			P2OUT |= BIT6 ;
			_clock();
		// Print m1 to the serial console
		}
		if (ADC10MEM > 408 && ADC10MEM < 612){
			int i;
			for (i=0; i<2; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		} 

		if (ADC10MEM > 612 && ADC10MEM < 816){
			int i;
			for (i=0; i<3; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		} 
		if (ADC10MEM > 816){
			int i;
			for (i=0; i<4; i++){
				P2OUT |= BIT6 ;
				_clock();
			}
		} */
