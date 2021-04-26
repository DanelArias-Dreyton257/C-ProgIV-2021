/*
 * ArrayList.cpp
 *
 *  Created on: 26 abr. 2021
 *      Author: danel
 */
#include "ArrayInt.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace containers;

ArrayInt::ArrayInt() {
	this->array = (int*) malloc(sizeof(int) * DEFAULT_SIZE);
	this->capacity = DEFAULT_SIZE;
	for (unsigned int i = 0; i < capacity; i++) {
		array[i] = 0;
	}
}
ArrayInt::ArrayInt(unsigned int capacity) {
	this->array = (int*) malloc(sizeof(int) * capacity);
	this->capacity = capacity;
	for (unsigned int i = 0; i < capacity; i++) {
		array[i] = 0;
	}
}
ArrayInt::~ArrayInt() {
	free(array);
}
void ArrayInt::setValue(unsigned int index, int data) {
	if (index >= 0 && index < capacity) {
		array[index] = data;
	}
}
int ArrayInt::getValue(unsigned int index) {
	if (index >= 0 && index < capacity) {
		return array[index];
	}
	return 0;
}
void ArrayInt::setCapacity(unsigned int capacity) {
	int *reArray = (int*) realloc(array, sizeof(int) * capacity);
	array = reArray;
	for (unsigned int i = this->capacity; i < capacity; i++) {
		array[i] = 0;
	}
	this->capacity = capacity;
}
unsigned int ArrayInt::getCapacity() {
	return capacity;
}
void ArrayInt::imprimir() {
	cout << "[";
	for (unsigned int i = 0; i < capacity - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[capacity - 1] << "]\n";
}
