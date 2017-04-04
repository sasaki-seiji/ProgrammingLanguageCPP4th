/*
 * Matrix.h
 *
 *  Created on: 2016/07/30
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <array>
#include <ostream>
#include <memory>
#include <utility>
#include <stdexcept>
using namespace std;

template<typename T>
class Matrix {
	array<int,2> dim;
	T* elem;
public:
	Matrix(int d1, int d2) :dim{d1, d2}, elem{new T[d1*d2]} { }

	int size() const { return dim[0]*dim[1]; }
	int rows() const { return dim[0]; }
	int cols() const { return dim[1]; }

	T& at(int i, int j) { return elem[i*dim[1]+j]; }
	const T& at(int i, int j) const { return elem[i*dim[1]+j]; }

	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);

	Matrix(Matrix&&);
	Matrix& operator=(Matrix&&);

	~Matrix() { delete [] elem; }

	template<typename X>
	friend Matrix<X> operator+(const Matrix<X>&, const Matrix<X>&);
};


template<typename T>
Matrix<T>::Matrix(const Matrix& m)
	: dim{m.dim},
	  elem{new T[m.size()]}
{
	copy(m.elem, m.elem+m.size(), elem);
}

template<typename T>
Matrix<T>::Matrix(Matrix&& a)
	:dim{a.dim}, elem{a.elem}
{
	a.dim = {0,0};
	a.elem = nullptr;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
	if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
		throw runtime_error("bad size in Matrix =");
	copy(m.elem, m.elem+m.size(), elem);

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& a)
{
	swap(dim, a.dim);
	swap(elem, a.elem);
	return *this;
}

template<typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
	if (a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1])
		throw std::runtime_error("unequal Matrix sizes in +");

	Matrix<T> res{a.dim[0], a.dim[1]};
	//constexpr auto n = a.size();
	auto n = a.size();
		// error: call to non-constexpr function ‘int Matrix<T>::size() const [with T = int]’
	for (int i = 0; i != n; ++i)
		res.elem[i] = a.elem[i]+b.elem[i];
	return res;
}

// add utilities

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& m)
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

#endif /* MATRIX_H_ */
