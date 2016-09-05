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

void rotate(const Shape& r)
{
	if (typeid(r) == typeid(Circle)) {
		cout << "rotate Circle\n";
	}
	else if (typeid(r) == typeid(Triangle)) {
		cout << "rotate Triangle\n";
	}
	else if(typeid(r) == typeid(Square))
	{
		cout << "rotate Square\n";
	}
}


void test_shape(Shape& s)
{
	s.draw();
	rotate(s);
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
