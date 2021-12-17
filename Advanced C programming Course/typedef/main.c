#include <stdio.h>
#include <stdlib.h>

typedef int *i_pointer; //Alias of a pointer to an int


int main()
{

    i_pointer p; //same as int *p
    i_pointer a, *b; // same as int *a, **b
    i_pointer myArray[10]; //same as int *myArray[10]


    return 0;
}
