/* goto statement
*
*  Created by Arturo de los Rios on 20/12/21.
*
* C code of how the goto statement is used.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i = 0;
    double number, average, sum = 0.0;
    const int maxInput = 5;

    for(i = 1; i <= maxInput; i++){

        printf("%d. Enter a number:", i);
        scanf("%lf",&number);

        if(number < 0.0){
            goto jump;
        }
        sum += number;

    }
    jump:
    average = sum/(i-1);
    printf("sum = %.2f \n", sum);
    printf("Average = %.2f\n",average);


    return 0;
}
