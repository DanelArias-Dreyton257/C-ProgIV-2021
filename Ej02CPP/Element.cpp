/*
 * Element.cpp
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#include "Element.h"
#include <stdlib.h>
using namespace containers;

containers::Element::Element(int data) {
	this->data = data;
	this->next = NULL;
}
int containers::Element::getData() {
	return this->data;
}
void containers::Element::setNext(Element *e) {
	this->next = next;
}
containers::Element* containers::Element::getNext() const {
	return this->next;
}

