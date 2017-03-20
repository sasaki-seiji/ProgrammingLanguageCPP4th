/*
 * usability_and_safety.cpp
 *
 *  Created on: 2016/05/26
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

namespace X {
	int i, j, k;
}

int k;

void f1()
{
	cout << "-- f1() --\n";

	int i = 0;
	using namespace X;
	i++;
	j++;
	//k++;
		// error: reference to ‘k’ is ambiguous
	::k++;
	X::k++;
}

void f2()
{
	cout << "-- f2() --\n";

	int i = 0;
	//using X::i;
		// error: 'i' is already declared in this scope
	using X::j;
	using X::k;

	i++;
	j++;
	k++;
}


void print()
{
	cout << "X::i==" << X::i << ", X::j==" << X::j << ", X::k==" << X::k << '\n';
	cout << "::k==" << ::k << '\n';
}

int main()
{
	f1();
	print();
	f2();
	print();
}
