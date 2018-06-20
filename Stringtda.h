/*
 * Stringtda.h
 *
 *  Created on: 07/06/2018
 *      Author: ie714715
 */

#ifndef STRINGTDA_H_
#define STRINGTDA_H_

typedef struct strString* String;
String create(char* chars);
void destroy(String);
void print(String);
void println(String);
unsigned int length(String);
char charAt(String, int index);
String clone(String);

#endif /* STRINGTDA_H_ */
