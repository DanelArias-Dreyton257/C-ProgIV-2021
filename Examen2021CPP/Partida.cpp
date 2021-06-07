/*
 * Partida.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#include "Partida.h"
#include <string.h>
#include <iostream>
using namespace std;

Partida::Partida(char *nombre, char *fecha) {
	this->nombre = strdup(nombre);
	this->fecha = strdup(fecha);
}

Partida::~Partida() {
	delete[] nombre;
	delete[] fecha;
}

Partida::Partida(const Partida &other) {
	this->nombre = strdup(other.nombre);
	this->fecha = strdup(other.fecha);
	this->numJugadores = other.numJugadores;
	this->ganador = other.ganador;
	for (int i = 0; i < other.numJugadores; i++) {
		jugadores[i] = other.jugadores[i];
	}
}
void Partida::anyadirJugador(Jugador *j) {
	if (numJugadores < 4) {
		jugadores[numJugadores] = j;
		numJugadores++;
	}
}
void Partida::imprimir() {
	cout << "PARTIDA: " << nombre << " (" << fecha << ")" << endl << "--------"
			<< endl;
	for (int i = 0; i < numJugadores; i++) {
		jugadores[i]->imprimir();
	}
	cout << "--------" << endl << "Ganador: " << ganador->getNombre() << " ("
			<< ganador->getEquipo() << ")" << endl;
}

void Partida::elegirGanador(int pos) {
	if (pos >= 0 && pos < numJugadores) {
		ganador = jugadores[pos];
	}
}

Jugador* Partida::getGanador() {
	return ganador;
}

char* Partida::getNombre() {
	return nombre;
}
char* Partida::getFecha() {
	return fecha;
}

int Partida::getPuntuacion() {
	return numJugadores;
}

