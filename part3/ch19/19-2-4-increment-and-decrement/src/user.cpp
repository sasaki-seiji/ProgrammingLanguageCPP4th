/*
 * user.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#include "Ptr.h"
#include <iostream>
using namespace std;

struct X {
	int x;
};

void f1(X a)
{
	cout << "-- f1(X) --\n";

	X v[200];
	X* p = &v[0];
	p--;
	//*p = a;	// error but not catch on MinGW
		// terminated (exit value:-1) on Ubuntu/g++ 5.4.0
	++p;
	*p = a;

	cout << "p->x: " << p->x << '\n';
}

void f2(X a)
{
	cout << "-- f2(X) --\n";

	X v[200];
	Ptr<X> p(&v[0], v);
	p--;
	try {
		*p = a;
	}
	catch (out_of_range& e) {
		cout << e.what() << '\n';
	}
	++p;
	try {
		*p = a;
		cout << "p->x: " << p->x << '\n';
	}
	catch (out_of_range& e) {
		cout << e.what() << '\n';
	}
}


void f3(X a)
{
	cout << "-- f3(X) --\n";

	X v[200];
	Ptr<X> p(&v[0], v);
	p.operator--(0);
	try {
		p.operator*() = a;
	}
	catch (out_of_range& e) {
		cout << e.what() << '\n';
	}
	p.operator++();
	try {
		p.operator*() = a;
		cout << "p->x: " << (p.operator->())->x << '\n';
	}
	catch (out_of_range& e) {
		cout << e.what() << '\n';
	}
}


// add main

int main()
{
	X a {1};
	f1(a);

	a.x = 11;
	f2(a);

	a.x = 22;
	f3(a);
}
