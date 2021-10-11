/*	Author: Bryan Dang
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; //Configures port C
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char cntavail = 0x04;
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x0F;
		// 2) Perform computation
		if (tmpA == 0x00){ //TRUE IF PA is 0x00
			cntavail = 0x04; // sets avail count to 3
		} else if (tmpA == 0x01){ // True if PA0 is 0x00
			cntavail = 0x03; // sets avail count to 3
		} else if (tmpA == 0x02){
			cntavail = 0x03;
		} else if (tmpA == 0x03){
			cntavail = 0x02;
		} else if (tmpA == 0x04){
			cntavail = 0x03;
		} else if (tmpA == 0x05){
			cntavail = 0x02;
		} else if (tmpA == 0x06){
			cntavail = 0x02;
		} else if (tmpA == 0x07){
                        cntavail = 0x01;
                } else if (tmpA == 0x08){
                        cntavail = 0x03;
                } else if (tmpA == 0x09){
                        cntavail = 0x02;
                } else if (tmpA == 0x0A){
                        cntavail = 0x02;
                } else if (tmpA == 0x0B){
                        cntavail = 0x01;
                } else if (tmpA == 0x0C){
                        cntavail = 0x02;
                } else if (tmpA == 0x0D){
                        cntavail = 0x01;
                } else if (tmpA == 0x0E){
                        cntavail = 0x01;
                } else if (tmpA == 0x0F){
                        cntavail = 0x80;
                }
		// 3) Write output
		PORTC = cntavail;
	}
	return 0;
}
