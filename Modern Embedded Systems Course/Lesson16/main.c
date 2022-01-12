/* Lesson 16
*
*  Created by Arturo de los Rios on 11/01/22.
*
* C program related to interrupts and how they work
*/

#include "bsp.h"
#include "stdint.h"
#include <intrinsics.h>
#include "tm4c_cmsis.h"



int main() {
  
  SYSCTL->RCGC2 |= (1U << 5); /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  SYSCTL->GPIOHSCTL |= (1U << 5); //Enables Advanced High-Performance Bus (AHB)
  
  GPIOF_HS->DIR |= (LED_RED | LED_BLUE | LED_GREEN);/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIOF_HS->DEN |= (LED_RED | LED_BLUE | LED_GREEN); /*The digital functions for the pins 1,2,3 are enabled*/
    
 
  /*This value does not overflow the dynamic range of the counter (24 bits)*/
  SysTick->LOAD = SYS_CLOCK_HZ/2u -1u; /*Value to load into the SysTick Current Value (STCURRENT) register 
                                        when the counter reaches 0.*/
    
  SysTick->VAL = 0u;
    
  /*1. Enables SysTick to operate in a multi-shot way.
    2. An interrupt is generated to the NVIC when SysTick counts to 0
    3. Clock Source: System clock*/  
  SysTick->CTRL = (1u << 2) | (1u << 1) | 1u;

  
  __enable_interrupt();
  
  while(1){
 
  }
 
  
  //return 0;
}



