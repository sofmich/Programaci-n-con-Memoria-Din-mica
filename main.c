/*
 * main.c
 *
 *  Created on: 06/06/2018
 *      Author: ie714715
 */

#include <stdio.h>
#include <stdlib.h>
#include "sequencetda.h"

int main(void){
	Sequence s1,s2,s3;
	s1 = seq_create(10);
	s2 = seq_create_step(1,5);
	s3 = seq_create_step(1,1);
	printf("%d", seq_next(s1));
	seq_destroy(s1);
	seq_destroy(s2);
	seq_destroy(s3);
	return 0;
}
