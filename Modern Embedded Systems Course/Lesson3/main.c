/* Lesson 3
*
*  Created by Arturo de los Rios on 04/01/22.
*
* C code related to variables and pointers.
*/

// global variable "count" will be stored within the Random Access Memory
 int count = 0;

int main()
{
 
    int *p_int; //Pointer that can hold addresses of integer variables
    p_int = &count;
  
/*see the control flow and assembly instructions with debugger */
  

  /*same as while(count < 21)*/
    
  while(*p_int < 21){
    ++(*p_int); /*same as ++count*/
  }
  
  /*NOTE: Introduction of the pointer has simplified the
  machine code and improved its efficiency as it
  reduced the assembly instrucctions*/
  

  return 0;
}
