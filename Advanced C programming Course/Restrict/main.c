/* Restrict qualifier
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how the restrict qualifier is used.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void f1(int n, float *restrict a1, const float *restrict a2){
    int i;

    //Each iteration of this loop is independent from the others
    //And it can be progressively optimized
    for(i = 0; i < n; i++){
        a1[n] = a2[n];
    }

}



int main()
{
    int array[10];
    int *restrict restart = (int *) malloc(10*sizeof(int));
    int *par = array;

    for(int n = 0; n < 10; n++){
        par[n] += 5;
        restart[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restart[n] += 3;
        //an optimization of type restart[n] += 8; can be performed as it is restrict
    }
    return 0;
}
