/*
 ============================================================================
 Name        : Sesion17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Create an stack for saving 10 numbers using tda and then showing them in monitor
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef struct{
	char name[15];
}Name;
int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	char expression[10];
	printf("Expression: ");
	fgets(expression, 10, stdin);
	printf("%s",expression);
	return 0;
}
int main2(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	Name names[5], *p;
	p = names;
	Stack s1 = createStack();
	int i;
	puts("!!!Creating an stack for practice!!!");
	for(i=0; i<5; i++) {
		scanf("%s",(p+i)->name);
		if(push(s1,(p+i))==true)printf("Agregado exitosamente.\n");
		else printf("Fallo al agregar.\n");
	}
	for(i=0; i<5; i++){
		p = pop(s1);
		printf("%s\t",p->name);
	}
	return 0;
}
int main1(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	puts("!!!Creating an stack for practice!!!"); /* prints !!!Hello World!!! */
	Stack s1= createStack();
	int i, aux[10];
	for(i=0; i<10; i++) {
		scanf("%d", &aux[i]);
		if(push(s1,&aux[i])==true)printf("Agregado exitosamente.\n");
		else printf("Fallo al agregar.\n");
		fflush(stdin);
	}
	int *p;
	for(i=0; i<10; i++){
		p = pop(s1);
		printf("%d\n",*p);
	}
	return EXIT_SUCCESS;

}
