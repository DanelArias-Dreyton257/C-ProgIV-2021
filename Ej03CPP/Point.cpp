/*
 * Point.cpp
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point &other) {
	this->x = other.x;
	this->y = other.y;
}

void Point::suma1(Point p) {
	this->suma2(p);
}
void Point::suma2(Point &p) {
	this->suma3(&p);
}
void Point::suma3(Point *p) {
	this->x += p->x;
	this->y += p->y;
}
Point Point::getSuma(Point &p) {
	return *(new Point(this->x + p.x, this->y + p.y));
}
void Point::print() {
	cout << "[" << x << ", " << y << "]\n";
}

void Point::swap1(Point p) {
	this->swap2(p);
}
void Point::swap2(Point &p) {
	this->swap3(&p);
}
void Point::swap3(Point *p) {
	Point tmp = *this;
	*this = *p;
	*p = tmp;
}

