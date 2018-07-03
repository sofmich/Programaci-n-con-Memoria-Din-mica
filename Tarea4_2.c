/*
 ============================================================================
 Name        : Tarea4_pt2_v3.c
 Author      : Momo
 Version     :
 Copyright   : Null
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
int infixToPostfix(char* exp);
int maint(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	char exp[40];
	int i;
	printf("Expression: ");
	scanf("%s", exp);
	infixToPostfix(exp);
	return 0;
}

int Operand(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int hasHigherPrecedence(char c){
	switch (c)
	{
	case '+':
	case '-':
		return 0;

	case '*':
	case '/':
		return 1;

	case '^':
		return 2;
	}
	return -1;
}
int infixToPostfix(char* exp){
	 Stack* stack = createStack(strlen(exp));
	int i, k;
	if(!stack) return -1 ;
	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (Operand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;
			else
				pop(stack);
		}
		else
		{
			while (!isEmpty(stack) && hasHigherPrecedence(exp[i]) <= hasHigherPrecedence(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}
	while (!isEmpty(stack)) exp[++k] = pop(stack );
	exp[++k] = '\0';
	printf( "%s", exp );
	return 0;
}




