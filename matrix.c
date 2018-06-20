/*
 * matrix.c
 *
 *  Created on: 04/06/2018
 *      Author: ie714715
 */


#include <stdlib.h>
#include <stdio.h>
int CrearMatriz(int **apuntador, int n, int m);
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int **m; //matriz[3][2];
	int i,j;
	m = (int**)malloc(sizeof(int*)*3);
	for(i = 0; i<3; i++){
		m[i] = (int*)malloc(sizeof(int)*2);
	}
	for(i = 0; i<3; i++){
		for(j =0; j< 2; j++){
			m[i][j] = i+1;
		}
	}
	printf("Dirección de m0: %p, m1: %p, m2: %p",m, m++, m+=2); //Dirección de los renglones
	//printf("Dirección de m[0][0]: %p", *m);
	for(i = 0; i<3; i++){
		//printf("Dirección de m[%d]: %p",i, m[i]);
			for(j =0; j< 2; j++){
				printf("m[%d][%d]: %d\t", i, j, m[i][j]);
			}
			printf("\n");
		}
	//Acceder al contenido de la matriz a través de un apuntador
	//la matriz acumula direcciones: m almacena los renglones y m* almacena la direccion de las columnas

	return 0;
}
