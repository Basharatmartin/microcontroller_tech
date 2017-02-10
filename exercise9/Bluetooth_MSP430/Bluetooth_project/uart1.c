//#include <msp430g2553.h>
#include <templateEMP.h>

/*
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
*/


int main(void)
{

	initMSP();
}
