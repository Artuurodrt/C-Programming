/* setjmp and longjmp
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how setjmp and longjmp are used.
*/
#include <stdio.h>
#include <stdlib.h>"
#include <setjmp.h>

jmp_buf buf;

void myFunction(){
    printf("in myFunction()\n");
    longjmp(buf, 1);
    /*NOT REACHED*/
    printf("Not reachable\n");

}


int main()
{
    /* //FIRST EXAMPLE
    int i = setjmp(buf);
    printf("i=%d\n",i);

    if(i!= 0) exit(0);

    longjmp(buf, 42);
    printf("Does this line get printed?\n");
    */
    if(setjmp(buf)){
        printf("Back in main\n");
    }
    else{
        printf("first time through\n");
        myFunction();
    }


    return 0;

}
