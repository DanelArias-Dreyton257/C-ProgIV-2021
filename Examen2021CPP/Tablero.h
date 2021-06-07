/*
 * Tablero.h
 *
 *  Created on: 7 jun. 2021
 *      Author: danel.arias
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Partida.h"

class Tablero: public Partida {
private:
	char **movimientos = NULL;
	int numMovimientos = 0;
public:
	Tablero(char *nombre, char *fecha);
	virtual ~Tablero();
	Tablero(const Tablero &other);

	void anadirSgteMovimiento(char *mov);
	void imprimir();
	int getPuntuacion();
};

#endif /* TABLERO_H_ */
