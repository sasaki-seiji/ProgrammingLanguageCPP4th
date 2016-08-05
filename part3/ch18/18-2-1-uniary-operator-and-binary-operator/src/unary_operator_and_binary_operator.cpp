/*
 * unary_operator_and_binary_operator.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

class X {
public:
	void operator+(int);
	X(int);
};

void operator+(X,X);
void operator+(X,double);

void f(X a)
{
	a+1;
	1+a;
	a+1.0;
}


class Y {
public:
	Y* operator&();
	Y operator&(Y);
	Y operator++(int);
	//Y operator&(Y,Y);
		// error: 'Y Y::operator&(Y, Y)' must take either zero or one argument
	//Y operator/();
		// error: 'Y Y::operator/()' must take exactly one argument
};

Y operator-(Y);
Y operator-(Y,Y);
Y operator--(Y&,int);
//Y operator-();
	// error: 'Y operator-()' must have an argument of class or enumerated type
//Y operator-(Y,Y,Y);
	// error: 'Y operator-(Y, Y, Y)' must take either one or two arguments
//Y operator%(Y);
	// error: 'Y operator%(Y)' must take exactly two arguments


// add undef func

X::X(int x)
{
	cout << "X::X(int: " << x << ")\n";
}

void X::operator+(int x)
{
	cout << "X::operator(int: " << x << ")\n";
}

void operator+(X x1, X x2)
{
	cout << "::operator+(X,X)\n";
}

void operator+(X x, double d)
{
	cout << "::operator+(X, double: " << d << ")\n";
}

// add main

int main()
{
	X a(10);
	f(a);
}
