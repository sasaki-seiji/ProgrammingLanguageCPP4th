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

// move constructor
Vector::Vector(Vector&& a)
	:elem{a.elem}, sz{a.sz}
{
	a.elem = nullptr;
	a.sz = 0;
}

// move assign operator
Vector& Vector::operator=(Vector&& a)
{
	// swap
	double *t_elem = elem;
	int		t_sz = sz;
	elem = a.elem;
	sz = a.sz;
	a.elem = t_elem;
	a.sz = t_sz;

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

Vector operator+(const Vector& a, const Vector& b)
{
	if (a.size() != b.size())
		throw Vector_size_mismatch{};

	Vector res(a.size());
	for (int i = 0; i != a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}

