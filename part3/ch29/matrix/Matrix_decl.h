/*
 * Matrix_decl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_DECL_H_
#define MATRIX_DECL_H_

#include "type_converter.h"
#include "common.h"
using namespace Estd;

#include "fwd_decl.h"
#include "Matrix_concept.h"
#include "Matrix_slice.h"

#include <vector>
#include <iostream>
using namespace std;


template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m);

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T,0>& m0);

template<typename T>
ostream& operator<<(ostream& os, const Matrix_ref<T,0>& mr0);

template<typename T, size_t N>
class Matrix {
public:
	static constexpr size_t order = N;
	using value_type = T;
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	Matrix() = default;
	Matrix(Matrix&&) = default;
	Matrix& operator=(Matrix&&) = default;
	Matrix(const Matrix&) = default;
	Matrix& operator=(const Matrix&) = default;
	~Matrix() = default;

	template<typename U>
		Matrix(const Matrix<U,N>&);
	template<typename U>
		Matrix& operator=(const Matrix<U,N>&);

	template<typename U>
		Matrix(const Matrix_ref<U,N>&);
	template<typename U>
		Matrix& operator=(const Matrix_ref<U,N>&);

	template<typename... Exts>
		explicit Matrix(Exts... exts);

	Matrix(Matrix_initializer<T,N>);
	Matrix& operator=(Matrix_initializer<T,N>);

	template<typename U, size_t NN=N, 	typename =Enable_if<(NN>1)>,
			typename =Enable_if<Convertible<U,size_t>()>>
		Matrix(initializer_list<U>) = delete;
	template<typename U, size_t NN=N, typename =Enable_if<(NN>1)>,
			typename =Enable_if<Convertible<U,size_t>()>>
		Matrix& operator=(initializer_list<U>) = delete;

	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
		operator()(Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
		operator()(Args... args) const;

	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
		operator()(const Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
		operator()(const Args... args) const;

	Matrix_ref<T,N-1> operator[](size_t i) { return row(i); }
	Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }

	Matrix_ref<T,N-1> row(size_t n);
	Matrix_ref<const T,N-1> row(size_t n) const;

	Matrix_ref<T,N-1> col(size_t n);
	Matrix_ref<const T,N-1> col(size_t n) const;

	template<typename F>
		Matrix& apply(F f);
	Matrix& operator=(const T& value);

	template<template<typename,size_t> class M, typename T2, typename F,
		typename =Enable_if<Dimensional_Matrix_type<M,T2,N>()>>
		Matrix& apply(const M<T2,N>& m, F f);

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const{ return elems.size(); }
	size_t rows() const { return desc.extents[0]; }
	size_t cols() const { return desc.extents[1]; }

	const Matrix_slice<N>& descriptor() const { return desc; }


	T* data() { return elems.data(); }
	const T* data() const { return elems.data(); }

	iterator begin() { return elems.begin(); }
	const_iterator begin() const { return elems.cbegin(); }
	iterator end() { return elems.end(); }
	const_iterator end() const { return elems.cend(); }

private:
	Matrix_slice<N> desc;
	vector<T> elems;
};


template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& a, const Matrix<T,N>& b);

template<typename T, size_t N>
Matrix<T,N> operator-(const Matrix<T,N>& a, const Matrix<T,N>& b);

template<typename T, typename T2, size_t N,
	typename RT = Common_type<T,T2>>
Matrix<RT,N> operator+(const Matrix<T,N>& a, const Matrix<T2,N>& b);

template<typename T, typename T2, size_t N,
	typename RT = Common_type<T,T2>>
Matrix<RT,N> operator-(const Matrix<T,N>& a, const Matrix<T2,N>& b);

template<typename T>
Matrix<T,2> operator*(const Matrix<T,1>& u, const Matrix<T,1>& v);

template<typename T>
Matrix<T,1> operator*(const Matrix<T,2>& m, const Matrix<T,1>& v);

template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2);


template<typename T>
class Matrix<T,0> {
public:
	static constexpr size_t order = 0;
	using value_type = T;

	Matrix(const T& x = T{}) : elem(x) { }
	Matrix& operator=(const T& value) { elem = value; return elem; }

	T& operator()() { return elem; }
	const T& operator()() const { return elem; }

	operator T&() { return elem; }
	operator const T&() const { return elem; }

	const Matrix_slice<0>& descriptor() const { return desc; }

private:
	T elem;
	Matrix_slice<0> desc;
};

#endif /* MATRIX_DECL_H_ */
