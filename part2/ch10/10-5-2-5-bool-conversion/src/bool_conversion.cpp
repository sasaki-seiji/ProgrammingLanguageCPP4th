/*
 * bool_conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int* p, int i)
{
	bool is_not_zero = p;
	bool b2 = i;

	cout << boolalpha;
	cout << "is_not_zero: " << is_not_zero << '\n';
	cout << "b2: " << b2 << '\n';
}

void do_something(int x) { cout << "do_something(" << x << ")\n"; }
void fi(int i) { cout << "fi(" << i << ")\n"; }
void fb(bool b) { cout << "fb(" << b << ")\n"; }

void ff(int*p, int* q)
{
	if (p) do_something(*p);
	if (q!=nullptr) do_something(*q);

	//fi(p);
		// error: invalid conversion from 'int*' to 'int' [-fpermissive]

	fb(q);
}

int main()
{
	int	x=1, y=2;

	f(&x, 10);
	f(nullptr, 0);

	ff(&x, &y);
}

