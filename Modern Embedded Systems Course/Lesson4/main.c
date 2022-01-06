/* Lesson 4
*
*  Created by Arturo de los Rios on 04/01/22.
*
* C program to blink TM4C123G LED.
*/

#define RCGCGPIO (*((volatile  unsigned int*)0x400FE608u))

#define GPIODIR (*((volatile  unsigned int*)0x40025400u))

#define GPIODEN (*((volatile  unsigned int*)0x4002551Cu))

#define GPIODATA  (*((volatile  unsigned int*)0x400253FCu))  /*0x3FC ( 1111111100)*/

void delay();

int main()
{
 
  RCGCGPIO = 0x20u; /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  GPIODIR = 0x0Eu;/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIODEN = 0x0Eu; /*The digital functions for the pins 1,2,3 are enabled*/
  
  
  while(1){
  GPIODATA  = 0x02u;/*Turn ON LED*/
  delay();
  GPIODATA  = 0x00u;/*Turn OFF LED*/
  delay();
  }
 
  
  return 0;
}


  void delay(){
  
  int counter = 0;
  while(counter < 1000000){
    counter++;
  }
  
  }