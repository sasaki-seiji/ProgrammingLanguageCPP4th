/*
 * Matrix.cpp
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */

#include "Matrix.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Vector::Vector()
{
	fill_n(v, rc_max, 0.0F);
}
Vector::Vector(initializer_list<float> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::Vector()");
	copy(lst.begin(), lst.end(), v);
}
Vector& Vector::operator =(initializer_list<float> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::operator=()");
	copy(lst.begin(), lst.end(), v);
	return *this;
}

ostream& operator<<(ostream& os, const Vector& v)
{
	os << "[ ";
	for (int i = 0 ; i < rc_max; ++i)
		os << v.v[i] << ' ';
	os << "]";
	return os;
}

Matrix::Matrix(initializer_list<initializer_list<float>> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Matrix::Matrix()");
	copy(lst.begin(), lst.end(), v);
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	os << "[\n";
	for (int i = 0; i < rc_max; ++i)
		os << "    " << m.v[i] << '\n';
	os << "]\n";
	return os;
}

Vector operator*(const Matrix& m, const Vector& v)
{
	Vector r;
	for (int i = 0; i!=rc_max; ++i) {
		r.v[i] = 0;
		for (int j = 0; j!=rc_max; ++j)
			r.v[i] += m.v[i].v[j] * v.v[j];
	}
	return r;
}

void invert(Matrix& m)	// add for 19.4.1
{
	cout << "invert(Marix& m) called with m : " << m << '\n';

	// do nothing
}
