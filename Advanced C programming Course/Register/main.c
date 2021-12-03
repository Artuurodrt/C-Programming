/* Register
*
*  Created by Arturo de los Rios on 12/02/21.
*
* C code of how register variables are used .
*/
#include <stdio.h>
#include <stdlib.h>

/*Note: register can only be used within a local block,
 * it can't be used in global scope*/
int main()
{
    register int x; //register variable (counter)
    int y = 15;
    register int *z = &y;//"z" pointer is going to store "y" address into a register

    printf("%d\n\n", *z);

    for(x = 1; x <= 15; x++){
        printf("%d\n", x);
    }
    return 0;
}
