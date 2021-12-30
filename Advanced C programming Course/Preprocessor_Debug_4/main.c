/* Preprocesor Debug 4
*
*  Created by Arturo de los Rios on 30/12/21.
*
* C program of how to debug with preprocessor.
*
* NOTE: const is an idempotent qualifier
*/
//gcc -D DEBON main.c
//a.exe 1 5 10

#include <stdio.h>

int Debug = 0;

#ifdef DEBON
#define DEBUG(level, fmt, …)  \
	if(Debug >= level ) \
		fprintf(stderr, fmt, _VA_ARGS_)
#else
	#define DEBUG(level, fmt, ...)
#endif

int process (int i, int j){
	int val  = 0;

	#ifdef DEBUG
		DEBUG(1, "process(%d, %d)\n",i,j);
	#endif //DEBUG

	val = i *j;

	#ifdef DEBUG
		DEBUG(3, "return %d\n",val);
	#endif //DEBUG

	return val;
}

int main(int argc, char *argv[]){

	int arg1 = 0, arg2 = 0;

	if( argc > 2){
		Debug = atoi(argv[1]);
		arg1 = atoi(argv[2]);
	}
	if( argc == 4){
		arg2 = atoi(argv[3]);
	}

	#ifdef DEBUG
		DEBUG(2, "Processed %d arguments\n",argc -1);
		DEBUG(3, "arg1 = %d, arg3 = %d \n",arg1, arg2);
	#endif //DEBUG

	printf("%i\n", process(arg1, arg2));


return 0;
}
