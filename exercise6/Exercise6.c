
// Name : Syed Sagheer Hussain  
// Exercise Nr. 6 
// Description : Dynamic Circuit Configuration 

#include "templateEMP.h"

// melodies and its frequencies 
#define  C4     3830    // 261 Hz	1915
#define  D4     3400    // 294 Hz	1700
#define  E4     3038    // 329 Hz	1519
#define  F4     2864    // 349 Hz	1432
#define  G4     2550    // 392 Hz	1275
#define  A4     2272    // 440 Hz	1136
#define  B4     2028    // 493 Hz	1014
#define  C5     1912    // 523 Hz	956
#define  B4b    2146	// 466 Hz	1073
#define  E5     1517	// 659 Hz	759

// Global variables ->> Tones 
unsigned int happy_birthday[25] = {C4, C4, D4, C4, F4, E4,C4, C4, D4, C4, G4, F4,C4, C4, C5, A4, F4, E4, D4,B4b, B4b, A4, F4, G4, F4};
unsigned int interval_hb[25] = {200, 200, 270, 270, 270, 670, 200, 200, 270, 270, 270, 590, 200, 200, 270, 270, 270, 300, 670,250, 250, 300, 300, 300, 590};

unsigned int random_tone[15] = {A4, B4, A4, B4b, A4, B4, B4, B4, B4, C5, B4, C5, B4, A4};
unsigned int interval_random[15] = {410, 210, 213, 410, 310, 210, 300, 310, 200, 200, 200, 100, 400, 100};

#define audio		BIT6	// connected to P3.6 
#define vibration	BIT3 	// connected to P1.3  
#define relay		BIT0 	// connected to P1.0 

void _delay(unsigned int ms);
void _first_melody(void);
void _second_melody(void);
void _init_timer(void);

unsigned int counter=0;
unsigned short once=1;
unsigned short melody=0;
unsigned short count, count1, count2;


int main(void) {

	initMSP();

	P3DIR |= audio;			// output to Buzzer
	P3SEL |= audio;			// P3.6 TA0.2 option
	TA0CCTL2 = OUTMOD_3;		// CCR2 set/reset
	TA0CTL = TASSEL_2 + MC_1;	// SMCLK: MC_1 -> Up mode;
        P1SEL  &= ~relay;               // Enable I/O function  
        P1SEL2 &= ~relay;               
        P1DIR  |= relay;                // direction output
        P1OUT  &= ~relay;               // 0 to P1.0
        P1SEL  &= ~vibration;          // Enable I/O function
        P1SEL2 &= ~vibration;
        P1DIR  &= ~vibration;          // P1.3 as input
        P1REN  &= ~vibration;          // Pull Down resister
        P1OUT  &= ~vibration;          // 0 to P1.3    
        P1IE  |= vibration;            // P1.4 Enabling the Interrupt  
        P1IES |= vibration;            // Trigger interrupt falling edge - High -> Low
        P1IFG &= ~vibration;           // Clear Interrupt
	__enable_interrupt();		// enabling the interrupts

	while (1)			// forever loop
	{
		if (melody==1){		// checking if 1 then play the _first_melody();
			_first_melody();
		}
		if (melody==2){		// checking if 2 then play the _second_melody();
			_second_melody();
		}
	}
}

void _delay(unsigned int ms)
{
	while (ms--){
        	__delay_cycles(1000);	// 1000 for 1 MHz
    	}
}


void _init_timer(void)
{
    TA1CCTL0  = CCIE;			// enabling Timer_A capture / compare interrupt 
    TA1CCR0   = 10000;			// PWM period
    TA1CTL  = TASSEL_2 + MC_1;		// SMCLK; MC_1 ->  up mode ;
}


void _first_melody(void)
{
	melody=0;
	P1OUT |= relay;
	unsigned char i;
	for (i = 0; i < 25; i++)
	{
    		TA0CCR0 = happy_birthday[i];	// pwm period
    		TA0CCR2 = happy_birthday[i]/2;	// 50% duty cycle
    		_delay(interval_hb[i]);		// duration of tones
    		TA0CCR0 = 0;			// period 0 - no tones
    		_delay(100);			// no tones  duration
    	}
    	TA0CCR2 = 0;
	P1OUT &= ~relay;
}

void _second_melody(void)
{
	melody=0;
	P1OUT |= relay;
	unsigned char i;
	for (i = 0; i < 15; i++)
	{
    		TA0CCR0 = random_tone[i];	// pwm period
    		TA0CCR2 = random_tone[i]/2;	// 50% duty cycle
    		_delay(interval_random[i]);	// duration of tones
    		TA0CCR0 = 0;			// period 0 - no tones
    		_delay(100);			// no duration of tones
    	}
    	TA0CCR2 = 0;
	P1OUT &= ~relay;
}

// Timer A0 interrupt service routine
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
	counter++;				// increment count
	if (counter == 100){			// if it is reached
		counter = 0;			// reset to count
		count = 0;
		count1 = 0;
		count2 = 0;
	
	}
}

// Port 1 interrupt vector
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
        P1REN  |= vibration;                   // pull up resistor
        P1REN  &= ~vibration;                  // pull down resistor

        if (P1IFG & vibration){                // P1.3 interrupt
                if (once == 1){                  // setup the 1s timer only once
                        once = 2;                // lock up re-executing _init_timer()
                        _init_timer();         // Initialization of timer
                }
                __delay_cycles(1000);
                count++;                        // Increment the count
                P1IFG &= ~vibration;           // clear P1.3 interrupt

                /* count within the first 500ms */
                if (counter < 50)
                        count1++;
                else                            // count within the second 500ms
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
