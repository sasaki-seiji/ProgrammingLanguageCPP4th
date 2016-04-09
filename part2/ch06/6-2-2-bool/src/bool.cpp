/*
 * bool.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

bool b1 = 7;
bool b2 {7};

int i1 = true;
int i2 {true};

void f(int i)
{
	bool b {i!=0};
	cout << "b = " << b << '\n';
}

bool a = true;
bool b = true;

bool x = a + b;
bool y = a || b;
bool z = a - b;

void g(int* p)
{
	bool b = p;
	bool b2 {p!=nullptr};

	if (p) {
		cout << "in if(p)\n";
	}

	cout << "b = " << b << ", b2 = " << b2 << '\n';
}

int main()
{
	cout << "b1 = " << b1 << ", b2 = " << b2 << '\n';
	cout << "i1 = " << i1 << ", i2 = " << i2 << '\n';

	f(7);
	int	i = 7;
	g(&i);

	cout << "a = " << a << ", b = " << b << '\n';
	cout << "x = " << x << ", y == " << y << ", z = " << z << '\n';
}
