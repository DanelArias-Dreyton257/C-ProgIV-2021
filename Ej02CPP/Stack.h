/*
 * Stack.h
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#ifndef STACK_H_
#define STACK_H_
#include "Element.h"

namespace containers {
class Stack {
private:
	Element *first;
	unsigned int size;
public:
	Stack();
	~Stack();
	void push(int dato);
	int pop();
	int poll();
	void clear();
	unsigned int getSize();
};
}
#endif /* STACK_H_ */
