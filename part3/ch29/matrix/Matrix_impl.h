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

#endif /* MATRIX_IMPL_H_ */
