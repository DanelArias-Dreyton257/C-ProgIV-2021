/*
 * Jugador.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#include "Jugador.h"
#include <string.h>
#include <iostream>

using namespace std;

Jugador::Jugador(Usuario *u, char *equipo) {
	this->u = u;
	this->equipo = strdup(equipo);
}

Jugador::~Jugador() {
	delete[] equipo;
}

Jugador::Jugador(const Jugador &other) {
	this->u = other.u;
	this->equipo = strdup(other.equipo);
}

char* Jugador::getEquipo() {
	return equipo;
}
char* Jugador::getNombre() {
	return u->getNombre();
}

void Jugador::imprimir() {
	cout << "Jugador (" << equipo << "): " << u->getNombre() << endl;
}
Usuario* Jugador::getUsuario() {
	return u;
}

