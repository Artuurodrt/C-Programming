/* Lesson 13
*
*  Created by Arturo de los Rios on 09/01/22.
*
* C program related to startup code and CPU reset
*/


#include "tm4c123gh6pm.h"
#include "Delay.h"
#include "stdint.h"
#include "tm4c_cmsis.h"

#define LED_RED    (1u << 1)
#define LED_BLUE   (1u << 2)
#define LED_GREEN  (1u << 3)

int16_t x = -1;
uint32_t y = LED_RED | LED_GREEN;

int16_t sqr[] = {
    1*1,
    2*2,
    3*3,
    4*4
};

/* The __packed qualifier sets the alignment of any valid type to 1.
This means that:
  There is no padding inserted to align the packed object.
  Objects of packed type are read or written using unaligned accesses.

Without the "__packed" qualifier the sizeof(Point) would be 4 bytes instead of 3.
*/

typedef __packed struct{
  uint8_t y; /*1 byte*/
  uint16_t x; /*2 bytes*/
}Point;

Point p1, p2;

Point p1 = {
    123U,
    0x1234U
};
Point p2;


typedef struct{
  Point top_left;
  Point bottom_right;

}Window;


Window w = {
    { 123U, 0x1234U },
    { 234U, 0x6789U }
};

typedef struct{
    Point corners[3];
}Triangle;


/*Variables of struct types are called instances.
 w is an instance of Window and t is an instance of Triangle*/
Window w, w2;
Triangle t;




int main() {
  
  Point *pp; /*Pointers to structure*/
  Window *wp;
  
  p1.x = sizeof(Point);
  p1.y = 0xAAu;
  
  w.top_left.x = 1u;
  w.bottom_right.y = 2u;
  
  t.corners[0].x = 1u;
  t.corners[2].y = 2u;
    
  p2 = p1;
  w2 = w;
  
  pp = &p1;
  wp = &w2;
  
  
  /*How to access members of a structure using pointers?*/
  
  /*First way*/
  
  (*pp).x = 1u;
  (*wp).top_left = *pp;
  
  /*Second way*/
  
  pp->x = 1u;
  wp->top_left = *pp;
  
    
  SYSCTL->RCGC2 |= (1U << 5); /*Enable and provide a clock to GPIO Port F in Run mode*/
  
  SYSCTL->GPIOHSCTL |= (1U << 5); //Enables Advanced High-Performance Bus (AHB)
  
  GPIOF_HS->DIR |= (LED_RED | LED_BLUE | LED_GREEN);/*configures the GPIO Port F pins 1,2,3 to be an output,*/
  
  GPIOF_HS->DEN |= (LED_RED | LED_BLUE | LED_GREEN); /*The digital functions for the pins 1,2,3 are enabled*/
  
  GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;/*TurnS ON BLUE LED*/
  
  
  while(1){
  
    
   /* The following three instructions are equivalent     
     *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
     *(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;*/
    GPIOF_HS->DATA_Bits[LED_RED] = LED_RED; /*TurnS ON RED LED*/
    delay(1000000);
    GPIOF_HS->DATA_Bits[LED_RED] = 0;/*TurnS OFF RED LED, this bitwise operation preserves the original GPIO PORTF bits*/
    delay(500000);
  }
 
  
  //return 0;
}



