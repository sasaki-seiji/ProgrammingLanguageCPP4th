/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */

#include <iostream>

namespace {
	class X { };
	int i;
	void f() { std::cout << "f() called, i=" << i << "\n"; }
}

void call_unnamed_namespace() { f(); }
