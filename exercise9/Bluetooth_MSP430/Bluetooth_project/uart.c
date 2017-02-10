#include <msp430g2553.h>

#define RXBUFFERSIZE 32

char volatile rxBuffer[RXBUFFERSIZE];
char volatile rxBufferStart = 0;
char volatile rxBufferEnd = 0;
char rxBufferError = 0;
char echoBack = 0;


void serialWrite(char);
void serialPrint(char*);
void serialPrintln(char*);

void serialWrite(char tx) {

	// Loop until the TX buffer is ready.
	while (!(IFG2&UCA0TXIFG));
	// Write the character into the TX-register.
	UCA0TXBUF = tx;
	// And wait until it has been transmitted.
	while (!(IFG2&UCA0TXIFG));
}

void serialPrint(char* tx) {

	int b, i = 0;	
	// Count the number of bytes we shall display.

	while(tx[i] != 0x00) {
		i++;
	}
	// Write each of the bytes we counted.
	for (b = 0; b < i; b++) {
        	// We already implemented the "write-a-single-character"-function,
        	// so we're going to use that function instead of implementing the
        	// same stuff here again.
        	serialWrite(tx[b]);
	}
}
    
void serialPrintln(char* tx) {
	// We don't have to implement this again, just pass tx to the apropriate
	// function.
	serialPrint(tx);
	// Print \n
	serialWrite(0x0D);
	// Print \r
	serialWrite(0x0A);
}

unsigned char serialRead(void) {
	// If the buffer's start is the buffer's end, there's no data (return -1)
	//if (rxBufferStart == rxBufferEnd) {
	//	return -1;
	//}
	// Save the first byte to a temporary variable, move the start-pointer
	//char r = rxBuffer[rxBufferStart++];
	//rxBufferStart %= RXBUFFERSIZE;	
	// and return the stored byte.
	//return r;

	while(!(IFG2&UCA0RXIFG));   //USCI_A0 RX buffer ready ?	
	return UCA0RXBUF;

}

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT

	/* Use Calibration values for 1MHz Clock DCO*/	
	DCOCTL = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	/* Configure Pin Muxing P1.1 RXD and P1.2 TXD */
	P1SEL = BIT1 | BIT2 ;
	P1SEL2 = BIT1 | BIT2;


	/* Place UCA0 in Reset to be configured */
	UCA0CTL1 = UCSWRST;


	/* Configure */
	UCA0CTL1 |= UCSSEL_2; // SMCLK
	UCA0BR0 = 104; // 1MHz 9600
	UCA0BR1 = 0; // 1MHz 9600
	UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1

	/* Take UCA0 out of reset */
	UCA0CTL1 &= ~UCSWRST;

	/* Enable USCI_A0 RX interrupt */
	IE2 |= UCA0RXIE;
	__bis_SR_register(LPM0_bits + GIE); // Enter LPM0, interrupts enabled

	unsigned char a;

	while (1){
		serialPrint("Hello !\n");
		a=serialRead();	

		serialPrint(a);
		if (a){
			//while (!a);
			serialPrint((char*)a);
		}
	}
}

/* Echo back RXed character, confirm TX buffer is ready first */
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{

	while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
	UCA0TXBUF = UCA0RXBUF; // TX -&amp;gt; RXed character
}
