/*
 * queue.c
 *
 *  Created on: 20/06/2018
 *      Author: ie714715
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct strNode{
	Type data;
	struct strNode *next;
};
typedef struct strNode *Node;
struct strQueue{
	Node first; //Apunta al primer nodo en la cola
	Node last; //Apunta al ultimo nodo que está en la ocla, el último al entrar
	int size;
};
typedef struct strNode *Node;
Queue createQueue(){
	Queue new = (Queue)malloc(sizeof(struct strNode));
	if(new == NULL) return NULL;
	new ->first = NULL;
	new -> last = NULL;
	new -> size = 0;
	return new;
} //Crea un ejemplar asignando null
int size(Queue queue){
	if(isEmpty(queue) == false) return queue->size;
	else return 0;
} //Extrae el tamañao de la cola
bool isEmpty(Queue queue){
	if(queue->size == 0) return true;
	else return false;
} //Si first es null
Type peek(Queue queue){
	if(isEmpty(queue) == false) return queue->first->data;
	else return NULL;
}//Consulta no elimina quien esta al frente
void offer(Queue queue, Type data){
	Node new = (Node)malloc(sizeof(struct strNode));
	if(new != NULL){
		new -> next = NULL;
		queue -> size += 1;
		if(isEmpty(queue) == true){
			queue -> first = new;
		} else {
			queue -> last ->next = new;
		}
		queue -> last = new;
	}
} // Se inserta uno nuevo al final
Type poll(Queue queue){
	if(isEmpty(queue)) return NULL;
	Type datatemp = queue->first->data;
	Node tempNode = queue->first;
	queue->size -= 1;
	if(queue->size == 1){
		queue->first = NULL;
		queue->last = NULL;
	}
	queue->first = queue->first->next;
	free(tempNode);
	return datatemp;
} //Atiende al que está al frente
void destroy(Queue queue){
	while(isEmpty(queue) == false) poll(queue);
	free(queue);
} //Elimina la cola
