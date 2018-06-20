/*
 * queue.h
 *
 *  Created on: 20/06/2018
 *      Author: ie714715
 */

#ifndef QUEUE_H_
#define QUEUE_H_
typedef void* Type;
typedef struct strQueue *Queue;
typedef enum{false, true}bool;
Queue createQueue();
int size(Queue);
bool isEmpty(Queue);
Type peek(Queue);
void offer(Queue, Type);
Type poll(); //Vac�o devuelve NULL, si no devuelve el que est� en first. Elimina el nodo que fue extra�do. Regresar los datos del nodo.
void destroy(Queue);



#endif /* QUEUE_H_ */
