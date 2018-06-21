/*
 * list.c
 *
 *  Created on: 21/06/2018
 *      Author: ie714715
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
typedef struct strNode{
	Type data;
	struct strNode *prior, *last; //quien esta adelante y quien esta atras
};
typedef struct strNode *Node;
struct strList{
	Node *last, *next;
	int size;
};

List createList(){
	List new = (List)malloc(sizeof(struct strList));
	if(new == NULL) return NULL;
	new -> next = NULL;
	new -> last = NULL;
	new -> size = 0;
	return new;
}
//Crea una lista con memoria dinámica e inicializa en ceros sus elementos
bool add(List list, Type data){
	Node newNode = (Node) malloc (sizeof(struct strNode));
	if (newNode == NULL) return false;
	if(list -> size == 0){
		list -> last = newNode;
		list ->next = newNode;
		newNode -> last = NULL;
		newNode -> prior = NULL;
	}else{
		list -> last -> prior = newNode;
		newNode -> prior = list -> last;
		list -> last = newNode;
	}
	newNode -> data = data;
	list ->size +=1 ;
	return true;
}
//Agrega un elemento (nodo) e incrementa el tamaño en 1
Type get(List list, int pos){

}
//Regresa el elemento en la posición indicada
void set(List list, Type data, int pos){

}
//Remplaza el elemtno en la posicion p por el valor recibido
Type Remove(List list, int pos){

}
//Elimina y devuelve el elemento en la posicion p, decrementa el tamaño en 1
void insert(List list, int pos, Type data){

}
//Inserta un elemento nuevo en la posicion p incrementando el tamaño
int size(List list){
	return list->size;
}
//Extrae el tamaño de la lista
void destroy(List list){
	while(list -> size != 0) remove (list);
	free(list);
}
//Elimina los nodos y la lista
