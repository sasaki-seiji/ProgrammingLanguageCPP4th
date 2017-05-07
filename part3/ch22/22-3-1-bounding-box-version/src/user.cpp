/*
 * user.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */


#include "Shape.h"
#include <vector>
#include <iostream>
using namespace std;

void test(Triangle& t, Circle& c)
{
	cout << "-- test(Triangle&: " << t << ", Circle&: " << c << ") --\n";

	vector<pair<Shape*,Shape*>> vs { {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c} };
	cout << boolalpha;
	for (auto p : vs) {
		bool b = intersect(*p.first,*p.second);
		cout << "intercected ? " << b << endl;
	}
}

// add main

int main()
{
	Circle c{10,10,5};
	Triangle t{0,0, 10,0, 0,10};

	test(t, c);

	Triangle t2{0,0, 5,0, 0,5};
	test(t2, c);
}

