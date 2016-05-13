/*
 * cpp_part.cpp
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "interface.h"

struct C_blewit {
	int err;
	C_blewit(int e) { err = e; }
};

void callC()
{
	errno = 0;
	c_function();
	if (errno) {
		throw C_blewit(errno);
	}
}

void c_plus_plus_function()
{
	cout << "c_plus_plus_function() called\n";
	throw C_blewit(E_CPLPLFCTBLEWIT);
}

extern "C" void call_from_C() noexcept
{
	try {
		c_plus_plus_function();
	}
	catch (...) {
		errno = E_CPLPLFCTBLEWIT;
	}
}

int main()
{
	try {
		callC();
	}
	catch (C_blewit& e) {
		cout << "caught C_blewit, err: " << e.err << '\n';
	}

	c_entry();
}
