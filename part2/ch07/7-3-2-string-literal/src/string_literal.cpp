/*
 * string_literal.cpp
 *
 *  Created on: 2016/04/14
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f()
{
	cout << "-- f() --\n";

	char* p = "Plato";	// not error
		// warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
	//p[4] = 'e';	// system down

	cout << "p = " << p << '\n';
}

void f2()
{
	cout << "-- f2() --\n";

	char p[] = "Zeno";
	p[0] = 'R';
	cout << "p = " << p << '\n';
}

const char* error_message(int i)
{
	return "range_error";
}

const char* p = "Heraclitus";
const char* q = "Heraclitus";

void g()
{
	cout << "-- g() --\n";

	if (p == q) cout << "one!\n";
}

int main()
{
	cout << sizeof("Bohr") << '\n';

	f();
	f2();
	cout << "error_message(0) = " << error_message(0) << '\n';
	g();
	cout << "beep at end of message\a\n";
	char alpha[] = "abcdefghijklmlopqrstuvwxyz"
					"ABCDEFGHIJKLMLOPQRSTUVWXYZ";
	cout << alpha << '\n';
}


