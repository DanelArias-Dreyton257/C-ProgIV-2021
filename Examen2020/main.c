#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "carrito.h"

void leerProductos(Producto *productos[], char *fichero);

int main(void) {
	Producto p1;
	p1.ref = 1;
	strcpy(p1.nombre, "Platanos");
	p1.precio = 12.0;
	Producto p2;
	p2.ref = 2;
	strcpy(p2.nombre, "Solomillo");
	p2.precio = 32.2;
	Producto p3;
	p3.ref = 3;
	strcpy(p3.nombre, "Chocolate");
	p3.precio = 25.5;
	Producto p4;
	p4.ref = 4;
	strcpy(p4.nombre, "Rodaballo");
	p4.precio = 35.4;
	Producto p5;
	p5.ref = 5;
	strcpy(p5.nombre, "Cereales");
	p5.precio = 10.5;

	imprimirProducto(p1);

	Producto *comprados[] = { &p1, &p2, &p3, &p4, &p5 };

	//PARTE 1 ---------------------------------------------------------
	Compra c = { &p2, 3 };
	printf("ANTES de la modificación de la compra…\n");
	imprimirCompra(c);
	printf("DESPUES de la modificación de la compra…\n");
	modificarCompra(&c, 0);
	imprimirCompra(c);

	//PARTE 2 --------------------------------------------------------
	Carrito *car = malloc(sizeof(Carrito));
	int cants[] = { 1, 3, 5, 7, 9 };
	crearCarrito(car, comprados, cants, 5);
	imprimirTicket(*car);
	//devolverCarrito(car);

	//PARTE 3-------------------------------------------------------
	printf("Carrito modificado:\n");
	modificarCarrito(car, 3, 0);
	imprimirTicket(*car);

	devolverCarrito(car);

	//Producto **lista = malloc(sizeof(Producto*)*5);
	//leerProductos(lista, "productos.txt");

	return 0;
}
Producto* listaStringToProducto(char **lista) {
	return NULL;
}

void leerProductos(Producto *productos[], char *fichero) {
	FILE *f = fopen(fichero, "r");
	char leido = fgetc(f);
	while (leido != EOF) {

		int cont = 1;
		char ref;
		char nombre[14+1];
		char precio[5+1];
		while (leido != '\n') {
			if (cont < 2) {
				ref = leido;
			}
			else if(cont>1 && cont<16){
				nombre[cont-2] = leido;
				if (cont==15){
					nombre[cont-1] = '\0';
				}
			}
			else if(cont>15 && cont<21){
				precio[cont-16] = leido;
				if (cont==20){
					precio[cont-15] = '\0';
				}
			}

			cont++;
			leido = fgetc(f);
		}
		cont = 1;
		printf("Ref:%c, Nombre: %s, Precio: %s",ref,nombre,precio);
		fflush(stdout);
		leido = fgetc(f);

	}
	fclose(f);

}
