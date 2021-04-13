/*
 * fichero.c
 *
 *  Created on: 13 abr. 2021
 *      Author: danel
 */
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>

void crearInforme(GrupoPersonas gp, char *fichero) {
	FILE *f = fopen(fichero, "w");
	fprintf(f, "CENSO\n");
	for (int i = 0; i < 25; i++) {
		fputc('-', f);
	}
	fputc('\n', f);
	for (int i = 0; i < gp.numPersonas; i++) {
		char *s = personaString(gp.personas[i]);
		fprintf(f, "%s\n", s);
		free(s);
	}
	fprintf(f, "Media: %f", gp.mediaEdad);

	fclose(f);
}
