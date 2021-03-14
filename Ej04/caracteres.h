/*
 * caracteres.h
 *
 *  Created on: 22 feb. 2021
 *      Author: danel
 */

#ifndef CARACTERES_H_
#define CARACTERES_H_

#include <stdbool.h>

bool isUpperCase(char c);
bool isLowerCase(char c);
bool isLetter(char c);
bool isNumber(char c);
bool isOtherCharacter(char c);
bool isEnter(char c);

char toUpperCase(char c);
char toLowerCase(char c);

#endif /* CARACTERES_H_ */
