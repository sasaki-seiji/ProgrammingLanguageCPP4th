/*
 * Vector.cpp
 *
 *  Created on: 2016/03/21
 *      Author: sasaki
 */

#include <initializer_list>
#include <algorithm>
#include "Vector.h"

Vector::Vector(std::initializer_list<double> lst)
	:elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }, space{ 0 }
{
	std::copy(lst.begin(), lst.end(), elem);
}

// 2016.03.21 add copy constructor
Vector::Vector(const Vector&src)
	:elem{ new double[src.sz] }, sz{ src.sz }, space{0}
{
	for (int i = 0; i < sz; ++i) {
		elem[i] = src.elem[i];
	}
}

Vector& Vector::operator=(const Vector& src)
{
	if (this == &src) return *this;

	double *newalloc = new double[src.sz];
	sz = src.sz;
	space = 0;
	delete[] elem;
	elem = newalloc;
	for (int i = 0; i < sz; ++i) {
		elem[i] = src.elem[i];
	}
	return *this;
}

void Vector::push_back(double x)
{
	if (space == 0) {
		int newsize = (sz == 0) ? 8 : sz * 2;
		double *newalloc = new double[newsize];
		space = newsize - sz;
		for (int i = 0; i < sz; ++i) {
			newalloc[i] = elem[i];
		}
		delete[] elem;
		elem = newalloc;
	}

	elem[sz++] = x;
	--space;
}

