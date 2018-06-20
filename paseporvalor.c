/*
 * paseporvalor.c
 *
 *  Created on: 24/05/2018
 *      Author: ie714715
 *      Tema: Pase de par�metros por referencia y por valor
 *
 *
 *      Pase de par�metros por valor: copia de la variable en donde el alor original de la funci�n no cambia
 *      Pase de par�metros por referencia: no se env�a el dato almacenado sino la direcci�n de memoria del dato.
 *      	el valor original s� puede cambiar. arr[i] = *(arr + i)
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

	duplicar(&v); //Lo que se manda es una direcci�n y se espera en la funci�n el contenido en la direcci�n.
	Vec vec;
	duplicarVector(&vec); //Direcci�n de memoria donde comienza la estructura
	/*
	 * Tipo *arr[] = {&var1, &var2, &var3}; arreglo de apuntadores
	 * */
	return 0;
}
void duplicar(int *i){	//Contenido en la direcci�n que se mando desde main
	*i *= 2;			// La modificaci�n del contenido guardado en ese espacio de memoria ya fue modificado
}
void duplicarVector(Vec *pv){
	pv -> x *= 2; //(*pv).x
	pv -> y *= 2;
}
