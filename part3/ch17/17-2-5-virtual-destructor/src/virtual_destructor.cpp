/*
 * virtual_destructor.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape();
};

class Circle : public Shape {
public:
	void draw();
	Circle(const string& name, double x, double y, double radius);
	~Circle();
private:
	string name;
	double x, y, radius;
};

Shape::~Shape()
{
	cout << "Shape::~Shape()\n";
}

Circle::Circle(const string& name, double x, double y, double radius)
	: name{name}, x{x}, y{y}, radius{radius}
{
	cout << "Circle(\"" << name << "\"," << x << "," << y << "," << radius << ")\n";
}

Circle::~Circle()
{
	cout << "Circle::~Circle(\"" << name << "\"," << x << "," << y << "," << radius << ")\n";
}

void Circle::draw()
{
	cout << "Circle::draw()\n";
}

void user(Shape* p)
{
	cout << "-- user(Shape*) --\n";

	p->draw();
	delete p;
}


class Shape2 {
public:
	virtual void draw() = 0;
	~Shape2();
};

class Circle2 : public Shape2 {
public:
	void draw();
	Circle2(const string& name, double x, double y, double radius);
	~Circle2();
private:
	string name;
	double x, y, radius;
};

Shape2::~Shape2()
{
	cout << "Shape2::~Shape2()\n";
}

Circle2::Circle2(const string& name, double x, double y, double radius)
	: name{name}, x{x}, y{y}, radius{radius}
{
	cout << "Circle2(\"" << name << "\"," << x << "," << y << "," << radius << ")\n";
}

Circle2::~Circle2()
{
	cout << "Circle2::~Circle2(\"" << name << "\"," << x << "," << y << "," << radius << ")\n";
}

void Circle2::draw()
{
	cout << "Circle2::draw()\n";
}

void user2(Shape2* p)
{
	cout << "-- user2(Shape2*) --\n";

	p->draw();
	delete p;
}


// add main
int main()
{
	Shape *p = new Circle("circle#1", 10, -10, 20);
	user(p);

	Shape2 *p2 = new Circle2("circle#2", 100, -100, 200);
	user2(p2);
}
