/*
 ============================================================================
 Name        : hilos_suma.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int inicio;
	int fin;
	unsigned long sumaParcial;
}Rango;

DWORD WINAPI suma(void *param);

int main(void) {
	Rango rango[2]={{0,10000,0},{10001,20000,0}};

	HANDLE h1=NULL, h2=NULL;

	h1=CreateThread(NULL, 0, suma, (void *)&rango[0], 0, NULL);
	h2=CreateThread(NULL, 0, suma, (void *)&rango[1], 0, NULL);

	WaitForSingleObject(h1, INFINITE);
	WaitForSingleObject(h2, INFINITE);

	printf("Sumatoria del rango 1: %lu \n", rango[0].sumaParcial);
	printf("Sumatoria del rango 2: %lu \n", rango[1].sumaParcial);

	return 0;
}

DWORD WINAPI suma(void *param){
	Rango *r=(Rango*)param;
	int i;
	for(i=r->inicio;i<=r->fin;i++)
		r->sumaParcial+=i;
	return 0;
}
