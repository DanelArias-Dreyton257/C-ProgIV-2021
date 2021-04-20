
#include "producto.h"
#include <stdio.h>
#include "carrito.h"
#include <stdlib.h>


void modificarCompra(Compra *c, int cant){
	c->cant = cant;
}


void imprimirCompra(Compra c){
	printf("Ref.%i %s %.2f x %i kg/ud\n",c.prod->ref, c.prod->nombre, c.prod->precio, c.cant);
}

void crearCarrito(Carrito *c, Producto **prods, int *cants, int tamanyo){
	c->compras = malloc(sizeof(Compra)*tamanyo);
	c->numCompras = tamanyo;
	for(int i = 0; i<tamanyo; i++){
		c->compras[i].prod = prods[i];
		c->compras[i].cant = cants[i];
		c->impTotal+= (prods[i]->precio * cants[i]);
	}
}

void imprimirTicket(Carrito c){
	printf("TICKET\n------\n");
	for (int i = 0; i<c.numCompras; i++){
		imprimirCompra(c.compras[i]);
	}
	printf("--------------------\nTOTAL: %.2f euros\n",c.impTotal);

}

void liberarCompra(Compra * c){
	free(c->prod);
}

void devolverCarrito(Carrito *c){
	for(int i = 0; i< c->numCompras; i++){
		liberarCompra(&(c->compras[i]));
	}
	free(c->compras);
}

void modificarCarrito(Carrito *c, int ref, int cant){
	c->impTotal = 0;
	for(int i = 0; i< c->numCompras; i++){
		if(c->compras[i].prod->ref == ref){
			c->compras[i].cant = cant;
		}
		c->impTotal+= c->compras[i].prod->precio * c->compras[i].cant;
	}
}
