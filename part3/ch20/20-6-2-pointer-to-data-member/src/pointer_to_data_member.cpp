/*
 * pointer_to_data_member.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct C {
	const char* val;
	int i;

	void print(int x) { cout << val << x << '\n'; }
	int f1(int);
	void f2();
	C(const char* v) { val = v; }
};

using Pmfi = void (C::*)(int);
using Pm = const char* C::*;

void f(C& z1, C& z2)
{
	C* p = &z2;
	Pmfi pf = &C::print;
	Pm pm = &C::val;

	z1.print(1);
	(z1.*pf)(2);
	z1.*pm = "nv1 ";
	p->*pm = "nv2 ";
	z2.print(3);
	(p->*pf)(4);

	//pf = &C::f1;
		// error: cannot convert 'int (C::*)(int)' to 'Pmfi {aka void (C::*)(int)}' in assignment
	//pf = &C::f2;
		// error: cannot convert 'void (C::*)()' to 'Pmfi {aka void (C::*)(int)}' in assignment
	//pm = &C::i;
		// error: cannot convert 'int C::*' to 'Pm {aka const char* C::*}' in assignment
	//pm = pf;
		// error: cannot convert 'Pmfi {aka void (C::*)(int)}' to 'Pm {aka const char* C::*}' in assignment
}

int main()
{
	C z1{"z1 "}, z2{"z2 "};
	f(z1, z2);
}
