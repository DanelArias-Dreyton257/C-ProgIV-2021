/*
 * Jugador.h
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Usuario.h"

class Jugador {
private:
	Usuario *u;
	char *equipo;
public:
	Jugador(Usuario *u, char *equipo);
	virtual ~Jugador();
	Jugador(const Jugador &other);
	void imprimir();

	char* getNombre();
	char* getEquipo();
	Usuario* getUsuario();
};

#endif /* JUGADOR_H_ */
