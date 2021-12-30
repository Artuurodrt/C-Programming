/* Preprocesor Debug 1
*
*  Created by Arturo de los Rios on 30/12/21.
*
* C program of how to debug with preprocessor.
*
* NOTE: const is an idempotent qualifier
*/
#include <stdio.h>

#define DEBUG


int process (int i, int j, int k){
	return i+j+k;
}

int main(void){
	int i, j, k, nread;

	nread = scanf("%d %d %d", &i, &j, &k);

	#ifdef DEBUG
		fprintf(stderr, "Number of integer read = %i \n", nread);
		fprintf(stderr, "i = %i, j = %i, k = %i \n", i, j, k);
	#endif //DEBUG

	printf("%d\n", process(i,j,k));

return 0;

}
