/*
 * cesar.c
 *
 *  Created on: 22/05/2018
 *      Author: Momo
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 40
void encriptar(char chr[MAX], int c);
int main(){
	int cifrado;
	char chr[MAX];
	//printf("Texto: ");
	fgets(chr, MAX, stdin);
	//printf("\nCifrado: ");
	scanf("%d",&cifrado);
	encriptar(chr, cifrado);
	printf("\nCadena encriptada: %s", chr);
	return 0;
}
void encriptar(char chr[MAX], int c){
	for(int i=0; i < MAX ; i++){
		if((chr[i] > 64 && chr[i] < 91) || (chr[i] > 96 && chr[i] < 123) ) {
			if((chr[i] + c > 122) || (chr[i] + c > 90 && chr[i] +c <95) ){
				int aux;
				if(chr[i] > 122){
					aux = 122 - chr[i];
					aux = c - aux;
					chr[i] = 95;
				}
				if(chr[i] > 90 && chr[i] <95){
					aux = 90 - chr[i];
					aux = c - aux;
					chr[i] = 64;
				}
				chr[i] = chr[i] + aux;
			}
			else chr[i] = chr[i] + c;
		}

	}
}
