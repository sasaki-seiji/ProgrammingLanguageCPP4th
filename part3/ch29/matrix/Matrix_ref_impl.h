/*
 * Matrix_ref_impl.h
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */

#ifndef MATRIX_REF_IMPL_H_
#define MATRIX_REF_IMPL_H_

#include "Matrix_ref_decl.h"
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const Matrix_ref<T,0>& mr0)
{
	return os << (const T&)mr0;
}


// Matrix_ref_iterator

template<typename T, size_t N>
Matrix_ref_iterator<T,N> Matrix_ref_iterator<T,N>::begin(const Matrix_ref<T,N>* t)
{
	Matrix_ref_iterator<T,N> iter{t};
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N> Matrix_ref_iterator<T,N>::end(const Matrix_ref<T,N>* t)
{
	Matrix_ref_iterator<T,N> iter{t, true};
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N>& Matrix_ref_iterator<T,N>::operator++()
{
	for (int i = N-1; i >= 0; --i) {
		if (++pos[i] < target->descriptor().extents[i]) return *this;
		pos[i] = 0;
	}
	ov = true;
	return *this;
}

template<typename T, size_t N>
ostream& operator<<(ostream& os, const Matrix_ref_iterator<T,N>& iter)
{
	os << "target: " << *iter.target << ", pos: " << iter.pos
			<< ", ov: " << iter.ov << endl;
	return os;
}

// assign from Matrix_initializer
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator=(Matrix_initializer<T,N> init)
{
	array<size_t, N> extents = Matrix_impl::derive_extents<N>(init);
	assert(extents == desc.extents);

	auto it = begin();
	Matrix_impl::copy_flat(init, it);
	return *this;
}

// assign from other type Matrix
template<typename T, size_t N>
template<typename U>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator=(const Matrix<U,N>& m)
{
	assert(desc.extents == m.descriptor().extents);

	copy(m.begin(), m.end(), begin());
	return *this;
}

template<typename T, size_t N>
template<typename... Args>
Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
Matrix_ref<T,N>::operator()(Args... args) const
{
	static_assert(sizeof...(Args)==N,
			"Matrix_ref<T,N>::operator()(size_t...): dimension mismatch");
	assert(Matrix_impl::check_bounds(desc, args...));
	return *(data() + desc(args...));
}

template<typename T, size_t N>
template<typename... Args>
Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
Matrix_ref<T,N>::operator()(const Args... args) const
{
	Matrix_slice<N> d;
	d.start = desc.start + Matrix_impl::do_slice(desc, d, args...);
	d.size = compute_size(d.extents);
	return {d, data()};
}


// row

template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,ptr};
}

// col

template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,ptr};
}

// inner product
template<typename T, typename U=T>
T dot_product(const Matrix_ref<T,1>& a, const Matrix_ref<U,1>& b)
{
	return inner_product(a.begin(), a.end(), b.begin(), T{});
}


// apply
template<typename T,size_t N>
template<typename F>
Matrix_ref<T,N>& Matrix_ref<T,N>::apply(F f)
{
	for (auto& x : *this) f(x);
	return *this;
}

// assign scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator=(const T& value)
{
	for (auto& x : *this) x = value;
	return *this;
}

// apply with other matrix
template<typename T, size_t N>
template<template<typename,size_t> class M, typename T2, typename F,
	typename>
Matrix_ref<T,N>& Matrix_ref<T,N>::apply(const M<T2,N>& m, F f)
{
	for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
		f(*i,*j);
	return *this;
}


#endif /* MATRIX_REF_IMPL_H_ */
