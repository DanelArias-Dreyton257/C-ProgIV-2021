/*
 * ArrayList.h
 *
 *  Created on: 26 abr. 2021
 *      Author: danel
 */

#ifndef ARRAYINT_H_
#define ARRAYINT_H_

#define DEFAULT_SIZE 10

namespace containers {
class ArrayInt {
private:
	unsigned int capacity;
	int *array;
public:
	ArrayInt();
	ArrayInt(unsigned int capacity);
	~ArrayInt();
	void setValue(unsigned int index, int data);
	int getValue(unsigned int index);
	void setCapacity(unsigned int capacity);
	unsigned int getCapacity();
	void imprimir();
};
}
#endif /* ARRAYINT_H_ */
