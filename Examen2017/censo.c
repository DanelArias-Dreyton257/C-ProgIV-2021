/*
 * censo.c
 *
 *  Created on: 13 abr. 2021
 *      Author: danel
 */
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>

int cuantasPersonas(Persona *ap, int tamanyo, int edad) {
	int cont = 0;
	for (int i = 0; i < tamanyo; i++) {
		if ((ap + i)->edad < edad) {
			cont++;
		}
	}
	return cont;
}

//float calcularMediaGrupo(GrupoPersonas *g) {
//	int sum = 0;
//	for (int i = 0; i < g->numPersonas; i++) {
//		sum += g->personas[i].edad;
//	}
//	return sum / g->numPersonas;
//}

void anyadePersonaEnGrupo(GrupoPersonas *g, Persona p) {
	if (g->numPersonas < 1) {
		g->numPersonas = 1;
		g->personas = malloc(sizeof(Persona));
		g->personas[0] = p;
	} else {
		g->numPersonas++;
		Persona *reallocPersonas = realloc(g->personas,
				sizeof(Persona) * g->numPersonas);
		g->personas = reallocPersonas;
		g->personas[g->numPersonas - 1] = p;
	}
	g->mediaEdad = (((g->numPersonas - 1) * g->mediaEdad) + p.edad)
			/ g->numPersonas; //calcularMediaGrupo(g);
}

GrupoPersonas recuperarJovenes(Persona *ap, int tamanyo) {
	GrupoPersonas g;
	g.numPersonas = 0;
	g.personas = NULL;

	for (int i = 0; i < tamanyo; i++) {
		if ((ap + i)->edad < 30) {
			anyadePersonaEnGrupo(&g, *(ap + i));
		}
	}
	return g;
}

Persona* recuperarYogurin(Persona *ap, int tamanyo) {
	int minEdad = 150, minPos = 0; //Asumo que no habra nadie con mas de 149 anyos
	for (int i = 0; i < tamanyo; i++) {
		if ((ap + i)->edad < minEdad) {
			minEdad = (ap + i)->edad;
			minPos = i;
		}
	}
	return ap + minPos;

}

void imprimirGrupoPersonas(GrupoPersonas g) {
	printf("Hay %i personas en este grupo:\n", g.numPersonas);
	for (int i = 0; i < g.numPersonas; i++) {
		printf("\t");
		imprimirPersona(g.personas[i]);
	}
	printf("La media de edad es: %f\n", g.mediaEdad);
}

int cuantosNombres(Persona *ap, int tamanyo, char letra) {
	int cont = 0;
	for (int i = 0; i < tamanyo; i++) {
		if (ap[i].nombre[0] == letra) {
			cont++;
		}
	}
	return cont;
}

char** listadoNombres(Persona *ap, int tamanyo, char letra) {
	int cont = 0;
	char **listado = NULL;
	for (int i = 0; i < tamanyo; i++) {
		if (ap[i].nombre[0] == letra) {
			cont++;
			char **reallocListado = realloc(listado, sizeof(char*) * cont);
			listado = reallocListado;
			listado[cont - 1] = ap[i].nombre;
		}
	}
	return listado;
}

