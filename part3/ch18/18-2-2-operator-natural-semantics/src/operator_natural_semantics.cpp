/*
 * operator_natural_semantics.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class X {
public:
	void operator=(const X&) = delete;
	void operator&() = delete;
	void operator,(const X&) = delete;
};

void f(X a, X b)
{
	//a = b;
		// error: use of deleted function 'void X::operator=(const X&)'
	// &a;
		// error: use of deleted function 'void X::operator&()'
	//a,b;
		// error: use of deleted function 'void X::operator,(const X&)'
}


struct Y {
	int v;
	Y(int vv) :v{vv} { }
};

void f(Y x, Y y)
{
	cout << "x.v: " << x.v << '\n';
	cout << "y.v: " << y.v << '\n';

	x = y;
	cout << "x=y; x.v: " << x.v << '\n';

	Y* p = &x;
	cout << "Y*p=&x; p: " << p << '\n';

	Y z = (x,y);
	cout << "Y z = x,y; z.v: " << z.v << '\n';
}

// add main

int main()
{
	X a, b;
	f(a, b);

	Y x(5), y(10);
	f(x, y);
}

