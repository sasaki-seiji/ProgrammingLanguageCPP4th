/*
 * virtual_destructor.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape();
};

class Circle : public Shape {
public:
	void draw();
	~Circle();
};

void user(Shape* p)
{
	p->draw();

	delete p;
}

// add undefined func

Shape::~Shape()
{
	cout << "Shape::~Shape()\n";
}

Circle::~Circle()
{
	cout << "Circle::~Circle()\n";
}

void Circle::draw()
{
	cout << "Circle::draw()\n";
}

// add main
int main()
{
	Shape *p = new Circle;
	user(p);
}
