/*
 * delete_of_function.cpp
 *
 *  Created on: 2016/08/05
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class Base {
public:
	Base() { };

	Base& operator=(const Base&) = delete;
	Base(const Base&) = delete;
	Base& operator=(Base&&) = delete;
	Base(Base&&) = delete;
};

Base x1;
//Base x2 {x1};
	// error: use of deleted function 'Base::Base(const Base&)'


template<typename T>
T* clone(T* p)
{
	return new T{*p};
}

struct Foo {
	Foo() { cout << "Foo::Foo()\n"; }
	~Foo() { cout << "Foo::~Foo()\n"; }
	Foo(const Foo&) { cout << "Foo::Foo(const Foo&)\n"; }
};
struct Shape {
	Shape() { cout << "Shape::Shape()\n"; }
	~Shape() { cout << "Shape::~Shape()\n"; }
	Shape(const Shape&) { cout << "Shape::Shape(const Shape&)\n"; }
};
Foo* clone(Foo*) = delete;

void f(Shape* ps, Foo* pf)
{
	cout << "-- f(Shape*,Foo*) --\n";

	Shape* ps2 = clone(ps);
	//Foo* pf2 = clone(pf);
		// error: use of deleted function 'Foo* clone(Foo*)'

	delete ps2;
}


struct Z {
	Z(double);
	Z(int) = delete;
};

Z::Z(double b)
{
	cout << "Z::Z(double: " << b << ")\n";
}

void f()
{
	cout << "-- f() --\n";

	//Z z1 {1};
		// error: use of deleted function 'Z::Z(int)'
	Z z2 {1.0};
}


class Not_on_stack {
public:
	Not_on_stack() { cout << "Not_on_stack()\n"; }
	~Not_on_stack() = delete;
};

class Not_on_free_store {
public:
	Not_on_free_store() { cout << "Not_on_free_store()\n"; }
	~Not_on_free_store() { cout << "~Not_on_free_store()\n"; }
	void* operator new(size_t) = delete;
};

void g()
{
	cout << "-- g() --\n";

	//Not_on_stack v1;
		// error: use of deleted function 'Not_on_stack::~Not_on_stack()'
	Not_on_free_store v2;

	Not_on_stack* p1 = new Not_on_stack;
	//Not_on_free_store* p2 = new Not_on_free_store;
		// error: use of deleted function 'static void* Not_on_free_store::operator new(size_t)'
}

// add undef func

// add main

int main()
{
	Shape shape;
	Foo	foo;
	f(&shape, &foo);

	f();

	g();
}
