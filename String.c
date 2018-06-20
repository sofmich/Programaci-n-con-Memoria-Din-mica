/*
 * String.c
 *
 *  Created on: 07/06/2018
 *      Author: ie714715
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stringtda.h"

struct strString {
	char *chars;
	unsigned int length;
};
String create(char* chars){
	String string;
	string = (String)malloc(sizeof(struct strString));
	int i, N;
	do{
		N++;
		i++;
	} while(*(chars + i)!= '\0');
	string -> length = N;
	char *array = (char*)malloc(sizeof(char)*N);

	string -> chars = array;
	return string;
}
void destroy(String string){
	free(string);
}
void print(String string){

}
void println(String string){

}
unsigned int length(String string){
	return string->length;
}
char charAt(String string, int index){

}
String clone(String string ){

}
