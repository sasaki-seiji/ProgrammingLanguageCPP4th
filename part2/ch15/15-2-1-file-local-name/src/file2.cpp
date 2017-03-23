/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


class X { };
void f();
int i = 2;

// add main
#include <iostream>
#include <typeinfo>
using namespace std;
void call_unnamed_namespace();
int main()
{
	f();
	call_unnamed_namespace();
}

// undef
void f()
{
	cout << "-- file2.f() --\n";
	cout << "i = " << i << endl;
	cout << "typeif(X) = " << typeid(X).name() << endl;
}
