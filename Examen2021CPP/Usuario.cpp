
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "Usuario.h"
using namespace std;

Usuario::Usuario() {
	this->edad = 0;
	this->nombre = new char[1];
	this->nombre[0] = '\0';
}
Usuario::Usuario(const char *nombre, int edad) {
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->edad = edad;
}
Usuario::Usuario(const Usuario &p) {
	this->nombre = new char[strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);
	this->edad = p.edad;
}
Usuario::~Usuario() {
	delete[] this->nombre;
}
char* Usuario::getNombre() const {
	return this->nombre;
}
int Usuario::getEdad() const {
	return this->edad;
}
void Usuario::setNombre(const char *nombre) {
	delete[] this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}
void Usuario::setEdad(int edad) {
	this->edad = edad;
}
bool Usuario::operator==(const Usuario &u) {
	return strcmp(this->nombre, u.nombre) == 0;
}
