/*
 * main.c
 *
 *  Created on: 21 abr. 2021
 *      Author: danel
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	printf("Se han recibido %i argumentos (%i extra):\n", argc, argc - 1);
	printf("Ruta: %s\n", argv[0]);
	if (argc > 1) {
		printf("Argumentos extra:\n");
		for (int i = 1; i < argc; i++) {
			printf("\t%s\n", argv[i]);
		}
	}
	if(strcmp("Danel",argv[1])==0){
		printf("Veo que sabes de lo que hablas amigo mio\n");
	}
}
