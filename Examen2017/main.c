#include "persona.h"
#include "censo.h"
#include "fichero.h"
#include <stdio.h>
#include <stdlib.h>

int edadJovenes = 15;
void gestionaArgumentos(int argc, char **argv);

int main(int argc, char **argv) {

	gestionaArgumentos(argc, argv);

	Persona personas[5];
	personas[0].nombre = "Hodei";
	personas[0].edad = 6;
	personas[1].nombre = "Anita";
	personas[1].edad = 41;
	personas[2].nombre = "Aitor";
	personas[2].edad = 12;
	personas[3].nombre = "Idoia";
	personas[3].edad = 31;
	personas[4].nombre = "Maite";
	personas[4].edad = 24;

	//PARTE 1-------------------------------------------------------------------------------------
	int n = cuantasPersonas(personas, 5, edadJovenes);
	printf("Personas menores de %i: %i\n", edadJovenes, n);
	GrupoPersonas g = recuperarJovenes(personas, 5);
	printf("Grupo personas jovenes:\n");
	imprimirGrupoPersonas(g);
	printf("Persona mas joven:\n\t");
	imprimirPersona(*recuperarYogurin(personas, 5));

	//PARTE 2 -------------------------------------------------------------------------------------
	crearInforme(g, "ficheroJovenes.txt");

	//PARTE 3 -------------------------------------------------------------------------------------
	char c = 'A';
	char **listado = listadoNombres(personas, 5, c);
	int m = cuantosNombres(personas, 5, c);
	printf("Los nombres que empiezan por %c son %i:\n", c, m);
	for (int i = 0; i < m; i++) {
		printf("\t%s\n", listado[i]);
	}

	//LIBERAR---------------------------------------------------------------------------------------
	free(g.personas);
	free(listado);

	return 0;
}

void gestionaArgumentos(int argc, char **argv) {
	if (argc <= 1) {
		return;
	}
	int convertedArg = atoi(argv[1]);
	if (convertedArg == 0) {
		return;
	}
	edadJovenes = convertedArg;
}
