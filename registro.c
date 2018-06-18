/*
 * registro.c
 *
 *  Created on: 23/05/2018
 *      Author: Momo
 */
#include <stdio.h>
#include <stdlib.h>
#define max 50
#define s printf("\n")

typedef struct{
	unsigned int Expediente;
	char Nombre[max];
	unsigned int Carrera;
	unsigned int Edad;
} Alumno;

void registrar(Alumno *p,int *lon);
void imprimir(Alumno *p,int *lon);
void eliminar(Alumno *p, int *lon);
void buscar(Alumno *p, int *lon);
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	char opc;
	Alumno alumnos[20];
	Alumno *pA = alumnos;
	int *lon;
	while(opc != 101){
		printf("= = = = = MENÚ = = = = =");
		s;
		printf("a.Registrar nuevo alumno\nb.Imprimir datos\nc.Eliminar alumno\nd.Buscar alumno\ne.Salir\n");
		printf("Opción: ");
		scanf("%c", &opc);
		if(opc < 96 || opc > 102){
			printf("Opción: ");
			scanf("%c", &opc);
		}
		switch(opc){
		case 97:
			registrar(pA,lon);
			break;
		case 98:
			if(*lon == 0){
				printf("No existen alumnos registrados");
			} else imprimir(pA,lon);
			break;
		case 99:
			if(*lon == 0){
				printf("No existen alumnos registrados");
			} else{
				imprimir(pA,lon);
				eliminar(pA,lon);
			}

			break;
		case 100:buscar(pA, lon); break;

		}
	}
	return 0;
}
void registrar(Alumno *p,int *lon){
	int i = *lon;
	printf("Expediente: ");
	scanf("%d",&(p+i)->Expediente);
	fflush(stdin);
	printf("Nombre: ");
	scanf("%50[^\n]", &(p+i)->Nombre);
	printf("Carrera: ");
	scanf("%d", &(p+i)->Carrera);
	printf("Edad:");
	scanf("%d", &(p+i)->Edad);

	(*lon) += 1;
}
void imprimir(Alumno *p, int *lon){
	int len = *(lon);
	int i;
	for(i=0; i<len; i++){
		printf ("Alumno %d: ", i+1);
		printf("%d \t %s \t %d \t %d\n",(p+i)->Expediente, (p+i)->Nombre, (p+i)->Carrera, (p+i)->Edad);
	}
}
void eliminar(Alumno *p, int *lon){
	int alum;
	printf("Ingresa el número de alumno que deseas eliminar: ");
	scanf("%d", &alum);
	for(int i = alum-1; i < (*lon); i++){
		strcpy((p+i)->Nombre, (p+i+1)->Nombre);
		(p+i)->Expediente = (p+i+1)->Expediente;
		(p+i)->Carrera = (p+i+1)->Carrera;
		(p+i)->Edad = (p+i+1)->Edad;
	}
	(*lon) -= 1;
}
void buscar(Alumno *p, int *lon){
	int exp, i, bandera = 0;
	printf("Ingresa el número de expediente: ");
	scanf("%d", &exp);
	for(i = 0; i < (*lon); i++){
		if((p+i)->Expediente == exp){
			printf("%d \t %s \t %d \t %d\n",(p+i)->Expediente, (p+i)->Nombre, (p+i)->Carrera, (p+i)->Edad);
			bandera += 1;
		}
	}
	if(bandera == 0){
		printf("No se encontraron registros\n");
	}

}
