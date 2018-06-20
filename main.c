/*
 * main.c
 *
 *  Created on: 06/06/2018
 *      Author: ie714715
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	int edad;
	float altura;
	int peso;
}Persona;

Persona *crearPersona (char *nombre, int edad, float altura, int peso);
void destruirPersona (Persona *quien);
void imprimirPersona (Persona *quien);
void actualizarPersona (Persona *quien);

int main(void) {
	Persona *aP;
	/*aP= (Persona *)malloc(sizeof(Persona));

	aP->nombre= strdup("Juan");
	aP->edad=19;
	aP->altura=1.88;
	aP->peso=80;

	free(aP->nombre);
	free(aP);
	*/

	aP =crearPersona("Luis", 19,1.74, 70);
	imprimirPersona(aP);
	actualizarPersona(aP);
	imprimirPersona(aP);
	destruirPersona(aP);


	return EXIT_SUCCESS;
}

Persona *crearPersona (char *nombre, int edad, float altura, int peso){
	Persona *aP;
	aP= (Persona *)malloc(sizeof(Persona));
	if (aP!=NULL){
		aP->nombre=strdup(nombre);
		aP->edad= edad;
		aP->altura= altura;
		aP->peso= peso;
	}
	printf("-Persona registrada-\n");
	return aP;
}

void destruirPersona (Persona *quien){
	if (quien!=NULL){
		free (quien->nombre);
		free(quien);
		printf("---Espacio Liberado---\n");
	}
}

void imprimirPersona (Persona *quien){
	printf("-Persona-\n");
	printf("Nombre: %s\n", quien->nombre);
	printf("Edad: %d\n", quien->edad);
	printf("Altura: %0.2f\n", quien->altura);
	printf("Peso: %d\n", quien->peso);
}

void actualizarPersona(Persona *quien){
	char *temp=malloc(sizeof(char)*10);
	printf("-Actulizar Persona-\n");
	printf("Nuevo nombre: ");
	scanf("%s", temp); // Recuerda que no lleva '&' por que ya lleva el arreglo
	// la direccion de memoria
	quien->nombre=temp;

	printf("Nueva edad: ");
	scanf("%d", &quien->edad); // Se le pone '&' por que estos ya son variables
	// y se necesita la direccion del nuevo valor

	printf("Nueva altura: ");
	scanf("%f", &quien->altura);

	printf("Nuevo peso: ");
	scanf("%d", &quien->peso);


}


