/*
 * Stack.cpp
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#include "Stack.h"
#include <stdlib.h>
using namespace containers;

Stack::Stack() {
	this->first = NULL;
	this->size = 0;
}

Stack::~Stack() {
	delete first;
}

void Stack::push(int dato) {
	Element *e = new Element(dato);
	e->setNext(first);
	first = e;
}
int Stack::pop() {
	int value = first->getData();
	first = first->getNext();
	return value;
}
int Stack::poll() {
	return pop(); //No entiendo la diferencia entre pop y poll
}
void Stack::clear() {
	delete this;
}
unsigned int Stack::getSize() {
	return size;
}

