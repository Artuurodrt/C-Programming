/* Stack
*
*  Created by Arturo de los Rios on 30/11/21.
*
* C code to explain how Stack-based memory is allocated.
*/


#include <stdio.h>
#include <stdlib.h>

double multiplyByTwo(double input){

    /*The variables "twice" is pushed onto the stack
    * as soon as the "multiplyByTwo" function allocates it */
    double twice = input * 2.0; //Local Variable
    /*When the "multiplyByTwo" function exits, the variable is
    * popped off the stack and gone forever*/
    return twice;
}


int main()
{
    /*The following three variables are pushed onto the stack
    * as the main function allocates them */
    int age = 30; //Local Variable
    double salary = 12345.67; //Local Variable
    double myList[3] = {1.2, 2.3, 3.4}; //Local Variable
    /*When the program stops, these variables are
    * popped off the stack*/


    printf("Double your salary is %.3f\n",multiplyByTwo(salary));
    return 0;
}
