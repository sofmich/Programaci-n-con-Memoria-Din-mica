/*
 ============================================================================
 Name        : Sesion2.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Pointers and data size.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pInt;
	float *pFloat;
	char *pChar;
	long *pLong;
	printf("Pointers sizes\nInt: %d\nFloat: %d\nChar: %d\nLong: %d\n", sizeof(pInt),sizeof(pFloat),sizeof(pChar),sizeof(pLong));
	printf("Data size\nInt: %d\nFloat: %d\nChar: %d\nLong: %d\n",sizeof(int),sizeof(float),sizeof(char),sizeof(long));
	return EXIT_SUCCESS;
}
