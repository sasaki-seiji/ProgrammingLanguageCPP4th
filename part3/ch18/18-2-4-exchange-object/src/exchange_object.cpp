/*
 * exchange_object.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int xx, int yy) :x{xx}, y{yy} { }
	void operator+=(Point);
	friend ostream& operator<<(ostream&, Point);
};

void Point::operator+=(Point delta)
{
	x += delta.x;
	y += delta.y;
}

ostream& operator<<(ostream& os, Point pt)
{
	os << "(" << pt.x << ", " << pt.y << ")";
	return os;
}

// add main

int main()
{
	Point a{10,20};
	Point delta{3, -5};

	a += delta;
	cout << "a+=delta: " << a << '\n';

	Matrix m1{2,3}, m2{2,3};
	for (int r=0; r<2; ++r) {
		for (int c=0; c<3; ++c) {
			m1.at(r,c) = r+c;
			m2.at(r,c) = r*c+1;
		}
	}

	cout << "m1:\n";
	cout << m1 << '\n';

	cout << "m2:\n";
	cout << m2 << '\n';

	Matrix m3 = m1+m2;
	cout << "m3(m1+m2):\n";
	cout << m3 << '\n';
}


