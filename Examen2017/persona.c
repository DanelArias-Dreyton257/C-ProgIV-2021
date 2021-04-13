#include <stdio.h>
#include "persona.h"
#include <stdlib.h>

#define MAX_NUM_C 100

void imprimirPersona(Persona p) {
	printf("%s\n", personaString(p));
}

char* personaString(Persona p) {
	char *s = malloc(sizeof(char) * MAX_NUM_C);
	sprintf(s, "[Nombre: %s, Edad: %i]", p.nombre, p.edad);
	return s;
}
