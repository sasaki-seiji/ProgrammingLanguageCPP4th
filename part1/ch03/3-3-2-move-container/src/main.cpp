/*
 * main.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "Vector.h"

// 2016.03.21 add
void print_vector(Vector& v)
{
	cout << "[";
	for( int i = 0; i < v.size(); ++i ) {
		cout << v[i] ;
		if( i < v.size() - 1 ) cout << ", ";
	}
	cout << "]\n";
}

void f(const Vector& x, const Vector& y, const Vector& z)
{
	Vector r = x + y + z;

	print_vector(r);
}

Vector f()
{
	Vector x(1000);
	Vector y(1000);
	Vector z(1000);

	z = x;
	y = std::move(x);

	return z;
}

int main()
{
	Vector x(10), y(10), z(10);

	for (int i = 0; i != 10; ++i) {
		x[i] = i * 0.5;
		y[i] = 1.2;
		z[i] = i * i * 0.1;
	}
	print_vector(x);
	print_vector(y);
	print_vector(z);
	f(x, y, z);

	Vector r = f();
}

