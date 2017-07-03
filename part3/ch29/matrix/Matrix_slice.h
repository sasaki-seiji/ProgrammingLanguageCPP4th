/*
 * Matrix_slice.h
 *
 *  Created on: 2017/06/26
 *      Author: sasaki
 */

#ifndef MATRIX_SLICE_H_
#define MATRIX_SLICE_H_


#include <cstddef>
#include <initializer_list>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

template<size_t N>
size_t compute_strides(const array<size_t,N>& exts, array<size_t,N>& strs);

template<size_t N>
size_t compute_size(const array<size_t,N>& exts);


template<size_t N>
struct Matrix_slice {
	Matrix_slice();
	Matrix_slice(size_t offset, initializer_list<size_t> exts);
	Matrix_slice(size_t offset, initializer_list<size_t> exts,
			initializer_list<size_t> strs);
	Matrix_slice(const array<size_t,N>& exts);

	template<typename... Dims>
		Matrix_slice(Dims... dims);

	template<typename... Dims>
		size_t operator()(Dims... dims) const;

	size_t offset(const array<size_t,N>& pos) const;

	size_t size;
	size_t start;
	array<size_t,N> extents;
	array<size_t,N> strides;
};

template<size_t N>
bool same_extents(const Matrix_slice<N>& a, const Matrix_slice<N>& b)
{
	return a.extents == b.extents;
}

template<size_t N>
Matrix_slice<N>::Matrix_slice()
	:size{0},start{0}
{
	fill(extents.begin(), extents.end(), 0);
	fill(strides.begin(), strides.end(), 1);
}
template<size_t N>
Matrix_slice<N>::Matrix_slice(size_t offset,
	initializer_list<size_t> exts)
	: start{offset}
{
	copy(exts.begin(), exts.end(), extents.begin());
	size = compute_strides(extents, strides);
}

template<size_t N>
Matrix_slice<N>::Matrix_slice(size_t offset,
	initializer_list<size_t> exts, initializer_list<size_t> strs)
	:start{offset}
{
	copy(exts.begin(), exts.end(), extents.begin());
	copy(strs.begin(), strs.end(), strides.begin());
	size = compute_size(extents);
}

template<size_t N>
Matrix_slice<N>::Matrix_slice(const array<size_t,N>& exts)
	:start{0}, extents{exts}
{
	size = compute_strides(extents, strides);
}

template<size_t N>
template<typename... Dims>
Matrix_slice<N>::Matrix_slice(Dims... dims)
	:start{0}
{
	static_assert(sizeof...(Dims)==N,
		"Matrix_slice<N>::Matrix_slice(Dims...): dimension mismatch");

	size_t args[N] { size_t(dims)... };
	copy(begin(args), end(args), extents.begin());
	size = compute_strides(extents, strides);
}


template<size_t N>
template<typename... Dims>
size_t Matrix_slice<N>::operator()(Dims... dims) const
{
	static_assert(sizeof...(Dims)==N,
		"Matrix_slice<N>::operator(): dimension mismatch");

	size_t args[N] { size_t(dims)... };
	return start + inner_product(args, args+N, strides.begin(), size_t{0});
}

template<size_t N>
size_t Matrix_slice<N>::offset(const array<size_t,N>& pos) const
{
	return start + inner_product(pos.begin(), pos.end(), strides.begin(), size_t{0});
}

template<size_t N>
size_t compute_strides(const array<size_t,N>& exts, array<size_t,N>& strs)
{
	size_t st = 1;
	for (int i=N-1; i>=0; --i) {
		strs[i] = st;
		st *= exts[i];
	}
	return st;
}

template<size_t N>
size_t compute_size(const array<size_t,N>& exts)
{
	return accumulate(exts.begin(), exts.end(), 1, multiplies<size_t>{});
}


template<size_t N>
ostream& operator<<(ostream& os, const array<size_t,N>& a)
{
	for (auto x : a)
		os << x << ' ';
	return os;
}


template<size_t N>
ostream& operator<<(ostream& os, const Matrix_slice<N>& ms)
{
	os << "size: " << ms.size
			<< ", start: " << ms.start
			<< ", extents: " << ms.extents
			<< ", strides: " << ms.strides;
	return os;
}



#endif /* MATRIX_SLICE_H_ */
