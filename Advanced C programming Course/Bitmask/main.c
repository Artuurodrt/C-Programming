/* Bitmask
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how bitmasks are used.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int flags = 15; //    0000 1111
    int mask = 182; //    1011 0110

    flags = flags | mask; //1011 1111

    return 0;
}
