/*
 ============================================================================
 Name        : Tarea4_1.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool  balanced(Stack stack, char expr[40]);

int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	char expr[40], *p = expr;
	unsigned short i=0, opc = 0;
	do{
		Stack stack;
		stack = createStack();
		puts("Expression:"); /* prints  */
		scanf("%s", expr);
		if(balanced(stack, expr)) printf("Expresión balanceada.\n");
		else printf("Expresión no balanceada.\n");
		printf("Presiona 0 para continuar... ");
		scanf("%hu", &opc);
	}while(opc == 0);

	return EXIT_SUCCESS;
}
bool  balanced(Stack stack, char expr[40]){
	char *p = expr, *p2;
	while(*p != '\0'){
		if(*p == '(' || *p == '[') push(stack, p);
		else{
			if(isEmpty(stack)!=true) {
				p2 = top(stack);
				if(*p == ')') {
					if(*p2 != '(') return false;
					else pop(stack);
				}
				else  if(*p == ']') {
					if(*p2 != '[') return false;
					else pop(stack);
				}
			}

		}

		p++;
	}
	if(isEmpty(stack)) {
		free(stack);
		return true;

	}
	else return false;


}
