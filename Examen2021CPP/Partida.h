/*
 * Partida.h
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_
#include "Jugador.h"
#include <stdlib.h>

class Partida {
protected:
	Jugador *jugadores[4];
	Jugador *ganador = NULL;
	char *nombre;
	char *fecha; //"dd-mm-aaaa"
	int numJugadores = 0;
public:
	Partida(char *nombre, char *fecha);
	virtual ~Partida();
	Partida(const Partida &other);

	void anyadirJugador(Jugador *j);
	void elegirGanador(int pos);

	virtual void imprimir();
	virtual int getPuntuacion();
	char* getNombre();
	char* getFecha();
	Jugador* getGanador();
};

#endif /* PARTIDA_H_ */
