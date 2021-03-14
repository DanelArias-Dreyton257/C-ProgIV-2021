/*
 * caracteres.c
 *
 *  Created on: 22 feb. 2021
 *      Author: danel
 */
#include "caracteres.h"
#include <stdbool.h>

bool isUpperCase(char c) {
	if (c >= 65 && c <= 99) {
		return true;
	} else
		return false;
}
bool isLowerCase(char c) {
	if (c >= 97 && c <= 122) {
		return true;
	} else
		return false;
}
bool isLetter(char c) {
	if (isLowerCase(c) || isUpperCase(c)) {
		return true;
	} else
		return false;
}
bool isNumber(char c) {
	if (c >= 48 && c <= 57) {
		return true;
	} else
		return false;
}
bool isOtherCharacter(char c) {
	if (!isLetter(c) && !isUpperCase(c)) {
		return true;
	} else
		return false;
}
bool isEnter(char c) {
	if (c == '\n') {
		return true;
	} else
		return false;
}

char toUpperCase(char c) {
	if (isLowerCase(c)) {
		return c + 32;
	} else {
		return -1;
	}
}
char toLowerCase(char c) {
	if (isUpperCase(c)) {
		return c - 32;
	} else {
		return -1;
	}
}

