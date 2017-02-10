/*
 * MSP430 Timer Tutorial Example Code 1
 * Anthony Scranney
 * www.Coder-Tronics.com
 * August 2014
 *
 * Switching the MSP430G2253 Launchpad LED's on and off
 */

#include <msp430g2253.h>

int Control = 0;

int main(void) {

	/*** Watchdog timer and clock Set-Up ***/
	WDTCTL = WDTPW + WDTHOLD;		// Stop watchdog timer
	DCOCTL = 0;             		// Select lowest DCOx and MODx
	BCSCTL1 = CALBC1_1MHZ;  		// Set range
	DCOCTL = CALDCO_1MHZ;   		// Set DCO step + modulation

	/*** GPIO Set-Up ***/
    P1DIR |= BIT0;					// P1.0 set as output
    P1OUT &= ~BIT0;					// P1.0 set LOW (Red LED)
    P1DIR |= BIT6;					// P1.6 set as output
    P1OUT &= ~BIT6;					// P1.6 set LOW (Green LED)

	/*** Timer0_A Set-Up ***/
    TA0CCR0 |= 3000;					// Counter value
    TA0CCTL0 |= CCIE;				// Enable Timer0_A interrupts
    TA0CTL |= TASSEL_1 + MC_1;		// ACLK, Up Mode (Counts to TA0CCR0)

    _BIS_SR(LPM0_bits + GIE);		// Enter Low power mode 0 with interrupts enabled
}

#pragma vector=TIMER0_A0_VECTOR     // Timer0 A0 interrupt service routine
   __interrupt void Timer0_A0 (void) {

	   Control++;
	    P1OUT ^= BIT0;					// P1.0 Toggle (Red LED)

	   if (Control == 4)
	   {
	    P1OUT ^= BIT6;					// P1.6 Toggle (Green LED)
	    Control = 0;
	   }
}
