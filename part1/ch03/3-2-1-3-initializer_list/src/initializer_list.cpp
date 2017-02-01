/*
 * initializer_list.cpp
 *
 *  Created on: 2016/03/21
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "Vector.h"

Vector read(istream& is)
{
	Vector v;
	for (double d; is >> d; ) {
		v.push_back(d);
	}
	return v;
}

void print_vector(ostream&os, Vector& v)
{
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1) {
			os << ", ";
		}
	}
	os << "]\n";
}

int main()
{
	Vector v {1, 2, 3.4};
	print_vector(cout, v);

	cout << "enter double values:\n";
	v = read(cin);
	print_vector(cout, v);
}

