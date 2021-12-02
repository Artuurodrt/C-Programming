/* extern variables
*
*  Created by Arturo de los Rios on 01/11/21.
*
* C code of how extern variables are used.
*/

#include <stdio.h>

int i = 5; //Global variable initialization
int count; //Global variable "count" declaration
void foo(void); //foo function Prototype

extern void write_extern();//extern function

int main (void)
{
    printf("%i\n",i);
    foo(); //Call to foo() function
    printf("%i\n",i);
    count = 5; //Count initialization
    write_extern();// call to extern function

    return 0;
}
