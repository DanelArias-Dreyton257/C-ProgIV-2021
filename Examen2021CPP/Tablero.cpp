/*
 * Tablero.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#include "Tablero.h"
#include "Partida.h"
#include <string.h>
#include <iostream>
using namespace std;

Tablero::Tablero(char *nombre, char *fecha) :
		Partida(nombre, fecha) {
	// TODO Auto-generated constructor stub
}

Tablero::~Tablero() {
	for (int i = 0; i < numMovimientos; i++) {
		delete[] movimientos[i];
	}
	delete[] movimientos;
}

Tablero::Tablero(const Tablero &other) :
		Partida(other) {
	this->movimientos = new char*[other.numMovimientos];
	this->numMovimientos = other.numMovimientos;
	for (int i = 0; i < other.numMovimientos; i++) {
		this->movimientos[i] = strdup(other.movimientos[i]);
	}
}

void Tablero::anadirSgteMovimiento(char *mov) {
	//Hacer la copia en temp
	char **temp = new char*[numMovimientos + 1];
	for (int i = 0; i < numMovimientos; i++) {
		temp[i] = strdup(movimientos[i]);
	}
	temp[numMovimientos] = strdup(mov);

	//Liberar la memoria anteriormente reservada
	for (int i = 0; i < numMovimientos; i++) {
		delete[] movimientos[i];
	}
	delete[] movimientos;

	//Asignar temp a movimientos
	this->movimientos = temp;
	numMovimientos++;
}

void Tablero::imprimir() {
	Partida::imprimir();
	cout << "--------" << endl << "Movimientos:" << endl << "--------" << endl;
	for (int i = 0; i < numMovimientos; i++) {
		cout << i + 1 << ". " << movimientos[i] << endl;
	}
	cout << "--------" << endl;
}

int Tablero::getPuntuacion() {
	return Partida::getPuntuacion() + numMovimientos;
}

