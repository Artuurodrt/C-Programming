/* Lesson 5
*
*  Created by Arturo de los Rios on 04/01/22.
*
* C program to blink TM4C123G LED.
*/

#define GPIOF_BASE 0x40025000u

#define RCGCGPIO (*((volatile  unsigned int*)0x400FE608u))

#define GPIODIR (*((volatile  unsigned int*)(GPIOF_BASE + 0x400u)))

#define GPIODEN (*((volatile  unsigned int*)(GPIOF_BASE + 0x51Cu)))

#define GPIODATA  (*((volatile  unsigned int*)(GPIOF_BASE + 0x3FCu)))  /*0x3FC ( 1111111100)*/


int main()
{
 
  RCGCGPIO = 0x20u; /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  GPIODIR = 0x0Eu;/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIODEN = 0x0Eu; /*The digital functions for the pins 1,2,3 are enabled*/
  
  
  while(1){
  GPIODATA  = 0x02u;/*Turn ON LED*/
  
  int volatile counter = 0; /*Prevents compiler optimizations
    
    If counter is declared as non-volatile, the compiler high optimization ignores the while loop
    and LED seems to be always ON*/
  
  while(counter < 1000000){
    counter++;
  }
  
  GPIODATA  = 0x00u;/*Turn OFF LED*/
  counter = 0;
  while(counter < 1000000){
    counter++;
  }
  }
 
  
  return 0;
}


