/*
 ============================================================================
 Name        : cifradoCesar.c
 Author      : Francisco Cervantes
 Version     : PMD2018v
 Copyright   : Your copyright notice
 Description : Implementación del algoritmo para Cifrado Cesar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cifradoCesar(char *texto, int k);

int main(void) {
	int k;
	char temp;
	char texto[100];
	printf("Define K (desplazamiento/Key): \n");
	scanf("%d", &k);
	printf("Escribe el texto a cifrar: \n");
	scanf("%c",&temp);
	scanf("%[^\n]",texto);
	cifradoCesar(texto, k);
	printf("Texto cifrado: \n");
	printf("%s", texto);
	return 0;
}

void cifradoCesar(char *texto, int k){
	int i=0;
	while(texto[i]!='\0'){
		if((texto[i]!=32)&&(texto[i]!=',')){
			texto[i]=toupper(texto[i])-65;
			texto[i]=(texto[i]+k)%26;
			texto[i]+=65;
		}
		i++;
	}
}
