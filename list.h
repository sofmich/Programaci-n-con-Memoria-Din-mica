/*
 * list.h
 *
 *  Created on: 21/06/2018
 *      Author: ie714715
 */

#ifndef LIST_H_
#define LIST_H_
typedef void *Type;
typedef struct strList * List;
typedef enum{false, true} bool;
List createList();
//Crea una lista con memoria dinámica e inicializa en ceros sus elementos

bool add(List, Type);
//Agrega un elemento (nodo) e incrementa el tamaño en 1
Type get(List, int);
//Regresa el elemento en la posición indicada
void set(List, Type, int);
//Remplaza el elemtno en la posicion p por el valor recibido
Type removee(List, int);
//Elimina y devuelve el elemento en la posicion p, decrementa el tamaño en 1
void insert(List, int, Type);
//Inserta un elemento nuevo en la posicion p incrementando el tamaño
int size(List);
//Extrae el tamaño de la lista
void destroy(List);
//Elimina los nodos y la lista

#endif /* LIST_H_ */
