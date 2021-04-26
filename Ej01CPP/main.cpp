/*
 * main.cpp
 *
 *  Created on: 26 abr. 2021
 *      Author: danel
 */
#include "ArrayInt.h"
using namespace containers;

int main(int argc, char **argv) {
	ArrayInt arr(20); //Estatica
	ArrayInt *arrP = new ArrayInt(); //Dinamica

	for (unsigned int i = 0; i < arr.getCapacity(); i++) {
		arr.setValue(i, i + 1);
	}

	for (unsigned int i = 0; i < arrP->getCapacity(); i++) {
		arrP->setValue(i, i + 1);
	}

	arr.imprimir();
	arrP->imprimir();

	delete arrP; //Libera la memoria del objeto

	return 0;

}

