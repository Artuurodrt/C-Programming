/* Heap
*
*  Created by Arturo de los Rios on 30/11/21.
*
* C code to explain how Heap-based memory is allocated.
*/

#include <stdio.h>
#include <stdlib.h>

 double *multiplyByTwo(double *input){

     /*By using the malloc() instruction, we are
     * allocating memory on the heap*/
    double *twice = malloc(sizeof(double));
    *twice = *input * 2.0;
    return twice;
 }


int main()
{

    /*NOTE: The malloc(), calloc and free instruction, are only
     * intented to deal with pointers*/
    int *age = malloc(sizeof(int));
    *age = 30;
    double *salary = malloc(sizeof(double));
    *salary = 12345.67;
    double *myList = malloc(3 * sizeof(double)); //Allocation on the heap of three times the size of a double data type
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;

    double *twiceSalary = multiplyByTwo(salary);

    printf("Double of your salary %.3f\n",*twiceSalary);

     /*The free() instruction deallocates memory on the heap*/
    free(age);
    free(salary);
    free(myList);
    free(twiceSalary);

    return 0;
}
