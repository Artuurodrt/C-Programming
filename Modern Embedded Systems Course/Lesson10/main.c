/* Lesson 10
*
*  Created by Arturo de los Rios on 06/01/22.
*
* C program related to stack overflow and other pitfalls of functions
*/


#include "tm4c123gh6pm.h"
#include "Delay.h"

#define LED_RED    (1u << 1)
#define LED_BLUE   (1u << 2)
#define LED_GREEN  (1u << 3)

unsigned fact(unsigned n);
void swap(int *x, int *y);


int main()
{
 
  unsigned volatile x;
  
  x = fact(0u);
  x = 2u + 3u*fact(1u);
  (void)fact(7u);
  
  int a = 1;
  int b = 2;
  swap(&a, &b);
  
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
 
  
  //return 0;
}

void swap(int *x, int *y){

int tmp = *x;
    *x = *y;
    *y = tmp;

}


unsigned fact(unsigned n){
/* 0! = 1
   n! = n*(n-1)! for n > 0
*/
    
 /*unsigned foo[100]; after 5 calls this code overflows the stack*/
  unsigned foo[6] ; //Will over pass the size of the array
  foo[n] = n;
  if(n == 0u){
    return 1u;
  }
  else{
  /*return foo[n]*fact(n - 1u); after 5 calls this code overflows the stack*/
  return foo[n]*fact(n - 1u);
  }
  
}

