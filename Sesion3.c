/*
 ============================================================================
 Name        : Sesion3.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
		int x,y;
	}Numeros;
int main(void) {
	puts("Apuntadores a estructuras.\n");
	Numeros numeros1;
	Numeros *pStr = &numeros1;
	pStr->x = 10;
	pStr->y = 12;
	(*pStr).x = 12;
	(*pStr).y = 3;
	return EXIT_SUCCESS;
}
