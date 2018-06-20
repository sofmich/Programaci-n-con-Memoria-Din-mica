/*
 * hilos.c
 *
 *  Created on: 29/05/2018
 *      Author: ie714715
 *
 *      Tema: Uso de hilos en c / generación de más de un ciclo de ejecución
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>  	//biblioteca para creación de hilos en windows (forma estática)
//process.h trabaja una segunda forma para la creación de hilos
typedef struct{
	int x,y;	//Hay dos datos que serán mandados al hilo
} param;
DWORD WINAPI funcionInicial(void*);
int main () {
	HANDLE h;
	param datos = {4,2};
	h = CreateThread(
	NULL, //seguridad por default
	0, //tamaño se stack por default
	funcionInicial, //dirección de la función
	(void *)&datos, //apuntador a los datos de la estructura con el apuntador de los paramétros de la función de arranque
	0, //flag de creación dword ejecuta de forma inmediata la función cuando se crea el hilo
	NULL //id del trhead por default
	);
	WaitForSingleObject(h, INFINITE); //Señala una paua hasta que el hilo señalado por esta función sea ejecutado
	printf("Final de ejecuciones: final de hilos");

	return 0;
}

DWORD WINAPI funcionInicial(void*p){ //al querer enviar más de un parámetro al hilo utilizar estructuras, solo se permite un apuntador void
	param *d = (param *)p;
	printf("Valor de X: %d \nValor de Y: %d", d->x, d->y);
	printf("\nFin del hilo");
	return 0;
}
