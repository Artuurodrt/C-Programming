/* Variable Length Array
*
*  Created by Arturo de los Rios on 16/12/21.
*
* C code of how variable length arrays are implemented
*/
#include <stdio.h>
#include <stdlib.h>


//second variable array implementation
void var_array2(int size){

    char alpha[size];
    int x = 0;

    //until x
    while (x < size){

        alpha[x] = 'A' + x;
        printf("alpha: %c\n", alpha[x]);
        x++;
    }
}


int main()
{
//---------------------------------------FIRST IMPLEMENTATION-----------------------------------------------------


    size_t size = 0; //base unsigned integer type and it is the type of the result returned by sizeof operator
    printf("Enter the number of elements you want to store:\n");
    scanf("%zd",&size);//%zd conversion instructions to match the return type of sizeof (ie, size_t type)

    int values[size];

    //store values in the array of variable size
    for(int i = 0;i < size; i++){
        values[i] = i;
        printf("Array: %d\n",values[i]);
    }


//---------------------------------------SECOND IMPLEMENTATION-----------------------------------------------------
    var_array2(5);
    var_array2(3);
    var_array2(2);

    return 0;
}
