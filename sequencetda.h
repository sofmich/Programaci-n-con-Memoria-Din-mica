/*
 * sequencetda.h
 *
 *  Created on: 06/06/2018
 *      Author: ie714715
 */

#ifndef SEQUENCETDA_H_
#define SEQUENCETDA_H_

typedef struct sequence *Sequence; //tipo de dato estructurado llamado Sequence

Sequence seq_create(int init);
Sequence seq_create_step(int init, int step);
void seq_destroy(Sequence);
int seq_next(Sequence);

#endif /* SEQUENCETDA_H_ */
