/* Recursion
*
*  Created by Arturo de los Rios on 23/12/21.
*
* C code of how recursion is used.
*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int n){

    int result = 0;

    if(n == 0){
        result = 1;
    }
    else{
        result = n*factorial(n-1);
    }
    return result;

}

//Each level of recursion uses its own private variables
void up_and_down(int n){

    printf("Level %d: n location %p\n", n, &n);

    if(n < 4){
        up_and_down(n+1);
    }
    printf("LEVEL:%d n location %p\n",n,&n);

}


int main()
{
    int i;

    for(i = 0;i < 8;i++){
        printf("%d! = %d\n",i,factorial(i));
    }

    up_and_down(1);



    return 0;
}
