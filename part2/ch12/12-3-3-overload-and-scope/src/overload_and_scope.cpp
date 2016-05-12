/*
 * overload_and_scope.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void f(int);

void g()
{
	void f(double);
	f(1);
}

struct Base {
	void f(int);
};

struct Derived : Base {
	void f(double);
};

void g(Derived& d)
{
	d.f(1);
}

int main()
{
	g();

	Derived d;
	g(d);
}

// undefs
void f(double d)
{
	cout << "f(double: " << d << ")\n";
}
void Derived::f(double d)
{
	cout << "Derived::f(double: " << d << ")\n";
}
