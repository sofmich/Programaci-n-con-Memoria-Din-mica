/*
 * arreglosdinamicos.c
 *
 *  Created on: 04/06/2018
 *      Author: ie714715
 */


#include <stdlib.h>
#include <stdio.h>
#define max 10000000000000000
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int *pointer[]={};
	int n = 1, i=0;
	for(i=0; i < max ; i++){
		pointer[i] = (int * )malloc(max*sizeof(int));
		if(pointer[i] == NULL) printf("No existe espacio en memoria disponible");
		else printf("Espacio en memoria disponible");
	}




	return 0;
}
