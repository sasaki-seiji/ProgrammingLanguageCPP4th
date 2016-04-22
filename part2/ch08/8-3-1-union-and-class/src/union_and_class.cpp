/*
 * union_and_class.cpp
 *
 *  Created on: 2016/04/22
 *      Author: sasaki
 */


#include <iostream>
#include <complex>
using namespace std;

enum Type { str, num };

union Value {
	char* s;
	int i;
};

struct Entry {
	char* name;
	Type t;
	Value v;
};

void f(Entry a)
{
	Entry b = a;
}

union U {
	int m1;
	//complex<double> m2;
		// union member 'U::m2' with non-trivial 'constexpr std::complex<double>::complex(double, double)'
	//string m3;
		// union member 'U::m3' with non-trivial 'std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::basic_string(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]'
};

void f2(U x)
{
	U u;
		// use of deleted function 'U::~U()'
		// use of deleted function 'U::U()'

	U u2 = x;
		// use of deleted function 'U::~U()'
		// use of deleted function 'U::U(const U&)'

	u.m1 = 1;
	//string s = u.m3;
	return ;
}

union U2 {
	int a;
	const char* p {""};
};

U2 x1;
//U2 x2 {7};
	// no matching function for call to 'U2::U2(<brace-enclosed initializer list>)'

int main()
{
	Entry e;
	f(e);

	cout << "x1.p = " << x1.p << '\n';

	return 0;
}
