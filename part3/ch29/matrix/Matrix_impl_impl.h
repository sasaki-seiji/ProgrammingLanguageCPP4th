/*
 * Matrix_impl_impl.h
 *
 *  Created on: 2017/06/26
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_IMPL_H_
#define MATRIX_IMPL_IMPL_H_

#include "slice.h"
#include "Matrix_impl_decl.h"
#include "Matrix_slice.h"
#include <cassert>

template<std::size_t N, typename List>
std::array<std::size_t, N> Matrix_impl::derive_extents(const List& list)
{
	std::array<std::size_t,N> a;
	auto f = a.begin();
	add_extents<N>(f,list);
	return a;
}

template<std::size_t N, typename I, typename List>
Enable_if<(N>1),void> Matrix_impl::add_extents(I& first, const List& list)
{
	assert(check_non_jagged<N>(list));
	*first++ = list.size();
	add_extents<N-1>(first, *list.begin());
}

template<std::size_t N, typename I, typename List>
Enable_if<(N==1),void> Matrix_impl::add_extents(I& first, const List& list)
{
	*first++ = list.size();
}

template<std::size_t N, typename List>
bool Matrix_impl::check_non_jagged(const List& list)
{
	auto i = list.begin();
	for (auto j = i+1; j!=list.end(); ++j)
		if (derive_extents<N-1>(*i) != derive_extents<N-1>(*j))
			return false;
	return true;
}

template<std::size_t N>
void Matrix_impl::compute_strides(Matrix_slice<N>& ms)
{
	ms.size = ::compute_strides(ms.extents, ms.strides);
}

template<typename T, typename Vec>
void Matrix_impl::insert_flat(initializer_list<T> list, Vec& vec)
{
	add_list(list.begin(), list.end(), vec);
}

template<typename T, typename Vec>
void Matrix_impl::add_list(const initializer_list<T>* first, const initializer_list<T>* last,
		Vec& vec)
{
	for ( ; first != last; ++first)
		add_list(first->begin(), first->end(), vec);
}

template<typename T, typename Vec>
void Matrix_impl::add_list(const T* first, const T* last, Vec& vec)
{
	vec.insert(vec.end(), first, last);
}

template<typename T, typename Iter>
void Matrix_impl::copy_flat(initializer_list<T> list, Iter& it)
{
	copy_list(list.begin(), list.end(), it);
}

template<typename T, typename Iter>
void Matrix_impl::copy_list
(const initializer_list<T>* first, const initializer_list<T>* last, Iter& it)
{
	for ( ; first != last; ++first)
		copy_list(first->begin(), first->end(), it);
}

template<typename T, typename Iter>
void Matrix_impl::copy_list(const T* first, const T* last, Iter& it)
{
	it = copy(first, last, it);
}


template<size_t I, size_t N>
void Matrix_impl::slice_dim(size_t offset,
		const Matrix_slice<N>& desc, Matrix_slice<N-1>& row)
{
	row.start = desc.start;
	int j = (int)N-2;
	for (int i=N-1; i>=0; --i) {
		if (i==I)
			row.start += desc.strides[i] * offset;
		else {
			row.extents[j] = desc.extents[i];
			row.strides[j] = desc.strides[i];
			--j;
		}
	}
	row.size = ::compute_size(row.extents);
}

template<size_t N, typename... Dims>
bool Matrix_impl::check_bounds(const Matrix_slice<N>& desc, Dims... dims)
{
	size_t indexes[N] {size_t(dims)...};
	return equal(indexes, indexes+N, desc.extents.begin(), less<size_t>{});
}

// impl for m(slice...)

template<size_t N, typename T, typename... Args>
size_t Matrix_impl::do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
		const T& s, const Args&... args)
{
	size_t m = do_slice_dim<sizeof...(Args)+1>(os,ns,s);
	size_t n = do_slice(os,ns,args...);
	return m+n;
}

template<size_t N>
size_t Matrix_impl::do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns)
{
	return 0;
}

template<size_t NRest, size_t N>
size_t Matrix_impl::do_slice_dim
	(const Matrix_slice<N>& os, Matrix_slice<N>& ns, size_t s)
{
	size_t i = N-NRest;
	ns.strides[i] = os.strides[i];
	ns.extents[i] = 1;
	return s * ns.strides[i];
}

template<size_t NRest, size_t N>
size_t Matrix_impl::do_slice_dim
	(const Matrix_slice<N>& os, Matrix_slice<N>& ns, slice s)
{
	size_t i = N-NRest;
	ns.strides[i] = s.stride * os.strides[i];
	ns.extents[i] = (s.length == size_t(-1)) ?
						(os.extents[i] - s.start + s.stride-1)/s.stride
					: s.length;
	return s.start * os.strides[i];
}



#endif /* MATRIX_IMPL_IMPL_H_ */
