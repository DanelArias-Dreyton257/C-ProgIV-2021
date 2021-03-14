
/*
 * main.c
 *
 *  Created on: 19 feb. 2021
 *      Author: danel
 */
#include <stdio.h>
#include <ctype.h>
#include "caracteres.h"

int main(int argc, char **argv) { //FIXME

	char l;

	    do
	    {
	        l = getchar();
	        if (!isEnter(l))
	        {
	        	if (isLetter(l)){
	        		printf("Has introducido la letra: %c. (Mayus: %c) ASCII = %i\n", l, toupper(l), l);
	        	}
	        	else if (isNumber(l)){
	        		printf("Has introducido el numero: %c. ASCII = %i\n", l, l);
	        	}
	        	else {
	        		printf("Has introducido el caracter especial de ASCII = %i\n", l);
	        	}

	            fflush(stdout);
	        }
	    } while (l != 'q');

	return 0;
}



