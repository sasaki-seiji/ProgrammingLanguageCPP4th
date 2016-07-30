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
using std::array;
using std::uninitialized_copy;
using std::copy;
using std::swap;
using std::runtime_error;
using std::ostream;

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
	//Matrix& assign(const Matrix&);

	Matrix(Matrix&&);
	Matrix& operator=(Matrix&&);

	~Matrix() { delete [] elem; }
};


template<typename T>
inline Matrix<T>::Matrix(const Matrix& m)
	: dim{m.dim},
	  elem{new T[m.size()]}
{
	uninitialized_copy(m.elem, m.elem+m.size(), elem);
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
	if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
		throw runtime_error("bad size in Matrix =");
	copy(m.elem, m.elem+m.size(), elem);

	return *this;
}

#if 0 // need move constructor/assign
template<typename T>
inline Matrix<T>& Matrix<T>::assign(const Matrix& m)
{
	Matrix tmp{m};
	swap(tmp, *this);
	return *this;
}
#endif

// add utilities

template<typename T>
inline ostream& operator<<(ostream& os, const Matrix<T>& m)
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
