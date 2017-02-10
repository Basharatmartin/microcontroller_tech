//********************************************************************************
//  Exercise 5 
//  MSP430 --- PWM 
//  Description; According to Exercise Nr. 5 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"
#include "melody.h"

#define	PB5	BIT3
#define	PB6	BIT4

void playNote1 (void);
void playNote2 (void);
void __init_timer (void);
void __delay(unsigned int ms);

unsigned int count=0;
unsigned short one=1;
unsigned short melody=0;
unsigned short mode=0;
unsigned short button5_count=0;
unsigned short button5_switch=0;
unsigned short button6_switch=0;


int main () {

	/* MSP initialization */
	initMSP();

        P3DIR |= BIT6;          	// output to Buzzer
        P3SEL |= BIT6;          	// P3.6 TA0.2 option
        TA0CCTL2 = OUTMOD_3;            // CCR2 set/reset
        TA0CTL = TASSEL_2 + MC_1;       // SMCLK: MC_1 -> up mode;

        P1SEL  &= ~(PB5 + PB6);         // Buttons PB5 & PB6
        P1SEL2 &= ~(PB5 + PB6);               
        P1DIR &= ~(PB5 + PB6);          // Buttons direction as input
        P1REN |= (PB5 + PB6);           // Pull-up resistors for buttons PB5 & PB6
        P1IE |= (PB5 + PB6);            // Interrupt for Port 1 for Pins  P1.3 & P1.4
        P1IES |= (PB5 + PB6);           // Trigger interrupt (falling edge) - High -> Low 
        P1IFG &= ~(PB5 + PB6);          // Clear Flag
        __enable_interrupt();           // Interrupts

        for (;;)                        
        {
                switch(melody){        
                        case 1: playNote1();	// Play first playNotes
                		break;
			case 2: playNote2();	// Play second playNotes
				break;
			default:break;
                }
        }

}

void __delay(unsigned int ms)
{
        while (ms--){
                __delay_cycles(1845);   // 1000 for 1 MHz
        }
}

void __init_timer(void)
{
    TA1CCTL0  = CCIE;                   // Timer_A interrupt c/c 
    TA1CCR0   = 10000;                  // PWM Period
    TA1CTL  = TASSEL_2 + MC_1;          // SMCLK; MC_1 ->  up mode ;
}

void playNote1(void)
{
        unsigned int i;
        for (i = 0; i < 25; i++)
        {
                do
                {
                        TA0CCR0 = 0;
                }
                while(button5_switch == 1);         // Button5 pause and replay playNote1
                if (melody != 1)                // play playNote1 as long as playNote1 flag is set
                        break;

                TA0CCR0 = notes_1[i];    	// pwm period
                TA0CCR2 = notes_1[i]/2;  	// 50% duty cycle
                __delay(notes_1_interval[i]);    // duration of tones
                TA0CCR0 = 0;                    // period 0 - no tones
                __delay(100);                    // no tones  duration
        }
        TA0CCR2 = 0;
}

void playNote2(void)
{
        unsigned int i;
        for (i = 0; i < 0; i++)
        {
                do
                {
                        TA0CCR0 = 0;
                }
                while(button6_switch == 1);         // button6 pause and replay playNote2
                if (melody != 2)                // play playNote2 as long as playNote2 flag is set
                        break;

                TA0CCR0 = notes_2[i];       // pwm period
                TA0CCR2 = notes_2[i]/2;     // 50% duty cycle
                __delay(notes_2_interval[i]);     // duration of tones
                TA0CCR0 = 0;                    // period 0 - no tones
                __delay(100);                    // no duration of tones
        }
        TA0CCR2 = 0;
}


// Interrupts enable

// Timer A0 Interrupt
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
        count++;                                // increment count
        if (count == 100){                      // if it is reached
                count = 0;                      // reset to count
                button5_count = 0;              // reset button5 interrupt count
        }
}
// PORT 1 Interrupt
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
        if (P1IFG & PB5){                       // button5 nterrupt
                if (one == 1){                 // only once - timer
                        one = 2;               // lock up re-executing __init_timer();
                        __init_timer();          // Initialization of timer
                }
                button5_count++;                    // counter increment
                P1IFG &= ~PB5;                  // clear button5 interrupt
                if (button5_count == 1){            // checking if button pressed once 
                        melody = 1;             // set playNote1 flag
                        count = 0;              // reset timer
                }
                if (button5_count == 2){            // checking if button pressed two times
                        melody = 2;             // set playNote2 flag
                        count = 0;              // reset timer
                }
        }

        if (P1IFG & PB6){                       // button6 interrupt
                P1IFG &= ~PB6;                  // clear button6 interrupt
                button6_switch++;                   // counter increment
                if (button6_switch == 2)            // for pause and reply two  times it is needed
                        button6_switch = 0;
        }
}



