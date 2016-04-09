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

int main()
{
	Vector v1(5);
	v1[2] = 2.3; v1[4] = 4.5;
	cout << "original v1:\n";
	print_vector(v1);

	Vector v2{v1};
	cout << "after v2{v1}; v1, v2:\n";
	print_vector(v1);
	print_vector(v2);
	cout << "after v2[1] = 1.2; v1, v2:\n";
	v2[1] = 1.2;
	print_vector(v1);
	print_vector(v2);

	Vector v3(3);
	v3[2] = 10;
	cout << "original v3:\n";
	print_vector(v3);
	v3 = v1;
	cout << "after v3 = v1; v3:\n";
	print_vector(v3);
	v3[3] = 20;
	cout << "after v3[3] = 20; v3, v1:\n";
	print_vector(v3);
	print_vector(v1);
}

