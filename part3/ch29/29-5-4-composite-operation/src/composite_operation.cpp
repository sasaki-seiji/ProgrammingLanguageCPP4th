/*
 * composite_operation.cpp
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */


#include "composite_operation.h"

std::ostream& operator<<(std::ostream& os, const Vec& v)
{
	os << '{';
	size_t n = v.size();
	for (size_t i = 0; i != n; ++i) {
		os << v(i);
		if (i != n-1) os << ',';
	}
	return os << '}';
}

void mul_add_and_assign(Vec* U, const Mat2d* M, const Vec* V, const Vec* W)
{
	size_t n = U->size();
	for (size_t i = 0; i != n; ++i) {
		(*U)(i) = (*W)(i);
		for (size_t j = 0; j != n; ++j) {
			(*U)(i) += (*M)(i,j) * (*V)(j);
		}
	}
}
