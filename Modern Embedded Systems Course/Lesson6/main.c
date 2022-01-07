/* Lesson 6
*
*  Created by Arturo de los Rios on 06/01/22.
*
* C program to activate the TM4C123G RGB LEDs.
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


int main()
{
 
  SYSCTL_RCGCGPIO_R = 0x20u; /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  GPIO_PORTF_DIR_R = (LED_RED | LED_BLUE | LED_GREEN);/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIO_PORTF_DEN_R = (LED_RED | LED_BLUE | LED_GREEN); /*The digital functions for the pins 1,2,3 are enabled*/
  
  GPIO_PORTF_DATA_R  = LED_BLUE;/*Turn BLUE LED*/
  
  
  while(1){
  GPIO_PORTF_DATA_R  |= LED_RED;/*Turn ON RED LED*/
  
  int volatile counter = 0; /*Prevents compiler optimizations
    
    If counter is declared as non-volatile, the compiler high optimization ignores the while loop
    and LED seems to be always ON*/
  
  while(counter < 1000000){
    counter++;
  }
  
  GPIO_PORTF_DATA_R  &= ~LED_RED;/*Turn OFF RED LED, this bitwise operation preserves the original GPIO PORTF bits*/
  counter = 0;
  while(counter < 1000000){
    counter++;
  }
  }
 
  
  return 0;
}


