/*
 ============================================================================
 Name        : Tarea2.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//double Pi(long long limit);
int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t inicio, fin;

	double segundos;
	double miPi = 0;
	long long i, limit = 500000000;
	printf("Comenzando\n");
	inicio = clock();


	for(i=1; i <= limit ; i++){
		if((i&1)==1){
			//Imar
			miPi += (double)1/(2*i-1);
		}else{
			//Par
			miPi -= (double)1/(2*i-1);
		}
	}
	miPi = 4*miPi;
	fin = clock();
	printf("Valor de Pi: %.10g\n", miPi);
	segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;
	printf("Tiempo requerido: %g milisegundos", segundos*1000.0);
	return EXIT_SUCCESS;
}
/*double Pi(long long limit){
	double pi = 0;
	long long  i;
	for(i=1; i < limit ; i++){
		if((i&1)==1){
			//Imar
			pi += (double)1/(2*i-1);
		}else{
			//Par
			pi -= (double)1/(2*i-1);
		}
	}
	return 4*pi;
}*/
