/*
 * exception_safe.cpp
 *
 *  Created on: 2017/03/11
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Bad { };

void f(int i)
{
	cout << "-- f(" << i << ") --\n";

	int* p = new int[10];

	if (i<0) {
		delete [] p;
		throw Bad();
	}

	p[i] = 10;
	cout << "p[i]: " << p[i] << endl;
	delete [] p;
}

int main()
{
	f(1);
	try {
		f(-1);
	}
	catch (const Bad& e) {
		cout << "caught Bad\n";
	}
}
