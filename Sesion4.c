/*
 ============================================================================
 Name        : Sesion4.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char Name[15];
}Nombre;
//void recibir();
//void revisar();
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	Nombre names[10];
	int i=0;
	printf("Nombres: \n");
	for(i=0; i<5; i++){
		scanf("%s",names[i].Name);
	}
	char comp;
	printf("Letra: \t");
	fflush(stdin);
	scanf("%c",&comp);
	for(i=0; i<5; i++){
		if(names[i].Name[0]==comp)printf("%s, ",names[i].Name);
	}
	return 0;
}
void incremento(int *array[], int N);
void imprimir(int *array[], int N);
int main1(void) {
	int a=0,b=0,c=0;
	int *arr[] = {&a,&b,&c};
	printf("Direcciones originales: \n");
	imprimir(arr,3);
	incremento(arr,3);
	printf("Direcciones incrementadas: \n");
	imprimir(arr,3);
	return EXIT_SUCCESS;
}
void incremento(int *array[], int N){
	int i;
	for(i=0; i<N; i++) {
		if(array[i]!=NULL)array[i]++;
	}

}
void imprimir(int *array[], int N){
	int i;
	for(i=0; i<N; i++) printf("%p\n", array[i]);
}
