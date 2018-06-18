/*
 ============================================================================
 Name        : Examen2.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <mat.h>
#define N 4
#define K 6
typedef struct{
	int expediente;
	char nombre [1000];
	float promedioGeneral;
} ExpedienteAcademico;


int main(void) {
	ExpedienteAcademico *arrExp = (ExpedienteAcademico*)calloc(N,sizeof(ExpedienteAcademico));
	if(arrExp == NULL){
		printf("Fallo al asignar memoria.");
		return -1;
	}else{
		arrExp[0].expediente=934;
		printf("Expediente 0: %d", arrExp[0].expediente);
		printf("\tPromedio 1: %f", arrExp[1].promedioGeneral);
		printf("\nParte 2:");
		ExpedienteAcademico *temp = realloc(arrExp,K);

		if(temp == NULL){
			printf("Fallo al asignar nueva memoria.");
			return -1;
		}
		else{
			arrExp = temp;
			printf("\n…xito al reasignar memoria.");
		}


	}
	free(arrExp);
	printf("\nParte 4:");
	int r = 5, c = 4;
	int **Matrix = (int**)malloc(sizeof(int*)*r);
	if(Matrix == NULL){
		printf("Fallo al asignar nueva memoria.");
		return -1;
	}
	else printf("\n…xito al asignar memoria(Filas).");
	int i,j;
	for(i=0; i<r; i++){
		Matrix[i]=(int*)malloc(sizeof(int)*c);
		if(Matrix[i]==NULL){
			printf("Fallo al asignar nueva memoria.");
			return -1;
		}
	}
	printf("\n…xito al asignar memoria(Columnas).");
	for(i=0; i<=r; i++){
		for(j=0; j<=c; j++){
			//if(((j+1)&1)==1)//Columnas impar
			//Matrix[i][j] = 2;
			// else Matrix[i][j] = 2;
			//printf("%d\t",Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\nParte 5:");
	for(i=0; i<r; i++){
		free(Matrix[i]);
		printf("\nMemoria de columna %d liberada",i);

	}
	free(**Matrix);
	printf("\nMemoria de renglones liberada",i);
	printf("\nParte 6:");
	/*numeros operacion = crear(1,2);
	 int suma = suma(operacion);
	 destroy(operacion);


	 * */
	printf("\nParte 7:");
	FILE *file = fopen("miarchivo.txt", "wb+");
	fprintf(file,"hola");
	fputs("HOLA",file);
	//while(!feof(file)){
		//fscanf(file,"%s",&hi);
	//}
	fseek(file,0,SEEK_END);
	printf("\nBytes escritos: %d", ftell(file));
	fclose(file);
	return EXIT_SUCCESS;
}
