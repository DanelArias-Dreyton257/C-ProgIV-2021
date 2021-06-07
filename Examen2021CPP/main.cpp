/**
 * Danel Arias Alamo
 * 07 / 06 / 2021
 */

#include "Usuario.h"
#include "Partida.h"
#include "Tablero.h"
#include <string.h>

#include <iostream>
using namespace std;

Partida* mejorPartida(Partida **partidas, int numPartidas);
void historialVictorias(Partida **partidas, int numPartidas, Usuario &u);

int main(int argc, char **argv) {
	Usuario ana((char*) "Ana Perez", 30 /*años*/);
	Usuario marta((char*) "Marta Canta", 48);
	Usuario fran((char*) "Fran Paz", 22);
	Usuario oneka((char*) "Oneka Baila", 10);

	cout << ana.getNombre() << " os reta a una partida." << endl;

	//PARTE 1-------------------------------------------------------------

	Partida p1((char*) "Mus", (char*) "28-05-2021");
	p1.anyadirJugador(new Jugador(&ana, (char*) "A"));
	p1.anyadirJugador(new Jugador(&marta, (char*) "B"));
	p1.elegirGanador(0);

	Partida p2((char*) "Trivial", (char*) "29-05-2021");
	p2.anyadirJugador(new Jugador(&fran, (char*) "Rojo"));
	p2.anyadirJugador(new Jugador(&marta, (char*) "Azul"));
	p2.anyadirJugador(new Jugador(&ana, (char*) "Verde"));
	p2.elegirGanador(1);

	cout << "========" << endl;
	p1.imprimir();
	cout << "========" << endl;
	p2.imprimir();

	//PARTE 2---------------------------------------------------------------
	Tablero p3((char*) "Ajedrez", (char*) "30-05-2021");
	p3.anyadirJugador(new Jugador(&oneka, (char*) "Blancas"));
	p3.anyadirJugador(new Jugador(&ana, (char*) "Negras"));
	p3.elegirGanador(1);

	p3.anadirSgteMovimiento((char*) "Mov1");
	p3.anadirSgteMovimiento((char*) "Mov2");
	p3.anadirSgteMovimiento((char*) "Mov3");
	p3.anadirSgteMovimiento((char*) "Mov4");

	cout << "========" << endl;
	p3.imprimir();

	//PARTE 3-----------------------------------------------------------------
	int numPartidas = 3;
	Partida **partidas = new Partida*[numPartidas];
	partidas[0] = &p1;
	partidas[1] = &p2;
	partidas[2] = &p3;
	Partida *mejor = mejorPartida(partidas, numPartidas);

	cout << endl << endl << "La partida mejor valorada es "
			<< mejor->getNombre() << " con " << mejor->getPuntuacion()
			<< " puntos" << endl;

	cout << endl << endl;
	historialVictorias(partidas, numPartidas, ana);

	delete[] partidas;

	return 0;
}

void historialVictorias(Partida **partidas, int numPartidas, Usuario &u) {
	cout << "VICTORIAS (" << u.getNombre() << ")" << endl
			<< "------------------------------" << endl;

	for (int i = 0; i < numPartidas; i++) {

		if (*(partidas[i]->getGanador()->getUsuario()) == u) { //Comprueba si el usuario es el mismo atraves de la sobrecarga del operador ==

			cout << partidas[i]->getNombre() << " (" << partidas[i]->getFecha()
					<< ") con " << partidas[i]->getPuntuacion() << " puntos"
					<< endl;
		}

	}
}

Partida* mejorPartida(Partida **partidas, int numPartidas) {
	int maxP = 0;
	Partida *pMax = NULL;

	if (numPartidas >= 1) {
		maxP = partidas[0]->getPuntuacion();
		pMax = partidas[0];

		for (int i = 1; i < numPartidas; i++) {
			int actualP = partidas[i]->getPuntuacion();
			if (actualP > maxP) {
				maxP = actualP;
				pMax = partidas[i];
			}
		}
	}
	return pMax;
}
