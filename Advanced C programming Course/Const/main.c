/* Const keyword
*
*  Created by Arturo de los Rios on 19/12/21.
*
* C code of how the const keyword is used.
*
* NOTE: const is an idempotent qualifier
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const PI = 3.1416; //Constant value (never changes its value)

    const float *pf; //pf points to a constant float value

    float * const pt; //pt is a const pointer

    const float * const ptr;

    float const *pcf; //same as const float *pcf;

    return 0;
}
