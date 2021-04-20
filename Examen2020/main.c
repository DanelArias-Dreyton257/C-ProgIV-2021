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

	//PARTE 3.2-----------------------------------------------------------------
	leerProductos(comprados, "productos.txt");

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

	//PARTE 3.1-------------------------------------------------------
	printf("Carrito modificado:\n");
	modificarCarrito(car, 3, 0);
	imprimirTicket(*car);

	devolverCarrito(car);


	return 0;
}
Producto* listaStringToProducto(char **lista) {
	return NULL;
}

void leerProductos(Producto *productos[], char *fichero) {
	FILE *f = fopen(fichero, "r");
	char leido = fgetc(f);
	int contPosiciones = 0;
	while (leido != EOF) {

		int contLetras = 1;
		char ref;
		char nombre[14+1];
		char precio[5+1];
		while (leido != '\n') {
			if (contLetras < 2) {
				ref = leido;
			}
			else if(contLetras>1 && contLetras<16){
				nombre[contLetras-2] = leido;
				if (contLetras==15){
					nombre[contLetras-1] = '\0';
				}
			}
			else if(contLetras>15 && contLetras<21){
				precio[contLetras-16] = leido;
				if (contLetras==20){
					precio[contLetras-15] = '\0';
				}
			}

			contLetras++;
			leido = fgetc(f);
		}
		contLetras = 1;

		//printf("Ref:%c, Nombre: %s, Precio: %s\n",ref,nombre,precio);
		Producto *p = malloc(sizeof(Producto));
		p->ref = ref - '0';
		strcpy(p->nombre,nombre);
		p->precio = atof(precio);
		productos[contPosiciones] = p;
		contPosiciones++;

		fflush(stdout);
		leido = fgetc(f);

	}
	fclose(f);

}
