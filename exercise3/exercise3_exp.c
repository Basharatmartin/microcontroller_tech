//********************************************************************************
//  Exercise 3 
//  MSP430 --- Shift Register
//  Description; According to Exercise Nr. 3 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"



/* Global variable */

void _clock (){
	P2OUT |= BIT4;
	P2OUT &= ~BIT4;
}

unsigned short pb4(){
	P2OUT |= BIT2 + BIT3;

	_clock();
	if ( (P2IN & BIT7) == 0)
		return 0;
	else
		return 1;
}
unsigned short pb1(){
	P2OUT |= BIT2 + BIT3;
	//_clock();
	P2OUT &= ~BIT5;
	P2OUT |= BIT2;
	P2OUT &= ~BIT3;
	//P2OUT |= BIT7;
	unsigned short i;

	for (i=0; i<4; i++){
		_clock();
	}
	

	if ( (P2IN & BIT7) == 0)
		return 0;
	else
		return 1;
}

unsigned short pb2(){
	P2OUT |= BIT2;
	P2OUT &= ~BIT3;
	//P2OUT |= BIT7;
	unsigned short i;

	for (i=0; i<2; i++){
		_clock();
	}
	

	if ( (P2IN & BIT7) == 0)
		return 0;
	else
		return 1;
}
int main () {

	initMSP();

	P2SEL &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7);
	P2SEL2 &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7);
	P2DIR |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6;
	P2DIR &= ~BIT7;

	P2REN |= BIT7;
	P2OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT5);
	P2OUT &= ~BIT7;

	for (;;){
		
		P2OUT &= ~BIT5;
		P2OUT &= ~BIT7;
		P2OUT = BIT0 + BIT2 + BIT3 + BIT5;
		P2OUT |= BIT4;		
		//P2OUT &= ~BIT4;		

		serialPrintInt(P2IN);
		serialPrintln("");

		while (pb1()){ 
			P2OUT &= ~BIT5;
			//P2OUT &= ~BIT0;
			P2OUT |= BIT0 + BIT2 + BIT5 + BIT6;	
			P2OUT &= ~BIT3;
			P2OUT |= BIT2;
			unsigned short i=0;
	
			for (i=0; i<4; i++){
				P2OUT &= ~BIT4;
				P2OUT |= BIT4;
				P2OUT &= ~BIT6;
				__delay_cycles (375);
				P2OUT &= ~BIT4;
			}
		}
		while (pb2()){ 
			P2OUT &= ~BIT5;
			//P2OUT &= ~BIT0;
			P2OUT |= BIT0 + BIT2 + BIT5 + BIT6;	
			unsigned short i=0;
	
			for (i=0; i<4; i++){
				P2OUT &= ~BIT4;
				P2OUT |= BIT4;
				P2OUT &= ~BIT6;
				__delay_cycles (9339);
				P2OUT &= ~BIT4;
			}
		}

		while (pb4()){ 
			P2OUT &= ~BIT5;
			//P2OUT &= ~BIT0;
			P2OUT |= BIT0 + BIT2 + BIT5 + BIT6;	
			unsigned short i=0;
	
			for (i=0; i<4; i++){
				P2OUT &= ~BIT4;
				P2OUT |= BIT4;
				P2OUT &= ~BIT6;
				__delay_cycles (93392);
				P2OUT &= ~BIT4;
			}
		}


		P2OUT &= ~BIT5;
		P2OUT = BIT0 + BIT5 + BIT6;	
		unsigned short i=0;

		for(i=0; i<1; i++){	
			P2OUT |= BIT4;
		
			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;

			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;
	
			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;
		}
		__delay_cycles(186785);
		
		P2OUT &= ~BIT5;
		P2OUT = BIT0 + BIT5 + BIT6;	
	
		for(i=0; i<1; i++){	
			P2OUT |= BIT4;
		
			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;

			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;
	
		}
		__delay_cycles(186785);



		P2OUT &= ~BIT5;
		P2OUT = BIT0 + BIT5 + BIT6;	
	
		for(i=0; i<1; i++){	
			P2OUT |= BIT4;
		
			P2OUT &= ~BIT4;
			P2OUT &= ~BIT6;
			P2OUT |= BIT4;

	
		}
		__delay_cycles(186785);

		P2OUT &= ~BIT5;
		P2OUT = BIT0 + BIT5 + BIT6;	
	
		for(i=0; i<1; i++){	
			P2OUT |= BIT4;
			P2OUT &= ~BIT6;
			P2OUT &= ~BIT4;
			
		}
		__delay_cycles(186785);

		P2OUT |= BIT4;
		P2OUT &= ~BIT6;
		P2OUT &= ~BIT4;
		P2OUT |= BIT4;
		
		__delay_cycles(186785);

		/*
		P2OUT |= BIT4;
		__delay_cycles (186785);
		P2OUT &= ~BIT6;
		P2OUT &= ~BIT4;
	
		P2OUT |= BIT4;
		__delay_cycles (186785);
		P2OUT &= ~BIT6;
		P2OUT &= ~BIT4;
	
		P2OUT |= BIT4;
		__delay_cycles (186785);
		P2OUT &= ~BIT6;
		P2OUT &= ~BIT4;
		*/
		

	}

	return 0;	

}
