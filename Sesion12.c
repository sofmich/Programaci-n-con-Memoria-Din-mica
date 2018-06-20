/*
 ============================================================================
 Name        : Sesion12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int N = 0, i=0;
	char frase[] = "Hola qué onda";
	char *chars = frase;
	do{
			N++;
			i++;
		} while(*(chars + i)!= '\0');
	printf("Longitud de la frase: %d",N);
	char frase2[]={'\0'};
	char *array = frase2;
	for(i=0; i < N+1 ; i++){
			*(array+i) = *(chars+i);
		}
	printf("\nFrase 2: %s", frase2);
	return EXIT_SUCCESS;
}
