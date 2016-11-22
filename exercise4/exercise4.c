//********************************************************************************
//  Exercise 3 
//  MSP430 --- Shift Register
//  Description; According to Exercise Nr. 3 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"

void _clock();
unsigned short pb1();
unsigned short pb2();
unsigned short pb3();
unsigned short pb4();
void fast_light_sequence();
void pause_light();
void playback_light();
void fast_forward_light();


int main () {

	initMSP();

	P2SEL &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7);
	P2SEL2 &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7);
	P2DIR |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 ;
	P2DIR &= ~BIT7;
	P2REN |= BIT7;
	P2OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT5 + BIT6);
	P2OUT &= ~BIT7;

	for (;;){
		
		P2OUT &= ~BIT5;
		P2OUT &= ~BIT7;
		P2OUT = BIT0 + BIT2 + BIT3 + BIT5 + BIT6;
		P2OUT |= BIT4;		

		serialPrintInt(P2IN);
		serialPrintln("");

		while (!pb1()){ 
			fast_light_sequence();
		}

		while (!pb2()){ 
			pause_light();
		}

		while (!pb3()){ 
			playback_light();
		}
		
		while (!pb4()){ 
			fast_forward_light();
		}

		while (pb1() & pb2() & pb3() &pb4()) {
			
			P2OUT &= ~BIT5;
			P2OUT = BIT0 + BIT5 + BIT6;	
			unsigned short i=0;
	
			for(i=0; i<4; i++){	
				_clock();
				P2OUT &= ~BIT6;
			}
			__delay_cycles(187687);
		
			P2OUT &= ~BIT5;
			P2OUT = BIT0 + BIT5 + BIT6;	
			for(i=0; i<3; i++){	
				_clock();
				P2OUT &= ~BIT6;
			}
			__delay_cycles(187687);

			P2OUT &= ~BIT5;
			P2OUT = BIT0 + BIT5 + BIT6;	
			for(i=0; i<2; i++){	
				_clock();
				P2OUT &= ~BIT6;
			}
			__delay_cycles(187687);

			P2OUT &= ~BIT5;
			P2OUT = BIT0 + BIT5 + BIT6;	
			for(i=0; i<1; i++){	
				_clock();
				P2OUT &= ~BIT6;
			}
			__delay_cycles(187687);

			P2OUT &= ~BIT5;
			P2OUT = BIT0 + BIT5 + BIT6;	
			P2OUT &= ~BIT6;
			_clock();
			__delay_cycles(186785);

		}
	}

	return 0;	
}


void fast_light_sequence(){

	P2OUT &= ~BIT5;
	P2OUT = BIT0 + BIT5 + BIT6;	
	unsigned short i=0;

	for(i=0; i<4; i++){	
		_clock();
		P2OUT &= ~BIT6;
	}
	__delay_cycles(93843);

	P2OUT &= ~BIT5;
	P2OUT = BIT0 + BIT5 + BIT6;	
	for(i=0; i<3; i++){	
		_clock();
		P2OUT &= ~BIT6;
	}
	__delay_cycles(93843);

	P2OUT &= ~BIT5;
	P2OUT = BIT0 + BIT5 + BIT6;	
	for(i=0; i<2; i++){	
		_clock();
		P2OUT &= ~BIT6;
	}
	__delay_cycles(93843);

	P2OUT &= ~BIT5;
	P2OUT = BIT0 + BIT5 + BIT6;	
	for(i=0; i<1; i++){	
		_clock();
		P2OUT &= ~BIT6;
	}
	__delay_cycles(93843);

	P2OUT &= ~BIT5;
	P2OUT = BIT0 + BIT5 + BIT6;	
	P2OUT &= ~BIT6;
	_clock();
	__delay_cycles(93843);
}

void pause_light(){

	// TO DO
}

void playback_light(){
	
	P2OUT &= ~BIT5;
	P2OUT |= BIT0 + BIT2 + BIT5 + BIT6;	
	unsigned short i=0;

	//serialPrintInt(P2IN);
	//serialPrintln("");	
	
	for (i=0; i<4; i++){
		_clock();
		P2OUT &= ~BIT6;
		__delay_cycles (187687); // 250ms delay X 4 = 4 lights taking one second which is one pass
	}
}
void fast_forward_light(){
	
	P2OUT &= ~BIT5;
	P2OUT |= BIT0 + BIT2 + BIT5 + BIT6;	
	unsigned short i=0;

	//serialPrintInt(P2IN);
	//serialPrintln("");	
	
	for (i=0; i<4; i++){
		_clock();
		P2OUT &= ~BIT6;
		__delay_cycles (93843); // 125ms delay X 4 = 4 lights taking one second which are two passes
	}
}

void _clock (){
	P2OUT |= BIT4;
	P2OUT &= ~BIT4;
}

unsigned short pb1(){
	P2OUT |= BIT2;
	P2OUT &= ~BIT3;
	unsigned short i;

	for (i=0; i<3; i++){
		_clock();
	}
	if ( (P2IN & BIT7) == 128)
		return 0;
	else
		return 1;
}

unsigned short pb2(){
	P2OUT &= ~BIT5;
	P2OUT = BIT5;
	P2OUT |= BIT2;
	P2OUT &= ~BIT3;
	unsigned short i;

	for (i=0; i<2; i++){	
		_clock();
	}
	if ( (P2IN & BIT7) == 128)
		return 0;
	else
		return 1;
}

unsigned short pb3(){
	P2OUT &= ~BIT5;
	P2OUT |= BIT5;
	P2OUT |= BIT2;
	P2OUT &= ~BIT3;
	unsigned short i;

	P2OUT &= ~BIT4;

	for (i=0; i<1; i++){
		_clock();
	}
	if ( (P2IN & BIT7) == 128)
		return 0;
	else
		return 1;
}

unsigned short pb4(){
	P2OUT &= ~BIT5;
	P2OUT = BIT5;
	P2OUT |= BIT2 + BIT3;

	P2OUT &= ~BIT4;		
	_clock();
	if ( (P2IN & BIT7) == 128)
		return 0;
	else
		return 1;
}

