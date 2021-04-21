/*
 * main.c
 *
 *  Created on: 21 abr. 2021
 *      Author: danel
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int numFilas;
	int numColumnas;
	int **m;
} Matriz;

void rellenarMatriz(Matriz *m) {
	for (int i = 0; i < m->numFilas; i++) {
		for (int j = 0; j < m->numColumnas; j++) {
			(m->m)[i][j] = (rand() % 10);
		}
	}
}
void reservarMemoriaMatriz(Matriz *m) {
	m->m = malloc(sizeof(int*) * m->numFilas);
	for (int i = 0; i < m->numFilas; i++) {
		m->m[i] = malloc(sizeof(int) * m->numColumnas);
	}
}
void imprimirMatriz(Matriz *m) {
	printf("[\n");
	for (int i = 0; i < m->numFilas; i++) {
		printf("\t[");
		for (int j = 0; j < m->numColumnas; j++) {
			printf(" %i, ", (m->m)[i][j]);
		}
		printf("]\n");
	}
	printf("]\n");
}
void liberarMatriz(Matriz *m) {
	for (int i = 0; i < m->numFilas; i++) {
		free(m->m[i]);
	}
	free(m->m);
}

int main(int argc, char **argv) {
	Matriz m;
	m.numFilas = 3;
	m.numColumnas = 3;
	reservarMemoriaMatriz(&m);
	rellenarMatriz(&m);
	imprimirMatriz(&m);
	liberarMatriz(&m);
}
