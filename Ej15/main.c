/*
 * main.c
 *
 *  Created on: 21 mar. 2021
 *      Author: danel
 */
#include <stdio.h>
#include <stdlib.h>

void menu();
void printOpciones(char *ops[], int size);
char getCharInput();
int getIntInput();
float getFloatInput();
void introducirAsig();
void mostrarAsig();
float calcularMedia();
char* getStringInput(int numChars);
void liberarMemoria();

typedef struct {
	char *nombre;
	int id;
	float nota;
} Asignatura;

#define MAX_ASIG 5

Asignatura asigs[MAX_ASIG];

int numAsigMetidas = 0;

int main(int argc, char **argv) {
	menu();
	liberarMemoria();
	return 0;
}

void menu() {

	//Define e imprime el menu
	char *titulo = "\nMenu";
	char *ops[] =
			{ "Introducir asignatura", "Mostrar listado", "Calcular media" };
	char *msg = "\nIntroduce tu seleccion (1-3):\nPulsa 'q' para salir.\n";

	printf("%s", titulo);
	printOpciones(ops, 3);
	printf("%s", msg);

	//Recoge la eleccion del usuario
	char s = getCharInput();

	//Segun la eleccion del usuario cambia el procedimiento
	switch (s) {
	default: //Si el usuario introduce algo no valido
		return;
	case '1':
		introducirAsig();
		menu();
		break;
	case '2':
		mostrarAsig();
		menu();
		break;
	case '3':
		printf("La media de las asignaturas es: %f\n", calcularMedia());
		menu();
		break;
	case 'q':
		break;
	}
}
void introducirAsig() {
	if (numAsigMetidas < MAX_ASIG) {
		printf("\nIntroduce el id de la asignatura (int):\n");
		int id = getIntInput();

		printf("\nIntroduce el nombre de la asignatura:\n");
		char *nom = getStringInput(25);

		printf("\nIntroduce la nota de la asignatura (sobre 10):\n");
		float nota = getFloatInput();

		asigs[numAsigMetidas] = (Asignatura ) { nom, id, nota };
		numAsigMetidas++;

	} else {
		printf("\nLimite de asignaturas superado");
	}
}

void mostrarAsig() {
	printf("\n");
	for (int i = 0; i < numAsigMetidas; i++) {
		printf("%i.%s,ID:%i,Nota:%f\n", i, asigs[i].nombre, asigs[i].id,
				asigs[i].nota);
	}
}

float calcularMedia() {
	if (numAsigMetidas > 0) {
		float sum = 0;
		for (int i = 0; i < numAsigMetidas; i++) {
			sum += asigs[i].nota;
		}
		return (sum / numAsigMetidas);
	} else
		return 0;
}

void printOpciones(char *ops[], int size) {
	for (int i = 0; i < size; i++) {
		printf("\n\t%i.%s", i + 1, ops[i]);
	}
}
char getCharInput() {
	char chr;
	fflush(stdin);
	scanf("%c", &chr);
	return chr;
}
int getIntInput() {
	int i;
	fflush(stdin);
	scanf("%i", &i);
	return i;
}
float getFloatInput() {
	float f;
	fflush(stdin);
	scanf("%f", &f);
	return f;
}
char* getStringInput(int numChars) {
	fflush(stdin);
	char *str = malloc(sizeof(char) * (numChars + 1));
	fgets(str, numChars, stdin);
	sscanf(str, "%s", str);
	return str;
}
void liberarMemoria() {
	for (int i = 0; i < numAsigMetidas; i++) {
		free(asigs[i].nombre);
	}
}
