/* Preprocesor Debug 3
*
*  Created by Arturo de los Rios on 30/12/21.
*
* C program of how to debug with preprocessor.
*
* NOTE: const is an idempotent qualifier
*/
#include <stdio.h>

#define DEBUG(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)

int process (int i, int j){
	int val  = 0;

	#ifdef DEBUG
		DEBUG("process(%d, %d)\n",i,j);
	#endif //DEBUG

	val = i *j;

	#ifdef DEBUG
		DEBUG("return %d\n",val);
	#endif //DEBUG

	return val;
}

int main(int argc, char *argv[]){

	int arg1 = 0, arg2 = 0;

	if( argc > 1){
		arg1 = atoi(argv[1]);
	}
	if( argc == 3){
		arg2 = atoi(argv[2]);
	}

	#ifdef DEBUG
		DEBUG("Processed %d arguments\n",argc -1);
		DEBUG("arg1 = %d, arg3 = %d \n",arg1, arg2);
	#endif //DEBUG

	printf("%i\n", process(arg1, arg2));


return 0;

}
