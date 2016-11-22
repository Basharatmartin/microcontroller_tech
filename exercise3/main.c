
/*	Exercise sheet
	Created on:  xx.xx.xxxx
	Author:      Boniface Bassey
*/

#include <msp430g2553.h>
#include "templateEMP.h"
#include <stdbool.h>

#define S0_SR2	BIT0
#define	S1_SR2	BIT1
#define S0_SR1	BIT2
#define	S1_SR1	BIT3
#define	CLK	    BIT4
#define CLR 	BIT5
#define SR	    BIT6
#define QD	    BIT7
#define DATA_PORT2 0x7F

void __resetSR(void);
void __setSR(void);
void __modeSelectSR(void);
void __modeSelectSL(void);
void __clockPulse(void);
void __shiftRight_SREG1(void);
void __pass_per_second(void);
void delay(unsigned int);

unsigned char i, j, val, state;
_Bool pause_button = false;
unsigned char getPB3 = 0;
unsigned char valPB3 = 0;
unsigned char idx;



/*
 * main.c
 */
int main(void)
{
	// Initialization of the controller
    initMSP();

	// select I/O function on PORT2
	P2SEL  &= ~DATA_PORT2;
	P2SEL2 &= ~DATA_PORT2;
	P2SEL &= ~QD;
	P2SEL2 &= ~QD;

	P1SEL &= ~BIT7;
	P1SEL2 &= ~BIT7;
	P1DIR |= BIT7;


	// PORT2 as output ports, P2.7 as input
	P2DIR |= DATA_PORT2;
	P2DIR &= ~QD;

	// initialize port - clear all bits
	P2OUT &= ~DATA_PORT2;
	P2OUT &= ~QD;

	// Set shift register - stop the reset mode
	__setSR();


	while(1)
	{

// Just to Test the Push buttons --- Not working
//.......................................
/*		P2OUT |= S0_SR1 + S1_SR1;		// select parallel input on SREG1
		P2OUT &= ~CLK;					// clock high
		__delay_cycles(10);
		P2OUT |= CLK;					// clock low
		val = (P2IN & QD);

		P1OUT = val;
*/
// shift Left and right ---OK
//.......................................

		P2OUT |= S0_SR1 + S1_SR1;		// select parallel input on SREG1
		if (state != 2){
			__modeSelectSR();				// select shift right on SREG2
			P2OUT |= SR;					// High input on SREG2 SR
		}

		for ( i = 0 ; i < 4 ; i++ )
		{
			__clockPulse();				// Toggle clock
			P2OUT &= ~SR;
			val = (P2IN & QD);  		// PB4

			if (val && (i == 0)){
				state = 4;
				P1OUT = val;
			}
			else
			{
				__shiftRight_SREG1();
				val = (P2IN & QD);

				if (val && (i == 1)){		// PB3
					state = 3;
					P1OUT = val;
				}
				else if (val && (i == 2)){	// PB2
					P2OUT &= ~(S0_SR2 + S1_SR2);
					state = 2;
					P1OUT = val;
				}
				else if (val && (i == 3) && (state != 2)){	// PB1
					state = 1;
					P1OUT = val;
				}
				else{
					//state = 0;
					P1OUT = 0;
				}
			}

			//if (state == 2){
			//	P2OUT &= ~(S0_SR2 + S1_SR2);
			//	val = 0;

				/*
				P2OUT |= S0_SR1 + S1_SR1;		// select parallel input on SREG1
				do{
					for ( idx = 0 ; idx < 4 ; idx++ )
					{
						__clockPulse();
						getPB3 = (P2IN & QD);
						__shiftRight_SREG1();

						if(getPB3 && (idx == 1))
						{
							valPB3 = 1;
							state = 0;
							break;
						}
						else
							valPB3 = 0;
					}
				}while(valPB3 != 1);
				*/
			//}

			// 2 or 1 led pass per second
			__pass_per_second();


			if ((i == 3) && (state == 1) && (pause_button == 0))
			{
				__modeSelectSL();
				for ( i = 0 ; i < 4 ; i++ ){
					__clockPulse();
					P2OUT &= ~SR;

					// 2 or 1 led pass per second
					__pass_per_second();
				}
			}
		}
	}
}

// Reset shift register
void __resetSR(void){
	P2OUT &= ~CLR ;
}

// Set shift register
void __setSR(void){
	P2OUT |= CLR ;
}

// Mode control - shift right
void __modeSelectSR(void){
	P2OUT |= S0_SR2 ;
	P2OUT &= ~S1_SR2 ;
}

// Mode control - shift left
void __modeSelectSL(void){
	P2OUT |= S1_SR2 ;
	P2OUT &= ~S0_SR2 ;
}

void __shiftRight_SREG1(void)
{
	P2OUT |= S0_SR1 ;
	P2OUT &= ~S1_SR1 ;
}

// Pulse the clock pin
void __clockPulse(void)
{
	P2OUT |= CLK;	// apply a rising clock edge = > shift data in
	P2OUT ^= CLK;	// reset the clock
}

void __pass_per_second(void)
{
	if (valPB3)
		delay(1000);
	else
		delay(500);
}
// Delay in ms
void delay(unsigned int ms)
{
 while (ms--)
    {
        __delay_cycles(1000); // 1000 for 1 Mhz
    }
}
