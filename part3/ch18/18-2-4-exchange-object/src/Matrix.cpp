/*
 * Matrix.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

Matrix::Matrix(const Matrix& m)
	: dim{m.dim},
	  elem{new double[m.size()]}
{
	uninitialized_copy(m.elem, m.elem+m.size(), elem);
}

Matrix::Matrix(Matrix&& a)
	:dim{a.dim}, elem{a.elem}
{
	a.dim = {0,0};
	a.elem = nullptr;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
		throw runtime_error("bad size in Matrix =");
	copy(m.elem, m.elem+m.size(), elem);

	return *this;
}

Matrix& Matrix::operator=(Matrix&& a)
{
	swap(dim, a.dim);
	swap(elem, a.elem);
	return *this;
}


Matrix operator+(const Matrix& a, const Matrix& b)
{
	Matrix res{a};
	return res += b;
}

Matrix& Matrix::operator+=(const Matrix& a)
{
	if (dim[0]!=a.dim[0] || dim[1]!=a.dim[1])
		//throw std::exception("bad Matrix += argument");
		throw std::runtime_error("bad Matrix += argument");

	double* p = elem;
	double* q = a.elem;
	double* end = p+dim[0]*dim[1];
	while(p!=end)
		*p++ += *q++;

	return *this;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i=0; i < m.rows(); ++i) {
		os << "[ ";
		for (int j=0; j < m.cols(); ++j) {
			os << m.at(i,j) << ", ";
		}
		os << "]\n";
	}

	return os;
}



