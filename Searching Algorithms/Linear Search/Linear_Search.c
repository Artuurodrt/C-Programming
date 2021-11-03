//  Linear_Search Algorithm
//
//  Created by Arturo de los Rios on 02/11/21.

// C code to linearly search x in array[]. 
// If "a" is present then return its location, otherwise return -1
 
#include <stdio.h>

int search(int array[], int n, int a){

for (int i = 0; i < n; i++)
{
    if(array[i] == a){
        return i;
    }
}
    return -1;
}


int main(void){

    int array[] = { 1, 2, 4, 10, 50 }; /* Input */
    int a = 2; /* element to search */
    int result = 0; 
    int n = sizeof(array) / sizeof(array[0]);

    result = search(array, n, a);
    (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);

return 0;
}
