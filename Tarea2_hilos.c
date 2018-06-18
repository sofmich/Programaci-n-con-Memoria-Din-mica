/*
 ============================================================================
 Name        : Tarea2_hilos.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


typedef struct{
	unsigned int inicio;
	unsigned int fin;
	double sumaHilo;
}Hilo;
double sumaTotal(void *param, int cant_hilos);
DWORD WINAPI suma(void *param);
int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t inicio, fin;
	int hilos;
	double segundos=0, pi=0;
	printf("Hilos [1,2,4,8,16]?");
	scanf("%d",&hilos);
	while(hilos==1 || hilos== 2 || hilos== 4 || hilos== 8 ||hilos==16){


		if(hilos == 1){
			Hilo hilo={1,500000000,0};
			HANDLE h1 = NULL;
			inicio = clock();
			h1 = CreateThread(NULL,0,suma,(void*)&hilo,0,NULL);
			WaitForSingleObject(h1, INFINITE);
			pi= sumaTotal(&hilo,1);
			fin = clock();
		}
		if(hilos == 2){
			Hilo hilo[2]={{1,250000000,0},{250000001,500000000,0}};
			HANDLE h1=NULL, h2=NULL;
			inicio = clock();
			h1=CreateThread(NULL, 0, suma, (void *)&hilo[0], 0, NULL);
			h2=CreateThread(NULL, 0, suma, (void *)&hilo[1], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			pi= sumaTotal(hilo,2);
			fin = clock();
		}
		if(hilos == 4){
			Hilo hilo[4]={{1,125000000,0},{125000001,250000000,0},{250000001,275000000,0},{275000001,500000000}};
			//HANDLE h1=NULL, h2=NULL,h3=NULL, h4 = NULL;
			HANDLE h[4] = {};
			inicio = clock();
			int i;
			for(i=0; i<4; i++)h[i]=CreateThread(NULL, 0, suma, (void *)&hilo[i], 0, NULL);
			//h1=CreateThread(NULL, 0, suma, (void *)&hilo[0], 0, NULL);
			//h2=CreateThread(NULL, 0, suma, (void *)&hilo[1], 0, NULL);
			//h3=CreateThread(NULL, 0, suma, (void *)&hilo[2], 0, NULL);
			//h4=CreateThread(NULL, 0, suma, (void *)&hilo[3], 0, NULL);
			for(i=0; i<4; i++)WaitForSingleObject(h[i],INFINITE);
			//WaitForSingleObject(h1, INFINITE);
			//WaitForSingleObject(h2, INFINITE);
			//WaitForSingleObject(h3, INFINITE);
			//WaitForSingleObject(h4, INFINITE);
			pi= sumaTotal(hilo,4);
			fin = clock();

		}
		if(hilos == 8){
			Hilo hilo[8]={
					{1,100000000,0},{100000001,150000000,0},{150000001,200000000,0},{200000001,250000000,0},
					{250000001,300000000,0},{300000001,380000000,0},{380000001,400000000,0},{400000001,500000000,0}
			};
			HANDLE h[8] = {};
			inicio = clock();
			int i;
			for(i=0; i<8; i++) h[i] = CreateThread(NULL, 0, suma, (void *)&hilo[i], 0, NULL);
			for(i=0; i<8; i++) WaitForSingleObject(h[i],INFINITE);
			/*h1=CreateThread(NULL, 0, suma, (void *)&hilo[0], 0, NULL);
			h2=CreateThread(NULL, 0, suma, (void *)&hilo[1], 0, NULL);
			h3=CreateThread(NULL, 0, suma, (void *)&hilo[2], 0, NULL);
			h4=CreateThread(NULL, 0, suma, (void *)&hilo[3], 0, NULL);
			h5=CreateThread(NULL, 0, suma, (void *)&hilo[4], 0, NULL);
			h6=CreateThread(NULL, 0, suma, (void *)&hilo[5], 0, NULL);
			h7=CreateThread(NULL, 0, suma, (void *)&hilo[6], 0, NULL);
			h8=CreateThread(NULL, 0, suma, (void *)&hilo[7], 0, NULL);*/

			/*WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);*/
			pi= sumaTotal(hilo,8);
			fin = clock();
		}
		if(hilos == 16){
			Hilo hilo[16]={
					{1,50000000,0},{50000001,80000000,0},{80000001,100000000,0},{100000001,125000000,0},
					{125000001,180000000,0},{180000001,200000000,0},{200000001,230000000,0},{230000001,250000000,0},
					{250000001,290000000,0},{290000001,330000000,0},{330000001,355000000,0},{355000001,375000000,0},
					{375000001,400000000,0},{400000001,440000000,0},{440000001,475000000,0},{475000001,500000000,0}
			};
			HANDLE h[16] = {};
			inicio = clock();
			int i;
			for(i=0; i<16; i++) h[i] = CreateThread(NULL, 0, suma, (void *)&hilo[i], 0, NULL);
			for(i=0; i<16; i++) WaitForSingleObject(h[i],INFINITE);
			pi= sumaTotal(hilo,16);
			fin = clock();
		}
		segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;
		printf("\nValor de Pi: %.10g\n",pi);
		printf("Tiempo requerido: %g milisegundos\n\n", segundos*1000.0);
		segundos = 0;
		inicio = 0;
		fin = 0;
		pi = 0;
		hilos = 0;
		printf("Hilos [1,2,4,8,16]?");
		scanf("%d",&hilos);
	}
	return EXIT_SUCCESS;
}

DWORD WINAPI suma(void *param){
	Hilo *p = param;
	long i;
	for(i = p->inicio; i <= (p->fin) ; i++){
		if((i&1)==1){
			//Impar
			p->sumaHilo += (double)1/(2*i-1);
		}else{
			//Par
			p->sumaHilo -= (double)1/(2*i-1);
		}
	}
	return 0;
}
double sumaTotal(void *param, int cant_hilos){
	Hilo *p = (Hilo*) param;
	double pi = 0;
	int i;
	for (i=0; i < cant_hilos; i++){
		//printf("\nValor inicial de hilo %d: %u", i+1, (p+i)->inicio);
		pi += (p+i)->sumaHilo;
	}
	return 4*pi;
}




