/*
 * extern_c.cpp
 *
 *  Created on: 2016/07/10
 *      Author: sasaki
 */

extern "C" int f();

int g()
{
	//return f(1);
		// error: too many arguments to function 'int f()'
	return f();
}

extern "C" {
	int g1;
	extern int g2;
}

extern "C" int g3;
extern "C" { int g4; }

#include <cstdio>

void f2()
{
	std::printf("Hello, ");
	printf("world!\n"); // no error
}


// add main
#include <iostream>
using namespace std;
int main()
{
	g();

	g1 = 10;
	cout << "g1 = " << g1 << '\n';
	cout << "g2 = " << g2 << '\n';

	cout << "g3 = " << g3 << '\n';
	g4 = 3;
	cout << "g4 = " << g4 << '\n';

	f2();
}

