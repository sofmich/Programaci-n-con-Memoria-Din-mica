/*
 * main.c
 *
 *  Created on: 30/05/2018
 *      Author: Momo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nombre[15];
	float calificacion;
}Profesor;
float averageArray(Profesor *parr,int *n);
void readArray(Profesor arr[], int n);
void mergeArrays(Profesor arr1[] , int *n1, Profesor arr2[], int *n2, Profesor arrF[], int *n3);
void sortArray(Profesor arr[], int *plen);
void printArray(Profesor arr[] , int *len);
int main(){
	//Profesor arr1[20];
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	Profesor arr1[20];  //Primer arreglo
	Profesor arr2[20];  //Segundo arreglo
	Profesor arrF[40];  //Arreglo final, con elementos fusionados y ordenados
	int n1, n2, lenF; //Longitud de los arreglos

	//printf("Cantidad de profesores de ingeniería:");
	scanf("%d", &n1);
	while(n1 > 20){
		scanf("%d", &n1);
	}
	readArray(arr1,n1);
	//printf("Cantidad de profesores de otras carreras: ");
	scanf("%d",&n2);
	while(n2 > 20){
			scanf("%d", &n2);
		}
	readArray(arr2,n2);
	lenF = n1 + n2;
	mergeArrays(arr1,&n1,arr2,&n2,arrF,&lenF);  //Fusionar los dos arreglos en un tercer arreglo
	sortArray(arrF,&lenF);  //Ordenar los elementos del tercer arreglo, recuerde que pueden
	printArray(arrF,&lenF);   //Imprimir el resultado final

	return 0;
}
float averageArray(Profesor *parr,int *n){
	int cant=*n;
	float promedio=0;
	for(int i=0;i<cant;i++)
		promedio+=(parr+i)->calificacion;
	return promedio/cant;
}
readArray(Profesor arr[], int n){
	int i;
	Profesor *p = arr;
	for(i = 0; i < n ; i++){
		fflush(stdin);
		//gets((p)->nombre);
		//scanf("\n");
		//scanf("%f",&(p)->calificacion);
		scanf("%s	%f",&(p)->nombre,&(p)->calificacion);
		p++;
	}
}
void mergeArrays(Profesor arr1[] , int *n1, Profesor arr2[], int *n2, Profesor arrF[],int *n3){
	int k=0, i;
	int len = *n3, len1 = *n1;
	Profesor *p= arrF, *p1 = arr1, *p2 = arr2;
	for(i=0;i<len;i++){
		if(i<len1){
			strcpy((p+i)->nombre,(p1+i)->nombre);
			(p+i)->calificacion=(p1+i)->calificacion;
		}
		else{
			strcpy((p+i)->nombre,(p2+k)->nombre);
			(p+i)->calificacion=(p2+k)->calificacion;
			k++;
		}
	}

}
void sortArray(Profesor arrF[], int *plen){
	int len = *plen;

	Profesor aux_;
	Profesor *paux = &aux_;
	int c;
	int i,j,l;
	Profesor *p = arrF;
	for(i = 0; i< len; i++){
		c=1;
		for(j = i+1;  j<len; j++){
			if(strcmp((p+i)->nombre,(p+j)->nombre)==0){
				strcpy(paux->nombre,(p+i+c)->nombre);
				paux->calificacion=(p+i+c)->calificacion;
				strcpy((p+i+c)->nombre,(p+j)->nombre);
				(p+i+c)->calificacion=(p+j)->calificacion;
				strcpy((p+j)->nombre,paux->nombre);
				(p+j)->calificacion=paux->calificacion;
				c++;
			}
		}
		if(c>1)
		{
			(p+i)->calificacion=averageArray((p+i),&c);
			for(l=i+1;l<len;l++)
			{
				strcpy((p+l)->nombre,(p+l+c-1)->nombre);
				(p+l)->calificacion=(p+l+c-1)->calificacion;
			}
			len-=(c-1);
		}
	}
	for(i=0;i<len;i++)
			for(j=0;j<len-1;j++)
			{
				if((p+j)->calificacion<(p+j+1)->calificacion)
				{
					strcpy(paux->nombre,(p+j)->nombre);
					paux->calificacion=(p+j)->calificacion;
					strcpy((p+j)->nombre,(p+j+1)->nombre);
					(p+j)->calificacion=(p+j+1)->calificacion;
					strcpy((p+j+1)->nombre,paux->nombre);
					(p+j+1)->calificacion=paux->calificacion;
				}
			}
	*plen = len;
}

void printArray(Profesor arr[] , int *len){
	Profesor *p = arr;
	int i;
	int lena = *len;
	for(i=0;i<lena;i++){
		printf("%s\t %.2f\n", p->nombre, p->calificacion);
		p++;
	}
}
