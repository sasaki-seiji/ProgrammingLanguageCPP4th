/*
 * user.cpp
 *
 *  Created on: 2016/09/05
 *      Author: sasaki
 */


#include "Shape.h"
#include <typeinfo>
#include <iostream>
using namespace std;

void rotate(Shape& r)
{
	if (typeid(r) == typeid(Circle)) {
		static_cast<Circle&>(r).rotate();
	}
	else if (typeid(r) == typeid(Triangle)) {
		static_cast<Triangle&>(r).rotate();
	}
	else if(typeid(r) == typeid(Square))
	{
		static_cast<Square&>(r).rotate();
	}
}


void test_shape(Shape& s)
{
	cout << "-- test_shape(Shape&) --\n";
	s.draw();
	rotate(s);
	s.draw();
}

// add main

int main()
{
	Circle c{{1,2},10};
	Triangle t{{1,2},{3,4},{5,6}};
	Square s{10,20,3,6};

	test_shape(c);
	test_shape(t);
	test_shape(s);
}
