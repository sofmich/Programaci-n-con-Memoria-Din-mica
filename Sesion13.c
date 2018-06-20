/*
 ============================================================================
 Name        : Sesion13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file;

	file = fopen("texto2.txt","r");

	//Si el archivo está en el lugar en donde esta el ejecutable, entonces no es necesario especificar la ruta
	/*
	 * Modo de apertura de archivos:
	 *	r 		sólo lectura
	 *	w 		abre el archivo solo para escritura, si no existe se crea, además trunca el contenido pues escribe al principio del archivo
	 *	a		si el archivo no existía se crea y se continúa escribiendo al final
	 *	r+		abre un archivo para lectura y escritura
	 *	w+		abre un archivo para modo lectura y escritura
	 *	a+		abre un archivo en modo lectura y escritura. La lectura se sitúa al inicio del archivo y la escritura al final
	 *
	 *	Existen modificadores para especificar si el archivo es de tipo binario o de texto:
	 *	b		binary mode 				rb wb wb
	 *	t		text mode
	 * */
	if(file==NULL)printf("Error al abrir el archivo");
	else{
		printf("Exito\n");
		//fprintf(file, "aaa %d\n ", 1);

		//fputs("Añadiendo fputs", file);
		char buff[100];
		/*fscanf(file, [^\n]", buff);
		puts(buff);
		fgets(buff,100,file);
		puts(buff);*/
		fgets(buff,100,file);
		printf("%s",buff);
		fgets(buff,100,file);
		printf("%s",buff);
	}
	fclose(file);
	return EXIT_SUCCESS;
}
