/*
 * Element.h
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

namespace containers {
class Element {
private:
	int data;
	Element *next;
public:
	Element(int data);
	int getData();
	void setNext(Element *e);
	Element* getNext() const;
};
}
#endif /* ELEMENT_H_ */
