/*
 * main.c
 *
 *  Created on: 19 feb. 2021
 *      Author: danel
 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) { //FIXME

	char l;

	    do
	    {
	        l = getchar();
	        if (l != '\n')
	        {
	            printf("Has introducido la letra: %c. (Mayus: %c) ASCII = %i\n", l, toupper(l), l);
	            fflush(stdout);
	        }
	    } while (l != 'q');

	return 0;
}

