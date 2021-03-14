/*
 * main.c
 *
 *  Created on: 4 mar. 2021
 *      Author: danel
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Point;

int sizeArr = 3;

int a2[] = { 6, 2, 3 };

void escalar(Point *ap, int *ae, int size) {
	for (int i = 0; i < size; i++) {
		(ap + i)->x *= *(ae + i);
		(ap + i)->y *= *(ae + i);
	}

}

int main(int argc, char **argv) {

	Point *p = (Point*) malloc(sizeArr * sizeof(Point));
	for (int i = 0; i < sizeArr; i++) {
		(p + i)->x = rand();
		(p + i)->y = rand();
		printf("Antes de escalar: P%i( %i , %i )\n",i, (p+i)->x, (p+i)->y);
	}

	escalar(p, a2, 3);
	for (int j = 0; j < sizeArr; j++) {
		printf("Despues de escalar: P%i( %i , %i )\n",j, (p + j)->x, (p + j)->y);
	}
	free(p);
	return 0;
}

