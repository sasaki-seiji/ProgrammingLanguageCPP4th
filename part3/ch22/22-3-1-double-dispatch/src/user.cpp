/*
 * user.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */


#include "Shape.h"
#include <vector>
using namespace std;

void test(Triangle& t, Circle& c)
{
	vector<pair<Shape*,Shape*>> vs { {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c} };
	for (auto p : vs)
		p.first->intersect(*p.second);
}

// add main

int main()
{
	Circle c;
	Triangle t;

	test(t, c);
}

