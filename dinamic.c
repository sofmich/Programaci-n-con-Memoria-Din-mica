/*
 * dinamic.c
 *
 *  Created on: 30/05/2018
 *      Author: ie714715
 */
#include <stdlib.h>
#include <stdio.h>
int main(){
	int *ptr = NULL;
	int i;
	for (i =0; i<=10; i++){
		ptr = (int *)malloc(64*sizeof(int));
		(ptr)[10] = 5000;
		printf("Dirección %d: %p\t",i+1, ptr);
		printf("Valor en la posición 10: %d\n", ptr[10]);
	}
	return 0;
}

