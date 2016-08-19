/*
 * friend_and_member.cpp
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class X {
public:
	X(int);

	int m1();
	int m2() const;

	friend int f1(X&);
	friend int f2(const X&);
	friend int f3(X);
};
int f1(X&);
int f2(const X&);
int f3(X);

void g()
{
	//99.m1();
		// error: unable to find numeric literal operator 'operator""m1'
	//99.m2();
		// error: unable to find numeric literal operator 'operator""m2'
}

void h()
{
	//f1(99);
		// error: invalid initialization of non-const reference of type 'X&' from an rvalue of type 'X'
	f2(99);
	f3(99);
}


// add undef

X::X(int x)
{
	cout << "X::X(int: " << x << ")\n";
}
int f1(X&)
{
	cout << "f1(X&)\n";
}
int f2(const X&)
{
	cout << "f2(const X&)\n";
}
int f3(X)
{
	cout << "f3(X)\n";
}

// add main
int main()
{
	h();
}
