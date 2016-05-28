/*
 * usability_and_safety.cpp
 *
 *  Created on: 2016/05/26
 *      Author: sasaki
 */

namespace X {
	int i, j, k;
}

int k;

void f1()
{
	int i = 0;
	using namespace X;
	i++;
	j++;
	//k++;
		// 'k' is ambiguous
	::k++;
	X::k++;
}

void f2()
{
	int i = 0;
	//using X::i;
		// 'i' is already declared in this scope
	using X::j;
	using X::k;

	i++;
	j++;
	k++;
}

#include <iostream>
using namespace std;

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
