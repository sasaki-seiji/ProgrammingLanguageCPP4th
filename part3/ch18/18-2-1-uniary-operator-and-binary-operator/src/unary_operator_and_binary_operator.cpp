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
	void operator+(int x) { 	cout << "X::operator(int: " << x << ")\n"; }
	X(int x) { cout << "X::X(int: " << x << ")\n"; }
};

void operator+(X,X) { cout << "::operator+(X,X)\n"; }
void operator+(X,double d) { cout << "::operator+(X, double: " << d << ")\n"; }

void f(X a)
{
	cout << "-- f(X) --\n";

	a+1;
	1+a;
	a+1.0;
}


class Y {
public:
	Y* operator&() { cout << "Y::operator&()\n"; return nullptr; }
	Y operator&(Y) { cout << "Y::operator&(Y)\n"; return *this; }
	Y operator++(int) { cout << "Y::operator++(int)\n"; return *this; }
	//Y operator&(Y,Y);
		// error: 'Y Y::operator&(Y, Y)' must take either zero or one argument
	//Y operator/();
		// error: 'Y Y::operator/()' must take exactly one argument
};

Y operator-(Y y) { cout << "::operator-(Y)\n"; return y; }
Y operator-(Y y1,Y y2) { cout << "::operator-(Y,Y)\n"; return y1; }
Y operator--(Y& y,int) { cout << "::operator--(Y&,int)\n"; return y; }
//Y operator-();
	// error: 'Y operator-()' must have an argument of class or enumerated type
//Y operator-(Y,Y,Y);
	// error: 'Y operator-(Y, Y, Y)' must take either one or two arguments
//Y operator%(Y);
	// error: 'Y operator%(Y)' must take exactly two arguments

void test_Y()
{
	cout << "-- test_Y() --\n";

	Y y1,y2;
	Y* p = &y1;
	Y y3 = y1 & y2;
	Y y4 = y1++;
	Y y5 = -y1;
	Y y6 = y1 - y2;
	Y y7 = y1--;
}

// add main

int main()
{
	X a(10);
	f(a);

	test_Y();
}
