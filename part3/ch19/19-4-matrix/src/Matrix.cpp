/*
 * Matrix.cpp
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */

#include "Matrix.h"
#include <stdexcept>
using namespace std;

Vector::Vector()
{
	for (int i = 0 ; i < rc_max; ++i)
		v[i] = 0;
}
Vector::Vector(initializer_list<float> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::Vector()");
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
}
Vector& Vector::operator =(initializer_list<float> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::operator=()");
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
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
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	os << "[\n";
	for (int i = 0; i < rc_max; ++i)
		os << '\t' << m.v[i] << '\n';
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
