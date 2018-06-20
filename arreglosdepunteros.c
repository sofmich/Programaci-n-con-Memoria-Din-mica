/*
 * arreglosdepunteros.c
 *
 *  Created on: 24/05/2018
 *      Author: ie714715
 */


#include <stdlib.h>
#include <stdio.h>
#define max 10
void incrementarParr(int *parr[], int tam);
void imprimirParr(int *parr[], int tam);

int main(){
	int arr[max] = {1,2,3,4,NULL};
	int *parr[] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};
	int tam = 5;
	printf("Valores del arreglo de punteros original: ");
	imprimirParr(parr,tam);
	incrementarParr(parr,tam);
	printf("\nValores del arreglo de punteros incrementado en 1: ");
	imprimirParr(parr,tam);

	return 0;
}

void imprimirParr(int *parr[], int tam){
	int i;
	for(i = 0; i < tam ; i++){
			printf("\nDirección %i : %d",i, *parr[i]);
			printf("\tDirección: %p", parr[i]);
			if(*parr[i] == NULL) {
				printf("\tEl contenido de la dirección es nulo");
			}


	}
}
void incrementarParr(int *parr[], int tam){
	int i;
	for(i = 0; i < tam ; i++){
		if(*parr[i] != NULL) *parr[i] += 1;
	}
}
