/*
 * valarray.cpp
 *
 *  Created on: 2016/04/08
 *      Author: sasaki
 */

#include <valarray>
#include <iostream>
using namespace std;

template <typename C>
void print(const C& c)
{
	for (auto& x : c)
		cout << x << "  ";
	cout << '\n';
}

void f(valarray<double>& a1, valarray<double>& a2)
{
	valarray<double> a = a1*3.14 + a2/a1;
	a2 += a1*3.14;
	a = abs(a);
	double d = a2[7];

	cout << "a1: ";
	print(a1);
	cout << "a2: ";
	print(a2);
	cout << "a: ";
	print(a);

	cout << "d = " << d << '\n';
}

int main()
{
	valarray<double> a1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	valarray<double> a2 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

	f(a1, a2);
}

