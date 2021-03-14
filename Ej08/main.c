/*
 * main.c
 *
 *  Created on: 25 feb. 2021
 *      Author: danel
 */
//SIN TERMINAR
typedef struct{
	float r;
	float i;
}Complex;

Complex suma (Complex c1, Complex c2){
	Complex c;
	c.r = c1.r + c2.r;
	c.i = c1.i + c2.i;
	return c;
}
void printComplex(Complex c){
	printf("(%i,%i)",c.r,c.i);
}

int main(int argc, char **argv) {
	Complex c1;
	c1.r = 1;
	c1.i = 10;

	return 0;
}



