/* Flexible Array Members
*
*  Created by Arturo de los Rios on 17/12/21.
*
* C code of memory allocation for Flexible Array Members.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct s{
    int arraySize,
    int array[]
};


int main()
{
    int desired_Size = 5;
    struct s *ptr;

    ptr = sizeof(struct s) + desired_Size * sizeof(int);

    return 0;
}
