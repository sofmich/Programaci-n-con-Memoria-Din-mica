/*
 * dinamic.c
 *
 *  Created on: 30/05/2018
 *      Author: ie714715
 */
#include <stdlib.h>
#include <stdio.h>
int main(){
	int n;
	int i;
	printf("Size: ");
	scanf("%d", &n);
	int *p ;
	p=(int*)malloc(n*sizeof(int)); //el valor a almacenar se guarda en el heap
	printf("Values: \n");

	for (i =0; i<n; i++) scanf("%d", &(*(p+i)));
	printf("Values: \n");
	for (i =0; i<n; i++) printf("%d\t", p[i]);
	free(p); //libera el espacio en el heap
	return 0;
}

