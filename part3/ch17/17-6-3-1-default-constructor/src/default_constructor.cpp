/*
 * default_constructor.cpp
 *
 *  Created on: 2016/08/01
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct X {
	X(int);
};

X a {1};
//X b {};
	// error: no matching function for call to 'X::X(<brace-enclosed initializer list>)'

struct Y {
	string s;
	int n;
	Y(const string& s);
	Y() = default;
};

// add undef-func

X::X(int i)
{
	cout << "X::X(" << i << ")\n";
}

Y::Y(const string& s)
{
	cout << "Y::Y(" << s << ")\n";
}
// add main

int main()
{
	Y y1 {"abc"};
	cout << "y1.s: " << y1.s << ", y1.n: " << y1.n << '\n';

	Y y2 { };
	cout << "y2.s: " << y2.s << ", y2.n: " << y2.n << '\n';

	Y y3;
	cout << "y3.s: " << y3.s << ", y3.n: " << y3.n << '\n';
}
