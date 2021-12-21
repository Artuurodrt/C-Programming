/* Bit Fields
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how bit fields are used.
*/
#include <stdio.h>
#include <stdlib.h>


struct packed_struct{

    unsigned int :3; //unused
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;

};

int main()
{
    struct packed_struct packed_data;
    packed_data.type = 7;
    unsigned int bit = packed_data.index; //extract the index fields from the pack data

    return 0;
}
