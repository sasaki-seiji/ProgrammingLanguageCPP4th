/*
 * Matrix_impl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_H_
#define MATRIX_IMPL_H_

#include "Matrix_concept.h"
#include "slice.h"
#include "Matrix_decl.h"
#include "Matrix_ref_decl.h"
#include "Matrix_impl_impl.h"

// print Matrix, Matrix_ref
template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=m.rows(); ++i) {
		os << m[i];
		if (i+1!=m.rows()) os << ',';
	}
	return os << '}';
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T,0>& m0)
{
	return os << (const T&)m0;
}


// construct from other type Matrix
template<typename T, size_t N>
template<typename U>
Matrix<T,N>::Matrix(const Matrix<U,N>& o)
	: desc{o.descriptor()}, elems{o.begin(), o.end()}
{
}

// assign from other type Matrix
template<typename T, size_t N>
template<typename U>
Matrix<T,N>& Matrix<T,N>::operator=(const Matrix<U,N>& o)
{
	desc = o.descritor();
	elems.assign(o.begin(), o.end());
	return *this;
}

// construct from extents
template<typename T, size_t N>
template<typename... Exts>
Matrix<T,N>::Matrix(Exts... exts)
	:desc{exts...}, elems(desc.size)
{
}

// construct from Matrix_initializer
template<typename T, size_t N>
Matrix<T,N>::Matrix(Matrix_initializer<T,N> init)
{
	desc.extents = Matrix_impl::derive_extents<N>(init);

	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);
}

// row
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::row(size_t n)
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

// col
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::col(size_t n)
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

// fortran style index access
template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
	Matrix<T,N>::operator()(Args... args)
{
	static_assert(sizeof...(Args)==N,
			"Matrix<T,N>::operator()(size_t...): dimension mismatch");

	assert(Matrix_impl::check_bounds(desc, args...));
	return *(data() + desc(args...));
}

template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
	Matrix<T,N>::operator()(Args... args) const
{
	assert(Matrix_impl::check_bounds(desc, args...));
	return *(data() + desc(args...));
}

// m(slice...)
template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
	Matrix<T,N>::operator()(const Args... args)
{
	Matrix_slice<N> d;
	d.start = Matrix_impl::do_slice(desc, d, args...);
	return {d, data()};
}

template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
	Matrix<T,N>::operator()(const Args... args) const
{
	Matrix_slice<N> d;
	d.start = Matrix_impl::do_slice(desc, d, args...);
	return {d, data()};
}

// construct from Matrix_ref
template<typename T, size_t N>
template<typename U>
	Matrix<T,N>::Matrix(const Matrix_ref<U,N>& x)
		:desc{x.descriptor().extents}, elems{x.begin(),x.end()}
{
	static_assert(Convertible<U,T>(),
			"Matrix constructor: incompatible element types");
}

// assign from Matrix_ref
template<typename T, size_t N>
template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix_ref<U,N>& x)
{
	static_assert(Convertible<U,T>(),
			"Matrix =: incompatible element types");

	desc = x.descriptor().extents;
	elems.assign(x.begin(), x.end());
	return *this;
}

// scalar operator

template<typename T, size_t N>
template<typename F>
Matrix<T,N>& Matrix<T,N>::apply(F f)
{
	for (auto& x : elems) f(x);
	return *this;
}

template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator=(const T& val)
{
	return apply([&](T& a) { a = val; });
}


// apply function to *this and matrix
template<typename T, size_t N>
template<template<typename,size_t> class M, typename T2, typename F,
	typename>
	Matrix<T,N>& Matrix<T,N>::apply(const M<T2,N>& m, F f)
{
	for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
		f(*i,*j);
	return *this;
}


// Matrix<T,1> * Matrix<T,1>
template<typename T>
Matrix<T,2> operator*(const Matrix<T,1>& u, const Matrix<T,1>& v)
{
	const size_t n = u.extent(0);
	const size_t m = v.extent(0);
	Matrix<T,2> res(n,m);
	for (size_t i = 0; i!=n; ++i)
		for (size_t j = 0; j!=m; ++j)
			res(i,j) = u[i]*v[j];
	return res;
}

// Matrix<T,2> * Matrix<T,1>
template<typename T>
Matrix<T,1> operator*(const Matrix<T,2>& m, const Matrix<T,1>& v)
{
	assert(m.extent(1) == v.extent(0));
	const size_t nr = m.extent(0);
	const size_t nc = m.extent(1);
	Matrix<T,1> res(nr);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=nc; ++j)
			res(i) += m(i,j)*v(j);
	return res;
}

// Matrix<T,2> * Matrix<T,2>
template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2)
{
	const size_t nr = m1.extent(0);
	const size_t nc = m1.extent(1);
	assert(nc==m2.extent(0));
	const size_t p = m2.extent(1);
	Matrix<T,2> res(nr,p);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=p; ++j)
#if 0
			for (size_t k = 0; k!=nc; ++k)
				res(i,j) += m1(i,k)*m2(k,j);
#else
		res(i,j) = dot_product(m1[i],m2.col(j));
#endif
	return res;
}


#endif /* MATRIX_IMPL_H_ */
