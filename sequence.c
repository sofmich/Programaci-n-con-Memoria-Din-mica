/*
 * sequence.c
 *
 *  Created on: 06/06/2018
 *      Author: ie714715
 */

#include <stdio.h>
#include <stdlib.h>
#include "sequencetda.h"

struct sequence{
	int next;
	int step;
};

Sequence seq_create(int init){
	Sequence new;
	new = seq_create_step(init, 1);
	return new;
}
Sequence seq_create_step(int init, int step){
	Sequence new;
	new=(Sequence)malloc(sizeof(struct sequence));
	if (new != NULL) {
	new -> next=init;
	new -> step = step;
	return new;
	}
	else return 0;
}
void seq_destroy(Sequence new){
	free(new);
}
int seq_next(Sequence new){
	new -> next += new->step;
	return new->next;
}
