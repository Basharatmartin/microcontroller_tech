//********************************************************************************
//  Exercise 6 
//  MSP430 --- Dynamic Circuit Configuration 
//  Description; According to Exercise Nr. 6 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>				
#include "templateEMP.h"
#include "melody.h"

#define	relay		BIT0	// P1.0
#define	vib_signal	BIT4 	// P1.4
#define	audio_signal	BIT6	// P3.6

void playNote1 (void);
void playNote2 (void);
void __init_timer (void);
void __delay(unsigned int ms);

unsigned int counter=0;
unsigned short one=1;
unsigned short melody=0;
unsigned short count, count1, count2;

int main () {

	/* MSP initialization */
	initMSP();

	/* Configuration of audio signal as output */	
	P3SEL |= audio_signal;         	// P3.6 TA0.2 option
	P3DIR |= audio_signal;         	// output to Buzzer
	TA0CCTL2 = OUTMOD_3;            // CCR2 set/reset
	TA0CTL = TASSEL_2 + MC_1;       // SMCLK: MC_1 -> up mode;

	/* Configuring the Relay */
	P1SEL  &= ~relay;		// Enable I/O function	
	P1SEL2 &= ~relay;		
	P1DIR  |= relay;		// direction output
	P1OUT  &= ~relay;		// 0 to P1.0

	/* Configuring the vibrational sensor as input */
	P1SEL  &= ~vib_signal;		// Enable I/O function
	P1SEL2 &= ~vib_signal;
	P1DIR  &= ~vib_signal;		// P1.4 as input
	P1REN  &= ~vib_signal;		// Pull Down resister
	P1OUT  &= ~vib_signal;		// 0 to P1.4	
	P1IE  |= vib_signal;		// P1.4 Enabling the Interrupt	
	P1IES |= vib_signal;		// Trigger interrupt falling edge - High -> Low
	P1IFG &= ~vib_signal;		// Clear Interrupt

	__enable_interrupt();           // Interrupts
	

	for(;;)
        {
                __delay_cycles(2000000);
                switch (melody){         	// switch melody
			case 1:	playNote1();    // Play first playNotes
                        	break;
                	case 2: playNote2(); 	// Play second playNotes
                        	break;
                }
                serialPrintInt(P1IN);
                serialPrintln("");
        }



}

void __delay(unsigned int ms)
{
        for (;ms--;){
                __delay_cycles(1000);   // 1000 for 1 MHz
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
	P1OUT |= relay;
	melody=0;
        unsigned int i;
        for (i = 0; i < 25; i++)
        {
		TA0CCR0 = notes_1[i];    	// pwm period	
		TA0CCR2 = notes_1[i]/2;  	// 50% duty cycle
		__delay(notes_1_interval[i]);    // duration of tones
		TA0CCR0 = 0;                    // period 0 - no tones	
		__delay(100);                    // no tones  duration
        }
	TA0CCR2 = 0;
	P1OUT &= ~relay;
}

void playNote2(void)
{
	P1OUT |= relay;
	melody=0;	
        unsigned int i;
        for (i = 0; i < 16; i++)
        {
		TA0CCR0 = notes_2[i];       // pwm period
		TA0CCR2 = notes_2[i]/2;     // 50% duty cycle
		__delay(notes_2_interval[i]);     // duration of tones
		TA0CCR0 = 0;                    // period 0 - no tone
		__delay(100);                    // no duration of tones
        }
	TA0CCR2 = 0;
	P1OUT &= ~relay;

}


// Interrupts enable

// Timer A0 Interrupt
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
        counter++;                                // increment counter
        if (counter == 100){                      // if it is reached
                counter = 0;                      // reset to counter
		count = 0;
		count1 = 0;
		count2 = 0;
        }
}
// PORT 1 Interrupt
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
        P1REN  |= vib_signal;			// pull up resistor
        P1REN  &= ~vib_signal;			// pull down resistor

        if (P1IFG & vib_signal){		// P1.3 interrupt
                if (one == 1){			// setup the 1s timer only once
                        one = 2;		// lock up re-executing __init_timer()
                        __init_timer();		// Initialization of timer
                }
                __delay_cycles(1000);
                //count++;                        // Increment the count
                P1IFG &= ~vib_signal;		// clear P1.3 interrupt

                /* count within the first 500ms */
                if (counter < 50)
                        count1++;
                else 				// count within the second 500ms
                        count2++;

                /* vibration detection with with two count cyles */
                count = count1 + count2;

                if ((count > count1) && (count >= 2))
                        melody = 2;             //set flag for playNote1
                else
                        if ((count1 >= 1) && (count1 < 3))
                                melody = 1;     //set flag for playNote2
        }
}


