/*
 * mem_fn.cpp
 *
 *  Created on: 2016/12/04
 *      Author: sasaki
 */

#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() { }
};

class Circle : public Shape {
public:
	void draw() { cout << "Circle::draw()\n"; }
};

class Squre : public Shape {
public:
	void draw() { cout << "Squre::draw()\n"; }
};

void user(Shape* p)
{
	cout << "-- user() --\n";

	p->draw();
	auto draw = mem_fn(&Shape::draw);
	draw(p);
}

void draw_all(vector<Shape*>& v)
{
	cout << "-- draw_all() --\n";

	for_each(v.begin(), v.end(), mem_fn(&Shape::draw));
}

int main()
{
	Shape *p = new Circle;
	user(p);

	vector<Shape*> v {new Circle, new Squre, new Squre, new Circle};
	draw_all(v);
}
