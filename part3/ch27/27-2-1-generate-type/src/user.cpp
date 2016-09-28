/*
 * user.cpp
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#include "shape.h"
#include <set>
using namespace std;

void f(set<Shape*>& s)
{
	Point p1{0,0}, p2{1,0}, p3{0,1};

	s.insert(new Triangle{p1,p2,p3});
}

void g(set<Circle*> s)
{
	//f(s);
		// error: invalid initialization of reference of type 'std::set<Shape*>&' from expression of type 'std::set<Circle*>'
}

// add main

int main()
{
	set<Circle*> s;
	Point p1{0,0}, p2{1,0};
	s.insert(new Circle{p1, 1});
	s.insert(new Circle{p2, 2});
	g(s);
}
