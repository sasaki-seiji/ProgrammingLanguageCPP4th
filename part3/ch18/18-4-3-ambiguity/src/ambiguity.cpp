/*
 * ambiguity.cpp
 *
 *  Created on: 2016/08/10
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class X {
public:
	X(int i) { cout << "X::X(int " << i << ")\n"; }
	X(const char* s) { cout << "X::X(const char* \"" << s << "\")\n"; }
};

class Y {
public:
	Y(int i) { cout << "Y::Y(int " << i << ")\n"; }
};

class Z {
public:
	Z(X) { cout << "Z::Z(X)\n"; }
};

X f(X x) { cout << "f(X)\n"; return x; }
Y f(Y y) { cout << "f(Y)\n"; return y; }

Z g(Z z) { cout << "g(Z)\n"; return z; }


void k1()
{
	cout << "-- k1() --\n";

	//f(1);
		// error: call of overloaded 'f(int)' is ambiguous
	f(X{1});
	f(Y{1});

	//g("Mack");
		// error: could not convert '(const char*)"Mack"' from 'const char*' to 'Z'
	g(X{"Doc"});
	g(Z{"Suzzy"});
}

class Quad {
public:
	long double ld;
	Quad(double d) :ld{d} { cout << "Quad::Quad(double " << d << ")\n"; }
};

Quad operator+(Quad q1, Quad q2)
{
	cout << "::operator+(Quad " << q1.ld << ", Quad " << q2.ld << ")\n";
	q1.ld += q2.ld;
	return q1;
}

ostream& operator<<(ostream& os, Quad q)
{
	os << q.ld;
	return os;
}

void f(double a1, double a2)
{
	cout << "-- f(double " << a1 << ",double " << a2 << ") --\n";

	Quad r1 = a1+a2;
	Quad r2 = Quad{a1}+a2;

	cout << "r1: " << r1 << '\n';
	cout << "r2: " << r2 << '\n';
}

class Real {
	double d;
public:
	operator double() { cout << "Real::operator double() -> " << d << "\n"; return d; }
	operator int() { cout << "Real::operator int() -> " << (int)d << "\n"; return (int)d; }

	Real(double dd) :d{dd} { }
};

void g(Real a)
{
	cout << "-- g(Real) --\n";

	double d = a;
	int i = a;

	d = a;
	i = a;

	cout << "d: " << d << '\n';
	cout << "i: " << i << '\n';
}

// add main

int main()
{
	k1();
	f(1.2, 2.3);

	Real r{4.5};
	g(r);
}
