
//********************************************************************************
//  Exercise 7 
//  MSP430 --- Watchdog timers & general timer modules 
//  Description; According to Exercise Nr. 7 -- follow the comments please
// 
//  Author : Basharat Basharat (MSc Embedded Sys Engg)
//********************************************************************************

//#include <msp430.h>                           
#include "templateEMP.h"

#define BUTTON5		BIT3	//	P1.3 
#define LED_GREEN	BIT0	//	P1.0
#define NTC		BIT5	//	P1.4
#define LED_RED		BIT3	//	P3.3
#define REL_STAT	BIT4	//	P3.4
#define REL_DYN 	BIT5	//	P3.5
#define S0_SR2		BIT0 	// 	P2.0
#define	S1_SR2		BIT1 	//	P2.1
#define CLR 		BIT5	//	P2.5
#define	CLK	    	BIT4	//	P2.4
#define SR	    	BIT6	//	P2.6

unsigned short Counter = 0;
unsigned short WD_Flag = 0;
unsigned short LED_Range = 0;

/* Delay Function  */
void delay(unsigned int ms)
{
    for (;ms--;)
    {
        __delay_cycles(1000);
    }
}

/* Pins Initialization */
void PINS_Init(void)
{

	/* Initialization MSP430* */
	initMSP();
	/* selecting I/O functions */	
	P1SEL  &= ~(LED_GREEN + BUTTON5);
	P1SEL2 &= ~(LED_GREEN + BUTTON5);
	P2SEL  &= ~( S0_SR2 + S1_SR2 + CLK + CLR + SR );
	P2SEL2 &= ~( S0_SR2 + S1_SR2 + CLK + CLR + SR );
	P3SEL  &= ~(LED_RED + REL_STAT);
	P3SEL2 &= ~(LED_RED + REL_STAT);
	/* P1.5 A5 option - Analog Input */
	P1SEL  |= NTC;
	P1SEL2 |= NTC;
	/* setting pin directions */
	P1DIR |= LED_GREEN;
	P1DIR &= ~BUTTON5;
	P2DIR |= ( S0_SR2 + S1_SR2 + CLK + CLR + SR );
	P3DIR |= (LED_RED + REL_STAT);
	/* Enabling pull-resistors */
	P1OUT |= BUTTON5;
	P1REN |= BUTTON5;
	/* Setting LED to OFF */
	P1OUT &= ~LED_GREEN;
	P2OUT &= ~( S0_SR2 + S1_SR2 + CLK + CLR + SR );
	P3OUT &= ~(LED_RED + REL_STAT);
}

void ADC_Init(void)
{
	/* Initializing the ADC && modified ADC10CTL0 only when ENC = 0 */
	ADC10CTL0 &= ~ENC;
	ADC10CTL0 = ADC10ON + ADC10SHT_2 ;
	ADC10AE0 |= NTC;
	ADC10CTL1 = INCH_5;
}

void Init_Timer(void)
{
    TA1CCTL0  = CCIE;			// Timer_A capture/compare interrupt enable
    TA1CCR0   = 10000;			// Timer A capture/Compare 0
    TA1CTL  = TASSEL_2 + MC_1;		// SMCLK- up mode - up to CCR0
}

void SReg_Init(void)
{
	P2OUT &= ~CLR;
	P2OUT |= S0_SR2 + CLR;
}

int ADC_Read(void)
{
	/* Start Conversion */
	ADC10CTL0 |= ENC + ADC10SC;
	/* Wait until the result is ready */
	while(ADC10CTL1 & ADC10BUSY);

	serialPrintInt ( ADC10MEM );
	serialPrintln ( " " );

	return ADC10MEM;
}


/* Clock for Shift Register */
void Clock(void)
{
	P2OUT |= CLK;
	P2OUT &= ~CLK;
}

unsigned short NTCRange(int ADCValue)
{
	if (ADCValue < 350)					// LEDS OFF
		LED_Range = 0;
	else if ((ADCValue > 350) && (ADCValue < 401))		// First LED
		LED_Range = 1;
	else if ((ADCValue > 400) && (ADCValue < 444))		// Second LED
		LED_Range = 2;
	else if ((ADCValue > 443) && (ADCValue < 478))		// Third LED
		LED_Range = 3;
	else if ((ADCValue > 477) && (ADCValue < 530))		// Fourth LED
		LED_Range = 4;
	else if ((ADCValue > 529) && (ADCValue < 575))		// On Overheating -> RED LED turns on 
		LED_Range = 5;

	return LED_Range;					// Nr. of LED Switch ON
}

/* Thermometer */
void Thermometer(unsigned short range)
{
	unsigned short i;
	if (range == 0)
	{
		/* Initialize shift register */
		SReg_Init();
		P2OUT &= ~SR;				// SR date = 0;
		range = 4;				// ALL LEDS are Tuned OFF
	}else{
		/* Initialize shift register */
		SReg_Init();
		P2OUT |= SR;				// SR data = 1;
	}

	/* Shifting the values acc. to the Range */
	for ( i = 0; i < range; i++)
	{
		if (range == 5)
			P3OUT |= LED_RED;
		else
			P3OUT &= ~LED_RED;
		Clock();				// Clock Toggle
	}
}


void main ( void )
{

	PINS_Init();					// Pin Initialization
	ADC_Init();					// ADC Initialization
	SReg_Init();					// Shift Register Initialization
	Init_Timer();					// PWM Initialization

		
	/* LED_GREEN on 4Hz ; 250ms toggles until BUTTON5 is pressed */
	
	do{
		P1OUT ^= LED_GREEN;
		delay(250);
		//__delay_cycles(750750);
	}while((P1IN & BUTTON5) != 0x00);
	
	/* Configuration of ACLK to source from VLO = 12KHz/8 */
	BCSCTL3 |= LFXT1S_2;

	/*  WDT is clocked by fACLK (12KHz) */
	WDTCTL = WDT_ADLY_1000;				// WatchDog Interval Timer
	IE1 |= WDTIE;                   		// Enable WatchDog interrupt
	_BIS_SR(LPM0_bits + GIE);           		// Enter LPM0 of the controller

	while (1) {}

}


/* Watchdog Interval Timer Interrupt Service */
#pragma vector=WDT_VECTOR  
__interrupt void watchdog_timer(void) 
{   
	WD_Flag++;
	if (WD_Flag == 8) 
	{
		WD_Flag = 0;
		WDTCTL = WDT_ARST_1000;      		// Watchdog mode ; reset it after time expires
	}
}  

/* Timer A0 Interrupt Service Routine */
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
	Counter++;					// Timer Increment
	if (Counter == 200){				// If it is reached to 2 secs
		Counter = 0;				// Reset the Timer
		if (LED_Range > 3)
			P3OUT &= ~REL_STAT;
		else
			P3OUT |= REL_STAT;
		Thermometer(NTCRange(ADC_Read()));	// Read and Display the temperature
	}
}

