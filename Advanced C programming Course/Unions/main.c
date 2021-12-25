/* Unions
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how unions are used.
*/
#include <stdio.h>
#include <stdlib.h>

//-----------------------Example 1-------------------------------
union car{
    int i_value;
    float f_value;
    char c_value[40];
}car1, car2, car3;

//-----------------------Example 2-------------------------------
struct owner {
    char socsecurity[12];
};

struct leasecompany{
    char name[40];
    char headquearters[40];
};

struct car_data{

    char make[15];
    int status;
    //Anonymous Union
    union{
        struct owner owncar;
        struct leasecompany;
    };
};

//-----------------------Example 3-------------------------------

struct{

    char *name;
    enum symbolType type;
    union{
        int i;
        float f;
        char c;
    }data;
} table;

int main()
{

    union car car1, car2, *car3;

    printf("Size of union: %zu bytes\n", sizeof(car1));
    return 0;
}
