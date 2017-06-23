/*
 * user.cpp
 *
 *  Created on: 2017/06/24
 *      Author: sasaki
 */

#include "predicate.h"
using namespace Estd;

#include <iostream>
using namespace std;

bool even(int i)
{
	return (i%2) == 0;
}

struct GreaterThan {
	int v;
	GreaterThan(int x): v{x} { }

	//bool operator()(int i) const { return (i%2) == 1; }
	bool operator()(int i) { return i > v; }
};

auto odd = [](int i) { return (i%2) == 1; };

auto iabs = [](int i) { return (i<0)?-i:i; };

int main()
{
	bool b1 = Predicate<decltype(even), int>();
	bool b2 = Predicate<GreaterThan,int>();
	bool b3 = Predicate<decltype(odd), int>();
	bool b4 = Predicate<decltype(iabs), int>();

	cout << boolalpha;
	cout << "Predicate<decltype(even), int>(): " << b1 << endl;
	cout << "Predicate<GreaterThan, int>(): " << b2 << endl;
	cout << "Predicate<decltype(odd), int>(): " << b3 << endl;
	cout << "Predicate<decltype(iabs), int>(): " << b4 << endl;
}
