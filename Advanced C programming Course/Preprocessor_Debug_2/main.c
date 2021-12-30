/* Preprocesor Debug 2
*
*  Created by Arturo de los Rios on 30/12/21.
*
* C program of how to debug with preprocessor.
*
* NOTE: const is an idempotent qualifier
*/
// gcc -D DEBUG main.c
// a.exe 5 10
#include <stdio.h>

int process (int i, int j){
	int val  = 0;

	#ifdef DEBUG
		fprintf(stderr, "process(%d, %d)\n",i,j);
	#endif //DEBUG

	val = i *j;

	#ifdef DEBUG
		fprintf(stderr, "return %d\n",val);
	#endif //DEBUG

	return val;
}

int main(int argc, char *argv[]){

	int arg1 = 0, arg2 = 0;

	if( argc > 1){
		arg1 = atoi(argv[1]);
	}
	if( argc > 1){
		arg2 = atoi(argv[2]);
	}

	#ifdef DEBUG
		fprintf(stderr, "Processed %d arguments\n",argc -1);
		fprintf(stderr, "arg1 = %d, arg3 = %d \n",arg1, arg2);
	#endif //DEBUG

	printf("%i\n", process(arg1, arg2));


return 0;

}
