/*
 * resolve_friend.cpp
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

// scope of friend

class C1 { };
void f1();

namespace N {
	class C2 { };
	void f2() { }

	class C {
		int x;
	public:
		friend class C1;
		friend void f1();
		friend class C2;
		friend void f2();
		friend class C3;
		friend void f3();
		friend class C4;
		friend void f4();
	};

	class C3 { };
	void f3() { C x; x.x = 1; }
}

class C4 { };
void f4()
{
	//N::C x; x.x = 1;
		// error: 'int N::C::x' is private
}

// search friend from argument

#include "Matrix.h"

void ff(Matrix& m)
{
	invert(m);
}


// search friend from class argument

class X {
	friend void f();
	friend void h(const X&);
};

void g(const X& x)
{
	//f();
		//  error: 'f' was not declared in this scope
	h(x);
}

void f()
{
	cout << "f()\n";
}

void h(const X& x)
{
	cout << "f(cont X&)\n";
}


// add main

int main()
{
	Matrix m = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
	};
	ff(m);

	X x;
	g(x);
}
