/*
 * Point.h
 *
 *  Created on: 29 abr. 2021
 *      Author: danel
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	float x, y;
public:
	Point(int x, int y);
	Point(const Point &other);

	void suma1(Point p);
	void suma2(Point &p);
	void suma3(Point *p);
	Point getSuma(Point &p);
	void print();

	void swap1(Point p);
	void swap2(Point &p);
	void swap3(Point *p);

	void setX(float x);
	void setY(float y);
	float getX() const;
	float getY() const;
	void sumar(const Point &p);
};

#endif /* POINT_H_ */
