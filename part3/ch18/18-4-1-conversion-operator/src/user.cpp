/*
 * user.cpp
 *
 *  Created on: 2016/08/10
 *      Author: sasaki
 */


#include "Tiny.h"
#include <iostream>
using namespace std;

int operator+(Tiny t1,Tiny t2) { return (int)t1+(int)t2; };

void f(Tiny t, int i)
{
	//t+i;
		// error: ambiguous overload for 'operator+' (operand types are 'Tiny' and 'int')
}

int main()
{
	Tiny c1 = 2;
	Tiny c2 = 62;
	Tiny c3 = c2-c1;
	Tiny c4 = c3;

	cout << "c1: " << c1 << '\n';
	cout << "c2: " << c2 << '\n';
	cout << "c3: " << c3 << '\n';
	cout << "c4: " << c4 << '\n';

	int i = c1+c2;
	cout << "i=c1+c2: " << i << '\n';

	try {
		c1 = c1+c2;
		cout << "c1=c1+c2: " << c1 << '\n';
	}
	catch (Tiny::Bad_range&) {
		cout << "c1=c1+c2: Bad_range\n";
	}

	i = c3-64;
	cout << "i=c3-64: " << i << '\n';

	try {
		c2 = c3-64;
		cout << "c2=c3-64: " << c2 << '\n';
	}
	catch (Tiny::Bad_range&) {
		cout << "c2=c3-64: Bad_range\n";
	}

	try {
		c3 = c4;
		cout << "c3=c4: " << c3 << '\n';
	}
	catch (Tiny::Bad_range&) {
		cout << "c3=c4: Bad_range\n";
	}
}

