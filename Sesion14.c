/*
 ============================================================================
 Name        : Sesion14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int id_cliente;
	char name[12];
}Cliente;
int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	FILE *file = fopen("Client.txt","ab");
	if(file==NULL) return 1;
	Cliente cliente[]={{1,"Sofía"},{2,"Michel"}};
	int bytes;

	//bytes = fwrite(&cliente,sizeof(Cliente),1,file);
	fclose(file);
	file = fopen("Client.txt","rb");
	if(file==NULL) return 1;
	Cliente temporal;
	char ind;
	while((!feof(file))){
		fread(&temporal,sizeof(Cliente),1,file);
		printf("%d %s\n",temporal.id_cliente, temporal.name);
	}
	fclose(file);
	file = fopen("Client.txt","rb");
	if(file==NULL) return 1;
	long int lenf;
	fseek(file,sizeof(Cliente),SEEK_END);
	lenf = ftell(file);
	printf("Tamaño del archivo: %d",lenf);
	fclose(file);
	printf("\nTamaño de struct: %d", sizeof(Cliente));

	return EXIT_SUCCESS;
}
