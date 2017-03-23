/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

namespace {
	class X { };
	int i = 1;
	void f()
	{
		cout << "-- file1.f() --\n";
		cout << "i = " << i << endl;
		cout << "typeid(X) = " << typeid(X).name() << endl;
	}
}

void call_unnamed_namespace() { f(); }
