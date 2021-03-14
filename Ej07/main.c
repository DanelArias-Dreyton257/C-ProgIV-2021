/*
 * main.c
 *
 *  Created on: 25 feb. 2021
 *      Author: danel
 */
#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point;
void escalar(Point *p, int n) {
	p->x += n;
	p->y += n;
}
int main(int argc, char **argv) {
	Point p;
	p.x = 4;
	p.y = 5;
	printf("Antes de escalar: ( %i , %i )\n", p.x, p.y);
	escalar(&p, 10);
	printf("Despues de escalar:( %i , %i )", p.x, p.y);
	return 0;
}


