/*
 * Matrix.h
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <initializer_list>
#include <ostream>
#include <stdexcept>
using std::initializer_list;
using std::ostream;
using std::invalid_argument;

constexpr int rc_max {4};

template<typename T>
class Matrix;

template<typename T>
class Vector;

template<typename T>
ostream& operator<<(ostream&, const Vector<T>&);

template<typename T>
ostream& operator<<(ostream&, const Matrix<T>&);

template<typename T>
Vector<T> operator*(const Matrix<T>&, const Vector<T>&);

template<typename T>
class Vector {
	T v[rc_max];
public:
	Vector();
	Vector(initializer_list<T>);
	Vector& operator=(initializer_list<T>);

	friend Vector operator* <>(const Matrix<T>&, const Vector&);
	friend ostream& operator<< <>(ostream&, const Vector&);
};


template<typename T>
Vector<T>::Vector()
{
	for (int i = 0 ; i < rc_max; ++i)
		v[i] = 0;
}

template<typename T>
Vector<T>::Vector(initializer_list<T> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::Vector()");
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
}

template<typename T>
Vector<T>& Vector<T>::operator =(initializer_list<T> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Vector::operator=()");
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& v)
{
	os << "[ ";
	for (int i = 0 ; i < rc_max; ++i)
		os << v.v[i] << ' ';
	os << "]";
	return os;
}

template<typename T>
class Matrix {
	Vector<T> v[rc_max];
public:
	Matrix(initializer_list<initializer_list<T>>);

	friend Vector<T> operator* <>(const Matrix&, const Vector<T>&);
	friend ostream& operator<< <>(ostream&, const Matrix&);
};

template<typename T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> lst)
{
	if (lst.size()!=rc_max) throw invalid_argument("incorrect initializer list - Matrix::Matrix()");
	auto it = lst.begin();
	for (int i = 0; i < rc_max; ++i, ++it)
		v[i] = *it;
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& m)
{
	os << "[\n";
	for (int i = 0; i < rc_max; ++i)
		os << '\t' << m.v[i] << '\n';
	os << "]\n";
	return os;
}

template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	Vector<T> r;
	for (int i = 0; i!=rc_max; ++i) {
		r.v[i] = 0;
		for (int j = 0; j!=rc_max; ++j)
			r.v[i] += m.v[i].v[j] * v.v[j];
	}
	return r;
}


#endif /* MATRIX_H_ */
