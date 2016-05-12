/*
 * default_argument.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class complex {
	double re, im;
public:
	complex(double r, double i) :re{r}, im{i} {}
	complex(double r) :re{r}, im{0} {}
	complex() :re{0}, im{0} {}

	double real() const { return re; }
	double imag() const { return im; }
};

ostream& operator<<(ostream& os, const complex& c)
{
	os << '(' << c.real() << ',' << c.imag() << ')';
	return os;
}

class complex2 {
	double re, im;
public:
	complex2(double r, double i) :re{r}, im{i} {}
	complex2(double r) :complex2{r,0} {}
	complex2() :complex2{0,0} {}

	double real() const { return re; }
	double imag() const { return im; }
};

ostream& operator<<(ostream& os, const complex2& c)
{
	os << '(' << c.real() << ',' << c.imag() << ')';
	return os;
}

class complex3 {
	double re, im;
public:
	complex3(double r ={}, double i ={}) :re{r}, im{i} {}

	double real() const { return re; }
	double imag() const { return im; }
};

ostream& operator<<(ostream& os, const complex3& c)
{
	os << '(' << c.real() << ',' << c.imag() << ')';
	return os;
}

class X {
public:
	static int def_arg;
	void f(int =def_arg);
};

int X::def_arg = 7;

void g(X& a)
{
	a.f();
	a.def_arg = 9;
	a.f();
}

int f(int, int =0, char* =nullptr);
//int g(int =0, int =0, char*);
	// default argument missing for parameter 3 of 'int g(int, int, char*)'
//int h(int =0, int, char* =nullptr);
	// default argument missing for parameter 2 of 'int h(int, int, char*)'

//void nasty(char*=nullptr);
	// expected ',' or '...' before '*=' token

void f(int x =7);
//void f(int =7);
	// default argument given for parameter 1 of 'void f(int)' [-fpermissive]
//void f(int =8);
	// default argument given for parameter 1 of 'void f(int)'


void g()
{
	void f(int x=9);
}

int main()
{
	complex c1 {10, 20};
	complex c2 {10};
	complex c3;

	cout << "c1: " << c1 << '\n';
	cout << "c2: " << c2 << '\n';
	cout << "c3: " << c3 << '\n';

	complex2 c21 {10, 20};
	complex2 c22 {10};
	complex2 c23;

	cout << "c21: " << c21 << '\n';
	cout << "c22: " << c22 << '\n';
	cout << "c23: " << c23 << '\n';

	complex3 c31 {10, 20};
	complex3 c32 {10};
	complex3 c33;

	cout << "c31: " << c31 << '\n';
	cout << "c32: " << c32 << '\n';
	cout << "c33: " << c33 << '\n';

	X x;
	g(x);
}

// undefs
void X::f(int x)
{
	cout << "f(" << x << ")\n" ;
}
