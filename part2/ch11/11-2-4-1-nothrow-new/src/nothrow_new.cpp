/*
 * nothrow_new.cpp
 *
 *  Created on: 2016/04/30
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int n)
{
	cout << "-- f(" << n << ")-- \n";

	int* p = new(nothrow) int[n];
	if (p==nullptr) {
		cerr << "can't allocate memory\n";
	}

	cout << "p = " << p << '\n';
	operator delete(p, nothrow);
}

int main()
{
	f(1000);
	f(1000000);
	f(10000000);
	f(100000000);
	f(200000000);
	f(400000000);
	f(800000000);
	f(1000000000);
	f(2000000000);
}
