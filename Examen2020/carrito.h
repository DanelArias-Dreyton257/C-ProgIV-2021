/*
 * carrito.h
 *
 *  Created on: 15 abr. 2021
 *      Author: danel
 */

#ifndef CARRITO_H_
#define CARRITO_H_

typedef struct {
	Producto *prod;
	int cant;
} Compra;

void modificarCompra(Compra *c, int cant);
void imprimirCompra(Compra c);

typedef struct {
	Compra *compras;
	int numCompras;
	float impTotal;
} Carrito;

void crearCarrito(Carrito *c, Producto **prods, int *cants, int tamanyo);

void imprimirTicket(Carrito c);

void devolverCarrito(Carrito *c);


void modificarCarrito(Carrito *c, int ref, int cant);

#endif /* CARRITO_H_ */
