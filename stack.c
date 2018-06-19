/*
 * stack.c
 *
 *  Created on: 18/06/2018
 *      Author: ie714715
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef struct strNode{
	Type data;
	struct strNode *prior;
}Node;
struct strStack{
	Node *top;
	int size;
};
Stack createStack(){
	Stack new = (Stack)malloc(sizeof(struct strStack));
	if (new == NULL) return NULL;
	new->top = NULL;
	new->size = 0; //Inicializar valores siempre
	return new;
}
bool push(Stack stack, Type data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL) return false;
	newNode->prior = stack->top;
	newNode->data = data;

	stack->size++;
	stack->top = newNode;
	return true;

}
Type pop(Stack stack){
	if(stack->top == NULL) return NULL;
	Type temp;
	temp = stack->top->data;
	stack->size--;
	Node *tempNode = stack->top;
	stack->top = stack->top->prior;
	free(tempNode);
	return temp;
} //Extrae el elemento
Type top(Stack stack){
	if(stack->top == NULL) return NULL;
	return stack->top->data;
} //Permite ver qué hay en el tope
bool isEmpty(Stack stack){
	if(stack->size == 0) return true;
	else return false;
}
void destroy(Stack stack){
	while(isEmpty(stack)!=true) pop(stack);
	free(stack);
}
