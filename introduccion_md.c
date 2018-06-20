/*
 * introduccion_md.c
 *
 *  Created on: 30/05/2018
 *      Author: ie714715
 *      -las variables estáticas y globales inicializadas en cero se consideran como no inicializadas
 *
 *
 */
#include <stdlib.h> //funciones que permiten trabajar con memoria dinámica están incluidas en stdlib
/*
 *	malloc retorna una dirección de memoria de los bytes disponibles que buscas
 *	type * pointer = (bytes_num);
 *
 * 	calloc(núm_elementos, tam_elementos); permite hacer lo mismo que malloc pero inicializando en cero
 * 	realloc(apuntador, dirección); hace lo mismo pero permite redimensionar ej. de X cant de bytes a Y cant de bytes
 * 	free(); liberar memoria; al dejar de utilizar la memoria es necesario liberarla -- La memoria dinámica no libera de forma automática
 *
 * */
#include <stdio.h>
int main(){
	int arreglo[5]; //memoria estática: enteros consecutivos
	int *p_ad = malloc(5*sizeof(int)); //dependiendo de la estructura de la computadora el número de bytes ocupados variará, sizeof retornará el valor aunque haya variedad en cada tamaño de procesador
	printf("%p\n", p_ad);
	p_ad = (int *)p_ad;	//El cast es importante para especificar el tipo de dato que se tomará para la memoria que malloc está buscando
	printf("%p", p_ad);
	return 0;
}
int function(){
	static int count = 0; //var que se considera no inicializada
	count ++;
	return count; //var que guarda/conserva su valor
}
//La declaración de un apuntador está en el stack. Una función que recibe un apuntador maneja distintos apuntadores, sólo que uno copia el apuntador de otra.

