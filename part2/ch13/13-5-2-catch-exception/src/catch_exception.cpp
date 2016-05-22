/*
 * catch_exception.cpp
 *
 *  Created on: 2016/05/18
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Error { };

void g()
{
	int x1 = 0;
	try {
		int x2 = x1;
		cout << "x2: " << x2 << '\n';
		//..
		throw Error{};
	}
	catch (Error) {
		++x1;
		//++x2;
			// 'x2' was not declared in this scope
		int x3 = 7;
		cout << "x3: " << x3 << '\n';
		//..
	}
	catch (...) {
		//++x3;
			// 'x3' was not declared in this scope
		//..
	}

	++x1;
	//++x2;
		// 'x2' was not declared in this scope
	//++x3;
		// 'x3' was not declared in this scope
	cout << "x1: " << x1 << '\n';
}

int main()
{
	g();
}
