/*
 * output.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f()
{
	cout << 10;
}

void g()
{
	int i {10};
	cout << i;
}

void h(int i)
{
	cout << "the value of i is ";
	cout << i;
	cout << '\n';
}

void h2(int i)
{
	cout << "the value of i is " << i << '\n';
}

void k()
{
	int b = 'b';
	char c = 'c';
	cout << 'a' << b << c;
}
int main()
{
	f();
	g();
	h(10);
	h2(20);
	k();
}
