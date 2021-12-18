/* Complex Numbers
*
*  Created by Arturo de los Rios on 17/12/21.
*
* C code of complex numbers operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXT1__ 1



int main()
{
#ifdef __STCD_NO_COMPLEX__
    printf("Complex Numbers are not supported!\n");
    exit(1);

#else
    printf("Complex Numbers are supported!\n");

    double complex cx = 1.0 + 3.0*I;
    double complex cy = 1.0 - 4.0*I;

    printf("Starting values: cx = %.2f%+.2fi  cy=%.2f%+.2fi\n", creal(cx),cimag(cx),creal(cy),cimag(cy));

    double complex sum = cx + cy;
    printf("sum = %.2f%+.2fi\n", creal(sum),cimag(sum));

    double complex dif = cx - cy;
    printf("dif = %.2f%+.2fi\n", creal(dif),cimag(dif));

    double complex mul = cx * cy;
    printf("mul = %.2f%+.2fi\n", creal(mul),cimag(mul));

    double complex div = cx / cy;
    printf("div = %.2f%+.2fi\n", creal(div),cimag(div));

    double complex conjugate_cx =conj(cx);
    printf("Conjugate of cx = %.2f%+.2fi\n", creal(conjugate_cx),cimag(conjugate_cx));


#endif // __STCD_NO_COMPLEX__


    return 0;
}
