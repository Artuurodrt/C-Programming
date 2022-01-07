/* Lesson 9
*
*  Created by Arturo de los Rios on 06/01/22.
*
* C program related to modules, recursion and ARM
  Application procedure Call Standards (AAPCS)
*/


#include "tm4c123gh6pm.h"
#include "Delay.h"

#define LED_RED    (1u << 1)
#define LED_BLUE   (1u << 2)
#define LED_GREEN  (1u << 3)


unsigned fact(unsigned n);

int main()
{
 
  unsigned volatile x;
  
  x = fact(0u);
  x = 2u + 3u*fact(1u);
  (void)fact(5U);
  
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


unsigned fact(unsigned n){
/* 0! = 1
   n! = n*(n-1)! for n > 0
*/
    
  if(n == 0u){
    return 1u;
  }
  else{
  return n*fact(n - 1u);
  }
  
}

