/* Lesson 6
*
*  Created by Arturo de los Rios on 06/01/22.
*
* C program for functions in C and the call stack
*/

/*

c = a | b;   OR
c = a & b;   AND
c = a ^ b;   XOR 
c = ~a;      NOT
c = b >> 1;  Right-shift operation
c = b << 3;  Left-shift operation


*/

#include "tm4c123gh6pm.h"

#define LED_RED    (1u << 1)
#define LED_BLUE   (1u << 2)
#define LED_GREEN  (1u << 3)

void delay(int iter);


int main()
{
 
  SYSCTL_RCGCGPIO_R = 0x20u; /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  SYSCTL_GPIOHBCTL_R |= (1u << 5); //Enables Advanced High-Performance Bus (AHB)
  
  GPIO_PORTF_AHB_DIR_R = (LED_RED | LED_BLUE | LED_GREEN);/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIO_PORTF_AHB_DEN_R = (LED_RED | LED_BLUE | LED_GREEN); /*The digital functions for the pins 1,2,3 are enabled*/
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;/*TurnS ON BLUE LED*/
  
  
  while(1){
  
    
   /* The following three instructions are equivalent     
     *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
     *(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;*/
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED; /*TurnS ON RED LED*/
    delay(1000000);
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;/*TurnS OFF RED LED, this bitwise operation preserves the original GPIO PORTF bits*/
    delay(500000);
  }
 
  
  return 0;
}



void delay(int iter){

int volatile counter = 0; /*Prevents compiler optimizations*/
    counter = 0;
  
  while(counter < iter){
    counter++;
  }
}


