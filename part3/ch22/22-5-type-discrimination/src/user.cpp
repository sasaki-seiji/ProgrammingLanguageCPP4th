/*
 * user.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include "Radio.h"
#include <typeinfo>
#include <iostream>
#include <exception>
using namespace std;

void f(Shape& r, Shape* p)
{
	const type_info &ti_r = typeid(r);
	const type_info &ti_derefence_p = typeid(*p);
	const type_info &ti_p = typeid(p);

	cout << "r: " << ti_r.name() << '\n';
	cout << "*p: " << ti_derefence_p.name() << '\n';
	cout << "p: " << ti_p.name() << '\n';
}

struct Poly {
	virtual void f() { }
};

struct Non_poly { };

struct D1 : Poly { };
struct D2 : Non_poly { };

void f(Non_poly& npr, Poly& pr)
{
	cout << typeid(npr).name() << '\n' << flush;
	cout << typeid(pr).name() << '\n' << flush;
}

void g()
{
	D1 d1;
	D2 d2;
	f(d2,d1);

	// crash
	//f(*static_cast<Non_poly*>(nullptr), *static_cast<Poly*>(nullptr));
}

void g(Component* p)
{
	cout << typeid(*p).name() << '\n';
}

// add main

int main()
{
	Circle circle;
	Triangle triangle;
	f(circle, &triangle);

	try {
		g();
	}
	catch (const exception& e) {
		cout << e.what() << '\n';
	}
	catch (...) {
		cout << "unknown exception\n";
	}

	Component comp;
	Receiver rec;
	Transmitter trans;
	Radio rad;

	g(&comp);
	g(&rec);
	g(&trans);
	g(static_cast<Receiver*>(&rad));
	g(static_cast<Transmitter*>(&rad));
}

