/*
 * Matrix.h
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <memory>
#include <ostream>

template<typename T, int N>
class Matrix;

template<typename T>
class Matrix<T,0> {
	T elem;

public:
	explicit Matrix(const T& val) : elem{val} { }
	T& val() { return elem; }
	const T& val() const { return elem; }
};

template<typename T>
class Matrix<T,1> {
	int sz;
	T* elem;
		// member order is important!
public:
	explicit Matrix(int s) : sz{s}, elem{new T[sz]}
		{ std::fill(elem, elem+sz, T{}); }
	Matrix(std::initializer_list<T> il) : sz{il.size()},elem{new T[sz]}
		{ std::copy(il.begin(), il.end(), elem); }

	Matrix(const Matrix& s) : sz{s.sz}, elem{new T[sz]}
		{ std::copy(s.elem, s.elem+sz, elem); }
	Matrix(Matrix&& s) : sz{s.sz}
		{ elem = s.elem; s.elem = nullptr; }
	Matrix& operator=(const Matrix&) = delete;
	Matrix& operator=(Matrix&&) = delete;
	~Matrix() { delete[] elem; }

	T& val(int i) { return elem[i]; }
	const T& val(int i) const { return elem[i]; }

	int size() const { return sz; }
};

template<typename T>
class Matrix<T,2> {
	int dim1;
	int dim2;
	T* elem;

public:
	explicit Matrix(int s1, int s2) : dim1{s1}, dim2{s2}, elem{new T[s1*s2]}
		{ std::fill(elem, elem+dim1*dim2, T{}); }
	Matrix(std::initializer_list<std::initializer_list<T>> il);

	Matrix(const Matrix& s) : dim1{s.dim1}, dim2{s.dim2}, elem{new T[dim1*dim2]}
		{ std::copy(s.elem, s.elem+dim1*dim2, elem); }
	Matrix(Matrix&& s) : dim1{s.dim1}, dim2{s.dim2}
		{ elem = s.elem; s.elem = nullptr; }
	~Matrix() { delete [] elem; }

	Matrix& operator=(const Matrix&) = delete;
	Matrix& operator=(Matrix&&) = delete;

	T& val(int i, int j) { return elem[i*dim2+j]; }
	const T& val(int i, int j) const { return elem[i*dim2+j]; }
	int row() const { return dim1; }
	int col() const { return dim2; }
};

// implementation of Matrix<T,0>

template<typename T>
Matrix<T,0> operator+(const Matrix<T,0>& a, const Matrix<T,0>& b)
{
	T res = a.val() + b.val();
	return Matrix<T,0>{res};
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T,0>& m)
{
	os << m.val();
	return os;
}

// implementation of Matrix<T,1>

template<typename T>
Matrix<T,1> operator+(const Matrix<T,1>& a, const Matrix<T,1>& b)
{
	if (a.size()!=b.size()) throw std::runtime_error("size mismatch");

	Matrix<T,1> res(a.size());
	for (int i = 0; i < a.size(); ++i)
		res.val(i) = a.val(i) + b.val(i);
	return res;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T,1>& m)
{
	os << "[ ";
	for (int i = 0; i < m.size(); ++i)
		os << m.val(i) << ' ';
	os << "]";
	return os;
}

// implementation of Matrix<T,2>

template<typename T>
Matrix<T,2>::Matrix(std::initializer_list<std::initializer_list<T>> il)
	: dim1{il.size()}, dim2{il.begin()->size()}, elem{new T[dim1*dim2]}
{
	T* row = elem;
	auto it = il.begin();
	for( ; it != il.end(); ++it, row+=dim2) {
		if (it->size()!=dim2) throw std::runtime_error{"size mismatch"};
		std::copy(it->begin(), it->end(), row);
	}
}

template<typename T>
Matrix<T,2> operator+(const Matrix<T,2>& a, const Matrix<T,2>& b)
{
	if (a.row()!=b.row() || a.col()!=b.col()) throw std::runtime_error("size mismatch");

	Matrix<T,2> res(a.row(), a.col());
	for (int i = 0; i < a.row(); ++i)
		for (int j = 0; j < a.col(); ++j)
			res.val(i,j) = a.val(i,j) + b.val(i,j);
	return res;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T,2>& m)
{
	os << "[\n";
	for (int i = 0; i < m.row(); ++i) {
		os << "\t[ ";
		for (int j = 0 ; j < m.col(); ++j)
			os << m.val(i,j) << ' ';
		os << "]\n";
	}
	os << "]";
	return os;
}

#endif /* MATRIX_H_ */
