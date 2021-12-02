/* Static variables
*
*  Created by Arturo de los Rios on 02/11/21.
*
* C code of how static variables are used.
*/

#include <stdio.h>
#include <stdlib.h>

/*Note: Static variables are allocated memory
 *on the heap, not on the stack*/

 /*Note: Functions are by default extern*/

int fun(){

    /* count static variable is not re-initialized each time
    * fun() is called, it retains the count value*/
    static int count = 0; //static variable definition
    int localvar = 0; //automatic variable

    /*Comparison between an auto and a static variable*/
    printf("automatic: %d,  static: %d\n",localvar,count);


    count++; //count + 1
    localvar++; //localvar + 1
    return count;
}


int main()
{
    for(int i = 0; i < 5 ; i++){
        fun(); //Calls fun() five times
    }
    return 0;
}
