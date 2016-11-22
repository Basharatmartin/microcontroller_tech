/*
	Date   : 04.11.2016
	Boniface Bassey
*/


#include  <msp430.h>
#include "templateEMP.h"

#define RED_rt   BIT4                
#define BLUE_rt BIT5                 

unsigned int red_count = 0;
unsigned int blue_count = 0;
char LED_on[10] = "LED: ON"; 
char LED_off[10] = "LED: OFF";


void delay_ms(){
    __delay_cycles(1000);
    red_count++;
    blue_count++;
}


int main(void){
    initMSP();

    P1SEL &= ~(RED_rt + BLUE_rt);     
    P1DIR |= RED_rt + BLUE_rt;        
    P1OUT &= ~(RED_rt + BLUE_rt);     
    while(1) {                        
        delay_ms();
        if (red_count == 500){        
	    P1OUT ^= RED_rt;          
	    red_count = 0;            
        }
        if (blue_count == 1000){      
	    P1OUT ^= BLUE_rt;         
	    blue_count = 0;           
        }

	//serialPrintInt(P1IN & BIT5);
	if (serialRead() != -1)
	{
	    serialPrint(" ::: ");		
	    if(P1IN & BIT5)
		serialPrint(LED_on);
	    else
		serialPrint(LED_off);
	}
    }
}



