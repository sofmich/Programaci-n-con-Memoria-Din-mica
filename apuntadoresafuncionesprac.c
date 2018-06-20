/*
 * apuntadoresafuncionesprac.c
 *
 *  Created on: 28/05/2018
 *      Author: ie714715
 */
#include <stdlib.h>
#include <stdio.h>
#define s printf("\n")

void saludar();
void despedirse();
void imprimirDoble(int x);
void imprimirTriple(int x);
int sumar(int a, int b);
int restar(int a, int b);


typedef int (*pop)(int,int);
typedef void (*pvoid)(void);
typedef void (*pinc)(int);

//void *ejecutar(void * , void *, pop );//función que ejecuta función y recibe función como paramétros tiene apuntadores y por eso el tipo es apuntador
//los apuntadores de void dejan un margen libre donde no se especifica el desplazamiento que hay en el apuntador
//se utiliza un cast para especificar el void de la funcion: void *v; (int *) v; ó en su caso (char *)v;
int ejecutar(void *, void *, pop);
int main(){
	int r;
	pop pSumar = sumar;
	pvoid pSaludar = saludar;
	pinc pDoble = imprimirDoble;
	r = pSumar(4,2);
	printf("Suma: %d",r);
	s;
	pSaludar();
	s;
	printf("Doble de 4: ");
	pDoble(4);

	//llamando a ejecuta
	int rp;
	int n1 = 2, n2 = 3;
	rp = ejecutar(&n1, &n2, sumar);
	s;
	printf("Ejecutar: %d", rp);
	return 0;
}

void saludar(){
	printf("Hello world!");
}
void despedirse(){
	printf("Good bye!");
}
void imprimirDoble(int x){
	printf("%d", x*2);
}
void imprimirTriple(int x){
	printf("%d", x*3);
}
int sumar(int a, int b){
	return a+b;
}
int restar(int a, int b){
	return a-b;
}
/*void *ejecutar(void *n1 , void *n2, pop fm ){
	int *v1 = (int *)n1, *v2 = (int *)n2; //Hacer el cast del apuntador de tipo de dato que querremos usar
	int r;
	r = fm(*v1, *v2);
	return &r;

}*/
int ejecutar(void *n1 , void *n2, pop fm ){
	int *v1 = (int *)n1, *v2 = (int *)n2; //Hacer el cast del apuntador de tipo de dato que querremos usar
	int r;
	r = fm(*v1, *v2);
	return r;
}

