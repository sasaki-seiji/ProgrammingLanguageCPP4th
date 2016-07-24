/*
 * initialize_by_constructor.cpp
 *
 *  Created on: 2016/07/25
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

struct X {
	X(int);
};

//X x0;
	//  error: no matching function for call to 'X::X()'
//X x1 {};
	// error: no matching function for call to 'X::X(<brace-enclosed initializer list>)'
X x2 {2};
//X x3 {"two"};
	// error: invalid conversion from 'const char*' to 'int' [-fpermissive]
//X x4 {1,2};
	// error: no matching function for call to 'X::X(<brace-enclosed initializer list>)'
X x5 {x2};

struct Y : X {
	X m {0};
	Y(int a) : X{a}, m{a} { cout << "Y::Y(" << a << ")\n"; }
	Y() : X{0} { cout << "Y::Y()\n"; }
};

X g {1};

void f(int i)
{
	//X def {};
		// error: no matching function for call to 'X::X(<brace-enclosed initializer list>)'
	cout << "- Y def2 { }\n";
	Y def2 {};

	cout << "- X* p {nullptr}\n";
	X* p {nullptr};

	cout << "- X var {2}\n";
	X var {2};

	cout << "- p = new X{4}\n";
	p = new X{4};

	cout << "- X a[] {1,2,3}\n";
	X a[] {1,2,3};

	cout << "- vector<X> v {1,2,3,4}\n";
	vector<X> v {1,2,3,4};
}

struct Y2 : X {
	X m;
	//Y2(int a) : X(a), m=a { }
		// error: expected '{' before '=' token
};

void h(int i)
{
	X def();
	X* p {nullptr};
	X var = 2;
	//p = new X=4;
		//error: no matching function for call to 'X::X()'
	//X a[](1,2,3);
		//  error: expression list treated as compound expression in initializer [-fpermissive]
	//vector<X> v(1,2,3,4);
		// error: no matching function for call to 'std::vector<X>::vector(int, int, int, int)'
}

struct S {
	S(const char*);
	S(double*);
};

S s1 {"Napier"};
S s2 {new double{1.0}};
//S s3 {nullptr};
	// error: call of overloaded 'S(<brace-enclosed initializer list>)' is ambiguous


// add undef-func

X::X(int i)
{
	cout << "X::X(" << i << ")\n";
}

S::S(const char* s)
{
	cout << "S::S(const char* \"" << s << "\")\n";
}

S::S(double* p)
{
	cout << "S::S(double*)\n";
}

// add main
int main()
{
	f(10);
}


