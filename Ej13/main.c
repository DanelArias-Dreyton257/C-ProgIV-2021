#include <stdio.h>
#include "string.h"

int main(int argc, char **argv) {

	char *h = "Marcos";
	char *c = clonar("Fernandito es ");
	concat(c,h);
	//char *c1 = "Lucas";
	imprimir(c);
	//printf("%i", longitud(c1));
}
