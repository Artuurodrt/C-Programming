/* Designated Initializers
*
*  Created by Arturo de los Rios on 02/11/21.
*
* C code of how Designated Initializers are used.
*/

#include <stdio.h>
#include <stdlib.h>

struct point {int x,  y;};

struct point_2 {int x,  y, z;};


int main()
{
    //The following initialization syntax are valid
    //struct point p = {.y = 2, .x = 3};
    //struct point p = {y: 2, x: 3};
    //struct point p = {2, 3};

    struct point_2 pts[5] = {[2].y = 5, [2].x = 6, [0].x = 2};

    for(int i=0;i < 5;i++){
        printf("%d %d\n",pts[i].x, pts[i].y);
    }

    int numbers[100] = {1,2,3,[3 ... 9] = 10, [10] = 80, 15, [70] = 50, [42]=400}; //Initialization of specific index of the array

        for(int i=0;i < 20;i++){
        printf("%d ",numbers[i]);
    }





    return 0;
}
