/*
 * censo.h
 *
 *  Created on: 13 abr. 2021
 *      Author: danel
 */

#ifndef CENSO_H_
#define CENSO_H_

#include "persona.h"

typedef struct{
	int numPersonas;
	Persona *personas;
	float mediaEdad;
} GrupoPersonas;

int cuantasPersonas(Persona *ap, int tamanyo, int edad);
GrupoPersonas recuperarJovenes(Persona *ap, int tamanyo);
Persona* recuperarYogurin(Persona *ap, int tamanyo);
void imprimirGrupoPersonas(GrupoPersonas g);

int cuantosNombres(Persona *ap, int tamanyo, char letra);
char** listadoNombres(Persona *ap, int tamanyo, char letra);

#endif /* CENSO_H_ */
