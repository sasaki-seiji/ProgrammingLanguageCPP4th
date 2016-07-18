/*
 * member_access.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct X {
	void f();
	int m;
};

void user(X x, X* px)
{
	//m = 1;
		// 'm' was not declared in this scope
	x.m = 1;
	//x->m = 1;
		// base operand of '->' has non-pointer type 'X'
	px->m = 1;
	//px.m = 1;
		// request for member 'm' in 'px', which is of pointer type 'X*' (maybe you meant to use '->' ?)
}

void X::f()
{
	m = 1;
}

struct Y {
	int f() { return m; }
	int m;
};

struct S {
	int m;
	int f();
	static int sm;
};

int S::f() { return m; }
int S::sm {7};
//int (S::*) pmf() {&S::f};
	// expected initializer before 'pmf'
int (S::*pmf)() {&S::f};

// add main
int main()
{
	X x1, x2;
	user(x1, &x2);
	cout << "x2.m after user(x1, &x2): " << x2.m << '\n';

	x1.f();
	cout << "x1.m after x1.f(): " << x1.m << '\n';

	Y y;
	y.m = 10;
	cout << "y.f(): " << y.f() << '\n';

	S s;
	s.m = 20;
	cout << "s.f(): " << s.f() << '\n';
	cout << "S::sm: " << S::sm << '\n';
	cout << "(s.*pmf)(): " << (s.*pmf)() << '\n';
}
