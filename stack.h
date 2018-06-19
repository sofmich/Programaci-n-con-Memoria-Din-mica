/*
 * stack.h
 *
 *  Created on: 18/06/2018
 *      Author: ie714715
 */

#ifndef STACK_H_
#define STACK_H_
typedef void* Type; //Estructura para los nodos
typedef struct strStack *Stack; //Estructura para pilas
typedef enum{false,true} bool;
Stack createStack();
bool push(Stack, Type);	//Agrega un elemento al final de la pila
Type pop(Stack); //Extrae el elemento
Type top(Stack); //Permite ver qué hay en el tope
bool isEmpty(Stack);
void destroy(Stack stack);


#endif /* STACK_H_ */
