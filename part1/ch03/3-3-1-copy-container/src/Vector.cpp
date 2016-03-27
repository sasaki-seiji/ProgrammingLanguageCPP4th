/*
 * Vector.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#include "Vector.h"

Vector::Vector(int s)
: elem{new double[s]}, sz{s}
{
	for (int i = 0; i != sz; ++i)
		elem[i] = 0;
}

Vector::~Vector()
{
	delete[] elem;
}

Vector::Vector(const Vector& a)
	:elem {new double[a.sz]}, sz {a.sz}
{
	for (int i = 0; i != sz; ++i)
		elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

double& Vector::operator[](int i)
{
	return elem[i];
}

const double& Vector::operator[](int i) const
{
	return elem[i];
}

int Vector::size() const
{
	return sz;
}

