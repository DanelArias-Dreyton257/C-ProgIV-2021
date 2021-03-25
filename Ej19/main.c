/*
 * main.c
 *
 *  Created on: 25 mar. 2021
 *      Author: danel
 */
#include <stdio.h>

void escribeNums(FILE *f, int nums);
int leeFilas(FILE *f);

int main(int argc, char **argv) {
	FILE *f = fopen("fichero.txt", "r+");

	escribeNums(f, 1000);

	int filas = leeFilas(f);
	fclose(f);

	printf("Tiene %i filas",filas);
	return 0;
}

void escribeNums(FILE *f, int nums) {
	fprintf(f, "Escribiendo %i numeros\n", nums);
	for (int i = 0; i < nums; i++) {
		fprintf(f, "%i\n", i);
	}
}
int leeFilas(FILE *f) {
	int numLineas = 0;
	char leido = '\0';
	while(leido!=EOF){

		if(leido == '\n'){
			numLineas++;
		}

		leido = fgetc(f);
	}
	return numLineas;
}

