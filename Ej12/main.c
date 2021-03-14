/*
 * main.c
 *
 *  Created on: 7 mar. 2021
 *      Author: danel
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int num;
	int den;
} Fraccion;

void printFraccion(Fraccion *f) {
	printf("\n%i / %i", (*f).num, f->den);
}

Fraccion sumar(Fraccion a, Fraccion b) {
	return (Fraccion) { (a.num * b.den) + (b.num * a.den), a.den * b.den };
}

Fraccion multiplicar(Fraccion *a, Fraccion *b) {
	return (Fraccion) { a->num * b->num , a->den * b->den };
}

void multiplicar2(Fraccion *a, Fraccion *b) {
	a->num*=b->num;
	a->den*=b->den;
}

int main(int argc, char **argv) {
	int i = 10;
	Fraccion f = { 3, 4 };

	int *puntEnt;
	Fraccion *puntFrac;

	puntEnt = &i;
	puntFrac = (Fraccion*) malloc(sizeof(Fraccion));

	f.num = 1;
	f.den = 6;

	puntFrac->num = 2;
	puntFrac->den = 9;

	*puntEnt = 4;

	printf("%i", *puntEnt);

	Fraccion fs = sumar(f,*puntFrac);
	printFraccion(&fs);

	Fraccion fm = multiplicar(&f,puntFrac);
	printFraccion(&fm);

	int arr[5];
	Fraccion *arrF = (Fraccion*) malloc(5 * sizeof(Fraccion));

	arr[2] = 21;

	arrF[2] = (Fraccion) {4,5};

	printf("\n%i",arr[2]);
	printFraccion(&arrF[2]);

	int *arrIP = arr;
	Fraccion *arrFP = arrF;

	*(arrIP + 1) = 99;
	*(arrFP + 1) = (Fraccion) {7,8};

	printf("\n%i",*(arrIP + 1));
	printFraccion(arrFP + 1);

	printf("\n%X",arrIP+5);

	int **puntPuntInt = &puntEnt;

	**puntPuntInt = 34;

	printf("\n%i", **puntPuntInt);

	Fraccion **puntPuntFrac = &puntFrac;

	**puntPuntFrac = (Fraccion){652,21};

	printFraccion(*puntPuntFrac);

	free(puntFrac);
	free(arrF);
	return 0;
}

