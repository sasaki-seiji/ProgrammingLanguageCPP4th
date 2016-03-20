/*
 * container.cpp
 *
 *  Created on: 2016/03/21
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
// 2016.03.21 add
void setall_vector(Vector& v, double val)
{
	for( int i = 0; i < v.size(); ++i ) {
		v[i] = val;
	}
}

void fct(int n)
{
	Vector v(n);

	setall_vector(v, 2.1);	// 2016.03.21 add
	{
		Vector v2(2*n);
		print_vector(v2);	// 2016.03.21 add
	}
	print_vector(v);	// 2016.03.21 add
}

// 2016.03.21 add
int main()
{
	fct(10);
}

