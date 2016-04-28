/*
 * evaluation_order.cpp
 *
 *  Created on: 2016/04/26
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int f(int x)
{
	cout << "f(" << x << ") called\n";
	return x;
}

int g(int x)
{
	cout << "g(" << x << ") called\n";
	return x;
}

int i = 1;
int v[3];

void f1(int val, int i)
{
	cout << "f1(" << val << ", " << i << ") called\n";
}

void f2(int x)
{
	cout << "f2(" << x << ") called\n";
}

int main()
{
	int x = f(2) + g(3);
	cout << "f(2) + g(3) returns " << x << '\n';

	v[i] = i++;
		// operation on 'i' may be undefined [-Wsequence-point]

	cout << "i: " << i << ", v[0]: " << v[0] << ", v[1]: " << v[1] << ", v[2]: " << v[2] << '\n';

	v[0] = 0; v[1] = 1; v[2] = 2;
	i = 1;
	f1(v[i], i++);
		// operation on 'i' may be undefined [-Wsequence-point]
	f2( (v[i],i++) );
		// left operand of comma operator has no effect [-Wunused-value]
}

