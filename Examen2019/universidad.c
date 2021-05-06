#include "universidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Imprime la informacion del alumno por consola
 */
void imprimirAlumno(Alumno a) {
	printf("%s (%s)\n", a.nombre, a.dni);
}
/**
 * Asigna el numero de plazas que estara disponible en esa asignatura reservando la memoria correpondiente
 */
void setNumeroPlazas(Asignatura *asig, int numAlumn) {
	asig->numPlazas = numAlumn;
	asig->alumnos = malloc(sizeof(Alumno) * numAlumn);
	asig->notas = malloc(sizeof(Nota) * numAlumn);
}
/**
 * Anyade un alumno a la lista de alumnos  matriculados de la asignatura si y solo si hay plazas suficientes
 */
void matricularAlumno(Asignatura *asig, Alumno *al) {
	if (asig->numAlumnos < asig->numPlazas) {
		asig->alumnos[asig->numAlumnos] = *al;
		asig->numAlumnos += 1;
		return;
	}
	printf("No hay espacio suficiente para matricular al alumno");
}
/**
 * Imprime los alumno mattriculados en la asignatura indicada por consola
 */
void imprimirMatriculados(Asignatura asig) {
	printf("ASIGNATURA: %s (%i plazas)\n", asig.nombre, asig.numPlazas);
	printf("Matriculados:\n-------------\n");
	for (int i = 0; i < asig.numAlumnos; i++) {
		imprimirAlumno(asig.alumnos[i]);
	}
}
/**
 *  METODO PRIVADO
 *  Devuelve la posicion de la array en la que se encuentra en alumno buscado por dni
 *  devuelve -1 si no se encuentra
 */
int buscarPosAlumnoPorDNI(Asignatura *asig, char *dni) {
	for (int i = 0; i < asig->numAlumnos; i++) {
		if (strcmp(asig->alumnos[i].dni, dni) == 0) {
			return i;
		}
	}
	return -1;
}
/**
 * Devuelve la un puntero alumno buscado por dni de la asignatura
 */
Alumno* buscarAlumnoPorDNI(Asignatura *asig, char *dni) {
	int p = buscarPosAlumnoPorDNI(asig, dni);
	if (p >= 0) {
		return asig->alumnos + p;
	}
	return NULL;
}
/**
 * Anyade la nota al alumno correspondiente segun el dni
 */
void anyadirNota(Asignatura *asig, char *dni, float valor) {
	int p = buscarPosAlumnoPorDNI(asig, dni);
	if (p >= 0) {
		asig->notas[p].nota = valor;
		strcpy(asig->notas[p].dni, dni);
	}
}
/**
 * Imprime las notas de os estudiantes en la asignatura
 */
void imprimirNotas(Asignatura asig) {
	printf("ASIGNATURA: %s (%i plazas)\n", asig.nombre, asig.numPlazas);

	printf("Notas:\n-------------\n");

	for (int i = 0; i < asig.numAlumnos; i++) {

		printf("%s	", asig.alumnos[i].nombre);

		//Depende de si se ha presentado o no
		if (asig.notas[i].nota >= 0) {
			printf("%.2f\n", asig.notas[i].nota);
		} else {
			printf("NP\n");
		}
	}
}
/**
 * Calcula la nota media de los alumnos que se hayan presentado
 */
float calcularNotaMedia(Asignatura asig) {
	float sum = 0;
	int num = 0;
	for (int i = 0; i < asig.numAlumnos; i++) {
		if (asig.notas[i].nota >= 0) {
			sum += asig.notas[i].nota;
			num++;
		}
	}
	return sum / num;
}
/**
 * Libera la memoria reservada en la estructura asignatura
 */
void liberarAsignatura(Asignatura *asig) {
	free(asig->alumnos);
	free(asig->notas);
}
/**
 * METODO PRIVADO
 * Devuelve el float leido por consola
 */
float getFloatInput() {
	fflush(stdin); //Para que no haya problemas con la consola de eclipse
	float f;
	scanf("%f", &f);
	return f;
}
/**
 * Pide las notas de cada alumno de la asignatura uno a uno y se las anyade
 */
void pedirNotasPorTeclado(Asignatura *asig) {
	printf("INTRODUCE LAS NOTAS DE TUS ALUMNOS (%s)\n", asig->nombre);

	for (int i = 0; i < asig->numAlumnos; i++) {

		printf("%s (%s): ", asig->alumnos[i].nombre, asig->alumnos[i].dni);
		fflush(stdout); //Para que no haya problemas con la consola de eclipse
		anyadirNota(asig,asig->alumnos[i].dni , getFloatInput());
	}
}

