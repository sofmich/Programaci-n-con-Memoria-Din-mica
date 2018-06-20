/*
 * introduccion_md.c
 *
 *  Created on: 30/05/2018
 *      Author: ie714715
 *      -las variables est�ticas y globales inicializadas en cero se consideran como no inicializadas
 *
 *
 */
#include <stdlib.h> //funciones que permiten trabajar con memoria din�mica est�n incluidas en stdlib
/*
 *	malloc retorna una direcci�n de memoria de los bytes disponibles que buscas
 *	type * pointer = (bytes_num);
 *
 * 	calloc(n�m_elementos, tam_elementos); permite hacer lo mismo que malloc pero inicializando en cero
 * 	realloc(apuntador, direcci�n); hace lo mismo pero permite redimensionar ej. de X cant de bytes a Y cant de bytes
 * 	free(); liberar memoria; al dejar de utilizar la memoria es necesario liberarla -- La memoria din�mica no libera de forma autom�tica
 *
 * */
#include <stdio.h>
int main(){
	int arreglo[5]; //memoria est�tica: enteros consecutivos
	int *p_ad = malloc(5*sizeof(int)); //dependiendo de la estructura de la computadora el n�mero de bytes ocupados variar�, sizeof retornar� el valor aunque haya variedad en cada tama�o de procesador
	printf("%p\n", p_ad);
	p_ad = (int *)p_ad;	//El cast es importante para especificar el tipo de dato que se tomar� para la memoria que malloc est� buscando
	printf("%p", p_ad);
	return 0;
}
int function(){
	static int count = 0; //var que se considera no inicializada
	count ++;
	return count; //var que guarda/conserva su valor
}
//La declaraci�n de un apuntador est� en el stack. Una funci�n que recibe un apuntador maneja distintos apuntadores, s�lo que uno copia el apuntador de otra.

