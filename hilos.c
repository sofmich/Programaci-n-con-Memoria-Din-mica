/*
 * hilos.c
 *
 *  Created on: 29/05/2018
 *      Author: ie714715
 *
 *      Tema: Uso de hilos en c / generaci�n de m�s de un ciclo de ejecuci�n
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>  	//biblioteca para creaci�n de hilos en windows (forma est�tica)
//process.h trabaja una segunda forma para la creaci�n de hilos
typedef struct{
	int x,y;	//Hay dos datos que ser�n mandados al hilo
} param;
DWORD WINAPI funcionInicial(void*);
int main () {
	HANDLE h;
	param datos = {4,2};
	h = CreateThread(
	NULL, //seguridad por default
	0, //tama�o se stack por default
	funcionInicial, //direcci�n de la funci�n
	(void *)&datos, //apuntador a los datos de la estructura con el apuntador de los param�tros de la funci�n de arranque
	0, //flag de creaci�n dword ejecuta de forma inmediata la funci�n cuando se crea el hilo
	NULL //id del trhead por default
	);
	WaitForSingleObject(h, INFINITE); //Se�ala una paua hasta que el hilo se�alado por esta funci�n sea ejecutado
	printf("Final de ejecuciones: final de hilos");

	return 0;
}

DWORD WINAPI funcionInicial(void*p){ //al querer enviar m�s de un par�metro al hilo utilizar estructuras, solo se permite un apuntador void
	param *d = (param *)p;
	printf("Valor de X: %d \nValor de Y: %d", d->x, d->y);
	printf("\nFin del hilo");
	return 0;
}
