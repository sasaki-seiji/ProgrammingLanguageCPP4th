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
X::X(int i)
{
	cout << "X::X(" << i << ")\n";
}

X a {1};
//X b {};
	// error: no matching function for call to 'X::X(<brace-enclosed initializer list>)'

struct Y {
	string s;
	int n;
	Y(const string& s);
	Y() = default;
};
Y::Y(const string& s)
	:s{s}, n{10}
{
	cout << "Y::Y(" << s << ")\n";
}

// add main

int main()
{
	Y y1 {"abc"};
	cout << "Y y1{\"abc\"}; y1.s = " << y1.s << ", y1.n = " << y1.n << '\n';

	Y y2 { };
	cout << "Y y2{}; y2.s = " << y2.s << ", y2.n = " << y2.n << '\n';

	Y y3;
	cout << "Y y3; y3.s = " << y3.s << ", y3.n = " << y3.n << '\n';
}
