/*
 ============================================================================
 Name        : Sesion16.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Contenedores y estructuras autorreferenciadas

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct Date{
	int day, month, year;
	//date self; Tipo de dato incompleto (Desconocido)
	//struct Date self; Tipo de dato declarado de forma estática en toda la estructura
	struct Date *self, *next; //La memoria está deifnida para el apuntador, intentar crear un tipo de dato que todavía no se define al completo es una paradoja
} date;
void setYear(date  data, int yy);
void setYearP(date * data, int yy);
void printDate(date * first);
int main(){
	date date1 = {1,2,1900};
	date date2 = {5,6,1870};
	date date3 = {21,03,1970};
	//Creación de una lista
	date1.next = &date2;
	date2.next = &date3;
	date3.next = NULL;
	printDate(&date1);
	return 0;
}
int main1(void) {
	date Date1  = {9,7,1998,&Date1};
	printf("%d \t",Date1.year );
	setYear(Date1,1999);
	printf("%d \t",Date1.year );
	setYearP(&Date1, 2000);
	printf("%d \t",Date1.year );
	return EXIT_SUCCESS;
}
void printDate(date *first){
	date * aux = first;
	while(aux != NULL){		//Accedes al next del next del next hasta que llegues al último en donde la siguiente dirección sería NULA
		printf("%02d/%02d/%02d\t",aux->day,aux->month, aux->year % 100);
		aux = aux->next;
	}

}
void setYear(date data, int yy){		//La dirección de data es != a la de la variable original
	//data.self->year = yy;
	date *p = data.self;
	p->year = yy;
	//printf("\nDirección de data: %p \tDirección de Data1: %p", &data, data.self);

}
void setYearP(date * data, int yy){
	data->self->year=yy;
	//data->year = yy;

}
/*	LISTA: Accedes a los elementos a través de indicies, permitiendo acceder al final, mitad e inicio.
 * 	PILAS: El último elemento es el primero en ser utilizado. Permite añadir, consultar y extraer solo en el top.
 * 			NO EXISTEN LOS INDICES. Atiende al más NUEVO.
 * 			Búsqueda de profundidad.
 * 	COLA: Permite añadir solo al final de la secuencia y consultar y extraer solo al inicio de la secuencia.
 * 			COMPARA LA PRIORIDAD Y SE MANEJA PRIMERO EL DE MAYOR ANTIGÜEDAD(depende del dato).
 * 			Búsqueda de amplitud.
 * 	COLA DE PRIORIDAD: Atiende primeramente a los elementos de mayor prioridad, de manera que hay una comparación
 * 			de datos. COLECCIÓN DE ELEMENTOS COMPARABLES.
 * 	CONJUNTO: No hay repetidos de acuerdo al CRITERIO DE COMPARACIÓN.
 * 	MAPA: Se accede a través de claves a los elementos, los cuales pueden estar repetidos pero su clave no.
 *
 * */
