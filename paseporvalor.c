/*
 * paseporvalor.c
 *
 *  Created on: 24/05/2018
 *      Author: ie714715
 *      Tema: Pase de parámetros por referencia y por valor
 *
 *
 *      Pase de parámetros por valor: copia de la variable en donde el alor original de la función no cambia
 *      Pase de parámetros por referencia: no se envía el dato almacenado sino la dirección de memoria del dato.
 *      	el valor original sí puede cambiar. arr[i] = *(arr + i)
 */
#include <stdlib.h>
#include <stdio.h>
#define max 10
typedef struct{
	float x, y;
} Vec;

int main(){
	int v = 5;
	int *array[max]; //arreglo de direcciones de memoria que apuntan a direcciones de sizeof(int)

	duplicar(&v); //Lo que se manda es una dirección y se espera en la función el contenido en la dirección.
	Vec vec;
	duplicarVector(&vec); //Dirección de memoria donde comienza la estructura
	/*
	 * Tipo *arr[] = {&var1, &var2, &var3}; arreglo de apuntadores
	 * */
	return 0;
}
void duplicar(int *i){	//Contenido en la dirección que se mando desde main
	*i *= 2;			// La modificación del contenido guardado en ese espacio de memoria ya fue modificado
}
void duplicarVector(Vec *pv){
	pv -> x *= 2; //(*pv).x
	pv -> y *= 2;
}
