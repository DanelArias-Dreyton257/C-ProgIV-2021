//Examen realizado el 04/05/2021

//Autor: Danel Arias

#include "universidad.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//PARTE INICIAL---------------------------------------------------------------------------------
	Alumno a1 = { "11111111A", "Erika Regales" };
	Alumno a2 = { "22222222B", "Pedro Delgado" };
	Alumno a3 = { "33333333C", "Oneka Sanchez" };

	imprimirAlumno(a1);
	printf("\n");

	//PARTE 1-----------------------------------------------------------------------------------------

	printf("\n");
	printf("\n");

	Asignatura prog4 = { 0, 0, "Prog4", NULL, NULL }; //Definicion de la asignatura

	setNumeroPlazas(&prog4, 4); //Establecer el numero de plazas

	//Matricular los alumnos
	matricularAlumno(&prog4, &a1);
	matricularAlumno(&prog4, &a2);
	matricularAlumno(&prog4, &a3);

	//Imprimir los matriculados
	imprimirMatriculados(prog4);
	printf("\n");

	//Buscar al alumno por DNI
	printf("BUSCADO: ");
	imprimirAlumno(*buscarAlumnoPorDNI(&prog4, "22222222B"));

	//PARTE 2---------------------------------------------------------------------------------------
	printf("\n");
	printf("\n");

	pedirNotasPorTeclado(&prog4); //Pedir las notas por teclado

	printf("\n");
	printf("\n");

	//Imprimir las notas
	imprimirNotas(prog4);
	printf("\n");

	//Sacar la media de las notas
	printf("MEDIA: %.2f",calcularNotaMedia(prog4));

	liberarAsignatura(&prog4);

	return 0;
}
