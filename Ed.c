/*
 ============================================================================
 Name        : Ed.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float recursiva (int x, int  y){
	float f,m;
	if(x==2.00){
		f=0.1*(sqrt(y))+0.4*(pow(x,2));
		printf("%f", f);
		x+=0.05;

	}
}

int main(void) {
	float x,y,f,m;
	x=2.00;
	y=4.00;
	for (short i=0; i<11; i++){
		printf("Valor x: %f\n", x);
		printf("Valor y: %f\n", y);
		f=0.1*(sqrt(y))+0.4*(pow(x,2));
		printf("f(x,y): %f\n",f);
		x+=0.05;
		m=y+(0.05*f);
		printf("m: %f\n\n\n", m);
		y=m;
	}
	return EXIT_SUCCESS;
}
