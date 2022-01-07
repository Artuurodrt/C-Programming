/* Lesson 11
*
*  Created by Arturo de los Rios on 06/01/22.
*
* C program related to standard data types
*/


#include "tm4c123gh6pm.h"
#include "Delay.h"
#include "stdint.h"

#define LED_RED    (1u << 1)
#define LED_BLUE   (1u << 2)
#define LED_GREEN  (1u << 3)

uint8_t  u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int8_t  s8;
int16_t s16;
int32_t s32;

int main() {
  
    u8a  = sizeof(u8a);
    u16c = sizeof(uint16_t);
    u32e = sizeof(uint32_t);
    
    u8a  = 0xa1U;
    u16c = 0xc1c2U;
    u32e = 0xe1e2e3e4U;
    
    u8b  = u8a;
    u16d = u16c;
    u32f = u32e;

    u16c = 40000U;
    u16d = 30000U;
    //u32e = u16c + u16d; // NOT portable!
    u32e = (uint32_t)u16c + u16d;
    
    u16c = 100U;
    //s32  = 10 - u16c;  // NOT portable!
    s32  = 10 - (int16_t)u16c;
    
    //if (u32e > -1) {  // ALWAYS false!
    if ((int32_t)u32e > -1) {
        u8a = 1U;
    }
    else {
        u8a = 0U;
    }
    
    u8a = 0xffU;
    //if (~u8a == 0x00U) { // ALWAYS false!
    if ((uint8_t)(~u8a) == 0x00U) {
        u8b = 1U;
    }    
    
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



